begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: TextSrcP.h,v 1.18 91/02/20 17:58:06 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*   * TextSrcP.h - Private definitions for TextSrc object  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawTextSrcP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawTextSrcP_h
end_define

begin_comment
comment|/***********************************************************************  *  * TextSrc Object Private Data  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/ObjectP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/TextP.h>
end_include

begin_comment
comment|/* This source works with the Text widget. */
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/TextSrc.h>
end_include

begin_comment
comment|/************************************************************  *  * New fields for the TextSrc object class record.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TextSrcClassPart
block|{
name|XawTextPosition
function_decl|(
modifier|*
name|Read
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|Replace
function_decl|)
parameter_list|()
function_decl|;
name|XawTextPosition
function_decl|(
modifier|*
name|Scan
function_decl|)
parameter_list|()
function_decl|;
name|XawTextPosition
function_decl|(
modifier|*
name|Search
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|SetSelection
function_decl|)
parameter_list|()
function_decl|;
name|Boolean
function_decl|(
modifier|*
name|ConvertSelection
function_decl|)
parameter_list|()
function_decl|;
block|}
name|TextSrcClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TextSrcClassRec
block|{
name|ObjectClassPart
name|object_class
decl_stmt|;
name|TextSrcClassPart
name|textSrc_class
decl_stmt|;
block|}
name|TextSrcClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|TextSrcClassRec
name|textSrcClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the TextSrc object record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|XawTextEditType
name|edit_mode
decl_stmt|;
block|}
name|TextSrcPart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TextSrcRec
block|{
name|ObjectPart
name|object
decl_stmt|;
name|TextSrcPart
name|textSrc
decl_stmt|;
block|}
name|TextSrcRec
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  * Private declarations.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
name|Boolean
function_decl|(
modifier|*
name|_XawBooleanFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_XawIntFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|XawTextPosition
function_decl|(
modifier|*
name|_XawTextPositionFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|_XawTextVoidFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|XtInheritRead
value|((_XawTextPositionFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritReplace
value|((_XawIntFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritScan
value|((_XawTextPositionFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritSearch
value|((_XawTextPositionFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritSetSelection
value|((_XawTextVoidFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritConvertSelection
value|((_XawBooleanFunc) _XtInherit)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawTextSrcP_h */
end_comment

end_unit

