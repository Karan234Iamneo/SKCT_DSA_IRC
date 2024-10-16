#include <iostream>
#include <vector>
using namespace std;

// Function for linear probing hashing
void hashing(vector<int> arr, int n) {
    vector<int> hash_table(n, -1);  // Initialize the hash table with -1

    for (int i = 0; i < n; i++) {
        int index = arr[i] % n;  // Calculate the hash index

        // If collision happens, perform linear probing
        while (hash_table[index] != -1) {
            index = (index + 1) % n;  // Move to the next slot in case of collision
        }

        // Insert the element at the calculated or probed index
        hash_table[index] = arr[i];
    }

    // Print the final hash table
    for (int i = 0; i < n; i++) {
        cout << hash_table[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;  // Read the size of the array

    vector<int> arr(n);

    // Read the input elements into the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the hashing function
    hashing(arr, n);

    return 0;
}
