#ifndef PLANETLIB_H
#define PLANETLIB_H

#include <iostream>
#include <cstring>

using namespace std;

class Planet
{
private:
	char* pName;
	int d;
	bool life;
	int s;

	// int id; // Уникальный номер объекта
    // static int counter; // Статический счетчик объектов
public:
	Planet();
	Planet(const Planet& p); //конструктор для создания объекта класса, такого же как p
	~Planet();

	char* getName() const;
	int getD() const;
	bool getLife() const;
	int getS() const;

	void setName(char* new_name);
	void setD(int new_d);
	void setLife(bool new_life);
	void setS(int new_s);

    void show() const;

	friend istream& operator >> (istream& in, Planet& planet);
	friend ostream& operator << (ostream& out, Planet& planet);

	friend bool operator < (Planet& p1, Planet& p2);
	friend bool operator == (Planet& p1, Planet& p2);

	Planet& operator = (const Planet& p);
};

#endif //PLANETLIB_H
