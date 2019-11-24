/*****************************************Student Data***************************************************/
/**@author Manavi Thorve*/

#include<iostream>
#include<limits>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;

/*DateValidor class accepts the date through constructor and then checks the
date range, days in month and according to that returns the output whether the date
is valid or not*/

class DateValidator
{
    private:
            int date,month,year;
            int days;
    public:

            //Initialize the value through constructor
            DateValidator(int dd,int mm,int yy)
            {
                date=dd;
                month=mm;
                year=yy;
            }

            // This function returns true if the date is valid.
            bool isValidDate()
            {
                if(year >= 1950 && year<=2001)
                {
                    //switch case number of days in month according to month number
                    switch(month)
                    {
                        case 1:case 3: case 5: case 7: case 8: case 10: case 12: days=31;
                        break;
                        case 4:case 6: case 9:case 11: days=30;
                        break;
                        case 2: if(year%4 == 0)
                                    days=29;
                                else
                                    days=28;
                        break;
                        default: return false;
                    }
                    if(date>=1 && date<=days)
                        return true;
                    else
                        return false;
                }
                else
                {
                    return false;
                }
            }

};

/*StudentData class simply accepts and displays the student data by using accessor and mutator methods
and the corresponding validations are performed in mutator methods.*/

class PersonData
{
 	private:
 			int id;
			char name[30];
			char address[100];
			int bDay,bMonth,bYear;
			string DOB;
			string bloodGroup;
			string phone;
            bool flag;

	public:

            void setId()
            {
                cin>>id;
                while(1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout<<"\nID should be number Only!";
                        cout<<"\nID: ";
                        cin>>id;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            void setName()
            {
                cin.ignore();
                cin.getline(name,30,'\n');
            }
            void setPhoneNo()
            {
                try
                {
                    int digitCount;
                    cin>>phone;
                    digitCount=phone.length();
                    bool first=phone.at(0)=='9' ||phone.at(0)=='8'||phone.at(0)=='7'||phone.at(0)=='6';
                    while(1)
                    {
                        if(digitCount!=10 || (!first))
                        {
                            throw "Invalid phone number try again!!!";
                        }
                        else
                        {
                            break;
                        }
                    }
                }catch(const char* exp)
                {
                    cout<<"\nError!! "<<exp;
                    cout<<"\nEnter the phone No: ";
                    setPhoneNo();
                }
            }
            void setAddress()
            {
                cin.ignore();
                cin.getline(address,50,'\n');
            }
            void setDOB()
            {
                try
                {
                        cout<<"\nDate: ";
                        cin>>bDay;
                        if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout<<"\nDate should be number Only!";
                            throw " Enter the date again...";
                        }
                        cout<<"\nMonth: ";
                        cin>>bMonth;
                        if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout<<"\nDate should be number Only!";
                            throw "Enter the date again...";
                        }
                        cout<<"\nYear: ";
                        cin>>bYear;
                        if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout<<"\nDate should be number Only!";
                            throw "Enter the date again...";
                        }
                        DateValidator d(bDay,bMonth,bYear);
                        if(!d.isValidDate())
                        {
                            throw "\nInvalid Date..! Please try again..!";
                        }
                }
                catch(const char* exp)
                {
                    cout<<"\n"<<exp;
                    setDOB();
                }
                stringstream ss;
                ss<<bDay<<"/"<<bMonth<<"/"<<bYear;
                ss>>DOB;
            }
            void setBloodGroup()
            {
                int bloodType;
            	do
            	{
                    cout<<"\nEnter your choice..!";
                    cout<<"\n1: A+\t2: A-\t3: B+\t4: B-\t5: O+\t6: O-\t7: AB+\t8: AB-\n";
                    cin>>bloodType,flag=1;
                    switch(bloodType)
                    {
                        case 1: bloodGroup="A+";
                    	break;
                    	case 2: bloodGroup="A-";
                    	break;
                    	case 3: bloodGroup="B+";
                    	break;
                    	case 4: bloodGroup="B-";
                    	break;
                    	case 5: bloodGroup="O+";
                    	break;
                    	case 6: bloodGroup="O-";
                    	break;
                    	case 7: bloodGroup="AB+";
                    	break;
                    	case 8: bloodGroup="AB-";
                    	break;
                    	default:cout<<"\nWrong choice, Please Enter Valid Blood Group!";
                                flag=0;
                    }

                }while(flag==0);

            }
            int getId()
            {
                return id;
            }
            char* getName()
            {
                return name;
            }
            string getPhoneNo()
            {
                return phone;
            }
            char* getAddress()
            {
                return address;
            }
            string getDOB()
            {
                return DOB;
            }
            string getBloodGroup()
            {
                return bloodGroup;
            }
			void acceptData();
			void displayData(string personType);

};
void PersonData::acceptData()
{
    cout<<"\nID: ";
    setId();
    cout<<"\nName: ";
    setName();
    cout<<"\nPhone No: ";
    setPhoneNo();
    cout<<"\nAddress: ";
    setAddress();
    cout<<"\nDOB: ";
    setDOB();
    cout<<"\nBlood Group: ";
    setBloodGroup();
}
void PersonData::displayData(string personType)
{
    cout<<"\n___________________"<<personType<<" Data____________________\n";
    cout<<"\n"<<personType<<" ID\t\t |\t"<<getId();
    cout<<"\n"<<personType<<" Name\t\t |\t"<<getName();
    cout<<"\n"<<personType<<" Phone No.\t |\t"<<getPhoneNo();
    cout<<"\n"<<personType<<" Address\t\t |\t"<<getAddress();
    cout<<"\n"<<personType<<" DOB\t\t |\t"<<getDOB();
    cout<<"\n"<<personType<<" Blood Group\t |\t"<<getBloodGroup();
}

class Student
{
    private:
             char division;
             char standard[5];
             PersonData person;
    public:

             Student()
             {
                cout<<"\n****************** Welcome Student! ***********************\n";
             }

             void setDivision()
             {
                cin>>division;
                while(1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore('\n');
                        cout<<"Division should be character only..!";
                        cin>>division;
                    }
                    else
                    {
                        break;
                    }
                }
                switch(division)
                {
                    case 'A': case 'a': division='A';
                    break;
                    case 'B': case 'b':  division='B';
                    break;
                    case 'C': case 'c':  division='C';
                    break;
                    case 'D': case 'd':  division='D';
                    break;
                    default: cout<<"\nWrong Choice, Try again..\nDivision: ";
                             setDivision();
                }
             }
             void setStandard()
             {
                cin.ignore();
                cin.getline(standard,5,'\n');
             }
             char getDivision()
             {
                return division;
             }
             char* getStandard()
             {
                return standard;
             }
             void acceptData();
             void displayData();

};

void Student::acceptData()
{
    person.acceptData();
    cout<<"\nStandard: ";
    setStandard();
    cout<<"\nDivision: ";
    setDivision();
}

void Student::displayData()
{
    person.displayData("Student");
    cout<<"\nStandard\t\t |\t"<<getStandard();
    cout<<"\nDivision\t\t |\t"<<getDivision();
    cout<<"\n________________________________________________________________\n";
}

int main()
{
 	Student s;
 	s.acceptData();
 	s.displayData();
 	return 0;
}
