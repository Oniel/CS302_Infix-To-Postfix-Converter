/*
    oniel toledo
    assignment 03
    cs 302 section 1001

    the following program prompts the user for an infix based expression
        and converts it into postfix expression.
    the program utilizes the template based linkedstack class for operand
        manipulation of the expression
    for detailed documentation refer to comments above code fragements,
        classes, and functions
*/

#include <iostream>
#include <string>
#include <sstream>
#include "linkedStack.h"
using namespace std;

int main()
{
    //variables
    string inputInfix;
    char infixChar;

    //objects
    linkedStack<char> stack;


    //prompt user for infix expression
    cout << "Enter Infix notation string to be converted" << endl;
    cout << "------------------------------------------------------------" << endl;
    getline(cin, inputInfix);                          //get string expression till \n
    istringstream input(inputInfix);        //create string stream for infix expression

    //with the infix expression set in the istringstream buffer 'input'
    //      perform the following loop until the 'input' has no more data'
    //there will be 4 possible cases:
    //      1. infixChar is ')', push it to stack
    //      2. infixChar is '(', pop stack until ')' is reached, then pop once more
    //      3. infixChar is numerical value, cout it
    //      4. infixChar is an operator

    input >> infixChar;                                    //input first char
    while(input){                                             //loop until there is no more data left
        if( infixChar == '(' )                               //case 1
            stack.push(infixChar);
        else
            if ( infixChar == ')' ){                                     //case 2
                while(stack.top() != '(' ) {                         //end of bracket pop, all operators
                    cout << stack.topNpop() << " ";         //till openning brack is reached
                    }
                stack.pop();                                                  //pop starting bracket
                }
            else
                if( infixChar >= '0' && infixChar <= '9')   //case 3
                    cout << infixChar << " ";                        //for all numerical variables, output

                //case 4
                else{
                    //loop until break is reached.
                    while(true){
                        //if infixChar is a high order operator.. * or /.
                            if( infixChar == '/' || infixChar == '*'){
                                //if stacktop is of equal priority topNpop and continue for another loop
                                if(stack.top() == '/' || stack.top() == stack.top() =='*')
                                    cout << stack.topNpop() << " ";
                                else{
                                    //stacktop is of lower priority or (, push and break for next char
                                    stack.push(infixChar);
                                    break;
                                    }
                                }
                        //if infixChar is a low order operator
                            if(infixChar == '+' || infixChar == '-'){
                                    //if stacktop is of equal or higher priority topNpop and loop
                                    if(  stack.top() == '+' ||  stack.top() =='-' || stack.top() == '/' || stack.top() =='*')
                                        cout << stack.topNpop() << " ";
                                    else{
                                        stack.push(infixChar);
                                         break;
                                        }
                            }
                            //if stack is empty or ( is reached push infixChar operand to  stack and break
                            if( stack.isEmpty() == true || stack.top() == '(' ){
                                stack.push(infixChar);
                                break;
                                }
                        } //end while loop for operators
                    } //end else statement for operators
        input >> infixChar;
    }
        //pop any remaining operands in stack
        while(stack.isEmpty() == false){
            cout << stack.topNpop() <<  " ";
            }
            cout << endl;



    return 0;
}
