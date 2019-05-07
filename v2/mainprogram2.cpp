#include <iostream>   
#include <string>     
#include <fstream>    
#include <conio.h>    
#include <cctype>     
#include <windows.h>  
using namespace std;
void CheckBookingRecord();  
ofstream MYFILE;
string NewWorkerName;
string NewWorkerPassword;
string AdminName = "admin";
string AdminPassword = "admin";
void BookingFromNewDelhiToNoida();   
void BookingFromNewDelhiToGurugram();  
void BookingFromNewDelhiToGhaziabad();     
void BookingFromNewDelhiToIndirapuram();     
const int Size = 10;
string NumberOfCab[Size] = {"", "215", "210", "456", "789", "123"};  
int CABSTATUS[Size] = {1, 1, 1, 1, 1, 1};                            
int ChargesPerKm = 5;                                                
int Counting = 4;                                                    
int count = 0;                                                       
int *PChargesPerKm = &ChargesPerKm;                                  

bool wrong = false;  
int main()
{
    //************************************************************************************
    //*                             DiSpLaYiNg WeLcOmE ScReEn                                                 *
    //************************************************************************************
    int count = 0;
    system("color 1E");
    cout << endl;
    cout << "\t******************************\n";
    cout << "\t*         Wel Come           *\n";
    cout << "\t*            To              *\n";
    cout << "\t*    Cab Booking System      *\n";
    cout << "\t******************************\n";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\tLoAdInG ";
    Sleep(100);  
    cout << "<";
    Sleep(100);  
    cout << ">";
    Sleep(100);  
    cout << "<";
    Sleep(100);  
    cout << ">";
    Sleep(100);  
    cout << "<";
    Sleep(100);  
    cout << ">";
    Sleep(100);  
    cout << "<";
    Sleep(100);  
    cout << ">";
    Sleep(100);  
    cout << "<";
    Sleep(100);  
    cout << ">";
    Sleep(100);  
    cout << "<";
    Sleep(100);  
    cout << ">";
    Sleep(100);  
    cout << "<";
    Sleep(100);  
    cout << ">";
    Sleep(100);  
    cout << "\n\n\t SuCcEsSFuL\n";

    Sleep(2000);    
    system("CLS");  

    //*********************************************************************************************************
    //*                                      LoGiN MeNu                                                       *
    //*********************************************************************************************************

    char Wish;
    string Choice;
    do
    {

        system("CLS");
        cout << "\t********************" << endl;
        cout << "\t*CaB BoOkInG SySteM*" << endl;
        cout << "\t********************" << endl;
        cout << endl;

        cout << "*************************" << endl;
        cout << "*<1>  For Login Admin   *" << endl;
        cout << "*************************" << endl;
        cout << endl;
        cout << "**************************" << endl;
        cout << "*<2> For Login Worker    *" << endl;
        cout << "**************************" << endl;
        cout << endl;
        cout << "******************" << endl;
        cout << "*<3> For Exit    *" << endl;
        cout << "******************" << endl;
        cout << endl;
        cout << "SElEct: ";
        cin >> Choice;

        int choice = atoi(Choice.c_str());
        switch (choice)
        {
        case 1:
        {
            string UserName;  
            string Password;  
            bool LoginSuccess = false;

            do
            {
                //************************************************************************************
                //*                           Admin Login                                            *
                //************************************************************************************
                system("CLS");
                cout << "\t********************" << endl;
                cout << "\t*  AdMiN LoGiN     *" << endl;
                cout << "\t********************" << endl;
                cout << endl;
                Sleep(500);  
                cout << "Hint:- admin\n";
                cout << "\nUserName: ";
                cin >> UserName;
                cout << "Password: ";
                cin >> Password;

                if (UserName == AdminName && Password == AdminPassword)
                {
                    cout << "LOgin Successful \n";
                    LoginSuccess = true;
                    Sleep(2000);
                    system("CLS");
                    char Wish;
                    do
                    {
                        system("CLS");
                        string Choice;  
                        cout << "\t********************" << endl;
                        cout << "\t* AdMiNiStRaTiOn   *" << endl;
                        cout << "\t********************" << endl;
                        cout << endl;
                        cout << "<1> Customer Record" << endl;
                        cout << endl;
                        cout << "<2> Cab Driver Record" << endl;
                        cout << endl;
                        cout << "<3> Cab Status" << endl;
                        cout << endl;
                        cout << "<4> Canceled Booking Record" << endl;
                        cout << endl;
                        cout << "<5> Change The Rate Of Per Km Charges" << endl;
                        cout << endl;
                        cout << "<6> New Worker Account" << endl;
                        cout << endl;
                        cout << "<7> To Log Out" << endl;
                        cout << "Select :";
                        cin >> Choice;
                        int choice = atoi(Choice.c_str());
                        switch (choice)
                        {
                        case 1:
                        {
                            CheckBookingRecord();
                            break;
                        } //end of case 1

                        case 2:
                        {
                            system("CLS");
                            ifstream InFile;                 
                            char ch;                         
                            InFile.open("Registration.txt"); 
                            while (!InFile.eof())
                            {
                                InFile.get(ch);
                                cout << ch;
                            }
                            InFile.close();
                            cout << endl;
                            break;
                        }
                        case 3:
                        {
                            system("CLS");
                            int size = 6;
                            cout << "CAB STATUS\n";
                            for (int i = 1; i < size; i++)
                            {
                                if (CABSTATUS[i] == 1)
                                {
                                    cout << "Cab " << NumberOfCab[i] << " IS FREE\n";
                                }
                                else
                                {
                                    cout << "Cab " << NumberOfCab[i] << " IS NOT FREE\n";
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                            system("CLS");
                            ifstream InFile;                  
                            char ch;                          
                            InFile.open("CancelBooking.txt"); 
                            while (!InFile.eof())
                            {
                                InFile.get(ch);
                                cout << ch;
                            }
                            InFile.close(); 
                            cout << endl;
                            break;
                        } 
                        case 5:
                        {
                            char Wish;
                            do
                            {
                               
                                system("CLS");
                                cout << "\t********************" << endl;
                                cout << "\t*     WeL CoME     *" << endl;
                                cout << "\t********************" << endl;
                                cout << endl;
                                int Charges;
                                cout << "Enter The Amount That You Want To Increment or Decrement On Km Per Charges :";
                                do
                                {
                                    cin >> Charges;
                                    wrong = cin.fail(); 
                                    if (wrong)
                                        cout << "Error Wrong Input\nEnter again" << endl;
                                    cin.clear();
                                    cin.ignore(200, '\n'); 
                                } while (wrong);

                                *PChargesPerKm += Charges;
                                cout << "\nThe Changes Has Been Done SuccessFully" << endl;
                                cout << "Do you Want TO Change The Rate Again(Y/N):  ";
                                cin >> Wish;
                            } while (Wish == 'Y' || Wish == 'y');
                            break;
                        }
                        case 6:
                        {
                            system("CLS");
                            cout << "\t WELCOME" << endl;
                            cout << endl;
                            cout << "Enter The New Worker User Name: ";
                            cin >> NewWorkerName;
                            cout << endl;
                            cout << "Enter New Worker Password: ";
                            cin >> NewWorkerPassword;
                            cout << endl;
                            cout << "The Account Has Been Made Successfully\n";
                            cout << endl;
                            cout << "\tThank YOu" << endl;

                            break;
                        }
                        case 7:
                        {
                            system("CLS");
                            cout << "\tFor Logout\n";
                            break;
                        } 

                        default:
                        {
                            cout << "You Enter Wrong Choice" << endl;
                            break;
                        }
                        } 
                        if (choice == 7)
                        {
                            break;
                        }
                        cout << "Press any key to continue...... ";
                        Wish = getch();
                    } while (Wish);
                }
                else
                {
                    cout << "Incorrect User Name And Password\n"
                         << "Please Try Again";
                    Sleep(1000);
                }
            } while (!LoginSuccess);
            break;
        } 

        case 2:
        {
            string UserName = "";
            string Password = "";
            bool LoginSuccess = false;
            do
            {
                system("CLS");
                cout << "\t********************" << endl;
                cout << "\t*  WoRkeR LoGiN     *" << endl;
                cout << "\t********************" << endl;
                cout << "\nHint:- worker\n";
                cout << "UserName: ";
                cin >> UserName;
                cout << "Password: ";
                cin >> Password;

                if (UserName == "worker" && Password == "worker" || UserName == NewWorkerName && Password == NewWorkerPassword)
                {
                    cout << "LOgin Successful \n";
                    LoginSuccess = true;
                    Sleep(2000);

                    system("CLS");

                    //*********************************************************************************************************
                    //*                             DiSpLaYiNg MeNu On The ScReEn                                             *
                    //*********************************************************************************************************

                    char Wish;
                    string Choice;
                    do
                    {
                    x:
                        system("CLS");
                        cout << "\t********************" << endl;
                        cout << "\t*    WoRkEr        *" << endl;
                        cout << "\t********************" << endl;
                        cout << endl;
                        cout << endl;
                        cout << "<1> Booking" << endl;
                        cout << endl;
                        cout << "<2> cab Status    " << endl;
                        cout << endl;
                        cout << "<3> Customer Record    " << endl;
                        cout << endl;
                        cout << "<4> Update Cab Status    " << endl;
                        cout << endl;
                        cout << "<5> To LogOut         " << endl;
                        cout << endl;

                        cout << "Select :";
                        cin >> Choice;
                        int choice = atoi(Choice.c_str());
                        switch (choice)
                        {
                        case 1:
                        {

                            //*************************************************************************
                            //*                       BoOkInG                                         *
                            //*************************************************************************

                            do
                            {

                                system("CLS");
                                char Wish;
                                string Choice;
                                cout << "\t********************" << endl;
                                cout << "\t*    Booking        *" << endl;
                                cout << "\t********************" << endl;
                                cout << endl;
                                cout << endl;
                                cout << "<1> To Book Cab From NewDelhi To Noida" << endl;
                                cout << endl;
                                cout << "<2> To Book Cab From NewDelhi To Gurugram" << endl;
                                cout << endl;
                                cout << "<3> To Book Cab From NewDelhi To Indirapuram" << endl;
                                cout << endl;
                                cout << "<4> To Book Cab From NewDelhi To Ghaziabad" << endl;
                                cout << endl;
                                cout << "<5> To Go Back to Previous Menu" << endl;
                                cout << endl;
                                cout << "Select :";
                                cin >> Choice;
                                int choice = atoi(Choice.c_str()); //converting string to int
                                switch (choice)
                                {
                                    count++;
                                case 1:
                                {
                                    BookingFromNewDelhiToNoida(); //Calling function
                                    break;
                                }
                                case 2:
                                {
                                    BookingFromNewDelhiToGurugram(); //Calling function
                                    break;
                                }
                                case 3:
                                {
                                    BookingFromNewDelhiToIndirapuram(); //Calling function
                                    break;
                                }
                                case 4:
                                {
                                    BookingFromNewDelhiToGhaziabad(); //Calling function
                                    break;
                                }
                                case 5:
                                {
                                    goto x;
                                }
                                default:
                                {
                                    cout << "You Enter Wrong Choice\n";
                                }
                                }
                                cout << "Do you want to continue...... ";
                                Wish = getch();
                            } while (Wish);

                            break;
                        }
                        case 4:
                        {

                            system("CLS");
                            string UpdatingStatus;
                            char Wish;
                            do
                            {
                                cout << "\t********************" << endl;
                                cout << "\t* UpDating Status  *" << endl;
                                cout << "\t********************" << endl;
                                cout << endl;
                                cout << "Enter The Cab Id Number To UPdate status: ";
                                cin >> UpdatingStatus;
                                long int choice = atoi(UpdatingStatus.c_str());
                                switch (choice)
                                {

                                case 215:
                                {
                                    char Statuss;
                                    cout << "The Cab Id Number 215 Returned Or Not(Y/N) :";
                                    cin >> Statuss;
                                    if (toupper(Statuss == 'N'))
                                    {
                                        CABSTATUS[1] = 0;
                                    }
                                    else
                                    {
                                        CABSTATUS[1] = 1;
                                    }
                                    break;
                                }
                                case 210:
                                {
                                    char Statuss;
                                    cout << "The Cab Id Number 210 Returned Or Not(Y/N) :";
                                    cin >> Statuss;
                                    if (toupper(Statuss == 'N'))
                                    {
                                        CABSTATUS[2] = 0;
                                    }
                                    else
                                    {
                                        CABSTATUS[2] = 1;
                                    }
                                    break;
                                }
                                case 456:
                                {
                                    char Statuss;
                                    cout << "The Cab Id Number 456 Returned Or Not(Y/N) :";
                                    cin >> Statuss;
                                    if (toupper(Statuss == 'N'))
                                    {
                                        CABSTATUS[3] = 0;
                                    }
                                    else
                                    {
                                        CABSTATUS[3] = 1;
                                    }
                                    break;
                                }
                                case 789:
                                {
                                    char Statuss;
                                    cout << "The Cab Id Number 789 Returned Or Not(Y/N) :";
                                    cin >> Statuss;
                                    if (toupper(Statuss == 'N'))
                                    {
                                        CABSTATUS[4] = 0;
                                    }
                                    else
                                    {
                                        CABSTATUS[4] = 1;
                                    }
                                    break;
                                }
                                case 123:
                                {
                                    char Statuss;
                                    cout << "The Cab Id Number 789 Returned Or Not(Y/N) :";
                                    cin >> Statuss;
                                    if (toupper(Statuss == 'N'))
                                    {
                                        CABSTATUS[5] = 0;
                                    }
                                    else
                                    {
                                        CABSTATUS[5] = 1;
                                    }
                                    break;
                                }

                                default:
                                {
                                    cout << "You Enter Wrong Choice." << endl;
                                }
                                }
                                cout << "Do You Want To update The Another CAb Status(Y/N): ";
                                cin >> Wish;
                            } while (Wish == 'Y' || Wish == 'y');
                            break;
                        }

                        case 3:
                        {
                            CheckBookingRecord();
                            break;
                        }
                        case 2:
                        {
                            system("CLS");
                            int size = 6;
                            cout << "CAB STATUS\n";
                            for (int i = 1; i < size; i++)
                            {
                                if (CABSTATUS[i] == 1)
                                {
                                    cout << "Cab " << NumberOfCab[i] << " IS FREE\n";
                                }
                                else
                                {
                                    cout << "Cab " << NumberOfCab[i] << " IS NOT FREE\n";
                                }
                            }

                            break;
                        }
                        case 5:
                        {
                            system("CLS");
                            cout << "\tFor Logout\n";
                            break;
                        }
                        default:
                        {
                            cout << "You Enter Wrong Choice\n";
                            break;
                        }
                        } 
                        if (choice == 5)
                        {
                            break;
                        }
                        cout << "Press any key to continue...... ";
                        Wish = getch();
                    } while (Wish);
                }
                else
                {
                    cout << "Incorrect User Name And Password\n"
                         << "Please Try Again";
                    Sleep(2000);
                }
            } while (!LoginSuccess);
            break;
        } 

        case 3:
        {
            system("CLS");
            ifstream InFile;         
            char ch;                  
            InFile.open("Exit.txt");
            while (!InFile.eof())
            {
                InFile.get(ch);
                cout << ch;
            }
            InFile.close(); 
            cout << endl;
            Sleep(2000);
            exit(0);
            break;
        } 

        default:
        {
            cout << "You Enter Wrong Choice" << endl;
            break;
        } 
        } 

        cout << "Press any key to continue...... ";
        Wish = getch();
    } while (Wish);

    return 0;
}
void BookingFromNewDelhiToNoida()
{
    if (CABSTATUS[1] == 0 && CABSTATUS[2] == 0 && CABSTATUS[3] == 0 && CABSTATUS[4] == 0 && CABSTATUS[5] == 0)
    {
        cout << "All The cabs Are Book" << endl;
        cout << "We Can Not Book Cab for You" << endl;
    }
    else
    {

        for (int i = 1; i <= 6; i++)
        {
            if (CABSTATUS[i] == 1)
            {
                count = i;
                break;
            }
        }

        system("CLS");
        ofstream MyFile;
        float Distance = 40;  
        float Charges;        
        ofstream MYFile;
        string Name;          
        ofstream MYFILE;
        MYFILE.open("CabStatus.txt", ios::app);
        MyFile.open("Customer Record.txt", ios::app);  
        MYFile.open("CancelBooking.txt", ios::app);    
        cout << "\t\tBoOkInG\n";
        cout << "--------------------------------------" << endl;
        cout << "|GuIdE LiNes WhIlE FiLlInG The fOrM: |" << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
        cout << "After Entering Your Name Put FullStop After Ending The NAme.\n";
        cout << "Your Must Put Fullstop at The End If You Didn't So Program \n";
        cout << "Will Not Go Further.\n";
        cout << "What is your NAme : ";
        getline(cin, Name, '.');
        Charges = Distance * ChargesPerKm - Distance * 0.10;
        cout << "\nPick : NewDelhi";
        cout << "\nDrop:Noida";
        cout << "\nDistance: 40Km";
        cout << "\nCharges: Rs" << Charges << "\n";
        char PaidCharges;
        cout << "Did You PAy The Charges(Y/N) :- ";
        PaidCharges = getch();
        if (PaidCharges == 'Y')
        {
            cout << "Cab id Num " << NumberOfCab[count] << " is Booked For You\n";
            cout << "Your Booking Has Been Done\n";
            MyFile << "\n\t\tCustomer Record\n";
            MyFile << "\nNAme : " << Name;
            MyFile << "\nPick : NewDelhi";
            MyFile << "\nDrop:Noida";
            MyFile << "\nDistance: 40Km";
            MyFile << "\nCharges: Rs" << Charges;
            MyFile.close();
            CABSTATUS[count] = 0;
            Sleep(1000);
        }
        else if (PaidCharges == 'y')
        {
            cout << NumberOfCab[count] << " is Booked For You\n";

            cout << "Your Booking Has Been Done\n";
            MyFile << "\n\t\tCustomer Record\n";   
            MyFile << "\nNAme : " << Name;         
            MyFile << "\nPick : NewDelhi";         
            MyFile << "\nDrop:Noida";           
            MyFile << "\nDistance: 40Km";          
            MyFile << "\nCharges: Rs" << Charges;  
            MyFile.close();                       
            CABSTATUS[count] = 0;
            Sleep(1000);
        }
        else
        {
            cout << "Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
            MYFile << "\n\t\tBooking Caceled\n";   
            MYFile << "\nNAme : " << Name;         
            MYFile << "\nPick : NewDelhi";         
            MYFile << "\nDrop:Gurugram";          
            MYFile << "\nDistance: 150Km";         
            MYFile << "\nCharges: Rs" << Charges;  
            MYFile.close();                        
            count--;
        }
        MYFILE.close();
        Sleep(2000);
    }
}

void BookingFromNewDelhiToGurugram()
{
    if (CABSTATUS[1] == 0 && CABSTATUS[2] == 0 && CABSTATUS[3] == 0 && CABSTATUS[4] == 0 && CABSTATUS[5] == 0)
    {
        cout << "All The cabs Are Book" << endl;
        cout << "We Can Not Book Cab for You" << endl;
    }
    else
    {
        for (int i = 0; i <= 6; i++)
        {
            if (CABSTATUS[i] == 1)
            {
                count = i;
                break;
            }
        }
        system("CLS");
        ofstream MyFile;       
        ofstream MYFile;       
        float Distance = 150;  
        float Charges;         
        string Name;           
        ofstream MYFILE;
        MYFILE.open("CabStatus.txt", ios::app);
        MyFile.open("Customer Record.txt", ios::app);  
        MYFile.open("CancelBooking.txt", ios::app);    
        cout << "\t\tBoOkInG\n";
        cout << "--------------------------------------" << endl;
        cout << "|GuIdE LiNes WhIlE FiLlInG The fOrM: |" << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
        cout << "After Entering Your Name Put FullStop After Ending The NAme.\n";
        cout << "Your Must Put Fullstop at The End If You Didn't So Program \n";
        cout << "Will Not Go Further.\n";
        cout << "What is your NAme : ";
        getline(cin, Name, '.');
        Charges = Distance * ChargesPerKm - Distance * 0.10;
        cout << "\nPick : NewDelhi";
        cout << "\nDrop:Noida";
        cout << "\nDistance: 150Km";
        cout << "\nCharges: Rs" << Charges << "\n";
        cout << endl;
        char PaidCharges;
        cout << "Did You PAy The Charges(Y/N) :- ";
        PaidCharges = getch();
        if (PaidCharges == 'Y')
        {
            cout << NumberOfCab[count] << " is Booked For You";

            cout << "Your Booking Has Been Done\n";
            MyFile << "\n\t\tCustomer Record\n";   
            MyFile << "\nNAme : " << Name;         
            MyFile << "\nPick : NewDelhi";         
            MyFile << "\nDrop:Gurugram";          
            MyFile << "\nDistance: 150Km";         
            MyFile << "\nCharges: Rs" << Charges;  
            MyFile.close();                        
            CABSTATUS[count] = 0;
            Sleep(1000);
        }
        else if (PaidCharges == 'y')
        {
            cout << NumberOfCab[count] << " is Booked For You";

            cout << "Your Booking Has Been Done\n";
            MyFile << "\n\t\tCustomer Record\n";   
            MyFile << "\nNAme : " << Name;         
            MyFile << "\nPick : NewDelhi";         
            MyFile << "\nDrop:Gurugram";          
            MyFile << "\nDistance: 150Km";         
            MyFile << "\nCharges: Rs" << Charges;  
            MyFile.close();                        
            CABSTATUS[count] = 0;
            Sleep(1000);
        }
        else
        {
            cout << "Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
            MYFile << "\n\t\tBooking Caceled\n";   
            MYFile << "\nNAme : " << Name;         
            MYFile << "\nPick : NewDelhi";         
            MYFile << "\nDrop:Gurugram";          
            MYFile << "\nDistance: 150Km";         
            MYFile << "\nCharges: Rs" << Charges;  
            count--;
            MYFile.close();  
        }
        MYFILE.close();
        Sleep(2000);
    }
}
void BookingFromNewDelhiToIndirapuram()
{

    if (CABSTATUS[1] == 0 && CABSTATUS[2] == 0 && CABSTATUS[3] == 0 && CABSTATUS[4] == 0 && CABSTATUS[5] == 0)
    {
        cout << "All The cabs Are Book" << endl;
        cout << "We Can Not Book Cab for You" << endl;
    }
    else
    {
        for (int i = 0; i <= 6; i++)
        {
            if (CABSTATUS[i] == 1)
            {
                count = i;
                break;
            }
        }
        system("CLS");
        ofstream MyFile;       
        float Distance = 450;  
        float Charges;         
        ofstream MYFile;
        string Name;  
        ofstream MYFILE;
        MYFILE.open("CabStatus.txt", ios::app);
        MyFile.open("Customer Record.txt", ios::app);  
        MYFile.open("CancelBooking.txt", ios::app);    
        cout << "\t\tBoOkInG\n";
        cout << "--------------------------------------" << endl;
        cout << "|GuIdE LiNes WhIlE FiLlInG The fOrM: |" << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
        cout << "After Entering Your Name Put FullStop After Ending The NAme.\n";
        cout << "Your Must Put Fullstop at The End If You Didn't So Program \n";
        cout << "Will Not Go Further.\n";
        cout << "What is your NAme : ";
        getline(cin, Name, '.');
        Charges = Distance * ChargesPerKm - Distance * 0.10; 
        cout << "\nPick : NewDelhi";
        cout << "\nDrop:Indirapuram";
        cout << "\nDistance: 450Km";
        cout << "\nCharges: Rs" << Charges << "\n";
        char PaidCharges;
        cout << "Did You PAy The Charges(Y/N) :- ";
        PaidCharges = getch();
        if (PaidCharges == 'Y')
        {
            cout << NumberOfCab[count] << " is Booked For You";
            cout << "Your Booking Has Been Done\n";
            MyFile << "\n\t\tCustomer Record\n";   
            MyFile << "\nNAme : " << Name;         
            MyFile << "\nPick : NewDelhi";         
            MyFile << "\nDrop:Indirapuram";             
            MyFile << "\nDistance: 350Km";         
            MyFile << "\nCharges: Rs" << Charges;  
            MyFile.close();                        
            CABSTATUS[count] = 0;
            Sleep(1000);
        }
        else if (PaidCharges == 'y')
        {

            cout << NumberOfCab[count] << " is Booked For You";

            cout << "Your Booking Has Been Done\n";
            MyFile << "\n\t\tCustomer Record\n";   
            MyFile << "\nNAme : " << Name;         
            MyFile << "\nPick : NewDelhi";         
            MyFile << "\nDrop:Indirapuram";             
            MyFile << "\nDistance: 350Km";         
            MyFile << "\nCharges: Rs" << Charges;  
            MyFile.close();                        
            CABSTATUS[count] = 0;
            Sleep(1000);
        }
        else
        {
            cout << "Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
            MYFile << "\n\t\tBooking Caceled\n";   
            MYFile << "\nNAme : " << Name;         
            MYFile << "\nPick : NewDelhi";         
            MYFile << "\nDrop:Indirapuram";             
            MYFile << "\nDistance: 350Km";         
            MYFile << "\nCharges: Rs" << Charges;  
            count--;
            MYFile.close();  
        }
        MYFILE.close();
        Sleep(2000);
    }
}

void BookingFromNewDelhiToGhaziabad()
{
    if (CABSTATUS[1] == 0 && CABSTATUS[2] == 0 && CABSTATUS[3] == 0 && CABSTATUS[4] == 0 && CABSTATUS[5] == 0)
    {
        cout << "All The cabs Are Book" << endl;
        cout << "We Can Not Book Cab for You" << endl;
    }
    else
    {
        for (int i = 0; i <= 6; i++)
        {
            if (CABSTATUS[i] == 1)
            {
                count = i;
                break;
            }
        }
        system("CLS");
        ofstream MYFile;      
        ofstream MyFile;      
        float Distance = 35;  
        float Charges;        
        string Name;          
        ofstream MYFILE;
        MYFILE.open("CabStatus.txt", ios::app);
        MyFile.open("Customer Record.txt", ios::app);  
        MYFile.open("CancelBooking.txt", ios::app);    
        cout << "\t\tBoOkInG\n";
        cout << "--------------------------------------" << endl;
        cout << "|GuIdE LiNes WhIlE FiLlInG The fOrM: |" << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
        cout << "After Entering Your Name Put FullStop After Ending The NAme.\n";
        cout << "Your Must Put Fullstop at The End If You Didn't So Program \n";
        cout << "Will Not Go Further.\n";
        cout << "What is your NAme : ";
        getline(cin, Name, '.');
        Charges = Distance * ChargesPerKm - Distance * 0.10; 
        cout << "\nPick : NewDelhi";
        cout << "\nDrop:Ghaziabad";
        cout << "\nDistance: 35Km";
        cout << "\nCharges: Rs" << Charges << "\n";
        char PaidCharges;
        cout << "Did You PAy The Charges(Y/N) :- ";
        PaidCharges = getch();
        if (PaidCharges == 'Y')
        {

            cout << NumberOfCab[count] << " is Booked For You";

            cout << "Your Booking Has Been Done\n";
            MyFile << "\n\t\tCustomer Record\n";   
            MyFile << "\nNAme : " << Name;         
            MyFile << "\nPick : NewDelhi";         
            MyFile << "\nDrop:Ghaziabad";             
            MyFile << "\nDistance: 35Km";          
            MyFile << "\nCharges: Rs" << Charges;  
            MyFile.close();                        
            CABSTATUS[count] = 0;
            Sleep(1000);
        }
        else if (PaidCharges == 'y')
        {
            cout << NumberOfCab[count] << " is Booked For You";

            cout << "Your Booking Has Been Done\n";
            MyFile << "\n\t\tCustomer Record\n";   
            MyFile << "\nNAme : " << Name;         
            MyFile << "\nPick : NewDelhi";         
            MyFile << "\nDrop:Ghaziabad";             
            MyFile << "\nDistance: 35Km";          
            MyFile << "\nCharges: Rs" << Charges;  
            MyFile.close();                        
            CABSTATUS[count] = 0;
            Sleep(1000);
        }
        else
        {
            cout << "Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
            MYFile << "\n\t\tBooking Caceled\n";   
            MYFile << "\nNAme : " << Name;         
            MYFile << "\nPick : NewDelhi";         
            MYFile << "\nDrop:Gurugram";          
            MYFile << "\nDistance: 150Km";         
            MYFile << "\nCharges: Rs" << Charges;  
            MYFile.close();                        
            count--;
        }
        MYFILE.close();
        Sleep(2000);
    }
}
void CheckBookingRecord()
{
    system("CLS");
    ifstream InFile;
    char ch;                             
    InFile.open("Customer Record.txt");  
    while (!InFile.eof())
    {
        InFile.get(ch);
        cout << ch;
    }
    InFile.close();  
    cout << endl;
}