// SaisieJoueurs.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "Tarot.h"
#include "SaisieJoueurs.h"
#include "afxdialogex.h"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "CPartie.h"


// Boîte de dialogue SaisieJoueurs

IMPLEMENT_DYNAMIC(SaisieJoueurs, CDialogEx)

SaisieJoueurs::SaisieJoueurs(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SaisieJoueurs, pParent)
	
	, joueur1(_T(""))
	, joueur2(_T(""))
	, joueur3(_T(""))
	, joueur4(_T(""))
{

}

SaisieJoueurs::~SaisieJoueurs()
{
}

void SaisieJoueurs::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, mDonneur1);
	DDX_Control(pDX, IDC_COMBO2, mDonneur2);
	DDX_Control(pDX, IDC_COMBO3, mDonneur3);
	DDX_Control(pDX, IDC_COMBO4, mDonneur4);
	DDX_Text(pDX, IDC_EDIT3, joueur1);
	DDX_Text(pDX, IDC_EDIT4, joueur2);
	DDX_Text(pDX, IDC_EDIT5, joueur3);
	DDX_Text(pDX, IDC_EDIT6, joueur4);
}


BEGIN_MESSAGE_MAP(SaisieJoueurs, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &SaisieJoueurs::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &SaisieJoueurs::OnEnChangeEdit4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &SaisieJoueurs::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &SaisieJoueurs::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &SaisieJoueurs::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &SaisieJoueurs::OnCbnSelchangeCombo4)
	ON_BN_CLICKED(IDC_BUTTON1, &SaisieJoueurs::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &SaisieJoueurs::OnBnClickedOk)
END_MESSAGE_MAP()


// Gestionnaires de messages de SaisieJoueurs


void SaisieJoueurs::OnEnChangeEdit3()
{
	// TODO:  S'il s'agit d'un contrôle RICHEDIT, le contrôle ne
	// envoyez cette notification sauf si vous substituez CDialogEx::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajouté au masque grâce à l'opérateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieJoueurs::OnEnChangeEdit4()
{
	// TODO:  S'il s'agit d'un contrôle RICHEDIT, le contrôle ne
	// envoyez cette notification sauf si vous substituez CDialogEx::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajouté au masque grâce à l'opérateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieJoueurs::OnCbnSelchangeCombo1()
{
	testJoueur1 = mDonneur1.GetCurSel();
}


void SaisieJoueurs::creerPartie()
{
	laPartie = new CPartie(lesJoueurs);
}

void SaisieJoueurs::OnCbnSelchangeCombo2()
{
	testJoueur2 = mDonneur2.GetCurSel();
}


void SaisieJoueurs::OnCbnSelchangeCombo3()
{
	testJoueur3= mDonneur3.GetCurSel();
}


void SaisieJoueurs::OnCbnSelchangeCombo4()
{
	testJoueur4 = mDonneur4.GetCurSel();
}

void SaisieJoueurs::OnBnClickedButton1()
{
	
	UpdateData(true);
	mDonneur1.ResetContent();
	mDonneur2.ResetContent();
	mDonneur3.ResetContent();
	mDonneur4.ResetContent();
	UpdateData(false);
	mDonneur1.AddString(joueur1);
	mDonneur1.AddString(joueur2);
	mDonneur1.AddString(joueur3);
	mDonneur1.AddString(joueur4);
	UpdateData(false);
	mDonneur2.AddString(joueur1);
	mDonneur2.AddString(joueur2);
	mDonneur2.AddString(joueur3);
	mDonneur2.AddString(joueur4);
	UpdateData(false);
	mDonneur3.AddString(joueur1);
	mDonneur3.AddString(joueur2);
	mDonneur3.AddString(joueur3);
	mDonneur3.AddString(joueur4);
	UpdateData(false);
	mDonneur4.AddString(joueur1);
	mDonneur4.AddString(joueur2);
	mDonneur4.AddString(joueur3);
	mDonneur4.AddString(joueur4);
	UpdateData(false);
	creerPartie();

}


void SaisieJoueurs::OnBnClickedOk()
{
	switch (testJoueur1)
	{
	case 0:
		lesJoueurs[0] = new CJoueur(CStringA(joueur1).GetBuffer(), 0);
		break;
	case 1:
		lesJoueurs[0] = new CJoueur(CStringA(joueur2).GetBuffer(), 0);
		break;
	case 2:
		lesJoueurs[0] = new CJoueur(CStringA(joueur3).GetBuffer(), 0);
		break;
	case 3:
		lesJoueurs[0] = new CJoueur(CStringA(joueur4).GetBuffer(), 0);
		break;
	}
	switch (testJoueur2)
	{
	case 0:
		lesJoueurs[1] = new CJoueur(CStringA(joueur1).GetBuffer(), 0);
		break;
	case 1:
		lesJoueurs[1] = new CJoueur(CStringA(joueur2).GetBuffer(), 0);
		break;
	case 2:
		lesJoueurs[1] = new CJoueur(CStringA(joueur3).GetBuffer(), 0);
		break;
	case 3:
		lesJoueurs[1] = new CJoueur(CStringA(joueur4).GetBuffer(), 0);
		break;
	}
	switch (testJoueur3)
	{
	case 0:
		lesJoueurs[2] = new CJoueur(CStringA(joueur1).GetBuffer(), 0);
		break;
	case 1:
		lesJoueurs[2] = new CJoueur(CStringA(joueur2).GetBuffer(), 0);
		break;
	case 2:
		lesJoueurs[2] = new CJoueur(CStringA(joueur3).GetBuffer(), 0);
		break;
	case 3:
		lesJoueurs[2] = new CJoueur(CStringA(joueur4).GetBuffer(), 0);
		break;
	}
	switch (testJoueur4)
	{
	case 0:
		lesJoueurs[3] = new CJoueur(CStringA(joueur1).GetBuffer(), 0);
		break;
	case 1:
		lesJoueurs[3] = new CJoueur(CStringA(joueur2).GetBuffer(), 0);
		break;
	case 2:
		lesJoueurs[3] = new CJoueur(CStringA(joueur3).GetBuffer(), 0);
		break;
	case 3:
		lesJoueurs[3] = new CJoueur(CStringA(joueur4).GetBuffer(), 0);
		break;
	}

	SaisiePreneur preneur(laPartie, lesJoueurs[4], this);
	preneur.DoModal();
	CDialogEx::OnOK();
}
