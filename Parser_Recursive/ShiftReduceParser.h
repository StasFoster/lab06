#pragma once
#include <vector>
#include <stack>
#include <map>
#include <string>
#include "../Class/TLexemList.h"
#include "../Class/TIdentList.h"

#ifdef ERROR
#undef ERROR
#endif

class ShiftReduceParser 
{
private:
    TLexemList* pLexemList;
    TIdentList* pIdentList;
    std::stack<int> stateStack;
    std::stack<TLexem*> valueStack;
    int currentPosition;
    
    enum Actions { SHIFT, REDUCE, ACCEPT, ERROR };
    enum Tokens { ID, NUM, PLUS, MINUS, MULT, DIV, LPAREN, RPAREN, END };
    enum NonTerminals { EXPR, TERM, FACTOR };
    
    struct Rule {
        NonTerminals lhs;
        std::vector<int> rhs;
    };
    
    std::vector<Rule> rules;
    std::map<std::pair<int, int>, std::pair<Actions, int>> actionTable;
    std::map<std::pair<int, int>, int> gotoTable;
    
    void initializeGrammar();
    void buildParsingTables();
    Tokens getNextToken();
    
public:
    ShiftReduceParser();
    ~ShiftReduceParser();
    
    bool parse(TLexemList* lexemList, TIdentList* identList, char* errorMessage);
    // step record for parser
    struct Step {
        int state;
        std::string token;
        std::string action;
        std::string stack;
        Step(int s, const std::string& t, const std::string& a, const std::string& st)
            : state(s), token(t), action(a), stack(st) {}
    };
    // parse with logging steps
    bool parseWithSteps(TLexemList* lexemList, TIdentList* identList, char* errorMessage, std::vector<Step>& steps);
}; 