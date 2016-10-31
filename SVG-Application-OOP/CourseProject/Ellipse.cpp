#include "Ellipse.h"

Ellipse::Ellipse()
{
	cx = 0;
	cy = 0;
	rx = 0;
	ry = 0;
}

Ellipse::Ellipse(const Ellipse& other)
{
	copyObject(other.cx, other.cy, other.rx, other.ry, other.num, other.stroke, other.fill, other.strokeWidth);
}

Ellipse::Ellipse(const float tmpCx, const float tmpCy, const float tmpRx, const float tmpRy, const unsigned tmpNum, const Color tmpStroke, const Color tmpFill, const float tmpStrokeWidth)
{
	copyObject(tmpCx, tmpCy, tmpRx, tmpRy, tmpNum, tmpStroke, tmpFill, tmpStrokeWidth);
}

Ellipse::~Ellipse()
{
	clearObject();
}

char* Ellipse::makeSvg()
{
	char* endOfStr = generateSvgLines();

	DynamicChar buff;
	buff += "<";
	buff += getPolygonTypeStr(getPolyType());
	buff += " cx=\"";
	buff += cx;
	buff += "\" cy=\"";
	buff += cy;
	buff += "\" rx=\"";
	buff += rx;
	buff += "\" ry=\"";
	buff += ry;
	buff += "\"";
	buff += endOfStr;

	int resultSize = buff.getSize() + 1;
	char* result = new char[resultSize];
	strcpy(result, buff.getChar());
	return result;
}

void Ellipse::translate(float x, float y)
{
	this->cx += x;
	this->cy += y;
}

bool Ellipse::isWithin(float cx, float cy, float r)
{
	bool result = false;

	if (this->cx + this->rx <= cx + r && this->cx - this->rx >= cx - r)
	{
		if (this->cy + this->ry <= cy + r && this->cy - this->ry >= cy - r)
		{
			result = true;
		}
	}

	return result;
}

bool Ellipse::isWithin(float x, float y, float width, float height)
{
	bool result = false;

	if (this->cx + this->rx <= x + width && this->cx - this->rx >= x)
	{
		if (this->cy + this->ry <= y + height && this->cy - this->ry >= y)
		{
			result = true;
		}
	}

	return result;
}

void Ellipse::print()
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
	buff += rx;
	buff += " ";
	buff += ry;
	buff += " ";
	buff += getColorStr(getShapeColor());

	std::cout << buff.getChar() << endl;
}

void Ellipse::copyObject(const float tmpCx, const float tmpCy, const float tmpRx, const float tmpRy, const unsigned tmpNum, const Color tmpStroke, const Color tmpFill, const float tmpStrokeWidth)
{
	cx = tmpCx;
	cy = tmpCy;
	rx = tmpRx;
	ry = tmpRy;
	setValues(tmpNum, ellipse, tmpStroke, tmpFill, tmpStrokeWidth);
}

void Ellipse::clearObject()
{

}