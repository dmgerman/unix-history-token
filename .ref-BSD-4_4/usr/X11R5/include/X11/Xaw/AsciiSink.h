begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: AsciiSink.h,v 1.7 90/12/01 13:01:31 rws Exp $  */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawAsciiSink_h
end_ifndef

begin_define
define|#
directive|define
name|_XawAsciiSink_h
end_define

begin_comment
comment|/***********************************************************************  *  * AsciiSink Object  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/TextSink.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  echo                Output             Boolean         True  displayNonprinting  Output             Boolean         True  */
end_comment

begin_define
define|#
directive|define
name|XtCOutput
value|"Output"
end_define

begin_define
define|#
directive|define
name|XtNdisplayNonprinting
value|"displayNonprinting"
end_define

begin_define
define|#
directive|define
name|XtNecho
value|"echo"
end_define

begin_comment
comment|/* Class record constants */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|asciiSinkObjectClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_AsciiSinkClassRec
modifier|*
name|AsciiSinkObjectClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_AsciiSinkRec
modifier|*
name|AsciiSinkObject
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  * Public Functions.  *  ************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawAsciiSrc_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

