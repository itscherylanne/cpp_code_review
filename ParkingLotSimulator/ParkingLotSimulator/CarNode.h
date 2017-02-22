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
/*      Filename: CarNode.h                                                 */
/*                                                                          */
/*      Date: July 29, 2014                                                  */
/*      Comments:  Developed in Windows Visual Studio 2013                  */
/*                 Tested in Visual Studio                                  */
/****************************************************************************/
/* CarNode - Class that defines the objects and methods of a car node (each*/
/*            node represents a car and is strung together in the alley by */
/*            a linked list */
/****************************************************************************/
/*                          preprocessor derivatives                        */
/****************************************************************************/

#define MAXSIZE 5

class CarNode {
public:
    CarNode() : m_pNext(0), m_ticketNum(0) { }
    ~CarNode();
    CarNode(CarNode &): m_pNext(0), m_ticketNum(0) { }
    // assign next pointer
    void SetNext(CarNode* p){ m_pNext = p; }
    // assign ticket number
    void SetTicketNum(int tN){ m_ticketNum = tN; }
    // get the next pointer
    CarNode *GetNext(void){ return(m_pNext); }
    // get the ticket number
    int GetTicketNum(void){ return(m_ticketNum); }
private:
    int m_ticketNum; // ticket number of car
    CarNode *m_pNext; // pointer to next node in stack
};
