#ifndef MYVECTORR_H
#define MYVECTOR_H
#include <iostream>
#include <initializer_list>

class MyVector {
private:
	int m_size = 0;
	int m_capacity = 0;
	double* pItems = nullptr;
public:
	MyVector(int newSize = 0);
	MyVector(const std::initializer_list<double> &list);
	MyVector(const MyVector &v);
	~MyVector();
	int size() const { return m_size; }
	double get(int index) const;
	void set(int index, double value);

	MyVector& operator=(const MyVector& v);
	double& operator[](int index);
	const double& operator[](int index) const;
	int capacity() const;
	void reserve(int newCapacity);
	void resize(int newSize);
	void push_back(double value);
	double pop_back();
};

std::ostream& operator<<(std::ostream& out, const MyVector &v);

#endif   // MYVECTOR_H