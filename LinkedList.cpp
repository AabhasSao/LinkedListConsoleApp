#include <iostream>
#include <string.h>

using namespace std;


struct LinkedListNode {
    int data;
    LinkedListNode *next;
};

class LinkedList {
    private:
    LinkedListNode *head, *tail;
    
    public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    LinkedListNode* createNode(int data);
    void pushBack(int data);
    void printAll();
    void reverse();
    void pop();
    void insert(int index, int data);
    void deleteNode(int index);
    int  getSize();
};

LinkedListNode* LinkedList::createNode(int data) {
    LinkedListNode *temp = new LinkedListNode;
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

void LinkedList::pushBack(int data) {
    LinkedListNode *node = createNode(data);

    if(head==NULL) {
        head = node;
        tail = node;
    }  
    else {
        tail->next = node;
        tail = tail->next;
    }
    cout<<node->data<<" added \n";
}

void LinkedList::printAll() {
    LinkedListNode* temp = head;
    if(head == NULL) {
        cout<<"Linked list is empty";
        return;
    }
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void LinkedList::reverse() {
    LinkedListNode* curr = head;
    LinkedListNode* prev = NULL;
    LinkedListNode* next = NULL;
    tail = head;

    while(curr!=NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev; 
}

void LinkedList::pop() {
    if(head == NULL) {
        cout<<"cannot pop from empty linked list \n";
        return;
    }

    if(head->next == NULL) {
        head = NULL;
        tail = NULL;
        return;
    }

    LinkedListNode* temp = head;
    while(temp->next != tail) {
        temp = temp->next;
    }
    tail = temp;
    tail->next = NULL;
}

void LinkedList::insert(int index, int data) {
    
    LinkedListNode *newNode = createNode(data);

    if(head == NULL && index == 1) {
        head = newNode;
        tail = newNode;
        return;
    }
    if(index == 1) {
        newNode->next = head->next;
        head->next = newNode;
        return;
    }
    if(head->next == NULL && index == 2) {
        head->next = newNode;
        tail = newNode;
        return;
    }

    int count = 2;
    LinkedListNode* temp = head;

    
    while(temp->next != NULL && count != index) {
        temp = temp->next;
        count++;
    } 

    if(index != count) {
        cout<<"index should be lesser than size\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    if(newNode->next == NULL) {
        tail = newNode;
    }
}

void LinkedList::deleteNode(int index) {
    LinkedListNode* temp = head;
    if(index == 1) {
        head = head->next;
        delete temp;
        return;
    }

    int count = 2;
    while(temp->next != NULL && count != index) {
        temp = temp->next;
        count++;
    }
    if(index != count) {
        cout<<"index should be lesser than size\n";
        return;
    }
    LinkedListNode* toDelete = temp->next;
    if(toDelete->next == NULL) {
        tail = toDelete;
    } 
    temp->next = toDelete->next;
    delete toDelete;
}
int LinkedList::getSize() {
    if(head == NULL) {
        return 0;
    }
    int count = 0;
    LinkedListNode* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}
int main() {
    LinkedList myLL;
    cout<<"\n----------------------------\n";
    cout<<"           Welcome\n";
    cout<<"----------------------------\n\n";
    // myLL.pushBack(1);
    // myLL.pushBack(2);
    // myLL.pushBack(3);
    // myLL.pushBack(4);
    // myLL.pushBack(5);
    // myLL.pushBack(6);
    // myLL.pushBack(7);
    // myLL.pushBack(8);
    // myLL.insert(3, 3);
    // myLL.deleteNode(3);
    // myLL.deleteNode(11);
    // myLL.printAll();
    // myLL.reverse();
    // cout<<"\n";
    // myLL.pop();
    // myLL.pop();
    // myLL.pop();
    // myLL.pop();
    // myLL.pop();
    // myLL.pop();
    // cout<<"size: "<<myLL.getSize()<<"\n";
    // myLL.pop();
    // myLL.pop();
    // myLL.pop();
    // myLL.pop();
    // myLL.printAll();


    char command[40];
    while(1) {
        cout<<"\n\nEnter help for commands list\n";
        cout<<"\nEnter command: ";
        cin>>command;
        if(strcmp(command, "add") == 0) {
            int s;
            cout<<"Enter integer to add\n";
            cin>>s;
            myLL.pushBack(s);
        }
        else if(strcmp(command, "help") == 0) {
            cout<<"\n----------COMMANDS LIST-------------\n";
            cout<<"\nadd : to add an integer to the linked list\n\n";
            cout<<"all : print all integers in the linked list\n\n";
            cout<<"delete : delete node at given index\n\n";
            cout<<"pop : deletes the last node\n\n";
            cout<<"reverse : figure it out yourself seems obvious to me\n\n";
            cout<<"size : size of the linked list\n\n";
            cout<<"insert : add an element at given index\n";
            cout<<"\n";
        }
        else if(strcmp(command, "delete") == 0) {
            cout<<"Enter index: ";
            int index;
            cin>>index;
            myLL.deleteNode(index);
        }
        else if(strcmp(command, "size") == 0) {
            cout<<"size: "<<myLL.getSize()<<"\n";
        }
        else if(strcmp(command, "reverse") == 0) {
            myLL.reverse();
        }
        else if(strcmp(command, "pop") == 0) {
            myLL.pop();
        }
        else if(strcmp(command, "insert") == 0) {
            cout<<"Enter index: ";
            int index;
            cin>>index;
             cout<<"Enter integer: ";
            int num;
            cin>>num;
            myLL.insert(index, num);
        }
        else if(strcmp(command, "all") == 0) {
            cout<<"\n--Here's your list--\n";
            myLL.printAll();
        }
        else {
            cout<<"No such command exists";
        }
    }
    return 0;
}

