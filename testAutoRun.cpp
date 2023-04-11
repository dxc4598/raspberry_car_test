# include <string>
# include <fstream>
# include <iostream>
# include <unistd.h>
# include "AutoRun.h"
using namespace std;

void test();
void stopTesting();
void catchSIGINT(int);

AutoRun autoRun;
bool stop = false;


int main() {
	ifstream f ("direction.txt");
	string s;
	
	if (f.is_open()) {
		while (!f.eof()) {
			f >> s;
			
			autoRun.setUp();
			if (s == "stop") {
				autoRun.stop();
			}
			else if (s == "go-straight") {
				f >> s;
				
				int sleep_time = (int) stoi(s) * 1612903;
				autoRun.goStraight(sleep_time);
				
			}
			else if (s == "turn-left") {
				f >> s;

				int sleep_time = (int) stoi(s) * 1612903;
				autoRun.turnLeft();
				autoRun.goStraight(sleep_time);
			}
			else if (s == "turn-right") {
				f >> s;
				
				int sleep_time = (int) stoi(s) * 1612903;
				autoRun.turnRight();
				autoRun.goStraight(sleep_time);
			}
			else if (stop) {
				stopTesting();
				exit(EXIT_SUCCESS);
			}
 		}
	}
	
	return 0;
}


void stopTesting() {
	autoRun.stop();
	cout << "AutoRun.h Stop Testing." << endl;
}


void catchSIGINT(int signal) {
	if (signal == SIGINT) {
		cout << "Ctrl + c has been pressed." << endl;
		stop = true;
	}
}

