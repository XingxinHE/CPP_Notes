#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include "LibraryMaterial.h"

using namespace std;

class Book : public LibraryMaterial
{
protected:
        string _author;
        string _title;        
public:
        Book(const string& title, const string& author);
        ~Book();
        virtual void print() const;
        const string& author() const {return _author;}
        const string& title() const {return _title;}
};


Book::Book(const string& title, const string& author)
        :_title(title), _author(author)
{
        cout << "Book::Book(" 
             << _title << ", " 
             << _author << ") constructor." << endl;
}

Book::~Book()
{
        cout << "Book::~Book() default destructor!" << endl;
}

void Book::print() const
{
        cout << "Book::print() -- I am a Book Object." << endl;
        cout << "My title is: " << _title << endl;
        cout << "My author is: " << _author << endl;
}

#endif