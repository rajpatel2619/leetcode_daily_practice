class Solution {
public:
    vector<int> bubbleSort(vector<int>&nums, int n){
        for(int i=0;i<n-1;i++){ // passes
            bool swapped = false;
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
            if(!swapped) break;
        }
        return nums;
    }

    vector<int> selectionSort(vector<int> &nums, int n){
        for(int i=0;i<n-1;i++){
            int min  = nums[i];
            int mInd = i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<min){
                    min = nums[j];
                    mInd = j;
                }
            }
            swap(nums[mInd], nums[i]);
        }
        return nums;
    }

    vector<int> insertionSort(vector<int> &nums, int n){
        for(int i=1;i<n;i++){
            int key = nums[i];
            int j = i-1;
            while(j>=0 && nums[j]>key){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }
        return nums;
    }

    void merge(vector<int>& nums, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right-mid;
        vector<int> larr(n1), rarr(n2);
        for(int i=0;i<n1;i++) larr[i] = nums[left+i];
        for(int i=0;i<n2;i++) rarr[i] = nums[mid+1+i]; 

        int i=0, j =0, k=left;
        while(i<n1 && j<n2){
            nums[k++] = (larr[i]<=rarr[j])?larr[i++]:rarr[j++];
        }
        while(i<n1) nums[k++] = larr[i++];
        while(j<n2) nums[k++] = rarr[j++];
    }
    void mergeSort(vector<int>&nums, int left, int right){
        if(left>=right) return;
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    int partition(vector<int> &nums, int left, int right){
        int p = nums[right];
        int i = left-1;
        for(int j=left;j<right;j++){
            if(nums[j]<p){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[right]);
        return i+1;
    }
    void quickSort(vector<int>&nums, int left, int right){
        if(left>=right) return;
        int pi = partition(nums, left, right);
        quickSort(nums, left, pi-1);
        quickSort(nums, pi+1, right);
    }
    
    void heapify(vector<int>&nums, int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<n and nums[left]>nums[largest])
            largest = left;
        if(right<n and nums[right]>nums[largest])
            largest = right;
        if(largest!=i){
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
    void heapSort(vector<int> &nums){
        int n = nums.size();
        for(int i=n/2-1;i>=0;i--)
            heapify(nums, n, i);
        
        for(int i=n-1;i>=0;i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // return insertionSort(nums, n);
        heapSort(nums);
        return nums;
    }
};