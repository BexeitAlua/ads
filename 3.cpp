#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteEverySecond(Node*& head) {
    if (head == NULL || head->next == NULL) {
        return;  // Not enough elements to delete every second.
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
        current = current->next;  // Move to the next node.
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        insertAtEnd(head, val);
    }

    deleteEverySecond(head);
    printList(head);

    // Clean up memory by deleting the remaining nodes.
    Node* current = head;
    while (current != NULL) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }

    return 0;
}
