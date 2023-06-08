#pragma once
#include <vector>
#include <map>
#include "Place.h"
#include "Synonims.h"

class MyForm : public CFormView
{
	DECLARE_DYNCREATE(MyForm)

private:
	CStringArray words;
	Synonims synonims;
protected:
	MyForm();
	virtual ~MyForm();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MyForm };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSynonimsButton();
	afx_msg void OnBnClickedWordsButton();
	afx_msg void OnBnClickedFunctionButton();

};

