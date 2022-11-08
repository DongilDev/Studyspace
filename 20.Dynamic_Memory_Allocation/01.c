#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num; // 학생 번호(1~n)
	double aver; // 학생 평균 점수
}Student;

void set_average(int** arr, int subjects, int students, Student* brr);
void student_sort_with_aver(Student* brr, int students);
void print_student(Student* brr, int students);
void destruct_memory(int** arr, int subjects, Student* brr);

int main(void) {
	int i, j;
	int students, subjects;
	int** arr;
	Student* brr;
	printf("과목 수 : ");
	scanf("%d", &subjects);
	printf("학생 수 : ");
	scanf("%d", &students);

	arr = (int**)malloc(sizeof(int*) * subjects);

	for (i = 0; i < subjects; i++) {
		arr[i] = (int*)malloc(sizeof(int) * students);
	}
	brr = (Student*)malloc(sizeof(Student) * students);

	for (i = 0; i < subjects; i++) {
		printf("\n과목%d\n", i + 1);
		for (j = 0; j < students; j++) {
			printf("학생%d의 점수 : ", j + 1);
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
	set_average(arr, subjects, students, brr);
	student_sort_with_aver(brr, students);
	print_student(brr, students);
	destruct_memory(arr, subjects, brr);

	return 0;
}

void set_average(int** arr, int subjects, int students, Student* brr) {
	int i, j;
	double aver = 0, sum = 0;

	for (j = 0; j < students; j++) {
		sum = 0;
		for (i = 0; i < subjects; i++) {
			sum += arr[i][j];
		}
		aver = sum / subjects;
		brr[j].num = j + 1;
		brr[j].aver = aver;
	}
}
void student_sort_with_aver(Student* brr, int students) {
	int i, j;
	Student tmp;
	int index = 0;
	double max;

	for (i = 0; i < students; i++) {
		for (j = 0; j < students - i - 1; j++) {
			if (brr[j].aver < brr[j + 1].aver) {
				tmp = brr[j];
				brr[j] = brr[j + 1];
				brr[j + 1] = tmp;
			}
		}
	}
}
void print_student(Student* brr, int students) {
	for (int i = 0; i < students; i++) {
		printf("학생 %d 의 평균점수 : %f  등수 : %d \n", brr[i].num, brr[i].aver, i + 1);
	}
}

void destruct_memory(int** arr, int subjects, Student* brr) {
	//메모리 해제. 
	for (int i = 0; i < subjects; i++) {
		free(arr[i]);
	}
	free(brr);
	free(arr);
}