#include "threaded_merge.hpp"

int main() {
  int max_threads, array_size;
  std::cout << "Input max threads" << std::endl;
  std::cin >> max_threads;
  std::cout << "Enter array size to sort" << std::endl;
  std::cin >> array_size;

  //init random number generator and array
  unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
  srand(seed);
  int* arr = new int[array_size];

  //Fill an array of the given size with random numbers
  for(int i=0; i<array_size; i++) {
    arr[i] = rand() % array_size;
  }
  for (int i = 0; i<array_size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "unsorted" << std::endl;

  mergeSort(arr, array_size);

  for (int i = 0; i<array_size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "sorted" << std::endl;

  //Delete the allocated array and exit
  delete[] arr;
  return 0;
}