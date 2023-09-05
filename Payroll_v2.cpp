#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <ctype.h>
#include <ctime>
#define max 50

using namespace std;

class employee;
class PayrollMgmt;
int num = 0;
void gotoXY(int, int);
void Cdelay(int);
void border(int, int, int, int);
void borderNoDelay(int, int, int, int);
void loginFrame(int, int, int, int);
void setWindowSize(int, int);
void intro();
void login();
void loading();
void menu();

void insertRecords(PayrollMgmt &pmgt);
void editRecords(PayrollMgmt &pmgt);
void editmenu();
void editname(PayrollMgmt &pmgt, int);
void editcode(PayrollMgmt &pmgt, int);
void editdes(PayrollMgmt &pmgt, int);
void editexp(PayrollMgmt &pmgt, int);
void editage(PayrollMgmt &pmgt, int);
void editsalary(PayrollMgmt &pmgt, int);
void displayRecords(PayrollMgmt &pmgt);
void displayRecords(PayrollMgmt &pmgt, int numOfRecords);
void deleteRecords(PayrollMgmt &pmgt);
void search(PayrollMgmt &pmgt);
void saveRecords(PayrollMgmt &pmgt);
void getrecords(PayrollMgmt &pmgt);
void displayPayslip(PayrollMgmt &pmgt);

bool isFilePresent();

class employee
{
public:
	char name[20];
	int code;
	char designation[20];
	int exp;
	int age;
	int salary;
	char AnyLoan;
	int HRA;
	int PF;
	int tax;
	int MealAllowance;
	int TransportAllowance;
	int MedicalAllowance;
	int LoanBalance;
	int LoanDebit;
	int grosspay;
	int workingHours;
	int DA;
};

class PayrollMgmt
{
private:
	employee emp[max], tempemp[max];
	clock_t time_req;
public:
	PayrollMgmt()
	{
		loading();
		cout << "\n\nInstantiating Clock...\n\n"
			 << endl;
		time_req = clock();
	}
	friend void insertRecords(PayrollMgmt &pmgt);
	friend void editRecords(PayrollMgmt &pmgt);
	friend void editmenu();
	friend void editname(PayrollMgmt &pmgt, int);
	friend void editcode(PayrollMgmt &pmgt, int);
	friend void editdes(PayrollMgmt &pmgt, int);
	friend void editexp(PayrollMgmt &pmgt, int);
	friend void editage(PayrollMgmt &pmgt, int);
	friend void editsalary(PayrollMgmt &pmgt, int);
	friend void displayRecords(PayrollMgmt &pmgt);
	friend void displayRecords(PayrollMgmt &pmgt, int numOfRecords);
	friend void deleteRecords(PayrollMgmt &pmgt);
	friend void search(PayrollMgmt &pmgt);
	friend void saveRecords(PayrollMgmt &pmgt);
	friend void getrecords(PayrollMgmt &pmgt);
	friend void displayPayslip(PayrollMgmt &pmgt);
	~PayrollMgmt()
	{
		loading();
		cout << "\n\n Terminating Session...\n\n"
			 <<"Time Taken:- "<< time_req - clock() << endl;
	}
};

// Global Initialization
employee emp[max], tempemp[max];

void getrecords(PayrollMgmt &pmgt)
{
	FILE *fp;
	fp = fopen("Records.txt", "r");
	int c = 0;
	if (fp != NULL)
	{
		while (feof(fp) == 0)
		{
			fscanf(fp, "%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", &pmgt.emp[c].name, &pmgt.emp[c].code, &pmgt.emp[c].designation, &pmgt.emp[c].exp, &pmgt.emp[c].age, &pmgt.emp[c].salary, &pmgt.emp[c].AnyLoan, &pmgt.emp[c].HRA, &pmgt.emp[c].PF, &pmgt.emp[c].tax, &pmgt.emp[c].MealAllowance, &pmgt.emp[c].TransportAllowance, &pmgt.emp[c].MedicalAllowance, &pmgt.emp[c].LoanBalance, &pmgt.emp[c].LoanDebit, &pmgt.emp[c].grosspay, &pmgt.emp[c].workingHours, &pmgt.emp[c].DA);
			c++;
		}
		num = c;
	}
	fclose(fp);
	// cout << "##########################" << num << "##############################" << endl;
}

void saveRecords(PayrollMgmt &pmgt)
{
	if (num == 0)
	{
		system("del Records.txt");
	}
	else
	{
		FILE *fp;
		fp = fopen("Records.txt", "w");
		for (int i = 0; i < num; i++)
		{
			fprintf(fp, "%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pmgt.emp[i].name, pmgt.emp[i].code, pmgt.emp[i].designation, pmgt.emp[i].exp, pmgt.emp[i].age, pmgt.emp[i].salary, pmgt.emp[i].AnyLoan, pmgt.emp[i].HRA, pmgt.emp[i].PF, pmgt.emp[i].tax, pmgt.emp[i].MealAllowance, pmgt.emp[i].TransportAllowance, pmgt.emp[i].MedicalAllowance, pmgt.emp[i].LoanBalance, pmgt.emp[i].LoanDebit, pmgt.emp[i].grosspay, pmgt.emp[i].workingHours, pmgt.emp[i].DA);
		}
		fclose(fp);
	}
}

void Cdelay(int msec)
{
	long goal = msec + (clock());
	while (goal > (clock()))
		;
}

bool isFilePresent()
{
	FILE *fp;
	fp = fopen("Records.txt", "r");
	if (fp == NULL)
		return false;
	else
		return true;
}
void loginFrame1(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
	system("cls");
	gotoXY(xLenS, yLenS);
	printf("%c", 201);

	gotoXY(xLenS, yLenE);
	printf("%c", 200);

	for (int i = xLenS + 1; i <= xLenE - 1; i++) // Top and Bottom Border line
	{
		// Cdelay(0);
		gotoXY(i, yLenS);
		printf("%c", 205);
		// puts(style);
		gotoXY(i, yLenE);
		// puts(style);
		printf("%c", 205);
	}
	gotoXY(xLenE, yLenS);
	printf("%c", 187);
	gotoXY(xLenE, yLenE);
	printf("%c", 188);
	for (int i = yLenS + 1; i <= yLenE - 1; i++) // Left and Right Border Line
	{
		// Cdelay(20);
		gotoXY(xLenS, i);
		printf("%c", 186);
		// puts(style);
		gotoXY(xLenE, i);
		printf("%c", 186);
		// puts(style);
	}
	printf("\n\n");
}
void login()
{

	char UserName[30], Password[30], ch;
	int i = 0;
	gotoXY(20, 10);
	printf("Enter UserName : ");

	cin >> UserName;
	gotoXY(20, 12);
	cout << "Enter Password : ";
	while (1)
	{
		ch = getch();
		if (ch == 13)
			break;
		if (ch == 32 || ch == 9)
			continue;
		else
		{
			cout << "*";
			Password[i] = ch;
			i++;
		}
	}
	Password[i] = '\0';
	if (strcmp(UserName, "admin") == 0 && strcmp(Password, "password") == 0)
	{
		system("cls");
		loginFrame1();
		gotoXY(27, 10);
		cout << "Login Success!!!";
		gotoXY(21, 12);
		cout << "Will be redirected in 3 Seconds...";
		gotoXY(56, 12);
		Cdelay(1000);
		gotoXY(44, 12);
		cout << "\b \b2";
		gotoXY(56, 12);
		Cdelay(1000);
		gotoXY(44, 12);
		cout << "\b \b1";
		gotoXY(56, 12);
		Cdelay(1000);
	}
	else
	{
		system("cls");
		loginFrame1();
		gotoXY(27, 10);
		printf("Access Denied!!!\a");
		gotoXY(21, 12);
		cout << "Will be redirected in 3 Seconds...";
		gotoXY(56, 12);
		Cdelay(1000);
		gotoXY(44, 12);
		cout << "\b \b2";
		gotoXY(56, 12);
		Cdelay(1000);
		gotoXY(44, 12);
		cout << "\b \b1";
		gotoXY(56, 12);
		Cdelay(1000);
		system("cls");
		loginFrame1();
		login();
	}
}
void setWindowSize(int width = 670, int height = 445)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoXY(int X, int Y)
{
	COORD coordinates;
	coordinates.X = X;
	coordinates.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void borderNoDelay(int xLenS = 2, int yLenS = 2, int xLenE = 76, int yLenE = 24)
{
	system("cls");
	gotoXY(xLenS, yLenS);
	printf("%c", 201);

	gotoXY(xLenS, yLenE);
	printf("%c", 200);

	for (int i = xLenS + 1; i <= xLenE - 1; i++) // Top and Bottom Border line
	{
		gotoXY(i, yLenS);
		printf("%c", 205);
		gotoXY(i, yLenE);
		printf("%c", 205);
	}
	gotoXY(xLenE, yLenS);
	printf("%c", 187);
	gotoXY(xLenE, yLenE);
	printf("%c", 188);
	for (int i = yLenS + 1; i <= yLenE - 1; i++) // Left and Right Border Line
	{
		gotoXY(xLenS, i);
		printf("%c", 186);
		gotoXY(xLenE, i);
		printf("%c", 186);
	}
	printf("\n\n");
}
void border(int xLenS = 2, int yLenS = 2, int xLenE = 76, int yLenE = 22)
{
	system("cls");
	gotoXY(xLenS, yLenS);
	printf("%c", 201);

	gotoXY(xLenS, yLenE);
	printf("%c", 200);

	for (int i = xLenS + 1; i <= xLenE - 1; i++) // Top and Bottom Border line
	{
		Cdelay(15);
		gotoXY(i, yLenS);
		printf("%c", 205);
		// puts(style);
		gotoXY(i, yLenE);
		// puts(style);
		printf("%c", 205);
	}
	gotoXY(xLenE, yLenS);
	printf("%c", 187);
	gotoXY(xLenE, yLenE);
	printf("%c", 188);
	for (int i = yLenS + 1; i <= yLenE - 1; i++) // Left and Right Border Line
	{
		Cdelay(15);
		gotoXY(xLenS, i);
		printf("%c", 186);
		// puts(style);
		gotoXY(xLenE, i);
		printf("%c", 186);
		// puts(style);
	}
	printf("\n\n");
}
void loginFrame(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
	border(xLenS, yLenS, xLenE, yLenE);
}
void insertRecords(PayrollMgmt &pmgt)
{

	borderNoDelay();
	int i = num;
	int sal, PF, TAX, HRA, MealA, MedicalA, TransportA, LoanBal, LoanDeb, h, DA;
	char loan;
	num += 1;
	gotoXY(28, 4);
	printf("Insert New Record");
	gotoXY(10, 6);
	cout << "Name : ";
	// cin.getline(emp[i].name,sizeof(emp[i].name));
	cin >> pmgt.emp[i].name;
	gotoXY(10, 8);
	cout << "Code : ";
	cin >> pmgt.emp[i].code;
	gotoXY(10, 10);
	cout << "Designation : ";
	cin >> pmgt.emp[i].designation;
	gotoXY(10, 12);
	cout << "Years of Experience : ";
	cin >> pmgt.emp[i].exp;
	gotoXY(10, 14);
	cout << "Age : ";
	cin >> pmgt.emp[i].age;
	gotoXY(10, 16);
	cout << "Enter Working Hours : ";
	cin >> h;
	sal = h * 300;
	pmgt.emp[i].workingHours = h;
	do
	{
		gotoXY(10, 18);
		cout << "Any Loan (Y/N) ?: \b \b";
		loan = getche();
		if (loan == 'Y' || loan == 'y' || loan == 'n' || loan == 'N')
			break;
	} while (1);
	if (loan == 'y' || loan == 'Y')
	{
		gotoXY(10, 20);
		cout << "Enter Loan Balance : ";
		cin >> LoanBal;
	}
	else
	{
		LoanBal = 0;
	}
	gotoXY(14, 22);
	cout << "Recorded Succesfully...!!!";

	TAX = 0.04 * sal;
	DA = 1.20 * sal;
	PF = 0.12 * sal;
	HRA = sal * 0.27;
	MealA = 300;
	MedicalA = 300;
	TransportA = 300;
	LoanDeb = sal * 0.09;
	if (LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	pmgt.emp[i].salary = sal;
	pmgt.emp[i].DA = DA;
	pmgt.emp[i].tax = TAX;
	pmgt.emp[i].PF = PF;
	pmgt.emp[i].HRA = HRA;
	pmgt.emp[i].MealAllowance = MealA;
	pmgt.emp[i].MedicalAllowance = MedicalA;
	pmgt.emp[i].TransportAllowance = TransportA;
	pmgt.emp[i].LoanBalance = LoanBal - LoanDeb;
	pmgt.emp[i].AnyLoan = loan;
	pmgt.emp[i].LoanDebit = LoanDeb;
	pmgt.emp[i].grosspay = (sal + MealA + MedicalA + TransportA + HRA + DA) - (PF + TAX + LoanDeb);
	getch();
}

void intro()
{
	gotoXY(27, 4);
	printf("PAYROLL MANAGEMENT SYSTEM");
	gotoXY(25, 5);
	for (int i = 0; i < 29; i++)
		printf("%c", 196);
	gotoXY(20, 8);
	printf("Designed and Programmed by:");
	gotoXY(20, 9);
	for (int i = 0; i < 29; i++)
		printf("%c", 196);
	gotoXY(20, 11);
	printf("Mrityunjay Shukla, Mrityunjay Badoni");
	gotoXY(20, 13);
	printf("Jyostsna Ashok and Harsh Harin");
	gotoXY(20, 15);
	printf("Press Any key to continue...");
	getch();
}

void displayRecords(PayrollMgmt &pmgt)
{
	// system("cls");
	borderNoDelay();
	gotoXY(20, 4);
	printf("       ******** List of the Employees ********");
	gotoXY(6, 6);
	cout << "Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary " << endl;
	gotoXY(6, 7);
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 0, j = 8; i <= num - 1; i++, j++)
	{
		gotoXY(6, j);
		cout << pmgt.emp[i].name;
		gotoXY(19, j);
		cout << pmgt.emp[i].code;
		gotoXY(26, j);
		cout << pmgt.emp[i].designation;
		gotoXY(47, j);
		cout << pmgt.emp[i].exp;
		gotoXY(58, j);
		cout << pmgt.emp[i].age;
		gotoXY(66, j);
		cout << pmgt.emp[i].grosspay;
	}
	getch();
}

// Function Overloading
void displayRecords(PayrollMgmt &pmgt, int numOfRecords)
{
	// system("cls");
	borderNoDelay();
	gotoXY(20, 4);
	printf("       ******** List of the Employees ********");
	gotoXY(6, 6);
	cout << "Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary " << endl;
	gotoXY(6, 7);
	cout << "------------------------------------------------------------------" << endl;
	if (numOfRecords > num)
	{
		for (int i = 0, j = 8; i <= num - 1; i++, j++)
		{
			gotoXY(6, j);
			cout << pmgt.emp[i].name;
			gotoXY(19, j);
			cout << pmgt.emp[i].code;
			gotoXY(26, j);
			cout << pmgt.emp[i].designation;
			gotoXY(47, j);
			cout << pmgt.emp[i].exp;
			gotoXY(58, j);
			cout << pmgt.emp[i].age;
			gotoXY(66, j);
			cout << pmgt.emp[i].grosspay;
		}
	}
	else
	{
		for (int i = 0, j = 8; i <= numOfRecords - 1; i++, j++)
		{
			gotoXY(6, j);
			cout << pmgt.emp[i].name;
			gotoXY(19, j);
			cout << pmgt.emp[i].code;
			gotoXY(26, j);
			cout << pmgt.emp[i].designation;
			gotoXY(47, j);
			cout << pmgt.emp[i].exp;
			gotoXY(58, j);
			cout << pmgt.emp[i].age;
			gotoXY(66, j);
			cout << pmgt.emp[i].grosspay;
		}
	}
	getch();
}

void loading()
{
	system("cls");
	gotoXY(55, 20);
	printf("Loading...");
	gotoXY(50, 22);
	for (int i = 0; i < 20; i++)
	{
		Cdelay(200);
		printf("%c", 254);
	}
}
void menu()
{
	// system("cls");
	borderNoDelay();
	// gotoXY(0,0);
	// cout<<"Number of Records Avaliable : "<<num;
	gotoXY(16, 4);
	printf("*****  Payroll Management System 1.0 ***** ");
	gotoXY(12, 6);
	cout << "Press  i ----> Insert New Record.";
	gotoXY(12, 8);
	cout << "Press  e ----> Edit a Record.";
	gotoXY(12, 10);
	cout << "Press  d ----> Delete a Record.";
	gotoXY(12, 12);
	cout << "Press  s ----> Search a Record.";
	gotoXY(12, 14);
	cout << "Press  l ----> List The Employee Table.";
	gotoXY(12, 16);
	cout << "Press  p ----> Print Employee PaySlip.";
	gotoXY(12, 18);
	cout << "Press  q ----> Quit Program.";
	gotoXY(16, 22);
	cout << "Select Your Option ====> ";
}

void deleteRecords(PayrollMgmt &pmgt)
{
	for (int i = 0; i < num; i++)
	{
		pmgt.tempemp[i] = pmgt.emp[i];
	}
	// system("cls");
	borderNoDelay();
	int code;
	int check = -1;
	gotoXY(28, 4);
	printf("Delete a Record");
	gotoXY(10, 6);
	cout << "Enter the JobCode To Delete That Record  :";
	cin >> code;
	int i, j;
	for (i = 0; i <= num - 1; i++)
	{
		if (pmgt.emp[i].code == code)
		{
			check = i;
		}
	}
	if (check != -1)
	{
		for (i = 0, j = 0; i <= num - 1; i++, j++)
		{
			if (i == check)
			{
				i++;
			}
			pmgt.emp[j] = pmgt.tempemp[i];
		}
		num--;
	}
}

void search(PayrollMgmt &pmgt)
{
	// system("cls");
	borderNoDelay();
	int jobcode;
	bool found = false;
	gotoXY(10, 4);
	cout << "You can Search only through the Jobcode of an Employee";
	gotoXY(10, 6);
	cout << "Enter Code Of the Employee : ";
	cin >> jobcode;
	for (int i = 0; i <= num - 1; i++)
	{
		if (pmgt.emp[i].code == jobcode)
		{
			gotoXY(6, 8);
			cout << "Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary " << endl;
			gotoXY(6, 9);
			cout << "------------------------------------------------------------------" << endl;
			gotoXY(6, 11);
			cout << pmgt.emp[i].name;
			gotoXY(19, 11);
			cout << pmgt.emp[i].code;
			gotoXY(26, 11);
			cout << pmgt.emp[i].designation;
			gotoXY(47, 11);
			cout << pmgt.emp[i].exp;
			gotoXY(58, 11);
			cout << pmgt.emp[i].age;
			gotoXY(66, 11);
			cout << pmgt.emp[i].grosspay;
			found = true;
		}
		// else
		//
	}
	if (!found)
	{
		gotoXY(26, 11);
		cout << "No records Found...!!!\a";
	}
	getch();
}

void editmenu()
{
	// system("cls");
	borderNoDelay();
	gotoXY(28, 4);
	printf("Edit An Entry");
	gotoXY(10, 6);
	cout << "What Do You Want To edit";
	gotoXY(12, 8);
	cout << "n ---------> Name ";
	gotoXY(12, 9);
	cout << "c ---------> Code ";
	gotoXY(12, 10);
	cout << "d ---------> Designation";
	gotoXY(12, 11);
	cout << "e ---------> Experience ";
	gotoXY(12, 12);
	cout << "a ---------> Age";
	gotoXY(12, 13);
	cout << "s ---------> Salary";
	gotoXY(12, 14);
	cout << "q ---------> QUIT";
	gotoXY(10, 16);
	cout << "Enter Choice ---->>>  ";
}

void editname(PayrollMgmt &pmgt, int i)
{
	gotoXY(10, 18);
	cout << "Enter New Name----->  ";
	cin >> pmgt.emp[i].name;
}

void editcode(PayrollMgmt &pmgt, int i)
{
	gotoXY(10, 18);
	cout << "Enter New Job Code----->  ";
	cin >> pmgt.emp[i].code;
}
void editdes(PayrollMgmt &pmgt, int i)
{
	gotoXY(10, 18);
	cout << "enter new designation----->  ";
	cin >> pmgt.emp[i].designation;
}

void editexp(PayrollMgmt &pmgt, int i)
{
	gotoXY(10, 18);
	cout << "Enter new Years of Experience";
	cin >> pmgt.emp[i].exp;
}
void editage(PayrollMgmt &pmgt, int i)
{
	gotoXY(10, 18);
	cout << "Enter new Age ";
	cin >> pmgt.emp[i].age;
}

void editsalary(PayrollMgmt &pmgt, int i)
{
	int sal, PF, TAX, HRA, MealA, MedicalA, TransportA, LoanBal = emp[i].LoanBalance, LoanDeb, DA;
	char loan;
	gotoXY(10, 18);
	cout << "Enter new Salary ";
	cin >> sal;
	DA = 1.20 * sal;
	TAX = 0.04 * sal;
	PF = 0.12 * sal;
	HRA = 4000;
	MealA = 300;
	MedicalA = 300;
	TransportA = 300;
	LoanDeb = sal * 0.09;
	if (LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	pmgt.emp[i].salary = sal;
	pmgt.emp[i].tax = TAX;
	pmgt.emp[i].PF = PF;
	pmgt.emp[i].HRA = HRA;
	pmgt.emp[i].MealAllowance = MealA;
	pmgt.emp[i].MedicalAllowance = MedicalA;
	pmgt.emp[i].TransportAllowance = TransportA;
	pmgt.emp[i].LoanBalance = LoanBal;
	pmgt.emp[i].AnyLoan = loan;
	pmgt.emp[i].LoanDebit = LoanDeb;
	pmgt.emp[i].grosspay = (sal + MealA + MedicalA + TransportA + HRA + DA) - (PF + TAX + LoanDeb);
}

void editRecords(PayrollMgmt &pmgt)
{
	// system("cls");
	borderNoDelay();
	int jobcode;
	gotoXY(28, 4);
	printf("Edit a Record");
	int i;
	char option;
	gotoXY(10, 6);
	cout << "Enter the jobcode To Edit : ";
	cin >> jobcode;
	editmenu();
	for (i = 0; i <= num - 1; i++)
	{
		if (pmgt.emp[i].code == jobcode)
		{
			while ((option = cin.get()) != 'q')
			{
				switch (option)
				{
				case 'n':
					editname(pmgt, i);
					break;
				case 'c':
					editcode(pmgt, i);
					break;
				case 'd':
					editdes(pmgt, i);
					break;
				case 'e':
					editexp(pmgt, i);
					break;
				case 'a':
					editage(pmgt, i);
					break;
				case 's':
					editsalary(pmgt, i);
					break;
				}
				editmenu();
			}
		}
	}
}

void displayPayslip(PayrollMgmt &pmgt)
{
	system("cls");
	borderNoDelay();
	gotoXY(10, 4);
	int code, i;
	cout << "Enter Employee Job Code :";
	cin >> code;
	for (i = 0; i <= num - 1; i++)
	{
		if (pmgt.emp[i].code == code)
		{
			gotoXY(12, 6);
			cout << "Name : " << pmgt.emp[i].name;
			gotoXY(45, 6);
			cout << "Working Hours : " << pmgt.emp[i].workingHours << " Hrs";
			gotoXY(6, 8);
			cout << "Earnings :-";
			gotoXY(8, 10);
			cout << "Basic Pay : " << pmgt.emp[i].salary << endl;
			gotoXY(8, 12);
			cout << "HRA(27% of Basic): " << pmgt.emp[i].HRA << endl;
			gotoXY(8, 14);
			cout << "DA (120% of Basic):" << pmgt.emp[i].DA;
			gotoXY(8, 16);
			cout << "Meal Allowance : " << pmgt.emp[i].MealAllowance << endl;
			gotoXY(8, 18);
			cout << "Medical Alowance : " << pmgt.emp[i].MedicalAllowance << endl;
			gotoXY(8, 20);
			cout << "Transport Allowance : " << pmgt.emp[i].TransportAllowance << endl;
			gotoXY(40, 8);
			cout << "Deductions :- " << endl
				 << endl;
			gotoXY(42, 10);
			cout << "PF : " << pmgt.emp[i].PF << endl;
			gotoXY(42, 12);
			cout << "Tax : " << pmgt.emp[i].tax << endl;
			gotoXY(42, 14);
			int l = pmgt.emp[i].AnyLoan;
			char l2 = toupper(l);
			cout << "Loan Status : " << l2 << endl;
			gotoXY(42, 16);
			cout << "Loan Debit This Month : " << pmgt.emp[i].LoanDebit << endl;
			gotoXY(42, 18);
			cout << "Loan Balance : " << pmgt.emp[i].LoanBalance << endl;
			gotoXY(32, 22);
			cout << "Total Gross Pay : " << pmgt.emp[i].grosspay;
		}
	}
	getch();
}

int main()
{
	PayrollMgmt *pmgt = new PayrollMgmt();
	setWindowSize();
	border();
	intro();
	loading();
	loginFrame();
	login();
	menu();
	getrecords(*pmgt);
	// displayRecords(pmgt);
	char option;
	if (emp[0].code == 0 && isFilePresent())
		num--;
	while (1)
	{
		option = getch();
		switch (option)
		{
		case 'l':
			displayRecords(*pmgt);
			break;
		case 'i':
			insertRecords(*pmgt);
			break;
		case 'd':
			deleteRecords(*pmgt);
			break;
		case 'e':
			editRecords(*pmgt);
			break;
		case 's':
			search(*pmgt);
			break;
		case 'p':
			displayPayslip(*pmgt);
			break;
		case 'q':
			saveRecords(*pmgt);
			delete pmgt;
			exit(0);
		}
		menu();
	}

	return 0;
}
