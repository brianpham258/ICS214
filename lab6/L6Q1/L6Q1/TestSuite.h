#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "Point.h"
#include "Tetromino.h"
#include <assert.h>
#include <iostream>



class TestSuite
{
public:
	static bool runTestSuite()
	{
		std::cout << "Running TestSuite ------------------------" << "\n";
		// run some sanity tests on our classes to ensure they're working as expected.
		TestSuite::testPointClass();
		TestSuite::testTetrominoClass();
		std::cout << "TestSuite complete -----------------------" << "\n";
		return true;
	}
	
	static bool testTetrominoClass()
	{
		std::cout << " testTetrominoClass...";

		Tetromino t;
		
		// ensure the constructor gave the tetromino a color
		assert(t.getColor() == Tetromino::TetColor::RED ||
			t.getColor() == Tetromino::TetColor::ORANGE ||
			t.getColor() == Tetromino::TetColor::YELLOW ||
			t.getColor() == Tetromino::TetColor::GREEN ||
			t.getColor() == Tetromino::TetColor::BLUE_LIGHT ||
			t.getColor() == Tetromino::TetColor::BLUE_DARK ||
			t.getColor() == Tetromino::TetColor::PURPLE);

		// ensure the constructor gave the tetromino a shape
		assert(t.getShape() == Tetromino::TetShape::SHAPE_S ||
			t.getShape() == Tetromino::TetShape::SHAPE_Z ||
			t.getShape() == Tetromino::TetShape::SHAPE_L ||
			t.getShape() == Tetromino::TetShape::SHAPE_J ||
			t.getShape() == Tetromino::TetShape::SHAPE_O ||
			t.getShape() == Tetromino::TetShape::SHAPE_I ||
			t.getShape() == Tetromino::TetShape::SHAPE_T);

		// ensure each tetromino shape has 4 blocks in it.
		Tetromino::TetShape shapes = { Tetromino::TetShape::SHAPE_S };
		const int locCount = 4;
		t.setShape(Tetromino::TetShape::SHAPE_S);
		assert(t.blockLocs.size() == locCount && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::SHAPE_Z);
		assert(t.blockLocs.size() == locCount && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::SHAPE_L);
		assert(t.blockLocs.size() == locCount && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::SHAPE_J);
		assert(t.blockLocs.size() == locCount && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::SHAPE_O);
		assert(t.blockLocs.size() == locCount && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::SHAPE_I);
		assert(t.blockLocs.size() == locCount && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::SHAPE_T);
		assert(t.blockLocs.size() == locCount && "Tetromino shape size should be 4");


		// test the rotate functionality of a single block
		t.blockLocs.clear();
		t.blockLocs.push_back(Point(1, 2));
		t.rotateCW();
		assert(t.blockLocs[0].getX() == 2 && t.blockLocs[0].getY() == -1 && "Tetromino::rotateCW() failed");
		t.rotateCW();
		assert(t.blockLocs[0].getX() == -1 && t.blockLocs[0].getY() == -2 && "Tetromino::rotateCW() failed");
		t.rotateCW();
		assert(t.blockLocs[0].getX() == -2 && t.blockLocs[0].getY() == 1 && "Tetromino::rotateCW() failed");
		t.rotateCW();
		assert(t.blockLocs[0].getX() == 1 && t.blockLocs[0].getY() == 2 && "Tetromino::rotateCW() failed");

		std::cout << "passed!" << "\n";
		return true;
	}


	static bool testPointClass()
	{
		std::cout << " testPointClass()...";

		Point p;

		// test our initial values are 0,0
		assert(p.getX() == 0 && "Point ctor - x not initialized to 0");
		assert(p.getY() == 0 && "Point ctor - y not initialized to 0");

		// test setX()
		p.setX(1);
		assert(p.getX() == 1 && "Point::setX() failed");
		p.setX(-1);
		assert(p.getX() == -1 && "Point::setX() failed");

		// test setY()
		p.setY(2);
		assert(p.getY() == 2 && "Point::setY() failed");
		p.setY(-2);
		assert(p.getY() == -2 && "Point::setY() failed");

		// test setXY()
		p.setXY(3, 4);
		assert(p.getX() == 3 && p.getY() == 4 && "Point::setXY() failed");
		p.setXY(-3, -4);
		assert(p.getX() == -3 && p.getY() == -4 && "Point::setXY() failed");

		// test constructor with 2 params
		Point q(3, 4);
		assert(q.getX() == 3 && q.getY() == 4 && "Point::ctor failed to set default params");

		// test swapXY()
		q.swapXY();
		assert(q.getX() == 4 && q.getY() == 3 && "Point::swapXY() failed");

		// test multiplyX()
		q.multiplyX(-1);
		assert(q.getX() == -4 && "Point::multiplyX() failed");

		// test multiplyY()
		q.multiplyY(-1);
		assert(q.getY() == -3 && "Point::multiplyY() failed");

		// test copy constructor
		q.setXY(1, 2);
		Point r = q;
		assert(r.getX() == q.getX() && r.getY() == q.getY() && "Point copy ctor failed");
		r.setXY(3, 4);
		assert(r.getX() == 3 && r.getY() == 4
			&& q.getX() == 1 && q.getY() == 2 && "Point::setXY() failed");

		std::cout << "passed!" << "\n";
		return true;
	}
};
#endif /* TESTSUITE_H */