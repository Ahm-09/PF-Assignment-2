#include <iostream>
using namespace std;
int find(int arr[], int s);
int main() {
    int arr[5] = { 34, 7, 32, 99, 1 };
    cout << "Maximum number is " << find(arr, 5);
    return 0;
}
    int find(int arr[], int s) {
        int max=arr[0];
        for (int i =1; i<s; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
