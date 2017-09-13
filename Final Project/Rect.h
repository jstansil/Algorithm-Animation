#ifndef RECT_H
#define RECT_H

class Rect {

	float x, y, x2, y2;
	float width;
	float height;

public:
	bool ex = false;
	bool oh = false;
	Rect() {
		x = 0;
		y = 0;
		ex = false;
		oh = false;
		width = 0;
		height = 0;
		x2 = x + width;
		y2 = y - height;
	}

	~Rect() {}

	float getX() const {
		return x;
	}
	float getY() const {
		return y;
	}
	float getX2() const {
		return x2;
	}
	float getY2() const {
		return y2;
	}
	float getCenterX() {
		return((x2 - x) / 2);
	}
	float getCenterY() {
		return((y - y2) / 2);
	}

	Rect(float xx, float yy, float w, float h) {
		x = xx;
		y = yy;
		width = w;
		height = h;
		x2 = x + width;
		y2 = y - height;
	}

	bool contains(float xx, float yy) {
		if ((xx >= x && xx <= x2) && (yy <= y && yy >= y2)) {
			return true;
		}
		else {
			return false;
		}
	}
};
#endif

