#pragma once
#include <iostream>
#include "registeredUser.h"
#include <string>
using namespace std;

class theater: registeredUser {
public:
	string address;
	theater(string str)
	{
		address = str;
	}
	registeredUser registerUser(string email, string password) {
		registeredUser user;
		user.email = email;
		user.password = password;
		return user;
	}
};