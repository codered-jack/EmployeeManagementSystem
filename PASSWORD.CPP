// file name -> Password.cpp

/************* Function for password authentication *************/
int password()
{
	clrscr();
	int authorised = 0;
	char password[10]="employee";  //Original password
	int i, j, flag = 1;
	char comp_pass[10];
	for (int l = 0; l <=9 ; l++ )
		comp_pass[l] = 0;
	while (flag <= 3 )  //Maximum no of times to be prompted for password
	{
		clrscr();
		gotoxy(30,10);
		cout<<"ENTER YOUR PASSWORD ";
		pass_screen();

		j = 0;
		while ( j <= 9 )
		{
			comp_pass[j] = getch();
			if (comp_pass[j] == 8)
			{
				if ( j >= 1)
				{
					cout<<'\b';  // '/b' For backspace
					cout<<' ';
					cout<<'\b';
					j--;
				}
				continue;
			}
			if (comp_pass[j]==13) //In place of 13 '\r' can also be used
			{
				comp_pass[j]=0;
				break;
			}
			cout<<"*";
			j = j + 1;
			if ( j == 10)
			{
				cout<<'\b';
				cout<<' ';
				cout<<'\b';
				j--;
			}
		}
		i=_fstrcmp(password,comp_pass);
		if (0==i)
		{
			clrscr();
			pass_screen();
			gotoxy(30,11);
			cout<<"Permission granted";
			gotoxy(26,19);
			textcolor(YELLOW+BLINK);
			cprintf("Press any key to continue...");
			textcolor(YELLOW);
			getch();
			authorised = 1;
			flag = 4;
		}
		else
		{
			clrscr();
			gotoxy(30,11);
			cout<<"INVALID PASSWORD!!! ";
			pass_screen();
			getch();
			clrscr();
			flag = flag + 1;
			if (flag == 4)
			{
				gotoxy(30,10);
				textcolor(RED);
				cprintf(" Unauthorized User");
				gotoxy(33,11);
				cprintf("Observed !!!");
				textcolor(YELLOW);
				pass_screen();
				gotoxy(26,19);
				cout<<"Press any key to return...";
				getch();
			}
		}
	}
	return (authorised);
}

//Function for the password screen.
void pass_screen()
{
	gotoxy(25,8);
	cout<<char(201);
	for (int i = 30 ; i <= 55; i++ )
		cout<<char(205);
	cout<<char(187);
	gotoxy(25,9);
	for ( i = 10; i <=14 ; i++ )
	{
		cout<<char(186);
		gotoxy(25,i);
	}
	cout<<char(200);
	for ( i = 30; i <= 55 ; i++ )
		cout<<char(205);
	cout<<char(188);
	for ( i = 9 ; i <= 13; i++ )
	{
		gotoxy(52,i);
		cout<<char(186);
	}
	gotoxy(34,12);
}
