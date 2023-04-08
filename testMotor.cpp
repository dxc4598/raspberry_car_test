# include <iostream>
# include <signal.h>
# include <unistd.h>
# include "Motor.h"
using namespace std;

void loop();
void destroy();
void catchSIGINT(int);

Motor pwm;
bool stop_signal = false;


int main() {
	signal(SIGINT, catchSIGINT);
	loop();
	
	if (stop_signal) {
		destroy();
	}
	
	return 0;
}


void loop() {
	pwm.setMotorModel(1000, 1000, 1000, 1000);         /* Move Forward. */
	cout << "Moving Forward." << endl;
	sleep(1);
	
	pwm.setMotorModel(-2000, -2000, -2000, -2000);     /* Move Back. */
	cout << "Moving Back." << endl;
	sleep(1);
	
	pwm.setMotorModel(-500, -500, 2000, 2000);         /* Turn Left. */
	cout << "Turning Left." << endl;
	sleep(1);
	
	pwm.setMotorModel(2000, 2000, -500, -500);         /* Turn Right. */
	cout << "Turning Right." << endl;
	sleep(1);
	
	pwm.setMotorModel(0, 0, 0, 0);                     /* Stop */
	cout << "End of Program." << endl;
}


void destroy() {
	pwm.setMotorModel(0, 0, 0, 0);                     /* Stop */
	cout << "End of Program." << endl;
}


void catchSIGINT(int signal) {
	if (signal == SIGINT) {
		cout << "Ctrl + C has been pressed." << endl;
		stop_signal = true;
	}
}

