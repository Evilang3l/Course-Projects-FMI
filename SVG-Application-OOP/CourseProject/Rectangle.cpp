#include "Rectangle.h"

Rectangle::Rectangle()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

Rectangle::Rectangle(const Rectangle& other)
{
	copyObject(other.x, other.y, other.width, other.height, other.num, other.stroke, other.fill, other.strokeWidth);
}

Rectangle::Rectangle(const float tmpX, const float tmpY, const float tmpWidth, const float tmpHeight, const unsigned tmpNum, const Color tmpStroke, const Color tmpFill, const float tmpStrokeWidth)
{
	copyObject(tmpX, tmpY, tmpWidth, tmpHeight, tmpNum, tmpStroke, tmpFill, tmpStrokeWidth);
}

Rectangle::~Rectangle()
{
	clearObject();
}

char* Rectangle::makeSvg()
{
	char* endOfStr = generateSvgLines();
	
	DynamicChar buff;
	buff += "<";
	buff += getPolygonTypeStr(getPolyType());
	buff += " x=\"";
	buff += x;
	buff += "\" y=\"";
	buff += y;
	buff += "\" width=\"";
	buff += width;
	buff += "\" height=\"";
	buff += height;
	buff += "\"";
	buff += endOfStr;

	int resultSize = buff.getSize() + 1;
	char* result = new char[resultSize];
	strcpy(result, buff.getChar());
	return result;
}

void Rectangle::translate(float x, float y)
{
	this->x += x;
	this->y += y;
}

bool Rectangle::isWithin(float cx, float cy, float r)
{
	bool result = false;

	if (this->x >= cx - r && this->y >= cy - r)
	{
		if (this->x + this->width <= cx + r && this->y + this->height <= cy + r)
		{
			result = true;
		}
	}

	return result;
}

bool Rectangle::isWithin(float x, float y, float width, float height)
{
	bool result = false;

	if (this->x + this->width <= x + width)
	{
		if (this->y + this->height <= y + height)
		{
			result = true;
		}
	}

	return result;
}

void Rectangle::print()
{
	DynamicChar buff;
	buff += getShapeNum();
	buff += ". ";
	buff += getPolygonTypeStr(getPolyType());
	buff += " ";
	buff += x;
	buff += " ";
	buff += y;
	buff += " ";
	buff += width;
	buff += " ";
	buff += height;
	buff += " ";
	buff += getColorStr(getShapeColor());

	std::cout << buff.getChar() << endl;
}

void Rectangle::copyObject(const float tmpX, const float tmpY, const float tmpWidth, const float tmpHeight, const unsigned tmpNum, const Color tmpStroke, const Color tmpFill, const float tmpStrokeWidth)
{
	x = tmpX;
	y = tmpY;
	width = tmpWidth;
	height = tmpHeight;
	setValues(tmpNum, rectangle, tmpStroke, tmpFill, tmpStrokeWidth);
}

void Rectangle::clearObject()
{

}