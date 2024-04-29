#include "threaded_merge.hpp"

int main() {
  int max_threads, num_runs;
  long int array_size, total_time = 0, avg_time;
  std::cout << "Input max threads" << std::endl;
  std::cin >> max_threads;
  std::cout << "Enter array size to sort" << std::endl;
  std::cin >> array_size;
  std::cout << "Number of test sorts to average" << std::endl;
  std::cin >> num_runs;

  int* arr = new int[array_size];
  for(int i=0; i < num_runs; i++ ) {
    //init random number generator and array
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    

    //Fill an array of the given size with random numbers
    for(int i=0; i<array_size; i++) {
      arr[i] = rand() % array_size;
    }

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, array_size, max_threads);
    auto stop = std::chrono::high_resolution_clock::now();
    
    long int runtime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    total_time += runtime;
    
  }
  avg_time = total_time / num_runs;

  std::cout << "Averge execution time: " << avg_time << " milliseconds" << std::endl; 

  //Delete array and exit
  delete[] arr;
  return 0;
}