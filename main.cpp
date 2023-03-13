#include <iostream>
#include <windows.h>
struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(){
        prev = nullptr;
        next = nullptr;
    }
};

Node* Create_list() {
    Node *head = nullptr;
    return head;
}

void Add_Elem(Node* &head, int val) {
    if (head == nullptr) {
        head = new Node();
        head->next = head;
        head->val = val;
        head->prev = head;
    }
    else {
        if (head->val <= val) {
            Node *temp = new Node();
            temp->prev = head->prev;
            temp->next = head;
            head->prev->next = temp;
            head->prev = temp;
            temp->val = val;
            head = temp;
        } else {
            Node *current = head->next;
            while ((current != head)&&(current->val >= val)) {
                current = current->next;
            }
            Node *temp = new Node();
            temp->prev = current->prev;
            current->prev->next = temp;
            current->prev = temp;
            temp->next = current;
            temp->val = val;
        }
    }
}

void Delete(Node *&head, int val){
    Node*current = head;
    if (head == nullptr)
        std::cout << "List is empty.";
    else{
    if (head->val == val){
        Node*temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        delete(temp);
    }
    current = current->next;
    while(current->next != head){
        if (current->val == val){
            Node*temp = current->next;
            current->next = temp->next;
            temp->next->prev = current;
            delete(temp);
        }
        current = current->next;
    }
    }
}

void Delete_List(Node *&head){
    if (head != nullptr) {
        Node *current = head->next;
        while (current != head) {
            Node *delet = current;
            current = current->next;
            delete (delet);
        }
    }
    head = nullptr;
}

void Print_List(Node*head){
    if (head){
        Node*current = head->next;
        std::cout << head->val << " <-> ";
        while (current != head){
            std::cout << current->val << " <-> ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    else{ std::cout << "Список пуст.\n";}
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Node* first = Create_list();
    Add_Elem(first, 10);
    Add_Elem(first, 9);
    Add_Elem(first, 11);
    Add_Elem(first,10);
    Add_Elem(first, 7);
    Add_Elem(first, 12);
    Add_Elem(first, 10);
    Print_List(first);
    Delete(first, 10);
    Print_List(first);
    Delete_List(first);

    return 0;
}
