#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class list {
    private:
        node *head;
        node *tail;

    public:
        list() { // Constructor
            head = nullptr;
            tail = nullptr;
        }


        void list_destroy() {
            while (head) {
                node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        void list_print() {
            while (head) {
                node *temp = head;
                head = head->next;
                cout << temp->data << " ";
            }
        }

        void node_create(int data) {
            node *newNode = new node;
            newNode->data = data;
            newNode->next = nullptr;
        }

        void list_append(int data) {
            node *newNode = new node;
            newNode->data = data;
            newNode->next = nullptr;
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

        void list_prepend(int data) {
            node *newNode = new node;
            newNode->data = data;
            newNode->next = nullptr;
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        void list_removeFirst() {
            node *temp = head;
            head = head->next;
            delete temp;
        }

        void list_removeLast() {
            node *temp = head;
            while (temp) {
                if (temp->next == tail) {
                    tail = temp;
                    temp = temp->next;
                    delete temp;
                    tail->next = nullptr;
                }
                temp = temp->next;
            }
        }
};