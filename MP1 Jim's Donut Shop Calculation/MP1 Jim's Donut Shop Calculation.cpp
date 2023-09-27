/*MP1 Jims Donut Shop - Breanna Sproul - 28 Sept 2023
Calculation of a customer's order in Jims Donut Shop
Considers: price of donuts/fritter from given amount, sales tax, and change back*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {

	//defining starting price variables
	double price_reg = 0.75;
	double price_reg12 = 7.99;
	double price_fancy = 0.85;
	double price_fancy12 = 8.49;
	double price_fritter = 1.50;

	//asking for regular orders and separating for dozens
	cout << "Number of regular donuts ordered: ";
	int reg_all;
	cin >> reg_all;

	int reg_dozen = 0;
	if (reg_all > 11) {
		reg_dozen = reg_all / 12;
	}
	int regular = reg_all - (reg_dozen * 12);

	//asking for fancy orders
	cout << "Number of fancy donuts ordered: ";
	int fancy_all;
	cin >> fancy_all;

	int fancy_dozen = 0;
	if (fancy_all > 11) {
		fancy_dozen = fancy_all / 12;
	}
	int fancy = fancy_all - (fancy_dozen * 12);

	//asking for fritter order
	cout << "Number of apples fritters ordered: ";
	int fritter;
	cin >> fritter;

	//sum of order + tax
	double order = (regular * price_reg) + (reg_dozen * price_reg12) + (fancy * price_fancy) + (fancy_dozen * price_fancy12) + (fritter * price_fritter);
	double sale_tax = 0.075;

	//rounding tax and applying to order
	double unedit_tax = order * sale_tax;
	double round_tax = unedit_tax + 0.005;
	int fix_round = round_tax * 100;
	double final_tax = (double)fix_round / 100.0;
	double final_order = order + final_tax;

	cout << fixed << setprecision(2) << "Customer owes: $" << final_order << endl;

	//customer pay
	cout << "Customer pays: $";
	double customer_pay;
	cin >> customer_pay;

	//determining change to give back
	double change = customer_pay - final_order;

	if (change == 0) {
		cout << "Exact payment received - no change owed.";
	}
	else { cout << fixed << setprecision(2) << "Change owed is: $" << change << " - "; }

	//starting values for variables
	int dollar = 0;
	int quarter = 0;
	int dime = 0;
	int nickel = 0;
	int penny = 0;

	int changeEdit = change * 100;

	//dollars
	if (changeEdit > 99) {
		dollar = changeEdit / 100;
	}

	//quarters
	if ((changeEdit - (dollar * 100)) > 24) {
		quarter = (changeEdit - dollar * 100) / 25;
	}

	//dime
	if ((changeEdit - ((dollar * 100) + (quarter * 25))) > 9) {
		dime = (changeEdit - ((dollar * 100) + (quarter * 25))) / 9;
		//cout << "dime check: " << dime << endl;
		//had to change the /10 to a /9, but im not sure why it wouldnt work??
	}
	

	//nickel
	if (((changeEdit - ((dollar * 100) + (quarter * 25) + (dime * 10)))) > 4) {
		nickel = ((changeEdit - ((dollar * 100) + (quarter * 25) + (dime * 10))) / 5);
	}

	//penny
	if (((changeEdit - ((dollar * 100) + (quarter * 25) + (dime * 10) + (nickel * 5)))) >= 1) {
		penny = ((changeEdit - ((dollar * 100) + (quarter * 25) + (dime * 10) + (nickel * 5))) / 1);
	}

	//outputting change with punctuation
	//dollar punctuation
	if (dollar > 0 && (quarter > 0 || dime > 0 || nickel > 0 || penny > 0)) {
		cout << dollar;
		if (dollar == 1) {
			cout << " dollar";
		}
		else {
			cout << " dollars";
		}
		cout << ", ";
	}
	else if (dollar > 0 && (quarter == 0 && dime == 0 && nickel == 0 && penny == 0)) {
		cout << dollar;
		if (dollar == 1) {
			cout << " dollar";
		}
		else {
			cout << " dollars";
		}
		cout << ". ";
	}

	//quarter punctuation
	if (quarter > 0 && (dime > 0 || nickel > 0 || penny > 0)) {
		cout << quarter;
		if (quarter == 1) {
			cout << " quarter";
		}
		else {
			cout << " quarters";
		}
		cout << ", ";
	}
	else if (quarter > 0 && (dime == 0 && nickel == 0 && penny == 0)) {
		cout << quarter;
		if (quarter == 1) {
			cout << " quarter";
		}
		else {
			cout << " quarters";
		}
		cout << ". ";
	}

	//dime puncuation
	if (dime > 0 && (nickel > 0 || penny > 0)) {
		cout << dime;
		if (dime == 1) {
			cout << " dime";
		}
		else {
			cout << " dimes";
		}
		cout << ", ";
	}
	else if (dime > 0 && (nickel == 0 && penny == 0)) {
		cout << dime;
		if (dime == 1) {
			cout << " dime";
		}
		else {
			cout << " dimes";
		}
		cout << ". ";
	}

	//nickel punctuation
	if (nickel > 0 && (penny > 0)) {
		cout << nickel;
		if (nickel == 1) {
			cout << " nickel";
		}
		else {
			cout << " nickels";
		}
		cout << ", ";
	}
	else if (nickel > 0 && (penny == 0)) {
		cout << nickel;
		if (nickel == 1) {
			cout << " nickel";
		}
		else {
			cout << " nickels";
		}
		cout << ". ";
	}

	//penny punctuation
	if (penny > 0) {
		cout << penny;
		if (penny == 1) {
			cout << " penny.";
		}
		else {
			cout << " pennies.";
		}
	}
}