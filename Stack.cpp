#include<bits/stdc++.h>
using namespace std;

int stk[10], top;

void push(int x){
    ++top;
    stk[top] = x;
}
bool isEmpty(){
    if(top >= 1) return false;
    else return true;
}

void pop(){
    stk[top] = 0;
    top--;
}

int topp(){
    return stk[top];
}
int main(){
    top = 0;
    push(1);
    push(2);
    push(3);
    pop();
    cout << topp() << "\n";
    cout << isEmpty() << "\n";
    for(int i = 0; i < 10; i++){
        cout << stk[i] << " ";
    }
    
    return 0;
}
