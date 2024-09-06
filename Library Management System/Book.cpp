#include "Book.h"
// Constructor definition
bool Book::addbook(const string &title, const string &author, const string &isbn, int quantity)
{
    string filename = "Bookinfo\\" + isbn + ".txt";
    ofstream outFile(filename);

    if (outFile.is_open()) {
        outFile << "Title: " << title << endl;
        outFile << "Author: " << author << endl;
        outFile << "ISBN: " << isbn << endl;
        outFile << "Quantity: " << quantity << endl;
        // Close the file
        outFile.close();
    }
}