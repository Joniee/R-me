#pragma once

#include "sha256.h"

#include <string>

using namespace std;


string m_username;

string m_password;

class User{
private:
	string m_username;
	string m_password;
public:
	User(string, string);
	~User();
	int changePass(string, string, string);
	string getName();
};
