#include <string>
#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;


long makeChange(vector<int> coins, int money, int index, unordered_map<string, long> memo)//Using Memoization
{

	if (money == 0)
		return 1;

	if (index >= coins.size())
		return 0;

	string key = money + "-" + index;
	if (memo.find(key) != memo.end())//if the memo contains the key
		return memo.at(key);

	int amountWithCoin = 0;
	long ways = 0;
	while (amountWithCoin <= money)
	{
		int remaining = money - amountWithCoin;
		ways += makeChange(coins, remaining, index + 1, memo);
		amountWithCoin += coins.at(index);
	}
	memo.insert({ key, ways });
	return ways;

}

long makeChange(vector<int> coins, int money)
{
	unordered_map<string, long> memo;
	return makeChange(coins, money, 0, memo);

}


int main()
{

	vector<int> coins{ 1, 2, 5 };
	
	cout<<makeChange(coins, 11)<<endl;
	/*
	Example:
		Input: { 1,2,3} with 4
		Output:4
	*/

	system("pause");
	return 0;
}