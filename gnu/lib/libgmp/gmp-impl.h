begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Include file for internal GNU MP types and definitions.  Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with the GNU MP Library; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.   */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_function_decl
specifier|volatile
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|inline
end_define

begin_comment
comment|/* Empty */
end_comment

begin_function_decl
name|void
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|x
parameter_list|)
value|(x>= 0 ? x : -x)
end_define

begin_include
include|#
directive|include
file|"gmp-mparam.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|_mp_allocate_func
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|_mp_reallocate_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|_mp_free_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_mp_default_allocate
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_mp_default_reallocate
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mp_default_free
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_mpz_get_str
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
name|int
name|_mpz_set_str
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
name|_mpz_impl_sqrt
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* Empty */
end_comment

begin_define
define|#
directive|define
name|signed
end_define

begin_comment
comment|/* Empty */
end_comment

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|_mp_allocate_func
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|_mp_reallocate_func
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|_mp_free_func
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_mp_default_allocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_mp_default_reallocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mp_default_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_mpz_get_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_mpz_set_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mpz_impl_sqrt
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Copy NLIMBS *limbs* from SRC to DST.  */
end_comment

begin_define
define|#
directive|define
name|MPN_COPY
parameter_list|(
name|DST
parameter_list|,
name|SRC
parameter_list|,
name|NLIMBS
parameter_list|)
define|\
value|do {									\     mp_size i;								\     for (i = 0; i< (NLIMBS); i++)					\       (DST)[i] = (SRC)[i];						\   } while (0)
end_define

begin_comment
comment|/* Zero NLIMBS *limbs* AT DST.  */
end_comment

begin_define
define|#
directive|define
name|MPN_ZERO
parameter_list|(
name|DST
parameter_list|,
name|NLIMBS
parameter_list|)
define|\
value|do {									\     mp_size i;								\     for (i = 0; i< (NLIMBS); i++)					\       (DST)[i] = 0;							\   } while (0)
end_define

begin_comment
comment|/* Initialize the MP_INT X with space for NLIMBS limbs.    X should be a temporary variable, and it will be automatically    cleared out when the running function returns.  */
end_comment

begin_define
define|#
directive|define
name|MPZ_TMP_INIT
parameter_list|(
name|X
parameter_list|,
name|NLIMBS
parameter_list|)
define|\
value|do {									\     (X)->alloc = (NLIMBS);						\     (X)->d = (mp_ptr) alloca ((NLIMBS) * BYTES_PER_MP_LIMB);		\   } while (0)
end_define

begin_comment
comment|/* Structure for conversion between internal binary format and    strings in base 2..36.  */
end_comment

begin_struct
struct|struct
name|bases
block|{
comment|/* Number of digits in the conversion base that always fits in      an mp_limb.  For example, for base 10 this is 10, since      2**32 = 4294967296 has ten digits.  */
name|int
name|chars_per_limb
decl_stmt|;
comment|/* big_base is conversion_base**chars_per_limb, i.e. the biggest      number that fits a word, built by factors of conversion_base.      Exception: For 2, 4, 8, etc, big_base is log2(base), i.e. the      number of bits used to represent each digit in the base.  */
name|mp_limb
name|big_base
decl_stmt|;
comment|/* big_base_inverted is a BITS_PER_MP_LIMB bit approximation to      1/big_base, represented as a fixed-point number.  Instead of      dividing by big_base an application can choose to multiply      by big_base_inverted.  */
name|mp_limb
name|big_base_inverted
decl_stmt|;
comment|/* log(2)/log(conversion_base) */
name|float
name|chars_per_bit_exactly
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bases
name|__mp_bases
index|[
literal|37
index|]
decl_stmt|;
end_decl_stmt

end_unit

