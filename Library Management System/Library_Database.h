#ifndef LIBRARY_DATABASE_H
#define LIBRARY_DATABASE_H
#pragma once

#include "Book.h"
#include "Calculation.h"
#include <bits/stdc++.h>
// #include <conio.h>
// #include <vector>
// #include <ctime>
// #include <fstream>

using namespace std;
class Library_Database
{
public:
    // For libirian
    bool displayLibStatus();
    bool displaylibrarianProfile(const string &libirianID);
    bool addBook();   
    bool displayAllBooks();
    // void displayUserBooks();
    bool updateBook(const string &isbn);
    bool deleteBook(const string &isbnToDelete);
    bool searchBookByISBN_LIBIRIN(const string &isbn);
    bool LibsearchStudent(const string &ID);

    // For Student.
    bool searchStudent(const string &ID);
    bool searchBookByISBN_STUDENT(const string &isbn);
    bool displayProfileStatus(const string &studentID);
    bool searchBorrowBookISBN(const string &isbn);
    bool AlreadyborrowBook(const string &studentID, const string &isbn);
    bool borrowBook(const string &studentID, const string &isbn);

    // void checkAllBooks();
    bool returnBook(const string &ReturnBook, const string &studentID, const string &isbn);
    void lostReport(const string &lostBookISBN, const string &studentID, const string &studentName, const string &description);
    // void calculateFine();

};
#endif // LIBRARY_DATABASE_H