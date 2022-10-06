#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long profit[50001][50001];

long do_stockmax(vector<int> prices, int day, int amount) {
    if (profit[day][amount] != -1) {
        return profit[day][amount];
    }
    
    if (day == (int) prices.size()) {
        return 0;
    }
    // If you have no amount, you cannot sell
    // Only options are buy/nothing
    if (amount == 0) {
        return (profit[day][amount] = max(
            -prices[day] + do_stockmax(prices, day+1, amount+1),
            do_stockmax(prices, day+1, amount)));
    }
    // If you have amount, you can sell 1 up to n
    // or buy or nothing
    long maxSelling = 0;
    for (int i = 1; i <= amount; i++) {
        maxSelling = max(maxSelling, 
            (i * prices[day]) + do_stockmax(prices, day+1, amount-i)
        );
    }
    return (profit[day][amount] = max(maxSelling, 
        max(-prices[day] + do_stockmax(prices, day+1, amount+1),
            do_stockmax(prices, day+1, amount))));
}

/*
 * Complete the 'stockmax' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY prices as parameter.
 */

long stockmax(vector<int> prices) {
    for (int i = 0; i < (int) prices.size(); i++) {
        for (int j = 0; j < (int) prices.size(); j++) {
           profit[i][j] = -1;
        }
    }
    return do_stockmax(prices, 0, 0);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string prices_temp_temp;
        getline(cin, prices_temp_temp);

        vector<string> prices_temp = split(rtrim(prices_temp_temp));

        vector<int> prices(n);

        for (int i = 0; i < n; i++) {
            int prices_item = stoi(prices_temp[i]);

            prices[i] = prices_item;
        }

        long result = stockmax(prices);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

