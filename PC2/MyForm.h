#pragma once
#include "Juego.h"
namespace PC2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		Graphics^ canvas;  
		BufferedGraphicsContext^ context; 
		BufferedGraphics^ buffer;
		Juego* juego;  
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
		   

	public:
		MyForm(void)
		{
			InitializeComponent();
			InitializeComponent();
			canvas = this->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(canvas, this->ClientRectangle);
			juego = new Juego(buffer->Graphics->VisibleClipBounds.Width, buffer->Graphics->VisibleClipBounds.Height);  
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 262);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			this->label1->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1296, 721);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		if (e->KeyCode == Keys::W)
		{
			juego->moverTeclas(buffer->Graphics, Arriba);  
		} 

		if (e->KeyCode == Keys::S) 
		{
			juego->moverTeclas(buffer->Graphics, Abajo); 
		}
		
		if (e->KeyCode == Keys::M)
		{
			juego->CrearZombi(buffer->Graphics->VisibleClipBounds.Width, buffer->Graphics->VisibleClipBounds.Height);  
		}
		if (e->KeyCode == Keys::Space) 
		{  
			juego->disparar(); 
		} 
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		if (juego->getTotalPuntos() <= 150)
		{
			
			buffer->Graphics->Clear(Color::White); 
			juego->mostrar(buffer->Graphics); 
			juego->mover(buffer->Graphics); 
			buffer->Render(canvas); 
		}

		else 
		{
			label1->Visible = true;
			label1->Text = "Tu numero de zombis asesinados fue: " + (juego->getTotalPuntos() / 10).ToString(); 
		}

	}


};
}
