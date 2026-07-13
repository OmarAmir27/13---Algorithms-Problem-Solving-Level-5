// 13 - Algorithms & Problem Solving Level 5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <queue>
#include "MyDblLinkedList.h";
#include "clsMyQueue.h";
#include "clsMyStack.h";
#include "clsDynamicArray.h";
#include "clsMyQueueArr.h";
#include "clsMyStackArr.h";
#include "clsMyString.h";
#include "clsQueueLine.h";

using namespace std;

void DoubleLinkedList()
{
    MyDblLinkedList<int> Db;

    if (Db.IsEmpty())
        cout << "Yes, This List is Empty :-) \n\n";
    else
        cout << "No, This List is NOT Empty :-( \n\n";


    Db.InsertAtBeginning(5);
    Db.InsertAtBeginning(4);
    Db.InsertAtBeginning(3);
    Db.InsertAtBeginning(2);
    Db.InsertAtBeginning(1);
    Db.InsertAtEnd(77);
    Db.InsertAtEnd(88);
    Db.InsertAtEnd(99);
    Db.PrintList("This List After Insert : ");

    cout << "Number of Nodes in Double Linked List : " << Db.Size() << "\n\n";


    Db.DeleteFirstNode();
    Db.PrintList("This List After Delete First Node : ");
    cout << "Number of Nodes in Double Linked List : " << Db.Size() << "\n\n";


    Db.DeleteLastNode();
    Db.PrintList("This List After Delete Last Node : ");
    cout << "Number of Nodes in Double Linked List : " << Db.Size() << "\n\n";

    if (Db.IsEmpty())
        cout << "Yes, This List is Empty :-) \n\n";
    else
        cout << "No, This List is NOT Empty :-( \n\n";

    MyDblLinkedList<int>::clsNode* N1 = Db.Find(4);
    if (N1 != NULL)
        cout << "Node is Found :-) \n\n";
    else
        cout << "Node is not Found :-( \n\n";
    Db.InsertAfter(N1, 500);
    Db.PrintList("This List After Insert 500 After N1 : ");

    cout << "Number of Nodes in Double Linked List : " << Db.Size() << "\n\n";


    //cout << "Executing .Clear() \n";
    //Db.Clear();
    //cout << "Number of Nodes in Double Linked List : " << Db.Size() << "\n\n";


    Db.PrintList("Original List : ");

    Db.Reverse();
    Db.PrintList("List After Reversing : ");


    MyDblLinkedList<int>::clsNode* NodeFind = Db.GetNode(2);
    cout << "Value of the Node is : " << NodeFind->Value << "\n";

    cout << "Item(2) Value is : " << Db.GetItem(2) << "\n";

    Db.UpdateItem(2, 8450);
    Db.PrintList("List After Update : ");

    Db.InsertAfter(7, 88888);
    Db.PrintList("List After Insert After : ");

}

void Queue()
{
    clsMyQueue<int> MyQueue;
    MyQueue.Push(10);
    MyQueue.Push(20);
    MyQueue.Push(30);
    MyQueue.Push(40);
    MyQueue.Push(50);

    MyQueue.Print("My Queue : ");


    cout << "Size Of MyQueue : " << MyQueue.Size() << endl;
    cout << "Front Of MyQueue : " << MyQueue.Front() << endl;
    cout << "Back Of MyQueue : " << MyQueue.Back() << endl;

    MyQueue.Pop();
    MyQueue.Print("\n\nMy Queue After Pop : ");


    // Extension #1
    cout << "\n Item(2) : " << MyQueue.GetItem(2) << "\n";
    // Extension #2
    MyQueue.Reverse();
    MyQueue.Print("My Queue After Reverse : ");

    // Extension #3
    MyQueue.UpdateItem(2, 800);
    MyQueue.Print("My Queue After Update Item (2) : ");

    // Extension #4
    MyQueue.InsertAfter(2, 11750);
    MyQueue.Print("My Queue After Insert After (2) : ");

    // Extension #5
    MyQueue.InsertAtFront(11111);
    MyQueue.Print("My Queue After Insert At Front 11111 : ");

    // Extension #6
    MyQueue.InsertAtBack(99999);
    MyQueue.Print("My Queue After Insert At Back 99999 : ");

    // Extension #7
    MyQueue.Clear();
    MyQueue.Print("My Queue After Clear : ");


}

void QueueArr()
{
    clsMyQueueArr<int> MyQueue;
    MyQueue.Push(10);
    MyQueue.Push(20);
    MyQueue.Push(30);
    MyQueue.Push(40);
    MyQueue.Push(50);

    MyQueue.Print("My Queue : ");


    cout << "Size Of MyQueue : " << MyQueue.Size() << endl;
    cout << "Front Of MyQueue : " << MyQueue.Front() << endl;
    cout << "Back Of MyQueue : " << MyQueue.Back() << endl;

    MyQueue.Pop();
    MyQueue.Print("\n\nMy Queue After Pop : ");


    // Extension #1
    cout << "\n Item(2) : " << MyQueue.GetItem(2) << "\n";
    // Extension #2
    MyQueue.Reverse();
    MyQueue.Print("My Queue After Reverse : ");

    // Extension #3
    MyQueue.UpdateItem(2, 800);
    MyQueue.Print("My Queue After Update Item (2) : ");

    // Extension #4
    MyQueue.InsertAfter(2, 11750);
    MyQueue.Print("My Queue After Insert After (2) : ");

    // Extension #5
    MyQueue.InsertAtFront(11111);
    MyQueue.Print("My Queue After Insert At Front 11111 : ");

    // Extension #6
    MyQueue.InsertAtBack(99999);
    MyQueue.Print("My Queue After Insert At Back 99999 : ");

    // Extension #7
    MyQueue.Clear();
    MyQueue.Print("My Queue After Clear : ");


}

void Stack()
{
    clsMyStack<int> MyStack;
    MyStack.Push(10);
    MyStack.Push(20);
    MyStack.Push(30);
    MyStack.Push(40);
    MyStack.Push(50);

    MyStack.Print("My Stack : ");


    cout << "Size Of MyStack : " << MyStack.Size() << endl;
    cout << "Top Of MyStack : " << MyStack.Top() << endl;
    cout << "Bottom Of MyStack : " << MyStack.Bottom() << endl;

    MyStack.Pop();
    MyStack.Print("\n\nMy Stack After Pop : ");


    // Extension #1
    cout << "\n Item(2) : " << MyStack.GetItem(2) << "\n";
    // Extension #2
    MyStack.Reverse();
    MyStack.Print("My Stack After Reverse : ");

    // Extension #3
    MyStack.UpdateItem(2, 800);
    MyStack.Print("My Stack After Update Item (2) : ");

    // Extension #4
    MyStack.InsertAfter(2, 11750);
    MyStack.Print("My Stack After Insert After (2) : ");

    // Extension #5
    MyStack.InsertAtTop(11111);
    MyStack.Print("My Stack After Insert At Top 11111 : ");

    // Extension #6
    MyStack.InsertAtBottom(99999);
    MyStack.Print("My Stack After Insert At Bottom 99999 : ");

    // Extension #7
    MyStack.Clear();
    MyStack.Print("My Stack After Clear : ");


}

void StackArr()
{
    clsMyStackArr<int> MyStack;
    MyStack.Push(10);
    MyStack.Push(20);
    MyStack.Push(30);
    MyStack.Push(40);
    MyStack.Push(50);

    MyStack.Print("My Stack : ");


    cout << "Size Of MyStack : " << MyStack.Size() << endl;
    cout << "Top Of MyStack : " << MyStack.Top() << endl;
    cout << "Bottom Of MyStack : " << MyStack.Bottom() << endl;

    MyStack.Pop();
    MyStack.Print("\n\nMy Stack After Pop : ");


    // Extension #1
    cout << "\n Item(2) : " << MyStack.GetItem(2) << "\n";
    // Extension #2
    MyStack.Reverse();
    MyStack.Print("My Stack After Reverse : ");

    // Extension #3
    MyStack.UpdateItem(2, 800);
    MyStack.Print("My Stack After Update Item (2) : ");

    // Extension #4
    MyStack.InsertAfter(2, 11750);
    MyStack.Print("My Stack After Insert After (2) : ");

    // Extension #5
    MyStack.InsertAtTop(11111);
    MyStack.Print("My Stack After Insert At Top 11111 : ");

    // Extension #6
    MyStack.InsertAtBottom(99999);
    MyStack.Print("My Stack After Insert At Bottom 99999 : ");

    // Extension #7
    MyStack.Clear();
    MyStack.Print("My Stack After Clear : ");


}

void DynamicArray()
{
    clsDynamicArray<int> DynamicArray(5);
    DynamicArray.SetItem(0, 10);
    DynamicArray.SetItem(1, 20);
    DynamicArray.SetItem(2, 30);
    DynamicArray.SetItem(3, 40);
    DynamicArray.SetItem(4, 50);

    cout << "is Empty : " << DynamicArray.IsEmpty() << "\n";
    cout << "Size : " << DynamicArray.Size() << "\n";

    DynamicArray.Print("Items in Dynamic Array : ");

    //DynamicArray.Resize(2);
    //cout << "Size : " << DynamicArray.Size() << "\n";
    //DynamicArray.Print("Items in Dynamic Array After Resize to 2 : ");

    //DynamicArray.Resize(10);
    //cout << "Size : " << DynamicArray.Size() << "\n";
    //DynamicArray.Print("Items in Dynamic Array After Resize to 10 : ");


    DynamicArray.InsertAt(2, 500);
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After insert 500 at Index 2 : ");

    DynamicArray.InsertAtBeginning(400);
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After insert 400 at Beginning : ");

    DynamicArray.InsertBefore(2, 600);
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After insert 600 before Index 2 : ");

    DynamicArray.InsertAfter(3, 700);
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After insert 700 after index 3 : ");

    DynamicArray.InsertAtEnd(800);
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After insert 800 at End : ");

    cout << DynamicArray.GetItem(2) << "\n";
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After Reverse : ");

    DynamicArray.Reverse();
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After Reverse : ");

    //DynamicArray.Clear();
    //cout << "Size : " << DynamicArray.Size() << "\n";
    //DynamicArray.Print("Items in Dynamic Array After Clear : ");

    DynamicArray.DeleteItemAt(2);
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After Delete Item At index 2 : ");

    DynamicArray.DeleteFirstItem();
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After Delete First Item : ");

    DynamicArray.DeleteLastItem();
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After Delete Last Item : ");

    int Index = DynamicArray.Find(40);
    if (Index != -1)
        cout << "40 Was Found Successfully :-) \n\n";
    else
        cout << "Item Was NOT Found :-( \n\n";

    DynamicArray.DeleteItem(40);
    cout << "Size : " << DynamicArray.Size() << "\n";
    DynamicArray.Print("Items in Dynamic Array After Delete Item 40 : ");
}

void MyString()
{
    clsMyString S1;
    S1.Value = "";
    cout << "S1 = " << S1.Value << "\n";

    S1.Value = "Omar";
    cout << "S1 = " << S1.Value << "\n";

    S1.Value = "Amir";
    cout << "S1 = " << S1.Value << "\n";

    S1.Value = "Khalel";
    cout << "S1 = " << S1.Value << "\n";


    cout << "\n\n----------------------------------------- Undo ----------------------------------------- \n\n";
    S1.Undo();
    cout << "S1 = " << S1.Value << "\n";

    S1.Undo();
    cout << "S1 = " << S1.Value << "\n";

    S1.Undo();
    cout << "S1 = " << S1.Value << "\n";

    cout << "\n\n----------------------------------------- Redo ----------------------------------------- \n\n";
    S1.Redo();
    cout << "S1 = " << S1.Value << "\n";

    S1.Redo();
    cout << "S1 = " << S1.Value << "\n";

    S1.Redo();
    cout << "S1 = " << S1.Value << "\n";

}

int main()
{
    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);


    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();


    PayBillsQueue.PrintInfo();

    PayBillsQueue.PrintTicketsLineQueueRTL();
    PayBillsQueue.PrintTicketsLineQueueLTR();

    PayBillsQueue.PrintAllTickets();
    
    PayBillsQueue.ServeNextClient();
    PayBillsQueue.PrintInfo();
    return 0;
}
