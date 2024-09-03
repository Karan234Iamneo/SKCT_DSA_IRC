#include <iostream>
using namespace std;

void findMaxInEachFrame(int packets[], int n, int k) {
    for (int i = 0; i <= n - k; ++i) {
        int maxVal = packets[i];
        for (int j = 1; j < k; ++j) {
            if (packets[i + j] > maxVal) {
                maxVal = packets[i + j];
            }
        }
        cout << maxVal << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int packets[n];
    for (int i = 0; i < n; ++i) {
        cin >> packets[i];
    }

    int k;
    cin >> k;

    findMaxInEachFrame(packets, n, k);

    return 0;
}
