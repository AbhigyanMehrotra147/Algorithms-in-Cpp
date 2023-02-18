#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
// #include "Rational_Numbers.h"
using namespace std;
template <class Type>
class Evaluate_Infix
{
    stack<char> operators;
    stack<Type> numbers;

public:
    string expression = "";
    int length;
    /*
     Function would get the expression from the user
    */
    // void get_expression();
    /*
    checks if two consecutive operators are there
    returns true if there are
    ignores if an operator and bracket are thee consecutivly
    returns false otherwise
    */
    /*
    Checks if expression entered by the user is a valid expression or not
    */
    // bool check_if_valid_expression();
    /*
    Function decides how high an operator is in the precedence heirarchy
    Assigns highest value to:
    Assigns lowest value to:
    */
    // int precedence(char);
    /*
    Checks if the character is an operator or not
    */
    // bool check_if_operator(char);
    /*
    Checks if the top of the operator stack is '(' and the next character in the expression string is ')'
    returns true if yes otherwise returns false
    */
    // bool check_if_brackets_match(char);
    /*
    function counts from index i how many characters are numbers;
    later used in evaluate_entire_expression function to push the substring of numbers into the numbers stack;
    */
    // int length_of_number_sequence(int);
    /*
    evaluates the first two numbers of the stack according the the type of operator
    pops the top two numbers
    pos the charachter
    pops back the result into numbers stack
    */
    // void evaluate();
    /*
    Evaluates the entire expression by calling evaluate according to some conditions and precedences
    */
    // Type evaluate_entire_expression();

    void get_expression()
    {
        cout << "Enter the expression to be evaluated" << endl;
        // cin.ignore();
        cin >> expression;
        length = expression.length();
        cout << expression << endl;
    }
    bool check_if_operator(char c)
    {
        if (c == '*' || c == '+' || c == '-' || c == '/' || c == '(' || c == ')')
        {
            return true;
        }
        return false;
    }
    bool two_consecutive_operators(char cur, char next)
    {
        if (cur == '+' || cur == '-' || cur == '*' || cur == '/' && next == '(')
        {
            return false;
        }
        if (next == '+' || next == '-' || next == '*' || next == '/' && next == ')')
        {
            return false;
        }
        return true;
    }
    bool check_if_valid_expression()
    {
        for (int i = 0; i < length - 1; i += 1)
        {
            if (!two_consecutive_operators(expression[i], expression[i + 1]))
            {
                continue;
            }
            return false;
        }
        return true;
    }
    int precedence(char c)
    {
        switch (c)
        {
        /*case ')':
            return 3;*/
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        case '(':
            return 0;
        }
        return -1;
    }

    bool check_if_brackets_match(char e)
    {
        if (e == '(' && operators.top() == ')')
        {
            return true;
        }
        return false;
    }
    int length_of_number_sequence(int i)
    {
        string temp = expression;
        int count = 0;
        while (!check_if_operator(temp[i]) && i > -1)
        {
            i -= 1;
            count += 1;
        }
        return count;
    }
    void evaluate()
    {
        Type first = numbers.top();
        numbers.pop();
        Type second = numbers.top();
        numbers.pop();
        char c = operators.top();
        operators.pop();
        switch (c)
        {
        case '*':
            numbers.push(first * second);
            return;
        case '/':
            numbers.push(first / second);
            return;
        case '+':
            numbers.push(first + second);
            return;
        case '-':
            numbers.push(first - second);
            return;
        }
        return;
    }
    Type evaluate_entire_expression()
    {
        if (!check_if_valid_expression())
        {
            for (int i = length - 1; i > -1; i -= 1)
            {
                if (check_if_operator(expression[i]))
                {
                    if (!operators.empty())
                    {
                        if (expression[i] == ')' || operators.top() == ')')
                        {
                            if (expression[i] == '(')
                            {
                                operators.pop();
                                continue;
                            }
                            operators.push(expression[i]);
                            continue;
                        }

                        if (precedence(expression[i]) <= precedence(operators.top()))
                        {
                            evaluate();
                            if (expression[i] == '(')
                            {
                                while (operators.top() != ')')
                                {
                                    evaluate();
                                }
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
                numbers.push(stof(expression.substr(i + 1 - length_of_number_sequence(i), length_of_number_sequence(i))));
                i = i - length_of_number_sequence(i) + 1;
            }
            while (!operators.empty())
            {
                evaluate();
            }
            Type ans = numbers.top();
            numbers.pop();
            return ans;
        }
    }
};
int main()
{
    Evaluate_Infix<float> EI;
    string exp = "";
    /*while (choice == "yes")
    {
        // EI.get_expression();
        int evaluation = EI.evaluate_entire_expression();
        cout << evaluation << endl;
        cout << "enter choice yes for continuing and no for disconinuing" << endl;
        cin >> choice;
    }*/
    cin >> exp;
    EI.expression = exp;
    cout << EI.expression << endl;
    EI.length = EI.expression.length();
    float evaluation = EI.evaluate_entire_expression();
    cout << evaluation << endl;

    return 0;
}