#pragma once
#include "afxwin.h"
#include "CJoueur.h"
#include "CPartie.h"
#include "SaisiePoint.h"
#include "SaisiePreneur.h"


// Boîte de dialogue SaisieJoueurs

class SaisieJoueurs : public CDialogEx
{
	DECLARE_DYNAMIC(SaisieJoueurs)

public:
	SaisieJoueurs(CWnd* pParent = NULL);   // constructeur standard
	virtual ~SaisieJoueurs();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SaisieJoueurs };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()

private:
	CString joueur1;
	CString joueur2;
	CString joueur3;
	CString joueur4;
	CJoueur *lesJoueurs[4];
	CPartie *laPartie;

public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox mDonneur1;
	CComboBox mDonneur2;
	CComboBox mDonneur3;
	CComboBox mDonneur4;
	void creerPartie();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnBnClickedButton1();

	afx_msg void OnBnClickedOk();
};
