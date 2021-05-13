#include<iostream>
using namespace std;
int main()
{
	int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
	float awt, atat;
	cout<<"Enter number of process: ";
	cin>>n;
	cout<<endl<<"Enter Burst Time:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"p"<<i+1<<": ";
		cin>>bt[i];
		p[i]=i+1;
	}
	for(i=1;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
			pos=j;	
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;
	for(i=0;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		
		wt[i]+=bt[j];
		total+=wt[i];
		
	}
	awt=(float)total/n;
	total=0;
	cout<<endl<<"Process\t   Burst Time   \t Waiting Time\tTurn Around Time";
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		cout<<endl<<"p"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
	}
	atat=(float)total/n;
	cout<<endl<<endl<<"Averge Waiting time= "<<awt;
	cout<<endl<<"Average Turnaround Time= "<<atat;
	return 0;
}
