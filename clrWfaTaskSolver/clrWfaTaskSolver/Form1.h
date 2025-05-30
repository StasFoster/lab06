#pragma once
#include <math.h>
#include "..\..\ClassDll\TTask.h"
#include "..\..\Module\SHASmodule.h"
#include "FormRPN.h"
#include "FormParser.h"
namespace clrWfaTaskSolver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	/// <summary>
	///   Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			// embed RPN and Parser into tabs
			FormRPN^ rpnForm = gcnew FormRPN(); rpnForm->TopLevel = false; rpnForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; rpnForm->Dock = DockStyle::Fill;
			this->tabPageRPN->Controls->Add(rpnForm); rpnForm->Show();
			FormParser^ parserForm = gcnew FormParser(); parserForm->TopLevel = false; parserForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; parserForm->Dock = DockStyle::Fill;
			this->tabPageParser->Controls->Add(parserForm); parserForm->Show();
		}

	protected:
		/// <summary>
		///    .
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonTaskSolve;
	protected: 
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBoxY;
	private: System::Windows::Forms::TextBox^  textBoxX;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^ comboExamples;
	private: System::Windows::Forms::TabControl^ tabControl;
	private: System::Windows::Forms::TabPage^ tabPageEuler;
	private: System::Windows::Forms::TabPage^ tabPageRPN;
	private: System::Windows::Forms::TabPage^ tabPageParser;

	private:
		/// <summary>
		///   .
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		///      -  
		///       .
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonTaskSolve = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboExamples = (gcnew System::Windows::Forms::ComboBox());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageEuler = (gcnew System::Windows::Forms::TabPage());
			this->tabPageRPN = (gcnew System::Windows::Forms::TabPage());
			this->tabPageParser = (gcnew System::Windows::Forms::TabPage());
			this->SuspendLayout();
			// 
			// buttonTaskSolve
			// 
			this->buttonTaskSolve->Location = System::Drawing::Point(128, 93);
			this->buttonTaskSolve->Name = L"buttonTaskSolve";
			this->buttonTaskSolve->Size = System::Drawing::Size(127, 34);
			this->buttonTaskSolve->TabIndex = 11;
			this->buttonTaskSolve->Text = L" ";
			this->buttonTaskSolve->UseVisualStyleBackColor = true;
			this->buttonTaskSolve->Click += gcnew System::EventHandler(this, &Form1::buttonTaskSolve_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(96, 150);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Y = ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(96, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 20);
			this->label2->TabIndex = 9;
			this->label2->Text = L"X = ";
			// 
			// textBoxY
			// 
			this->textBoxY->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxY->Location = System::Drawing::Point(143, 150);
			this->textBoxY->Name = L"textBoxY";
			this->textBoxY->ReadOnly = true;
			this->textBoxY->Size = System::Drawing::Size(100, 20);
			this->textBoxY->TabIndex = 8;
			// 
			// textBoxX
			// 
			this->textBoxX->BackColor = System::Drawing::SystemColors::Menu;
			this->textBoxX->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxX->Location = System::Drawing::Point(143, 50);
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->Size = System::Drawing::Size(100, 20);
			this->textBoxX->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(354, 21);
			this->label1->TabIndex = 6;
			this->label1->Text = L"   y = arctg(x)";
			// 
			// comboExamples
			// 
			this->comboExamples->Location = System::Drawing::Point(12, 65);
			this->comboExamples->Size = System::Drawing::Size(127, 21);
			this->comboExamples->Items->Add(L"0.0");
			this->comboExamples->Items->Add(L"0.5");
			this->comboExamples->Items->Add(L"1.0");
			this->comboExamples->Items->Add(L"2.0");
			this->comboExamples->SelectedIndex = 0;
			this->comboExamples->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboExamples_SelectedIndexChanged);
			// 
			// tabControl
			// 
			this->tabControl->Dock = DockStyle::Fill;
			this->tabControl->Controls->Add(this->tabPageEuler);
			this->tabControl->Controls->Add(this->tabPageRPN);
			this->tabControl->Controls->Add(this->tabPageParser);
			this->tabControl->SelectedIndex = 0;
			// 
			// tabPageEuler
			// 
			this->tabPageEuler->Text = L"Euler Solver";
			this->tabPageEuler->UseVisualStyleBackColor = true;
			// move existing Euler controls to tabPageEuler
			this->tabPageEuler->Controls->Add(this->comboExamples);
			this->tabPageEuler->Controls->Add(this->textBoxX);
			this->tabPageEuler->Controls->Add(this->label2);
			this->tabPageEuler->Controls->Add(this->buttonTaskSolve);
			this->tabPageEuler->Controls->Add(this->label3);
			this->tabPageEuler->Controls->Add(this->textBoxY);
			this->tabPageEuler->Controls->Add(this->label1);
			// 
			// tabPageRPN
			// 
			this->tabPageRPN->Text = L"RPN Converter";
			this->tabPageRPN->UseVisualStyleBackColor = true;
			// placeholder for embedded FormRPN
			// 
			// tabPageParser
			// 
			this->tabPageParser->Text = L"Parser";
			this->tabPageParser->UseVisualStyleBackColor = true;
			// placeholder for embedded FormParser
			// 
			// Form1
			// 
			this->ClientSize = System::Drawing::Size(500, 400);
			this->Controls->Clear();
			this->Controls->Add(this->tabControl);
			this->Name = L"Form1";
			this->Text = L"Task Solver";
			this->tabControl->ResumeLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonTaskSolve_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// parse X input using invariant decimal
		int iRet = -1;
		String^ s = textBoxX->Text;
		double x = Convert::ToDouble(s, CultureInfo::InvariantCulture);
		TTask* ptr = new TTask();
		ptr->set_X(x);
		iRet = SHASmodule(ptr);
		if (iRet == 0)
		{
			double y = ptr->get_Y();
			y = floor(y * 1000) / 1000;
			// format output with decimal point
			String^ out = Convert::ToString(y, CultureInfo::InvariantCulture);
			textBoxY->Text = out;
		}
		delete ptr;
		ptr = nullptr;
	}
	System::Void comboExamples_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->textBoxX->Text = this->comboExamples->SelectedItem->ToString();
	}
};
}


