begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: ConstrainP.h,v 1.14 89/10/04 12:22:33 swick Exp $ */
end_comment

begin_comment
comment|/* $oHeader: ConstrainP.h,v 1.2 88/08/18 15:54:15 asente Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtConstraintP_h
end_ifndef

begin_define
define|#
directive|define
name|_XtConstraintP_h
end_define

begin_include
include|#
directive|include
file|<X11/Constraint.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_ConstraintPart
block|{
name|XtPointer
name|mumble
decl_stmt|;
comment|/* No new fields, keep C compiler happy */
block|}
name|ConstraintPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ConstraintRec
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
block|}
name|ConstraintRec
operator|,
typedef|*
name|ConstraintWidget
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ConstraintClassPart
block|{
name|XtResourceList
name|resources
decl_stmt|;
comment|/* constraint resource list	     */
name|Cardinal
name|num_resources
decl_stmt|;
comment|/* number of constraints in list       */
name|Cardinal
name|constraint_size
decl_stmt|;
comment|/* size of constraint record           */
name|XtInitProc
name|initialize
decl_stmt|;
comment|/* constraint initialization           */
name|XtWidgetProc
name|destroy
decl_stmt|;
comment|/* constraint destroy proc             */
name|XtSetValuesFunc
name|set_values
decl_stmt|;
comment|/* constraint set_values proc          */
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|ConstraintClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtPointer
name|next_extension
decl_stmt|;
comment|/* 1st 4 mandated for all extension records */
name|XrmQuark
name|record_type
decl_stmt|;
comment|/* NULLQUARK; on ConstraintClassPart */
name|long
name|version
decl_stmt|;
comment|/* must be XtConstraintExtensionVersion */
name|Cardinal
name|record_size
decl_stmt|;
comment|/* sizeof(ConstraintClassExtensionRec) */
name|XtArgsProc
name|get_values_hook
decl_stmt|;
block|}
name|ConstraintClassExtensionRec
operator|,
typedef|*
name|ConstraintClassExtension
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ConstraintClassRec
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
block|}
name|ConstraintClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|ConstraintClassRec
name|constraintClassRec
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XtConstraintExtensionVersion
value|1L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtConstraintP_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

