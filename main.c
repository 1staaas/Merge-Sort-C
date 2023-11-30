#include <stdio.h>

void citireArray(int arr[], int n) {
    for(int i=0; i < n; i++) {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
}

void afisareArray(int arr[], int n) {
    for(int i=0; i < n; i++) {
        printf("arr[%d]= %d\n", i, arr[i]);
    }
}

void mergeSort(int arr[], int n);
void mergeRecursion(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);



int main() {
    int arr[100], n;
    printf("Introduceti cate elemente doriti sa contina array-ul: ");
    scanf("%d", &n);
    
    printf("Introduceti elementele in array:\n");
    citireArray(arr, n);
    printf("Elementele in array inainte sa fie sortate:\n");
    afisareArray(arr, n);
    printf("Elementele in array dupa ce au fost sortate:\n");
    mergeSort(arr, n);
    afisareArray(arr, n);
    
}

void mergeSort(int arr[], int n) {
    mergeRecursion(arr, 0, n-1);
 
}

void mergeRecursion(int arr[], int left, int right) {
    if(left < right) {
        
        int mid= left + (right - left) / 2;
    
        mergeRecursion(arr, left, mid);
        mergeRecursion(arr, mid+1, right);
    
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int leftLength= mid - left + 1;
    int rightLength= right - mid;
    
    int tempLeft[leftLength];
    int tempRight[rightLength];
    
    for(int i = 0; i < leftLength; i++) {
        tempLeft[i]= arr[left + i];
    }
    
    for(int i = 0; i < rightLength; i++) {
        tempRight[i]= arr[mid + 1 + i];
    }
    
    int i = 0;
    int j = 0;
    int index = left;

    while (i < leftLength && j < rightLength) {
        if (tempLeft[i] <= tempRight[j]) {
            arr[index] = tempLeft[i];
            i++;
        } else {
            arr[index] = tempRight[j];
            j++;
        }
        index++;
    }

    
    while (i < leftLength) {
        arr[index] = tempLeft[i];
        i++;
        index++;
    }

    while (j < rightLength) {
        arr[index] = tempRight[j];
        j++;
        index++;
    }
}
















