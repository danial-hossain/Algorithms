#include <bits/stdc++.h>
using namespace std;
int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
        return -1;
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}
string infixToPostfix(string s)
{
    stack<char> op;
    string postFix;
    for (int i = 0; i < s.length(); i++)
    {
        string sp;
        if (s[i] == ' ')
        {
            continue;
        }
        else if (s[i] == '(')
        {
            op.push('(');
        }
        else if (s[i] == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                postFix += op.top();
                postFix += " ";
                op.pop();
            }
            op.pop();
        }
        else if (!isOperator(s[i]))
        {
            string num = "";
            while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            {
                num += s[i];
                i++;
            }
            i--;
            postFix += num + " ";
        }
        else
        {
            while (!op.empty() && precedence(s[i]) <= precedence(op.top()))
            {
                postFix += op.top();
                postFix += " ";
                op.pop();
            }
            op.push(s[i]);
        }
    }
    while (!op.empty())
    {
        postFix += op.top();
        postFix += " ";
        op.pop();
    }
    return postFix;
}
int postfixEvaluation(string s)
{
    stack<int> st;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        else if (isdigit(s[i]))
        {
            string num = "";
            int number = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            {
                number = number * 10 + (s[i] - '0');
                i++;
            }
            i--;

            st.push(number);
        }

        else
        {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(val1 + val2);
                break;
            case '-':
                st.push(val1 - val2);
                break;
            case '*':
                st.push(val1 * val2);
                break;
            case '/':
                st.push(val1 / val2);
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string exp = "(12 + 34) * 56 - 78 / 9";
    string postFix = infixToPostfix(exp);
    cout << "Infix to Postfix : " << postFix << endl;
    cout << "Evaluation of Postfix : " << postfixEvaluation(postFix);
    return 0;
}