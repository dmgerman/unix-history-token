begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: VendorP.h,v 1.20 89/10/04 12:22:55 swick Exp $ * $oHeader: VendorP.h,v 1.2 88/08/18 15:56:48 asente Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*   * VendorP.h - Private definitions for VendorShell widget  *   * Author:	Paul Asente  * 		Digital Equipment Corporation  * 		Western Software Laboratory  * Date:	Thu Dec 3, 1987  */
end_comment

begin_comment
comment|/***********************************************************************  *  * VendorShell Widget Private Data  *  ***********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtVendorPrivate_h
end_ifndef

begin_define
define|#
directive|define
name|_XtVendorPrivate_h
end_define

begin_include
include|#
directive|include
file|<X11/Vendor.h>
end_include

begin_comment
comment|/* New fields for the VendorShell widget class record */
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
name|VendorShellClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_VendorShellClassRec
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
block|}
name|VendorShellClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|VendorShellClassRec
name|vendorShellClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the vendor shell widget. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|vendor_specific
decl_stmt|;
block|}
name|VendorShellPart
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
block|}
name|VendorShellRec
operator|,
typedef|*
name|VendorShellWidget
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtVendorPrivate_h */
end_comment

end_unit

