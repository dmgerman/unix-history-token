begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Header file for decimal.c (arbitrary precision decimal arithmetic)  *  * Copyright (C) 1984 Free Software Foundation, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, you can either send email to this  * program's author (see below) or write to: The Free Software Foundation,  * Inc.; 675 Mass Ave. Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Autoconf stuff */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BCOPY
end_ifndef

begin_undef
undef|#
directive|undef
name|bcopy
end_undef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s2
parameter_list|,
name|s1
parameter_list|,
name|n
parameter_list|)
value|memcpy (s1, s2, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BZERO
end_ifndef

begin_undef
undef|#
directive|undef
name|bzero
end_undef

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|b
parameter_list|,
name|l
parameter_list|)
value|memset (b, 0, l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the radix to use by default, and for representing the    numbers internally.  This does not need to be decimal; that is just    the default for it.  */
end_comment

begin_comment
comment|/* Currently, this is required to be even for this program to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RADIX
end_ifndef

begin_define
define|#
directive|define
name|RADIX
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The user must define the external function `decimal_error'    which is called with two arguments to report errors in this package.    The two arguments may be passed to `printf' to print a message. */
end_comment

begin_comment
comment|/* Structure that represents a decimal number */
end_comment

begin_struct
struct|struct
name|decimal
block|{
name|unsigned
name|int
name|sign
range|:
literal|1
decl_stmt|;
comment|/* One for negative number */
comment|/* The sign should always be zero for the number 0 */
name|int
name|after
range|:
literal|15
decl_stmt|;
comment|/* number of fraction digits */
name|unsigned
name|short
name|before
decl_stmt|;
comment|/* number of non-fraction digits */
name|unsigned
name|short
name|refcnt
decl_stmt|;
comment|/* number of pointers to this number */
comment|/* (used by calling program) */
name|char
name|contents
index|[
literal|1
index|]
decl_stmt|;
comment|/* the digits themselves, least significant first. */
comment|/* digits are just numbers 0 .. RADIX-1 */
block|}
struct|;
end_struct

begin_comment
comment|/* There may never be leading nonfraction zeros or trailing fraction    zeros in a number.  They must be removed by all the arithmetic    functions.  Therefore, the number zero always has no digits stored. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|decimal
modifier|*
name|decimal
typedef|;
end_typedef

begin_comment
comment|/* Decimal numbers are always passed around as pointers.    All the external entries in this file allocate new numbers    using `malloc' to store values in.    They never modify their arguments or any existing numbers. */
end_comment

begin_comment
comment|/* Return the total number of digits stored in the number `b' */
end_comment

begin_define
define|#
directive|define
name|LENGTH
parameter_list|(
name|b
parameter_list|)
value|((b)->before + (b)->after)
end_define

begin_comment
comment|/* Some constant decimal numbers */
end_comment

begin_define
define|#
directive|define
name|DECIMAL_ZERO
value|&decimal_zero
end_define

begin_define
define|#
directive|define
name|DECIMAL_ONE
value|&decimal_one
end_define

begin_define
define|#
directive|define
name|DECIMAL_HALF
value|&decimal_half
end_define

begin_decl_stmt
name|decimal
name|decimal_add
argument_list|()
decl_stmt|,
name|decimal_sub
argument_list|()
decl_stmt|,
name|decimal_mul
argument_list|()
decl_stmt|,
name|decimal_div
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|decimal
name|decimal_mul_dc
argument_list|()
decl_stmt|,
name|decimal_mul_rounded
argument_list|()
decl_stmt|,
name|decimal_rem
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|decimal
name|decimal_round_digits
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|decimal
name|make_decimal
argument_list|()
decl_stmt|,
name|decimal_copy
argument_list|()
decl_stmt|,
name|decimal_parse
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|decimal
name|decimal_sqrt
argument_list|()
decl_stmt|,
name|decimal_expt
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|decimal_print
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* End of decimal.h */
end_comment

end_unit

