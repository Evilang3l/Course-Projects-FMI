#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include "Colors.h"
#include "ShapeTypes.h"
#include "DynamicChar.h"
#include <iostream>

class Shape
{
protected:
	//пореден номер на фигура
	unsigned num;

	//тип на фигурата
	ShapeType type;

	//цвят на външната линия, с която е нарисувана фигурата
	Color stroke;

	//цвят на вътрешността на фигурата
	Color fill;

	//дебелина на линията, с която фигурата е нарисувана
	float strokeWidth;

public:
	virtual ~Shape() = 0;
	Shape& operator=(const Shape&);

	//Функция, която връща char* от подаден тип фигура
	friend char* getPolygonTypeStr(const ShapeType);

	//Връша типа на текущата фигура
	ShapeType getPolyType();

	//Връша цвета на текушата фигура
	const Color getShapeColor();

	void setValues(const unsigned, const ShapeType, const Color, const Color, const float);

	//Всяка фигура си има номер, тази функция го връща
	const unsigned getShapeNum();

	virtual void translate(float, float) = 0;

	//Функция, която проверява дали фигурата е в кръг
	virtual bool isWithin(float, float, float) = 0;

	//Функция, която проверява дали фигурата е в правоъгълник
	virtual bool isWithin(float, float, float, float) = 0;

	//Създава char* съдържащ property-тата на фигурите
	virtual char* generateSvgLines();

	//Създава валиден svg ред, който описва фигурата
	virtual char* makeSvg() = 0;

	//Изписва фигурат на ред в конзолата
	virtual void print() = 0;

	//Връща бройката на всички заредени вигури
	const unsigned getTotalShapes() { return totalShapes; };
	void setTotalShapes(const unsigned);

	//Връща цвят по зададен char*
	friend Color getColorFromStr(const char*);

	//Връща char* по зададен цвят
	friend char* getColorStr(const Color);

private:
	//Променлива, която отброява всички заредени фигури
	static unsigned totalShapes;

};

#endif // !SHAPE_HEADER
