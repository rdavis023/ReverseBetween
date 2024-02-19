#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }
    
        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }
    
        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }
    
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
    
void reverseBetween(int m, int n) {
    // Edge case: no need to reverse if m equals n
    if (m == n) return;

    Node* dummy = new Node(0); // Create a dummy node to simplify the head handling
    dummy->next = head;
    Node* prevM = dummy; // To store the node just before the start of the reversal segment

    // Traverse to the node just before the start of the segment to reverse
    for (int i = 0; i < m - 1; i++) {
        prevM = prevM->next;
    }

    // 'start' will eventually point to the first node of the segment to reverse
    Node* start = prevM->next;
    Node* then = start->next; // The node that will be moved around

    // Perform the reversal between m and n
    for (int i = 0; i < n - m; i++) {
        start->next = then->next; // Link the start node to the node after 'then'
        then->next = prevM->next; // Move 'then' node to the front of the segment
        prevM->next = then; // Connect the 'prevM' node to the 'then' node, now at the front
        then = start->next; // Move 'then' to the next node to be processed
    }

    // If m was 1, update the head to reflect the new start of the list
    head = dummy->next;

    // Clean up the dummy node
    delete dummy;
}

};
