/*
#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    int isEmpty()
    {
        if (top == -1)
        {
            cout << "empty stack" << endl;
            return true;
        }
        else
        {
            cout << "non empty stack" << endl;
            return false;
        }
    }
    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
            cout << arr[top] << endl;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }
    int peek()
    {
        int val = 0;
        if (top >= 0)
        {
            val = arr[top];
            cout << val << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
        return val;
    }

    void print()
    {
        // int count = size;
        // while (count != size)
        // {
        //     cout << arr[size] << " ";
        //     size--;
        // }
        // cout << endl;
        cout << "top: " << arr[top];
        cout << endl;
    }
};
int main()
{
    // stack<int> s;
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);
    // s.push(7);
    // cout << s.top() << endl;
    // cout << s.empty() << endl;
    // s.pop();
    // cout << s.top() << endl;

    Stack st(5);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    // cout << st.peek() << endl;
    st.peek();
    st.isEmpty();
    st.pop();
    st.peek();
    st.print();
}

//reverse string using stack:: written inside int main
    string str = "pratham";
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    string ans = "";
    while (!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout << ans << endl;


    //Delete middle element from stack

void solve(stack<int>&inputStack,int count ,  int N){
//     basecase:
    if(count == N/2){
        inputStack.pop();
        return;
}
    int num = inputStack.top();
    inputStack.pop();
    solve(inputStack, count+1 ,N);
    inputStack.push(num);

}
void deleteMiddle(stack<int>&inputStack, int N){
   // Write your code here
   int count = 0;
   solve(inputStack, count ,N);
}

//most popular:: if valid parenthesis::
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>s;
    for(int i  = 0 ; i < expression.length();i++){
        char ch = expression[i];
        if(ch == '(' ||ch == '{' ||ch == '[' ){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top = s.top();
                if((ch == ')' && top== '(') ||(ch == '}' && top== '{') || (ch == ']' && top== '[')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
};
*/