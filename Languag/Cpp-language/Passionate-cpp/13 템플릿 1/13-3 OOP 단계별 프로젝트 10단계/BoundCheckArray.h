#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__
#include "Account.h"


template <class T>
class BoundCheckArray {
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}

public:
	BoundCheckArray(int len = 100);
	T& operator[] (int idx);
	T& operator[] (int idx) const;
	int GetArrlen() const;
	~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len) {
	arr = new T[len];
}

template <class T>
T& BoundCheckArray<T>::operator[] (int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <class T>
T& BoundCheckArray<T>::operator[] (int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <class T>
int BoundCheckArray<T>::GetArrlen() const {
	return arrlen;
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[]arr;
}

#endif