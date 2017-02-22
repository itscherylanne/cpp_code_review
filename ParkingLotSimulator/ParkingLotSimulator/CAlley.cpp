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
/*      Filename: CAlley.cpp                                                */
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
#include "CAlley.hpp"

////////////////////////////////////////////////////////////////
// Function: CAlley::Push
// Purpose: Add a new node to top of stack
// Parameters:
// CarNode * pNewNode- the node to be added to top of stack
// Local Variables:
// status - return 1 if pushed sucessfully
// - return 0 if stack was full
////////////////////////////////////////////////////////////////
int CAlley::Push(CarNode* pNewNode)
{
    if(this->Full())
        return 0;
    else
    {
        //currently top of lot is memory location of the last
        //parked car. the next location of this new car is the
        //current top location
        pNewNode->SetNext(m_pTop);
        
        //increment number of car/nodes in Alley
        mSize++;
        
        //the new top location is this new car
        this->SetTop(pNewNode);
    }
    
    return 1;
}
/////////////////////////////////////////////////////////////////
// Function: CAlley::Pop
// Purpose: Remove a node to top of Alley (stack).
// Parameters:
// CarNode * pNewNode- returns the node removed from top of Alley
// is zero if stack is empty
// Local Variables:
/////////////////////////////////////////////////////////////////
CarNode * CAlley::Pop()
{
    CarNode *pNewNode;
    if (this->Empty())
        return 0;
    else
    {
        //grab the location of the top node
        pNewNode = m_pTop;
        
        //replace the top with the next location
        this->SetTop(pNewNode->GetNext());
        
        //decrement number of cars in alley
        mSize--;
    }
    
    return pNewNode;
}
///////////////////////////////////////////////////////////////
// Function: CAlley::Park ( )
// Purpose: Park a car, if lot is not full. First allocate a
// node, then add it to the top of the stack
// Parameters:
// userTicketNum - the ticket number for the node to be added
// Local Variables:
// CarNode *pNewNode - local pointer to newly allocated node
// int status - 1 if parked sucessfully (lot not full)
// 0 if not parked (lot was full)
///////////////////////////////////////////////////////////////
int CAlley::Park(int userTicketNum)
{
    int status = 0;
    CarNode *pNewNode = new CarNode; //create a new car to park
    
    pNewNode->SetTicketNum(userTicketNum); //assign ticket number to car
    status = this->Push(pNewNode); //park car in alley
    
    return status;
}
///////////////////////////////////////////////////////////////
// Function: CAlley::Retrieve ( int userTicketNum, CAlley *pB)
// Purpose: Retrieve a car from alley A. Search for the car/node
// based on ticket num. by driving a car (popping off top) out of
// A and driving (pushing onto top) into B.
// If the car is found, it is not pushed onto B, but rather,
// it is deleted. Then the cars in B are moved back into A.
//
// Parameters:
// userTicketNum - the ticket number for the node to be retrieved
// pB - pointer to CAlley B
//
// Local Variables:
// CarNode *pCurr - local pointer used as index
// bool found - true if car is found, false if not found
///////////////////////////////////////////////////////////////
bool CAlley::Retrieve(int userTicketNum, CAlley *pB)
{
    CarNode *pCurr;
    bool found = false;
    //scan through Alley A
    while (!this->Empty() && (!found))
    {
        pCurr = this->Pop();
        
        //if ticket number matches, leave loop
        if (userTicketNum == pCurr->GetTicketNum())
        {
            found = 1;
        }
        else//else push car into Alley B
        {
            pB->Push(pCurr);
        }
    }
    
    //once you finish searching Alley A
    //then move all cars in Alley B back into Alley A
    while (!pB->Empty())
    {
        this->Push(pB->Pop());
    }
    
    return found;
}
///////////////////////////////////////////////////////////////
// Function: CAlley::Display ( string *displayText )
// Purpose: Generates text for displaying contents of alley
//
// Parameters:
// displayText - string to be populated for display text
//
// Local Variables:
// pCurr - local pointer used as index
// sspace - local string containing space character used as a
//          delimiter
///////////////////////////////////////////////////////////////
void CAlley::Display(string *displayText)
{
    CarNode *pCurr = m_pTop;
    string sspace = " ";
    
    displayText->clear();
    
    //traverse the stack and print locations into character array
    for (int i = 0; i < mSize; i++)
    {
        displayText[0] += to_string(pCurr->GetTicketNum()) + sspace;
        pCurr = pCurr->GetNext();
    }
}
