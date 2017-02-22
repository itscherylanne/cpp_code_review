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
/*      Filename: main.cpp                                                  */
/*                                                                          */
/*      Date: July 29, 2014                                                  */
/*      Comments:  Developed in Windows Visual Studio 2013                  */
/*                 Tested in Visual Studio                                  */
/****************************************************************************/
/* PARKING LOT SIMULATION - Simulates a parking lot that consists of two  */
/* alleyways (Alley A and Alley B) that are five cars wide. Cars will be  */
/* parked in Alley A and Alley B will be used to temporary hold cars that */
/* are blocking the car that needs to be retrieved.   */

/****************************************************************************/
/*                          preprocessor derivatives                        */
/****************************************************************************/

#include "ParkingLot.hpp"
#include <iostream>

using namespace std;

/****************************************************************************/
/*                        Function Prototypes                               */
/****************************************************************************/
void ReadTicketNumber(int &outNumber);  //User prompt for ticket number for retrieving a car
void ReadCommandInput(char &outCommand); //User prompt for commands available in parking lot simulation

/****************************************************************************/
/*                        Main - Program Entry                              */
/****************************************************************************/
int main(int argc, char *argv[])
{
    CParkingLot parkingLot;
    char commandInput;
    int ticketNumber;
    bool run_program = true;
    
    while (run_program)
    {
        ReadCommandInput( commandInput);
        switch (commandInput)
        {
            case 'D':
                parkingLot.Display();
                break;
            case 'P':
                parkingLot.Park();
                break;
            case 'R':
                ReadTicketNumber(ticketNumber);
                parkingLot.Retrieve(ticketNumber);
                break;
            case 'Q':
                run_program = false;
                break;
            default:
                //quietly ignore unknown input commands
                break;
        }
    }
    
    return 0;
}
/****************************************************************************/
/*                        Function Definitions                              */
/****************************************************************************/

///////////////////////////////////////////////////////////////
// Function: ReadTicketNumber(int &outNumber)
// Purpose: User interface via console that prompts user to enter
//   ticket number of car to be retrieved.
//
// Parameters:
// outNumber - integer corresponding to car's ticket number to be
//             retrieved
//
// Local Variables:
// (none)
///////////////////////////////////////////////////////////////
void ReadTicketNumber(int &outNumber)
{
    cout << "Ticket no: ";
    cin >> outNumber;
    
}

///////////////////////////////////////////////////////////////
// Function: ReadCommandInput(char &outCommand)
// Purpose: User interface via console that prompts user to enter
//   a command to run a specific functionality in user simulation
//
// Parameters:
// outCommand - character output corresponding to user command
//             to run a specified function in parking lot simulation
//
// Local Variables:
// (none)
///////////////////////////////////////////////////////////////
void ReadCommandInput(char &outCommand)
{
    cout << "D)isplay" << "\t" << "P)ark" << "\t" << "R)etrieve" << "\t" << "Q)uit: ";
    cin >> outCommand;
    outCommand = toupper(outCommand);
}
