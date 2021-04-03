#pragma once

#include "VentanaGrafo.h"
#include "Digrafica.h"
#include <string>

namespace Grafo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class VentanaInsertar : public System::Windows::Forms::Form
	{
	public:
		VentanaInsertar(Digrafica<int>* newDri)
		{
			this->dri = newDri;
			InitializeComponent();
			pnlInsertarArista->Hide();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VentanaInsertar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Digrafica<int>* dri;
	private: int* nClicks = new int;

	private: System::Windows::Forms::ComboBox^ cbxNAristas;
	private: System::Windows::Forms::Panel^ pnlNAristas;
	private: System::Windows::Forms::Button^ btnAceptar;
	private: System::Windows::Forms::Panel^ pnlInsertarArista;
	private: System::Windows::Forms::Label^ lblCoste;
	private: System::Windows::Forms::Label^ lblVf;
	private: System::Windows::Forms::Label^ lblVi;
	private: System::Windows::Forms::Button^ btnInsertar;
	private: System::Windows::Forms::TextBox^ txtCoste;
	private: System::Windows::Forms::TextBox^ txbVf;
	private: System::Windows::Forms::TextBox^ txbVi;
	private: System::Windows::Forms::Label^ lblAristas;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cbxNAristas = (gcnew System::Windows::Forms::ComboBox());
			this->pnlNAristas = (gcnew System::Windows::Forms::Panel());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->pnlInsertarArista = (gcnew System::Windows::Forms::Panel());
			this->lblCoste = (gcnew System::Windows::Forms::Label());
			this->lblVf = (gcnew System::Windows::Forms::Label());
			this->lblVi = (gcnew System::Windows::Forms::Label());
			this->btnInsertar = (gcnew System::Windows::Forms::Button());
			this->txtCoste = (gcnew System::Windows::Forms::TextBox());
			this->txbVf = (gcnew System::Windows::Forms::TextBox());
			this->txbVi = (gcnew System::Windows::Forms::TextBox());
			this->lblAristas = (gcnew System::Windows::Forms::Label());
			this->pnlNAristas->SuspendLayout();
			this->pnlInsertarArista->SuspendLayout();
			this->SuspendLayout();
			// 
			// cbxNAristas
			// 
			this->cbxNAristas->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(10) {
				L"1", L"2", L"3", L"4", L"5",
					L"6", L"7", L"8", L"9", L"10"
			});
			this->cbxNAristas->FormattingEnabled = true;
			this->cbxNAristas->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->cbxNAristas->Location = System::Drawing::Point(17, 24);
			this->cbxNAristas->Name = L"cbxNAristas";
			this->cbxNAristas->Size = System::Drawing::Size(121, 24);
			this->cbxNAristas->TabIndex = 0;
			// 
			// pnlNAristas
			// 
			this->pnlNAristas->Controls->Add(this->btnAceptar);
			this->pnlNAristas->Controls->Add(this->cbxNAristas);
			this->pnlNAristas->Location = System::Drawing::Point(12, 12);
			this->pnlNAristas->Name = L"pnlNAristas";
			this->pnlNAristas->Size = System::Drawing::Size(387, 118);
			this->pnlNAristas->TabIndex = 1;
			// 
			// btnAceptar
			// 
			this->btnAceptar->Location = System::Drawing::Point(209, 24);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(75, 23);
			this->btnAceptar->TabIndex = 1;
			this->btnAceptar->Text = L"Aceptar";
			this->btnAceptar->UseVisualStyleBackColor = true;
			this->btnAceptar->Click += gcnew System::EventHandler(this, &VentanaInsertar::btnAceptar_Click);
			// 
			// pnlInsertarArista
			// 
			this->pnlInsertarArista->Controls->Add(this->lblAristas);
			this->pnlInsertarArista->Controls->Add(this->lblCoste);
			this->pnlInsertarArista->Controls->Add(this->lblVf);
			this->pnlInsertarArista->Controls->Add(this->lblVi);
			this->pnlInsertarArista->Controls->Add(this->btnInsertar);
			this->pnlInsertarArista->Controls->Add(this->txtCoste);
			this->pnlInsertarArista->Controls->Add(this->txbVf);
			this->pnlInsertarArista->Controls->Add(this->txbVi);
			this->pnlInsertarArista->Location = System::Drawing::Point(13, 159);
			this->pnlInsertarArista->Name = L"pnlInsertarArista";
			this->pnlInsertarArista->Size = System::Drawing::Size(386, 324);
			this->pnlInsertarArista->TabIndex = 2;
			// 
			// lblCoste
			// 
			this->lblCoste->AutoSize = true;
			this->lblCoste->Location = System::Drawing::Point(132, 210);
			this->lblCoste->Name = L"lblCoste";
			this->lblCoste->Size = System::Drawing::Size(44, 17);
			this->lblCoste->TabIndex = 6;
			this->lblCoste->Text = L"Coste";
			// 
			// lblVf
			// 
			this->lblVf->AutoSize = true;
			this->lblVf->Location = System::Drawing::Point(225, 126);
			this->lblVf->Name = L"lblVf";
			this->lblVf->Size = System::Drawing::Size(96, 17);
			this->lblVf->TabIndex = 5;
			this->lblVf->Text = L"Arista Destino";
			// 
			// lblVi
			// 
			this->lblVi->AutoSize = true;
			this->lblVi->Location = System::Drawing::Point(34, 126);
			this->lblVi->Name = L"lblVi";
			this->lblVi->Size = System::Drawing::Size(91, 17);
			this->lblVi->TabIndex = 4;
			this->lblVi->Text = L"Arista Origen";
			// 
			// btnInsertar
			// 
			this->btnInsertar->Location = System::Drawing::Point(149, 270);
			this->btnInsertar->Name = L"btnInsertar";
			this->btnInsertar->Size = System::Drawing::Size(75, 23);
			this->btnInsertar->TabIndex = 3;
			this->btnInsertar->Text = L"Insertar";
			this->btnInsertar->UseVisualStyleBackColor = true;
			this->btnInsertar->Click += gcnew System::EventHandler(this, &VentanaInsertar::btnInsertar_Click);
			// 
			// txtCoste
			// 
			this->txtCoste->Location = System::Drawing::Point(135, 185);
			this->txtCoste->Name = L"txtCoste";
			this->txtCoste->Size = System::Drawing::Size(100, 22);
			this->txtCoste->TabIndex = 2;
			// 
			// txbVf
			// 
			this->txbVf->Location = System::Drawing::Point(228, 101);
			this->txbVf->Name = L"txbVf";
			this->txbVf->Size = System::Drawing::Size(100, 22);
			this->txbVf->TabIndex = 1;
			// 
			// txbVi
			// 
			this->txbVi->Location = System::Drawing::Point(37, 101);
			this->txbVi->Name = L"txbVi";
			this->txbVi->Size = System::Drawing::Size(100, 22);
			this->txbVi->TabIndex = 0;
			// 
			// lblAristas
			// 
			this->lblAristas->AutoSize = true;
			this->lblAristas->Location = System::Drawing::Point(181, 21);
			this->lblAristas->Name = L"lblAristas";
			this->lblAristas->Size = System::Drawing::Size(13, 17);
			this->lblAristas->TabIndex = 7;
			this->lblAristas->Text = L"-";
			// 
			// VentanaInsertar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(411, 495);
			this->Controls->Add(this->pnlInsertarArista);
			this->Controls->Add(this->pnlNAristas);
			this->Name = L"VentanaInsertar";
			this->Text = L"MyForm";
			this->pnlNAristas->ResumeLayout(false);
			this->pnlInsertarArista->ResumeLayout(false);
			this->pnlInsertarArista->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnAceptar_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlInsertarArista->Show();
		int numVer = cbxNAristas->SelectedIndex + 1;
		dri->setNumver(numVer);
		dri->iniciarVertices();
		lblAristas->Text = convertToString(std::to_string(dri->getNumver()));
		*nClicks = dri->getNumver();
	}

	private: System::Void btnInsertar_Click(System::Object^ sender, System::EventArgs^ e) {   
		if (btnInsertar->Capture && *nClicks > 0) {
			dri->insertarVertice(convertToInt(txbVi->Text), convertToInt(txbVf->Text), convertToInt(txtCoste->Text));
			*nClicks = *nClicks - 1;
		}
		if (*nClicks == 0) {
			this->Visible = false;
		}
	}

	private:int convertToInt(String^ a) {
		std::string aux;
		for (int i = 0; i < a->Length; i++) {
			aux += a[i];
		}
		return stoi(aux);
	}

	private:String^ convertToString(std::string a) {
		String^ aux;
		for (int i = 0; i < a.length(); i++) {
			aux += a[i] - 48;
		}
		return aux;
	}
};
}
