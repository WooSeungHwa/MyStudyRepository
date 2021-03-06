//자료구조 Heap
#include<iostream>
#include<queue>
#include<vector>
using namespace std;


//직접 구현
class MyHeap {
public:
    MyHeap() {
        length = 0;
        heapList = new int[100];
    }
    MyHeap(int n) {
        length = 0;
        heapList = new int[n];
    }
    //힙에 필요한것이 무엇인가? what is nessary to Heap?
    void push(int n) {
        heapList[++length] = n;

        for (int i = length; i > 1; i /= 2) {
            if (compare(heapList[i], heapList[i / 2])) {
                int temp = heapList[i / 2];
                heapList[i / 2] = heapList[i];
                heapList[i] = temp;
            }
        }


    }

    void pop() {
        if (length < 1)
            return;
        
        int temp = heapList[length];
        heapList[1] = temp;
        length -= 1;

        int i = 1;
        while (i <= length)
        {

            if (compare(heapList[i * 2], heapList[i]) || compare(heapList[i * 2 + 1], heapList[i])) {
                if (compare(heapList[i * 2 + 1], heapList[i * 2])) {
                    int temp = heapList[i * 2 + 1];
                    heapList[i * 2] = heapList[i];
                    heapList[i] = temp;
                    i = i * 2 + 1;
                }
                else {
                    int temp = heapList[i * 2];
                    heapList[i * 2] = heapList[i];
                    heapList[i] = temp;
                    i *= 2;
                }
            }
            else {
                break;
            }
        }
    }

    const int top() {
        if (length >= 1) {
            return heapList[1];
        }
    }

    bool compare(const int a, const int b) { //a가 b보다 ~할때 true
        if (a <= b) {
            return true;
        }
        return false;
    }

private:
    int length;
    int* heapList;
};




int main() {
    //힙 구현
    MyHeap heap;

    heap.push(5);
    heap.push(3);
    heap.push(10);
    heap.push(7);
    heap.push(1);
    heap.pop();
    cout << heap.top() << endl;

    // STL
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(5);
    q.push(3);
    q.push(10);
    q.push(7);
    q.push(1);
    q.pop();
    cout << q.size() << endl;
    cout << q.empty() << endl;
    cout << q.top() << endl;

}