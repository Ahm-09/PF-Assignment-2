#include <iostream>
using namespace std;
int sum1(int arr[], int s);
int main() {
    int num[5] = { 5, 9, 15, 20, 75 };
    cout << "Sum is: " << sum1(num, 5) << endl;
    return 0;
}
int sum1(int arr[], int s) {
    int sum= 0;
    for (int i =0; i<s; i++) {
        sum = sum + arr[i];
    }
    return sum;
}
