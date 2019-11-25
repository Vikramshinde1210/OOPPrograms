#include<iostream>
using namespace std;

template <class T>
class Sort
{
    private: T arr[20];
             int i,n;

    public:
            Sort(int n)
            {
                this->n=n;
            }
            void acceptElements()
            {
                for(i=0;i<n;i++)
                {
                    cin>>arr[i];
                }
            }
            void displayElements()
            {
                for(i=0;i<n;i++)
                {
                    cout<<arr[i]<<" ";
                }
            }
            void sortElements();
};

template <class T>
void Sort<T>::sortElements()
{
    int i,j,minI;
    T temp;
	for(i=0;i<n-1;i++)
	{
		minI=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[minI])
			{
				minI=j;
			}
		}
		temp=arr[minI];
		arr[minI]=arr[i];
		arr[i]=temp;
	}
}

int main()
{
    int size;
    cout<<"\nEnter the size of elements: ";
    cin>>size;
    Sort<int> sortInt=Sort<int>(size);
    Sort<float> sortFloat=Sort<float>(size);

    cout<<"\nEnter the Integer Elements: ";
    sortInt.acceptElements();
    sortInt.sortElements();
    cout<<"\n***************Sorted Integer Elements******************\n";
    sortInt.displayElements();
    cout<<"\nEnter the Float Elements: ";
    sortFloat.acceptElements();
    sortFloat.sortElements();
    cout<<"\n***************Sorted Float Elements******************\n";
    sortFloat.displayElements();
    return 0;
}


