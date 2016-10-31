#include "Line.h"

Line::Line()
{
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

Line::Line(const Line& other)
{
	copyObject(other.x1, other.x2, other.y1, other.y2, other.num, other.stroke, other.fill, other.strokeWidth);
}

Line::Line(const float tmpX1, const float tmpX2, const float tmpY1, const float tmpY2, const unsigned tmpNum, const Color tmpStroke, const Color tmpFill, const float tmpStrokeWidth)
{
	copyObject(tmpX1, tmpX2, tmpY1, tmpY2, tmpNum, tmpStroke, tmpFill, tmpStrokeWidth);
}

Line::~Line()
{
	clearObject();
}

char* Line::makeSvg()
{
	char* endOfStr = generateSvgLines();

	DynamicChar buff;
	buff += "<";
	buff += getPolygonTypeStr(getPolyType());
	buff += " x1=\"";
	buff += x1;
	buff += "\" x2=\"";
	buff += x2;
	buff += "\" y1=\"";
	buff += y1;
	buff += "\" y2=\"";
	buff += y2;
	buff += "\"";
	buff += endOfStr;

	int resultSize = buff.getSize() + 1;
	char* result = new char[resultSize];
	strcpy(result, buff.getChar());
	return result;
}

void Line::translate(float x, float y)
{
	this->x1 += x;
	this->x2 += x;
	this->y1 += y;
	this->y2 += y;
}

bool Line::isWithin(float cx, float cy, float r)
{
	bool result = false;

	if (this->x1 + this->x2 <= cx + r && this->x1 - this->x2 >= cx - r)
	{
		if (this->y1 + this->y2 <= cy + r && this->y1 - this->y2 >= cy - r)
		{
			result = true;
		}
	}

	return result;
}

bool Line::isWithin(float x, float y, float width, float height)
{
	bool result = false;

	if (this->x1 + this->x2 <= x + width && this->x1 - this->x2 >= x)
	{
		if (this->y1 + this->y2 <= y + height && this->y1 - this->y2 >= y)
		{
			result = true;
		}
	}

	return result;
}

void Line::print()
{
	DynamicChar buff;
	buff += getShapeNum();
	buff += ". ";
	buff += getPolygonTypeStr(getPolyType());
	buff += " ";
	buff += x1;
	buff += " ";
	buff += x2;
	buff += " ";
	buff += y1;
	buff += " ";
	buff += y2;
	buff += " ";
	buff += getColorStr(getShapeColor());

	std::cout << buff.getChar() << endl;
}

void Line::copyObject(const float tmpX1, const float tmpX2, const float tmpY1, const float tmpY2, const unsigned tmpNum, const Color tmpStroke, const Color tmpFill, const float tmpStrokeWidth)
{
	x1 = tmpX1;
	x2 = tmpX2;
	y1 = tmpY1;
	y2 = tmpY2;
	setValues(tmpNum, line, tmpStroke, tmpFill, tmpStrokeWidth);
}

void Line::clearObject()
{

}