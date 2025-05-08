#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <numeric>
#include <cmath>

using namespace std;

class Fraction {
private:
    int whole_part; // целая часть
    int numerator; // числитель
    int denominator; // знаменатель

    int sign; // знак дроби (-1 или 1)

    static const int N_DEC = 4;  // Точность (4 знака после запятой)
public:
    void set_whole_part(int new_whole_part);
    void set_numerator(int new_numerator);
    void set_denominator(int new_denominator);

    Fraction(); // конструктор по умолчанию
    Fraction(int num, int denom); // конструктор для известных числителя и знаменателя
    Fraction(const char* input); // конструктор от строки
    Fraction(const Fraction& frac); // конструктор копирования
    Fraction(double num);

    Fraction(int w, int n, int d, int s); // для создания дроби при сложении дробей

    friend istream& operator >> (istream& in, Fraction& frac); // перегрузка ввода
    friend ostream& operator << (ostream& out, Fraction& frac); // перегрузка вывода

    friend Fraction operator + (Fraction& f1, Fraction& f2);		// дробь + дробь
	friend Fraction operator + (Fraction& frac, int num);		// дробь + целое
	friend Fraction operator + (int num, Fraction& frac);		// целое + дробь
	friend Fraction operator + (Fraction& frac, double num);	// дробь + double
	friend Fraction operator + (double num, Fraction& frac);	// doible + дробь

	Fraction operator += (Fraction frac);	// прибавление дроби к дроби
	Fraction operator += (int num);				// прибавление числа к дроби
	Fraction operator += (double num);			// прибавление double к дроби
};

#endif //FRACTION_H
