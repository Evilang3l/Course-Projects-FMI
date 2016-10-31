#ifndef PARSER_HEADER
#define PARSER_HEADER

#include <cstring>
#include "Colors.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Line.h"

namespace parser {
	
	Shape* parseLine(char*, unsigned);

	Shape* parseLine(char* line, unsigned currShapeNum)
	{
		if (strstr(line, "circle"))
		{
			char* parsed = strtok(line, "< >/\"=");
			float cx, cy, r, strokeWidth;
			Color fill, stroke;
			while (parsed != NULL)
			{
				parsed = strtok(NULL, "< >/\"=");
				if (parsed != NULL)
				{
					if (!strcmp(parsed, "cx"))
					{
						parsed = strtok(NULL, "< >/\"=");
						cx = float(atof(parsed));
					}
					if (!strcmp(parsed, "cy"))
					{
						parsed = strtok(NULL, "< >/\"=");
						cy = float(atof(parsed));
					}
					if (!strcmp(parsed, "r"))
					{
						parsed = strtok(NULL, "< >/\"=");
						r = float(atof(parsed));
					}
					if (!strcmp(parsed, "stroke-width"))
					{
						parsed = strtok(NULL, "< >/\"=");
						strokeWidth = float(atof(parsed));
					}
					if (!strcmp(parsed, "fill"))
					{
						parsed = strtok(NULL, "< >/\"=");
						fill = getColorFromStr(parsed);
					}
					if (!strcmp(parsed, "stroke"))
					{
						parsed = strtok(NULL, "< >/\"=");
						stroke = getColorFromStr(parsed);
					}
				}
			}

			return new Circle(cx, cy, r, currShapeNum, stroke, fill, strokeWidth);
		}
		else if (strstr(line, "rect"))
		{
			char* parsed = strtok(line, "< >/\"=");
			float x, y, width, height, strokeWidth;
			Color fill, stroke;
			while (parsed != NULL)
			{
				parsed = strtok(NULL, "< >/\"=");
				if (parsed != NULL)
				{
					if (!strcmp(parsed, "x"))
					{
						parsed = strtok(NULL, "< >/\"=");
						x = float(atof(parsed));
					}
					if (!strcmp(parsed, "y"))
					{
						parsed = strtok(NULL, "< >/\"=");
						y = float(atof(parsed));
					}
					if (!strcmp(parsed, "width"))
					{
						parsed = strtok(NULL, "< >/\"=");
						width = float(atof(parsed));
					}
					if (!strcmp(parsed, "height"))
					{
						parsed = strtok(NULL, "< >/\"=");
						height = float(atof(parsed));
					}
					if (!strcmp(parsed, "stroke-width"))
					{
						parsed = strtok(NULL, "< >/\"=");
						strokeWidth = float(atof(parsed));
					}
					if (!strcmp(parsed, "fill"))
					{
						parsed = strtok(NULL, "< >/\"=");
						fill = getColorFromStr(parsed);
					}
					if (!strcmp(parsed, "stroke"))
					{
						parsed = strtok(NULL, "< >/\"=");
						stroke = getColorFromStr(parsed);
					}
				}
			}

			return new Rectangle(x, y, width, height, currShapeNum, stroke, fill, strokeWidth);
		}
		else if (strstr(line, "ellipse"))
		{
			char* parsed = strtok(line, "< >/\"=");
			float cx, cy, rx, ry, strokeWidth;
			Color fill, stroke;
			while (parsed != NULL)
			{
				parsed = strtok(NULL, "< >/\"=");
				if (parsed != NULL)
				{
					if (!strcmp(parsed, "cx"))
					{
						parsed = strtok(NULL, "< >/\"=");
						cx = float(atof(parsed));
					}
					if (!strcmp(parsed, "cy"))
					{
						parsed = strtok(NULL, "< >/\"=");
						cy = float(atof(parsed));
					}
					if (!strcmp(parsed, "rx"))
					{
						parsed = strtok(NULL, "< >/\"=");
						rx = float(atof(parsed));
					}
					if (!strcmp(parsed, "ry"))
					{
						parsed = strtok(NULL, "< >/\"=");
						ry = float(atof(parsed));
					}
					if (!strcmp(parsed, "stroke-width"))
					{
						parsed = strtok(NULL, "< >/\"=");
						strokeWidth = float(atof(parsed));
					}
					if (!strcmp(parsed, "fill"))
					{
						parsed = strtok(NULL, "< >/\"=");
						fill = getColorFromStr(parsed);
					}
					if (!strcmp(parsed, "stroke"))
					{
						parsed = strtok(NULL, "< >/\"=");
						stroke = getColorFromStr(parsed);
					}
				}
			}

			return new Ellipse(cx, cy, rx, ry, currShapeNum, stroke, fill, strokeWidth);
		}
		else if (strstr(line, "line") && strstr(line, "polyline") == NULL)
		{
			char* parsed = strtok(line, "< >/\"=");
			float x1, x2, y1, y2, strokeWidth;
			Color fill, stroke;
			while (parsed != NULL)
			{
				parsed = strtok(NULL, "< >/\"=");
				if (parsed != NULL)
				{
					if (!strcmp(parsed, "x1"))
					{
						parsed = strtok(NULL, "< >/\"=");
						x1 = float(atof(parsed));
					}
					if (!strcmp(parsed, "x2"))
					{
						parsed = strtok(NULL, "< >/\"=");
						x2 = float(atof(parsed));
					}
					if (!strcmp(parsed, "y1"))
					{
						parsed = strtok(NULL, "< >/\"=");
						y1 = float(atof(parsed));
					}
					if (!strcmp(parsed, "y2"))
					{
						parsed = strtok(NULL, "< >/\"=");
						y2 = float(atof(parsed));
					}
					if (!strcmp(parsed, "stroke-width"))
					{
						parsed = strtok(NULL, "< >/\"=");
						strokeWidth = float(atof(parsed));
					}
					if (!strcmp(parsed, "fill"))
					{
						parsed = strtok(NULL, "< >/\"=");
						fill = getColorFromStr(parsed);
					}
					if (!strcmp(parsed, "stroke"))
					{
						parsed = strtok(NULL, "< >/\"=");
						stroke = getColorFromStr(parsed);
					}
				}
			}

			return new Line(x1, x2, y1, y2, currShapeNum, stroke, fill, strokeWidth);
		}
		else
		{
			return nullptr;
		}
	}
}

#endif // !PARSER_HEADER