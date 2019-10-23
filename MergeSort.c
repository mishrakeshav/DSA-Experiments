#include<stdio.h>
#define MAX 100


int merge(int A[], int p, int q, int r);
int mergeSort(int A[], int p, int r);

int main(){
    int a[MAX], i, j, n, flag, swap;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a,0,n-1);

    
    printf("\nSorted array\n");
    for(i=0; i<n; i++){
        printf("%d\n", a[i]);
    }

}
int mergeSort(int A[], int p, int r){
    int q;
    if(p<r){
        q = p + (r-1)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}
int merge(int A[],int p,int q,int r){
    
    int i, j, k;
    int n1 = q-p + 1;
    int n2 = r-q;
    int L[n1],R[n2];
    for(i=0; i<n1; i++){
        L[i] = A[p+i];
    }
    for(i=0; i<n2; i++){
        R[i] = A[q+i+1];
    }
    i=0; j=0, k = p;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k]=L[i];
        k++;
        i++;

    }
    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }

}
