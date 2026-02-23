#include <iostream>
using namespace std;

void bubble_sort(int arr[],int n){
    int swapped=1;
    while(swapped){
        swapped=0;
        for(int i=0;i<n-1;i++){
                if(arr[i]>arr[i+1]){
                    int temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                    swapped=1;
                }
        }
    }

}

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        if(min_index!=i){
            int temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
        }
    }
}
 
void merge(int arr[],int left,int mid,int right){
    int i,j,k=left;
    int n1=mid-left+1;
    int n2=right-mid;

    int l[n1];
    int r[n2];

    for(i=0;i<n1;i++){
        l[i]=arr[left+i];
    }

    for(j=0;j<n2;j++){
        r[j]=arr[mid+1+j];
    }

    i=0;j=0;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            k++;
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }


}

void merge_sort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int partition(int arr[],int left,int right){
    int pivot=arr[left];
    int i=left+1;
    int j=right;
    while(1){
        while(i<=right && arr[i]<=pivot){
            i=i+1;
        }
        while(j>=left && arr[j]>pivot){
            j=j-1;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }else{
            break;
        }
    }
    int temp=arr[left];
    arr[left]=arr[j];
    arr[j]=temp;
    return j;
}


void quick_sort(int arr[],int left,int right){
    if(left<right){
        int pivotindex=partition(arr,left,right);
        quick_sort(arr,left,pivotindex-1);
        quick_sort(arr,pivotindex+1,right);
    }
     
}



int main(){
    int arr[7]={2,9,6,8,3,5,0};
    int n=7;
    int c;
    cout <<"enter c"<<endl;
    cin>>c;
    switch(c){
        case 1: bubble_sort(arr,n);
                break;
        case 2: insertion_sort(arr,n);
                break;
        case 3: selection_sort(arr,n);
                break;
        case 4: merge_sort(arr,0,n-1);
                break;
        case 5: quick_sort(arr,0,n-1);
                break;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}