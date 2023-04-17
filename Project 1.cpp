/*
 Caleb St.Germain
 chs0043
 project1_St.Germain_CHS0043.cpp
 compile project1_St.Germain_CHS0043.cpp then execute it.
 -std=c++14
 */
#include <iostream>
using namespace std;

int main() {

    //Formatting of the Output
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //info from user.
    cout << "Loan Amount: ";
    double lAmount;
    cin >> lAmount;
    cout << "Interest rate (% per year): ";
    double rate;
    cin >> rate;
    cout << "Monthly Payments: ";
    double payment;
    cin >> payment;

    //changing the rate into a decimal value.
    rate = rate/100;

    //change to monthly rate.
    rate = rate/12;

    //Initialize the variables.
    double balance = lAmount;
    double interest;
    double principal;
    double totalInterest = 0.0;
    int month = 0;

    //checking to make sture that the monthly payments are enough to pay off the interest.
    bool canPay;
    interest = balance * rate;
    if(payment <=interest){
        cout << "You'll need a higher monthly payment, otherwise you can't pay off the loan" << endl;
        canPay = false;
    }
    else {
        canPay = true;
    }

    if(canPay){
        //Start of table
        cout << "*********************************************************" << endl;
        cout << "\tAmortization Table" << endl;
        cout << "*********************************************************" << endl;
        cout << "Month\tBalance\t  Payment\tRate\tInterest\tPrincipal" << endl;
        cout << "0\t\t$" << lAmount << "  N/A\t\tN/A\t\tN/A\t\t\tN/A" << endl;

        //Calculation of each monthly payment.
        while (balance > 0.0){
            month++;
            interest = balance * rate;
            totalInterest = totalInterest + interest;
            //checking to see if the payment is more than what we can actually pay.
            if (payment > (balance + interest)){
                payment = balance + interest;
            }
            principal = payment - interest;
            balance = balance - principal;
            //result (formatting accounting for additional digit spaces).
            if(balance > 1000){
                cout << month << "\t\t$" << balance << "  $" << payment << "\t" << rate * 100 << "\t$" << interest << "\t\t$" << principal << endl;
            }
            else{
                cout << month << "\t\t$" << balance << "\t  $" << payment << "\t" << rate * 100 << "\t$" << interest << "\t\t$" << principal << endl;
            }

        }
        //total numbers.
        cout << "*********************************************************" << endl << endl;
        cout << "It takes " << month << " months to pay off the loan." << endl;
        cout << "Total interest paid is: $" << totalInterest << endl;
    }
}
