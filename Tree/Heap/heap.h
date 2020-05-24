#pragma once
#include <iostream>
#include<vector>
using namespace std;

//Swap two elements
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

//Create a max heap using the heapify method
void Maxheapify(vector<int>& arr, int n, int i)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root 
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively Maxheapify the affected sub-tree 
        Maxheapify(arr, n, largest);
    }
}

//Function that call heapify Max to build the Max-heap out of the givern array
void buildMaxHeap(vector<int>& arr, int n)
{
    // Index of last non-leaf node 
    int startIdx = (n / 2) - 1;
    if (startIdx < 0)
        startIdx = 0;

    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i >= 0; i--) {
        Maxheapify(arr, n, i);
    }
}

//Create a MinHeap using the heapify method
void Minheapify(vector<int>& arr, int n, int i)
{
    int smallest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is smaller than root 
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    // If right child is smaller than smaller so far 
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    // If smaller is not root 
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively Minheapify the affected sub-tree 
        Minheapify(arr, n, smallest);
    }
}

// Function that call heapifyMin to build the MinHeap out of the given array
void buildMinHeap(vector<int>& arr, int n)
{
    // Index of last non-leaf node 
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i >= 0; i--) {
        Minheapify(arr, n, i);
    }
}

// insets newItem into the MaxHeap arr of size n,
// and then calls buildMaxHeap Function to sort the array into MaxHeap
void insertMax(vector<int>& arr, int newItem, int& n) // O(n)
{
    n++;
    arr.insert(arr.begin() + (n-2), newItem);
    buildMaxHeap(arr, n); // O(n)
}

// Inserts newItem into the MinHeap arr of size n,
// and then calls buildMinHeap Function to sort the array into MinHeap
void insertMin(vector<int> &arr,int newItem, int &n) // O(n)
{
    n++;
    arr.insert(arr.begin()+(n-2), newItem);
    buildMinHeap(arr, n); // O(n)   
}

//swaps the last element in the arr with the first one, and then shrinks
// the array by one element, then rearranges the array into MinHeap
void deleteMin(vector<int>& arr, int& n)
{
    cout << arr[0];
    swap(arr[0], arr[n-1]);
    n--;
    buildMinHeap(arr, n);

}

//swaps the last element in the arr with the first one, and then shrinks
// the array by one element, then rearranges the array into MaxHeap
void deleteMax(vector<int>& arr, int& n)
{
    cout << arr[0];
    swap(arr[0], arr[n-1]);
    n--;
    buildMaxHeap(arr, n);

}

//Print function of heap in an array format
void printHeap(vector<int> arr, int n)
{
    cout << "\nArray representation of Heap is:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";

}

