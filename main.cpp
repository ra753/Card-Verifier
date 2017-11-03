//Written by- Abhishek Anand
//03/11/2017
//This program can be used to verify authenticity of a bank card either debit or credit
//It uses Luhn Mod 10 Algorithm to verify the card number

#include <iostream>
#include <conio.h>

using namespace  std;
void vendor(int cardi[]);
//Converts user input string to array
int * stringtoarray(string card)        //returns array using pointer
{
    static int cardi[15];
    for(int i=0;i<=15;i++)
    {
        cardi[i]=card[i]-'0';
    }
    //cout<<"\n "<<cardi;  //for printing the converted array
    return cardi;
}
/*string reverse(string cardrev) {
    int i = 0;
    int j = 15;
    char temp;
    while (i < j)
    {
        temp = cardrev[i];
        cardrev[i] = cardrev[j];
        cardrev[j] = temp;
        i++;
        j--;
    }

    cout << "\nReverse string is: " << cardrev;
    return cardrev;
}*/
//For checking genuiness

void checksum(int cardi[])
{
    int mul=0,sum_even=0,sum_odd=0,total;
    for(int i=0;i<=14;i++)
    {
        if(i%2==0)  //if even place is encountered
        {
            mul=cardi[i]*2;
            {
                if(mul>9)
                {
                    mul=mul-9;

                }
            }
            //cout<<"  "<<mul<<"  i="<<i;       //for testing the multiplier
            sum_even=sum_even+mul;
        }
        else                //if even place is encountered
            sum_odd=sum_odd+cardi[i];
    }
    total=sum_odd+sum_even+cardi[15];
    /*cout<<"\n"<<sum_even;
    cout<<"\n"<<sum_odd;        //for checking if sum is correct
    cout<<"\n"<<total;*/

    //Checking of Geniuneness

    if(total%10==0)
    {
        cout<<"\n\nCARD IS VALID\n";
        vendor(cardi);
    }
    else
        cout<<"\nCARD INVALID\n";

}

void vendor(int cardi[])
{
    cout<<"\nCARD DETAILS\n";
    {
        //for industry type
        if (cardi[0] == 1 || cardi[0] == 2) {
            cout << "Type: Arline";
        }
        if (cardi[0] == 4 || cardi[0] == 5) {
            cout << "Type: Banking and Financial\n";
        }

        if(cardi[0]==6)
        {
            cout<<"Type: Merchandising and Banking/Financial\n";
        }
        //else
          //  cout << "Unknown Type";
    }
    //Issuer
    {
        if (cardi[0] == 4) {
            cout << "Card Issuer: Visa";
        }
        else if (cardi[0] == 5 && cardi[1] == 1 || cardi[0] == 5 && cardi[1] == 2) {
            cout << "Card Issuer: Mastercard";
        }
        else if(cardi[0]==3&&cardi[1]==4||cardi[0]==3&&cardi[1]==7)
        {
            cout<<"Card Issuer: American Express";
        }
        else if(cardi[0]==6&&cardi[1]==0&&cardi[2]==1&&cardi[3]==1 || cardi[0]==6&&cardi[1]==4&&cardi[2]==4 || cardi[0]==6&&cardi[1]==5)
        {
            cout<<"Card Issuer: Discover";
        }
        else if(cardi[0]==6&&cardi[1]==2) {
            cout << "Card Issuer: Maestro";
        }
        else if(cardi[0]==6&&cardi[1]==0)
        {
            cout<<"Card Issuer: RuPay";
        }
        else
            cout<<"Issuer: Unknown";
    }
}

int main()
{
    string card="";
    int *ptr; //pointer to point to the returned array
    cout<<"Enter the Card Number\n";
    cin>>card;
    if(card.size()!=16)
    {
        cout<<"Entered number not of 16 digits\nPlease Note:\n A card number is always of 16 digits";
    }
    else
    cout<<"The Entered Number is:"<<card;

    //string cardrev=reverse(card);         //reversing the string (no need)
    ptr= stringtoarray(card);

    /*cout<<"\nOutput of string to array:\n";
    for(int i=0;i<=15;i++)
    {
        cout<<" "<<ptr[i];
    }
    cout<<"\n";*/

    checksum(ptr);
    //cout<<"\n"<<ptr;              //prints the address of the pointer pointing to the array
    getch();
    return 0;



}