begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* expr.h -> header file for expr.c    Copyright 1987, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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
comment|/* X_op_symbol [ X_add_symbol ] */
name|O_index
block|,
comment|/* machine dependent operators */
name|O_md1
block|,
name|O_md2
block|,
name|O_md3
block|,
name|O_md4
block|,
name|O_md5
block|,
name|O_md6
block|,
name|O_md7
block|,
name|O_md8
block|,
name|O_md9
block|,
name|O_md10
block|,
name|O_md11
block|,
name|O_md12
block|,
name|O_md13
block|,
name|O_md14
block|,
name|O_md15
block|,
name|O_md16
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
name|symbolS
modifier|*
name|X_add_symbol
decl_stmt|;
comment|/* The second symbol, if needed.  */
name|symbolS
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
literal|8
decl_stmt|;
else|#
directive|else
name|unsigned
name|char
name|X_op
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
comment|/* 7 additional bits can be defined if needed.  */
comment|/* Machine dependent field */
name|unsigned
name|short
name|X_md
decl_stmt|;
block|}
name|expressionS
typedef|;
end_typedef

begin_comment
comment|/* "result" should be type (expressionS *).  */
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
comment|/* If an expression is O_big, look here for its value. These common    data may be clobbered whenever expr() is called.  */
end_comment

begin_comment
comment|/* Flonums returned here.  Big enough to hold most precise flonum.  */
end_comment

begin_decl_stmt
specifier|extern
name|FLONUM_TYPE
name|generic_floating_point_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bignums returned here.  */
end_comment

begin_decl_stmt
specifier|extern
name|LITTLENUM_TYPE
name|generic_bignum
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of littlenums in above.  */
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
name|void
name|expr_set_precedence
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
name|symbolS
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
name|symbolS
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

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|expr_build_uconstant
name|PARAMS
argument_list|(
operator|(
name|offsetT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|expr_build_unary
name|PARAMS
argument_list|(
operator|(
name|operatorT
operator|,
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|expr_build_binary
name|PARAMS
argument_list|(
operator|(
name|operatorT
operator|,
name|symbolS
operator|*
operator|,
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|expr_build_dot
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

