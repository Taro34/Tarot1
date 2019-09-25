// SaisiePoint.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "Tarot.h"
#include "SaisiePoint.h"
#include "afxdialogex.h"


// Boîte de dialogue SaisiePoint

IMPLEMENT_DYNAMIC(SaisiePoint, CDialogEx)

SaisiePoint::SaisiePoint(CPartie *laPartie, CJoueur *lesJoueurs, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SaisiePoint, pParent)
	, points(0)
	, nbBouts(0)
{
	this->laPartie = laPartie;
}

SaisiePoint::~SaisiePoint()
{
}

void SaisiePoint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_point, points);
	DDX_Text(pDX, IDC_nbBout, nbBouts);
	DDX_Control(pDX, IDC_comboPetit, mComboPetit);
	DDX_Control(pDX, IDC_comboPoignee, mComboPoignee);
}


BEGIN_MESSAGE_MAP(SaisiePoint, CDialogEx)
	ON_BN_CLICKED(IDOK, &SaisiePoint::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_comboPetit, &SaisiePoint::OnCbnSelchangecombopetit)
	ON_CBN_SELCHANGE(IDC_comboPoignee, &SaisiePoint::OnCbnSelchangecombopoignee)
END_MESSAGE_MAP()


// Gestionnaires de messages de SaisiePoint

void SaisiePoint::envoyerValeur()
{
	Poignee typePoignee;
	Camp campPetitAuBout;
	switch (testPetit)
	{
	case 0:
		campPetitAuBout = personne;
		break;
	case 1:
		campPetitAuBout = preneur;
		break;
	case 2:
		campPetitAuBout = defenseur;
		break;
	}
	laPartie->setCampPetit(campPetitAuBout);
	switch (testPoignee)
	{
	case 0:
		typePoignee = Sans;
		break;
	case 1:
		typePoignee = Simple;
		break;
	case 2:
		typePoignee = Double;
		break;
	case 3:
		typePoignee = Triple;
		break;
	}
	laPartie->setPoingnee(typePoignee);
	laPartie->setPoint(points, nbBouts);
	laPartie->calculerDonne();

}

void SaisiePoint::OnCbnSelchangecombopetit()
{
	testPetit = mComboPetit.GetCurSel();
}


void SaisiePoint::OnCbnSelchangecombopoignee()
{
	testPoignee = mComboPoignee.GetCurSel();
}

void SaisiePoint::OnBnClickedOk()
{
	UpdateData(true);
	envoyerValeur();
	CDialogEx::OnOK();
}