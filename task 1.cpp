#include <iostream>
using namespace std;
void print(int arr[], int s);
int main() {
    int num[5] = { 1, 2, 90, 9, 67 };
    print(num, 5);
    return 0;
}
void print(int arr[], int s) {
    for (int i= 0; i< s; i++) {
        cout << arr[i] << endl;
    }
}
