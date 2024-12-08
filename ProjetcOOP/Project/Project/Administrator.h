#pragma once
#include"Permanent.h"
#include"Temporary.h"
class Administrator
{
	string strUserName;
	string strPassWord;
public:
	Administrator();
	string getUserName();
	string getPassWord();
	void setUserName(string );
	void setPassWord(string );
	void takeAcc(fstream& );
	void changeTempIntoPerm(string );
	void addPermanent(string );
	void addTemporary(string );
	void removePermanent(string );
	void removeTemporary(string );
	void searchPermanent(string );
	void searchTemporary(string );
	void updatePermanent(string );
	void updateTemporary(string );
	void showAll();
	bool checkAcc();
};

