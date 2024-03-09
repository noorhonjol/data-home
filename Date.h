#ifndef DATA_HOME_DATE_H
#define DATA_HOME_DATE_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

struct Date {
public:
    Date() {
        putDefault();
    }

    Date(const char* date) {
        fillDate(date);
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.day << '/' << date.month << '/' << date.year << std::endl;
        return os;
    }

    bool operator==(const Date& date) const {
        return day == date.day && month == date.month && year == date.year;
    }

private:
    void fillDate(const char* date) {
        char* copy = strdup(date);

        const char* separators = "/";
        char* token = strtok(copy, separators);

        int dateValues[] = { 0, 0, 0 };

        for (int i = 0; i < 3; ++i) {
            if (token == nullptr || strlen(token) > ((i == 2) ? 5 : 3)) {
                handleBadInput("There is bad input");
                free(copy);
                return;
            }

            dateValues[i] = convertToInt(token);
            token = strtok(nullptr, separators);
        }

        if(!checkResults(dateValues)){
            handleBadInput("There is bad input");
            return;
        }

        this->day = dateValues[0];
        this->month = dateValues[1];
        this->year = dateValues[2];

        free(copy);
    }

    int convertToInt(const char* num) {
        int number = 0;

        for (int i = 0; num[i]; i++) {
            if (!isdigit(num[i])) {
                cerr << "Invalid numeric input\n";
                exit(EXIT_FAILURE);
            }
            number = number * 10 + (num[i] - '0');

        }

        return number;
    }

    void putDefault() {
        day = 1;
        month = 1;
        year = 2000;
    }

    bool checkResults(const int dateValues[]) {

        bool isValidDay=dateValues[0] <= 31 && dateValues[0] >= 1;
        bool isValidMonth= dateValues[1] <= 12 && dateValues[1] >= 1;
        bool isValidYear=dateValues[2] >= 0;

        if (!isValidDay|| !isValidMonth||!isValidYear||!checkEdgeDateOfYears(dateValues)) {
            return false;
        }

        return true;
    }

    bool checkEdgeDateOfYears(const int dateValues[]) {

        bool isValidLeaperYear=dateValues[2]%4==0;

        if(dateValues[1] == 2){
            bool isValidFeb = ((isValidLeaperYear && dateValues[0] <= 29) || (!isValidLeaperYear && dateValues[0] <= 28));
            return isValidFeb;
        }

        bool isValid30Days=((dateValues[1] <= 7 && dateValues[1] % 2 == 0 )|| (dateValues[1] >= 8 && dateValues[1] % 2 != 0))&& dateValues[0] <= 30;

        bool isValid31Days= ( (dateValues[1] <= 7 && dateValues[1] % 2 != 0 || (dateValues[1] >= 8 && dateValues[1] % 2 == 0)) ) && dateValues[0] <= 31;


        return isValid30Days||isValid31Days;
    }

    void handleBadInput(const char* message) {
        cout << message << endl;
        putDefault();
    }

    int day;
    int month;
    int year;
};

#endif // DATA_HOME_DATE_H
