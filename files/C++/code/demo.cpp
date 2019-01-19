#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class book
{
  private:
    string title;
    string author;
    string isbn_num;

  public:
    book();
    book(string inTitle, string inAuthor, string inIsbn);

    string getIsbn(void) { return isbn_num; }
    string getTitle(void) { return title; }
    string getAuthor(void) { return author; }
    string getDetails(void);
};

book::book(string inTitle, string inAuthor, string inIsbn)
{
    this->title = inTitle;
    author = inAuthor;
    isbn_num = inIsbn;
}

string book::getDetails(void)
{
    string ret;
    ret = title + " " + author;
    return ret;
}

int main()
{
    string inputName;
    string inputBookTitle;
    string inputBookAuthor;

    cout << "Enter your name : ";
    getline(cin, inputName);
    cout << "Enter your favourite book : ";
    getline(cin, inputBookTitle);
    cout << "Enter the author : ";
    getline(cin, inputBookAuthor);

    book outputBook = book(inputBookTitle, inputBookAuthor, "");

    cout << "Hello " << inputName << " !!! Your favourite book is " << outputBook.getTitle() << ", by " << outputBook.getAuthor() << endl;

    book mybook = book("IT", "Stephen King", "4234-2323");

    return 0;
}

/* 
Modify demo.cpp so that as well as entering a name, the user can also enter details of their 
favourite book; the program should then respond with a greeting and statement about the 
favourite book. (“Hello Pete!!! Your favourite book is Anna Karenina, by Leo Tolstoy”) */