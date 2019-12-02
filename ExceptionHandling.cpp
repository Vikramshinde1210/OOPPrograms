/*--------------------------------------------------User Defined Exception----------------------------------------------------*/
#include<iostream>
#include<string>
#include<strings.h>
#include<cctype>
using namespace std;

class Exception
{
    virtual void printError()=0;
};
class InvalidCityException: public Exception
{
    string arr[4]={"PUNE","MUMBAI","BANGLORE","CHENNAI"};
    public:
            bool isValidCity(string city)
            {
                bool flag;
                for(int i=0;i<4;i++)
                {
                    if(city.compare(arr[i])==0)
                    {
                        flag=true;
                        break;
                    }
                    else
                    {
                        flag=false;
                    }
                }
                if(flag)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            void printError()
            {
                cout<<"\n\t\tEntered city is invalid! Try again..";
            }
};
class InvalidVehicleException: public Exception
{
    public:
            bool isValidVehicle(int num_wheels)
            {
                if(num_wheels>=4 || num_wheels<=0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            void printError()
            {
                cout<<"\n\t\tVehicle with 4 or more and 0 or less wheels are not permitted! Try again..";
            }
};
class ExceptionHandler
{
    private:
            string city;
            int num_wheels;
    public:
            void setCity(string my_city)
            {
                try
                {
                    //lowercase all characters
                    for(int i=0;i<my_city.length();i++)
                    {
                        my_city.at(i)=toupper(my_city.at(i));
                    }
                    InvalidCityException e;
                    if(e.isValidCity(my_city))
                    {
                        city=my_city;
                    }
                    else
                    {
                        throw InvalidCityException();
                    }
                }
                catch(InvalidCityException e)
                {
                    e.printError();
                    cin>>city;
                    setCity(city);
                }
            }
            void setVehicle(int no_wheels)
            {
                try
                {
                    InvalidVehicleException e;
                    if(e.isValidVehicle(no_wheels))
                    {
                        num_wheels=no_wheels;
                    }
                    else
                    {
                        throw InvalidVehicleException();
                    }
                }
                catch(InvalidVehicleException e)
                {
                    e.printError();
                    cin>>num_wheels;
                    setVehicle(num_wheels);
                }
            }
            inline string getCity()
            {
                return city;
            }
            inline int getVehicle()
            {
                return num_wheels;
            }
};

int main()
{
    string city;
    int num_wheels;
    ExceptionHandler handle;
    cout<<"\n\t\t***********************Exception Handling**************************\n\t\t";
    cout<<"\n\t\tEnter your city: ";
    cin>>city;
    handle.setCity(city);
    cout<<"\n\t\tHow many wheels your vehicle has? ";
    cin>>num_wheels;
    handle.setVehicle(num_wheels);
    cout<<"\n\t\tYour city is: "<<handle.getCity();
    cout<<"\n\t\tYour vehicle has "<<handle.getVehicle()<<" wheels";
    return 0;
}
