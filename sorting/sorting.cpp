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
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}