begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XcmsStCols.c,v 1.7 91/05/13 23:29:57 rws Exp $" */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *	NAME  *		XcmsStCols.c  *  *	DESCRIPTION  *		Source for XcmsStoreColors  *  *  */
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
comment|/*  *	NAME  *		XcmsStoreColors - Store Colors  *  *	SYNOPSIS  */
end_comment

begin_function
name|Status
name|XcmsStoreColors
parameter_list|(
name|dpy
parameter_list|,
name|colormap
parameter_list|,
name|pColors_in
parameter_list|,
name|nColors
parameter_list|,
name|pCompressed
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
name|pColors_in
decl_stmt|;
name|unsigned
name|int
name|nColors
decl_stmt|;
name|Bool
modifier|*
name|pCompressed
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Given device-dependent or device-independent color  *		specifications, this routine will convert them to X RGB  *		values then use it in a call to XStoreColors.  *  *	RETURNS  *		XcmsFailure if failed;  *		XcmsSuccess if it succeeded without gamut compression;  *		XcmsSuccessWithCompression if it succeeded with gamut  *			compression;  *  *		Since XStoreColors has no return value, this routine  *		does not return color specifications of the colors actually  *		stored.  */
block|{
name|XcmsColor
name|Color1
decl_stmt|;
name|XcmsColor
modifier|*
name|pColors_tmp
decl_stmt|;
name|Status
name|retval
decl_stmt|;
comment|/*      * Make copy of array of color specifications so we don't      * overwrite the contents.      */
if|if
condition|(
name|nColors
operator|>
literal|1
condition|)
block|{
name|pColors_tmp
operator|=
operator|(
name|XcmsColor
operator|*
operator|)
name|Xmalloc
argument_list|(
name|nColors
operator|*
sizeof|sizeof
argument_list|(
name|XcmsColor
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|pColors_tmp
operator|=
operator|&
name|Color1
expr_stmt|;
block|}
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pColors_in
argument_list|,
operator|(
name|char
operator|*
operator|)
name|pColors_tmp
argument_list|,
name|nColors
operator|*
sizeof|sizeof
argument_list|(
name|XcmsColor
argument_list|)
argument_list|)
expr_stmt|;
comment|/*      * Call routine to store colors using the copied color structures      */
name|retval
operator|=
name|_XcmsSetGetColors
argument_list|(
name|XStoreColors
argument_list|,
name|dpy
argument_list|,
name|colormap
argument_list|,
name|pColors_tmp
argument_list|,
name|nColors
argument_list|,
name|XcmsRGBFormat
argument_list|,
name|pCompressed
argument_list|)
expr_stmt|;
comment|/*      * Free copies as needed.      */
if|if
condition|(
name|nColors
operator|>
literal|1
condition|)
block|{
name|Xfree
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pColors_tmp
argument_list|)
expr_stmt|;
block|}
comment|/*      * Ah, finally return.      */
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

end_unit

