begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Template.h,v 1.5 90/12/19 18:46:00 converse Exp $ */
end_comment

begin_comment
comment|/* Copyright	Massachusetts Institute of Technology	1987, 1988  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Template_h
end_ifndef

begin_define
define|#
directive|define
name|_Template_h
end_define

begin_comment
comment|/****************************************************************  *  * Template widget  *  ****************************************************************/
end_comment

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		Pixel		XtDefaultBackground  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  destroyCallback     Callback		Pointer		NULL  height		     Height		Dimension	0  mappedWhenManaged   MappedWhenManaged	Boolean		True  sensitive	     Sensitive		Boolean		True  width		     Width		Dimension	0  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_comment
comment|/* define any special resource names here that are not in<X11/StringDefs.h> */
end_comment

begin_define
define|#
directive|define
name|XtNtemplateResource
value|"templateResource"
end_define

begin_define
define|#
directive|define
name|XtCTemplateResource
value|"TemplateResource"
end_define

begin_comment
comment|/* declare specific TemplateWidget class and instance datatypes */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_TemplateClassRec
modifier|*
name|TemplateWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_TemplateRec
modifier|*
name|TemplateWidget
typedef|;
end_typedef

begin_comment
comment|/* declare the class constant */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|templateWidgetClass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _Template_h */
end_comment

end_unit

