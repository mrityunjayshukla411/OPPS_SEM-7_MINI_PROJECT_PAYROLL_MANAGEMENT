#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "helper.cpp"
#include <time.h>
#include <iomanip>
#include <ctype.h>
#include <ctime>
#define max 50

using namespace std;

// Forward Functions and Classes
class employee;
class PayrollMgmt;
// Glogal variable
int num = 0;
// Call by reference and Call by value Usage
void insertRecords(PayrollMgmt &pmgt);
void editRecords(PayrollMgmt &pmgt);
void editsalary(PayrollMgmt &pmgt, int);
// Function Overloading
void displayRecords(PayrollMgmt &pmgt);
void displayRecords(PayrollMgmt &pmgt, int numOfRecords);
void deleteRecords(PayrollMgmt &pmgt);
void search(PayrollMgmt &pmgt);
void saveRecords(PayrollMgmt &pmgt);
void getrecords(PayrollMgmt &pmgt);
void displayPayslip(PayrollMgmt &pmgt);

class employee
{
public:
	char name[20], designation[20], AnyLoan;
	int code, exp, age, salary, HRA, PF, tax, MealAllowance, TransportAllowance, MedicalAllowance, LoanBalance, LoanDebit, grosspay, workingHours, DA;

	// Operator Overloading Usage
	int operator%(employee const &c1)
	{
		return (300 * c1.workingHours);
	}
};

class PayrollMgmt
{
private:
	// Array of objects
	employee emp[max], tempemp[max];
	clock_t time_req;

public:
	// Constructor Usage
	PayrollMgmt()
	{
		loading();
		cout << "\n\nInstantiating Clock...\n\n"
			 << endl;
		// This keyword usage
		this->time_req = clock();
	}
	// Friend Function Usage to access private variables of employee class
	friend void insertRecords(PayrollMgmt &pmgt);
	friend void editRecords(PayrollMgmt &pmgt);
	friend void editsalary(PayrollMgmt &pmgt, int);
	friend void displayRecords(PayrollMgmt &pmgt);
	friend void displayRecords(PayrollMgmt &pmgt, int numOfRecords);
	friend void deleteRecords(PayrollMgmt &pmgt);
	friend void search(PayrollMgmt &pmgt);
	friend void saveRecords(PayrollMgmt &pmgt);
	friend void getrecords(PayrollMgmt &pmgt);
	friend void displayPayslip(PayrollMgmt &pmgt);

	// Destructor Usage
	~PayrollMgmt()
	{
		loading();
		cout << "\n\n Terminating Session...\n\n"
			 << "Time Taken:- " << clock() - time_req << " msecs" << endl;
	}
};

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
}

void saveRecords(PayrollMgmt &pmgt)
{
	cout << "###############\n Num :- " << num << "\n###############" << endl;
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
	pmgt.emp[i].workingHours = h;
	sal = pmgt.emp[i] % pmgt.emp[i];
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

	TAX = 0.4 * sal;
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

void displayRecords(PayrollMgmt &pmgt)
{
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

void deleteRecords(PayrollMgmt &pmgt)
{
	for (int i = 0; i < num; i++)
	{
		pmgt.tempemp[i] = pmgt.emp[i];
	}
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
	}
	if (!found)
	{
		gotoXY(26, 11);
		cout << "No records Found...!!!\a";
	}
	getch();
}

void editRecords(PayrollMgmt &pmgt)
{
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
					gotoXY(10, 18);
					cout << "Enter New Name----->  ";
					cin >> pmgt.emp[i].name;
					break;
				case 'c':
					gotoXY(10, 18);
					cout << "Enter New Job Code----->  ";
					cin >> pmgt.emp[i].code;
					break;
				case 'd':
					gotoXY(10, 18);
					cout << "Enter new designation----->  ";
					cin >> pmgt.emp[i].designation;
					break;
				case 'e':
					gotoXY(10, 18);
					cout << "Enter new Years of Experience";
					cin >> pmgt.emp[i].exp;
					break;
				case 'a':
					gotoXY(10, 18);
					cout << "Enter new Age ";
					cin >> pmgt.emp[i].age;
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
			cout << "Deductions :- " << endl;
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
	// New keyword and Pointer usage
	PayrollMgmt *pmgt = new PayrollMgmt();
	setWindowSize();
	border();
	intro();
	loading();
	loginFrame();
	login();
	menu();
	getrecords(*pmgt);
	char option;
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
			// Delete Keyword Usage
			delete pmgt;
			exit(0);
		}
		menu();
	}
	return 0;
}