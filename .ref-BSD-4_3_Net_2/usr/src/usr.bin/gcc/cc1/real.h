begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Front-end tree definitions for GNU compiler.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|REAL_H_INCLUDED
end_define

begin_comment
comment|/* If we are not cross-compiling, use a `double' to represent the    floating-point value.  Otherwise, use some other type    (probably a struct containing an array of longs).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_TYPE
value|double
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REAL_IS_NOT_DOUBLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compare two floating-point values for equality.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUES_EQUAL
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUES_EQUAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) == (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compare two floating-point values for less than.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUES_LESS
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUES_LESS
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Scale X by Y powers of 2.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_LDEXP
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_LDEXP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|ldexp (x, y)
end_define

begin_function_decl
specifier|extern
name|double
name|ldexp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert the string X to a floating-point value.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_ATOF
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_ATOF
parameter_list|(
name|x
parameter_list|)
value|atof (x)
end_define

begin_function_decl
specifier|extern
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Negate the floating-point value X.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_NEGATE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_NEGATE
parameter_list|(
name|x
parameter_list|)
value|(- (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Truncate the floating-point value X to single-precision.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REAL_VALUE_TRUNCATE
end_ifndef

begin_define
define|#
directive|define
name|REAL_VALUE_TRUNCATE
parameter_list|(
name|x
parameter_list|)
value|((float) (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Union type used for extracting real values from CONST_DOUBLEs    or putting them in.  */
end_comment

begin_union
union|union
name|real_extract
block|{
name|REAL_VALUE_TYPE
name|d
decl_stmt|;
name|int
name|i
index|[
sizeof|sizeof
argument_list|(
name|REAL_VALUE_TYPE
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* For a CONST_DOUBLE:    The usual two ints that hold the value.    For a DImode, that is all there are;     and CONST_DOUBLE_LOW is the low-order word and ..._HIGH the high-order.    For a float, the number of ints varies,     and CONST_DOUBLE_LOW is the one that should come first *in memory*.     So use&CONST_DOUBLE_LOW(r) as the address of an array of ints.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_LOW
parameter_list|(
name|r
parameter_list|)
value|XINT (r, 2)
end_define

begin_define
define|#
directive|define
name|CONST_DOUBLE_HIGH
parameter_list|(
name|r
parameter_list|)
value|XINT (r, 3)
end_define

begin_comment
comment|/* Link for chain of all CONST_DOUBLEs in use in current function.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_CHAIN
parameter_list|(
name|r
parameter_list|)
value|XEXP (r, 1)
end_define

begin_comment
comment|/* The MEM which represents this CONST_DOUBLE's value in memory,    or const0_rtx if no MEM has been made for it yet,    or cc0_rtx if it is not on the chain.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_MEM
parameter_list|(
name|r
parameter_list|)
value|XEXP (r, 0)
end_define

begin_comment
comment|/* Function to return a real value (not a tree node)    from a given integer constant.  */
end_comment

begin_function_decl
name|REAL_VALUE_TYPE
name|real_value_from_int_cst
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not REAL_H_INCLUDED */
end_comment

end_unit

