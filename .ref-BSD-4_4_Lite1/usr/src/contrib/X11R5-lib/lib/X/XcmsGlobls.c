begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*$XConsortium: XcmsGlobls.c,v 1.8 91/07/25 01:08:47 rws Exp $ */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *	NAME  *		XcmsGlobls.c  *  *	DESCRIPTION  *		Source file containing TekCMS globals  *  *  */
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
comment|/*  *      EXTERNS  *              External declarations required locally to this package  *              that are not already declared in any of the included header  *		files (external includes or internal includes).  */
end_comment

begin_decl_stmt
specifier|extern
name|XcmsFunctionSet
name|XcmsLinearRGBFunctionSet
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|GRAY
end_ifdef

begin_decl_stmt
specifier|extern
name|XcmsFunctionSet
name|XcmsGrayFunctionSet
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GRAY */
end_comment

begin_comment
comment|/* UNDEFINED Color Space */
end_comment

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsUNDEFINEDColorSpace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CIE XYZ Color Space */
end_comment

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsCIEXYZColorSpace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CIE uvY Color Space */
end_comment

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsCIEuvYColorSpace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CIE xyY Color Space */
end_comment

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsCIExyYColorSpace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CIE Lab Color Space */
end_comment

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsCIELabColorSpace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CIE Luv Color Space */
end_comment

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsCIELuvColorSpace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TekHVC Color Space */
end_comment

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsTekHVCColorSpace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device Dependent Color Space Structures */
end_comment

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsRGBiColorSpace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|XcmsColorSpace
name|XcmsRGBColorSpace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      GLOBALS  *              Variables declared in this package that are allowed  *		to be used globally.  */
end_comment

begin_comment
comment|/*      * Initial array of Device Independent Color Spaces      */
end_comment

begin_decl_stmt
name|XcmsColorSpace
modifier|*
name|_XcmsDIColorSpacesInit
index|[]
init|=
block|{
operator|&
name|XcmsCIEXYZColorSpace
block|,
operator|&
name|XcmsCIEuvYColorSpace
block|,
operator|&
name|XcmsCIExyYColorSpace
block|,
operator|&
name|XcmsCIELabColorSpace
block|,
operator|&
name|XcmsCIELuvColorSpace
block|,
operator|&
name|XcmsTekHVCColorSpace
block|,
operator|&
name|XcmsUNDEFINEDColorSpace
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      * Pointer to the array of pointers to XcmsColorSpace structures for      * Device-Independent Color Spaces that are currently accessible by      * the color management system.  End of list is indicated by a NULL pointer.      */
end_comment

begin_decl_stmt
name|XcmsColorSpace
modifier|*
modifier|*
name|_XcmsDIColorSpaces
init|=
name|_XcmsDIColorSpacesInit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      * Initial array of Device Dependent Color Spaces      */
end_comment

begin_decl_stmt
name|XcmsColorSpace
modifier|*
name|_XcmsDDColorSpacesInit
index|[]
init|=
block|{
operator|&
name|XcmsRGBColorSpace
block|,
operator|&
name|XcmsRGBiColorSpace
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      * Pointer to the array of pointers to XcmsColorSpace structures for      * Device-Dependent Color Spaces that are currently accessible by      * the color management system.  End of list is indicated by a NULL pointer.      */
end_comment

begin_decl_stmt
name|XcmsColorSpace
modifier|*
modifier|*
name|_XcmsDDColorSpaces
init|=
operator|&
name|_XcmsDDColorSpacesInit
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      * Initial array of Screen Color Characterization Function Sets      */
end_comment

begin_decl_stmt
name|XcmsFunctionSet
modifier|*
name|_XcmsSCCFuncSetsInit
index|[]
init|=
block|{
operator|&
name|XcmsLinearRGBFunctionSet
block|,
ifdef|#
directive|ifdef
name|GRAY
operator|&
name|XcmsGrayFunctionSet
block|,
endif|#
directive|endif
comment|/* GRAY */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      * Pointer to the array of pointers to XcmsSCCFuncSet structures      * (Screen Color Characterization Function Sets) that are currently      * accessible by the color management system.  End of list is      * indicated by a NULL pointer.      */
end_comment

begin_decl_stmt
name|XcmsFunctionSet
modifier|*
modifier|*
name|_XcmsSCCFuncSets
init|=
name|_XcmsSCCFuncSetsInit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      * X Consortium Registered Device-Independent Color Spaces      *	Note that prefix must be in lowercase.      */
end_comment

begin_decl_stmt
name|char
name|XcmsCIEXYZ_prefix
index|[]
init|=
literal|"ciexyz"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|XcmsCIEuvY_prefix
index|[]
init|=
literal|"cieuvy"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|XcmsCIExyY_prefix
index|[]
init|=
literal|"ciexyy"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|XcmsCIELab_prefix
index|[]
init|=
literal|"cielab"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|XcmsCIELuv_prefix
index|[]
init|=
literal|"cieluv"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|XcmsTekHVC_prefix
index|[]
init|=
literal|"tekhvc"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      * Registered Device-Dependent Color Spaces      */
end_comment

begin_decl_stmt
name|char
name|XcmsRGBi_prefix
index|[]
init|=
literal|"rgbi"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|XcmsRGB_prefix
index|[]
init|=
literal|"rgb"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XcmsRegColorSpaceEntry
name|_XcmsRegColorSpaces
index|[]
init|=
block|{
name|XcmsCIEXYZ_prefix
block|,
name|XcmsCIEXYZFormat
block|,
name|XcmsCIEuvY_prefix
block|,
name|XcmsCIEuvYFormat
block|,
name|XcmsCIExyY_prefix
block|,
name|XcmsCIExyYFormat
block|,
name|XcmsCIELab_prefix
block|,
name|XcmsCIELabFormat
block|,
name|XcmsCIELuv_prefix
block|,
name|XcmsCIELuvFormat
block|,
name|XcmsTekHVC_prefix
block|,
name|XcmsTekHVCFormat
block|,
name|XcmsRGB_prefix
block|,
name|XcmsRGBFormat
block|,
name|XcmsRGBi_prefix
block|,
name|XcmsRGBiFormat
block|,
name|NULL
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

