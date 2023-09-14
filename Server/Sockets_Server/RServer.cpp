#include "Server.h"
#include <iostream>

using namespace std;

int __cdecl main() {

	bool serverResult = false;
	while (!serverResult) {
		serverResult = initServer("localhost");
	}
	return 0;
}