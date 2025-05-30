#include "ReversePolishNotation.h"
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib> // for atof
#include <algorithm>

ReversePolishNotation::ReversePolishNotation() {
}

ReversePolishNotation::~ReversePolishNotation() {
}

bool ReversePolishNotation::isOperator(const std::string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/" || token == "^");
}

int ReversePolishNotation::getPrecedence(const std::string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

bool ReversePolishNotation::convertToRPN(TLexemList* lexemList, TIdentList* identList, std::vector<RPNItem>& output) {
    if (!lexemList) return false;
    output.clear();
    std::stack<std::string> operatorStack;
    
    for (int i = 0; i < lexemList->getCount(); ++i) {
        TLexem* lexem = nullptr;
        lexemList->get(i, &lexem);
        if (!lexem) continue;
        std::string token(lexem->getText());
        
        if (isOperator(token)) {
            // pop ops with higher or equal precedence
            while (!operatorStack.empty() && operatorStack.top() != "(" && getPrecedence(operatorStack.top()) >= getPrecedence(token)) {
                output.push_back(RPNItem(RPNItem::OPERATOR, operatorStack.top()));
                operatorStack.pop();
            }
            operatorStack.push(token);
        } else if (token == "(") {
            operatorStack.push(token);
        } else if (token == ")") {
            // pop until matching '('
            while (!operatorStack.empty() && operatorStack.top() != "(") {
                output.push_back(RPNItem(RPNItem::OPERATOR, operatorStack.top()));
                operatorStack.pop();
            }
            if (!operatorStack.empty()) operatorStack.pop();
        } else {
            // operand (number or variable)
            output.push_back(RPNItem(RPNItem::OPERAND, token, i));
        }
    }

    // pop remaining operators
    while (!operatorStack.empty()) {
        if (operatorStack.top() == "(" || operatorStack.top() == ")") {
            return false; // unbalanced parentheses
        }
        output.push_back(RPNItem(RPNItem::OPERATOR, operatorStack.top()));
        operatorStack.pop();
    }
    return true;
}

bool ReversePolishNotation::evaluateRPN(const std::vector<RPNItem>& rpn, double& result) {
    std::stack<double> valueStack;
    for (size_t i = 0; i < rpn.size(); ++i) {
        const RPNItem& item = rpn[i];
        if (item.type == RPNItem::OPERAND) {
            // convert string to double
            double value = atof(item.value.c_str());
            valueStack.push(value);
        } else if (item.type == RPNItem::OPERATOR) {
            if (valueStack.size() < 2) return false;
            double val2 = valueStack.top(); valueStack.pop();
            double val1 = valueStack.top(); valueStack.pop();
            if (item.value == "+") valueStack.push(val1 + val2);
            else if (item.value == "-") valueStack.push(val1 - val2);
            else if (item.value == "*") valueStack.push(val1 * val2);
            else if (item.value == "/") {
                if (val2 == 0) return false;
                valueStack.push(val1 / val2);
            } else if (item.value == "^") valueStack.push(pow(val1, val2));
        }
    }
    
    if (valueStack.size() != 1) return false;
    result = valueStack.top();
    return true;
}

std::string ReversePolishNotation::rpnToString(const std::vector<RPNItem>& rpn) {
    std::stringstream ss;
    for (size_t i = 0; i < rpn.size(); ++i) {
        const RPNItem& item = rpn[i];
        if (item.type == RPNItem::OPERAND) ss << item.value << ' ';
        else if (item.type == RPNItem::OPERATOR) ss << item.value << ' ';
        else if (item.type == RPNItem::RESULT) ss << "= " << item.value << ' ';
    }
    return ss.str();
}

bool ReversePolishNotation::convertToRPNWithSteps(TLexemList* lexemList, TIdentList* identList, std::vector<RPNItem>& output, std::vector<StepRecord>& steps) {
    if (!lexemList) return false;
    output.clear(); steps.clear();
    std::stack<std::string> opStack;
    auto stackToStr = [](std::stack<std::string> s) -> std::string {
        std::vector<std::string> elems;
        while (!s.empty()) { elems.push_back(s.top()); s.pop(); }
        std::reverse(elems.begin(), elems.end());
        std::string res;
        for (size_t i = 0; i < elems.size(); ++i) {
            if (i) res += ", "; res += elems[i];
        }
        return res;
    };
    auto outputToStr = [&](const std::vector<RPNItem>& out) -> std::string {
        std::string res;
        for (size_t i = 0; i < out.size(); ++i) {
            if (i) res += ", "; res += out[i].value;
        }
        return res;
    };
    for (int i = 0; i < lexemList->getCount(); ++i) {
        TLexem* lexem = nullptr; lexemList->get(i, &lexem);
        if (!lexem) continue;
        std::string token(lexem->getText());
        if (isOperator(token)) {
            // pop higher or equal
            while (!opStack.empty() && opStack.top() != "(" && getPrecedence(opStack.top()) >= getPrecedence(token)) {
                // pop op
                output.push_back(RPNItem(RPNItem::OPERATOR, opStack.top()));
                steps.push_back(StepRecord(token, "достать оператор в выход", stackToStr(opStack), outputToStr(output)));
                opStack.pop();
            }
            opStack.push(token);
            steps.push_back(StepRecord(token, "добавить в стек", stackToStr(opStack), outputToStr(output)));
        } else if (token == "(") {
            opStack.push(token);
            steps.push_back(StepRecord(token, "добавить в стек", stackToStr(opStack), outputToStr(output)));
        } else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(RPNItem(RPNItem::OPERATOR, opStack.top()));
                steps.push_back(StepRecord(token, "достать оператор в выход", stackToStr(opStack), outputToStr(output)));
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();
            steps.push_back(StepRecord(token, "удалить скобки", stackToStr(opStack), outputToStr(output)));
        } else {
            output.push_back(RPNItem(RPNItem::OPERAND, token, i));
            steps.push_back(StepRecord(token, "добавить в выход", stackToStr(opStack), outputToStr(output)));
        }
    }
    // final pop
    while (!opStack.empty()) {
        if (opStack.top() == "(" || opStack.top() == ")") { return false; }
        output.push_back(RPNItem(RPNItem::OPERATOR, opStack.top()));
        steps.push_back(StepRecord(opStack.top(), "достать оператор в выход", stackToStr(opStack), outputToStr(output)));
        opStack.pop();
    }
    return true;
} 