#include<iostream>
using namespace std;
class  OperatorOverload
{
	private:
			 int a;
			 float ans;
	public: 
			 OperatorOverload()
			 {
			 }
			 OperatorOverload(int a)
			 {	
			 	this->a=a;
			 }
			 void operator +(OperatorOverload);
			 void operator -(OperatorOverload);
			 void operator *(OperatorOverload);111
};
void OperatorOverload::operator+(OperatorOverload op)
{
	int m=a+op.a;
	cout<<"\nAns: "<<m;
}
void OperatorOverload::operator-(OperatorOverload op)
{
	int m=a-op.a;
	cout<<"\nAns: "<<m;
}
void OperatorOverload::operator*(OperatorOverload op)
{
	int m=a*(op.a);
	cout<<"\nAns: "<<m;
}
int main()
{
	OperatorOverload op1(10);
	OperatorOverload op2(20);
	op1+op2;
	op1-op2;
	op1*op2;	
	return 0;
}
