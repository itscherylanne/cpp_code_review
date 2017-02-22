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
/*     Assignment Number: 3                                                 */
/*                                                                          */
/*      Filename: CComprehensive_Assignment3_Estacio.cpp                    */
/*                                                                          */
/*      Date: August 18, 2014                                               */
/*      Comments:  Developed in Windows Visual Studio 2010                  */
/*                 Tested in Visual Studio                                  */
/****************************************************************************/
/* Employee Database - This program manages an employee database in a linked*/
/*  list. Each entry requires an employee name, age and salary. The data is */
/*  initialized from a semicolon delimited input file. This input file must be*/
/* specified as a command line input argument. Data entered into the linked list*/
/* will be inputed in a sorted order. The user will have the option to add entries,*/
/* delete entries, search for an employee, list all employees, save the list,*/
/* and exit the program                                                    */

/*******************************************************************
 *   Includes                                                       *
 ********************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/*******************************************************************
 *      User Option Enumeration                                     *
 ********************************************************************/
enum UserOptions
{
    AddEmployee = 1,
    DeleteEmployee,
    SearchEmployee,
    ListAllEmployees,
    SaveEmployeeDatabase,
    ExitEmployeeDatabase
};

/*******************************************************************
 *      Funcition Declarations                                      *
 ********************************************************************/
void PrintProgramIntroduction();     // Prints program introduction
void PrintUserPrompt();              // Prints user prompt
bool CompareNamesAlphabetically(char *nameA, char *nameB); //determines if nameB goes in front of nameA
bool MatchNamesNoCase( char* nameA, char* nameB); //determines if names match (regardless of case)
void GetName( string* name);

/********************************************************************
 *   CLASS NAME: CEmployee                                           *
 *   PURPOSE:
 *
 *   MEMBER FUNCTIONS:                                               *
 *     void Open (CEmployee *&pHeadPtr, char* filename );
 *     void AddEmp (CEmployee *&pHeadPtr, char *name, int age, int salary );
 *     void AddEmpUI (CEmployee *&pHeadPtr );
 *     void DeleteEmp (CEmployee *&pHeadPtr);
 *     void SearchEmp (CEmployee *pHeadPtr);
 *     void ListAllEmp (CEmployee *&pHeadPtr);
 *     void SaveToFile (CEmployee *&pHeadPtr);
 *     void ExitProg (CEmployee *pHeadPtr);                           *
 **********************************************************************/
class CEmployee {
public:
    bool Open (CEmployee *&pHeadPtr, char *filename);    //populates employee linked list with specified filename
    void AddEmpUI(CEmployee *&pHeadPtr );                //adds employee information via command prompt
    void DeleteEmp (CEmployee *&pHeadPtr);               //deletes employee from linked list
    void SearchEmp (CEmployee *pHeadPtr);                //search for employee
    void ListAllEmp (CEmployee *&pHeadPtr);              //prints out all employee in database
    void SaveToFile (CEmployee *&pHeadPtr, char* filename ); //saves database to file
    void ExitProg (CEmployee *pHeadPtr);                 //deletes employee linked list when exiting program
    
private:
    void AddEmp (CEmployee *&pHeadPtr, char *name, int age, int salary ); //adds employee to linked list in sorted order
    bool EmpInDatabase( CEmployee *pHeadPtr,char* empName);    //verifies if employee name exists in database
    
    
    char m_Name [20];			//name of employee
    unsigned int m_Age;        //age of employee
    unsigned int m_Salary;     //salary of employee
    CEmployee *m_pLink;		//location of previous node
};

/********************************************************************
 *   FUNCTION: main                                                  *
 *   PURPOSE: Program Entry                                          *
 *   PARAMETERS: argc, argv                                          *
 ********************************************************************/
int main( int argc, char* argv[])
{
    CEmployee* employeeDatabase = new CEmployee;
    CEmployee* nextEmployeeEntry;
    
    PrintProgramIntroduction();
    
    //read in file name as input argument
    if( argc != 2 )
    {
        cout << "Usage: Executable <filename>\n";
        return 1;
    }
    
    //if file cannot successfully open, exit
    if( !employeeDatabase->Open( employeeDatabase, argv[1] )) {
        cout << "Cannot open file " << argv[1] << endl;
        return 2;
    }
    
    
    
    //UserPrompt();
    bool quitProgram = false;
    while( !quitProgram )
    {
        int UserOption = 0;
        
        //prompt user
        PrintUserPrompt();
        cin >> UserOption;
        cin.ignore();
        switch( UserOption )
        {
            case AddEmployee:
                employeeDatabase->AddEmpUI( employeeDatabase );
                break;
            case DeleteEmployee:
                employeeDatabase->DeleteEmp( employeeDatabase );
                break;
            case SearchEmployee:
                employeeDatabase->SearchEmp( employeeDatabase);
                break;
            case ListAllEmployees:
                employeeDatabase->ListAllEmp( employeeDatabase);
                break;
            case SaveEmployeeDatabase:
                employeeDatabase->SaveToFile( employeeDatabase, argv[1]);
                break;
            case ExitEmployeeDatabase:
                employeeDatabase->ExitProg( employeeDatabase);
                quitProgram = true;
                break;
            default:
                cout << "Option not recognized. Please try again. " <<endl;
                break;
        }
        
    }
    
    cout << "Exiting program." << endl;
    
    return 0;
}


/********************************************************************
 *   FUNCTION: PrintProgramIntroduction                              *
 *   PURPOSE: Prints program introduction dialogue                   *
 *   PARAMETERS: none                                                *
 ********************************************************************/
void PrintProgramIntroduction()
{
    cout << "Employee database program will load an existing database "<< endl;
    cout << "from an input file. File is specified as a command line " <<endl;
    cout << "input argument. Program user may query the employee database " <<endl;
    cout << "based on employee name. In addition, database may be modified with"<< endl;
    cout << "the options of adding and deleting employee information. Database is" <<endl;
    cout << " self-sorting during insertion of new employee data. User has option" <<endl;
    cout << " of displaying all employee database information as well as saving" << endl;
    cout << "database to existing filename."<<endl;
}
/********************************************************************
 *   FUNCTION: PrintUserPrompt                                       *
 *   PURPOSE: Prints user options before prompting for user entry    *
 *   PARAMETERS: none                                                *
 ********************************************************************/
void PrintUserPrompt()
{
    cout << "Menu Options:" << endl;
    cout << "   " << AddEmployee << ". Add Employee" <<endl;
    cout << "   " << DeleteEmployee << ". Delete Employee" <<endl;
    cout << "   " << SearchEmployee << ". Search Employee" <<endl;
    cout << "   " << ListAllEmployees<< ". List All Employees" <<endl;
    cout << "   " << SaveEmployeeDatabase<< ". Save Employee Database" <<endl;
    cout << "   " << ExitEmployeeDatabase<< ". Exit Employee Database" <<endl;
    cout << "Enter Your Choice: ";
}

/********************************************************************
 *   FUNCTION: CompareNamesAlphabetically                            *
 *   PURPOSE: Compares two character strings for alphabetical order  *
 *   PARAMETERS: nameA, nameB                                        *
 *   LOCAL: lenA, lenB, shortestLen                                  *
 *   return - true if nameB falls before nameA alphabetically        *
 ********************************************************************/
bool CompareNamesAlphabetically( char *nameA, char *nameB )
{
    int lenA = strlen( nameA );
    int lenB = strlen( nameB );
    
    int shortestLen = (lenA < lenB ) ? lenA : lenB ; //find the shorter name
    for( int i = 0; i < shortestLen; i++)
    {
        if( tolower(nameA[i]) > tolower(nameB[i])) //nameB is before nameA in the alphabet
            return true;
        if( tolower(nameA[i]) < tolower(nameB[i]))
            return false;
    }
    
    return false;
}


/********************************************************************
 *   FUNCTION: MatchNamesNoCase                                      *
 *   PURPOSE: Checks to see if the two names are the same            *
 *   PARAMETERS: nameA, nameB                                        *
 *   LOCAL: lenA, lenB, shortestLen                                  *
 *   return - true if names match, false otherwise                   *
 ********************************************************************/
bool MatchNamesNoCase( char* nameA, char* nameB)
{
    int lenA = strlen( nameA );
    int lenB = strlen( nameB );
    
    
    if( lenA == lenB )
    {
        for( int i = 0; i < lenA; i++)
        {
            if( tolower(nameA[i]) != tolower(nameB[i])) //nameB is different from nameA
                return false;
        }
    }
    else
    {
        return false;
    }
    
    
    return true;
}

/********************************************************************
 *   FUNCTION: GetName                                               *
 *   PURPOSE: Uses command prompt for user to enter name             *
 *   PARAMETERS: name - string to be populated with name             *
 *   LOCAL: firstName, lastName                                      *
 ********************************************************************/
void GetName(string *name)
{
    string firstName;
    string lastName;
    
    cout << "Enter First Name: ";
    cin >> firstName;
    cin.ignore();
    cout << "Enter Last Name: ";
    cin >> lastName;
    cin.ignore();
    
    *(name) = firstName + " " + lastName;
}

/********************************************************************
 *   FUNCTION: Open                                                  *
 *   PURPOSE: opens specified file and loads employee information    *
 *   PARAMETERS: pHeadPtr, filename                                  *
 *   LOCAL VARIABLES: infile, Str, d, i, empName, age, salary        *
 ********************************************************************/
bool CEmployee::Open (CEmployee *&pHeadPtr, char* filename)
{
    // Open input file
    ifstream infile;
    infile.open(filename);
    //Check if input file exists
    if ( !infile ) {
        cout << "\nFile does not exist. Use Add and Save options to create file\n";
        return false;
    } //if
    char Str[80]; // string to be read from the file
    char d[] = ";"; //delimiter
    int i = 0;
    while (infile.getline(Str, 80)) {
        
        //variables to grab employee information
        char empName[20]; //employee name
        int age;          //employee age
        int salary;       //employee salary
        strcpy( empName,strtok(Str, d));
        age = atoi(strtok(NULL, d));
        salary = atoi(strtok(NULL, d));
        
        if( i == 0 ) //no employee information exists, populate first node
        {
            strcpy( pHeadPtr->m_Name, empName );
            pHeadPtr->m_Age = age;
            pHeadPtr->m_Salary = salary;
            pHeadPtr->m_pLink = NULL;
        }
        else
        {
            //add employee information to new node in linked list database
            AddEmp( pHeadPtr, empName, age, salary);
        }
        i++;
    } //while
    infile.close();
    cout << endl << i << " employee records are loaded from the data file into the link list" << endl;
    
    return true;
}
/***********************************************************************
 *   FUNCTION:  DeleteEmp                                               *
 *   PURPOSE:  Deletes employees from link list.                        *
 *   PARAMETERS:  pHeadPtr                                              *
 *   LOCAL VARIABLES: CurrPtr, LastPtr, Del_name, found                 *
 ***********************************************************************/
void CEmployee::DeleteEmp (CEmployee *&pHeadPtr)
{
    CEmployee* CurrPtr = pHeadPtr;
    CEmployee* LastPtr;
    string Del_name;
    //enter employee name to be deleted
    cout << endl;
    cout << "Enter name of employee to be deleted: "<<endl;
    GetName( &Del_name );
    
    bool found = false;
    //traverse list until name to be deleted matches employee name
    while( !found && CurrPtr != NULL)
    {
        if( MatchNamesNoCase( (char*)Del_name.c_str(), CurrPtr->m_Name) )
        {
            found = true;
            if( CurrPtr != pHeadPtr)
            {
                LastPtr->m_pLink = CurrPtr->m_pLink;
            }
            else //CurrPtr is the head of list
            {
                pHeadPtr = CurrPtr->m_pLink;
            }
            delete CurrPtr;
            
            cout << endl;
            cout << "Successfully deleted " << Del_name << " from database. " << endl;
            cout << endl;
        }
        else
        {
            // go to next node in linked list
            LastPtr = CurrPtr;
            CurrPtr = CurrPtr->m_pLink;
        }
        
    }
    
    if( !found )
    {
        cout << "Delete failed. User " << Del_name << " does not exist in database." <<endl;
        cout << endl;
    }
}
/***********************************************************************
 *   FUNCTION: SaveToFile                                               *
 *   PURPOSE: Saves link list data to input file, or user specified file*
 *   PARAMETERS: pHeadPtr, char* filename                               *
 *   LOCAL VARIABLES:  userInput, outputFilename                        *
 ***********************************************************************/
void CEmployee::SaveToFile (CEmployee *&pHeadPtr, char* filename )
{
    char userInput;
    cout << "Would you like to save file to " << filename << "? (Y/N)";
    cin >> userInput;
    
    string outputFilename;
    if( toupper( userInput) == 'Y' )
        outputFilename = filename;
    else
    {
        cout << "Enter Filename: ";
        cin >> outputFilename;
        cin.ignore();
    }
    
    //save file
    ofstream outFile( outputFilename);
    if( !outFile )
    {
        cout << "Cannot open outfile. Save failed." <<endl;
        return;
    }
    
    CEmployee* pCurrPtr = pHeadPtr;
    while( pCurrPtr )
    {
        outFile << pCurrPtr->m_Name << ";";
        outFile << pCurrPtr->m_Age << ";";
        outFile << pCurrPtr->m_Salary << endl;
        
        pCurrPtr = pCurrPtr->m_pLink;
    }
    
    outFile.close();
    
    cout << endl;
    cout << "File saved to " << outputFilename << endl;
    cout << endl;
}


/***********************************************************************
 *   FUNCTION: AddEmp                                                   *
 *   PURPOSE:  Adds emmployee to link list.                            *
 *   PARAMETERS:  pHeadPtr, name, age, salary                           *
 *   LOCAL VARIABLES:  LastEmployee, newEmployee, pCurrPtr              *
 ***********************************************************************/
void CEmployee::AddEmp (CEmployee *&pHeadPtr, char *name, int age, int salary )
{
    CEmployee* LastEmployee; //holds location of previous node for insert
    CEmployee* pCurrPtr = pHeadPtr;   //pointer to traverse linked list
    CEmployee* prevEmployee; //location of previous node in linked list
    CEmployee* newEmployee = (CEmployee*) new CEmployee; //new employee node
    
    //populate newEmployee with employee information
    strcpy(newEmployee->m_Name, name);
    newEmployee->m_Age = age;
    newEmployee->m_Salary = salary;
    newEmployee->m_pLink = NULL;
    
    
    while( pCurrPtr ) //go through the linked list and insert new employee in alphabetical order
    {
        bool insertNameInList = CompareNamesAlphabetically(pCurrPtr->m_Name, newEmployee->m_Name);
        if(  insertNameInList )
        {
            //insert node between two nodes in linked list
            LastEmployee = pCurrPtr; //employee at current pointer has name
            // that should be listed after new employee
            
            if( pCurrPtr == pHeadPtr)
            {
                pHeadPtr = newEmployee;
                newEmployee->m_pLink = pCurrPtr;
            }
            else
            {
                prevEmployee->m_pLink = newEmployee;
                newEmployee->m_pLink = pCurrPtr;
            }
            break;
        }
        else
        {
            if( !pCurrPtr->m_pLink ){ //if it is the end of the list
                pCurrPtr->m_pLink = newEmployee; //then append new employee node to the end of list
                break;
            }
            else
            {
                prevEmployee = pCurrPtr;
                pCurrPtr = pCurrPtr->m_pLink; // go to next node
            }
        }
        
        
    }
    
    
}

/***********************************************************************
 *   FUNCTION: AddEmpUI                                                 *
 *   PURPOSE:  Adds emmployee to link list. Grabs information from command prompt *
 *   PARAMETERS:  pHeadPtr                                              *
 *   LOCAL VARIABLES:  empName, age, salary                             *
 ***********************************************************************/
void CEmployee::AddEmpUI(CEmployee *&pHeadPtr )
{
    string empName; //input for employee name
    int age;        //input for employee age
    int salary;     //input for employee salary
    
    
    //populate employee information
    cout << endl;
    cout << "\nEnter Employee  Name: " << endl;
    GetName( &empName );
    
    //verify that name does not already exist in employee database
    //if it does, notify that name needs to be re-entered (suggest to include a middle initial)
    while( EmpInDatabase(pHeadPtr, (char*)empName.c_str()) || (empName == "") )
    {
        cout << "Invalid name. Please enter unique employee name." <<endl;
        cout << "\nEnter Employee  Name: ";
        GetName( &empName);
    }
    
    
    cout << "\nEnter Employee's Age: ";
    cin >> age;
    cin.ignore();
    while( age < 0 ) //error check for age
    {
        cout << "Age cannot be a negative number. Please enter a valid age." <<endl;
        cout << "Enter Employee's Age: ";
        cin >> age;
        cin.ignore();
    }
    
    cout << "\nEnter Employee's Salary: ";
    cin >> salary;
    cin.ignore();
    while( salary < 0 ) //error check for salary
    {
        cout << "Salary cannot be a negative number. Please enter a valid salary." <<endl;
        cout << "Enter Employee's Salary: ";
        cin >> salary;
        cin.ignore();
    }
    
    
    //add routine to add employee in alphabetical order
    //insert employee into linked list in sorted order
    AddEmp( pHeadPtr, (char*)empName.c_str(), age, salary);
    
    cout << endl;
    cout << "Successfully added " << empName << " to the database." << endl;
    cout << endl;
}
/********************************************************************
 *  FUNCTION: ExitProg
 * PURPOSE: Exits program and deletes memory spaces that were being
 *        used.
 *  PARAMETERS: pHeadNode
 *   LOCAL VARIABLES:  pCurr, pDeleteThisNode
 ***********************************************************************/
void CEmployee::ExitProg (CEmployee *pHeadNode)
{
    CEmployee *pCurr, *pDeleteThisNode;
    pCurr = pHeadNode;
    while ( pCurr != 0)
    {
        pDeleteThisNode = pCurr;
        pCurr = pCurr->m_pLink;
        delete pDeleteThisNode;
    }
}
/*********************************************************************
 *   FUNCTION:  ListAllEmp                                            *
 *   PURPOSE:  Lists all employees in link list to the screen.        *
 *   PARAMETER:  pHeadPtr                                             *
 *   LOCAL VARIABLES: count, numString, formatSalary, insertPosition  *
 **********************************************************************/
void CEmployee::ListAllEmp (CEmployee *&pHeadPtr)
{
    //print out headers
    //print out line
    cout << endl;
    cout << " #   Employee Name            Age      Salary" << endl;
    cout << "=============================================" <<endl;
    
    int count = 1;
    
    CEmployee* pCurrPtr = pHeadPtr;
    while( pCurrPtr )
    {
        //print out information
        cout << setw( 3 ) << right << count << "  "; //print out number
        cout << setw( 25 )<< left << pCurrPtr->m_Name << " "; //print out employee name
        cout << setw( 6 ) << left << pCurrPtr->m_Age << " "; //print out age
        //print out salary (with commas)
        char numString[32];
        sprintf( numString, "%i", pCurrPtr->m_Salary);
        string formatSalary = numString;
        unsigned long insertPosition = formatSalary.length() - 3;
        while (insertPosition > 0) {
            formatSalary.insert(insertPosition, ",");
            insertPosition-=3;
        }
        cout << setw( 7 ) << right <<  formatSalary << endl;
        count++;
        pCurrPtr = pCurrPtr->m_pLink;
    }
    cout <<endl;
}
/*********************************************************************
 *   FUNCTION:  SearchEmp                                             *
 *   PURPOSE:  Searches link list for specified employee.             *
 *   PARAMTERS:  pHeadPtr                                             *
 *   LOCAL VARIABLES: CurrPtr, Search_name, flag                      *
 **********************************************************************/
void CEmployee::SearchEmp (CEmployee *pHeadPtr)
{ 
    CEmployee* CurrPtr = pHeadPtr;
    string Search_name;
    bool flag = false;
    
    //enter name to be searched
    cout << endl;
    cout << "Please enter name of employee: "<<endl;
    GetName( &Search_name);
    
    //traverse list
    while( CurrPtr != NULL && !flag )
    {
        //print out information
        if( MatchNamesNoCase( (char*)Search_name.c_str(), CurrPtr->m_Name) )
        {
            cout << endl;
            cout << "Employee Name: "<< CurrPtr->m_Name << endl;
            cout << "Age: " << CurrPtr->m_Age <<endl;
            cout << "Salary: " << CurrPtr->m_Salary << endl;
            cout << endl;
            flag = true;
        }
        else
        {
            // go to next node in linked list
            CurrPtr = CurrPtr->m_pLink;
        }
    }
    
    if( !flag )
    {
        cout << "Employee does not exist in this database. " << endl;
        cout << endl;
    }
}
/*********************************************************************
 *   FUNCTION:  EmpInDatabase                                         *
 *   PURPOSE:  Searches link list for specified employee.             *
 *   PARAMTERS:  pHeadPtr, empName                                    *
 *   LOCAL VARIABLES: CurrPtr, Search_name, flag                      *
 *   RETURN: true if employee exists in database, false otherwise     *
 **********************************************************************/
bool CEmployee::EmpInDatabase(CEmployee *pHeadPtr, char* empName)
{ 
    CEmployee* CurrPtr = pHeadPtr;
    //traverse list
    while( CurrPtr != NULL )
    {
        //print out information
        if( MatchNamesNoCase( empName, CurrPtr->m_Name) )
        {
            return true;
        }
        else
        {
            // go to next node in linked list
            CurrPtr = CurrPtr->m_pLink;
        }
    }
    
    return false;
}
