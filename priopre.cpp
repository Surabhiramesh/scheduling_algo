#include<iostream>
using namespace std;
struct process
{
	char process_name;
	int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
	int status;
}process_queue[10];
 
int limit;
 
void Arrival_Time_Sorting()
{
	struct process temp;
	int i, j;
	for(i = 0; i < limit - 1; i++)
	{
		for(j = i + 1; j < limit; j++)
		{
			if(process_queue[i].arrival_time > process_queue[j].arrival_time)
			{
				temp = process_queue[i];
				process_queue[i] = process_queue[j];
				process_queue[j] = temp;
			}
		}
	}
}
 
int main()
{
	int i, time = 0, burst_time = 0, largest;
	char c;
        float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
	cout<<"\nEnter Total Number of Processes:\t";
 	cin>>limit;;
 	for(i = 0, c = 'A'; i < limit; i++, c++)
 	{
 		process_queue[i].process_name = c;
		cout<<"\nEnter Details For Process:\n"<<process_queue[i].process_name;
		cout<<"Enter Arrival Time:\t";
		cin>>process_queue[i].arrival_time;
		cout<<"Enter Burst Time:\t";
		cin>>process_queue[i].burst_time;
		cout<<"Enter Priority:\t";
		cin>>process_queue[i].priority;
 		process_queue[i].status = 0;
 		burst_time = burst_time + process_queue[i].burst_time;
	}
	Arrival_Time_Sorting();
	process_queue[9].priority = -9999;
	cout<<"\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time";
  	for(time = process_queue[0].arrival_time; time < burst_time;)
  	{
    		largest = 9;
    		for(i = 0; i < limit; i++)
    		{
      			if(process_queue[i].arrival_time <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[largest].priority)
        		{
				largest = i;
			}
    		}
      		time = time + process_queue[largest].burst_time;
  		process_queue[largest].ct = time;
          	process_queue[largest].waiting_time = process_queue[largest].ct - process_queue[largest].arrival_time - process_queue[largest].burst_time;
     		process_queue[largest].turnaround_time = process_queue[largest].ct - process_queue[largest].arrival_time;
    		process_queue[largest].status = 1;
    		wait_time = wait_time + process_queue[largest].waiting_time;
		turnaround_time = turnaround_time + process_queue[largest].turnaround_time;
	cout<<"\n"<<process_queue[largest].process_name<<"\t"<<process_queue[largest].arrival_time<<"\t"<<process_queue[largest].burst_time<<"\t"<<process_queue[largest].priority<<"\t"<<process_queue[largest].waiting_time<<"\n";
	}
	average_waiting_time = wait_time / limit;
	average_turnaround_time = turnaround_time / limit;
	cout<<"\n\nAverage waiting time:\t\n"<<average_waiting_time;
	cout<<"Average Turnaround Time:\t\n"<<average_turnaround_time;
    return(0);
}
