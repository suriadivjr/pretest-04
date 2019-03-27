/*
Author    		: SURIADI VAJRAKARUNA
NPM		        : 140810180038
Deskripsi	    : pretest-04
Tahun           : 2019
*/

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

struct ElemList
{
    char npm[12];
    char nama[40];
    float ipk;
    ElemList* next;
};
typedef ElemList* pointer;
typedef pointer List;

void createList(List& First)
{
    First = NULL;
}

void createElmt (pointer& pBaru)
{
    pBaru = new ElemList;
    cout<<"NPM			: "; cin>>pBaru->npm;
    cout<<"Nama			: "; cin.ignore();cin.getline(pBaru->nama,40);
    cout<<"IPK	     	: "; cin>>pBaru->ipk;
    pBaru->next=NULL;
}

void insertLast (List& First, pointer pBaru)
{
    pointer Last;
    if (First==NULL) First=pBaru;
    else 
	{
        Last=First;
        while (Last->next!=NULL)
		{
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void traversal (List First)
{
    pointer pBantu;
    pBantu=First;
    int i=1;
    cout<<"No\tNPM\t\t\t\t\t\tNama\t\t\tIPK\t\t\t"<<endl;
    while(pBantu != NULL)
	{
		cout<<i<<"\t"<<pBantu->npm<<"\t\t\t\t\t"<<pBantu->nama<<"\t\t\t"<<pBantu->ipk<<endl;
        pBantu=pBantu->next;
        i++;
    }
}


/*
void sorting ()
{
	
}
*/

int main()
{
    pointer pBaru;
    List first;
	int n;
	
	createList(first);
	
	cout << "Berapa jumlah mahasiswa yang anda ingin input? "; cin >> n;
	for (int i=0; i<n; i++)
	{
		cout << "Data mahasiswa ke-" << i+1 << ": " << endl;
		createElmt(pBaru);
		insertLast(first,pBaru);
	}
	//sorting(first, pBaru);
	traversal(first);
}
