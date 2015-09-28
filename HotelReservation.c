#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<graphics.h>
#include<ctype.h>
#include<dos.h>
int choice;
void graph(void);
void basic(void);
class ROOMS
{
		public:
		int roomNo;
		int roomType;
		int roomStatus;
		int roomCharges;
		void Database();
		void status();
		int findRoomNo(int TYPE);
		void bookRoom(int roomNo);
		unsigned long retRoomCharges(int roomNo);
		void releaseRoom(int roomNo);

};

class CUSTOMER
{
		public:
		int Roomn;
		char name[30];
		char add[30];
		char phone[20];
		int daysStayed;
		int DAY,MONTH,YEAR;
		long amount;
		void searchRoomNo();
		void searchCust();
		void check_in();
		void check_out();
		void reports();
		void previous_Customer();
		};
int DAY, MONTH, YEAR;
void main()
   {
   char c;
   textcolor(GREEN);
   void graph(void);
   void enter_password();

   enter_password();
   clrscr();
   struct date d;
   getdate(&d);
		DAY=	d.da_day;
		MONTH=	d.da_mon;
		YEAR=	d.da_year;
do
	{
			clrscr();
			graph();
			gotoxy(32,3); cout<<"H I L L   V I E W";
			gotoxy(5,23); cout<<"Designed and Created by";
			gotoxy(30,24); cout <<"ARUN VENKATESH";
			gotoxy(30,25); cout <<"ANANDA VALLIAPPAN";
			gotoxy(30,26); cout <<"ATEETH KUMAR";
			gotoxy (5,12);cout<<"1. Search";
			gotoxy (5,13);cout<<"2. Check in";
			gotoxy (5,14);cout<<"3. Check out";
			gotoxy (5,15);cout<<"4. Room status";
			gotoxy (5,16);cout<<"5. Earnings";
			gotoxy (5,17);cout<<"6. Previous Customers";
			gotoxy (5,18);cout<<"0. Exit";
			gotoxy(30,21);	cout<<"Enter choice : ";
			do{c=getch();
			  if(c>=48 &&c<=54) {cout<<c;delay(500);}
			  }while(c<48 || c>54);
			switch(c)
				{ case '0':choice =0;break;
				case '1' : choice =1;break;
				case '2':choice=2;break;
				case '3':choice =3;break;
				case '4':choice=4;break;
				case '5':choice=5;break;
				case '6':choice=6;break;
				}
			closegraph();
			restorecrtmode();
switch(choice)
			{
		case 1:	{
			 int choice;
			 char ch;
			 do
			{
			clrscr();
			graph();
			gotoxy(32,3);cout<<"H I L L   V I E W";
			gotoxy(32, 5);cout<<"S E A R C H\n\n";
			gotoxy (5,12);cout<<"1. To search by NAME";
			gotoxy (5,13);cout<<"2. To search by ROOM NO.";
			gotoxy (5,14);cout<<"0. Exit";
			gotoxy(30,21);cout<<"Enter choice : ";
			do{
			  ch=getch();
			  if(ch>=48 &&ch<=50) {cout<<ch;delay(500);}
			  }while(ch<48 || ch>50);
			switch(ch)
				{ case '0':choice =0;break;
				case '1' : choice =1;break;
				case '2':choice=2;break;
				}

			closegraph();
			restorecrtmode();
			switch(choice)
			{
			case 1:	{
			CUSTOMER c;
			c.searchCust();
			break;
					}
			case 2:	{
			CUSTOMER c;
			c.searchRoomNo();
			break;
			}
			}
			}while(choice!=0);
			break;
				}
		case 2:	{
			CUSTOMER c;
			c.check_in();
			break;
				}

		case 3:	{
			CUSTOMER c;
			c.check_out();
			break;
				}
		case 4:	{
			ROOMS r;
			r.status();
			break;
				}
		case 5:	{
			CUSTOMER c;
			c.reports();
			break;
				}
		case 6: {
		CUSTOMER c;
			c.previous_Customer();
			break;
				}


		}
		}while(choice!=0);
}
void ROOMS::Database()
	   {
		ROOMS r;
		fstream fin("rooms", ios::binary | ios::in);
		fin.close();
		for (int i=1;i<=200;i++)
		{
			if(i<100)
			{
			r.roomNo=i;
			r.roomStatus = 0 ;
			r.roomCharges = 300;
			r.roomType= 0 ;
			fstream fout("rooms", ios::binary | ios:: app);
			fout.write((char*)&r, sizeof(r));
			fout.close();
			 }
			else if(i>=101 && i<=150)
		   {
			r.roomNo = i;
			r.roomStatus = 0 ;
			r.roomCharges = 500;
			r.roomType= 1 ;
			fstream fout("rooms", ios::binary | ios:: app);
			fout.write((char*)&r, sizeof(r));
			fout.close();
			}
			else if(i>150 && i<=200)
		   {
			r.roomNo = i;
			r.roomStatus = 0 ;
			r.roomCharges = 1000;
			r.roomType= 2 ;
			fstream fout("rooms", ios::binary | ios:: app);
			fout.write((char*)&r, sizeof(r));
			fout.close();
		   }
	   }
 }
 void CUSTOMER::searchCust()
 {
		clrscr();
		basic();
		struct date d;
		getdate(&d);
		DAY=	d.da_day;
		MONTH=	d.da_mon;
		YEAR=	d.da_year;
		int flag=0;
		char NAME[20];
		gotoxy(32,3); cout<<"H I L L   V I E W";
		gotoxy(26,5); cout<<"C U S T O M E R    D E T A I L";
		gotoxy (5,15);cout<<"Enter Customer's Name : ";
		gets(NAME);
		CUSTOMER c;
		fstream fin("cust", ios::binary | ios::in);
		while(fin.read((char*)&c, sizeof(c)))
		{
			if(strcmp(NAME, c.name)==0)
			{
			flag=1;
			gotoxy (40,15);cout<<"Room Number: "<<c.Roomn;
			gotoxy (40,16);cout<<"Customer Name : "<<c.name;
			gotoxy (40,17);cout<<"Address: "<<c.add;
			gotoxy (40,18);cout<<"Phone No. : "<<c.phone;
			gotoxy (40,19);cout<<"Check-in : "<<c.DAY<<"/"<<c.MONTH<<"/"<<c.YEAR;
			break;
			}
		}
		fin.close();
		if(flag==0)
		{
		  gotoxy(40,15);	cout<<"No such Name Found !!!";
		}
		getch();
		closegraph();
		restorecrtmode();
 }
 void CUSTOMER::searchRoomNo()
 {
		clrscr();
		basic();
		struct date d;
		getdate(&d);
		DAY=	d.da_day;
		MONTH=	d.da_mon;
		YEAR=	d.da_year;
		int roomno, flag=0;
		gotoxy(32,3); cout<<"H I L L  V I E W ";
		gotoxy(26,5);cout<<"C U S T O M E R   D E T A I L ";
		gotoxy(5,15);cout<<"Enter Room Number : ";
		cin>>roomno;
		CUSTOMER c;
		fstream fin("cust", ios::binary | ios::in);
		while(fin.read((char *) &c, sizeof(c)))
		{
			if(roomno==c.Roomn)
			{
			flag=1;
			gotoxy (40,15);cout<<"Room Number: "<<c.Roomn;
			gotoxy (40,16);cout<<"Customer Name : "<<c.name;
			gotoxy (40,17);cout<<"Address: "<<c.add;
			gotoxy (40,18);cout<<"Phone No. : "<<c.phone;
			gotoxy (40,19);cout<<"Check-in : "<<c.DAY<<"."<<c.MONTH<<"."<<c.YEAR;
			break;
			}
		}
		fin.close();
		if(flag==0)
		{
			gotoxy(40, 15);
			cout<<"No such Room No. Found !!!";
		}
		getch();
		closegraph();
		restorecrtmode();
}


 void CUSTOMER::reports()
 {
	clrscr();
	basic();
	CUSTOMER c;
	gotoxy(32,3); cout<<"H I L L   V I E W";
	gotoxy(21, 5);	cout<<"C U S T O M E R  S T A Y    S U M M A R Y";
	int i=11;
	unsigned  long AMOUNT=0;
	fstream fin("detail", ios::binary | ios::in);
	gotoxy(7,9);
	cout<<"R.No NAME\t ADDRESS\t AMOUNT\t DT OF CHECK-IN\tDAYS STAYED";
	while(fin.read((char*)&c, sizeof(c)))
	{
	gotoxy(7, i);	cout<<c.Roomn;
	gotoxy(12, i);	cout<<c.name;
	gotoxy(23, i);	cout<<c.add;
	gotoxy(37, i);
	if(c.amount==-1)
	cout<<"N/A";
	else
	{
	cout<<c.amount<<"/=";
	AMOUNT=AMOUNT+c.amount;
	}
	gotoxy(50, i);	cout<<c.DAY<<"/"<<c.MONTH<<"/"<<c.YEAR;
	gotoxy(68, i);
	if(c.daysStayed==-1)
	cout<<"N/A";
	else
	cout<<c.daysStayed;
	i++;
	if(i==22)
	{
	i=11;
	gotoxy(21, 5);	cout<<"C U S T O M E R   S T A Y    S U M M A R Y";
	gotoxy(7,9);
	cout<<"R.No NAMEADDRESS AMOUNT";
	cout<<"DT/OF CHECK-INDAYS STAYED";
	gotoxy(28,23);
	cout<<"<Press any key to continue>";
	getch();
	}
	}
	gotoxy(27, 25);
	gotoxy(27, 25);	cout<<"< Net Amount Rs.: "<<AMOUNT<<"/= >";
	fin.close();
	getch();
	closegraph();
	restorecrtmode();
}
 void ROOMS::status()
{
	clrscr();
	ROOMS r;
	gotoxy(8, 9);	cout<<"R O O M  S T A T U S";
	fstream fin("rooms", ios::binary | ios::in);
	gotoxy(5,20);cout<<"\nR.No    Room Type  Room Charges   Status"<<"\n\n";
	int maxPageSize = 25;
	int initPageSize = 4;
	for (int i=1;i<200;i++)
	{
	fin.read((char*)&r, sizeof(r));
	cout<<r.roomNo<<"\t";

	if(r.roomType==2)
	{
	cout<<"Deluxe  "<<"\t";
    }
	else if(r.roomType==1)
	{
	cout<<"semi-deluxe"<<"\t";
	}
	else
	{
	cout<<"Ordinary"<<"\t";
	}
	cout<<r.roomCharges<<"\t";


	if(r.roomStatus==1)
	cout<<"Occupied"<<"\n";
	else
   cout<<"--------"<<endl;

	initPageSize++;
	if(initPageSize == maxPageSize) {
		initPageSize = 1;

		getch();
	}
	}
	fin.close();
	getch();
}
 void CUSTOMER::check_in()
   {
	clrscr();
	int TYPE, roomno, flag;
	char c;
	struct date d;
	getdate(&d);
	DAY=d.da_day;
	MONTH=d.da_mon;
	YEAR=d.da_year;
	ROOMS r;
	basic();
	r.Database();
	gotoxy(32,3); cout<<"H I L L  V I E W";
	gotoxy(28,5);cout<<"C H E C K    I N";
	gotoxy(10, 10);cout<<"<Enter:: '2' for Deluxe, '1' for Semi Deluxe and '0' for Ordinary>";
	gotoxy(5,15);cout<<"Enter Room Type : ";

	do{
		c=getch();
		if(c>=48 &&c<=50) {cout<<c;delay(500);}
		}while(c<48 || c>50);
		switch(c)
		 {  case '0':TYPE =0;break;
			case '1' : TYPE =1;break;
			case '2':TYPE=2;break;
		 }

	gotoxy(20, 24);
	roomno=r.findRoomNo(TYPE);
	gotoxy(20, 24);
	if(roomno==-1)
	{
	cout<<"This Room Type is not available !!!";
	getch();
	return;
	}
	else if(roomno==0)
	{
	cout<<"Invalid room number !!!";
	getch();
	return;
	}
	else
	{
	CUSTOMER c;
	static char NAME[30], ADD[30], PHONE[20];
	fstream fout("cust", ios::binary | ios::app);
	gotoxy(5,16);	cout<<"Enter the Name : ";
	gets(NAME);
	gotoxy(5, 17); cout<<"Enter Address: ";
	gets(ADD);
	gotoxy(5, 18);	cout<<"Enter Phone No. : ";
	gets(PHONE);

	c.Roomn=roomno;
	c.daysStayed=-1;
	c.amount=-1;
	strcpy(c.name, NAME);
	strcpy(c.add, ADD);
	strcpy(c.phone, PHONE);
	c.DAY=DAY;
	c.MONTH=MONTH;
	c.YEAR=YEAR;
	fout.write((char*)&c, sizeof(c));
	fout.close();
	}
	r.bookRoom(roomno);
	closegraph();
	restorecrtmode();
}
void CUSTOMER::check_out()
{
	clrscr();
	basic();
	int roomno, flag=0;
            long double AMOUNT;
	gotoxy(32,3); cout<<"H I L L   V I E W";
	gotoxy(32,5);	cout<<"C H E C K  O U T";
	gotoxy(23,14);	cout<<"Enter Room No. to Vacate : ";
	cin>>roomno;
	CUSTOMER c;
	fstream fin("cust", ios::binary | ios::in);

	while(fin.read((char*)&c, sizeof(c)))
	{
		if(roomno==c.Roomn)
		{
		flag=1;
		break;
		}
	}
	fin.close();
	if(flag==0)
	{
		gotoxy(28, 17);
		cout<<"The Room is Unoccupied !!!";
		getch();
		return;
	}
	if(flag==1)
	{
		ROOMS r;
		r.releaseRoom(roomno);
		AMOUNT=r.retRoomCharges(roomno);
	}
	fstream fin1("cust", ios::binary | ios::in);
	fstream fout1("temp", ios::binary | ios::out);
	while(fin1.read((char*)&c, sizeof(c)))
	{
		if(roomno==c.Roomn && c.daysStayed==-1)
		{
		int D;
		gotoxy(23,16);	cout<<"Enter No. of Days stayed : ";
		cin>>D;
		c.daysStayed=D;
		c.amount=D*AMOUNT;
		gotoxy(23,18);	cout<<"Total Charges are Rupees : "<<c.amount;
		fout1.write((char*)&c, sizeof(c));
		}
		else
		fout1.write((char*)&c, sizeof(c));
	}
	fin1.close();
	fout1.close();
	remove("cust");
	rename("temp","cust");

	ofstream f1,f2;
	f1.open("temp", ios::binary | ios::out | ios::app);
	f2.open("detail",ios::binary | ios::out | ios::app);
	fstream fin2("cust", ios::binary | ios::in | ios::app);
	while(!fin2.eof())
	{
		fin2.read((char*)&c, sizeof(c));
		if(!fin2.eof())
		 {
		 if(roomno!=c.Roomn)
		 {
		 f1.write((char*)&c ,sizeof(c));
		 }
		 else
		 {
		 f2.write((char*)&c ,sizeof(c));
		 }
	    }
	}
	fin2.close();
	f1.close();
	f2.close();
	remove("cust");
	rename("temp","cust");

	getch();
	closegraph();
	restorecrtmode();
	}
int ROOMS::findRoomNo(int TYPE)
{
	ROOMS r;
	int RNO, flag=0;
	fstream fin("rooms", ios::binary | ios::in);
	while(fin.read((char*)&r, sizeof(r)))
	{
	   if(TYPE==r.roomType)
			{
			if(r.roomStatus==0)
				{
				RNO=r.roomNo;
				flag=1;
				break;
				}
			else
				flag=2;
		}
	}
	fin.close();
	if(flag==0)
	return 0;
	else if(flag==1)
	return RNO;
	else if(flag==2)
	return -1;
	return 0;
}
void ROOMS::bookRoom(int RNO)
{
	ROOMS r;
	fstream fin("rooms", ios::binary | ios::in);
	fstream fout("temp", ios::binary | ios::out);
	while(fin.read((char*)&r, sizeof(r)))
	{
	if(RNO==r.roomNo)
	{
	gotoxy(22,25);
	cout<<"Room No '"<<RNO<<"' has been booked";
	r.roomStatus=1;
	fout.write((char*)&r, sizeof(r));
	}
	else
	fout.write((char*)&r, sizeof(r));
	}
	fout.close();
	fin.close();
	remove("rooms");
	rename("temp","rooms");
	getch();
}
void ROOMS::releaseRoom(int RNO)
{
	ROOMS r;
	int NO_DAYS;
	fstream fin("rooms", ios::binary | ios::in);
	fstream fout("temp", ios::binary | ios::out);
	while(fin.read((char*)&r, sizeof(r)))
	{
	if(RNO==r.roomNo)
	{
	r.roomStatus=0;
    fout.write((char*)&r, sizeof(r));
    }
    else
    fout.write((char*)&r, sizeof(r));
    }
    fin.close();
    fout.close();
    remove("rooms");
    rename("temp","rooms");
}
unsigned long ROOMS::retRoomCharges(int RNO)
{
	ROOMS r;
	long double AMOUNT;
	fstream fin("rooms", ios::binary | ios::in);
	while(fin.read((char*)&r, sizeof(r)))
	{
	if(RNO==r.roomNo)
	{
	AMOUNT=r.roomCharges;
	break;
	}
	}
	fin.close();
	return AMOUNT;
}
void CUSTOMER::previous_Customer(void)
{
	clrscr();
	basic();
	CUSTOMER c;
	char NAME[30];
	gotoxy(32,3); cout<<"H I L L   V I E W";
	gotoxy(5,6);cout<<"Enter customer name: ";
	gets(NAME);
	fstream fin("detail", ios::binary | ios::in);
	while(fin.read((char*)&c, sizeof(c)))
	{
	if(strcmp(c.name,NAME)==0)
	{
		gotoxy (26,8);cout<<"Room Number: "<<c.Roomn;
		gotoxy (26,9);cout<<"Customer Name : "<<c.name;
		gotoxy (26,10);cout<<"Address: "<<c.add;
		gotoxy (26,11);cout<<"Phone No. : "<<c.phone;
	}
	}
	getch();
	closegraph();
	restorecrtmode();
}
void enter_password()
{
	 clrscr() ;
	 char pass[10],c;
	 int i =0;
	 gotoxy(25,18);cout <<"Enter the password : " ;
	 do{
	c= getch();
	if(c==8) {cout<<'\b'<<' '<<'\b';i--;}
	else if(c!=13) {cout<<'*';pass[i]=c;i++;}
	}while(c!=13);
    pass[i]='\0';

	 if (strcmp(pass,"hms")==0)
	  return ;
	 gotoxy(28,20);cout <<"   WRONG PASSWORD    " ;
	 getch() ;
	 exit(0) ;
	 }

void graph()
{
	int gd=DETECT,gm;
			initgraph(&gd,&gm,"C:/BORLANDC/bgi");
			setcolor(4);
			rectangle(0,0,636,476);
			rectangle(2,2,634,474);
			line(247,52,384,52);
			line(247,50,384,50);
			setbkcolor(0);
			setcolor(10);
			line(172,345,400,345);

}

void basic()
{
			int gd=DETECT,gm;
			initgraph(&gd,&gm,"C:/BORLANDC/bgi");
			setcolor(4);
			rectangle(0,0,636,476);
			rectangle(2,2,634,474);
			line(247,52,384,52);
			line(247,50,384,50);
			setbkcolor(0);

}
