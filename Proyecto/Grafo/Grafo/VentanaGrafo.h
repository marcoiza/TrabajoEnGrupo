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
			vInsertar = gcnew VentanaInsertar(dri, grf, dtgvMatAdy);
			InitializeComponent();
			dtgvMatAdy->Rows->Add();
			dtgvMatAdy->Rows->AddCopies(0, 8);
			dgvListaRecorrido->Rows->Add();
			dgvListaRecorrido->Rows->AddCopies(0, 8);
			cargarDatosInciales();
			cargarDatosIncialesTree();
			*nClicks = 0;
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

	private: Lista<Vertice<int>>* vrts = new Lista<Vertice<int>>;
	private: Digrafica<int>* dri = new Digrafica<int>;
	private: Grafica<int>* grf = new Grafica<int>;
	private: Recorridos<int>* rcd = new Recorridos<int>;
	private: int* nClicks = new int;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dtgvMatAdy;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txbBuscar;
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
	private: System::Windows::Forms::Label^ lblListaRecorridos;
	private: System::Windows::Forms::Label^ lblMatrizCoste;
	private: System::Windows::Forms::Label^ lblAyuda;
	private: System::Windows::Forms::RadioButton^ RBLista;
	private: System::Windows::Forms::RadioButton^ RBMat;
	private: System::Windows::Forms::Panel^ panelLista;

	private: System::Windows::Forms::TreeView^ treeLista;






	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			this->panelLista = (gcnew System::Windows::Forms::Panel());
			this->treeLista = (gcnew System::Windows::Forms::TreeView());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txbBuscar = (gcnew System::Windows::Forms::TextBox());
			this->btnNuevoGrafo = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dgvListaRecorrido = (gcnew System::Windows::Forms::DataGridView());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnBuscarProfundidad = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->lblListaRecorridos = (gcnew System::Windows::Forms::Label());
			this->lblMatrizCoste = (gcnew System::Windows::Forms::Label());
			this->lblAyuda = (gcnew System::Windows::Forms::Label());
			this->RBLista = (gcnew System::Windows::Forms::RadioButton());
			this->RBMat = (gcnew System::Windows::Forms::RadioButton());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgvMatAdy))->BeginInit();
			this->panelLista->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvListaRecorrido))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dtgvMatAdy);
			this->panel1->Location = System::Drawing::Point(469, 92);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(471, 407);
			this->panel1->TabIndex = 0;
			// 
			// dtgvMatAdy
			// 
			this->dtgvMatAdy->AllowUserToAddRows = false;
			this->dtgvMatAdy->AllowUserToDeleteRows = false;
			this->dtgvMatAdy->Anchor = System::Windows::Forms::AnchorStyles::None;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dtgvMatAdy->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
			this->dtgvMatAdy->ColumnHeadersHeight = 30;
			this->dtgvMatAdy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dtgvMatAdy->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Column1, this->Column2,
					this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9
			});
			this->dtgvMatAdy->Cursor = System::Windows::Forms::Cursors::Default;
			this->dtgvMatAdy->Location = System::Drawing::Point(21, 15);
			this->dtgvMatAdy->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dtgvMatAdy->Name = L"dtgvMatAdy";
			this->dtgvMatAdy->ReadOnly = true;
			this->dtgvMatAdy->RowHeadersWidth = 51;
			this->dtgvMatAdy->RowTemplate->Height = 30;
			this->dtgvMatAdy->Size = System::Drawing::Size(429, 372);
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
			// panelLista
			// 
			this->panelLista->Controls->Add(this->treeLista);
			this->panelLista->Location = System::Drawing::Point(445, 92);
			this->panelLista->Margin = System::Windows::Forms::Padding(4);
			this->panelLista->Name = L"panelLista";
			this->panelLista->Size = System::Drawing::Size(273, 354);
			this->panelLista->TabIndex = 12;
			this->panelLista->Visible = false;
			// 
			// treeLista
			// 
			this->treeLista->Location = System::Drawing::Point(47, 4);
			this->treeLista->Margin = System::Windows::Forms::Padding(4);
			this->treeLista->Name = L"treeLista";
			this->treeLista->Size = System::Drawing::Size(160, 285);
			this->treeLista->TabIndex = 0;
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(133, 12);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(156, 23);
			this->btnBuscar->TabIndex = 1;
			this->btnBuscar->Text = L"Buscar en Amplitud";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &VentanaGrafo::btnBuscar_Click);
			// 
			// txbBuscar
			// 
			this->txbBuscar->Location = System::Drawing::Point(13, 12);
			this->txbBuscar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txbBuscar->Name = L"txbBuscar";
			this->txbBuscar->Size = System::Drawing::Size(100, 22);
			this->txbBuscar->TabIndex = 2;
			// 
			// btnNuevoGrafo
			// 
			this->btnNuevoGrafo->Location = System::Drawing::Point(500, 12);
			this->btnNuevoGrafo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->panel2->Location = System::Drawing::Point(45, 92);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(313, 407);
			this->panel2->TabIndex = 4;
			// 
			// dgvListaRecorrido
			// 
			this->dgvListaRecorrido->AllowUserToAddRows = false;
			this->dgvListaRecorrido->AllowUserToDeleteRows = false;
			this->dgvListaRecorrido->Anchor = System::Windows::Forms::AnchorStyles::None;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvListaRecorrido->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dgvListaRecorrido->ColumnHeadersHeight = 30;
			this->dgvListaRecorrido->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dgvListaRecorrido->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column10,
					this->Column11, this->Column12
			});
			this->dgvListaRecorrido->Location = System::Drawing::Point(19, 15);
			this->dgvListaRecorrido->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgvListaRecorrido->Name = L"dgvListaRecorrido";
			this->dgvListaRecorrido->RowHeadersWidth = 51;
			this->dgvListaRecorrido->RowTemplate->Height = 30;
			this->dgvListaRecorrido->Size = System::Drawing::Size(272, 372);
			this->dgvListaRecorrido->TabIndex = 0;
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
			this->btnBuscarProfundidad->Location = System::Drawing::Point(309, 12);
			this->btnBuscarProfundidad->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnBuscarProfundidad->Name = L"btnBuscarProfundidad";
			this->btnBuscarProfundidad->Size = System::Drawing::Size(171, 23);
			this->btnBuscarProfundidad->TabIndex = 5;
			this->btnBuscarProfundidad->Text = L"Buscar en Profundidad";
			this->btnBuscarProfundidad->UseVisualStyleBackColor = true;
			this->btnBuscarProfundidad->Click += gcnew System::EventHandler(this, &VentanaGrafo::btnBuscarProfundidad_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Location = System::Drawing::Point(623, 12);
			this->btnSalir->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(75, 23);
			this->btnSalir->TabIndex = 6;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &VentanaGrafo::btnSalir_Click);
			// 
			// lblListaRecorridos
			// 
			this->lblListaRecorridos->AutoSize = true;
			this->lblListaRecorridos->Location = System::Drawing::Point(61, 71);
			this->lblListaRecorridos->Name = L"lblListaRecorridos";
			this->lblListaRecorridos->Size = System::Drawing::Size(174, 17);
			this->lblListaRecorridos->TabIndex = 7;
			this->lblListaRecorridos->Text = L"Lista de Vertices Visitados";
			// 
			// lblMatrizCoste
			// 
			this->lblMatrizCoste->AutoSize = true;
			this->lblMatrizCoste->Location = System::Drawing::Point(488, 71);
			this->lblMatrizCoste->Name = L"lblMatrizCoste";
			this->lblMatrizCoste->Size = System::Drawing::Size(215, 17);
			this->lblMatrizCoste->TabIndex = 8;
			this->lblMatrizCoste->Text = L"Matriz de Adyacencia Etiquetada";
			// 
			// lblAyuda
			// 
			this->lblAyuda->AutoSize = true;
			this->lblAyuda->Location = System::Drawing::Point(61, 502);
			this->lblAyuda->Name = L"lblAyuda";
			this->lblAyuda->Size = System::Drawing::Size(191, 17);
			this->lblAyuda->TabIndex = 9;
			this->lblAyuda->Text = L"El 0 representa un valor nulo";
			// 
			// RBLista
			// 
			this->RBLista->AutoSize = true;
			this->RBLista->Location = System::Drawing::Point(764, 16);
			this->RBLista->Margin = System::Windows::Forms::Padding(4);
			this->RBLista->Name = L"RBLista";
			this->RBLista->Size = System::Drawing::Size(155, 21);
			this->RBLista->TabIndex = 10;
			this->RBLista->TabStop = true;
			this->RBLista->Text = L"Lista de adyacencia";
			this->RBLista->UseVisualStyleBackColor = true;
			this->RBLista->CheckedChanged += gcnew System::EventHandler(this, &VentanaGrafo::RBLista_CheckedChanged);
			// 
			// RBMat
			// 
			this->RBMat->AutoSize = true;
			this->RBMat->Location = System::Drawing::Point(764, 46);
			this->RBMat->Margin = System::Windows::Forms::Padding(4);
			this->RBMat->Name = L"RBMat";
			this->RBMat->Size = System::Drawing::Size(163, 21);
			this->RBMat->TabIndex = 11;
			this->RBMat->TabStop = true;
			this->RBMat->Text = L"Matriz de adyacencia";
			this->RBMat->UseVisualStyleBackColor = true;
			this->RBMat->CheckedChanged += gcnew System::EventHandler(this, &VentanaGrafo::RDMat_CheckedChanged);
			// 
			// VentanaGrafo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(979, 553);
			this->Controls->Add(this->panelLista);
			this->Controls->Add(this->RBMat);
			this->Controls->Add(this->RBLista);
			this->Controls->Add(this->lblAyuda);
			this->Controls->Add(this->lblMatrizCoste);
			this->Controls->Add(this->lblListaRecorridos);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnBuscarProfundidad);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->btnNuevoGrafo);
			this->Controls->Add(this->txbBuscar);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"VentanaGrafo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VentanaGrafo";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgvMatAdy))->EndInit();
			this->panelLista->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvListaRecorrido))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnNuevoGrafo_Click(System::Object^ sender, System::EventArgs^ e) {
		rcd->iniciarListaVertice(*vrts, 9);
		dri->~Digrafica();
		grf->~Grafica();
		dri = new Digrafica<int>;
		grf = new Grafica<int>;
		vInsertar = gcnew VentanaInsertar(dri, grf, dtgvMatAdy);
		vInsertar->Visible = true;
	}

private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (IngresoDeDatos::validarTXB(txbBuscar->Text)) {
		if (vInsertar->getChxGrafoDirigido())
			*vrts = rcd->buscarAmplitud(IngresoDeDatos::convertToInt(txbBuscar->Text), 
				dri->getMatAdy(), dri->getVertices(), dri->getNumver());
		else
			*vrts = rcd->buscarAmplitud(IngresoDeDatos::convertToInt(txbBuscar->Text), 
				grf->getMatAdy(), grf->getVertices(), grf->getNumver());
		cargarDatos();
	}
}

private: System::Void btnBuscarProfundidad_Click(System::Object^ sender, System::EventArgs^ e) {
	if (IngresoDeDatos::validarTXB(txbBuscar->Text)) {
		if (vInsertar->getChxGrafoDirigido())
			*vrts = rcd->buscarProfundidad(IngresoDeDatos::convertToInt(txbBuscar->Text),
				dri->getMatAdy(), dri->getVertices(), dri->getNumver());
		else
			*vrts = rcd->buscarProfundidad(IngresoDeDatos::convertToInt(txbBuscar->Text), 
				grf->getMatAdy(), grf->getVertices(), grf->getNumver());
		cargarDatos();
	}
}

private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

public: void cargarDatos() {
	Vertice<int> vrt;
	for (int i = 0; i < 9; i++) {
		vrt = vrts->buscar(i + 1)->getInfo();
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

public: void cargarDatosInciales() {
	for (int i = 0; i < 9; i++) {
		dgvListaRecorrido->Rows[i]->Cells[0]->Value = i + 1;
		dgvListaRecorrido->Rows[i]->Cells[1]->Value = 0;
		dgvListaRecorrido->Rows[i]->Cells[2]->Value = false;
		for (int j = 0; j < 9; j++)
			dtgvMatAdy->Rows[i]->Cells[j]->Value = 0;
	}
}

public: void cargarDatosIncialesTree() {
	Object^ ingreso;
	for (int i = 1; i < 10; i++) {
		ingreso = i;
		treeLista->Nodes->Add(ingreso->ToString());
	}
}


private: System::Void RBLista_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (RBLista->Checked) {
		*nClicks = *nClicks + 1;
		if (*nClicks == 1) {
			cargarListaAdy();
		}
		panel1->Visible = false;
		panelLista->Visible = true;
		lblMatrizCoste->Text = "Lista de adyacencia";
	}
}

private: System::Void RDMat_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (RBMat->Checked == true) {
		panelLista->Visible = false;
		panel1->Visible = true;
		lblMatrizCoste->Text = "Matriz de adyacencia etiquetada";
	}
}

public: void cargarListaAdy() {
	Object^ ingreso;
	Lista<int> listaTree;
	for (int i = 0; i < 9; i++) {
		if (vInsertar->getChxGrafoDirigido())
			listaTree = rcd->verticesAdyacentes(i, dri->getMatAdy(), dri->getVertices(), 9);
		else
			listaTree = rcd->verticesAdyacentes(i,grf->getMatAdy(),grf->getVertices(),9);
		for (int j = 0; !listaTree.listaVacia() ; j++) {
			ingreso = listaTree.eliminarPrimero();
			treeLista->Nodes[i]->Nodes->Add(ingreso->ToString());
		}
	}
}
};
}
