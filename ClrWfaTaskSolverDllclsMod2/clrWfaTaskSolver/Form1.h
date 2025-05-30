#pragma once
#include "..\..\ClassDll\TTaskImport.h"
#include <windows.h>
#include "..\..\CoDec\CoDec.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
namespace clrWfaTaskSolver {
	typedef int (CALLBACK* MYPROC ) (TTask* _ptr);
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
	private: System::Windows::Forms::TextBox^  textBox5;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

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
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(187, 353);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(244, 20);
			this->textBox5->TabIndex = 25;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(187, 406);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(244, 20);
			this->textBox6->TabIndex = 24;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 406);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(164, 21);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Пароль (расшфир.)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(12, 351);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(139, 21);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Имя (расшфир.)";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(187, 225);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(244, 20);
			this->textBox3->TabIndex = 21;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(187, 279);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(244, 20);
			this->textBox4->TabIndex = 20;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 278);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 21);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Пароль (зашифр.)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 225);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 21);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Имя (зашифр.)";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(187, 82);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(244, 20);
			this->textBox2->TabIndex = 17;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(187, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(244, 20);
			this->textBox1->TabIndex = 16;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(205, 133);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 33);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Вход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 21);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Пароль";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 21);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Имя";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 472);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Решетняк К.И. СПО, Лабораторная работа 4";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 				 IntPtr IntPtrPtr = Marshal::StringToHGlobalAnsi(textBox1->Text);
				 unsigned char* cLoginStr = (unsigned char*)IntPtrPtr.ToPointer();
				 IntPtrPtr = Marshal::StringToHGlobalAnsi(textBox2->Text);
				 unsigned char* cPassStr = (unsigned char*)IntPtrPtr.ToPointer();
				 unsigned char cLoginCode[32];
				 unsigned char cPassCode[32];
				 unsigned char cPtrKey[2]={'A', '\0'};
				 unsigned char* cPtrLogin=0;
				 unsigned char* cPtrPass=0;
				 unsigned char* cPtrK=0;	 

				 cPtrLogin = &cLoginCode[0];
				 cPtrPass = &cPassCode[0];
				 cPtrK = &cPtrKey[0];

				 int iRet = Code(cPtrLogin, cLoginStr, cPtrK);

				 if (iRet > 0)
				 {
					 String^ sNameC = gcnew String(( char*)cPtrLogin);
					 textBox3->Text = sNameC; 
				 }

				 iRet = Code(cPtrPass, cPassStr, cPtrK);

				 if (iRet > 0)
				 {
					 String^ sPassC = gcnew String(( char*)cPtrPass);
					 textBox4->Text = sPassC;
				 }

				 
				ofstream f;
				f.open("C:\\proverka\\4\\Users.txt", std::ios::app);
				f << cPtrLogin << " " <<cPtrPass<<endl;
				f.close();

				 iRet = DeCode(cPtrLogin, cPtrLogin, cPtrK);
				 iRet = DeCode(cPtrPass, cPtrPass, cPtrK);

				 if (iRet > 0)				
				 {
					 String^ sNameC = gcnew String(( char*)cPtrLogin);
					 textBox5->Text = sNameC; 
				 }
				
				 if (iRet > 0)
				 {
					 String^ sPassC = gcnew String(( char*)cPtrPass);
					 textBox6->Text = sPassC;
				 }
		 }
};
}

