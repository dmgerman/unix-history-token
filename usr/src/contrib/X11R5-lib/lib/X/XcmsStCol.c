begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XcmsStCol.c,v 1.5 91/09/21 21:49:25 rws Exp $" */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *	NAME  *		XcmsStCol.c  *  *	DESCRIPTION  *		Source for XcmsStoreColor  *  *  */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_include
include|#
directive|include
file|"Xcmsint.h"
end_include

begin_escape
end_escape

begin_comment
comment|/************************************************************************  *									*  *			PUBLIC ROUTINES					*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  *	NAME  *		XcmsStoreColor - Store Color  *  *	SYNOPSIS  */
end_comment

begin_function
name|Status
name|XcmsStoreColor
parameter_list|(
name|dpy
parameter_list|,
name|colormap
parameter_list|,
name|pColor_in
parameter_list|)
name|Display
modifier|*
name|dpy
decl_stmt|;
name|Colormap
name|colormap
decl_stmt|;
name|XcmsColor
modifier|*
name|pColor_in
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Given a device-dependent or device-independent color  *		specification, this routine will convert it to X RGB  *		values then use it in a call to XStoreColor.  *  *	RETURNS  *		XcmsFailure if failed;  *		XcmsSuccess if it succeeded without gamut compression;  *		XcmsSuccessWithCompression if it succeeded with gamut  *			compression;  *  *		Since XStoreColor has no return value this routine  *		does not return the color specification of the color actually  *		stored.  */
block|{
name|XcmsColor
name|tmpColor
decl_stmt|;
name|tmpColor
operator|=
operator|*
name|pColor_in
expr_stmt|;
return|return
operator|(
name|_XcmsSetGetColors
argument_list|(
name|XStoreColor
argument_list|,
name|dpy
argument_list|,
name|colormap
argument_list|,
operator|&
name|tmpColor
argument_list|,
literal|1
argument_list|,
name|XcmsRGBFormat
argument_list|,
operator|(
name|Bool
operator|*
operator|)
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

