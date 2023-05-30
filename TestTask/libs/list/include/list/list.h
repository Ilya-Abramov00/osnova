#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
#include <cstddef>

template <class Type>
class List;

template <class Type>
class Node
{
    template <class T>
    friend class List;

private:
    Node<Type> (Type data, Node<Type>* next=NULL, Node<Type>* prev=NULL ): data(data), next(next), prev(prev){}

    Node<Type> *next;
    Node<Type> *prev;
public:
    Type data;
};

template <class Type>
class List{

public:

    List()
    {
        this->end=this->begin=NULL;
        this->count=0;
    }

    void  push_back(Type data)
    {
        Node<Type>  *ptr= new Node(data);
        if ( begin==NULL ) { this->begin=ptr; this->end=ptr; }
        else
        {
            end->next=ptr;
            ptr->prev=end;
            this->end=ptr;
        }
        count++;
        return;
    }

    void push_front(Type data)
    {
        Node<Type>  *ptr= new Node( data);
        begin->prev=ptr;
        ptr->next=begin;
        this->begin=ptr;
        count++;
        return;
    }

    Node<Type> * getAt(int index)
    {
        Node<Type> * ptr = begin;
        int n = 0;
        while (n != index) {
            if (ptr == NULL) return ptr;
            ptr = ptr->next;
            n++;
        }
        return ptr;
    }


    Node<Type> * operator [] (int index) {
        return getAt(index);
    }

    void insert(int index, Type data)
    {

        if (index==0) push_front(data);
        else if (index==count) push_back(data);
        else
        {
            Node<Type>  *ptr= new Node( data);
            Node<Type>  *rite=getAt( index );
            Node<Type>  *left=rite->prev;
            left->next=ptr;
            ptr->prev=left;
            ptr->next=rite;
            rite->prev=ptr;
            count++;
        }
        return ;
    }

    void pop_back()
    {
        if( begin!=NULL  )
        {
            Node<Type>  *left = end->prev;
            Node<Type> * ptr=end;

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
            Node<Type>  *del = getAt(index);
            Node<Type>  *rite = del->next;
            Node<Type>  *left = del->prev;

            left->next=rite;
            rite->prev=left;
            count --;
            del->next=NULL;
            delete del;
            return true;
        }
        else  return false;
    };

    Node<Type> * begin_(){

        return begin;
    }

    Node<Type> * end_(){

        return end;
    }
    ~List()
    {
        while ( count!=1 )
        {
            pop_back();
        }
        delete begin;
    }

private:
    Node<Type>  * begin ;
    Node<Type>  * end  ;
    int count;
};


#endif
