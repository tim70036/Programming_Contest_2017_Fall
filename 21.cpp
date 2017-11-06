#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Heap
{
public:
    Heap() { back = 1; }
    
    void push(int v)
    {
        data[back++] = v;
        
        /* Bubble up */
        int index = back-1;
        int parent = index / 2;
        while(parent >= 1 && data[parent] > data[index])
        {
            swap(data[parent], data[index]);
            index = parent;
            parent = index / 2;
        }
    }
    
    void pop()
    {
        data[1] = data[--back];
        
        /* Bubble down */
        int index = 1;
        while(1)
        {
            int smallest = index;
            /* left child */
            smallest = (index*2 >= back || data[index*2] > data[smallest]) ? smallest : index*2;
            /* right child */
            smallest = (index*2+1 >= back || data[index*2+1] > data[smallest]) ? smallest : index*2+1;
            
            if(data[smallest] == data[index])	break;
            swap(data[smallest], data[index]);
            index = smallest;
        }
    }
    
    bool empty() { return (back <= 1) ? true:false ; }
    int top()	{ return data[1]; }
    
private:
    int data[300005];
    int back;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Heap heap;
    int n; cin >> n;
    while(n--)
    {
        string in; cin >> in;
        if(in == "push")
        {
            int v; cin >> v;
            heap.push(v);
        }
        else if(in == "pop")
        {
            if(!heap.empty())	heap.pop();
            else	cout << "pop empty!\n";
        }
        else if(in == "top")
        {
            if(!heap.empty())	cout << heap.top() << "\n";
            else	cout << "top empty!\n";
        }
    }
}