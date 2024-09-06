#include "main.h"
int main()
{
    Library_Management_System lms;
    Student student;
    Librarian librarian;
    lms.createUserFolder();
    while (true)
    {
        int choice;
        system("cls");
        cout << endl
             << formatCurrentDateTime() << endl;
        cout << "========================================================================================================================" << endl;
        cout << "\t\t\t\t\t<<<<< LIBRARY MANAGEMENT SYSTEM MAIN MENU >>>>>" << endl;
        cout << "========================================================================================================================" << endl;
        cout << "" << endl;
        cout << "\t\t\t\t\t\t\t[1]--- LOGIN" << endl;
        cout << "" << endl;
        cout << "\t\t\t\t\t\t\t[2]--- SIGN IN" << endl;
        cout << "" << endl;
        cout << "\t\t\t\t\t\t\t[0]--- EXIT" << endl;
        cout << "" << endl;
        cout << "\t\t\t\t\t\tENTER YOUR CHOICE HERE: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << endl
                 << formatCurrentDateTime() << endl;
            cout << "========================================================================================================================" << endl;
            cout << "\t\t\t\t\t<<<<< LIBRARY MANAGEMENT SYSTEM LOGIN PORTAL >>>>>" << endl;
            cout << "========================================================================================================================" << endl;
            cout << "" << endl;
            cout << "\t\t\t\t\t\t[1]---- LOGIN AS STUDENT" << endl;
            cout << "" << endl;
            cout << "\t\t\t\t\t\t[2]---- LOGIN AS LIBRARIAN" << endl;
            cout << "" << endl;
            cout << "\t\t\t\t\t\t[0]---- BACK TO MAIN MENU" << endl;
            cout << "" << endl;
            cout << "\t\t\t\t\t\tENTER YOUR CHOICE HERE: ";
            cin >> choice;

            if (choice == 1)
            {
                const int maxAttempts = 3;
                int attempts = 0;
                bool loggedIn = false;
                string studentID, password;
                string tempstudentID; ///hodai

                while (attempts < maxAttempts)
                {
                    system("cls");
                    cout << endl
                         << formatCurrentDateTime() << endl;
                    cout << "========================================================================================================================" << endl;
                    cout << "\t\t\t\t\t<<<<< LIBRARY MANAGEMENT SYSTEM STUDENT LOGIN PORTAL >>>>>" << endl;
                    cout << "========================================================================================================================" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t\tENTER STUDENT ID: ";
                    cin >> ws; // Clear the whitespace and newline characters
                    getline(cin, studentID);
                    cout << endl;

                    // tempstudentID = studentID;     /*//this is for hodaaaaayy , 😁😁😁😁*/

                    cout << "\t\t\t\t\t\tENTER PASSWORD: ";
                    cin >> ws; // Clear the whitespace and newline characters
                    getline(cin, password);
                    cout << endl;

                    if (lms.login_Student(studentID, password))
                    {
                        loggedIn = true;
                        cout << "\t\t\t\t\t\tStudent login successful!" << endl;
                        // Perform actions after successful login
                        student.StudentUserPanel(studentID);
                        // Break out of the loop if login is successful
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "\t\t\t\t\t\tInvalid ID or password!" << endl;
                        attempts++;
                        cout << "\t\t\t\t\t...Press Enter to back...";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get(); // Wait for the Enter key

                        if (attempts == maxAttempts)
                        {
                            system("cls");
                            cout << "\t\t\t\t\t...Maximum login attempts reached. Exiting..." << endl;
                            break;
                        }
                    }
                }
            }
            else if (choice == 2)
            {
                int Attempts = 3;
                bool loggedIn = false;
                string librarianID, password;

                while (--Attempts >= 0)
                {
                    system("cls");
                    cout << endl
                         << formatCurrentDateTime() << endl;
                    cout << "========================================================================================================================" << endl;
                    cout << "\t\t\t\t\t<<<<< LIBRARY MANAGEMENT SYSTEM LIBRARIAN LOGIN PORTAL >>>>>" << endl;
                    cout << "========================================================================================================================" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t\tENTER LIBRARIAN ID: ";
                    cin >> ws; // Clear the whitespace and newline characters
                    getline(cin, librarianID);
                    cout << endl;

                    cout << "\t\t\t\t\t\tENTER PASSWORD: ";
                    cin >> ws; // Clear the whitespace and newline characters
                    getline(cin, password);
                    cout << endl;

                    if (lms.login_Librarian(librarianID, password))
                    {
                        loggedIn = true;
                        cout << "\t\t\t\t\tlibrarian login successful!" << endl;
                        // Perform actions after successful login
                        librarian.librarian_portal(librarianID);
                        // Break out of the loop if login is successful
                        break;
                    }
                    else
                    {
                        cout << "\t\t\t\t\t\tInvalid ID or password!";
                        cin.clear();                                         // Clear any error flags on cin
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input buffer
                        cout << endl
                             << endl;
                        cout << "\t\t\t\t\t\t...Press Enter to try again...";
                        cin.get(); // Wait for the Enter key
                    }
                }

                if (Attempts < 0)
                {
                    system("cls");
                    cout << "\t\t\t\t\t...Maximum login attempts reached. Exiting..." << endl;
                }
            }

            else if (choice == 0)
            {
                break; // Continue to the main menu
                system("cls");
            }
            else
            {
                cout << "\t\t\t\t\t\tERROR! INVALID OPTION ENTERED" << endl;
            }
            break;
        }

        case 2:
        {
            system("cls");
            cout << endl
                 << formatCurrentDateTime() << endl;
            cout << "========================================================================================================================" << endl;
            cout << "\t\t\t\t\t<<<<< LIBRARY MANAGEMENT SYSTEM SIGN IN PORTAL >>>>>" << endl;
            cout << "========================================================================================================================" << endl;
            cout << endl;
            cout << "\t\t\t\t\t\t[1]---- SIGN IN AS STUDENT" << endl;
            cout << "" << endl;
            cout << "\t\t\t\t\t\t[2]---- SIGN IN AS LIBRARIAN" << endl;
            cout << "" << endl;
            cout << "\t\t\t\t\t\t[0]---- BACK TO MAIN MENU" << endl;
            cout << "" << endl;
            cout << "\t\t\t\t\t\tENTER YOUR CHOICE HERE: ";
            cin >> choice;

            bool isIDValid = false;
            bool isPasswordValid = false;
            bool isEmailValid = false;
            bool isPhoneNumberValid = false;

            if (choice == 1)
            {
                string studentName, studentID, password, email, department, phoneNumber;

                // Input student details
                system("cls");
                cout << endl
                     << formatCurrentDateTime() << endl;
                cout << "========================================================================================================================" << endl;
                cout << "\t\t\t\t\t<<<<< LIBRARY MANAGEMENT SYSTEM STUDENT SIGN IN PORTAL >>>>>" << endl;
                cout << "========================================================================================================================" << endl;
                cout << endl
                     << endl;

                cout << "\t\t\t\t\t\t[*]---- ENTER STUDENT NAME : ";
                cin >> ws; // Clear the whitespace and newline characters
                getline(cin, studentName);
                cout << endl;
                int attemtID = 3;
                while (attemtID--)
                {
                    cout << "\t\t\t\t\t\t[*]---- ENTER STUDENT ID: ";
                    getline(cin, studentID);
                    if (lms.IDSearchStudent(studentID))
                    {
                        isIDValid = true;
                        break;
                    }
                    else
                    {
                        if (attemtID == 2)
                        {
                            cout << "\t\t\t\t\t...Tor " << studentID << " ID Dia account ache..." << endl
                                 << endl;
                        }
                        else if (attemtID == 1) // Sob txt change kora labg
                        {
                            cout << "\t\t\t\t...Tor " << studentID << " ID Dia 1 ta account ache re vaii ,ja gia login kor..." << attemtID << endl;
                        }
                        else if (attemtID == 0)
                        {
                            cout << "\t\t\t\t...Tor kane kotha dhuke na kotobar komu account ache" << studentID << "dia..." << endl;
                            cout << "\t\t\t\t...Ja tor account khola labe na ber ho Ekhan theke.." << studentID << "dia..." << endl;
                        }
                        // cout << "\t\t\t\t\tYou Have " << attemtID << " Atempts..:( " << endl
                        //      << endl;
                    }
                }
                if (attemtID == -1)
                {
                    system("cls");
                    cout << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t...Tor kane kotha dhuke na kotobar komu account ache" << studentID << "dia..." << endl;
                    cout << "\t\t\t\t...Ja tor account khola labe na ber ho Ekhan theke.." << studentID << "dia..." << endl;
                    cout << "\t\t\t\t\t[*]---- Press Enter to Jaldi Eha se Hato----[*]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                    break;
                }
                cout << endl;
                int attemptPassword = 3;
                while (attemptPassword--)
                {
                    cout << "\t\t\t\t\t\t[*]---- ENTER PASSWORD: ";
                    getline(cin, password);
                    if (validatePassword(password))
                    {
                        string reenteredPassword;
                        cout << endl;
                        cout << "\t\t\t\t\t\t[*]---- PLEASE RE-ENTER PASSWORD: ";
                        getline(cin, reenteredPassword);
                        if (reenteredPassword == password)
                        {
                            isPasswordValid = true;
                            break;
                        }
                        else
                        {
                            cout << "\t\t\t\t\t\tPasswords do not match. Try again." << endl;
                            continue; // Restart the loop for password entry
                        }
                    }
                    else
                    {
                        // cout << "\t\t\t\t\tInvalid password. Please enter a valid password." << endl;
                        cout << "\t\t\t\t\tYou have " << attemptPassword << " attempts remaining." << endl
                             << endl;
                    }
                }
                cout << endl;
                if (attemptPassword == -1)
                {
                    system("cls");
                    cout << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t[*]---- Press Enter to Jaldi Eha se Hato----[*]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                    break;
                }
                // this loop for cheak valid email or not
                int attemtemail = 3;
                while (attemtemail--)
                {
                    cout << "\t\t\t\t\t\t[*]---- ENTER EMAIL: ";
                    getline(cin, email);
                    if (isValidEmailStudent(email))
                    {
                        isEmailValid = true;
                        break;
                    }
                    else
                    {
                        cout << "\t\t\t\t\tInvalid email. Please enter a valid email.....:( " << endl;
                        cout << "\t\t\t\t\tYou Have " << attemtemail << " Atempts..:( " << endl
                             << endl;
                    }
                }
                if (attemtemail == -1)
                {
                    system("cls");
                    cout << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t[*]---- Press Enter to Jaldi Eha se Hato----[*]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                    break;
                }
                cout << endl;
                cout << "\t\t\t\t\t\t[*]---- ENTER DEPARTMENT: ";
                cin >> ws; // Clear the whitespace and newline characters
                getline(cin, department);
                // this is for valid phone number
                int attemtnumber = 3;
                while (attemtnumber--)
                {
                    cout << endl;
                    cout << "\t\t\t\t\t\t[*]---- ENTER PHONENUMBER: +88";
                    getline(cin, phoneNumber);
                    if (isValidPhoneNumber(phoneNumber))
                    {
                        isPhoneNumberValid = true;
                        break;
                    }
                    else
                    {
                        cout << "\t\t\t\t\tInvalid phone number. Please enter a valid 11-digit phone number.." << endl;
                        cout << "\t\t\t\t\tYou Have " << attemtnumber << " Atempts..:( " << endl
                             << endl;
                    }
                }
                if (attemtnumber == -1)
                {
                    system("cls");
                    cout << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t[*]---- Press Enter to Jaldi Eha se Hato----[*]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                    break;
                }
                if (isIDValid && isPasswordValid && isEmailValid && isPhoneNumberValid)
                {
                    if (lms.register_student(studentName, studentID, password, email, department, phoneNumber))
                    {
                        // system("cls");
                        cout << endl;
                        cout << "\t\t\t\t\t[*]---- Student registered successfully! ----[*]" << endl
                             << endl;
                        cout << "\t\t\t\t\t\t[*]---- Press Enter to back----[*]";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get(); // Wait for the Enter key
                    }
                }
                else
                {
                    // system("cls");
                    cout << endl
                         << endl;
                    cout << "\t\t\t\t\t[*]---- Failed to register student.----[*]" << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t\t\t[*]---- Press Enter to back----[*]";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                }
            }
            else if (choice == 2)
            {
                string librarianName, librarianID, password, email, Key, phoneNumber;

                system("cls");
                cout << endl
                     << formatCurrentDateTime() << endl;
                cout << "========================================================================================================================" << endl;
                cout << "\t\t\t\t\t<<<<< LIBRARY MANAGEMENT SYSTEM LIBRARIAN SIGN IN PORTAL >>>>>" << endl;
                cout << "========================================================================================================================" << endl;
                cout << endl;

                cout << "\t\t\t\t\t\t[*]---- ENTER LIBRARIAN NAME : ";
                cin >> ws; // Clear the whitespace and newline characters
                getline(cin, librarianName);
                cout << endl;
                int attemtID = 3;
                while (attemtID--)
                {
                    cout << "\t\t\t\t\t\t[*]---- ENTER LIBRARIAN ID: ";
                    getline(cin, librarianID);
                    cout << endl;
                    if (lms.IDSearchLibrarian(librarianID))
                    {
                        isIDValid = true;
                        break;
                    }
                    else
                    {
                        if (attemtID == 2)
                        {
                            cout << "\t\t\t\t\t...You AllRedy Have A Account.. this ID :" << librarianID << endl
                                 << endl;
                        }
                        else if (attemtID == 1) // Sob txt change kora labg
                        {
                            cout << "\t\t\t\t...GO TO LOGIN PAGE ,YOU AllREDY Have A ACCOUNT.." << endl;
                        }
                        else if (attemtID == 0)
                        {
                            cout << "\t\t\t\t...Ja tor account khola labe na ber ho Ekhan theke.." << librarianID << "dia..." << endl;
                        }
                        // cout << "\t\t\t\t\tYou Have " << attemtID << " Atempts..:( " << endl
                        //      << endl;
                    }
                }
                if (attemtID == -1)
                {
                    system("cls");
                    cout << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t...Already have an account .." << librarianID << endl;
                    cout << endl
                         << endl
                         << endl;

                    cout << "\t\t\t\t\t[*]---- Press Enter to Jaldi Eha se Hato----[*]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                    break;
                }
                int attemptPassword = 3;
                while (attemptPassword--)
                {
                    cout << "\t\t\t\t\t\t[*]---- ENTER PASSWORD: ";
                    getline(cin, password);
                    if (validatePassword(password))
                    {
                        string reenteredPassword;
                        cout << endl;
                        cout << "\t\t\t\t\t\t[*]---- PLEASE RE-ENTER PASSWORD: ";
                        getline(cin, reenteredPassword);
                        cout << endl;
                        if (reenteredPassword == password)
                        {
                            isPasswordValid = true;
                            break;
                        }
                        else
                        {
                            cout << "\t\t\t\t\tPasswords do not match. Try again." << endl;
                            continue; // Restart the loop for password entry
                        }
                    }
                    else
                    {
                        // cout << "\t\t\t\t\tInvalid password. Please enter a valid password." << endl;
                        cout << "\t\t\t\t\tYou have " << attemptPassword << " attempts remaining." << endl
                             << endl;
                    }
                }
                if (attemptPassword == -1)
                {
                    system("cls");
                    cout << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t\t[*]---- Press Enter to Jaldi Eha se Hato----[*]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                    break;
                }

                int attemtemail = 3;
                while (attemtemail--)
                {
                    cout << "\t\t\t\t\t\t[*]---- ENTER EMAIL: ";
                    getline(cin, email);
                    cout << endl;
                    if (isValidEmailLibrarian(email, librarianID))
                    {
                        isEmailValid = true;
                        break;
                    }
                    else
                    {
                        cout << "\t\t\t\t\tInvalid email. Please enter a valid email.....:( " << endl;
                        cout << "\t\t\t\t\tYou Have " << attemtemail << " Atempts..:( " << endl
                             << endl;
                    }
                }
                if (attemtemail == -1)
                {
                    system("cls");
                    cout << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t\t[*]---- Press Enter to Jaldi Eha se Hato----[*]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                    break;
                }

                cout << "\t\t\t\t\t\t[*]---- ENTER LIBRARIAN PASS KEY: ";
                cin >> ws; // Clear the whitespace and newline characters
                getline(cin, Key);
                cout << endl;
                int attemtnumber = 3;
                while (attemtnumber--)
                {
                    cout << "\t\t\t\t\t\t[*]---- ENTER PHONENUMBER: +88";
                    getline(cin, phoneNumber);
                    cout << endl;
                    if (isValidPhoneNumber(phoneNumber))
                    {
                        isPhoneNumberValid = true;
                        break;
                    }
                    else
                    {
                        cout << "\t\t\t\t\tInvalid phone number. Please enter a valid 11-digit phone number.." << endl;
                        cout << "\t\t\t\t\tYou Have " << attemtnumber << " Atempts..:( " << endl
                             << endl;
                    }
                }
                if (attemtnumber == -1)
                {
                    system("cls");
                    cout << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl
                         << endl;
                    cout << "\t\t\t\t\t[*]---- Press Enter to Jaldi Eha se Hato----[*]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                    break;
                }
                if (isIDValid && isPasswordValid && isEmailValid && isPhoneNumberValid)

                {
                    if (lms.register_librarian(librarianName, librarianID, password, email, Key, phoneNumber))
                    {
                        // system("cls");
                        cout << "\t\t\t\t\t....Librarian registered successfully!...." << endl
                             << endl
                             << endl;
                        cout << "\t\t\t\t\t....Press Enter to back....";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get(); // Wait for the Enter key
                        system("cls");
                    }
                }
                else
                {
                    // system("cls");

                    cout << "\t\t\t\t\tFailed to register librarian." << endl
                         << endl;
                    cout << "\t\t\t\t\t....Press Enter to back....";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(); // Wait for the Enter key
                }
            }
            else if (choice == 0)
            {
                break;
            }
            else
            {
                cout << "\t\t\t\t\tERROR! INVALID OPTION ENTERED" << endl;
            }
            break;
        }

        case 0:
            cout << "\t\t\t\t\tExiting the application..." << endl;
            return 0;
            system("cls");

        default:
            cout << "\t\t\t\t\tERROR! INVALID OPTION ENTERED" << endl;
            break;
        }
    }
    return 0;
}