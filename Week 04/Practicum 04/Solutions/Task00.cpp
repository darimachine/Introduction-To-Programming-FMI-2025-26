#include <iostream>

bool isLeapYear(const int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int daysInMonth(const int month, const int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 0;
    }
}

bool isValidDate(const int day, const int month, const int year) {
    if (month < 1 || month > 12) return false;
    int dim = daysInMonth(month, year);
    return day >= 1 && day <= dim;
}

void addDays(int& day, int& month, int& year, int n) {
    while (n > 0) {
        int daysInCurrentMonth = daysInMonth(month, year);
        if (daysInCurrentMonth == 0) return;

        if (day + n <= daysInCurrentMonth) {
            day += n;
            n = 0;
        } else {
            n -= (daysInCurrentMonth - day + 1);
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                ++year;
            }
        }
    }
}

void readInput(int& day, int& month, int& year, int& n) {
    std::cout << "Enter day, month, year: ";
    std::cin >> day >> month >> year;

    std::cout << "Enter number of days to add: ";
    std::cin >> n;
}

void printDate(const int day, const int month, const int year) {
    std::cout << "New date: " << day << ' ' << month << ' ' << year << '\n';
}

int main() {
    int day, month, year, n;
    readInput(day, month, year, n);

    if (!isValidDate(day, month, year)) {
        std::cout << "Invalid date.\n";
        return 1;
    }

    addDays(day, month, year, n);
    printDate(day, month, year);
    return 0;
}
