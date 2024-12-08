#include "Permanent.h"
Permanent::Permanent() {
	setPosition("Permanent");
	iSeniority = 0;
	dBaseSalary = 1800000;
	dSalaryCoefficient = 2.5;
	dSeniorityAllowance = 0;
}
int Permanent::getSeniority() { return iSeniority; }
double Permanent::getSalaryCoefficient() { return dSalaryCoefficient; }
double Permanent::getSeniorityAllowance() { return dSeniorityAllowance; }

void Permanent::setSeniority(int _iSeniority) {
	iSeniority = _iSeniority;
}
void Permanent::setSalaryCoefficient(double _iCoefficient) {
	if (_iCoefficient > 0) {
		dSalaryCoefficient = _iCoefficient;
	}
}
void Permanent::setSeniorityAllowance(double _dAllowance) {
	dSeniorityAllowance = _dAllowance;
}

int Permanent::calculateSeniority() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int currentMonth = 1 + ltm->tm_mon; // Thang hien tai (0-11 -> 1-12)
	int currentYear = 1900 + ltm->tm_year; // Nam hien tai

	int seniority = currentYear - getStarYear();

	// Neu thang hien tai nho hon thang vao lam, giam 1 nam tham nien
	if (currentMonth < getStarMonth()) {
		seniority--;
	}
	return seniority;
}
double Permanent::calculateSeniorityAllowance() {
	return dBaseSalary * ((double)(iSeniority / 5) * 0.05 + 1);
}
double Permanent::calculateSalary() {
	return dBaseSalary * dSalaryCoefficient + dSeniorityAllowance;
}

void Permanent::takeFull(fstream& file) {
	string _str;
	int _i;
	double _d;
	getline(file, _str); setID(_str);
	getline(file, _str); setName(_str);
	getline(file, _str); setDOB(_str);
	getline(file, _str); setAddress(_str);
	getline(file, _str); setIDC(_str);
	file >> _i; setStarMonth(_i);
	file >> _i; setStarYear(_i);
	file >> _i; setSeniority(_i);
	file >> _d; setSalaryCoefficient(_d);
	file >> _d; setSeniorityAllowance(_d);
	file >> _d; setSalary(_d);
	file.ignore();
}
void Permanent::inputFull() {
	string _str;
	int _i;
	cout << "\nID: "; cout << getID();
	cout << "\nName: "; getline(cin, _str); setName(_str);
	cout << "Address: "; getline(cin, _str); setAddress(_str);
	cout << "DOB: "; getline(cin, _str); setDOB(_str);
	cout << "IDC: "; getline(cin, _str); setIDC(_str);
	cout << "Star Month: "; cin >> _i; while (!setStarMonth(_i))cin >> _i;
	cout << "Star Year: "; cin >> _i; while (!setStarYear(_i))cin >> _i;
	setSeniority(calculateSeniority());
	setSeniorityAllowance(calculateSeniorityAllowance());
	setSalary(calculateSalary());
}
bool Permanent::checkID() {
	fstream file;
	file.open("Permanent.txt", ios::in);
	if (!file.is_open()) {
		cout << "Cannot open file!" << endl;
		return false;
	}

	Permanent Perm;
	while (file.peek() != EOF) {
		Perm.takeFull(file);


		if (Perm.getID() == getID()) {
			*this = Perm;
			file.close();
			return true;
		}
	}

	file.close();
	return false;
}




void Permanent::printFull(fstream& file) {
	file << getID() << endl;
	file << getName() << endl;
	file << getAddress() << endl;
	file << getDOB() << endl;
	file << getIDC() << endl;
	file << getStarMonth() << " " << getStarYear() << endl;
	file << fixed << setprecision(3);
	file << getSeniority() << endl;
	file << getSalaryCoefficient() << endl;
	file << getSeniorityAllowance() << endl;
	file << getSalary() << endl;
}
void Permanent::showFull() {//todo can chinh
	cout << "\n0.Position: " << getPosition();
	cout << "\n1.ID: " << getID();
	cout << "\n2.Name: " << getName();
	cout << "\n3.Address: " << getAddress();
	cout << "\n4.DateOfBirth: " << getDOB();
	cout << "\n5.IDC: " << getIDC();
	cout << "\n6.Star Date: " << getStarMonth() << "/" << getStarYear();
	cout << fixed << setprecision(3);
	cout << "\n7.Seniority: " << calculateSeniority();
	cout << "\n8.SalaryCoefficent: " << dSalaryCoefficient;
	cout << "\n9.SeniorityAllowance: " << dSeniorityAllowance;
	cout << "\n10.Salary: " << getSalary() << " VND\n";
}