#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
class Employee
{
	string strPosition;
	string strID;//company id
	string strName;
	string strDOB;//date of birth
	string strAddress;
	string strIDC;// ID Card : CCCD
	int iStarMonth;//thang vao lam
	int iStarYear;//nam vao lam
	double dSalary;
public:
	Employee();
	string getPosition() const;
	string getID() const ;
	string getName() const;
	string getDOB() const;
	string getAddress() const;
	string getIDC() const;
	int getStarMonth();
	int getStarYear();
	double getSalary() const;

	void setPosition(const string& );
	void setID(const string& );
	void setName(const string& );
	void setDOB(const string& );
	void setAddress(const string& );
	void setIDC(const string& );
	bool setStarMonth(int );
	bool setStarYear(int );
	void setSalary(double );
};
