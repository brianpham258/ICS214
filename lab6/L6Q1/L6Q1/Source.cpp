#include <iostream>
#include "TestSuite.h"
#include "Tetromino.h"

int main() {
	//assert(TestSuite::runTestSuite());
	Tetromino t;

	char input;

	do {
		std::cout << "Input either 's', 'z', 'l', 'j', 'o', 'i', 't' for shape, or 'r' to rotatem or 'e' to exit: ";
		std::cin >> input;
		if (input == 'r') {
			t.rotateCW();
			t.printToConsole();
		}
		else {
			switch (input) {
			case 's':
				t.setShape(Tetromino::TetShape::SHAPE_S);
				t.printToConsole();
				break;
			case 'z':
				t.setShape(Tetromino::TetShape::SHAPE_Z);
				t.printToConsole();
				break;
			case 'l':
				t.setShape(Tetromino::TetShape::SHAPE_L);
				t.printToConsole();
				break;
			case 'j':
				t.setShape(Tetromino::TetShape::SHAPE_J);
				t.printToConsole();
				break;
			case 'o':
				t.setShape(Tetromino::TetShape::SHAPE_O);
				t.printToConsole();
				break;
			case 'i':
				t.setShape(Tetromino::TetShape::SHAPE_I);
				t.printToConsole();
				break;
			case 't':
				t.setShape(Tetromino::TetShape::SHAPE_T);
				t.printToConsole();
				break;

			default:
				std::cout << "Wrong choice! Try again!";
				break;
			}
		}
	} while (input != 'e');

	return 0;
}