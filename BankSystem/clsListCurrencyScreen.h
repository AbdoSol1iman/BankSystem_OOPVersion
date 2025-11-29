#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
class clsListCurrencyScreen: protected clsScreen
{
private:
    static void PrinturrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(7) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(15) << left << Currency.Rate();
    
    } 

public:
	static void ShowListCurrencyScreen() {

            vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
            string Title = "\t  Currency List Screen";
            string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency(s).";

            _DrawScreenHeader(Title, SubTitle);


            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
            cout << "| " << left << setw(7) << "Code";
            cout << "| " << left << setw(40) << "Name";
            cout << "| " << left << setw(15) << "Rate/(1$)";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vCurrencies.size() == 0)
                cout << "\t\t\t\tNo vCurrencies Available In the System!";
            else

                for (clsCurrency Currency : vCurrencies)
                {

                    PrinturrencyRecordLine(Currency);
                    cout << endl;
                }

           cout << setw(8) << left << "" << "\n\t_______________________________________________________";
           cout << "_________________________________________\n" << endl;
	}
};
