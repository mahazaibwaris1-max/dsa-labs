#include <iostream>
#include <string>
using namespace std;

struct Customer { string name, transaction; };

template <typename T>
class Queue {
protected:
    T* arr; int maxSize, currentSize, front, rear;
public:
    Queue(int s) { maxSize = s; arr = new T[s]; currentSize = 0; front = 0; rear = -1; }
    virtual ~Queue() { delete[] arr; }
    virtual void enqueue(T) = 0;
    virtual T dequeue() = 0;
    virtual T peek() = 0;
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
};

template <typename T>
class MyQueue : public Queue<T> {
public:
    MyQueue(int s) : Queue<T>(s) {}
    void enqueue(T d) override {
        if (isFull()) { cout << "[OVERFLOW] Queue full!\n"; return; }
        this->rear = (this->rear + 1) % this->maxSize;
        this->arr[this->rear] = d;
        this->currentSize++;
    }
    

int main() {
    int n; cout << "Capacity: "; cin >> n; cin.ignore();
    MyQueue<Customer> q(n);
    int c;
    do {
        cout << "\n1.Add 2.Serve 3.Display 4.Total 5.Exit\nChoice: ";
        cin >> c; cin.ignore();
        if (c == 1) {
            Customer x;
            cout << "Name: "; getline(cin, x.name);
            cout << "Transaction: "; getline(cin, x.transaction);
            q.enqueue(x);
        }
     