#include <iostream>

using namespace std;
#include "LinkedList.h"
//DS ==> Way store Data Memory
//Variable (Primitive Data Structure) ==> int , float ,character,boolean
// (No Primitive) Derivied Array
// Linear DS  ===> Array , Linkedlist , Stack ,Queue
// NOn Linear DS ===> Tree,Hash Table, Graph

//Array :-
     // Fixed Size ==>(Once Created Never Change) Resize [Insert () , Remove(Shifting)]
     // Contiguous Block of Memory ==>
     // Homgonus Same DataType
     // Same Data Type from Different Domain ==> Not Homgonus


//5 Degree Student
//5 Salary Employee
//int arr[10]={};
//int Degree[5]={};
//int Salary[5]={};

/*dict arr={"name":"ali","age":25,"Salary":5000};
struct Employee{
    char

}*/
//-------------------------------------------------------------------
//Disadvantage Heap
//1- Memory Leak
    //int x=5;
    //int * ptr =malloc(sizeof(int)*size);
    //free(ptr);
    //ptr=&x;
// 2-What is Heap Fragmentation
    //|---|  |----|     |-----------|   |

//Array Disadvantage:-
//Contiguous Block of Memory ===> Fixed Size ==> Insert , Remove
//Array Advantage:-
//Contiguous Block of Memory ==> Access Index [Direct Access] [Random Access]

//#define NULL (void *) 0

//    HW==>CPU==>SW
/*
volatile int x=0;
ISR(){
    //ptr=&x;
    if(x==0){
        x=1;
    }
    else{
        x=0;
    }
}
*/


int main()
{
    //Wild Pointer
        //int *ptr; // Pointer(without Initalization) point to Grabage ??
        //Dereference Pointer ???
        /*if(ptr == ???){
            *ptr=5;
        }*/
    //NULL Pointer
    /*
    int *ptr=NULL; // Pointer(with Initalization NULL) point to NULL ??
        //Dereference Pointer ???
        //*ptr=5; ==> Crash
        if(ptr != NULL){
            *ptr=5;
        }
        else{
            printf("Pointer is NULL , Can't Derefence \n");
        }
    */
    //Dangling Pointer ==> Point Deleted Memory
    //RUST
    /*    int * function(){
             int arr[2]={0};
            //static int arr[2];
            //int *arr=malloc();
            return arr;
        }
        int * ptr= function();
    */


    //Node * head , Node * tail ====> Linkedlist
    //Node * Next ,Node * Prev, Data  ====> Node
    //LinkedList ===>head,tail,Consist of Collections of Nodes [Compisition]
    LinkedList mylist;

    mylist.add(1);
    mylist.add(5);
    mylist.add(10);
    mylist.add(3);
    mylist.add(13);
    mylist.display();// 3 5 10 3 13
///==============================================================
    ///Quest1
    /// insert node after given node
    mylist.InsertAfter(60,1);
    mylist.display();// 1 60 5 10 3  13
    mylist.InsertAfter(65,5);
    mylist.display();// 1 60 5 65 10 3  13
    mylist.InsertAfter(70,13);
    mylist.display();// 1 60 5 65 10 3  13 70
    mylist.InsertBefore(75,1);
    mylist.display();// 75 1 60 5 65 10 3  13 70
    ///Quest2
    /// insert node before given node
    mylist.InsertBefore(80,5);
    mylist.display();// 75 1 60 80 5 65 10 3  13 70
    mylist.InsertBefore(85,13);
    mylist.display();// 75 1 60 80 5 65 10 3 85 13 70
    ///Quest3
    /// get number of nodes
    cout<<"\n==================\nNumber of NODES is "<<mylist.GetCount()<<"\n==================\n"<<endl;
    ///Quest4
    /// get data in the given
    mylist.displayBYindex(0);
///==============================================================
    mylist.removeNode(15); //Not Found
    mylist.removeNode(3);
    mylist.display();//5 10 3 13
    mylist.removeNode(3);
    mylist.display();// 5 10 13
    mylist.removeNode(10);
    mylist.display();// 5 13
    mylist.removeNode(13);
    mylist.display();//5
    mylist.removeNode(5);
    mylist.display();//List Empty
    mylist.add(5);
    if(!mylist.search_using_data(10)){
        cout<<"Not Found"<<endl;
    }else{
        cout<<"Found"<<endl;
    }
    return 0;


}
