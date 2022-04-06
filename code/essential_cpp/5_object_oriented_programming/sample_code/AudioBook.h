#ifndef AUDIO_BOOK_H
#define AUDIO_BOOK_H

#include <iostream>
#include <string>
#include "Book.h"

class AudioBook : public Book
{
private:
        string _narrator;
public:
        AudioBook(const string& title, const string& author, const string& narrator);
        ~AudioBook();
        virtual void print() const;
        const string& narrator() const {return _narrator;}
};

AudioBook::AudioBook(const string& title, const string& author, const string& narrator)
        : Book(title, author), _narrator(narrator)
{
        cout << "AudioBook::AudioBook(" 
             << _title << ", " 
             << _author << ", "
             << _narrator << ") constructor." << endl;
}

AudioBook::~AudioBook()
{
        cout << "AudioBook::~AudioBook() default destructor!" << endl;
}

void AudioBook::print() const
{
        cout << "AudioBook::print() -- I am an AudioBook object!\n"
             << "My title is: " << _title << "\n"
             << "My author is: " << _author << "\n"
             << "My narrator is: " << _narrator << endl;
}


#endif