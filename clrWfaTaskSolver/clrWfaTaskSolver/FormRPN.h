#pragma once

#include <vector>
#include <sstream>
#include <cctype>
#include <msclr/marshal_cppstd.h>
#include "../../IR_Tetrads/ReversePolishNotation.h"
#include "../../Class/TLexemList.h"
#include "../../Class/TIdentList.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace msclr::interop;
using namespace std;

namespace clrWfaTaskSolver {

    public ref class FormRPN : public Form
    {
    public:
        FormRPN()
        {
            InitializeComponent();
        }
    protected:
        ~FormRPN()
        {
            if (components)
                delete components;
        }
    private:
        TextBox^ textBoxInput;
        Button^ buttonConvert;
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
            this->comboExamples->Items->Add(L"3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
            this->comboExamples->Items->Add(L"( 1 + 2 ) * ( 3 - 4 )");
            this->comboExamples->SelectedIndex = 0;
            this->comboExamples->SelectedIndexChanged += gcnew EventHandler(this, &FormRPN::comboExamples_SelectedIndexChanged);
            this->Controls->Add(this->comboExamples);
            this->textBoxInput = gcnew TextBox();
            this->textBoxInput->Location = Point(12, 40);
            this->textBoxInput->Size = Drawing::Size(260, 20);
            this->buttonConvert = gcnew Button();
            this->buttonConvert->Location = Point(12, 66);
            this->buttonConvert->Size = Drawing::Size(75, 23);
            this->buttonConvert->Text = L"Convert";
            this->buttonConvert->Click += gcnew EventHandler(this, &FormRPN::buttonConvert_Click);
            this->textBoxOutput = gcnew TextBox();
            this->textBoxOutput->Location = Point(12, 95);
            this->textBoxOutput->Size = Drawing::Size(260, 20);
            this->textBoxOutput->ReadOnly = true;
            this->gridSteps->Location = Point(12, 130);
            this->gridSteps->Size = Drawing::Size(500, 200);
            this->gridSteps->Columns->Add(L"Symbol", L"Symbol");
            this->gridSteps->Columns->Add(L"Operation", L"Operation");
            this->gridSteps->Columns->Add(L"Stack", L"Stack");
            this->gridSteps->Columns->Add(L"Output", L"Output");
            this->ClientSize = Drawing::Size(520, 350);
            this->Controls->Add(this->textBoxInput);
            this->Controls->Add(this->buttonConvert);
            this->Controls->Add(this->textBoxOutput);
            this->Controls->Add(this->gridSteps);
            this->Name = L"FormRPN";
            this->Text = L"Reverse Polish Notation";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void buttonConvert_Click(Object^ sender, EventArgs^ e)
        {
            std::vector<ReversePolishNotation::RPNItem> output;
            TLexemList* lexList = new TLexemList();
            TIdentList* identList = new TIdentList();
            std::string input = marshal_as<std::string>(this->textBoxInput->Text);
            std::istringstream iss(input);
            std::string tok;
            while (iss >> tok) {
                TLexem* lex = new TLexem();
                lex->setText(const_cast<char*>(tok.c_str()));
                lex->setType(isdigit(tok[0]) ? 2 : 1);
                lexList->add(lex);
            }
            ReversePolishNotation rpn;
            std::vector<ReversePolishNotation::StepRecord> steps;
            bool ok = rpn.convertToRPNWithSteps(lexList, identList, output, steps);
            this->gridSteps->Rows->Clear();
            for each (auto& step in steps) {
                array<Object^>^ row = gcnew array<Object^>(4){
                    gcnew String(step.token.c_str()),
                    gcnew String(step.operation.c_str()),
                    gcnew String(step.stack.c_str()),
                    gcnew String(step.output.c_str())
                };
                this->gridSteps->Rows->Add(row);
            }
            if (ok) {
                std::string result = rpn.rpnToString(output);
                this->textBoxOutput->Text = gcnew String(result.c_str());
            } else {
                this->textBoxOutput->Text = L"Error";
            }
        }

        System::Void comboExamples_SelectedIndexChanged(Object^ sender, EventArgs^ e)
        {
            this->textBoxInput->Text = this->comboExamples->SelectedItem->ToString();
        }
    };
} 