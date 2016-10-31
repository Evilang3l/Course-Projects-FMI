#include "Shape.h"

unsigned Shape::totalShapes = 0;

void Shape::setValues(const unsigned tmpNum, const ShapeType tmpType, const Color tmpStroke, const Color tmpFill, const float tmpWidth)
{
	num = tmpNum;
	type = tmpType;
	stroke = tmpStroke;
	fill = tmpFill;
	strokeWidth = tmpWidth;
	totalShapes ++;
}

Color getColorFromStr(const char* tmp)
{
	if (!strcmp(tmp, "red"))
	{
		return Red;
	}
	else if (!strcmp(tmp, "orange"))
	{
		return Orange;
	}
	else if (!strcmp(tmp, "yellow"))
	{
		return Yellow;
	}
	else if (!strcmp(tmp, "green"))
	{
		return Green;
	}
	else if (!strcmp(tmp, "blue"))
	{
		return Blue;
	}
	else if (!strcmp(tmp, "purple"))
	{
		return Purple;
	}
	else if (!strcmp(tmp, "pink"))
	{
		return Pink;
	}
	else if (!strcmp(tmp, "white"))
	{
		return White;
	}
	else if (!strcmp(tmp, "black"))
	{
		return Black;
	}
	else if (!strcmp(tmp, "brown"))
	{
		return Brown;
	}
	else if (!strcmp(tmp, "transparent"))
	{
		return Transperent;
	}
	else
	{
		return noColor;
	}
}

char* Shape::generateSvgLines()
{
	DynamicChar buff;
	buff += " stroke=\"";
	buff += getColorStr(stroke);
	buff += "\" fill=\"";
	buff += getColorStr(fill);
	buff += "\" stroke-width=\"";
	buff += strokeWidth;
	buff += "\" />";

	int resultSize = buff.getSize() + 1;
	char* result = new char[resultSize];
	strcpy(result, buff.getChar());
	return result;
}

void Shape::setTotalShapes(const unsigned num)
{
	totalShapes = num;
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		this->num = other.num;
		this->type = other.type;
		this->stroke = other.stroke;
		this->fill = other.fill;
		this->strokeWidth = other.strokeWidth;
	}

	return *this;
}

const Color Shape::getShapeColor()
{
	return this->fill;
}

char * getPolygonTypeStr(const ShapeType type)
{
	switch (type)
	{
	case rectangle:
		return "rect";
		break;
	case circle:
		return "circle";
		break;
	case ellipse:
		return "ellipse";
		break;
	case line:
		return "line";
		break;
	case polyLine:
		return "polyline";
		break;
	case polygon:
		return "polygon";
		break;
	default:
		return "noPoly";
		break;
	}
}

char* getColorStr(Color color)
{
	switch (color)
	{
	case Red:
		return "red";
		break;
	case Orange:
		return "orange";
		break;
	case Yellow:
		return "yellow";
		break;
	case Green:
		return "green";
		break;
	case Blue:
		return "blue";
		break;
	case Purple:
		return "purple";
		break;
	case Pink:
		return "pink";
		break;
	case White:
		return "white";
		break;
	case Black:
		return "black";
		break;
	case Brown:
		return "brown";
		break;
	case Transperent:
		return "transparent";
		break;
	default:
		return "noColor";
		break;
	}
}

ShapeType Shape::getPolyType()
{
	return type;
}

const unsigned Shape::getShapeNum()
{
	return this->num;
}

Shape::~Shape() {

}