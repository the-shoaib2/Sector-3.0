/*
#include "Calculation.h"

Calculation::Calculation() {
    totalStudentAccount = "0";
    totalBookInLib = "0";
    totalDeleteBookInLib = "0";
    totalStudent = "0";
    bookOut = "0";
    borrowAllTime = "0";
    returnBooks = "0";
}

void Calculation::saveLibraryInfo() {
    ofstream outFile("Bookinfo\\libraryinfo\\libraryinfo.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Total Student Account: " << totalStudentAccount << endl;
        outFile << "Total Book in Library: " << totalBookInLib << endl;
        outFile << "Total Deleted Book in Library: " << totalDeleteBookInLib << endl;
        outFile << "Total Student: " << totalStudent << endl;
        outFile << "Book Out: " << bookOut << endl;
        outFile.close();
    }
}

void Calculation::saveStudentInfo() {
    ofstream outFile("Bookinfo\\libraryinfo\\libraryinfo.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Total Borrow Book: " << borrowAllTime << endl;
        outFile << "Total Return Book : " << returnBooks << endl;
        outFile.close();
    }
}

void Calculation::incrementValue(string& value) {
    int currentValue = stoi(value);
    currentValue++;
    value = to_string(currentValue);
}

void Calculation::decrementValue(string& value) {
    int currentValue = stoi(value);
    if (currentValue > 0) {
        currentValue--;
        value = to_string(currentValue);
    } else {
        cout << "No books left in the library!" << endl;
    }
}

void Calculation::TotalStudentAccount() {
    incrementValue(totalStudentAccount);
    saveLibraryInfo();
}

void Calculation::TotalBookInLib() {
    incrementValue(totalBookInLib);
    saveLibraryInfo();
}

void Calculation::TotalDeleteBookInLib() {
    incrementValue(totalDeleteBookInLib);
    saveLibraryInfo();
}

void Calculation::DeleteBookFromLib() {
    decrementValue(totalBookInLib);
    saveLibraryInfo();
}

void Calculation::TotalStudent() {
    incrementValue(totalStudent);
    saveLibraryInfo();
}

void Calculation::BookOut() {
    incrementValue(bookOut);
    saveLibraryInfo();
}

string Calculation::calculateBookTotalLib() {
    int totalBooks = stoi(totalBookInLib);
    int booksOut = stoi(bookOut);
    int bookTotalLib = totalBooks - booksOut;
    return to_string(bookTotalLib);
}

void Calculation::BorrowAllTime() {
    incrementValue(borrowAllTime);
    saveStudentInfo();
}

void Calculation::ReturnBooks() {
    incrementValue(returnBooks);
    saveStudentInfo();
}

string Calculation::calculateBorrowNow() {
    int borrowNowVal = stoi(borrowAllTime) - stoi(returnBooks);
    return to_string(borrowNowVal);
}

string Calculation::calculateStudentBookFine(int daysLate) {
    if (daysLate >= 1 && daysLate <= 5) {
        return "40"; // Fine for 1 to 5 days late
    } else if (daysLate >= 6 && daysLate <= 10) {
        return "500"; // Fine for 6 to 10 days late
    } else {
        return "0"; // No fine if not within these ranges
    }
}

*/