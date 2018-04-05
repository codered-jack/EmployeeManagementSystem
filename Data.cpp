// file name -> Data.cpp

class data
{
	protected:
		int dd,mm,yy;   // Date of joining
		char ename[30]; // Name of employee
		char dept[15];  // Department name
		char desig[17]; // Designation of employee
		char add[30];   // Address of employee
		float basic;    // Basic Salary of employee
	public :
		int ecode;
		int el;          // Earned leave
		int cl;          // Casual leave
		void getdata();  // to get data about the employee while enrolling
		void putdata();  // to display the master details of employee
		void putdata1(); // same as putdata but without date of joining
		void add_emp();  // to enroll a new employee
		void del_emp();  // to retire an employee
		void mod_emp();  // to modify the details of an employee
		void disp_all(); // to display records of all employees
		void bal_leave();// to display the balance leaves of employees
		friend void disp_one(); // to display all the details of one employee
		friend void salary();   // to calculate and display the net salary
		friend void dept_sal(); // to calculate and display dept wise salary
};

void data::getdata()
{
	data d1;
	fstream in("off_det.dat",ios::in | ios::binary);
	in.seekg(0);
	in.read((char *) &d1 , sizeof(d1));
	if( in.eof() == 1 )
		d1.ecode = 1000;
	while(in)
	{
		in.read((char *) &d1 , sizeof(d1));
	}
	d1.ecode = d1.ecode + 1;
	in.close();
	ecode=d1.ecode;
	cout<<"\n\tEmployee code              : # ";
	cout<<ecode;
	cout<<"\n\n\tEmployee Name              : ";
	cin.getline(ename,30);
	cout<<"\n\tDesignation                : ";
	cin.getline(desig,15);
	cout<<"\n\tDepartment                 : ";
	cin>>dept;
	basic=2000;
	while(basic<2500)
	{
		cout<<"\n\tBasic Salary               :         \b\b\b\b\b\b\b\b";
		cin>>basic;
		if(basic<2500)
		{
			gotoxy(50,13);
			cout<<"Enter a value above 2499";
			getch();
			gotoxy(8,12);
			continue;
		}
		else
			break;
	}
	gotoxy(50,13);
	cout<<"                        ";
	cin.ignore();
	cout<<"\n\n\tAddress                    : ";
	cin.getline(add,30);
	el = 30;
	cl = 12;
	struct date d;
	getdate(&d);
	dd = d.da_day;
	mm = d.da_mon;
	yy = d.da_year;
	cout<<"\n\tDate of joining (dd-mm-yy) : ";
	cout<<dd<<"-"<<mm<<"-"<<yy;


}

void data::putdata()
{
	cout<<"\n\tEmployee No                : "<<ecode;
	cout<<"\n\tName                       : "<<ename;
	cout<<"\n\tDesignation                : "<<desig;
	cout<<"\n\tDepartment                 : "<<dept;
	cout<<"\n\tBasic                      : "<<basic;
	cout<<"\n\tAddress                    : "<<add;
	cout<<"\n\tDate of joining (dd-mm-yy) : ";
	cout<<dd<<"-"<<mm<<"-"<<yy;
}

void data::putdata1()
{
	cout<<"\n\tEmployee No  : "<<ecode;
	cout<<"\n\tName         : "<<ename;
	cout<<"\n\tDesignation  : "<<desig;
	cout<<"\n\tDepartment   : "<<dept;
	cout<<"\n\tBasic        : "<<basic;
	cout<<"\n\tAddress      : "<<add;
}