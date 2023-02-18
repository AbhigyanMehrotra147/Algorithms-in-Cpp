#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
#include "Rational_Numbers.h"
using namespace std;
// Constant Rational number to be returned in case of Zero Division error
const Rational zero_div(-99999, 0);
class Evaluate_Infix
{
    // Stack of operators, stores operators in char type
    stack<char> operators;
    // Stack of numbers, stores them in Rational type
    stack<Rational> numbers;

public:
    // The user enters the string;
    string expression = "";
    // length of the string expression
    int length;
    // Default constructor
    Evaluate_Infix() {}
    /*
    if there is division by zero anywhere in the expression then returns true
    */
    bool check_division_by_zero()
    {
        for (int i = 0; i < length - 1; i += 1)
        {
            if (expression[i] == '/' && expression[i + 1] == '0')
            {
                return true;
            }
        }
        return false;
    }
    /*
    Checks if the character is an operator or not
    Returns bool
    */
    bool check_if_operator(char c)
    {
        if (c == '*' || c == '+' || c == '-' || c == '/' || c == '(' || c == ')')
        {
            return true;
        }
        return false;
    }
    /*
    Function decides how high an operator is in the precedence heirarchy
    Assigns highest value to: '*' and '/'
    Assigns lowest value to:  '('
    */
    int precedence(char c)
    {
        switch (c)
        {
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
    /*
    Checks if the top of the operator stack is '(' and the next character in the expression string is ')'
    returns true if yes otherwise returns false
    */
    bool check_if_brackets_match(char e)
    {
        if (e == ')' && operators.top() == '(')
        {
            return true;
        }
        return false;
    }
    /*
    function counts from index i how many characters are numbers;
    later used in evaluate_entire_expression function to push the substring of numbers into the numbers stack;
    */
    int length_of_number_sequence(int i)
    {
        string temp = expression;
        int count = 0;
        while (!check_if_operator(temp[i]) && i < length)
        {
            i += 1;
            count += 1;
        }
        return count;
    }
    /*
    Converts integer type to rational and then pushes into the numbers stack
    */
    void int_to_rational_push(int numerator)
    {
        Rational r(numerator, 1);
        numbers.push(r);
    }
    /*
    evaluates the first two numbers of the stack according the the type of operator
    pops the top two numbers
    pos the charachter
    pops back the result into numbers stack
    */
    void evaluate()
    {
        Rational first = numbers.top();
        numbers.pop();
        Rational second = numbers.top();
        numbers.pop();
        char c = operators.top();
        operators.pop();
        switch (c)
        {
        case '*':
            numbers.push(second * first);
            return;
        case '/':
            if (first.Numerator != 0)
            {
                numbers.push(second / first);
                return;
            }

        case '+':
            numbers.push(second + first);
            return;
        case '-':
            numbers.push(second - first);
            return;
        }
        return;
    }
    /*
    Handles when the top of operators stack = '(' or expression[index] = '('
    */
    void handling_bracket_left_concave(int index)
    {
        operators.push(expression[index]);
    }
    /*
    Handles when the operators[top] == ')'
    pushes expression[index]
    */
    void handling_bracket_right_concave(int index)
    {
        operators.pop();
        while (operators.top() != '(')
        {
            evaluate();
        }
        operators.pop();
        operators.push(expression[index]);
    }
    /*
    Handles when the operators[top] == ')'
    For the end
    */
    void handling_bracket_right_concave()
    {
        operators.pop();
        while (operators.top() != '(')
        {
            evaluate();
        }
        operators.pop();
    }
    /*
    Handles the case when precedence of expression[index] is lesser than or equal to operators[top].
    after evaluating it pushes the expression[index] into the operators stack
    */
    void handling_lower_precednce_of_expression_character(int index)
    {
        int s1 = numbers.size();
        evaluate();
        int s2 = numbers.size();
        if (s2 != s1 - 1)
        {
            return;
        }
        operators.push(expression[index]);
    }
    /*
    Handles the case when precednece of expression[index] is greater than operators[top]
    Just pushes the expression[index] into the operators stack
    */
    void handling_higher_precedence_of_expression_charachter(int index)
    {
        operators.push(expression[index]);
    }
    /*
    Handles the end case when 2 operators may be left after evaluating the entire expression;
    Returns the answer as well
    Clears the stack
    */
    Rational handling_tail_case()
    {
        int ns1;
        int ns2;
        while (!operators.empty())
        {
            ns1 = numbers.size();
            evaluate();
            ns2 = numbers.size();
            if (ns1 != ns2 + 1)
                return zero_div;
        }
        Rational r = numbers.top();
        numbers.pop();
        return r;
    }
    /*
    Handles when encounters integer in expression[index]
    assings new index to index as well
    */
    int handling_integer_assiging_index(int index)
    {
        int length_numb_seq = length_of_number_sequence(index);
        int numerator = stoll(expression.substr(index, length_numb_seq));
        int_to_rational_push(numerator);
        index = index + length_numb_seq - 1;
        return index;
    }
    Rational evaluate_entire_expression()
    {
        for (int i = 0; i < length; i += 1)
        {
            int os1 = operators.size();
            if (expression[i] == ' ')
            {
                continue;
            }
            if (check_if_operator(expression[i]))
            {
                if (operators.empty())
                {
                    operators.push(expression[i]);
                    continue;
                }
                if (operators.top() == ')')
                {
                    handling_bracket_right_concave(i);
                    continue;
                }
                if (operators.top() == '(' || expression[i] == '(')
                {
                    handling_bracket_left_concave(i);
                    continue;
                }
                if (precedence(expression[i]) <= precedence(operators.top()))
                {
                    if (os1 != operators.size())
                        return zero_div;
                    handling_lower_precednce_of_expression_character(i);
                    continue;
                }
                if (precedence(expression[i]) > precedence(operators.top()))
                {
                    handling_higher_precedence_of_expression_charachter(i);
                    continue;
                }
            }
            i = handling_integer_assiging_index(i);
        }
        if (!operators.empty())
        {
            if (operators.top() == ')')
            {
                handling_bracket_right_concave();
            }
        }
        return handling_tail_case();
    }
};
int main()
{

    /*string choice = "yes";
    while (choice == "yes")
    {
        cout << "enter_expression" << endl;
        cin >> EI.expression;
        EI.length = EI.expression.length();
        if (EI.check_division_by_zero() == true)
        {
            cout << "Not defined";
            return 0;
        }
        Rational evaluation = EI.evaluate_entire_expression();
        evaluation.print();
        cout << "enter choice yes for continuing and no for disconinuing" << endl;
        cin >> choice;
    }*/
    string exp = "";
    while (getline(cin, exp))
    {
        Evaluate_Infix EI;
        EI.expression = exp;
        EI.length = EI.expression.length();
        // cout << EI.expression;
        // return 0;
        if (!EI.check_division_by_zero())
        {
            Rational evaluation = EI.evaluate_entire_expression();
            if (evaluation.Numerator == -99999 && evaluation.Denominator == 0)
            {
                cout << "not defined" << endl
                     << endl;
                exp = "";
                continue;
            }
            int answer = evaluation.Numerator / evaluation.Denominator;
            cout << answer << endl;
        }
        else
        {
            cout << "not defined" << endl;
            exp = "";
        }
    }
    return 0;
}
