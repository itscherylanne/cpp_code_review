/****************************************************************************/
/**********************         Prologue          ***************************/
/*                                                                          */
/*             University of California Extension, Santa Cruz               */
/*                                                                          */
/*                        C++ Comprehensive                                 */
/*                                                                          */
/*     Instructor: Suleman Saya                                             */
/*                                                                          */
/*     Author: Cheryl Anne Estacio                                          */
/*                                                                          */
/*     Assignment Number: 2                                                 */
/*                                                                          */
/*      Filename: CAlley.h                                        */
/*                                                                          */
/*      Date: July 29, 2014                                                  */
/*      Comments:  Developed in Windows Visual Studio 2013                  */
/*                 Tested in Visual Studio                                  */
/****************************************************************************/
/* CAlley - Class that defines the objects and methods of each alley within */
/*          the car simulation*/
/****************************************************************************/
/*                          preprocessor derivatives                        */
/****************************************************************************/

#include "CarNode.h"

#include <iostream>
#include <string>
using namespace std;

class CAlley {
public:
    CAlley() : m_pTop(0), mSize(0), mMaxSize(MAXSIZE) { }
    ~CAlley() {}
    CAlley(CAlley &) :m_pTop(0), mSize(0), mMaxSize(MAXSIZE) { }
    int Park(int); // park a car
    bool Retrieve(int userTicketNum, CAlley *pB); // retrieve a car
    void Display(string *displayText); // display contents af alley
private:
    void SetTop(CarNode *p){ m_pTop = p; } // assign top pointer
    // check if stack is empty
    bool Empty(){ return ((mSize == 0) ? true : false); }
    // check if stack is full
    bool Full() { return ((mSize == MAXSIZE) ? true : false); }
    int Push(CarNode *); // push one node onto top of stack
    CarNode * Pop(); // pop one node from the top of stack
    CarNode *m_pTop; // pointer to top of Allay (stack)
    
    int mSize; // number of nodes in Allay (stack)
    int mMaxSize;
};
