begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XcmsQuCols.c,v 1.4 91/05/13 23:28:26 rws Exp $" */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *	NAME  *		XcmsQuCol.c  *  *	DESCRIPTION  *		Source for XcmsQueryColors  *  *  */
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
comment|/*  *	NAME  *		XcmsQueryColors - Query Colors  *  *	SYNOPSIS  */
end_comment

begin_function
name|Status
name|XcmsQueryColors
parameter_list|(
name|dpy
parameter_list|,
name|colormap
parameter_list|,
name|pXcmsColors_in_out
parameter_list|,
name|nColors
parameter_list|,
name|result_format
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
name|pXcmsColors_in_out
decl_stmt|;
name|unsigned
name|int
name|nColors
decl_stmt|;
name|XcmsColorFormat
name|result_format
decl_stmt|;
comment|/*  *	DESCRIPTION  *		This routine uses XQueryColors to obtain the X RGB values  *		stored in the specified colormap for the specified pixels.  *		The X RGB values are then converted to the target format as  *		specified by the format component of the XcmsColor structure.  *  *	RETURNS  *		XcmsFailure if failed;  *		XcmsSuccess if it succeeded.  *  *		Returns the color specifications of the colors stored in the  *		specified pixels.  */
block|{
return|return
operator|(
name|_XcmsSetGetColors
argument_list|(
name|XQueryColors
argument_list|,
name|dpy
argument_list|,
name|colormap
argument_list|,
name|pXcmsColors_in_out
argument_list|,
name|nColors
argument_list|,
name|result_format
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

