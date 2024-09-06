#include "Library_Database.h"

bool Library_Database::displayLibStatus()
{
    ifstream inFile(R"(Bookinfo\libraryinfo\libraryinfo.txt)");

    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            cout << "\t\t\t\t\t\t" << line << endl
                 << endl;
        }
        inFile.close();
        return true;
    }
    return false;

}
bool Library_Database::addBook()
{
    string title, author, isbn;
    int quantity;

    cout << "\t\t\t\t\t\tENTER TITEL: ";
    cin >> ws;
    getline(cin, title);
    cout << "\t\t\t\t\t\tENTER AUTHOR: ";
    cin >> ws;
    getline(cin, author);
    cout << "\t\t\t\t\t\tENTER ISBN: ";
    cin >> ws;
    getline(cin, isbn);
    cout << "\t\t\t\t\t\tENTER QUANTITY: ";
    cin >> quantity;

    Book bookObject; // Creating an object of the Book class

    if (bookObject.addbook(title, author, isbn, quantity))
    {
        system("cls");
        cout << endl
             << endl
             << endl;
        cout << "\t\t\t\t\t[*]---- Book added successfully----[*]" << endl
             << endl
             << endl
             << endl
             << endl;
        cout << "\t\t\t\t\t[*]---- Press Enter to back ----[*]";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get(); // Wait for the Enter key
    }
    else
    {
        system("cls");
        cout << endl
             << endl
             << endl;
        cout << "\t\t\t\t\t\t[*]---- Failed to add the book.----[*]" << endl
             << endl
             << endl
             << endl
             << endl;
        cout << "\t\t\t\t\t\t[*]---- Press Enter to back ----[*]";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get(); // Wait for the Enter key
    }
}

/*
void Library_Database::displayAllBooks() {
    system("cls");
    cout << "---------------------------------------------------------------------\n";
    cout << "TITLE          AUTHOR         ISBN           STATUS         QUANTITY" << endl;
    cout << "---------------------------------------------------------------------\n";

    string folderPath = "Bookinfo\\"; // Assuming the folder is named Bookinfo

    sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
        return a.get_isbn() < b.get_isbn();
    });

    for (const auto &book : books) {
        string filename = folderPath + book.get_isbn() + ".txt";

        // Check if the file exists before opening it
        if (fs::exists(filename)) {
            ifstream inFile(filename);
            if (inFile.is_open()) {
                string title, author, isbn, status, quantity;
                string line;
                while (getline(inFile, line)) {
                    if (line.find("Title:") != string::npos)
                        title = line.substr(line.find(":") + 2); // Extract title
                    else if (line.find("Author:") != string::npos)
                        author = line.substr(line.find(":") + 2); // Extract author
                    else if (line.find("ISBN:") != string::npos)
                        isbn = line.substr(line.find(":") + 2); // Extract ISBN
                    else if (line.find("Status:") != string::npos)
                        status = line.substr(line.find(":") + 2); // Extract status
                    else if (line.find("Quantity:") != string::npos)
                        quantity = line.substr(line.find(":") + 2); // Extract quantity
                }

                // Print the book details
                cout << left << setw(15) << title << setw(15) << author
                     << setw(15) << isbn << setw(15) << status
                     << setw(15) << quantity << endl;

                inFile.close();
            }
        }
    }

    char option;
    cout << "\nDO YOU WANT TO GO BACK?\n\n";
    cout << "Press Enter to back......:(";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); // Wait for the Enter key
}
*/

bool Library_Database::searchBookByISBN_LIBIRIN(const string &isbn)
{
    system("cls");
    string folderPath = "Bookinfo\\"; // Assuming the folder is named Bookinfo

    string filename = folderPath + isbn + ".txt";
    ifstream inFile(filename);

    if (inFile.is_open())
    {
        string title, author, bookISBN, status, quantity;
        string line;
        while (getline(inFile, line))
        {
            if (line.find("Title:") != string::npos)
                title = line.substr(line.find(":") + 2); // Extract title
            else if (line.find("Author:") != string::npos)
                author = line.substr(line.find(":") + 2); // Extract author
            else if (line.find("ISBN:") != string::npos)
                bookISBN = line.substr(line.find(":") + 2); // Extract ISBN
            else if (line.find("Quantity:") != string::npos)
                quantity = line.substr(line.find(":") + 2); // Extract quantity
        }

        inFile.close();

        // Check if all necessary information is found before printing
        if (!title.empty() && !author.empty() && !bookISBN.empty() && !quantity.empty())
        {
            cout << endl
                 << endl;
            cout << "\t\t\t\t\tTITLE: " << title << endl;
            cout << "\t\t\t\t\tAUTHOR: " << author << endl;
            cout << "\t\t\t\t\tISBN: " << bookISBN << endl;
            cout << "\t\t\t\t\tQUANTITY: " << quantity << endl;
            cout << endl
                 << endl
                 << endl
                 << endl;
            cout << "\n\n\t\t\t\t\t\t...Press Enter to go back...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return true; // Book found
        }
    }

    cout << "\t\t\t\t\t\tBook not found!" << endl;
    cout << "\n\t\t\t\t\t...Press Enter to go back...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return false; // Book not found
}

bool Library_Database::searchBookByISBN_STUDENT(const string &isbn)
{
    string folderPath = "Bookinfo\\"; // Assuming the folder is named Bookinfo
    string filename = folderPath + isbn + ".txt";
    ifstream inFile(filename);

    if (inFile.is_open())
    {
        string title, author, bookISBN, status, quantity;
        string line;
        while (getline(inFile, line))
        {
            if (line.find("Title:") != string::npos)
                title = line.substr(line.find(":") + 2); // Extract title
            else if (line.find("Author:") != string::npos)
                author = line.substr(line.find(":") + 2); // Extract author
            else if (line.find("ISBN:") != string::npos)
                bookISBN = line.substr(line.find(":") + 2); // Extract ISBN
            else if (line.find("Quantity:") != string::npos)
                quantity = line.substr(line.find(":") + 2); // Extract quantity
        }

        inFile.close();

        // Check if all necessary information is found before printing
        if (!title.empty() && !author.empty() && !bookISBN.empty() && !quantity.empty())
        {
            cout << endl;
            cout << "\t\t\t\t\tTITLE: " << title << endl;
            cout << "\t\t\t\t\tAUTHOR: " << author << endl;
            cout << "\t\t\t\t\tISBN: " << bookISBN << endl;
            cout << "\t\t\t\t\tQUANTITY: " << quantity << endl;
            cout << endl;
            return true; // Book found
        }
    }
    cout << "\t\t\t\t\t\tBook not found!" << endl;
    return false; // Book not found
}

bool Library_Database::deleteBook(const string &isbnToDelete)
{
    string folderPath = R"(Bookinfo\)";
    string filename = folderPath + isbnToDelete + ".txt";
    string binFilename = folderPath + "bin" + isbnToDelete + ".txt";

    ifstream inFile(filename);
    if (inFile.is_open())
    {
        inFile.close();

        if (rename(filename.c_str(), binFilename.c_str()) == 0)
        {
            cout << "\t\t\t\tBook with ISBN " << isbnToDelete << " deleted successfully!" << endl;
            return true;
        }
        else
        {
            cout << "\t\t\t\tBook with ISBN " << isbnToDelete << " could not be deleted!" << endl;
            return false;
        }
    }
    else
    {
        cout << "\t\t\t\tBook with ISBN " << isbnToDelete << " not found!" << endl;
        return false;
    }
}

bool Library_Database::updateBook(const string &isbn)
{
    system("cls");
    cout<<endl<<endl;
    string folderPath = R"(Bookinfo\)"; // Assuming the folder is named Bookinfo

    string filename = folderPath + isbn + ".txt";
    ifstream inFile(filename);

    if (inFile.is_open())
    {
        string title, author, bookISBN, status, quantity;
        string line;

        while (getline(inFile, line))
        {
            if (line.find("Title:") != string::npos)
                cout << "Current Title: " << line.substr(line.find(":") + 2) << endl; // Print current title
            else if (line.find("Author:") != string::npos)
                cout << "Current Author: " << line.substr(line.find(":") + 2) << endl; // Print current author
            else if (line.find("ISBN:") != string::npos)
                cout << "Current ISBN: " << line.substr(line.find(":") + 2) << endl; // Print current ISBN
            else if (line.find("Quantity:") != string::npos)
                cout << "Current Quantity: " << line.substr(line.find(":") + 2) << endl; // Print current quantity
        }

        inFile.close();

        string newTitle, newAuthor, newISBN, newQuantity;

        cout << "\t\t\t\t\tEnter new title (Press Enter to keep current): ";
        getline(cin, newTitle);

        cout << "\t\t\t\t\tEnter new author (Press Enter to keep current): ";
        getline(cin, newAuthor);

        cout << "\t\t\t\t\tEnter new ISBN (Press Enter to keep current): ";
        getline(cin, newISBN);

        cout << "\t\t\t\t\tEnter new quantity (Press Enter to keep current): ";
        getline(cin, newQuantity);

        // Update the file with new information if provided
        ofstream outFile(filename);
        outFile << (newTitle.empty() ? "Title:" : "Title: " + newTitle) << endl;
        outFile << (newAuthor.empty() ? "Author:" : "Author: " + newAuthor) << endl;
        outFile << (newISBN.empty() ? "ISBN:" : "ISBN: " + newISBN) << endl;
        outFile << (newQuantity.empty() ? "Quantity:" : "Quantity: " + newQuantity) << endl;
        outFile.close();

        cout << "\n\t\t\t\t\tBook information updated successfully!\n";
        cout << "\n\t\t\t\t\t...Press Enter to go back...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        return true; // Book updated
    }
    else
    {
        cout << "Book not found!" << endl;

        cout << "\n\t\t\t\t\t...Press Enter to go back...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        return false; // Book not found
    }
}

/*
bool Library_Database::searchLibrarian(const string &librarianID) {
    string filename = R"(UserData\Librarianinfo\)" + librarianID + ".txt";
    ifstream inFile(filename);

    if (inFile.is_open()) {
        string librarianName, foundLibrarianID, password, email, passKey, phoneNumber, line;

        while (getline(inFile, line)) {
            if (line.find("Librarian Name:") != string::npos)
                librarianName = line.substr(line.find(":") + 2); // Extract librarian name
            else if (line.find("Librarian ID:") != string::npos)
                foundLibrarianID = line.substr(line.find(":") + 2); // Extract librarian ID
            else if (line.find("Password:") != string::npos)
                password = line.substr(line.find(":") + 2); // Extract password
            else if (line.find("Email:") != string::npos)
                email = line.substr(line.find(":") + 2); // Extract email
            else if (line.find("Pass Key:") != string::npos)
                passKey = line.substr(line.find(":") + 2); // Extract pass key
            else if (line.find("Phone Number:") != string::npos)
                phoneNumber = line.substr(line.find(":") + 2); // Extract phone number
        }

        // Check if all necessary information is found before printing
        if (!librarianName.empty() && !foundLibrarianID.empty() && !password.empty() &&
            !email.empty() && !passKey.empty() && !phoneNumber.empty()) {
            // Print the librarian information
            cout << "\t\t\t\t\tLibrarian Name: " << librarianName << endl << endl;
            cout << "\t\t\t\t\tLibrarian ID: " << foundLibrarianID << endl << endl;
            cout << "\t\t\t\t\tPassword: ******" << endl; // password << endl;
            cout << "\t\t\t\t\tEmail: " << email << endl << endl;
            cout << "\t\t\t\t\tPass Key: " << passKey << endl << endl;
            cout << "\t\t\t\t\tPhone Number: " << phoneNumber << endl << endl;
            inFile.close();
            return true; // librarian found
        }
        inFile.close();
    }
    return false; // librarian not found or incomplete information
}
*/
bool Library_Database::displaylibrarianProfile(const string &librarianID) // libiran profile view
{
    string filename = R"(UserData\Librarianinfo\)" + librarianID + ".txt";
    ifstream inFile(filename);

    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            cout << "\t\t\t\t\t\t" << line << endl
                 << endl;
        }
        inFile.close();
        return true;
    }
    return false;
}

bool Library_Database::LibsearchStudent(const string &ID) // libirian view Student profile
{
    string filename = "UserData\\StudentInfo\\" + ID + ".txt";
    ifstream inFile(filename);

    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            cout << "\t\t\t\t\t\t" << line << endl
                 << endl;
        }
        inFile.close();
        return true;
    }
    return false;
}

///////////////////////////////////////////////////////STUDENT PART //////////////////////////////////////////////////////

bool Library_Database::searchStudent(const string &ID) // student view profile
{
    string filename = "UserData\\StudentInfo\\" + ID + ".txt";
    ifstream inFile(filename);

    if (inFile.is_open())
    {
        string studentName, studentID, password, email, department, phoneNumber;
        string line;

        while (getline(inFile, line))
        {
            if (line.find("Student Name:") != string::npos)
                studentName = line.substr(line.find(":") + 2); // Extract student name
            else if (line.find("Student ID:") != string::npos)
                studentID = line.substr(line.find(":") + 2); // Extract student ID
            else if (line.find("Password:") != string::npos)
                password = line.substr(line.find(":") + 2); // Extract password
            else if (line.find("Email:") != string::npos)
                email = line.substr(line.find(":") + 2); // Extract email
            else if (line.find("Department:") != string::npos)
                department = line.substr(line.find(":") + 2); // Extract department
            else if (line.find("Phone Number:") != string::npos)
                phoneNumber = line.substr(line.find(":") + 2); // Extract phone number
        }

        // Check if all necessary information is found before printing
        if (!studentName.empty() && !studentID.empty() && !password.empty() &&
            !email.empty() && !department.empty() && !phoneNumber.empty())
        {
            // Print the student information
            cout << "\t\t\t\t\tStudent Name: " << studentName << endl;
            cout << endl;
            cout << "\t\t\t\t\tStudent ID: " << studentID << endl;
            cout << endl;
            cout << "\t\t\t\t\tPassword: ******" << endl; // password << endl;
            cout << endl;
            cout << "\t\t\t\t\tEmail: " << email << endl;
            cout << endl;
            cout << "\t\t\t\t\tDepartment: " << department << endl;
            cout << endl;
            cout << "\t\t\t\t\tPhone Number: " << phoneNumber << endl;
            cout << endl;
            inFile.close();
            return true; // Student found
        }
        inFile.close();
    }
    return false; // Student not found
}

bool Library_Database::displayProfileStatus(const string &studentID)
{
    ifstream inFile(R"(Bookinfo\UserBookinfo\)" + studentID + ".txt");

    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            cout << "\t\t\t\t\t\t" << line << endl << endl;
        }
        inFile.close();
        return true;
    }
    return false;
}

bool Library_Database::searchBorrowBookISBN(const string &isbn)
{
    string folderPath = R"(UserData\StudentBookinfo\)"; 
    string filename = folderPath + isbn + ".txt";
    ifstream inFile(filename);

    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            cout << "\t\t\t\t\t\t" << line << endl << endl;
        }
        inFile.close();
        return true;
    }

    cout << endl;
    cout << "\t\t\t\t\t\tBook not found!" << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "\t\t\t\t\t...Press Enter to go back...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return false;
}

bool Library_Database::AlreadyborrowBook(const string &studentID, const string &isbn)
{
    string folderPath = R"(UserData\StudentBookinfo\)";
    string filename = folderPath + studentID + isbn + ".txt";
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        inFile.close();
        return true;
    }
    return false;
}

bool Library_Database::borrowBook(const string &studentID, const string &isbn)
{
    // Get current time
    time_t currentTime = time(nullptr);
    string timeString = ctime(&currentTime);
    // Create a filename based on the student studentID
    string filename = R"(UserData\StudentBookinfo\)" + studentID + isbn + ".txt"; // Path to student data file
    // Open the file for writing
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        cout << "\t\t\t\t\tError: Unable to create student records file." << endl;
        return false;
    }
    // Write student information to the file
    outFile << "Student ID:" << studentID << endl
            << "ISBN:" << isbn << endl
            << "Time:" << timeString << endl; // Add semicolon here
    // Close the file
    outFile.close();
    return true;
}

bool Library_Database::returnBook(const string &ReturnBook, const string &studentID, const string &isbn)
{
    string folderPath = R"(UserData\StudentBookinfo\)";
    string filename = folderPath + studentID + isbn + ".txt";
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        inFile.close();
        string newFilename = folderPath + "returnbook" + studentID + isbn + "xz" + ".txt";

        if (rename(filename.c_str(), newFilename.c_str()) == 0)
        {
            cout << "\t\t\t\t\tFile return successfully!" << endl;
            return true;
        }
        else
        {
            cout << "\t\t\t\t\tError renaming the file!" << endl;
            return false;
        }
    }
    else
    {
        cout << endl;cout << endl;
        cout << "\t\t\t\t\tFile does not exist!" << endl;
        return false;
    }
}

void Library_Database::lostReport(const string &lostBookISBN, const string &studentID, const string &studentName, const string &description)
{
    string FilePath = R"(Bookinfo\Notificatons\)" + studentID + lostBookISBN + "lost_reports.txt";
    ofstream notificationFile(FilePath, ios::app); // Open file in append mode

    if (notificationFile.is_open())
    {
        // Write information into the file
        notificationFile << "Lost Book ISBN: " << lostBookISBN << endl;
        notificationFile << "Student ID: " << studentID << endl;
        notificationFile << "Student Name: " << studentName << endl;
        notificationFile << "Description: " << description << endl;
        // Close the file
        notificationFile.close();
    }
}
