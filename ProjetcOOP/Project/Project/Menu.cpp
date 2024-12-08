#include"Menu.h"
void setColor(int _color) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, _color);
}
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Menu::printMain() { //Main login menu 
    system("cls"); //Xoa man hinh
    setColor(YELLOW);
    gotoXY(40, 2);
    for (int i = 0; i <= 20; i++) if (i != 20) cout << "*" << " "; else cout << "*\n";
    gotoXY(40, 3); cout << "*";
    setColor(LIGHT_GREEN);
    gotoXY(55, 3); cout << "DANG NHAP";
    setColor(YELLOW);
    gotoXY(80, 3); cout << "*";
    gotoXY(40, 4);
    for (int i = 0; i <= 20; i++) if (i != 20) cout << "*" << " "; else cout << "*\n";
    setColor(WHITE);
}
void Menu::printLoginAdmin() { //Main login menu 
    system("cls"); //Xoa man hinh
    setColor(LIGHT_YELLOW);
    gotoXY(40, 2);
    for (int i = 0; i <= 20; i++) if (i != 20) cout << "*" << " "; else cout << "*\n";
    gotoXY(40, 3); cout << "*";
    setColor(LIGHT_GREEN);
    gotoXY(54, 3); cout << "DANG NHAP ADMIN";
    setColor(LIGHT_YELLOW);
    gotoXY(80, 3); cout << "*";
    gotoXY(40, 4);
    for (int i = 0; i <= 20; i++) if (i != 20) cout << "*" << " "; else cout << "*\n";
    setColor(WHITE);
}
void Menu::printLoginUser() {
    setColor(LIGHT_GREEN);
    gotoXY(40, 6); cout << "User";
    setColor(WHITE);
    cout << ":"; gotoXY(50, 6);
}
void Menu::printLoginPin() {
    setColor(LIGHT_GREEN);
    gotoXY(40, 7); cout << "Pin";
    setColor(WHITE);
    cout << ":"; gotoXY(50, 7);
}
void Menu::printAdminFunc() {
    system("cls");
    setColor(LIGHT_YELLOW);
    gotoXY(37, 2);
    for (int i = 0; i < 23; i++)if (i == 11)cout << "*MENU"; else if (i >= 0 || i <= 20 || i != 9 || i != 10)cout << "* ";
    gotoXY(36, 3);  cout << "*";
    setColor(LIGHT_GREEN);
    gotoXY(43, 3); cout << "0. Cap nhat vi tri nhan vien chinh thuc";
    setColor(LIGHT_YELLOW);
    gotoXY(85, 3);  cout << "*";
    gotoXY(36, 4);  cout << "*";
    setColor(LIGHT_GREEN);
    gotoXY(43, 4); cout << "1. Them Employee";
    setColor(LIGHT_YELLOW);
    gotoXY(85, 4);  cout << "*";
    gotoXY(36, 5);  cout << "*";
    setColor(LIGHT_GREEN);
    gotoXY(43, 5); cout << "2. Xoa Employee";
    setColor(LIGHT_YELLOW);
    gotoXY(85, 5);  cout << "*";
    gotoXY(36, 6);  cout << "*";
    setColor(LIGHT_GREEN);
    gotoXY(43, 6); cout << "3. Tim Employee";
    setColor(LIGHT_YELLOW);
    gotoXY(85, 6);  cout << "*";
    gotoXY(36, 7);  cout << "*";
    setColor(LIGHT_GREEN);
    gotoXY(43, 7); cout << "4. Cap nhat thong tin Employee";
    setColor(LIGHT_YELLOW);
    gotoXY(85, 7);  cout << "*";
    gotoXY(36, 8);  cout << "*";
    setColor(LIGHT_GREEN);
    gotoXY(43, 8); cout << "5. Hien thi thong tin Employee";
    setColor(LIGHT_YELLOW);
    gotoXY(85, 8);  cout << "*";
    gotoXY(36, 9);  cout << "*";
    setColor(RED);
    gotoXY(43, 9); cout << "6. Thoat!";
    setColor(LIGHT_YELLOW);
    gotoXY(85, 9); cout << "*";
    gotoXY(37, 10);
    for (int i = 0; i < 23; i++)if (i == 11)cout << "*MENU"; else if (i >= 0 || i <= 20 || i != 9 || i != 10)cout << "* ";
    gotoXY(40, 11);
    for (int i = 0; i < 20; i++)if (i == 20)
        cout << endl;
    cout << "Option: ";
    setColor(BRIGHT_WHITE);
}