#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsListCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen :protected clsScreen
{
private:
    enum enCurrencyExchangeMenueoptions {
        eListCurrency=1,eFindCurrency=2,eUpdateRate=3,eCurrencyCalculator=4,eMainMenue=5
    };
     
    static short _ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menue...";
        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static void _ShowListCurrencyScreen()
    {
        //cout << "\nList Currency Screen Will Be Here.\n";
        clsListCurrencyScreen::ShowListCurrencyScreen();    

    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "\nFind Currency Screen Will Be Here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "\nUpdate Rate Screen Will Be Here.\n";
        clsUpdateRateScreen::ShowUpdateRateScreen();

    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //cout << "\nCurrency Calculator Screen Will Be Here.\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformManageUsersMenueOption(enCurrencyExchangeMenueoptions CurrencyExchangeMenueoptions)
    {

        switch (CurrencyExchangeMenueoptions)   
        {
        case enCurrencyExchangeMenueoptions::eListCurrency :
        {
            system("cls");
            _ShowListCurrencyScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enCurrencyExchangeMenueoptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enCurrencyExchangeMenueoptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enCurrencyExchangeMenueoptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enCurrencyExchangeMenueoptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
            break;
        }
        }

    }

    
public:
	static void ShowCurrencyExchangeMenue() {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currency.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enCurrencyExchangeMenueoptions)_ReadCurrencyExchangeMenueOption());

	}
};

