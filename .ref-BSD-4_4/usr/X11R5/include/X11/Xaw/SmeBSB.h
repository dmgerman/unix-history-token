begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: SmeBSB.h,v 1.5 89/12/11 15:20:14 kit Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * SmeBSB.h - Public Header file for SmeBSB object.  *  * This is the public header file for the Athena BSB Sme object.  * It is intended to be used with the simple menu widget.  This object  * provides bitmap - string - bitmap style entries.  *  * Date:    April 3, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SmeBSB_h
end_ifndef

begin_define
define|#
directive|define
name|_SmeBSB_h
end_define

begin_include
include|#
directive|include
file|<X11/Xmu/Converters.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Sme.h>
end_include

begin_comment
comment|/****************************************************************  *  * SmeBSB object  *  ****************************************************************/
end_comment

begin_comment
comment|/* BSB Menu Entry Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  callback            Callback           Callback        NULL  destroyCallback     Callback		Pointer		NULL  font                Font               XFontStruct *   XtDefaultFont  foreground          Foreground         Pixel           XtDefaultForeground  height		     Height		Dimension	0  label               Label              String          Name of entry  leftBitmap          LeftBitmap         Pixmap          None  leftMargin          HorizontalMargins  Dimension       4  rightBitmap         RightBitmap        Pixmap          None  rightMargin         HorizontalMargins  Dimension       4  sensitive	     Sensitive		Boolean		True  vertSpace           VertSpace          int             25  width		     Width		Dimension	0  x		     Position		Position	0n  y		     Position		Position	0  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_SmeBSBClassRec
modifier|*
name|SmeBSBObjectClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_SmeBSBRec
modifier|*
name|SmeBSBObject
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|smeBSBObjectClass
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XtNleftBitmap
value|"leftBitmap"
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
name|XtNrightBitmap
value|"rightBitmap"
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
name|XtNvertSpace
value|"vertSpace"
end_define

begin_define
define|#
directive|define
name|XtCLeftBitmap
value|"LeftBitmap"
end_define

begin_define
define|#
directive|define
name|XtCHorizontalMargins
value|"HorizontalMargins"
end_define

begin_define
define|#
directive|define
name|XtCRightBitmap
value|"RightBitmap"
end_define

begin_define
define|#
directive|define
name|XtCVertSpace
value|"VertSpace"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SmeBSB_h */
end_comment

end_unit

