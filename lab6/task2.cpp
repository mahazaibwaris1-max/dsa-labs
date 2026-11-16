#include <iostream>
#include <string>
using namespace std;

struct PrintJob { int jobID, pages; string userName; };

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
    T dequeue() override {
        if (isEmpty()) { cout << "[UNDERFLOW] Queue empty!\n"; return T(); }
        T d = this->arr[this->front];
        this->front = (this->front + 1) % this->maxSize;
        this->currentSize--;
        return d;
    }
    T peek() override {
        if (isEmpty()) { cout << "[UNDERFLOW] Queue empty!\n"; return T(); }
        return this->arr[this->front];
    }
    bool isFull() override { return this->currentSize == this->maxSize; }
    bool isEmpty() override { return this->currentSize == 0; }
    int size() { return this->currentSize; }
    void display() {
        if (isEmpty()) { cout << "No jobs.\n"; return; }
        int i = this->front;
        for (int k = 0; k < this->currentSize; k++) {
            cout << "Job:" << this->arr[i].jobID << " " << this->arr[i].userName
                << " Pages:" << this->arr[i].pages << endl;
            i = (i + 1) % this->maxSize;
        }
    }
};

int main() {
    int n; cout << "Capacity: "; cin >> n; cin.ignore();
    MyQueue<PrintJob> q(n);
    int c;
    do {
        cout << "\n1.Submit 2.Process 3.Next 4.Display 5.Total 6.Exit\nChoice: ";
        cin >> c; cin.ignore();
        if (c == 1) {
            PrintJob p;
            cout << "Job ID: "; cin >> p.jobID; cin.ignore();
            cout << "User: "; getline(cin, p.userName);
            cout << "Pages: "; cin >> p.pages; cin.ignore();
            q.enqueue(p);
        }
        else if (c == 2) {
            if (q.isEmpty()) cout << "[UNDERFLOW] No job to process.\n";
            else { PrintJob p = q.dequeue(); cout << "Processed job " << p.jobID << " by " << p.userName << endl; }
        }
        else if (c == 3) {
            if (q.isEmpty()) cout << "[UNDERFLOW] No jobs.\n";
            else { PrintJob p = q.peek(); cout << "Next job: " << p.jobID << " " << p.userName << endl; }
        }
        else if (c == 4) q.display();
        else if (c == 5) cout << "Pending jobs: " << q.size() << endl;
    } while (c != 6);
}