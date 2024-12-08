#include"oopproject.h"
void runProject() {
	Menu out;
	Administrator admin;
	Employee _employee;
	string _strUserName;
	string _strPassWord;
	int iCount = 0;
	int iPassSize = 0;
	while (iCount < 3) {
		out.printMain();
		out.printLoginUser();
		_strUserName = printUserName();
		out.printLoginPin();
		_strPassWord = printAsterisk();
		iPassSize = _strPassWord.length();
		admin.setUserName(_strUserName);
		admin.setPassWord(_strPassWord);
		if (!admin.checkAcc()) {
			iCount++;
			setColor(RED);
			if (iCount != 1)cout << "\nWrong UserName or PassWord " << iCount << " times\n";
			else cout << "\nWrong UserName or PassWord " << iCount << " time\n";
			setColor(WHITE);
			system("pause");
			continue;
		}
		out.printLoginAdmin();
		out.printLoginUser();
		cout << "Admin";
		out.printLoginPin();
		for (int iCountA = 0; iCountA < iPassSize; iCountA++)cout << "*";
		gotoXY(45, 9);
		system("pause");
		AdminFunctionMenu();
		break;
	}
}
