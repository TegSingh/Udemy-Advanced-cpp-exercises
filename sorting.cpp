#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;    
}

void swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void selectionSort(int arr[], int size) {
    int first, temp;
    for (int i = size-1; i > 0; i--)
    {
        first = 0;
        for (int j = 1; j <= i; j++)
        {
            // Find the largest number to add at the end of the list
            if (arr[j] > arr[first]) 
                first = j;
            swap(arr[first], arr[i]);
        }
    }
    display(arr, size);
}

void insertionSort(int arr[], int size) {
    int j, temp;
    for (int i = 1; i < size; i++) {
        j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    display(arr, size);
}

// function to join 2 arrays that have been seperated
void merge(int arr[], int size, int low, int middle, int high) {
    int temp[size];
    for (int i = low; i <= high; i++)
        temp[i] = arr[i];    
    int i = low;
    int j = middle + 1;
    int k = low;

    // Merging the 2 seperated arrays
    while (i <= middle && j <= high) {
        if (temp[i] <= temp[j]) {
            arr[k] = temp[i];
            i++; // Increments index for the first half
        }
        else {
            arr[k] = temp[j];
            j++; // Increments index for the second half
        }
        k++; // Increments overall index
    }
    // In case first half has the rest of the values [Note that these values would already be sorted]
    while (i <= middle) {
        arr[k] = temp[i];
        i++;
        k++;
    }
    // In case the second half has not completed merging
    while(j <= high) {
        arr[k] = temp[j];
        j++;
        k++;
    }
}

// Low and high and low and high bound of the array [used in the merge function (worker not public)]
void mergeSort(int arr[], int size, int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2; // middle is calculated to seperate the array into 2 halves
        mergeSort(arr, size, low, middle); // Recursive call to the lower half of the array
        mergeSort(arr, size, middle+1, high); // Recursive call to the upper half of the array
        merge(arr, size, low, middle, high); // By the time this part is reached the first time, the lowest level has been reached
    }
}

// Sort by partitions [first partition has numbers lower than a certain pivot, and the other partition has numbers higher than a chosen pivot]
void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2]; // chosen pivot to rest partitions at
    while (i <= j) {
        // Partition with values lower than pivot
        while (arr[i] < pivot)
            i++;
        // Partition with values higher than pivot
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
} 

int main() {

    const int size = 10;
    int numbers1[size], numbers2[size], numbers3[size], numbers4[size];
    srand(unsigned(time(0))); // Initialize a random number generator
    
    cout << "Selection Sort: " << endl;
    for (int i = 0; i < size; i++) {
        numbers1[i] = (rand() % 100) + 1;
    }
    display(numbers1, size);
    selectionSort(numbers1, size);
    
    cout << "Insertion Sort: " << endl;
    for (int i = 0; i < size; i++) {
        numbers2[i] = (rand() % 100) + 1;
    }
    display(numbers2, size);
    insertionSort(numbers2, size);
    
    // Merge sort is stable
    cout << "Merge Sort: " << endl;
    for (int i = 0; i < size; i++)
        numbers3[i] = (rand() % 100) + 1;
    display(numbers3, size);
    mergeSort(numbers3, size, 0, 9);
    display(numbers3, size);
    
    // Quick sort is not stable [values that are not unique will not be sorted in the order they were found in]
    cout << "Quick Sort: " << endl;
    for (int i = 0; i < size; i++) 
        numbers4[i] = (rand() % 100) + 1;
    display(numbers4, size);
    quickSort(numbers4, 0, size-1);
    display(numbers4, size);

    return 0;
}