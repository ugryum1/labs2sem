#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <fstream>
#include "../containers/myvector.h"
#include "term.h"

class Polynomial {
    private:
        MyVector<Term<Polynomial>> poly;
        int degree;
        int order;
    public:
        Polynomial(int c = 0) : poly(1) {
            Term<Polynomial> term(c);
            poly.add_element(term);
            order = 1;
            degree = 0;
        }

        Polynomial(const Term<Polynomial> &term) {
            poly.add_element(term);
            degree = term.pow;
            order = 1;
        }

        Polynomial(const Polynomial &p) {
            poly = p.poly;
            degree = p.degree;
            order = p.order;
        }

        void setOrder(int new_order) {
            order = new_order;
        }

        Polynomial &operator=(const Polynomial &right) {
            this->poly = right.poly;
            this->degree = right.degree;
            this->order = right.order;
            return *this;
        }

        Polynomial &operator+=(const Term<Polynomial> &term) {
            bool is_find = false;
            for (int i = 0; i < this->poly.length(); ++i) {
                if (this->poly[i].pow == term.pow) {
                    this->poly[i] = this->poly[i] + term;
                    is_find = true;
                    break;
                }
            }

            if (!is_find) {
                this->poly.add_element(term);
            }

            this->degree = (term.pow > this->degree) ? term.pow : this->degree;

            return *this;
        }

        Polynomial &operator+=(Polynomial &right) {
            for (int i = 0; i < right.poly.length(); ++i) {
                *this += right.poly[i];
            }
            return *this;
        }

        friend Polynomial operator+(Polynomial &left, Polynomial &right) {
            Polynomial p = left;
            p += right;
            return p;
        }

        friend Polynomial operator*(Polynomial &left, Polynomial &right) {
            Polynomial p;
            p.order = left.order;
            p.degree = 0;

            for (int i = 0; i < left.poly.length(); ++i) {
                for (int j = 0; j < right.poly.length(); ++j) {
                    p += left.poly[i] * right.poly[j];
                    if (left.poly[i].getPow() + right.poly[j].getPow() > p.degree) {
                        p.degree = left.poly[i].getPow() + right.poly[j].getPow();
                    }
                }
            }

            return p;
        }

        Polynomial &operator*=(Polynomial &right) {
            *this = *this * right;
            return *this;
        }

        friend std::istream &operator>>(std::istream &in, Polynomial &p) {
            p = Polynomial();
            p.order = 1;

            char str[100];
            in >> std::ws; // очищаем поток от лишних пробелов/переводов строки
            in.getline(str, 100);

            char s[100];
            int count = 0;
            for (int i = 0; str[i] != '\0'; ++i) {
                if (str[i] != ' ') {
                    s[count++] = str[i];
                }
            }
            s[count] = '\0';

            int len = std::strlen(s);
            int begin_index = 0;

            for (int i = 1; i <= len; ++i) {
                if (i == len || s[i] == '+' || s[i] == '-') {
                    int term_length = i - begin_index;
                    if (term_length <= 0) {
                        begin_index = i;
                        continue;
                    }

                    char term_str[100] = {0};
                    std::strncpy(term_str, s + begin_index, term_length);
                    term_str[term_length] = '\0';

                    Term<Polynomial> term(term_str);
                    p += term;

                    begin_index = i;
                }
            }

            return in;
        }

        friend std::ostream &operator<<(std::ostream &out, Polynomial &p) {
            if (p.order == 1) { // вывод полинома по убыванию степеней
                bool first_term = true;

                for (int d = p.degree; d >= 0; --d) {
                    int coef = 0;

                    for (int i = 0; i < p.poly.length(); ++i) {
                        if (p.poly[i].getPow() == d) {
                            coef += p.poly[i].getCoef();
                        }
                    }

                    if (coef != 0) {
                        if (!first_term) {
                            out << (coef > 0 ? " + " : " - ");
                        } else if (coef < 0) {
                            out << "-";
                        }

                        int abs_coef = std::abs(coef);

                        if (abs_coef != 1 || d == 0) {
                            out << abs_coef;
                        }

                        if (d > 0) {
                            out << "x";
                            if (d > 1) {
                                out << "^" << d;
                            }
                        }

                        first_term = false;
                    }
                }

                if (first_term) {
                    out << "0";
                }

            } else { // вывод полинома по возрастанию степеней
                bool first_term = true;
                for (int d = 0; d <= p.degree; ++d) {
                    int coef = 0;
                    for (int i = 0; i < p.poly.length(); ++i) {
                        if (p.poly[i].getPow() == d) {
                            coef += p.poly[i].getCoef();
                        }
                    }
                    if (coef != 0) {
                        if (!first_term) {
                            out << (coef > 0 ? " + " : " - ");
                        } else if (coef < 0) {
                            out << "-";
                        }
                        int abs_coef = std::abs(coef);
                        if (abs_coef != 1 || d == 0) {
                            out << abs_coef;
                        }
                        if (d > 0) {
                            out << "x";
                            if (d > 1) {
                                out << "^" << d;
                            }
                        }
                        first_term = false;
                    }
                }

                if (first_term) {
                    out << "0";
                }
            }

            return out;
        }
};

#endif  // POLYNOMIAL_H
