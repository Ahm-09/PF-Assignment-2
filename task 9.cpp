#include <iostream>
using namespace std;
bool p(char str[]);
int main() {
    char input[100];
    cout << "enter input: ";
    cin.getline(input, 100);
    if (p(input))
        cout << "It is a palindrome!......" << endl;
    else
        cout << "Not a palindrome.;;;;;;;;;;" << endl;
    return 0;
}
bool p(char str[]) {
    int start = 0;
    int end = 0;
    while (str[end] != '\0') {
        end++;
    }
    end--;
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}