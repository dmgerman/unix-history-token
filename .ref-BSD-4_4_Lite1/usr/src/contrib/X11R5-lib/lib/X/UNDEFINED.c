begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: UNDEFINED.c,v 1.5 91/07/25 01:10:56 rws Exp $" */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *  *	NAME  *		UNDEFINED.c  *  *	DESCRIPTION  *		UNDEFINED Color Space  *  *  */
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
comment|/*  *      FORWARD DECLARATIONS  */
end_comment

begin_function_decl
specifier|static
name|int
name|ReturnZero
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *      LOCALS VARIABLES  */
end_comment

begin_expr_stmt
specifier|static
name|Status
argument_list|(
operator|*
operator|(
name|Fl_ReturnZero
index|[]
operator|)
argument_list|)
argument_list|()
operator|=
block|{
name|ReturnZero
block|,
name|NULL
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  *      GLOBALS  *              Variables declared in this package that are allowed  *		to be used globally.  */
end_comment

begin_comment
comment|/*      * UNDEFINED Color Space      */
end_comment

begin_decl_stmt
name|XcmsColorSpace
name|XcmsUNDEFINEDColorSpace
init|=
block|{
literal|"undefined"
block|,
comment|/* prefix */
name|XcmsUndefinedFormat
block|,
comment|/* id */
name|ReturnZero
block|,
comment|/* parseString */
name|Fl_ReturnZero
block|,
comment|/* to_CIEXYZ */
name|Fl_ReturnZero
comment|/* from_CIEXYZ */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/************************************************************************  *									*  *			PRIVATE ROUTINES				*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  *	NAME  *		ReturnZero  *  *	SYNOPSIS  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|ReturnZero
parameter_list|()
comment|/*  *	DESCRIPTION  *		Does nothing.  *  *	RETURNS  *		0  *  */
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

