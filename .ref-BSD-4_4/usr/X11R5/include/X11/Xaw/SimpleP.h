begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************************   $XConsortium: SimpleP.h,v 1.10 90/03/05 17:47:33 kit Exp $   Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SimpleP_h
end_ifndef

begin_define
define|#
directive|define
name|_SimpleP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Simple.h>
end_include

begin_comment
comment|/* #include<X11/CoreP.h> */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Boolean
function_decl|(
modifier|*
name|change_sensitive
function_decl|)
parameter_list|(
comment|/* widget */
parameter_list|)
function_decl|;
block|}
name|SimpleClassPart
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XtInheritChangeSensitive
value|((Boolean (*)())_XtInherit)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SimpleClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
block|}
name|SimpleClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SimpleClassRec
name|simpleClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|Cursor
name|cursor
decl_stmt|;
name|Pixmap
name|insensitive_border
decl_stmt|;
name|String
name|cursor_name
decl_stmt|;
comment|/* cursor specified by name. */
name|Pixel
name|pointer_fg
decl_stmt|,
name|pointer_bg
decl_stmt|;
comment|/* Pointer colors. */
comment|/* private state */
block|}
name|SimplePart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SimpleRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
block|}
name|SimpleRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SimpleP_h */
end_comment

end_unit

