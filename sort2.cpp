#include <iostream>

using namespace std;

void display_list(int list[], int len){
    for(int i=0;i<len;i++){
        cout << list[i] << " ";
    }
    cout << "\n";
}

void swap_value(int list[], int index1, int index2){
    int tmp;
    tmp = list[index1];
    list[index1] = list[index2];
    list[index2] = tmp;
}

void quick_sort(int list[], int left, int right, int len){
    int pivot = list[(left + right) / 2];
    
    if(right <= left){
        return;
    }
    
    int i = left;
    int j = right;
    
    while(1){
        while(list[i] < pivot){
            i++;
        }
        while(list[j] > pivot){
            j--;
        }
        if(i >= j){
            break;
        }else{
            swap_value(list, i, j);
            i++;
            j--;
            display_list(list, len);
        }
    }

    quick_sort(list, left, i-1, len);
    quick_sort(list, j+1, right, len);
}

int main(int argc, const char * argv[]) {
    int list[10] = {5,6,2,4,7,0,3,1,8,9};
    
    quick_sort(list, 0, (sizeof(list) / 4) - 1, (sizeof(list) / 4));
    
    return 0;
}
