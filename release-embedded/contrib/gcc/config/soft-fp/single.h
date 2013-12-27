begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Software floating-point emulation.    Definitions for IEEE Single Precision.    Copyright (C) 1997,1998,1999,2006 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Richard Henderson (rth@cygnus.com), 		  Jakub Jelinek (jj@ultra.linux.cz), 		  David S. Miller (davem@redhat.com) and 		  Peter Maydell (pmaydell@chiark.greenend.org.uk).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     In addition to the permissions in the GNU Lesser General Public    License, the Free Software Foundation gives you unlimited    permission to link the compiled version of this file into    combinations with other programs, and to distribute those    combinations without any restriction coming from the use of this    file.  (The Lesser General Public License restrictions do apply in    other respects; for example, they cover modification of the file,    and distribution when not linked into a combine executable.)     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
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

begin_define
define|#
directive|define
name|_FP_FRACTBITS_S
value|_FP_W_TYPE_SIZE
end_define

begin_define
define|#
directive|define
name|_FP_FRACBITS_S
value|24
end_define

begin_define
define|#
directive|define
name|_FP_FRACXBITS_S
value|(_FP_FRACTBITS_S - _FP_FRACBITS_S)
end_define

begin_define
define|#
directive|define
name|_FP_WFRACBITS_S
value|(_FP_WORKBITS + _FP_FRACBITS_S)
end_define

begin_define
define|#
directive|define
name|_FP_WFRACXBITS_S
value|(_FP_FRACTBITS_S - _FP_WFRACBITS_S)
end_define

begin_define
define|#
directive|define
name|_FP_EXPBITS_S
value|8
end_define

begin_define
define|#
directive|define
name|_FP_EXPBIAS_S
value|127
end_define

begin_define
define|#
directive|define
name|_FP_EXPMAX_S
value|255
end_define

begin_define
define|#
directive|define
name|_FP_QNANBIT_S
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_S-2))
end_define

begin_define
define|#
directive|define
name|_FP_QNANBIT_SH_S
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_S-2+_FP_WORKBITS))
end_define

begin_define
define|#
directive|define
name|_FP_IMPLBIT_S
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_S-1))
end_define

begin_define
define|#
directive|define
name|_FP_IMPLBIT_SH_S
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_S-1+_FP_WORKBITS))
end_define

begin_define
define|#
directive|define
name|_FP_OVERFLOW_S
value|((_FP_W_TYPE)1<< (_FP_WFRACBITS_S))
end_define

begin_comment
comment|/* The implementation of _FP_MUL_MEAT_S and _FP_DIV_MEAT_S should be    chosen by the target machine.  */
end_comment

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

begin_union
union|union
name|_FP_UNION_S
block|{
name|SFtype
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
name|_FP_EXPBITS_S
decl_stmt|;
name|unsigned
name|frac
range|:
name|_FP_FRACBITS_S
operator|-
operator|(
name|_FP_IMPLBIT_S
operator|!=
literal|0
operator|)
decl_stmt|;
else|#
directive|else
name|unsigned
name|frac
range|:
name|_FP_FRACBITS_S
operator|-
operator|(
name|_FP_IMPLBIT_S
operator|!=
literal|0
operator|)
decl_stmt|;
name|unsigned
name|exp
range|:
name|_FP_EXPBITS_S
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
name|FP_DECL_S
parameter_list|(
name|X
parameter_list|)
value|_FP_DECL(1,X)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_S
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_1(S,X,val)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_SP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
value|_FP_UNPACK_RAW_1_P(S,X,val)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_S
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
value|_FP_PACK_RAW_1(S,val,X)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_SP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_1_P(S,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_S
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_1(S,X,val);		\     _FP_UNPACK_CANONICAL(S,1,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_1_P(S,X,val);	\     _FP_UNPACK_CANONICAL(S,1,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_S
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_1(S,X,val);		\     _FP_UNPACK_SEMIRAW(S,1,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_SP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     _FP_UNPACK_RAW_1_P(S,X,val);	\     _FP_UNPACK_SEMIRAW(S,1,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_S
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(S,1,X);		\     _FP_PACK_RAW_1(S,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(S,1,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_1_P(S,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_S
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(S,1,X);		\     _FP_PACK_RAW_1(S,val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_SP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(S,1,X);		\     if (!FP_INHIBIT_RESULTS)		\       _FP_PACK_RAW_1_P(S,val,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_ISSIGNAN_S
parameter_list|(
name|X
parameter_list|)
value|_FP_ISSIGNAN(S,1,X)
end_define

begin_define
define|#
directive|define
name|FP_NEG_S
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_NEG(S,1,R,X)
end_define

begin_define
define|#
directive|define
name|FP_ADD_S
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_ADD(S,1,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SUB_S
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_SUB(S,1,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_MUL_S
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_MUL(S,1,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_DIV_S
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV(S,1,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SQRT_S
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_SQRT(S,1,R,X)
end_define

begin_define
define|#
directive|define
name|_FP_SQRT_MEAT_S
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

begin_define
define|#
directive|define
name|FP_CMP_S
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|un
parameter_list|)
value|_FP_CMP(S,1,r,X,Y,un)
end_define

begin_define
define|#
directive|define
name|FP_CMP_EQ_S
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_EQ(S,1,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_CMP_UNORD_S
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_UNORD(S,1,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_TO_INT_S
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|rsz
parameter_list|,
name|rsg
parameter_list|)
value|_FP_TO_INT(S,1,r,X,rsz,rsg)
end_define

begin_define
define|#
directive|define
name|FP_FROM_INT_S
parameter_list|(
name|X
parameter_list|,
name|r
parameter_list|,
name|rs
parameter_list|,
name|rt
parameter_list|)
value|_FP_FROM_INT(S,1,X,r,rs,rt)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_S
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_1(X)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_RAW_S
parameter_list|(
name|X
parameter_list|)
value|_FP_FRAC_HIGH_1(X)
end_define

end_unit

