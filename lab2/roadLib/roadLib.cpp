#include "roadLib.h"

// int Road::counter = 0;

Road::Road() {
	// counter++;
    // id = counter;
	pName = new char[1];
	strcpy(pName, "");
	// cout << "Создание ID " << id << endl;
}

Road::Road(const Road& r) {
	// counter++;
    // id = counter;
	pName = new char[strlen(r.pName) + 1];
	*this = r;
	// cout << "Создание ID " << id << " (копия ID " << r.id << ")" << endl;
}

Road::~Road() {
	// cout << "Удаление ID " << id << endl;
	delete[] pName;
}

char* Road::getName() const {
	return pName;
}

int Road::getLength() const {
	return length;
}

bool Road::getDir() const {
	return dir;
}

int Road::getStripes() const {
	return stripes;
}

void Road::setName(char* new_name) {
    //if (pName != nullptr) {
    delete[] pName;
    //}
	//pName = nullptr;

	pName = new char[strlen(new_name) + 1];
	strcpy(pName, new_name);
}

void Road::setLength(int new_length) {
	length = new_length;
}

void Road::setDir(bool new_dir) {
	dir = new_dir;
}

void Road::setStripes(int new_stripes) {
	stripes = new_stripes;
}

void Road::show() const{
    cout << pName << ' ' << length << ' ' << dir << ' ' << stripes << endl;
}

istream& operator >> (istream& in, Road& road)
{
	char name[30];
	in >> name >> road.length >> road.dir >> road.stripes;
	road.setName(name);
	return in;
}

ostream& operator << (ostream& out, Road& road)
{
	out << road.pName << ' ' << road.length << ' ' << road.dir << ' ' << road.stripes;
	return out;
}

bool operator < (Road& r1, Road& r2)
{
	return strcmp(r1.pName, r2.pName) < 0;
}

bool operator == (Road& r1, Road& r2)
{
	return strcmp(r1.pName, r2.pName) == 0;
}

Road& Road::operator = (const Road& r)
{
	if (this == &r)
		return *this;

	setName(r.pName);
	length = r.length;
	dir = r.dir;
	stripes = r.stripes;
	return *this;
}
