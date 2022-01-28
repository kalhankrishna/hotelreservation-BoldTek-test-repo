#include <bits/stdc++.h>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#define ll long long int
#define pb push_back

using namespace std;

vector<string> tokenize(string str, const regex re)
{
    sregex_token_iterator it{str.begin(),
                             str.end(), re, -1};
    vector<string> tokenized{it, {}};

    // Additional check to remove empty strings
    tokenized.erase(
        remove_if(tokenized.begin(),
                  tokenized.end(),
                  [](string const &s)
                  {
                      return s.size() == 0;
                  }),
        tokenized.end());

    return tokenized;
}

class Hotel
{
public:
    int rating;
    int regularWeekday;
    int regularWeekend;
    int rewardWeekday;
    int rewardWeekend;
};

int main()
{
    Hotel greenValley;
    greenValley.rating = 3;
    greenValley.regularWeekday = 1100;
    greenValley.regularWeekend = 900;
    greenValley.rewardWeekday = 800;
    greenValley.rewardWeekend = 800;

    Hotel redRiver;
    redRiver.rating = 4;
    redRiver.regularWeekday = 1600;
    redRiver.regularWeekend = 600;
    redRiver.rewardWeekday = 1100;
    redRiver.rewardWeekend = 500;

    Hotel blueHills;
    blueHills.rating = 5;
    blueHills.regularWeekday = 2200;
    blueHills.regularWeekend = 1500;
    blueHills.rewardWeekday = 1000;
    blueHills.rewardWeekend = 400;

    string input;
    cout << "Enter Customer Type and reservation dates: " << endl;
    cout << "INPUT FORMAT: <customer_type>: <date1>, <date2>, <date3>" << endl;
    getline(cin, input);

    const regex re("[^a-zA-Z]+");
    vector<string> tokenized = tokenize(input, re);

    string customerType = tokenized[0];

    int weekend = 0;
    int weekday = 0;

    for (int i = 2; i < tokenized.size(); i += 2)
    {
        string day = tokenized[i];
        if (day == "mon" or day == "tues" or day == "wed" or day == "thur" or day == "fri")
        {
            weekday++;
        }
        else if (day == "sat" or day == "sun")
        {
            weekend++;
        }
        else
        {
            cout << "Error:Invalid Input" << endl;
            break;
            return 0;
        }
    }

    int gvPrice = 0, rrPrice = 0, bhPrice = 0;

    if (customerType == "Regular")
    {
        gvPrice = weekday * greenValley.regularWeekday + weekend * greenValley.regularWeekend;
        rrPrice = weekday * redRiver.regularWeekday + weekend * redRiver.regularWeekend;
        bhPrice = weekday * blueHills.regularWeekday + weekend * blueHills.regularWeekend;
    }

    if (customerType == "Rewards")
    {
        gvPrice = weekday * greenValley.rewardWeekday + weekend * greenValley.rewardWeekend;
        rrPrice = weekday * redRiver.rewardWeekday + weekend * redRiver.rewardWeekend;
        bhPrice = weekday * blueHills.rewardWeekday + weekend * blueHills.rewardWeekend;
    }

    if (gvPrice < rrPrice and gvPrice < bhPrice)
    {
        cout << "GreenValley" << endl;
    }

    if (rrPrice < gvPrice and rrPrice < bhPrice)
    {
        cout << "RedRiver" << endl;
    }

    if (bhPrice < gvPrice and bhPrice < rrPrice)
    {
        cout << "BlueHills" << endl;
    }

    if (gvPrice == rrPrice)
    {
        if (greenValley.rating < redRiver.rating)
        {
            cout << "RedRiver" << endl;
        }
        else
        {
            cout << "GreenValley" << endl;
        }
    }

    if (gvPrice == bhPrice)
    {
        if (greenValley.rating < blueHills.rating)
        {
            cout << "BlueHills" << endl;
        }
        else
        {
            cout << "GreenValley" << endl;
        }
    }

    if (rrPrice == bhPrice)
    {
        if (redRiver.rating < blueHills.rating)
        {
            cout << "BlueHills" << endl;
        }
        else
        {
            cout << "RedRiver" << endl;
        }
    }

    if (gvPrice == rrPrice and gvPrice == bhPrice and rrPrice == bhPrice)
    {
        if (greenValley.rating > redRiver.rating and greenValley.rating > blueHills.rating)
        {
            cout << "GreenValley" << endl;
        }
        else if (redRiver.rating > blueHills.rating)
        {
            cout << "RedRiver" << endl;
        }
        else
        {
            cout << "BlueHills" << endl;
        }
    }

    return 0;
}

//If more data is added or data is changed, then modifying the classes and respective objects
//are enough to get a result.