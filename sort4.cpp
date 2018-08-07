
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

void shift_down(int heap[], int node, int len){
    if(node*2 >= len || len == 1){
        return;
    }
    
    //もし右子がないなら
    if(node*2+2 == len){
        if(heap[node] > heap[node*2+1]){
            swap_value(heap, node, node*2+1);
        }
    }else if(heap[node] > heap[node*2+1] || heap[node] > heap[node*2+2]){
        //右子があるなら左子もあるのでどっちか小さい方と交換
        if(heap[node*2+1] < heap[node*2+2]){
            swap_value(heap, node, node*2+1);
            node = node*2+1;
            shift_down(heap, node, len);
        }else{
            swap_value(heap, node, node*2+2);
            node = node*2+2;
            shift_down(heap, node, len);
        }
    }
}

void min_heap(int list[], int len, int heap[]){
    for(int i=0; i<len; i++){
        heap[i] = list[i];
    }
    
    int cnt = 0;
    int lmt = len;
    
    while(cnt != lmt){
        int node = (len-2) / 2;
        
        while(node != -1){
            shift_down(heap, node, len);
            node--;
        }
        
        cout << "step" << cnt << ":";
        display_list(heap, len);
        
        list[cnt] = heap[0];
        swap_value(heap, 0, len-1);
        cnt++;
        len--;
    }
}

int main(int argc, const char * argv[]) {
    int list[9] = {19,9,13,15,16,11,29,35,20};
    int len = sizeof(list) / 4;
    int heap[len];
    
    cout << "input:";
    display_list(list, len);
    
    min_heap(list, len, heap);
    
    cout << "result:";
    display_list(list, len);
    
    return 0;
}

