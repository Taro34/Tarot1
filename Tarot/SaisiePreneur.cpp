// SaisiePreneur.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "Tarot.h"
#include "SaisiePreneur.h"
#include "CDonne.h"
#include "CPartie.h"
#include "afxdialogex.h"



// Boîte de dialogue SaisiePreneur

IMPLEMENT_DYNAMIC(SaisiePreneur, CDialogEx)

SaisiePreneur::SaisiePreneur(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SaisiePreneur, pParent)
{

}

SaisiePreneur::~SaisiePreneur()
{
}

void SaisiePreneur::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, mContrat);
	DDX_Control(pDX, IDC_COMBO1, mPreneur);
}


BEGIN_MESSAGE_MAP(SaisiePreneur, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &SaisiePreneur::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &SaisiePreneur::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// Gestionnaires de messages de SaisiePreneur


void SaisiePreneur::OnCbnSelchangeCombo1()
{
	int index = 0;
	index = mPreneur.GetCurSel();
	//laPartie->setPreneur(lesJoueurs[index]);
}


void SaisiePreneur::OnCbnSelchangeCombo2()
{
	int index = -1;
	index = mContrat.GetCurSel();
	switch (index)
	{
	case passe:
		break;
	case prise:
		break;
	case garde:
		break;
	case gardeSans:
		break;
	case GardeContre:
		break;
	default:
		break;
	}
}
