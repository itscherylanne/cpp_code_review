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
/*      Filename: ParkingLot.cpp                                            */
/*                                                                          */
/*      Date: July 29, 2014                                                  */
/*      Comments:  Developed in Windows Visual Studio 2013                  */
/*                 Tested in Visual Studio                                  */
/****************************************************************************/
/* CParkingLot - Class that defines the objects and methods of a parking lot*/
/****************************************************************************/
/*                          preprocessor derivatives                        */
/****************************************************************************/
#include "ParkingLot.hpp"
#include <iostream>

#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////
// Function: CParkingLot::Park()
// Purpose: Wrapper for parking a car in AlleyA. Handles display
// text regarding if car is parked (ticked number) if it fails
// to park.
//
// Parameters:
// (none)
//
// Local Variables:
// carParked - retrieves status if car can be parked in AlleyA
///////////////////////////////////////////////////////////////
void CParkingLot::Park()
{
    
    int carParked = AlleyA.Park(m_ticketNumber);
    
    if (carParked == 1)
    {
        cout << "Ticket no. = " << m_ticketNumber << endl << endl;
        m_ticketNumber++; //increment ticket number if successful
    }
    else
    {
        cout << "PARKING LOT FULL." << endl;
    }
    
    
}

///////////////////////////////////////////////////////////////
// Function: CParkingLot::Retrieve(int userTicketNumber)
// Purpose: Wrapper for retrieving a car from AlleyA. Provides
// status text if car does not exist in lot
//
// Parameters:
// userTicketNumber - ticket number of node to be retrieved
//
// Local Variables:
// foundCar - boolean reporting if car can be retrieved from lot
///////////////////////////////////////////////////////////////
void CParkingLot::Retrieve(int userTicketNumber)
{
    bool foundCar = AlleyA.Retrieve(userTicketNumber, &AlleyB);
    
    if ( !foundCar )
        cout << "CAR NOT PARKED IN MY LOT." << endl << endl;
}

///////////////////////////////////////////////////////////////
// Function: CParkingLot::Display()
// Purpose: Grabs status text from AlleyA and prints text to
// console
//
// Parameters:
// (none)
//
// Local Variables:
// displayText - string to be populated by AlleyA.Display method
///////////////////////////////////////////////////////////////
void CParkingLot::Display()
{
    string displayText;
    
    AlleyA.Display(&displayText);
    
    cout << "Alley A:" << displayText.c_str() << endl << endl;
}
