#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Convert infix to postfix while handling multi-digit numbers
string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // Ignore spaces
        if (c == ' ')
            continue;

        // Handle multi-digit numbers
        if (isdigit(c))
        {
            while (i < s.length() && isdigit(s[i]))
            {
                result += s[i];
                i++;
            }
            result += ' '; // Separator for multi-digit numbers
            i--;           // Adjust loop counter
        }
        // If '(' push to stack
        else if (c == '(')
            st.push('(');
        // If ')' pop till '(' is found
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                result += ' '; // Separator for operators
                st.pop();
            }
            st.pop(); // Remove '(' from stack
        }
        // If an operator is found
        else
        {
            while (!st.empty() && prec(c) <= prec(st.top()))
            {
                result += st.top();
                result += ' '; // Separator for operators
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        result += st.top();
        result += ' ';
        st.pop();
    }

    return result;
}

// Function to evaluate postfix expression
int evaluatePostfix(string exp)
{
    stack<int> st;
    int i = 0;
    while (i < exp.size())
    {
        // Skip spaces
        if (exp[i] == ' ')
        {
            i++;
            continue;
        }

        // If number, push to stack
        if (isdigit(exp[i]))
        {
            int num = 0;
            while (i < exp.size() && isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            st.push(num);
        }
        // If operator, pop two values and apply operation
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            switch (exp[i])
            {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
            i++;
        }
    }
    return st.top();
}

int main()
{
    string infix = "(12 + 34) * 56 - 78 / 9";
    cout << "Infix to Postfix: ";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;

    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;
    return 0;
}
