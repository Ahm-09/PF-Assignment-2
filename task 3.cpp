#include <iostream>
using namespace std;
int Vowel(char str[]);
int main() {
    char str[150];
    cout << "enter : ";
    cin.getline(str, 150);
    cout << "Vowels are: " << Vowel(str);
    return 0;
}int Vowel(char str[]) {
    int count= 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c =(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
     ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}
