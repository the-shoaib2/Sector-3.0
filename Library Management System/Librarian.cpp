#include "Librarian.h"

Library_Database ldb;
Library_Management_System lms;
void Librarian::librarian_portal(const string &librarianID)
{
    bool loop = true;
    while (loop)
    {
        system("cls");
        cout << "========================================================================================================================\n";
        cout << "\t\t\t\t\t\t<<<<< LIBRARIAN PORTAL >>>>>\n";
        cout << "========================================================================================================================";
        cout << endl
             << endl;
        cout << "\t\t\t\t\t\t[1]---VIEW PROFILE" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t[2]---LIBRARY BOOK INFO" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t[3]---ADD A NEW BOOK" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t[4]---SEARCH AN EXISTING BOOK" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t[5]---DISPLAY ALL BOOKS" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t[6]---DELETE A BOOK" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t[7]---UPDATE A EXISTING BOOK" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t[8]---SEARCH A STUDENT" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t[0]---LOGOUT AS LIBRARIAN" << endl;
        cout << endl
             << endl;
        cout << "\t\t\t\t\t\tENTER YOUR CHOICE HERE: ";

        int choice;
        while (!(cin >> choice))
        {
            cin.clear();                                         // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cout << "\t\t\t\tERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n\n";
            cout << "\t\t\t\t\t\tENTER YOUR CHOICE HERE: ";
        }

        string isbnupdate, isbn, id, isbnToDelete;

        switch (choice)
        {
        case 1:
            system("cls");
            cout << "========================================================================================================================\n";
            cout << "\t\t\t\t\t\t<<<<< LIBRARIAN PROFILE >>>>>\n";
            cout << "========================================================================================================================\n";
            cout << endl
                 << endl;

            ldb.displaylibrarianProfile(librarianID);
            cout << endl
                 << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\t\t  ...Press Enter to back...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); // Wait for the Enter key
            break;

        case 2:
            system("cls");
            cout << "========================================================================================================================\n";
            cout << "\t\t\t\t\t\t<<<<< LIBRARY INFORMATION >>>>>\n";
            cout << "========================================================================================================================\n";
            cout << endl
                 << endl;
            ldb.displayLibStatus();
            cout << endl
                 << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\t...Press Enter to go back...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        case 3:
            system("cls");
            cout << "========================================================================================================================\n";
            cout << "\t\t\t\t\t\t<<<<< LIBRARY ADD BOOK >>>>>\n";
            cout << "========================================================================================================================\n";
            cout << endl
                 << endl
                 << endl;
            ldb.addBook();
            break;
        case 4:
            system("cls");
            cout << "========================================================================================================================\n";
            cout << "\t\t\t\t\t\t<<<<< LIBRARIAN BOOK SEARCH PANEL >>>>>\n";
            cout << "========================================================================================================================\n";
            cout << endl
                 << endl
                 << endl;

            cout << "\t\t\t\t\t\tENTER ISBN TO SEARCH: ";
            cin >> isbn; // Read the ISBN number
            ldb.searchBookByISBN_LIBIRIN(isbn);
            break;
        case 5:
            system("cls");
            cout << "========================================================================================================================\n";
            cout << "\t\t\t\t\t\t<<<<< LIBRARY ALL BOOKS >>>>>\n";
            cout << "========================================================================================================================\n";
            cout << endl
                 << endl
                 << endl;
            // ldb.displayAllBooks();
            cout << "\t\t\t\t\t...NOT IMPLEMENT YET...";
            cout << endl
                 << endl
                 << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\t...Press Enter to back...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); // Wait for the Enter key
            break;
        case 6:
            system("cls");
            cout << "========================================================================================================================\n";
            cout << "\t\t\t\t\t\t<<<<< REMOVE BOOK  >>>>>\n";
            cout << "========================================================================================================================\n";
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\tENTER ISBN TO DELETE: ";
            cin >> isbnToDelete;
            ldb.deleteBook(isbnToDelete);
            break;
        case 7:
            system("cls");
            cout << "========================================================================================================================\n";
            cout << "\t\t\t\t\t\t<<<<< UPADATE BOOK INFORATION >>>>>\n";
            cout << "========================================================================================================================\n";
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\tENTER ISBN TO UPDATE: ";
            cin >> isbnupdate;
            ldb.updateBook(isbnupdate);
            break;
        case 8:
            system("cls");
            cout << "========================================================================================================================\n";
            cout << "\t\t\t\t\t\t<<<<< SEARCH A STUDENT >>>>>\n";
            cout << "========================================================================================================================\n";
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\tENTER ID TO SEARCH STUDENT: ";
            cin >> id;
            cout << endl
                 << endl;
            if (ldb.LibsearchStudent(id))
            {
                cout << "\t\t\t\t\tStudent Profile Status NOT IMPLEMENT" << endl;
                // student profile status and fine calculate fungtion call inside hare
            }
            else
            {
                cout << "\t\t\t\t\tStudent with ID " << id << " does not exist." << endl;
            }

            cout << endl
                 << endl
                 << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t\t\t...Press Enter to go back...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        case 0:
            system("cls");
            lms.logout();
            loop = false;
            break;
        default:
            cout << "\t\t\t\t\t\t\nERROR! INVALID OPTION ENTERED, PLEASE TRY AGAIN\n";
            break;
        }
    }
}
