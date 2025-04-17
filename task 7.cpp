#include <iostream>
using namespace std;
void reverse(char str[]);
int main() {
    char input1[100];
    cout << "Enter a string: ";
    cin.getline(input1, 100);
    reverse(input1);
    return 0;
}
void reverse(char str[]) {
    int l = 0;
    while (str[l]!= '\0') {
        l++;
    }
    cout << "Reverse is: ";
    for (int i = l- 1; i>= 0; i--) {
        cout << str[i];
    }
    cout << endl;
}

