begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* expr.h -> header file for expr.c    Copyright (C) 1987, 92, 93, 94, 95, 96, 1997 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * By popular demand, we define a struct to represent an expression.  * This will no doubt mutate as expressions become baroque.  *  * Currently, we support expressions like "foo OP bar + 42".  In other  * words we permit a (possibly undefined) symbol, a (possibly  * undefined) symbol and the operation used to combine the symbols,  * and an (absolute) augend.  RMS says this is so we can have 1-pass  * assembly for any compiler emissions, and a 'case' statement might  * emit 'undefined1 - undefined2'.  *  * The type of an expression used to be stored as a segment.  That got  * confusing because it overloaded the concept of a segment.  I added  * an operator field, instead.  */
end_comment

begin_comment
comment|/* This is the type of an expression.  The operator types are also    used while parsing an expression.     NOTE: This enumeration must match the op_rank array in expr.c.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* An illegal expression.  */
name|O_illegal
block|,
comment|/* A nonexistent expression.  */
name|O_absent
block|,
comment|/* X_add_number (a constant expression).  */
name|O_constant
block|,
comment|/* X_add_symbol + X_add_number.  */
name|O_symbol
block|,
comment|/* X_add_symbol + X_add_number - the base address of the image.  */
name|O_symbol_rva
block|,
comment|/* A register (X_add_number is register number).  */
name|O_register
block|,
comment|/* A big value.  If X_add_number is negative or 0, the value is in      generic_floating_point_number.  Otherwise the value is in      generic_bignum, and X_add_number is the number of LITTLENUMs in      the value.  */
name|O_big
block|,
comment|/* (- X_add_symbol) + X_add_number.  */
name|O_uminus
block|,
comment|/* (~ X_add_symbol) + X_add_number.  */
name|O_bit_not
block|,
comment|/* (! X_add_symbol) + X_add_number.  */
name|O_logical_not
block|,
comment|/* (X_add_symbol * X_op_symbol) + X_add_number.  */
name|O_multiply
block|,
comment|/* (X_add_symbol / X_op_symbol) + X_add_number.  */
name|O_divide
block|,
comment|/* X_add_symbol % X_op_symbol) + X_add_number.  */
name|O_modulus
block|,
comment|/* X_add_symbol<< X_op_symbol) + X_add_number.  */
name|O_left_shift
block|,
comment|/* X_add_symbol>> X_op_symbol) + X_add_number.  */
name|O_right_shift
block|,
comment|/* X_add_symbol | X_op_symbol) + X_add_number.  */
name|O_bit_inclusive_or
block|,
comment|/* X_add_symbol |~ X_op_symbol) + X_add_number.  */
name|O_bit_or_not
block|,
comment|/* X_add_symbol ^ X_op_symbol) + X_add_number.  */
name|O_bit_exclusive_or
block|,
comment|/* X_add_symbol& X_op_symbol) + X_add_number.  */
name|O_bit_and
block|,
comment|/* X_add_symbol + X_op_symbol) + X_add_number.  */
name|O_add
block|,
comment|/* X_add_symbol - X_op_symbol) + X_add_number.  */
name|O_subtract
block|,
comment|/* (X_add_symbol == X_op_symbol) + X_add_number.  */
name|O_eq
block|,
comment|/* (X_add_symbol != X_op_symbol) + X_add_number.  */
name|O_ne
block|,
comment|/* (X_add_symbol< X_op_symbol) + X_add_number.  */
name|O_lt
block|,
comment|/* (X_add_symbol<= X_op_symbol) + X_add_number.  */
name|O_le
block|,
comment|/* (X_add_symbol>= X_op_symbol) + X_add_number.  */
name|O_ge
block|,
comment|/* (X_add_symbol> X_op_symbol) + X_add_number.  */
name|O_gt
block|,
comment|/* (X_add_symbol&& X_op_symbol) + X_add_number.  */
name|O_logical_and
block|,
comment|/* (X_add_symbol || X_op_symbol) + X_add_number.  */
name|O_logical_or
block|,
comment|/* this must be the largest value */
name|O_max
block|}
name|operatorT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|expressionS
block|{
comment|/* The main symbol.  */
name|struct
name|symbol
modifier|*
name|X_add_symbol
decl_stmt|;
comment|/* The second symbol, if needed.  */
name|struct
name|symbol
modifier|*
name|X_op_symbol
decl_stmt|;
comment|/* A number to add.  */
name|offsetT
name|X_add_number
decl_stmt|;
comment|/* The type of the expression.  We can't assume that an arbitrary      compiler can handle a bitfield of enum type.  FIXME: We could      check this using autoconf.  */
ifdef|#
directive|ifdef
name|__GNUC__
name|operatorT
name|X_op
range|:
literal|5
decl_stmt|;
else|#
directive|else
name|unsigned
name|X_op
range|:
literal|5
decl_stmt|;
endif|#
directive|endif
comment|/* Non-zero if X_add_number should be regarded as unsigned.  This is      only valid for O_constant expressions.  It is only used when an      O_constant must be extended into a bignum (i.e., it is not used      when performing arithmetic on these values).      FIXME: This field is not set very reliably.  */
name|unsigned
name|int
name|X_unsigned
range|:
literal|1
decl_stmt|;
block|}
name|expressionS
typedef|;
end_typedef

begin_comment
comment|/* "result" should be type (expressionS *). */
end_comment

begin_define
define|#
directive|define
name|expression
parameter_list|(
name|result
parameter_list|)
value|expr (0, result)
end_define

begin_comment
comment|/* If an expression is O_big, look here for its value. These common    data may be clobbered whenever expr() is called. */
end_comment

begin_comment
comment|/* Flonums returned here.  Big enough to hold most precise flonum. */
end_comment

begin_decl_stmt
specifier|extern
name|FLONUM_TYPE
name|generic_floating_point_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bignums returned here. */
end_comment

begin_decl_stmt
specifier|extern
name|LITTLENUM_TYPE
name|generic_bignum
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of littlenums in above. */
end_comment

begin_define
define|#
directive|define
name|SIZE_OF_LARGE_NUMBER
value|(20)
end_define

begin_typedef
typedef|typedef
name|char
name|operator_rankT
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
name|get_symbol_end
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expr_begin
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|segT
name|expr
name|PARAMS
argument_list|(
operator|(
name|int
name|rank
operator|,
name|expressionS
operator|*
name|resultP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|get_single_number
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|make_expr_symbol
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
name|expressionP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|expr_symbol_where
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|unsigned
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of expr.h */
end_comment

end_unit

