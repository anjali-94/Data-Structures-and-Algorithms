#include <stdio.h>

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

// Function to right rotate array
void rightRotate(int a[], int n, int k) {
    // If rotation is greater than size of array
    k = k % n;

    int temp[k];
    int j = 0;

    // Store the last k elements in a temporary array
    for (int i = n - k; i < n; i++) {
        temp[j] = a[i];
        j++;
    }

    // Shift elements to the right by k positions
    for (int i = n - 1; i >= k; i--) {
        a[i] = a[i - k];
    }

    // Copy back the temporary array to the beginning
    for (int i = 0; i < k; i++) {
        a[i] = temp[i];
    }
    printf("\n");
}

// Driver code
int main() {
    int Array[] = {1, 3, 5, 7, 9};
    int N = sizeof(Array) / sizeof(Array[0]);
    int K = 4;
    print_array(Array, N);
    rightRotate(Array, N, K);
    print_array(Array, N);
    return 0;
}
