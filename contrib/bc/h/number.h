begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* number.h: Arbitrary precision numbers header file. */
end_comment

begin_comment
comment|/*     Copyright (C) 1991, 1992, 1993, 1994, 1997, 2000 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2 of the License , or     (at your option) any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; see the file COPYING.  If not, write to:        The Free Software Foundation, Inc.       59 Temple Place, Suite 330       Boston, MA 02111-1307 USA.       You may contact the author by:        e-mail:  philnelson@acm.org       us-mail:  Philip A. Nelson                 Computer Science Department, 9062                 Western Washington University                 Bellingham, WA 98226-9062         *************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NUMBER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NUMBER_H_
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|PLUS
block|,
name|MINUS
block|}
name|sign
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bc_struct
modifier|*
name|bc_num
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bc_struct
block|{
name|sign
name|n_sign
decl_stmt|;
name|int
name|n_len
decl_stmt|;
comment|/* The number of digits before the decimal point. */
name|int
name|n_scale
decl_stmt|;
comment|/* The number of digits after the decimal point. */
name|int
name|n_refs
decl_stmt|;
comment|/* The number of pointers to this number. */
name|bc_num
name|n_next
decl_stmt|;
comment|/* Linked list for available list. */
name|char
modifier|*
name|n_ptr
decl_stmt|;
comment|/* The pointer to the actual storage. 			   If NULL, n_value points to the inside of 			   another number (bc_multiply...) and should 			   not be "freed." */
name|char
modifier|*
name|n_value
decl_stmt|;
comment|/* The number. Not zero char terminated. 			   May not point to the same place as n_ptr as 			   in the case of leading zeros generated. */
block|}
name|bc_struct
typedef|;
end_typedef

begin_comment
comment|/* The base used in storing the numbers in n_value above.    Currently this MUST be 10. */
end_comment

begin_define
define|#
directive|define
name|BASE
value|10
end_define

begin_comment
comment|/*  Some useful macros and constants. */
end_comment

begin_define
define|#
directive|define
name|CH_VAL
parameter_list|(
name|c
parameter_list|)
value|(c - '0')
end_define

begin_define
define|#
directive|define
name|BCD_CHAR
parameter_list|(
name|d
parameter_list|)
value|(d + '0')
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MIN
end_ifdef

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(a):(b))
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(b):(a))
end_define

begin_define
define|#
directive|define
name|ODD
parameter_list|(
name|a
parameter_list|)
value|((a)&1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|LONG_MAX
value|0x7ffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Global numbers. */
end_comment

begin_decl_stmt
specifier|extern
name|bc_num
name|_zero_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bc_num
name|_one_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bc_num
name|_two_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function Prototypes */
end_comment

begin_comment
comment|/* Define the _PROTOTYPE macro if it is needed. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROTOTYPE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|_PROTOTYPE
parameter_list|(
name|func
parameter_list|,
name|args
parameter_list|)
value|func args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PROTOTYPE
parameter_list|(
name|func
parameter_list|,
name|args
parameter_list|)
value|func()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_init_numbers
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|bc_num bc_new_num
argument_list|,
argument|(int length, int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_free_num
argument_list|,
argument|(bc_num *num)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|bc_num bc_copy_num
argument_list|,
argument|(bc_num num)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_init_num
argument_list|,
argument|(bc_num *num)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_str2num
argument_list|,
argument|(bc_num *num, char *str, int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYPE
argument_list|(
name|char
operator|*
name|bc_num2str
argument_list|,
operator|(
name|bc_num
name|num
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_int2num
argument_list|,
argument|(bc_num *num, int val)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|long bc_num2long
argument_list|,
argument|(bc_num num)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int bc_compare
argument_list|,
argument|(bc_num n1, bc_num n2)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|char bc_is_zero
argument_list|,
argument|(bc_num num)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|char bc_is_near_zero
argument_list|,
argument|(bc_num num, int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|char bc_is_neg
argument_list|,
argument|(bc_num num)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_add
argument_list|,
argument|(bc_num n1, bc_num n2, bc_num *result, int scale_min)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_sub
argument_list|,
argument|(bc_num n1, bc_num n2, bc_num *result, int scale_min)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_multiply
argument_list|,
argument|(bc_num n1, bc_num n2, bc_num *prod, int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int bc_divide
argument_list|,
argument|(bc_num n1, bc_num n2, bc_num *quot, int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int bc_modulo
argument_list|,
argument|(bc_num num1, bc_num num2, bc_num *result, 			   int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int bc_divmod
argument_list|,
argument|(bc_num num1, bc_num num2, bc_num *quot, 			   bc_num *rem, int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int bc_raisemod
argument_list|,
argument|(bc_num base, bc_num expo, bc_num mod, 			     bc_num *result, int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_raise
argument_list|,
argument|(bc_num num1, bc_num num2, bc_num *result, 			   int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int bc_sqrt
argument_list|,
argument|(bc_num *num, int scale)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|void bc_out_num
argument_list|,
argument|(bc_num num, int o_base, void (* out_char)(int), 			     int leading_zero)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

