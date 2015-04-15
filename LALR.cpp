#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
class Stack
{
	char arr[1000];
	int topi;

	public:

	Stack()	{ topi = -1;	}
	void push(char ch)
	{
		topi++;
		arr[topi] = ch;
	}
	void pop()	{ topi--; }
	char top()	{ return arr[topi]; }
	int empty() { return topi == -1; }
};

char action[12][6][5] = {
			"s5","0","0","s4","0","0",
			"0","s6","0","0","0","acc",
			"0","r2","s7","0","r2","r2",
			"0","r4","r4","0","r4","r4",
			"s5","0","0","s4","0","0",
			"0","r6","r6","0","r6","r6",
			"s5","0","0","s4","0","0",
			"s5","0","0","s4","0","0",
			"0","s6","0","0","s11","0",
			"0","r1","s7","0","r1","r1",
			"0","r3","r3","0","r3","r3",
			"0","r5","r5","0","r5","r5"
					   };

int gt[12][3] = {0};
char production[6][2][10] = {
				"E","E+T",
				"E","T",
				"T","T*F",
				"T","F",
				"F","(E)",
				"F","i"
				 };

int prolen[6] = {3,1,3,1,3,1};
int accol[260];
int gtcol[260];

int main()
{               clrscr();
	char str[100];
	int i,j,k,l,m,n,t,len,ns,pn;
	int flag;

	gt[0][0] = 1;
	gt[0][1] = 2;
	gt[0][2] = 3;
	gt[4][0] = 8;
	gt[4][1] = 2;
	gt[4][2] = 3;
	gt[6][1] = 9;
	gt[6][2] = 3;
	gt[7][2] = 10;

	accol['i'] = 0;
	accol['+'] = 1;
	accol['*'] = 2;
	accol['('] = 3;
	accol[')'] = 4;
	accol['$'] = 5;

	gtcol['E'] = 0;
	gtcol['T'] = 1;
	gtcol['F'] = 2;
	{
		cin>>str;

		i = 0;
		flag = 1;

		Stack st;
		st.push(0);
		strcat(str,"$");

		while(1)
		{
			j = st.top();
			k = accol[str[i]];

			if(action[j][k][0] == 's')
			{
				ns = atoi(&action[j][k][1]);
				st.push(ns);
				i++;
				continue;
			}

			if(action[j][k][0] == 'r')
			{
				pn = atoi(&action[j][k][1]) - 1;

				len = prolen[pn];
				for(l=0;l<len;l++) st.pop();

				m = st.top();
				n = gtcol[production[pn][0][0]];
				ns = gt[m][n];
				st.push(ns);

				cout<<production[pn][0]<<"->"<<production[pn][1]<<endl;
				continue;
			}

			if(action[j][k][0] == 'a') break;

			flag = 0;
			break;
		}

		if(flag)
			cout<<"Accepted"<<endl;
		else
			cout<<"this string is not valid"<<endl;
		cout<<endl;
	}
	 getch();
	return 0;
}
