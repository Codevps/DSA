#include <bits/stdc++.h>
using namespace std;

/*
* Remember to put <<time and space complexity >>limitations on the code !!!! 
*/
// functions-----------------------------------------------------------------------
void fibonacci(int n)
{
    int i = 0;
    int first = 0;
    int second = 1;
    cout << first << " " << second << " ";
    while (i < n - 2)
    {
        int temp = first + second;
        cout << temp << " ";
        first = second;
        second = temp;
        i++;
    }
}

void armstrong(int n)
{
    int y = n;
    int x = 0;
    while (n != 0)
    {
        int ld = n % 10;
        x = x + pow(ld, 3);
        n = n / 10;
    }
    if (x == y)
    {
        cout << "Armstrong No. " << endl;
    }
    else
    {
        cout << "Not an armstrong no. " << endl;
    }
}
int reverse(int n)
{
    int rev = 0;
    while (n != 0)
    {
        int ld = n % 10;
        rev = (rev * 10) + ld;
        n = n / 10;
    }
    return rev;
}

int prime(int n)
{
    int i = 2;
    {
        if (n == 2)
        {
            cout << "Prime" << endl;
            return 0;
        }
        if (n % 2 == 1)
        {
            cout << " Prime" << endl;
        }
        else
        {
            cout << " not Prime " << endl;
        }
    }
    return 0;
}

int factorial(int n)
{
    int fact = n;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

void permutation(int n, int r)
{
    int x = factorial(n) / (factorial(n - r));
    cout << x << endl;
}

void combination(int n, int r)
{
    int x = factorial(n) / (factorial(n - r) * factorial(r));
    cout << x << endl;
}

void min_maxArray(int n, int arr[])
{
    int max = INT_MIN;
    int min = INT_MAX;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << min << endl;
    cout << max << endl;
}

void linearSearch(int n, int arr[], int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            cout << i + 1 << endl;
    }
}

void binarySearch(int n, int arr[], int key)
{
    int s = 0, e = n;
    for (int i = 0; i < n; i++)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
            cout << mid + 1 << endl;
        else
        {
            if (arr[mid] > key)
                e = mid - 1;
            else
                s = mid + 1;
        }
    }
}

void linearSort(int n, int arr[])
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void dtb(int n)
{
    int binary = 0;
    while (n != 0)
    {
        int bit = n & 1;
        binary = binary * 10 + bit;
        n = n >> 1;
    }
    cout << binary << endl;

    int binary = 0;
    while (n != 0)
    {
        int bit = n % 2;
        binary = binary * 10 + bit;
        n = n / 2;
    }
    cout << binary << endl;
}

void btd(int n)
{
    int binary = 0;
    while (n != 0)
    {
        int bit = n % 10;
        binary = binary * 2 + bit;
        n = n / 10;
    }
    cout << binary << endl;
}

void arraySum(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    cout << sum << endl;
}

void swapAlternate(int n, int arr[])
{
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int unique(int n, int arr[])
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int duplicates(int n, int arr[])
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}