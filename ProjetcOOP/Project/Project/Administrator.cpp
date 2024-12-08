#include"Administrator.h"
Administrator::Administrator() {
	strUserName = "N/A";
	strPassWord = "111111";
}
string Administrator::getUserName() {
	return strUserName;
}
string Administrator::getPassWord() {
	return strPassWord;
}
void Administrator::setUserName(string _strUserName) {
	strUserName = _strUserName;
}
void Administrator::setPassWord(string _strPassWord) {
	strPassWord = _strPassWord;
}
void Administrator::takeAcc(fstream& file) {//#
	file >> strUserName;
	file >> strPassWord;
}
void Administrator::changeTempIntoPerm(string _strID) {
	Temporary Temp;
	Temp.setID(_strID);
	if (!Temp.checkID()) {
		cout << "\nNone Exist User\n"; return;
	}
	cout << "\nChange Success\n";
	Permanent Perm;
	Perm.setID(Temp.getID());
	Perm.setName(Temp.getName());
	Perm.setAddress(Temp.getAddress());
	Perm.setDOB(Temp.getDOB());
	Perm.setIDC(Temp.getIDC());
	Perm.setStarMonth(Temp.getStarMonth());
	Perm.setStarYear(Temp.getStarYear());
	Perm.setSeniority(Perm.calculateSeniority());
	Perm.setSeniorityAllowance(Perm.calculateSeniorityAllowance());
	Perm.setSalary(Perm.calculateSalary());
	removeTemporary(_strID);
	fstream file;
	file.open("Permanent.txt", ios::app);
	Perm.printFull(file);
	file.close();
}
void Administrator::addPermanent(string _strID) {
	Permanent Perm;
	Perm.setID(_strID);
	if (Perm.checkID()) {
		cout << "\nExist Employee\n"; return;
	}
	cout << "\nStar Edit Permant Employee";
	fstream file;
	Perm.inputFull();
	file.open("Permanent.txt", ios::app);
	Perm.printFull(file);
	file.close();
	cout << "\nEdit Success\n";
}
void Administrator::addTemporary(string _strID) {
	Temporary Temp;
	Temp.setID(_strID);
	if (Temp.checkID()) {
		cout << "\nExist Employee\n"; return;
	}
	cout << "\nStar Edit Permant Employee";
	fstream file;
	Temp.inputFull();
	file.open("Temporary.txt", ios::app);
	Temp.printFull(file);
	file.close();
	cout << "\nEdit Success\n";
}
void Administrator::removePermanent(string _strID) {
	Permanent Perm;
	Perm.setID(_strID);
	if (!Perm.checkID()) {
		cout << "\nNone Exist User\n"; return;
	}

	/*employee.takeFull(); */
	fstream file;
	file.open("Permanent.txt", ios::in);
	int iSize = 0;
	Permanent PermanentList[50];
	while (!file.eof()) {
		/*if (file.eof())break; */
		PermanentList[iSize++].takeFull(file);
	}
	iSize--;
	file.close();
	for (int iCount = 0; iCount < iSize; iCount++) {
		if (PermanentList[iCount].getID() == Perm.getID()) {
			for (int jCount = iCount; jCount < iSize - 1; jCount++)PermanentList[jCount] = PermanentList[jCount + 1];
			iSize--;
			break;
		}
	}
	file.open("Permanent.txt", ios::out);
	for (int iCount = 0; iCount < iSize; iCount++)PermanentList[iCount].printFull(file);
	file.close();
	cout << "\nRemove Success\n";
}
void Administrator::removeTemporary(string _strID) {
	Temporary Temp;
	Temp.setID(_strID);
	if (!Temp.checkID()) {
		cout << "\nNone Exist User\n"; return;
	}
	/*employee.takeFull(); */
	fstream file;
	file.open("Temporary.txt", ios::in);
	int iSize = 0;
	Temporary TemporaryList[50];
	while (!file.eof()) {
		/*if (file.eof())break; */
		TemporaryList[iSize++].takeFull(file);
	}
	iSize--;
	file.close();
	for (int iCount = 0; iCount < iSize; iCount++) {
		if (TemporaryList[iCount].getID() == Temp.getID()) {
			for (int jCount = iCount; jCount < iSize - 1; jCount++)TemporaryList[jCount] = TemporaryList[jCount + 1];
			iSize--;
			break;
		}
	}
	file.open("Temporary.txt", ios::out);
	for (int iCount = 0; iCount < iSize; iCount++)TemporaryList[iCount].printFull(file);
	file.close();
	cout << "\nRemove Success\n";
}
void Administrator::searchPermanent(string _strID) {
	Permanent Perm;
	Perm.setID(_strID);
	if (!Perm.checkID()) {
		cout << "\nNone Exist User\n"; return;
	}
	cout << "\nUserName Exist";
	Perm.showFull();
}
void Administrator::searchTemporary(string _strID) {
	Temporary Temp;
	Temp.setID(_strID);
	if (!Temp.checkID()) {
		cout << "\nNone Exist User\n"; return;
	}
	cout << "\nUserName Exist";
	Temp.showFull();
}
void Administrator::updatePermanent(string _strID) {
	Permanent Perm;
	Perm.setID(_strID);
	if (!Perm.checkID()) {
		cout << "\nNone Exist User\n"; return;
	}
	cout << "\nUserName Exist";
	Perm.showFull();
	int iChoice;//choice
	string _strTemp;
	cout << "\nInformation need to change is: ";
	cin >> iChoice;
	cin.ignore();
	switch (iChoice) {
	case 1: cout << "\nCannt Change ID"; return;
	case 2: cout << "\nChange into: "; getline(cin, _strTemp); Perm.setName(_strTemp); break;
	case 3: cout << "\nChange into: "; getline(cin, _strTemp); Perm.setAddress(_strTemp); break;
	case 4: cout << "\nChange into: "; getline(cin, _strTemp); Perm.setDOB(_strTemp); break;
	case 5: cout << "\nChange into: "; getline(cin, _strTemp); Perm.setIDC(_strTemp); break;
	case 6:cout << "\nCannt Change StarDate\n"; return;
	case 7:cout << "\nCannt Change Seniority\n"; return;
	case 8:cout << "\nCannt Change SalaryCoefficient\n"; return;
	case 9:cout << "\nCannt Change SeniorityAllowance\n"; return;
	case 10:cout << "\nCannt Change Salary\n"; return;
	default: cout << "\nNone Option\n"; return;
	}
	fstream file;
	file.open("Permanent.txt", ios::in);
	int iSize = 0;
	Permanent PermanentList[50];
	while (!file.eof()) {
		/*if (file.eof())break; */
		PermanentList[iSize].takeFull(file);
		if (PermanentList[iSize].getID() == Perm.getID())PermanentList[iSize] = Perm;
		iSize++;
	}
	iSize--;
	file.close();
	file.open("Permanent.txt", ios::out);
	for (int iCount = 0; iCount < iSize; iCount++)PermanentList[iCount].printFull(file);
	file.close();
	cout << "\nEdit Succes\n";
}
void Administrator::updateTemporary(string _strID) {
	Temporary Temp;
	Temp.setID(_strID);
	if (!Temp.checkID()) {
		cout << "\nNone Exist User\n"; return;
	}
	cout << "\nUserName Exist";
	Temp.showFull();
	int iChoice;//choice
	string _strTemp;
	double _d;
	cout << "\nInformation need to change is: ";
	cin >> iChoice;
	cin.ignore();

	switch (iChoice) {
	case 1: { cout << "\nCannt Change ID"; return; }
	case 2: { cout << "\nChange into: "; getline(cin, _strTemp); Temp.setName(_strTemp); break; }
	case 3: { cout << "\nChange into: "; getline(cin, _strTemp); Temp.setAddress(_strTemp); break; }
	case 4: { cout << "\nChange into: "; getline(cin, _strTemp); Temp.setDOB(_strTemp); break; }
	case 5: { cout << "\nChange into: "; getline(cin, _strTemp); Temp.setIDC(_strTemp); break; }
	case 6: { cout << "\nCannt Change StarDate\n"; return; }
	case 7: { cout << "\nChange into: "; cin >> _d; Temp.setProduct(_d); break; }
	case 8: { cout << "\nChange into: "; cin >> _d; Temp.setReward(_d); break; }
	case 9: { cout << "\nCannt Change Salary\n"; return; }
	default: { cout << "\nNone Option\n"; return; }
	}
	Temp.setFinalProduct(Temp.calculateFinalProducts());
	Temp.setSalary(Temp.calculateSalary());
	fstream file;
	file.open("Temporary.txt", ios::in);
	int iSize = 0;
	Temporary TemporaryList[50];
	while (!file.eof()) {
		/*if (file.eof())break; */
		TemporaryList[iSize].takeFull(file);
		if (TemporaryList[iSize].getID() == Temp.getID()) { TemporaryList[iSize] = Temp; }
		iSize++;
	}
	iSize--;
	file.close();
	file.open("Temporary.txt", ios::out);
	for (int iCount = 0; iCount < iSize; iCount++)TemporaryList[iCount].printFull(file);
	file.close();
	cout << "\nEdit Succes\n";
}
void Administrator::showAll() {
	fstream file;
	file.open("Permanent.txt", ios::in);
	int iPSize = 0;
	Permanent PermanentList[50];
	while (!file.eof()) {
		/*if (file.eof())break; */
		PermanentList[iPSize++].takeFull(file);
	}
	iPSize--;
	file.close();
	file.open("Temporary.txt", ios::in);
	int iTSize = 0;
	Temporary TemporaryList[50];
	while (!file.eof()) {
		/*if (file.eof())break; */
		TemporaryList[iTSize++].takeFull(file);
	}
	iTSize--;
	file.close();
	double dRes=0;
	int i = 0;
	for (i = 0; i < iPSize; i++) {
		cout << endl << i + 1 << ".Position: Permanent";
		cout << "\nID: " << PermanentList[i].getID();
		cout << "\nName: " << PermanentList[i].getName();
		cout << fixed << setprecision(3) << "\nSalaey: " << PermanentList[i].getSalary() << " VND\n";
		dRes += PermanentList[i].getSalary();
	}
	for (int j = 0; j < iTSize; j++) {
		cout << endl << 1 + i++ << ".Position: Temporary";
		cout << "\nID: " << TemporaryList[j].getID();
		cout << "\nName: " << TemporaryList[j].getName();
		cout << fixed << setprecision(3) << "\nSalaey: " << TemporaryList[j].getSalary() << " VND\n";
		dRes += TemporaryList[j].getSalary();
	}
	if (i == 0)cout << "\nDanh sach rong\n";
	cout << "\nTotal company payroll: "<<dRes<<" VND\n";
}
bool Administrator::checkAcc() {//doi fn thanh 1 file luon ton tai
	fstream file;
	file.open("Administrators.txt", ios::in);
	Administrator adminTemporary;
	while (!file.eof()) {
		adminTemporary.takeAcc(file);
		if (adminTemporary.strUserName == strUserName && adminTemporary.strPassWord == strPassWord) {
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}
