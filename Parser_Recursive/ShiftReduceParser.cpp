#include "ShiftReduceParser.h"
#include <sstream>
#include <iostream>
#include <utility>
#include <algorithm>

ShiftReduceParser::ShiftReduceParser() {
    initializeGrammar();
    buildParsingTables();
}

ShiftReduceParser::~ShiftReduceParser() {
}

void ShiftReduceParser::initializeGrammar() {
    rules.clear();
    
    // rule 1: EXPR -> EXPR PLUS TERM
    {
        Rule r1;
        r1.lhs = EXPR;
        r1.rhs.clear();
        r1.rhs.push_back(EXPR);
        r1.rhs.push_back(PLUS);
        r1.rhs.push_back(TERM);
        rules.push_back(r1);
    }
    // rule 2: EXPR -> EXPR MINUS TERM
    {
        Rule r2;
        r2.lhs = EXPR;
        r2.rhs.clear();
        r2.rhs.push_back(EXPR);
        r2.rhs.push_back(MINUS);
        r2.rhs.push_back(TERM);
        rules.push_back(r2);
    }
    // rule 3: EXPR -> TERM
    {
        Rule r3;
        r3.lhs = EXPR;
        r3.rhs.clear();
        r3.rhs.push_back(TERM);
        rules.push_back(r3);
    }
    // rule 4: TERM -> TERM MULT FACTOR
    {
        Rule r4;
        r4.lhs = TERM;
        r4.rhs.clear();
        r4.rhs.push_back(TERM);
        r4.rhs.push_back(MULT);
        r4.rhs.push_back(FACTOR);
        rules.push_back(r4);
    }
    // rule 5: TERM -> TERM DIV FACTOR
    {
        Rule r5;
        r5.lhs = TERM;
        r5.rhs.clear();
        r5.rhs.push_back(TERM);
        r5.rhs.push_back(DIV);
        r5.rhs.push_back(FACTOR);
        rules.push_back(r5);
    }
    // rule 6: TERM -> FACTOR
    {
        Rule r6;
        r6.lhs = TERM;
        r6.rhs.clear();
        r6.rhs.push_back(FACTOR);
        rules.push_back(r6);
    }
    // rule 7: FACTOR -> ID
    {
        Rule r7;
        r7.lhs = FACTOR;
        r7.rhs.clear();
        r7.rhs.push_back(ID);
        rules.push_back(r7);
    }
    // rule 8: FACTOR -> NUM
    {
        Rule r8;
        r8.lhs = FACTOR;
        r8.rhs.clear();
        r8.rhs.push_back(NUM);
        rules.push_back(r8);
    }
    // rule 9: FACTOR -> LPAREN EXPR RPAREN
    {
        Rule r9;
        r9.lhs = FACTOR;
        r9.rhs.clear();
        r9.rhs.push_back(LPAREN);
        r9.rhs.push_back(EXPR);
        r9.rhs.push_back(RPAREN);
        rules.push_back(r9);
    }
}

void ShiftReduceParser::buildParsingTables() {
    actionTable.clear();
    gotoTable.clear();
    
    // shift actions
    actionTable[std::make_pair(0, ID)]    = std::make_pair(SHIFT, 5);
    actionTable[std::make_pair(0, NUM)]   = std::make_pair(SHIFT, 6);
    actionTable[std::make_pair(0, LPAREN)] = std::make_pair(SHIFT, 4);
    
    actionTable[std::make_pair(1, PLUS)]  = std::make_pair(SHIFT, 7);
    actionTable[std::make_pair(1, MINUS)] = std::make_pair(SHIFT, 8);
    actionTable[std::make_pair(1, END)]   = std::make_pair(ACCEPT, 0);
    
    actionTable[std::make_pair(2, PLUS)]   = std::make_pair(REDUCE, 3);
    actionTable[std::make_pair(2, MINUS)]  = std::make_pair(REDUCE, 3);
    actionTable[std::make_pair(2, MULT)]   = std::make_pair(SHIFT, 9);
    actionTable[std::make_pair(2, DIV)]    = std::make_pair(SHIFT, 10);
    actionTable[std::make_pair(2, RPAREN)] = std::make_pair(REDUCE, 3);
    actionTable[std::make_pair(2, END)]    = std::make_pair(REDUCE, 3);
    
    actionTable[std::make_pair(3, PLUS)]   = std::make_pair(REDUCE, 6);
    actionTable[std::make_pair(3, MINUS)]  = std::make_pair(REDUCE, 6);
    actionTable[std::make_pair(3, MULT)]   = std::make_pair(REDUCE, 6);
    actionTable[std::make_pair(3, DIV)]    = std::make_pair(REDUCE, 6);
    actionTable[std::make_pair(3, RPAREN)] = std::make_pair(REDUCE, 6);
    actionTable[std::make_pair(3, END)]    = std::make_pair(REDUCE, 6);
    
    actionTable[std::make_pair(4, ID)]    = std::make_pair(SHIFT, 5);
    actionTable[std::make_pair(4, NUM)]   = std::make_pair(SHIFT, 6);
    actionTable[std::make_pair(4, LPAREN)] = std::make_pair(SHIFT, 4);
    
    actionTable[std::make_pair(5, PLUS)]   = std::make_pair(REDUCE, 7);
    actionTable[std::make_pair(5, MINUS)]  = std::make_pair(REDUCE, 7);
    actionTable[std::make_pair(5, MULT)]   = std::make_pair(REDUCE, 7);
    actionTable[std::make_pair(5, DIV)]    = std::make_pair(REDUCE, 7);
    actionTable[std::make_pair(5, RPAREN)] = std::make_pair(REDUCE, 7);
    actionTable[std::make_pair(5, END)]    = std::make_pair(REDUCE, 7);
    
    actionTable[std::make_pair(6, PLUS)]   = std::make_pair(REDUCE, 8);
    actionTable[std::make_pair(6, MINUS)]  = std::make_pair(REDUCE, 8);
    actionTable[std::make_pair(6, MULT)]   = std::make_pair(REDUCE, 8);
    actionTable[std::make_pair(6, DIV)]    = std::make_pair(REDUCE, 8);
    actionTable[std::make_pair(6, RPAREN)] = std::make_pair(REDUCE, 8);
    actionTable[std::make_pair(6, END)]    = std::make_pair(REDUCE, 8);
    
    actionTable[std::make_pair(7, ID)]    = std::make_pair(SHIFT, 5);
    actionTable[std::make_pair(7, NUM)]   = std::make_pair(SHIFT, 6);
    actionTable[std::make_pair(7, LPAREN)] = std::make_pair(SHIFT, 4);
    
    actionTable[std::make_pair(8, ID)]    = std::make_pair(SHIFT, 5);
    actionTable[std::make_pair(8, NUM)]   = std::make_pair(SHIFT, 6);
    actionTable[std::make_pair(8, LPAREN)] = std::make_pair(SHIFT, 4);
    
    actionTable[std::make_pair(9, ID)]    = std::make_pair(SHIFT, 5);
    actionTable[std::make_pair(9, NUM)]   = std::make_pair(SHIFT, 6);
    actionTable[std::make_pair(9, LPAREN)] = std::make_pair(SHIFT, 4);
    
    actionTable[std::make_pair(10, ID)]   = std::make_pair(SHIFT, 5);
    actionTable[std::make_pair(10, NUM)]  = std::make_pair(SHIFT, 6);
    actionTable[std::make_pair(10, LPAREN)] = std::make_pair(SHIFT, 4);
    
    actionTable[std::make_pair(11, PLUS)]  = std::make_pair(SHIFT, 7);
    actionTable[std::make_pair(11, MINUS)] = std::make_pair(SHIFT, 8);
    actionTable[std::make_pair(11, RPAREN)] = std::make_pair(SHIFT, 15);
    
    actionTable[std::make_pair(12, PLUS)]  = std::make_pair(REDUCE, 1);
    actionTable[std::make_pair(12, MINUS)] = std::make_pair(REDUCE, 1);
    actionTable[std::make_pair(12, RPAREN)] = std::make_pair(REDUCE, 1);
    actionTable[std::make_pair(12, END)]   = std::make_pair(REDUCE, 1);
    actionTable[std::make_pair(12, MULT)] = std::make_pair(SHIFT, 9);
    actionTable[std::make_pair(12, DIV)]  = std::make_pair(SHIFT, 10);
    
    actionTable[std::make_pair(13, PLUS)]  = std::make_pair(REDUCE, 2);
    actionTable[std::make_pair(13, MINUS)] = std::make_pair(REDUCE, 2);
    actionTable[std::make_pair(13, RPAREN)] = std::make_pair(REDUCE, 2);
    actionTable[std::make_pair(13, END)]   = std::make_pair(REDUCE, 2);
    actionTable[std::make_pair(13, MULT)] = std::make_pair(SHIFT, 9);
    actionTable[std::make_pair(13, DIV)]  = std::make_pair(SHIFT, 10);
    
    actionTable[std::make_pair(14, PLUS)]  = std::make_pair(REDUCE, 4);
    actionTable[std::make_pair(14, MINUS)] = std::make_pair(REDUCE, 4);
    actionTable[std::make_pair(14, MULT)]  = std::make_pair(REDUCE, 4);
    actionTable[std::make_pair(14, DIV)]   = std::make_pair(REDUCE, 4);
    actionTable[std::make_pair(14, RPAREN)] = std::make_pair(REDUCE, 4);
    actionTable[std::make_pair(14, END)]   = std::make_pair(REDUCE, 4);
    
    actionTable[std::make_pair(15, PLUS)]  = std::make_pair(REDUCE, 9);
    actionTable[std::make_pair(15, MINUS)] = std::make_pair(REDUCE, 9);
    actionTable[std::make_pair(15, MULT)]  = std::make_pair(REDUCE, 9);
    actionTable[std::make_pair(15, DIV)]   = std::make_pair(REDUCE, 9);
    actionTable[std::make_pair(15, RPAREN)] = std::make_pair(REDUCE, 9);
    actionTable[std::make_pair(15, END)]   = std::make_pair(REDUCE, 9);
    
    // goto table
    gotoTable[std::make_pair(0, EXPR)]   = 1;
    gotoTable[std::make_pair(0, TERM)]   = 2;
    gotoTable[std::make_pair(0, FACTOR)] = 3;
    
    gotoTable[std::make_pair(4, EXPR)]   = 11;
    gotoTable[std::make_pair(4, TERM)]   = 2;
    gotoTable[std::make_pair(4, FACTOR)] = 3;
    
    gotoTable[std::make_pair(7, TERM)]   = 12;
    gotoTable[std::make_pair(7, FACTOR)] = 3;
    
    gotoTable[std::make_pair(8, TERM)]   = 13;
    gotoTable[std::make_pair(8, FACTOR)] = 3;
    
    gotoTable[std::make_pair(9, FACTOR)] = 14;
    gotoTable[std::make_pair(10, FACTOR)] = 16;
}

ShiftReduceParser::Tokens ShiftReduceParser::getNextToken() {
    if (currentPosition >= pLexemList->getCount()) {
        return END;
    }
    
    TLexem* lexem = nullptr;
    pLexemList->get(currentPosition, &lexem);
    currentPosition++;
    
    if (!lexem) return END;
    
    int lexType = lexem->getType();
    
    switch (lexType) {
        case 1: return ID;
        case 2: return NUM;
        case 7: // �������������� ���������
            if (strcmp(lexem->getText(), "+") == 0) return PLUS;
            if (strcmp(lexem->getText(), "-") == 0) return MINUS;
            if (strcmp(lexem->getText(), "*") == 0) return MULT;
            if (strcmp(lexem->getText(), "/") == 0) return DIV;
            return static_cast<Tokens>(Actions::ERROR);
        case 3: // ������
            if (strcmp(lexem->getText(), "(") == 0) return LPAREN;
            if (strcmp(lexem->getText(), ")") == 0) return RPAREN;
            return static_cast<Tokens>(Actions::ERROR);
        default:
            return static_cast<Tokens>(Actions::ERROR);
    }
}

bool ShiftReduceParser::parse(TLexemList* lexemList, TIdentList* identList, char* errorMessage) {
    pLexemList = lexemList;
    pIdentList = identList;
    currentPosition = 0;
    
    stateStack = std::stack<int>();
    valueStack = std::stack<TLexem*>();
    
    stateStack.push(0);
    
    Tokens token = getNextToken();
    bool success = true;
    
    while (success) {
        int state = stateStack.top();
        
        auto actionIt = actionTable.find(std::make_pair(state, token));
        if (actionIt == actionTable.end()) {
            // map token code to name
            static const char* tokenNames[] = { "id", "num", "+", "-", "*", "/", "(", ")", "end" };
            int t = static_cast<int>(token);
            const char* name = (t >= 0 && t < 9) ? tokenNames[t] : "<unknown>";
            std::stringstream ss;
            ss << "�������������� ������ � ��������� " << state << " ��� ������ '" << name << "'";
            strcpy(errorMessage, ss.str().c_str());
            return false;
        }
        
        auto action = actionIt->second;
        
        switch (action.first) {
            case SHIFT: {
                stateStack.push(action.second);
                TLexem* lexem = nullptr;
                pLexemList->get(currentPosition - 1, &lexem);
                valueStack.push(lexem);
                token = getNextToken();
                break;
            }
                
            case REDUCE: {
                Rule& rule = rules[action.second - 1];
                
                for (size_t i = 0; i < rule.rhs.size(); ++i) {
                    if (!stateStack.empty()) stateStack.pop();
                    if (!valueStack.empty()) valueStack.pop();
                }
                
                if (stateStack.empty()) {
                    std::ostringstream msg; msg << "������: ������ ���� ��������� ����� �������";
                    strcpy(errorMessage, msg.str().c_str());
                    return false;
                }
                
                int top = stateStack.top();
                auto gotoIt = gotoTable.find(std::make_pair(top, rule.lhs));
                
                if (gotoIt == gotoTable.end()) {
                    std::stringstream ss;
                    ss << "������ �������� � ��������� " << top;
                    strcpy(errorMessage, ss.str().c_str());
                    return false;
                }
                
                stateStack.push(gotoIt->second);
                valueStack.push((TLexem*)0); // simplified version
                break;
            }
                
            case ACCEPT:
                return true;
                
            case ERROR:
                std::stringstream ss;
                ss << "����������� ������ � ��������� " << state;
                strcpy(errorMessage, ss.str().c_str());
                return false;
        }
    }
    
    return false;
}

// parse with logging steps
bool ShiftReduceParser::parseWithSteps(TLexemList* lexemList, TIdentList* identList, char* errorMessage, std::vector<Step>& steps) {
    // initialize parser state
    pLexemList = lexemList;
    pIdentList = identList;
    currentPosition = 0;
    stateStack = std::stack<int>();
    valueStack = std::stack<TLexem*>();
    stateStack.push(0);
    // helper to stringify state stack
    auto stackToStr = [](std::stack<int> s) -> std::string {
        std::vector<int> elems;
        while (!s.empty()) { elems.push_back(s.top()); s.pop(); }
        std::reverse(elems.begin(), elems.end());
        std::ostringstream oss;
        for (size_t i = 0; i < elems.size(); ++i) {
            if (i) oss << ", "; oss << elems[i];
        }
        return oss.str();
    };
    // clear previous steps
    steps.clear();
    // initial record
    steps.push_back(Step(stateStack.top(), "", "�������������", stackToStr(stateStack)));
    // token mapping
    static const char* tokenNames[] = { "id", "�����", "+", "-", "*", "/", "(", ")", "�����" };
    // start parsing
    Tokens token = getNextToken();
    while (true) {
        if (stateStack.empty()) {
            std::ostringstream msg; msg << "������: ������ ���� ���������";
            strcpy(errorMessage, msg.str().c_str());
            steps.push_back(Step(0, "?", "������", "������ ����"));
            return false;
        }
        int state = stateStack.top();
        const char* tname = (token >= ID && token <= END) ? tokenNames[token] : "<unknown>";
        auto actionIt = actionTable.find(std::make_pair(state, token));
        if (actionIt == actionTable.end()) {
            std::ostringstream msg; msg << "�������������� ������ � ��������� " << state << " ��� ������ '" << tname << "'";
            strcpy(errorMessage, msg.str().c_str());
            steps.push_back(Step(state, tname, "������", stackToStr(stateStack)));
            return false;
        }
        auto action = actionIt->second;
        if (action.first == SHIFT) {
            // log shift with state
            {
                std::ostringstream op; op << "����� " << action.second;
                steps.push_back(Step(state, tname, op.str(), stackToStr(stateStack)));
            }
            stateStack.push(action.second);
            TLexem* lx = nullptr; pLexemList->get(currentPosition - 1, &lx);
            valueStack.push(lx);
            token = getNextToken();
        } else if (action.first == REDUCE) {
            // log reduce with rule number
            {
                std::ostringstream op; op << "������� " << action.second;
                steps.push_back(Step(state, tname, op.str(), stackToStr(stateStack)));
            }
            Rule& rule = rules[action.second - 1];
            for (size_t i = 0; i < rule.rhs.size(); ++i) { 
                if (!stateStack.empty()) stateStack.pop(); 
                if (!valueStack.empty()) valueStack.pop(); 
            }
            if (stateStack.empty()) {
                std::ostringstream msg; msg << "������: ������ ���� ��������� ����� �������";
                strcpy(errorMessage, msg.str().c_str());
                steps.push_back(Step(0, tname, "������", "������ ����"));
                return false;
            }
            int top = stateStack.top();
            auto gtIt = gotoTable.find(std::make_pair(top, rule.lhs));
            if (gtIt == gotoTable.end()) {
                std::ostringstream msg; msg << "������ �������� � ��������� " << top;
                strcpy(errorMessage, msg.str().c_str());
                steps.push_back(Step(top, tname, "������", stackToStr(stateStack)));
                return false;
            }
            stateStack.push(gtIt->second);
            // log goto transition
            {
                std::ostringstream op; op << "������� " << gtIt->second;
                steps.push_back(Step(top, tname, op.str(), stackToStr(stateStack)));
            }
        } else if (action.first == ACCEPT) {
            steps.push_back(Step(state, tname, "�������", stackToStr(stateStack)));
            return true;
        } else { // ERROR action
            std::ostringstream msg; msg << "������ � ��������� " << state;
            strcpy(errorMessage, msg.str().c_str());
            steps.push_back(Step(state, tname, "������", stackToStr(stateStack)));
            return false;
        }
    }
} 