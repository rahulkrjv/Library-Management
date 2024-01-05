# Library Management System

This C++ code implements a simple Library Management System with features for both administrators and students. It utilizes file handling for data storage and retrieval. Below is a brief overview of the functionality and structure of the code.


## Overview

The program provides a menu-driven interface with different options for administrators and students. Administrators can perform tasks such as registering books, registering students, and searching for books or students. Students can issue and submit books. Data is stored in binary files (`Books.dat` and `Students.dat`) using file handling.

## Usage

1. Run the program.
2. Choose the appropriate option from the main menu.
   - For administrators: Register books, register students, search for books, search for students, exit.
   - For students: Issue books, submit books, exit.

## File Structure

- main.cpp: Contains the main function and menu functions.
- books.h: Header file for the books class, which represents book-related information.
- students.h: Header file for the students class, which represents student-related information.

## Functions

- menu: Displays the main menu and returns the selected option.
- adminMenu: Displays the administrator menu and returns the selected option.
- studentMenu: Displays the student menu and returns the selected option.
- addBooks: Adds book data to the Books.dat file.
- addStudents: Adds student data to the Students.dat file.
- srchBook: Searches for a book by its ID.
- srchStudent: Searches for a student by their URN.
- issueBooks: Allows a student to issue a book.
- submitBooks: Allows a student to submit a book.

## Data Storage

- Book data is stored in the Books.dat file using binary file handling.
- Student data is stored in the Students.dat file using binary file handling.

