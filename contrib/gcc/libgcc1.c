begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Subroutines needed by GCC output code on some machines.  */
end_comment

begin_comment
comment|/* Compile this file with the Unix C compiler!  */
end_comment

begin_comment
comment|/* Copyright (C) 1987, 1988, 1992, 1994, 1995 Free Software Foundation, Inc.  This file is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file with other programs, and to distribute those programs without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into another program.)  This file is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* Don't use `fancy_abort' here even if config.h says to use it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|abort
end_ifdef

begin_undef
undef|#
directive|undef
name|abort
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On some machines, cc is really GCC.  For these machines, we can't    expect these functions to be properly compiled unless GCC open codes    the operation (which is precisely when the function won't be used).    So allow tm.h to specify ways of accomplishing the operations    by defining the macros perform_*.     On a machine where cc is some other compiler, there is usually no    reason to define perform_*.  The other compiler normally has other ways    of implementing all of these operations.     In some cases a certain machine may come with GCC installed as cc    or may have some other compiler.  Then it may make sense for tm.h    to define perform_* only if __GNUC__ is defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|perform_mulsi3
end_ifndef

begin_define
define|#
directive|define
name|perform_mulsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a * b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_divsi3
end_ifndef

begin_define
define|#
directive|define
name|perform_divsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a / b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_udivsi3
end_ifndef

begin_define
define|#
directive|define
name|perform_udivsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a / b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_modsi3
end_ifndef

begin_define
define|#
directive|define
name|perform_modsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a % b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_umodsi3
end_ifndef

begin_define
define|#
directive|define
name|perform_umodsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a % b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_lshrsi3
end_ifndef

begin_define
define|#
directive|define
name|perform_lshrsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a>> b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_ashrsi3
end_ifndef

begin_define
define|#
directive|define
name|perform_ashrsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a>> b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_ashlsi3
end_ifndef

begin_define
define|#
directive|define
name|perform_ashlsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a<< b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_adddf3
end_ifndef

begin_define
define|#
directive|define
name|perform_adddf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a + b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_subdf3
end_ifndef

begin_define
define|#
directive|define
name|perform_subdf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a - b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_muldf3
end_ifndef

begin_define
define|#
directive|define
name|perform_muldf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a * b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_divdf3
end_ifndef

begin_define
define|#
directive|define
name|perform_divdf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a / b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_addsf3
end_ifndef

begin_define
define|#
directive|define
name|perform_addsf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return INTIFY (a + b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_subsf3
end_ifndef

begin_define
define|#
directive|define
name|perform_subsf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return INTIFY (a - b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_mulsf3
end_ifndef

begin_define
define|#
directive|define
name|perform_mulsf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return INTIFY (a * b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_divsf3
end_ifndef

begin_define
define|#
directive|define
name|perform_divsf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return INTIFY (a / b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_negdf2
end_ifndef

begin_define
define|#
directive|define
name|perform_negdf2
parameter_list|(
name|a
parameter_list|)
value|return -a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_negsf2
end_ifndef

begin_define
define|#
directive|define
name|perform_negsf2
parameter_list|(
name|a
parameter_list|)
value|return INTIFY (-a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_fixdfsi
end_ifndef

begin_define
define|#
directive|define
name|perform_fixdfsi
parameter_list|(
name|a
parameter_list|)
value|return (nongcc_SI_type) a;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_fixsfsi
end_ifndef

begin_define
define|#
directive|define
name|perform_fixsfsi
parameter_list|(
name|a
parameter_list|)
value|return (nongcc_SI_type) a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_floatsidf
end_ifndef

begin_define
define|#
directive|define
name|perform_floatsidf
parameter_list|(
name|a
parameter_list|)
value|return (double) a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_floatsisf
end_ifndef

begin_define
define|#
directive|define
name|perform_floatsisf
parameter_list|(
name|a
parameter_list|)
value|return INTIFY ((float) a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_extendsfdf2
end_ifndef

begin_define
define|#
directive|define
name|perform_extendsfdf2
parameter_list|(
name|a
parameter_list|)
value|return a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_truncdfsf2
end_ifndef

begin_define
define|#
directive|define
name|perform_truncdfsf2
parameter_list|(
name|a
parameter_list|)
value|return INTIFY (a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Note that eqdf2 returns a value for "true" that is == 0,    nedf2 returns a value for "true" that is != 0,    gtdf2 returns a value for "true" that is> 0,    and so on.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|perform_eqdf2
end_ifndef

begin_define
define|#
directive|define
name|perform_eqdf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return !(a == b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_nedf2
end_ifndef

begin_define
define|#
directive|define
name|perform_nedf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a != b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_gtdf2
end_ifndef

begin_define
define|#
directive|define
name|perform_gtdf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a> b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_gedf2
end_ifndef

begin_define
define|#
directive|define
name|perform_gedf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return (a>= b) - 1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_ltdf2
end_ifndef

begin_define
define|#
directive|define
name|perform_ltdf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return -(a< b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_ledf2
end_ifndef

begin_define
define|#
directive|define
name|perform_ledf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return 1 - (a<= b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_eqsf2
end_ifndef

begin_define
define|#
directive|define
name|perform_eqsf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return !(a == b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_nesf2
end_ifndef

begin_define
define|#
directive|define
name|perform_nesf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a != b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_gtsf2
end_ifndef

begin_define
define|#
directive|define
name|perform_gtsf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return a> b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_gesf2
end_ifndef

begin_define
define|#
directive|define
name|perform_gesf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return (a>= b) - 1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_ltsf2
end_ifndef

begin_define
define|#
directive|define
name|perform_ltsf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return -(a< b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|perform_lesf2
end_ifndef

begin_define
define|#
directive|define
name|perform_lesf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|return 1 - (a<= b);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Define the C data type to use for an SImode value.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|nongcc_SI_type
end_ifndef

begin_define
define|#
directive|define
name|nongcc_SI_type
value|long int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the C data type to use for a value of word size */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|nongcc_word_type
end_ifndef

begin_define
define|#
directive|define
name|nongcc_word_type
value|nongcc_SI_type
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the type to be used for returning an SF mode value    and the method for turning a float into that type.    These definitions work for machines where an SF value is    returned in the same register as an int.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT_VALUE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|FLOAT_VALUE_TYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTIFY
end_ifndef

begin_define
define|#
directive|define
name|INTIFY
parameter_list|(
name|FLOATVAL
parameter_list|)
value|(intify.f = (FLOATVAL), intify.i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLOATIFY
end_ifndef

begin_define
define|#
directive|define
name|FLOATIFY
parameter_list|(
name|INTVAL
parameter_list|)
value|((INTVAL).f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT_ARG_TYPE
end_ifndef

begin_define
define|#
directive|define
name|FLOAT_ARG_TYPE
value|union flt_or_int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_union
union|union
name|flt_or_value
block|{
name|FLOAT_VALUE_TYPE
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|flt_or_int
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
union|;
end_union

begin_ifdef
ifdef|#
directive|ifdef
name|L_mulsi3
end_ifdef

begin_function
name|nongcc_SI_type
name|__mulsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|nongcc_SI_type
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_mulsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_udivsi3
end_ifdef

begin_function
name|nongcc_SI_type
name|__udivsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|unsigned
name|nongcc_SI_type
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_udivsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_divsi3
end_ifdef

begin_function
name|nongcc_SI_type
name|__divsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|nongcc_SI_type
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_divsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_umodsi3
end_ifdef

begin_function
name|nongcc_SI_type
name|__umodsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|unsigned
name|nongcc_SI_type
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_umodsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_modsi3
end_ifdef

begin_function
name|nongcc_SI_type
name|__modsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|nongcc_SI_type
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_modsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_lshrsi3
end_ifdef

begin_function
name|nongcc_SI_type
name|__lshrsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|unsigned
name|nongcc_SI_type
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_lshrsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ashrsi3
end_ifdef

begin_function
name|nongcc_SI_type
name|__ashrsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|nongcc_SI_type
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_ashrsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ashlsi3
end_ifdef

begin_function
name|nongcc_SI_type
name|__ashlsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|nongcc_SI_type
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_ashlsi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_divdf3
end_ifdef

begin_function
name|double
name|__divdf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_divdf3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_muldf3
end_ifdef

begin_function
name|double
name|__muldf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_muldf3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_negdf2
end_ifdef

begin_function
name|double
name|__negdf2
parameter_list|(
name|a
parameter_list|)
name|double
name|a
decl_stmt|;
block|{
name|perform_negdf2
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_adddf3
end_ifdef

begin_function
name|double
name|__adddf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_adddf3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_subdf3
end_ifdef

begin_function
name|double
name|__subdf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|perform_subdf3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Note that eqdf2 returns a value for "true" that is == 0,    nedf2 returns a value for "true" that is != 0,    gtdf2 returns a value for "true" that is> 0,    and so on.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|L_eqdf2
end_ifdef

begin_function
name|nongcc_word_type
name|__eqdf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
comment|/* Value == 0 iff a == b.  */
name|perform_eqdf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_nedf2
end_ifdef

begin_function
name|nongcc_word_type
name|__nedf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
comment|/* Value != 0 iff a != b.  */
name|perform_nedf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_gtdf2
end_ifdef

begin_function
name|nongcc_word_type
name|__gtdf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
comment|/* Value> 0 iff a> b.  */
name|perform_gtdf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_gedf2
end_ifdef

begin_function
name|nongcc_word_type
name|__gedf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
comment|/* Value>= 0 iff a>= b.  */
name|perform_gedf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ltdf2
end_ifdef

begin_function
name|nongcc_word_type
name|__ltdf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
comment|/* Value< 0 iff a< b.  */
name|perform_ltdf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ledf2
end_ifdef

begin_function
name|nongcc_word_type
name|__ledf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
comment|/* Value<= 0 iff a<= b.  */
name|perform_ledf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixdfsi
end_ifdef

begin_function
name|nongcc_SI_type
name|__fixdfsi
parameter_list|(
name|a
parameter_list|)
name|double
name|a
decl_stmt|;
block|{
name|perform_fixdfsi
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixsfsi
end_ifdef

begin_function
name|nongcc_SI_type
name|__fixsfsi
parameter_list|(
name|a
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|;
block|{
name|union
name|flt_or_value
name|intify
decl_stmt|;
name|perform_fixsfsi
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_floatsidf
end_ifdef

begin_function
name|double
name|__floatsidf
parameter_list|(
name|a
parameter_list|)
name|nongcc_SI_type
name|a
decl_stmt|;
block|{
name|perform_floatsidf
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_floatsisf
end_ifdef

begin_function
name|FLOAT_VALUE_TYPE
name|__floatsisf
parameter_list|(
name|a
parameter_list|)
name|nongcc_SI_type
name|a
decl_stmt|;
block|{
name|union
name|flt_or_value
name|intify
decl_stmt|;
name|perform_floatsisf
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_addsf3
end_ifdef

begin_function
name|FLOAT_VALUE_TYPE
name|__addsf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_value
name|intify
decl_stmt|;
name|perform_addsf3
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_negsf2
end_ifdef

begin_function
name|FLOAT_VALUE_TYPE
name|__negsf2
parameter_list|(
name|a
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|;
block|{
name|union
name|flt_or_value
name|intify
decl_stmt|;
name|perform_negsf2
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_subsf3
end_ifdef

begin_function
name|FLOAT_VALUE_TYPE
name|__subsf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_value
name|intify
decl_stmt|;
name|perform_subsf3
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_eqsf2
end_ifdef

begin_function
name|nongcc_word_type
name|__eqsf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_int
name|intify
decl_stmt|;
comment|/* Value == 0 iff a == b.  */
name|perform_eqsf2
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_nesf2
end_ifdef

begin_function
name|nongcc_word_type
name|__nesf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_int
name|intify
decl_stmt|;
comment|/* Value != 0 iff a != b.  */
name|perform_nesf2
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_gtsf2
end_ifdef

begin_function
name|nongcc_word_type
name|__gtsf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_int
name|intify
decl_stmt|;
comment|/* Value> 0 iff a> b.  */
name|perform_gtsf2
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_gesf2
end_ifdef

begin_function
name|nongcc_word_type
name|__gesf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_int
name|intify
decl_stmt|;
comment|/* Value>= 0 iff a>= b.  */
name|perform_gesf2
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ltsf2
end_ifdef

begin_function
name|nongcc_word_type
name|__ltsf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_int
name|intify
decl_stmt|;
comment|/* Value< 0 iff a< b.  */
name|perform_ltsf2
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_lesf2
end_ifdef

begin_function
name|nongcc_word_type
name|__lesf2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_int
name|intify
decl_stmt|;
comment|/* Value<= 0 iff a<= b.  */
name|perform_lesf2
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_mulsf3
end_ifdef

begin_function
name|FLOAT_VALUE_TYPE
name|__mulsf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_value
name|intify
decl_stmt|;
name|perform_mulsf3
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_divsf3
end_ifdef

begin_function
name|FLOAT_VALUE_TYPE
name|__divsf3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|union
name|flt_or_value
name|intify
decl_stmt|;
name|perform_divsf3
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|,
name|FLOATIFY
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_truncdfsf2
end_ifdef

begin_function
name|FLOAT_VALUE_TYPE
name|__truncdfsf2
parameter_list|(
name|a
parameter_list|)
name|double
name|a
decl_stmt|;
block|{
name|union
name|flt_or_value
name|intify
decl_stmt|;
name|perform_truncdfsf2
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_extendsfdf2
end_ifdef

begin_function
name|double
name|__extendsfdf2
parameter_list|(
name|a
parameter_list|)
name|FLOAT_ARG_TYPE
name|a
decl_stmt|;
block|{
name|union
name|flt_or_value
name|intify
decl_stmt|;
name|perform_extendsfdf2
argument_list|(
name|FLOATIFY
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

