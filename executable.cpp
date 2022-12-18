#include <bits/stdc++.h>
#include "books.h"
#include "students.h"
#include "functions.cpp"

int main(void)
{
    system("CLS");
    books *ob;
    students *obj;

    int sw = 0, x = 0, size = 0;

    while (sw != 3)
    {
        sw = menu();

        switch (sw)
        {
        case 1:
            while (x != 5)
            {
                x = adminMenu();
                switch (x)
                {
                case 1:
                    std::cout << "Enter how many books do you want to register:\t";
                    std::cin >> size;

                    ob = new books[size];
                    for (int i = 0; i < size; i++)
                    {
                        addBooks(ob + i);
                    }
                    break;

                case 2:
                    std::cout << "Enter how many students you wants to register:\t";
                    std::cin >> size;

                    obj = new students[size];
                    for (int i = 0; i < size; i++)
                        addStudents(obj + i);
                    break;

                case 3:
                    srchBook();
                    break;

                case 4:
                    srchStudent();
                    break;

                case 5:
                    break;

                default:
                    std::cout << "I don't understand." << std::endl;
                    std::cout << "Enter again..." << std::endl;
                    break;
                }
                system("pause");
            }
            break;

        case 2:
            while (x != 3)
            {
                x = studentMenu();
                switch (sw)
                {
                case 1:
                    issueBooks();
                    break;

                case 2:
                    submitBooks();
                    break;

                case 3:
                    break;

                default:
                    std::cout << "Error!" << std::endl;
                    break;
                }
                system("pause");
            }
            break;

        case 3:
            break;

        default:
            std::cout << "Enter again..." << std::endl;
            break;
        }
        system("pause");
    }

    system("pause");
    return 0;
}