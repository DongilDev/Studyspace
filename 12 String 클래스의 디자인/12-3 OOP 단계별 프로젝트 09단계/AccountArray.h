#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__
#include "Account.h"

typedef Account* Account_Ptr;

class BoundCheckAccountPtrArray {
	Account_Ptr* arr;
	int arrlen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) {}
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) {}

public:
	BoundCheckAccountPtrArray(int len = 100);
	Account_Ptr& operator[] (int idx);
	Account_Ptr& operator[] (int idx) const;
	int GetArrlen() const;
	~BoundCheckAccountPtrArray();
};
#endif