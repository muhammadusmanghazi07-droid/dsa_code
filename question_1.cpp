#include <iostream>
using namespace std;
int get(int *arr,int val)
{
    cout<<"we get the "<<val<<" index number: ";
    return *(arr+val);
}

int update(int* arr,int val)
{
    int a;
    cout<<"enter the update value: ";
    cin>>a;
    cout<<"before update: "<<*(arr+val);
    cout<<endl;
    *(arr+val)=a;
    cout<<"after update: ";
    return *(arr+val);
}

int length(int *arr,int size)
{   
    int count=0;
    int *p=arr;
    while(p<arr+size)
    {
        count++;
        p++;
    }
    delete[] p; 
    return count;
}


int main()
{
    int size;
    cout<<"enter the size of array: ";
    cin>>size;
    int *ptr=new int[size];
    cout<<"ENTER THE VALUE OF : "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>*(ptr+i);
    }
    int chose;
    cout<<"WHICH index number YOU WANT TO GET IT,PLEASE ENTER:  ";
    cin>>chose;
    cout<<get(ptr,chose);

    cout<<endl;

    cout<<"WHICH index number YOU WANT TO update IT,PLEASE ENTER:  ";
    int index_number;
    cin>>index_number;
    cout<<update(ptr,index_number);
    cout<<endl;
    
    cout<<"the lenght of array: ";
    cout<<length(ptr,size);
    cout<<endl;
    delete[] ptr;
    return 0;
}