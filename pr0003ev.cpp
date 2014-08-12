/*  Project proj0003
    
    Copyright © 1995. All Rights Reserved.

    SUBSYSTEM:    proj0003.exe Application
    FILE:         pr0003ev.cpp
    AUTHOR:       


    OVERVIEW
    ========
    Source file for implementation of proj0003EditView (TEditView).      
*/


#include <owl\owlpch.h>
#pragma hdrstop

#include "prj0003a.h"
#include "pr0003ev.h"

#include <stdio.h>


//{{proj0003EditView Implementation}}


//
// Build a response table for all messages/commands handled
// by proj0003EditView derived from TEditView.
//
DEFINE_RESPONSE_TABLE1(proj0003EditView, TEditView)
//{{proj0003EditViewRSP_TBL_BEGIN}}
    EV_WM_GETMINMAXINFO,
//{{proj0003EditViewRSP_TBL_END}}
END_RESPONSE_TABLE;


//////////////////////////////////////////////////////////
// proj0003EditView
// ==========
// Construction/Destruction handling.
proj0003EditView::proj0003EditView (TDocument& doc, TWindow* parent)
    : TEditView(doc, parent)
{
    // INSERT>> Your constructor code here.

}


proj0003EditView::~proj0003EditView ()
{
    // INSERT>> Your destructor code here.

}


//
// Paint routine for Window, Printer, and PrintPreview for a TEditView client.
//
void proj0003EditView::Paint (TDC& dc, bool, TRect& rect)
{
    proj0003App *theApp = TYPESAFE_DOWNCAST(GetApplication(), proj0003App);
    if (theApp) {
        // Only paint if we're printing and we have something to paint, otherwise do nothing.
        if (theApp->Printing && theApp->Printer && !rect.IsEmpty()) {
            // Use pageSize to get the size of the window to render into.  For a Window it's the client area,
            // for a printer it's the printer DC dimensions and for print preview it's the layout window.
            TSize   pageSize(rect.right - rect.left, rect.bottom - rect.top);

            HFONT   hFont = (HFONT)GetWindowFont();
            TFont   font("Arial", -12);
            if (hFont == 0)
              dc.SelectObject(font);
            else
              dc.SelectObject(TFont(hFont));
    
            TEXTMETRIC  tm;
            int fHeight = (dc.GetTextMetrics(tm) == true) ? tm.tmHeight + tm.tmExternalLeading : 10;
    
            // How many lines of this font can we fit on a page.
            int linesPerPage = MulDiv(pageSize.cy, 1, fHeight);
            if (linesPerPage) {    
                TPrintDialog::TData &printerData = theApp->Printer->GetSetup();

                int maxPg = ((GetNumLines() / linesPerPage) + 1.0);

                // Compute the number of pages to print.
                printerData.MinPage = 1;
                printerData.MaxPage = maxPg;

                // Do the text stuff:
                int     fromPage = printerData.FromPage == -1 ? 1 : printerData.FromPage;
                int     toPage = printerData.ToPage == -1 ? 1 : printerData.ToPage;
                char    buffer[255];
                int     currentPage = fromPage;

                while (currentPage <= toPage) {
                    int startLine = (currentPage - 1) * linesPerPage;
                    int lineIdx = 0;
                    while (lineIdx < linesPerPage) {
                        // If the string is no longer valid then there's nothing more to display.
                        if (!GetLine(buffer, sizeof(buffer), startLine + lineIdx))
                            break;
                        dc.TabbedTextOut(TPoint(0, lineIdx * fHeight), buffer, strlen(buffer), 0, NULL, 0);
                        lineIdx++;
                    }
                    currentPage++;
                }
            }
        }
    }
}


void proj0003EditView::EvGetMinMaxInfo (MINMAXINFO far& minmaxinfo)
{
    proj0003App *theApp = TYPESAFE_DOWNCAST(GetApplication(), proj0003App);
    if (theApp) {
        if (theApp->Printing) {
            minmaxinfo.ptMaxSize = TPoint(32000, 32000);
            minmaxinfo.ptMaxTrackSize = TPoint(32000, 32000);
            return;
        }
    }
    TEditView::EvGetMinMaxInfo(minmaxinfo);
}
