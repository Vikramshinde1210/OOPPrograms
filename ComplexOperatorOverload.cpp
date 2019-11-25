#include<iostream>
using namespace std;

class Complex
{
    private:
            int real,imgn;
    public:
            Complex(int real=0,int imgn=0)
            {
                this->real=real;
                this->imgn=imgn;
            }
            friend void operator>>(istream &in,Complex &c)
            {
                cout<<"\nEnter the Real Part: ";
                in>>c.real;
                cout<<"\nEnter the Imaginary Part: ";
                in>>c.imgn;
            }
            void operator <<(ostream &out)
            {
                out<<real;
                out<<"+i"<<imgn<<endl;
            }
            int getReal()
            {
                return real;
            }
            int getImaginary()
            {
                return imgn;
            }
            Complex operator +(Complex);
            Complex operator *(Complex);
};

Complex Complex:: operator +(Complex c)
{
    Complex temp;
    temp.real=real+c.real;
    temp.imgn=imgn+c.imgn;
    return(temp);
}

Complex Complex:: operator *(Complex c)
{
    Complex temp;
    temp.real=(real*c.real)-(imgn*c.imgn);
    temp.imgn=(real*c.imgn)+(imgn*c.real);
    return(temp);
}
int main()
{
    Complex c1,c2,add,mul;
    cout<<"\nEnter First Complex Number: ";
    cin>>c1;
    cout<<"\nEnter Second Complex Number: ";
    cin>>c2;
    cout<<"\nAddition is: ";
    add=c1+c2;
    add<<cout;
    cout<<"\nMultiplication is: ";
    mul=c1*c2;
    mul<<cout;
    return 0;
}
