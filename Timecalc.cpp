#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
#include <vector>
using namespace std;

int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = low - 1; // Initialize i to low - 1

    for (int j = low; j < high; j++){
        if (array[j] < pivot){
            i++;
            swap(array[i], array[j]);
        }
    }
    i++;
    // Place the pivot element in its correct position
    swap(array[i], array[high]);

    return i;
}
void quickSortRecursive(int array[], int low, int high ){
    if(low < high){
        // Partition the array and get the pivot index
        int pivot = partition(array, low, high);
        // Recursively sort the left and right subarrays
        quickSortRecursive(array, low, pivot-1);
        quickSortRecursive(array, pivot+1, high);
    }
}

void quickSortIterative(int arr[], int start, int end)
{
    int stack[end - start + 1];
    int top = -1;
    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0)
    {
        end = stack[top--];
        start = stack[top--];

        int i = start, j = end;
        int tmp;
        int pivot = arr[(start + end) / 2];

        /* partition */
        while (i <= j)
        {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        };

        /* push values to stack */
        if (i < end)
        {
            stack[++top] = i;
            stack[++top] = end;
        }
        if (start < j)
        {
            stack[++top] = start;
            stack[++top] = j;
        }
    }
}

int main()
{   cout << endl;
    cout <<  "          "<<"Recursive Quicksort" << endl << endl ;
    int sizes[] = {500, 1000, 1500, 2000, 2500};
    int repetitions = 5;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000); 

    for (int size : sizes)
    {
        vector<long long> time_taken(repetitions);
        long long total_time = 0;

        for (int rep = 0; rep < repetitions; rep++)
        {
            int arr[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = dis(gen); 
            }

            auto start_time = chrono::steady_clock::now();
            quickSortRecursive(arr, 0, size - 1);
            auto end_time = chrono::steady_clock::now();
            long long current_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
            time_taken[rep] = current_time;
            total_time += current_time;
        }

        cout << setw(4) << size << " : ";
        for (int rep = 0; rep < repetitions; rep++)
        {
            cout << setw(10) << time_taken[rep];
            if (rep < repetitions - 1)
                cout << " | ";
        }
        cout << " |   Average time: " << total_time / repetitions << " ns" << endl;
    }

    cout << "" << endl << endl << endl;

    cout << "           "<<"Iterative Quicksort" << endl << endl ;
    for (int size : sizes)
    {
        vector<long long> time_taken(repetitions);
        long long total_time = 0;

        for (int rep = 0; rep < repetitions; rep++)
        {
            int arr[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = dis(gen); 
            }

            auto start_time = chrono::steady_clock::now();
            quickSortIterative(arr, 0, size - 1);
            auto end_time = chrono::steady_clock::now();
            long long current_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
            time_taken[rep] = current_time;
            total_time += current_time;
        }

        cout << setw(4) << size << " : ";
        for (int rep = 0; rep < repetitions; rep++)
        {
            cout << setw(10) << time_taken[rep];
            if (rep < repetitions - 1)
                cout << " | ";
        }
        cout << " |   Average time: " << total_time / repetitions << " ns" << endl;
    }

    cout << "" << endl << endl << endl;
    return 0;
}
