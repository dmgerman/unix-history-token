begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: CIELuvWpAj.c,v 1.4 91/05/13 22:22:56 rws Exp $" */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of XCMS based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *	NAME  *		CIELuvWpAj.c  *  *	DESCRIPTION  *		This file contains routine(s) that support white point  *		adjustment of color specifications in the CIE CIELuv.color  *		space.  */
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

begin_comment
comment|/*  *	EXTERNS  */
end_comment

begin_function_decl
specifier|extern
name|Status
name|_XcmsConvertColorsWithWhitePt
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/************************************************************************  *									*  *			 PUBLIC ROUTINES				*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  *	NAME  *		XcmsCIELuvWhiteShiftColors  *  *	SYNOPSIS  */
end_comment

begin_function
name|Status
name|XcmsCIELuvWhiteShiftColors
parameter_list|(
name|ccc
parameter_list|,
name|pWhitePtFrom
parameter_list|,
name|pWhitePtTo
parameter_list|,
name|destSpecFmt
parameter_list|,
name|pColors_in_out
parameter_list|,
name|nColors
parameter_list|,
name|pCompressed
parameter_list|)
name|XcmsCCC
name|ccc
decl_stmt|;
name|XcmsColor
modifier|*
name|pWhitePtFrom
decl_stmt|;
name|XcmsColor
modifier|*
name|pWhitePtTo
decl_stmt|;
name|XcmsColorFormat
name|destSpecFmt
decl_stmt|;
name|XcmsColor
modifier|*
name|pColors_in_out
decl_stmt|;
name|unsigned
name|int
name|nColors
decl_stmt|;
name|Bool
modifier|*
name|pCompressed
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Adjusts color specifications in an array of XcmsColor  *		structures for white point differences.  *  *	RETURNS  *		XcmsFailure if failed,  *		XcmsSuccess if succeeded without gamut compression,  *		XcmsSuccessWithCompression if succeeded with  *			gamut compression.  */
block|{
if|if
condition|(
name|pWhitePtFrom
operator|==
name|NULL
operator|||
name|pWhitePtTo
operator|==
name|NULL
operator|||
name|pColors_in_out
operator|==
name|NULL
condition|)
block|{
return|return
operator|(
name|XcmsFailure
operator|)
return|;
block|}
comment|/*      * Convert to CIELuv using pWhitePtFrom      *    We can ignore return value for compression because we are converting      *    to XcmsCIELuvFormat which is device-independent, not device-dependent.      */
if|if
condition|(
name|_XcmsConvertColorsWithWhitePt
argument_list|(
name|ccc
argument_list|,
name|pColors_in_out
argument_list|,
name|pWhitePtFrom
argument_list|,
name|nColors
argument_list|,
name|XcmsCIELuvFormat
argument_list|,
name|pCompressed
argument_list|)
operator|==
name|XcmsFailure
condition|)
block|{
return|return
operator|(
name|XcmsFailure
operator|)
return|;
block|}
comment|/*      * Convert from CIELuv to destSpecFmt using pWhitePtTo      */
return|return
operator|(
name|_XcmsConvertColorsWithWhitePt
argument_list|(
name|ccc
argument_list|,
name|pColors_in_out
argument_list|,
name|pWhitePtTo
argument_list|,
name|nColors
argument_list|,
name|destSpecFmt
argument_list|,
name|pCompressed
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

