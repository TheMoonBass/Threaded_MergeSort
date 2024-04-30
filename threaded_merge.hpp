#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <random>

//Authored by TheMoonBass
//Threaded MergeSort, working as intended
//Note: Runs slower for the first run after being built in VSCode

//Globals for thread management
int maxThreads = 0;
int currNumThreads = 0;

//Function declarations
void mergeSortAUX(int arr[], int size);
void merge(int arrA[], int sizeA, int arrB[], int sizeB, int arrC[], int sizeC, int num_threads);
void mergeSort(int arr[], int size, int numThreads);

//Function definitions below
void merge(int arrA[], int sizeA, int arrB[], int sizeB, int arrC[], int sizeC) {
  int ia = 0, ib = 0, ic = 0;
  
  //Merge the arrays into arrC (which should be the main array)
  for (ic; ic < sizeC; ic++) {
    if ((arrA[ia] < arrB[ib]) && ia < sizeA) {
      arrC[ic] = arrA[ia];
      ia++;
    }
    else if ((arrB[ib] <= arrA[ia]) && ib < sizeB) {
      arrC[ic] = arrB[ib];
      ib++;
    }
    else {
      //should only execute if in danger of walking off the array
      if ((ia == sizeA) && (ib != sizeB)) {
        arrC[ic] = arrB[ib];
        ib++;
      }
      else if ((ib == sizeB) && (ia != sizeA)) {
        arrC[ic] = arrA[ia];
        ia++;
      }
      else {
        std::cout << "Something has gone terribly wrong this should never execute" << std::endl;
        break;
      }
    }
  }

}

void mergeSortAUX(int arr[], int size) {
  int sizeB;
  if (size < 2) {
    return;
  }

  //Calculate size of B
  if ((size%2) == 0) {
    sizeB = size/2;
  }
  else {
    sizeB = (size/2)+1;
  }

  //Intitialize arrays for the two halves
  int* arrA = new int[size/2];
  int* arrB = new int[sizeB];

  //Fill the two halves with the correct values
  for (int i=0; i<size/2; i++) {
    arrA[i] = arr[i];
  }
  int k = (size/2);
  for (int i = 0; i<sizeB; i++) {
    arrB[i] = arr[k];
    k++;
  }

  //Recursively sort and merge the arrays, have a new thread handle the right side of the array.
  if(currNumThreads < maxThreads) {
    currNumThreads += 1;
    std::thread thread(mergeSortAUX, arrB, sizeB);
    mergeSortAUX(arrA, size/2);
    thread.join();
    currNumThreads -= 1;
    merge(arrA, size/2, arrB, sizeB, arr, size);
  }
  else {
    mergeSortAUX(arrA, size/2);
    mergeSortAUX(arrB, sizeB);
    merge(arrA, size/2, arrB, sizeB, arr, size);
  }

  delete[] arrA;
  delete[] arrB;
  return;
}

void mergeSort(int arr[], int size, int numThreads) {
  maxThreads = numThreads;
  mergeSortAUX(arr, size);
}