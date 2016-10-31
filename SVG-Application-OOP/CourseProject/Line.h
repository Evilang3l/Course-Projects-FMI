#ifndef LINE_HEADER
#define LINE_HEADER

#include "Shape.h"

class Line : public Shape
{
private:
	float x1;
	float x2;
	float y1;
	float y2;

public:
	Line();
	Line(const Line&);
	Line(const float, const float, const float, const float, const unsigned, const Color, const Color, const float);
	~Line();

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


#endif // !LINE_HEADER