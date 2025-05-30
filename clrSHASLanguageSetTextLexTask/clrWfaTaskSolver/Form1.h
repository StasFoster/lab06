#pragma once
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include "..\..\Class\TLexem.h"
#include "..\..\Class\TIdent.h"
#include "..\..\Class\TLexemList.h"
#include "..\..\Class\TIdentList.h"
#include "..\..\Class\kaLex.h"
#include <cmath>
#include <sstream>
#include <Windows.h>
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h> // для преобразования System::String в std::string
#include <cliext/vector> // для работы с dataGridView
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;
using namespace System::Diagnostics;
using namespace System::Threading;
#include "..\..\Language\SHASProcess.h"
namespace clrWfaTaskSolver {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private: Stopwatch^ stopwatch;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавить код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControlOsnovnoy;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPageVkhodnye;
	private: System::Windows::Forms::Label^  labelFormula6;
	private: System::Windows::Forms::Label^  labelFormula5;
	private: System::Windows::Forms::Label^  labelFormula4;
	private: System::Windows::Forms::Label^  labelFormula3;
	private: System::Windows::Forms::Label^  labelFormula2;
	private: System::Windows::Forms::Label^  labelFormula1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownB;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownA;
	private: System::Windows::Forms::TabPage^  tabPageIskhodnyy;
	private: System::Windows::Forms::TextBox^  textBoxIskhodnyy;
	private: System::Windows::Forms::TabPage^  tabPageRezultat;
	private: System::Windows::Forms::TextBox^  textBoxRezultat;
	private: System::Windows::Forms::GroupBox^  groupBoxUpravlenie;
	private: System::Windows::Forms::Label^  labelMsMain;
	private: System::Windows::Forms::Button^  knopkaVychislit;
	private: System::Windows::Forms::TextBox^  textBoxVremyaGlavnyy;
	private: System::Windows::Forms::TextBox^  textBoxVremyaDrugoy;
	private: System::Windows::Forms::Button^  knopkaGlavnyy;
	private: System::Windows::Forms::Label^  labelMsOther;
	private: System::Windows::Forms::CheckBox^  checkBoxRuchnoy;
	private: System::Windows::Forms::TabPage^  tabPageLeksicheskiy;
	private: System::Windows::Forms::TabControl^  tabControlLeksicheskiy;
	private: System::Windows::Forms::TabPage^  tabPageLeksemy;
	private: System::Windows::Forms::DataGridView^  dataGridViewLeksemy;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnLeksema;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnTip;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnZnach;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnVeshZnach;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnStroka;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnPozStr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnPozObsh;
	private: System::Windows::Forms::TabPage^  tabPageIdent;
	private: System::Windows::Forms::DataGridView^  dataGridViewIdent;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnIdentif;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnIdentTip;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnIdentZnach;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnIdentVeshZnach;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnIdentStroka;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnIdentPozStr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnIdentPozObsh;
	private: System::Windows::Forms::Label^  labelOshibka5;
	private: System::Windows::Forms::Label^  labelOshibka4;
	private: System::Windows::Forms::Label^  labelOshibka3;
	private: System::Windows::Forms::Label^  labelOshibka2;
	private: System::Windows::Forms::Label^  labelOshibka1;
	private: System::Windows::Forms::Button^  knopkaLeksAnaliz;
	private: System::Windows::Forms::Button^  knopkaIskhodnyy;

	protected: 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->tabControlOsnovnoy = (gcnew System::Windows::Forms::TabControl());
			this->tabPageVkhodnye = (gcnew System::Windows::Forms::TabPage());
			this->labelFormula6 = (gcnew System::Windows::Forms::Label());
			this->labelFormula5 = (gcnew System::Windows::Forms::Label());
			this->labelFormula4 = (gcnew System::Windows::Forms::Label());
			this->labelFormula3 = (gcnew System::Windows::Forms::Label());
			this->labelFormula2 = (gcnew System::Windows::Forms::Label());
			this->labelFormula1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownB = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownA = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPageIskhodnyy = (gcnew System::Windows::Forms::TabPage());
			this->textBoxIskhodnyy = (gcnew System::Windows::Forms::TextBox());
			this->tabPageRezultat = (gcnew System::Windows::Forms::TabPage());
			this->textBoxRezultat = (gcnew System::Windows::Forms::TextBox());
			this->tabPageLeksicheskiy = (gcnew System::Windows::Forms::TabPage());
			this->tabControlLeksicheskiy = (gcnew System::Windows::Forms::TabControl());
			this->tabPageLeksemy = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewLeksemy = (gcnew System::Windows::Forms::DataGridView());
			this->columnLeksema = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnTip = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnZnach = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnVeshZnach = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnStroka = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnPozStr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnPozObsh = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPageIdent = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewIdent = (gcnew System::Windows::Forms::DataGridView());
			this->columnIdentif = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnIdentTip = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnIdentZnach = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnIdentVeshZnach = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnIdentStroka = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnIdentPozStr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnIdentPozObsh = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBoxUpravlenie = (gcnew System::Windows::Forms::GroupBox());
			this->labelMsMain = (gcnew System::Windows::Forms::Label());
			this->knopkaVychislit = (gcnew System::Windows::Forms::Button());
			this->textBoxVremyaGlavnyy = (gcnew System::Windows::Forms::TextBox());
			this->textBoxVremyaDrugoy = (gcnew System::Windows::Forms::TextBox());
			this->knopkaGlavnyy = (gcnew System::Windows::Forms::Button());
			this->labelMsOther = (gcnew System::Windows::Forms::Label());
			this->checkBoxRuchnoy = (gcnew System::Windows::Forms::CheckBox());
			this->labelOshibka5 = (gcnew System::Windows::Forms::Label());
			this->labelOshibka4 = (gcnew System::Windows::Forms::Label());
			this->labelOshibka3 = (gcnew System::Windows::Forms::Label());
			this->labelOshibka2 = (gcnew System::Windows::Forms::Label());
			this->labelOshibka1 = (gcnew System::Windows::Forms::Label());
			this->knopkaLeksAnaliz = (gcnew System::Windows::Forms::Button());
			this->knopkaIskhodnyy = (gcnew System::Windows::Forms::Button());
			this->tabControlOsnovnoy->SuspendLayout();
			this->tabPageVkhodnye->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownA))->BeginInit();
			this->tabPageIskhodnyy->SuspendLayout();
			this->tabPageRezultat->SuspendLayout();
			this->tabPageLeksicheskiy->SuspendLayout();
			this->tabControlLeksicheskiy->SuspendLayout();
			this->tabPageLeksemy->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridViewLeksemy))->BeginInit();
			this->tabPageIdent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridViewIdent))->BeginInit();
			this->groupBoxUpravlenie->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControlOsnovnoy
			// 
			this->tabControlOsnovnoy->Controls->Add(this->tabPageVkhodnye);
			this->tabControlOsnovnoy->Controls->Add(this->tabPageIskhodnyy);
			this->tabControlOsnovnoy->Controls->Add(this->tabPageRezultat);
			this->tabControlOsnovnoy->Controls->Add(this->tabPageLeksicheskiy);
			this->tabControlOsnovnoy->Location = System::Drawing::Point(16, 2);
			this->tabControlOsnovnoy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControlOsnovnoy->Name = L"tabControlOsnovnoy";
			this->tabControlOsnovnoy->SelectedIndex = 0;
			this->tabControlOsnovnoy->Size = System::Drawing::Size(740, 741);
			this->tabControlOsnovnoy->TabIndex = 25;
			// 
			// tabPageVkhodnye
			// 
			this->tabPageVkhodnye->Controls->Add(this->labelFormula6);
			this->tabPageVkhodnye->Controls->Add(this->labelFormula5);
			this->tabPageVkhodnye->Controls->Add(this->labelFormula4);
			this->tabPageVkhodnye->Controls->Add(this->labelFormula3);
			this->tabPageVkhodnye->Controls->Add(this->labelFormula2);
			this->tabPageVkhodnye->Controls->Add(this->labelFormula1);
			this->tabPageVkhodnye->Controls->Add(this->numericUpDownB);
			this->tabPageVkhodnye->Controls->Add(this->numericUpDownA);
			this->tabPageVkhodnye->Location = System::Drawing::Point(4, 25);
			this->tabPageVkhodnye->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPageVkhodnye->Name = L"tabPageVkhodnye";
			this->tabPageVkhodnye->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPageVkhodnye->Size = System::Drawing::Size(732, 712);
			this->tabPageVkhodnye->TabIndex = 0;
			this->tabPageVkhodnye->Text = L"Входные данные";
			this->tabPageVkhodnye->UseVisualStyleBackColor = true;
			// 
			// labelFormula6
			// 
			this->labelFormula6->AutoSize = true;
			this->labelFormula6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelFormula6->Location = System::Drawing::Point(19, 203);
			this->labelFormula6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelFormula6->Name = L"labelFormula6";
			this->labelFormula6->Size = System::Drawing::Size(84, 25);
			this->labelFormula6->TabIndex = 15;
			this->labelFormula6->Text = L"a = a - b";
			// 
			// labelFormula5
			// 
			this->labelFormula5->AutoSize = true;
			this->labelFormula5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelFormula5->Location = System::Drawing::Point(19, 245);
			this->labelFormula5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelFormula5->Name = L"labelFormula5";
			this->labelFormula5->Size = System::Drawing::Size(45, 25);
			this->labelFormula5->TabIndex = 14;
			this->labelFormula5->Text = L"end";
			// 
			// labelFormula4
			// 
			this->labelFormula4->AutoSize = true;
			this->labelFormula4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelFormula4->Location = System::Drawing::Point(11, 159);
			this->labelFormula4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelFormula4->Name = L"labelFormula4";
			this->labelFormula4->Size = System::Drawing::Size(48, 25);
			this->labelFormula4->TabIndex = 12;
			this->labelFormula4->Text = L"else";
			// 
			// labelFormula3
			// 
			this->labelFormula3->AutoSize = true;
			this->labelFormula3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelFormula3->Location = System::Drawing::Point(11, 112);
			this->labelFormula3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelFormula3->Name = L"labelFormula3";
			this->labelFormula3->Size = System::Drawing::Size(89, 25);
			this->labelFormula3->TabIndex = 11;
			this->labelFormula3->Text = L"a = a + b";
			// 
			// labelFormula2
			// 
			this->labelFormula2->AutoSize = true;
			this->labelFormula2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelFormula2->Location = System::Drawing::Point(11, 71);
			this->labelFormula2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelFormula2->Name = L"labelFormula2";
			this->labelFormula2->Size = System::Drawing::Size(60, 25);
			this->labelFormula2->TabIndex = 10;
			this->labelFormula2->Text = L"If a > ";
			// 
			// labelFormula1
			// 
			this->labelFormula1->AutoSize = true;
			this->labelFormula1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelFormula1->Location = System::Drawing::Point(11, 22);
			this->labelFormula1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelFormula1->Name = L"labelFormula1";
			this->labelFormula1->Size = System::Drawing::Size(45, 25);
			this->labelFormula1->TabIndex = 9;
			this->labelFormula1->Text = L"a = ";
			// 
			// numericUpDownB
			// 
			this->numericUpDownB->DecimalPlaces = 2;
			this->numericUpDownB->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->numericUpDownB->Location = System::Drawing::Point(88, 71);
			this->numericUpDownB->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->numericUpDownB->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->numericUpDownB->Name = L"numericUpDownB";
			this->numericUpDownB->Size = System::Drawing::Size(81, 22);
			this->numericUpDownB->TabIndex = 6;
			// 
			// numericUpDownA
			// 
			this->numericUpDownA->DecimalPlaces = 2;
			this->numericUpDownA->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->numericUpDownA->Location = System::Drawing::Point(65, 22);
			this->numericUpDownA->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->numericUpDownA->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->numericUpDownA->Name = L"numericUpDownA";
			this->numericUpDownA->Size = System::Drawing::Size(81, 22);
			this->numericUpDownA->TabIndex = 4;
			// 
			// tabPageIskhodnyy
			// 
			this->tabPageIskhodnyy->Controls->Add(this->textBoxIskhodnyy);
			this->tabPageIskhodnyy->Location = System::Drawing::Point(4, 25);
			this->tabPageIskhodnyy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPageIskhodnyy->Name = L"tabPageIskhodnyy";
			this->tabPageIskhodnyy->Size = System::Drawing::Size(732, 712);
			this->tabPageIskhodnyy->TabIndex = 2;
			this->tabPageIskhodnyy->Text = L"Исходный текст";
			this->tabPageIskhodnyy->UseVisualStyleBackColor = true;
			// 
			// textBoxIskhodnyy
			// 
			this->textBoxIskhodnyy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxIskhodnyy->Location = System::Drawing::Point(8, 9);
			this->textBoxIskhodnyy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxIskhodnyy->Multiline = true;
			this->textBoxIskhodnyy->Name = L"textBoxIskhodnyy";
			this->textBoxIskhodnyy->Size = System::Drawing::Size(716, 696);
			this->textBoxIskhodnyy->TabIndex = 1;
			// 
			// tabPageRezultat
			// 
			this->tabPageRezultat->Controls->Add(this->textBoxRezultat);
			this->tabPageRezultat->Location = System::Drawing::Point(4, 25);
			this->tabPageRezultat->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPageRezultat->Name = L"tabPageRezultat";
			this->tabPageRezultat->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPageRezultat->Size = System::Drawing::Size(732, 712);
			this->tabPageRezultat->TabIndex = 1;
			this->tabPageRezultat->Text = L"Результат";
			this->tabPageRezultat->UseVisualStyleBackColor = true;
			// 
			// textBoxRezultat
			// 
			this->textBoxRezultat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxRezultat->Location = System::Drawing::Point(8, 7);
			this->textBoxRezultat->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxRezultat->Multiline = true;
			this->textBoxRezultat->Name = L"textBoxRezultat";
			this->textBoxRezultat->ReadOnly = true;
			this->textBoxRezultat->Size = System::Drawing::Size(725, 693);
			this->textBoxRezultat->TabIndex = 0;
			// 
			// tabPageLeksicheskiy
			// 
			this->tabPageLeksicheskiy->Controls->Add(this->tabControlLeksicheskiy);
			this->tabPageLeksicheskiy->Location = System::Drawing::Point(4, 25);
			this->tabPageLeksicheskiy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPageLeksicheskiy->Name = L"tabPageLeksicheskiy";
			this->tabPageLeksicheskiy->Size = System::Drawing::Size(732, 712);
			this->tabPageLeksicheskiy->TabIndex = 3;
			this->tabPageLeksicheskiy->Text = L"Лексический анализ";
			this->tabPageLeksicheskiy->UseVisualStyleBackColor = true;
			// 
			// tabControlLeksicheskiy
			// 
			this->tabControlLeksicheskiy->Controls->Add(this->tabPageLeksemy);
			this->tabControlLeksicheskiy->Controls->Add(this->tabPageIdent);
			this->tabControlLeksicheskiy->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tabControlLeksicheskiy->Location = System::Drawing::Point(0, 3);
			this->tabControlLeksicheskiy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControlLeksicheskiy->Name = L"tabControlLeksicheskiy";
			this->tabControlLeksicheskiy->SelectedIndex = 0;
			this->tabControlLeksicheskiy->Size = System::Drawing::Size(732, 709);
			this->tabControlLeksicheskiy->TabIndex = 5;
			// 
			// tabPageLeksemy
			// 
			this->tabPageLeksemy->Controls->Add(this->dataGridViewLeksemy);
			this->tabPageLeksemy->Location = System::Drawing::Point(4, 25);
			this->tabPageLeksemy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPageLeksemy->Name = L"tabPageLeksemy";
			this->tabPageLeksemy->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPageLeksemy->Size = System::Drawing::Size(724, 680);
			this->tabPageLeksemy->TabIndex = 0;
			this->tabPageLeksemy->Text = L"Лексемы";
			this->tabPageLeksemy->UseVisualStyleBackColor = true;
			// 
			// dataGridViewLeksemy
			// 
			this->dataGridViewLeksemy->AllowUserToAddRows = false;
			this->dataGridViewLeksemy->AllowUserToDeleteRows = false;
			this->dataGridViewLeksemy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewLeksemy->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {this->columnLeksema, 
				this->columnTip, this->columnZnach, this->columnVeshZnach, this->columnStroka, this->columnPozStr, this->columnPozObsh});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewLeksemy->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewLeksemy->Location = System::Drawing::Point(3, 7);
			this->dataGridViewLeksemy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridViewLeksemy->Name = L"dataGridViewLeksemy";
			this->dataGridViewLeksemy->ReadOnly = true;
			this->dataGridViewLeksemy->Size = System::Drawing::Size(729, 670);
			this->dataGridViewLeksemy->TabIndex = 1;
			// 
			// columnLeksema
			// 
			this->columnLeksema->HeaderText = L"Лексема";
			this->columnLeksema->Name = L"columnLeksema";
			this->columnLeksema->ReadOnly = true;
			// 
			// columnTip
			// 
			this->columnTip->HeaderText = L"Тип";
			this->columnTip->Name = L"columnTip";
			this->columnTip->ReadOnly = true;
			this->columnTip->Width = 75;
			// 
			// columnZnach
			// 
			this->columnZnach->HeaderText = L"Значение";
			this->columnZnach->Name = L"columnZnach";
			this->columnZnach->ReadOnly = true;
			// 
			// columnVeshZnach
			// 
			this->columnVeshZnach->HeaderText = L"Вещественное значение";
			this->columnVeshZnach->Name = L"columnVeshZnach";
			this->columnVeshZnach->ReadOnly = true;
			this->columnVeshZnach->Width = 50;
			// 
			// columnStroka
			// 
			this->columnStroka->HeaderText = L"Строка";
			this->columnStroka->Name = L"columnStroka";
			this->columnStroka->ReadOnly = true;
			// 
			// columnPozStr
			// 
			this->columnPozStr->HeaderText = L"Позиция в строке";
			this->columnPozStr->Name = L"columnPozStr";
			this->columnPozStr->ReadOnly = true;
			this->columnPozStr->Width = 50;
			// 
			// columnPozObsh
			// 
			this->columnPozObsh->HeaderText = L"Позиция общее";
			this->columnPozObsh->Name = L"columnPozObsh";
			this->columnPozObsh->ReadOnly = true;
			this->columnPozObsh->Width = 75;
			// 
			// tabPageIdent
			// 
			this->tabPageIdent->Controls->Add(this->dataGridViewIdent);
			this->tabPageIdent->Location = System::Drawing::Point(4, 25);
			this->tabPageIdent->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPageIdent->Name = L"tabPageIdent";
			this->tabPageIdent->Size = System::Drawing::Size(721, 680);
			this->tabPageIdent->TabIndex = 1;
			this->tabPageIdent->Text = L"Идентификаторы";
			this->tabPageIdent->UseVisualStyleBackColor = true;
			// 
			// dataGridViewIdent
			// 
			this->dataGridViewIdent->AllowUserToAddRows = false;
			this->dataGridViewIdent->AllowUserToDeleteRows = false;
			this->dataGridViewIdent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewIdent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {this->columnIdentif, 
				this->columnIdentTip, this->columnIdentZnach, this->columnIdentVeshZnach, this->columnIdentStroka, this->columnIdentPozStr, this->columnIdentPozObsh});
			this->dataGridViewIdent->Location = System::Drawing::Point(-5, 0);
			this->dataGridViewIdent->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridViewIdent->Name = L"dataGridViewIdent";
			this->dataGridViewIdent->ReadOnly = true;
			this->dataGridViewIdent->Size = System::Drawing::Size(724, 673);
			this->dataGridViewIdent->TabIndex = 2;
			// 
			// columnIdentif
			// 
			this->columnIdentif->HeaderText = L"Идентификатор";
			this->columnIdentif->Name = L"columnIdentif";
			this->columnIdentif->ReadOnly = true;
			// 
			// columnIdentTip
			// 
			this->columnIdentTip->HeaderText = L"Тип";
			this->columnIdentTip->Name = L"columnIdentTip";
			this->columnIdentTip->ReadOnly = true;
			this->columnIdentTip->Width = 75;
			// 
			// columnIdentZnach
			// 
			this->columnIdentZnach->HeaderText = L"Значение";
			this->columnIdentZnach->Name = L"columnIdentZnach";
			this->columnIdentZnach->ReadOnly = true;
			// 
			// columnIdentVeshZnach
			// 
			this->columnIdentVeshZnach->HeaderText = L"Вещественное значение";
			this->columnIdentVeshZnach->Name = L"columnIdentVeshZnach";
			this->columnIdentVeshZnach->ReadOnly = true;
			this->columnIdentVeshZnach->Width = 50;
			// 
			// columnIdentStroka
			// 
			this->columnIdentStroka->HeaderText = L"Строка";
			this->columnIdentStroka->Name = L"columnIdentStroka";
			this->columnIdentStroka->ReadOnly = true;
			// 
			// columnIdentPozStr
			// 
			this->columnIdentPozStr->HeaderText = L"Позиция в строке";
			this->columnIdentPozStr->Name = L"columnIdentPozStr";
			this->columnIdentPozStr->ReadOnly = true;
			this->columnIdentPozStr->Width = 50;
			// 
			// columnIdentPozObsh
			// 
			this->columnIdentPozObsh->HeaderText = L"Позиция общее";
			this->columnIdentPozObsh->Name = L"columnIdentPozObsh";
			this->columnIdentPozObsh->ReadOnly = true;
			this->columnIdentPozObsh->Width = 75;
			// 
			// groupBoxUpravlenie
			// 
			this->groupBoxUpravlenie->Controls->Add(this->labelMsMain);
			this->groupBoxUpravlenie->Controls->Add(this->knopkaVychislit);
			this->groupBoxUpravlenie->Controls->Add(this->textBoxVremyaGlavnyy);
			this->groupBoxUpravlenie->Controls->Add(this->textBoxVremyaDrugoy);
			this->groupBoxUpravlenie->Controls->Add(this->knopkaGlavnyy);
			this->groupBoxUpravlenie->Controls->Add(this->labelMsOther);
			this->groupBoxUpravlenie->Location = System::Drawing::Point(836, 15);
			this->groupBoxUpravlenie->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxUpravlenie->Name = L"groupBoxUpravlenie";
			this->groupBoxUpravlenie->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxUpravlenie->Size = System::Drawing::Size(437, 124);
			this->groupBoxUpravlenie->TabIndex = 26;
			this->groupBoxUpravlenie->TabStop = false;
			this->groupBoxUpravlenie->Text = L"Управление";
			// 
			// labelMsMain
			// 
			this->labelMsMain->AutoSize = true;
			this->labelMsMain->Location = System::Drawing::Point(367, 78);
			this->labelMsMain->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelMsMain->Name = L"labelMsMain";
			this->labelMsMain->Size = System::Drawing::Size(50, 17);
			this->labelMsMain->TabIndex = 8;
			this->labelMsMain->Text = L"Время";
			// 
			// knopkaVychislit
			// 
			this->knopkaVychislit->Location = System::Drawing::Point(55, 34);
			this->knopkaVychislit->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->knopkaVychislit->Name = L"knopkaVychislit";
			this->knopkaVychislit->Size = System::Drawing::Size(111, 28);
			this->knopkaVychislit->TabIndex = 3;
			this->knopkaVychislit->Text = L"Вычислить";
			this->knopkaVychislit->UseVisualStyleBackColor = true;
			this->knopkaVychislit->Click += gcnew System::EventHandler(this, &Form1::knopkaVychislit_Click);
			// 
			// textBoxVremyaGlavnyy
			// 
			this->textBoxVremyaGlavnyy->Location = System::Drawing::Point(259, 70);
			this->textBoxVremyaGlavnyy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxVremyaGlavnyy->Name = L"textBoxVremyaGlavnyy";
			this->textBoxVremyaGlavnyy->ReadOnly = true;
			this->textBoxVremyaGlavnyy->Size = System::Drawing::Size(99, 22);
			this->textBoxVremyaGlavnyy->TabIndex = 5;
			// 
			// textBoxVremyaDrugoy
			// 
			this->textBoxVremyaDrugoy->Location = System::Drawing::Point(55, 70);
			this->textBoxVremyaDrugoy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxVremyaDrugoy->Name = L"textBoxVremyaDrugoy";
			this->textBoxVremyaDrugoy->ReadOnly = true;
			this->textBoxVremyaDrugoy->Size = System::Drawing::Size(109, 22);
			this->textBoxVremyaDrugoy->TabIndex = 6;
			// 
			// knopkaGlavnyy
			// 
			this->knopkaGlavnyy->Location = System::Drawing::Point(259, 34);
			this->knopkaGlavnyy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->knopkaGlavnyy->Name = L"knopkaGlavnyy";
			this->knopkaGlavnyy->Size = System::Drawing::Size(100, 28);
			this->knopkaGlavnyy->TabIndex = 4;
			this->knopkaGlavnyy->Text = L"Вычислить";
			this->knopkaGlavnyy->UseVisualStyleBackColor = true;
			this->knopkaGlavnyy->Click += gcnew System::EventHandler(this, &Form1::knopkaGlavnyy_Click);
			// 
			// labelMsOther
			// 
			this->labelMsOther->AutoSize = true;
			this->labelMsOther->Location = System::Drawing::Point(175, 78);
			this->labelMsOther->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelMsOther->Name = L"labelMsOther";
			this->labelMsOther->Size = System::Drawing::Size(50, 17);
			this->labelMsOther->TabIndex = 7;
			this->labelMsOther->Text = L"Время";
			// 
			// checkBoxRuchnoy
			// 
			this->checkBoxRuchnoy->AutoSize = true;
			this->checkBoxRuchnoy->Checked = true;
			this->checkBoxRuchnoy->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxRuchnoy->Location = System::Drawing::Point(872, 48);
			this->checkBoxRuchnoy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxRuchnoy->Name = L"checkBoxRuchnoy";
			this->checkBoxRuchnoy->Size = System::Drawing::Size(120, 21);
			this->checkBoxRuchnoy->TabIndex = 27;
			this->checkBoxRuchnoy->Text = L"Ручной ввод\?";
			this->checkBoxRuchnoy->UseVisualStyleBackColor = true;
			this->checkBoxRuchnoy->Visible = false;
			// 
			// labelOshibka5
			// 
			this->labelOshibka5->AutoSize = true;
			this->labelOshibka5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelOshibka5->Location = System::Drawing::Point(1080, 500);
			this->labelOshibka5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelOshibka5->Name = L"labelOshibka5";
			this->labelOshibka5->Size = System::Drawing::Size(0, 25);
			this->labelOshibka5->TabIndex = 56;
			this->labelOshibka5->Visible = false;
			// 
			// labelOshibka4
			// 
			this->labelOshibka4->AutoSize = true;
			this->labelOshibka4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelOshibka4->Location = System::Drawing::Point(861, 500);
			this->labelOshibka4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelOshibka4->Name = L"labelOshibka4";
			this->labelOshibka4->Size = System::Drawing::Size(98, 25);
			this->labelOshibka4->TabIndex = 55;
			this->labelOshibka4->Text = L"Ошибка:";
			this->labelOshibka4->Visible = false;
			// 
			// labelOshibka3
			// 
			this->labelOshibka3->AutoSize = true;
			this->labelOshibka3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelOshibka3->Location = System::Drawing::Point(1036, 437);
			this->labelOshibka3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelOshibka3->Name = L"labelOshibka3";
			this->labelOshibka3->Size = System::Drawing::Size(0, 25);
			this->labelOshibka3->TabIndex = 54;
			this->labelOshibka3->Visible = false;
			// 
			// labelOshibka2
			// 
			this->labelOshibka2->AutoSize = true;
			this->labelOshibka2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelOshibka2->Location = System::Drawing::Point(861, 437);
			this->labelOshibka2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelOshibka2->Name = L"labelOshibka2";
			this->labelOshibka2->Size = System::Drawing::Size(98, 25);
			this->labelOshibka2->TabIndex = 53;
			this->labelOshibka2->Text = L"Ошибка:";
			this->labelOshibka2->Visible = false;
			// 
			// labelOshibka1
			// 
			this->labelOshibka1->AutoSize = true;
			this->labelOshibka1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelOshibka1->Location = System::Drawing::Point(861, 378);
			this->labelOshibka1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelOshibka1->Name = L"labelOshibka1";
			this->labelOshibka1->Size = System::Drawing::Size(571, 25);
			this->labelOshibka1->TabIndex = 52;
			this->labelOshibka1->Text = L"Ошибка: неверное выражение или неверный формат ввода";
			this->labelOshibka1->Visible = false;
			this->labelOshibka1->Click += gcnew System::EventHandler(this, &Form1::labelOshibka1_Click);
			// 
			// knopkaLeksAnaliz
			// 
			this->knopkaLeksAnaliz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->knopkaLeksAnaliz->Location = System::Drawing::Point(867, 218);
			this->knopkaLeksAnaliz->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->knopkaLeksAnaliz->Name = L"knopkaLeksAnaliz";
			this->knopkaLeksAnaliz->Size = System::Drawing::Size(180, 39);
			this->knopkaLeksAnaliz->TabIndex = 51;
			this->knopkaLeksAnaliz->Text = L"Лексический анализ";
			this->knopkaLeksAnaliz->UseVisualStyleBackColor = true;
			this->knopkaLeksAnaliz->Click += gcnew System::EventHandler(this, &Form1::knopkaLeksAnaliz_Click);
			// 
			// knopkaIskhodnyy
			// 
			this->knopkaIskhodnyy->Location = System::Drawing::Point(867, 297);
			this->knopkaIskhodnyy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->knopkaIskhodnyy->Name = L"knopkaIskhodnyy";
			this->knopkaIskhodnyy->Size = System::Drawing::Size(132, 49);
			this->knopkaIskhodnyy->TabIndex = 50;
			this->knopkaIskhodnyy->Text = L"Выход";
			this->knopkaIskhodnyy->UseVisualStyleBackColor = true;
			this->knopkaIskhodnyy->Click += gcnew System::EventHandler(this, &Form1::knopkaIskhodnyy_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1525, 758);
			this->Controls->Add(this->labelOshibka5);
			this->Controls->Add(this->labelOshibka4);
			this->Controls->Add(this->labelOshibka3);
			this->Controls->Add(this->labelOshibka2);
			this->Controls->Add(this->labelOshibka1);
			this->Controls->Add(this->knopkaLeksAnaliz);
			this->Controls->Add(this->knopkaIskhodnyy);
			this->Controls->Add(this->tabControlOsnovnoy);
			this->Controls->Add(this->groupBoxUpravlenie);
			this->Controls->Add(this->checkBoxRuchnoy);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"Шапкина А.С.";
			this->tabControlOsnovnoy->ResumeLayout(false);
			this->tabPageVkhodnye->ResumeLayout(false);
			this->tabPageVkhodnye->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownA))->EndInit();
			this->tabPageIskhodnyy->ResumeLayout(false);
			this->tabPageIskhodnyy->PerformLayout();
			this->tabPageRezultat->ResumeLayout(false);
			this->tabPageRezultat->PerformLayout();
			this->tabPageLeksicheskiy->ResumeLayout(false);
			this->tabControlLeksicheskiy->ResumeLayout(false);
			this->tabPageLeksemy->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridViewLeksemy))->EndInit();
			this->tabPageIdent->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridViewIdent))->EndInit();
			this->groupBoxUpravlenie->ResumeLayout(false);
			this->groupBoxUpravlenie->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: void SetTextTextTask()
		 {
			textBoxIskhodnyy->Text = "a = 12;\r\nif a > b\r\na = a + b;\r\nelse\r\na = a - b;\r\nend";
		 }
private: void SetTextTask()
		 {
			// Очистка TextBoxIskhodnyy
			textBoxIskhodnyy->Clear();

			// Преобразование значений из NumericUpDown в переменные
			double a = static_cast<double>(numericUpDownA->Value);       // numericUpDownA -> a
			double num_b_val = static_cast<double>(numericUpDownB->Value); // numericUpDownB

			// Формирование строки исходного текста
			String^ output = "";
			output += "a = " + a.ToString() + ";\r\n";
			output += "if a > "  + num_b_val.ToString() + "\r\n";
			output += "a = a + b;\r\n";
			output += "else\r\n";
			output += "a = a - b;\r\n";
			output += "end";
			// Добавление строки исходного текста в TextBoxIskhodnyy
			textBoxIskhodnyy->AppendText(output);
		 }
private: System::Void dataGridView1_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e) {
		// Обработка события для редактирования ячейки
		TextBox^ textBox = dynamic_cast<TextBox^>(e->Control);
		if (textBox != nullptr) {
			textBox->KeyPress += gcnew KeyPressEventHandler(this, &Form1::dataGridViewTextBox_KeyPress);
		}
	}

	private: System::Void dataGridViewTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Проверка на допустимые символы в тексте
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 127) {
			e->Handled = true;
		}
	}


	private: std::vector<std::string> ExtractValuesFromDataGridView(DataGridView^ dataGridView, int rowIndex) {
		std::vector<std::string> values;

		if (rowIndex < 0 || rowIndex >= dataGridView->RowCount) {
			return values; // Возвращаем пустой вектор, если индекс выходит за пределы
		}

		// Получение строки из dataGridView
		DataGridViewRow^ row = dataGridView->Rows[rowIndex];

		// Получение значения каждой ячейки и преобразование в строку
		for each (DataGridViewCell^ cell in row->Cells) {
			try
			{
				System::String^ cellValue = cell->Value->ToString();
				std::string stdCellValue = msclr::interop::marshal_as<std::string>(cellValue);
				values.push_back(stdCellValue);
			}
			catch(System::Exception^ ex)
			{
				values.push_back("0");
			}
		}

		return values;
	}

private: System::Void startOperation()
		{
			double a =Decimal::ToDouble(numericUpDownA->Value);
			double b =Decimal::ToDouble(numericUpDownB->Value);
			std::string myStdString = SHASProcess::FormatAsMatlabArray(checkBoxRuchnoy->Checked, a,b);
			System::String ^ mySystemString = marshal_as<System::String ^>(myStdString);
			textBoxRezultat->Invoke(gcnew Action<String^>(this, &Form1::UpdateTextBoxRezultat), mySystemString);
		}


		// Метод для обновления textBoxRezultat
		void UpdateTextBoxRezultat(String^ newText) {
			textBoxRezultat->Text = newText;
			stopwatch->Stop();
			String^ elapsedTimeStr = gcnew String(std::to_string(stopwatch->ElapsedMilliseconds).c_str());
			textBoxVremyaDrugoy->Text = elapsedTimeStr;
		}
private: System::Void knopkaVychislit_Click(System::Object^  sender, System::EventArgs^  e) 
				  {
					stopwatch = gcnew Stopwatch();
					// Запуск таймера
					stopwatch->Start();

					Thread^ operationsThread = gcnew Thread(gcnew ThreadStart(this, &Form1::startOperation));
					operationsThread->Start();
					SetTextTask();
		 }
				  

private: System::Void knopkaGlavnyy_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			Stopwatch^ stopwatch = gcnew Stopwatch();
			// Запуск таймера
			stopwatch->Start();
			double a =Decimal::ToDouble(numericUpDownA->Value);
			double b =Decimal::ToDouble(numericUpDownB->Value);
			std::string myStdString = SHASProcess::FormatAsMatlabArray(checkBoxRuchnoy->Checked, a,b);
			System::String ^ mySystemString = marshal_as<System::String ^>(myStdString);
			textBoxRezultat->Text = mySystemString;
			// Остановка таймера
			stopwatch->Stop();

			// Получение времени выполнения в миллисекундах
			long long elapsedTimeMs = stopwatch->ElapsedMilliseconds;

			// Преобразование времени в строку
			String^ elapsedTimeStr = gcnew String(std::to_string(elapsedTimeMs).c_str());

			// Добавление времени выполнения в textBoxVremyaGlavnyy
			textBoxVremyaGlavnyy->Text = elapsedTimeStr;

			SetTextTask();
		 }
private: System::Void knopkaLeksAnaliz_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SetTextTextTask();
			 tabControlOsnovnoy->SelectedIndex = 1;  
		 }
private: System::Void knopkaIskhodnyy_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 dataGridViewLeksemy->RowCount = 0;
			 dataGridViewIdent->RowCount = 0;
			 tabControlOsnovnoy->SelectedIndex = 3;   

			TLexemList* pLexemList = 0;
			TIdentList* pIdentList = 0;
			String^ sPassC;
			int				iRet = 0;
			char*			cStr = 0;
			char*			cError = 0;
			char*			cTaskText = 0;
			IntPtr ptr = Marshal::StringToHGlobalAnsi(textBoxIskhodnyy->Text);
			cTaskText = (char*)ptr.ToPointer(); 

			iRet = kaLex(cTaskText, &pLexemList, &pIdentList, cError);
			if(iRet == -1)
			{
				labelOshibka1->Visible = true;
				labelOshibka2->Visible = true;
				labelOshibka3->Visible = true;
				labelOshibka4->Visible = true;
				labelOshibka5->Visible = true;
				if(pLexemList->getCount() != NULL)
				{
					String ^s;
					String ^S;
					TLexem* pLex = 0;
					pLexemList->get(pLexemList->getCount() - 1,&pLex);
					s = System::Convert::ToString(pLex->getNumStr()); 
					S = System::Convert::ToString(pLex->getPosStr());
					labelOshibka3->Text = s;
					labelOshibka5->Text = S;
				}
				else 
				{
					labelOshibka3->Text = "1";
					labelOshibka5->Text = "1";
				}
			}
			else
			{
				labelOshibka1->Visible = false;
				labelOshibka2->Visible = false;
				labelOshibka3->Visible = false;
				labelOshibka4->Visible = false;
				labelOshibka5->Visible = false;
			}


			if(pLexemList->getCount() != NULL)
			{
				int iCount = pLexemList->getCount();
				dataGridViewLeksemy->Rows->Add(iCount);
				TLexem* pLex = 0;
				for (int i=0; i<iCount; i++)
				{
					pLexemList->get(i,&pLex);
					if(pLex != 0)
					{
						cStr = (char*)pLex->getText();
						String^ sStr			= gcnew String(cStr);
						int iLexType            = pLex->getType();
						int iLexIntValue        = pLex->getIval();
						double dLexRealValue    = pLex->getDval();
						unsigned int iLexStrNum = pLex->getNumStr();
						unsigned int iLexPosStr = pLex->getPosStr();
						unsigned int iLexPos    = pLex->getPos();


						dataGridViewLeksemy[0,i]->Value = sStr;
						dataGridViewLeksemy[1,i]->Value = iLexType;
						dataGridViewLeksemy[2,i]->Value = iLexIntValue;
						dataGridViewLeksemy[3,i]->Value = dLexRealValue;
						dataGridViewLeksemy[4,i]->Value = iLexStrNum;
						dataGridViewLeksemy[5,i]->Value = iLexPosStr;
						dataGridViewLeksemy[6,i]->Value = iLexPos;

						cStr = 0;
					}
				}
				delete pLexemList;
			}
			pLexemList = 0;

			if(pIdentList->getCount() != NULL)
			{
				int iCount = pIdentList->getCount();

				dataGridViewIdent->Rows->Add(iCount);
				TLexem* pLex = 0;
				for (int i=0; i<iCount; i++)
				{
					pIdentList->get(i,&pLex);
					if(pLex != 0)
					{
						cStr = (char*)pLex->getText();
						String^ sStr			= gcnew String(cStr);
						int iType            = pLex->getType();
						int iIntValue        = pLex->getIval();
						double dRealValue    = pLex->getDval();
						unsigned int iStrNum = pLex->getNumStr();
						unsigned int iPosStr = pLex->getPosStr();
						unsigned int iPos    = pLex->getPos();

						dataGridViewIdent[0,i]->Value = sStr;
						dataGridViewIdent[1,i]->Value = iType;
						dataGridViewIdent[2,i]->Value = iIntValue;
						dataGridViewIdent[3,i]->Value = dRealValue;
						dataGridViewIdent[4,i]->Value = iStrNum;
						dataGridViewIdent[5,i]->Value = iPosStr;
						dataGridViewIdent[6,i]->Value = iPos;

						cStr = 0;
					}
				}
				delete pIdentList;
			}
			pIdentList = 0;
		 }

		/// <summary>
		/// Required variable for the designer.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Void labelOshibka1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}


