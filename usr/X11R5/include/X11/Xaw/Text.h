begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Text.h,v 1.41 91/07/22 19:05:20 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawText_h
end_ifndef

begin_define
define|#
directive|define
name|_XawText_h
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/*  Text widget   Class: 	textWidgetClass  Class Name:	Text  Superclass:	Simple   Resources added by the Text widget:   Name		     Class	     RepType		Default Value  ----		     -----	     -------		-------------  autoFill	    AutoFill	     Boolean		False  bottomMargin	    Margin	     Position		2  displayPosition    TextPosition     XawTextPosition	0  insertPosition	    TextPosition     XawTextPosition	0  leftMargin	    Margin	     Position		2  resize		    Resize	     XawTextResizeMode	XawTextResizeNever  rightMargin	    Margin	     Position		4  scrollHorizontal   Scroll	     XawTextScrollMode	XawtextScrollNever  scrollVertical     Scroll	     XawTextScrollMode  XawtextScrollNever  selectTypes        SelectTypes      Pointer            see documentation  textSink	    TextSink	     Widget		NULL  textSource	    TextSource	     Widget		NULL  topMargin	    Margin	     Position		2  unrealizeCallback  Callback	     Callback		NULL  wrap		    Wrap	     XawTextWrapMode	XawTextWrapNever  */
end_comment

begin_typedef
typedef|typedef
name|long
name|XawTextPosition
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawtextScrollNever
block|,
name|XawtextScrollWhenNeeded
block|,
name|XawtextScrollAlways
block|}
name|XawTextScrollMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawtextWrapNever
block|,
name|XawtextWrapLine
block|,
name|XawtextWrapWord
block|}
name|XawTextWrapMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawtextResizeNever
block|,
name|XawtextResizeWidth
block|,
name|XawtextResizeHeight
block|,
name|XawtextResizeBoth
block|}
name|XawTextResizeMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawsdLeft
block|,
name|XawsdRight
block|}
name|XawTextScanDirection
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawtextRead
block|,
name|XawtextAppend
block|,
name|XawtextEdit
block|}
name|XawTextEditType
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawselectNull
block|,
name|XawselectPosition
block|,
name|XawselectChar
block|,
name|XawselectWord
block|,
name|XawselectLine
block|,
name|XawselectParagraph
block|,
name|XawselectAll
block|}
name|XawTextSelectType
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|firstPos
decl_stmt|;
name|int
name|length
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
name|unsigned
name|long
name|format
decl_stmt|;
block|}
name|XawTextBlock
operator|,
typedef|*
name|XawTextBlockPtr
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<X11/Xaw/TextSink.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/TextSrc.h>
end_include

begin_define
define|#
directive|define
name|XtEtextScrollNever
value|"never"
end_define

begin_define
define|#
directive|define
name|XtEtextScrollWhenNeeded
value|"whenneeded"
end_define

begin_define
define|#
directive|define
name|XtEtextScrollAlways
value|"always"
end_define

begin_define
define|#
directive|define
name|XtEtextWrapNever
value|"never"
end_define

begin_define
define|#
directive|define
name|XtEtextWrapLine
value|"line"
end_define

begin_define
define|#
directive|define
name|XtEtextWrapWord
value|"word"
end_define

begin_define
define|#
directive|define
name|XtEtextResizeNever
value|"never"
end_define

begin_define
define|#
directive|define
name|XtEtextResizeWidth
value|"width"
end_define

begin_define
define|#
directive|define
name|XtEtextResizeHeight
value|"height"
end_define

begin_define
define|#
directive|define
name|XtEtextResizeBoth
value|"both"
end_define

begin_define
define|#
directive|define
name|XtNautoFill
value|"autoFill"
end_define

begin_define
define|#
directive|define
name|XtNbottomMargin
value|"bottomMargin"
end_define

begin_define
define|#
directive|define
name|XtNdialogHOffset
value|"dialogHOffset"
end_define

begin_define
define|#
directive|define
name|XtNdialogVOffset
value|"dialogVOffset"
end_define

begin_define
define|#
directive|define
name|XtNdisplayCaret
value|"displayCaret"
end_define

begin_define
define|#
directive|define
name|XtNdisplayPosition
value|"displayPosition"
end_define

begin_define
define|#
directive|define
name|XtNleftMargin
value|"leftMargin"
end_define

begin_define
define|#
directive|define
name|XtNrightMargin
value|"rightMargin"
end_define

begin_define
define|#
directive|define
name|XtNscrollVertical
value|"scrollVertical"
end_define

begin_define
define|#
directive|define
name|XtNscrollHorizontal
value|"scrollHorizontal"
end_define

begin_define
define|#
directive|define
name|XtNselectTypes
value|"selectTypes"
end_define

begin_define
define|#
directive|define
name|XtNtopMargin
value|"topMargin"
end_define

begin_define
define|#
directive|define
name|XtNwrap
value|"wrap"
end_define

begin_define
define|#
directive|define
name|XtCAutoFill
value|"AutoFill"
end_define

begin_define
define|#
directive|define
name|XtCScroll
value|"Scroll"
end_define

begin_define
define|#
directive|define
name|XtCSelectTypes
value|"SelectTypes"
end_define

begin_define
define|#
directive|define
name|XtCWrap
value|"Wrap"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

begin_define
define|#
directive|define
name|XtNinsertPosition
value|"insertPosition"
end_define

begin_define
define|#
directive|define
name|XtNresize
value|"resize"
end_define

begin_define
define|#
directive|define
name|XtNselection
value|"selection"
end_define

begin_define
define|#
directive|define
name|XtCResize
value|"Resize"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return Error code for XawTextSearch */
end_comment

begin_define
define|#
directive|define
name|XawTextSearchError
value|(-12345L)
end_define

begin_comment
comment|/* Return codes from XawTextReplace */
end_comment

begin_define
define|#
directive|define
name|XawReplaceError
value|-1
end_define

begin_define
define|#
directive|define
name|XawEditDone
value|0
end_define

begin_define
define|#
directive|define
name|XawEditError
value|1
end_define

begin_define
define|#
directive|define
name|XawPositionError
value|2
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|FMT8BIT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Class record constants */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|textWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_TextClassRec
modifier|*
name|TextWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_TextRec
modifier|*
name|TextWidget
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XawTextDisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextEnableRedisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextDisableRedisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextSetSelectionArray
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextSelectType
modifier|*
comment|/* sarray */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextGetSelectionPos
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
modifier|*
comment|/* begin_return */
parameter_list|,
name|XawTextPosition
modifier|*
comment|/* end_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextSetSource
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|Widget
comment|/* source */
parameter_list|,
name|XawTextPosition
comment|/* position */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XawTextReplace
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* start */
parameter_list|,
name|XawTextPosition
comment|/* end */
parameter_list|,
name|XawTextBlock
modifier|*
comment|/* text */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XawTextPosition
name|XawTextTopPosition
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextSetInsertionPoint
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* position */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XawTextPosition
name|XawTextGetInsertionPoint
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextUnsetSelection
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextSetSelection
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* left */
parameter_list|,
name|XawTextPosition
comment|/* right */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextInvalidate
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* from */
parameter_list|,
name|XawTextPosition
comment|/* to */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XawTextGetSource
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XawTextPosition
name|XawTextSearch
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* XawTextScanDirection */
name|int
comment|/* dir */
parameter_list|,
else|#
directive|else
name|XawTextScanDirection
comment|/* dir */
parameter_list|,
endif|#
directive|endif
name|XawTextBlock
modifier|*
comment|/* text */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawTextDisplayCaret
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* Boolean */
name|int
comment|/* visible */
else|#
directive|else
name|Boolean
comment|/* visible */
endif|#
directive|endif
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_comment
comment|/*  * For R3 compatability only.   */
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/AsciiSrc.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/AsciiSink.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawText_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

