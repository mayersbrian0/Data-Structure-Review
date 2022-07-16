#ifndef MY_HEAP
#define MY_HEAP
#include <vector>

//only handle ints
class Heap {
    private:

    std::vector<int> queue;
    int size;

    //delete an element
    void heapify(std::vector<int>& arr,int n, int index);
    //insert an element
    void sift_up(int value);
    void sift_down(int index);

    public:

    Heap();
    void insert(int value);
    int get_max();
    int get_size();
    bool is_empty();
    int extract_max();
    void print_heap();

    //sort an array using a heap
    void heap_sort(std::vector<int>& arr);
};



#endif