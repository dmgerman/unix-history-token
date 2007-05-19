begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for fp-bit.c.  */
end_comment

begin_comment
comment|/* Copyright (C) 2000, 2002, 2003, 2006 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file into combinations with other programs, and to distribute those combinations without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into a combine executable.)  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_FP_BIT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_FP_BIT_H
end_define

begin_comment
comment|/* Defining FINE_GRAINED_LIBRARIES allows one to select which routines    from this file are compiled via additional -D options.     This avoids the need to pull in the entire fp emulation library    when only a small number of functions are needed.     If FINE_GRAINED_LIBRARIES is not defined, then compile every    suitable routine.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FINE_GRAINED_LIBRARIES
end_ifndef

begin_define
define|#
directive|define
name|L_pack_df
end_define

begin_define
define|#
directive|define
name|L_unpack_df
end_define

begin_define
define|#
directive|define
name|L_pack_sf
end_define

begin_define
define|#
directive|define
name|L_unpack_sf
end_define

begin_define
define|#
directive|define
name|L_addsub_sf
end_define

begin_define
define|#
directive|define
name|L_addsub_df
end_define

begin_define
define|#
directive|define
name|L_mul_sf
end_define

begin_define
define|#
directive|define
name|L_mul_df
end_define

begin_define
define|#
directive|define
name|L_div_sf
end_define

begin_define
define|#
directive|define
name|L_div_df
end_define

begin_define
define|#
directive|define
name|L_fpcmp_parts_sf
end_define

begin_define
define|#
directive|define
name|L_fpcmp_parts_df
end_define

begin_define
define|#
directive|define
name|L_compare_sf
end_define

begin_define
define|#
directive|define
name|L_compare_df
end_define

begin_define
define|#
directive|define
name|L_eq_sf
end_define

begin_define
define|#
directive|define
name|L_eq_df
end_define

begin_define
define|#
directive|define
name|L_ne_sf
end_define

begin_define
define|#
directive|define
name|L_ne_df
end_define

begin_define
define|#
directive|define
name|L_gt_sf
end_define

begin_define
define|#
directive|define
name|L_gt_df
end_define

begin_define
define|#
directive|define
name|L_ge_sf
end_define

begin_define
define|#
directive|define
name|L_ge_df
end_define

begin_define
define|#
directive|define
name|L_lt_sf
end_define

begin_define
define|#
directive|define
name|L_lt_df
end_define

begin_define
define|#
directive|define
name|L_le_sf
end_define

begin_define
define|#
directive|define
name|L_le_df
end_define

begin_define
define|#
directive|define
name|L_unord_sf
end_define

begin_define
define|#
directive|define
name|L_unord_df
end_define

begin_define
define|#
directive|define
name|L_usi_to_sf
end_define

begin_define
define|#
directive|define
name|L_usi_to_df
end_define

begin_define
define|#
directive|define
name|L_si_to_sf
end_define

begin_define
define|#
directive|define
name|L_si_to_df
end_define

begin_define
define|#
directive|define
name|L_sf_to_si
end_define

begin_define
define|#
directive|define
name|L_df_to_si
end_define

begin_define
define|#
directive|define
name|L_f_to_usi
end_define

begin_define
define|#
directive|define
name|L_df_to_usi
end_define

begin_define
define|#
directive|define
name|L_negate_sf
end_define

begin_define
define|#
directive|define
name|L_negate_df
end_define

begin_define
define|#
directive|define
name|L_make_sf
end_define

begin_define
define|#
directive|define
name|L_make_df
end_define

begin_define
define|#
directive|define
name|L_sf_to_df
end_define

begin_define
define|#
directive|define
name|L_df_to_sf
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT
end_ifdef

begin_define
define|#
directive|define
name|L_thenan_sf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|L_thenan_df
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
comment|/* ! FINE_GRAINED_LIBRARIES */
end_comment

begin_if
if|#
directive|if
name|__LDBL_MANT_DIG__
operator|==
literal|113
operator|||
name|__LDBL_MANT_DIG__
operator|==
literal|106
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TFLOAT
argument_list|)
operator|||
name|defined
argument_list|(
name|L_sf_to_tf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_df_to_tf
argument_list|)
end_if

begin_define
define|#
directive|define
name|TMODES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|TMODES
end_ifdef

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
name|HItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|HI
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
name|int
name|DItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|TMODES
end_ifdef

begin_typedef
typedef|typedef
name|int
name|TItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|TI
typedef|)));
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The type of the result of a floating point comparison.  This must    match `word_mode' in GCC for the target.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CMPtype
end_ifndef

begin_typedef
typedef|typedef
name|int
name|CMPtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|word
typedef|)));
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UHItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|HI
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

begin_ifdef
ifdef|#
directive|ifdef
name|TMODES
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UTItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|TI
typedef|)));
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_USI_INT
value|(~(USItype)0)
end_define

begin_define
define|#
directive|define
name|MAX_SI_INT
value|((SItype) (MAX_USI_INT>> 1))
end_define

begin_define
define|#
directive|define
name|BITS_PER_SI
value|(4 * BITS_PER_UNIT)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TMODES
end_ifdef

begin_define
define|#
directive|define
name|MAX_UDI_INT
value|(~(UDItype)0)
end_define

begin_define
define|#
directive|define
name|MAX_DI_INT
value|((DItype) (MAX_UDI_INT>> 1))
end_define

begin_define
define|#
directive|define
name|BITS_PER_DI
value|(8 * BITS_PER_UNIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT_ONLY
end_ifdef

begin_define
define|#
directive|define
name|NO_DI_MODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TFLOAT
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TMODES
end_ifndef

begin_error
error|#
directive|error
literal|"TFLOAT requires long double to have 113 bits of mantissa"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PREFIXFPDP
value|tp
end_define

begin_define
define|#
directive|define
name|PREFIXSFDF
value|tf
end_define

begin_define
define|#
directive|define
name|NGARDS
value|10L
end_define

begin_comment
comment|/* Is this right? */
end_comment

begin_define
define|#
directive|define
name|GARDROUND
value|0x1ff
end_define

begin_define
define|#
directive|define
name|GARDMASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|GARDMSB
value|0x200
end_define

begin_define
define|#
directive|define
name|FRAC_NBITS
value|128
end_define

begin_if
if|#
directive|if
name|__LDBL_MANT_DIG__
operator|==
literal|113
end_if

begin_comment
comment|/* IEEE quad */
end_comment

begin_define
define|#
directive|define
name|EXPBITS
value|15
end_define

begin_define
define|#
directive|define
name|EXPBIAS
value|16383
end_define

begin_define
define|#
directive|define
name|EXPMAX
value|(0x7fff)
end_define

begin_define
define|#
directive|define
name|QUIET_NAN
value|((TItype)0x8<< 108)
end_define

begin_define
define|#
directive|define
name|FRACHIGH
value|((TItype)0x8<< 124)
end_define

begin_define
define|#
directive|define
name|FRACHIGH2
value|((TItype)0xc<< 124)
end_define

begin_define
define|#
directive|define
name|FRACBITS
value|112
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__LDBL_MANT_DIG__
operator|==
literal|106
end_if

begin_comment
comment|/* IBM extended (double+double) */
end_comment

begin_define
define|#
directive|define
name|EXPBITS
value|11
end_define

begin_define
define|#
directive|define
name|EXPBIAS
value|1023
end_define

begin_define
define|#
directive|define
name|EXPMAX
value|(0x7ff)
end_define

begin_define
define|#
directive|define
name|QUIET_NAN
value|((TItype)0x8<< (48 + 64))
end_define

begin_define
define|#
directive|define
name|FRACHIGH
value|((TItype)0x8<< 124)
end_define

begin_define
define|#
directive|define
name|FRACHIGH2
value|((TItype)0xc<< 124)
end_define

begin_define
define|#
directive|define
name|FRACBITS
value|105
end_define

begin_define
define|#
directive|define
name|HALFFRACBITS
value|52
end_define

begin_define
define|#
directive|define
name|HALFSHIFT
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pack_d
value|__pack_t
end_define

begin_define
define|#
directive|define
name|unpack_d
value|__unpack_t
end_define

begin_define
define|#
directive|define
name|__fpcmp_parts
value|__fpcmp_parts_t
end_define

begin_typedef
typedef|typedef
name|UTItype
name|fractype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UDItype
name|halffractype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|USItype
name|qrtrfractype
typedef|;
end_typedef

begin_define
define|#
directive|define
name|qrtrfractype
value|qrtrfractype
end_define

begin_typedef
typedef|typedef
name|TFtype
name|FLO_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TItype
name|intfrac
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
name|FLOAT
end_elif

begin_define
define|#
directive|define
name|NGARDS
value|7L
end_define

begin_define
define|#
directive|define
name|GARDROUND
value|0x3f
end_define

begin_define
define|#
directive|define
name|GARDMASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|GARDMSB
value|0x40
end_define

begin_define
define|#
directive|define
name|EXPBITS
value|8
end_define

begin_define
define|#
directive|define
name|EXPBIAS
value|127
end_define

begin_define
define|#
directive|define
name|FRACBITS
value|23
end_define

begin_define
define|#
directive|define
name|EXPMAX
value|(0xff)
end_define

begin_define
define|#
directive|define
name|QUIET_NAN
value|0x100000L
end_define

begin_define
define|#
directive|define
name|FRAC_NBITS
value|32
end_define

begin_define
define|#
directive|define
name|FRACHIGH
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|FRACHIGH2
value|0xc0000000L
end_define

begin_define
define|#
directive|define
name|pack_d
value|__pack_f
end_define

begin_define
define|#
directive|define
name|unpack_d
value|__unpack_f
end_define

begin_define
define|#
directive|define
name|__fpcmp_parts
value|__fpcmp_parts_f
end_define

begin_typedef
typedef|typedef
name|USItype
name|fractype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UHItype
name|halffractype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SFtype
name|FLO_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SItype
name|intfrac
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PREFIXFPDP
value|dp
end_define

begin_define
define|#
directive|define
name|PREFIXSFDF
value|df
end_define

begin_define
define|#
directive|define
name|NGARDS
value|8L
end_define

begin_define
define|#
directive|define
name|GARDROUND
value|0x7f
end_define

begin_define
define|#
directive|define
name|GARDMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|GARDMSB
value|0x80
end_define

begin_define
define|#
directive|define
name|EXPBITS
value|11
end_define

begin_define
define|#
directive|define
name|EXPBIAS
value|1023
end_define

begin_define
define|#
directive|define
name|FRACBITS
value|52
end_define

begin_define
define|#
directive|define
name|EXPMAX
value|(0x7ff)
end_define

begin_define
define|#
directive|define
name|QUIET_NAN
value|0x8000000000000LL
end_define

begin_define
define|#
directive|define
name|FRAC_NBITS
value|64
end_define

begin_define
define|#
directive|define
name|FRACHIGH
value|0x8000000000000000LL
end_define

begin_define
define|#
directive|define
name|FRACHIGH2
value|0xc000000000000000LL
end_define

begin_define
define|#
directive|define
name|pack_d
value|__pack_d
end_define

begin_define
define|#
directive|define
name|unpack_d
value|__unpack_d
end_define

begin_define
define|#
directive|define
name|__fpcmp_parts
value|__fpcmp_parts_d
end_define

begin_typedef
typedef|typedef
name|UDItype
name|fractype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|USItype
name|halffractype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|DFtype
name|FLO_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|DItype
name|intfrac
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FLOAT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|US_SOFTWARE_GOFAST
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TFLOAT
end_ifdef

begin_error
error|#
directive|error
literal|"GOFAST TFmode not supported"
end_error

begin_elif
elif|#
directive|elif
name|defined
name|FLOAT
end_elif

begin_define
define|#
directive|define
name|add
value|fpadd
end_define

begin_define
define|#
directive|define
name|sub
value|fpsub
end_define

begin_define
define|#
directive|define
name|multiply
value|fpmul
end_define

begin_define
define|#
directive|define
name|divide
value|fpdiv
end_define

begin_define
define|#
directive|define
name|compare
value|fpcmp
end_define

begin_define
define|#
directive|define
name|_unord_f2
value|__unordsf2
end_define

begin_define
define|#
directive|define
name|usi_to_float
value|__floatunsisf
end_define

begin_define
define|#
directive|define
name|si_to_float
value|sitofp
end_define

begin_define
define|#
directive|define
name|float_to_si
value|fptosi
end_define

begin_define
define|#
directive|define
name|float_to_usi
value|fptoui
end_define

begin_define
define|#
directive|define
name|negate
value|__negsf2
end_define

begin_define
define|#
directive|define
name|sf_to_df
value|fptodp
end_define

begin_define
define|#
directive|define
name|sf_to_tf
value|__extendsftf2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|add
value|dpadd
end_define

begin_define
define|#
directive|define
name|sub
value|dpsub
end_define

begin_define
define|#
directive|define
name|multiply
value|dpmul
end_define

begin_define
define|#
directive|define
name|divide
value|dpdiv
end_define

begin_define
define|#
directive|define
name|compare
value|dpcmp
end_define

begin_define
define|#
directive|define
name|_unord_f2
value|__unorddf2
end_define

begin_define
define|#
directive|define
name|usi_to_float
value|__floatunsidf
end_define

begin_define
define|#
directive|define
name|si_to_float
value|litodp
end_define

begin_define
define|#
directive|define
name|float_to_si
value|dptoli
end_define

begin_define
define|#
directive|define
name|float_to_usi
value|dptoul
end_define

begin_define
define|#
directive|define
name|negate
value|__negdf2
end_define

begin_define
define|#
directive|define
name|df_to_sf
value|dptofp
end_define

begin_define
define|#
directive|define
name|df_to_tf
value|__extenddftf2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FLOAT */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TFLOAT
end_ifdef

begin_define
define|#
directive|define
name|add
value|__addtf3
end_define

begin_define
define|#
directive|define
name|sub
value|__subtf3
end_define

begin_define
define|#
directive|define
name|multiply
value|__multf3
end_define

begin_define
define|#
directive|define
name|divide
value|__divtf3
end_define

begin_define
define|#
directive|define
name|compare
value|__cmptf2
end_define

begin_define
define|#
directive|define
name|_eq_f2
value|__eqtf2
end_define

begin_define
define|#
directive|define
name|_ne_f2
value|__netf2
end_define

begin_define
define|#
directive|define
name|_gt_f2
value|__gttf2
end_define

begin_define
define|#
directive|define
name|_ge_f2
value|__getf2
end_define

begin_define
define|#
directive|define
name|_lt_f2
value|__lttf2
end_define

begin_define
define|#
directive|define
name|_le_f2
value|__letf2
end_define

begin_define
define|#
directive|define
name|_unord_f2
value|__unordtf2
end_define

begin_define
define|#
directive|define
name|usi_to_float
value|__floatunsitf
end_define

begin_define
define|#
directive|define
name|si_to_float
value|__floatsitf
end_define

begin_define
define|#
directive|define
name|float_to_si
value|__fixtfsi
end_define

begin_define
define|#
directive|define
name|float_to_usi
value|__fixunstfsi
end_define

begin_define
define|#
directive|define
name|negate
value|__negtf2
end_define

begin_define
define|#
directive|define
name|tf_to_sf
value|__trunctfsf2
end_define

begin_define
define|#
directive|define
name|tf_to_df
value|__trunctfdf2
end_define

begin_elif
elif|#
directive|elif
name|defined
name|FLOAT
end_elif

begin_define
define|#
directive|define
name|add
value|__addsf3
end_define

begin_define
define|#
directive|define
name|sub
value|__subsf3
end_define

begin_define
define|#
directive|define
name|multiply
value|__mulsf3
end_define

begin_define
define|#
directive|define
name|divide
value|__divsf3
end_define

begin_define
define|#
directive|define
name|compare
value|__cmpsf2
end_define

begin_define
define|#
directive|define
name|_eq_f2
value|__eqsf2
end_define

begin_define
define|#
directive|define
name|_ne_f2
value|__nesf2
end_define

begin_define
define|#
directive|define
name|_gt_f2
value|__gtsf2
end_define

begin_define
define|#
directive|define
name|_ge_f2
value|__gesf2
end_define

begin_define
define|#
directive|define
name|_lt_f2
value|__ltsf2
end_define

begin_define
define|#
directive|define
name|_le_f2
value|__lesf2
end_define

begin_define
define|#
directive|define
name|_unord_f2
value|__unordsf2
end_define

begin_define
define|#
directive|define
name|usi_to_float
value|__floatunsisf
end_define

begin_define
define|#
directive|define
name|si_to_float
value|__floatsisf
end_define

begin_define
define|#
directive|define
name|float_to_si
value|__fixsfsi
end_define

begin_define
define|#
directive|define
name|float_to_usi
value|__fixunssfsi
end_define

begin_define
define|#
directive|define
name|negate
value|__negsf2
end_define

begin_define
define|#
directive|define
name|sf_to_df
value|__extendsfdf2
end_define

begin_define
define|#
directive|define
name|sf_to_tf
value|__extendsftf2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|add
value|__adddf3
end_define

begin_define
define|#
directive|define
name|sub
value|__subdf3
end_define

begin_define
define|#
directive|define
name|multiply
value|__muldf3
end_define

begin_define
define|#
directive|define
name|divide
value|__divdf3
end_define

begin_define
define|#
directive|define
name|compare
value|__cmpdf2
end_define

begin_define
define|#
directive|define
name|_eq_f2
value|__eqdf2
end_define

begin_define
define|#
directive|define
name|_ne_f2
value|__nedf2
end_define

begin_define
define|#
directive|define
name|_gt_f2
value|__gtdf2
end_define

begin_define
define|#
directive|define
name|_ge_f2
value|__gedf2
end_define

begin_define
define|#
directive|define
name|_lt_f2
value|__ltdf2
end_define

begin_define
define|#
directive|define
name|_le_f2
value|__ledf2
end_define

begin_define
define|#
directive|define
name|_unord_f2
value|__unorddf2
end_define

begin_define
define|#
directive|define
name|usi_to_float
value|__floatunsidf
end_define

begin_define
define|#
directive|define
name|si_to_float
value|__floatsidf
end_define

begin_define
define|#
directive|define
name|float_to_si
value|__fixdfsi
end_define

begin_define
define|#
directive|define
name|float_to_usi
value|__fixunsdfsi
end_define

begin_define
define|#
directive|define
name|negate
value|__negdf2
end_define

begin_define
define|#
directive|define
name|df_to_sf
value|__truncdfsf2
end_define

begin_define
define|#
directive|define
name|df_to_tf
value|__extenddftf2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FLOAT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* US_SOFTWARE_GOFAST */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE
end_ifndef

begin_define
define|#
directive|define
name|INLINE
value|__inline__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Preserve the sticky-bit when shifting fractions to the right.  */
end_comment

begin_define
define|#
directive|define
name|LSHIFT
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|{ a = (a>> s) | !!(a& (((fractype) 1<< s) - 1)); }
end_define

begin_comment
comment|/* numeric parameters */
end_comment

begin_comment
comment|/* F_D_BITOFF is the number of bits offset between the MSB of the mantissa    of a float and of a double. Assumes there are only two float types.    (double::FRAC_BITS+double::NGARDS-(float::FRAC_BITS-float::NGARDS))  */
end_comment

begin_define
define|#
directive|define
name|F_D_BITOFF
value|(52+8-(23+7))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TMODES
end_ifdef

begin_define
define|#
directive|define
name|F_T_BITOFF
value|(__LDBL_MANT_DIG__-1+10-(23+7))
end_define

begin_define
define|#
directive|define
name|D_T_BITOFF
value|(__LDBL_MANT_DIG__-1+10-(52+8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NORMAL_EXPMIN
value|(-(EXPBIAS)+1)
end_define

begin_define
define|#
directive|define
name|IMPLICIT_1
value|((fractype)1<<(FRACBITS+NGARDS))
end_define

begin_define
define|#
directive|define
name|IMPLICIT_2
value|((fractype)1<<(FRACBITS+1+NGARDS))
end_define

begin_comment
comment|/* common types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CLASS_SNAN
block|,
name|CLASS_QNAN
block|,
name|CLASS_ZERO
block|,
name|CLASS_NUMBER
block|,
name|CLASS_INFINITY
block|}
name|fp_class_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
ifdef|#
directive|ifdef
name|SMALL_MACHINE
name|char
name|class
decl_stmt|;
name|unsigned
name|char
name|sign
decl_stmt|;
name|short
name|normal_exp
decl_stmt|;
else|#
directive|else
name|fp_class_type
name|class
decl_stmt|;
name|unsigned
name|int
name|sign
decl_stmt|;
name|int
name|normal_exp
decl_stmt|;
endif|#
directive|endif
union|union
block|{
name|fractype
name|ll
decl_stmt|;
name|halffractype
name|l
index|[
literal|2
index|]
decl_stmt|;
block|}
name|fraction
union|;
block|}
name|fp_number_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|FLO_type
name|value
decl_stmt|;
name|fractype
name|value_raw
decl_stmt|;
ifndef|#
directive|ifndef
name|FLOAT
ifdef|#
directive|ifdef
name|qrtrfractype
name|qrtrfractype
name|qwords
index|[
literal|4
index|]
decl_stmt|;
else|#
directive|else
name|halffractype
name|words
index|[
literal|2
index|]
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|FLOAT_BIT_ORDER_MISMATCH
struct|struct
block|{
name|fractype
name|fraction
range|:
name|FRACBITS
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|exp
range|:
name|EXPBITS
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|sign
range|:
literal|1
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
name|bits
struct|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_DEBUG_BITFLOAT
struct|struct
block|{
name|unsigned
name|int
name|sign
range|:
literal|1
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|exp
range|:
name|EXPBITS
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|fractype
name|fraction
range|:
name|FRACBITS
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
name|bits_big_endian
struct|;
struct|struct
block|{
name|fractype
name|fraction
range|:
name|FRACBITS
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|exp
range|:
name|EXPBITS
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|sign
range|:
literal|1
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
name|bits_little_endian
struct|;
endif|#
directive|endif
block|}
name|FLO_union_type
typedef|;
end_typedef

begin_comment
comment|/* Prototypes */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_pack_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_pack_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_pack_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|FLO_type
name|pack_d
parameter_list|(
name|fp_number_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|unpack_d
parameter_list|(
name|FLO_union_type
modifier|*
parameter_list|,
name|fp_number_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_addsub_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_addsub_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_addsub_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|FLO_type
name|add
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FLO_type
name|sub
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
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
name|defined
argument_list|(
name|L_mul_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_mul_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_mul_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|FLO_type
name|multiply
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
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
name|defined
argument_list|(
name|L_div_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_div_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_div_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|FLO_type
name|divide
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|__fpcmp_parts
parameter_list|(
name|fp_number_type
modifier|*
parameter_list|,
name|fp_number_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_compare_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_compare_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_compare_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|compare
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|US_SOFTWARE_GOFAST
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_eq_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_eq_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_eq_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|_eq_f2
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
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
name|defined
argument_list|(
name|L_ne_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_ne_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_ne_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|_ne_f2
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
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
name|defined
argument_list|(
name|L_gt_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_gt_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_gt_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|_gt_f2
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
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
name|defined
argument_list|(
name|L_ge_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_ge_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_ge_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|_ge_f2
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
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
name|defined
argument_list|(
name|L_lt_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_lt_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_lt_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|_lt_f2
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
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
name|defined
argument_list|(
name|L_le_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_le_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_le_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|_le_f2
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
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
name|defined
argument_list|(
name|L_unord_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_unord_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_unord_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|CMPtype
name|_unord_f2
parameter_list|(
name|FLO_type
parameter_list|,
name|FLO_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! US_SOFTWARE_GOFAST */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_si_to_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_si_to_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_si_to_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|FLO_type
name|si_to_float
parameter_list|(
name|SItype
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
name|defined
argument_list|(
name|L_sf_to_si
argument_list|)
operator|||
name|defined
argument_list|(
name|L_df_to_si
argument_list|)
operator|||
name|defined
argument_list|(
name|L_tf_to_si
argument_list|)
end_if

begin_function_decl
specifier|extern
name|SItype
name|float_to_si
parameter_list|(
name|FLO_type
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
name|defined
argument_list|(
name|L_sf_to_usi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_df_to_usi
argument_list|)
operator|||
name|defined
argument_list|(
name|L_tf_to_usi
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|US_SOFTWARE_GOFAST
argument_list|)
operator|||
name|defined
argument_list|(
name|L_tf_to_usi
argument_list|)
end_if

begin_function_decl
specifier|extern
name|USItype
name|float_to_usi
parameter_list|(
name|FLO_type
parameter_list|)
function_decl|;
end_function_decl

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
name|defined
argument_list|(
name|L_usi_to_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_usi_to_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_usi_to_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|FLO_type
name|usi_to_float
parameter_list|(
name|USItype
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
name|defined
argument_list|(
name|L_negate_sf
argument_list|)
operator|||
name|defined
argument_list|(
name|L_negate_df
argument_list|)
operator|||
name|defined
argument_list|(
name|L_negate_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|FLO_type
name|negate
parameter_list|(
name|FLO_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_make_sf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|SFtype
name|__make_fp
parameter_list|(
name|fp_class_type
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|USItype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT_ONLY
end_ifndef

begin_function_decl
specifier|extern
name|DFtype
name|__make_dp
parameter_list|(
name|fp_class_type
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|UDItype
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_sf_to_df
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DFtype
name|sf_to_df
parameter_list|(
name|SFtype
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
name|defined
argument_list|(
name|L_sf_to_tf
argument_list|)
operator|&&
name|defined
argument_list|(
name|TMODES
argument_list|)
end_if

begin_function_decl
specifier|extern
name|TFtype
name|sf_to_tf
parameter_list|(
name|SFtype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FLOAT_ONLY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FLOAT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT
end_ifndef

begin_function_decl
specifier|extern
name|SFtype
name|__make_fp
parameter_list|(
name|fp_class_type
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|USItype
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_make_df
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DFtype
name|__make_dp
parameter_list|(
name|fp_class_type
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|UDItype
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
name|defined
argument_list|(
name|L_df_to_sf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|SFtype
name|df_to_sf
parameter_list|(
name|DFtype
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
name|defined
argument_list|(
name|L_df_to_tf
argument_list|)
operator|&&
name|defined
argument_list|(
name|TMODES
argument_list|)
end_if

begin_function_decl
specifier|extern
name|TFtype
name|df_to_tf
parameter_list|(
name|DFtype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FLOAT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TMODES
end_ifdef

begin_function_decl
specifier|extern
name|DFtype
name|__make_dp
parameter_list|(
name|fp_class_type
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|UDItype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|TFtype
name|__make_tp
parameter_list|(
name|fp_class_type
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|UTItype
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TFLOAT
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|L_tf_to_sf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|SFtype
name|tf_to_sf
parameter_list|(
name|TFtype
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
name|defined
argument_list|(
name|L_tf_to_df
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DFtype
name|tf_to_df
parameter_list|(
name|TFtype
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
name|defined
argument_list|(
name|L_di_to_tf
argument_list|)
end_if

begin_function_decl
specifier|extern
name|TFtype
name|di_to_df
parameter_list|(
name|DItype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TFLOAT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TMODES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_FP_BIT_H */
end_comment

end_unit

