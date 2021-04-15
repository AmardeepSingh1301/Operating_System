#include<iostream>
using namespace std;
int main()
{
	int n,bt[20],wt[20],tat[20],avwt = 0, avtat = 0;
	cout<<"Enter Total Number of Processor: ";
	cin>>n;
	cout<<endl<<"Enter Process Burst Time"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Process["<<i+1<<"]: ";
		cin>>bt[i];
	}
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=0;
		for(int j=0;j<i;j++)
		wt[i]+= bt[j];
	}
	cout<<endl<<"Process\t     Burst Time\t    Watimg Time\t    Turnarround Time";
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avwt+= wt[i];
		avtat+= tat[i];
		cout<<endl<<"Process["<<i+1<<"]"<<"\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
   // avwt != i;
	//avtat != i;
	cout<<endl<<endl<<"Average Wating Time: "<<avwt;
	cout<<endl<<"Average Turnaround Time: "<<avtat;
	
	return 0;	
}
