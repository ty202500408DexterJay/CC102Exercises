#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimes() {
    ifstream file("NUMS.TXT");
    int num, count = 0;
    
    while (file >> num) {
        if (isPrime(num))
            count++;
    }
    
    file.close();
    return count;
}

int main() {
    cout << "Prime count: " << countPrimes() << endl;
    return 0;
}