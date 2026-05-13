#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ofstream original("original.txt");
    original << "One\nTwo\nThree\nFour\nFive\nSix";
    original.close();

    ifstream inFile("original.txt");
    vector<string> words;
    string line;

    while (getline(inFile, line))
        words.push_back(line);
    inFile.close();

    for (int i = 0; i < words.size() - 1; i++) {
        for (int j = 0; j < words.size() - i - 1; j++) {
            if (words[j] > words[j + 1])
                swap(words[j], words[j + 1]);
        }
    }

    ofstream sorted("sorted.txt");
    for (int i = 0; i < words.size(); i++)
        sorted << words[i] << "\n";
    sorted.close();

    cout << "Done. Check sorted.txt" << endl;
    return 0;
}