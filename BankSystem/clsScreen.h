#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "clsDate.h"
#include "clsUser.h"
#include "Global.h"
#include "clsSaveLogDetails.h"

using namespace std;

class clsScreen
{
private:
    /*static string _GetDate() {
        time_t now = time(0);

        // Safe version
        tm localTime;
        localtime_s(&localTime, &now);

        int Year = 1900 + localTime.tm_year;
        int Month = 1 + localTime.tm_mon;
        int Day = localTime.tm_mday;
        string Date = to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year);
        return Date;
    }*/

    
   
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        
        cout << "\t\t\t\t\tUser: "<<CurrentUser.UserName;
        string Date = clsDate::DateToString(clsDate());
        cout << "\n\t\t\t\t\tDate:"<< Date<<"\n\n";
        //cout << "\n\t\t\t\t\tDate:"<< _GetDate()<<"\n\n";
        
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }


};