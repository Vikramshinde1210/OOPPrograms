#include<iostream>
#include<vector>
using namespace std;

class MyVector
{
    private:
            vector<int> v;
            int size;
            int element;
    public:
            void createVector(int size)
            {
                for(int i=0;i<size;i++)
                {
                    cin>>element;
                    v.push_back(element);
                }
            }
            void displayVector()
            {
                for(vector<int>::iterator display_itr= v.begin();display_itr!=v.end();++display_itr)
                {
                    cout<<*display_itr<<", ";
                }
                cout<<endl;
            }
            int getSize()
            {
                return v.size();
            }
            void modifyElement(int element,int position)
            {
                v.at(position-1)=element;
            }
            void multiplyScalar(int value)
            {
                for(int i=0;i<v.size();i++)
                {
                    v[i]=v[i]*value;
                }
            }
};

int main()
{
    int size,ch,position,element,scalar_value;
    char choice;
    MyVector vect;

    cout<<"\n\t\t***************** Vector ***********************\n";
    cout<<"\n\t\tEnter the number of elements: ";
    cin>>size;
    cout<<"\n\t\tEnter "<<size<<" elements: ";
    vect.createVector(size);
    do
    {
        cout<<"\n\t\tEnter your choice ";
        cout<<"\n\t\t1-Display Vector\n\t\t2-Display size of vector\n\t\t3-Modify\n\t\t";
        cout<<"4-Multiply by scalar value\n\t\t->";
        cin>>ch;

        switch(ch)
        {
            case 1: //Display the contents of vector.
                    cout<<"\n\t\tElements in vector are: \n\t\t";
                    vect.displayVector();
            break;
            case 2: //Display the size of the vector.
                    cout<<"\n\t\tSize of Vector is: "<<vect.getSize();
            break;
            case 3: //Modify the contents of vector
                    cout<<"\n\t\tEnter the position to modify the element: ";
                    cin>>position;
                    cout<<"\n\t\tEnter new element: ";
                    cin>>element;
                    vect.modifyElement(element,position);
                    cout<<"\n\t\tChanges Saved!\n\t\t";
                    vect.displayVector();
            break;
            case 4: //Multiply with scalar value
                    cout<<"\n\t\tEnter the scalar value: ";
                    cin>>scalar_value;
                    vect.multiplyScalar(scalar_value);
                    cout<<"\n\t\tSuccess..!\n\t\t";
                    vect.displayVector();
            break;
            default: cout<<"Wrong choice! Try again..!";
        }

        cout<<"\n\t\tDo you want to continue? --> Y/N ";
        cin>>choice;
    }while(choice=='y' || choice=='Y');
    return 0;
}
