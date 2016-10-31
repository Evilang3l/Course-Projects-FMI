#include "DynamicChar.h"
#include <iostream>

DynamicChar::DynamicChar()
{
	pArr = nullptr;
	size = 0;
}

DynamicChar::~DynamicChar()
{
	delete[] pArr;
}

DynamicChar& DynamicChar::operator=(const char* otherArr)
{
	if (strcmp(pArr, otherArr))
	{
		delete[] pArr;
		size = 0;
		char* tmpArr = new char[strlen(otherArr) + 1];
		strcpy(pArr, otherArr);
		size = strlen(otherArr) + 1;
	}

	return *this;
}

DynamicChar& DynamicChar::operator+=(const char* otherArr)
{
	appendCharSeq(otherArr);

	return *this;
}

DynamicChar& DynamicChar::operator+=(const char otherChar)
{
	int newSize = 0;
	if (size == 0)
	{
		newSize = 1;
	}
	else
	{
		newSize = size + 1;
	}

	char* tmpArr = new char[newSize];

	if (newSize > 1)
	{
		for (int i = 0; i < size; i++)
		{
			tmpArr[i] = pArr[i];
		}
	}

	if (newSize == 1)
	{
		tmpArr[0] = otherChar;
	}
	else
	{
		tmpArr[newSize - 1] = otherChar;
	}
	
	if (newSize > 1)
	{
		tmpArr[newSize] = '\0';
	}
	else
	{
		tmpArr[1] = '\0';
	}
	
	size = strlen(tmpArr);
	pArr = tmpArr;
	tmpArr = nullptr;

	return *this;
}

DynamicChar& DynamicChar::operator+=(const int num)
{
	char* numArr = new (nothrow) char[32];
	sprintf(numArr, "%d", num);
	appendCharSeq(numArr);
	delete[] numArr;

	return *this;
}

DynamicChar& DynamicChar::operator+=(const unsigned num)
{
	char* numArr = new (nothrow) char[32];
	sprintf(numArr, "%d", num);
	appendCharSeq(numArr);
	delete[] numArr;

	return *this;
}

DynamicChar& DynamicChar::operator+=(const float num)
{
	char* numArr = new (nothrow) char[32];
	sprintf(numArr, "%.2f", num);
	appendCharSeq(numArr);
	delete[] numArr;

	return *this;
}

int DynamicChar::getSize()
{
	return size;
}

char* DynamicChar::getChar() const
{
	return pArr;
}

void DynamicChar::appendCharSeq(const char* otherArr)
{
	int newSize = 0;
	newSize = size + strlen(otherArr) + 1;

	char* tmpArr = new char[newSize];

	for (int i = 0; i < size; i++)
	{
		tmpArr[i] = pArr[i];
	}

	for (int i = size; i < newSize - 1; i++)
	{
		tmpArr[i] = otherArr[i - size];
	}

	tmpArr[newSize - 1] = '\0';
	size = strlen(tmpArr);
	pArr = tmpArr;
	tmpArr = nullptr;
}