#include "User.h"


User::User(string username, string password) {
	m_username = username;
	SHA256 securePass;
	m_password = securePass(password);
}

User::~User() {

}

int User::changePass(string pastPass1, string pastPass2, string newPass) {
	if (pastPass1 == pastPass2) {
		SHA256 securePass;
		if (securePass(pastPass1) == m_password) {
			m_password = securePass(newPass);
			//Save on file.
			return 1;
		}
		return 0;
	}
	return -1;
}

string User::getName() {
	return m_username;
}

bool User::comparePass(string user, string pass) {
	SHA256 securePass;
	if (user == m_username) {
		if (m_password == securePass(pass)) {
			return true;
		}
	}
	
	return false;
}
