begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* flonum.h - Floating point package     Copyright (C) 1987, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/***********************************************************************\  *									*  *	Arbitrary-precision floating point arithmetic.			*  *									*  *									*  *	Notation: a floating point number is expressed as		*  *	MANTISSA * (2 ** EXPONENT).					*  *									*  *	If this offends more traditional mathematicians, then		*  *	please tell me your nomenclature for flonums!			*  *									*  \***********************************************************************/
end_comment

begin_if
if|#
directive|if
operator|(
name|__STDC__
operator|!=
literal|1
operator|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|const
argument_list|)
end_if

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bignum.h"
end_include

begin_comment
comment|/***********************************************************************\  *									*  *	Variable precision floating point numbers.			*  *									*  *	Exponent is the place value of the low littlenum. E.g.:		*  *	If  0:  low points to the units             littlenum.		*  *	If  1:  low points to the LITTLENUM_RADIX   littlenum.		*  *	If -1:  low points to the 1/LITTLENUM_RADIX littlenum.		*  *									*  \***********************************************************************/
end_comment

begin_comment
comment|/* JF:  A sign value of 0 means we have been asked to assemble NaN    A sign value of 'P' means we've been asked to assemble +Inf    A sign value of 'N' means we've been asked to assemble -Inf    */
end_comment

begin_struct
struct|struct
name|FLONUM_STRUCT
block|{
name|LITTLENUM_TYPE
modifier|*
name|low
decl_stmt|;
comment|/* low order littlenum of a bignum */
name|LITTLENUM_TYPE
modifier|*
name|high
decl_stmt|;
comment|/* high order littlenum of a bignum */
name|LITTLENUM_TYPE
modifier|*
name|leader
decl_stmt|;
comment|/* -> 1st non-zero littlenum */
comment|/* If flonum is 0.0, leader == low-1 */
name|long
name|exponent
decl_stmt|;
comment|/* base LITTLENUM_RADIX */
name|char
name|sign
decl_stmt|;
comment|/* '+' or '-' */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|FLONUM_STRUCT
name|FLONUM_TYPE
typedef|;
end_typedef

begin_comment
comment|/***********************************************************************\  *									*  *	Since we can (& do) meet with exponents like 10^5000, it	*  *	is silly to make a table of ~ 10,000 entries, one for each	*  *	power of 10. We keep a table where item [n] is a struct		*  *	FLONUM_FLOATING_POINT representing 10^(2^n). We then		*  *	multiply appropriate entries from this table to get any		*  *	particular power of 10. For the example of 10^5000, a table	*  *	of just 25 entries suffices: 10^(2^-12)...10^(2^+12).		*  *									*  \***********************************************************************/
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|FLONUM_TYPE
name|flonum_positive_powers_of_ten
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|FLONUM_TYPE
name|flonum_negative_powers_of_ten
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|table_size_of_flonum_powers_of_ten
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flonum_XXX_powers_of_ten[] table has */
end_comment

begin_comment
comment|/* legal indices from 0 to */
end_comment

begin_comment
comment|/* + this number inclusive. */
end_comment

begin_comment
comment|/***********************************************************************\  *									*  *	Declare worker functions.					*  *									*  \***********************************************************************/
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_function_decl
name|int
name|atof_generic
parameter_list|(
name|char
modifier|*
modifier|*
name|address_of_string_pointer
parameter_list|,
specifier|const
name|char
modifier|*
name|string_of_decimal_marks
parameter_list|,
specifier|const
name|char
modifier|*
name|string_of_decimal_exponent_marks
parameter_list|,
name|FLONUM_TYPE
modifier|*
name|address_of_generic_floating_point_number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flonum_copy
parameter_list|(
name|FLONUM_TYPE
modifier|*
name|in
parameter_list|,
name|FLONUM_TYPE
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flonum_multip
parameter_list|(
specifier|const
name|FLONUM_TYPE
modifier|*
name|a
parameter_list|,
specifier|const
name|FLONUM_TYPE
modifier|*
name|b
parameter_list|,
name|FLONUM_TYPE
modifier|*
name|product
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|int
name|atof_generic
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flonum_copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flonum_multip
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_comment
comment|/***********************************************************************\  *									*  *	Declare error codes.						*  *									*  \***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|ERROR_EXPONENT_OVERFLOW
value|(2)
end_define

begin_comment
comment|/* end of flonum.h */
end_comment

end_unit

