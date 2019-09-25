#pragma once
#include "afxwin.h"
#include "CJoueur.h"
#include "CPartie.h"
#include "string"
using namespace std;

// Boîte de dialogue SaisiePoint

class SaisiePoint : public CDialogEx
{
	DECLARE_DYNAMIC(SaisiePoint)

public:
	SaisiePoint(CWnd* pParent = NULL);   // constructeur standard
	virtual ~SaisiePoint();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SaisiePoint };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int points;
	int nbBouts;
	int testPetit;
	int testPoignee;
	CComboBox mComboPetit;
	CComboBox mComboPoignee;
	void envoyerValeur();
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangecombopetit();
	afx_msg void OnCbnSelchangecombopoignee();
};
