#include "Circle.h"

Circle::Circle()
{
	cx = 0;
	cy = 0;
	r = 0;
}

Circle::Circle(const Circle& other)
{
	copyObject(other.cx, other.cy, other.r, other.num, other.stroke, other.fill, other.strokeWidth);
}

Circle::Circle(const float tmpCx, const float tmpCy, const float tmpR, const unsigned tmpNum, const Color tmpStroke, const Color tmpFill, const float tmpStrokeWidth)
{
	copyObject(tmpCx, tmpCy, tmpR, tmpNum, tmpStroke, tmpFill, tmpStrokeWidth);
}

Circle::~Circle()
{
	clearObject();
}

char* Circle::makeSvg()
{
	char* endOfStr = generateSvgLines();

	DynamicChar buff;
	buff += "<";
	buff += getPolygonTypeStr(getPolyType());
	buff += " cx=\"";
	buff += cx;
	buff += "\" cy=\"";
	buff += cy;
	buff += "\" r=\"";
	buff += r;
	buff += "\"";
	buff += endOfStr;

	int resultSize = buff.getSize() + 1;
	char* result = new char[resultSize];
	strcpy(result, buff.getChar());
	return result;
}

bool Circle::isWithin(float cx, float cy, float r)
{
	bool result = false;

	if (this->cx + this-> r <= cx + r && this->cx - this->r >= cx - r)
	{
		if (this->cy + this->r <= cy + r && this->cy - this->r >= cy - r)
		{
			result = true;
		}
	}

	return result;
}

bool Circle::isWithin(float x, float y, float width, float height)
{
	bool result = false;

	if (this->cx + this->r <= x + width && this->cx - this->r >= x)
	{
		if (this->cy + this->r <= y + height && this->cy - this->r >= y)
		{
			result = true;
		}
	}

	return result;
}

void Circle::translate(float x, float y)
{
	this->cx += x;
	this->cy += y;
}

void Circle::print()
{
	DynamicChar buff;
	buff += getShapeNum();
	buff += ". ";
	buff += getPolygonTypeStr(getPolyType());
	buff += " ";
	buff += cx;
	buff += " ";
	buff += cy;
	buff += " ";
	buff += r;
	buff += " ";
	buff += getColorStr(getShapeColor());

	std::cout << buff.getChar() << endl;
}

void Circle::copyObject(const float tmpCx, const float tmpCy, const float tmpR, const unsigned tmpNum, const Color tmpStroke, const Color tmpFill, const float tmpStrokeWidth)
{
	cx = tmpCx;
	cy = tmpCy;
	r = tmpR;
	setValues(tmpNum, circle, tmpStroke, tmpFill, tmpStrokeWidth);
}

void Circle::clearObject()
{

}