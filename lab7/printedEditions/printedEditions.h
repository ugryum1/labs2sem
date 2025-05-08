#ifndef PRINTED_EDITIONS_H
#define PRINTED_EDITIONS_H

#include <iostream>
#include <cstring>

// абстрактрый класс "печатное издание"
class PrintedEdition {
    protected:
        char* title;
        int year;
        int pageCount;
    public:
        PrintedEdition(const char* title, int year, int pageCount);
        virtual ~PrintedEdition();
        virtual void show() = 0;
};

// класс "книга", наследоаванный от класса "печатное изделие"
class Book : public PrintedEdition {
    protected:
        char* author;
        char* genre;
    public:
        Book(const char* title, const char* author, const char* genre, int year, int pageCount);
        ~Book() override;
        void show() override;

};

// класс "журнал"
class Journal : public PrintedEdition {
    protected:
        int issueNumber;
        char* publisher;
    public:
        Journal(const char* title, const char* publisher, int issueNumber, int year, int pageCount);
        ~Journal() override;
        void show() override;
};

// класс учебник
class Textbook : public Book {
    protected:
        char* subject;
        int gradeLevel;
    public:
        Textbook(const char* title, const char* author, const char* subject, int gradeLevel, int year, int pageCount);
        ~Textbook() override;
        void show() override;
};

#endif  // PRINTED_EDITIONS_H
