begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: WidgetNode.h,v 1.7 91/07/22 23:46:16 converse Exp $  *  * Copyright 1990 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Jim Fulton, MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XmuWidgetNode_h
end_ifndef

begin_define
define|#
directive|define
name|_XmuWidgetNode_h
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/*  * This is usually initialized by setting the first two fields and letting  * rest be implicitly nulled (by genlist.sh, for example)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XmuWidgetNode
block|{
name|char
modifier|*
name|label
decl_stmt|;
comment|/* mixed case name */
name|WidgetClass
modifier|*
name|widget_class_ptr
decl_stmt|;
comment|/* addr of widget class */
name|struct
name|_XmuWidgetNode
modifier|*
name|superclass
decl_stmt|;
comment|/* superclass of widget_class */
name|struct
name|_XmuWidgetNode
modifier|*
name|children
decl_stmt|,
modifier|*
name|siblings
decl_stmt|;
comment|/* subclass links */
name|char
modifier|*
name|lowered_label
decl_stmt|;
comment|/* lowercase version of label */
name|char
modifier|*
name|lowered_classname
decl_stmt|;
comment|/* lowercase version of class_name */
name|Bool
name|have_resources
decl_stmt|;
comment|/* resources have been fetched */
name|XtResourceList
name|resources
decl_stmt|;
comment|/* extracted resource database */
name|struct
name|_XmuWidgetNode
modifier|*
modifier|*
name|resourcewn
decl_stmt|;
comment|/* where resources come from */
name|Cardinal
name|nresources
decl_stmt|;
comment|/* number of resources */
name|XtResourceList
name|constraints
decl_stmt|;
comment|/* extracted constraint resources */
name|struct
name|_XmuWidgetNode
modifier|*
modifier|*
name|constraintwn
decl_stmt|;
comment|/* where constraints come from */
name|Cardinal
name|nconstraints
decl_stmt|;
comment|/* number of constraint resources */
name|XtPointer
name|data
decl_stmt|;
comment|/* extra data */
block|}
name|XmuWidgetNode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XmuWnClass
parameter_list|(
name|wn
parameter_list|)
value|((wn)->widget_class_ptr[0])
end_define

begin_define
define|#
directive|define
name|XmuWnClassname
parameter_list|(
name|wn
parameter_list|)
value|(XmuWnClass(wn)->core_class.class_name)
end_define

begin_define
define|#
directive|define
name|XmuWnSuperclass
parameter_list|(
name|wn
parameter_list|)
value|((XmuWnClass(wn))->core_class.superclass)
end_define

begin_comment
comment|/* external interfaces */
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XmuWnInitializeNodes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuWidgetNode
modifier|*
comment|/* nodearray */
parameter_list|,
name|int
comment|/* nnodes */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmuWnFetchResources
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuWidgetNode
modifier|*
comment|/* node */
parameter_list|,
name|Widget
comment|/* toplevel */
parameter_list|,
name|XmuWidgetNode
modifier|*
comment|/* topnode */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XmuWnCountOwnedResources
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuWidgetNode
modifier|*
comment|/* node */
parameter_list|,
name|XmuWidgetNode
modifier|*
comment|/* ownernode */
parameter_list|,
name|Bool
comment|/* constraints */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XmuWidgetNode
modifier|*
name|XmuWnNameToNode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuWidgetNode
modifier|*
comment|/* nodelist */
parameter_list|,
name|int
comment|/* nnodes */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XmuWidgetNode_h */
end_comment

end_unit

