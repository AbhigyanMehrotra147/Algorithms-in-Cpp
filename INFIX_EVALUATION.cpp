#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
/*
 Function would get the expression from the user
*/
void get_expression();
/*
Checks if expression entered by the user is a valid expression or not
*/
bool check_if_valid_expression();
/*
Function decides how high an operator is in the precedence heirarchy
Assigns highest value to:
Assigns lowest value to:
*/
int precedence(char);
/*
Checks if the character is an operator or not
*/
bool check_if_operator(char);
/*
Checks if the top of the operator stack is '(' and the next character in the expression string is ')'
returns true if yes otherwise returns false
*/
bool check_if_brackets_match(char);
/*
count from index i how many characters are numbers;
later used in evaluate_entire_expression function to push the substring of numbers into the numbers stack;
*/
int length_of_number_sequence(int);
/*
evaluates the first two numbers of the stack according the the type of operator
pops back the result into numbers stack
*/
void evaluate();
/*
Evaluates the entire expression by calling evaluate according to some conditions and precedences
*/
int evaluate_entire_expression();
class Evaluate_Infix
{
    stack<char> operators;
    stack<int> numbers;
    string expression = "";
    int length;

public:
    void get_expression()
    {
        cout << "Enter the expression to be evaluated" << endl;
        getline(cin, expression);
        length = expression.length();
        cout << expression << endl;
    }
    bool check_if_valid_expression()
    {
        return true;
    }
    int precedence(char c)
    {
        switch (c)
        {
        /*case '(':
            return 3;*/
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
    bool check_if_operator(char c)
    {
        if (c == '*' || c == '+' || c == '-' || c == '/' || c == '(' || c == ')')
        {
            return true;
        }
        return false;
    }
    bool check_if_brackets_match(char e)
    {
        if (e == ')' && operators.top() == '(')
        {
            return true;
        }
        return false;
    }
    int length_of_number_sequence(int i)
    {
        int count = 0;
        while (!check_if_operator(expression[i]) && i < length)
        {
            i += 1;
            count += 1;
        }
        return count;
    }
    void evaluate()
    {
        int first = numbers.top();
        numbers.pop();
        int second = numbers.top();
        numbers.pop();
        char c = operators.top();
        operators.pop();
        switch (c)
        {
        case '*':
            numbers.push(first * second);
            return;
        case '/':
            numbers.push(second / first);
            return;
        case '+':
            numbers.push(first + second);
            return;
        case '-':
            numbers.push(second - first);
            return;
        }
        return;
    }
    int evaluate_entire_expression()
    {
        for (int i = 0; i < length; i += 1)
        {
            if (check_if_operator(expression[i]))
            {
                if (!operators.empty())
                {
                    if (expression[i] == '(' || operators.top() == '(')
                    {
                        operators.push(expression[i]);
                        continue;
                    }

                    if (precedence(expression[i]) <= precedence(operators.top()))
                    {
                        evaluate();
                        if (expression[i] == ')')
                        {
                            operators.pop();
                            continue;
                        }
                        operators.push(expression[i]);
                        continue;
                    }
                }
                operators.push(expression[i]);
                continue;
            }
            numbers.push(stoi(expression.substr(i, length_of_number_sequence(i))));
            i = i + length_of_number_sequence(i) - 1;
        }
        while (!operators.empty())
        {
            evaluate();
        }
        int ans = numbers.top();
        numbers.pop();
        return ans;
    }
};
int main()
{
    Evaluate_Infix EI;
    EI.get_expression();
    int evaluation = EI.evaluate_entire_expression();
    cout << evaluation << endl;
    return 0;
}