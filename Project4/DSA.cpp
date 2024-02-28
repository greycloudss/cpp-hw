#include <iostream>
#include <cstdio>
#include <Windows.h>

struct Node {
    void* next;
    int data;
};

Node* head = nullptr;

Node* addNode(int data) {
    Node* newNode = new Node;
    if (head == nullptr) {
        newNode->data = data;
        newNode->next = nullptr;
        head = newNode;
    }
    else {
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    return newNode;
}

int removeNode(int data) {
    Node* current = head;
    Node* prev = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            // if current node is the list head
            if (current == head)
            {
                head = static_cast<Node*>(current->next);
            }
            else {
                prev->next = current->next;
                free(current);
                current = NULL;
            }

            return 1;
        }
        prev = current;
        current = static_cast<Node*>(current->next);
    }

    return 0;
}

Node* insertNode(int data, int position)
{
    Node* current = head;
    while (current != NULL && position != 0)
    {
        position--;
    }

    if (position != 0)
    {
        std::cout << "Requested position too far into list" << std::endl;
        return NULL;
    }

    Node* New = (Node*)malloc(sizeof(Node));
    if (New == NULL)
        return NULL;

    New->data = data;
    New->next = current->next;
    current->next = New;

    return New;
}

void printList() {
    system("cls");
    Node* current = head;
    while (current != NULL)
    {
        std::cout << current->data << " ";
        current = static_cast<Node*>(current->next);
    }
    std::cout << std::endl;
}

void freeList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = static_cast<Node*>(current->next);
        delete temp;
    }
}

void printUI() {
	system("cls");
	std::cout << "Following options: \n\t1. Add node\n\t2. Remove Node\n\t3. Insert node\n\t4. Quit";
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	int option = -1;
    int data;
    int pos;
	while (option != 4) {
		printUI();
		std::cin >> option;
		std::cout << "pick a value: ";
		std::cin >> data;
		switch (option) {
			case 1:
				addNode(data);
                break;
			case 2:
                removeNode(data);
                break;
			case 3:
                std::cout << "which node: " << std::endl;
                std::cin >> pos;
                    insertNode(data, pos);
                break;
			case 4:
                option = 4;
                printList();
				break;
		}
        
	}
    freeList();
	system("pause");
	return 0;
}