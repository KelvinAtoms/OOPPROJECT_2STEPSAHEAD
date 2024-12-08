#include"Employee.h"
	Employee::Employee() {
		strPosition = "N/A";
		strID = "N/A";
		strName = "N/A";
		strDOB = "N/A";
		strAddress = "N/A";
		strIDC = "N/A";
		iStarMonth = 0;
		iStarYear = 0;
		dSalary = 0;
	}
	string Employee::getPosition() const { return strPosition; }
	string Employee::getID() const { return strID; }
	string Employee::getName() const { return strName; }
	string Employee::getDOB() const { return strDOB; }
	string Employee::getAddress() const { return strAddress; }
	string Employee::getIDC() const { return strIDC; }
	int Employee::getStarMonth() { return iStarMonth; }
	int Employee::getStarYear() { return iStarYear; }
	double Employee::getSalary() const { return dSalary; }

	void Employee::setPosition(const string& _strPosition) { strPosition = _strPosition; }
	void Employee::setID(const string& _strID) { strID = _strID; }
	void Employee::setName(const string& _strName) { strName = _strName; }
	void Employee::setDOB(const string& _strDOB) { strDOB = _strDOB; }
	void Employee::setAddress(const string& _strAddress) { strAddress = _strAddress; }
	void Employee::setIDC(const string& _strIDC) { strIDC = _strIDC; }
	bool Employee::setStarMonth(int _iMonth) {
		if (_iMonth >= 1 && _iMonth <= 12) {
			iStarMonth = _iMonth;
			return true;
		}
		return false;
	}
	bool Employee::setStarYear(int _iYear) {
		if (_iYear > 1900) {
			iStarYear = _iYear;
			return true;
		}
		return false;
	}
	void Employee::setSalary(double _dSalary) {
		dSalary = _dSalary;
	}
