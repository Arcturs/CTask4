#include "pch.h"
#include "MyForm.h"
#include <string>

IMPLEMENT_DYNCREATE(MyForm, CFormView)

MyForm::MyForm(): CFormView(IDD_MyForm)
{

}

MyForm::~MyForm()
{
}

void MyForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MyForm, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_TEXT, &MyForm::OnBnClickedSynonimsButton)
	ON_BN_CLICKED(IDC_BUTTON_WORDS, &MyForm::OnBnClickedWordsButton)
	ON_BN_CLICKED(IDC_BUTTON_FUNC, &MyForm::OnBnClickedFunctionButton)
END_MESSAGE_MAP()


#ifdef _DEBUG
void MyForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void MyForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif


void MyForm::OnBnClickedWordsButton()
{
	LPCTSTR filter =
		_T("TXT (*.txt)| *.txt|");
	CFileDialog dlgFile(TRUE, _T("txt"), NULL, OFN_OVERWRITEPROMPT, filter, AfxGetMainWnd());
	try {
		if (IDOK == dlgFile.DoModal()) {
			CStdioFile file(dlgFile.GetPathName(), CFile::modeRead | CFile::typeText);
			bool isFile = false;
			CString buff;
			while (file.ReadString(buff)) {
				int pos = 0;
				CString strToken = buff.Tokenize(_T(" "), pos);
				while (!strToken.IsEmpty())
				{
					if (!strToken.IsEmpty() && strToken != "\n") {
						words.Add(strToken);
					}
					strToken = buff.Tokenize(_T(" "), pos);
				}
				isFile = true;
			}
			if (!isFile) {
				AfxMessageBox(_T("Empty file"));
			} else {
				for (int i = 0; i < words.GetSize(); i++) {
					TRACE(_T("%s \n"), words[i]);
				}
			}

		}
	}
	catch (CFileException* e) {
		TRACE(_T("File could not be opened, cause = %d\n"),
			e->m_cause);
		e->Delete();
	}

}

void MyForm::OnBnClickedSynonimsButton()
{
	LPCTSTR filter =
		_T("TXT (*.txt)| *.txt|");
	CFileDialog dlgFile(TRUE, _T("txt"), NULL, OFN_OVERWRITEPROMPT, filter, AfxGetMainWnd());
	try {
		if (IDOK == dlgFile.DoModal()) {
			CStdioFile file(dlgFile.GetPathName(), CFile::modeRead | CFile::typeText);
			bool isFile = false;
			CString buff;
			CStringArray buffArr;
			while (file.ReadString(buff)) {
				buffArr.Add(buff);
				isFile = true;
			}
			if (!isFile) {
				AfxMessageBox(_T("Empty file"));
			} else {
				for (int i = 0; i < buffArr.GetSize(); i++) {
					int nTokenPos = 0;
					CString strToken = buffArr[i].Tokenize(_T(" "), nTokenPos);
					synonims.addWord(strToken);
					while (!strToken.IsEmpty())
					{
						strToken = buffArr[i].Tokenize(_T(" "), nTokenPos);
						if (!strToken.IsEmpty() && strToken != "\n") {
							synonims.addSynonim(strToken);
						}
					}
				}
			}
		}

	}
	catch (CFileException* e) {
		TRACE(_T("File could not be opened, cause = %d\n"),
			e->m_cause);
		e->Delete();
	}
}

void MyForm::OnBnClickedFunctionButton()
{
	if (words.GetSize() == 0 || synonims.isEmpty()) {
		AfxMessageBox(_T("You have not loaded any required file"));
		return;
	}
	LPCTSTR filter =
		_T("TXT (*.txt)| *.txt|");
	CFileDialog dlgFile(FALSE, _T("txt"), _T("Output.txt"), OFN_OVERWRITEPROMPT, filter, AfxGetMainWnd());

	try {
		if (IDOK == dlgFile.DoModal()) {
			CStdioFile file(dlgFile.GetPathName(), CFile::modeCreate | CFile::modeWrite | CFile::typeText);
			CString buff;
			for (int i = 0; i < words.GetSize(); i++) {
				file.WriteString(synonims.getSynonim(words[i]));
				file.WriteString(_T(" "));
			}
		}

	}
	catch (CFileException* e) {
		TRACE(_T("File could not be opened, cause = %d\n"),
			e->m_cause);
		e->Delete();
	}
}