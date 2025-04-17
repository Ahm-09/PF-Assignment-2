#include <iostream>
using namespace std;
void copy(int s[], int d[], int size);
int main() {
    int s[5] = { 16, 28, 3, 49, 50 };
    int d[5];
    copy(s, d, 5);
    cout << "so the  copy array is: ";
    for (int i = 0; i < 5; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
void copy(int s[], int d[], int size) {
    for (int i = 0; i < size; i++) {
        d[i] = s[i];
    }
}