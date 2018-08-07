#include <iostream>

using namespace std;

int cnt = 1;

void display_list(int list[], int len){
    for(int i=0;i<len;i++){
        cout << list[i] << " ";
    }
    cout << "\n";
}

//結合パート
void merge(int list[], int left, int middle, int right, int len){
    int i = left;
    int j = middle+1;
    int k = right;
    
    int* tmp_list = (int *)malloc(sizeof(int) * (left+1));
    for(int x=0; x<k+1; x++){
        tmp_list[x] = list[x];
    }
    
    for(int x=left; x<right+1; x++){
        if((tmp_list[i] < tmp_list[j] || j > k) && (i <= middle)){
            list[x] = tmp_list[i];
            i++;
        }else if(tmp_list[i] > tmp_list[j] || i > j){
            list[x] = tmp_list[j];
            j++;
        }
    }
}

void merge_sort(int list[], int left, int right, int len){
    int middle = (left + right) / 2;

    if((right - left) == 0){
        return;
    }
    
    merge_sort(list, left, middle, len);
    merge_sort(list, middle+1, right, len);
    merge(list, left, middle, right, len);
    
    cout << "step" << cnt <<":";
    display_list(list, len);
    cnt++;
}

int main(int argc, const char * argv[]) {
    int list[9] = {6,5,7,0,3,1,8,2,4};
    
    cout << "input:";
    display_list(list, sizeof(list) / 4);
    
    merge_sort(list, 0, (sizeof(list) / 4) - 1, (sizeof(list) / 4));
    
    return 0;
}

