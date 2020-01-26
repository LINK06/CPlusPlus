

#include <iostream>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <ctime>

using namespace std;

void TotalTicketCost(); //function for total amount of ticket
bool isFined(int, int);

//main function calls the programs functions
int main()
{

	TotalTicketCost();

	return 0;
	
} // end main

// TotalTicketCost will create a random speed limit and prompt for user input of the drivers speed
// Based on the Drivers speed compared to speed limit a ticket price will be determined

void TotalTicketCost() {

	int DriversSpeed; //users input of drivers speed	
	char response; // 'y' or 'n' response to run program again

	do {

		//generate random number between 25 and 65	
		srand(time(0));
		int SpeedLimit = (25 + rand() % 40);

		//display random speed limit
		//prompt for user input of drivers speed
		cout << "The speed limit is: " << SpeedLimit << "\n";
		cout << "Enter the drivers speed: ";
		cin >> DriversSpeed;
		cout << "The speed limit is: " << SpeedLimit << "\n";
		cout << "The drivers speed was: " << DriversSpeed << "\n";

		//looping if user wants to input another potential violation
		while (!isFined(DriversSpeed, SpeedLimit))
			cin >> DriversSpeed;

		cout << "Would you like to enter another Speeding Violation (y, n)? ";
		cin >> response;

		cout << endl;
	} while (response == 'y');
}
	
	
//Function for determing price of ticket and looping if user want to do another Speed Ticket entry
bool isFined(int g, int a) {

	double BaseTicket{ 60.25 };
	//Determines the price of the ticket based on the Drivers Speed
		//Price if speed was 5 or less than the speed limit
	if (g > a && g <= (a + 5)) {		
		cout << "The speeding fine is: $" << BaseTicket << endl;
		return BaseTicket;
	}
	//Price if speed was 10 or less than the speed limit
	else if (g > (a + 5) && g <= (a + 10)) {
		double Ticket1 = BaseTicket + (BaseTicket * .05);
		cout << setprecision(2) << fixed;
		cout << "The speeding fine is: $" << Ticket1 << endl;
		return Ticket1;
	}
	//Price if speed was 20 or less than the speed limit
	else if (g > (a + 10) && g < (a + 20)) {
		double Ticket2 = BaseTicket + (BaseTicket * .1);
		cout << setprecision(2) << fixed;
		cout << "The speeding fine is: $" << Ticket2 << endl;
		return Ticket2;
	}
	//Price if speed was more than 20 than the speed limit
	else if (g >= (a + 20)) {
		double Ticket3 = BaseTicket + (BaseTicket * .2);
		cout << setprecision(2) << fixed;
		cout << "Thee speeding fine is: $" << Ticket3 << endl;
		return Ticket3;
	}
	//No ticket if Driver was not speading
	else if (g <= a){
		cout << " The driver was not speeding, and will not receive a ticket." << endl;
		return true;
	}
	
	return 0;
	
}

	



