/*Jessica Megaro
 *07/11/2021
 *This program will run a 12 and 24 hour clock for Chada Tech written in C++.
 * It will print both types of clock in correct format and  update correct times according to user input in hours, minutes and seconds.
 */

#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>

using namespace std;

void displayClock(int hr, int minute, int sec);
void getTime(int& hour, int& minute, int& sec);
char getOption();
void updatedClock(int, int, int, int&, int&, int&);

//Get current time, declare argument and name variables to get and hold time.
void getTime(int& hour, int& minute, int& sec) {
	time_t displayClock = time(0); //Declare clock as argument for local clock
	tm* local_time = localtime(&displayClock); //Hold local clock

	hour = local_time->tm_hour;
	minute = local_time->tm_min;
	sec = local_time->tm_sec;

}
//Main function to declare hour, minutes and sec, as well as user input, and whether user wants to add an hour, minute or second to the current time.
int main() {
	int hour;
	int minute;
	int sec;
	char userInput = ' ';
	int userHour = 0;
	int userMin = 0;
	int userSec = 0;

	//While user has not selected exit.
	while (userInput != '4') {
		getTime(hour, minute, sec);
	//Calculate updated clock with user input.
		updatedClock(userHour, userMin, userSec, hour, minute, sec);
	//Display Clock
		displayClock(hour, minute, sec);

	   
		//Get Option from User
		userInput = getOption();
		//   Update time based on user's selection, or gives a salutation to exit program. 
		switch (userInput) { 
		case '1':
			userHour = userHour + 1;
			break;
		case '2':
			userMin = userMin + 1;
			break;
		case '3':
			userSec = userSec + 1;
			break;
		case '4':
			cout << "Thank you, Goodbye!" << endl;	
		}
	}
}
/*Function to update the clocks correctly.This will take the time, and make sure that if 
 *the seconds are > 59, it will roll over the minute, and if minutes are >59, it will roll 
 *over the hour, not to exceed 12 in the 12 hour clock and not to exceed 23 in the 24 hour clock.
 *Also ensure that the 2300 in military time changes to 0000.
 */
void updatedClock(int userHour, int userMin, int userSec, int &hour, int &minute, int &sec) {
	
	sec = (sec + userSec);
	if (sec > 59) {
		sec = sec % 59;
	}
	
	minute = (minute + userMin);
	if (minute > 59) {
		hour++;
		minute = minute % 59;
	}
	hour = (hour + userHour) % 24;
}

/*Function to display and print both clocks properly in the terminal.
 *12 hour clock will print with standard hour to convert the 24 hour clock
 *fetched from ctime. Also width set to fill empty spaced with zero to avoid misalignments
 *when outputting single digit hours, minutes or seconds and for better readability.
 */
void displayClock(int hour, int minute, int sec) {
	int standardHour = hour % 12;
	if (standardHour == 0) {
		standardHour = 12;
	}

	cout << "**************************"
		 << "     "
		 << "**************************" << endl;

	cout << "*     12-Hour Clock      *"
		 << "     "
		 << "*     24-Hour Clock      *" << endl;

	cout << setfill('0')
		 << "*       " << setw(2) << standardHour << ":" << setw(2) << minute << ":" << setw(2) << sec << ((hour > 11) ? "PM" : "AM") << "       *"
		 << "     "
		 << "*        " << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << sec << "        *" << endl;
 

	cout << "**************************"
		<< "     "
		<< "**************************" << endl;

}
//Get option based on what user would like to do with the time in a readable format.
char getOption() {
	cout << "               " << "**************************" << endl;
	cout << "               " << "* 1 - Add one hour       *" << endl;
	cout << "               " << "* 2 - Add one minute     *" << endl;
	cout << "               " << "* 3 - Add one second     *" << endl;
	cout << "               " << "* 4 - Exit program       *" << endl;
	cout << "               " << "**************************" << endl;
//While to repeat "Please Enter Option:" if user enters anything outside of parameters.	
	char userInput = ' ';
	while (userInput < '1' || userInput > '4') {
		cout << "Please Enter Option : " << endl;
		cin >> userInput;
	}
	return userInput;
}

