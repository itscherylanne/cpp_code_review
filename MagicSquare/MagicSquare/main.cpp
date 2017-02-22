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
/*     Assignment Number: 1                                                 */
/*                                                                          */
/*      Filename: main.cpp                                                  */
/*                                                                          */
/*      Date: July 9, 2014                                                  */
/*      Comments:  Developed in Windows Visual Studio 2013                  */
/*                 Tested in Visual Studio                                  */
/****************************************************************************/
/* MAGIC SQUARE - An NxN matrix containing values from 1 to N*N that are  */
/* ordered so that the sum of the rows, columns, and the major diagonals  */
/* are all equal.  There is a particular algorithm for odd integers, and  */
/* this program constructs that matrix, up to 13 rows and columns.  This   */
/* program also adds the sums of the row, columns, and major diagonals.   */

/****************************************************************************/
/*                          preprocessor derivatives                        */
/****************************************************************************/
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

/****************************************************************************/
/*                         Class Definition                                 */
/****************************************************************************/
class MagicSquare{
    
private:
    
    int m_input;           /* User defined integer       */
    int **m_loc;           /* Array holding all          */
    /*  input*input values.       */
    int m_row;             /* Determines row of matrix   */
    int m_col;             /* Determines col of matrix   */
    int m_value;             /* Integer between 1 and      */
    /*  input*input               */
    int m_otherdiag;        /* Total of one matrix diagonal*/
    
    
    void AllocateLoc();
    void DeallocateLoc();
    
    void PrintIntro();
    void PrintEntryPrompt();
    void InitializeMatrix();
    void PositionValuesInMatrix();
    void PrintMatrixWithTotals();
    void PrintColumnTotals();
    void PrintOutro();
    
public:
    /* Constructors and Destructors*/
    MagicSquare();
    ~MagicSquare();
    
    void Create();
    
    
};

/****************************************************************************/
/*                        Class  function prototypes                        */
/****************************************************************************/
/*Class Constructor*/
MagicSquare::MagicSquare()
{
    AllocateLoc();
}

/*Class Destructor*/
MagicSquare::~MagicSquare()
{
    DeallocateLoc();
}

void MagicSquare::AllocateLoc()
{
    /*allocate memory for m_loc*/
    m_loc = new int*[14];
    
    for (int i = 0; i < 14; i++)
        m_loc[i] = new int[14];
}

void MagicSquare::DeallocateLoc()
{
    /*deallocate memory for m_loc*/
    for (int i = 0; i < 14; i++)
        delete[] m_loc[i];
    
    delete[] m_loc;
}

void MagicSquare::Create()
{
    PrintIntro();
    PrintEntryPrompt();
    
    while (cin >> m_input)
    {
        /*                                                                        */
        /*    If input = -1, then exit program.                                   */
        /*                                                                        */
        if (m_input == -1)
            break;
        /*                                                                        */
        /*    Validity check for input: Must be a positive odd integer < 13.      */
        /*                                                                        */
        if (m_input <= 0)
        {
            cout << "Sorry, but the integer has to be positive." << endl;
            cout << endl << "Enter a positive, odd integer (-1 to exit program):" << endl;
            continue;
        }
        if (m_input > 13)
        {
            cout << "Sorry, but the integer has to be less than 15." << endl;
            cout << "Enter a positive, odd integer (-1 to exit program):" << endl;
            continue;
        }
        if (m_input % 2 == 0)
        {
            cout << "Sorry, but the integer has to be odd." << endl;
            cout << "Enter a positive, odd integer (-1 to exit program):" << endl;
            continue;
        }
        
        InitializeMatrix();
        PositionValuesInMatrix();
        PrintMatrixWithTotals();
        PrintColumnTotals();
        PrintEntryPrompt();
    }
    
    PrintOutro();
}


void MagicSquare::PrintIntro()
{
    /*                                                                        */
    /* Print introduction of what this program is all about.                  */
    /*                                                                        */
    
    cout << endl;
    cout << "Magic Squares: This program produces an NxN matrix where " << endl;
    cout << "N is some positive odd integer.  The matrix contains the " << endl;
    cout << "values 1 to N*N.  The sum of each row, each column, and " << endl;
    cout << "the two main diagonals are all equal.  Not only does this " << endl;
    cout << "program produces the matrix, it also computes the totals for" << endl;
    cout << "each row, column, and two main diagonals." << endl;
    
    cout << endl;
    cout << "Because of display constraints, this program can work with" << endl;
    cout << "values up to 13 only." << endl;
}

void MagicSquare::PrintEntryPrompt()
{
    cout << endl;
    cout << "Enter a positive, odd integer (-1 to exit program):" << endl;
}

void MagicSquare::InitializeMatrix()
{
    /*                                                                        */
    /*    Initialize matrix, row, col, and otherdiag                          */
    /*                                                                        */
    for (m_row = 0; m_row <= m_input; m_row++)  /* Initialize matrix with     */
        for (m_col = 0; m_col <= m_input; m_col++)  /*  all zeroes.               */
            m_loc[m_row][m_col] = 0;                /* Values will reside within  */
    /*  rows 1 to input*input and */
    /*  columns 1 to input*input. */
    /* Row totals will reside in  */
    /*  loc[row][0], where row is */
    /*  the row number, while the */
    /*  column totals will reside */
    /*  in loc[0][col], where col */
    /*  is the column number.     */
}

void MagicSquare::PositionValuesInMatrix()
{
    m_row = 1;                                  /* First value gets to sit on */
    m_col = m_input / 2 + 1;                    /*  1st row, middle of matrix.*/
    m_otherdiag = 0;
    
    /*                                                                        */
    /*    Loop for every value up to input*input, and position value in matrix*/
    /*                                                                        */
    for (m_value = 1; m_value <= m_input*m_input; m_value++)
    {                                           /* Loop for all values.       */
        if (m_loc[m_row][m_col] > 0)            /* If some value already      */
        {                                       /*  present, then             */
            m_row += 2;                         /*  move down 1 row of prev.  */
            if (m_row > m_input)                /*  If exceeds side, then     */
                m_row -= m_input;               /*   go to other side.        */
            
            m_col--;                            /*  move left 1 column.       */
            if (m_col < 1)                      /*  If exceeds side, then     */
                m_col = m_input;                /*   go to other side.        */
        }
        
        m_loc[m_row][m_col] = m_value;         /* Assign value to location.  */
        
        /*                                                                        */
        /*       Add to totals                                                    */
        /*                                                                        */
        m_loc[0][m_col] += m_value;                 /* Add to its column total.   */
        m_loc[m_row][0] += m_value;                 /* Add to its row total.      */
        if (m_row == m_col)                         /* Add to diagonal total if   */
            m_loc[0][0] += m_value;                 /*  it falls on the diagonal. */
        
        if (m_row + m_col == m_input + 1)           /* Add to other diagonal if   */
            m_otherdiag += m_value;                 /*  it falls on the line.     */
        
        /*                                                                        */
        /*       Determine where new row and col are                              */
        /*                                                                        */
        m_row--;
        if (m_row < 1)                             /* If row exceeds side then   */
            m_row = m_input;                       /*  goto other side.          */
        m_col++;
        if (m_col > m_input)                       /* If col exceeds side then   */
            m_col = 1;                             /*  goto other side.          */
    }
}

void MagicSquare::PrintMatrixWithTotals()
{
    /*                                                                        */
    /*    Print out the matrix with its totals                                */
    /*                                                                        */
    cout << endl << "The number you selected was " << m_input;
    cout << ", and the matrix is:" << endl << endl;
    for (m_row = 1; m_row <= m_input; m_row++)     /* Loop: print a row at a time*/
    {
        cout << "     ";                   /* Create column for diag.total*/
        for (m_col = 1; m_col <= m_input; m_col++)
            cout << setw(5) << m_loc[m_row][m_col];    /* Print values found in a row*/
        cout << " = " << setw(5) << m_loc[m_row][0] << endl;    /* Print total of row.        */
    }
}

void MagicSquare::PrintColumnTotals()
{
    
    /*                                                                        */
    /*    Print out the totals for each column, starting with diagonal total. */
    /*                                                                        */
    for (m_col = 0; m_col <= m_input; m_col++)     /* Print line separating the  */
        cout << "-----";                          /*  value matrix and col totals*/
    cout << endl << setw(5) << m_otherdiag;       /* Print out the diagonal total*/
    for (m_col = 1; m_col <= m_input; m_col++)
        cout << setw(5) << m_loc[0][m_col];       /* Print out the column totals*/
    cout << "   " << setw(5) << m_loc[0][0];      /* Print out the other diagonal*/
    /*  total                     */
    cout << endl;
}

void MagicSquare::PrintOutro()
{
    cout << endl;
    cout << "Bye bye!" << endl;
}



/****************************************************************************/
/*                        Main - Program Entry                              */
/****************************************************************************/
int main()
{
    MagicSquare magic_square;
    
    magic_square.Create();
    
    return 0;
}
