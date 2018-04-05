// file name -> bal_leave.cpp

/********** funtion to calculate and display balance leaves **********/
/**********		    		of all employees				**********/
void data::bal_leave()
{
	int choice_check = 1;
	int scroll=0;
	clrscr();
	cout<<"\n\n\t\t    ________BALANCE LEAVE DETAILS________\n\n";
	cout<<"\tEcode    Employee Name        Casual Leave(s)  Earned Leave(s)\n";
	cout<<"\t--------------------------------------------------------------\n";
	fstream o_data("off_det.dat", ios::binary | ios::in | ios::ate);
	o_data.seekg(0);
	o_data.read((char *) this, sizeof(*this));
	while(o_data)
	{
		scroll++;
		cout<<setiosflags(ios::right)<<setw(13)<<ecode
			<<setw(4)<<" "
			<<setiosflags(ios::left)<<setw(20)<<ename
			<<setiosflags(ios::right)<<setw(9)<<cl
			<<setiosflags(ios::right)<<setw(17)<<el<<"\n";
		if(scroll==15) // to display the records screenfull at a time
		{
			scroll=0;
			cout<<"\n\tPress any key to continue...";
			box();
			gotoxy(62,1);
			cout<<"Q -> Quit";
			char choice;
			choice=getch();
			if (choice == 'q' || choice == 'Q')
			{
				choice_check=0;
				o_data.close();
				break;
			}
			clrscr();
			cout<<"\n\n\t\t    ________BALANCE LEAVE DETAILS________\n\n";
			cout<<"\tEcode    Employee Name        Casual Leave(s)  Earned Leave(s)\n";
			cout<<"\t--------------------------------------------------------------\n";
		}

		o_data.read((char *) this, sizeof(*this));
	}
	if(choice_check !=0)
	{
		box();
		gotoxy(62,1);
		cout<<"Q -> Quit";
		o_data.close();
		getch();
	}
}