#pragma once
#include "Employee.h"
#include<ctime>
class Permanent :
    public Employee
{
		int iSeniority;//tham nien
		double dBaseSalary;
		double dSalaryCoefficient;//he so luong
		double dSeniorityAllowance;// phu cap tham nien
	public:
		Permanent();
		int getSeniority();
		double getSalaryCoefficient();
		double getSeniorityAllowance();

		void setSeniority(int );
		void setSalaryCoefficient(double );
		void setSeniorityAllowance(double );

		int calculateSeniority();
		double calculateSeniorityAllowance();
		double calculateSalary();

		void takeFull(fstream& );
		void inputFull();
		bool checkID();




		void printFull(fstream& );
		void showFull();
	};


