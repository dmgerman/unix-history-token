begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: CIEXYZ.c,v 1.6 91/07/25 01:07:49 rws Exp $" */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of XCMS based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *  *	NAME  *		CIEXYZ.c  *  *	DESCRIPTION  *		CIE XYZ Color Space  *  *  */
end_comment

begin_include
include|#
directive|include
file|<X11/Xos.h>
end_include

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
name|char
name|XcmsCIEXYZ_prefix
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	DEFINES  *		Internal definitions that need NOT be exported to any package  *		or program using this package.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DBL_EPSILON
end_ifdef

begin_define
define|#
directive|define
name|XMY_DBL_EPSILON
value|DBL_EPSILON
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XMY_DBL_EPSILON
value|0.00001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *      FORWARD DECLARATIONS  */
end_comment

begin_function_decl
specifier|static
name|int
name|CIEXYZ_ParseString
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XcmsCIEXYZ_ValidSpec
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *      LOCALS VARIABLES  */
end_comment

begin_decl_stmt
specifier|static
name|XcmsConversionProc
name|Fl_CIEXYZ_to_CIEXYZ
index|[]
init|=
block|{
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      GLOBALS  *              Variables declared in this package that are allowed  *		to be used globally.  */
end_comment

begin_comment
comment|/*      * CIE XYZ Color Space      */
end_comment

begin_decl_stmt
name|XcmsColorSpace
name|XcmsCIEXYZColorSpace
init|=
block|{
name|XcmsCIEXYZ_prefix
block|,
comment|/* prefix */
name|XcmsCIEXYZFormat
block|,
comment|/* id */
name|CIEXYZ_ParseString
block|,
comment|/* parseString */
name|Fl_CIEXYZ_to_CIEXYZ
block|,
comment|/* to_CIEXYZ */
name|Fl_CIEXYZ_to_CIEXYZ
block|,
comment|/* from_CIEXYZ */
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/************************************************************************  *									*  *			PRIVATE ROUTINES				*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  *	NAME  *		CIEXYZ_ParseString  *  *	SYNOPSIS  */
end_comment

begin_function
specifier|static
name|int
name|CIEXYZ_ParseString
parameter_list|(
name|spec
parameter_list|,
name|pColor
parameter_list|)
specifier|register
name|char
modifier|*
name|spec
decl_stmt|;
name|XcmsColor
modifier|*
name|pColor
decl_stmt|;
comment|/*  *	DESCRIPTION  *		This routines takes a string and attempts to convert  *		it into a XcmsColor structure with XcmsCIEXYZFormat.  *		The assumed CIEXYZ string syntax is:  *		    CIEXYZ:<X>/<Y>/<Z>  *		Where X, Y, and Z are in string input format for floats  *		consisting of:  *		    a. an optional sign  *		    b. a string of numbers possibly containing a decimal point,  *		    c. an optional exponent field containing an 'E' or 'e'  *			followed by a possibly signed integer string.  *  *	RETURNS  */
block|{
name|int
name|n
decl_stmt|;
name|char
modifier|*
name|pchar
decl_stmt|;
if|if
condition|(
operator|(
name|pchar
operator|=
name|strchr
argument_list|(
name|spec
argument_list|,
literal|':'
argument_list|)
operator|)
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
name|n
operator|=
call|(
name|int
call|)
argument_list|(
name|pchar
operator|-
name|spec
argument_list|)
expr_stmt|;
comment|/*      * Check for proper prefix.      */
if|if
condition|(
name|strncmp
argument_list|(
name|spec
argument_list|,
name|XcmsCIEXYZ_prefix
argument_list|,
name|n
argument_list|)
operator|!=
literal|0
condition|)
block|{
return|return
operator|(
name|XcmsFailure
operator|)
return|;
block|}
comment|/*      * Attempt to parse the value portion.      */
if|if
condition|(
name|sscanf
argument_list|(
name|spec
operator|+
name|n
operator|+
literal|1
argument_list|,
literal|"%lf/%lf/%lf"
argument_list|,
operator|&
name|pColor
operator|->
name|spec
operator|.
name|CIEXYZ
operator|.
name|X
argument_list|,
operator|&
name|pColor
operator|->
name|spec
operator|.
name|CIEXYZ
operator|.
name|Y
argument_list|,
operator|&
name|pColor
operator|->
name|spec
operator|.
name|CIEXYZ
operator|.
name|Z
argument_list|)
operator|!=
literal|3
condition|)
block|{
return|return
operator|(
name|XcmsFailure
operator|)
return|;
block|}
name|pColor
operator|->
name|format
operator|=
name|XcmsCIEXYZFormat
expr_stmt|;
name|pColor
operator|->
name|pixel
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|XcmsCIEXYZ_ValidSpec
argument_list|(
name|pColor
argument_list|)
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/************************************************************************  *									*  *			PUBLIC ROUTINES 				*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  *	NAME  *		XcmsCIELab_ValidSpec  *  *	SYNOPSIS  */
end_comment

begin_function
name|Status
name|XcmsCIEXYZ_ValidSpec
parameter_list|(
name|pColor
parameter_list|)
name|XcmsColor
modifier|*
name|pColor
decl_stmt|;
comment|/*  *	DESCRIPTION  *		Checks if color specification valid for CIE XYZ  *  *	RETURNS  *		XcmsFailure if invalid,  *		XcmsSuccess if valid.  *  */
block|{
if|if
condition|(
name|pColor
operator|->
name|format
operator|!=
name|XcmsCIEXYZFormat
operator|||
operator|(
name|pColor
operator|->
name|spec
operator|.
name|CIEXYZ
operator|.
name|Y
operator|<
literal|0.0
operator|-
name|XMY_DBL_EPSILON
operator|)
operator|||
operator|(
name|pColor
operator|->
name|spec
operator|.
name|CIEXYZ
operator|.
name|Y
operator|>
literal|1.0
operator|+
name|XMY_DBL_EPSILON
operator|)
condition|)
block|{
return|return
operator|(
name|XcmsFailure
operator|)
return|;
block|}
return|return
operator|(
name|XcmsSuccess
operator|)
return|;
block|}
end_function

end_unit

