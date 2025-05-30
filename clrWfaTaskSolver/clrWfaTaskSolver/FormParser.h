#pragma once

#include <vector>
#include <sstream>
#include <cctype>
#include <msclr/marshal_cppstd.h>
#include <cstring>
#include "../../Parser_Recursive/ShiftReduceParser.h"
#include "../../Class/TLexemList.h"
#include "../../Class/TIdentList.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace msclr::interop;
using namespace std;

namespace clrWfaTaskSolver {

    public ref class FormParser : public Form
    {
    public:
        FormParser()
        {
            InitializeComponent();
        }
    protected:
        ~FormParser()
        {
            if (components)
                delete components;
        }
    private:
        TextBox^ textBoxInput;
        Button^ buttonParse;
        TextBox^ textBoxOutput;
        ComboBox^ comboExamples;
        DataGridView^ gridSteps;
        System::ComponentModel::Container^ components;

        void InitializeComponent()
        {
            this->gridSteps = gcnew DataGridView();
            this->comboExamples = gcnew ComboBox();
            this->comboExamples->Location = Point(12, 12);
            this->comboExamples->Size = Drawing::Size(260, 21);
            this->comboExamples->Items->Add(L"id + id * id");
            this->comboExamples->Items->Add(L"( id + id ) * id");
            this->comboExamples->Items->Add(L"id + id - id");
            this->comboExamples->SelectedIndex = 0;
            this->comboExamples->SelectedIndexChanged += gcnew EventHandler(this, &FormParser::comboExamples_SelectedIndexChanged);
            this->Controls->Add(this->comboExamples);
            this->textBoxInput = gcnew TextBox();
            this->textBoxInput->Location = Point(12, 40);
            this->textBoxInput->Size = Drawing::Size(260, 20);
            this->buttonParse = gcnew Button();
            this->buttonParse->Location = Point(12, 66);
            this->buttonParse->Size = Drawing::Size(75, 23);
            this->buttonParse->Text = L"Parse";
            this->buttonParse->Click += gcnew EventHandler(this, &FormParser::buttonParse_Click);
            this->textBoxOutput = gcnew TextBox();
            this->textBoxOutput->Location = Point(12, 95);
            this->textBoxOutput->Size = Drawing::Size(260, 20);
            this->textBoxOutput->ReadOnly = true;
            this->gridSteps->Location = Point(12, 130);
            this->gridSteps->Size = Drawing::Size(500, 200);
            this->gridSteps->Columns->Clear();
            this->gridSteps->Columns->Add(L"State", L"State");
            this->gridSteps->Columns->Add(L"Symbol", L"Symbol");
            this->gridSteps->Columns->Add(L"Action", L"Action");
            this->gridSteps->Columns->Add(L"Stack", L"Stack");
            this->ClientSize = Drawing::Size(520, 350);
            this->Controls->Add(this->textBoxInput);
            this->Controls->Add(this->buttonParse);
            this->Controls->Add(this->textBoxOutput);
            this->Controls->Add(this->gridSteps);
            this->Name = L"FormParser";
            this->Text = L"Shift-Reduce Parser";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void buttonParse_Click(Object^ sender, EventArgs^ e)
        {
            // prepare lexem list
            TLexemList* lexList = new TLexemList();
            TIdentList* identList = new TIdentList();
            std::string input = marshal_as<std::string>(this->textBoxInput->Text);
            std::istringstream iss(input);
            std::string tok;
            while (iss >> tok) {
                TLexem* lex = new TLexem();
                lex->setText(const_cast<char*>(tok.c_str()));
                if (isdigit(tok[0])) lex->setType(2);
                else if (tok == "+" || tok == "-" || tok == "*" || tok == "/") lex->setType(7);
                else if (tok == "(" || tok == ")") lex->setType(3);
                else lex->setType(1);
                lexList->add(lex);
            }
            // run parser with steps
            ShiftReduceParser parser;
            std::vector<ShiftReduceParser::Step> steps;
            char error[256];
            bool ok = parser.parseWithSteps(lexList, identList, error, steps);
            this->gridSteps->Rows->Clear();
            for each (auto& step in steps) {
                array<Object^>^ row = gcnew array<Object^>(4) {
                    Convert::ToString(step.state),
                    gcnew String(step.token.c_str()),
                    gcnew String(step.action.c_str()),
                    gcnew String(step.stack.c_str())
                };
                this->gridSteps->Rows->Add(row);
            }
            // show result
            this->textBoxOutput->Text = ok ? L"Success" : gcnew String(error);
        }

        System::Void comboExamples_SelectedIndexChanged(Object^ sender, EventArgs^ e)
        {
            this->textBoxInput->Text = this->comboExamples->SelectedItem->ToString();
        }
    };
} 