#include <iostream>
#include <string>
#include <fstream>
using namespace std;
static string usern;
static string empcat;
class expensesemp
{
	public:
		int ta,da;
		int extra;
		void actualexpenses()
		{
			int ch;
			int net;
			ofstream audit("auditbill.txt",ios::app);
			if(!audit)
			{
				audit.open("auditbill.txt");
			}
			audit<<::usern<<endl;
			cout<<"Enter your desired travelling allowances"<<endl;
			cin>>ta;
			cout<<"Enter your desired dearness allowances"<<endl;
			cin>>da;
			cout<<"Enter desired extra expenses"<<endl;
			cin>>extra;
			cout<<"Enter 1 to submit expenses to attend a workshop"<<endl;
			cout<<"Enter 2 to submit expenses to attend a sports event"<<endl;
			cout<<"Enter 3 to attend any conference"<<endl;
			cin>>ch;
			int c,day;
			switch(ch)
			{
				case 1:if(ta>3500)
					{
						cout<<"Limit Exceeded, you cannot enter travelling allowance more than 3500"<<"\nPlease reenter"<<endl;
						actualexpenses();
					}
					else {
						cout<<"Enter 1 if you stayed in capital else enter any other digit"<<endl;
						audit<<"TA for workshop--"<<ta<<endl;
						net+=ta;
						cin>>c;
						cout<<"Enter no. of days you spent"<<endl;
						cin>>day;
						if(c==1)
						{
							if(da>500*day)
							{
								cout<<"Limit Exceeded, you cannot enter dearness allowances more than 500 per day if you are staying in capital"<<endl;
								actualexpenses();
							}
							else {
								net+=(500*day);
								audit<<"DA for days- "<<day<<" is "<<(500*day)<<endl;
							}
						}
						else {
							if(da>400*day)
							{
								cout<<"Limit Exceeded, you cannot enter dearness allowances more than 400 per day if you are staying in other cities"<<endl;
								actualexpenses();
							}
							else {
								net+=(400*day);
								audit<<"DA for days- "<<day<<" is "<<(400*day)<<endl;
							}
						}
					}
					if(::empcat=="1"||::empcat=="one")
					{
						if(extra>2000)
						{
							cout<<"Limit exceeded, you cannot enter more than 2000 for category 1 employee"<<endl;
							actualexpenses();
						}
						else {
							net+=extra;
							audit<<"Extra Expenses are -"<<extra<<endl;
						}
					}
					else if(::empcat=="2"||::empcat=="two")
					{
						if(extra>1500)
						{
							cout<<"Limit exceeded, you cannot enter more than 1500 for category 2 employee"<<endl;
							actualexpenses();
						}
						else {
							net+=extra;
							audit<<"Extra Expenses are -"<<extra<<endl;
						}
					}
					else {
						if(extra>1000)
						{
							cout<<"Limit exceeded, you cannot enter more than 1000 for category 3 employee"<<endl;
							actualexpenses();
						}
						else {
							net+=extra;
							audit<<"Extra Expenses are -"<<extra<<endl;
						}
					}
				break;
				case 2: cout<<"Enter kilometers of where you travelled"<<endl;
					int km;
					cin>>km;
					if(km>2000)
					{
						cout<<"Limit Exceeded,you cannot enter more than 2000 Kilometers"<<endl;
						actualexpenses(); 
					}
					else {
					cout<<"Did you stay in capital, if yes enter 1,else enter any other digit"<<endl;
					cin>>c;
					cout<<"Enter no. of days"<<endl;
					cin>>day;
					if(c==1)
					{
						if(da>day*250)
						{
							cout<<"Limit exceeded, limit is 250 per day for staying in capitals"<<endl;
							actualexpenses();
						}
						else {
							net+=(day*250);
							audit<<"DA for days- "<<day<<" is "<<(250*day)<<endl;
						}
					}
					else {
						if(da>day*200)
						{
							cout<<"Limit exceeded, limit is 200 per day for staying in capitals"<<endl;
							actualexpenses();
						}
						else {
							net+=(day*200);
							audit<<"DA for days- "<<day<<" is "<<(200*day)<<endl;
						}
					}
					if(::empcat=="1"||::empcat=="one")
					{
						if(extra>2000)
						{
							cout<<"Limit exceeded, limit is 2000 for faculty or category 1 employee"<<endl;
							actualexpenses();
						}
						else {
							net+=extra;
							audit<<"Extra Expenses are -"<<extra<<endl;
						}
					}
					else {
						if(extra>0)
						{
							cout<<"You are not allowed to enter extra expenses"<<endl;
							actualexpenses();
						}
					}
				}
				break;
				case 3:cout<<"Enter Registration Fees"<<endl;
					int reg,tier;
					cin>>reg;
					cout<<"Enter org. tier no."<<endl;
					cin>>tier;
					if(tier==1)
					{
						if(reg>7000)
						{
							cout<<"Limit Exceeded, Please be in limit of 7000"<<endl;
							actualexpenses();
						}
						else {
							net+=reg;
							audit<<"Registration Fee --"<<reg<<endl;
						}
					}
					else if(tier==2)
					{
						if(reg>4000)
						{
							cout<<"Limit Exceeded, Please be in limit of 4000"<<endl;
							actualexpenses();
						}
						else {
							net+=reg;
							audit<<"Registration Fee --"<<reg<<endl;
						}
					}
					else if(tier==3)
					{
						if(reg>2500)
						{
							cout<<"Limit Exceeded, Please be in limit of 2500"<<endl;
							actualexpenses();
						}
						else {
							net+=reg;
							audit<<"Registration Fee --"<<reg<<endl;
						}
					}
					else{
						cout<<"Enter correct tier no. belonging to 1 2 or 3 only"<<endl;
						actualexpenses();
					}
					if(ta>3500)
					{
						cout<<"Limit exceeded, Enter TA according to 3500"<<endl;
						actualexpenses();
					}
					else {
						cout<<"Enter 1 if you stayed in capital else enter any other digit"<<endl;
						net+=ta;
						audit<<"TA for attending conference --"<<ta<<endl;
						cin>>c;
						cout<<"Enter no. of days you spent"<<endl;
						cin>>day;
						if(c==1)
						{
							if(da>500*day)
							{
								cout<<"Limit Exceeded, you cannot enter dearness allowances more than 500 per day if you are staying in capital"<<endl;
								actualexpenses();
							}
							else {
								net+=(500*day);
								audit<<"DA for days- "<<day<<" is "<<(500*day)<<endl;
							}
						}
						else {
							if(da>400*day)
							{
								cout<<"Limit Exceeded, you cannot enter dearness allowances more than 400 per day if you are staying in other cities"<<endl;
								actualexpenses();
							}
							else {
								net+=(400*day);
								audit<<"DA for days- "<<day<<" is "<<(400*day)<<endl;
							}
						}
					}
					if(::empcat=="1"||::empcat=="one")
					{
						if(extra>2000)
						{
							cout<<"Limit exceeded, you cannot enter more than 2000 for category 1 employee"<<endl;
							actualexpenses();
						}
						else {
							net+=extra;
							audit<<"Extra Expenses --"<<extra<<endl;
						}
					}
					else if(::empcat=="2"||::empcat=="two")
					{
						if(extra>1500)
						{
							cout<<"Limit exceeded, you cannot enter more than 1500 for category 2 employee"<<endl;
							actualexpenses();
						}
						else {
							net+=extra;
							audit<<"Extra Expenses --"<<extra<<endl;
						}
					}
					else {
						if(extra>1000)
						{
							cout<<"Limit exceeded, you cannot enter more than 1000 for category 3 employee"<<endl;
							actualexpenses();
						}
						else {
							net+=extra;
							audit<<"Extra Expenses --"<<extra<<endl;
						}
					}
				break;
				default:cout<<"Wrong choice, please enter again"<<endl;	
			}
			ofstream biller("actualbills.txt",ios::app);
			if(!biller)
			{
				biller.open("actualbills.txt");
			}
			biller<<::usern<<" "<<net<<endl;
			audit<<"Total Expense -- "<<net<<endl;
		}
		void submitapp()
		{
			int ch;
			int net;
			cout<<"Enter your desired travelling allowances"<<endl;
			cin>>ta;
			cout<<"Enter your desired dearness allowances"<<endl;
			cin>>da;
			cout<<"Enter desired extra expenses"<<endl;
			cin>>extra;
			cout<<"Enter 1 to submit expenses to attend a workshop"<<endl;
			cout<<"Enter 2 to submit expenses to attend a sports event"<<endl;
			cout<<"Enter 3 to attend any conference"<<endl;
			cin>>ch;
			int c,day;
			switch(ch)
			{
				case 1:if(ta>3500)
					{
						cout<<"Limit Exceeded, you cannot enter travelling allowance more than 3500"<<"\nPlease reenter"<<endl;
						submitapp();
					}
					else {
						cout<<"Enter 1 if you are going to stay in capital else enter any other digit"<<endl;
						net+=ta;
						cin>>c;
						cout<<"Enter no. of days you are going to spend"<<endl;
						cin>>day;
						if(c==1)
						{
							if(da>500*day)
							{
								cout<<"Limit Exceeded, you cannot enter dearness allowances more than 500 per day if you are staying in capital"<<endl;
								submitapp();
							}
							else {
								net+=(500*day);
							}
						}
						else {
							if(da>400*day)
							{
								cout<<"Limit Exceeded, you cannot enter dearness allowances more than 400 per day if you are staying in other cities"<<endl;
								submitapp();
							}
							else {
								net+=(400*day);
							}
						}
					}
					if(::empcat=="1"||::empcat=="one")
					{
						if(extra>2000)
						{
							cout<<"Limit exceeded, you cannot enter more than 2000 for category 1 employee"<<endl;
							submitapp();
						}
						else {
							net+=extra;
						}
					}
					else if(::empcat=="2"||::empcat=="two")
					{
						if(extra>1500)
						{
							cout<<"Limit exceeded, you cannot enter more than 1500 for category 2 employee"<<endl;
							submitapp();
						}
						else {
							net+=extra;
						}
					}
					else {
						if(extra>1000)
						{
							cout<<"Limit exceeded, you cannot enter more than 1000 for category 3 employee"<<endl;
							submitapp();
						}
						else {
							net+=extra;
						}
					}
				break;
				case 2: cout<<"Enter kilometers of where you are going to travel"<<endl;
					int km;
					cin>>km;
					if(km>2000)
					{
						cout<<"Limit Exceeded,you cannot enter more than 2000 Kilometers"<<endl;
						submitapp(); 
					}
					else {
					cout<<"Are you going to stay in capital, if yes enter 1,else enter any other digit"<<endl;
					cin>>c;
					cout<<"Enter no. of days"<<endl;
					cin>>day;
					if(c==1)
					{
						if(da>day*250)
						{
							cout<<"Limit exceeded, limit is 250 per day for staying in capitals"<<endl;
							submitapp();
						}
						else {
							net+=(day*250);
						}
					}
					else {
						if(da>day*200)
						{
							cout<<"Limit exceeded, limit is 200 per day for staying in capitals"<<endl;
							submitapp();
						}
						else {
							net+=(day*200);
						}
					}
					if(::empcat=="1"||::empcat=="one")
					{
						if(extra>2000)
						{
							cout<<"Limit exceeded, limit is 2000 for faculty or category 1 employee"<<endl;
							submitapp();
						}
						else {
							net+=extra;
						}
					}
					else {
						if(extra>0)
						{
							cout<<"You are not allowed to enter extra expenses"<<endl;
							submitapp();
						}
					}
				}
				break;
				case 3:cout<<"Enter Registration Fees"<<endl;
					int reg,tier;
					cin>>reg;
					cout<<"Enter org. tier no."<<endl;
					cin>>tier;
					if(tier==1)
					{
						if(reg>7000)
						{
							cout<<"Limit Exceeded, Please be in limit of 7000"<<endl;
							submitapp();
						}
						else {
							net+=reg;
						}
					}
					else if(tier==2)
					{
						if(reg>4000)
						{
							cout<<"Limit Exceeded, Please be in limit of 4000"<<endl;
							submitapp();
						}
						else {
							net+=reg;
						}
					}
					else if(tier==3)
					{
						if(reg>2500)
						{
							cout<<"Limit Exceeded, Please be in limit of 2500"<<endl;
							submitapp();
						}
						else {
							net+=reg;
						}
					}
					else{
						cout<<"Enter correct tier no. belonging to 1 2 or 3 only"<<endl;
						submitapp();
					}
					if(ta>3500)
					{
						cout<<"Limit exceeded, Enter TA according to 3500"<<endl;
						submitapp();
					}
					else {
						cout<<"Enter 1 if you are going to stay in capital else enter any other digit"<<endl;
						net+=ta;
						cin>>c;
						cout<<"Enter no. of days you are going to spend"<<endl;
						cin>>day;
						if(c==1)
						{
							if(da>500*day)
							{
								cout<<"Limit Exceeded, you cannot enter dearness allowances more than 500 per day if you are staying in capital"<<endl;
								submitapp();
							}
							else {
								net+=(500*day);
							}
						}
						else {
							if(da>400*day)
							{
								cout<<"Limit Exceeded, you cannot enter dearness allowances more than 400 per day if you are staying in other cities"<<endl;
								submitapp();
							}
							else {
								net+=(400*day);
							}
						}
					}
					if(::empcat=="1"||::empcat=="one")
					{
						if(extra>2000)
						{
							cout<<"Limit exceeded, you cannot enter more than 2000 for category 1 employee"<<endl;
							submitapp();
						}
						else {
							net+=extra;
						}
					}
					else if(::empcat=="2"||::empcat=="two")
					{
						if(extra>1500)
						{
							cout<<"Limit exceeded, you cannot enter more than 1500 for category 2 employee"<<endl;
							submitapp();
						}
						else {
							net+=extra;
						}
					}
					else {
						if(extra>1000)
						{
							cout<<"Limit exceeded, you cannot enter more than 1000 for category 3 employee"<<endl;
							submitapp();
						}
						else {
							net+=extra;
						}
					}
				break;
				default:cout<<"Wrong choice, please enter again"<<endl;	
			}
			cout<<"The total Tentative amount is ---- "<<net<<endl;
			ofstream biller("advancebills.txt",ios::app);
			if(!biller)
			{
				biller.open("advancebills.txt");
			}
			biller<<::usern<<" "<<net<<endl;
			
		}
		bool search(string word) //search function for searching the name
		{
			ifstream dealf("status.txt"); //opening the file in read mode
			if(!dealf) //checking for all types of flags
			{
				dealf.open("status.txt"); //if file to open this will work
			}
			bool found=false; //default value
			string line; //temp string
			while(dealf >> line && found==false) //condition to read file and checking the name
			{
				if(line.compare(word)==0) //comparing the word with line from file
				{
					found = true; //if found this will break the while loop
				}
			}
			return found; //return search status
		}
		int count(string word) //search function for searching the name
		{
			ifstream dealf("status.txt"); //opening the file in read mode
			if(!dealf) //checking for all types of flags
			{
				dealf.open("status.txt"); //if file to open this will work
			}
			bool found=false; //default value
			string line; //temp string
			int count;
			while(dealf >> line && found==false) //condition to read file and checking the name
			{
				count++;
				if(line.compare(word)==0) //comparing the word with line from file
				{
					found = true; //if found this will break the while loop
				}
			}
			return count; //return search status
		}
		void checkstats()
		{
			int counter,flag;
			string line;
			ifstream check("status.txt");
			if(!check)
			{
				check.open("status.txt");
			}
			bool found = search(::usern);
			if(found==true)
			{
				counter = count(::usern);
				while(getline(check,line))
				{
					flag++;
					if(flag==counter)
					{
						cout<<line<<endl;
					}
				}
			}
			else {
				cout<<"You have not submitted any application"<<endl;
			}
		}
}exp;
class loggeremp
{
	public:
		string username; 
		string password;
		string inputusername;
		string inputpassword;
		string inputcat;
		void userregdo() //for making the registration and appending in the user data file
		{
			ofstream usersFile("useremp.txt", ios::app); //appending the file
			if(!usersFile.is_open())
			{
				usersFile.open("useremp.txt");
			}
			usersFile<<username<<" "<<password<<" "<<::empcat<<endl; //storing the username and pass in a line
			::usern = username; //storing the username
			usersFile.close();
		}
		void signupemp()
		{
			cout<<"Welcome, Please register\nEnter a username"<<endl;  //for processing the registration
			cin>>username;
			cout<<"Please enter a new Password";
			cin>>password;
			cout<<"Please enter your category"<<endl;
			cin>>::empcat;
		}
		void loginemp() //for login
		{
			cout<<"Please enter your username"<<endl;
			cin>>inputusername;
			cout<<"\nPlease enter your password"<<endl;
			cin>>inputpassword;
			cout<<"\nPlease enter your Category"<<endl;
			cin>>inputcat;
			string userpass = inputusername+" "+inputpassword+" "+inputcat; //making the same pattern to match the file content
			bool found = false;
			string line;
			ifstream usersFile;
			usersFile.open("useremp.txt", ios::app);
			if(usersFile.is_open()) //opening the file
			{
				while(getline(usersFile,line) && !found) //checking for contents of file.
				{
					if(line.compare(userpass) == 0) //using the string compare function to get results.
					{
						::usern = inputusername;
						::empcat = inputcat;
						found = true; //if found the loop will stop.
					}
				}
				usersFile.close();
				if(found) //if found the login is successful and will move to next stage.
				{
					cout<<"Login Attempt successful"<<userpass<<endl;
				}
				else {
					cout<<"Login failed, Enter correct details"<<endl;
					loginemp(); //if failed error will be displayed and recursively login function will be called again.
				}
			}	
		}
}emp;
class loggeradmin
{
	public:
		string username; 
		string password;
		string inputusername;
		string inputpassword;
		void userregdo() //for making the registration and appending in the user data file
		{
			ofstream usersFile("useradmin.txt", ios::app); //appending the file
			if(!usersFile.is_open())
			{
				usersFile.open("useradmin.txt");
			}
			usersFile<<username<<" "<<password<<endl; //storing the username and pass in a line
			::usern = username; //storing the username
			cout<<"Registered Successfully"<<endl;
			usersFile.close();
		}
		void signupadmin()
		{
			cout<<"Welcome, Please register\nEnter a username"<<endl;  //for processing the registration
			cin>>username;
			cout<<"Please enter a new Password";
			cin>>password;
		}
		void loginadmin() //for login
		{
			cout<<"Please enter your username"<<endl;
			cin>>inputusername;
			cout<<"\nPlease enter your password"<<endl;
			cin>>inputpassword;
			string userpass = inputusername+" "+inputpassword; //making the same pattern to match the file content
			bool found = false;
			string line;
			ifstream usersFile;
			usersFile.open("useradmin.txt", ios::app);
			if(usersFile.is_open()) //opening the file
			{
				while(getline(usersFile,line) && !found) //checking for contents of file.
				{
					if(line.compare(userpass) == 0) //using the string compare function to get results.
					{
						::usern = inputusername;
						found = true; //if found the loop will stop.
					}
				}
				usersFile.close();
				if(found) //if found the login is successful and will move to next stage.
				{
					cout<<"Login Attempt successful"<<userpass<<endl;
				}
				else {
					cout<<"Login failed, Enter correct details"<<endl;
					loginadmin(); //if failed error will be displayed and recursively login function will be called again.
				}
			}	
		}
}adm;
class adminexp
{
	public:
		void showactual()
		{
			ifstream billshow("actualbills.txt");
			if(!billshow)
			{
				billshow.open("actualbills.txt");
			}
			string line;
			cout<<"EMPLOYEE ID --- NET AMOUNT"<<endl;
			while(billshow >> line)
			{
				cout<<line<<endl;
			}	
		}
		void reviewadvance()
		{
			int ch;
			ifstream billshow("advancebills.txt");
			if(!billshow)
			{
				billshow.open("advancebills.txt");
			}
			string line;
			while(!billshow.eof())
			{
				getline(billshow,line);
				cout<<line<<endl;
				cout<<"Enter 1 to accept or any other digit to Reject"<<endl;
				cin>>ch;
				ofstream status("statusbill.txt");
				if(!status)
				{
					status.open("statusbill.txt");
				}
				if(ch==1)
				{
					status<<line<<" "<<"ACCEPTED"<<endl;
				}
				else
				{
					status<<line<<" "<<"REJECTED"<<endl;
				}
			}
		}
		void auditshow()
		{
			ifstream audit("auditbill.txt");
			if(!audit)
			{
				audit.open("auditbill.txt");
			}
			string line;
			while(getline(audit,line))
			{
				cout<<line<<endl;
			}
		}
}admexp;
main()
{
	cout<<"Hello There, Welcome to Eke's Expense Management System--"<<endl;
	cout<<"Please login or signup with your respective criteria"<<endl;
	cout<<"Enter 1 to login/signup through Admin id"<<endl;
	cout<<"Enter 2 to login/signup through employee id"<<endl;
	cout<<"Enter 3 to Exit"<<endl;
	int c,ch,pass;
	cin>>c;
	switch(c)
	{
		case 1:cout<<"Enter 1 to login through Admin ID"<<endl;
			cout<<"Enter 2 to signup through Admin ID"<<endl;
			cout<<"Enter 3 to exit"<<endl;
			cin>>ch;
			while(pass==0)
			{
				switch(ch)
				{
					case 1:adm.loginadmin();
					pass=1;
					break;
					case 2:adm.signupadmin();
					adm.userregdo();
					pass=1;
					break;
					case 3:pass=1;
					break;
					default:cout<<"Wrong choice, input again"<<endl;
				}
			}
			break;
		case 2:cout<<"Enter 1 to login through Employee ID"<<endl;
			cout<<"Enter 2 to signup though Employee ID"<<endl;
			cout<<"Enter 3 to exit"<<endl;
			pass=0;
			cin>>ch;
			while(pass==0)
			{
				switch(ch)
				{
					case 1:emp.loginemp();
					pass=1;
					break;
					case 2:emp.signupemp();
					emp.userregdo();
					pass=1;
					break;
					case 3:pass=1;
					break;
					default:cout<<"Wrong choice, input again"<<endl;
				}
			}
			break;
		case 3:exit(0);
		break;
		default:cout<<"Wrong choice, Enter again"<<endl;
	}
	if(::empcat!="")
	{
		cout<<"Enter 1 to show actual expenses portal"<<endl;
		cout<<"Enter 2 to submit advance application"<<endl;
		cout<<"Enter 3 to check status of applications"<<endl;
		cout<<"Enter 4 to exit"<<endl;
		cin>>c;
		switch(c)
		{
			case 1:exp.actualexpenses();
			break;
			case 2:exp.submitapp();
			break;
			case 3:exp.checkstats();
			break;
			case 4:exit(0);
			break;
			default:cout<<"Enter correct choice"<<endl;
		}
	}
	else {
		cout<<"Enter 1 to show actual expenses"<<endl;
		cout<<"Enter 2 to review advance application"<<endl;
		cout<<"Enter 3 to review audit bills"<<endl;
		cout<<"Enter 4 to exit"<<endl;
		cin>>c;
		switch(c)
		{
			case 1:admexp.showactual();
			break;
			case 2:admexp.reviewadvance();
			break;
			case 3:admexp.auditshow();
			break;
			case 4:exit(0);
			break;
			default:cout<<"Wrong choice, please enter again"<<endl;
		}
	}
}
