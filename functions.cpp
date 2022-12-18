#include <bits/stdc++.h>
#include <fstream>
#include "books.h"
#include "students.h"

int menu(void)
{
    int sw = 0;
    std::cout << "\n********************** MENU **********************\n"
              << std::endl;
    std::cout << "\n[1] - Admin"
              << "\n[2] - Issue / Submit books"
              << "\n[3] - exit\t";
    std::cin >> sw;
    return sw;
}

int adminMenu(void)
{
    system("CLS");

    int sw = 0;
    std::cout << "______________________ MENU( ONLY FOR ADMINS ) _____________________" << std::endl;
    std::cout << "-------------------------------------------------------------------\n"
              << std::endl;
    std::cout << "[1] - Register books\n"
              << "[2] - Register students\n"
              << "[3] - Search book\n"
              << "[4] - Search students\n"
              << "[5] - Exit\t";
    std::cin >> sw;
    return sw;
}

int studentMenu(void)
{
    int sw = 0;
    std::cout << "______________________* MENU *_____________________" << std::endl;
    std::cout << "----------------------------------------------------\n"
              << std::endl;
    std::cout << "[1] - Issue books\n"
              << "[2] - Submit books\n"
              << "[3] - Exit\t";
    std::cin >> sw;

    return sw;
}

void addBooks(books *temp)
{
    if ((temp->bookName == "") && (temp->authorName == "") && (temp->publication == "") && (temp->price == 0) && (temp->year == 0) && (temp->bookId == 0))
    {
        temp->getdata();
    }

    std::ofstream file;
    file.open("Books.dat", std::ios::app | std::ios::binary);
    file.write((char *)temp, sizeof(*temp));
    file.close();

    std::cout << "Book data is successfully added." << std::endl;
    system("pause");
}
void addStudents(students *temp)
{
    if ((temp->name == "") && (temp->branch == "") && (temp->urn == "") && (temp->crn == ""))
    {
        temp->getdata();
    }

    std::ofstream file;
    file.open("Students.dat", std::ios::app | std::ios::binary);
    file.write((char *)temp, sizeof(*temp));
    file.close();

    std::cout << "Student data is successfully added." << std::endl;
    system("pause");
}
void srchBook(void)
{
    int bookid;
    std::cout << "Enter Book Id:\t";
    std::cin >> bookid;

    books temp;
    std::ifstream file;
    file.open("Books.dat", std::ios::in | std::ios::binary);
    while (!file.eof())
    {
        file.read((char *)&temp, sizeof(temp));

        if (temp.bookId == bookid)
        {
            temp.putdata();
        }
    }
}
void srchStudent(void)
{
    std::string URN;
    std::cout << "Enter URN:\t";
    std::cin >> URN;

    students temp;
    std::ifstream file;
    file.open("Students.dat", std::ios::in | std::ios::binary);
    while (!file.eof())
    {
        file.read((char *)&temp, sizeof(temp));

        if (temp.urn == URN)
        {
            temp.putdata();
        }
    }
}
void issueBooks(void)
{
    students temp;
    std::ifstream file;
    std::ofstream ofile;
    int noOfBooks = 0;
    char ch = '|';
    std::string URN, BookId;

    std::cout << "Enter your URN:\t";
    std::cin >> URN;
    std::cout << "Enter book Id:\t";
    std::cin >> BookId;

    file.open("Students.dat", std::ios::in | std::ios::binary);
    ofile.open("tempFile.dat", std::ios::app | std::ios::binary);
    while (!file.eof())
    {
        file.read((char *)&temp, sizeof(temp));

        if (temp.urn == URN)
        {
            noOfBooks = count(temp.bookId.begin(), temp.bookId.end(), ch);

            if (noOfBooks < 5)
            {
                temp.bookId = temp.bookId + BookId + " | ";
                ofile.write((char *)&temp, sizeof(temp));

                std::cout << "Book issued successfully..." << std::endl;
            }
            else
                std::cout << "You have reached your quota..." << std::endl;
            break;
        }
        else
        {
            ofile.write((char *)&temp, sizeof(temp));
        }
    }
    file.close();
    ofile.close();
    remove("Students.dat");
    rename("tempFile.dat", "Students.dat");
}
void submitBooks(void)
{
    students temp;
    std::ifstream file;
    std::ofstream ofile;
    char ch = '|';
    int size = count(temp.bookId.begin(), temp.bookId.end(), ch);
    std::string URN, BookId, str, substr;

    std::cout << "Enter your URN:\t";
    std::cin >> URN;
    std::cout << "Enter book Id:\t";
    std::cin >> BookId;

    file.open("Students.dat", std::ios::in | std::ios::binary);
    ofile.open("tempFile.dat", std::ios::app | std::ios::binary);
    while (!file.eof())
    {
        file.read((char *)&temp, sizeof(temp));

        if (temp.urn == URN)
        {
            for (int i = 0; i < size; i++)
            {
                int pos = temp.bookId.find("|");
                substr = temp.bookId.substr(0, pos);
                if (substr == BookId)
                    continue;
                else
                {
                    if (str.length() == 0)
                    {
                        str += substr;
                    }
                    else
                        str = str + "," + substr;
                }
                temp.bookId = temp.bookId.substr(pos + 1);
            }
            ofile.write((char *)&temp, sizeof(temp));
        }
        else
        {
            ofile.write((char *)&temp, sizeof(temp));
        }
    }
    file.close();
    ofile.close();
    remove("Students.dat");
    rename("tempFile.dat", "Students.dat");
}