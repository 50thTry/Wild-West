// Ivan Wen
// 4/9/2023
// CS-210

#include <iostream>
#include <tuple>
#include <iomanip>
using namespace std;


double initInvest = 0.0;
double startBal = 0.0;
double intRate = 0.0;
double interestFactor = 0.0;
double newBal = 0.0;
double depoAmount = 0.0;
double totalFactor = 0.0;
double totalNoDeposit = 0.0;
double totalDeposit = 0.0;
double monthlyInterest = 0.0;
int numYears = 0;
int periodFactor = 0;
tuple<double, double, double, int> userChoices;
char stop =  'y';

double calculateNoDeposit(double initInvest, double intRate){ //Calculates balance without monthly deposit
	intRate = intRate / 100;
	interestFactor = (intRate / 12);
	for (int i = 1; i <= 12; i++) {
		monthlyInterest = initInvest * interestFactor;
		initInvest = initInvest + monthlyInterest;
	}
	totalNoDeposit = round(initInvest * 100)/100;
	return totalNoDeposit;
}

double calculateDeposit(double initInvest, double intRate, double depoAmount) { //Calculates balance with monthly deposit
	intRate = intRate / 100;
	interestFactor = (intRate / 12);
	for (int i = 1; i <= 12; i++) {
		monthlyInterest = (initInvest + depoAmount) * interestFactor;
		initInvest = initInvest + depoAmount + monthlyInterest;
	}
	totalDeposit = round(initInvest*100)/100;
	return totalDeposit;
}

void getList() { // Displays final balance for deposit and no deposit
	cout.setf(ios::left); //sets up allignment to line up chart
	cout << "Balance and interest without Additional Monthly Deposit" << endl;
	cout.width(8); //sets up width of line for the next cout
	cout << "Year";
	cout.width(20);
	cout << "Year End Balance";
	cout.width(20);
	cout << "Interest Earned" << endl;
	startBal = initInvest;
	for (int i = 1; i <= numYears; i++) { //Loop to calculate balance based on input number of years
		calculateNoDeposit(initInvest, intRate);
		newBal = (totalNoDeposit - initInvest);
		newBal = round(newBal * 100) / 100;
		initInvest = totalNoDeposit;
		cout.width(8);
		cout << i;
		cout << "$";
		cout.width(20);
		cout << totalNoDeposit;
		cout << "$";
			cout.width(20);
		cout << newBal << endl;
	}
	initInvest = startBal;
	cout << endl;
	cout << "Balance and interest with Monthly Deposit" << endl;
	cout.width(8);
	cout << "Year";
	cout.width(20);
	cout << "Year End Balance";
	cout.width(20);
	cout << "Interest Earned" << endl;
	for (int i = 1; i <= numYears; i++) { //Loop to calculate balance based on input number of years
		calculateDeposit(initInvest, intRate, depoAmount);
		newBal = totalDeposit - initInvest - (depoAmount* 12);
		initInvest = totalDeposit;
		cout.width(8);
		cout << i;
		cout << "$"; 
		cout.width(20);
		cout << totalDeposit;
		cout << "$";
		cout.width(20);
		cout << newBal << endl;
	}
	initInvest = 0.0;
	intRate = 0.0;
	depoAmount = 0.0;
	numYears = 0.0;

}

void menuDisplay() { //Displays initial menu with user inputs
	cout << "*************** Data Input ***************" << endl;
	cout << "Initial Invest Amount: " << initInvest << endl;
	cout << "Monthly Deposit: " << depoAmount << endl;
	cout << "Annual Interest: " << intRate << endl;
	cout << "Year Invested: " << numYears << endl;
}

tuple<double, double, double, int> userInput() { //Collects user input in a tuple to return
	cout << "Please enter your Investment Amount" << endl;
	cin >> initInvest;
	cout << "Please enter your Monthly Deposit" << endl;
	cin >> depoAmount;
	cout << "Please enter your annual interest rate" << endl;
	cin >> intRate;
	cout << "Please enter the length of the investment in Years" << endl;
	cin >> numYears;
	userChoices = make_tuple(initInvest, depoAmount, intRate, numYears);
	return userChoices;
	}
int main() {
	while (stop != 'n') { //loop to stop on char n
		userInput();
		menuDisplay();
		system("Pause");
		getList();
		system("Pause");
		cout << "Continue? y/n" << endl;
		cin >> stop;
	}


}

