#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

const int MAX=10;

class OperatorOverloading
{
    private:
            char str[30];
    public:
            void getdata()
            {
                cout<<"\nEnter the string : ";
                cin>>str;
            }
            void display()
            {
                cout<<"\n"<<str;
            }
            void operator+ (OperatorOverloading op);
            void operator= (OperatorOverloading op);
            void operator>> (OperatorOverloading op);
            void palindrome();
            bool operator== (OperatorOverloading op);
};

class MyArray
{
    private:
            int Arr[MAX];
            int size;

	public:
            MyArray(int s, int v)
            {
                if(s>MAX)
                {
                    cout<<endl<<"This is beyond maximum size";
                }
                size = s;

                for(int i=0;i<size;i++)
                Arr[i] = v;
            }
            int& operator[](int i);
};

/*Overloading + operator for concatenation*/
void OperatorOverloading::operator+ (OperatorOverloading op)
{
   strcat(str,op.str);
   cout<<"\n\t--String After Concatenation is : "<<str;
}

/*Overloading = operator to copy string*/
void OperatorOverloading::operator= (OperatorOverloading op)
{
   strcpy(op.str,str);
   cout<<"\n\tCopied String is : "<<op.str;
}

/*Overloading >> operator to reverse a string*/
void OperatorOverloading::operator>> (OperatorOverloading op)
{
    int i;
    cout<<"\n\t--The string after reversing is : ";
    for(i=strlen(op.str);i>=0;i--)
    {
        cout<<op.str[i];
    }
}

/*Checking whether string is palindrome or not*/
void OperatorOverloading::palindrome()
{
    int i,j,flag=0;
    for(i=0,j=strlen(str)-1;i<=strlen(str),j>=0;j--,i++)
    {
        if(str[i]!=str[j])
        {
            flag=1;
            cout<<"\n\t--Not a palindrome--";
            break;
        }
        else
            flag=0;
    }
    if(flag==0)
    {
        cout<<"\n\t--Palindrome--";
    }
}

/*Overloading = operator to check equality of strings*/
bool OperatorOverloading::operator== (OperatorOverloading op)
{
   if(strcmp(str,op.str)==0)
     return true;

     return false;
}

/*Overloading [] operator to check array index out of bound condition */
int& MyArray::operator[](int i)
{
    if( (i<0) || (i>size) )
    {
        cout<<endl<<"Error: Array out of bound";
        exit(1);

    }
    return Arr[i];
}

int main()
{
    int choice,opt1=1,arr_size,i,value,number;
    bool check;

    OperatorOverloading op1,op2;
	do
    {

        cout<<"\n\t\t\t---Main Menu---\n";

        cout<<"\n\t1.String Concatenate\n\t2.String Copy\n\t3.String Reverse";
        cout<<"\n\t4.Palindrome\n\t5.String Compare";
        cout<<"\n\t6.Display\n\t7.Display Array\n\t8.Exit\n\t";

        cout<<"\n--Enter your choice-->";
        cin>>choice;

        switch(choice)
        {
            case 1:
                    cout<<"\nEnter the 1st string-\n";
                    op1.getdata();
                    cout<<"\nEnter the 2nd string-\n";
                    op2.getdata();
                    op1+op2;
            break;
            case 2:
                    op1.getdata();
                    op1=op2;
            break;
            case 3:
                    op1.getdata();
                    op2>>op1;
            break;
            case 4:
                    op1.getdata();
                    op1.palindrome();
            break;
            case 5:
                    cout<<"\nEnter the 1st string-\n";
                    op1.getdata();
                    cout<<"\nEnter the 2nd string-\n";
                    op2.getdata();
                    check=op1==op2;
                    if(check)
                    cout<<"\n\t---Strings are Equal---\n";
                    else
                    cout<<"\n\t---Strings are not Equal---\n";
            break;
            case 6:
                    op1.getdata();
                    op1.display();
            break;
            case 7:
                    {
                        cout<<"\n\tWhich table you want to display?";
                        cin>>number;
                        cout<<"\n\tUp to? : ";
                        cin>>arr_size;
                        MyArray arr(arr_size,0);
                        for(i=1;i<=arr_size;i++)
                        {
                            arr[i] = i*number;
                        }
                        cout<<"Table of "<<number<<" :"<<endl;
                        for(i=1;i<=arr_size;i++)
                        {
                            value = arr[i];
                            cout<<value<<endl;
                        }
                    }
            break;
            case 8: return 0;
            break;

            default: cout<<"Wrong choice..try again!\n";
        }
        cout<<"\n--Press 1 to continue--> ";
        cin>>choice;

    }while(choice==1);

    return 0;
}
