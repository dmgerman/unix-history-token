begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: TemplateP.h,v 1.6 91/03/13 20:12:07 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright	Massachusetts Institute of Technology	1987, 1988  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TemplateP_h
end_ifndef

begin_define
define|#
directive|define
name|_TemplateP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Template.h>
end_include

begin_comment
comment|/* include superclass private header file */
end_comment

begin_include
include|#
directive|include
file|<X11/CoreP.h>
end_include

begin_comment
comment|/* define unique representation types not found in<X11/StringDefs.h> */
end_comment

begin_define
define|#
directive|define
name|XtRTemplateResource
value|"TemplateResource"
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|TemplateClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TemplateClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|TemplateClassPart
name|template_class
decl_stmt|;
block|}
name|TemplateClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|TemplateClassRec
name|templateClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|char
modifier|*
name|resource
decl_stmt|;
comment|/* private state */
block|}
name|TemplatePart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TemplateRec
block|{
name|CorePart
name|core
decl_stmt|;
name|TemplatePart
name|template
decl_stmt|;
block|}
name|TemplateRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TemplateP_h */
end_comment

end_unit

