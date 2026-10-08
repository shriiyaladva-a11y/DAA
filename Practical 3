#include <iostream>
#include <vector>

// Function to maintain the max-heap property
void heapify(std::vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        std::swap(a[i], a[largest]); // Using C++ built-in swap
        heapify(a, n, largest);
    }
}

// Function to implement heap sort
void heapSort(std::vector<int>& a) {
    int n = a.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        std::swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid array size." << std::endl;
        return 0;
    }

    std::vector<int> a(n);
    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    heapSort(a);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
