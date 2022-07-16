#include <iostream>
#include "myheap.h"

/*
NOTE THE QUEUE IS 1 INDEXED NOT ZERO
*/

void swap(int& a, int& b) {
    int temp = a;
    a =b;
    b = temp;
}

int get_left_child(int i) {
    return 2*i;
}

int get_right_child(int i) {
    return (2*i +1);
}

int get_parent(int i ) {
    return i /2;
}

Heap::Heap() {
    //first element is pushed for easier calcualtions
    queue.push_back(-1);
    size = 0;
}

void Heap::sift_up(int value) {
    queue.push_back(value);
    int parent = get_parent(size);
    int i = size;

    //move the freshly inserted value up
    while (i > 1 && queue[parent] < queue[i]) {
        swap(queue[parent], queue[i]);
        i = parent;
        parent = get_parent(i);
    }
}

void Heap::insert(int value) {
    size++;
    if (size == 0) queue.push_back(value);
    else sift_up(value);
}

int Heap::get_max() {
    return queue[1];
}

int Heap::get_size() {
    return size;
}

bool Heap::is_empty() {
    return size == 0;
}

//Note this is the same as heapify but without the array
void Heap::sift_down(int i) {
    //move the last element to the first position
    int left = get_left_child(i), right = get_right_child(i);
    //store which of the root, or children is the largest
    int largest = i;

    if (left <= size && queue[left] > queue[largest]) largest = left;
    if (right <= size && queue[right] > queue[largest]) largest = right;

    //if we need to move the root
    if (largest != i) {
        swap(queue[i], queue[largest]);
        sift_down(largest);
    }

}

int Heap::extract_max() {
    if (size == 0) {
        std::cout << "Empty Queue" << "\n";
        return -1;
    }

    int max = queue[1];

    if (size == 1) {
        size--;
        return max;
    }

    swap(queue[1], queue[size]);
    size--;
    sift_down(1);   
    return max;
}

void Heap::heapify(std::vector<int>& arr,int n, int i) {
    //index does not start at one
    int left = 2*i + 1, right = 2*i + 2;
    int largest = i;

    if (left < n && arr[largest] < arr[left]) largest = left;
    if (right < n && arr[largest] < arr[right]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    } 
}

void Heap::heap_sort(std::vector<int>& arr) {
    for (int i = arr.size() /2 -1; i >= 0; i--) {
        heapify(arr,arr.size(), i);
    }

    for(int i = arr.size()-1;i >= 0; i--) {
        //"pop the elements"
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

void Heap::print_heap() {
    for (int i = 1; i <= size; i++) {
        std::cout << queue[i] << " ";
    }
    std::cout << "\n";
}



