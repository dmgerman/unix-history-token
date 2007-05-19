begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Software floating-point emulation.    Definitions for IEEE Quad Precision.    Copyright (C) 1997,1998,1999,2006 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Richard Henderson (rth@cygnus.com), 		  Jakub Jelinek (jj@ultra.linux.cz), 		  David S. Miller (davem@redhat.com) and 		  Peter Maydell (pmaydell@chiark.greenend.org.uk).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     In addition to the permissions in the GNU Lesser General Public    License, the Free Software Foundation gives you unlimited    permission to link the compiled version of this file into    combinations with other programs, and to distribute those    combinations without any restriction coming from the use of this    file.  (The Lesser General Public License restrictions do apply in    other respects; for example, they cover modification of the file,    and distribution when not linked into a combine executable.)     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
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
literal|"Here's a nickel, kid. Go buy yourself a real computer."
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
name|_FP_FRACTBITS_Q
value|(4*_FP_W_TYPE_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_FP_FRACTBITS_Q
value|(2*_FP_W_TYPE_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_FP_FRACBITS_Q
value|113
end_define

begin_define
define|#
directive|define
name|_FP_FRACXBITS_Q
value|(_FP_FRACTBITS_Q - _FP_FRACBITS_Q)
end_define

begin_define
define|#
directive|define
name|_FP_WFRACBITS_Q
value|(_FP_WORKBITS + _FP_FRACBITS_Q)
end_define

begin_define
define|#
directive|define
name|_FP_WFRACXBITS_Q
value|(_FP_FRACTBITS_Q - _FP_WFRACBITS_Q)
end_define

begin_define
define|#
directive|define
name|_FP_EXPBITS_Q
value|15
end_define

begin_define
define|#
directive|define
name|_FP_EXPBIAS_Q
value|16383
end_define

begin_define
define|#
directive|define
name|_FP_EXPMAX_Q
value|32767
end_define

begin_define
define|#
directive|define
name|_FP_QNANBIT_Q
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_Q-2) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_QNANBIT_SH_Q
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_Q-2+_FP_WORKBITS) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_IMPLBIT_Q
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_Q-1) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_IMPLBIT_SH_Q
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_Q-1+_FP_WORKBITS) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_OVERFLOW_Q
define|\
value|((_FP_W_TYPE)1<< (_FP_WFRACBITS_Q % _FP_W_TYPE_SIZE))
end_define

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

begin_if
if|#
directive|if
name|_FP_W_TYPE_SIZE
operator|<
literal|64
end_if

begin_union
union|union
name|_FP_UNION_Q
block|{
name|TFtype
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
name|_FP_EXPBITS_Q
decl_stmt|;
name|unsigned
name|long
name|frac3
range|:
name|_FP_FRACBITS_Q
operator|-
operator|(
name|_FP_IMPLBIT_Q
operator|!=
literal|0
operator|)
operator|-
operator|(
name|_FP_W_TYPE_SIZE
operator|*
literal|3
operator|)
decl_stmt|;
name|unsigned
name|long
name|frac2
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|long
name|frac1
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|long
name|frac0
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
else|#
directive|else
name|unsigned
name|long
name|frac0
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|long
name|frac1
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|long
name|frac2
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|long
name|frac3
range|:
name|_FP_FRACBITS_Q
operator|-
operator|(
name|_FP_IMPLBIT_Q
operator|!=
literal|0
operator|)
operator|-
operator|(
name|_FP_W_TYPE_SIZE
operator|*
literal|3
operator|)
decl_stmt|;
name|unsigned
name|exp
range|:
name|_FP_EXPBITS_Q
decl_stmt|;
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
comment|/* not bigendian */
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
name|FP_DECL_Q
parameter_list|(
name|X
parameter_list|)
value|_FP_DECL(4,X)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_Q
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_4(Q,X,val)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_QP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_4_P(Q,X,val)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_Q
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
value|_FP_PACK_RAW_4(Q,val,X)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_QP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_4_P(Q,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_Q
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_4(Q,X,val);		\     _FP_UNPACK_CANONICAL(Q,4,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_QP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_4_P(Q,X,val);	\     _FP_UNPACK_CANONICAL(Q,4,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_Q
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_4(Q,X,val);		\     _FP_UNPACK_SEMIRAW(Q,4,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_QP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_4_P(Q,X,val);	\     _FP_UNPACK_SEMIRAW(Q,4,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_Q
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(Q,4,X);		\     _FP_PACK_RAW_4(Q,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_QP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(Q,4,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_4_P(Q,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_Q
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(Q,4,X);		\     _FP_PACK_RAW_4(Q,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_QP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(Q,4,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_4_P(Q,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_ISSIGNAN_Q
parameter_list|(
name|X
parameter_list|)
value|_FP_ISSIGNAN(Q,4,X)
end_define

begin_define
define|#
directive|define
name|FP_NEG_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_NEG(Q,4,R,X)
end_define

begin_define
define|#
directive|define
name|FP_ADD_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_ADD(Q,4,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SUB_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_SUB(Q,4,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_MUL_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_MUL(Q,4,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_DIV_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV(Q,4,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SQRT_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_SQRT(Q,4,R,X)
end_define

begin_define
define|#
directive|define
name|_FP_SQRT_MEAT_Q
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
value|_FP_SQRT_MEAT_4(R,S,T,X,Q)
end_define

begin_define
define|#
directive|define
name|FP_CMP_Q
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|un
parameter_list|)
value|_FP_CMP(Q,4,r,X,Y,un)
end_define

begin_define
define|#
directive|define
name|FP_CMP_EQ_Q
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_EQ(Q,4,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_CMP_UNORD_Q
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_UNORD(Q,4,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_TO_INT_Q
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|rsz
parameter_list|,
name|rsg
parameter_list|)
value|_FP_TO_INT(Q,4,r,X,rsz,rsg)
end_define

begin_define
define|#
directive|define
name|FP_FROM_INT_Q
parameter_list|(
name|X
parameter_list|,
name|r
parameter_list|,
name|rs
parameter_list|,
name|rt
parameter_list|)
value|_FP_FROM_INT(Q,4,X,r,rs,rt)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_Q
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_4(X)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_RAW_Q
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_4(X)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not _FP_W_TYPE_SIZE< 64 */
end_comment

begin_union
union|union
name|_FP_UNION_Q
block|{
name|TFtype
name|flt
comment|/* __attribute__((mode(TF))) */
decl_stmt|;
struct|struct
block|{
name|_FP_W_TYPE
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|longs
struct|;
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
name|_FP_EXPBITS_Q
decl_stmt|;
name|unsigned
name|long
name|frac1
range|:
name|_FP_FRACBITS_Q
operator|-
operator|(
name|_FP_IMPLBIT_Q
operator|!=
literal|0
operator|)
operator|-
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|long
name|frac0
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
else|#
directive|else
name|unsigned
name|long
name|frac0
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|long
name|frac1
range|:
name|_FP_FRACBITS_Q
operator|-
operator|(
name|_FP_IMPLBIT_Q
operator|!=
literal|0
operator|)
operator|-
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|exp
range|:
name|_FP_EXPBITS_Q
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
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|FP_DECL_Q
parameter_list|(
name|X
parameter_list|)
value|_FP_DECL(2,X)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_Q
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_2(Q,X,val)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_QP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_2_P(Q,X,val)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_Q
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
value|_FP_PACK_RAW_2(Q,val,X)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_QP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_2_P(Q,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_Q
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2(Q,X,val);		\     _FP_UNPACK_CANONICAL(Q,2,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_QP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2_P(Q,X,val);	\     _FP_UNPACK_CANONICAL(Q,2,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_Q
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2(Q,X,val);		\     _FP_UNPACK_SEMIRAW(Q,2,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_QP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_2_P(Q,X,val);	\     _FP_UNPACK_SEMIRAW(Q,2,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_Q
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(Q,2,X);		\     _FP_PACK_RAW_2(Q,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_QP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(Q,2,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_2_P(Q,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_Q
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(Q,2,X);		\     _FP_PACK_RAW_2(Q,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_QP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(Q,2,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_2_P(Q,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_ISSIGNAN_Q
parameter_list|(
name|X
parameter_list|)
value|_FP_ISSIGNAN(Q,2,X)
end_define

begin_define
define|#
directive|define
name|FP_NEG_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_NEG(Q,2,R,X)
end_define

begin_define
define|#
directive|define
name|FP_ADD_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_ADD(Q,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SUB_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_SUB(Q,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_MUL_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_MUL(Q,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_DIV_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV(Q,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SQRT_Q
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_SQRT(Q,2,R,X)
end_define

begin_define
define|#
directive|define
name|_FP_SQRT_MEAT_Q
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
name|FP_CMP_Q
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|un
parameter_list|)
value|_FP_CMP(Q,2,r,X,Y,un)
end_define

begin_define
define|#
directive|define
name|FP_CMP_EQ_Q
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_EQ(Q,2,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_CMP_UNORD_Q
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_UNORD(Q,2,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_TO_INT_Q
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|rsz
parameter_list|,
name|rsg
parameter_list|)
value|_FP_TO_INT(Q,2,r,X,rsz,rsg)
end_define

begin_define
define|#
directive|define
name|FP_FROM_INT_Q
parameter_list|(
name|X
parameter_list|,
name|r
parameter_list|,
name|rs
parameter_list|,
name|rt
parameter_list|)
value|_FP_FROM_INT(Q,2,X,r,rs,rt)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_Q
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_2(X)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_RAW_Q
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_2(X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _FP_W_TYPE_SIZE< 64 */
end_comment

end_unit

