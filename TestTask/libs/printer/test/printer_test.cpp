#include <gtest/gtest.h>
#include "printer/printer.h"

/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованны и с созданием объекта всё ок.
 */
TEST(PrinterTests, Creating) {
	Printing::Printer testedObject;
	Printing::Printer testedObject1(std::cerr);
}
/**
 * @brief TEST в этом тесте не создаётся объектов. поэтому число созданных объектов равно нулю
 */
TEST(PrinterTests, CheckCountCreatedObjects_nothing) {
	ASSERT_EQ(Printing::Printer::getCountCreatedPrinters(), 0);
}
/**
 * @brief TEST создаём три подряд объекта. счётчик созданных объектов равен нулю
 */
TEST(PrinterTests, CheckCountCreatedObjects) {
	Printing::Printer testedObject;
	Printing::Printer testedObject1;
	Printing::Printer testedObject2;

	ASSERT_EQ(Printing::Printer::getCountCreatedPrinters(), 3);
}
/**
 * @brief TEST создаётся три подряд объекта в куче. далее по одному объекты начинают удаляться.
 * после каждого последующего удаления количество созданных принеторов декрементируется.
 * и достигает нуля, когда каждый из созданных обектов уничтожился.
 *
 */
TEST(PrinterTests, CheckCountCreatedObjectsWithDelete) {
	Printing::Printer* testedObject = new Printing::Printer();
	Printing::Printer* testedObject1 = new Printing::Printer();
	Printing::Printer* testedObject2 = new Printing::Printer();

	delete  testedObject;
	ASSERT_EQ(Printing::Printer::getCountCreatedPrinters(), 2);
	delete  testedObject1;
	ASSERT_EQ(Printing::Printer::getCountCreatedPrinters(), 1);
	delete  testedObject2;
	ASSERT_EQ(Printing::Printer::getCountCreatedPrinters(), 0);
}
/**
 * @brief этот тест проверяет печатает ли принтер вообще что-то, результат виден только в виде вывода в консоль
 */
TEST(PrinterTests, printing_stock) {
	Printing::Printer testedObject;
	testedObject.print(" Hello Word! ");
}
/**
 * @brief этот тест проверяет печатает ли принтер путём подстановки собственного потока вывода.
 * в данном случае это объект класса std::stringstream
 * результат печати должен находиться в объекте printString, и должен представлять из себя сторку для печати + escape последовательность '\n'
 * '\n' переводит каретку в начало следующей строки
 */
TEST(PrinterTests, printing_custom) {
	std::stringstream printString;

	Printing::Printer testedObject(printString);

	testedObject.print(" Hello Word! ");

	auto printerResult = printString.str();
	ASSERT_EQ(printerResult, (" Hello Word! \n"));
}

#include <cstddef>
#include <iostream>

//здесь описан List
using namespace std;

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

TEST(list_test, 1) {
    List a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);

    ASSERT_TRUE(a.getAt(0)->data==1);
    ASSERT_TRUE(a.getAt(1)->data==2);
    ASSERT_TRUE(a.getAt(2)->data==2);
}

TEST(list_test, 2) {
    List a;
    a.push_back(1);
    a.push_front(2);
    a.push_back(2);

    ASSERT_TRUE(a.getAt(0)->data==2);
    ASSERT_TRUE(a.getAt(1)->data==1);
    ASSERT_TRUE(a.getAt(2)->data==2);
}

TEST(list_test, 3) {
    List a;
    a.push_back(1);
    a.push_back(2);
    a.pop_back();
    a.push_back(3);

    ASSERT_TRUE(a.getAt(0)->data==1);
    ASSERT_TRUE(a.getAt(1)->data==3);

}
TEST(list_test, 4) {
    List a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.erese(1);


    ASSERT_TRUE(a.getAt(0)->data==1);
    ASSERT_TRUE(a.getAt(1)->data==3);
}

TEST(list_test, 5) {
    List a;
    a.push_back(1);
    a.insert(0,0);
    a.insert(2,4);

    ASSERT_TRUE(a.getAt(0)->data==0);
    ASSERT_TRUE(a.getAt(1)->data==1);
    ASSERT_TRUE(a.getAt(2)->data==4);

}