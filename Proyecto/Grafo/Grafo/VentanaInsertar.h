#pragma once

#include "VentanaGrafo.h"
#include "Digrafica.h"
#include "Grafica.h"
#include "Recorrido.h"
#include <string>

namespace Grafo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class VentanaInsertar : public System::Windows::Forms::Form
	{
	public:
		VentanaInsertar(Digrafica<int>* newDri, Grafica<int>* grf, DataGridView^ dtgvMatAdy)
		{
			this->dtgvMatAdy = dtgvMatAdy;
			this->dri = newDri;
			this->grf = grf;
			InitializeComponent();
			pnlInsertarArista->Hide();
		}

	protected:
		~VentanaInsertar()
		{
			delete grf;
			delete dri;
			if (components)
			{
				delete components;
			}
		}
	private: DataGridView^ dtgvMatAdy;
	private: Digrafica<int>* dri;
	private: Grafica<int>* grf;
	private: int* nClicks = new int;
	private: System::Windows::Forms::ComboBox^ cbxNumVertices;

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
	private: System::Windows::Forms::Label^ lblNumAristas;

	private: System::Windows::Forms::TextBox^ txbNumAristas;
	private: System::Windows::Forms::Label^ lblNumVertices;
	private: System::Windows::Forms::CheckBox^ chxGrafoNoDirigido;
	private: System::Windows::Forms::CheckBox^ chxGrafoDirigido;
	private: System::Windows::Forms::Label^ lblNumAristaIngresar;
	private: System::Windows::Forms::Button^ btnSalir;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->cbxNumVertices = (gcnew System::Windows::Forms::ComboBox());
			this->pnlNAristas = (gcnew System::Windows::Forms::Panel());
			this->chxGrafoNoDirigido = (gcnew System::Windows::Forms::CheckBox());
			this->chxGrafoDirigido = (gcnew System::Windows::Forms::CheckBox());
			this->lblNumVertices = (gcnew System::Windows::Forms::Label());
			this->lblNumAristas = (gcnew System::Windows::Forms::Label());
			this->txbNumAristas = (gcnew System::Windows::Forms::TextBox());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->pnlInsertarArista = (gcnew System::Windows::Forms::Panel());
			this->lblNumAristaIngresar = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->lblAristas = (gcnew System::Windows::Forms::Label());
			this->lblCoste = (gcnew System::Windows::Forms::Label());
			this->lblVf = (gcnew System::Windows::Forms::Label());
			this->lblVi = (gcnew System::Windows::Forms::Label());
			this->btnInsertar = (gcnew System::Windows::Forms::Button());
			this->txtCoste = (gcnew System::Windows::Forms::TextBox());
			this->txbVf = (gcnew System::Windows::Forms::TextBox());
			this->txbVi = (gcnew System::Windows::Forms::TextBox());
			this->pnlNAristas->SuspendLayout();
			this->pnlInsertarArista->SuspendLayout();
			this->SuspendLayout();
			// 
			// cbxNumVertices
			// 
			this->cbxNumVertices->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(10) {
				L"1", L"2", L"3", L"4",
					L"5", L"6", L"7", L"8", L"9", L"10"
			});
			this->cbxNumVertices->FormattingEnabled = true;
			this->cbxNumVertices->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9"
			});
			this->cbxNumVertices->Location = System::Drawing::Point(17, 77);
			this->cbxNumVertices->Name = L"cbxNumVertices";
			this->cbxNumVertices->Size = System::Drawing::Size(121, 24);
			this->cbxNumVertices->TabIndex = 0;
			this->cbxNumVertices->SelectedIndex = 0;
			// 
			// pnlNAristas
			// 
			this->pnlNAristas->Controls->Add(this->chxGrafoNoDirigido);
			this->pnlNAristas->Controls->Add(this->btnSalir);
			this->pnlNAristas->Controls->Add(this->chxGrafoDirigido);
			this->pnlNAristas->Controls->Add(this->lblNumVertices);
			this->pnlNAristas->Controls->Add(this->lblNumAristas);
			this->pnlNAristas->Controls->Add(this->txbNumAristas);
			this->pnlNAristas->Controls->Add(this->btnAceptar);
			this->pnlNAristas->Controls->Add(this->cbxNumVertices);
			this->pnlNAristas->Location = System::Drawing::Point(12, 12);
			this->pnlNAristas->Name = L"pnlNAristas";
			this->pnlNAristas->Size = System::Drawing::Size(387, 202);
			this->pnlNAristas->TabIndex = 1;
			// 
			// chxGrafoNoDirigido
			// 
			this->chxGrafoNoDirigido->AutoSize = true;
			this->chxGrafoNoDirigido->Location = System::Drawing::Point(229, 24);
			this->chxGrafoNoDirigido->Name = L"chxGrafoNoDirigido";
			this->chxGrafoNoDirigido->Size = System::Drawing::Size(138, 21);
			this->chxGrafoNoDirigido->TabIndex = 6;
			this->chxGrafoNoDirigido->Text = L"Grafo no Dirigido";
			this->chxGrafoNoDirigido->UseVisualStyleBackColor = true;
			this->chxGrafoNoDirigido->CheckedChanged += gcnew System::EventHandler(this, &VentanaInsertar::chxGrafoNoDirigido_CheckedChanged);
			// 
			// chxGrafoDirigido
			// 
			this->chxGrafoDirigido->AutoSize = true;
			this->chxGrafoDirigido->Location = System::Drawing::Point(17, 24);
			this->chxGrafoDirigido->Name = L"chxGrafoDirigido";
			this->chxGrafoDirigido->Size = System::Drawing::Size(118, 21);
			this->chxGrafoDirigido->TabIndex = 5;
			this->chxGrafoDirigido->Text = L"Grafo Dirigido";
			this->chxGrafoDirigido->UseVisualStyleBackColor = true;
			this->chxGrafoDirigido->CheckedChanged += gcnew System::EventHandler(this, &VentanaInsertar::chxGrafoDirigido_CheckedChanged);
			this->chxGrafoDirigido->Checked = true;
			// 
			// lblNumVertices
			// 
			this->lblNumVertices->AutoSize = true;
			this->lblNumVertices->Location = System::Drawing::Point(14, 109);
			this->lblNumVertices->Name = L"lblNumVertices";
			this->lblNumVertices->Size = System::Drawing::Size(133, 17);
			this->lblNumVertices->TabIndex = 4;
			this->lblNumVertices->Text = L"Numero de Vertices";
			// 
			// lblNumAristas
			// 
			this->lblNumAristas->AutoSize = true;
			this->lblNumAristas->Location = System::Drawing::Point(226, 109);
			this->lblNumAristas->Name = L"lblNumAristas";
			this->lblNumAristas->Size = System::Drawing::Size(125, 17);
			this->lblNumAristas->TabIndex = 3;
			this->lblNumAristas->Text = L"Numero de Aristas";
			// 
			// txbNumAristas
			// 
			this->txbNumAristas->Location = System::Drawing::Point(229, 79);
			this->txbNumAristas->Name = L"txbNumAristas";
			this->txbNumAristas->Size = System::Drawing::Size(100, 22);
			this->txbNumAristas->TabIndex = 2;
			this->txbNumAristas->Text = "1";
			// 
			// btnAceptar
			// 
			this->btnAceptar->Location = System::Drawing::Point(76, 158);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(75, 23);
			this->btnAceptar->TabIndex = 1;
			this->btnAceptar->Text = L"Aceptar";
			this->btnAceptar->UseVisualStyleBackColor = true;
			this->btnAceptar->Click += gcnew System::EventHandler(this, &VentanaInsertar::btnAceptar_Click);
			// 
			// pnlInsertarArista
			// 
			this->pnlInsertarArista->Controls->Add(this->lblNumAristaIngresar);
			this->pnlInsertarArista->Controls->Add(this->lblAristas);
			this->pnlInsertarArista->Controls->Add(this->lblCoste);
			this->pnlInsertarArista->Controls->Add(this->lblVf);
			this->pnlInsertarArista->Controls->Add(this->lblVi);
			this->pnlInsertarArista->Controls->Add(this->btnInsertar);
			this->pnlInsertarArista->Controls->Add(this->txtCoste);
			this->pnlInsertarArista->Controls->Add(this->txbVf);
			this->pnlInsertarArista->Controls->Add(this->txbVi);
			this->pnlInsertarArista->Location = System::Drawing::Point(13, 231);
			this->pnlInsertarArista->Name = L"pnlInsertarArista";
			this->pnlInsertarArista->Size = System::Drawing::Size(386, 252);
			this->pnlInsertarArista->TabIndex = 2;
			// 
			// lblNumAristaIngresar
			// 
			this->lblNumAristaIngresar->AutoSize = true;
			this->lblNumAristaIngresar->Location = System::Drawing::Point(57, 18);
			this->lblNumAristaIngresar->Name = L"lblNumAristaIngresar";
			this->lblNumAristaIngresar->Size = System::Drawing::Size(197, 17);
			this->lblNumAristaIngresar->TabIndex = 9;
			this->lblNumAristaIngresar->Text = L"Numero de Arsitas a Ingresar:";
			// 
			// btnSalir
			// 
			this->btnSalir->Location = System::Drawing::Point(214, 158);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(75, 23);
			this->btnSalir->TabIndex = 8;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &VentanaInsertar::btnSalir_Click);
			// 
			// lblAristas
			// 
			this->lblAristas->AutoSize = true;
			this->lblAristas->Location = System::Drawing::Point(273, 18);
			this->lblAristas->Name = L"lblAristas";
			this->lblAristas->Size = System::Drawing::Size(13, 17);
			this->lblAristas->TabIndex = 7;
			this->lblAristas->Text = L"-";
			// 
			// lblCoste
			// 
			this->lblCoste->AutoSize = true;
			this->lblCoste->Location = System::Drawing::Point(132, 164);
			this->lblCoste->Name = L"lblCoste";
			this->lblCoste->Size = System::Drawing::Size(44, 17);
			this->lblCoste->TabIndex = 6;
			this->lblCoste->Text = L"Coste";
			// 
			// lblVf
			// 
			this->lblVf->AutoSize = true;
			this->lblVf->Location = System::Drawing::Point(225, 89);
			this->lblVf->Name = L"lblVf";
			this->lblVf->Size = System::Drawing::Size(96, 17);
			this->lblVf->TabIndex = 5;
			this->lblVf->Text = L"Arista Destino";
			// 
			// lblVi
			// 
			this->lblVi->AutoSize = true;
			this->lblVi->Location = System::Drawing::Point(36, 89);
			this->lblVi->Name = L"lblVi";
			this->lblVi->Size = System::Drawing::Size(91, 17);
			this->lblVi->TabIndex = 4;
			this->lblVi->Text = L"Arista Origen";
			// 
			// btnInsertar
			// 
			this->btnInsertar->Location = System::Drawing::Point(148, 203);
			this->btnInsertar->Name = L"btnInsertar";
			this->btnInsertar->Size = System::Drawing::Size(75, 23);
			this->btnInsertar->TabIndex = 3;
			this->btnInsertar->Text = L"Insertar";
			this->btnInsertar->UseVisualStyleBackColor = true;
			this->btnInsertar->Click += gcnew System::EventHandler(this, &VentanaInsertar::btnInsertar_Click);
			// 
			// txtCoste
			// 
			this->txtCoste->Location = System::Drawing::Point(135, 133);
			this->txtCoste->Name = L"txtCoste";
			this->txtCoste->Size = System::Drawing::Size(100, 22);
			this->txtCoste->TabIndex = 2;
			this->txtCoste->Text = "1";
			// 
			// txbVf
			// 
			this->txbVf->Location = System::Drawing::Point(228, 57);
			this->txbVf->Name = L"txbVf";
			this->txbVf->Size = System::Drawing::Size(100, 22);
			this->txbVf->TabIndex = 1;
			this->txbVf->Text = "1";
			// 
			// txbVi
			// 
			this->txbVi->Location = System::Drawing::Point(39, 57);
			this->txbVi->Name = L"txbVi";
			this->txbVi->Size = System::Drawing::Size(100, 22);
			this->txbVi->TabIndex = 0;
			this->txbVi->Text = "1";
			// 
			// VentanaInsertar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(411, 495);
			this->ControlBox = false;
			this->Controls->Add(this->pnlInsertarArista);
			this->Controls->Add(this->pnlNAristas);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"VentanaInsertar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Insertar";
			this->pnlNAristas->ResumeLayout(false);
			this->pnlNAristas->PerformLayout();
			this->pnlInsertarArista->ResumeLayout(false);
			this->pnlInsertarArista->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnAceptar_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlInsertarArista->Show();
		lblAristas->Text = txbNumAristas->Text;
		*nClicks = convertToInt(txbNumAristas->Text);
		if (chxGrafoDirigido->Checked) {
			dri->setNumver(cbxNumVertices->SelectedIndex + 1);
			dri->iniciarVertices();
		}
		else {
			grf->setNumver(cbxNumVertices->SelectedIndex + 1);
			grf->iniciarVertices();
		}
		btnAceptar->Visible = false;
	}

	private: System::Void btnInsertar_Click(System::Object^ sender, System::EventArgs^ e) {   
		if (chxGrafoDirigido->Checked  && *nClicks > 0) {
			dri->insertarVertice(convertToInt(txbVi->Text), convertToInt(txbVf->Text), convertToInt(txtCoste->Text));
		}
		else {
			grf->insertarVertice(convertToInt(txbVi->Text), convertToInt(txbVf->Text), convertToInt(txtCoste->Text));
		}
		*nClicks = *nClicks - 1;
		if (*nClicks == 0) {
			cargarDatos();
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

private: System::Void chxGrafoDirigido_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	chxGrafoNoDirigido->Checked = false;
}
private: System::Void chxGrafoNoDirigido_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	chxGrafoDirigido->Checked = false;
}

public: bool getChxGrafoDirigido() {
	return chxGrafoDirigido->Checked;
}

public: void cargarDatos() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			if (getChxGrafoDirigido())
				dtgvMatAdy->Rows[i]->Cells[j]->Value = dri->getCoste(i, j);
			else
				dtgvMatAdy->Rows[i]->Cells[j]->Value = grf->getCoste(i, j);
	}
}
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Visible = false;
}
};
}
