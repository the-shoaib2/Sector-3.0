#include "Library_Management_System.h"
bool validatePassword(const string &password) {
    if (password.length() < 8) {
        cout << "\t\t\t\t\tPassword must be at least 8 characters long." << endl;
        return false;
    }  
    return true;
}
bool isValidPhoneNumber(const string &phoneNumber)
{
    // const regex pattern(R"(^\d{11}$)");
    // return regex_match(phoneNumber, pattern);
    return true;
}
bool isValidEmailStudent(const string &email)

{
    const regex pattern(R"([a-zA-Z0-9._%+-]+@gmail\.com)");
    return regex_match(email, pattern);
}
bool isValidEmailLibrarian(const string &email,const string &librarianID)

{
    // const regex pattern(R"([0-9._%+-]+librarian@gmail\.com)$)");  // librarian@
    const regex pattern(librarianID + R"(lib@gmail\.com)");
    return regex_match(email, pattern);
}

// for print always date & time
string formatCurrentDateTime() {
    // Get the current time point
    auto currentTime = chrono::system_clock::now();
    // Convert the current time to a time_t object
    time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);
    // Convert time_t to a local time struct
    tm* timeinfo = localtime(&currentTimeT);
    // Format the date
    ostringstream dateStream;
    dateStream << "Date: " << put_time(timeinfo, "%d/%m/%Y");
    string formattedDate = dateStream.str();
    // Format the time
    ostringstream timeStream;
    timeStream << "Time: " << put_time(timeinfo, "%I:%M:%S %p");
    string formattedTime = timeStream.str();
    // Return formatted date and time as a combined string
    return ("\t" + formattedDate + "\t\t\t\t\t\t\t\t\t" + formattedTime);
}