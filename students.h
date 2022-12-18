#ifndef STUDENTS_H
#define STUDENTS_H

#include <bits/stdc++.h>
#include <cstring>

class students
{
public:
    std::string name, branch, bookId, urn, crn;

    students(std::string name = "", std::string branch = "", std::string urn = "", std::string crn = "")
    {
        this->name = name;
        this->branch = branch;
        this->urn = urn;
        this->crn = crn;
    }

    void getdata(void);
    void putdata(void);
};

void students::getdata(void)
{
    std::cout << "Enter name:\t";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter branch:\t";
    std::getline(std::cin >> std::ws, branch);
    std::cout << "Enter urn:\t";
    std::cin >> urn;
    std::cout << "Enter crn:\t";
    std::cin >> crn;
}
void students::putdata()
{
    std::cout << "Name:\t" << name
              << "Branch:\t" << branch
              << "URN:\t" << urn
              << "CRN:\t" << crn
              << "Issued Books:\t" << bookId << std::endl;
}
#endif