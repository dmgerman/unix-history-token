begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Template.c,v 1.4 91/02/17 16:18:42 converse Exp $ */
end_comment

begin_comment
comment|/* Copyright	Massachusetts Institute of Technology	1987, 1988  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  */
end_comment

begin_include
include|#
directive|include
file|<X11/IntrinsicP.h>
end_include

begin_include
include|#
directive|include
file|<X11/StringDefs.h>
end_include

begin_include
include|#
directive|include
file|"TemplateP.h"
end_include

begin_decl_stmt
specifier|static
name|XtResource
name|resources
index|[]
init|=
block|{
define|#
directive|define
name|offset
parameter_list|(
name|field
parameter_list|)
value|XtOffsetOf(TemplateRec, template.field)
comment|/* {name, class, type, size, offset, default_type, default_addr}, */
block|{
name|XtNtemplateResource
block|,
name|XtCTemplateResource
block|,
name|XtRTemplateResource
block|,
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
block|,
name|offset
argument_list|(
name|resource
argument_list|)
block|,
name|XtRString
block|,
operator|(
name|XtPointer
operator|)
literal|"default"
block|}
block|,
undef|#
directive|undef
name|offset
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|TemplateAction
parameter_list|(
comment|/* Widget, XEvent*, String*, Cardinal* */
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|XtActionsRec
name|actions
index|[]
init|=
block|{
comment|/* {name, procedure}, */
block|{
literal|"template"
block|,
name|TemplateAction
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|translations
index|[]
init|=
literal|"<Key>:		template()	\n\ "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateClassRec
name|templateClassRec
init|=
block|{
block|{
comment|/* core fields */
comment|/* superclass		*/
operator|(
name|WidgetClass
operator|)
operator|&
name|widgetClassRec
block|,
comment|/* class_name		*/
literal|"Template"
block|,
comment|/* widget_size		*/
sizeof|sizeof
argument_list|(
name|TemplateRec
argument_list|)
block|,
comment|/* class_initialize		*/
name|NULL
block|,
comment|/* class_part_initialize	*/
name|NULL
block|,
comment|/* class_inited		*/
name|FALSE
block|,
comment|/* initialize		*/
name|NULL
block|,
comment|/* initialize_hook		*/
name|NULL
block|,
comment|/* realize			*/
name|XtInheritRealize
block|,
comment|/* actions			*/
name|actions
block|,
comment|/* num_actions		*/
name|XtNumber
argument_list|(
name|actions
argument_list|)
block|,
comment|/* resources		*/
name|resources
block|,
comment|/* num_resources		*/
name|XtNumber
argument_list|(
name|resources
argument_list|)
block|,
comment|/* xrm_class		*/
name|NULLQUARK
block|,
comment|/* compress_motion		*/
name|TRUE
block|,
comment|/* compress_exposure	*/
name|TRUE
block|,
comment|/* compress_enterleave	*/
name|TRUE
block|,
comment|/* visible_interest		*/
name|FALSE
block|,
comment|/* destroy			*/
name|NULL
block|,
comment|/* resize			*/
name|NULL
block|,
comment|/* expose			*/
name|NULL
block|,
comment|/* set_values		*/
name|NULL
block|,
comment|/* set_values_hook		*/
name|NULL
block|,
comment|/* set_values_almost	*/
name|XtInheritSetValuesAlmost
block|,
comment|/* get_values_hook		*/
name|NULL
block|,
comment|/* accept_focus		*/
name|NULL
block|,
comment|/* version			*/
name|XtVersion
block|,
comment|/* callback_private		*/
name|NULL
block|,
comment|/* tm_table			*/
name|translations
block|,
comment|/* query_geometry		*/
name|XtInheritQueryGeometry
block|,
comment|/* display_accelerator	*/
name|XtInheritDisplayAccelerator
block|,
comment|/* extension		*/
name|NULL
block|}
block|,
block|{
comment|/* template fields */
comment|/* empty			*/
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WidgetClass
name|templateWidgetClass
init|=
operator|(
name|WidgetClass
operator|)
operator|&
name|templateClassRec
decl_stmt|;
end_decl_stmt

end_unit

