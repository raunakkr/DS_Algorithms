/*  Project proj0003
    
    Copyright © 1995. All Rights Reserved.

    SUBSYSTEM:    proj0003.exe Application
    FILE:         prj0003a.cpp
    AUTHOR:       


    OVERVIEW
    ========
    Source file for implementation of proj0003App (TApplication).      
*/


#include <owl\owlpch.h>
#pragma hdrstop

#include <dir.h>

#include "prj0003a.h"
#include "0003mdic.h"
#include "0003mdi1.h"
#include "pr0003ev.h"
#include "pr0003ad.h"                        // Definition of about dialog.       


// Drag / Drop support:
TFileDrop::TFileDrop (char* fileName, TPoint& p, bool inClient, TModule*)
{
    char    exePath[MAXPATH];
    
    exePath[0] = 0;
    FileName = strcpy(new char[strlen(fileName) + 1], fileName);
    Point = p;
    InClientArea = inClient;
}

TFileDrop::~TFileDrop ()
{
    delete FileName;
}

const char *TFileDrop::WhoAmI ()
{
  return FileName;
}


//{{proj0003App Implementation}}



//{{DOC_VIEW}}
DEFINE_DOC_TEMPLATE_CLASS(TFileDocument, proj0003EditView, DocType1);
//{{DOC_VIEW_END}}

//{{DOC_MANAGER}}
DocType1 __dvt1("All Files (*.*)", "*.*", 0, "TXT", dtAutoDelete | dtUpdateDir);
//{{DOC_MANAGER_END}}


//
// Build a response table for all messages/commands handled
// by the application.
//
DEFINE_RESPONSE_TABLE1(proj0003App, TApplication)
//{{proj0003AppRSP_TBL_BEGIN}}
    EV_OWLVIEW(dnCreate, EvNewView),
    EV_OWLVIEW(dnClose,  EvCloseView),
    EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
    EV_WM_DROPFILES,
    EV_WM_WININICHANGE,
//{{proj0003AppRSP_TBL_END}}
END_RESPONSE_TABLE;


//////////////////////////////////////////////////////////
// proj0003App
// =====
//
proj0003App::proj0003App () : TApplication("proj0003")
{
    Printer = 0;
    Printing = 0;

    SetDocManager(new TDocManager(dmMDI, this));

    // INSERT>> Your constructor code here.
}


proj0003App::~proj0003App ()
{
    if (Printer)
        delete Printer;

    // INSERT>> Your destructor code here.
}


void proj0003App::CreateGadgets (TControlBar *cb, bool server)
{
    if (!server) {
        cb->Insert(*new TButtonGadget(CM_MDIFILENEW, CM_MDIFILENEW));
        cb->Insert(*new TButtonGadget(CM_MDIFILEOPEN, CM_MDIFILEOPEN));
        cb->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE));
        cb->Insert(*new TSeparatorGadget(6));
    }

    cb->Insert(*new TButtonGadget(CM_EDITCUT, CM_EDITCUT));
    cb->Insert(*new TButtonGadget(CM_EDITCOPY, CM_EDITCOPY));
    cb->Insert(*new TButtonGadget(CM_EDITPASTE, CM_EDITPASTE));
    cb->Insert(*new TSeparatorGadget(6));
    cb->Insert(*new TButtonGadget(CM_EDITUNDO, CM_EDITUNDO));
    cb->Insert(*new TSeparatorGadget(6));
    cb->Insert(*new TButtonGadget(CM_EDITFIND, CM_EDITFIND));
    cb->Insert(*new TButtonGadget(CM_EDITFINDNEXT, CM_EDITFINDNEXT));

    if (!server) {
        cb->Insert(*new TSeparatorGadget(6));
        cb->Insert(*new TButtonGadget(CM_FILEPRINT, CM_FILEPRINT));
        cb->Insert(*new TButtonGadget(CM_FILEPRINTPREVIEW, CM_FILEPRINTPREVIEW));
    }

    // Add fly-over help hints.
    cb->SetHintMode(TGadgetWindow::EnterHints);
}


void proj0003App::SetupSpeedBar (TDecoratedMDIFrame *frame)
{ 
    //
    // Create default toolbar New and associate toolbar buttons with commands.
    //   
    TControlBar* cb = new TControlBar(frame);
    CreateGadgets(cb);

    // Setup the toolbar ID used by OLE 2 for toolbar negotiation.
    cb->Attr.Id = IDW_TOOLBAR;

    frame->Insert(*cb, TDecoratedFrame::Top);
}


//////////////////////////////////////////////////////////
// proj0003App
// =====
// Application intialization.
//
void proj0003App::InitMainWindow ()
{
    if (nCmdShow != SW_HIDE)
        nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

    mdiClient = new proj0003MDIClient(this);
    TDecoratedMDIFrame* frame = new TDecoratedMDIFrame(Name, MDI_MENU, *mdiClient, true, this);

    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

    //
    // Assign ICON w/ this application.
    //
    frame->SetIcon(this, IDI_MDIAPPLICATION);

    //
    // Menu associated with window and accelerator table associated with table.
    //
    frame->AssignMenu(MDI_MENU);
    
    //
    // Associate with the accelerator table.
    //
    frame->Attr.AccelTable = MDI_MENU;

    SetupSpeedBar(frame);

    TStatusBar *sb = new TStatusBar(frame, TGadget::Recessed,
                                    TStatusBar::CapsLock        |
                                    TStatusBar::NumLock         |
                                    TStatusBar::ScrollLock      |
                                    TStatusBar::Overtype);
    frame->Insert(*sb, TDecoratedFrame::Bottom);
  
    SetMainWindow(frame);

    frame->SetMenuDescr(TMenuDescr(MDI_MENU));

}


//////////////////////////////////////////////////////////
// proj0003App
// =====
// Response Table handlers:
//
void proj0003App::EvNewView (TView& view)
{
    TMDIClient *mdiClient = TYPESAFE_DOWNCAST(GetMainWindow()->GetClientWindow(), TMDIClient);
    if (mdiClient) {
        proj0003MDIChild* child = new proj0003MDIChild(*mdiClient, 0, view.GetWindow());

        // Associate ICON w/ this child window.
        child->SetIcon(this, IDI_DOC);

        child->Create();
    }
}


void proj0003App::EvCloseView (TView&)
{
}


//////////////////////////////////////////////////////////
// proj0003App
// ===========
// Menu Help About proj0003.exe command
void proj0003App::CmHelpAbout ()
{
    //
    // Show the modal dialog.
    //
    proj0003AboutDlg(GetMainWindow()).Execute();
}


void proj0003App::InitInstance ()
{
    TApplication::InitInstance();

    // Accept files via drag/drop in the frame window.
    GetMainWindow()->DragAcceptFiles(true);
}


void proj0003App::EvDropFiles (TDropInfo drop)
{
    // Number of files dropped.
    int totalNumberOfFiles = drop.DragQueryFileCount();

    TFileList* files = new TFileList;

    for (int i = 0; i < totalNumberOfFiles; i++) {
        // Tell DragQueryFile the file interested in (i) and the length of your buffer.
        int     fileLength = drop.DragQueryFileNameLen(i) + 1;
        char    *fileName = new char[fileLength];

        drop.DragQueryFile(i, fileName, fileLength);

        // Getting the file dropped. The location is relative to your client coordinates,
        // and will have negative values if dropped in the non client parts of the window.
        //
        // DragQueryPoint copies that point where the file was dropped and returns whether
        // or not the point is in the client area.  Regardless of whether or not the file
        // is dropped in the client or non-client area of the window, you will still receive
        // the file name.
        TPoint  point;
        bool    inClientArea = drop.DragQueryPoint(point);
        files->Add(new TFileDrop(fileName, point, inClientArea, this));
    }

    // Open the files that were dropped.
    AddFiles(files);

    // Release the memory allocated for this handle with DragFinish.
    drop.DragFinish();
}


void proj0003App::AddFiles (TFileList* files)
{
    // Open all files dragged in.
    TFileListIter fileIter(*files);

    while (fileIter) {
        TDocTemplate* tpl = GetDocManager()->MatchTemplate(fileIter.Current()->WhoAmI());
        if (tpl)
            tpl->CreateDoc(fileIter.Current()->WhoAmI());
        fileIter++;
    }
}


void proj0003App::EvWinIniChange (char far* section)
{
    if (strcmp(section, "windows") == 0) {
        // If the device changed in the WIN.INI file then the printer
        // might have changed.  If we have a TPrinter (Printer) then
        // check and make sure it's identical to the current device
        // entry in WIN.INI.
        if (Printer) {
            char printDBuffer[255];
            LPSTR printDevice = printDBuffer;
            LPSTR devName;
            LPSTR driverName = 0;
            LPSTR outputName = 0;
        
            if (::GetProfileString("windows", "device", "", printDevice, sizeof(printDevice))) {
                // The string which should come back is something like:
                //
                //      HP LaserJet III,hppcl5a,LPT1:
                //
                // Where the format is:
                //
                //      devName,driverName,outputName
                //
                devName = printDevice;
                while (*printDevice) {
                    if (*printDevice == ',') {
                        *printDevice++ = 0;
                        if (!driverName)
                            driverName = printDevice;
                        else
                            outputName = printDevice;
                    } else
                        printDevice = ::AnsiNext(printDevice);
                }

                if ((Printer->GetSetup().Error != 0)                                ||
                    (strcmp(devName, Printer->GetSetup().GetDeviceName()) != 0)    ||
                    (strcmp(driverName, Printer->GetSetup().GetDriverName()) != 0) ||
                    (strcmp(outputName, Printer->GetSetup().GetOutputName()) != 0)) {
                
                    // New printer installed so get the new printer device now.
                    delete Printer;
                    Printer = new TPrinter(this);
                }
            } else {
                // No printer installed (GetProfileString failed).
                delete Printer;
                Printer = new TPrinter(this);
            }
        }
    }
}


int OwlMain (int , char* [])
{
    try {
        proj0003App    app;
        return app.Run();
    }
    catch (xmsg& x) {
        ::MessageBox(0, x.why().c_str(), "Exception", MB_OK);
    }

    return -1;
}
