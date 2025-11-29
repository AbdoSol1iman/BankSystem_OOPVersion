#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsUpdateRateScreen:protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _UpdateCurrencyRate(clsCurrency& Currency) {
		cout << "\nEnter New Rate : ";
		float newrate = clsInputValidate::ReadNumber<float>();
		Currency.UpdateRate(newrate);
	}
public:
	static void ShowUpdateRateScreen() {
		_DrawScreenHeader("Update Currency Screen");

		string CurrencyCode;
		
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();
		

		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency Code is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
			
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrency(Currency); 

		cout << "\nAre you sure you want to update this currency  y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {
			cout << "\n\nUpdateCurrency Rate:\n";
			cout << "\n\n____________________\n";

			_UpdateCurrencyRate(Currency);
			cout << "\n\nCurrency Rate updated Successfully\n";
			_PrintCurrency(Currency);

		}


		
	}
};

