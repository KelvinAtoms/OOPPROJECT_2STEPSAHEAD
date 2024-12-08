#pragma once
#include<iostream>
#include<windows.h>
using namespace std;
enum Color { //Moi gia tri trong enum se tu dong duoc gan mot so nguyen bat dau tu 0 va tang dan khi xuong hang
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    PURPLE,
    YELLOW,
    WHITE,//normal
    GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_AQUA,
    LIGHT_RED,
    LIGHT_PURPLE,
    LIGHT_YELLOW,
    BRIGHT_WHITE
};
void setColor(int );
void gotoXY(int , int );
class Menu
{
public:
    void printMain();
    void printLoginAdmin();
    void printLoginUser();
    void printLoginPin();
    void printAdminFunc();
};

