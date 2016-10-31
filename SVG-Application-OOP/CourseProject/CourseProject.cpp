#include "DynamicChar.h"
#include "Parser.h"

using namespace std;
using namespace parser;

//Брояч за текуща фигура
unsigned currShape = 1;

//Масив от фигури
Shape** shapes = nullptr;

bool isReadingFromFile = false;

//Функция, която прочита svg файл и
//създава фигурите, описани в нея
void readFile(char*);

//Функция, която добавя фигура в масивът от фигури
void addShape(Shape*);

//Функция, записваща фигурите във файл посочен от нас, или текушия отворен
void saveFile(char*);

//Функция, която чисти паметта, заета от масивът фигури
void clear();

//Функция, която извежда на екрана всички фигури
void print();

//Функция, която съзава нова фигура, създадена от текст
void create(char*);

//Функция, която транслира фигура (ако е посочена такава) или всички
void translateShape(char*);

//Функция, която премахва фигура от масивът с фигури
void removeShape(unsigned);

//Функция, която проверява дали има фигури, лежащи в тази, която е посочена
void checkWithin(char*);

int main(){

	//Флагът се вдига, когато въведем команда ">exit" и изключва програмата
	bool isCommandExit = false;

	//Променлива, в която записваме името не текущия файл, с който работим
	char* fileName = nullptr;

	//Меню
	while (!isCommandExit)
	{
		//Взимаме въведените данни
		char* input = new (nothrow) char[1024];
		cin.getline(input, 1024);

		//Според въведения текст програмата определя коя функция да извика
		//и ако тя не фигурира - не прави нищо а очаква нова команда
		if (input[0] == '>')
		{
			if (strstr(input, "create"))
			{
				isReadingFromFile = false;
				create(input);
			}
			else if (strstr(input, "print"))
			{
				if (shapes != nullptr)
				{
					print();
				}
				else
				{
					cout << "Nothing to print!" << endl;
				}
			}
			else if (strstr(input, "erase"))
			{
				if (shapes != nullptr)
				{
					char* tmp = strtok(input, " >erase");
					if (tmp != NULL)
					{
						removeShape(atoi(tmp));
					}
				}
				else
				{
					cout << "There is nothing to erase!" << endl;
				}
			}
			else if (strstr(input, "translate"))
			{
				if (shapes != nullptr)
				{
					translateShape(input);
				}
				else
				{
					cout << "There is nothing to translate!" << endl;
				}
			}
			else if (strstr(input, "within"))
			{
				if (shapes != nullptr)
				{
					checkWithin(input);
				}
				else
				{
					cout << "There are no figures loaded!" << endl;
				}
			}
			else if (strstr(input, "open"))
			{
				isReadingFromFile = true;
				char* tmp = strtok(input, " >");
				while (tmp != NULL)
				{
					if (strcmp(tmp, "open"))
					{
						tmp = strtok(NULL, " >");
					}
					if (tmp != NULL)
					{
						if (!strcmp(tmp, "open"))
						{
							tmp = strtok(NULL, " >");
							if (tmp != NULL)
							{
								fileName = tmp;
								break;
							}
						}
					}
				}
				tmp = nullptr;

				readFile(fileName);
			}
			else if (strstr(input, "save") && strstr(input, "as") == NULL)
			{
				if (fileName != nullptr)
				{
					saveFile(fileName);
				}
				else
				{
					cout << "You have not opened any file!" << endl;
				}
			}
			else if (strstr(input, "save as"))
			{
				char* tmp = strtok(input, " >");
				while (tmp != NULL)
				{
					tmp = strtok(NULL, " >");
					if (tmp != NULL)
					{
						if (!strcmp(tmp, "as"))
						{
							tmp = strtok(NULL, " >");
							fileName = tmp;
							break;
						}
					}
				}
				tmp = nullptr;

				if (shapes != nullptr)
				{
					saveFile(fileName);
				}
				else
				{
					cout << "You dont have a current opened file and you have nothing to save!" << endl;
				}
				
			}
			else if (strstr(input, "close"))
			{
				if (shapes != nullptr)
				{
					clear();
					cout << "Successfully closed " << fileName << endl;
				}
				else
				{
					cout << "First open a file, then close one!" << endl;
				}
			}
			else if (strstr(input, "exit"))
			{
				if (shapes != nullptr)
				{
					clear();
				}
				isCommandExit = true;
			}
			else
			{
				cout << "Your command was found not allowed in this program!" << endl;
			}
		}
		else
		{
			cout << "Commands begin with > at first symbol!" << endl;
		}
	}
    return 0;
}

//Обработката на въведените данни става като дума по дума
//разпределим данните в правилните полета или обекти.
//Всяка обработка на въведени данни се прави аналогично.

void checkWithin(char* input)
{
	if (strstr(input, "within"))
	{
		char* parsed = strtok(input, "> ");
		while (parsed != NULL)
		{
			bool anyShapes = false;
			DynamicChar buff;
			parsed = strtok(NULL, "> ");
			if (parsed != NULL)
			{
				bool isCircle = false;
				if (!strcmp(parsed, "rectangle"))
				{
					float x, y, width, height;
					parsed = strtok(NULL, "> ");
					x = float(atof(parsed));
					parsed = strtok(NULL, "> ");
					y = float(atof(parsed));
					parsed = strtok(NULL, "> ");
					width = float(atof(parsed));
					parsed = strtok(NULL, "> ");
					height = float(atof(parsed));

					buff += x;
					buff += " ";
					buff += y;
					buff += " ";
					buff += width;
					buff += " ";
					buff += height;
					buff += " ";

					for (size_t i = 0; i < shapes[0]->getTotalShapes(); i++)
					{
						if (shapes[i]->isWithin(x, y, width, height))
						{
							shapes[i]->print();
						}
					}
				}
				if (!strcmp(parsed, "circle"))
				{
					isCircle = true;
					float cx, cy, r;
					parsed = strtok(NULL, "> ");
					cx = float(atof(parsed));
					parsed = strtok(NULL, "> ");
					cy = float(atof(parsed));
					parsed = strtok(NULL, "> ");
					r = float(atof(parsed));

					buff += cx;
					buff += " ";
					buff += cy;
					buff += " ";
					buff += r;
					buff += " ";

					anyShapes = false;

					for (size_t i = 0; i < shapes[0]->getTotalShapes(); i++)
					{
						if (shapes[i]->isWithin(cx, cy, r))
						{
							shapes[i]->print();
							anyShapes = true;
						}
					}
				}

				if (!anyShapes)
				{
					if (isCircle)
					{
						cout << "No figures are located within circle " << buff.getChar() << endl;
					}
					else
					{
						cout << "No figures are located within rectangle " << buff.getChar() << endl;
					}
				}
			}
		}
	}
}

void readFile(char* fileName)
{
	fstream file;
	file.open(fileName, ios::in);

	if (!file)
	{
		cout << "Could not find file with name " << fileName << endl;
	}
	else
	{
		file.seekg(0, ios::end);
		streampos end = file.tellg();
		unsigned lenght = (unsigned)(end);
		file.seekg(0, ios::beg);

		//Флагът се вдига само като четем фигури от файл
		//Иначе не ни интересува какво пише, защото при записът
		//Винаги се създава валиден svg файл
		bool isReadingSvg = false;

		while (!file.eof())
		{
			char* buff = new (nothrow) char[lenght + 1];
			file.getline(buff, lenght, '\n');
			if (strstr(buff, "</svg"))
			{
				isReadingSvg = false;
			}
			if (strstr(buff, "/>") == NULL && isReadingSvg && strcmp(buff, ""))
			{
				//Може данните за една фигура да са написани на 2 реда,
				//затова ако този ред не съдържа "/>" четем и следващия
				DynamicChar tmp;
				tmp += buff;
				delete[] buff;
				buff = new (nothrow) char[lenght + 1];
				file.getline(buff, lenght, '\n');
				tmp += buff;
				strcpy(buff, tmp.getChar());
			}
			if (strstr(buff, "<svg") != NULL)
			{
				isReadingSvg = true;
			}

			//Всеки ред минава през разбиване
			Shape* tmp = parseLine(buff, currShape);

			if (tmp != nullptr)
			{
				addShape(tmp);
			}

		}
		cout << "Successfully opened " << fileName << endl;
	}
	file.close();
}



void addShape(Shape* tmp)
{
	if (shapes != nullptr)
	{
		//Създава временен масив от фигури с размер 1 по-голям,
		//копира всичко досега и добава една нова
		unsigned total = shapes[0]->getTotalShapes();
		Shape** tmpShapes = new Shape*[total];
		for (size_t i = 0; i < total; i++)
		{
			tmpShapes[i] = shapes[i];
		}
		tmpShapes[total - 1] = tmp;

		shapes = tmpShapes;
		tmpShapes = nullptr;
	}
	else
	{
		shapes = new Shape*[1];
		shapes[0] = tmp;
	}
	currShape++;
	if (!isReadingFromFile)
	{
		//Изписва го само когато създаваме нова фигура чрез комапнда, а не докато чете от файл
		cout << "Successfully created " << getPolygonTypeStr(tmp->getPolyType()) << " (" << tmp->getShapeNum() << ")" << endl;
	}
}

void saveFile(char* fileName)
{
	DynamicChar buff;
	//Записваме валиден хедър на файла. Така той ще бъде винаги валиден
	buff += "<?xml version=\"1.0\"?> \n <svg xmlns = \"http://www.w3.org/2000/svg\"> \n";
	for (size_t i = 0; i < shapes[0]->getTotalShapes(); i++)
	{
		//Една по една записваме фигурите на отелни редове
		buff += shapes[i]->makeSvg();
		buff += "\n";
	}
	buff += "</svg>";

	fstream saveFile;
	saveFile.open(fileName, ios::trunc | ios::out);

	saveFile.write(buff.getChar(), buff.getSize());
	cout << "Successfully saved " << fileName << endl;
}

void clear()
{
	for (size_t i = 0; i < shapes[0]->getTotalShapes(); i++)
	{
		delete[] shapes[i];
	}
	
	shapes = nullptr;
}

void print()
{
	for (size_t i = 0; i < shapes[0]->getTotalShapes(); i++)
	{
		shapes[i]->print();
	}
}

void translateShape(char* input)
{
	if (strstr(input, "translate"))
	{
		float x, y;
		unsigned shapeNum = currShape + 1;

		char* parsed = strtok(input, "> ");
		while (parsed != NULL)
		{
			parsed = strtok(NULL, "> ");
			if (parsed != NULL)
			{
				if (atoi(parsed))
				{
					shapeNum = atoi(parsed);
				}
				if (strstr(parsed, "vertical="))
				{
					char* tmp = new (nothrow) char[32];
					for (size_t i = 9; i < strlen(parsed); i++)
					{
						tmp[i - 9] = parsed[i];
					}
					tmp[strlen(parsed) - 9] = '\0';
					y = float(atof(tmp));
					delete[] tmp;
				}
				if (strstr(parsed, "horizontal="))
				{
					char* tmp = new (nothrow) char[32];
					for (size_t i = 11; i < strlen(parsed); i++)
					{
						tmp[i - 11] = parsed[i];
					}
					tmp[strlen(parsed) - 11] = '\0';
					x = float(atof(tmp));
					delete[] tmp;
				}
			}
		}

		if (shapeNum == currShape + 1)
		{
			for (size_t i = 0; i < shapes[0]->getTotalShapes(); i++)
			{
				shapes[i]->translate(x, y);
			}
		}
		else
		{
			unsigned index = currShape + 1;
			for (size_t i = 0; i < shapes[0]->getTotalShapes(); i++)
			{
				if (shapes[i]->getShapeNum() == shapeNum)
				{
					index = i;
					break;
				}
			}

			if (index != currShape + 1)
			{
				shapes[index]->translate(x, y);
			}
			else
			{
				cout << "There is no figure number " << shapeNum << " to translate!" << endl;
			}
		}
	}
}

void create(char* text)
{
	if (strstr(text, "rectangle"))
	{
		float x, y, width, height;
		Color fill;
		unsigned counter = 0;
		
		char* parsed = strtok(text, "> create rectangle");
		while (parsed != NULL)
		{
			if (strcmp(parsed, "create") && strcmp(parsed, "rectangle"))
			{
				if (counter == 0)
				{
					x = float(atof(parsed));
				}
				if (counter == 1)
				{
					y = float(atof(parsed));
				}
				if (counter == 2)
				{
					width = float(atof(parsed));
				}
				if (counter == 3)
				{
					height = float(atof(parsed));
				}
				if (counter == 4)
				{
					fill = getColorFromStr(parsed);
				}
				counter++;
			}
			parsed = strtok(NULL, "> ");
		}
		addShape(new Rectangle(x, y, width, height, currShape, fill, fill, 1));
	}
	else if (strstr(text, "circle"))
	{
		float cx, cy, r;
		Color fill;
		unsigned counter = 0;

		char* parsed = strtok(text, "> create circle");
		while (parsed != NULL)
		{
			if (strcmp(parsed, "create") && strcmp(parsed, "circle"))
			{
				if (counter == 0)
				{
					cx = float(atof(parsed));
				}
				if (counter == 1)
				{
					cy = float(atof(parsed));
				}
				if (counter == 2)
				{
					r = float(atof(parsed));
				}
				if (counter == 3)
				{
					fill = getColorFromStr(parsed);
				}
				counter++;
			}
			parsed = strtok(NULL, "> ");
		}
		addShape(new Circle(cx, cy, r, currShape, fill, fill, 1));
	}
	else if (strstr(text, "ellipse"))
	{
		float cx, cy, rx, ry;
		Color fill;
		unsigned counter = 0;

		char* parsed = strtok(text, "> create ellipse");
		while (parsed != NULL)
		{
			if (strcmp(parsed, "create") && strcmp(parsed, "ellipse"))
			{
				if (counter == 0)
				{
					cx = float(atof(parsed));
				}
				if (counter == 1)
				{
					cy = float(atof(parsed));
				}
				if (counter == 2)
				{
					rx = float(atof(parsed));
				}
				if (counter == 3)
				{
					ry = float(atof(parsed));
				}
				if (counter == 4)
				{
					fill = getColorFromStr(parsed);
				}
				counter++;
			}
			parsed = strtok(NULL, "> ");
		}
		addShape(new Ellipse(cx, cy, rx, ry, currShape, fill, fill, 1));
	}
	else if (strstr(text, "line"))
	{
		float x1, x2, y1, y2;
		Color fill;
		unsigned counter = 0;

		char* parsed = strtok(text, "> create line");
		while (parsed != NULL)
		{
			if (strcmp(parsed, "create") && strcmp(parsed, "line"))
			{
				if (counter == 0)
				{
					x1 = float(atof(parsed));
				}
				if (counter == 1)
				{
					y1 = float(atof(parsed));
				}
				if (counter == 2)
				{
					x2 = float(atof(parsed));
				}
				if (counter == 3)
				{
					y2 = float(atof(parsed));
				}
				if (counter == 4)
				{
					fill = getColorFromStr(parsed);
				}
				counter++;
			}
			parsed = strtok(NULL, "> ");
		}
		addShape(new Line(x1, y1, x2, y2, currShape, fill, fill, 1));
	}
	else
	{
		cout << "The program can't create such figure :(" << endl;
	}
}

void removeShape(unsigned index)
{
	if (shapes != nullptr)
	{
		unsigned shapesSize = shapes[0]->getTotalShapes();
		unsigned eraseInd = shapesSize + 1;
		for (size_t i = 0; i < shapesSize; i++)
		{
			if (shapes[i]->getShapeNum() == index)
			{
				eraseInd = i;
				break;
			}
		}

		if (eraseInd != shapesSize + 1)
		{
			Shape** tmpShapes = new (nothrow) Shape*[currShape - 2];

			for (size_t i = 0; i < eraseInd; i++)
			{
				tmpShapes[i] = shapes[i];
			}

			for (size_t i = eraseInd + 1; i < currShape - 1; i++)
			{
				tmpShapes[i - 1] = shapes[i];
			}

			Shape* tmpShape = shapes[eraseInd];

			shapes = new (nothrow) Shape*[currShape - 2];

			shapes[0]->setTotalShapes(shapesSize - 1);
			currShape--;

			for (size_t i = 0; i < shapesSize - 1; i++)
			{
				shapes[i] = tmpShapes[i];
			}

			cout << "Erased a " << getPolygonTypeStr(tmpShape->getPolyType()) << " (" << tmpShape->getShapeNum() << ")" << endl;
		}
		else
		{
			cout << "There is no figure number " << index << endl;
		}
	}
	else
	{
		cout << "There is no figure number " << index << endl;
	}
}