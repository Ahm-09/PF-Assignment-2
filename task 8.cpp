#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int word(const string& file);
int main() {
    string file;
    cout << "enter  the filename: ";
    cin >> file;
    cout << "Word present: " << word(file);
    return 0;
}
int word(const string& file) {
    ifstream f1(file);
    string word;
    int c = 0;
    while (f1 >> word) {
        c++;
    }
    f1.close();
    return c;
}