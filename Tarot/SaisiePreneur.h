#pragma once
#include "afxwin.h"
#include "CJoueur.h"


// Boîte de dialogue SaisiePreneur

class SaisiePreneur : public CDialogEx
{
	DECLARE_DYNAMIC(SaisiePreneur)

public:
	SaisiePreneur(CWnd* pParent = NULL);   // constructeur standard
	virtual ~SaisiePreneur();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SaisiePreneur };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox mContrat;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox mPreneur;
};
