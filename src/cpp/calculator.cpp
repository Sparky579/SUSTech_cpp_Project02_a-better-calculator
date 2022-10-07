# include "../headfile/calculator.hpp"
# include "../headfile/constant.hpp"
# include <map>
# include <stack>
# include <string>
# include <vector>
# include <iostream>
char priority[10][10]={ 
        {'>', '>', '<', '<', '<', '>', '>', '<', '<', '>'},  
        {'>', '>', '<', '<', '<', '>', '>', '<', '<', '>'},  
        {'>', '>', '>', '>', '<', '>', '>', '>', '<', '>'},  
        {'>', '>', '>', '>', '<', '>', '>', '>', '<', '>'},  
        {'<', '<', '<', '<', '<', '=', '0', '<', '<', '>'},
        {'>', '>', '>', '>', '0', '>', '>', '>', '>', '>'},  
        {'<', '<', '<', '<', '<', '0', '=', '<', '<', '>'},
        {'>', '>', '>', '>', '<', '>', '>', '>', '<', '>'},
        {'>', '>', '>', '>', '<', '>', '>', '>', '>', '>'},
        {'<', '<', '<', '<', '<', '0', '0', '<', '<', '<'}
	};
calculator::calculator() {
    variableNum = 0;
    variableId.clear();
    variables.clear();
    modify_variables("last", "0");
}
char calculator::Procede(char a,char b){  
    int i = 9, j = 9;  
    switch(a){  
        case '+' : i = 0; break;  
        case '-' : i = 1; break;  
        case '*' : i = 2; break;  
        case '/' : i = 3; break;  
        case '(' : i = 4; break;  
        case ')' : i = 5; break;  
        case '#' : i = 6; break;
        case '%' : i = 7; break;
        case '^' : i = 8; break;
    }  
    switch(b){  
        case '+' : j = 0; break;  
        case '-' : j = 1; break;  
        case '*' : j = 2; break;  
        case '/' : j = 3; break;  
        case '(' : j = 4; break;  
        case ')' : j = 5; break;  
        case '#' : j = 6; break;
        case '%' : j = 7; break;
        case '^' : j = 8; break;
    }  
    return priority[i][j];
}
void calculator::show_variables() {
    for (std::map<std::string, int>::iterator it = variableId.begin(); it != variableId.end(); it++) {
        std::cout << it->first << " : " << variables[it->second].to_string() << std::endl;
    }
}
BigNumber calculator::getval(std::string val_str) {
    bool negative = false;
    if (val_str[0] == '-') {
        negative = true;
    }
    if (val_str[0] == '-' || val_str[0] == '+') {
        val_str = val_str.substr(1);
    }
    BigNumber resval;
    if (variableId.count(val_str) != 0) {
        resval = variables[variableId[val_str]];
    } else {
        resval = val_str;
    }
    if (negative) resval *= -1;
    return resval;
}
char calculator::getFunctionId(std::string name) {
    if (name == "sqrt") return 'a';
    if (name == "trunc") return 'b';
    if (name == "ceil") return 'c';
    if (name == "floor") return 'd';
    if (name == "exp") return 'e';
    if (name == "ln") return 'f';
    if (name == "fac") return 'g';
    if (name == "sin") return 'h';
    if (name == "cos") return 'i';
    if (name == "tan") return 'j';
    if (name == "arctan") return 'k';
    if (name == "arccot") return 'l';
    if (name == "arcsin") return 'm';
    if (name == "arccos") return 'n';
    return 0;
}
bool calculator::isoperator(char ch) {
    return (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == ')' || ch == '#' || ch == '^');
}
BigNumber calculator::do_operation(BigNumber num1, BigNumber num2, char op) {
    if (op == '+') return num1 + num2;
    else if (op == '-') return num1 - num2;
    else if (op == '*') return num1 * num2;
    else if (op == '/') return num1 / num2;
    else if (op == '%') return num1 % num2;
    else return num1 ^ num2;
}
BigNumber calculator::do_function(BigNumber num, char op) {
    if (op == 'a') return sqrt(num);
    if (op == 'b') return trunc(num);
    if (op == 'c') return ceil(num);
    if (op == 'd') return floor(num);
    if (op == 'e') return exp(num);
    if (op == 'f') return ln(num);
    if (op == 'g') return fac(num);
    if (op == 'h') return sin(num);
    if (op == 'i') return cos(num);
    if (op == 'j') return tan(num);
    if (op == 'k') return arctan(num);
    if (op == 'l') return arccot(num);
    if (op == 'm') return arcsin(num);
    if (op == 'n') return arccos(num);
    return num;
}
BigNumber calculator::calculate (std::string expression) {
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '[' || expression[i] == '{' ) {
            expression[i] = '(';
        }
        if (expression[i] == ']' || expression[i] == '}' ) {
            expression[i] = ')';
        }
    }
    std::stack<char> stack_ch;
    std::stack<BigNumber> stack_num;
    std::string nowNum = "";
    stack_ch.push('#');
    if (expression[0] == '-' || expression[0] == '+') {
        expression = "0" + expression;
    }
    expression += '#';
    int k = 1; char c = expression[0];
    while (c != '#' || stack_ch.top() != '#') {
        std::string newNum = "";
        if (!isoperator(c) || (c == '-' && expression[k - 2] == 'e') || (c == '-' && expression[k - 2] == '(') || (c == '+' && expression[k - 2] == '(')) {
            while (!isoperator(c) || (c == '-' && expression[k - 2] == 'e') || (c == '-' && expression[k - 2] == '(') || (c == '+' && expression[k - 2] == '(')) {
                newNum += c;
                c = expression[k++];
            }
            char functionId = getFunctionId(newNum);
            if (functionId) {
                stack_ch.push(functionId);
            } else {
                stack_num.push(getval(newNum));
            }
        } else {
            switch(Procede(stack_ch.top(), c)) {
                case '<' :
                    stack_ch.push(c);
                    c = expression[k++];
                    break;
                case '=' :
                    stack_ch.pop();
                    if (stack_ch.size() && !isoperator(stack_ch.top())) {
                        BigNumber x = stack_num.top(); stack_num.pop();
                        stack_num.push(do_function(x, stack_ch.top()));
                        stack_ch.pop();
                    }
                    c = expression[k++];
                    break;
                case '>' :
                    char op = stack_ch.top(); stack_ch.pop();
                    BigNumber x = stack_num.top(); stack_num.pop();
                    BigNumber y = stack_num.top(); stack_num.pop();
                    stack_num.push(do_operation(y, x, op));
                    break;
            }
        }
    }
    return stack_num.top();
}
void calculator::modify_variables(std::string varName, std::string expression) {
    if (varName == "scale") {
        scale = 0;
        for (int i = 0; i < expression.length(); i++) 
            scale = scale * 10 + expression[i] - '0';
        return;
    }
    BigNumber varval = calculate(expression);
    if (variableId.count(varName) == 0) {
        variableId[varName] = variableNum++;
        variables.push_back(varval);
    } else {
        variables[variableId[varName]] = varval;
    }
}
void calculator::call(std::string statement) {
    std::string no_blank_statement = "";
    for (int i = 0; i < statement.length(); i++) 
        if (statement[i] != ' ') {
            no_blank_statement += statement[i];
        }
    statement = no_blank_statement;
    int posEqual = -1;
    for (int i = 0; i < statement.length(); i++)
        if (statement[i] == '=') {
            posEqual = i; break;
        }
    if (posEqual == -1) {
        modify_variables("last", statement);
        std::cout << getval("last").to_string() << std::endl;
    } else {
        std::string varName = statement.substr(0, posEqual);
        std::string expression = statement.substr(posEqual + 1);
        modify_variables(varName, expression);
    }
}