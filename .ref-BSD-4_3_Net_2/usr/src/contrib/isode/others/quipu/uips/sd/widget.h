begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* widget.h - definition of the widget structure and assorted constants */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/others/quipu/uips/sd/RCS/widget.h,v 7.2 91/02/22 09:32:32 mrose Interim $  */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*This file has been modified; /*Modifier:     Damanjit Mahl @ Brunel University, Uxbridge /*****************************************************************************/
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/* File:	widget.h /* Author:	Paul Sharpe @ GEC Research, Hirst Research Centre. /* Date:	August 12, 1988. /* Function:	Definition of the widget structure and assorted constants. /* /* DISCLAIMER: /* This source file is deemed to be public domain: any person may use the /* code in any way, on two simple provisos - /*   1 - That this header remains in this file, /*   2 - It is accepted that neither the author, nor the authors employees /*       accept any responsibility for the use, abuse or misuse of the /*       contained code. /* No guarantee is made by the author to provide maintainance or up-grading /* of this source. However, any adaptations made to this file will be viewed /* at least with interest. /*****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIDGETDEFS
end_ifndef

begin_define
define|#
directive|define
name|WIDGETDEFS
end_define

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_comment
comment|/* These define the type of the widget involved */
end_comment

begin_define
define|#
directive|define
name|FINISH
value|0
end_define

begin_define
define|#
directive|define
name|LABEL
value|1
end_define

begin_define
define|#
directive|define
name|COMMAND
value|2
end_define

begin_define
define|#
directive|define
name|TOGGLE
value|3
end_define

begin_define
define|#
directive|define
name|DIALOG
value|4
end_define

begin_define
define|#
directive|define
name|SCROLLBAR
value|5
end_define

begin_define
define|#
directive|define
name|DUMMY
value|6
end_define

begin_comment
comment|/* These define functions that aren't really needed */
end_comment

begin_define
define|#
directive|define
name|NULLFN
value|nullfn
end_define

begin_define
define|#
directive|define
name|TOGGLEFN
value|NULLFN
end_define

begin_define
define|#
directive|define
name|QUITFN
value|quitfn
end_define

begin_comment
comment|/* These define the LABEL wdgt text justification */
end_comment

begin_define
define|#
directive|define
name|CENTER
value|CENTRE
end_define

begin_define
define|#
directive|define
name|CENTRE
value|1
end_define

begin_define
define|#
directive|define
name|LEFT
value|2
end_define

begin_define
define|#
directive|define
name|RIGHT
value|4
end_define

begin_comment
comment|/* Thisdefines an expanded widget box */
end_comment

begin_define
define|#
directive|define
name|EXPAND
value|-1
end_define

begin_comment
comment|/* This defines a widget position starting on a new line */
end_comment

begin_define
define|#
directive|define
name|CRNL
value|-1
end_define

begin_comment
comment|/* This is the default shown length of the dialog string */
end_comment

begin_define
define|#
directive|define
name|DIALOGLEN
value|4
end_define

begin_comment
comment|/* This defines the maximum number of levels of active widgets */
end_comment

begin_define
define|#
directive|define
name|MAXACTIVE
value|10
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BUFLEN
end_ifndef

begin_define
define|#
directive|define
name|BUFLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|lowy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the height of a widget box, in number of lines */
end_comment

begin_define
define|#
directive|define
name|WDGTHGHT
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|widget
block|{
name|char
name|type
decl_stmt|;
comment|/* Type of widget: see the above definitions */
name|char
modifier|*
name|label
decl_stmt|;
comment|/* text string label for the widget          */
comment|/* The former is used by LABEL and COMMAND widgets: the latter by COMMAND */
name|char
name|callch
decl_stmt|;
comment|/* Character to activate the COMMAND widget  */
name|void
function_decl|(
modifier|*
name|callfn
function_decl|)
parameter_list|()
function_decl|;
comment|/* Function called by an activated COMMAND  */
comment|/* ALL widgets need these fields to be set */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* Position of the top right of the window  */
name|int
name|wdth
decl_stmt|,
name|hght
decl_stmt|;
comment|/* width and height of the widget window    */
comment|/* These are only used by the DIALOG type widgets                  */
name|int
name|dstrlen
decl_stmt|;
comment|/* Maximum length of the DIALOG widget str  */
name|char
modifier|*
name|dstr
decl_stmt|;
comment|/* Pointer to the DIALOG string to fill in   */
comment|/* These are only used by the TOGGLE type widgets                  */
name|char
name|tindx
decl_stmt|;
comment|/* Index into the toggle values              */
name|char
modifier|*
modifier|*
name|tvalues
decl_stmt|;
comment|/* NULL-terminated array of TOGGLE strings   */
name|WINDOW
modifier|*
name|wndw
decl_stmt|;
comment|/* The curses-widget window structure */
block|}
name|WIDGET
typedef|;
end_typedef

begin_decl_stmt
name|WIDGET
modifier|*
name|currwidgets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|typetoggled
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|initwidgets
argument_list|()
decl_stmt|,
name|textfresh
argument_list|()
decl_stmt|,
name|makewidgets
argument_list|()
decl_stmt|,
name|setwdgtwdth
argument_list|()
decl_stmt|,
name|killwidgets
argument_list|()
decl_stmt|,
name|activewidget
argument_list|()
decl_stmt|,
name|deleteactive
argument_list|()
decl_stmt|,
name|activeindex
argument_list|()
decl_stmt|,
name|redraw
argument_list|()
decl_stmt|,
name|rfrshwidgets
argument_list|()
decl_stmt|,
name|boxwdgt
argument_list|()
decl_stmt|,
name|printwdgt
argument_list|()
decl_stmt|,
name|printbar
argument_list|()
decl_stmt|,
name|printlabel
argument_list|()
decl_stmt|,
name|printdialog
argument_list|()
decl_stmt|,
name|printtoggle
argument_list|()
decl_stmt|,
name|printcommand
argument_list|()
decl_stmt|,
name|interact
argument_list|()
decl_stmt|,
name|docallback
argument_list|()
decl_stmt|,
name|dialog
argument_list|()
decl_stmt|,
name|setdialogstr
argument_list|()
decl_stmt|,
name|toggle
argument_list|()
decl_stmt|,
name|settogglstrs
argument_list|()
decl_stmt|,
name|setlabel
argument_list|()
decl_stmt|,
name|getlabel
argument_list|()
decl_stmt|,
name|wprint
argument_list|()
decl_stmt|,
name|tprint
argument_list|()
decl_stmt|,
name|xprint
argument_list|()
decl_stmt|,
name|xprintint
argument_list|()
decl_stmt|,
name|cleartext
argument_list|()
decl_stmt|,
name|jumpback
argument_list|()
decl_stmt|,
name|nullfn
argument_list|()
decl_stmt|,
name|quitfn
argument_list|()
decl_stmt|,
name|endwidgets
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linec
argument_list|()
decl_stmt|,
name|gety
argument_list|()
decl_stmt|,
name|posnwidgets
argument_list|()
decl_stmt|,
name|getwidgetindex
argument_list|()
decl_stmt|,
name|getdialogstr
argument_list|()
decl_stmt|,
name|settogglindx
argument_list|()
decl_stmt|,
name|gettogglindx
argument_list|()
decl_stmt|,
name|gettogglstr
argument_list|()
decl_stmt|,
name|lowesty
argument_list|()
decl_stmt|,
name|findactiveinput
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|WIDGET
modifier|*
name|getwidget
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

