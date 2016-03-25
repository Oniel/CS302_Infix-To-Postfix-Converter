/*linkedStack class declarations and implementation functions
    functions used:
        constructor
        destructor
        isEmpty
        makeEmpty
        push
        pop
        top
        topNpop
*/

#ifndef HSTACK
#define HSTACK

#include <iostream>
using namespace std;

//list node ***********************************************
//each character of the work will be stored in the 'info' element
template <class type>
struct stackNode{
    type info;
    stackNode<type> *next;
    };

//class declarations **************************************
template <class type>
class linkedStack{
    public:
        linkedStack();
        ~linkedStack();
        bool isEmpty() const;
        void makeEmpty();
        void push(const type &newItem);
        void pop();
        type top() const;
        type topNpop();
    private:
        stackNode<type> *stacktop;
};

//implementation functions ********************************
//constructor, sets only variable to NULL
template <class type>
linkedStack<type>::linkedStack(){
    stacktop = NULL;
    }

//destructor
template <class type>
linkedStack<type>::~linkedStack(){
    makeEmpty();}

//return true if stack is empty
template <class type>
bool linkedStack<type>::isEmpty() const{
    return (stacktop == NULL);
    }

//clear the list
template <class type>
void linkedStack<type>::makeEmpty(){
    stackNode<type> *tmp;
    while(stacktop != NULL){
        tmp = stacktop;
        stacktop = stacktop->next;
        delete tmp;
    }
}

//create a new stackNode, store the newItem, and push to front of stack
template <class type>
void linkedStack<type>::push(const type& newItem){
    stackNode<type> *newNode;
    newNode = new stackNode<type>;
    newNode->info = newItem;
    newNode->next = stacktop;
    stacktop = newNode;
    }

//remove  top, used for topNpop function
template <class type>
void linkedStack<type>::pop(){
    stackNode<type> *tmp;
    if(stacktop !=NULL){
        tmp = stacktop;
        stacktop = stacktop->next;
        delete tmp;
        }
        //else list is empty do nothing
    }

//return top value
template <class type>
type linkedStack<type>::top() const{
    if(stacktop != NULL)
    return (stacktop->info);
    }

//calls the top and pop functions
template <class type>
type linkedStack<type>::topNpop(){
    type tmp = top();
    pop();
    return tmp;
    }

#endif
