#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
#include<string.h>

using namespace std;
class MyFile
{
    private:
            fstream file;
            char ch;
    public:
            void create(const char* filename)
            {
                file.open(filename,ios::out);
                cout<<"\n\t\tFile Created!";
            }
            void write(char* content)
            {
                if(!file)
                {
                    cout<<"\n\t\tError opening file";
                }
                file<<content;
                file.close();
            }
            void read(const char* filename)
            {
                file.open(filename,ios::in);
                if(!file)
                {
                    cout<<"\n\t\tError Opening file";
                }
                cout<<"\n\t\tReading file...";
                cout<<"\n\t\tContents : \n\t\t";
                while(file>>ch)
                {
                    cout<<ch;
                }
                file.close();
            }
};
int main()
{
    char filename[15];
    char content[1000];
    bool flag;
    MyFile file1;
    cout<<"\n\t\t**************File Handling***************\n";
    cout<<"\n\t\tEnter the name of the file.";
    while(true)
    {
        cin>>filename;
        for(int i=0;i<strlen(filename);i++)
        {
            if(!isalpha(filename[i]))
            {
                cout<<"\n\t\tFilename should contain letters only..!";
            }
            else
            {
                flag=true;
            }
        }
        if(flag)
        {
            strcat(filename,".txt");
            break;
        }
    }
    cout<<"\n\t\tEnter the content in file: ";
    cin.ignore();
    cin.getline(content,1000,'\n');
    cout<<"\n\t\tCreating file...";
    file1.create(filename);
    file1.write(content);
    file1.read(filename);
    return 0;
}
