
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct employee{
    int number;
    string name;
    float payRate;
    int hours;
};

void readTxt(ifstream&,employee* );                     //Read String from File
void outputTxtandWritetoFile(employee* ,int );                        //Output to screen

int main()
{
    const int MAXNUMWORKERS = 128; //Max Number of Workers
    employee workers[MAXNUMWORKERS]; //Array of employees

    ifstream myFileRead; //source File
    string sourceFilename ;// Filenames

    cout<<"Enter Source File Name: ";
    getline(cin,sourceFilename);//Reads File Name from user

    //Open Source File
    myFileRead.open(sourceFilename.c_str());

    //Check if Source File Exist
    if (myFileRead.fail())
    {
        cout<<"\nThe file '"<<sourceFilename<<"' was not opened";

        exit(1);//close file
    }
    cout<<"\nDebug =>File has been succefully opened for reading";

    int empCounter = 0; //Employee Counter
    //Read Data From File
    //Store Data to Employee Array Struct
    while(myFileRead.good())
    {
        myFileRead >> workers[empCounter].number >> workers[empCounter].name
                   >> workers[empCounter].payRate >> workers[empCounter].hours;
        empCounter++;
    }

    outputTxtandWritetoFile(workers,empCounter);

//------------------------------------------------------------------------
    myFileRead.close();//Close File
    return 0;
}
void outputTxtandWritetoFile(employee* workers,int empCounter)
{
    //Salary
    float overTimePay = 0.0;
    float regularPay = 0.0;
    float grossPay = 0.0;

    //13 empty spaces
    string headingBuffer = "\nNumber       Name    PayRate    Hours    RegularPay    OvertimePay    GrossPay";
    string payReportBuffer = "";
    string destinationFilename; //Output FileName
    ofstream destination;

    cout<<"\nEnter Destination File Name: ";
    getline(cin,destinationFilename);//Reads File Name from user

    destination.open(destinationFilename.c_str());
    //Check if Destination File Exist
    if (destination.fail())
    {
        cout<<"\nThe file '"<<destinationFilename<<"' was not opened";

        exit(1);//close file
    }
    cout<<"\nDebug =>File has been succefully opened for Writing";

    //Write Heading to File
    destination << headingBuffer;

    //-----------------------------------------------------------------
    //Display Heading
    cout<<headingBuffer;
    for(int i = 0; i < empCounter ; i++)
    {
        if ( workers[i].hours <= 0 )
        {
            //RegularPay
            //OvertimePay
            //GrossPay
            //All Zero
        }
      else
      {
          //If Employee has worked more than 40 hours
         if ( workers[i].hours > 40 )
         {
            regularPay = workers[i].payRate*40;                             //Regular Pay Rate
            overTimePay = (workers[i].payRate*1.5)*(workers[i].hours-40) ; //Overtime PayRate

            //Gross PayRate
            grossPay = regularPay + overTimePay;
         }
         //If Employee has worked less than or equal to 40 hours
         else
         {
            regularPay = workers[i].hours*workers[i].payRate;   //Regular Pay Rate
            grossPay = regularPay + overTimePay;            //Gross PayRate
         }
      }


        //Write to File
        destination<<"\n"<<setw(4) << workers[i].number <<"     "
                  <<setw(8) << workers[i].name   <<"      "
                  <<setw(3) << workers[i].payRate<<"      "
                  <<setw(3) << workers[i].hours  <<"       "
                  <<setw(7) << regularPay        <<"       "
                  <<setw(6) << overTimePay       <<"       "
                  <<setw(6) << grossPay;

        //Display Employee info
        cout<<"\n"<<setw(4) << workers[i].number <<"     "
                  <<setw(8) << workers[i].name   <<"      "
                  <<setw(3) << workers[i].payRate<<"      "
                  <<setw(3) << workers[i].hours  <<"       "
                  <<setw(7) << regularPay        <<"       "
                  <<setw(6) << overTimePay       <<"       "
                  <<setw(6) << grossPay;

    //Reset Salaray Buffers
    overTimePay = 0.0;
    regularPay = 0.0;
    grossPay = 0.0;
    }
}
