#include <string>
#include <iostream>
#include <algorithm>  
using namespace std;

int min(int a, int b)
{

	return (a < b) ? a : b;

}


void fillArray(int arr[], int N, int value)
{
	for (int i = 0; i < N; i++)
		arr[i] = value;

}


int coinChange(int coins[], int coinsLength,int amount)//bottom up approach
{
	sort(coins, coins + coinsLength);//to improve average case
	int* dp = new int[amount+1];
	fillArray(dp, amount + 1, amount+1);
	dp[0] = 0;

	for (int i = 0; i <= amount; i++)
	{
		for (int j = 0; j < coinsLength; j++)
		{
			if (coins[j] <= i)
			{
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
			else
				break;//to improve average case
		}
	}
	return (dp[amount] > amount) ? -1 : dp[amount];
	
}


int main()
{
	int coinsSize=3;

	int* coins = new int[coinsSize];
	int amount = 11;

	coins[0] = 1;
	coins[1] = 2;
	coins[2] = 5;

	cout<<coinChange(coins, coinsSize, amount)<<endl;
	
	system("pause");
	return 0;
}