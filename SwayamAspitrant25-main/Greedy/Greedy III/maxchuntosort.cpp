#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxChunksToSorted(std::vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        std::vector<long long> suffix_min(n);
        
        suffix_min[n - 1] = arr[n - 1]; 
        
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = std::min((long long)arr[i], suffix_min[i + 1]);
        }
        
        int chunk_count = 1;
        long long current_max = -1;
        
        for (int i = 0; i < n - 1; ++i) {
            current_max = std::max(current_max, (long long)arr[i]);
            
            if (current_max <= suffix_min[i + 1]) {
                chunk_count++;
            }
        }
        
        return chunk_count;
    }
};

int main() {
    Solution s;
    
    // Example 1: Should result in 1 chunk
    std::vector<int> arr1 = {5, 4, 3, 2, 1};
    std::cout << "Input: [5, 4, 3, 2, 1] | Chunks: " << s.maxChunksToSorted(arr1) << std::endl; 

    // Example 2: Should result in 4 chunks
    std::vector<int> arr2 = {2, 1, 3, 4, 4};
    std::cout << "Input: [2, 1, 3, 4, 4] | Chunks: " << s.maxChunksToSorted(arr2) << std::endl; 
    
    // Example 3: Should result in 2 chunks ([1, 2], [0, 3, 4])
    std::vector<int> arr3 = {1, 2, 0, 3, 4};
    std::cout << "Input: [1, 2, 0, 3, 4] | Chunks: " << s.maxChunksToSorted(arr3) << std::endl; 

    // Example 4: Should result in 1 chunk
    std::vector<int> arr4 = {1, 1, 0, 0, 1};
    std::cout << "Input: [1, 1, 0, 0, 1] | Chunks: " << s.maxChunksToSorted(arr4) << std::endl;

    return 0;
}