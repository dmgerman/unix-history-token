begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Include file for internal GNU MP types and definitions.  Copyright (C) 1991, 1993, 1994, 1995, 1996 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU MP Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/* When using gcc, make sure to use its builtin alloca.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|alloca
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* When using cc, do whatever necessary to allow use of alloca.  For many    machines, this means including alloca.h.  IBM's compilers need a #pragma    in "each module that needs to use alloca".  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|alloca
argument_list|)
end_if

begin_comment
comment|/* We need lots of variants for MIPS, to cover all versions and perversions    of OSes for MIPS.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPSEL
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPSEB
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_MIPSEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_MIPSEB
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ksr__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_define
define|#
directive|define
name|HAVE_ALLOCA
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
name|_IBMR2
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_define
define|#
directive|define
name|HAVE_ALLOCA
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
name|__DECC
argument_list|)
end_if

begin_define
define|#
directive|define
name|alloca
parameter_list|(
name|x
parameter_list|)
value|__ALLOCA(x)
end_define

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|HAVE_ALLOCA
argument_list|)
operator|||
name|USE_STACK_ALLOC
end_if

begin_include
include|#
directive|include
file|"stack-alloc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TMP_DECL
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TMP_ALLOC
parameter_list|(
name|x
parameter_list|)
value|alloca(x)
end_define

begin_define
define|#
directive|define
name|TMP_MARK
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TMP_FREE
parameter_list|(
name|m
parameter_list|)
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
value|((void *) 0)
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
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|inline
end_define

begin_comment
comment|/* Empty */
end_comment

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

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|l
parameter_list|,
name|o
parameter_list|)
value|((l)< (o) ? (l) : (o))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|h
parameter_list|,
name|i
parameter_list|)
value|((h)> (i) ? (h) : (i))
end_define

begin_comment
comment|/* Field access macros.  */
end_comment

begin_define
define|#
directive|define
name|SIZ
parameter_list|(
name|x
parameter_list|)
value|((x)->_mp_size)
end_define

begin_define
define|#
directive|define
name|ABSIZ
parameter_list|(
name|x
parameter_list|)
value|ABS (SIZ (x))
end_define

begin_define
define|#
directive|define
name|PTR
parameter_list|(
name|x
parameter_list|)
value|((x)->_mp_d)
end_define

begin_define
define|#
directive|define
name|EXP
parameter_list|(
name|x
parameter_list|)
value|((x)->_mp_exp)
end_define

begin_define
define|#
directive|define
name|PREC
parameter_list|(
name|x
parameter_list|)
value|((x)->_mp_prec)
end_define

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)->_mp_alloc)
end_define

begin_include
include|#
directive|include
file|"gmp-mparam.h"
end_include

begin_comment
comment|/* #include "longlong.h" */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

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
name|MPN_COPY_INCR
parameter_list|(
name|DST
parameter_list|,
name|SRC
parameter_list|,
name|NLIMBS
parameter_list|)
define|\
value|do {									\     mp_size_t __i;							\     for (__i = 0; __i< (NLIMBS); __i++)				\       (DST)[__i] = (SRC)[__i];						\   } while (0)
end_define

begin_define
define|#
directive|define
name|MPN_COPY_DECR
parameter_list|(
name|DST
parameter_list|,
name|SRC
parameter_list|,
name|NLIMBS
parameter_list|)
define|\
value|do {									\     mp_size_t __i;							\     for (__i = (NLIMBS) - 1; __i>= 0; __i--)				\       (DST)[__i] = (SRC)[__i];						\   } while (0)
end_define

begin_define
define|#
directive|define
name|MPN_COPY
value|MPN_COPY_INCR
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
value|do {									\     mp_size_t __i;							\     for (__i = 0; __i< (NLIMBS); __i++)				\       (DST)[__i] = 0;							\   } while (0)
end_define

begin_define
define|#
directive|define
name|MPN_NORMALIZE
parameter_list|(
name|DST
parameter_list|,
name|NLIMBS
parameter_list|)
define|\
value|do {									\     while (NLIMBS> 0)							\       {									\ 	if ((DST)[(NLIMBS) - 1] != 0)					\ 	  break;							\ 	NLIMBS--;							\       }									\   } while (0)
end_define

begin_define
define|#
directive|define
name|MPN_NORMALIZE_NOT_ZERO
parameter_list|(
name|DST
parameter_list|,
name|NLIMBS
parameter_list|)
define|\
value|do {									\     while (1)								\       {									\ 	if ((DST)[(NLIMBS) - 1] != 0)					\ 	  break;							\ 	NLIMBS--;							\       }									\   } while (0)
end_define

begin_comment
comment|/* Initialize the MP_INT X with space for NLIMBS limbs.    X should be a temporary variable, and it will be automatically    cleared out when the running function returns.    We use __x here to make it possible to accept both mpz_ptr and mpz_t    arguments.  */
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
value|do {									\     mpz_ptr __x = (X);							\     __x->_mp_alloc = (NLIMBS);						\     __x->_mp_d = (mp_ptr) TMP_ALLOC ((NLIMBS) * BYTES_PER_MP_LIMB);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|MPN_MUL_N_RECURSE
parameter_list|(
name|prodp
parameter_list|,
name|up
parameter_list|,
name|vp
parameter_list|,
name|size
parameter_list|,
name|tspace
parameter_list|)
define|\
value|do {									\     if ((size)< KARATSUBA_THRESHOLD)					\       impn_mul_n_basecase (prodp, up, vp, size);			\     else								\       impn_mul_n (prodp, up, vp, size, tspace);			\   } while (0);
end_define

begin_define
define|#
directive|define
name|MPN_SQR_N_RECURSE
parameter_list|(
name|prodp
parameter_list|,
name|up
parameter_list|,
name|size
parameter_list|,
name|tspace
parameter_list|)
define|\
value|do {									\     if ((size)< KARATSUBA_THRESHOLD)					\       impn_sqr_n_basecase (prodp, up, size);				\     else								\       impn_sqr_n (prodp, up, size, tspace);				\   } while (0);
end_define

begin_comment
comment|/* Structure for conversion between internal binary format and    strings in base 2..36.  */
end_comment

begin_struct
struct|struct
name|bases
block|{
comment|/* Number of digits in the conversion base that always fits in an mp_limb_t.      For example, for base 10 on a machine where a mp_limb_t has 32 bits this      is 9, since 10**9 is the largest number that fits into a mp_limb_t.  */
name|int
name|chars_per_limb
decl_stmt|;
comment|/* log(2)/log(conversion_base) */
name|float
name|chars_per_bit_exactly
decl_stmt|;
comment|/* base**chars_per_limb, i.e. the biggest number that fits a word, built by      factors of base.  Exception: For 2, 4, 8, etc, big_base is log2(base),      i.e. the number of bits used to represent each digit in the base.  */
name|mp_limb_t
name|big_base
decl_stmt|;
comment|/* A BITS_PER_MP_LIMB bit approximation to 1/big_base, represented as a      fixed-point number.  Instead of dividing by big_base an application can      choose to multiply by big_base_inverted.  */
name|mp_limb_t
name|big_base_inverted
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
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mp_size_t
name|__gmp_default_fp_limb_precision
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Divide the two-limb number in (NH,,NL) by D, with DI being the largest    limb not larger than (2**(2*BITS_PER_MP_LIMB))/D - (2**BITS_PER_MP_LIMB).    If this would yield overflow, DI should be the largest possible number    (i.e., only ones).  For correct operation, the most significant bit of D    has to be set.  Put the quotient in Q and the remainder in R.  */
end_comment

begin_define
define|#
directive|define
name|udiv_qrnnd_preinv
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|nh
parameter_list|,
name|nl
parameter_list|,
name|d
parameter_list|,
name|di
parameter_list|)
define|\
value|do {									\     mp_limb_t _q, _ql, _r;						\     mp_limb_t _xh, _xl;							\     umul_ppmm (_q, _ql, (nh), (di));					\     _q += (nh);
comment|/* DI is 2**BITS_PER_MP_LIMB too small */
value|\     umul_ppmm (_xh, _xl, _q, (d));					\     sub_ddmmss (_xh, _r, (nh), (nl), _xh, _xl);				\     if (_xh != 0)							\       {									\ 	sub_ddmmss (_xh, _r, _xh, _r, 0, (d));				\ 	_q += 1;							\ 	if (_xh != 0)							\ 	  {								\ 	    sub_ddmmss (_xh, _r, _xh, _r, 0, (d));			\ 	    _q += 1;							\ 	  }								\       }									\     if (_r>= (d))							\       {									\ 	_r -= (d);							\ 	_q += 1;							\       }									\     (r) = _r;								\     (q) = _q;								\   } while (0)
end_define

begin_comment
comment|/* Like udiv_qrnnd_preinv, but for for any value D.  DNORM is D shifted left    so that its most significant bit is set.  LGUP is ceil(log2(D)).  */
end_comment

begin_define
define|#
directive|define
name|udiv_qrnnd_preinv2gen
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|nh
parameter_list|,
name|nl
parameter_list|,
name|d
parameter_list|,
name|di
parameter_list|,
name|dnorm
parameter_list|,
name|lgup
parameter_list|)
define|\
value|do {									\     mp_limb_t n2, n10, n1, nadj, q1;					\     mp_limb_t _xh, _xl;							\     n2 = ((nh)<< (BITS_PER_MP_LIMB - (lgup))) + ((nl)>> 1>> (l - 1));\     n10 = (nl)<< (BITS_PER_MP_LIMB - (lgup));				\     n1 = ((mp_limb_signed_t) n10>> (BITS_PER_MP_LIMB - 1));		\     nadj = n10 + (n1& (dnorm));					\     umul_ppmm (_xh, _xl, di, n2 - n1);					\     add_ssaaaa (_xh, _xl, _xh, _xl, 0, nadj);				\     q1 = ~(n2 + _xh);							\     umul_ppmm (_xh, _xl, q1, d);					\     add_ssaaaa (_xh, _xl, _xh, _xl, nh, nl);				\     _xh -= (d);								\     (r) = _xl + ((d)& _xh);						\     (q) = _xh - q1;							\   } while (0)
end_define

begin_comment
comment|/* Exactly like udiv_qrnnd_preinv, but branch-free.  It is not clear which    version to use.  */
end_comment

begin_define
define|#
directive|define
name|udiv_qrnnd_preinv2norm
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|nh
parameter_list|,
name|nl
parameter_list|,
name|d
parameter_list|,
name|di
parameter_list|)
define|\
value|do {									\     mp_limb_t n2, n10, n1, nadj, q1;					\     mp_limb_t _xh, _xl;							\     n2 = (nh);								\     n10 = (nl);								\     n1 = ((mp_limb_signed_t) n10>> (BITS_PER_MP_LIMB - 1));		\     nadj = n10 + (n1& (d));						\     umul_ppmm (_xh, _xl, di, n2 - n1);					\     add_ssaaaa (_xh, _xl, _xh, _xl, 0, nadj);				\     q1 = ~(n2 + _xh);							\     umul_ppmm (_xh, _xl, q1, d);					\     add_ssaaaa (_xh, _xl, _xh, _xl, nh, nl);				\     _xh -= (d);								\     (r) = _xl + ((d)& _xh);						\     (q) = _xh - q1;							\   } while (0)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|/* Define stuff for longlong.h.  */
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

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UQItype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|SItype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|USItype
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|mp_limb_t
name|UWtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UHWtype
typedef|;
end_typedef

begin_define
define|#
directive|define
name|W_TYPE_SIZE
value|BITS_PER_MP_LIMB
end_define

begin_comment
comment|/* Internal mpn calls */
end_comment

begin_define
define|#
directive|define
name|impn_mul_n_basecase
value|__MPN(impn_mul_n_basecase)
end_define

begin_define
define|#
directive|define
name|impn_mul_n
value|__MPN(impn_mul_n)
end_define

begin_define
define|#
directive|define
name|impn_sqr_n_basecase
value|__MPN(impn_sqr_n_basecase)
end_define

begin_define
define|#
directive|define
name|impn_sqr_n
value|__MPN(impn_sqr_n)
end_define

begin_comment
comment|/* Define ieee_double_extract and _GMP_IEEE_FLOATS.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LITTLE_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|__LITTLE_ENDIAN__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__alpha
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__ARMWEL__
argument_list|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|__clipper__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__cris
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__i860__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__i960__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|MIPSEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_MIPSEL
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ns32000__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__WINNT
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GMP_IEEE_FLOATS
value|1
end_define

begin_union
union|union
name|ieee_double_extract
block|{
struct|struct
block|{
name|unsigned
name|int
name|manl
range|:
literal|32
decl_stmt|;
name|unsigned
name|int
name|manh
range|:
literal|20
decl_stmt|;
name|unsigned
name|int
name|exp
range|:
literal|11
decl_stmt|;
name|unsigned
name|int
name|sig
range|:
literal|1
decl_stmt|;
block|}
name|s
struct|;
name|double
name|d
decl_stmt|;
block|}
union|;
end_union

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Need this as an #else since the tests aren't made exclusive.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_BIG_ENDIAN
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__a29k__
argument_list|)
operator|||
name|defined
argument_list|(
name|_AM29K
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__arm__
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|__convex__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_IEEE_FLOAT_
argument_list|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|__i370__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mvs__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__mc68000__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mc68020__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NeXT__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|mc68020
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__m88000__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|MIPSEB
argument_list|)
operator|||
name|defined
argument_list|(
name|_MIPSEB
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__hppa
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__pyr__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ibm032__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__sh__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__we32k__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GMP_IEEE_FLOATS
value|1
end_define

begin_union
union|union
name|ieee_double_extract
block|{
struct|struct
block|{
name|unsigned
name|int
name|sig
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|exp
range|:
literal|11
decl_stmt|;
name|unsigned
name|int
name|manh
range|:
literal|20
decl_stmt|;
name|unsigned
name|int
name|manl
range|:
literal|32
decl_stmt|;
block|}
name|s
struct|;
name|double
name|d
decl_stmt|;
block|}
union|;
end_union

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
name|MP_BASE_AS_DOUBLE
value|(2.0 * ((mp_limb_t) 1<< (BITS_PER_MP_LIMB - 1)))
end_define

begin_if
if|#
directive|if
name|BITS_PER_MP_LIMB
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|LIMBS_PER_DOUBLE
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIMBS_PER_DOUBLE
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|double
name|__gmp_scale2
name|_PROTO
argument_list|(
operator|(
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__gmp_extract_double
name|_PROTO
argument_list|(
operator|(
name|mp_ptr
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

