#pragma once
#include "Employee.h"
class Temporary :
    public Employee
{
		double dProduct;//san pham'
		double dPricePerProduct;
		double dFinalProduct;
		double dReward;// thuong
	public:
		Temporary();
		double getProduct();
		double getReward();
		double getFinalProduct();
		void setProduct(double );
		void setReward(double );
		void setFinalProduct(double );
		double calculateFinalProducts();
		double calculateSalary();
		void takeFull(fstream& );
		void inputFull();
		bool checkID();
		void printFull(fstream& );
		void showFull();
	};

