begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XcmsSetCCC.c,v 1.3 91/07/09 14:18:07 rws Exp $ */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *	NAME  *		XcmsSetCCC.c - Color Conversion Context Setting Routines  *  *	DESCRIPTION  *		Routines to set components of a Color Conversion  *		Context structure.  *  *  */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
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
comment|/*  *	NAME  *		XcmsSetWhitePoint  *  *	SYNOPSIS  */
end_comment

begin_function
name|Status
name|XcmsSetWhitePoint
parameter_list|(
name|ccc
parameter_list|,
name|pColor
parameter_list|)
name|XcmsCCC
name|ccc
decl_stmt|;
name|XcmsColor
modifier|*
name|pColor
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Sets the Client White Point in the specified CCC.  *  *	RETURNS  *		Returns XcmsSuccess if succeeded; otherwise XcmsFailure.  *  */
block|{
if|if
condition|(
name|pColor
operator|==
name|NULL
operator|||
name|pColor
operator|->
name|format
operator|==
name|XcmsUndefinedFormat
condition|)
block|{
name|ccc
operator|->
name|clientWhitePt
operator|.
name|format
operator|=
name|XcmsUndefinedFormat
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pColor
operator|->
name|format
operator|!=
name|XcmsCIEXYZFormat
operator|&&
name|pColor
operator|->
name|format
operator|!=
name|XcmsCIEuvYFormat
operator|&&
name|pColor
operator|->
name|format
operator|!=
name|XcmsCIExyYFormat
condition|)
block|{
return|return
operator|(
name|XcmsFailure
operator|)
return|;
block|}
else|else
block|{
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pColor
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|ccc
operator|->
name|clientWhitePt
argument_list|,
sizeof|sizeof
argument_list|(
name|XcmsColor
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|XcmsSuccess
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *	NAME  *		XcmsSetCompressionProc  *  *	SYNOPSIS  */
end_comment

begin_function
name|XcmsCompressionProc
name|XcmsSetCompressionProc
parameter_list|(
name|ccc
parameter_list|,
name|compression_proc
parameter_list|,
name|client_data
parameter_list|)
name|XcmsCCC
name|ccc
decl_stmt|;
name|XcmsCompressionProc
name|compression_proc
decl_stmt|;
name|XPointer
name|client_data
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Set the specified CCC's compression function and client data.  *  *	RETURNS  *		Returns the old compression function.  *  */
block|{
name|XcmsCompressionProc
name|old
init|=
name|ccc
operator|->
name|gamutCompProc
decl_stmt|;
name|ccc
operator|->
name|gamutCompProc
operator|=
name|compression_proc
expr_stmt|;
name|ccc
operator|->
name|gamutCompClientData
operator|=
name|client_data
expr_stmt|;
return|return
operator|(
name|old
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *	NAME  *		XcmsSetWhiteAdjustProc  *  *	SYNOPSIS  */
end_comment

begin_function
name|XcmsWhiteAdjustProc
name|XcmsSetWhiteAdjustProc
parameter_list|(
name|ccc
parameter_list|,
name|white_adjust_proc
parameter_list|,
name|client_data
parameter_list|)
name|XcmsCCC
name|ccc
decl_stmt|;
name|XcmsWhiteAdjustProc
name|white_adjust_proc
decl_stmt|;
name|XPointer
name|client_data
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Set the specified CCC's white_adjust function and client data.  *  *	RETURNS  *		Returns the old white_adjust function.  *  */
block|{
name|XcmsWhiteAdjustProc
name|old
init|=
name|ccc
operator|->
name|whitePtAdjProc
decl_stmt|;
name|ccc
operator|->
name|whitePtAdjProc
operator|=
name|white_adjust_proc
expr_stmt|;
name|ccc
operator|->
name|whitePtAdjClientData
operator|=
name|client_data
expr_stmt|;
return|return
operator|(
name|old
operator|)
return|;
block|}
end_function

end_unit

