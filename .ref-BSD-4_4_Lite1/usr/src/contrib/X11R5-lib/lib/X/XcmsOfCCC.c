begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XcmsOfCCC.c,v 1.1 91/05/13 22:37:17 rws Exp $ */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *	NAME  *		XcmsOfCCC.c - Color Conversion Context Querying Routines  *  *	DESCRIPTION  *		Routines to query components of a Color Conversion  *		Context structure.  *  *  */
end_comment

begin_include
include|#
directive|include
file|"Xlib.h"
end_include

begin_include
include|#
directive|include
file|"Xcms.h"
end_include

begin_escape
end_escape

begin_comment
comment|/************************************************************************  *									*  *			PUBLIC INTERFACES				*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  *	NAME  *		XcmsDisplayOfCCC  *  *	SYNOPSIS  */
end_comment

begin_function
name|Display
modifier|*
name|XcmsDisplayOfCCC
parameter_list|(
name|ccc
parameter_list|)
name|XcmsCCC
name|ccc
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Queries the Display of the specified CCC.  *  *	RETURNS  *		Pointer to the Display.  *  */
block|{
return|return
operator|(
name|ccc
operator|->
name|dpy
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *	NAME  *		XcmsVisualOfCCC  *  *	SYNOPSIS  */
end_comment

begin_function
name|Visual
modifier|*
name|XcmsVisualOfCCC
parameter_list|(
name|ccc
parameter_list|)
name|XcmsCCC
name|ccc
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Queries the Visual of the specified CCC.  *  *	RETURNS  *		Pointer to the Visual.  *  */
block|{
return|return
operator|(
name|ccc
operator|->
name|visual
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *	NAME  *		XcmsScreenNumberOfCCC  *  *	SYNOPSIS  */
end_comment

begin_function
name|int
name|XcmsScreenNumberOfCCC
parameter_list|(
name|ccc
parameter_list|)
name|XcmsCCC
name|ccc
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Queries the screen number of the specified CCC.  *  *	RETURNS  *		screen number.  *  */
block|{
return|return
operator|(
name|ccc
operator|->
name|screenNumber
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *	NAME  *		XcmsScreenWhitePointOfCCC  *  *	SYNOPSIS  */
end_comment

begin_function
name|XcmsColor
modifier|*
name|XcmsScreenWhitePointOfCCC
parameter_list|(
name|ccc
parameter_list|)
name|XcmsCCC
name|ccc
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Queries the screen white point of the specified CCC.  *  *	RETURNS  *		Pointer to the XcmsColor containing the screen white point.  *  */
block|{
return|return
operator|(
operator|&
name|ccc
operator|->
name|pPerScrnInfo
operator|->
name|screenWhitePt
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *	NAME  *		XcmsClientWhitePointOfCCC  *  *	SYNOPSIS  */
end_comment

begin_function
name|XcmsColor
modifier|*
name|XcmsClientWhitePointOfCCC
parameter_list|(
name|ccc
parameter_list|)
name|XcmsCCC
name|ccc
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Queries the client white point of the specified CCC.  *  *	RETURNS  *		Pointer to the XcmsColor containing the client white point.  *  */
block|{
return|return
operator|(
operator|&
name|ccc
operator|->
name|clientWhitePt
operator|)
return|;
block|}
end_function

end_unit

