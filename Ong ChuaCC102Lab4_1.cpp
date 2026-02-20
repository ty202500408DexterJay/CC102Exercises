#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int numStudents, numQuizzes;

    cout << "=== Student Quiz Averages ===" << endl;
    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << "Enter number of quizzes: ";
    cin >> numQuizzes;
    cin.ignore();

    vector<string> names(numStudents);
    vector<double> averages(numStudents);

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter name for student " << (i + 1) << ": ";
        getline(cin, names[i]);

        double total = 0;
        for (int j = 0; j < numQuizzes; j++) {
            double score;
            cout << "  Quiz " << (j + 1) << " score: ";
            cin >> score;
            total += score;
        }
        cin.ignore();
        averages[i] = total / numQuizzes;
    }

    cout << "\n--- Results ---" << endl;
    cout << left << setw(20) << "Student"
         << right << setw(10) << "Average"
         << setw(8) << "Grade" << endl;
    cout << string(38, '-') << endl;

    double classTotal = 0;
    for (int i = 0; i < numStudents; i++) {
        string grade;
        if      (averages[i] >= 90) grade = "A";
        else if (averages[i] >= 80) grade = "B";
        else if (averages[i] >= 70) grade = "C";
        else if (averages[i] >= 60) grade = "D";
        else                        grade = "F";

        cout << left  << setw(20) << names[i]
             << right << setw(10) << fixed << setprecision(2) << averages[i]
             << setw(8) << grade << endl;

        classTotal += averages[i];
    }

    cout << string(38, '-') << endl;
    cout << left  << setw(20) << "Class Average"
         << right << setw(10) << fixed << setprecision(2)
         << (classTotal / numStudents) << endl;

    return 0;
}
