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

SaisiePreneur::SaisiePreneur(CPartie *laPartie,CJoueur *lesJoueurs, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SaisiePreneur, pParent)
{
	this->laPartie = laPartie;
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
	ON_BN_CLICKED(IDC_BUTTON1, &SaisiePreneur::OnBnClickedButton1)
END_MESSAGE_MAP()


// Gestionnaires de messages de SaisiePreneur


void SaisiePreneur::OnCbnSelchangeCombo1()
{
	testJoueur = mPreneur.GetCurSel();
}


void SaisiePreneur::OnCbnSelchangeCombo2()
{
	testContrat= mContrat.GetCurSel();
}


void SaisiePreneur::OnBnClickedButton1()
{
	UpdateData(false);
	laPartie->setPreneur(lesJoueurs[testJoueur]);
	switch(testContrat)
	{
	case passe:
		laPartie->setTypeContrat(passe);
		break;
	case prise:
		laPartie->setTypeContrat(prise);
		break;
	case garde:
		laPartie->setTypeContrat(garde);
		break;
	case gardeSans:
		laPartie->setTypeContrat(gardeSans);
		break;
	case GardeContre:
		laPartie->setTypeContrat(GardeContre);
		break;
	}
	SaisiePoint point(laPartie, lesJoueurs[4], this);
	point.DoModal();
}
