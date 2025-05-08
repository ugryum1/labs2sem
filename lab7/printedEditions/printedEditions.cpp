#include "printedEditions.h"

PrintedEdition::PrintedEdition(const char* title, int year, int pageCount) {
    this->year = year;
    this->pageCount = pageCount;
    this->title = new char[std::strlen(title) + 1];
    std::strcpy(this->title, title);
    // std::cout << "PrintedEdition()" << std::endl;
}

PrintedEdition::~PrintedEdition() {
    delete[] title;
    year = 0;
    pageCount = 0;
    // std::cout << "~PrintedEdition()" << std::endl;
}

Book::Book(const char* title, const char* author, const char* genre,
           int year, int pageCount) : PrintedEdition(title, year, pageCount) {
   this->author = new char[std::strlen(author) + 1];
   std::strcpy(this->author, author);
   this->genre = new char[std::strlen(genre) + 1];
   std::strcpy(this->genre, genre);
   // std::cout << "Book()" << std::endl;
}

Book::~Book() {
   delete[] author;
   delete[] genre;
   // std::cout << "~Book()" << std::endl;
}

void Book::show() {
   std::cout << "Book: " << title << " by " << author
             << " (" << genre << "), " << year
             << ", " << pageCount << " pages" << std::endl;
}

Journal::Journal(const char* title, const char* publisher,
                 int issueNumber, int year, int pageCount) : PrintedEdition(title, year, pageCount) {
    this->issueNumber = issueNumber;
    this->publisher = new char[std::strlen(publisher) + 1];
    std::strcpy(this->publisher, publisher);
    // std::cout << "Journal()" << std::endl;
}

Journal::~Journal() {
    delete[] publisher;
    // std::cout << "~Journal()" << std::endl;
}

void Journal::show() {
    std::cout << "Journal: " << title << " (Issue №" << issueNumber
              << "), published by " << publisher << ", " << year
              << ", " << pageCount << " pages" << std::endl;
}

Textbook::Textbook(const char* title, const char* author, const char* subject, int gradeLevel, int year, int pageCount)
                   : Book(title, author, "Educational", year, pageCount) {
    this->gradeLevel = gradeLevel;
    this->subject = new char[std::strlen(subject) + 1];
    std::strcpy(this->subject, subject);
    // std::cout << "Textbook()" << std::endl;
}

Textbook::~Textbook() {
    delete[] subject;
    // std::cout << "~Textbook()" << std::endl;
}

void Textbook::show() {
    std::cout << "Textbook: " << title << " by " << author
              << " (Grade " << gradeLevel << " " << subject << "), "
              << year << ", " << pageCount << " pages" << std::endl;
}
