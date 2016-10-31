#include "PlygonTypes.h"

char* getPolygonTypeStr(PolygonType type)
{
	switch (type)
	{
	case Rectangle:
		return "rect";
		break;
	case Circle:
		return "circle";
		break;
	case Ellipse:
		return "ellipse";
		break;
	case Line:
		return "line";
		break;
	case Polyline:
		return "polyline";
		break;
	case Polygon:
		return "polygon";
		break;
	case noPoly:
		return "noPoly";
		break;
	default:
		break;
	}
}