#include<iostream>
using namespace std;

class OperatorOverloading
{
	private:
			 int count=0;
	public: 
			void operator ++();
			
			void acceptCount()
			{
				cout<<"Enter Value of count: ";
				cin>>count;
			}
			void displayCount()
			{
				cout<<"\nCount Value: "<<count<<"\n";
			}
};
void OperatorOverloading::operator ++()
{
	count++;
}
int main()
{
	OperatorOverloading op;
	op.acceptCount();
	cout<<"\n-------------------Before Overloading-------------------\n";
	op.displayCount();
	++op;
	cout<<"\n-------------------After Overloading-------------------\n";
	op.displayCount();
	return 0;
}
