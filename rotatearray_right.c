#include <stdio.h>

// Function to right rotate array
void rightRotate(int a[], int n, int k) {
    // If rotation is greater than size of array
    k = k % n;

    for (int i = 0; i < n; i++) {
        if (i < k) {
            // Printing rightmost kth elements
            printf("%d ", a[n + i - k]);
        } else {
            // Prints array after 'k' elements
            printf("%d ", a[i - k]);
        }
    }
    printf("\n");
}

// Driver code
int main() {
    int Array[] = {1, 3, 5, 7, 9};
    int N = sizeof(Array) / sizeof(Array[0]);
    int K = 4;
    
    rightRotate(Array, N, K);
    return 0;
}
