// file name -> dept_sal.cpp

/******** function to calculate and display the department  ********/
/********         wise distribution of basic salary         ********/
void dept_sal()
{
	remove("dept.dat");
	data d1;
	char dname1[15],dname2[15];
	fstream in;
	ifstream tin;
	in.open("off_det.dat",ios::ate | ios::binary | ios::in | ios::out);
	in.seekg(0);
	in.read((char *) &d1, sizeof(d1));
	while(in)
	{
		 int ctr=0;
		 strcpy(dname1,d1.dept);
		 ifstream tin("dept.dat");
		 tin>>dname2;
		 if(strcmp(dname2,"")!=0)
		 {
			 while (tin.eof()==0)
			 {
				if(strcmp(strupr(dname1),strupr(dname2))==0)
				{
					ctr=1;
					break;
				}
				tin>>dname2;
			 }
		 }
		 tin.close();
		 if (ctr==0)
		 {
			 ofstream tout("dept.dat",ios::app);
			 tout<<dname1<<"\n";
			 tout.close();
		 }
		in.read((char *) &d1, sizeof(d1));
	}
	in.close();
	clrscr();
	cout<<"\n\n\t\t     DEPARTMENT WISE MONTHLY SALARY REPORT\n";
	cout<<"\t\t ---------------------------------------------\n\n";
	cout<<"        S.No       Department       Basic Salary       No of Employees\n";
	cout<<"\t--------------------------------------------------------------\n";
	int noe,count=1,scroll=0;
	int choice_check = 1;
	float tot;
	tin.open("dept.dat");
	tin>>dname2;
	while(tin.eof()==0)
	{
		in.open("off_det.dat",ios::ate | ios::binary | ios::in | ios::out);
		in.seekg(0);
		in.read((char *) &d1,sizeof(d1));
		tot=0,noe=0;
		while(in)
		{
			if(strcmp(strupr(d1.dept),strupr(dname2))==0)
			{
				tot=tot+d1.basic;
				noe=noe+1;
			}
			in.read((char *) &d1,sizeof(d1));
		}
		cout<<setiosflags(ios::right)<<setw(11)<<count++
			<<setw(8)<<" "
			<<setiosflags(ios::left)<<setw(17)<<dname2
			<<setiosflags(ios::right | ios::fixed)<<setw(12)<<tot
			<<setiosflags(ios::right)<<setw(14)<<noe<<"\n";
			scroll++;
		if(scroll==15) // to display screenfull of records at a time
		{
			scroll=0;
			cout<<"\tPress any key to continue...";
			box();
			gotoxy(62,1);
			cout<<"Q -> Quit";
			char choice;
			choice=getch();
			if (choice == 'q' || choice == 'Q')
			{
				choice_check = 0;
				in.close();
				break;
			}
			clrscr();
			cout<<"\n\n\t\t     DEPARTMENT WISE MONTHLY SALARY REPORT\n";
			cout<<"\t\t ---------------------------------------------\n\n";
			cout<<"        S.No       Department       Basic Salary       No of Employees\n";
			cout<<"\t--------------------------------------------------------------\n";
		 }
		 in.close();
		tin>>dname2;
	}
	if (choice_check !=0)
	{
		tin.close();
		box();
		gotoxy(62,1);
		cout<<"Q -> Quit";
		getch();
	}
}
