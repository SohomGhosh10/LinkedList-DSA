// Linkedlist Insertion & Deletion using C++

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
    Node *head = nullptr, *tail = nullptr;
    int countNode = 0;

public:
    void insertAtFirst(int data)
    {
        Node *newNode = new Node(data);
        if (!countNode) // if (countNode == 0)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
        countNode++;
    }
    void insertAtLast(int data)
    {
        Node *newNode = new Node(data);
        if (!countNode) // if (countNode == 0)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        countNode++;
    }
    void insertAtPosition(int position, int data)
    {
        if (position < 0 || position > countNode) // not a valid position
            exit(1);                              // exit from the program directly
        if (position == 0)
            insertAtFirst(data);
        else if (position == countNode)
            insertAtLast(data);
        else
        {
            Node *newNode = new Node(data);
            Node *temp = head;
            for (int i = 0; i < position - 1; i++)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            countNode++;
        }
    }

    void deleteFromFirst(){
      if (!head)
          exit(2);

      Node * temp = head;
      head = head->next;
      free(temp);

      if (countNode == 1)
      {
          tail = NULL;
      }

      countNode--;
      
    }

    void deleteFromLast(){
      if (!head)
          exit(3);

      else if (countNode == 1) 
      {
          free(head);
          head = tail = NULL;
      }

      else
      {
          Node * temp = head;

          while (temp->next != tail){
              temp = temp->next;
          }

          temp->next = NULL;
          free(tail);
          tail = temp;
      } 
      countNode--;
    }

    void deleteFromIndex(int position){
      if (position < 0 || position > countNode - 1)
          exit(5);
      else if (position == 0)
          deleteFromFirst();
      else if (position == countNode - 1)
          deleteFromLast();

      else{
        Node * temp1 = head;

        for (int i = 0; i < position - 1; i++)
            temp1 = temp1->next;

        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
        countNode--;
        
      }
    }

    void displayList()
    {
        if (!head)
            exit(2); // list is empty
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l1;
    l1.insertAtFirst(5);
    l1.insertAtFirst(4);
    l1.insertAtFirst(3);
    l1.insertAtFirst(2);
    l1.insertAtFirst(1);
    l1.insertAtLast(6);
    l1.insertAtLast(7);
    l1.insertAtLast(8);
    l1.insertAtPosition(3, 55);
    l1.displayList();

    l1.deleteFromFirst();

    l1.displayList();

    l1.deleteFromLast();

    l1.displayList();

    l1.deleteFromIndex(1);

    l1.displayList();

    l1.deleteFromIndex(0);

    l1.displayList();
    return 0;
}