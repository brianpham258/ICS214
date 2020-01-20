#include "TestSuite.h"

int main() {
	//MyVector v{ 1,2,3 };
	//MyVector v2 = v;
	//v2.set(1, 99);

	//std::cout << "v[1]: " << v.get(1) << '\n';
	//std::cout << "size: " << v.size() << '\n';
	//std::cout << "v: " << v << '\n';
	//std::cout << "v2: " << v2 << '\n';

	assert(TestSuite::runTestSuite());

	return 0;
}