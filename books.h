#ifndef BOOKS_H
#define BOOKS_H

#include <bits/stdc++.h>

class books
{
public:
    std::string bookName, authorName, publication;
    float price;
    int year, bookId;

    books(std::string bookName = "", std::string authorName = "", std::string publication = "", float price = 0, int year = 0, int bookId = 0)
    {
        this->bookName = bookName;
        this->authorName = authorName;
        this->publication = publication;
        this->price = price;
        this->year = year;
        this->bookId = bookId;
    }

    void getdata(void);
    void putdata(void);
    void deldata(void);
};

void books::getdata(void)
{
    std::cout << "Enter book name:\t";
    std::getline(std::cin >> std::ws, bookName);
    std::cout << "Enter Book Id:\t";
    std::cin >> bookId;
    std::cout << "Enter author's name:\t";
    std::getline(std::cin >> std::ws, authorName);
    std::cout << "Enter publisher name:\t";
    std::getline(std::cin >> std::ws, publication);
    std::cout << "Enter year:\t";
    std::cin >> year;
    std::cout << "Enter price:\t";
    std::cin >> price;
    system("pause");
}

void books::putdata()
{
    std::cout << "\n Name:\t" << bookName
              << "\n Book Id:\t" << bookId
              << "\n Author:\t" << authorName
              << "\n Publication:\t" << publication
              << "\n"
              << year
              << "\n Price:\tINR " << price << std::endl;
    std::cout << std::endl;
    system("pause");
}

#endif