#include "threaded_merge.hpp"

int main() {
  int max_threads;
  long int array_size;
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

  auto start = std::chrono::high_resolution_clock::now();
  mergeSort(arr, array_size, max_threads);
  auto stop = std::chrono::high_resolution_clock::now();
  
  auto runtime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  std::cout << "Execution time: " << runtime.count() << " microseconds" << std::endl; 

  //Delete the allocated array and exit
  delete[] arr;
  return 0;
}