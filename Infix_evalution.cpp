#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;
class Infix_eval
{
    stack<int> numb;
    stack<char> operators;
    string expression;

public:
    // Function get_input gets the expression from the user
    void get_input()
    {
        expression = "";
        cout << "Please enter expression" << endl;
        // getline(cin, expression);
        cin >> expression;
    }
    // Function defines precedence of operators;
    int precedence(char c)
    {
        switch (c)
        {
        case '(':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        case ')':
            return 0;
        }
        return -1;
    }
    // Funcion evaluate does not check precedence, precedence will have to be checked by another function calling evaluate
    void evaluate()
    {
        int first = numb.top();
        numb.pop();
        int second = numb.top();
        numb.pop();
        char c = operators.top();
        operators.pop();
        switch (c)
        {
        case '*':
            numb.push(first * second);
            return;
        case '/':
            numb.push(second / first);
            return;
        case '+':
            numb.push(first + second);
            return;
        case '-':
            numb.push(second - first);
            return;
        }
        return;
    }
    bool check_if_op(char c)
    {
        if (c == '*' || c == '+' || c == '-' || c == '/' || c == '(' || c == ')')
        {
            return true;
        }
        return false;
    }
    // Checks if user has entered valid expression
    bool check_expression_validity()
    {
        return true;
    }
    // checks if bracket matching has occoured
    bool match_brackets(char e)
    {
        if (e == ')' && operators.top() == '(')
        {
            return true;
        }
        return false;
    }
    // Function complete_expression evaluates the entire expression
    int complete_expression()
    {
        int len = expression.length();
        for (int i = 0; i < len; i += 1)
        {
            if (check_if_op(expression[i]))
            {
                if (operators.empty())
                {
                    operators.push(expression[i]);
                    continue;
                }
                if (precedence(expression[i]) <= precedence(operators.top()))
                {
                    if (match_brackets(expression[i]) == true)
                    {
                        operators.pop();
                        continue;
                    }
                    evaluate();
                    operators.push(expression[i]);
                    continue;
                }
                else
                {
                    operators.push(expression[i]);
                    continue;
                }
            }
            int k = i;
            while (k < len && !check_if_op(expression[k]))
            {
                k = k + 1;
            }
            numb.push(stoi(expression.substr(i, k - i)));
            i = k - 1;
        }
        evaluate();
        int ans = numb.top();
        numb.pop();
        return ans;
    }
};
int main()
{
    Infix_eval IE;
    int command;
    /*cout << "Enter 1 to enter and 0 to exit dont enter any oter command" << endl;
    cin >> command;
    cout << endl;*/
    command = 1;
    while (command == 1)
    {
        IE.get_input();
        int value = IE.complete_expression();
        cout << value << endl;
        cout << "Enter 1 to enter and 0 to exit dont enter any oter command" << endl;
        cin >> command;
    }
}