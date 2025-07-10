# Approach
We use a min-heap of size k to store the k largest elements in the stream. The smallest among these k elements (i.e., the top of the min-heap) will be the k-th largest overall.
Steps:
-Initialize a min-heap with the first k elements of the stream.
-If fewer than k elements are available, add the current element to the heap.
-For each new element:
-If it's larger than the smallest in the heap (heap top), remove the smallest and insert the new element.
-Otherwise, ignore it.
-At any point, the heap top is the k-th largest element.


  
  # Code
```cpp []
class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> minH;
int size;
    KthLargest(int k, vector<int>& nums) {
      size = k;
      for(int num : nums){
        add(num);
      }  
    }
    
    int add(int val) {
        if( minH.size() < size){
            minH.push(val);
        } else if(val > minH.top()){
            minH.pop();
            minH.push(val);
        }
        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
