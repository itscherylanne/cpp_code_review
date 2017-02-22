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
/*     Assignment Number: 4                                                 */
/*                                                                          */
/*      Filename: CPPComprehensive_Assignment4_Estacio.cpp                  */
/*                                                                          */
/*      Date: September 1, 2014                                             */
/*      Comments:  Developed in Windows Visual Studio 2010                  */
/*                 Tested in Visual Studio                                  */
/****************************************************************************/
/*  This program demonstrates the use of polymorphism                       */

/*******************************************************************
 *   Includes                                                       *
 ********************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

enum AirshipType {AIRPLANE,BALLOON};


/*******************************************************************
 *     AirshipFile - General structure to read in data              *
 ********************************************************************/
struct AirshipFile{
    int airshipType;		//specifies type of airship: airplane or balloon
    char *airshipName;		//name of airship
    int maxPassangerCount;	//maximum allowable number of passengers
    int maxCargoWeight;		//maximum amount of cargo weight in lbs
    int technologyType;		//generic specifier for airship. Airplane:Jet/Propeller, Balloon:Hydrogen/Helium
    int technologyCapacity; //generic specified for airship. Airplane:range, Balloon:altitude
};


/*******************************************************************
 *      Base Class Prototype                                         *
 ********************************************************************/
class CAirship{
public:
    CAirship(){}
    virtual void GetData(AirshipFile &data) = 0;
    virtual void ShowData() = 0;
    int GetAirshipType(){ return m_AirshipType;}
    
protected:
    int m_AirshipType;
    char m_AirshipName[20];
    int   m_MaxPassengerCount;
    int   m_MaxCargoWeight;
};
/*******************************************************************
 *      Airship Derived Class: Airplane Prototype                   *
 ********************************************************************/
class CAirplane : public CAirship{
public:
    CAirplane() : CAirship() {}
    void GetData( AirshipFile &data);
    void ShowData();
    
private:
    const char* SetEngineText(int type);
    
    int   m_EngineType;
    int   m_MaxRange;
};
/*******************************************************************
 *     Airplane Class Definitions                                   *
 ********************************************************************/
/********************************************************************
 *   FUNCTION: CAirplane::SetEngineText                              *
 *   PURPOSE: Returns text for Engine type for display purposes      *
 *   PARAMETERS: integer representing type                           *
 ********************************************************************/
const char* CAirplane::SetEngineText( int type )
{
    switch( type )
    {
        case 0:
            return "Jet";
            break;
        case 1:
            return "Propeller";
            break;
        default:
            return "Unknown";
            break;
    }
}
/********************************************************************
 *   FUNCTION: CAirplane::GetData                                     *
 *   PURPOSE: Stores information from generic data structure to      *
 *            class specific structure                               *
 *   PARAMETERS: Data structure containting airship data             *
 ********************************************************************/
void CAirplane::GetData( AirshipFile &data)
{
    m_AirshipType = data.airshipType;
    sprintf( m_AirshipName, "%s", data.airshipName);
    m_MaxPassengerCount = data.maxPassangerCount;
    m_MaxCargoWeight = data.maxCargoWeight;
    m_EngineType = data.technologyType;
    m_MaxRange = data.technologyCapacity;
}
/********************************************************************
 *   FUNCTION: CAirplane::ShowData()                                 *
 *   PURPOSE: Prints out information as specified by assignment      *
 *   PARAMETERS: integer representing type                           *
 ********************************************************************/
void CAirplane::ShowData()
{
    cout << setw(20) <<left << m_AirshipName;
    cout << setw(16) <<left << SetEngineText( m_EngineType );
    cout << setw(13) <<left << m_MaxRange << "\n";
}


/*******************************************************************
 *      Airship Derived Class: Balloon                               *         *
 ********************************************************************/
class CBalloon : public CAirship{
    //airshipType, balloonName, maxPassengerCount, maxCargoWeight, gasType, maxAltitude;
public:
    CBalloon() : CAirship() {}
    void GetData( AirshipFile &data);
    void ShowData();
    
private:
    const char* SetGasText( int type );
    
    int   m_GasType;
    int   m_MaxAltitude;
};
/*******************************************************************
 *     Balloon Class Definitions                                    *
 ********************************************************************/
/********************************************************************
 *   FUNCTION: CBalloon::SetGasText                                  *
 *   PURPOSE: Returns text for Gas type for display purposes         *
 *   PARAMETERS: integer representing type                           *
 ********************************************************************/
const char* CBalloon::SetGasText( int type )
{
    switch( type )
    {
        case 0:
            return "Helium";
            break;
        case 1:
            return "Hydrogen";
            break;
        default:
            return "Unknown";
            break;
    }
}
/********************************************************************
 *   FUNCTION: CBalloon::GetData                                     *
 *   PURPOSE: Stores information from generic data structure to      *
 *            class specific structure                               *
 *   PARAMETERS: Data structure containting airship data             *
 ********************************************************************/
void CBalloon::GetData( AirshipFile &data)
{
    m_AirshipType = data.airshipType;
    sprintf( m_AirshipName, "%s", data.airshipName);
    m_MaxPassengerCount = data.maxPassangerCount;
    m_MaxCargoWeight = data.maxCargoWeight;
    m_GasType = data.technologyType;
    m_MaxAltitude = data.technologyCapacity;
}
/********************************************************************
 *   FUNCTION: CBalloon::ShowData()                                  *
 *   PURPOSE: Prints out information as specified by assignment      *
 *   PARAMETERS: integer representing type                           *
 ********************************************************************/
void CBalloon::ShowData()
{
    cout << setw(20) << left << m_AirshipName;
    cout << setw(16) << left << SetGasText( m_GasType );
    cout << setw(13) << left << m_MaxAltitude << "\n";
}

/********************************************************************
 *   FUNCTION: main                                                  *
 *   PURPOSE: Program Entry                                          *
 *   PARAMETERS: argc, argv                                          *
 ********************************************************************/
int main( int argc, char* argv[])
{
    //parse command line argument for input filename
    if (argc != 2) {
        cout << "Usage: PR <filename>\n";
        return 1; }
    ifstream Infile(argv[1]);
    if (!Infile) {
        cout << "Cannot open file. Exiting program\n";
        return 1; }
    
    //read each line of input
    char LineBuf[100];
    char d[] = ",";
    CAirship *pAirshipFile[10];
    int i=0;
    while (Infile.getline(LineBuf, 100) && !Infile.eof()) {
        struct AirshipFile data;
        data.airshipType = atoi (strtok(LineBuf, d));
        //check airship type for data
        switch (data.airshipType) {
            case AIRPLANE:
                //create airplane
                pAirshipFile[i] = new CAirplane();
                data.airshipName = strtok(NULL, d);
                data.maxPassangerCount = atoi( strtok(NULL,d));
                data.maxCargoWeight = atoi( strtok( NULL, d));
                data.technologyType = atoi( strtok( NULL, d) );
                data.technologyCapacity = atoi( strtok( NULL, d) );
                break;
            case BALLOON:
                //create balooon
                pAirshipFile[i] = new CBalloon();
                data.airshipName = strtok(NULL, d);
                data.maxPassangerCount = atoi( strtok(NULL,d));
                data.maxCargoWeight = atoi( strtok( NULL, d));
                data.technologyType = atoi( strtok( NULL, d) );
                data.technologyCapacity = atoi( strtok( NULL, d) );
                break;
            default:
                break;
        } // end switch
        //place object in array of pointer type *airship
        pAirshipFile[i++]->GetData(data);
        memset(LineBuf,'\0',100);
    }
    cout <<"Succesfully loaded data from input file: "<< argv[1] <<endl <<endl;
    
    //iterate through array to generate airplane report
    cout << endl;
    cout << "Listing of all Airplanes\n";
    cout << "Name \t\tEngine Type\tMaximum Range\n";
    cout <<" ------------------------------------------------"<<endl;
    for (int i = 0; i < 10; i++) {
        if (pAirshipFile[i]->GetAirshipType() == AIRPLANE)
        {
            pAirshipFile[i]->ShowData();
        }
    }
    
    //iterate through array to generate balloon report
    cout << endl;
    cout << "Listing of all Balloons\n";
    cout << "Name \t\tGasType\tMaximum Altitude\n";
    cout <<" ------------------------------------------------"<<endl;
    for (int i = 0; i < 10; i++) {
        if (pAirshipFile[i]->GetAirshipType() == BALLOON)
        {
            pAirshipFile[i]->ShowData();
        }
    }
    
    
    //cleanup before exiting program
    Infile.close();
    for (int i = 0; i < 10; i++) {
        if (pAirshipFile[i])
            delete pAirshipFile[i];// Delete appropriate object
    } // end for loop
    return 0;
}
