#ifndef TETROMINO_H
#define TETROMINO_H

#include "Point.h"
#include <vector>

class Tetromino {
public:
	enum class TetColor {
		RED,
		ORANGE,
		YELLOW,
		GREEN,
		BLUE_LIGHT,
		BLUE_DARK,
		PURPLE
	};

	enum class TetShape {
		SHAPE_S,
		SHAPE_Z,
		SHAPE_L,
		SHAPE_J,
		SHAPE_O,
		SHAPE_I,
		SHAPE_T
	};

	Tetromino();
	TetColor getColor() const;
	TetShape getShape() const;
	void setShape(TetShape shape);
	void rotateCW();
	void printToConsole() const;

protected:
	std::vector<Point> blockLocs;
private:
	TetColor color;
	TetShape shape;
friend class TestSuite;
};

#endif // !TETROMINO_H

