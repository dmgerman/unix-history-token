begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* More subroutines needed by GCC output code on some machines.  */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1992, 1993, 1994, 1995 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_comment
comment|/* It is incorrect to include config.h here, because this file is being    compiled for the target, and hence definitions concerning only the host    do not apply.  */
end_comment

begin_include
include|#
directive|include
file|"tconfig.h"
end_include

begin_include
include|#
directive|include
file|"machmode.h"
end_include

begin_include
include|#
directive|include
file|"defaults.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|L_trampoline
end_ifndef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
operator|(
name|SUPPORTS_WEAK
operator|==
literal|1
operator|)
operator|&&
name|defined
argument_list|(
name|ASM_OUTPUT_DEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|WEAK_ALIAS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Permit the tm.h file to select the endianness to use just for this    file.  This is used when the endianness is determined when the    compiler is run.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBGCC2_WORDS_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|WORDS_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In the first part of this file, we are interfacing to calls generated    by the compiler itself.  These calls pass values into these routines    which have very specific modes (rather than very specific types), and    these compiler-generated calls also expect any return values to have    very specific modes (rather than very specific types).  Thus, we need    to avoid using regular C language type names in this part of the file    because the sizes for those types can be configured to be anything.    Instead we use the following special type names.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UQItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|QI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|SItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|DItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UDItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|SFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SF
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|DFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DF
typedef|)));
end_typedef

begin_if
if|#
directive|if
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
end_if

begin_typedef
typedef|typedef
name|float
name|XFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|XF
typedef|)));
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|128
end_if

begin_typedef
typedef|typedef
name|float
name|TFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|TF
typedef|)));
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|word_type
name|__attribute__
typedef|((
name|mode
typedef|(
name|__word__
typedef|)));
end_typedef

begin_comment
comment|/* Make sure that we don't accidentally use any normal C language built-in    type names in the first part of this file.  Instead we want to use *only*    the type names defined above.  The following macro definitions insure    that if we *do* accidentally use some normal C language built-in type name,    we will get a syntax error.  */
end_comment

begin_define
define|#
directive|define
name|char
value|bogus_type
end_define

begin_define
define|#
directive|define
name|short
value|bogus_type
end_define

begin_define
define|#
directive|define
name|int
value|bogus_type
end_define

begin_define
define|#
directive|define
name|long
value|bogus_type
end_define

begin_define
define|#
directive|define
name|unsigned
value|bogus_type
end_define

begin_define
define|#
directive|define
name|float
value|bogus_type
end_define

begin_define
define|#
directive|define
name|double
value|bogus_type
end_define

begin_define
define|#
directive|define
name|SI_TYPE_SIZE
value|(sizeof (SItype) * BITS_PER_UNIT)
end_define

begin_comment
comment|/* DIstructs are pairs of SItype values in the order determined by    LIBGCC2_WORDS_BIG_ENDIAN.  */
end_comment

begin_if
if|#
directive|if
name|LIBGCC2_WORDS_BIG_ENDIAN
end_if

begin_struct
struct|struct
name|DIstruct
block|{
name|SItype
name|high
decl_stmt|,
name|low
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|DIstruct
block|{
name|SItype
name|low
decl_stmt|,
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We need this union to unpack/pack DImode values, since we don't have    any arithmetic yet.  Incoming DImode parameters are stored into the    `ll' field, and the unpacked result is read from the struct `s'.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|struct
name|DIstruct
name|s
decl_stmt|;
name|DItype
name|ll
decl_stmt|;
block|}
name|DIunion
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|L_udivmoddi4
argument_list|)
operator|||
name|defined
argument_list|(
name|L_muldi3
argument_list|)
operator|||
name|defined
argument_list|(
name|L_udiv_w_sdiv
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_divdi3
argument_list|)
operator|||
name|defined
argument_list|(
name|L_udivdi3
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|L_moddi3
argument_list|)
operator|||
name|defined
argument_list|(
name|L_umoddi3
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|"longlong.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* udiv or mul */
end_comment

begin_function_decl
specifier|extern
name|DItype
name|__fixunssfdi
parameter_list|(
name|SFtype
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DItype
name|__fixunsdfdi
parameter_list|(
name|DFtype
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
end_if

begin_function_decl
specifier|extern
name|DItype
name|__fixunsxfdi
parameter_list|(
name|XFtype
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|128
end_if

begin_function_decl
specifier|extern
name|DItype
name|__fixunstfdi
parameter_list|(
name|TFtype
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_negdi2
argument_list|)
operator|||
name|defined
argument_list|(
name|L_divdi3
argument_list|)
operator|||
name|defined
argument_list|(
name|L_moddi3
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_divdi3
argument_list|)
operator|||
name|defined
argument_list|(
name|L_moddi3
argument_list|)
end_if

begin_function
specifier|static
specifier|inline
endif|#
directive|endif
name|DItype
name|__negdi2
parameter_list|(
name|u
parameter_list|)
name|DItype
name|u
decl_stmt|;
block|{
name|DIunion
name|w
decl_stmt|;
name|DIunion
name|uu
decl_stmt|;
name|uu
operator|.
name|ll
operator|=
name|u
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|low
operator|=
operator|-
name|uu
operator|.
name|s
operator|.
name|low
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|high
operator|=
operator|-
name|uu
operator|.
name|s
operator|.
name|high
operator|-
operator|(
operator|(
name|USItype
operator|)
name|w
operator|.
name|s
operator|.
name|low
operator|>
literal|0
operator|)
expr_stmt|;
return|return
name|w
operator|.
name|ll
return|;
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
name|L_lshrdi3
end_ifdef

begin_function
name|DItype
name|__lshrdi3
parameter_list|(
name|u
parameter_list|,
name|b
parameter_list|)
name|DItype
name|u
decl_stmt|;
name|word_type
name|b
decl_stmt|;
block|{
name|DIunion
name|w
decl_stmt|;
name|word_type
name|bm
decl_stmt|;
name|DIunion
name|uu
decl_stmt|;
if|if
condition|(
name|b
operator|==
literal|0
condition|)
return|return
name|u
return|;
name|uu
operator|.
name|ll
operator|=
name|u
expr_stmt|;
name|bm
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|SItype
argument_list|)
operator|*
name|BITS_PER_UNIT
operator|)
operator|-
name|b
expr_stmt|;
if|if
condition|(
name|bm
operator|<=
literal|0
condition|)
block|{
name|w
operator|.
name|s
operator|.
name|high
operator|=
literal|0
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|low
operator|=
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|high
operator|>>
operator|-
name|bm
expr_stmt|;
block|}
else|else
block|{
name|USItype
name|carries
init|=
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|high
operator|<<
name|bm
decl_stmt|;
name|w
operator|.
name|s
operator|.
name|high
operator|=
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|high
operator|>>
name|b
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|low
operator|=
operator|(
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|low
operator|>>
name|b
operator|)
operator||
name|carries
expr_stmt|;
block|}
return|return
name|w
operator|.
name|ll
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ashldi3
end_ifdef

begin_function
name|DItype
name|__ashldi3
parameter_list|(
name|u
parameter_list|,
name|b
parameter_list|)
name|DItype
name|u
decl_stmt|;
name|word_type
name|b
decl_stmt|;
block|{
name|DIunion
name|w
decl_stmt|;
name|word_type
name|bm
decl_stmt|;
name|DIunion
name|uu
decl_stmt|;
if|if
condition|(
name|b
operator|==
literal|0
condition|)
return|return
name|u
return|;
name|uu
operator|.
name|ll
operator|=
name|u
expr_stmt|;
name|bm
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|SItype
argument_list|)
operator|*
name|BITS_PER_UNIT
operator|)
operator|-
name|b
expr_stmt|;
if|if
condition|(
name|bm
operator|<=
literal|0
condition|)
block|{
name|w
operator|.
name|s
operator|.
name|low
operator|=
literal|0
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|high
operator|=
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|low
operator|<<
operator|-
name|bm
expr_stmt|;
block|}
else|else
block|{
name|USItype
name|carries
init|=
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|low
operator|>>
name|bm
decl_stmt|;
name|w
operator|.
name|s
operator|.
name|low
operator|=
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|low
operator|<<
name|b
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|high
operator|=
operator|(
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|high
operator|<<
name|b
operator|)
operator||
name|carries
expr_stmt|;
block|}
return|return
name|w
operator|.
name|ll
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ashrdi3
end_ifdef

begin_function
name|DItype
name|__ashrdi3
parameter_list|(
name|u
parameter_list|,
name|b
parameter_list|)
name|DItype
name|u
decl_stmt|;
name|word_type
name|b
decl_stmt|;
block|{
name|DIunion
name|w
decl_stmt|;
name|word_type
name|bm
decl_stmt|;
name|DIunion
name|uu
decl_stmt|;
if|if
condition|(
name|b
operator|==
literal|0
condition|)
return|return
name|u
return|;
name|uu
operator|.
name|ll
operator|=
name|u
expr_stmt|;
name|bm
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|SItype
argument_list|)
operator|*
name|BITS_PER_UNIT
operator|)
operator|-
name|b
expr_stmt|;
if|if
condition|(
name|bm
operator|<=
literal|0
condition|)
block|{
comment|/* w.s.high = 1..1 or 0..0 */
name|w
operator|.
name|s
operator|.
name|high
operator|=
name|uu
operator|.
name|s
operator|.
name|high
operator|>>
operator|(
sizeof|sizeof
argument_list|(
name|SItype
argument_list|)
operator|*
name|BITS_PER_UNIT
operator|-
literal|1
operator|)
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|low
operator|=
name|uu
operator|.
name|s
operator|.
name|high
operator|>>
operator|-
name|bm
expr_stmt|;
block|}
else|else
block|{
name|USItype
name|carries
init|=
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|high
operator|<<
name|bm
decl_stmt|;
name|w
operator|.
name|s
operator|.
name|high
operator|=
name|uu
operator|.
name|s
operator|.
name|high
operator|>>
name|b
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|low
operator|=
operator|(
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|low
operator|>>
name|b
operator|)
operator||
name|carries
expr_stmt|;
block|}
return|return
name|w
operator|.
name|ll
return|;
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
name|L_ffsdi2
end_ifdef

begin_function
name|DItype
name|__ffsdi2
parameter_list|(
name|u
parameter_list|)
name|DItype
name|u
decl_stmt|;
block|{
name|DIunion
name|uu
decl_stmt|,
name|w
decl_stmt|;
name|uu
operator|.
name|ll
operator|=
name|u
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|high
operator|=
literal|0
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|low
operator|=
name|ffs
argument_list|(
name|uu
operator|.
name|s
operator|.
name|low
argument_list|)
expr_stmt|;
if|if
condition|(
name|w
operator|.
name|s
operator|.
name|low
operator|!=
literal|0
condition|)
return|return
name|w
operator|.
name|ll
return|;
name|w
operator|.
name|s
operator|.
name|low
operator|=
name|ffs
argument_list|(
name|uu
operator|.
name|s
operator|.
name|high
argument_list|)
expr_stmt|;
if|if
condition|(
name|w
operator|.
name|s
operator|.
name|low
operator|!=
literal|0
condition|)
block|{
name|w
operator|.
name|s
operator|.
name|low
operator|+=
name|BITS_PER_UNIT
operator|*
sizeof|sizeof
argument_list|(
name|SItype
argument_list|)
expr_stmt|;
return|return
name|w
operator|.
name|ll
return|;
block|}
return|return
name|w
operator|.
name|ll
return|;
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
name|L_muldi3
end_ifdef

begin_function
name|DItype
name|__muldi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
name|DItype
name|u
decl_stmt|,
name|v
decl_stmt|;
block|{
name|DIunion
name|w
decl_stmt|;
name|DIunion
name|uu
decl_stmt|,
name|vv
decl_stmt|;
name|uu
operator|.
name|ll
operator|=
name|u
operator|,
name|vv
operator|.
name|ll
operator|=
name|v
expr_stmt|;
name|w
operator|.
name|ll
operator|=
name|__umulsidi3
argument_list|(
name|uu
operator|.
name|s
operator|.
name|low
argument_list|,
name|vv
operator|.
name|s
operator|.
name|low
argument_list|)
expr_stmt|;
name|w
operator|.
name|s
operator|.
name|high
operator|+=
operator|(
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|low
operator|*
operator|(
name|USItype
operator|)
name|vv
operator|.
name|s
operator|.
name|high
operator|+
operator|(
name|USItype
operator|)
name|uu
operator|.
name|s
operator|.
name|high
operator|*
operator|(
name|USItype
operator|)
name|vv
operator|.
name|s
operator|.
name|low
operator|)
expr_stmt|;
return|return
name|w
operator|.
name|ll
return|;
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
name|L_udiv_w_sdiv
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sdiv_qrnnd
argument_list|)
end_if

begin_function
name|USItype
name|__udiv_w_sdiv
parameter_list|(
name|rp
parameter_list|,
name|a1
parameter_list|,
name|a0
parameter_list|,
name|d
parameter_list|)
name|USItype
modifier|*
name|rp
decl_stmt|,
name|a1
decl_stmt|,
name|a0
decl_stmt|,
name|d
decl_stmt|;
block|{
name|USItype
name|q
decl_stmt|,
name|r
decl_stmt|;
name|USItype
name|c0
decl_stmt|,
name|c1
decl_stmt|,
name|b1
decl_stmt|;
if|if
condition|(
operator|(
name|SItype
operator|)
name|d
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|a1
operator|<
name|d
operator|-
name|a1
operator|-
operator|(
name|a0
operator|>>
operator|(
name|SI_TYPE_SIZE
operator|-
literal|1
operator|)
operator|)
condition|)
block|{
comment|/* dividend, divisor, and quotient are nonnegative */
name|sdiv_qrnnd
argument_list|(
name|q
argument_list|,
name|r
argument_list|,
name|a1
argument_list|,
name|a0
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Compute c1*2^32 + c0 = a1*2^32 + a0 - 2^31*d */
name|sub_ddmmss
argument_list|(
name|c1
argument_list|,
name|c0
argument_list|,
name|a1
argument_list|,
name|a0
argument_list|,
name|d
operator|>>
literal|1
argument_list|,
name|d
operator|<<
operator|(
name|SI_TYPE_SIZE
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
comment|/* Divide (c1*2^32 + c0) by d */
name|sdiv_qrnnd
argument_list|(
name|q
argument_list|,
name|r
argument_list|,
name|c1
argument_list|,
name|c0
argument_list|,
name|d
argument_list|)
expr_stmt|;
comment|/* Add 2^31 to quotient */
name|q
operator|+=
operator|(
name|USItype
operator|)
literal|1
operator|<<
operator|(
name|SI_TYPE_SIZE
operator|-
literal|1
operator|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|b1
operator|=
name|d
operator|>>
literal|1
expr_stmt|;
comment|/* d/2, between 2^30 and 2^31 - 1 */
name|c1
operator|=
name|a1
operator|>>
literal|1
expr_stmt|;
comment|/* A/2 */
name|c0
operator|=
operator|(
name|a1
operator|<<
operator|(
name|SI_TYPE_SIZE
operator|-
literal|1
operator|)
operator|)
operator|+
operator|(
name|a0
operator|>>
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|a1
operator|<
name|b1
condition|)
comment|/* A< 2^32*b1, so A/2< 2^31*b1 */
block|{
name|sdiv_qrnnd
argument_list|(
name|q
argument_list|,
name|r
argument_list|,
name|c1
argument_list|,
name|c0
argument_list|,
name|b1
argument_list|)
expr_stmt|;
comment|/* (A/2) / (d/2) */
name|r
operator|=
literal|2
operator|*
name|r
operator|+
operator|(
name|a0
operator|&
literal|1
operator|)
expr_stmt|;
comment|/* Remainder from A/(2*b1) */
if|if
condition|(
operator|(
name|d
operator|&
literal|1
operator|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|r
operator|>=
name|q
condition|)
name|r
operator|=
name|r
operator|-
name|q
expr_stmt|;
elseif|else
if|if
condition|(
name|q
operator|-
name|r
operator|<=
name|d
condition|)
block|{
name|r
operator|=
name|r
operator|-
name|q
operator|+
name|d
expr_stmt|;
name|q
operator|--
expr_stmt|;
block|}
else|else
block|{
name|r
operator|=
name|r
operator|-
name|q
operator|+
literal|2
operator|*
name|d
expr_stmt|;
name|q
operator|-=
literal|2
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|c1
operator|<
name|b1
condition|)
comment|/* So 2^31<= (A/2)/b1< 2^32 */
block|{
name|c1
operator|=
operator|(
name|b1
operator|-
literal|1
operator|)
operator|-
name|c1
expr_stmt|;
name|c0
operator|=
operator|~
name|c0
expr_stmt|;
comment|/* logical NOT */
name|sdiv_qrnnd
argument_list|(
name|q
argument_list|,
name|r
argument_list|,
name|c1
argument_list|,
name|c0
argument_list|,
name|b1
argument_list|)
expr_stmt|;
comment|/* (A/2) / (d/2) */
name|q
operator|=
operator|~
name|q
expr_stmt|;
comment|/* (A/2)/b1 */
name|r
operator|=
operator|(
name|b1
operator|-
literal|1
operator|)
operator|-
name|r
expr_stmt|;
name|r
operator|=
literal|2
operator|*
name|r
operator|+
operator|(
name|a0
operator|&
literal|1
operator|)
expr_stmt|;
comment|/* A/(2*b1) */
if|if
condition|(
operator|(
name|d
operator|&
literal|1
operator|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|r
operator|>=
name|q
condition|)
name|r
operator|=
name|r
operator|-
name|q
expr_stmt|;
elseif|else
if|if
condition|(
name|q
operator|-
name|r
operator|<=
name|d
condition|)
block|{
name|r
operator|=
name|r
operator|-
name|q
operator|+
name|d
expr_stmt|;
name|q
operator|--
expr_stmt|;
block|}
else|else
block|{
name|r
operator|=
name|r
operator|-
name|q
operator|+
literal|2
operator|*
name|d
expr_stmt|;
name|q
operator|-=
literal|2
expr_stmt|;
block|}
block|}
block|}
else|else
comment|/* Implies c1 = b1 */
block|{
comment|/* Hence a1 = d - 1 = 2*b1 - 1 */
if|if
condition|(
name|a0
operator|>=
operator|-
name|d
condition|)
block|{
name|q
operator|=
operator|-
literal|1
expr_stmt|;
name|r
operator|=
name|a0
operator|+
name|d
expr_stmt|;
block|}
else|else
block|{
name|q
operator|=
operator|-
literal|2
expr_stmt|;
name|r
operator|=
name|a0
operator|+
literal|2
operator|*
name|d
expr_stmt|;
block|}
block|}
block|}
operator|*
name|rp
operator|=
name|r
expr_stmt|;
return|return
name|q
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* If sdiv_qrnnd doesn't exist, define dummy __udiv_w_sdiv.  */
end_comment

begin_function
name|USItype
name|__udiv_w_sdiv
parameter_list|(
name|rp
parameter_list|,
name|a1
parameter_list|,
name|a0
parameter_list|,
name|d
parameter_list|)
name|USItype
modifier|*
name|rp
decl_stmt|,
name|a1
decl_stmt|,
name|a0
decl_stmt|,
name|d
decl_stmt|;
block|{}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|L_udivdi3
argument_list|)
operator|||
name|defined
argument_list|(
name|L_divdi3
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|L_umoddi3
argument_list|)
operator|||
name|defined
argument_list|(
name|L_moddi3
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|L_udivmoddi4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_udivmoddi4
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|UQItype
name|__clz_tab
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|2
block|,
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|, }
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|L_udivdi3
argument_list|)
operator|||
name|defined
argument_list|(
name|L_divdi3
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|L_umoddi3
argument_list|)
operator|||
name|defined
argument_list|(
name|L_moddi3
argument_list|)
operator|)
end_if

begin_function
specifier|static
specifier|inline
endif|#
directive|endif
name|UDItype
name|__udivmoddi4
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|,
name|rp
parameter_list|)
name|UDItype
name|n
decl_stmt|,
name|d
decl_stmt|;
name|UDItype
modifier|*
name|rp
decl_stmt|;
block|{
name|DIunion
name|ww
decl_stmt|;
name|DIunion
name|nn
decl_stmt|,
name|dd
decl_stmt|;
name|DIunion
name|rr
decl_stmt|;
name|USItype
name|d0
decl_stmt|,
name|d1
decl_stmt|,
name|n0
decl_stmt|,
name|n1
decl_stmt|,
name|n2
decl_stmt|;
name|USItype
name|q0
decl_stmt|,
name|q1
decl_stmt|;
name|USItype
name|b
decl_stmt|,
name|bm
decl_stmt|;
name|nn
operator|.
name|ll
operator|=
name|n
expr_stmt|;
name|dd
operator|.
name|ll
operator|=
name|d
expr_stmt|;
name|d0
operator|=
name|dd
operator|.
name|s
operator|.
name|low
expr_stmt|;
name|d1
operator|=
name|dd
operator|.
name|s
operator|.
name|high
expr_stmt|;
name|n0
operator|=
name|nn
operator|.
name|s
operator|.
name|low
expr_stmt|;
name|n1
operator|=
name|nn
operator|.
name|s
operator|.
name|high
expr_stmt|;
if|#
directive|if
operator|!
name|UDIV_NEEDS_NORMALIZATION
if|if
condition|(
name|d1
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|d0
operator|>
name|n1
condition|)
block|{
comment|/* 0q = nn / 0D */
name|udiv_qrnnd
argument_list|(
name|q0
argument_list|,
name|n0
argument_list|,
name|n1
argument_list|,
name|n0
argument_list|,
name|d0
argument_list|)
expr_stmt|;
name|q1
operator|=
literal|0
expr_stmt|;
comment|/* Remainder in n0.  */
block|}
else|else
block|{
comment|/* qq = NN / 0d */
if|if
condition|(
name|d0
operator|==
literal|0
condition|)
name|d0
operator|=
literal|1
operator|/
name|d0
expr_stmt|;
comment|/* Divide intentionally by zero.  */
name|udiv_qrnnd
argument_list|(
name|q1
argument_list|,
name|n1
argument_list|,
literal|0
argument_list|,
name|n1
argument_list|,
name|d0
argument_list|)
expr_stmt|;
name|udiv_qrnnd
argument_list|(
name|q0
argument_list|,
name|n0
argument_list|,
name|n1
argument_list|,
name|n0
argument_list|,
name|d0
argument_list|)
expr_stmt|;
comment|/* Remainder in n0.  */
block|}
if|if
condition|(
name|rp
operator|!=
literal|0
condition|)
block|{
name|rr
operator|.
name|s
operator|.
name|low
operator|=
name|n0
expr_stmt|;
name|rr
operator|.
name|s
operator|.
name|high
operator|=
literal|0
expr_stmt|;
operator|*
name|rp
operator|=
name|rr
operator|.
name|ll
expr_stmt|;
block|}
block|}
else|#
directive|else
comment|/* UDIV_NEEDS_NORMALIZATION */
if|if
condition|(
name|d1
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|d0
operator|>
name|n1
condition|)
block|{
comment|/* 0q = nn / 0D */
name|count_leading_zeros
argument_list|(
name|bm
argument_list|,
name|d0
argument_list|)
expr_stmt|;
if|if
condition|(
name|bm
operator|!=
literal|0
condition|)
block|{
comment|/* Normalize, i.e. make the most significant bit of the 		 denominator set.  */
name|d0
operator|=
name|d0
operator|<<
name|bm
expr_stmt|;
name|n1
operator|=
operator|(
name|n1
operator|<<
name|bm
operator|)
operator||
operator|(
name|n0
operator|>>
operator|(
name|SI_TYPE_SIZE
operator|-
name|bm
operator|)
operator|)
expr_stmt|;
name|n0
operator|=
name|n0
operator|<<
name|bm
expr_stmt|;
block|}
name|udiv_qrnnd
argument_list|(
name|q0
argument_list|,
name|n0
argument_list|,
name|n1
argument_list|,
name|n0
argument_list|,
name|d0
argument_list|)
expr_stmt|;
name|q1
operator|=
literal|0
expr_stmt|;
comment|/* Remainder in n0>> bm.  */
block|}
else|else
block|{
comment|/* qq = NN / 0d */
if|if
condition|(
name|d0
operator|==
literal|0
condition|)
name|d0
operator|=
literal|1
operator|/
name|d0
expr_stmt|;
comment|/* Divide intentionally by zero.  */
name|count_leading_zeros
argument_list|(
name|bm
argument_list|,
name|d0
argument_list|)
expr_stmt|;
if|if
condition|(
name|bm
operator|==
literal|0
condition|)
block|{
comment|/* From (n1>= d0) /\ (the most significant bit of d0 is set), 		 conclude (the most significant bit of n1 is set) /\ (the 		 leading quotient digit q1 = 1).  		 This special case is necessary, not an optimization. 		 (Shifts counts of SI_TYPE_SIZE are undefined.)  */
name|n1
operator|-=
name|d0
expr_stmt|;
name|q1
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|/* Normalize.  */
name|b
operator|=
name|SI_TYPE_SIZE
operator|-
name|bm
expr_stmt|;
name|d0
operator|=
name|d0
operator|<<
name|bm
expr_stmt|;
name|n2
operator|=
name|n1
operator|>>
name|b
expr_stmt|;
name|n1
operator|=
operator|(
name|n1
operator|<<
name|bm
operator|)
operator||
operator|(
name|n0
operator|>>
name|b
operator|)
expr_stmt|;
name|n0
operator|=
name|n0
operator|<<
name|bm
expr_stmt|;
name|udiv_qrnnd
argument_list|(
name|q1
argument_list|,
name|n1
argument_list|,
name|n2
argument_list|,
name|n1
argument_list|,
name|d0
argument_list|)
expr_stmt|;
block|}
comment|/* n1 != d0... */
name|udiv_qrnnd
argument_list|(
name|q0
argument_list|,
name|n0
argument_list|,
name|n1
argument_list|,
name|n0
argument_list|,
name|d0
argument_list|)
expr_stmt|;
comment|/* Remainder in n0>> bm.  */
block|}
if|if
condition|(
name|rp
operator|!=
literal|0
condition|)
block|{
name|rr
operator|.
name|s
operator|.
name|low
operator|=
name|n0
operator|>>
name|bm
expr_stmt|;
name|rr
operator|.
name|s
operator|.
name|high
operator|=
literal|0
expr_stmt|;
operator|*
name|rp
operator|=
name|rr
operator|.
name|ll
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* UDIV_NEEDS_NORMALIZATION */
else|else
block|{
if|if
condition|(
name|d1
operator|>
name|n1
condition|)
block|{
comment|/* 00 = nn / DD */
name|q0
operator|=
literal|0
expr_stmt|;
name|q1
operator|=
literal|0
expr_stmt|;
comment|/* Remainder in n1n0.  */
if|if
condition|(
name|rp
operator|!=
literal|0
condition|)
block|{
name|rr
operator|.
name|s
operator|.
name|low
operator|=
name|n0
expr_stmt|;
name|rr
operator|.
name|s
operator|.
name|high
operator|=
name|n1
expr_stmt|;
operator|*
name|rp
operator|=
name|rr
operator|.
name|ll
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* 0q = NN / dd */
name|count_leading_zeros
argument_list|(
name|bm
argument_list|,
name|d1
argument_list|)
expr_stmt|;
if|if
condition|(
name|bm
operator|==
literal|0
condition|)
block|{
comment|/* From (n1>= d1) /\ (the most significant bit of d1 is set), 		 conclude (the most significant bit of n1 is set) /\ (the 		 quotient digit q0 = 0 or 1).  		 This special case is necessary, not an optimization.  */
comment|/* The condition on the next line takes advantage of that 		 n1>= d1 (true due to program flow).  */
if|if
condition|(
name|n1
operator|>
name|d1
operator|||
name|n0
operator|>=
name|d0
condition|)
block|{
name|q0
operator|=
literal|1
expr_stmt|;
name|sub_ddmmss
argument_list|(
name|n1
argument_list|,
name|n0
argument_list|,
name|n1
argument_list|,
name|n0
argument_list|,
name|d1
argument_list|,
name|d0
argument_list|)
expr_stmt|;
block|}
else|else
name|q0
operator|=
literal|0
expr_stmt|;
name|q1
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|rp
operator|!=
literal|0
condition|)
block|{
name|rr
operator|.
name|s
operator|.
name|low
operator|=
name|n0
expr_stmt|;
name|rr
operator|.
name|s
operator|.
name|high
operator|=
name|n1
expr_stmt|;
operator|*
name|rp
operator|=
name|rr
operator|.
name|ll
expr_stmt|;
block|}
block|}
else|else
block|{
name|USItype
name|m1
decl_stmt|,
name|m0
decl_stmt|;
comment|/* Normalize.  */
name|b
operator|=
name|SI_TYPE_SIZE
operator|-
name|bm
expr_stmt|;
name|d1
operator|=
operator|(
name|d1
operator|<<
name|bm
operator|)
operator||
operator|(
name|d0
operator|>>
name|b
operator|)
expr_stmt|;
name|d0
operator|=
name|d0
operator|<<
name|bm
expr_stmt|;
name|n2
operator|=
name|n1
operator|>>
name|b
expr_stmt|;
name|n1
operator|=
operator|(
name|n1
operator|<<
name|bm
operator|)
operator||
operator|(
name|n0
operator|>>
name|b
operator|)
expr_stmt|;
name|n0
operator|=
name|n0
operator|<<
name|bm
expr_stmt|;
name|udiv_qrnnd
argument_list|(
name|q0
argument_list|,
name|n1
argument_list|,
name|n2
argument_list|,
name|n1
argument_list|,
name|d1
argument_list|)
expr_stmt|;
name|umul_ppmm
argument_list|(
name|m1
argument_list|,
name|m0
argument_list|,
name|q0
argument_list|,
name|d0
argument_list|)
expr_stmt|;
if|if
condition|(
name|m1
operator|>
name|n1
operator|||
operator|(
name|m1
operator|==
name|n1
operator|&&
name|m0
operator|>
name|n0
operator|)
condition|)
block|{
name|q0
operator|--
expr_stmt|;
name|sub_ddmmss
argument_list|(
name|m1
argument_list|,
name|m0
argument_list|,
name|m1
argument_list|,
name|m0
argument_list|,
name|d1
argument_list|,
name|d0
argument_list|)
expr_stmt|;
block|}
name|q1
operator|=
literal|0
expr_stmt|;
comment|/* Remainder in (n1n0 - m1m0)>> bm.  */
if|if
condition|(
name|rp
operator|!=
literal|0
condition|)
block|{
name|sub_ddmmss
argument_list|(
name|n1
argument_list|,
name|n0
argument_list|,
name|n1
argument_list|,
name|n0
argument_list|,
name|m1
argument_list|,
name|m0
argument_list|)
expr_stmt|;
name|rr
operator|.
name|s
operator|.
name|low
operator|=
operator|(
name|n1
operator|<<
name|b
operator|)
operator||
operator|(
name|n0
operator|>>
name|bm
operator|)
expr_stmt|;
name|rr
operator|.
name|s
operator|.
name|high
operator|=
name|n1
operator|>>
name|bm
expr_stmt|;
operator|*
name|rp
operator|=
name|rr
operator|.
name|ll
expr_stmt|;
block|}
block|}
block|}
block|}
name|ww
operator|.
name|s
operator|.
name|low
operator|=
name|q0
expr_stmt|;
name|ww
operator|.
name|s
operator|.
name|high
operator|=
name|q1
expr_stmt|;
return|return
name|ww
operator|.
name|ll
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_divdi3
end_ifdef

begin_function_decl
name|UDItype
name|__udivmoddi4
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|DItype
name|__divdi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
name|DItype
name|u
decl_stmt|,
name|v
decl_stmt|;
block|{
name|word_type
name|c
init|=
literal|0
decl_stmt|;
name|DIunion
name|uu
decl_stmt|,
name|vv
decl_stmt|;
name|DItype
name|w
decl_stmt|;
name|uu
operator|.
name|ll
operator|=
name|u
expr_stmt|;
name|vv
operator|.
name|ll
operator|=
name|v
expr_stmt|;
if|if
condition|(
name|uu
operator|.
name|s
operator|.
name|high
operator|<
literal|0
condition|)
name|c
operator|=
operator|~
name|c
operator|,
name|uu
operator|.
name|ll
operator|=
name|__negdi2
argument_list|(
name|uu
operator|.
name|ll
argument_list|)
expr_stmt|;
if|if
condition|(
name|vv
operator|.
name|s
operator|.
name|high
operator|<
literal|0
condition|)
name|c
operator|=
operator|~
name|c
operator|,
name|vv
operator|.
name|ll
operator|=
name|__negdi2
argument_list|(
name|vv
operator|.
name|ll
argument_list|)
expr_stmt|;
name|w
operator|=
name|__udivmoddi4
argument_list|(
name|uu
operator|.
name|ll
argument_list|,
name|vv
operator|.
name|ll
argument_list|,
operator|(
name|UDItype
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
condition|)
name|w
operator|=
name|__negdi2
argument_list|(
name|w
argument_list|)
expr_stmt|;
return|return
name|w
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_moddi3
end_ifdef

begin_function_decl
name|UDItype
name|__udivmoddi4
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|DItype
name|__moddi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
name|DItype
name|u
decl_stmt|,
name|v
decl_stmt|;
block|{
name|word_type
name|c
init|=
literal|0
decl_stmt|;
name|DIunion
name|uu
decl_stmt|,
name|vv
decl_stmt|;
name|DItype
name|w
decl_stmt|;
name|uu
operator|.
name|ll
operator|=
name|u
expr_stmt|;
name|vv
operator|.
name|ll
operator|=
name|v
expr_stmt|;
if|if
condition|(
name|uu
operator|.
name|s
operator|.
name|high
operator|<
literal|0
condition|)
name|c
operator|=
operator|~
name|c
operator|,
name|uu
operator|.
name|ll
operator|=
name|__negdi2
argument_list|(
name|uu
operator|.
name|ll
argument_list|)
expr_stmt|;
if|if
condition|(
name|vv
operator|.
name|s
operator|.
name|high
operator|<
literal|0
condition|)
name|vv
operator|.
name|ll
operator|=
name|__negdi2
argument_list|(
name|vv
operator|.
name|ll
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__udivmoddi4
argument_list|(
name|uu
operator|.
name|ll
argument_list|,
name|vv
operator|.
name|ll
argument_list|,
operator|&
name|w
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
condition|)
name|w
operator|=
name|__negdi2
argument_list|(
name|w
argument_list|)
expr_stmt|;
return|return
name|w
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_umoddi3
end_ifdef

begin_function_decl
name|UDItype
name|__udivmoddi4
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|UDItype
name|__umoddi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
name|UDItype
name|u
decl_stmt|,
name|v
decl_stmt|;
block|{
name|UDItype
name|w
decl_stmt|;
operator|(
name|void
operator|)
name|__udivmoddi4
argument_list|(
name|u
argument_list|,
name|v
argument_list|,
operator|&
name|w
argument_list|)
expr_stmt|;
return|return
name|w
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_udivdi3
end_ifdef

begin_function_decl
name|UDItype
name|__udivmoddi4
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|UDItype
name|__udivdi3
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|)
name|UDItype
name|n
decl_stmt|,
name|d
decl_stmt|;
block|{
return|return
name|__udivmoddi4
argument_list|(
name|n
argument_list|,
name|d
argument_list|,
operator|(
name|UDItype
operator|*
operator|)
literal|0
argument_list|)
return|;
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
name|L_cmpdi2
end_ifdef

begin_function
name|word_type
name|__cmpdi2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|DItype
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|DIunion
name|au
decl_stmt|,
name|bu
decl_stmt|;
name|au
operator|.
name|ll
operator|=
name|a
operator|,
name|bu
operator|.
name|ll
operator|=
name|b
expr_stmt|;
if|if
condition|(
name|au
operator|.
name|s
operator|.
name|high
operator|<
name|bu
operator|.
name|s
operator|.
name|high
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
name|au
operator|.
name|s
operator|.
name|high
operator|>
name|bu
operator|.
name|s
operator|.
name|high
condition|)
return|return
literal|2
return|;
if|if
condition|(
operator|(
name|USItype
operator|)
name|au
operator|.
name|s
operator|.
name|low
operator|<
operator|(
name|USItype
operator|)
name|bu
operator|.
name|s
operator|.
name|low
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
operator|(
name|USItype
operator|)
name|au
operator|.
name|s
operator|.
name|low
operator|>
operator|(
name|USItype
operator|)
name|bu
operator|.
name|s
operator|.
name|low
condition|)
return|return
literal|2
return|;
return|return
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_ucmpdi2
end_ifdef

begin_function
name|word_type
name|__ucmpdi2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|DItype
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|DIunion
name|au
decl_stmt|,
name|bu
decl_stmt|;
name|au
operator|.
name|ll
operator|=
name|a
operator|,
name|bu
operator|.
name|ll
operator|=
name|b
expr_stmt|;
if|if
condition|(
operator|(
name|USItype
operator|)
name|au
operator|.
name|s
operator|.
name|high
operator|<
operator|(
name|USItype
operator|)
name|bu
operator|.
name|s
operator|.
name|high
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
operator|(
name|USItype
operator|)
name|au
operator|.
name|s
operator|.
name|high
operator|>
operator|(
name|USItype
operator|)
name|bu
operator|.
name|s
operator|.
name|high
condition|)
return|return
literal|2
return|;
if|if
condition|(
operator|(
name|USItype
operator|)
name|au
operator|.
name|s
operator|.
name|low
operator|<
operator|(
name|USItype
operator|)
name|bu
operator|.
name|s
operator|.
name|low
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
operator|(
name|USItype
operator|)
name|au
operator|.
name|s
operator|.
name|low
operator|>
operator|(
name|USItype
operator|)
name|bu
operator|.
name|s
operator|.
name|low
condition|)
return|return
literal|2
return|;
return|return
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_fixunstfdi
argument_list|)
operator|&&
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|128
operator|)
end_if

begin_define
define|#
directive|define
name|WORD_SIZE
value|(sizeof (SItype) * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((UDItype) 1)<< WORD_SIZE)
end_define

begin_function
name|DItype
name|__fixunstfdi
parameter_list|(
name|a
parameter_list|)
name|TFtype
name|a
decl_stmt|;
block|{
name|TFtype
name|b
decl_stmt|;
name|UDItype
name|v
decl_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|/* Compute high word of result, as a flonum.  */
name|b
operator|=
operator|(
name|a
operator|/
name|HIGH_WORD_COEFF
operator|)
expr_stmt|;
comment|/* Convert that to fixed (but not to DItype!),      and shift it into the high word.  */
name|v
operator|=
operator|(
name|USItype
operator|)
name|b
expr_stmt|;
name|v
operator|<<=
name|WORD_SIZE
expr_stmt|;
comment|/* Remove high part from the TFtype, leaving the low part as flonum.  */
name|a
operator|-=
operator|(
name|TFtype
operator|)
name|v
expr_stmt|;
comment|/* Convert that to fixed (but not to DItype!) and add it in.      Sometimes A comes out negative.  This is significant, since      A has more bits than a long int does.  */
if|if
condition|(
name|a
operator|<
literal|0
condition|)
name|v
operator|-=
call|(
name|USItype
call|)
argument_list|(
operator|-
name|a
argument_list|)
expr_stmt|;
else|else
name|v
operator|+=
operator|(
name|USItype
operator|)
name|a
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_fixtfdi
argument_list|)
operator|&&
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|128
operator|)
end_if

begin_function
name|DItype
name|__fixtfdi
parameter_list|(
name|a
parameter_list|)
name|TFtype
name|a
decl_stmt|;
block|{
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
operator|-
name|__fixunstfdi
argument_list|(
operator|-
name|a
argument_list|)
return|;
return|return
name|__fixunstfdi
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_fixunsxfdi
argument_list|)
operator|&&
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
operator|)
end_if

begin_define
define|#
directive|define
name|WORD_SIZE
value|(sizeof (SItype) * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((UDItype) 1)<< WORD_SIZE)
end_define

begin_function
name|DItype
name|__fixunsxfdi
parameter_list|(
name|a
parameter_list|)
name|XFtype
name|a
decl_stmt|;
block|{
name|XFtype
name|b
decl_stmt|;
name|UDItype
name|v
decl_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|/* Compute high word of result, as a flonum.  */
name|b
operator|=
operator|(
name|a
operator|/
name|HIGH_WORD_COEFF
operator|)
expr_stmt|;
comment|/* Convert that to fixed (but not to DItype!),      and shift it into the high word.  */
name|v
operator|=
operator|(
name|USItype
operator|)
name|b
expr_stmt|;
name|v
operator|<<=
name|WORD_SIZE
expr_stmt|;
comment|/* Remove high part from the XFtype, leaving the low part as flonum.  */
name|a
operator|-=
operator|(
name|XFtype
operator|)
name|v
expr_stmt|;
comment|/* Convert that to fixed (but not to DItype!) and add it in.      Sometimes A comes out negative.  This is significant, since      A has more bits than a long int does.  */
if|if
condition|(
name|a
operator|<
literal|0
condition|)
name|v
operator|-=
call|(
name|USItype
call|)
argument_list|(
operator|-
name|a
argument_list|)
expr_stmt|;
else|else
name|v
operator|+=
operator|(
name|USItype
operator|)
name|a
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_fixxfdi
argument_list|)
operator|&&
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
operator|)
end_if

begin_function
name|DItype
name|__fixxfdi
parameter_list|(
name|a
parameter_list|)
name|XFtype
name|a
decl_stmt|;
block|{
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
operator|-
name|__fixunsxfdi
argument_list|(
operator|-
name|a
argument_list|)
return|;
return|return
name|__fixunsxfdi
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunsdfdi
end_ifdef

begin_define
define|#
directive|define
name|WORD_SIZE
value|(sizeof (SItype) * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((UDItype) 1)<< WORD_SIZE)
end_define

begin_function
name|DItype
name|__fixunsdfdi
parameter_list|(
name|a
parameter_list|)
name|DFtype
name|a
decl_stmt|;
block|{
name|DFtype
name|b
decl_stmt|;
name|UDItype
name|v
decl_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|/* Compute high word of result, as a flonum.  */
name|b
operator|=
operator|(
name|a
operator|/
name|HIGH_WORD_COEFF
operator|)
expr_stmt|;
comment|/* Convert that to fixed (but not to DItype!),      and shift it into the high word.  */
name|v
operator|=
operator|(
name|USItype
operator|)
name|b
expr_stmt|;
name|v
operator|<<=
name|WORD_SIZE
expr_stmt|;
comment|/* Remove high part from the DFtype, leaving the low part as flonum.  */
name|a
operator|-=
operator|(
name|DFtype
operator|)
name|v
expr_stmt|;
comment|/* Convert that to fixed (but not to DItype!) and add it in.      Sometimes A comes out negative.  This is significant, since      A has more bits than a long int does.  */
if|if
condition|(
name|a
operator|<
literal|0
condition|)
name|v
operator|-=
call|(
name|USItype
call|)
argument_list|(
operator|-
name|a
argument_list|)
expr_stmt|;
else|else
name|v
operator|+=
operator|(
name|USItype
operator|)
name|a
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixdfdi
end_ifdef

begin_function
name|DItype
name|__fixdfdi
parameter_list|(
name|a
parameter_list|)
name|DFtype
name|a
decl_stmt|;
block|{
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
operator|-
name|__fixunsdfdi
argument_list|(
operator|-
name|a
argument_list|)
return|;
return|return
name|__fixunsdfdi
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunssfdi
end_ifdef

begin_define
define|#
directive|define
name|WORD_SIZE
value|(sizeof (SItype) * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((UDItype) 1)<< WORD_SIZE)
end_define

begin_function
name|DItype
name|__fixunssfdi
parameter_list|(
name|SFtype
name|original_a
parameter_list|)
block|{
comment|/* Convert the SFtype to a DFtype, because that is surely not going      to lose any bits.  Some day someone else can write a faster version      that avoids converting to DFtype, and verify it really works right.  */
name|DFtype
name|a
init|=
name|original_a
decl_stmt|;
name|DFtype
name|b
decl_stmt|;
name|UDItype
name|v
decl_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|/* Compute high word of result, as a flonum.  */
name|b
operator|=
operator|(
name|a
operator|/
name|HIGH_WORD_COEFF
operator|)
expr_stmt|;
comment|/* Convert that to fixed (but not to DItype!),      and shift it into the high word.  */
name|v
operator|=
operator|(
name|USItype
operator|)
name|b
expr_stmt|;
name|v
operator|<<=
name|WORD_SIZE
expr_stmt|;
comment|/* Remove high part from the DFtype, leaving the low part as flonum.  */
name|a
operator|-=
operator|(
name|DFtype
operator|)
name|v
expr_stmt|;
comment|/* Convert that to fixed (but not to DItype!) and add it in.      Sometimes A comes out negative.  This is significant, since      A has more bits than a long int does.  */
if|if
condition|(
name|a
operator|<
literal|0
condition|)
name|v
operator|-=
call|(
name|USItype
call|)
argument_list|(
operator|-
name|a
argument_list|)
expr_stmt|;
else|else
name|v
operator|+=
operator|(
name|USItype
operator|)
name|a
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixsfdi
end_ifdef

begin_function
name|DItype
name|__fixsfdi
parameter_list|(
name|SFtype
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
operator|-
name|__fixunssfdi
argument_list|(
operator|-
name|a
argument_list|)
return|;
return|return
name|__fixunssfdi
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_floatdixf
argument_list|)
operator|&&
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
operator|)
end_if

begin_define
define|#
directive|define
name|WORD_SIZE
value|(sizeof (SItype) * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|HIGH_HALFWORD_COEFF
value|(((UDItype) 1)<< (WORD_SIZE / 2))
end_define

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((UDItype) 1)<< WORD_SIZE)
end_define

begin_function
name|XFtype
name|__floatdixf
parameter_list|(
name|u
parameter_list|)
name|DItype
name|u
decl_stmt|;
block|{
name|XFtype
name|d
decl_stmt|;
name|SItype
name|negate
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|u
operator|<
literal|0
condition|)
name|u
operator|=
operator|-
name|u
operator|,
name|negate
operator|=
literal|1
expr_stmt|;
name|d
operator|=
call|(
name|USItype
call|)
argument_list|(
name|u
operator|>>
name|WORD_SIZE
argument_list|)
expr_stmt|;
name|d
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|d
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|d
operator|+=
call|(
name|USItype
call|)
argument_list|(
name|u
operator|&
operator|(
name|HIGH_WORD_COEFF
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|negate
condition|?
operator|-
name|d
else|:
name|d
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_floatditf
argument_list|)
operator|&&
operator|(
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|128
operator|)
end_if

begin_define
define|#
directive|define
name|WORD_SIZE
value|(sizeof (SItype) * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|HIGH_HALFWORD_COEFF
value|(((UDItype) 1)<< (WORD_SIZE / 2))
end_define

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((UDItype) 1)<< WORD_SIZE)
end_define

begin_function
name|TFtype
name|__floatditf
parameter_list|(
name|u
parameter_list|)
name|DItype
name|u
decl_stmt|;
block|{
name|TFtype
name|d
decl_stmt|;
name|SItype
name|negate
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|u
operator|<
literal|0
condition|)
name|u
operator|=
operator|-
name|u
operator|,
name|negate
operator|=
literal|1
expr_stmt|;
name|d
operator|=
call|(
name|USItype
call|)
argument_list|(
name|u
operator|>>
name|WORD_SIZE
argument_list|)
expr_stmt|;
name|d
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|d
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|d
operator|+=
call|(
name|USItype
call|)
argument_list|(
name|u
operator|&
operator|(
name|HIGH_WORD_COEFF
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|negate
condition|?
operator|-
name|d
else|:
name|d
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_floatdidf
end_ifdef

begin_define
define|#
directive|define
name|WORD_SIZE
value|(sizeof (SItype) * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|HIGH_HALFWORD_COEFF
value|(((UDItype) 1)<< (WORD_SIZE / 2))
end_define

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((UDItype) 1)<< WORD_SIZE)
end_define

begin_function
name|DFtype
name|__floatdidf
parameter_list|(
name|u
parameter_list|)
name|DItype
name|u
decl_stmt|;
block|{
name|DFtype
name|d
decl_stmt|;
name|SItype
name|negate
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|u
operator|<
literal|0
condition|)
name|u
operator|=
operator|-
name|u
operator|,
name|negate
operator|=
literal|1
expr_stmt|;
name|d
operator|=
call|(
name|USItype
call|)
argument_list|(
name|u
operator|>>
name|WORD_SIZE
argument_list|)
expr_stmt|;
name|d
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|d
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|d
operator|+=
call|(
name|USItype
call|)
argument_list|(
name|u
operator|&
operator|(
name|HIGH_WORD_COEFF
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|negate
condition|?
operator|-
name|d
else|:
name|d
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_floatdisf
end_ifdef

begin_define
define|#
directive|define
name|WORD_SIZE
value|(sizeof (SItype) * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|HIGH_HALFWORD_COEFF
value|(((UDItype) 1)<< (WORD_SIZE / 2))
end_define

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((UDItype) 1)<< WORD_SIZE)
end_define

begin_define
define|#
directive|define
name|DI_SIZE
value|(sizeof (DItype) * BITS_PER_UNIT)
end_define

begin_comment
comment|/* Define codes for all the float formats that we know of.  Note    that this is copied from real.h.  */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_FLOAT_FORMAT
value|0
end_define

begin_define
define|#
directive|define
name|IEEE_FLOAT_FORMAT
value|1
end_define

begin_define
define|#
directive|define
name|VAX_FLOAT_FORMAT
value|2
end_define

begin_define
define|#
directive|define
name|IBM_FLOAT_FORMAT
value|3
end_define

begin_comment
comment|/* Default to IEEE float if not specified.  Nearly all machines use it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_FLOAT_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|HOST_FLOAT_FORMAT
value|IEEE_FLOAT_FORMAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HOST_FLOAT_FORMAT
operator|==
name|IEEE_FLOAT_FORMAT
end_if

begin_define
define|#
directive|define
name|DF_SIZE
value|53
end_define

begin_define
define|#
directive|define
name|SF_SIZE
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HOST_FLOAT_FORMAT
operator|==
name|IBM_FLOAT_FORMAT
end_if

begin_define
define|#
directive|define
name|DF_SIZE
value|56
end_define

begin_define
define|#
directive|define
name|SF_SIZE
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HOST_FLOAT_FORMAT
operator|==
name|VAX_FLOAT_FORMAT
end_if

begin_define
define|#
directive|define
name|DF_SIZE
value|56
end_define

begin_define
define|#
directive|define
name|SF_SIZE
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|SFtype
name|__floatdisf
parameter_list|(
name|u
parameter_list|)
name|DItype
name|u
decl_stmt|;
block|{
comment|/* Do the calculation in DFmode      so that we don't lose any of the precision of the high word      while multiplying it.  */
name|DFtype
name|f
decl_stmt|;
name|SItype
name|negate
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|u
operator|<
literal|0
condition|)
name|u
operator|=
operator|-
name|u
operator|,
name|negate
operator|=
literal|1
expr_stmt|;
comment|/* Protect against double-rounding error.      Represent any low-order bits, that might be truncated in DFmode,      by a bit that won't be lost.  The bit can go in anywhere below the      rounding position of the SFmode.  A fixed mask and bit position      handles all usual configurations.  It doesn't handle the case      of 128-bit DImode, however.  */
if|if
condition|(
name|DF_SIZE
operator|<
name|DI_SIZE
operator|&&
name|DF_SIZE
operator|>
operator|(
name|DI_SIZE
operator|-
name|DF_SIZE
operator|+
name|SF_SIZE
operator|)
condition|)
block|{
define|#
directive|define
name|REP_BIT
value|((USItype) 1<< (DI_SIZE - DF_SIZE))
if|if
condition|(
name|u
operator|>=
operator|(
operator|(
name|UDItype
operator|)
literal|1
operator|<<
name|DF_SIZE
operator|)
condition|)
block|{
if|if
condition|(
operator|(
name|USItype
operator|)
name|u
operator|&
operator|(
name|REP_BIT
operator|-
literal|1
operator|)
condition|)
name|u
operator||=
name|REP_BIT
expr_stmt|;
block|}
block|}
name|f
operator|=
call|(
name|USItype
call|)
argument_list|(
name|u
operator|>>
name|WORD_SIZE
argument_list|)
expr_stmt|;
name|f
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|f
operator|*=
name|HIGH_HALFWORD_COEFF
expr_stmt|;
name|f
operator|+=
call|(
name|USItype
call|)
argument_list|(
name|u
operator|&
operator|(
name|HIGH_WORD_COEFF
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
return|return
call|(
name|SFtype
call|)
argument_list|(
name|negate
condition|?
operator|-
name|f
else|:
name|f
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_fixunsxfsi
argument_list|)
operator|&&
name|LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
end_if

begin_comment
comment|/* Reenable the normal types, in case limits.h needs them.  */
end_comment

begin_undef
undef|#
directive|undef
name|char
end_undef

begin_undef
undef|#
directive|undef
name|short
end_undef

begin_undef
undef|#
directive|undef
name|int
end_undef

begin_undef
undef|#
directive|undef
name|long
end_undef

begin_undef
undef|#
directive|undef
name|unsigned
end_undef

begin_undef
undef|#
directive|undef
name|float
end_undef

begin_undef
undef|#
directive|undef
name|double
end_undef

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

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_function
name|USItype
name|__fixunsxfsi
parameter_list|(
name|a
parameter_list|)
name|XFtype
name|a
decl_stmt|;
block|{
if|if
condition|(
name|a
operator|>=
operator|-
operator|(
name|DFtype
operator|)
name|LONG_MIN
condition|)
return|return
call|(
name|SItype
call|)
argument_list|(
name|a
operator|+
name|LONG_MIN
argument_list|)
operator|-
name|LONG_MIN
return|;
return|return
operator|(
name|SItype
operator|)
name|a
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunsdfsi
end_ifdef

begin_comment
comment|/* Reenable the normal types, in case limits.h needs them.  */
end_comment

begin_undef
undef|#
directive|undef
name|char
end_undef

begin_undef
undef|#
directive|undef
name|short
end_undef

begin_undef
undef|#
directive|undef
name|int
end_undef

begin_undef
undef|#
directive|undef
name|long
end_undef

begin_undef
undef|#
directive|undef
name|unsigned
end_undef

begin_undef
undef|#
directive|undef
name|float
end_undef

begin_undef
undef|#
directive|undef
name|double
end_undef

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

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_function
name|USItype
name|__fixunsdfsi
parameter_list|(
name|a
parameter_list|)
name|DFtype
name|a
decl_stmt|;
block|{
if|if
condition|(
name|a
operator|>=
operator|-
operator|(
name|DFtype
operator|)
name|LONG_MIN
condition|)
return|return
call|(
name|SItype
call|)
argument_list|(
name|a
operator|+
name|LONG_MIN
argument_list|)
operator|-
name|LONG_MIN
return|;
return|return
operator|(
name|SItype
operator|)
name|a
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_fixunssfsi
end_ifdef

begin_comment
comment|/* Reenable the normal types, in case limits.h needs them.  */
end_comment

begin_undef
undef|#
directive|undef
name|char
end_undef

begin_undef
undef|#
directive|undef
name|short
end_undef

begin_undef
undef|#
directive|undef
name|int
end_undef

begin_undef
undef|#
directive|undef
name|long
end_undef

begin_undef
undef|#
directive|undef
name|unsigned
end_undef

begin_undef
undef|#
directive|undef
name|float
end_undef

begin_undef
undef|#
directive|undef
name|double
end_undef

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

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_function
name|USItype
name|__fixunssfsi
parameter_list|(
name|SFtype
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|>=
operator|-
operator|(
name|SFtype
operator|)
name|LONG_MIN
condition|)
return|return
call|(
name|SItype
call|)
argument_list|(
name|a
operator|+
name|LONG_MIN
argument_list|)
operator|-
name|LONG_MIN
return|;
return|return
operator|(
name|SItype
operator|)
name|a
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* From here on down, the routines use normal data types.  */
end_comment

begin_define
define|#
directive|define
name|SItype
value|bogus_type
end_define

begin_define
define|#
directive|define
name|USItype
value|bogus_type
end_define

begin_define
define|#
directive|define
name|DItype
value|bogus_type
end_define

begin_define
define|#
directive|define
name|UDItype
value|bogus_type
end_define

begin_define
define|#
directive|define
name|SFtype
value|bogus_type
end_define

begin_define
define|#
directive|define
name|DFtype
value|bogus_type
end_define

begin_undef
undef|#
directive|undef
name|char
end_undef

begin_undef
undef|#
directive|undef
name|short
end_undef

begin_undef
undef|#
directive|undef
name|int
end_undef

begin_undef
undef|#
directive|undef
name|long
end_undef

begin_undef
undef|#
directive|undef
name|unsigned
end_undef

begin_undef
undef|#
directive|undef
name|float
end_undef

begin_undef
undef|#
directive|undef
name|double
end_undef

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L__gcc_bcmp
end_ifdef

begin_comment
comment|/* Like bcmp except the sign is meaningful.    Result is negative if S1 is less than S2,    positive if S1 is greater, 0 if S1 and S2 are equal.  */
end_comment

begin_function
name|int
name|__gcc_bcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|size
parameter_list|)
name|unsigned
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_decl_stmt
name|size_t
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|size
operator|>
literal|0
condition|)
block|{
name|unsigned
name|char
name|c1
init|=
operator|*
name|s1
operator|++
decl_stmt|,
name|c2
init|=
operator|*
name|s2
operator|++
decl_stmt|;
if|if
condition|(
name|c1
operator|!=
name|c2
condition|)
return|return
name|c1
operator|-
name|c2
return|;
name|size
operator|--
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_varargs
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__i860__
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alliant__
argument_list|)
end_if

begin_asm
asm|asm ("	.text");
end_asm

begin_asm
asm|asm ("	.align	4");
end_asm

begin_comment
comment|/* The Alliant needs the added underscore.  */
end_comment

begin_asm
asm|asm (".globl	__builtin_saveregs");
end_asm

begin_asm
asm|asm ("__builtin_saveregs:");
end_asm

begin_asm
asm|asm (".globl	___builtin_saveregs");
end_asm

begin_asm
asm|asm ("___builtin_saveregs:");
end_asm

begin_asm
asm|asm ("	andnot	0x0f,%sp,%sp");
end_asm

begin_comment
comment|/* round down to 16-byte boundary */
end_comment

begin_asm
asm|asm ("	adds	-96,%sp,%sp");
end_asm

begin_comment
comment|/* allocate stack space for reg save 					   area and also for a new va_list 					   structure */
end_comment

begin_comment
comment|/* Save all argument registers in the arg reg save area.  The 	   arg reg save area must have the following layout (according 	   to the svr4 ABI):  		struct { 		  union  { 		    float freg[8]; 		    double dreg[4]; 		  } float_regs; 		  long	ireg[12]; 		}; 	*/
end_comment

begin_asm
asm|asm ("	fst.q	%f8,  0(%sp)");
end_asm

begin_comment
comment|/* save floating regs (f8-f15)  */
end_comment

begin_asm
asm|asm ("	fst.q	%f12,16(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r16,32(%sp)");
end_asm

begin_comment
comment|/* save integer regs (r16-r27) */
end_comment

begin_asm
asm|asm ("	st.l	%r17,36(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r18,40(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r19,44(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r20,48(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r21,52(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r22,56(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r23,60(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r24,64(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r25,68(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r26,72(%sp)");
end_asm

begin_asm
asm|asm ("	st.l	%r27,76(%sp)");
end_asm

begin_asm
asm|asm ("	adds	80,%sp,%r16");
end_asm

begin_comment
comment|/* compute the address of the new 					   va_list structure.  Put in into 					   r16 so that it will be returned 					   to the caller.  */
end_comment

begin_comment
comment|/* Initialize all fields of the new va_list structure.  This 	   structure looks like:  		typedef struct { 		    unsigned long	ireg_used; 		    unsigned long	freg_used; 		    long		*reg_base; 		    long		*mem_ptr; 		} va_list; 	*/
end_comment

begin_asm
asm|asm ("	st.l	%r0, 0(%r16)");
end_asm

begin_comment
comment|/* nfixed */
end_comment

begin_asm
asm|asm ("	st.l	%r0, 4(%r16)");
end_asm

begin_comment
comment|/* nfloating */
end_comment

begin_asm
asm|asm ("  st.l    %sp, 8(%r16)");
end_asm

begin_comment
comment|/* __va_ctl points to __va_struct.  */
end_comment

begin_asm
asm|asm ("	bri	%r1");
end_asm

begin_comment
comment|/* delayed return */
end_comment

begin_asm
asm|asm ("	st.l	%r28,12(%r16)");
end_asm

begin_comment
comment|/* pointer to overflow args */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __svr4__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__PARAGON__
argument_list|)
end_if

begin_comment
comment|/* 	 *	we'll use SVR4-ish varargs but need SVR3.2 assembler syntax, 	 *	and we stand a better chance of hooking into libraries 	 *	compiled by PGI.  [andyp@ssd.intel.com] 	 */
end_comment

begin_asm
asm|asm ("	.text");
end_asm

begin_asm
asm|asm ("	.align	4");
end_asm

begin_asm
asm|asm (".globl	__builtin_saveregs");
end_asm

begin_asm
asm|asm ("__builtin_saveregs:");
end_asm

begin_asm
asm|asm (".globl	___builtin_saveregs");
end_asm

begin_asm
asm|asm ("___builtin_saveregs:");
end_asm

begin_asm
asm|asm ("	andnot	0x0f,sp,sp");
end_asm

begin_comment
comment|/* round down to 16-byte boundary */
end_comment

begin_asm
asm|asm ("	adds	-96,sp,sp");
end_asm

begin_comment
comment|/* allocate stack space for reg save 					   area and also for a new va_list 					   structure */
end_comment

begin_comment
comment|/* Save all argument registers in the arg reg save area.  The 	   arg reg save area must have the following layout (according 	   to the svr4 ABI):  		struct { 		  union  { 		    float freg[8]; 		    double dreg[4]; 		  } float_regs; 		  long	ireg[12]; 		}; 	*/
end_comment

begin_asm
asm|asm ("	fst.q	f8,  0(sp)");
end_asm

begin_asm
asm|asm ("	fst.q	f12,16(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r16,32(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r17,36(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r18,40(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r19,44(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r20,48(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r21,52(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r22,56(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r23,60(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r24,64(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r25,68(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r26,72(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r27,76(sp)");
end_asm

begin_asm
asm|asm ("	adds	80,sp,r16");
end_asm

begin_comment
comment|/* compute the address of the new 					   va_list structure.  Put in into 					   r16 so that it will be returned 					   to the caller.  */
end_comment

begin_comment
comment|/* Initialize all fields of the new va_list structure.  This 	   structure looks like:  		typedef struct { 		    unsigned long	ireg_used; 		    unsigned long	freg_used; 		    long		*reg_base; 		    long		*mem_ptr; 		} va_list; 	*/
end_comment

begin_asm
asm|asm ("	st.l	r0, 0(r16)");
end_asm

begin_comment
comment|/* nfixed */
end_comment

begin_asm
asm|asm ("	st.l	r0, 4(r16)");
end_asm

begin_comment
comment|/* nfloating */
end_comment

begin_asm
asm|asm ("  st.l    sp, 8(r16)");
end_asm

begin_comment
comment|/* __va_ctl points to __va_struct.  */
end_comment

begin_asm
asm|asm ("	bri	r1");
end_asm

begin_comment
comment|/* delayed return */
end_comment

begin_asm
asm|asm ("	 st.l	r28,12(r16)");
end_asm

begin_comment
comment|/* pointer to overflow args */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __PARAGON__ */
end_comment

begin_asm
asm|asm ("	.text");
end_asm

begin_asm
asm|asm ("	.align	4");
end_asm

begin_asm
asm|asm (".globl	___builtin_saveregs");
end_asm

begin_asm
asm|asm ("___builtin_saveregs:");
end_asm

begin_asm
asm|asm ("	mov	sp,r30");
end_asm

begin_asm
asm|asm ("	andnot	0x0f,sp,sp");
end_asm

begin_asm
asm|asm ("	adds	-96,sp,sp");
end_asm

begin_comment
comment|/* allocate sufficient space on the stack */
end_comment

begin_comment
comment|/* Fill in the __va_struct.  */
end_comment

begin_asm
asm|asm ("	st.l	r16, 0(sp)");
end_asm

begin_comment
comment|/* save integer regs (r16-r27) */
end_comment

begin_asm
asm|asm ("	st.l	r17, 4(sp)");
end_asm

begin_comment
comment|/* int	fixed[12] */
end_comment

begin_asm
asm|asm ("	st.l	r18, 8(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r19,12(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r20,16(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r21,20(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r22,24(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r23,28(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r24,32(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r25,36(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r26,40(sp)");
end_asm

begin_asm
asm|asm ("	st.l	r27,44(sp)");
end_asm

begin_asm
asm|asm ("	fst.q	f8, 48(sp)");
end_asm

begin_comment
comment|/* save floating regs (f8-f15) */
end_comment

begin_asm
asm|asm ("	fst.q	f12,64(sp)");
end_asm

begin_comment
comment|/* int floating[8] */
end_comment

begin_comment
comment|/* Fill in the __va_ctl.  */
end_comment

begin_asm
asm|asm ("  st.l    sp, 80(sp)");
end_asm

begin_comment
comment|/* __va_ctl points to __va_struct.  */
end_comment

begin_asm
asm|asm ("	st.l	r28,84(sp)");
end_asm

begin_comment
comment|/* pointer to more args */
end_comment

begin_asm
asm|asm ("	st.l	r0, 88(sp)");
end_asm

begin_comment
comment|/* nfixed */
end_comment

begin_asm
asm|asm ("	st.l	r0, 92(sp)");
end_asm

begin_comment
comment|/* nfloating */
end_comment

begin_asm
asm|asm ("	adds	80,sp,r16");
end_asm

begin_comment
comment|/* return address of the __va_ctl.  */
end_comment

begin_asm
asm|asm ("	bri	r1");
end_asm

begin_asm
asm|asm ("	mov	r30,sp");
end_asm

begin_comment
comment|/* recover stack and pass address to start  				   of data.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __PARAGON__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __svr4__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __i860__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc__
end_ifdef

begin_asm
asm|asm (".global __builtin_saveregs");
end_asm

begin_asm
asm|asm ("__builtin_saveregs:");
end_asm

begin_asm
asm|asm (".global ___builtin_saveregs");
end_asm

begin_asm
asm|asm ("___builtin_saveregs:");
end_asm

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_PROC_COMMAND
end_ifdef

begin_asm
asm|asm (".proc 020");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_asm
asm|asm ("st %i0,[%fp+68]");
end_asm

begin_asm
asm|asm ("st %i1,[%fp+72]");
end_asm

begin_asm
asm|asm ("st %i2,[%fp+76]");
end_asm

begin_asm
asm|asm ("st %i3,[%fp+80]");
end_asm

begin_asm
asm|asm ("st %i4,[%fp+84]");
end_asm

begin_asm
asm|asm ("retl");
end_asm

begin_asm
asm|asm ("st %i5,[%fp+88]");
end_asm

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_TYPE_COMMAND
end_ifdef

begin_asm
asm|asm (".type __builtin_saveregs,#function");
end_asm

begin_asm
asm|asm (".size __builtin_saveregs,.-__builtin_saveregs");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __sparc__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MIPSEL__
argument_list|)
operator||
name|defined
argument_list|(
name|__R3000__
argument_list|)
operator||
name|defined
argument_list|(
name|__R2000__
argument_list|)
operator||
name|defined
argument_list|(
name|__mips__
argument_list|)
end_if

begin_asm
asm|asm ("	.text");
end_asm

begin_asm
asm|asm ("	.ent __builtin_saveregs");
end_asm

begin_asm
asm|asm ("	.globl __builtin_saveregs");
end_asm

begin_asm
asm|asm ("__builtin_saveregs:");
end_asm

begin_asm
asm|asm ("	sw	$4,0($30)");
end_asm

begin_asm
asm|asm ("	sw	$5,4($30)");
end_asm

begin_asm
asm|asm ("	sw	$6,8($30)");
end_asm

begin_asm
asm|asm ("	sw	$7,12($30)");
end_asm

begin_asm
asm|asm ("	j	$31");
end_asm

begin_asm
asm|asm ("	.end __builtin_saveregs");
end_asm

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __mips__, etc. */
end_comment

begin_function
name|void
modifier|*
name|__builtin_saveregs
parameter_list|()
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __mips__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __sparc__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __i860__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_eprintf
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|inhibit_libc
end_ifndef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_comment
comment|/* Avoid errors if stdio.h and our stddef.h mismatch.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* This is used by the `assert' macro.  */
end_comment

begin_function
name|void
name|__eprintf
parameter_list|(
name|string
parameter_list|,
name|expression
parameter_list|,
name|line
parameter_list|,
name|filename
parameter_list|)
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
specifier|const
name|char
modifier|*
name|expression
decl_stmt|;
name|int
name|line
decl_stmt|;
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|string
argument_list|,
name|expression
argument_list|,
name|line
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_bb
end_ifdef

begin_comment
comment|/* Structure emitted by -a  */
end_comment

begin_struct
struct|struct
name|bb
block|{
name|long
name|zero_word
decl_stmt|;
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
name|long
modifier|*
name|counts
decl_stmt|;
name|long
name|ncounts
decl_stmt|;
name|struct
name|bb
modifier|*
name|next
decl_stmt|;
specifier|const
name|unsigned
name|long
modifier|*
name|addresses
decl_stmt|;
comment|/* Older GCC's did not emit these fields.  */
name|long
name|nwords
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|functions
decl_stmt|;
specifier|const
name|long
modifier|*
name|line_nums
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|filenames
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|BLOCK_PROFILER_CODE
end_ifdef

begin_function_decl
name|BLOCK_PROFILER_CODE
else|#
directive|else
ifndef|#
directive|ifndef
name|inhibit_libc
comment|/* Simple minded basic block profiling output dumper for    systems that don't provide tcov support.  At present,    it requires atexit and stdio.  */
undef|#
directive|undef
name|NULL
comment|/* Avoid errors if stdio.h and our stddef.h mismatch.  */
include|#
directive|include
file|<stdio.h>
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ATEXIT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WINNT
end_ifdef

begin_function_decl
specifier|extern
name|int
name|atexit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|atexit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ON_EXIT
parameter_list|(
name|FUNC
parameter_list|,
name|ARG
parameter_list|)
value|atexit ((FUNC))
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_function_decl
specifier|extern
name|void
name|on_exit
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ON_EXIT
parameter_list|(
name|FUNC
parameter_list|,
name|ARG
parameter_list|)
value|on_exit ((FUNC), (ARG))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|struct
name|bb
modifier|*
name|bb_head
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the number of digits needed to print a value */
end_comment

begin_comment
comment|/* __inline__ */
end_comment

begin_function
specifier|static
name|int
name|num_digits
parameter_list|(
name|long
name|value
parameter_list|,
name|int
name|base
parameter_list|)
block|{
name|int
name|minus
init|=
operator|(
name|value
operator|<
literal|0
operator|&&
name|base
operator|!=
literal|16
operator|)
decl_stmt|;
name|unsigned
name|long
name|v
init|=
operator|(
name|minus
operator|)
condition|?
operator|-
name|value
else|:
name|value
decl_stmt|;
name|int
name|ret
init|=
name|minus
decl_stmt|;
do|do
block|{
name|v
operator|/=
name|base
expr_stmt|;
name|ret
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|v
condition|)
do|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|void
name|__bb_exit_func
parameter_list|(
name|void
parameter_list|)
block|{
name|FILE
modifier|*
name|file
init|=
name|fopen
argument_list|(
literal|"bb.out"
argument_list|,
literal|"a"
argument_list|)
decl_stmt|;
name|long
name|time_value
decl_stmt|;
if|if
condition|(
operator|!
name|file
condition|)
name|perror
argument_list|(
literal|"bb.out"
argument_list|)
expr_stmt|;
else|else
block|{
name|struct
name|bb
modifier|*
name|ptr
decl_stmt|;
comment|/* This is somewhat type incorrect, but it avoids worrying about 	 exactly where time.h is included from.  It should be ok unless 	 a void * differs from other pointer formats, or if sizeof(long) 	 is< sizeof (time_t).  It would be nice if we could assume the 	 use of rationale standards here.  */
name|time
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
name|time_value
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"Basic block profiling finished on %s\n"
argument_list|,
name|ctime
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
name|time_value
argument_list|)
argument_list|)
expr_stmt|;
comment|/* We check the length field explicitly in order to allow compatibility 	 with older GCC's which did not provide it.  */
for|for
control|(
name|ptr
operator|=
name|bb_head
init|;
name|ptr
operator|!=
operator|(
expr|struct
name|bb
operator|*
operator|)
literal|0
condition|;
name|ptr
operator|=
name|ptr
operator|->
name|next
control|)
block|{
name|int
name|i
decl_stmt|;
name|int
name|func_p
init|=
operator|(
name|ptr
operator|->
name|nwords
operator|>=
sizeof|sizeof
argument_list|(
expr|struct
name|bb
argument_list|)
operator|&&
name|ptr
operator|->
name|nwords
operator|<=
literal|1000
operator|)
decl_stmt|;
name|int
name|line_p
init|=
operator|(
name|func_p
operator|&&
name|ptr
operator|->
name|line_nums
operator|)
decl_stmt|;
name|int
name|file_p
init|=
operator|(
name|func_p
operator|&&
name|ptr
operator|->
name|filenames
operator|)
decl_stmt|;
name|long
name|ncounts
init|=
name|ptr
operator|->
name|ncounts
decl_stmt|;
name|long
name|cnt_max
init|=
literal|0
decl_stmt|;
name|long
name|line_max
init|=
literal|0
decl_stmt|;
name|long
name|addr_max
init|=
literal|0
decl_stmt|;
name|int
name|file_len
init|=
literal|0
decl_stmt|;
name|int
name|func_len
init|=
literal|0
decl_stmt|;
name|int
name|blk_len
init|=
name|num_digits
argument_list|(
name|ncounts
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|int
name|cnt_len
decl_stmt|;
name|int
name|line_len
decl_stmt|;
name|int
name|addr_len
decl_stmt|;
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"File %s, %ld basic blocks \n\n"
argument_list|,
name|ptr
operator|->
name|filename
argument_list|,
name|ncounts
argument_list|)
expr_stmt|;
comment|/* Get max values for each field.  */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ncounts
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|len
decl_stmt|;
if|if
condition|(
name|cnt_max
operator|<
name|ptr
operator|->
name|counts
index|[
name|i
index|]
condition|)
name|cnt_max
operator|=
name|ptr
operator|->
name|counts
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|addr_max
operator|<
name|ptr
operator|->
name|addresses
index|[
name|i
index|]
condition|)
name|addr_max
operator|=
name|ptr
operator|->
name|addresses
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|line_p
operator|&&
name|line_max
operator|<
name|ptr
operator|->
name|line_nums
index|[
name|i
index|]
condition|)
name|line_max
operator|=
name|ptr
operator|->
name|line_nums
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|func_p
condition|)
block|{
name|p
operator|=
operator|(
name|ptr
operator|->
name|functions
index|[
name|i
index|]
operator|)
condition|?
operator|(
name|ptr
operator|->
name|functions
index|[
name|i
index|]
operator|)
else|:
literal|"<none>"
expr_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|func_len
operator|<
name|len
condition|)
name|func_len
operator|=
name|len
expr_stmt|;
block|}
if|if
condition|(
name|file_p
condition|)
block|{
name|p
operator|=
operator|(
name|ptr
operator|->
name|filenames
index|[
name|i
index|]
operator|)
condition|?
operator|(
name|ptr
operator|->
name|filenames
index|[
name|i
index|]
operator|)
else|:
literal|"<none>"
expr_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|file_len
operator|<
name|len
condition|)
name|file_len
operator|=
name|len
expr_stmt|;
block|}
block|}
name|addr_len
operator|=
name|num_digits
argument_list|(
name|addr_max
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|cnt_len
operator|=
name|num_digits
argument_list|(
name|cnt_max
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|line_len
operator|=
name|num_digits
argument_list|(
name|line_max
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|/* Now print out the basic block information.  */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ncounts
condition|;
name|i
operator|++
control|)
block|{
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"    Block #%*d: executed %*ld time(s) address= 0x%.*lx"
argument_list|,
name|blk_len
argument_list|,
name|i
operator|+
literal|1
argument_list|,
name|cnt_len
argument_list|,
name|ptr
operator|->
name|counts
index|[
name|i
index|]
argument_list|,
name|addr_len
argument_list|,
name|ptr
operator|->
name|addresses
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|func_p
condition|)
name|fprintf
argument_list|(
name|file
argument_list|,
literal|" function= %-*s"
argument_list|,
name|func_len
argument_list|,
operator|(
name|ptr
operator|->
name|functions
index|[
name|i
index|]
operator|)
condition|?
name|ptr
operator|->
name|functions
index|[
name|i
index|]
else|:
literal|"<none>"
argument_list|)
expr_stmt|;
if|if
condition|(
name|line_p
condition|)
name|fprintf
argument_list|(
name|file
argument_list|,
literal|" line= %*ld"
argument_list|,
name|line_len
argument_list|,
name|ptr
operator|->
name|line_nums
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|file_p
condition|)
name|fprintf
argument_list|(
name|file
argument_list|,
literal|" file= %s"
argument_list|,
operator|(
name|ptr
operator|->
name|filenames
index|[
name|i
index|]
operator|)
condition|?
name|ptr
operator|->
name|filenames
index|[
name|i
index|]
else|:
literal|"<none>"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"\n\n"
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|__bb_init_func
parameter_list|(
name|struct
name|bb
modifier|*
name|blocks
parameter_list|)
block|{
comment|/* User is supposed to check whether the first word is non-0,      but just in case.... */
if|if
condition|(
name|blocks
operator|->
name|zero_word
condition|)
return|return;
ifdef|#
directive|ifdef
name|ON_EXIT
comment|/* Initialize destructor.  */
if|if
condition|(
operator|!
name|bb_head
condition|)
name|ON_EXIT
argument_list|(
name|__bb_exit_func
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Set up linked list.  */
name|blocks
operator|->
name|zero_word
operator|=
literal|1
expr_stmt|;
name|blocks
operator|->
name|next
operator|=
name|bb_head
expr_stmt|;
name|bb_head
operator|=
name|blocks
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not inhibit_libc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BLOCK_PROFILER_CODE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L_bb */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Default free-store management functions for C++, per sections 12.5 and    17.3.3 of the Working Paper. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|L_op_new
end_ifdef

begin_comment
comment|/* operator new (size_t), described in 17.3.3.5.  This function is used by    C++ programs to allocate a block of memory to hold a single object. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vfp
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|vfp
name|__new_handler
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|__default_new_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WEAK_ALIAS
end_ifdef

begin_function_decl
name|void
modifier|*
name|__builtin_new
parameter_list|(
name|size_t
name|sz
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"___builtin_new"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
modifier|*
name|___builtin_new
argument_list|(
name|size_t
name|sz
argument_list|)
else|#
directive|else
name|void
modifier|*
name|__builtin_new
argument_list|(
name|size_t
name|sz
argument_list|)
endif|#
directive|endif
block|{
name|void
modifier|*
name|p
decl_stmt|;
name|vfp
name|handler
init|=
operator|(
name|__new_handler
operator|)
condition|?
name|__new_handler
else|:
name|__default_new_handler
decl_stmt|;
comment|/* malloc (0) is unpredictable; avoid it.  */
if|if
condition|(
name|sz
operator|==
literal|0
condition|)
name|sz
operator|=
literal|1
expr_stmt|;
name|p
operator|=
operator|(
name|void
operator|*
operator|)
name|malloc
argument_list|(
name|sz
argument_list|)
expr_stmt|;
while|while
condition|(
name|p
operator|==
literal|0
condition|)
block|{
call|(
modifier|*
name|handler
call|)
argument_list|()
expr_stmt|;
name|p
operator|=
operator|(
name|void
operator|*
operator|)
name|malloc
argument_list|(
name|sz
argument_list|)
expr_stmt|;
block|}
return|return
name|p
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L_op_new */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|L_op_vnew
end_ifdef

begin_comment
comment|/* void * operator new [] (size_t), described in 17.3.3.6.  This function    is used by C++ programs to allocate a block of memory for an array.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|__builtin_new
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WEAK_ALIAS
end_ifdef

begin_function_decl
name|void
modifier|*
name|__builtin_vec_new
parameter_list|(
name|size_t
name|sz
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"___builtin_vec_new"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
modifier|*
name|___builtin_vec_new
argument_list|(
name|size_t
name|sz
argument_list|)
else|#
directive|else
name|void
modifier|*
name|__builtin_vec_new
argument_list|(
name|size_t
name|sz
argument_list|)
endif|#
directive|endif
block|{
return|return
name|__builtin_new
argument_list|(
name|sz
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L_op_vnew */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|L_new_handler
end_ifdef

begin_comment
comment|/* set_new_handler (fvoid_t *) and the default new handler, described in    17.3.3.2 and 17.3.3.5.  These functions define the result of a failure    to allocate the amount of memory requested from operator new or new []. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|inhibit_libc
end_ifndef

begin_comment
comment|/* This gets us __GNU_LIBRARY__.  */
end_comment

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_comment
comment|/* Avoid errors if stdio.h and our stddef.h mismatch.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNU_LIBRARY__
end_ifdef

begin_comment
comment|/* Avoid forcing the library's meaning of `write' on the user program      by using the "internal" name (for use within the library)  */
end_comment

begin_define
define|#
directive|define
name|write
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
value|__write((fd), (buf), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* inhibit_libc */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vfp
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|__default_new_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|vfp
name|__new_handler
init|=
operator|(
name|vfp
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|vfp
name|set_new_handler
parameter_list|(
name|vfp
name|handler
parameter_list|)
block|{
name|vfp
name|prev_handler
decl_stmt|;
name|prev_handler
operator|=
name|__new_handler
expr_stmt|;
if|if
condition|(
name|handler
operator|==
literal|0
condition|)
name|handler
operator|=
name|__default_new_handler
expr_stmt|;
name|__new_handler
operator|=
name|handler
expr_stmt|;
return|return
name|prev_handler
return|;
block|}
end_function

begin_define
define|#
directive|define
name|MESSAGE
value|"Virtual memory exceeded in `new'\n"
end_define

begin_function
name|void
name|__default_new_handler
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|inhibit_libc
comment|/* don't use fprintf (stderr, ...) because it may need to call malloc.  */
comment|/* This should really print the name of the program, but that is hard to      do.  We need a standard, clean way to get at the name.  */
name|write
argument_list|(
literal|2
argument_list|,
name|MESSAGE
argument_list|,
sizeof|sizeof
argument_list|(
name|MESSAGE
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* don't call exit () because that may call global destructors which      may cause a loop.  */
name|_exit
argument_list|(
operator|-
literal|1
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
name|L_op_delete
end_ifdef

begin_comment
comment|/* operator delete (void *), described in 17.3.3.3.  This function is used    by C++ programs to return to the free store a block of memory allocated    as a single object. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WEAK_ALIAS
end_ifdef

begin_function_decl
name|void
name|__builtin_delete
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"___builtin_delete"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|___builtin_delete
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
else|#
directive|else
name|void
name|__builtin_delete
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
endif|#
directive|endif
block|{
if|if
condition|(
name|ptr
condition|)
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|L_op_vdel
end_ifdef

begin_comment
comment|/* operator delete [] (void *), described in 17.3.3.4.  This function is    used by C++ programs to return to the free store a block of memory    allocated as an array. */
end_comment

begin_function_decl
specifier|extern
name|void
name|__builtin_delete
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WEAK_ALIAS
end_ifdef

begin_function_decl
name|void
name|__builtin_vec_delete
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
operator|,
function_decl|alias
parameter_list|(
function_decl|"___builtin_vec_delete"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|___builtin_vec_delete
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
else|#
directive|else
name|void
name|__builtin_vec_delete
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
endif|#
directive|endif
block|{
name|__builtin_delete
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End of C++ free-store management functions */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_shtab
end_ifdef

begin_decl_stmt
name|unsigned
name|int
name|__shtab
index|[]
init|=
block|{
literal|0x00000001
block|,
literal|0x00000002
block|,
literal|0x00000004
block|,
literal|0x00000008
block|,
literal|0x00000010
block|,
literal|0x00000020
block|,
literal|0x00000040
block|,
literal|0x00000080
block|,
literal|0x00000100
block|,
literal|0x00000200
block|,
literal|0x00000400
block|,
literal|0x00000800
block|,
literal|0x00001000
block|,
literal|0x00002000
block|,
literal|0x00004000
block|,
literal|0x00008000
block|,
literal|0x00010000
block|,
literal|0x00020000
block|,
literal|0x00040000
block|,
literal|0x00080000
block|,
literal|0x00100000
block|,
literal|0x00200000
block|,
literal|0x00400000
block|,
literal|0x00800000
block|,
literal|0x01000000
block|,
literal|0x02000000
block|,
literal|0x04000000
block|,
literal|0x08000000
block|,
literal|0x10000000
block|,
literal|0x20000000
block|,
literal|0x40000000
block|,
literal|0x80000000
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_clear_cache
end_ifdef

begin_comment
comment|/* Clear part of an instruction cache.  */
end_comment

begin_define
define|#
directive|define
name|INSN_CACHE_PLANE_SIZE
value|(INSN_CACHE_SIZE / INSN_CACHE_DEPTH)
end_define

begin_function
name|void
name|__clear_cache
parameter_list|(
name|beg
parameter_list|,
name|end
parameter_list|)
name|char
modifier|*
name|beg
decl_stmt|,
decl|*
name|end
decl_stmt|;
end_function

begin_block
block|{
ifdef|#
directive|ifdef
name|CLEAR_INSN_CACHE
name|CLEAR_INSN_CACHE
argument_list|(
name|beg
argument_list|,
name|end
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|INSN_CACHE_SIZE
specifier|static
name|char
name|array
index|[
name|INSN_CACHE_SIZE
operator|+
name|INSN_CACHE_PLANE_SIZE
operator|+
name|INSN_CACHE_LINE_WIDTH
index|]
decl_stmt|;
specifier|static
name|int
name|initialized
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|void
modifier|*
name|start_addr
name|void
modifier|*
name|end_addr
decl_stmt|;
typedef|typedef
call|(
modifier|*
name|function_ptr
call|)
argument_list|()
expr_stmt|;
if|#
directive|if
operator|(
name|INSN_CACHE_SIZE
operator|/
name|INSN_CACHE_LINE_WIDTH
operator|)
operator|<
literal|16
comment|/* It's cheaper to clear the whole cache.      Put in a series of jump instructions so that calling the beginning      of the cache will clear the whole thing.  */
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|int
name|ptr
init|=
operator|(
operator|(
operator|(
name|int
operator|)
name|array
operator|+
name|INSN_CACHE_LINE_WIDTH
operator|-
literal|1
operator|)
operator|&
operator|-
name|INSN_CACHE_LINE_WIDTH
operator|)
decl_stmt|;
name|int
name|end_ptr
init|=
name|ptr
operator|+
name|INSN_CACHE_SIZE
decl_stmt|;
while|while
condition|(
name|ptr
operator|<
name|end_ptr
condition|)
block|{
operator|*
operator|(
name|INSTRUCTION_TYPE
operator|*
operator|)
name|ptr
operator|=
name|JUMP_AHEAD_INSTRUCTION
operator|+
name|INSN_CACHE_LINE_WIDTH
expr_stmt|;
name|ptr
operator|+=
name|INSN_CACHE_LINE_WIDTH
expr_stmt|;
block|}
operator|*
operator|(
name|INSTRUCTION_TYPE
operator|*
operator|)
operator|(
name|ptr
operator|-
name|INSN_CACHE_LINE_WIDTH
operator|)
operator|=
name|RETURN_INSTRUCTION
expr_stmt|;
name|initialized
operator|=
literal|1
expr_stmt|;
block|}
comment|/* Call the beginning of the sequence.  */
operator|(
operator|(
call|(
name|function_ptr
call|)
argument_list|(
operator|(
operator|(
name|int
operator|)
name|array
operator|+
name|INSN_CACHE_LINE_WIDTH
operator|-
literal|1
operator|)
operator|&
operator|-
name|INSN_CACHE_LINE_WIDTH
argument_list|)
operator|)
operator|(
operator|)
operator|)
expr_stmt|;
else|#
directive|else
comment|/* Cache is large.  */
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|int
name|ptr
init|=
operator|(
operator|(
operator|(
name|int
operator|)
name|array
operator|+
name|INSN_CACHE_LINE_WIDTH
operator|-
literal|1
operator|)
operator|&
operator|-
name|INSN_CACHE_LINE_WIDTH
operator|)
decl_stmt|;
while|while
condition|(
name|ptr
operator|<
operator|(
name|int
operator|)
name|array
operator|+
sizeof|sizeof
name|array
condition|)
block|{
operator|*
operator|(
name|INSTRUCTION_TYPE
operator|*
operator|)
name|ptr
operator|=
name|RETURN_INSTRUCTION
expr_stmt|;
name|ptr
operator|+=
name|INSN_CACHE_LINE_WIDTH
expr_stmt|;
block|}
name|initialized
operator|=
literal|1
expr_stmt|;
block|}
comment|/* Find the location in array that occupies the same cache line as BEG.  */
name|offset
operator|=
operator|(
operator|(
name|int
operator|)
name|beg
operator|&
operator|-
name|INSN_CACHE_LINE_WIDTH
operator|)
operator|&
operator|(
name|INSN_CACHE_PLANE_SIZE
operator|-
literal|1
operator|)
expr_stmt|;
name|start_addr
operator|=
operator|(
operator|(
call|(
name|int
call|)
argument_list|(
name|array
operator|+
name|INSN_CACHE_PLANE_SIZE
operator|-
literal|1
argument_list|)
operator|&
operator|-
name|INSN_CACHE_PLANE_SIZE
operator|)
operator|+
name|offset
operator|)
expr_stmt|;
comment|/* Compute the cache alignment of the place to stop clearing.  */
if|#
directive|if
literal|0
comment|/* This is not needed for gcc's purposes.  */
comment|/* If the block to clear is bigger than a cache plane,      we clear the entire cache, and OFFSET is already correct.  */
block|if (end< beg + INSN_CACHE_PLANE_SIZE)
endif|#
directive|endif
name|offset
operator|=
operator|(
operator|(
call|(
name|int
call|)
argument_list|(
name|end
operator|+
name|INSN_CACHE_LINE_WIDTH
operator|-
literal|1
argument_list|)
operator|&
operator|-
name|INSN_CACHE_LINE_WIDTH
operator|)
operator|&
operator|(
name|INSN_CACHE_PLANE_SIZE
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
if|#
directive|if
name|INSN_CACHE_DEPTH
operator|>
literal|1
name|end_addr
operator|=
operator|(
name|start_addr
operator|&
operator|-
name|INSN_CACHE_PLANE_SIZE
operator|)
operator|+
name|offset
expr_stmt|;
if|if
condition|(
name|end_addr
operator|<=
name|start_addr
condition|)
name|end_addr
operator|+=
name|INSN_CACHE_PLANE_SIZE
expr_stmt|;
for|for
control|(
name|plane
operator|=
literal|0
init|;
name|plane
operator|<
name|INSN_CACHE_DEPTH
condition|;
name|plane
operator|++
control|)
block|{
name|int
name|addr
init|=
name|start_addr
operator|+
name|plane
operator|*
name|INSN_CACHE_PLANE_SIZE
decl_stmt|;
name|int
name|stop
init|=
name|end_addr
operator|+
name|plane
operator|*
name|INSN_CACHE_PLANE_SIZE
decl_stmt|;
while|while
condition|(
name|addr
operator|!=
name|stop
condition|)
block|{
comment|/* Call the return instruction at ADDR.  */
operator|(
operator|(
name|function_ptr
operator|)
name|addr
operator|)
operator|(
operator|)
expr_stmt|;
name|addr
operator|+=
name|INSN_CACHE_LINE_WIDTH
expr_stmt|;
block|}
block|}
else|#
directive|else
comment|/* just one plane */
do|do
block|{
comment|/* Call the return instruction at START_ADDR.  */
operator|(
operator|(
name|function_ptr
operator|)
name|start_addr
operator|)
operator|(
operator|)
expr_stmt|;
name|start_addr
operator|+=
name|INSN_CACHE_LINE_WIDTH
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|start_addr
operator|%
name|INSN_CACHE_SIZE
operator|)
operator|!=
name|offset
condition|)
do|;
endif|#
directive|endif
comment|/* just one plane */
endif|#
directive|endif
comment|/* Cache is large */
endif|#
directive|endif
comment|/* Cache exists */
endif|#
directive|endif
comment|/* CLEAR_INSN_CACHE */
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L_clear_cache */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_trampoline
end_ifdef

begin_comment
comment|/* Jump to a trampoline, loading the static chain address.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WINNT
end_ifdef

begin_function
name|long
name|getpagesize
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|_ALPHA_
return|return
literal|8192
return|;
else|#
directive|else
return|return
literal|4096
return|;
endif|#
directive|endif
block|}
end_function

begin_function
name|int
name|mprotect
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|prot
parameter_list|)
name|char
modifier|*
name|addr
decl_stmt|;
name|int
name|len
decl_stmt|,
name|prot
decl_stmt|;
block|{
name|int
name|np
decl_stmt|,
name|op
decl_stmt|;
if|if
condition|(
name|prot
operator|==
literal|7
condition|)
name|np
operator|=
literal|0x40
expr_stmt|;
elseif|else
if|if
condition|(
name|prot
operator|==
literal|5
condition|)
name|np
operator|=
literal|0x20
expr_stmt|;
elseif|else
if|if
condition|(
name|prot
operator|==
literal|4
condition|)
name|np
operator|=
literal|0x10
expr_stmt|;
elseif|else
if|if
condition|(
name|prot
operator|==
literal|3
condition|)
name|np
operator|=
literal|0x04
expr_stmt|;
elseif|else
if|if
condition|(
name|prot
operator|==
literal|1
condition|)
name|np
operator|=
literal|0x02
expr_stmt|;
elseif|else
if|if
condition|(
name|prot
operator|==
literal|0
condition|)
name|np
operator|=
literal|0x01
expr_stmt|;
if|if
condition|(
name|VirtualProtect
argument_list|(
name|addr
argument_list|,
name|len
argument_list|,
name|np
argument_list|,
operator|&
name|op
argument_list|)
condition|)
return|return
literal|0
return|;
else|else
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRANSFER_FROM_TRAMPOLINE
end_ifdef

begin_function
name|TRANSFER_FROM_TRAMPOLINE
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|&&
name|defined
argument_list|(
name|__MACH__
argument_list|)
comment|/* Make stack executable so we can call trampolines on stack.    This is called from INITIALIZE_TRAMPOLINE in next.h.  */
ifdef|#
directive|ifdef
name|NeXTStep21
include|#
directive|include
file|<mach.h>
else|#
directive|else
include|#
directive|include
file|<mach/mach.h>
endif|#
directive|endif
name|void
name|__enable_execute_stack
parameter_list|(
name|addr
parameter_list|)
name|char
modifier|*
name|addr
decl_stmt|;
block|{
name|kern_return_t
name|r
decl_stmt|;
name|char
modifier|*
name|eaddr
init|=
name|addr
operator|+
name|TRAMPOLINE_SIZE
decl_stmt|;
name|vm_address_t
name|a
init|=
operator|(
name|vm_address_t
operator|)
name|addr
decl_stmt|;
comment|/* turn on execute access on stack */
name|r
operator|=
name|vm_protect
argument_list|(
name|task_self
argument_list|()
argument_list|,
name|a
argument_list|,
name|TRAMPOLINE_SIZE
argument_list|,
name|FALSE
argument_list|,
name|VM_PROT_ALL
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|!=
name|KERN_SUCCESS
condition|)
block|{
name|mach_error
argument_list|(
literal|"vm_protect VM_PROT_ALL"
argument_list|,
name|r
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* We inline the i-cache invalidation for speed */
ifdef|#
directive|ifdef
name|CLEAR_INSN_CACHE
name|CLEAR_INSN_CACHE
argument_list|(
name|addr
argument_list|,
name|eaddr
argument_list|)
expr_stmt|;
else|#
directive|else
name|__clear_cache
argument_list|(
operator|(
name|int
operator|)
name|addr
argument_list|,
operator|(
name|int
operator|)
name|eaddr
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (NeXT)&& defined (__MACH__) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__convex__
end_ifdef

begin_comment
comment|/* Make stack executable so we can call trampolines on stack.    This is called from INITIALIZE_TRAMPOLINE in convex.h.  */
end_comment

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/machparam.h>
end_include

begin_function
name|void
name|__enable_execute_stack
parameter_list|()
block|{
name|int
name|fp
decl_stmt|;
specifier|static
name|unsigned
name|lowest
init|=
name|USRSTACK
decl_stmt|;
name|unsigned
name|current
init|=
operator|(
name|unsigned
operator|)
operator|&
name|fp
operator|&
operator|-
name|NBPG
decl_stmt|;
if|if
condition|(
name|lowest
operator|>
name|current
condition|)
block|{
name|unsigned
name|len
init|=
name|lowest
operator|-
name|current
decl_stmt|;
name|mremap
argument_list|(
name|current
argument_list|,
operator|&
name|len
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
operator||
name|PROT_EXEC
argument_list|,
name|MAP_PRIVATE
argument_list|)
expr_stmt|;
name|lowest
operator|=
name|current
expr_stmt|;
block|}
comment|/* Clear instruction cache in case an old trampoline is in it. */
asm|asm ("pich");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __convex__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__DOLPHIN__
end_ifdef

begin_comment
comment|/* Modified from the convex -code above. */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/m88kbcs.h>
end_include

begin_function
name|void
name|__enable_execute_stack
parameter_list|()
block|{
name|int
name|save_errno
decl_stmt|;
specifier|static
name|unsigned
name|long
name|lowest
init|=
name|USRSTACK
decl_stmt|;
name|unsigned
name|long
name|current
init|=
operator|(
name|unsigned
name|long
operator|)
operator|&
name|save_errno
operator|&
operator|-
name|NBPC
decl_stmt|;
comment|/* Ignore errno being set. memctl sets errno to EINVAL whenever the      address is seen as 'negative'. That is the case with the stack.   */
name|save_errno
operator|=
name|errno
expr_stmt|;
if|if
condition|(
name|lowest
operator|>
name|current
condition|)
block|{
name|unsigned
name|len
init|=
name|lowest
operator|-
name|current
decl_stmt|;
name|memctl
argument_list|(
name|current
argument_list|,
name|len
argument_list|,
name|MCT_TEXT
argument_list|)
expr_stmt|;
name|lowest
operator|=
name|current
expr_stmt|;
block|}
else|else
name|memctl
argument_list|(
name|current
argument_list|,
name|NBPC
argument_list|,
name|MCT_TEXT
argument_list|)
expr_stmt|;
name|errno
operator|=
name|save_errno
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DOLPHIN__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__pyr__
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_comment
comment|/* Avoid errors if stdio.h and our stddef.h mismatch.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmac.h>
end_include

begin_comment
comment|/* Modified from the convex -code above.    mremap promises to clear the i-cache. */
end_comment

begin_function
name|void
name|__enable_execute_stack
parameter_list|()
block|{
name|int
name|fp
decl_stmt|;
if|if
condition|(
name|mprotect
argument_list|(
operator|(
operator|(
name|unsigned
name|int
operator|)
operator|&
name|fp
operator|/
name|PAGSIZ
operator|)
operator|*
name|PAGSIZ
argument_list|,
name|PAGSIZ
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
operator||
name|PROT_EXEC
argument_list|)
condition|)
block|{
name|perror
argument_list|(
literal|"mprotect in __enable_execute_stack"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __pyr__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L_trampoline */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L__main
end_ifdef

begin_include
include|#
directive|include
file|"gbl-ctors.h"
end_include

begin_comment
comment|/* Some systems use __main in a way incompatible with its use in gcc, in these    cases use the macros NAME__MAIN to give a quoted symbol and SYMBOL__MAIN to    give the same symbol without quotes for an alternative entry point.  You    must define both, or neither. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAME__MAIN
end_ifndef

begin_define
define|#
directive|define
name|NAME__MAIN
value|"__main"
end_define

begin_define
define|#
directive|define
name|SYMBOL__MAIN
value|__main
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INIT_SECTION_ASM_OP
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|OBJECT_FORMAT_ELF
argument_list|)
end_if

begin_comment
comment|/* Run all the global destructors on exit from the program.  */
end_comment

begin_function
name|void
name|__do_global_dtors
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|DO_GLOBAL_DTORS_BODY
name|DO_GLOBAL_DTORS_BODY
expr_stmt|;
else|#
directive|else
name|func_ptr
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
name|__DTOR_LIST__
operator|+
literal|1
init|;
operator|*
name|p
condition|;
control|)
operator|(
operator|*
name|p
operator|++
operator|)
operator|(
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* Run all the global constructors on entry to the program.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ON_EXIT
end_ifndef

begin_define
define|#
directive|define
name|ON_EXIT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Make sure the exit routine is pulled in to define the globals as    bss symbols, just in case the linker does not automatically pull    bss definitions from the library.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_exit_dummy_decl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|_exit_dummy_ref
init|=
operator|&
name|_exit_dummy_decl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ON_EXIT */
end_comment

begin_function
name|void
name|__do_global_ctors
parameter_list|()
block|{
name|DO_GLOBAL_CTORS_BODY
expr_stmt|;
name|ON_EXIT
argument_list|(
name|__do_global_dtors
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Subroutine called automatically by `main'.    Compiling a global function named `main'    produces an automatic call to this function at the beginning.     For many systems, this routine calls __do_global_ctors.    For systems which support a .init section we use the .init section    to run __do_global_ctors, so we need not do anything here.  */
end_comment

begin_function
name|void
name|SYMBOL__MAIN
parameter_list|()
block|{
comment|/* Support recursive calls to `main': run initializers just once.  */
specifier|static
name|int
name|initialized
decl_stmt|;
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|initialized
operator|=
literal|1
expr_stmt|;
name|__do_global_ctors
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no INIT_SECTION_ASM_OP or INVOKE__main */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L__main */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_ctors
end_ifdef

begin_include
include|#
directive|include
file|"gbl-ctors.h"
end_include

begin_comment
comment|/* Provide default definitions for the lists of constructors and    destructors, so that we don't get linker errors.  These symbols are    intentionally bss symbols, so that gld and/or collect will provide    the right values.  */
end_comment

begin_comment
comment|/* We declare the lists here with two elements each,    so that they are valid empty lists if no other definition is loaded.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|INIT_SECTION_ASM_OP
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|OBJECT_FORMAT_ELF
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|CTOR_LISTS_DEFINED_EXTERNALLY
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NeXT__
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
end_if

begin_comment
comment|/* After 2.3, try this definition on all systems.  */
end_comment

begin_decl_stmt
name|func_ptr
name|__CTOR_LIST__
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|func_ptr
name|__DTOR_LIST__
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|func_ptr
name|__CTOR_LIST__
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|func_ptr
name|__DTOR_LIST__
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no INIT_SECTION_ASM_OP and not CTOR_LISTS_DEFINED_EXTERNALLY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L_ctors */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_exit
end_ifdef

begin_include
include|#
directive|include
file|"gbl-ctors.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ON_EXIT
end_ifndef

begin_comment
comment|/* If we have no known way of registering our own __do_global_dtors    routine so that it will be invoked at program exit time, then we    have to define our own exit routine which will get this to happen.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__do_global_dtors
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_exit
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|exit
parameter_list|(
name|status
parameter_list|)
name|int
name|status
decl_stmt|;
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INIT_SECTION_ASM_OP
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|OBJECT_FORMAT_ELF
argument_list|)
name|__do_global_dtors
argument_list|()
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EXIT_BODY
name|EXIT_BODY
expr_stmt|;
else|#
directive|else
name|_cleanup
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|_exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|_exit_dummy_decl
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prevent compiler& linker warnings */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L_exit */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_eh
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|start
decl_stmt|;
name|void
modifier|*
name|end
decl_stmt|;
name|void
modifier|*
name|exception_handler
decl_stmt|;
block|}
name|exception_table
typedef|;
end_typedef

begin_struct
struct|struct
name|exception_table_node
block|{
name|exception_table
modifier|*
name|table
decl_stmt|;
name|void
modifier|*
name|start
decl_stmt|;
name|void
modifier|*
name|end
decl_stmt|;
name|struct
name|exception_table_node
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|int
name|except_table_pos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
modifier|*
name|except_pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|exception_table_node
modifier|*
name|exception_table_list
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|exception_table
modifier|*
name|find_exception_table
parameter_list|(
name|pc
parameter_list|)
name|void
modifier|*
name|pc
decl_stmt|;
block|{
specifier|register
name|struct
name|exception_table_node
modifier|*
name|table
init|=
name|exception_table_list
decl_stmt|;
for|for
control|(
init|;
name|table
operator|!=
literal|0
condition|;
name|table
operator|=
name|table
operator|->
name|next
control|)
block|{
if|if
condition|(
name|table
operator|->
name|start
operator|<=
name|pc
operator|&&
name|table
operator|->
name|end
operator|>
name|pc
condition|)
return|return
name|table
operator|->
name|table
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* this routine takes a pc, and the address of the exception handler associated    with the closest exception table handler entry associated with that PC,    or 0 if there are no table entries the PC fits in.  The algorithm works    something like this:      while(current_entry exists) {         if(current_entry.start< pc )             current_entry = next_entry;         else {             if(prev_entry.start<= pc&& prev_entry.end> pc) {                 save pointer to prev_entry;                 return prev_entry.exception_handler;              }             else return 0;          }      }     return 0;     Assuming a correctly sorted table (ascending order) this routine should    return the tightest match...     In the advent of a tie, we have to give the last entry, as it represents    an inner block.  */
end_comment

begin_function
name|void
modifier|*
name|__find_first_exception_table_match
parameter_list|(
name|pc
parameter_list|)
name|void
modifier|*
name|pc
decl_stmt|;
block|{
name|exception_table
modifier|*
name|table
init|=
name|find_exception_table
argument_list|(
name|pc
argument_list|)
decl_stmt|;
name|int
name|pos
init|=
literal|0
decl_stmt|;
name|int
name|best
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|table
operator|==
literal|0
condition|)
return|return
operator|(
name|void
operator|*
operator|)
literal|0
return|;
if|#
directive|if
literal|0
block|printf("find_first_exception_table_match(): pc = %x!\n",pc);
endif|#
directive|endif
name|except_pc
operator|=
name|pc
expr_stmt|;
if|#
directive|if
literal|0
comment|/* We can't do this yet, as we don't know that the table is sorted.  */
block|do {     ++pos;     if (table[pos].start> except_pc)
comment|/* found the first table[pos].start> except_pc, so the previous 	 entry better be the one we want! */
block|break;   } while(table[pos].exception_handler != (void*)-1);    --pos;   if (table[pos].start<= except_pc&& table[pos].end> except_pc)     {       except_table_pos = pos;
if|#
directive|if
literal|0
block|printf("find_first_eh_table_match(): found match: %x\n",table[pos].exception_handler);
endif|#
directive|endif
block|return table[pos].exception_handler;     }
else|#
directive|else
while|while
condition|(
name|table
index|[
operator|++
name|pos
index|]
operator|.
name|exception_handler
operator|!=
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|table
index|[
name|pos
index|]
operator|.
name|start
operator|<=
name|except_pc
operator|&&
name|table
index|[
name|pos
index|]
operator|.
name|end
operator|>
name|except_pc
condition|)
block|{
comment|/* This can apply.  Make sure it is better or as good as the previous 	   best.  */
comment|/* The best one ends first. */
if|if
condition|(
name|best
operator|==
literal|0
operator|||
operator|(
name|table
index|[
name|pos
index|]
operator|.
name|end
operator|<=
name|table
index|[
name|best
index|]
operator|.
name|end
comment|/* The best one starts last.  */
operator|&&
name|table
index|[
name|pos
index|]
operator|.
name|start
operator|>=
name|table
index|[
name|best
index|]
operator|.
name|start
operator|)
condition|)
name|best
operator|=
name|pos
expr_stmt|;
block|}
block|}
if|if
condition|(
name|best
operator|!=
literal|0
condition|)
return|return
name|table
index|[
name|best
index|]
operator|.
name|exception_handler
return|;
endif|#
directive|endif
if|#
directive|if
literal|0
block|printf("find_first_eh_table_match(): else: returning NULL!\n");
endif|#
directive|endif
return|return
operator|(
name|void
operator|*
operator|)
literal|0
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|__throw_type_match
parameter_list|(
name|void
modifier|*
name|catch_type
parameter_list|,
name|void
modifier|*
name|throw_type
parameter_list|,
name|void
modifier|*
name|obj
parameter_list|)
block|{
if|#
directive|if
literal|0
block|printf("__throw_type_match (): catch_type = %s, throw_type = %s\n", 	catch_type, throw_type);
endif|#
directive|endif
if|if
condition|(
name|strcmp
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|catch_type
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|throw_type
argument_list|)
operator|==
literal|0
condition|)
return|return
name|obj
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|__register_exceptions
parameter_list|(
name|exception_table
modifier|*
name|table
parameter_list|)
block|{
name|struct
name|exception_table_node
modifier|*
name|node
decl_stmt|;
name|exception_table
modifier|*
name|range
init|=
name|table
operator|+
literal|1
decl_stmt|;
if|if
condition|(
name|range
operator|->
name|start
operator|==
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
condition|)
return|return;
name|node
operator|=
operator|(
expr|struct
name|exception_table_node
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|exception_table_node
argument_list|)
argument_list|)
expr_stmt|;
name|node
operator|->
name|table
operator|=
name|table
expr_stmt|;
comment|/* This look can be optimized away either if the table      is sorted, or if we pass in extra parameters. */
name|node
operator|->
name|start
operator|=
name|range
operator|->
name|start
expr_stmt|;
name|node
operator|->
name|end
operator|=
name|range
operator|->
name|end
expr_stmt|;
for|for
control|(
name|range
operator|++
init|;
name|range
operator|->
name|start
operator|!=
operator|(
name|void
operator|*
operator|)
operator|(
operator|-
literal|1
operator|)
condition|;
name|range
operator|++
control|)
block|{
if|if
condition|(
name|range
operator|->
name|start
operator|<
name|node
operator|->
name|start
condition|)
name|node
operator|->
name|start
operator|=
name|range
operator|->
name|start
expr_stmt|;
if|if
condition|(
name|range
operator|->
name|end
operator|>
name|node
operator|->
name|end
condition|)
name|node
operator|->
name|end
operator|=
name|range
operator|->
name|end
expr_stmt|;
block|}
name|node
operator|->
name|next
operator|=
name|exception_table_list
expr_stmt|;
name|exception_table_list
operator|=
name|node
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
operator|#
name|machine
argument_list|(
name|i386
argument_list|)
end_if

begin_function
name|void
name|__unwind_function
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
asm|asm("movl 8(%esp),%ecx");
comment|/* Undo current frame */
asm|asm("movl %ebp,%esp");
asm|asm("popl %ebp");
comment|/* like ret, but stay here */
asm|asm("addl $4,%esp");
comment|/* Now, undo previous frame. */
comment|/* This is a test routine, as we have to dynamically probe to find out      what to pop for certain, this is just a guess. */
asm|asm("leal -16(%ebp),%esp");
asm|asm("pop %ebx");
asm|asm("pop %esi");
asm|asm("pop %edi");
asm|asm("movl %ebp,%esp");
asm|asm("popl %ebp");
asm|asm("movl %ecx,0(%esp)");
asm|asm("ret");
block|}
end_function

begin_elif
elif|#
directive|elif
operator|#
name|machine
argument_list|(
name|rs6000
argument_list|)
end_elif

begin_macro
name|__unwind_function
argument_list|(
argument|void *ptr
argument_list|)
end_macro

begin_block
block|{
asm|asm("mr 31,1");
asm|asm("l 1,0(1)");
asm|asm("l 31,-4(1)");
asm|asm("# br");
asm|asm("mr 31,1");
asm|asm("l 1,0(1)");
comment|/* use 31 as a scratch register to restore the link register. */
asm|asm("l 31, 8(1);mtlr 31 # l lr,8(1)");
asm|asm("l 31,-4(1)");
asm|asm("# br");
asm|asm("mtctr 3;bctr # b 3");
block|}
end_block

begin_elif
elif|#
directive|elif
operator|#
name|machine
argument_list|(
name|powerpc
argument_list|)
end_elif

begin_macro
name|__unwind_function
argument_list|(
argument|void *ptr
argument_list|)
end_macro

begin_block
block|{
asm|asm("mr 31,1");
asm|asm("lwz 1,0(1)");
asm|asm("lwz 31,-4(1)");
asm|asm("# br");
asm|asm("mr 31,1");
asm|asm("lwz 1,0(1)");
comment|/* use 31 as a scratch register to restore the link register. */
asm|asm("lwz 31, 8(1);mtlr 31 # l lr,8(1)");
asm|asm("lwz 31,-4(1)");
asm|asm("# br");
asm|asm("mtctr 3;bctr # b 3");
block|}
end_block

begin_elif
elif|#
directive|elif
operator|#
name|machine
argument_list|(
name|vax
argument_list|)
end_elif

begin_macro
name|__unwind_function
argument_list|(
argument|void *ptr
argument_list|)
end_macro

begin_block
block|{
name|__label__
name|return_again
decl_stmt|;
comment|/* Replace our frame's return address with the label below.      During execution, we will first return here instead of to      caller, then second return takes caller's frame off the stack.      Two returns matches two actual calls, so is less likely to      confuse debuggers.  `16' corresponds to RETURN_ADDRESS_OFFSET.  */
asm|__asm ("movl %0,16(fp)" : : "p" (&& return_again));
return|return;
name|return_again
label|:
return|return;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|__unwind_function
argument_list|(
argument|void *ptr
argument_list|)
end_macro

begin_block
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* powerpc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L_eh */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|L_pure
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|inhibit_libc
end_ifndef

begin_comment
comment|/* This gets us __GNU_LIBRARY__.  */
end_comment

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_comment
comment|/* Avoid errors if stdio.h and our stddef.h mismatch.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNU_LIBRARY__
end_ifdef

begin_comment
comment|/* Avoid forcing the library's meaning of `write' on the user program      by using the "internal" name (for use within the library)  */
end_comment

begin_define
define|#
directive|define
name|write
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
value|__write((fd), (buf), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* inhibit_libc */
end_comment

begin_define
define|#
directive|define
name|MESSAGE
value|"pure virtual method called\n"
end_define

begin_function
name|void
name|__pure_virtual
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|inhibit_libc
name|write
argument_list|(
literal|2
argument_list|,
name|MESSAGE
argument_list|,
sizeof|sizeof
argument_list|(
name|MESSAGE
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|_exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

