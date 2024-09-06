#include "Student.h"
Library_Management_System lms1;
Library_Database ldbs;
// Calculation cal;

void Student::StudentUserPanel(const string &studentID)
{

    while (true)
    {
        system("cls");
        cout << "========================================================================================================================\n";
        cout << "\t\t\t\t\t\t<<<<< STUDENT USER PANEL >>>>>\n";
        cout << "========================================================================================================================\n\n\n";
        cout << "\t\t\t\t\t\t  [1]----VIEW PROFILE" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t  [2]----PROFILE STATUS" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t  [3]----CHECK ALL BOOKS" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t  [4]----SEARCH A BOOK" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t  [5]----BORROW A BOOK" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t  [6]----RETURN A BOOK" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t  [7]----REPORT A LOST BOOK" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t  [8]----CALCULATE FINE" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t  [0]----LOGOUT AS USER" << endl;
        cout << endl
             << endl;
        cout << "\t\t\t\t\t\tENTER YOUR OPTION HERE: ";

        int choice;
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
            cout << "\nPLEASE ENTER YOUR OPTION HERE AGAIN: ";
        }

        string ReturnBook, isbn, lostBookISBN, ID, studentName, description;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "========================================================================================================================\n";
            cout << "\t\t\t\t\t\t<<<<< STUDENT PROFILE >>>>>\n";
            cout << "========================================================================================================================\n\n\n";

            string filename = R"(UserData\Studentinfo\)" + studentID + ".txt";

            // cout << "Student ID :" << studentID << " " << endl;
            ldbs.searchStudent(studentID);

            cout << "\t\t\t\t\t\t...Press ENTER to go back to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        }

        case 2:
            system("cls");
            cout << "========================================================================================================================" << endl;
            cout << "\t\t\t\t\t\t<<<<< STUDENT PROFILE >>>>>\n";
            cout << "========================================================================================================================";
            cout << endl
                 << endl;
            ldbs.displayProfileStatus(studentID);
            cout << endl
                 << endl
                 << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\t...Press ENTER to go back...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;

        case 3:
            system("cls");
            cout << "Check All Books Logic" << endl;
            cout << "\t\t\t\t\t...Press ENTER to go back to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;

        case 4:
            system("cls");
            cout << "========================================================================================================================" << endl;
            cout << "\t\t\t\t\t\t<<<<< STUDENT PROFILE >>>>>\n";
            cout << "========================================================================================================================";
            cout << "" << endl
                 << endl;
            cout << "\t\t\t\t\tENTER ISBN NUMBER TO SEARCH: ";
            cin >> isbn;
            cout << "" << endl
                 << endl;
            if (ldbs.searchBookByISBN_STUDENT(isbn))
            {
                if (ldbs.AlreadyborrowBook(studentID, isbn))
                {
                    cout << endl
                         << endl;
                    cout << "\t\t\t\t\t...This Book Already Borrowed You..." << endl;
                }
                else
                {
                    cout << "\t\t\t\t\t...IF You Need This Book ,Then Borrow The Book..." << endl;
                }
            }
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\t...Press ENTER to go back to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;

        case 5:
            system("cls");
            cout << "========================================================================================================================" << endl;
            cout << "\t\t\t\t\t\t<<<<< STUDENT PROFILE >>>>>\n";
            cout << "========================================================================================================================";
            cout << "" << endl
                 << endl;
            cout << "\t\t\t\t\tENTER ISBN NUMBER TO BORROW: ";
            cin >> isbn;
            cout << "" << endl
                 << endl;
            if (ldbs.searchBookByISBN_STUDENT(isbn))
            {
                if (ldbs.AlreadyborrowBook(studentID, isbn))
                {
                    cout << endl
                         << endl;
                    cout << "\t\t\t\t\t...This Book Already Borrowed You..." << endl;
                }
                else
                {
                    cout << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t\tDo you want to borrow this book? (Y/N): ";
                    string Choice;
                    cin >> Choice;
                    if (Choice == "Y" || Choice == "y")
                    {
                        if (ldbs.borrowBook(studentID, isbn))

                        // cal.BorrowAllTime();
                        // cal.();
                        // TotalBorrowBook++;
                        // BorrowNow++;

                        cout << endl;
                        cout << "\t\t\t\t\tBook borrowed successfully by student ID: " << studentID << endl
                             << endl
                             << endl
                             << endl;
                        cout << "\t\t\t\t\t...Press ENTER to go back to the menu...";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    }
                }
            }
            else
            {
                cout << endl
                     << endl
                     << endl;
                cout << "\t\t\t\t\tBook not available for borrowing." << endl;
            }
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\t...Press ENTER to go back to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;

        case 6:
            system("cls");
            cout << "========================================================================================================================" << endl;
            cout << "\t\t\t\t\t\t<<<<< RETURN BORROW BOOK >>>>>\n";
            cout << "========================================================================================================================";
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "\t\t\t\t\tENTER ISBN NUMBER TO BORROW: ";
            cin >> isbn;
            if (ldbs.returnBook(ReturnBook, studentID, isbn))
            {
                // cal.ReturnBooks();
                // BorrowNow--;
                // ReturnBooks++;
            }
            cout << endl
                 << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\t...Press ENTER to go back to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        case 7:
        {
            system("cls");
            cout << "========================================================================================================================" << endl;
            cout << "\t\t\t\t\t\t<<<<< REPORT BOOK >>>>>\n";
            cout << "========================================================================================================================";
            cout << endl
                 << endl;
            bool isISBNValISBN = false;
            int attemtISBN = 3;

            while (attemtISBN--)
            {
                cout << "\t\t\t\t\t\t[*]---- ENTER LOST BOOK ISBN: ";
                getline(cin, lostBookISBN);

                if (ldbs.searchBookByISBN_STUDENT(lostBookISBN))
                {
                    isISBNValISBN = true;
                    break;
                }
                else
                {
                    cout << "\t\t\t\t...YOU DID NOT BORROW THIS BOOK, ENTER BORROWED BOOK ISBN..." << endl;
                    if (attemtISBN > 0)
                    {
                        cout << "\t\t\t\t\tYou Have " << attemtISBN << " Attempts Left." << endl
                             << endl;
                    }
                    else
                    {
                        cout << "\t\t\t\t\tYou Have No Attempts Left." << endl
                             << endl;
                    }
                }
            }

            if (attemtISBN == -1)
            {
                system("cls");
                cout << "\t\t\t\t\t[*]---- PRESS ENTER TO GO BACK ----[*]" << endl
                     << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get(); // Wait for the Enter key
            }
            else
            {
                cout << endl
                     << "\t\t\t\t\tENTER STUDENT ID: ";
                cin >> ws;
                getline(cin, ID);

                cout << endl
                     << "\t\t\t\t\tENTER STUDENT NAME: ";
                getline(cin, studentName);

                cout << endl
                     << "\t\t\t\t\tENTER DESCRIPTION: ";
                getline(cin, description);

                ldbs.lostReport(lostBookISBN, ID, studentName, description);

                cout << "\t\t\t\t\t...Press ENTER to go back to the menu...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }

            break;
        }

        case 8:
            system("cls");
            cout << "Calculate Fine Logic" << endl;
            cout << "\t\t\t\t\t...Press ENTER to go back to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        case 0:
            system("cls");
            lms1.logout();
            return;

        default:
            cout << "\t\t\t\t\t\tInvalid option. Try again." << endl;
            break;
        }
    }
}
