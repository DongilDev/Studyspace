#include <iostream>

using namespace std;

class  Car { // 기본 연료 자동차
	int gasolineGauge;
public:
	Car(int n) : gasolineGauge(n) {}

	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car { // 하이브리드 자동차
	int electricGauge;
public:
	HybridCar(int n1, int n2) : Car(n1), electricGauge(n2) {}

	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar { // 하이브리드 워터카
	int waterGauge;
public:
	HybridWaterCar(int n1, int n2, int n3) : HybridCar(n1,n2), waterGauge(n3) {}

	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main() {
	HybridWaterCar watercar(20, 30, 40);
	watercar.ShowCurrentGauge();

	return 0;
}