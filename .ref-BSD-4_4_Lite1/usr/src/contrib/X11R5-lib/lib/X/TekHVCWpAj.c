begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: TekHVCWpAj.c,v 1.4 91/05/13 22:48:45 rws Exp $" */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  TekColor is a  * trademark of Tektronix, Inc.  The term "TekHVC" designates a particular  * color space that is the subject of U.S. Patent No. 4,985,853 (equivalent  * foreign patents pending).  Permission is hereby granted to use, copy,  * modify, sell, and otherwise distribute this software and its  * documentation for any purpose and without fee, provided that:  *   * 1. This copyright, permission, and disclaimer notice is reproduced in  *    all copies of this software and any modification thereof and in  *    supporting documentation;   * 2. Any color-handling application which displays TekHVC color  *    cooordinates identifies these as TekHVC color coordinates in any  *    interface that displays these coordinates and in any associated  *    documentation;  * 3. The term "TekHVC" is always used, and is only used, in association  *    with the mathematical derivations of the TekHVC Color Space,  *    including those provided in this file and any equivalent pathways and  *    mathematical derivations, regardless of digital (e.g., floating point  *    or integer) representation.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *	DESCRIPTION  *		TekHVCWpAj.c  *  *	DESCRIPTION  *		This file contains routine(s) that support white point  *		adjustment of color specifications in the TekHVC color  *		space.  */
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

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsTekHVCColorSpace
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/************************************************************************  *									*  *			 PUBLIC ROUTINES				*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  *	NAME  *		XcmsTekHVCWhiteShiftColors  *  *	SYNOPSIS  */
end_comment

begin_function
name|Status
name|XcmsTekHVCWhiteShiftColors
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
comment|/*  *	DESCRIPTION  *		Convert color specifications in an array of XcmsColor structures  *		for differences in white points.  *  *	RETURNS  *		XcmsFailure if failed,  *		XcmsSuccess if succeeded without gamut compression,  *		XcmsSuccessWithCompression if succeeded with  *			gamut compression.  */
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
comment|/*      * Insure TekHVC installed      */
if|if
condition|(
name|XcmsAddColorSpace
argument_list|(
operator|&
name|XcmsTekHVCColorSpace
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
comment|/*      * Convert to TekHVC using pWhitePtFrom      *    We can ignore return value for compression because we are converting      *    to XcmsTekHVCFormat which is device-independent, not device-dependent.      */
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
name|XcmsTekHVCFormat
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
comment|/*      * Convert from TekHVC to destSpecFmt using pWhitePtTo      */
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

