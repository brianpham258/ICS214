#include "MyVector.h"
#include <stdexcept>
#include <iostream>

////////////////////////////////
// CONSTRUCTOR AND DESTRUCTOR //
////////////////////////////////

MyVector::MyVector(int newSize): m_size(newSize) {
	if (m_size < 0) {
		throw std::length_error("can't have a length of 0");
	}
	else if (m_size > 0) {
		m_capacity = m_size;
		pItems = new double[m_size];
	}
}

MyVector::~MyVector() {
	delete[] pItems;
	pItems = nullptr;
	m_size = 0;
}

///////////////////////
// MEMBER FUNCTIONS //
//////////////////////

double MyVector::get(int index) const {
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("get() index out of range");
	}
	return pItems[index];
}

void MyVector::set(int index, double value) {
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("get() index out of range");
	}
	pItems[index] = value;
}

int MyVector::capacity() const {
	return m_capacity;
}

////////////////////////
// OPERATOR OVERLOADS //
////////////////////////

MyVector::MyVector(const std::initializer_list<double>& list): MyVector(list.size()) {
	int index = 0;
	for (auto& value : list) {
		pItems[index] = value;
		index++;
	}
}

MyVector::MyVector(const MyVector& v): MyVector(v.size()) {
	// Copy into newly allocated memory
	for (int i = 0; i < v.size(); i++) {
		pItems[i] = v.get(i);
	}
}

std::ostream& operator<<(std::ostream& out, const MyVector& v) {
	out << "[ ";
	for (int i = 0; i < v.size(); i++) {
		out << v.get(i) << " ";
	}
	out << "]";

	return out;
}

/////////////
// METHODS //
/////////////

void MyVector::reserve(int newCapacity) {
	if (newCapacity <= m_capacity) {
		return;
	}
	else {
		//allocate new memory bigger than current 
		double* temp = new double[newCapacity];
		//copy old to new memory
		for (int i = 0; i < m_size; i++) {
			temp[i] = pItems[i];
		}

		//return old memory to heap
		delete[]pItems;

		//update pitems
		pItems = temp;


		//set capacity
		m_capacity = newCapacity;

	}
}

void MyVector::resize(int newSize) {
	reserve(newSize);

	for (int i = m_size; i < newSize; i++) {
		pItems[i] = 0;
	}

	m_size = newSize;
}

void MyVector::push_back(double value) {
	if (m_capacity == 0) {
		reserve(8);
	}
	else if (m_capacity == m_size) {
		reserve(m_size * 2);
	}

	pItems[m_size] = value;
	m_size++;
}

double MyVector::pop_back() {
	if (m_size == 0) {
		throw std::out_of_range("Vector is empty");
	}

	m_size--;
	return pItems[m_size];
}

MyVector& MyVector::operator=(const MyVector& v) {
	//1 handle self assignmnent
	// this instance has the same address
	if (this == &v)
		return *this;

	delete[] pItems;

	//reallocate new memory
	pItems = new double[v.m_size];
	m_size = v.m_size;
	m_capacity = v.m_capacity;
	//make copy
	for (int i = 0; i < m_size; i++) {
		pItems[i] = v.get(i);
	}
}

double& MyVector::operator[](int index) {
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("Index out of range");
	}

	return pItems[index];
}

const double& MyVector::operator[](int index) const {
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("Index out of range");
	}

	return pItems[index];
}