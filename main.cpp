// MAX HEAPIFY IMPLEMENTATION

// PSEUDOCODE: 

#include <array>
#include <cstddef> // size_t
#include <iostream>


using namespace std;

void PrintArray(const array<int, 10>& arr){
    size_t size = arr.size();
    cout << '{' << arr.at(0);
    for(size_t i = 1; i!= size; ++i){
        cout << ", " << arr.at(i);
    }
    cout << '}' << endl;
}

void max_heapify(array<int, 10>& nums){
    
}

int main() {
    array<int, 10> nums = {5, 3, 2, 15, 0, -5, 12, 0, 0, 200};
    
    cout << "Before: ";
    PrintArray(nums);

    max_heapify(nums);
    cout << "After : ";
    PrintArray(nums);

    return 0;
}