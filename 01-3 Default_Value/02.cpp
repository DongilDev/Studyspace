#include <iostream>

int SimpleFunc(int a = 10) {
	return a + 1;
}

int SimpleFunc(void) {
	return 10;
}

//다음과 같은 형태로의 함수 오버로딩은 문제가 있다.
//SimpleFunc(); 과 같이 인자를 전달하지 않으면서 함수를 호출하는 경우, 
//두 함수 모두 호출조건을 만족하기 때문에 컴파일 에러가 발생한다. 