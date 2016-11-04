// InfixToPostfix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "StackType.h"
#include <string>

using namespace std;

ifstream ifile;
string infix;
StackType S1;
char postfix[10];
int num = -1;

StackType::StackType()
{
	top = -1;
}

bool StackType::isEmpty()const
{
	return(top == -1);
}

bool StackType::isFull() const
{
	return (top == MAX_ITEMS);
}

void StackType::Push(char c)
{
	if (isFull())
		return;
	top++;
	item[top] = c;
}

void StackType::Pop()
{
	if (isEmpty())
		return;
	else
		top--;
}

char StackType::Top()
{
	return item[top];
}

void ReadString(ifstream& filename) {
	ifile.open("InputFile.txt");

	if (!ifile.is_open())
	{
		cout << "Input file connection failed.Check if the file exists" << endl;
		return;
	}
	cout << "Fetching data" << endl;
	getline(ifile, infix);
	cout << infix << endl;
}

int weight (char opr)
{
	switch (opr)
	{
	case '*':
	case '/': return 2;
	case '+':
	case '-':return 1;
	default:return 0;
	}
}

void InfixToPostfixCon()
{
	char in_char;
	int i=0,k=0,type = 0;
	int length = infix.length();

	while (i != length)
	{
		in_char = infix[i];
		if (in_char == '(')
		{
			S1.Push(in_char);
			i++;
			continue;
		}
		if (in_char == ')')
		{
			while (!S1.isEmpty() && S1.Top() != '(' && S1.Top() != ')')
			{
					postfix[k] = S1.Top();
					k++;
					S1.Pop();
			}	
			if(S1.Top() == '(')
				S1.Pop();
			i++;
			continue;
		}
		type = weight(in_char);
		if (type == 0)
		{
			postfix[k] = in_char;
			k++;
			i++;
			continue;
		}
		else
		{
			if (S1.isEmpty())
				S1.Push(in_char);
			else
			{
				while (!S1.isEmpty() && S1.Top() != '(' && S1.Top() != ')' && type <= weight(S1.Top())) {
					
						postfix[k] = S1.Top();
						k++;
					S1.Pop();
					continue;
				}
				if(S1.Top() != ')' )
					S1.Push(in_char);
			}
			i++;
		}
	}
	while (!S1.isEmpty())
	{
		if (S1.Top() != '(' && S1.Top() != ')')
		{ 
			postfix[k] = S1.Top();
			k++;
		}
		S1.Pop();
	}
}

void Print()
{
	cout << postfix << endl;
}

int main()
{
	
	ReadString(ifile);
	InfixToPostfixCon();
	Print();
	getchar();
	return 0;
}


