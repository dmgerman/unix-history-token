begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Composite.h,v 1.12 91/10/24 13:19:40 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtComposite_h
end_ifndef

begin_define
define|#
directive|define
name|_XtComposite_h
end_define

begin_typedef
typedef|typedef
name|struct
name|_CompositeClassRec
modifier|*
name|CompositeWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Cardinal
function_decl|(
modifier|*
name|XtOrderProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* child */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XtManageChildren
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|WidgetList
comment|/* children */
parameter_list|,
name|Cardinal
comment|/* num_children */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtManageChild
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* child */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtUnmanageChildren
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|WidgetList
comment|/* children */
parameter_list|,
name|Cardinal
comment|/* num_children */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtUnmanageChild
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* child */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|_XFUNCPROTOEND
ifndef|#
directive|ifndef
name|COMPOSITE
name|externalref
name|WidgetClass
name|compositeWidgetClass
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
comment|/* _XtComposite_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

