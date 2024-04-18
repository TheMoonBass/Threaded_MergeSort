#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <random>

//Function declarations
void merge(int arrA[], int sizeA, int arrB[], int sizeB, int arrC[], int sizeC);
void mergeSort(int arr[], int size);

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

void mergeSort(int arr[], int size) {
  int sizeB;
  if (size < 2) {
    return;
  }
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
  

  //Recursively sort and merge the arrays
  mergeSort(arrA, size/2);
  mergeSort(arrB, sizeB);
  merge(arrA, size/2, arrB, sizeB, arr, size);

  return;

}