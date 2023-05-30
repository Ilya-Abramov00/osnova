#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
#include <cstddef>


class List;

class Node{
    friend List;
public:
    Node(int data, Node* next=NULL,Node* prev=NULL ): data(data), next(next), prev(prev){}

    int data;
private:
    Node *next;
    Node *prev;
};

class List{
    friend Node;

public:

    List()
    {
        this->end=this->begin=NULL;
        this->count=0;
    }

    Node* push_back(int data)
    {
        Node *ptr= new Node(data);
        if ( begin==NULL ) { this->begin=ptr; this->end=ptr; }
        else
        {
            end->next=ptr;
            ptr->prev=end;
            this->end=ptr;
        }
        count++;
        return ptr;
    }

    Node* push_front(int data)
    {
        Node *ptr= new Node( data);
        begin->prev=ptr;
        ptr->next=begin;
        this->begin=ptr;
        count++;
        return ptr;
    }

    Node* getAt(int index)
    {
        Node* ptr = begin;
        int n = 0;
        while (n != index) {
            if (ptr == NULL) return ptr;
            ptr = ptr->next;
            n++;
        }
        return ptr;
    }


    Node* operator [] (int index) {
        return getAt(index);
    }

    Node* insert(int index, int data)
    {
        Node *ptr;
        if (index==0) ptr=push_front(data);
        else if (index==count) ptr=push_back(data);
        else
        {
            ptr= new Node( data );
            Node *rite=getAt( index );
            Node *left=rite->prev;
            left->next=ptr;
            ptr->prev=left;
            ptr->next=rite;
            rite->prev=ptr;
            count++;
        }
        return ptr;
    }

    void pop_back()
    {
        if( begin!=NULL  )
        {
            Node *left = end->prev;
            Node* ptr=end;

            delete  ptr;
            end = left;
            left->next=NULL;
            count --;
        }
        return;
    }

    bool erese(int index){
        if(index==count) pop_back();
        else if(0<index<count)
        {
            Node *del = getAt(index);
            Node *rite = del->next;
            Node *left = del->prev;

            left->next=rite;
            rite->prev=left;
            count --;
            del->next=NULL;
            delete del;
            return true;
        }
        else  return false;
    };


    ~List()
    {
        while ( count!=1 )
        {
            pop_back();
        }
        delete begin;
    }

private:
    Node * begin ;
    Node * end  ;
    int count;
};


#endif
