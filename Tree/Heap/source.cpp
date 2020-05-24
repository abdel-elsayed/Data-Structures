#include <iostream>
#include "algo.h"
#include "heap.h"
#include <vector>

using namespace std;
   
int main()
{
    vector<int> arr = {1,8,2,3,67,78,5};

    int n = arr.size();
        
    //create a MaxHeap out of the array
    cout << "Max heap:";
    buildMaxHeap(arr, n);

    //print the MaxHeap array
    printHeap(arr, n);
    cout << endl;

    //delete the root element in the MaxHeap
    cout << "After deletion: "; 
    deleteMax(arr, n);
    printHeap(arr, n);
    cout << endl;

    //inserting a value of 90 into the MaxHeap
    int x = 90;
    insertMax(arr,x, n);
    cout << "After insertion: "<<x;
    printHeap(arr, n);


    cout << "---------------------------------------------\n\n";

    //reinitializing the array
    arr = { 1,8,2,3,67,78,5 };

    // creating a MinHeap out of the array
    cout << "Min heap:";
    buildMinHeap(arr, n);
    // print the MinHeap array
    printHeap(arr, n);
    cout << endl;

    // delete the root element in the MinHeap
    cout << "After deletion: ";
    deleteMin(arr, n);
    printHeap(arr, n);
    cout << endl;

    //inserting a value of 90 in the MinHeap
    insertMin(arr,x, n);
    cout << "After insertion: "<< x;
    printHeap(arr, n);

    return 0;
    }
