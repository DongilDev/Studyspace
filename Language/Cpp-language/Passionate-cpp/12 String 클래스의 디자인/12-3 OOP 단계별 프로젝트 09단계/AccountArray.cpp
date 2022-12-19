#include "AccountArray.h"
#include "BankingCommonDecl.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len = 100) : arrlen(len) {
	arr = new Account_Ptr[len];
}
Account_Ptr& BoundCheckAccountPtrArray::operator[] (int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}
Account_Ptr& BoundCheckAccountPtrArray::operator[] (int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}
int BoundCheckAccountPtrArray::GetArrlen() const {
	return arrlen; 
}
BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {
	delete[]arr;
}