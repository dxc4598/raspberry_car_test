# include <iostream>
# include <signal.h>
# include <unistd.h>
# include "Motor.h"
# include "Servo.h"
# include "Ultrasonic.h"
using namespace std;

void testGetDistance();
void stopTesting();
void catchSIGINT(int);

Motor pwm;
Servo pwmServo;
Ultrasonic ultrasonic;
bool stop = false;


int main() {
	signal(SIGINT, catchSIGINT);
	
	while (true) {
		testGetDistance();
		
		if (stop) {
			stopTesting();
			exit(EXIT_SUCCESS);
		}
	}
	
	return 0;
}


void testGetDistance() {
	int data;
	data = ultrasonic.getDistance();
	cout << "Obstacle Distance is " << data << " cm" << endl;
	sleep(1);
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
    
