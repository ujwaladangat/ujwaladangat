#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Client
{
    string name;
    int phoneNumber;
};
class HashTable
{
public:
	string name;
    int phoneNumber;
    static const int size=10;
    Client table[size];
    int collisions[size];
    int hash(int key) 
	{ 
	   return key%size; 
	}
    HashTable() 
	{ 
	    for(int i=0;i<size;i++) 
	       collisions[i]=0; 
	}
    void linearprobing(Client client)
    {
        int index=hash(client.phoneNumber);
        int count=0;
        while(collisions[index]==1)
        {
            index=(index+1)%size;
            count++;
        }
        table[index]=client;
        collisions[index]=1;
        cout<<"Inserted "<<client.name<<"'s phone number after "<<count<<" collisions using linear probing."<<endl;
    }
    void quadraticprobing(Client client)
    {
        int index=hash(client.phoneNumber);
        int count=0;
        while(collisions[index]!=0 && collisions[index]!=client.phoneNumber)
        {
            count++;
            index=(hash(client.phoneNumber)+count*count)%size;
        }
        table[index]=client;
        collisions[index]=1;
        cout<<"Inserted "<<client.name<<"'s phone number after "<<count<<" collisions using quadratic probing."<<endl;
    }
    bool search(int phoneNumber)
    {
        int index=hash(phoneNumber);
        int count=0;
        while(collisions[index]!=0)
        {
            if(table[index].phoneNumber==phoneNumber)
            {
                cout<<"Found "<<table[index].name<<"'s phone number after "<<count<<" comparisons using linear probing."<< endl;
                return true;
            }
            index=(index+1)%size;
            count++;
        }
        cout<<"Phone number not found."<<endl;
        return false;
    }
};

int main()
{
    HashTable ht;
    int number;
    string name;
    int x=11;
    int y;
    while(x!=0)
    {
        cout<<"\n1.INSERT NUMBER\n2.SEARCH NUMBER\n0.EXIT\nEnter your choice:";
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"\nEnter name:";
                cin>>name;
                cout<<"Enter number:";
                cin>>number;
                cout<<"\n1.Linear probing\n2.Quadratic probing\nEnter your option:";
                cin>>y;
                if(y==1) ht.linearprobing({name, number});
                else if(y==2) ht.quadraticprobing({name, number});
                else cout<<"Error! invalid option\n";
                cout<<endl;
                break;
            case 2:
                cout<<"\nEnter number to search:";
                cin>>number;
                ht.search(number);
                break;
            case 0:
                cout<<"\nExiting....\n\n";
                break;
            default:
                cout<<"\nInvalid choice!!\nEnter again\n\n";
                break;
        }
    }
    return 0;
}
