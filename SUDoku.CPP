#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

int a[9][9];
int small[9],i,j,k=0,flag=0;

void boxcheck()     //checks for duplicate values in the internal squares//
{
for(i=0;i<9;i++)
for(j=i+1;j<9;j++)
if(small[i]==small[j])
{cout<<"boxes not in order"<<endl;
sleep(3);
exit(0);}}

void convert(int c,int d)  //converts 2d array of internal square into a 1d array//
{k=0;
for(int x=c;x<c+3;x++)
for(int y=d;y<d+3;y++)
{small[k]=a[x][y];
if(k<9)
{k++;}}
}

void incheck()     //takes input checks if rows and columns are in order and calls functions check() and boxcheck()//
{
cout<<"enter elements for sudoku"<<endl;
for(i=0;i<9;i++)
for(j=0;j<9;j++)
{cin>>a[i][j];
if((a[i][j]>9)||(a[i][j]<0))
while((a[i][j]>9)||(a[i][j]<0))
{a[i][j]=0;
cout<<"invalid input!!! please enter correct value"<<endl;
cin>>a[i][j];}}

for(i=0;i<9;i++)    //loops for checking duplicate values in rows//
for(j=0;j<9;j++)
for(k=j+1;k<9;k++)
{if(a[i][j]==a[i][k])
flag=1;
break;}

if(flag==1)
{cout<<"rows are not in order"<<endl;
sleep(3);
exit(0);}
else
cout<<endl<<"rows are in order"<<endl;

flag=0;


for(i=0;i<9;i++)    //loops for checking duplicate values in columns//
for(j=0;j<9;j++)
for(int k=j+1;k<9;k++)
{if(a[j][i]==a[k][i])
flag=1;
break;}

if(flag==1)
{cout<<"columns are not in order"<<endl;
sleep(3);
exit(0);}
else
cout<<"column are in order"<<endl<<endl;

for(int w=0;w<9;w=w+3)  //loops for accessing values from the 9 smaller internal squares and checking them for duplicate values//
{for(int v=0;v<9;v=v+3)
{convert(w,v);
boxcheck();}}
}

void main()
{clrscr();
incheck();
cout<<"true";
getch();}
