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
/*      Filename: ParkingLot.h                                            */
/*                                                                          */
/*      Date: July 29, 2014                                                  */
/*      Comments:  Developed in Windows Visual Studio 2013                  */
/*                 Tested in Visual Studio                                  */
/****************************************************************************/
/* CParkingLot - Class that defines the objects and methods of a parking lot*/
/****************************************************************************/
/*                          preprocessor derivatives                        */
/****************************************************************************/
#include "CAlley.hpp"

class CParkingLot{
public:
    CParkingLot() : m_ticketNumber(1){ }		//constructor - empty parking lot, numbering system starts at 1
    ~CParkingLot(){}	//destructor
    
    void Park();		//park car into lot, will display ticket number at end of parking
    void Retrieve(int userTicketNumber);	//retrieve car from lot
    void Display();		//display cars in lot
    
private:
    
    unsigned int m_ticketNumber;	//ticket number counter for operation in parking lot
    
    //Parking lot consists of two alleys
    CAlley AlleyA;		//alley to park cars
    CAlley AlleyB;		//alley to move cars out of parked spot
};
