#include <iostream>
using namespace std;

struct Node { int customerNum; Node* next; };

Node* front = NULL;
Node* rear  = NULL;
int count = 1;

void enqueue() {
    Node* n = new Node();

    n->customerNum  = count++;
    n->next = NULL;
    if (rear == NULL) front = rear = n;
    else { rear->next = n; rear = n; }
    cout << "Customer #" << n->customerNum << " Added\n";
}

void dequeue() {
    if (front == NULL) { cout << "No Customers!\n"; return; }
    cout << "Now Serving Customer #" << front->customerNum << "\n";
    Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete temp;
}

void peek() {
    if (front == NULL) { cout << "No Customers!\n"; return; }
    cout << "Next Customer: #" << front->customerNum << "\n";
}


int main() {
    int choice;
    do {
        cout << "\n== BARBER SHOP ==\n1.Add  2.Serve  3.Next  4.Exit\nChoose: ";
        cin >> choice;
        if      (choice == 1) enqueue();
        else if (choice == 2) dequeue();
        else if (choice == 3) peek();
        else if (choice == 4) cout << "Goodbye!\n";
        else                  cout << "Invalid!\n";
    } while (choice != 4);
    return 0;
}
