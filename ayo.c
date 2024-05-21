#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node untuk Circular Doubly Linked List
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Fungsi untuk menambahkan node ke akhir list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

// Fungsi untuk mencetak list (memory address & data)
void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%p: %d\n", temp, temp->data);
        temp = temp->next;
    } while (temp != head);
}

// Fungsi untuk mengurutkan node pada Circular Doubly Linked List
void sortList(Node** head) {
    if (*head == NULL || (*head)->next == *head) return;
    Node *curr, *index;
    int temp;
    for (curr = *head; curr->next != *head; curr = curr->next) {
        for (index = curr->next; index != *head; index = index->next) {
            if (curr->data > index->data) {
                // Swap data antara curr dan index
                temp = curr->data;
                curr->data = index->data;
                index->data = temp;
            }
        }
    }
}

int main() {
    int N, data;
    Node* head = NULL;

    printf("Masukkan jumlah data: ");
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        printf("Masukkan data ke-%d: ", i + 1);
        scanf("%d", &data);
        append(&head, data);
    }

    printf("\nList sebelum pengurutan:\n");
    printList(head);

    sortList(&head);

    printf("\nList setelah pengurutan:\n");
    printList(head);

    return 0;
}
