#include"mwindows.h"
string printUserName() {
    string strInputUserName = "";
    unsigned char ucLetter;// nhan gia tri am
    while (true) {
        ucLetter = _getch();
        if (ucLetter == 13) {//enter
            break;
        }
        else if (ucLetter == 8) {//backspace
            if (!strInputUserName.empty()) {
                strInputUserName.pop_back();//xoa 1 phan tu container vector, list, stack, queue
                cout << "\b \b";
            }
        }
        else if (ucLetter == 32) {//spacebar
        }
        else if (isprint(ucLetter)) { // cac ky tu in duoc
            strInputUserName += ucLetter;
            cout << ucLetter;
        }
    }
    return strInputUserName;
}
string printAsterisk() {
    string strInputPassWord = "";
    unsigned char ucLetter;// nhan gia tri am
    while (true) {
        ucLetter = _getch();
        if (ucLetter == 13) {//enter
            break;
        }
        else if (ucLetter == 8) {//backspace
            if (!strInputPassWord.empty()) {
                strInputPassWord.pop_back();//xoa 1 phan tu container vector, list, stack, queue
                cout << "\b \b";
            }
        }
        else if (ucLetter == 32) {
        }
        else if (isprint(ucLetter)) { // cac ky tu in duoc
            strInputPassWord += ucLetter;
            cout << "*";
        }
    }
    return strInputPassWord;
}
void AdminFunctionMenu() {
    Administrator admin;
    Menu out;
    int ichoice;
    string _strUserName;

    while (true) {
        out.printAdminFunc();
        cin >> ichoice;
        cin.ignore();
        switch (ichoice) {
        case 0: {
            system("cls");
            cout << "\nChange Temporary into Permanent\nEmployee ID: ";
            _strUserName = printUserName();
            admin.changeTempIntoPerm(_strUserName);
            system("pause");

            break;
        }
        case 1: {
            system("cls");
            cout << "\nAdd Employee\n";
            cout << "\nPosition :\n1.Permanent\n2.Temporary\nOption:";
            cin >> ichoice;
            cin.ignore();
            cout << "\nEmployee ID: ";
            _strUserName = printUserName();
            if (ichoice == 1)  admin.addPermanent(_strUserName);
            else if (ichoice == 2)admin.addTemporary(_strUserName);
            else cout << "\nNone Option\n";
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            cout << "\nRemove Employee\n";
            cout << "\nPosition :\n1.Permanent\n2.Temporary\nOption:";
            cin >> ichoice;
            cin.ignore();
            cout << "\nEmployee ID: ";
            _strUserName = printUserName();
            if (ichoice == 1) admin.removePermanent(_strUserName); 
            else if (ichoice == 2) admin.removeTemporary(_strUserName); 
            else cout << "\nNone Option\n";
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            cout << "\nSearch Employee\n";
            cout << "\nPosition :\n1.Permanent\n2.Temporary\nOption:";
            cin >> ichoice;
            cin.ignore();
            cout << "\nEmployee ID: ";
            _strUserName = printUserName();
            if (ichoice == 1)admin.searchPermanent(_strUserName);
            else if (ichoice == 2)admin.searchTemporary(_strUserName);
            else cout << "\nNone Option\n";
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            cout << "\nUpdate/Change Employee Information\n";
            cout << "\nPosition :\n1.Permanent\n2.Temporary\nOption:";
            cin >> ichoice;
            cin.ignore();
            cout << "\nEmployee ID: ";
            _strUserName = printUserName();
            if (ichoice == 1)admin.updatePermanent(_strUserName);
            else if (ichoice == 2)admin.updateTemporary(_strUserName);
            else cout << "\nNone Option\n";
            system("pause");
            break;
        }
        case 5: {
            system("cls");
            cout << "\tEmployee List\n";
            admin.showAll();
            system("pause");
            break;
        }
        case 6: {
            return;
        }
        default: {
            setColor(RED);
            cout << "\nNone Function!\n" << endl;
            system("pause");
            setColor(WHITE);
            break;
        }
        }
    }
}
