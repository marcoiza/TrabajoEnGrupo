#pragma once

#include "VentanaInsertar.h"
#include "Recorrido.h"

#include <stdlib.h>

namespace Grafo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class VentanaGrafo : public System::Windows::Forms::Form
	{
	public:
		VentanaGrafo(void)
		{
			vInsertar = gcnew VentanaInsertar(dri, grf);
			InitializeComponent();
			dtgvMatAdy->Rows->Add();
			dtgvMatAdy->Rows->AddCopies(0, 8);
			dgvListaRecorrido->Rows->Add();
			dgvListaRecorrido->Rows->AddCopies(0, 8);
		}

	protected:
		~VentanaGrafo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: VentanaInsertar^ vInsertar;

	private: Digrafica<int>* dri = new Digrafica<int>;
	private: Grafica<int>* grf = new Grafica<int>;
	private: Recorridos<int>* rcd = new Recorridos<int>;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dtgvMatAdy;

	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txtBuscar;
	private: System::Windows::Forms::Button^ btnNuevoGrafo;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DataGridView^ dgvListaRecorrido;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column12;
	private: System::Windows::Forms::Button^ btnBuscarProfundidad;
	private: System::Windows::Forms::Button^ btnSalir;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dtgvMatAdy = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->btnNuevoGrafo = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dgvListaRecorrido = (gcnew System::Windows::Forms::DataGridView());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnBuscarProfundidad = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgvMatAdy))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvListaRecorrido))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dtgvMatAdy);
			this->panel1->Location = System::Drawing::Point(479, 57);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(471, 422);
			this->panel1->TabIndex = 0;
			// 
			// dtgvMatAdy
			// 
			this->dtgvMatAdy->AllowUserToAddRows = false;
			this->dtgvMatAdy->AllowUserToDeleteRows = false;
			this->dtgvMatAdy->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dtgvMatAdy->ColumnHeadersHeight = 30;
			this->dtgvMatAdy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dtgvMatAdy->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Column1, this->Column2,
					this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9
			});
			this->dtgvMatAdy->Cursor = System::Windows::Forms::Cursors::Default;
			this->dtgvMatAdy->Location = System::Drawing::Point(21, 15);
			this->dtgvMatAdy->Name = L"dtgvMatAdy";
			this->dtgvMatAdy->ReadOnly = true;
			this->dtgvMatAdy->RowHeadersWidth = 51;
			this->dtgvMatAdy->RowTemplate->Height = 30;
			this->dtgvMatAdy->Size = System::Drawing::Size(430, 372);
			this->dtgvMatAdy->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->Frozen = true;
			this->Column1->HeaderText = L"1";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 30;
			// 
			// Column2
			// 
			this->Column2->Frozen = true;
			this->Column2->HeaderText = L"2";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 30;
			// 
			// Column3
			// 
			this->Column3->Frozen = true;
			this->Column3->HeaderText = L"3";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 30;
			// 
			// Column4
			// 
			this->Column4->Frozen = true;
			this->Column4->HeaderText = L"4";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 30;
			// 
			// Column5
			// 
			this->Column5->Frozen = true;
			this->Column5->HeaderText = L"5";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 30;
			// 
			// Column6
			// 
			this->Column6->Frozen = true;
			this->Column6->HeaderText = L"6";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 30;
			// 
			// Column7
			// 
			this->Column7->Frozen = true;
			this->Column7->HeaderText = L"7";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 30;
			// 
			// Column8
			// 
			this->Column8->Frozen = true;
			this->Column8->HeaderText = L"8";
			this->Column8->MinimumWidth = 6;
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Width = 30;
			// 
			// Column9
			// 
			this->Column9->Frozen = true;
			this->Column9->HeaderText = L"9";
			this->Column9->MinimumWidth = 6;
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			this->Column9->Width = 30;
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(134, 12);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(144, 23);
			this->btnBuscar->TabIndex = 1;
			this->btnBuscar->Text = L"Buscar en Amplitud";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &VentanaGrafo::btnBuscar_Click);
			// 
			// txtBuscar
			// 
			this->txtBuscar->Location = System::Drawing::Point(13, 12);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(100, 22);
			this->txtBuscar->TabIndex = 2;
			// 
			// btnNuevoGrafo
			// 
			this->btnNuevoGrafo->Location = System::Drawing::Point(455, 12);
			this->btnNuevoGrafo->Name = L"btnNuevoGrafo";
			this->btnNuevoGrafo->Size = System::Drawing::Size(103, 23);
			this->btnNuevoGrafo->TabIndex = 3;
			this->btnNuevoGrafo->Text = L"Nuevo Grafo";
			this->btnNuevoGrafo->UseVisualStyleBackColor = true;
			this->btnNuevoGrafo->Click += gcnew System::EventHandler(this, &VentanaGrafo::btnNuevoGrafo_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dgvListaRecorrido);
			this->panel2->Location = System::Drawing::Point(52, 57);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(313, 407);
			this->panel2->TabIndex = 4;
			// 
			// dgvListaRecorrido
			// 
			this->dgvListaRecorrido->AllowUserToAddRows = false;
			this->dgvListaRecorrido->AllowUserToDeleteRows = false;
			this->dgvListaRecorrido->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dgvListaRecorrido->ColumnHeadersHeight = 30;
			this->dgvListaRecorrido->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dgvListaRecorrido->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column10,
					this->Column11, this->Column12
			});
			this->dgvListaRecorrido->Location = System::Drawing::Point(19, 15);
			this->dgvListaRecorrido->Name = L"dgvListaRecorrido";
			this->dgvListaRecorrido->RowHeadersWidth = 51;
			this->dgvListaRecorrido->RowTemplate->Height = 30;
			this->dgvListaRecorrido->Size = System::Drawing::Size(272, 372);
			this->dgvListaRecorrido->TabIndex = 0;
			this->dgvListaRecorrido->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &VentanaGrafo::dataGridView2_CellContentClick);
			// 
			// Column10
			// 
			this->Column10->Frozen = true;
			this->Column10->HeaderText = L"Origen";
			this->Column10->MinimumWidth = 6;
			this->Column10->Name = L"Column10";
			this->Column10->ReadOnly = true;
			this->Column10->Width = 50;
			// 
			// Column11
			// 
			this->Column11->Frozen = true;
			this->Column11->HeaderText = L"Destino";
			this->Column11->MinimumWidth = 6;
			this->Column11->Name = L"Column11";
			this->Column11->ReadOnly = true;
			this->Column11->Width = 50;
			// 
			// Column12
			// 
			this->Column12->Frozen = true;
			this->Column12->HeaderText = L"Visitado";
			this->Column12->MinimumWidth = 6;
			this->Column12->Name = L"Column12";
			this->Column12->ReadOnly = true;
			this->Column12->Width = 50;
			// 
			// btnBuscarProfundidad
			// 
			this->btnBuscarProfundidad->Location = System::Drawing::Point(296, 12);
			this->btnBuscarProfundidad->Name = L"btnBuscarProfundidad";
			this->btnBuscarProfundidad->Size = System::Drawing::Size(143, 23);
			this->btnBuscarProfundidad->TabIndex = 5;
			this->btnBuscarProfundidad->Text = L"Buscar en Amplitud";
			this->btnBuscarProfundidad->UseVisualStyleBackColor = true;
			this->btnBuscarProfundidad->Click += gcnew System::EventHandler(this, &VentanaGrafo::btnBuscarProfundidad_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Location = System::Drawing::Point(577, 12);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(75, 23);
			this->btnSalir->TabIndex = 6;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &VentanaGrafo::btnSalir_Click);
			// 
			// VentanaGrafo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 553);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnBuscarProfundidad);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->btnNuevoGrafo);
			this->Controls->Add(this->txtBuscar);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->panel1);
			this->Name = L"VentanaGrafo";
			this->Text = L"VentanaGrafo";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgvMatAdy))->EndInit();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvListaRecorrido))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnNuevoGrafo_Click(System::Object^ sender, System::EventArgs^ e) {
		vInsertar = gcnew VentanaInsertar(dri, grf);
		vInsertar->Visible = true;
	}

private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
	Lista<Vertice<int>> vrts;
	if(vInsertar->getChxGrafoDirigido())
		vrts = rcd->buscarAmplitud(1, dri->getMatAdy(), dri->getVertices(), dri->getNumver());
	else 
		vrts = rcd->buscarAmplitud(1, grf->getMatAdy(), grf->getVertices(), grf->getNumver());
	Vertice<int> vrt;
	for (int i = 0; i < 9; i++) {
		vrt = vrts.buscar(i + 1)->getInfo();
		dgvListaRecorrido->Rows[i]->Cells[0]->Value = vrt.getDato();
		dgvListaRecorrido->Rows[i]->Cells[1]->Value = vrt.getPariente();
		dgvListaRecorrido->Rows[i]->Cells[2]->Value = vrt.getVisitado();
		for (int j = 0; j < 9; j++)
			if (vInsertar->getChxGrafoDirigido())
				dtgvMatAdy->Rows[i]->Cells[j]->Value = dri->getCoste(i, j);
			else
				dtgvMatAdy->Rows[i]->Cells[j]->Value = grf->getCoste(i, j);
	}
}
private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void btnBuscarProfundidad_Click(System::Object^ sender, System::EventArgs^ e) {
	Lista<Vertice<int>> vrts;
	Vertice<int> vrt;
	if (vInsertar->getChxGrafoDirigido())
		vrts = rcd->buscarProfundidad(1, dri->getMatAdy(), dri->getVertices(), dri->getNumver());
	else
		vrts = rcd->buscarProfundidad(1, grf->getMatAdy(), grf->getVertices(), grf->getNumver());
	for (int i = 0; i < 9; i++) {
		vrt = vrts.buscar(i + 1)->getInfo();
		dgvListaRecorrido->Rows[i]->Cells[0]->Value = vrt.getDato();
		dgvListaRecorrido->Rows[i]->Cells[1]->Value = vrt.getPariente();
		dgvListaRecorrido->Rows[i]->Cells[2]->Value = vrt.getVisitado();
		for (int j = 0; j < 9; j++)
			if (vInsertar->getChxGrafoDirigido())
				dtgvMatAdy->Rows[i]->Cells[j]->Value = dri->getCoste(i, j);
			else
				dtgvMatAdy->Rows[i]->Cells[j]->Value = grf->getCoste(i, j);
	}
}
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	exit(0);
}
};
}
