begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: ShellP.h,v 1.30 91/01/11 16:41:19 converse Exp $ * $oHeader: ShellP.h,v 1.2 88/08/18 15:56:19 asente Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*   * ShellP.h - Private definitions for Shell widget  *   * Author:	Paul Asente  * 		Digital Equipment Corporation  * 		Western Software Laboratory  * Date:	Thu Dec 3, 1987  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtShellPrivate_h
end_ifndef

begin_define
define|#
directive|define
name|_XtShellPrivate_h
end_define

begin_include
include|#
directive|include
file|<X11/Shell.h>
end_include

begin_comment
comment|/* *****  * ***** VendorP.h is included later on; it needs fields defined in the first  * ***** part of this header file  * *****  */
end_comment

begin_comment
comment|/***********************************************************************  *  * Shell Widget Private Data  *  ***********************************************************************/
end_comment

begin_comment
comment|/* New fields for the Shell widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|ShellClassPart
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
comment|/* NULLQUARK; on ShellClassPart */
name|long
name|version
decl_stmt|;
comment|/* must be XtShellExtensionVersion */
name|Cardinal
name|record_size
decl_stmt|;
comment|/* sizeof(ShellClassExtensionRec) */
name|XtGeometryHandler
name|root_geometry_manager
decl_stmt|;
block|}
name|ShellClassExtensionRec
operator|,
typedef|*
name|ShellClassExtension
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XtShellExtensionVersion
value|1L
end_define

begin_define
define|#
directive|define
name|XtInheritRootGeometryManager
value|((XtGeometryHandler)_XtInherit)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ShellClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ShellClassPart
name|shell_class
decl_stmt|;
block|}
name|ShellClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|ShellClassRec
name|shellClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the shell widget */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|geometry
decl_stmt|;
name|XtCreatePopupChildProc
name|create_popup_child_proc
decl_stmt|;
name|XtGrabKind
name|grab_kind
decl_stmt|;
name|Boolean
name|spring_loaded
decl_stmt|;
name|Boolean
name|popped_up
decl_stmt|;
name|Boolean
name|allow_shell_resize
decl_stmt|;
name|Boolean
name|client_specified
decl_stmt|;
comment|/* re-using old name */
define|#
directive|define
name|_XtShellPositionValid
value|((Boolean)(1<<0))
define|#
directive|define
name|_XtShellNotReparented
value|((Boolean)(1<<1))
define|#
directive|define
name|_XtShellPPositionOK
value|((Boolean)(1<<2))
define|#
directive|define
name|_XtShellGeometryParsed
value|((Boolean)(1<<3))
name|Boolean
name|save_under
decl_stmt|;
name|Boolean
name|override_redirect
decl_stmt|;
name|XtCallbackList
name|popup_callback
decl_stmt|;
name|XtCallbackList
name|popdown_callback
decl_stmt|;
name|Visual
modifier|*
name|visual
decl_stmt|;
block|}
name|ShellPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ShellPart
name|shell
decl_stmt|;
block|}
name|ShellRec
operator|,
typedef|*
name|ShellWidget
typedef|;
end_typedef

begin_comment
comment|/***********************************************************************  *  * OverrideShell Widget Private Data  *  ***********************************************************************/
end_comment

begin_comment
comment|/* New fields for the OverrideShell widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|OverrideShellClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_OverrideShellClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ShellClassPart
name|shell_class
decl_stmt|;
name|OverrideShellClassPart
name|override_shell_class
decl_stmt|;
block|}
name|OverrideShellClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|OverrideShellClassRec
name|overrideShellClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No new fields for the override shell widget */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|frabjous
decl_stmt|;
block|}
name|OverrideShellPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ShellPart
name|shell
decl_stmt|;
name|OverrideShellPart
name|override
decl_stmt|;
block|}
name|OverrideShellRec
operator|,
typedef|*
name|OverrideShellWidget
typedef|;
end_typedef

begin_comment
comment|/***********************************************************************  *  * WMShell Widget Private Data  *  ***********************************************************************/
end_comment

begin_comment
comment|/* New fields for the WMShell widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|WMShellClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_WMShellClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ShellClassPart
name|shell_class
decl_stmt|;
name|WMShellClassPart
name|wm_shell_class
decl_stmt|;
block|}
name|WMShellClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|WMShellClassRec
name|wmShellClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the WM shell widget */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|title
decl_stmt|;
name|int
name|wm_timeout
decl_stmt|;
name|Boolean
name|wait_for_wm
decl_stmt|;
name|Boolean
name|transient
decl_stmt|;
name|Atom
name|wm_configure_denied
decl_stmt|,
name|wm_moved
decl_stmt|;
struct|struct
name|_OldXSizeHints
block|{
comment|/* pre-R4 Xlib structure */
name|long
name|flags
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
name|int
name|min_width
decl_stmt|,
name|min_height
decl_stmt|;
name|int
name|max_width
decl_stmt|,
name|max_height
decl_stmt|;
name|int
name|width_inc
decl_stmt|,
name|height_inc
decl_stmt|;
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|min_aspect
struct|,
name|max_aspect
struct|;
block|}
name|size_hints
struct|;
name|XWMHints
name|wm_hints
decl_stmt|;
name|int
name|base_width
decl_stmt|,
name|base_height
decl_stmt|;
name|int
name|win_gravity
decl_stmt|;
name|Atom
name|title_encoding
decl_stmt|;
block|}
name|WMShellPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ShellPart
name|shell
decl_stmt|;
name|WMShellPart
name|wm
decl_stmt|;
block|}
name|WMShellRec
operator|,
typedef|*
name|WMShellWidget
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<X11/VendorP.h>
end_include

begin_comment
comment|/***********************************************************************  *  * TransientShell Widget Private Data  *  ***********************************************************************/
end_comment

begin_comment
comment|/* New fields for the TransientShell widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|TransientShellClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TransientShellClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ShellClassPart
name|shell_class
decl_stmt|;
name|WMShellClassPart
name|wm_shell_class
decl_stmt|;
name|VendorShellClassPart
name|vendor_shell_class
decl_stmt|;
name|TransientShellClassPart
name|transient_shell_class
decl_stmt|;
block|}
name|TransientShellClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|TransientShellClassRec
name|transientShellClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the transient shell widget */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Widget
name|transient_for
decl_stmt|;
block|}
name|TransientShellPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ShellPart
name|shell
decl_stmt|;
name|WMShellPart
name|wm
decl_stmt|;
name|VendorShellPart
name|vendor
decl_stmt|;
name|TransientShellPart
name|transient
decl_stmt|;
block|}
name|TransientShellRec
operator|,
typedef|*
name|TransientShellWidget
typedef|;
end_typedef

begin_comment
comment|/***********************************************************************  *  * TopLevelShell Widget Private Data  *  ***********************************************************************/
end_comment

begin_comment
comment|/* New fields for the TopLevelShell widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|TopLevelShellClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TopLevelShellClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ShellClassPart
name|shell_class
decl_stmt|;
name|WMShellClassPart
name|wm_shell_class
decl_stmt|;
name|VendorShellClassPart
name|vendor_shell_class
decl_stmt|;
name|TopLevelShellClassPart
name|top_level_shell_class
decl_stmt|;
block|}
name|TopLevelShellClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|TopLevelShellClassRec
name|topLevelShellClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the top level shell widget */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|icon_name
decl_stmt|;
name|Boolean
name|iconic
decl_stmt|;
name|Atom
name|icon_name_encoding
decl_stmt|;
block|}
name|TopLevelShellPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ShellPart
name|shell
decl_stmt|;
name|WMShellPart
name|wm
decl_stmt|;
name|VendorShellPart
name|vendor
decl_stmt|;
name|TopLevelShellPart
name|topLevel
decl_stmt|;
block|}
name|TopLevelShellRec
operator|,
typedef|*
name|TopLevelShellWidget
typedef|;
end_typedef

begin_comment
comment|/***********************************************************************  *  * ApplicationShell Widget Private Data  *  ***********************************************************************/
end_comment

begin_comment
comment|/* New fields for the ApplicationShell widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|ApplicationShellClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ApplicationShellClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ShellClassPart
name|shell_class
decl_stmt|;
name|WMShellClassPart
name|wm_shell_class
decl_stmt|;
name|VendorShellClassPart
name|vendor_shell_class
decl_stmt|;
name|TopLevelShellClassPart
name|top_level_shell_class
decl_stmt|;
name|ApplicationShellClassPart
name|application_shell_class
decl_stmt|;
block|}
name|ApplicationShellClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|ApplicationShellClassRec
name|applicationShellClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the application shell widget */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|c_plusplus
argument_list|)
name|char
modifier|*
name|c_class
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|class
decl_stmt|;
endif|#
directive|endif
name|XrmClass
name|xrm_class
decl_stmt|;
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|}
name|ApplicationShellPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ShellPart
name|shell
decl_stmt|;
name|WMShellPart
name|wm
decl_stmt|;
name|VendorShellPart
name|vendor
decl_stmt|;
name|TopLevelShellPart
name|topLevel
decl_stmt|;
name|ApplicationShellPart
name|application
decl_stmt|;
block|}
name|ApplicationShellRec
operator|,
typedef|*
name|ApplicationShellWidget
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtShellPrivate_h */
end_comment

end_unit

