// 93. Write a program to implement Merge Sort using Array.

void merge(int array[], int low, int mid, int high) {
    int brray[high-low+1], h=low, i=low, j=mid+1, k;

    while(h<=mid && j<=high) {
        if(array[h] <= array[j]) {
            brray[i] = array[h];
            h++;
        }
        else {
            brray[i] = array[j];
            j++;
        }
        i++;
    }

    if(h>mid) {
        for(k=j; k<=high; k++) {
            brray[i] = array[k];
            i++;
        } 
    }
    else {
        for(k=h; k<=mid; k++) {
            brray[i] = array[k];
            i++;
        }
    }

    for(k=low; k<=high; k++) 
        array[k] = brray[k];
}

//                              0        size-1
void mergeSort(int array[], int low, int high) {
    int mid = (low + high) / 2;

    mergeSort(array, low, mid);    
    mergeSort(array, mid+1, high);
    merge(array, low, mid, high);
}

int main() {
    return 0;
}