begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Software floating-point emulation.    Definitions for IEEE Double Precision    Copyright (C) 1997,1998,1999,2006 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Richard Henderson (rth@cygnus.com), 		  Jakub Jelinek (jj@ultra.linux.cz), 		  David S. Miller (davem@redhat.com) and 		  Peter Maydell (pmaydell@chiark.greenend.org.uk).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     In addition to the permissions in the GNU Lesser General Public    License, the Free Software Foundation gives you unlimited    permission to link the compiled version of this file into    combinations with other programs, and to distribute those    combinations without any restriction coming from the use of this    file.  (The Lesser General Public License restrictions do apply in    other respects; for example, they cover modification of the file,    and distribution when not linked into a combine executable.)     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_if
if|#
directive|if
name|_FP_W_TYPE_SIZE
operator|<
literal|32
end_if

begin_error
error|#
directive|error
literal|"Here's a nickel kid.  Go buy yourself a real computer."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_FP_W_TYPE_SIZE
operator|<
literal|64
end_if

begin_define
define|#
directive|define
name|_FP_FRACTBITS_D
value|(2 * _FP_W_TYPE_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_FP_FRACTBITS_D
value|_FP_W_TYPE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_FP_FRACBITS_D
value|53
end_define

begin_define
define|#
directive|define
name|_FP_FRACXBITS_D
value|(_FP_FRACTBITS_D - _FP_FRACBITS_D)
end_define

begin_define
define|#
directive|define
name|_FP_WFRACBITS_D
value|(_FP_WORKBITS + _FP_FRACBITS_D)
end_define

begin_define
define|#
directive|define
name|_FP_WFRACXBITS_D
value|(_FP_FRACTBITS_D - _FP_WFRACBITS_D)
end_define

begin_define
define|#
directive|define
name|_FP_EXPBITS_D
value|11
end_define

begin_define
define|#
directive|define
name|_FP_EXPBIAS_D
value|1023
end_define

begin_define
define|#
directive|define
name|_FP_EXPMAX_D
value|2047
end_define

begin_define
define|#
directive|define
name|_FP_QNANBIT_D
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_D-2) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_QNANBIT_SH_D
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_D-2+_FP_WORKBITS) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_IMPLBIT_D
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_D-1) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_IMPLBIT_SH_D
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_D-1+_FP_WORKBITS) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_OVERFLOW_D
define|\
value|((_FP_W_TYPE)1<< _FP_WFRACBITS_D % _FP_W_TYPE_SIZE)
end_define

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
name|_FP_W_TYPE_SIZE
operator|<
literal|64
end_if

begin_union
union|union
name|_FP_UNION_D
block|{
name|DFtype
name|flt
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|exp
range|:
name|_FP_EXPBITS_D
decl_stmt|;
name|unsigned
name|frac1
range|:
name|_FP_FRACBITS_D
operator|-
operator|(
name|_FP_IMPLBIT_D
operator|!=
literal|0
operator|)
operator|-
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|frac0
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
else|#
directive|else
name|unsigned
name|frac0
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|frac1
range|:
name|_FP_FRACBITS_D
operator|-
operator|(
name|_FP_IMPLBIT_D
operator|!=
literal|0
operator|)
operator|-
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|exp
range|:
name|_FP_EXPBITS_D
decl_stmt|;
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
name|bits
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|FP_DECL_D
parameter_list|(
name|X
parameter_list|)
value|_FP_DECL(2,X)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_D
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_2(D,X,val)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_DP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_2_P(D,X,val)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_D
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
value|_FP_PACK_RAW_2(D,val,X)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_DP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_2_P(D,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_D
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2(D,X,val);		\     _FP_UNPACK_CANONICAL(D,2,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_DP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2_P(D,X,val);	\     _FP_UNPACK_CANONICAL(D,2,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_D
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2(D,X,val);		\     _FP_UNPACK_SEMIRAW(D,2,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_DP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2_P(D,X,val);	\     _FP_UNPACK_SEMIRAW(D,2,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_D
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(D,2,X);		\     _FP_PACK_RAW_2(D,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_DP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(D,2,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_2_P(D,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_D
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(D,2,X);		\     _FP_PACK_RAW_2(D,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_DP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(D,2,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_2_P(D,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_ISSIGNAN_D
parameter_list|(
name|X
parameter_list|)
value|_FP_ISSIGNAN(D,2,X)
end_define

begin_define
define|#
directive|define
name|FP_NEG_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_NEG(D,2,R,X)
end_define

begin_define
define|#
directive|define
name|FP_ADD_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_ADD(D,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SUB_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_SUB(D,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_MUL_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_MUL(D,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_DIV_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV(D,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SQRT_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_SQRT(D,2,R,X)
end_define

begin_define
define|#
directive|define
name|_FP_SQRT_MEAT_D
parameter_list|(
name|R
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|X
parameter_list|,
name|Q
parameter_list|)
value|_FP_SQRT_MEAT_2(R,S,T,X,Q)
end_define

begin_define
define|#
directive|define
name|FP_CMP_D
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|un
parameter_list|)
value|_FP_CMP(D,2,r,X,Y,un)
end_define

begin_define
define|#
directive|define
name|FP_CMP_EQ_D
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_EQ(D,2,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_CMP_UNORD_D
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_UNORD(D,2,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_TO_INT_D
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|rsz
parameter_list|,
name|rsg
parameter_list|)
value|_FP_TO_INT(D,2,r,X,rsz,rsg)
end_define

begin_define
define|#
directive|define
name|FP_FROM_INT_D
parameter_list|(
name|X
parameter_list|,
name|r
parameter_list|,
name|rs
parameter_list|,
name|rt
parameter_list|)
value|_FP_FROM_INT(D,2,X,r,rs,rt)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_D
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_2(X)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_RAW_D
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_2(X)
end_define

begin_else
else|#
directive|else
end_else

begin_union
union|union
name|_FP_UNION_D
block|{
name|DFtype
name|flt
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|exp
range|:
name|_FP_EXPBITS_D
decl_stmt|;
name|unsigned
name|long
name|frac
range|:
name|_FP_FRACBITS_D
operator|-
operator|(
name|_FP_IMPLBIT_D
operator|!=
literal|0
operator|)
decl_stmt|;
else|#
directive|else
name|unsigned
name|long
name|frac
range|:
name|_FP_FRACBITS_D
operator|-
operator|(
name|_FP_IMPLBIT_D
operator|!=
literal|0
operator|)
decl_stmt|;
name|unsigned
name|exp
range|:
name|_FP_EXPBITS_D
decl_stmt|;
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
name|bits
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|FP_DECL_D
parameter_list|(
name|X
parameter_list|)
value|_FP_DECL(1,X)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_D
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_1(D,X,val)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_DP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_1_P(D,X,val)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_D
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
value|_FP_PACK_RAW_1(D,val,X)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_DP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_1_P(D,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_D
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_1(D,X,val);		\     _FP_UNPACK_CANONICAL(D,1,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_DP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_1_P(D,X,val);	\     _FP_UNPACK_CANONICAL(D,1,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_D
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2(1,X,val);		\     _FP_UNPACK_SEMIRAW(D,1,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_DP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2_P(1,X,val);	\     _FP_UNPACK_SEMIRAW(D,1,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_D
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(D,1,X);		\     _FP_PACK_RAW_1(D,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_DP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(D,1,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_1_P(D,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_D
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(D,1,X);		\     _FP_PACK_RAW_1(D,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_DP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(D,1,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_1_P(D,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_ISSIGNAN_D
parameter_list|(
name|X
parameter_list|)
value|_FP_ISSIGNAN(D,1,X)
end_define

begin_define
define|#
directive|define
name|FP_NEG_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_NEG(D,1,R,X)
end_define

begin_define
define|#
directive|define
name|FP_ADD_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_ADD(D,1,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SUB_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_SUB(D,1,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_MUL_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_MUL(D,1,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_DIV_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV(D,1,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SQRT_D
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_SQRT(D,1,R,X)
end_define

begin_define
define|#
directive|define
name|_FP_SQRT_MEAT_D
parameter_list|(
name|R
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|X
parameter_list|,
name|Q
parameter_list|)
value|_FP_SQRT_MEAT_1(R,S,T,X,Q)
end_define

begin_comment
comment|/* The implementation of _FP_MUL_D and _FP_DIV_D should be chosen by    the target machine.  */
end_comment

begin_define
define|#
directive|define
name|FP_CMP_D
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|un
parameter_list|)
value|_FP_CMP(D,1,r,X,Y,un)
end_define

begin_define
define|#
directive|define
name|FP_CMP_EQ_D
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_EQ(D,1,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_CMP_UNORD_D
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_UNORD(D,1,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_TO_INT_D
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|rsz
parameter_list|,
name|rsg
parameter_list|)
value|_FP_TO_INT(D,1,r,X,rsz,rsg)
end_define

begin_define
define|#
directive|define
name|FP_FROM_INT_D
parameter_list|(
name|X
parameter_list|,
name|r
parameter_list|,
name|rs
parameter_list|,
name|rt
parameter_list|)
value|_FP_FROM_INT(D,1,X,r,rs,rt)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_D
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_1(X)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_RAW_D
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_1(X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* W_TYPE_SIZE< 64 */
end_comment

end_unit

