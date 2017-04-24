//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*		PROGRAM FILE NAME:	Main.cpp			ASSIGNMENT #:	2			Grade: _________          *
//*                                                                                                   *
//*		PROGRAM AUTHORS:	_____________________________     __________________________________      *
//*                                      Carly Fristoe				  Benjamin Nelson                 *
//*                                                                                                   *
//*		COURSE #:	CSC 40600							DUE DATE:	May 5, 2017                       *
//*                                                                                                   *
//*****************************************************************************************************
//************************************  PROGRAM DESCRIPTION  ******************************************
//*		PROCESS: simulate the operations of an Operating System as it processes a stream of incoming  *
//*		processes. The purpose of the simulation is to compare the results of at least two different  *
//*		scheduling algorithms and their effect on system performance. This simulation will employ only*
//*		one processor (CPU), one I/O device, and one each Long Term Queue, Short Term Queue and I/O   *
//*		Queue. All statistical calculations are to be made using a clock tick as the unit of measure  *
//*		for the simulation. All processed will be non-preemptive.									  *
//*****************************************************************************************************
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

//establish structure for input data
struct DataType {
	int jobNumber;
	int jobLength;
	int interArrivalTime;
	int ioBurstLength;
	int cpuBursts[20];
	int cpuBurstEU = 0;
	int actualArrivalTime;
};

using namespace std;
//read data into the array of structures
void ReadData(ifstream &input, DataType Jobs[], int &jobsEU);
//print data to the output file
void PrintData(ofstream &output, DataType Jobs[], int &jobsEU);
void AddJob(); //routine to add a job to a queue
void DeleteJob(); //routine to delete a job from a queue
void RemoveJob(); //routine to take a job out of the system
void Compute(); //routine t ocomputer the statistical data
void ProcessData(); //routine to process the data
//*********************************FUNCTION Main*******************************************************
int main()
{
	//1. Initialize variables
	int clock = 0; //initialize clock to keep track of total time
	int io_timer = 0; //initialize variable for current I/O burst
	int job_timer = 0; //initialize variable for time between job arrivals
	int more_jobs = 0; //initialize variable for num of jobs in system
	int process_timer = 0; //initialize variable for current CPU burst
	int suspend_timer = 0; //initialize variable for current interrupt time
	bool cpu_ready_flag = true; //initialize variable for CPU availability
	bool cpu_complete_flag = false; //initialize variable for signal of completion of a CPU burst
	bool finished_flag = false; //initialize variable for signall that the job is finished
	bool interrput_flag = false; //initialize variable for signal that an interrupt in progress
	bool io_complete_flag = false; //initialize variable for completion of an I/O burst
	bool io_device_flag = true; //initialize variable for available I/O device
	bool job_flag = false; //initialize variable for signal that a job has arrived
	bool stop_flag = false; //initialize variable for signal to stop CPU job processing
	bool suspend_flag = false; //initialize variable for signal for context switch to hand interrupt
	int cpu = 0;
	int count = 0;
	int devise = 0;
	int process = -1;
	int ioprocess = -1;
	int temp = 0;
	bool ioq_full = false;
	bool ioq_empty = true;
	bool ltq_empty = true;
	bool ltq_full = false;
	bool stq_empty = true;
	bool stqu_full = false;

	/*establish array of structures, assuming unknown amount of
	jobs (i.e. >100 jobs) and establish EU count for jobs*/
	DataType Jobs[200];
	int jobsEU = 0;
	int LTQ[60]; //create Long term queue
	int STQ[30]; //create short term queue
	int IOQ[30]; //create I/O queue
	int ltqCount = 0;
	int stqCount = 0;
	int ioqCount = 0;
	int jobCount = 0;
	int jobIndex = 1;

	//establish I/O
	ifstream input("data.txt", ios::in);
	ofstream output("output.txt", ios::out);
	
	//2. Read in all processes in input file into array of structures
	ReadData(input, Jobs, jobsEU);

	//print data as test
	PrintData(output, Jobs, jobsEU);

	//3. Get first job into the system.
	job_timer++; //increment job timer
	if (Jobs[jobCount].interArrivalTime == job_timer) {
		job_flag = true; //signal the LTQ of job arrival
		Jobs[jobCount].actualArrivalTime = job_timer; //record time of arrival
		job_timer = 0; //reset job timer
		count++; //increment total number of jobs ran
		more_jobs++; //increment number of jobs in the system
		process_timer = Jobs[jobCount].cpuBurstEU;
	}

	//4. While there are jobs to be processed, manage the LTP
	while (process_timer > 0) {
		//4.1.1
		if (ltq_empty == false) {
			//increment wait counters for all processes in the queue
		}
		//4.1.12
		if (job_flag == true && ltq_full == false) {
			LTQ[ltqCount] = Jobs[jobCount-1].jobNumber; //add int corresponding to index of process array
			job_flag = false;
			ltq_empty = false;
			jobCount++; //increment job index
		}
		//4.1.3 check for full LTQ
		if (LTQ[60] != NULL) {
			ltq_full = true;
		}
		/*4.2 This routine increments the STQ Wait counters for all processes in the STQ. It then moves a job, that is
		finished with the I/O device, from the I/O device to the STQ.*/

		//4.2.1 increment STQ Wait counters for processes in STQ.
		if (stq_empty == false) {
			//increment wait counters for all processes in the queue
		}
		//4.2.2 check if io_complet_flag is true
		if (io_complete_flag == true) {
			io_complete_flag = false; //reset io_complete_flag
			io_device_flag = true; //set io_device_flag to true
			if (finished_flag == true) {
				//remove job from system
				more_jobs--; //decrement more jobs
				finished_flag = false; //set finish_flag to false
				//collect data: wait times, etc
			}
			else {
				if (stqu_full == false) {
					//place process in the STQ
					devise = 0; //set device to zero
					if (STQ[29] != NULL) {
						stqu_full = true;
					}
				}
			}
		}
		//4.2.3 (reads as 4.3.3 on the sheet but its a typo)
		if ((stqu_full == false) & (ltq_empty == false)) {
			//move process from the LTQ to the STQ
			stq_empty = false; //set sqt_empty to false

			if (LTQ[0] == NULL) { //if LTQ is empty
				ltq_empty = true; //set ltq to empty
				ltq_full = false; //set ltq to not be full
			}
			if (STQ[29] != NULL) //if STQ is full
			stqu_full = true;
		}
		//4.3 Managing the CPU

		//4.3.1 check if the process is suspended
		if (suspend_flag == true) { //the process is suspended
			suspend_timer--; //decrement suspend timer
			if (suspend_timer == 0) { //check for completion of interrupt
				interrput_flag = false;
				suspend_flag = false;
			}
			else {
				if (temp == process) { //process is in CPU when interrupt occured
					//increment cpu wait counter
					stop_flag = true;
				}
			}
		}
		//4.3.2 check for interrupt if processing has not been halted
		if (stop_flag == false) { //check for interrupt flag if processing has not halted
			if (interrput_flag == true) {
				if (cpu > 0) {
					temp = cpu; //supend the process
					cpu = 0;
				}
				suspend_timer = 3;
				suspend_flag = true;
			}
		}
		else {
			if (cpu == process) {
				process_timer++; //increment process timer
				if (process_timer == Jobs[jobCount].cpuBurstEU) { //if process timer equals cpu burst length
					cpu_complete_flag = true;
					process_timer = 0;
				}
			}
			else { //if there is no interrupt and a job is in the cpu, process the cpu burst and check to see if it is finished
				if (temp == process) {
					process_timer++; //increment process timer
					if (process_timer == Jobs[jobCount].cpuBurstEU) { // if process timer equals cpu burst length
						cpu_complete_flag = true; //set cpu complete flag to true
						process_timer = 0; //set process timer to 0
					}
				}
				else {
					if (temp == process) {
						cpu = process;
						//increment cpu wait counter
						temp = 0; //set temp to 0
					}
					else { /* if the interrupt flag is not set and if a process has nto been suspended and if the stq is not
						   empty, get the next job for the cpu, reset the cpu ready flag, and reset the process timer*/
						if (stq_empty == false && cpu_ready_flag == true) {
							//set process equal to the head of the stq
							cpu = process;
							//delete job from the queue
							stqu_full = false;
							if (STQ[0] == NULL) //if STQ is empty
								stq_empty = true;
							cpu_ready_flag = false;
							process_timer = 0;
						}
					}
				}
			}
		}
		stop_flag = false;

		/*4.4 Manage the I/O Queue - This routine increments the I/O Wait counters for all processs in the I/O queue
		and places any job with the CPU in the back of the queue*/

		//4.4.1
		if (ioq_empty == false) {
			//increment I/O queue wait counter for all processes in the queue
		}
		//4.4.2
		if (cpu_complete_flag == true) {
			if (ioq_full == false) {
				//add the process to the tail of the queue
				cpu = 0;
				ioq_empty = false;
				cpu_ready_flag = true;
				if (IOQ[29] != NULL)
					ioq_full = true;
				cpu_complete_flag = false;
			}
		}
		//4.5 Manage I/O Devices
		if (interrput_flag == false) {
			if (devise == ioprocess) { //then process is in the I/O device
				//increment the I/O timer
				if (io_timer == Jobs[jobCount + 1].cpuBurstEU) { //next CPU burst length
					interrput_flag = true;
				}
				else {
					finished_flag = true;
				}
			}
			else {
				if (ioq_empty == false && io_device_flag == true) { /*the I/O queue is not empty so place a 
																	process in the I/O device from the queue*/
					ioprocess = IOQ[0]; //ioprocess equals head of the queue
					devise = ioprocess;
					//delete job from the I/O queue
					if (IOQ[0] == NULL)
						ioq_empty = true;
					io_timer = 0;
					io_device_flag = false;
				}
			}
		}


		//get another job into the system
		if (Jobs[jobCount].interArrivalTime == job_timer) {
			job_flag = true; //signal the LTQ of job arrival
							 //record time of arrival
			job_timer = 0; //reset job timer
			count++; //increment total number of jobs ran
			more_jobs++; //increment number of jobs in the system
			process_timer = Jobs[jobCount].cpuBurstEU;
		}
	}

	//5. 

	return 0;
}
//******************************END OF FUNCTION Main***************************************************

//***********************************FUNCTION ReadData*************************************************
void ReadData(ifstream &input, DataType Jobs[], int &jobsEU) {
	int temp;
	int tempCPUBurst = 0;
	input >> ws >> temp;

	//read in data into array of structures until sentinel of negative number is read
	while (temp >= 0)
	{
		Jobs[jobsEU].jobNumber = temp;
		input >> ws >> Jobs[jobsEU].jobLength;
		input >> ws >> Jobs[jobsEU].interArrivalTime;
		input >> ws >> Jobs[jobsEU].ioBurstLength;
		input >> ws >> tempCPUBurst;
		//read in CPU burst into array until sentinel of 0 is read
		while (tempCPUBurst > 0)
		{
			Jobs[jobsEU].cpuBursts[Jobs[jobsEU].cpuBurstEU] = tempCPUBurst;
			Jobs[jobsEU].cpuBurstEU++;
			input >> ws >> tempCPUBurst;
		}

		input >> ws >> temp;
		jobsEU++;
		//return if negative number is read as a CPU burst
		//if sentinel (-1) is read in as a CPU burst, return
		if (tempCPUBurst < 0)
			return;
	}
	return;
}
//******************************END OF FUNCTION ReadData***********************************************


//***********************************FUNCTION PrintData************************************************

void PrintData(ofstream &output, DataType Jobs[], int &jobsEU) {
	output << "The original input data: \n";
	for (int i = 0; i < jobsEU; i++) {
		output << "Job number: " << Jobs[i].jobNumber << endl;
		output << "Job length: " << Jobs[i].jobLength << endl;
		output << "Inter arrival time: " << Jobs[i].interArrivalTime << endl;
		output << "IO burst length: " << Jobs[i].ioBurstLength << endl;
		output << "CPU bursts: ";
		for (int j = 0; j < Jobs[i].cpuBurstEU; j++)
		{
			output << Jobs[i].cpuBursts[j] << " ";
		}
		output << endl << endl;
	}
	return;
}
//******************************END OF FUNCTION PrintData**********************************************



//***********************************FUNCTION AddJob***************************************************
void AddJob() {
	return;
}
//******************************END OF FUNCTION AddJob*************************************************

//***********************************FUNCTION AddJob***************************************************
void DeleteJob() {
	return;
}
//******************************END OF FUNCTION AddJob*************************************************

//***********************************FUNCTION AddJob***************************************************
void RemoveJob() {
	return;
}
//******************************END OF FUNCTION AddJob*************************************************

//***********************************FUNCTION AddJob***************************************************
void Compute() {
	return;
}
//******************************END OF FUNCTION AddJob*************************************************

//***********************************FUNCTION AddJob***************************************************
void ProcessData() {
	return;
}
//******************************END OF FUNCTION AddJob*************************************************