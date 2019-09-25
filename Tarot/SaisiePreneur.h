#pragma once
#include "afxwin.h"
#include "SaisieJoueurs.h"
#include "SaisiePoint.h"

// Boîte de dialogue SaisiePreneur

class SaisiePreneur : public CDialogEx
{
	DECLARE_DYNAMIC(SaisiePreneur)

public:
	SaisiePreneur(CPartie *laPartie,CJoueur *lesJoueurs, CWnd* pParent = NULL);   // constructeur standard
	virtual ~SaisiePreneur();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SaisiePreneur };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV
	CPartie *laPartie;
	CJoueur *lesJoueurs[4];

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox mContrat;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox mPreneur;
	afx_msg void OnBnClickedButton1();
	int testJoueur;
	int testContrat;
};
