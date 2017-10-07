#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int i;
bool check;
void E(char *string);
void E1(char *string);
void T(char *string);
void T1(char *string);
void F(char *string);
void advance();

int main()
{
	char string[20];
	i = 0;
	check = true;
	cout << "Enter the String" << endl;
	cin >> string;
	E(string);
	if(string[i] == '\0' && check)
		cout << "correct String" << endl;
	else
		cout << "Incorrect String" << endl;
	return 0;
}

void advance()
{
	i++;
};

void E(char *string)
{
	T(string);
	E1(string);
};
	
void E1(char *string)
{
	if(string[i] == '+')
	{
		advance();
		T(string);
		E1(string);
	}
};

void T(char *string)
{
	F(string);
	T1(string);
};

void T1(char *string)
{
	if(string[i] == '*')
	{
		advance();
		F(string);
		T1(string);
	}	
};

void F(char *string)
{
	if(string[i] == 'a')
		advance();
	else if(string[i] == '(')
	{
		advance();
		E(string);
		if(string[i] == ')')
			advance();
		else
			check = false;
	}
	else
		check = false;
};

