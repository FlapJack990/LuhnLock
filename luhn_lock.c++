#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> Make_arr(string num);
int Luhn_check_num(string num);
bool Luhn_check_sum(string num);

int main()
{
    string Cred_num;
    cout << "Enter Your Credit or Debit Number Please: " << endl;
    cin >> Cred_num;
    bool check_the_credit = Luhn_check_sum(Cred_num);
    if (!check_the_credit) {
        cout << "Your Card is Invalid!" << endl;
    }
    else {
        cout << "Valid!" << endl;
    }
    return 0;
}

vector<int> Make_arr(string num) {
    vector<int> arr;

    for (char c : num) {
        arr.push_back(c-'0');
    }
    return arr;
}

int Luhn_check_num(string num) {
    vector<int> arr = Make_arr(num);
    int even = 0;
    int odd = 0;
    for (int i = arr.size() - 2; i >= 0; i -= 2)
    {
        if (arr[i] > 4) {
            even += arr[i]*2 - 9;
        } else
            even += arr[i] * 2;
    }
    for (int i = arr.size() - 1; i >= 0; i -= 2)
    {
        odd += arr[i];
    }
    return even + odd;
}

bool Luhn_check_sum(string num) {
    int number = Luhn_check_num(num);
    return number % 10 == 0;
}
