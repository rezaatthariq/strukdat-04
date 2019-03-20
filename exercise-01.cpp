/*
Author 		: M Reza Atthariq Kori 
NPM 		: 140810180060
Kelas		: B
Tanggal		: 20 Maret 2019
Deskripsi	: Program Menu fungsi-fungsi Linked List
*/

#include <iostream>
#include <iomanip>
using namespace std;

struct pegawai{
    char nama[30];
    char divisi[30];
    int gaji;
    pegawai* next;
};
typedef pegawai* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst (List& First, pointer pBaru);
void insertLast (List& First, pointer pBaru);
void traversal (List First, pointer pBantu);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast (List& First, pointer& pHapus);

main()
{
    pointer pBaru;
    pointer pBantu;
    List first;
    int pilihan;
    char jawab;

    createList(first);
    do{
        system("cls");
        cout<<"Pilih Menu : \n"<<endl;
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Delete First"<<endl;
        cout<<"4. Delete Last"<<endl;
        cout<<"5. Tampilkan Data ( traversal )"<<endl;
        cout << "\nMasukan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
            createElmt(pBaru);
            insertFirst(first, pBaru);
        break;

        case 2:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 3:
            deleteFirst(first, pBaru);
        break;

        case 4:
            deleteLast(first, pBaru);
        break;
		
        case 5:
        	cout<<setfill('=')<<setw(75)<<"\n";
            traversal(first,pBantu);
        break;

        default:
        	cout<<"Exit";
        }

  		cout<<"Ingin Ke Menu lagi? (Y/N) ";cin>>jawab;
    	cin.ignore();
    	if (jawab=='Y'||jawab=='y'){system("cls");}
    	else 
			cout<<setfill('=')<<setw(75)<<"\n";
			traversal(first,pBantu);
    	}
    while(jawab=='Y'||jawab=='y');
}


void createList(List& First){
    First = NULL;
    }

void createElmt (pointer& pBaru){
    pBaru = new pegawai;
    cout<<"\nMasukkan data pegawai  "<<endl;
    cout<<"Nama     : "; cin.ignore();cin.getline(pBaru->nama,30);
    cout<<"Divisi   : "; cin>>pBaru->divisi;
    cout<<"Gaji     : "; cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
	if(First==NULL)
		First=pBaru;
	else{
		pBaru->next=First;
		First=pBaru;
	}
}

void insertLast (List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void traversal (List First, pointer pBantu){
	pBantu = First;
  	int i = 1;
  	cout << setfill(' ')<<setw(5) << "No" << setw(30) << " Nama" << setw(18) << " Divisi" << setw(18) << " Gaji" << endl;
  	do {
   		cout << setw(5) << i << setw(30) << pBantu->nama << setw(18) << pBantu->divisi << setw(18) << pBantu->gaji << endl;
   		pBantu = pBantu->next;
   		i++;
  		} while (pBantu != NULL); {
   		cout << endl;
	}
}

void deleteFirst(List& First, pointer& pHapus){
    if(First==NULL){
        pHapus=NULL;
        cout<<"List kosong!"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast (List& First, pointer& pHapus){
    pointer Last, precLast;
    if (First==NULL){
        pHapus=NULL;
        cout<<"List kosong!"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        Last=First;
        precLast=NULL;
        while (Last->next!=NULL){
            precLast=Last;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}
