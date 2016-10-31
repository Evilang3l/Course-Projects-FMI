#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include "Colors.h"
#include "ShapeTypes.h"
#include "DynamicChar.h"
#include <iostream>

class Shape
{
protected:
	//������� ����� �� ������
	unsigned num;

	//��� �� ��������
	ShapeType type;

	//���� �� �������� �����, � ����� � ���������� ��������
	Color stroke;

	//���� �� ������������ �� ��������
	Color fill;

	//�������� �� �������, � ����� �������� � ����������
	float strokeWidth;

public:
	virtual ~Shape() = 0;
	Shape& operator=(const Shape&);

	//�������, ����� ����� char* �� ������� ��� ������
	friend char* getPolygonTypeStr(const ShapeType);

	//����� ���� �� �������� ������
	ShapeType getPolyType();

	//����� ����� �� �������� ������
	const Color getShapeColor();

	void setValues(const unsigned, const ShapeType, const Color, const Color, const float);

	//����� ������ �� ��� �����, ���� ������� �� �����
	const unsigned getShapeNum();

	virtual void translate(float, float) = 0;

	//�������, ����� ��������� ���� �������� � � ����
	virtual bool isWithin(float, float, float) = 0;

	//�������, ����� ��������� ���� �������� � � ������������
	virtual bool isWithin(float, float, float, float) = 0;

	//������� char* �������� property-���� �� ��������
	virtual char* generateSvgLines();

	//������� ������� svg ���, ����� ������ ��������
	virtual char* makeSvg() = 0;

	//������� ������� �� ��� � ���������
	virtual void print() = 0;

	//����� �������� �� ������ �������� ������
	const unsigned getTotalShapes() { return totalShapes; };
	void setTotalShapes(const unsigned);

	//����� ���� �� ������� char*
	friend Color getColorFromStr(const char*);

	//����� char* �� ������� ����
	friend char* getColorStr(const Color);

private:
	//����������, ����� �������� ������ �������� ������
	static unsigned totalShapes;

};

#endif // !SHAPE_HEADER
