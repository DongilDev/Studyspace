#include <stdio.h>

int main() {
    int i, j, x = 2, y = 2;
    int map[11][11];
    
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    while (1) {
        if (map[x][y] == 0) {
            map[x][y] = 9;
            y++;
        }
        if (map[x][y] == 1) {
            y--;
            x++;
        }
        if (map[x][y] == 2) {
            map[x][y] = 9;
            break;
        }
        else if (map[x][y + 1] == 1 && map[x + 1][y] == 1) {
            if (map[x][y] == 0) {
                map[x][y] = 9;
            }
            break;
        }
    }

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// CodeUp 모범답안 (재귀함수 사용)
#include <stdio.h>
int map[12][12];

void back(int r, int c)
{
	if(map[r][c] == 2)
	{
			map[r][c] = 9;
			return ;
	}
	map[r][c] = 9;

	if(map[r][c+1] != 1)
		back(r, c+1);
	else if(map[r+1][c] != 1)
		back(r+1, c);
}

int main()
{
	int i, j;
	for(i = 1; i <= 10; i++)
		for(j = 1; j <= 10; j++)
			scanf("%d", &map[i][j]);
	back(2, 2);

	for(i = 1; i <= 10; i++,puts(""))
		for(j = 1; j <= 10; j++)
			printf("%d ", map[i][j]);
}