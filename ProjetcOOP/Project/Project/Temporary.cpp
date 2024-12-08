#include "Temporary.h"
Temporary::Temporary() {
	setPosition("Temporary");
	dProduct = 0;
	dPricePerProduct = 225000;
	dFinalProduct = 0;
	dReward = 0;
}
//khoi tao tham so
//khoi tao sao chep
// huy
double Temporary::getProduct() {
	return dProduct;
}
double Temporary::getReward() {
	return dReward;
}
double Temporary::getFinalProduct() {
	return dFinalProduct;
}
void Temporary::setProduct(double _dProduct) {
	dProduct = _dProduct;
}
void Temporary::setReward(double _dReward) {
	dReward = _dReward;
}
void Temporary::setFinalProduct(double _dFinalProduct) {
	dFinalProduct = _dFinalProduct;
}
double Temporary::calculateFinalProducts() {
	return dProduct * dPricePerProduct;
}
double Temporary::calculateSalary() {
	return dFinalProduct + dReward;
}
void Temporary::takeFull(fstream& file) {
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
	file >> _d; setProduct(_d);
	file >> _d; setReward(_d);
	file >> _d; setSalary(_d);
	file.ignore();
}
void Temporary::inputFull() {
	string _str;
	int _i;
	double _d;
	cout << "\nID: "; cout << getID();
	cout << "\nName: "; getline(cin, _str); setName(_str);
	cout << "Address: "; getline(cin, _str); setAddress(_str);
	cout << "DOB: "; getline(cin, _str); setDOB(_str);
	cout << "IDC: "; getline(cin, _str); setIDC(_str);
	cout << "Star Month: "; cin >> _i; while (!setStarMonth(_i))cin >> _i;
	cout << "Star Year: "; cin >> _i; while (!setStarYear(_i))cin >> _i;
	cout << "Products: "; cin >> _d; setProduct(_d);
	cout << "Reward: "; cin >> _d; setReward(_d);
	setFinalProduct(calculateFinalProducts());
	setSalary(calculateSalary());
}
bool Temporary::checkID() {
	fstream file;
	file.open("Temporary.txt", ios::in);
	if (!file.is_open()) {
		cout << "Cannot open file!" << endl;
		return false;
	}
	Temporary Temp;
	while (file.peek() != EOF) {
		Temp.takeFull(file);
		if (Temp.getID() == getID()) {
			*this = Temp;
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}
void Temporary::printFull(fstream& file) {
	file << getID() << endl;
	file << getName() << endl;
	file << getAddress() << endl;
	file << getDOB() << endl;
	file << getIDC() << endl;
	file << getStarMonth() << " " << getStarYear() << endl;
	file << fixed << setprecision(3);
	file << getProduct() << endl;
	file << getReward() << endl;
	file << getSalary() << endl;
}
void Temporary::showFull() {
	cout << "\nPosition: " << getPosition();
	cout << "\n1.ID: " << getID();
	cout << "\n2.Name: " << getName();
	cout << "\n3.Address: " << getAddress();
	cout << "\n4.DateOfBirth: " << getDOB();
	cout << "\n5.IDC: " << getIDC();
	cout << "\n6.Star Date: " << getStarMonth() << "/" << getStarYear();
	cout << fixed << setprecision(3);
	cout << "\n7.Products: " << dProduct;
	cout << "\n8.Reward: " << dReward;
	cout << "\n9.Salary: " << getSalary() << " VND\n";
}