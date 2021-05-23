#include<iostream>
using namespace std;
int main()
{
	int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n, total=0, pos, temp, avgwt, avgtat;
	cout<<"Enter Total Number Of Process: ";
	cin>>n;
	cout<<endl<<"Enter Burst Time and Priority:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<endl<<"P["<<i+1<<"]\n";
		cout<<"Burst Time: ";
		cin>>bt[i];
		cout<<"Priority: ";
		cin>>pr[i];
		p[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
	
		pos=i;
		for(j=i;j<n;j++)
		{
			if(pr[j]<pr[pos])
			pos=j;
		}
		temp=pr[i];
		pr[i]=pr[pos];
		pr[pos]=temp;
		
		temp=pr[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<n;j++)
		wt[i]+=bt[j];
		
		
		total+=wt[i];
	}
	avgwt=total/n;
	total=0;
	cout<<endl<<"Process\t Burst Time  \tWaiting Time\tTurn Around Time";
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];     //calaulate turn around time
		total+=tat[i];
		cout<<endl<<"P["<<p[i]<<"]\t      "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t   "<<tat[i];
	}
	avgtat=total/n;            //average turn around time
	cout<<endl<<endl<<"Average Wating Time= "<<avgwt;
	cout<<endl<<"Average Turn Around Time= "<<avgtat;
	return (0);
}
