#include "Tetromino.h"
#include <iostream>

Tetromino::Tetromino() {
	color = TetColor::RED;
	shape = TetShape::SHAPE_S;
	this->setShape(TetShape::SHAPE_S);
}

TetColor Tetromino::getColor() const {
	return this->color;
}

TetShape Tetromino::getShape() const {
	return this->shape;
}

void Tetromino::setShape(TetShape shape) {
	this->shape = shape;
	
	switch (this->shape) {
	case TetShape::SHAPE_S:
		blockLocs = { Point(0, 0), Point(-1, 0), Point(0, 1), Point(1, 1) };
		color = TetColor::RED;
		break;
	case TetShape::SHAPE_Z:
		blockLocs = { Point(0, 0), Point(0, 1), Point(-1, 1), Point(1, 0) };
		color = TetColor::GREEN;
		break;
	case TetShape::SHAPE_L:
		blockLocs = { Point(0, 0), Point(0, 1), Point(0, -1), Point(1, -1) };
		color = TetColor::ORANGE;
		break;
	case TetShape::SHAPE_J:
		blockLocs = { Point(0, 0), Point(0, 1), Point(0, -1), Point(-1, -1) };
		color = TetColor::PURPLE;
		break;
	case TetShape::SHAPE_O:
		blockLocs = { Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0) };
		color = TetColor::YELLOW;
		break;
	case TetShape::SHAPE_I:
		blockLocs = { Point(0, 0), Point(0, 1), Point(0, 2), Point(0, -1) };
		color = TetColor::BLUE_LIGHT;
		break;
	case TetShape::SHAPE_T:
		blockLocs = { Point(0, 0), Point(0, -1), Point(-1, 0), Point(1, 0) };
		color = TetColor::BLUE_DARK;
		break;
	}
}

void Tetromino::rotateCW() {
	for (int i = 0; i < blockLocs.size(); i++) {
		blockLocs[i].swapXY();
		blockLocs[i].multiplyX(-1);
	}
}

TetShape Tetromino::getRandomShape() {
	int convertedTetShapeCount = static_cast<int>(TetShape::TetShapeCount);
	int random = rand() % convertedTetShapeCount;

	return static_cast<TetShape>(random);
}

void Tetromino::printToConsole() const {
	Point p;
	for (int y = 3; y >= -3; y--) {
		for (int x = -3; x <= 3; x++) {
			bool isBlock = false;
			int testSize = blockLocs.size();
			for (int k = 0; k < blockLocs.size(); k++) {
				int ptX = blockLocs[k].getX();
				int	ptY = blockLocs[k].getY();
				if (x == ptX && y == ptY) {
					isBlock = true;
					break;
				}
			}
			if (isBlock) {
				std::cout << " x ";
			}
			else {
				std::cout << " . ";
			}
		}
		std::cout << '\n';
	}
}