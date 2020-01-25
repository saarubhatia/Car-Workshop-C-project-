#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class car
{
public:
    char oname[20],pno[12],state[12],cmodel[20],cno[20],cdated[10],cdatem[10],status[10];
    int n,num,num1,a;
void in()
{

    cout<<"\n Is it an accidental vehicle?";
    cout<<"\n Press 1 if YES, Press 2 if NO"<<endl;
    cin>>num;
    switch(num)
    {
    case 1:
        cout<<"\n Has the customer submitted the FIR copy?";
        cout<<"\n Press 1 if YES and Press 2 if NO"<<endl;
        cin>>a;
        if(a==1)
        {
            cout<<"\n CONTINUE";
        }
        else
            {
                cout<<"\n SORRY SIR,PLEASE SUBMIT THE FIR COPY";
                exit(0);
            }

        break;
    case 2:
        cout<<"\n CONTINUE";
        break;
    }
    fflush(stdin);
cout<<"\n\tOWNER NAME:";
gets(oname);
cout<<"\tCONTACT NUMBER:";
cin>>pno;
cout<<"\tSTATE:";
cin>>state;
cout<<"\tCAR NAME:";
cin>>cmodel;
cout<<"\tCAR NUMBER:";
cin>>cno;
cout<<"\tDATE:\tDD:";
cin>>cdated;
cout<<"\tMM:";
cin>>cdatem;
cout<<"\tSTATUS:\n\t1.DELIVERED\t2.NOT DELIVERED\t\t3.SERVICING\t";
cin>>status;
cout<<"\nCAR DETAILS ADDED SUCCESSFULLY!\n";
}
 void display()
 {
     cout<<"\n\nOWNER NAME\t: "<<oname<<endl;
     cout<<"CONTACT NUMBER\t: "<<pno<<endl;
     cout<<"STATE\t\t: "<<state<<endl;
     cout<<"CAR NAME\t: "<<cmodel<<endl;
     cout<<"CAR NUMBER\t: "<<cno<<endl;
 }
 void form()
 {
     cout<<"\n What is the glitch in your car?"<<endl<<"PRESS:"<<endl;
     cout<<"\n 0 for Brakes problem"<<endl<<"\n 1 for accelerator problem"<<endl<<"\n 2 for engine problem"<<endl<<"\n 3 for modification"<<endl<< "\n 4 for Denting painting"<<endl<<"\n 5 for wheel aligning"<<endl<<"\n 6 for washing"<<endl<<"\n 7 for full service";
     do{
     cin>>num1;
     switch(num1)
     {
 case 0:
    cout<<"As your car's brakes are not working well, so it may cause you approx. Rs1,400."<<endl;
    cout<<"THIS IS THE ESTIMATED COST, FULL PAYMENT WILL BE MADE AT THE END"<<endl;
    break;
 case 1:
    cout<<"As your car have some accelerator issues, so it may cause you approx. Rs1,000."<<endl;
    cout<<"THIS IS THE ESTIMATED COST, FULL PAYMENT WILL BE MADE AT THE END"<<endl;
    break;
 case 2:
    cout<<"As your car have some engine problem,  so it may cause you approx. Rs5,000."<<endl;
    cout<<"THIS IS THE ESTIMATED COST, FULL PAYMENT WILL BE MADE AT THE END"<<endl;
    break;
 case 3:
    cout<<"So you want your car to be be modified which may cause you approx. Rs10,000."<<endl;
    cout<<"THIS IS THE ESTIMATED COST, FULL PAYMENT WILL BE MADE AT THE END"<<endl;
    break;
 case 4:
    cout<<"Your car will be painted in approx Rs800."<<endl;
    cout<<"THIS IS THE ESTIMATED COST, FULL PAYMENT WILL BE MADE AT THE END"<<endl;
 case 5:
    cout<<"Your car's wheel aligning will cause you approx. Rs500."<<endl;
    cout<<"THIS IS THE ESTIMATED COST, FULL PAYMENT WILL BE MADE AT THE END"<<endl;
    break;
 case 6:
    cout<<"Washing your car may cause you approx. Rs200"<<endl;
    cout<<"THIS IS THE ESTIMATED COST, FULL PAYMENT WILL BE MADE AT THE END"<<endl;
    break;
 case 7:
    cout<<"Full service of your car may cause you approx. Rs15,000."<<endl;
    cout<<"THIS IS THE ESTIMATED COST, FULL PAYMENT WILL BE MADE AT THE END"<<endl;
    break;
     }
 }
 while(num1!=8);
 }
};
int main()
{
    fstream FILE;
    fstream FILE1;
    car c;
    int a,b,i,j,choice,location,count1,count2,count3=0;
    char phone[10],cno1[20],cdd1[10],cdd2[10];
    system("color 1f ");
    cout<<"\t \t \t \t \t WELCOME TO APNA CAR WORKSHOP";
    cout<<" \n \t \t \t \t \t    TIMINGS- 9am to 10pm";
    do
    {
    cout<<"\n\t-------MENU-------\n\n\t1.ADD NEW CAR\n\t2.SEARCH CARS\n\t3.EDIT CAR DETAILS\n\t4.DELETE CARS\n\t5.DISPLAY CAR DETAILS\n\t6.USER QUERY FORMS\n\t7.CHECK AVAILABILITY\n\t8.EXIT\n\tYOUR RESPONSE:\t";
    cin>>choice;
    switch(choice)
    {
    case 1:
        FILE.open("CAR1.txt",ios::in|ios::app);
        while(1)
        {
        FILE.read((char*)&c,sizeof(c));
        if(FILE.eof())
        break;
        else
        {
            count3++;
        };
    	}
        FILE.close();
       if(count3<=20)
        {
        FILE.open("CAR1.txt",ios::app);
        cout<<"\n \n \n **ENTER THE DETAILS OF THE CAR**"<<endl;
        c.in();
        FILE.write((char*)&c,sizeof(c));
        FILE.close();
    	}
    else
    {
        cout<<"YOUR WORKSHOP IS FULL"<<endl;
    }
    break;

    case 2:
    cout<<"\nSEARCH BY:\n1.DATE\n2.CAR NUMBER\t";
    cin>>a;
	switch(a)
    {
    case 1:
	FILE.open("CAR1.txt", ios::in);
	cout<<"\nENTER THE DATE WHOSE RECORDS ARE TO BE SEARCHED\nDD:";
	cin>>cdd1;
	cout<<"MM:";
	cin>>cdd2;
	while(FILE.eof()!=1)
	{
	FILE.read((char*)&c,sizeof(c));
	if(FILE.eof())
	break;
	if(stricmp(c.cdated,cdd1)==0 && stricmp(c.cdatem,cdd2)==0)
	{
	cout<<"\n\nOwner Name\t: "<<c.oname<<"\nPhone Number\t: "<<c.pno<<"\nState\t \t: "<<c.state<<"\nCar Name\t: "<<c.cmodel<<"\nCar Number\t: "<<c.cno<"\n";
	}
	}
	FILE.close();
	break;

	case 2:
	FILE.open("CAR1.txt", ios::in);
	cout<<"\nENTER THE CAR NUMBER TO BE SEARCHED";
	cin>>cno1;
	while(FILE.eof()!=1)
	{
	FILE.read((char*)&c,sizeof(c));
	if(FILE.eof())
	break;
	if(stricmp(c.cno,cno1)==0)
	{
	cout<<"\n\nOwner Name\t: "<<c.oname<<"\nPhone Number\t: "<<c.pno<<"\nState\t \t: "<<c.state<<"\nCar Name\t: "<<c.cmodel<<"\nCar Number\t: "<<c.cno<"\n";
	}
	}
	FILE.close();
	break;
	default:
		cout<<"\nINVALID CHOICE!";
		break;
	}
	break;
case 3:
			FILE.open("CAR1.txt",ios::in);
			FILE1.open("Temp.txt",ios::out);
			count1=0;
			cout<<"\nENTER THE PHONE NUMBER OF THE RECORD YOU WANT TO EDIT:";
			cin>>phone;
			while(FILE.eof()!=1)
			{
			FILE.read((char*)&c,sizeof(c));
			if(FILE.eof())
			break;
			if(stricmp(c.pno,phone)==0)
			{
				count1++;
			}
			if(stricmp(c.pno,phone)!=0)
			{
			FILE1.write((char*)&c,sizeof(c));
			}
			//i++;
			}
			if(count1==0)
			{
				cout<<"RECORD NOT FOUND";
				FILE.close();
				FILE1.close();
				remove("Temp.txt");
				break;
			}
			cout<<"EDIT THE CHOSEN RECORD:\n";
				fflush(stdin);
			cout<<"OWNER NAME:";
			gets(c.oname);
			fflush(stdin);
			cout<<"PHONE:";
			cin>>c.pno;
			cout<<"STATE:";
			cin>>c.state;
			fflush(stdin);
			cout<<"CAR NAME:";
			gets(c.cmodel);
			cout<<"CAR NUMBER:";
			cin>>c.cno;
			FILE1.write((char*)&c,sizeof(c));
			FILE.close();
			FILE1.close();
			cout<<"\nCHOSEN CONTACT EDITED SUCCESSFULLY!";
			remove("CAR1.txt");
			rename("Temp.txt","CAR1.txt");
break;

case 4:
			FILE.open("CAR1.txt",ios::in);
			FILE1.open("Temp.txt",ios::out);
			count2=0;
			cout<<"ENTER THE PHONE NUMBER OF THE RECORD YOU WANT TO DELETE:";
			cin>>phone;
			while(FILE.eof()!=1)
			{
			FILE.read((char*)&c,sizeof(c));
			if(FILE.eof())
			break;
			if(stricmp(c.pno,phone)==0)
			{
				count2++;
			}
			if(stricmp(c.pno,phone)!=0)
			{
			FILE1.write((char*)&c,sizeof(c));
			}
			//i++;
			}
			if(count2==0)
			{
				cout<<"RECORD NOT FOUND";
				FILE.close();
				FILE1.close();
				remove("Temp.txt");
				break;
			}
			FILE.close();
			FILE1.close();
			cout<<"\nCHOSEN CONTACT DELETED SUCCESSFULLY!"<<endl;
			remove("CAR1.txt");
			rename("Temp.txt","CAR1.txt");
			break;

case 5:
    FILE.open("CAR1.txt",ios::in);
    if(!FILE)
    {
    cout<<"No record present";
    break;
    }
    while(1)
    {
        FILE.read((char*)&c,sizeof(c));
        if(FILE.eof())
        break;
        c.display();
    }
    FILE.close();
            break;
case 6:
    c.form();
    break;
case 7:
	cout<<"\n1.CARS DELIVERED\n2.CARS NOT DELIVERED\n3.CARS IN THE GARAGE (SERVICING)\nYOUR RESPONSE:\t";
	cin>>b;
	switch(b)
	{
	case 1:
	FILE.open("CAR1.txt", ios::in);
	while(FILE.eof()!=1)
	{
	FILE.read((char*)&c,sizeof(c));
	if(FILE.eof())
	break;
	if(stricmp(c.status,"1")==0)
	{
	cout<<"\n\nOwner Name\t: "<<c.oname<<"\nPhone Number\t: "<<c.pno<<"\nState\t \t: "<<c.state<<"\nCar Name\t: "<<c.cmodel<<"\nCar Number\t: "<<c.cno<"\n";
	}
	}
	FILE.close();
	break;
	case 2:
	FILE.open("CAR1.txt", ios::in);
	while(FILE.eof()!=1)
	{
	FILE.read((char*)&c,sizeof(c));
	if(FILE.eof())
	break;
	if(stricmp(c.status,"2")==0)
	{
	cout<<"\n\nOwner Name\t: "<<c.oname<<"\nPhone Number\t: "<<c.pno<<"\nState\t \t: "<<c.state<<"\nCar Name\t: "<<c.cmodel<<"\nCar Number\t: "<<c.cno<"\n";
	}
	}
	FILE.close();
	break;
	case 3:
	FILE.open("CAR1.txt", ios::in);
	while(FILE.eof()!=1)
	{
	FILE.read((char*)&c,sizeof(c));
	if(FILE.eof())
	break;
	if(stricmp(c.status,"3")==0)
	{
	cout<<"\n\nOwner Name\t: "<<c.oname<<"\nPhone Number\t: "<<c.pno<<"\nState\t\t: "<<c.state<<"\nCar Name\t: "<<c.cmodel<<"\nCar Number\t: "<<c.cno<"\n";
	}
	}
	FILE.close();
	break;
	default:
		cout<<"\nINVALID INPUT";
		break;
	}
	break;
case 8:
	exit(0);
	break;
default:
cout<<"INVALID INPUT";
}
}while(choice!=8);
}
