#include <iostream>
#include <iomanip>

using namespace std;

void intialMenu() { //initial menu
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: " << endl;
    cout << "Monthly Deposit: " << endl;
    cout << "Annual Interest: " << endl;
    cout << "Number of years: " << endl;

    system("PAUSE");
}

void noMonthlyDeposits(float years, float initInvestment, float AnuInt) { //Data without monthly deposits
    float intAmount;

    cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==============================================================" << endl;
    cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 0; i < years; i++) {
        intAmount = (initInvestment) * ((AnuInt / 100)); //yearly interest
        initInvestment = initInvestment + intAmount;
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << initInvestment << "\t\t\t$" << intAmount << endl;
    }
}

void monthlyDeposits(float years, float initInvestment, float AnuInt, float monDeposit) { //Data with monthly deposits
    float yearTotInt;
    float intAmount;

    cout << endl << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "==============================================================" << endl;
    cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 0; i < years; i++) {
        yearTotInt = 0; //Set interest to zero
        for (int j = 0; j < 12; j++) {
            intAmount = (initInvestment + monDeposit) * ((AnuInt / 100) / 12); //monthly interest
            yearTotInt = yearTotInt + intAmount; //month end interest
            initInvestment = initInvestment + monDeposit + intAmount;
        }
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << initInvestment << "\t\t\t$" << yearTotInt << "\n";
    }
}

int main()
{
    float initInvestment;
    float monDeposit;
    float AnuInt;
    float years;

    intialMenu(); //call function for menu

    //Get data from user
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: $";
    cin >> initInvestment;
    cout << "Monthly Deposit: $";
    cin >> monDeposit;
    cout << "Annual Interest: %";
    cin >> AnuInt;
    cout << "Number of years: ";
    cin >> years;

    system("PAUSE");

    noMonthlyDeposits(years, initInvestment, AnuInt); //call function for no monthly deposits

    monthlyDeposits(years, initInvestment, AnuInt, monDeposit); //call function for monthly deposits

    return 0;
}