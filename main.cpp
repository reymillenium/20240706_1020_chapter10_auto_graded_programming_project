/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                             *
 *   Name: Reinier Garcia Ramos                                                                *
 *                                                                                             *
 *   Program Title/Name:                                                                       *
 *   Chapter 10: Auto-Graded Programming Project                                               *
 *                                                                                             *
 *   Purpose:                                                                                  *
 *   Receives a datetime in the format "YYYY-MM-DD HH:MM:SS" from the console, must            *
 *   validate it and then return the following format:                                         *
 *   "DDth of MonthName, YYYY at HH:MM AM/PM"                                                  *
 *                                                                                             *
 *   More Details:                                                                             *
 *   https://github.com/reymillenium/20240706_1020_chapter10_auto_graded_programming_project   *
 *                                                                                             *
 *                                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <regex>


using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setfill;
using std::string;
using std::to_string;
using std::vector;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::smatch;
using std::stoi;


// Gets a string with or without spaces, from the terminal
string getString();

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(long long int);

void displayResults(double, double, double);

// Function to validate the DateTime(YYYY-MM-DD HH:MM:SS)
bool validDateTime(const string &);

// Function to extract all the components of a DateTime(YYYY-MM-DD HH:MM:SS)
vector<string> getComponentsFromDateTime(const string &);

// Function to convert from a military Time (24 hours format) to civilian Time (12 hours format with meridian)
string convertTimeToCivilian(int, int);

// Main Function
int main() {
    vector<string> monthNames {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const string userInput = getString();

    if (validDateTime(userInput)) {
        const vector<string> componentsFromDateTime = getComponentsFromDateTime(userInput);
        const string yearAsString = componentsFromDateTime[1];
        const string monthAsString = componentsFromDateTime[2];
        const string dayAsString = componentsFromDateTime[3];
        const string hoursAsString = componentsFromDateTime[4];
        const string minutesAsString = componentsFromDateTime[5];
        cout << setw(4) << setfill('0') << ordinalFromNumber(stoi(dayAsString)) << " of " << monthNames[stoi(monthAsString) - 1] << ", " << yearAsString << " at " << convertTimeToCivilian(stoi(hoursAsString), stoi(minutesAsString)) << endl;
    } else
        cout << "Invalid datetime format" << endl;

    return 0;
}

// Gets a string with or without spaces, from the terminal
string getString() {
    string value;
    getline(cin, value);
    return value;
}

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(const long long int number) {
    const long long int lastDigit = number % 10;
    string additive;

    switch (number) {
        case 11:
        case 12:
            additive = "th";
            break;
        default:
            switch (lastDigit) {
                case 1:
                    additive = "st";
                    break;
                case 2:
                    additive = "nd";
                    break;
                case 3:
                    additive = "rd";
                    break;
                default:
                    additive = "th";
                    break;
            }
            break;
    }

    return to_string(number) + additive;
}

// Function to validate the DateTime(YYYY-MM-DD HH:MM:SS)
bool validDateTime(const string &datetimeAsString) {
    if (datetimeAsString.empty()) return false;

    // RegExp to check a valid DateTime(YYYY-MM-DD HH:MM:SS).
    const regex pattern("^([0-9]{4})-(01|02|03|04|05|06|07|08|09|10|11|12)-([0-2][0-9]|30|31)"
        "\\s([0-1][0-9]|[2][0-3]):([0-5][0-9]):([0-5][0-9])"
        "$");

    return regex_match(datetimeAsString, pattern);
}

// Function to extract all the components of a DateTime(YYYY-MM-DD HH:MM:SS)
vector<string> getComponentsFromDateTime(const string &datetimeAsString) {
    vector<string> dataComponents;

    // RegExp to check a valid DateTime(YYYY-MM-DD HH:MM:SS).
    const regex pattern("^([0-9]{4})-(01|02|03|04|05|06|07|08|09|10|11|12)-([0-2][0-9]|30|31)"
        "\\s([0-1][0-9]|[2][0-3]):([0-5][0-9]):([0-5][0-9])"
        "$");
    smatch matches;

    if (regex_search(datetimeAsString.begin(), datetimeAsString.end(), matches, pattern)) {
        for (string match: matches) {
            dataComponents.push_back(match);
        }
    }

    return dataComponents;
}

// Function to convert from a military Time (24 hours format) to civilian Time (12 hours format with meridian)
string convertTimeToCivilian(const int militaryHours, const int minutes) {
    string meridian;
    int civilianHours;

    // Handle midnight and noon
    if (militaryHours == 0) {
        civilianHours = 12;
        meridian = "AM";
    } else if (militaryHours == 12) {
        civilianHours = 12;
        meridian = "PM";
    } else if (militaryHours < 12) {
        civilianHours = militaryHours;
        meridian = "AM";
    } else {
        civilianHours = militaryHours - 12;
        meridian = "PM";
    }

    // cout << civilianHours << ":" << (minutes < 10 ? "0" : "") << minutes << meridian << endl;
    return to_string(civilianHours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes) + " " + meridian;
}
