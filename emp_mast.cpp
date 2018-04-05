// file name -> emp_mast.cpp

/**************** Function to Add New Employee ***************/
void data :: add_emp()
{
	ofstream out;
	out.open("off_det.dat" , ios::ate | ios::out | ios::binary);
/*	char ch = 'y';
	while (ch=='y' || ch=='Y')
	{   */
		clrscr();
		cout<<"\n\t\t   .......EMPLOYEE ENROLLMENT FORM.......\n\n";
		this->getdata();
		out.write((char *) this, sizeof(*this));
		cout<<"\n\n\n\t\t\t    EMPLOYEE  ADDED";
		getch();
/*		cout<<"\n\t\t\t     Add More(y/n) : ";
		cin>>ch;
	}*/
	out.close();
	clrscr();
}

/*************** Function to Remove an Employee ****************/
void data :: del_emp()
{
	clrscr();
	fstream inout , tinout;
	inout.open("off_det.dat",ios::ate | ios::in | ios::binary);
	tinout.open("d_temp.dat",ios :: out | ios::binary);
	cout<<"\n\n\t\t\t.......REMOVE AN EMPLOYEE.......\n";
	cout<<"\n\n\n\n\tEnter Employee Code : ";
	int cecode;    // for the desired ecode, cecode (current ecode)
	cin>>cecode;
	inout.seekg(0);
	inout.read((char *) this, sizeof(*this));
	int flag=0 ; // check flag for the existence of desired ecode
	while(inout)
	{
		if (cecode==ecode)
		{
			flag++;
			putdata();
			cout<<"\n\n\tSure for deletion <y/n> : ";
			char ch;
			cin>>ch;
			if (ch=='y' || ch=='Y')
			{
				flag++;
				inout.read((char *) this, sizeof(*this));
				attendence a1;
				fstream io_attend , tio_attend ;
				tio_attend.open
				("a_temp.dat",ios::in|ios::out|ios::ate|ios::binary);
				io_attend.open
				("attend.dat",ios::in|ios::out|ios::ate|ios::binary);
				io_attend.read((char *) &a1, sizeof(a1));
				while(io_attend)
				{
					if(cecode == a1.ecode)
						io_attend.read((char *) &a1, sizeof(a1));
					if(!io_attend.eof())
						tio_attend.write((char *) &a1, sizeof(a1));
					io_attend.read((char *) &a1, sizeof(a1));
				}
				io_attend.close();
				tio_attend.close();
				remove("attend.dat");
				rename("a_temp.dat","attend.dat");
			}
		}
		if(!inout.eof())
			tinout.write((char *) this, sizeof(*this));
		inout.read((char *) this, sizeof(*this));
	}
	inout.close();
	tinout.close();
	remove("off_det.dat");
	rename("d_temp.dat","off_det.dat");
	if (flag==0)
	{
		cout<<"\n\tThis E-code does not exist";
		getch();
	}
	else
	if (flag==2)
	{
		cout<<"\n\n\t\t\t\tEmployee Removed";
		getch();
	}
}

/**************** Fuction to Modify an Employee Details ****************/
void data :: mod_emp()
{
	clrscr();
	fstream inout ;
	inout.open("off_det.dat",ios::ate | ios::in | ios::out | ios::binary);
	cout<<"\n\t\t    .......MODIFY EMPLOYEE SCREEN.......\n";
	cout<<"\n\tEnter Employee Code : ";
	int cecode;    // for the desired ecode, cecode (current ecode)
	cin>>cecode;
	inout.seekg(0);
	inout.read((char *) this, sizeof(*this));
	int flag=0 ; // check flag for the existence of desired ecode
	while(inout)
	{
		if (cecode==this->ecode)
		{
			this->putdata();
			cout<<"\n\n\tSure for Modification <y/n> : ";
			char ch;
			ch = getche();
			/****** Code below within if block is for actual modification ******/
			if (ch=='y' || ch=='Y')
			{
				cout<<"\nIf you wish to modify a particular field then press 'y', when asked";
				cout<<"\n              and enter new value otherwise press 'n'";
				flag = flag++;
				char check;
				cout<<"\nModify Employee name <y/n> : ";
				check = getche();
				if (check=='y' || check=='Y')
				{
					cin.ignore();
					cout<<"\nEnter new name : ";
					cin.getline(this->ename,30);
				}
				cout<<"\nModify Designation <y/n> : ";
				check = getche();
				cin.ignore();
				if (check=='y' || check=='Y')
				{
					cout<<"\nEnter new designation : ";
					cin>>this->desig;
				}
				cout<<"\nModify Department <y/n> : ";
				check = getche();
				if (check=='y' || check=='Y')
				{
					cout<<"\nEnter new department : ";
					cin>>this->dept;
				}
				cout<<"\nModify Basic Salary <y/n> : ";
				check = getche();
				if (check=='y' || check=='Y')
				{
					cout<<"\nEnter new salary : ";
					cin>>this->basic;
				}
				cout<<"\nModify Address <y/n> : ";
				check = getche();
				if (check=='y' || check=='Y')
				{
					cout<<"\nEnter new Address : ";
					cin>>this->add;
				}
				int size = sizeof(*this);
				inout.seekp(-size,ios::cur);
				inout.write((char *) this, sizeof(*this));
				inout.close();
			}
			else
			if (ch=='n' || ch=='N')
			{
				flag = 2;
			}
			else
			{	cout<<"\n\tInvalid Data Please Re-enter ";
				getch();
				clrscr();
				cout<<"\n\t\t    .......MODIFY EMPLOYEE SCREEN.......\n";
				continue;
			}
		}
		inout.read((char *) this, sizeof(*this));
	}
	if (flag == 0)
	{
		cout<<"\n\tThis E-Code does not exist";
		getch();
	}
	else
	if (flag == 2)
	{}
	else
	{
		cout<<"\n\t\t\tEmployee Details Updated";
		getch();
	}
}







