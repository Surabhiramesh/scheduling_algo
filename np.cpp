#include<iostream>
using namespace std;
int main()
{
  int i,j,n,time,sum_wait=0,sum_turnaround=0;
  int smallest,at[10],bt[10],priority[10],remain;
  cout<<"Enter no of Processes : ";
  cin>>n;
  remain=n;
  for(i=0;i<n;i++)
  {
    cout<<"Enter arrival time, burst time and priority for process p"<<i+1<<"\t";
    cin>>at[i];
    cin>>bt[i];
    cin>>priority[i];
  }
  priority[9]=11;
  cout<<"\n\nProcess\t|Turnaround time|waiting time\n";
  for(time=0;remain!=0;)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time && priority[i]<priority[smallest] && bt[i]>0)
      {
        smallest=i;
      }
    }
    time+=bt[smallest];
    remain--;
    cout<<"P["<<smallest+1<<time-at[smallest]<<time-at[smallest]-bt[smallest];
    sum_wait+=time-at[smallest]-bt[smallest];
    sum_turnaround+=time-at[smallest];
    bt[smallest]=0;
  }
  cout<<"\nAvg waiting time ="<<sum_wait*1.0/n<<"\n";
  cout<<"Avg turnaround time = "<<sum_turnaround*1.0/n;
  return 0;
}
