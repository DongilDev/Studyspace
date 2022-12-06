#include <iostream>

using namespace std;

class Calculator {
	double result;
	int PlusNum;
	int MinusNum;
	int DivideNum;
	int MultiplyNum;

public:

	void Init();

	double Plus(double num1, double num2);
	double Minus(double num1, double num2);
	double Divide(double num1, double num2);
	double Multiply(double num1, double num2);

	void ShowOpCount();
};

void Calculator::Init() {
	result = 0;
	PlusNum = 0;
	MinusNum = 0;
	DivideNum = 0;
	MultiplyNum = 0;
}

double Calculator::Plus(double num1, double num2) {
	result = num1 + num2;
	PlusNum++;
	return result;
}
double Calculator::Minus(double num1, double num2) {
	result = num1 - num2;
	MinusNum++;
	return result;
}
double Calculator::Divide(double num1, double num2) {
	result = num1 / num2;
	DivideNum++;
	return result;
}
double Calculator::Multiply(double num1, double num2) {
	result = num1 * num2;
	MultiplyNum++;
	return result;
}

void Calculator::ShowOpCount() {
	cout << "덧셈: " << PlusNum << " 뺄셈: " << MinusNum << " 곱셈: " << MultiplyNum << " 나눗셈: " << DivideNum << endl;
}

int main() {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Plus(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Divide(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Minus(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Divide(4.9, 1.2) << endl;
	cal.ShowOpCount();

	return 0;
}