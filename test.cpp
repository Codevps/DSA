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
    // using bit
    int binary = 0;
    while (n != 0)
    {
        int bit = n & 1;
        binary = binary * 10 + bit;
        n = n >> 1;
    }
    cout << binary << endl;

    // without using bit operator
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
    // two times occuring only one element is occuring one time
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // n^n = 0;
        // n^0 = n;
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

// pivot of an array:
int leftSum(int x, int arr[])
{
    int sum = 0;
    for (int i = 0; i <= x - 1; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int rightSum(int n, int arr[], int i)
{
    int sum = 0;
    for (int j = i + 1; j < n; j++)
    {
        sum = sum + arr[j];
    }
    return sum;
}

// Pivot of unsorted array
int pivot(int n, int arr[])
{
    int i = 0;
    while (i < n)
    {
        if (leftSum(i, arr) == rightSum(n, arr, i))
        {
            return i;
        }
        i++;
    }
    return -1;
}

// reverse array

// here m is the number from where you have to start reversing the array if no need of m keep it as 0
void reverse(int n, int arr[], int m)
{
    int s = m + 1, e = n - 1;
    while (s <= e)
    {
        // swap(arr[s] , arr[e]  or
        int temp = arr[s];
        arr[s] = arr[e];
        s++;
        e--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// merge sorted array:
void print(int ans[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
void mergeSortedArrays(int n, int arr[], int m, int arr2[], int l, int arr3[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr[i] <= arr2[j])
        {
            arr3[k] = arr[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        arr3[k] = arr[i];
        k++;
        i++;
    }

    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }

    print(arr3, l);
}

bool checkPalindrome(string s)
{
    // the range of character is 65 to 90 ,
    // isalpha and isdigit are two stl c++ inbuilt functions
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]) || isdigit(s[i]))
        {

            if (int(s[i]) >= 65 && int(s[i]) <= 90)
                str += (s[i] - 'A' + 'a');
            else
                str += s[i];
        }
    }
    int st = 0, e = str.length() - 1;
    while (st <= e)
    {
        if (str[st++] != str[e--])
        {
            return false;
        }
    }
    return true;
}

// merge sort :
// split array in half and sort it and merge both of them
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    // dynamic memory allocation:
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy array:
    int index = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[index++];
    }

    index = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[index++];
    }

    // merge:
    int index1 = 0;
    int index2 = 0;
    index = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[index++] = first[index1++];
        }
        else
        {
            arr[index++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[index++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[index++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void solve(int *arr, int s, int e)
{
    // basecase:
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;

    // merge left:
    solve(arr, s, mid);

    // merge right:
    solve(arr, mid + 1, e);

    // merge:
    merge(arr, s, e);
}

// quicksort
// array given should be ascending
// do partiton and the put the first element in its right place and then if left side of that element is greater than the element or its right side then swap
int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = count + s;
    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void solve(int *arr, int s, int e)
{
    // basecase:
    if (s >= e)
    {
        return;
    }

    // do partition
    int p = partition(arr, s, e);

    // sort left and right:
    solve(arr, s, p - 1);
    solve(arr, p + 1, e);
}

// subset
class Solution
{
private:
    void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> output, int index)
    {
        //         base case:
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        //         exclude:
        solve(nums, ans, output, index + 1);
        //         include:
        int element = nums[index];
        output.push_back(element);
        solve(nums, ans, output, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, ans, output, index);
        return ans;
    }
};
// subsequences

void solve(string str, vector<string> &ans, string output, int index)
{
    //     base case:
    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    //         exclude case:
    solve(str, ans, output, index + 1);

    //         include case:
    char element = str[index];
    output.push_back(element);
    solve(str, ans, output, index + 1);
}
vector<string> subsequences(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, ans, output, index);
    return ans;
}

// phonekeypad
class Solution
{
private:
    void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
    {

        // base case
        if (index >= digit.length())
        {
            ans.push_back(output);
            return;
        }

        int number = digit[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digit, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};

// permutation:
class Solution
{
private:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index)
    {
        // basecase:
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(nums, ans, index + 1);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};

// book allocation problem: minimum no of pages alloted to a student01
int isPossible(int n, int arr[], int m, int mid)
{
    int students = 0;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            students++;
            if (students > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
int allocation(int n, int arr[], int m)
{
    int s = 0;
    int e = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        e += arr[i];
    }
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(n, arr, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
