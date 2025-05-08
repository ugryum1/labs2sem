#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

template <class FRIEND>
class Term {
    private:
        int coef;
        int pow;
        friend FRIEND;
    public:
        Term(int c = 0, int p = 0) : coef(c), pow(p) {}

        Term(char* str) {
            std::istringstream iss(str);
            iss >> *this;
        }

        int getCoef() {
            return coef;
        }

        int getPow() {
            return pow;
        }

        void setCoef(int new_coef) {
            coef = new_coef;
        }

        friend Term<FRIEND> operator+(const Term<FRIEND> &left, const Term<FRIEND> &right) {
            if (left.pow != right.pow) {
                std::cout << "Невозможно сложить термы, т.к. разные степени при x." << std::endl;
                return Term<FRIEND>();
            }
            return Term<FRIEND>(left.coef + right.coef, left.pow);
        }

        Term<FRIEND> &operator=(const Term<FRIEND> &right) {
            this->coef = right.coef;
            this->pow = right.pow;
            return *this;
        }

        friend Term<FRIEND> operator*(Term<FRIEND> &left, Term<FRIEND> &right) {
            return Term<FRIEND>(left.coef * right.coef, left.pow + right.pow);
        }

        friend std::istream &operator>>(std::istream &in, Term<FRIEND> &term) {
            char str[100];
            in.getline(str, 100);

            // убираем пробелы и знак возведения в степень
            char s[100];
            int count = 0;
            for (int i = 0; i < std::strlen(str); ++i) {
                if (str[i] != ' ' && str[i] != '^') {
                    s[count++] = str[i];
                }
            }
            s[count] = '\0';

            // ищем индекс 'x'
            int x_index = -1;
            for (int i = 0; i < count; ++i) {
                if (s[i] == 'x') {
                    x_index = i;
                    break;
                }
            }

            if (x_index == -1) {
                term.coef = std::atoi(s);
                term.pow = 0;
            } else {
                // обработка коэффициента
                if (x_index == 0) {
                    term.coef = 1;
                } else if (x_index == 1 && s[0] == '-') {
                    term.coef = -1;
                } else if (x_index == 1 && s[0] == '+') {
                    term.coef = 1;
                } else {
                    s[x_index] = '\0';
                    term.coef = s[0] ? std::atoi(s) : 1; // на случай если перед x ничего нет
                }

                // обработка степени
                if (x_index == count - 1) {
                    term.pow = 1;
                } else {
                    // проверяем, что после x идет число
                    bool correct_format = true;
                    for (int i = x_index + 1; i < count; ++i) {
                        if (!std::isdigit(s[i]) && !(i == x_index + 1 && s[i] == '-')) {
                            correct_format = false;
                            break;
                        }
                    }

                    if (correct_format && (count > x_index + 1)) {
                        term.pow = std::atoi(s + x_index + 1);
                        if (term.pow < 0) {
                            term.pow = 0;
                        }
                    } else {
                        term.pow = 1;
                    }
                }
            }

            return in;
        }

        friend std::ostream &operator<<(std::ostream &out, const Term<FRIEND> &term) {
            if (term.coef == 0 || term.pow == 0) {
                out << term.coef;
                return out;
            }

            if (term.coef == 1) {
                out << 'x';
            } else if (term.coef == -1) {
                out << "-x";
            } else {
                out << term.coef << 'x';
            }

            if (term.pow != 1) {
                out << '^' << term.pow;
            }

            return out;
        }
};

#endif  // TERM_H
