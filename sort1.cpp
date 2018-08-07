#include <iostream>

using namespace std;

void display_list(int list[], int len){
    for(int i=0;i<len;i++){
        cout << list[i];
    }
    cout << "\n";
}

void selection_sort(int list[], int len){
    int tmp;
    int min_index;
    
    cout << "Input:";
    display_list(list, len);
    
    for(int start=0;start<len;start++){
        min_index = start;
        for(int i=start+1;i<len;i++){
            if(list[min_index] > list[i]){
                min_index = i;
            }
        }
        tmp = list[start];
        list[start] = list[min_index];
        list[min_index] = tmp;
        
        cout << "step" << start+1 << ":";
        display_list(list, len);
    }
}

void insert_sort(int list[], int len){
    int tmp;
    int i;
    
    cout << "Input:";
    display_list(list, len);
    
    for(int start=1;start<len;start++){
        tmp = list[start];
        
        //shift
        for(i=start; i>0 && list[i-1]>tmp; i--){
            list[i] = list[i-1];
        }
        
        //insert
        list[i] = tmp;
        
        cout << "step" << start << ":";
        display_list(list, len);
    }
}

void bubble_sort(int list[], int len){
    int tmp;
    int flag;
    
    cout << "Input:";
    display_list(list, len);
    
    for(int end=len; end>0; end--){
        flag = 0;
        
        for(int i=0; i<end; i++){
            if(list[i] > list[i+1]){
                tmp = list[i+1];
                list[i+1] = list[i];
                list[i] = tmp;
                flag = 1;
            }
        }
        cout << "step" << len-end+1 << ":";
        display_list(list, len);
        
        if(flag == 0){
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    int list[9] = {6,5,4,7,2,3,1,8,9};
    
    //selection_sort(list, (sizeof(list) / 4));
    //insert_sort(list, sizeof(list) / 4);
    bubble_sort(list, sizeof(list) / 4);
    
    return 0;
}
