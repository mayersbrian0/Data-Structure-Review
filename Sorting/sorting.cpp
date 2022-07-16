#include <iostream>
#include <vector>

//swap two values
void swap(int& n1, int& n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}



/* SELECTION SORT */
//O(n^2) time 
//O(1) space
void selectionsort(std::vector<int>& nums) {
    int i = 0, j = 0;
    int min_idx = 0;

    for (i = 0; i < nums.size(); i++) {
        min_idx = i;
        for (j = i; j < nums.size();j++) {
            if (nums[j] < nums[min_idx]) {
                min_idx = j;
            }
        }
        swap(nums[min_idx], nums[i]);
    }
}

/* BUBBLE SORT */
//O(n^2) time
//O(1) space
void bubblesort(std::vector<int>& nums) {
    int i = 0, j = 0;
    
    for (i = nums.size() -1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
            }  
        }
    }
    
}


/* INSERTION SORT*/
//O(n^2) worst case
//O(1) space
//Notice it only loop backwards if it needs to
void insertionsort(std::vector<int>& nums) {
    int i = 0;
    int hole_idx = 0; //index on the left side we need to find
    int temp = 0; //used to store the value were finding a place for

    for (i = 1; i < nums.size(); i++) {
        hole_idx = i;
        temp = nums[hole_idx];
        //condition where we find the index to swap
        while (hole_idx > 0 && nums[hole_idx-1] > temp) {
            nums[hole_idx] = nums[hole_idx-1];
            hole_idx--;
        }
        if (hole_idx != i) nums[hole_idx] = temp;
    }
}


/* MERGE SORT */
void merge(std::vector<int>& nums, int left, int middle, int right) {
    if (left >= right) return;
    int N = right - left + 1;
    //i for left array, j for right array, k for combined array
    int i = left, j = middle+1, k = 0, g = 0;
    std::vector<int> new_vec(N,0);

    while (i <= middle && j <= right) {
        new_vec[k++] = (nums[i] > nums[j]) ? nums[j++] : nums[i++];
    }

    while (i <= middle) new_vec[k++] = nums[i++];
    while (j <= right) new_vec[k++] = nums[j++];

    //copy elements over
    for (g = 0; g < k; g++) {
        nums[g+left] = new_vec[g];
    }
}

//O(nlog(n)) time
void mergesort(std::vector<int>&nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left)/2;
    mergesort(nums, left, mid);
    mergesort(nums, mid+1, right);
    merge(nums, left, mid, right);

}


/* QUICK SORT */
int partiton(std::vector<int>& nums,int pivot, int left, int right) {

    return 0;
}

void quicksort(std::vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int pivot = partiton(nums, left, right);
    quicksort(nums, left, pivot-1);
    quicksort(nums, pivot+1, right);
}


int main() {

    std::vector<int> vec = {5,4,3,2,1};

    mergesort(vec, 0, vec.size() -1);

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}