
// CTask4View.h: интерфейс класса CCTask4View
//

#pragma once


class CCTask4View : public CView
{
protected: // создать только из сериализации
	CCTask4View() noexcept;
	DECLARE_DYNCREATE(CCTask4View)

// Атрибуты
public:
	CCTask4Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CCTask4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в CTask4View.cpp
inline CCTask4Doc* CCTask4View::GetDocument() const
   { return reinterpret_cast<CCTask4Doc*>(m_pDocument); }
#endif

