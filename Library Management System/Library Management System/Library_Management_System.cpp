#include "Library_Management_System.h"

using namespace std;

void Library_Management_System::createUserFolder()
{
    string path;

    // Create Studentinfo folder
    path = R"(UserData\Studentinfo)";
    CreateDirectory(path.c_str(), NULL);

    // Create Librarianinfo folder
    path = R"(UserData\Librarianinfo)";
    CreateDirectory(path.c_str(), NULL);

    // Create StudentBookinfo folder
    path = R"(UserData\StudentBookinfo)";
    CreateDirectory(path.c_str(), NULL);

    // Create Bookinfo folder
    path = R"(Bookinfo)";
    CreateDirectory(path.c_str(), NULL);

    // Create Report/LostNotification folder
    path = R"(Bookinfo\Notificatons)";
    CreateDirectory(path.c_str(), NULL);

    // Create Report/LostNotification folder
    path = R"(Bookinfo\UserBookinfo)";
    CreateDirectory(path.c_str(), NULL);
    
}

bool Library_Management_System::IDSearchLibrarian(const string &ID)
{
    string filename = R"(UserData\Librarianinfo\)" + ID + ".txt";
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        return false;
    }
    inFile.close();
    return true;
}

bool Library_Management_System::IDSearchStudent(const string &ID)
{
    string filename = R"(UserData\StudentInfo\)" + ID + ".txt";
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        return false;
    }
    inFile.close();
    return true;
}

Library_Management_System::Library_Management_System()
{
    logged_in = false;
}

bool Library_Management_System::logout()
{
    logged_in = false;
    ID.clear();
    password.clear();
    return true;
}

bool Library_Management_System::login_Student(const string &studentID, const string &password)
{   // tumse muhabat hee haaa tumse muhabat hee haaa
    string filename = R"(UserData\Studentinfo\)" + studentID + ".txt"; 
    ifstream inFile(filename);
    if (!inFile.is_open())
    {
        // cout << "\t\t\t\t\tError: Unable to open student records file." << endl;
        return false;
    }

    string line;
    string fileID, filePassword, studentName, email, department, phoneNumber;

    // Read line by line
    while (getline(inFile, line))
    {
        if (line.find("Student Name:") != string::npos)
            studentName = line.substr(line.find(":") + 2); // Extract student name
        else if (line.find("Student ID:") != string::npos)
            fileID = line.substr(line.find(":") + 2); // Extract student ID
        else if (line.find("Password:") != string::npos)
            filePassword = line.substr(line.find(":") + 2); // Extract password
        else if (line.find("Email:") != string::npos)
            email = line.substr(line.find(":") + 2); // Extract email
        else if (line.find("Department:") != string::npos)
            department = line.substr(line.find(":") + 2); // Extract department
        else if (line.find("Phone Number:") != string::npos)
        {
            phoneNumber = line.substr(line.find(":") + 2); // Extract phone number

            // Check if ID and password match
            if (fileID == studentID && filePassword == password)
            {
                inFile.close();
                ID = fileID;
                this->password = filePassword;
                logged_in = true;
                return true; // Successful login
            }
        }
    }

    inFile.close();
    return false; // Login failed
}

bool Library_Management_System::login_Librarian(const string &LibrarianID, const string &password)
{
    string filename = R"(UserData\Librarianinfo\)" + LibrarianID + ".txt"; // Path to librarian data file
    ifstream inFile(filename);
    if (!inFile.is_open())
    {
        return false;
    }

    string line;
    string fileID, filePassword, LibrarianName, email, Key, phoneNumber;

    // Read line by line
    while (getline(inFile, line))
    {
        if (line.find("Librarian Name:") != string::npos)
            LibrarianName = line.substr(line.find(":") + 2); // Extract librarian name
        else if (line.find("Librarian ID:") != string::npos)
            fileID = line.substr(line.find(":") + 2); // Extract librarian ID
        else if (line.find("Password:") != string::npos)
            filePassword = line.substr(line.find(":") + 2); // Extract password
        else if (line.find("Email:") != string::npos)
            email = line.substr(line.find(":") + 2); // Extract email
        else if (line.find("Librarian Pass key :") != string::npos)
            Key = line.substr(line.find(":") + 2); // Extract Key
        else if (line.find("Phone Number:") != string::npos)
            phoneNumber = line.substr(line.find(":") + 2); // Extract phone number
    }

    inFile.close();

    // Check if ID and password match
    if (fileID == LibrarianID && filePassword == password)
    {
        ID = fileID;
        this->password = filePassword;
        logged_in = true;
        return true; // Successful login
    }

    return false; // Login failed
}

bool Library_Management_System::register_student(const string &studentName, const string &studentID, const string &password, const string &email, const string &department, const string &phoneNumber)
{
    // Create a filename based on the student ID
    string filename = R"(UserData\Studentinfo\)" + studentID + ".txt"; // Path to student data file

    // Open the file for writing
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        return false;
    }

    // Write student information to the file
    outFile << "Student Name: " << studentName << endl
            << "Student ID: " << studentID << endl
            << "Password: " << password << endl
            << "Email: " << email << endl
            << "Department: " << department << endl
            << "Phone Number: " << phoneNumber << endl;
    // Close the file
    outFile.close();
    return true;
}

bool Library_Management_System::register_librarian(const string &librarianName, const string &librarianID, const string &password, const string &email, const string &Key, const string &phoneNumber)
{
    string filename = R"(UserData\Librarianinfo\)" + librarianID + ".txt"; // Path to librarian data file

    ofstream outFile(filename, ios::app); // Open the file in append mode
    if (!outFile.is_open())
    {
        return false;
    }

    // Write librarian information to the file
    outFile << "Librarian Name: " << librarianName << endl // same id dia 1 tar besi accoutt khola jbe na jodi khoolte jai tahole error dekhabe esob implement korte hoeb
            << "Librarian ID: " << librarianID << endl
            << "Password: " << password << endl
            << "Email: " << email << endl
            << "Librarian Pass key : " << Key << endl // eta implement kora baki pore kormu
            << "Phone Number: " << phoneNumber << endl;

    outFile.close();
    return true;
}
