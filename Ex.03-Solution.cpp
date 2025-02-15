/*
  Programmer    : Adi Zejnilovic
  Date          : 02/25/2014
  Description   : This program asks the user to
                  enter a the user to enter the number of 
                  students in his/her class and then calculates 
                  and displays number of A�s, B�s, C�s, D�s, and 
                  F�s for the entire class. Each student is graded 
                  on the:
                         * 10 programming Exercises (progEx)
                         *  1 Midterm (midTerm)
                         *  1 Final Exam (final)
                  For each student, random number generator is used to 
                  generate scores for each category. 
                  Student grade is calculated using the following formula:
                  numericGrade = (progEx Average *.70) + 
                                 (midTerm *.15) +
                                 (final *.15)
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    const int HIGH = 100;       // max range for grade
    const int LOW = 0;          // min range for grade
    const int NUM_PROG_EX = 10; // max number of programming exercises
    
    // grade weights
    const double PROG_EX_WEIGHT = 0.70;
    const double MTE_WEIGHT = 0.15;
    const double FINAL_EXAM_WEIGHT = 0.15;
    
    int numStudents;     // to hold number of students in the class
    int progEx;          // to hold the score for a programming exercise 
    int progExSum;       // accumulator to hold the sum of all programming
                         // exercises
    double progExAvg;    // to hold calculated average for prog. exercises
    int    midTermExam;  // to hold the midterm exam score
    int    finalExam;    // to hold the final exam score
    int    countF=0,     // number of F's (counter)
           countD=0,     // number of D's (counter)
           countC=0,     // number of C's (counter)
           countB=0,     // number of B's (counter)
           countA=0;     // number of A's (counter)
    double grade;        // to hold calculated grade       
    
    cout << "Enter the number of students in your class: ";
    cin >> numStudents;
    
    // Get the system time
    unsigned seed= time(0);
    
    // seed the random number generator
    srand(seed);
        
    for (int student=0; student<numStudents; student++)
    {  
        // get the 10 programming Exercises
        for (int exercise=0; exercise<NUM_PROG_EX; exercise++)
        {
            progEx = rand()%(HIGH-LOW+1);
            progExSum += progEx;
        }
        
        // Calculate the progEx Average
        progExAvg = static_cast<double>(progExSum)/NUM_PROG_EX;
        
        // get the midterm grade
        midTermExam = rand()%(HIGH-LOW+1);
        
        // get the final exam grade
        finalExam = rand()%(HIGH-LOW+1);
        
        // calculate the grade
        grade = (progExAvg * PROG_EX_WEIGHT) +
                (midTermExam * MTE_WEIGHT) +
                (finalExam * FINAL_EXAM_WEIGHT);
                
        // Count number of letter grades
        if (grade >=0 && grade <=59)
           countF++;
        else if (grade >=60 && grade <= 69)
           countD++;   
        else if (grade >=70 && grade <= 79)
           countC++;
        else if (grade >=80 && grade <= 89)
           countB++;
        else if (grade >=90 && grade <=100)
           countA++;  
                      
        // reset the sum for another student              
        progExSum = 0;       
    }
    
    // display
    cout << " Number of students who received each letter grade: " << endl;
    cout << right << setw(6) << countA  << setw(3) << 'A' << endl;
    cout << setw(6) << countB  << setw(3) << 'B' << endl;
    cout << setw(6) << countC  << setw(3) << 'C' << endl;
    cout << setw(6) << countD  << setw(3) << 'D' << endl;
    cout << setw(6) << countF  << setw(3) << 'F' << endl;        
    system("PAUSE");
    return EXIT_SUCCESS;
}
