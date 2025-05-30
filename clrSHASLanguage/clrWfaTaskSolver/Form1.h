#pragma once
#include <Windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <msclr/marshal_cppstd.h> // Для преобразования System::String в std::string
#include <cliext/vector> // Для работы с dataGridView
#include <msclr/marshal_cppstd.h>
#include "..\..\Language\SHASProcess.h"
using namespace msclr::interop;
using namespace System::Diagnostics;
using namespace System::Threading;
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
			//TODO: добавьте код конструктора
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
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPageInput;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  num_b;
	private: System::Windows::Forms::NumericUpDown^  num_a;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TabPage^  tabPageSolver;
	private: System::Windows::Forms::TextBox^  textBoxSolver;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBoxButtonTimeMainThread;
	private: System::Windows::Forms::TextBox^  textBoxButtonTimeOtherThread;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::CheckBox^  ManualCheckBox;

	protected: 













	protected: 






	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageInput = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->num_b = (gcnew System::Windows::Forms::NumericUpDown());
			this->num_a = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabPageSolver = (gcnew System::Windows::Forms::TabPage());
			this->textBoxSolver = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBoxButtonTimeMainThread = (gcnew System::Windows::Forms::TextBox());
			this->textBoxButtonTimeOtherThread = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->ManualCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl1->SuspendLayout();
			this->tabPageInput->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num_b))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num_a))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->tabPageSolver->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPageInput);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPageSolver);
			this->tabControl1->Location = System::Drawing::Point(12, 106);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(817, 382);
			this->tabControl1->TabIndex = 25;
			// 
			// tabPageInput
			// 
			this->tabPageInput->Controls->Add(this->label6);
			this->tabPageInput->Controls->Add(this->label5);
			this->tabPageInput->Controls->Add(this->label4);
			this->tabPageInput->Controls->Add(this->label3);
			this->tabPageInput->Controls->Add(this->label2);
			this->tabPageInput->Controls->Add(this->label1);
			this->tabPageInput->Controls->Add(this->num_b);
			this->tabPageInput->Controls->Add(this->num_a);
			this->tabPageInput->Location = System::Drawing::Point(4, 22);
			this->tabPageInput->Name = L"tabPageInput";
			this->tabPageInput->Padding = System::Windows::Forms::Padding(3);
			this->tabPageInput->Size = System::Drawing::Size(809, 356);
			this->tabPageInput->TabIndex = 0;
			this->tabPageInput->Text = L"Исходные Данные";
			this->tabPageInput->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(14, 165);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 20);
			this->label6->TabIndex = 15;
			this->label6->Text = L"a = a - b";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(14, 199);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 20);
			this->label5->TabIndex = 14;
			this->label5->Text = L"end";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(8, 129);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 20);
			this->label4->TabIndex = 12;
			this->label4->Text = L"else";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"a = a + b";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 20);
			this->label2->TabIndex = 10;
			this->label2->Text = L"If a > ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(8, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 20);
			this->label1->TabIndex = 9;
			this->label1->Text = L"a = ";
			// 
			// num_b
			// 
			this->num_b->DecimalPlaces = 2;
			this->num_b->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->num_b->Location = System::Drawing::Point(66, 58);
			this->num_b->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->num_b->Name = L"num_b";
			this->num_b->Size = System::Drawing::Size(61, 20);
			this->num_b->TabIndex = 6;
			// 
			// num_a
			// 
			this->num_a->DecimalPlaces = 2;
			this->num_a->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->num_a->Location = System::Drawing::Point(49, 18);
			this->num_a->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->num_a->Name = L"num_a";
			this->num_a->Size = System::Drawing::Size(61, 20);
			this->num_a->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Size = System::Drawing::Size(809, 356);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Постановка задачи";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(6, 7);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(797, 343);
			this->textBox1->TabIndex = 1;
			// 
			// tabPageSolver
			// 
			this->tabPageSolver->Controls->Add(this->textBoxSolver);
			this->tabPageSolver->Location = System::Drawing::Point(4, 22);
			this->tabPageSolver->Name = L"tabPageSolver";
			this->tabPageSolver->Padding = System::Windows::Forms::Padding(3);
			this->tabPageSolver->Size = System::Drawing::Size(809, 356);
			this->tabPageSolver->TabIndex = 1;
			this->tabPageSolver->Text = L"Результат";
			this->tabPageSolver->UseVisualStyleBackColor = true;
			// 
			// textBoxSolver
			// 
			this->textBoxSolver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBoxSolver->Location = System::Drawing::Point(6, 6);
			this->textBoxSolver->Multiline = true;
			this->textBoxSolver->Name = L"textBoxSolver";
			this->textBoxSolver->ReadOnly = true;
			this->textBoxSolver->Size = System::Drawing::Size(797, 343);
			this->textBoxSolver->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBoxButtonTimeMainThread);
			this->groupBox1->Controls->Add(this->textBoxButtonTimeOtherThread);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Location = System::Drawing::Point(497, 11);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(328, 101);
			this->groupBox1->TabIndex = 26;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Поток";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(275, 63);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(27, 13);
			this->label8->TabIndex = 8;
			this->label8->Text = L"мск";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(41, 28);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(83, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Отдельный";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBoxButtonTimeMainThread
			// 
			this->textBoxButtonTimeMainThread->Location = System::Drawing::Point(194, 57);
			this->textBoxButtonTimeMainThread->Name = L"textBoxButtonTimeMainThread";
			this->textBoxButtonTimeMainThread->ReadOnly = true;
			this->textBoxButtonTimeMainThread->Size = System::Drawing::Size(75, 20);
			this->textBoxButtonTimeMainThread->TabIndex = 5;
			// 
			// textBoxButtonTimeOtherThread
			// 
			this->textBoxButtonTimeOtherThread->Location = System::Drawing::Point(41, 57);
			this->textBoxButtonTimeOtherThread->Name = L"textBoxButtonTimeOtherThread";
			this->textBoxButtonTimeOtherThread->ReadOnly = true;
			this->textBoxButtonTimeOtherThread->Size = System::Drawing::Size(83, 20);
			this->textBoxButtonTimeOtherThread->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(194, 28);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Основной";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(131, 63);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(27, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"мск";
			// 
			// ManualCheckBox
			// 
			this->ManualCheckBox->AutoSize = true;
			this->ManualCheckBox->Checked = true;
			this->ManualCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ManualCheckBox->Location = System::Drawing::Point(654, 39);
			this->ManualCheckBox->Name = L"ManualCheckBox";
			this->ManualCheckBox->Size = System::Drawing::Size(137, 17);
			this->ManualCheckBox->TabIndex = 27;
			this->ManualCheckBox->Text = L"Ввод автоматически\?";
			this->ManualCheckBox->UseVisualStyleBackColor = true;
			this->ManualCheckBox->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(828, 487);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->ManualCheckBox);
			this->Name = L"Form1";
			this->Text = L"Решетняк К.И. СПО, Лабораторная работа 5";
			this->tabControl1->ResumeLayout(false);
			this->tabPageInput->ResumeLayout(false);
			this->tabPageInput->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num_b))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num_a))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPageSolver->ResumeLayout(false);
			this->tabPageSolver->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: void SetTextTask()
		 {
			// Очищаем TextBox1 перед добавлением новых данных
			textBox1->Clear();

			// Получаем значения от пользователя
			double a = static_cast<double>(num_a->Value);       // num_a -> a
			double num_b_val = static_cast<double>(num_b->Value); // num_b

			// Формируем строку вывода с формулами
			String^ output = "";
			output += "a = " + a.ToString() + ";\r\n";
			output += "if a > "  + num_b_val.ToString() + "\r\n";
			output += "a = a + b;\r\n";
			output += "else\r\n";
			output += "a = a - b;\r\n";
			output += "end";
			// Добавляем результат в TextBox
			textBox1->AppendText(output);
		 }
private: System::Void dataGridView1_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e) {
		// Установим ограничение на ввод только чисел в ячейках
		TextBox^ textBox = dynamic_cast<TextBox^>(e->Control);
		if (textBox != nullptr) {
			textBox->KeyPress += gcnew KeyPressEventHandler(this, &Form1::dataGridViewTextBox_KeyPress);
		}
	}

	private: System::Void dataGridViewTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Разрешим вводить только цифры, Backspace и клавишу Delete
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 127) {
			e->Handled = true;
		}
	}


	private: std::vector<std::string> ExtractValuesFromDataGridView(DataGridView^ dataGridView, int rowIndex) {
		std::vector<std::string> values;

		if (rowIndex < 0 || rowIndex >= dataGridView->RowCount) {
			return values; // Возвращаем пустой вектор, если строка не существует
		}

		// Получаем доступ к строке в dataGridView
		DataGridViewRow^ row = dataGridView->Rows[rowIndex];

		// Перебираем ячейки в строке и извлекаем их значения
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
			double a =Decimal::ToDouble(num_a->Value);
			double b =Decimal::ToDouble(num_b->Value);
			std::string myStdString = SHASProcess::FormatAsMatlabArray(ManualCheckBox->Checked, a,b);
			System::String ^ mySystemString = marshal_as<System::String ^>(myStdString);
			textBoxSolver->Invoke(gcnew Action<String^>(this, &Form1::UpdateTextBoxSolver), mySystemString);
		}


		// Метод для обновления textBoxSolver
		void UpdateTextBoxSolver(String^ newText) {
			textBoxSolver->Text = newText;
			stopwatch->Stop();
			String^ elapsedTimeStr = gcnew String(std::to_string(stopwatch->ElapsedMilliseconds).c_str());
			textBoxButtonTimeOtherThread->Text = elapsedTimeStr;
		}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
				  {
					stopwatch = gcnew Stopwatch();
					// Запускаем секундомер
					stopwatch->Start();

					Thread^ operationsThread = gcnew Thread(gcnew ThreadStart(this, &Form1::startOperation));
					operationsThread->Start();
					SetTextTask();
		 }
				  

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			Stopwatch^ stopwatch = gcnew Stopwatch();
			// Запускаем секундомер
			stopwatch->Start();
			double a =Decimal::ToDouble(num_a->Value);
			double b =Decimal::ToDouble(num_b->Value);
			std::string myStdString = SHASProcess::FormatAsMatlabArray(ManualCheckBox->Checked, a,b);
			System::String ^ mySystemString = marshal_as<System::String ^>(myStdString);
			textBoxSolver->Text = mySystemString;
			// Останавливаем секундомер
			stopwatch->Stop();

			// Получаем время выполнения в миллисекундах
			long long elapsedTimeMs = stopwatch->ElapsedMilliseconds;

			// Преобразуем время выполнения в строку
			String^ elapsedTimeStr = gcnew String(std::to_string(elapsedTimeMs).c_str());

			// Отображаем время выполнения в textBoxSolver
			textBoxButtonTimeMainThread->Text = elapsedTimeStr;

			SetTextTask();
		 }
};
}


