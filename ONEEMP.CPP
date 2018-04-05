// file name -> oneemp.cpp

/****** Function to display all the details of a single employee ******/
/******		      master as well as trasaction details           ******/
void disp_one()
{
	clrscr();
	fstream in1 , in2;
	in1.open("off_det.dat" , ios::binary | ios::ate | ios::in );
	in2.open("attend.dat" , ios::binary | ios::ate | ios::in );
	in1.seekg(0);
	in2.seekg(0);
	data d1;
	attendence a1;
	in1.read((char *) &d1, sizeof(d1));
	in2.read((char *) &a1, sizeof(a1));
	cout<<"\n\t\t\t    INDIVIDUAL EMPLOYEE";
	cout<<"\n\t\t\t    ===================\n";
	cout<<"\n\tEnter Employee code : ";
	int cecode;
	cin>>cecode;
	cout<<"\tEnter Year          : ";
	int cyear;
	cin>>cyear;
	while(in1)
	{
		if (d1.ecode==cecode)
		{
			d1.putdata();
			cout<<"\n\t------------------------------------------------------";
			break;
		}
		in1.read((char *) &d1, sizeof(d1));
	}
	cout<<"\n\tYEAR   MONTH   CLA   ELA   LWP   NOD-WK   ADVANCE\n";
	cout<<"\t------------------------------------------------------";
	while(in2) // loop to check the desired year
	{
		if (a1.ecode==cecode && a1.year==cyear)
		{
			a1.putdata();
		}
		in2.read((char *) &a1, sizeof(a1));
	}
	getch();
}
