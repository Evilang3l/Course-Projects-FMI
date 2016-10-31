#ifndef DYNAMIC_CHAR_HEADER
#define DYNAMIC_CHAR_HEADER

#include <cstring>
#include <fstream>

using namespace std;
class DynamicChar
{
public:
	DynamicChar();
	~DynamicChar();
	DynamicChar& operator= (const char*);
	DynamicChar& operator+= (const char*);
	DynamicChar& operator+=(const char);
	DynamicChar& operator+= (const int);
	DynamicChar& operator+= (const unsigned);
	DynamicChar& operator+= (const float);
	char* getChar() const;
	int getSize();

private:
	void appendCharSeq(const char*);
	char* pArr;
	int size;

};

#endif // !DYNAMIC_CHAR_HEADER