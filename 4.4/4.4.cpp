#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <Windows.h>
using namespace std;
#pragma warning (disable : 4996)

void CreateTXT(char* fname,const int N,const int M)
{
	ofstream fout(fname);
	int tmp;
	fout << N << " x " << M << endl;
	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= M; j++) 
		{
			cin >> tmp;
			fout << tmp << " ";
		}
		fout << endl;
	}
}

void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}

int SecondTXT(char* fname, char* tname, const int N, const int M)  
{
	ofstream tout(tname);

	int max = 0;
	ifstream fin(fname);
	char s[100];
	char* w;
	int tmp;
	int k = 0;
	while (fin.getline(s, sizeof(s)))
	{
		w = strtok(s, " ");
		int max = 0;
		if (k == 0)
			tout << s;
		while (w != NULL)
		{
			if (w[0] != 'x')
				tmp = stoi(w);
			if (tmp > max)
			{
				max = tmp;
			}
			k++;
			w = strtok(NULL, " ");
		}
		tout << " " << max << endl;
	}
	return k;
}

int main()
{
	int d;
	char fname[100];
	char tname[100];
	int M, N;
	do
	{
		cout << endl;
		cout << "Slelect something" << endl;
		cout << "[1] Enter start data" << endl;
		cout << "[2] Create first TXT" << endl;
		cout << "[3] Create second file(if first created)" << endl;
		cout << "[4] Show first file" << endl;
		cout << "[5] Show second file" << endl;
		cout << "[9] Open File." << endl;
		cout << "[0] Exit" << endl << endl;
		cout << "Select : >> ";
		cin >> d;
		switch (d)
		{
		case 1:
			cout << "Enter first name file:"; cin >> fname;
			cout << "Enter second name file:"; cin >> tname;
			cout << "Enter N:"; cin >> N;
			cout << "Enter M:"; cin >> M;
			break;
		case 2:
			CreateTXT(fname ,N,M);
			
			break;
		case 3:
			SecondTXT(fname, tname, N, M);
			break;
		case 4:
			PrintTXT(fname);
			break;
		case 5:
			PrintTXT(tname);
			break;
		case 9:
			cout << "Enter name file : "; cin >> fname;
			break;
		case 0:
			d = 0;
			break;
		default:
			cout << "Error selected params" << endl;
			break;

		}

	} while (d != 0);

	return 0;
}	