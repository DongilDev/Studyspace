#include <iostream>
#include <cstring>

using namespace std;

class Gun {
	int bullet;

public:
	Gun(int bnum) : bullet(bnum) {}

	Gun(const Gun& ref) : bullet(ref.bullet) {
		cout << "Gun 복사생성자 호출" << endl;
	}

	void shot() {
		cout << " BBANG!" << endl;
		bullet--;
	}
};

class Police {
	int handcuffs;
	Gun* pistol;

public:
	Police(int bnum, int bcuff) : handcuffs(bcuff) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police& ref) : handcuffs(ref.handcuffs) {
		cout << "복사 생성자 호출" << endl;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
	}
	Police& operator=(const Police& ref) {
		delete[]pistol;
		cout << "대입 연산자 호출" << endl;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
		return *this;
		
	}
	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->shot();
	}
	~Police() {
		if (pistol != NULL) {
			cout << "소멸자 호출" << endl;
			delete pistol;
		}
	}
};

int main() {
	Police man1(2, 2);
	Police man2(1, 0);
	Police man3=man2; // 복사 생성자
	man3=man1; // 대입 연산자 
}