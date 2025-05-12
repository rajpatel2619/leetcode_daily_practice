class Solution {
    public void mergeSort(int[] arr, int left, int right){
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1, right);
            // merge sorted array
            merge(arr, left, mid, right);
        }
    }
    public void merge(int[] arr, int left, int mid, int right){
        int m = mid - left +1;
        int n = right - mid;

        int arrm[] = new int[m];
        int arrn[] = new int[n];

        // copy values in temp arrays;
        for(int i=0;i<m;i++){
            arrm[i] = arr[left+i];
        }
        for(int i=0;i<n;i++){
            arrn[i] = arr[mid+1+i];
        }

        int i=0, j=0, k=left;
        while(i<m && j<n){
            if(arrm[i]<=arrn[j]){
                arr[k++] = arrm[i++];
            }else{
                arr[k++] = arrn[j++];
            }
        }

        //copy remaining
        while(i<m){
            arr[k++] = arrm[i++];
        }
        while(j<n){
            arr[k++] = arrn[j++];
        }
    }

    public int[] sortArray(int[] nums) {
        int n = nums.length;
        if(n==1) return nums;
        mergeSort(nums, 0, n-1);
        return nums;
    }
}