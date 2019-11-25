#include<iostream>
using namespace std;

class Shape
{
    protected:
             double x,y;
    public:
            virtual void getData()=0;
            virtual void displayData()=0;
};

class Rectangle: public Shape
{
    public:
            void getData()
            {
                cout<<"\nLength: ";
                cin>>x;
                cout<<"\nBreadth: ";
                cin>>y;
            }
            double calcData()
            {
                return (x*y);
            }
            void displayData()
            {
                cout<<"\nArea of Rectangle is: "<<calcData();
            }
};

class Triangle: public Shape
{
    public:
            void getData()
            {
                cout<<"\nBase: ";
                cin>>x;
                cout<<"\nHeight: ";
                cin>>y;
            }
            double calcData()
            {
                return (0.5*x*y);
            }
            void displayData()
            {
                cout<<"\nArea of Triangle is: "<<calcData();
            }
};

int main()
{
    cout<<"\n\n*********Area of Rectangle*************\n";
    Rectangle r;
    cout<<"\nEnter the length and breadth: ";
    r.getData();
    r.displayData();
    cout<<"\n\n*********Area of Rectangle*************\n";
    Triangle t;
    cout<<"\nEnter the base and height: ";
    t.getData();
    t.displayData();
    return 0;
}
