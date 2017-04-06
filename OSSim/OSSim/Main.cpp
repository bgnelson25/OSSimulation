//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*		PROGRAM FILE NAME:	Main.cpp			ASSIGNMENT #:	2			Grade: _________          *
//*                                                                                                   *
//*		PROGRAM AUTHORS:	_____________________________     __________________________________      *
//*                                      Carly Fristoe				  Ben Nelson                      *
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
using namespace std;
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

	//2. Read in all processes in input file into array of structures

	//3. Get a job into the system.

	//4. While there are jobs to be processed

	//5. 

	return 0;
}
//******************************END OF FUNCTION Main***************************************************

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