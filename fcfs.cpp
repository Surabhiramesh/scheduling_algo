 #include <iostream>
 using namespace std; 
 /* First Come First Serve CPU Scheduling Algorithm  
   By Suraj Jha & Abhas Tandon  
 */  
 int wt[10],bt[10],at[10],tat[10],n;  
 float awt,atat;  
 void input(){  
        cout<<"Enter Number of processes:";
        cin>>n;  
        int i;  
        for(i=0;i<n;i++)
        {  
          cout<<"\n"<<"Enter Burst Time of process"<<i+1<<"\n";  
          cin>>bt[i];         
          cout<<"\n"<<"Enter Arrival Time of process"<<i+1<<"\n";  
          cin>>at[i];         
        }  
 }  
 void calculate(){  
    wt[0]=0;  
    atat=tat[0]=bt[0];  
    int btt=bt[0];//to store total burst time sum  
    int i;  
    for(i=1;i<n;i++){  
      wt[i]=btt-at[i];  
      btt+=bt[i];        
      awt+=wt[i];     
      tat[i]= wt[i]+bt[i];   
      atat+=tat[i];    
    }  
    atat/=n;  
    awt/=n;       
 }  
 void display(){  
    int i;  
    cout<<"SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";  
    for(i=0;i<n;i++)  
    {  
   cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";          
    }    
  cout<<"\n"<<"Average Waiting Time:"<<awt<<"\n"<<"Average Turn Around Time:"<<atat<<"\n";  
 }    
 int main(){  
       cout<<"FCFS CPU Scheduling Algorithm\n";  
       input();  
       calculate();  
       display();   
     return 0;   
 } 
