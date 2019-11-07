#include<iostream>
#include<limits>
#include<string>
//#include<string.h>
#include<sstream>
using namespace std;
class DateValidator
{
    private:
            int date,month,year;
            int days;
    public:
            DateValidator(int dd,int mm,int yy)
            {
                date=dd;
                month=mm;
                year=yy;
            }
            bool isValidDate()
            {
                if(year >= 1950 && year<=2001)
                {
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
class EmployeeData
{
 	private:
 			int emp_id;
			char emp_name[30];
			double emp_sal;
			char emp_addr[100];
			int emp_bDay,emp_bMonth,emp_bYear;
			string emp_DOB;
			string emp_bloodGroup;
			string emp_phone;
			bool flag;
	public:
            void setEmpId()
            {
                cin>>emp_id;
                while(1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout<<"\nEmployee ID should be number Only!";
                        cout<<"\nEmployee ID: ";
                        cin>>emp_id;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            void setEmpName()
            {
                cin.ignore();
                cin.getline(emp_name,30,'\n');
            }
            void setEmpSalary()
            {
                cin>>emp_sal;
                while(1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout<<"\nEmployee Salary should be number Only!";
                        cout<<"\nEmployee Salary: ";
                        cin>>emp_sal;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            void setEmpPhoneNo()
            {
                try
                {
                    int digitCount;
                    cin>>emp_phone;
                    digitCount=emp_phone.length();
                    bool first=emp_phone.at(0)=='9' ||emp_phone.at(0)=='8'||emp_phone.at(0)=='7'||emp_phone.at(0)=='6';
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
                    setEmpPhoneNo();
                }
            }
            void setEmpAddress()
            {
                cin.ignore();
                cin.getline(emp_addr,50,'\n');
            }
            void setEmpDOB()
            {
                bool invalid;
                do
                {
                    cout<<"\nDate: ";
                    cin>>emp_bDay;
                    cout<<"\nMonth: ";
                    cin>>emp_bMonth;
                    cout<<"\nYear: ";
                    cin>>emp_bYear;
                    DateValidator d(emp_bDay,emp_bMonth,emp_bYear);
                    if(!d.isValidDate())
                    {
                        cout<<"Invalid Date Please try again!!";
                        invalid=true;
                    }
                }while(invalid);
                stringstream ss;
                ss<<emp_bDay<<"/"<<emp_bMonth<<"/"<<emp_bYear;
                ss>>emp_DOB;
            }
            void setEmpBloodGroup()
            {
            	int bloodType;
            	do
            	{
                    cout<<"\nEnter your choice..!";
                    cout<<"\n1: A+\t2: A-\t3: B+\t4: B-\t5: O+\t6: O-\t7: AB+\t8: AB-\n";
                    cin>>bloodType,flag=1;
                    switch(bloodType)
                    {
                    	case 1: emp_bloodGroup="A+";
                    	break;
                    	case 2: emp_bloodGroup="A-";
                    	break;
                    	case 3: emp_bloodGroup="B+";
                    	break;
                    	case 4: emp_bloodGroup="B-";
                    	break;
                    	case 5: emp_bloodGroup="O+";
                    	break;
                    	case 6: emp_bloodGroup="O-";
                    	break;
                    	case 7: emp_bloodGroup="AB+";
                    	break;
                    	case 8: emp_bloodGroup="AB-";
                    	break;
                    	default: cout<<"\nWrong choice, Please Enter Valid Blood Group!";
                    			 flag=0;
                    }
                }while(flag==0);   
            }
            int getEmpId()
            {
                return emp_id;
            }
            char* getEmpName()
            {
                return emp_name;
            }
            double getEmpSalary()
            {
                return emp_sal;
            }
            string getEmpPhoneNo()
            {
                return emp_phone;
            }
            char* getEmpAddress()
            {
                return emp_addr;
            }
            string getEmpDOB()
            {
                return emp_DOB;
            }
            string getEmpBloodGroup()
            {
                return emp_bloodGroup;
            }
			void acceptData();
			void displayData();

 };

void EmployeeData::acceptData()
{
    cout<<"\nEmployee ID: ";
    setEmpId();
    cout<<"\nEmployee Name: ";
    setEmpName();
    cout<<"\nEmployee Salary: ";
    setEmpSalary();
    cout<<"\nEmployee Phone No: ";
    setEmpPhoneNo();
    cout<<"\nEmployee Address: ";
    setEmpAddress();
    cout<<"\nEmployee DOB: ";
    setEmpDOB();
    cout<<"\nEmployee Blood Group: ";
    setEmpBloodGroup();
}
void EmployeeData::displayData()
{
    cout<<"\n_________________Employee Data_________________\n";
    cout<<"\nID\t\t |\t"<<getEmpId();
    cout<<"\nName\t\t |\t"<<getEmpName();
    cout<<"\nSalary\t\t |\t"<<getEmpSalary();
    cout<<"\nPhone No.\t |\t"<<getEmpPhoneNo();
    cout<<"\nAddress\t\t |\t"<<getEmpAddress();
    cout<<"\nDOB\t\t |\t"<<getEmpDOB();
    cout<<"\nBlood Group\t |\t"<<getEmpBloodGroup();
    cout<<"\n_______________________________________________\n";
}

int main()
{
 	cout<<"\n****************Employee****************\n";
 	EmployeeData e;
 	e.acceptData();
 	e.displayData();
 	return 0;
}
