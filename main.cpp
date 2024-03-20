#include <iostream>
#include <cassert>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool removeNode(int data) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                delete temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Example Unit Test for DoublyLinkedList
void testDoublyLinkedList() {
    DoublyLinkedList list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    assert(list.head->data == 1);
    assert(list.tail->data == 3);

    list.removeNode(2);

    assert(list.head->next->data == 3);
    assert(list.tail->prev->data == 1);

    std::cout << "All tests passed." << std::endl;
}

int main() {
    testDoublyLinkedList();
    return 0;
}
