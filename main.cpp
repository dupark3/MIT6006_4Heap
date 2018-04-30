// MAX HEAPIFY IMPLEMENTATION

/* PSEUDOCODE: 
           5
       3        2
   -15    0  -5  12
 7  -10 9

for n > 0
(n-1)/2 = parent
2n+1 = left child
2n+2 = right child

*/

#include <array>
#include <climits> // INT_MIN
#include <cstddef> // size_t
#include <iostream>

static const int size = 10;

using namespace std;

void PrintArray(const array<int, size>& arr){
    // Print with approximate tree format
    cout << "             " << arr[0] << endl
         << "         " << arr[1] << "      " << arr[2] << endl
         << "     " << arr[3] << "    " << arr[4] << "   " << arr[5] << "  " << arr[6] << endl
         << "   " << arr[7] << "  " << arr[8] << "   " << arr[9] << endl;
    
    /* Print without format
    cout << '{' << arr[0];
    for(size_t i = 1; i!= size; ++i)
        cout << ", " << arr[i];
    cout << '}' << endl;
    */
}

void swap(array<int, size>& nums, int first_index, int second_index){
    int temp = nums[first_index];
    nums[first_index] = nums[second_index];
    nums[second_index] = temp;
}

void max_heapify(array<int, size>& nums, int n){
    int left_child_index = 2 * n + 1;
    int right_child_index = 2 * n + 2;

    int left_child = INT_MIN;
    int right_child = INT_MIN;

    if (left_child_index < size)
        left_child = nums[left_child_index];
    if (right_child_index < size)
        right_child = nums[right_child_index];

    if (nums[n] < left_child && left_child > right_child){
        swap(nums, n, left_child_index);
        max_heapify(nums, left_child_index);
    }
    if (nums[n] < right_child){
        swap(nums, n, right_child_index);
        max_heapify(nums, right_child_index);
    }
}

void build_max_heap(array<int, size>& nums){
    int n = size;

    // start at the parent of the last element and end at the root
    for(int i = (size - 1) / 2; i >= 0; --i)
        max_heapify(nums, i);
}


int main() {
    array<int, size> nums = {5, 3, 2, -15, 0, -5, 12, 7, 10, 9};
    
    cout << "Before: " << endl;
    PrintArray(nums);

    build_max_heap(nums);

    cout << "After : " << endl;
    PrintArray(nums);

    return 0;
}