#include <iostream>
#include "./Heap/myheap.cpp"

int main() {
    Heap heap;


    heap.insert(1);
    heap.insert(2);
    heap.insert(0);
    heap.insert(500);

    int max = heap.extract_max();

    heap.print_heap();
    std::cout << "Max Value: " << max << "\n";
    std::cout << "Size: " << heap.get_size() << "\n";

    std::vector<int> arr = {6,7,8,9,1,2,3,4,10,1};
    heap.heap_sort(arr);


    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}