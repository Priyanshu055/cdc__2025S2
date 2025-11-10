class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
  int n = arr.size();
        if (n == 0) return 0;

        std::vector<int> min_right(n);
        min_right[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            min_right[i] = min(arr[i], min_right[i + 1]);
        }

        int chunk_count = 0;
        int max_left = numeric_limits<int>::min(); 

        for (int i = 0; i < n; ++i) {
            max_left = max(max_left, arr[i]);
            
            if (i < n - 1) {
                if (max_left <= min_right[i + 1]) {
                    chunk_count++;
                }
            } else {
                chunk_count++;
            }
        }

        return chunk_count;
    }
};