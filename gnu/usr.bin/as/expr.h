begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* expr.h -> header file for expr.c    Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Abbreviations (mnemonics).  *  *	O	operator  *	Q	quantity,  operand  *	X	eXpression  */
end_comment

begin_comment
comment|/*  * By popular demand, we define a struct to represent an expression.  * This will no doubt mutate as expressions become baroque.  *  * Currently, we support expressions like "foo-bar+42".  * In other words we permit a (possibly undefined) minuend, a  * (possibly undefined) subtrahend and an (absolute) augend.  * RMS says this is so we can have 1-pass assembly for any compiler  * emmissions, and a 'case' statement might emit 'undefined1 - undefined2'.  *  * To simplify table-driven dispatch, we also have a "segment" for the  * entire expression. That way we don't require complex reasoning about  * whether particular components are defined; and we can change component  * semantics without re-working all the dispatch tables in the assembler.  * In other words the "type" of an expression is its segment.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|symbolS
modifier|*
name|X_add_symbol
decl_stmt|;
comment|/* foo */
name|symbolS
modifier|*
name|X_subtract_symbol
decl_stmt|;
comment|/* bar */
name|symbolS
modifier|*
name|X_got_symbol
decl_stmt|;
comment|/* got */
name|long
name|X_add_number
decl_stmt|;
comment|/* 42.    Must be signed. */
name|segT
name|X_seg
decl_stmt|;
comment|/* What segment (expr type)? */
block|}
name|expressionS
typedef|;
end_typedef

begin_comment
comment|/* result should be type (expressionS *). */
end_comment

begin_define
define|#
directive|define
name|expression
parameter_list|(
name|result
parameter_list|)
value|expr(0,result)
end_define

begin_comment
comment|/* If an expression is SEG_BIG, look here */
end_comment

begin_comment
comment|/* for its value. These common data may */
end_comment

begin_comment
comment|/* be clobbered whenever expr() is called. */
end_comment

begin_decl_stmt
specifier|extern
name|FLONUM_TYPE
name|generic_floating_point_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flonums returned here. */
end_comment

begin_comment
comment|/* Enough to hold most precise flonum. */
end_comment

begin_decl_stmt
specifier|extern
name|LITTLENUM_TYPE
name|generic_bignum
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bignums returned here. */
end_comment

begin_define
define|#
directive|define
name|SIZE_OF_LARGE_NUMBER
value|(20)
end_define

begin_comment
comment|/* Number of littlenums in above. */
end_comment

begin_typedef
typedef|typedef
name|char
name|operator_rankT
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_function_decl
name|char
name|get_symbol_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|segT
name|expr
parameter_list|(
name|int
name|rank
parameter_list|,
name|expressionS
modifier|*
name|resultP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|get_single_number
parameter_list|(
name|void
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
name|char
name|get_symbol_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|segT
name|expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|get_single_number
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
comment|/* end of expr.h */
end_comment

end_unit

