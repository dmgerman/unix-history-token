begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Grip.h,v 1.18 91/07/26 19:42:40 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  *  Grip.h - Public Definitions for Grip widget (used by VPane Widget)  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawGrip_h
end_ifndef

begin_define
define|#
directive|define
name|_XawGrip_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Simple.h>
end_include

begin_comment
comment|/***************************************************************************  *  * Grip Widget   *  **************************************************************************/
end_comment

begin_comment
comment|/* Parameters:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  foreground	     Foreground		Pixel		XtDefaultForeground  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	0  callback	     Callback		Pointer		GripAction  cursor		     Cursor		Cursor		None  cursorName	     Cursor		String		NULL  destroyCallback     Callback		Pointer		NULL  height		     Height		Dimension	8  mappedWhenManaged   MappedWhenManaged	Boolean		True  pointerColor	     Foreground		Pixel		XtDefaultForeground  pointerColorBackground Background	Pixel		XtDefaultBackground  sensitive	     Sensitive		Boolean		True  width		     Width		Dimension	8  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_define
define|#
directive|define
name|XtNgripTranslations
value|"gripTranslations"
end_define

begin_typedef
typedef|typedef
struct|struct
name|_XawGripCallData
block|{
name|XEvent
modifier|*
name|event
decl_stmt|;
comment|/* the event causing the GripAction */
name|String
modifier|*
name|params
decl_stmt|;
comment|/* the TranslationTable params */
name|Cardinal
name|num_params
decl_stmt|;
comment|/* count of params */
block|}
name|XawGripCallDataRec
operator|,
typedef|*
name|XawGripCallData
operator|,
name|GripCallDataRec
operator|,
typedef|*
name|GripCallData
typedef|;
end_typedef

begin_comment
comment|/* supported for R4 compatibility */
end_comment

begin_comment
comment|/* Class Record Constant */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|gripWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_GripClassRec
modifier|*
name|GripWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_GripRec
modifier|*
name|GripWidget
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawGrip_h */
end_comment

end_unit

