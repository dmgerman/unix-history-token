begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gmp.h -- Definitions for GNU multiple precision functions.  Copyright (C) 1991, 1993 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with the GNU MP Library; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GMP_H__
end_ifndef

begin_define
define|#
directive|define
name|__GMP_H__
end_define

begin_define
define|#
directive|define
name|__GNU_MP__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__MP_H__
end_ifndef

begin_define
define|#
directive|define
name|__need_size_t
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MINT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__MP_SMALL__
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|int
name|alloc
decl_stmt|;
comment|/* Number of *limbs* allocated and pointed 				   to by the D field.  */
name|long
name|int
name|size
decl_stmt|;
comment|/* abs(SIZE) is the number of limbs 				   the last field points to.  If SIZE 				   is negative this is a negative 				   number.  */
name|unsigned
name|long
name|int
modifier|*
name|d
decl_stmt|;
comment|/* Pointer to the limbs.  */
block|}
name|__MP_INT
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|int
name|alloc
decl_stmt|;
comment|/* Number of *limbs* allocated and pointed 				   to by the D field.  */
name|short
name|int
name|size
decl_stmt|;
comment|/* abs(SIZE) is the number of limbs 				   the last field points to.  If SIZE 				   is negative this is a negative 				   number.  */
name|unsigned
name|long
name|int
modifier|*
name|d
decl_stmt|;
comment|/* Pointer to the limbs.  */
block|}
name|__MP_INT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MP_INT
value|__MP_INT
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|mp_limb
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|int
name|mp_limb_signed
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|mp_limb
modifier|*
name|mp_ptr
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
specifier|const
name|mp_limb
modifier|*
name|mp_srcptr
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|mp_limb
modifier|*
name|mp_srcptr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|long
name|int
name|mp_size
typedef|;
end_typedef

begin_comment
comment|/* Structure for rational numbers.  Zero is represented as 0/any, i.e.    the denominator is ignored.  Negative numbers have the sign in    the numerator.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|MP_INT
name|num
decl_stmt|;
name|MP_INT
name|den
decl_stmt|;
if|#
directive|if
literal|0
block|long int num_alloc;
comment|/* Number of limbs allocated 				   for the numerator.  */
block|long int num_size;
comment|/* The absolute value of this field is the 				   length of the numerator; the sign is the 				   sign of the entire rational number.  */
block|mp_ptr num;
comment|/* Pointer to the numerator limbs.  */
block|long int den_alloc;
comment|/* Number of limbs allocated 				   for the denominator.  */
block|long int den_size;
comment|/* Length of the denominator.  (This field 				   should always be positive.) */
block|mp_ptr den;
comment|/* Pointer to the denominator limbs.  */
endif|#
directive|endif
block|}
name|MP_RAT
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|mp_set_memory_functions
parameter_list|(
name|void
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************** Integer (i.e. Z) routines.  ****************/
end_comment

begin_function_decl
name|void
name|mpz_init
parameter_list|(
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_set
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_set_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_set_si
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|signed
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_set_str
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_init_set
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_init_set_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_init_set_si
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|signed
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_init_set_str
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|int
name|mpz_get_ui
parameter_list|(
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|signed
name|long
name|int
name|mpz_get_si
parameter_list|(
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mpz_get_str
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_clear
parameter_list|(
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_mpz_realloc
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_add
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_add_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_sub
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_sub_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mul
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mul_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_div
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_div_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mod
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mod_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_divmod
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_divmod_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mdiv
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mdiv_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mmod
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|int
name|mpz_mmod_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mdivmod
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|int
name|mpz_mdivmod_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_sqrt
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_sqrtrem
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_perfect_square_p
parameter_list|(
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_probab_prime_p
parameter_list|(
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_powm
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_powm_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_pow_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_fac_ui
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_gcd
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_gcdext
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|MP_INT
modifier|*
parameter_list|,
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_neg
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_com
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_abs
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_cmp
parameter_list|(
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_cmp_ui
parameter_list|(
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_cmp_si
parameter_list|(
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|signed
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mul_2exp
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_div_2exp
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mod_2exp
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_and
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_ior
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_xor
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FILE
argument_list|)
operator|||
name|defined
argument_list|(
name|_STDIO_H
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDIO_H__
argument_list|)
end_if

begin_function_decl
name|void
name|mpz_inp_raw
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_inp_str
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_out_raw
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_out_str
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|mpz_array_init
parameter_list|(
name|MP_INT
index|[]
parameter_list|,
name|size_t
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_random
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_random2
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mpz_size
parameter_list|(
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mpz_sizeinbase
parameter_list|(
specifier|const
name|MP_INT
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************** Rational (i.e. Q) routines.  ****************/
end_comment

begin_function_decl
name|void
name|mpq_init
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_clear
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set_ui
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set_si
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
name|signed
name|long
name|int
parameter_list|,
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_add
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_sub
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_mul
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_div
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_neg
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpq_cmp
parameter_list|(
specifier|const
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_inv
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set_num
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set_den
parameter_list|(
name|MP_RAT
modifier|*
parameter_list|,
specifier|const
name|MP_INT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_get_num
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_get_den
parameter_list|(
name|MP_INT
modifier|*
parameter_list|,
specifier|const
name|MP_RAT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************ Low level positive-integer (i.e. N) routines.  ************/
end_comment

begin_function_decl
name|mp_limb
name|mpn_add
parameter_list|(
name|mp_ptr
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_sub
parameter_list|(
name|mp_ptr
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_mul
parameter_list|(
name|mp_ptr
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_div
parameter_list|(
name|mp_ptr
parameter_list|,
name|mp_ptr
parameter_list|,
name|mp_size
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mp_limb
name|mpn_divmod_1
parameter_list|(
name|mp_ptr
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|,
name|mp_limb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mp_limb
name|mpn_mod_1
parameter_list|(
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|,
name|mp_limb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mp_limb
name|mpn_lshift
parameter_list|(
name|mp_ptr
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_rshift
parameter_list|(
name|mp_ptr
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_rshiftci
parameter_list|(
name|mp_ptr
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|mp_limb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_sqrt
parameter_list|(
name|mp_ptr
parameter_list|,
name|mp_ptr
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpn_cmp
parameter_list|(
name|mp_srcptr
parameter_list|,
name|mp_srcptr
parameter_list|,
name|mp_size
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __STDC__ */
end_comment

begin_function_decl
name|void
name|mp_set_memory_functions
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/**************** Integer (i.e. Z) routines.  ****************/
end_comment

begin_function_decl
name|void
name|mpz_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_set_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_set_si
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_set_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_init_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_init_set_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_init_set_si
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_init_set_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|int
name|mpz_get_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|int
name|mpz_get_si
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mpz_get_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_clear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_mpz_realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_add_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_sub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_sub_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mul
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mul_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_div
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_div_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mod_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_divmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_divmod_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mdiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mdiv_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|int
name|mpz_mmod_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mdivmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|int
name|mpz_mdivmod_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_sqrt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_sqrtrem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_perfect_square_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_probab_prime_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_powm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_powm_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_pow_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_fac_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_gcd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_gcdext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_neg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_com
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_abs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_cmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_cmp_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpz_cmp_si
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mul_2exp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_div_2exp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_mod_2exp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_and
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_ior
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_xor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_inp_raw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_inp_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_out_raw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_out_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_array_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_random
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpz_random2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mpz_size
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mpz_sizeinbase
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/**************** Rational (i.e. Q) routines.  ****************/
end_comment

begin_function_decl
name|void
name|mpq_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_clear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set_ui
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set_si
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_sub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_mul
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_div
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_neg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpq_cmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_inv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set_num
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_set_den
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_get_num
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpq_get_den
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/************ Low level positive-integer (i.e. N) routines.  ************/
end_comment

begin_function_decl
name|mp_limb
name|mpn_add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_sub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_mul
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_div
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|mp_limb
name|mpn_lshift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_rshift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|mp_size
name|mpn_rshiftci
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpn_cmp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GMP_H__ */
end_comment

end_unit

