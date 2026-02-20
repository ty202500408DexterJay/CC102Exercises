#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    double sales[12];
    double total = 0;

    cout << "=== Monthly Sales Summary ===" << endl;

    for (int i = 0; i < 12; i++) {
        cout << "Enter sales for " << months[i] << ": $";
        cin >> sales[i];
        total += sales[i];
    }

    double average = total / 12;
    double highest = sales[0], lowest = sales[0];
    int highIdx = 0, lowIdx = 0;

    for (int i = 1; i < 12; i++) {
        if (sales[i] > highest) { highest = sales[i]; highIdx = i; }
        if (sales[i] < lowest)  { lowest  = sales[i]; lowIdx  = i; }
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Monthly Sales Report ---" << endl;

    for (int i = 0; i < 12; i++) {
        cout << left << setw(12) << months[i] << ": $" << sales[i] << endl;
    }

    cout << "\nTotal Annual Sales : $" << total << endl;
    cout << "Monthly Average    : $" << average << endl;
    cout << "Highest Month      : " << months[highIdx] << " ($" << highest << ")" << endl;
    cout << "Lowest Month       : " << months[lowIdx]  << " ($" << lowest  << ")" << endl;

    cout << "\n--- Quarterly Totals ---" << endl;
    string quarters[] = { "Q1 (Jan-Mar)", "Q2 (Apr-Jun)", "Q3 (Jul-Sep)", "Q4 (Oct-Dec)" };
    for (int q = 0; q < 4; q++) {
        double qTotal = sales[q*3] + sales[q*3+1] + sales[q*3+2];
        cout << left << setw(14) << quarters[q] << ": $" << qTotal << endl;
    }

    return 0;
}
