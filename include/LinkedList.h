#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
class LinkedList
{
    private:
        Node * head;
        Node * tail;
        ///get number of nodes
        int Ncounter = 0;
    Node * getNodeUsingData(int data){
        Node *current=head;
        while(current != NULL){
            if(current->Data==data){
                return current;
            }
            //Jump
            current=current->Next;
        }
        return NULL;

    }


    public:
        LinkedList() {
            head=tail=NULL;
        }
        void add(int data){
            //Create Node
            Node * node = new Node(data); //Create Object Node , Data=data , next,prev=null
            ///get number of nodes
            Ncounter +=1;
                if(head == NULL){//First Node
                    head=tail=node;
                    //node->Next=node->prev=NULL;
                }
                else{//Not First Node
                    tail->Next = node; //Old->Next=NewNode
                    node->Prev=tail; //newNode->prev=old(Node)
                    tail=node;//tail=node;
                }
        }

        void display(){
            Node * current =head;//NULL
            if(current == NULL){
                cout<<"Linked List is Empty \n";
                return ;
            }
            while(current != NULL){
                //Display
                cout<<current->Data<<"\t";
                //Increment Jump Node
                current=current->Next;
            }
            cout<<endl;
        }

    void removeNode(int data){
        //Search Linked List
        Node * node = getNodeUsingData(data);
        if(node == NULL){
            cout<<"Element Not Found , Can't Remove \n";
            return;
        }
        else{
            //Remove First
            if(node == head){
                if(node == tail){
                    tail=head=NULL;
                }
                else{
                    head=node->Next;
                    head->Prev=NULL;
                }

            }
            else if (node == tail){ //Remove Last
                tail=node->Prev;
                tail->Next=NULL;
            }
            else{//Remove Mid
                Node * A=node->Prev;
                Node * B=node->Next;
                A->Next=B;
                B->Prev=A;
            }

            delete(node);

        }

    }
///==============================================================
    ///Quest1
    /// insert node after given node
    void InsertAfter(int data, int afterData){
        //Search Linked List
        Node * node = getNodeUsingData(afterData);
        if(node == NULL){
            cout<<"Element Not Found , I can't find the place to put this data in..?! \n";
            return;
        }
        else{
            Node * Nnode = new Node(data);
            ///get number of nodes
            Ncounter +=1;
            if(node == head){
                Node * A = head->Next;
                A->Prev = Nnode;
                Nnode->Next = A;
                Nnode->Prev = head; //newNode->prev=old(Node)
                head->Next = Nnode;
            }else if(node == tail){
                Nnode->Next = NULL;
                tail->Next = Nnode; //Old->Next=NewNode
                Nnode->Prev = tail; //newNode->prev=old(Node)
                tail=Nnode;//tail=node;
            }else{
                Node * A = node->Next;
                A->Prev = Nnode;
                Nnode->Next = A;
                Nnode->Prev = node; //newNode->prev=old(Node)
                node->Next = Nnode;
            }
            }
    }

    ///Quest2
    /// insert node before given node
    void InsertBefore(int data, int beforeData){
        //Search Linked List
        Node * node = getNodeUsingData(beforeData);
        if(node == NULL){
            cout<<"Element Not Found , I can't find the place to put this data in..?! \n";
            return;
        }
        else{
            Node * Nnode = new Node(data);
            ///get number of nodes
            Ncounter +=1;
            if(node == head){
                Nnode->Next = head;
                Nnode->Prev = NULL; //newNode->prev=old(Node)
                node ->Prev = Nnode;
                head = Nnode;
            }else if(node == tail){
                Node * A = tail->Prev;
                A -> Next = Nnode;
                Nnode->Prev = A; //newNode->prev=old(Node)
                Nnode->Next = node;
                tail->Prev = Nnode; //Old->Next=NewNode
            }else{
                Node * A = node->Prev;
                A->Next = Nnode;
                Nnode->Prev = A; //newNode->prev=old(Node)
                Nnode->Next = node;
                node->Prev = Nnode;
            }
            }
    }

    ///Quest3
    /// get number of nodes
    int GetCount(){
        return Ncounter;

       };
    ///Quest4
    /// get data in the given
    void displayBYindex(int x){
        int i = 0;
        Node * current =head;//NULL
        while(i!=x)
        {
            current=current->Next;
            i++;
        }
        cout<<"====================\n";
        cout<<"your NODE in index  "<<x<<"  is: \n";
        cout<<current->Data;
        cout<<"\n====================\n";
    }

///==============================================================

    int search_using_data(int data){
        Node * node = getNodeUsingData(data);
        if(node == NULL){
            return 0;
        }
        else{
            return 1;
        }
    }
    protected:

};

#endif // LINKEDLIST_H
