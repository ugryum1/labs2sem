#include "fraction.h"

void Fraction::set_whole_part(int new_whole_part) {
    whole_part = new_whole_part;
}

void Fraction::set_numerator(int new_numerator) {
    numerator = new_numerator;
}

void Fraction::set_denominator(int new_denominator) {
    denominator = new_denominator;
}

Fraction::Fraction() {
    whole_part = 0;
    numerator = 0;
    denominator = 1;
    sign = 1;
}

Fraction::Fraction(int num, int denom) {
    if (denominator == 0) {
        cerr << "Знаменатель не может быть нулём." << endl;
        return;
    }
    whole_part = 0;
    numerator = num;
    denominator = denom;
    sign = 1;
}

Fraction::Fraction(const char* input) {
    std::istringstream iss(input);
    iss >> *this; // Используем перегруженный оператор >>
}

Fraction::Fraction(const Fraction& frac) {
    whole_part = frac.whole_part;
    numerator = frac.numerator;
    denominator = frac.denominator;
    sign = frac.sign;
}

Fraction::Fraction(double num) {
	sign = (num < 0) ? -1 : 1;
    num = abs(num);
    whole_part = static_cast<int>(num);
    double frac_part = num - whole_part;
    numerator = static_cast<int>(round(frac_part * pow(10, N_DEC)));
    denominator = pow(10, N_DEC);
}

Fraction::Fraction(int w, int n, int d, int s) {
    whole_part = w;
    numerator = n;
    denominator = d;
    sign = s;
}

istream& operator >> (istream& in, Fraction& frac) {
    char s[100];
    in.getline(s, 100);

    int arr[3] = {0, 0, 1};
    int count = 0;
    bool inword = false;
    int a = 0; // номер первой цифры числа
    int b = 0; // номер последней цифры числа
    int start_last_number = 0; // номер сивмола - начала последнего числа
    int end_prev_last_number = 0; // номер символа - конца предпоследнего числа

    // разбиение ввода на числа
    for (int i = 0; i < strlen(s); ++i) {
        if (!isdigit(s[i]) && s[i] != ' ' && s[i] != '/' && s[i] != '-') {
            cerr << "Некорректный ввод, введены посторонние символы." << endl;
            return in;
        }

        if ((s[i] == '-' || isdigit(s[i]))) {
            if (!inword) {
                inword = true;
                a = i;
                start_last_number = i;
                if (i == strlen(s) - 1) { // если последний символ строки - начало нового числа
                    inword = false;
                    ++count;
                    if (count > 3) {
                        cerr << "Некорректный ввод, слишком много чисел." << endl;
                        return in;
                    }

                    end_prev_last_number = b - 1;
                    b = i + 1;
                    char temp[100];
                    strncpy(temp, s + a, b - a);
                    temp[b - a] = '\0';

                    arr[count - 1] = atoi(temp);
                }
                continue;
            } else {
                if (s[i] == '-') {
                    cerr << "Некорректный ввод." << endl;
                    return in;
                }
            }
        }

        if (inword && ((s[i] == ' ') || (s[i] == '/')) || (i == strlen(s) - 1)) {
            inword = false;
            ++count;
            if (count > 3) {
                cerr << "Некорректный ввод, слишком много чисел." << endl;
                return in;
            }

            end_prev_last_number = b - 1;
            b = i;
            b = (i == strlen(s) - 1) ? (i + 1) : i;
            char temp[100];
            strncpy(temp, s + a, b - a);
            temp[b - a] = '\0';

            arr[count - 1] = atoi(temp);
        }
    }

    if ((count == 3 && arr[2] == 0) || (count == 2 && arr[1] == 0)) {
        cerr << "Некорректный ввод, знаменатель не может равняться нулю." << endl;
        return in;
    }

    // проверка знаков '/'
    int countSlash = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '/') {
            ++countSlash;
            if (countSlash > 1) {
                cerr << "Некорректный ввод, введено более одного символа '/'." << endl;
                return in;
            }
        }
    }

    if (countSlash == 0 && count > 1) {
        cerr << "Ошибка ввода, отсутствует знак деления." << endl;
        return in;
    }

    if (countSlash == 1) {
        if (count == 1) {
            cerr << "Ошибка ввода, лишний символ '/'." << endl;
            return in;
        } else {
            bool flag = false; // не найден '/' между последними двуся числами
            for (int i = end_prev_last_number + 1; i < start_last_number; ++i) {
                if (s[i] == '/') {
                    flag = true;
                }
            }

            if (!flag) {
                cerr << "Ошибка ввода, '/' стоит не в том месте." << endl;
                return in;
            }
        }
    }

    // определяем знак дроби
    if (((arr[0] < 0) + (arr[1] < 0) + (arr[2] < 0)) % 2 == 0) {
        frac.sign = 1;
    } else {
        frac.sign = -1;
    }

    // делаем дробь беззнаковой
    arr[0] = abs(arr[0]);
    arr[1] = abs(arr[1]);
    arr[2] = abs(arr[2]);

    // устанавливаем целую часть, числитель и знаменатель
    if (count == 1) {
        frac.whole_part = arr[0];
        frac.numerator = 0;
        frac.denominator = 1;
    } else if (count == 2) {
        frac.whole_part = 0;
        frac.numerator = arr[0];
        frac.denominator = arr[1];
    } else {
        frac.whole_part = arr[0];
        frac.numerator = arr[1];
        frac.denominator = arr[2];
    }

    return in;
}

ostream& operator << (ostream& out, Fraction& frac) {
    // сокращение числителя и знаменателя
    int nod = gcd(frac.numerator, frac.denominator);
    frac.numerator /= nod;
    frac.denominator /= nod;

    // переход к правильной дроби
    frac.whole_part += frac.numerator / frac.denominator;
    frac.numerator %= frac.denominator;

    if (frac.sign == -1) {
        out << '-';
    }

    if (frac.numerator == 0) {
        out << frac.whole_part;
    } else {
        if (frac.whole_part == 0) {
            out << frac.numerator << '/' << frac.denominator;
        } else {
            out << frac.whole_part << ' ' << frac.numerator << '/' << frac.denominator;
        }
    }

	return out;
}

Fraction operator + (Fraction& f1, Fraction& f2) {
    // Преобразуем обе дроби в неправильные
    int num1 = f1.sign * (f1.whole_part * f1.denominator + f1.numerator);
    int num2 = f2.sign * (f2.whole_part * f2.denominator + f2.numerator);

    // Общий знаменатель
    int common_denominator = f1.denominator * f2.denominator;
    int new_numerator = num1 * f2.denominator + num2 * f1.denominator;

    // Определяем знак результата
    int result_sign = (new_numerator >= 0) ? 1 : -1;
    new_numerator = abs(new_numerator);

    // Вычисляем целую часть и новый числитель
    int new_whole = new_numerator / common_denominator;
    int new_numer = new_numerator % common_denominator;

    return Fraction(new_whole, new_numer, common_denominator, result_sign);
}

Fraction operator + (Fraction& frac, int num) {
    Fraction second(num, 1);
	Fraction answer = frac + second;
	return answer;
}

Fraction operator + (int num, Fraction& frac) {
    Fraction first(num, 1);
	Fraction answer = first + frac;
	return answer;
}

Fraction operator + (Fraction& frac, double num) {
    Fraction second(num);
	Fraction answer = frac + second;
	return answer;
}

Fraction operator + (double num, Fraction& frac) {
    Fraction first(num);
	Fraction answer = first + frac;
	return answer;
}

Fraction Fraction::operator += (Fraction frac) {
    *this = *this + frac;
	return *this;
}

Fraction Fraction::operator += (int num) {
    *this = *this + num;
	return *this;
}

Fraction Fraction::operator += (double num) {
    *this = *this + num;
	return *this;
}
