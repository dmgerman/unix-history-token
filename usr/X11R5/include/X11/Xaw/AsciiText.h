begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: AsciiText.h,v 1.16 91/01/21 12:39:04 swick Exp $   */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/***********************************************************************  *  * AsciiText Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/*  * AsciiText.c - Public header file for AsciiText Widget.  *  * This Widget is intended to be used as a simple front end to the   * text widget with an ascii source and ascii sink attached to it.  *  * Date:    June 29, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AsciiText_h
end_ifndef

begin_define
define|#
directive|define
name|_AsciiText_h
end_define

begin_comment
comment|/****************************************************************  *  * AsciiText widgets  *  ****************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/Text.h>
end_include

begin_comment
comment|/* AsciiText is a subclass of Text */
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/AsciiSrc.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		  Default Value  ----		     -----		-------		  -------------  autoFill	     AutoFill		Boolean		  False  background	     Background		Pixel		  XtDefaultBackground  border		     BorderColor	Pixel		  XtDefaultForeground  borderWidth	     BorderWidth	Dimension	  1  bottomMargin	     Margin		Position	  2  cursor		     Cursor		Cursor		  xterm  destroyCallback     Callback		Pointer		  NULL  displayCaret	     Output		Boolean		  True  displayPosition     TextPosition	int		  0  editType	     EditType		XawTextEditType	  XawtextRead  font		     Font		XFontStruct*	  Fixed  foreground	     Foreground		Pixel		  Black  height		     Height		Dimension	  font height  insertPosition	     TextPosition	int		  0  leftMargin	     Margin		Position	  2  mappedWhenManaged   MappedWhenManaged	Boolean		  True  resize		     Resize		XawTextResizeMode XawtextResizeNever  rightMargin	     Margin		Position	  4  scrollHorizontal    Scroll		XawTextScrollMode XawtextScrollNever  scrollVertical	     Scroll		XawTextScrollMode XawtextScrollNever  selectTypes	     SelectTypes	Pointer		  pos/word/line/par/all  selection	     Selection		Pointer		  (empty selection)  sensitive	     Sensitive		Boolean		  True  sink		     TextSink		Widget		  (none)  source		     TextSource		Widget		  (none)  string		     String		String		  NULL  topMargin	     Margin		Position	  2  width		     Width		Dimension	  100  wrap		     Wrap		XawTextWrapMode	  XawtextWrapNever  x		     Position		Position	  0  y		     Position		Position	  0   (see also *Src.h and *Sink.h) */
end_comment

begin_comment
comment|/*  * Everything else we need is in StringDefs.h or Text.h  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_AsciiTextClassRec
modifier|*
name|AsciiTextWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_AsciiRec
modifier|*
name|AsciiWidget
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|asciiTextWidgetClass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************************************************************  *  * Disk and String Emulation Info.  *   ************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII_STRING
end_ifdef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|asciiStringWidgetClass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII_DISK
end_ifdef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|asciiDiskWidgetClass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AsciiText_h */
end_comment

end_unit

