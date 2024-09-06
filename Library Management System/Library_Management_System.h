#ifndef LIBRARY_MANAGEMENT_SYSTEM_H
#define LIBRARY_MANAGEMENT_SYSTEM_H
#include "Student.h"
#include "Librarian.h"
#include "Calculation.h"
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
class Library_Management_System
{
private:
    bool logged_in;
    string ID;
    string password;
public:
    Library_Management_System();

    // Declaration of the createUserFolder function
    void createUserFolder();
    bool IDSearchLibrarian(const string &ID);
    bool IDSearchStudent(const string &ID);
    bool login_Student(const string &studentID, const string &password);
    bool login_Librarian(const string &LibrarianID, const string &password);
    bool logout();
    bool register_student(const string &studentName, const string &studentID, const string &password, const string &email, const string &department, const string &phoneNumber);
    bool register_librarian(const string &librarianName, const string &librarianID, const string &password, const string &email, const string &Key, const string &phoneNumber);
};

#endif // LIBRARY_MANAGEMENT_SYSTEM_H
