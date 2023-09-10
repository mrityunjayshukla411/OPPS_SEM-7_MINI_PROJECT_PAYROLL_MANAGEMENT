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

using namespace std;

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
bool isFilePresent();

void Cdelay(int msec)
{
	long goal = msec + (clock());
	while (goal > (clock()))
		;
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
	borderNoDelay();
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


bool isFilePresent()
{
	FILE *fp;
	fp = fopen("Records.txt", "r");
	if (fp == NULL)
		return false;
	else
		return true;
}

void editmenu()
{
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