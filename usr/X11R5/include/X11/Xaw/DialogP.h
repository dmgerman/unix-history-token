begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: DialogP.h,v 1.12 89/08/25 18:35:37 kit Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/* Private definitions for Dialog widget */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DialogP_h
end_ifndef

begin_define
define|#
directive|define
name|_DialogP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Dialog.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/FormP.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|DialogClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DialogClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ConstraintClassPart
name|constraint_class
decl_stmt|;
name|FormClassPart
name|form_class
decl_stmt|;
name|DialogClassPart
name|dialog_class
decl_stmt|;
block|}
name|DialogClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|DialogClassRec
name|dialogClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|_DialogPart
block|{
comment|/* resources */
name|String
name|label
decl_stmt|;
comment|/* description of the dialog	*/
name|String
name|value
decl_stmt|;
comment|/* for the user response	*/
name|Pixmap
name|icon
decl_stmt|;
comment|/* icon bitmap			*/
comment|/* private data */
name|Widget
name|iconW
decl_stmt|;
comment|/* widget to display the icon	*/
name|Widget
name|labelW
decl_stmt|;
comment|/* widget to display description*/
name|Widget
name|valueW
decl_stmt|;
comment|/* user response TextWidget	*/
block|}
name|DialogPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DialogRec
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ConstraintPart
name|constraint
decl_stmt|;
name|FormPart
name|form
decl_stmt|;
name|DialogPart
name|dialog
decl_stmt|;
block|}
name|DialogRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|DialogConstraintsPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DialogConstraintsRec
block|{
name|FormConstraintsPart
name|form
decl_stmt|;
name|DialogConstraintsPart
name|dialog
decl_stmt|;
block|}
name|DialogConstraintsRec
operator|,
typedef|*
name|DialogConstraints
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DialogP_h */
end_comment

end_unit

