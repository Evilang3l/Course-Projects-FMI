#ifndef RECTANGLE_HEADER
#define RECTANGLE_HEADER

#include "Shape.h"

class Rectangle : public Shape
{
private:
	float x;
	float y;
	float width;
	float height;

public:
	Rectangle();
	Rectangle(const Rectangle&);
	Rectangle(const float, const float, const float, const float, const unsigned, const Color, const Color, const float);
	~Rectangle();

public:
	char* makeSvg();
	void print();
	void translate(float, float);
	bool isWithin(float, float, float);
	bool isWithin(float, float, float, float);

private:
	void copyObject(const float, const float, const float, const float, const unsigned, const Color, const Color, const float);
	void clearObject();

};


#endif // !RECTANGLE_HEADER