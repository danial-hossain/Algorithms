#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 5;
    if (c == '*' || c == '/') return 4;
    if (c == '+' || c == '-') return 3;
    return -1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char symbol = infix[i];

        if (isdigit(symbol)) {
            postfix += symbol;
        }
        else if (symbol == '(') {
            s.push(symbol);
        }
        else if (symbol == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else if (isOperator(symbol)) {
            while (!s.empty() && precedence(symbol) <= precedence(s.top()) && symbol != '^') {
                postfix += s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char symbol : postfix) {
        if (isdigit(symbol)) {
            s.push(symbol - '0');
        }
        else if (isOperator(symbol)) {
            if (s.size() < 2) {
                cerr << "Error: Not enough operands\n";
                return -1;
            }
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            switch (symbol) {
                case '^': s.push(pow(b, a)); break;
                case '*': s.push(b * a); break;
                case '/':
                    if (a == 0) {
                        cerr << "Error: Division by zero\n";
                        return -1;
                    }
                    s.push(b / a);
                    break;
                case '+': s.push(b + a); break;
                case '-': s.push(b - a); break;
            }
        }
    }

    return s.size() == 1 ? s.top() : -1;
}

int main() {
    string infix="(12 + 34) * 56 - 78 / 9";
    cout << "Input infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    if (result != -1) {
        cout << "Value: " << result << endl;
    }

    return 0;
}
