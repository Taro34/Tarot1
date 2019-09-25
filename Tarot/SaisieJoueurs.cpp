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
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieJoueurs::OnCbnSelchangeCombo2()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieJoueurs::OnCbnSelchangeCombo3()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieJoueurs::OnCbnSelchangeCombo4()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieJoueurs::OnBnClickedButton1()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	UpdateData(true);
	mDonneur1.ResetContent();
	mDonneur2.ResetContent();
	mDonneur3.ResetContent();
	mDonneur4.ResetContent();
	UpdateData(false);
	lesJoueurs[0] = new CJoueur(CStringA(joueur1).GetBuffer(), 0);
	lesJoueurs[1] = new CJoueur(CStringA(joueur2).GetBuffer(), 0);
	lesJoueurs[2] = new CJoueur(CStringA(joueur3).GetBuffer(), 0);
	lesJoueurs[3] = new CJoueur(CStringA(joueur4).GetBuffer(), 0);
	for (int i = 0; i < 4; i++)
		mDonneur1.AddString(CString(lesJoueurs[i]->lireNom().c_str()));
	UpdateData(false);
	for (int i = 0; i < 4; i++)
		mDonneur2.AddString(CString(lesJoueurs[i]->lireNom().c_str()));
	UpdateData(false);
	for (int i = 0; i < 4; i++)
		mDonneur3.AddString(CString(lesJoueurs[i]->lireNom().c_str()));
	UpdateData(false);
	for (int i = 0; i < 4; i++)
		mDonneur4.AddString(CString(lesJoueurs[i]->lireNom().c_str()));
	UpdateData(false);
}
