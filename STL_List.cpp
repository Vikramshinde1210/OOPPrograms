#include<iostream>
#include<list>
using namespace std;

class MyList
{
    private: list<int> list1,list2;
             int value,size;
             list<int>::iterator itr;
    public:
            void accept(int size)
            {
                for(int i=0;i<size;i++)
                {
                    cin>>value;
                    list1.push_back(value);
                }
            }
            void display()
            {
                if(list1.empty())
                {
                    cout<<"\n\t\tList is Empty!";
                }
                else
                {
                    for(itr=list1.begin();itr!=list1.end();++itr)
                    {
                        cout<<*itr<<endl<<"\t\t";
                    }
                    cout<<endl;
                }
            }
            void insertElement(int value,int position)
            {
                itr=list1.begin();
                advance(itr,position-1);
                list1.insert(itr,value);
            }
            void reverseList()
            {
                list1.reverse();
            }
            void sortList()
            {
                list1.sort();
            }
            void mergeList(MyList l)
            {
                cout<<"\n\t\tEnter the size of list: ";
                cin>>size;
                cout<<"\n\t\tEnter elements: ";
                l.accept(size);
                list1.merge(l.list1);
            }
            void uniqueList()
            {
                list1.unique();
            }
};

int main()
{
    cout<<"****************************LIST**********************************";
    int ch,size,position,element;
    char choice;
    MyList list1,templist;
    cout<<"\n\t\tEnter the size of list: ";
    cin>>size;
    cout<<"\n\t\tEnter the elements in the list: ";
    list1.accept(size);
    do
    {
        cout<<"\n\t\tEnter your choice ";
        cout<<"\n\t\t1-Display\n\t\t2-Insert\n\t\t3-Reverse\n\t\t4-Sort\n\t\t5-Merge\n\t\t6-Unique";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\n\t\tList elements are: \n\t\t";
                    list1.display();
            break;
            case 2: cout<<"\n\t\tEnter the position: ";
                    cin>>position;
                    cout<<"\n\t\tEnter element: ";
                    cin>>element;
                    list1.insertElement(element,position);
            break;
            case 3: cout<<"\n\t\tReversed List is: \n\t\t";
                    list1.reverseList();
                    list1.display();
                    list1.reverseList();
            break;
            case 4: cout<<"\n\t\tSorted List is: \n\t\t";
                    list1.sortList();
                    list1.display();
            break;
            case 5: list1.mergeList(templist);
                    cout<<"\n\t\tMerged List is: \n\t\t";
                    list1.display();
            break;
            case 6: list1.uniqueList();
                    cout<<"\n\t\tAfter Removing Duplication\n\t\t";
                    list1.display();
            break;
            default: cout<<"\n\t\tWrong choice..";
        }
        cout<<"\n\t\tDo you want to continue? Y/N";
        cin>>choice;
    }while(choice=='y' || choice=='Y');
    return 0;
}
