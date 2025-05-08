#ifndef ROADLIB_H
#define ROADLIB_H

#include <iostream>
#include <cstring>

using namespace std;

class Road
{
private:
	char* pName;
	int length;
	bool dir; //направление
	int stripes; //количество полос

	// int id; // Уникальный номер объекта
    // static int counter; // Статический счетчик объектов
public:
	Road();
	Road(const Road& road); //конструктор для создания объекта класса, такого же как road
	~Road();

	char* getName() const;
	int getLength() const;
	bool getDir() const;
	int getStripes() const;

	void setName(char* new_name);
	void setLength(int new_length);
	void setDir(bool new_dir);
	void setStripes(int new_stripes);

    void show() const;

	friend istream& operator >> (istream& in, Road& road);
	friend ostream& operator << (ostream& out, Road& road);

	friend bool operator < (Road& r1, Road& r2);
	friend bool operator == (Road& r1, Road& r2);

	Road& operator = (const Road& r);
};

#endif //ROADLIB_H
