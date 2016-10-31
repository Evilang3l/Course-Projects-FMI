#ifndef ELLIPSE_HEADER
#define ELLIPSE_HEADER

#include "Shape.h"

class Ellipse : public Shape
{
private:
	float cx;
	float cy;
	float rx;
	float ry;

public:
	Ellipse();
	Ellipse(const Ellipse&);
	Ellipse(const float, const float, const float, const float, const unsigned, const Color, const Color, const float);
	~Ellipse();

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


#endif // !ELLIPSE_HEADER