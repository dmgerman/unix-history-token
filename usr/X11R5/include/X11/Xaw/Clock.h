begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: Clock.h,v 1.29 90/10/22 14:43:12 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawClock_h
end_ifndef

begin_define
define|#
directive|define
name|_XawClock_h
end_define

begin_comment
comment|/***********************************************************************  *  * Clock Widget  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xmu/Converters.h>
end_include

begin_comment
comment|/* Parameters:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  analog		     Boolean		Boolean		True  background	     Background		Pixel		white  backingStore	     BackingStore	BackingStore	default  border		     BorderColor	Pixel		Black  borderWidth	     BorderWidth	Dimension	1  chime		     Boolean		Boolean		False  destroyCallback     Callback		Pointer		NULL  font		     Font		XFontStruct*	fixed  foreground	     Foreground		Pixel		black  hand		     Foreground		Pixel		black  height		     Height		Dimension	164  highlight	     Foreground		Pixel		black  mappedWhenManaged   MappedWhenManaged	Boolean		True  padding	     Margin		int		8  update		     Interval		int		60 (seconds)  width		     Width		Dimension	164  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_comment
comment|/* Resource names used to the clock widget */
end_comment

begin_comment
comment|/* color of hands */
end_comment

begin_define
define|#
directive|define
name|XtNhand
value|"hands"
end_define

begin_comment
comment|/* Boolean: digital if FALSE */
end_comment

begin_define
define|#
directive|define
name|XtNanalog
value|"analog"
end_define

begin_comment
comment|/* Boolean:  */
end_comment

begin_define
define|#
directive|define
name|XtNchime
value|"chime"
end_define

begin_comment
comment|/* Int: amount of space around outside of clock */
end_comment

begin_define
define|#
directive|define
name|XtNpadding
value|"padding"
end_define

begin_typedef
typedef|typedef
name|struct
name|_ClockRec
modifier|*
name|ClockWidget
typedef|;
end_typedef

begin_comment
comment|/* completely defined in ClockPrivate.h */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ClockClassRec
modifier|*
name|ClockWidgetClass
typedef|;
end_typedef

begin_comment
comment|/* completely defined in ClockPrivate.h */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|clockWidgetClass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawClock_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

