#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER

#include "Shape.h"

class Circle : public Shape
{
private:
	float cx;
	float cy;
	float r;

public:
	Circle();
	Circle(const Circle&);
	Circle(const float, const float, const float, const unsigned, const Color, const Color, const float);
	~Circle();

public:
	char* makeSvg();
	void print();
	void translate(float, float);
	bool isWithin(float, float, float);
	bool isWithin(float, float, float, float);

private:
	void copyObject(const float, const float, const float, const unsigned, const Color, const Color, const float);
	void clearObject();

};

#endif // !CIRCLE_HEADER