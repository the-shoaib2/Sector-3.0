#ifndef BOOK_H
#define BOOK_H

#include <bits/stdc++.h>
#include "Library_Database.h"
#include "Librarian.h"

using namespace std;
class Book
{
public:
    bool addbook(const string& title, const string& author, const string& isbn, int quantity);
};

#endif /* BOOK_H */
