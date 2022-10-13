// CPP Program to print Fibonomial Triangle of height n.
#include<bits/stdc++.h>
#define N 6
using namespace std;

// Function to produce Fibonacci Series.
void fib(int f[], int n)
{
	int i;

	/* 0th and 1st number of the series are 0 and 1*/
	f[0] = 0;
	f[1] = 1;

	for (i = 2; i <= n; i++)
	
		/* Add the previous 2 numbers in the series
		and store it */
		f[i] = f[i-1] + f[i-2];
}

// Function to produce fibonomial coefficient
void fibcoef(int fc[][N+1], int f[], int n)
{
	for (int i = 0; i <= n; i++)
		fc[i][0] = 1;
		
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int k = j;
			while(k--)
				fc[i][j] *= f[k];
				
			k = 1;
			
			while((j+1)!=k)
				fc[i][j] /= f[k++];
		}
	}
}

// Function to print Fibonomial Triangle.
void printFibonomialTriangle(int n)
{
	int f[N+1] = { 0 };
	
	// Finding the fibonacci series.
	fib(f, n);
	
	// to store triangle value.
	int dp[N+1][N+1] = { 0 };
	
	// initialising the 0th element of each row
	// and diagonal element equal to 0.
	for (int i = 0; i <= n; i++)
		dp[i][0] = dp[i][i] = 1;
		
	// for each row.
	for (int i = 1; i <= n; i++)
	{
		// for each column.
		for (int j = 1; j < i; j++)
		
			// finding each element using recurrence
			// relation.
			dp[i][j] = f[i-j+1]*dp[i-1][j-1] +
					f[j-1]*dp[i-1][j];
	}
	
	// printing the Fibonomial Triangle.
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)	
			cout << dp[i][j] << " ";	
		cout << endl;
	}
}
// Driven Program
int main()
{
	int n = 6;
	printFibonomialTriangle(n);
	return 0;
}
