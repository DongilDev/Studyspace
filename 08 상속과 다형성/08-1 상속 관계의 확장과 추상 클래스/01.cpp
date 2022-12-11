#include <iostream>
#include <cstring>

using namespace std;

class Employee {
	char name[100];
public:
	Employee(char* name) {
		strcpy(this->name, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee {
	int salary;
public:
	PermanentWorker(char*name, int money) : Employee(name), salary(money) {}
	int GetPay() const {
		return salary;
	}
	void ShowSlaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee {
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(char*name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowSalaryInfo();
		cout << "slaary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker {
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

namespace RISK_LEVEL {
	enum { RISK_C = 1, RISK_B, RISK_A };
}

class ForeignSalesWorker : public SalesWorker {
	const int risk;
public:
	ForeignSalesWorker(char*name, int money, double ratio, int _risk)
		: SalesWorker(name, money, ratio), risk(_risk) {}
	int GetRiskPay() const {
		return SalesWorker::GetPay() * (0.1 * risk);
	}
	int GetPay() const {
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "RISK PAY: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) 
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {
	EmployeeHandler handler;

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	
	return 0;
}