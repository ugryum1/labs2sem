#include "planetLib.h"

// int Planet::counter = 0;

Planet::Planet() {
	// counter++;
    // id = counter;
	pName = new char[1];
	strcpy(pName, "");
	// cout << "Создание ID " << id << endl;
}

Planet::Planet(const Planet& p) {
	// counter++;
    // id = counter;
	pName = new char[strlen(p.pName) + 1];
	*this = p;
	// cout << "Создание ID " << id << " (копия ID " << p.id << ")" << endl;
}

Planet::~Planet() {
	// cout << "Удаление ID " << id << endl;
	delete[] pName;
}

char* Planet::getName() const {
	return pName;
}

int Planet::getD() const {
	return d;
}

bool Planet::getLife() const {
	return life;
}

int Planet::getS() const {
	return s;
}

void Planet::setName(char* new_name) {
    if (pName != nullptr) {
        delete[] pName;
    }
	pName = nullptr;

	pName = new char[strlen(new_name) + 1];
	strcpy(pName, new_name);
}

void Planet::setD(int new_d) {
	d = new_d;
}

void Planet::setLife(bool new_life) {
	life = new_life;
}

void Planet::setS(int new_s) {
	s = new_s;
}

void Planet::show() const{
    cout << pName << ' ' << d << ' ' << life << ' ' << s << endl;
}

istream& operator >> (istream& in, Planet& planet)
{
	char name[30];
	in >> name >> planet.d >> planet.life >> planet.s;
	planet.setName(name);
	return in;
}

ostream& operator << (ostream& out, Planet& planet)
{
	out << planet.pName << ' ' << planet.d << ' ' << planet.life << ' ' << planet.s;
	return out;
}

bool operator < (Planet& p1, Planet& p2)
{
	return strcmp(p1.pName, p2.pName) < 0;
}

bool operator == (Planet& p1, Planet& p2)
{
	return strcmp(p1.pName, p2.pName) == 0;
}

Planet& Planet::operator = (const Planet& p)
{
	if (this == &p)
		return *this;

	setName(p.pName);
	d = p.d;
	life = p.life;
	s = p.s;
	return *this;
}
