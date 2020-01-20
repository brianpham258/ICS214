#include "GridTetromino.h"

// constructor, initialize gridLoc to 0,0
GridTetromino::GridTetromino() {
	GridTetromino::gridLoc.setXY(0, 0);
};

// return the tetromino's grid/gameboard loc (x,y)
Point GridTetromino::getGridLoc() const {
	return GridTetromino::gridLoc;
};

// sets the tetromino's grid/gameboard loc using x,y
void GridTetromino::setGridLoc(int x, int y) {
	GridTetromino::gridLoc.setXY(x, y);
};

// sets the tetromino's grid/gameboard loc using a Point
void GridTetromino::setGridLoc(const Point& pt) {
	GridTetromino::gridLoc.setXY(pt.getX(), pt.getY());
};

// transpose the gridLoc of this shape
void GridTetromino::move(int xOffset, int yOffset) {
	setGridLoc(GridTetromino::gridLoc.getX() + xOffset, GridTetromino::gridLoc.getY() + yOffset);
};

// build and return a vector of Points to represent our inherited
// blockLocs vector mapped to the gridLoc of this object instance.
// eg: if we have a Point [x,y] in our vector,
// and our gridLoc is [5,6] the mapped Point would be [5+x,6+y].
std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const {
	std::vector<Point> newBlock;
	int currX;
	int currY;
	int gridX = GridTetromino::gridLoc.getX();
	int gridY = GridTetromino::gridLoc.getY();

	for (int i = 0; i < blockLocs.size(); i++) {
		currX = blockLocs[i].getX();
		currY = blockLocs[i].getY();
		newBlock.push_back(Point(currX + gridX, currY + gridY));
	}

	return newBlock;
};