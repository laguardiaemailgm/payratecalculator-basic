
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;

void zeroFill(float* , int );                       //Set Values inside array to Zero
void mpgPerGallon(float* , float* , float* , int ); //Calculate mpgPerGallon
void inputMiles_Gallons(float* , float* , int );    //Input Miles and Gallons
void display_mpgPerGallon(float* , float* , float* , int );//Display mpgPerGallon


int main()
{
    static const int NUMITEMS = 10;//Number of items
    //Declare Variables
    float *miles, *gallons, *mpg;
    miles = new float[NUMITEMS];
    gallons = new float[NUMITEMS];
    mpg = new float[NUMITEMS];

    //Zero Fill ararys
    zeroFill(miles,NUMITEMS);
    zeroFill(gallons,NUMITEMS);
    zeroFill(mpg,NUMITEMS);

    //Input Miles and Gallons;
    inputMiles_Gallons(miles, gallons,  NUMITEMS);

    //calculate Miles per gallon
    mpgPerGallon(miles, gallons, mpg, NUMITEMS);

    cout<<"Output------------------------------------------------Output";

    //Display Miles Per Gallons;
    display_mpgPerGallon(miles, gallons, mpg, NUMITEMS);


    //De-alloc arrays
    delete[] miles;
    delete[] gallons;
    delete[] mpg;

    return 0;
}
//Calculate mpgPerGallon
void mpgPerGallon(float* miles, float* gallons, float* mpg, int NUMITEMS)
{
    for(int i = 0 ; i < NUMITEMS ; i++)
    {
        mpg[i] = miles[i]/gallons[i];
    }
}

//Set Values inside array to Zero
void zeroFill(float* var, int NUMITEMS)
{
    for(int i = 0 ; i < NUMITEMS ; i++)
    {
        var[i] = 0;
    }
}
//Input Miles and Gallons
void inputMiles_Gallons(float* miles, float* gallons, int NUMITEMS)
{
    cout<<"\nInput Miles and Gallons in this format: <miles> <gallons>";
    cout<<"\nsample: 15 15";

    for(int i = 0 ; i < NUMITEMS ; i++)
    {
        cout<<"\nInput: ";
        cin>>miles[i]>>gallons[i];
    }
}

//Display mpgPerGallon
void display_mpgPerGallon(float* miles, float* gallons, float* mpg, int NUMITEMS)
{
    for(int i = 0 ; i < NUMITEMS ; i++)
    {
        cout<<"\n"<<miles[i]<<" miles / "<<gallons[i]<<" gallons"<<" is equal to "<<mpg[i]<<" Miles per Gallon";
    }
}
