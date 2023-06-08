
// CTask4View.cpp: реализация класса CCTask4View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "CTask4.h"
#endif

#include "CTask4Doc.h"
#include "CTask4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCTask4View

IMPLEMENT_DYNCREATE(CCTask4View, CView)

BEGIN_MESSAGE_MAP(CCTask4View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCTask4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CCTask4View

CCTask4View::CCTask4View() noexcept
{
	// TODO: добавьте код создания

}

CCTask4View::~CCTask4View()
{
}

BOOL CCTask4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CCTask4View

void CCTask4View::OnDraw(CDC* /*pDC*/)
{
	CCTask4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CCTask4View


void CCTask4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCTask4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CCTask4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CCTask4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CCTask4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCTask4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CCTask4View

#ifdef _DEBUG
void CCTask4View::AssertValid() const
{
	CView::AssertValid();
}

void CCTask4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCTask4Doc* CCTask4View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCTask4Doc)));
	return (CCTask4Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CCTask4View
