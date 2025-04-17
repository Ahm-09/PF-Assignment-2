#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void f1(string text);
int main() {
    string t;
    cout << "enter text please: ";
    getline(cin, t);
    f1(t);
    return 0;
}
void f1(string text) {
    ofstream f2("output.txt");
    f2 << text;
    f2.close();
    cout << "Text saved to output.txt";
}