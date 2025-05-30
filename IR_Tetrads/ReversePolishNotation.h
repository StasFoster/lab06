#pragma once
#include <vector>
#include <string>
#include <stack>
#include <map>
#include "../Class/TLexemList.h"
#include "../Class/TIdentList.h"

class ReversePolishNotation {
public:
    struct RPNItem {
        enum Type { OPERAND, OPERATOR, RESULT };
        
        Type type;
        std::string value;
        int operandId;
        
        RPNItem(Type t, const std::string& v, int id = -1) : type(t), value(v), operandId(id) {}
    };
    
    ReversePolishNotation();
    ~ReversePolishNotation();
    
    bool convertToRPN(TLexemList* lexemList, TIdentList* identList, std::vector<RPNItem>& output);
    bool evaluateRPN(const std::vector<RPNItem>& rpn, double& result);
    std::string rpnToString(const std::vector<RPNItem>& rpn);
    
    // step-by-step record for RPN conversion
    struct StepRecord {
        std::string token;
        std::string operation;
        std::string stack;
        std::string output;
        StepRecord(const std::string& t, const std::string& op, const std::string& s, const std::string& o)
            : token(t), operation(op), stack(s), output(o) {}
    };
    // convert with logging steps
    bool convertToRPNWithSteps(TLexemList* lexemList, TIdentList* identList, std::vector<RPNItem>& output, std::vector<StepRecord>& steps);

private:
    int getPrecedence(const std::string& op);
    bool isOperator(const std::string& token);
}; 