begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: SmeLine.h,v 1.3 89/12/11 15:20:19 kit Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * SmeLine.h - Public Header file for SmeLine object.  *  * This is the public header file for the Athena SmeLine object.  * It is intended to be used with the simple menu widget.    *  * Date:    April 3, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SmeLine_h
end_ifndef

begin_define
define|#
directive|define
name|_SmeLine_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Sme.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xmu/Converters.h>
end_include

begin_comment
comment|/****************************************************************  *  * SmeLine Object  *  ****************************************************************/
end_comment

begin_comment
comment|/* Menu Entry Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  callback            Callback		Pointer		NULL  destroyCallback     Callback		Pointer		NULL  height		     Height		Dimension	0  sensitive	     Sensitive		Boolean		True  width		     Width		Dimension	0  x		     Position		Position	0n  y		     Position		Position	0  */
end_comment

begin_define
define|#
directive|define
name|XtCLineWidth
value|"LineWidth"
end_define

begin_define
define|#
directive|define
name|XtCStipple
value|"Stipple"
end_define

begin_define
define|#
directive|define
name|XtNlineWidth
value|"lineWidth"
end_define

begin_define
define|#
directive|define
name|XtNstipple
value|"stipple"
end_define

begin_typedef
typedef|typedef
name|struct
name|_SmeLineClassRec
modifier|*
name|SmeLineObjectClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_SmeLineRec
modifier|*
name|SmeLineObject
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|smeLineObjectClass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SmeLine_h */
end_comment

end_unit

