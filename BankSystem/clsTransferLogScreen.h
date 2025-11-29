#pragma once
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"
#include "clsTransfer.h"

class clsTransferLogScreen : protected clsScreen
{
private:
    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {
        
        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(10) << left << TransferLogRecord.sAcct;
        cout << "| " << setw(10) << left << TransferLogRecord.dAcct;
        cout << "| " << setw(10) << left << to_string(TransferLogRecord.Amount);
        cout << "| " << setw(10) << left << to_string(TransferLogRecord.sBalance);
        cout << "| " << setw(10) << left << to_string(TransferLogRecord.dBalance);
        cout << "| " << setw(10) << left << TransferLogRecord.username;
    }

public:
	static void ShowTransferLogScreen() {

        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}
};
