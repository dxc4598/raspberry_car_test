# include <iostream>
# include <signal.h>
# include <unistd.h>
# include "Motor.h"
# include "Servo.h"
# include "Ultrasonic.h"
using namespace std;

void test();
void stopTesting();
void catchSIGINT(int);

Motor pwm;
Servo pwmServo;
Ultrasonic ultrasonic;
bool stop = false;


int main() {
	signal(SIGINT, catchSIGINT);
	test();
		
	if (stop) {
		stopTesting();
		exit(EXIT_SUCCESS);
	}
	
	return 0;
}


void test() {
	ultrasonic.run();
}


void stopTesting() {
	pwm.setMotorModel(0, 0, 0, 0);
	pwmServo.setServoPWM("0", 90);
	cout << "Ultrasonic.h Stop Testing." << endl;
}


void catchSIGINT(int signal) {
	if (signal == SIGINT) {
		cout << "Ctrl + c has been pressed." << endl;
		stop = true;
	}
}
    
