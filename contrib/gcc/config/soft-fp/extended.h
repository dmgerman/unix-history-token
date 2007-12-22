begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Software floating-point emulation.    Definitions for IEEE Extended Precision.    Copyright (C) 1999,2006,2007 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Jakub Jelinek (jj@ultra.linux.cz).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     In addition to the permissions in the GNU Lesser General Public    License, the Free Software Foundation gives you unlimited    permission to link the compiled version of this file into    combinations with other programs, and to distribute those    combinations without any restriction coming from the use of this    file.  (The Lesser General Public License restrictions do apply in    other respects; for example, they cover modification of the file,    and distribution when not linked into a combine executable.)     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
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
name|_FP_FRACTBITS_E
value|(4*_FP_W_TYPE_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_FP_FRACTBITS_E
value|(2*_FP_W_TYPE_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_FP_FRACBITS_E
value|64
end_define

begin_define
define|#
directive|define
name|_FP_FRACXBITS_E
value|(_FP_FRACTBITS_E - _FP_FRACBITS_E)
end_define

begin_define
define|#
directive|define
name|_FP_WFRACBITS_E
value|(_FP_WORKBITS + _FP_FRACBITS_E)
end_define

begin_define
define|#
directive|define
name|_FP_WFRACXBITS_E
value|(_FP_FRACTBITS_E - _FP_WFRACBITS_E)
end_define

begin_define
define|#
directive|define
name|_FP_EXPBITS_E
value|15
end_define

begin_define
define|#
directive|define
name|_FP_EXPBIAS_E
value|16383
end_define

begin_define
define|#
directive|define
name|_FP_EXPMAX_E
value|32767
end_define

begin_define
define|#
directive|define
name|_FP_QNANBIT_E
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_E-2) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_QNANBIT_SH_E
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_E-2+_FP_WORKBITS) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_IMPLBIT_E
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_E-1) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_IMPLBIT_SH_E
define|\
value|((_FP_W_TYPE)1<< (_FP_FRACBITS_E-1+_FP_WORKBITS) % _FP_W_TYPE_SIZE)
end_define

begin_define
define|#
directive|define
name|_FP_OVERFLOW_E
define|\
value|((_FP_W_TYPE)1<< (_FP_WFRACBITS_E % _FP_W_TYPE_SIZE))
end_define

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

begin_if
if|#
directive|if
name|_FP_W_TYPE_SIZE
operator|<
literal|64
end_if

begin_union
union|union
name|_FP_UNION_E
block|{
name|XFtype
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
name|long
name|pad1
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|long
name|pad2
range|:
operator|(
name|_FP_W_TYPE_SIZE
operator|-
literal|1
operator|-
name|_FP_EXPBITS_E
operator|)
decl_stmt|;
name|unsigned
name|long
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|long
name|exp
range|:
name|_FP_EXPBITS_E
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
name|exp
range|:
name|_FP_EXPBITS_E
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
name|FP_DECL_E
parameter_list|(
name|X
parameter_list|)
value|_FP_DECL(4,X)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_E
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {							\     union _FP_UNION_E _flo; _flo.flt = (val);		\ 							\     X##_f[2] = 0; X##_f[3] = 0;				\     X##_f[0] = _flo.bits.frac0;				\     X##_f[1] = _flo.bits.frac1;				\     X##_e  = _flo.bits.exp;				\     X##_s  = _flo.bits.sign;				\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_EP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {							\     union _FP_UNION_E *_flo =				\     (union _FP_UNION_E *)(val);				\ 							\     X##_f[2] = 0; X##_f[3] = 0;				\     X##_f[0] = _flo->bits.frac0;			\     X##_f[1] = _flo->bits.frac1;			\     X##_e  = _flo->bits.exp;				\     X##_s  = _flo->bits.sign;				\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_E
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {							\     union _FP_UNION_E _flo;				\ 							\     if (X##_e) X##_f[1] |= _FP_IMPLBIT_E;		\     else X##_f[1]&= ~(_FP_IMPLBIT_E);			\     _flo.bits.frac0 = X##_f[0];				\     _flo.bits.frac1 = X##_f[1];				\     _flo.bits.exp   = X##_e;				\     _flo.bits.sign  = X##_s;				\ 							\     (val) = _flo.flt;					\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_EP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {							\     if (!FP_INHIBIT_RESULTS)				\       {							\ 	union _FP_UNION_E *_flo =			\ 	  (union _FP_UNION_E *)(val);			\ 							\ 	if (X##_e) X##_f[1] |= _FP_IMPLBIT_E;		\ 	else X##_f[1]&= ~(_FP_IMPLBIT_E);		\ 	_flo->bits.frac0 = X##_f[0];			\ 	_flo->bits.frac1 = X##_f[1];			\ 	_flo->bits.exp   = X##_e;			\ 	_flo->bits.sign  = X##_s;			\       }							\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_E
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     FP_UNPACK_RAW_E(X,val);		\     _FP_UNPACK_CANONICAL(E,4,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_EP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     FP_UNPACK_RAW_EP(X,val);		\     _FP_UNPACK_CANONICAL(E,4,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_E
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     FP_UNPACK_RAW_E(X,val);		\     _FP_UNPACK_SEMIRAW(E,4,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_EP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     FP_UNPACK_RAW_EP(X,val);		\     _FP_UNPACK_SEMIRAW(E,4,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_E
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(E,4,X);		\     FP_PACK_RAW_E(val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_EP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(E,4,X);		\     FP_PACK_RAW_EP(val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_E
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(E,4,X);		\     FP_PACK_RAW_E(val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_EP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(E,4,X);		\     FP_PACK_RAW_EP(val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_ISSIGNAN_E
parameter_list|(
name|X
parameter_list|)
value|_FP_ISSIGNAN(E,4,X)
end_define

begin_define
define|#
directive|define
name|FP_NEG_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_NEG(E,4,R,X)
end_define

begin_define
define|#
directive|define
name|FP_ADD_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_ADD(E,4,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SUB_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_SUB(E,4,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_MUL_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_MUL(E,4,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_DIV_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV(E,4,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SQRT_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_SQRT(E,4,R,X)
end_define

begin_comment
comment|/*  * Square root algorithms:  * We have just one right now, maybe Newton approximation  * should be added for those machines where division is fast.  * This has special _E version because standard _4 square  * root would not work (it has to start normally with the  * second word and not the first), but as we have to do it  * anyway, we optimize it by doing most of the calculations  * in two UWtype registers instead of four.  */
end_comment

begin_define
define|#
directive|define
name|_FP_SQRT_MEAT_E
parameter_list|(
name|R
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|X
parameter_list|,
name|q
parameter_list|)
define|\
value|do {							\     q = (_FP_W_TYPE)1<< (_FP_W_TYPE_SIZE - 1);		\     _FP_FRAC_SRL_4(X, (_FP_WORKBITS));			\     while (q)						\       {							\ 	T##_f[1] = S##_f[1] + q;			\ 	if (T##_f[1]<= X##_f[1])			\ 	  {						\ 	    S##_f[1] = T##_f[1] + q;			\ 	    X##_f[1] -= T##_f[1];			\ 	    R##_f[1] += q;				\ 	  }						\ 	_FP_FRAC_SLL_2(X, 1);				\ 	q>>= 1;					\       }							\     q = (_FP_W_TYPE)1<< (_FP_W_TYPE_SIZE - 1);		\     while (q)						\       {							\ 	T##_f[0] = S##_f[0] + q;			\ 	T##_f[1] = S##_f[1];				\ 	if (T##_f[1]< X##_f[1] || 			\ 	    (T##_f[1] == X##_f[1]&&			\ 	     T##_f[0]<= X##_f[0]))			\ 	  {						\ 	    S##_f[0] = T##_f[0] + q;			\ 	    S##_f[1] += (T##_f[0]> S##_f[0]);		\ 	    _FP_FRAC_DEC_2(X, T);			\ 	    R##_f[0] += q;				\ 	  }						\ 	_FP_FRAC_SLL_2(X, 1);				\ 	q>>= 1;					\       }							\     _FP_FRAC_SLL_4(R, (_FP_WORKBITS));			\     if (X##_f[0] | X##_f[1])				\       {							\ 	if (S##_f[1]< X##_f[1] || 			\ 	    (S##_f[1] == X##_f[1]&&			\ 	     S##_f[0]< X##_f[0]))			\ 	  R##_f[0] |= _FP_WORK_ROUND;			\ 	R##_f[0] |= _FP_WORK_STICKY;			\       }							\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_CMP_E
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|un
parameter_list|)
value|_FP_CMP(E,4,r,X,Y,un)
end_define

begin_define
define|#
directive|define
name|FP_CMP_EQ_E
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_EQ(E,4,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_CMP_UNORD_E
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_UNORD(E,4,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_TO_INT_E
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|rsz
parameter_list|,
name|rsg
parameter_list|)
value|_FP_TO_INT(E,4,r,X,rsz,rsg)
end_define

begin_define
define|#
directive|define
name|FP_FROM_INT_E
parameter_list|(
name|X
parameter_list|,
name|r
parameter_list|,
name|rs
parameter_list|,
name|rt
parameter_list|)
value|_FP_FROM_INT(E,4,X,r,rs,rt)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_E
parameter_list|(
name|X
parameter_list|)
value|(X##_f[2])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_RAW_E
parameter_list|(
name|X
parameter_list|)
value|(X##_f[1])
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
name|_FP_UNION_E
block|{
name|XFtype
name|flt
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
name|_FP_W_TYPE
name|pad
range|:
operator|(
name|_FP_W_TYPE_SIZE
operator|-
literal|1
operator|-
name|_FP_EXPBITS_E
operator|)
decl_stmt|;
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|exp
range|:
name|_FP_EXPBITS_E
decl_stmt|;
name|_FP_W_TYPE
name|frac
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
else|#
directive|else
name|_FP_W_TYPE
name|frac
range|:
name|_FP_W_TYPE_SIZE
decl_stmt|;
name|unsigned
name|exp
range|:
name|_FP_EXPBITS_E
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
name|FP_DECL_E
parameter_list|(
name|X
parameter_list|)
value|_FP_DECL(2,X)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_E
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\     union _FP_UNION_E _flo; _flo.flt = (val);			\ 								\     X##_f0 = _flo.bits.frac;					\     X##_f1 = 0;							\     X##_e = _flo.bits.exp;					\     X##_s = _flo.bits.sign;					\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_RAW_EP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\     union _FP_UNION_E *_flo =					\       (union _FP_UNION_E *)(val);				\ 								\     X##_f0 = _flo->bits.frac;					\     X##_f1 = 0;							\     X##_e = _flo->bits.exp;					\     X##_s = _flo->bits.sign;					\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_E
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {								\     union _FP_UNION_E _flo;					\ 								\     if (X##_e) X##_f0 |= _FP_IMPLBIT_E;				\     else X##_f0&= ~(_FP_IMPLBIT_E);				\     _flo.bits.frac = X##_f0;					\     _flo.bits.exp  = X##_e;					\     _flo.bits.sign = X##_s;					\ 								\     (val) = _flo.flt;						\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_RAW_EP
parameter_list|(
name|fs
parameter_list|,
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {								\     if (!FP_INHIBIT_RESULTS)					\       {								\ 	union _FP_UNION_E *_flo =				\ 	  (union _FP_UNION_E *)(val);				\ 								\ 	if (X##_e) X##_f0 |= _FP_IMPLBIT_E;			\ 	else X##_f0&= ~(_FP_IMPLBIT_E);			\ 	_flo->bits.frac = X##_f0;				\ 	_flo->bits.exp  = X##_e;				\ 	_flo->bits.sign = X##_s;				\       }								\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_E
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     FP_UNPACK_RAW_E(X,val);		\     _FP_UNPACK_CANONICAL(E,2,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_EP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     FP_UNPACK_RAW_EP(X,val);		\     _FP_UNPACK_CANONICAL(E,2,X);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_E
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     FP_UNPACK_RAW_E(X,val);		\     _FP_UNPACK_SEMIRAW(E,2,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_UNPACK_SEMIRAW_EP
parameter_list|(
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\     FP_UNPACK_RAW_EP(X,val);		\     _FP_UNPACK_SEMIRAW(E,2,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_E
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(E,2,X);		\     FP_PACK_RAW_E(val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_EP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_CANONICAL(E,2,X);		\     FP_PACK_RAW_EP(val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_E
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(E,2,X);		\     FP_PACK_RAW_E(val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_PACK_SEMIRAW_EP
parameter_list|(
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     _FP_PACK_SEMIRAW(E,2,X);		\     FP_PACK_RAW_EP(val,X);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_ISSIGNAN_E
parameter_list|(
name|X
parameter_list|)
value|_FP_ISSIGNAN(E,2,X)
end_define

begin_define
define|#
directive|define
name|FP_NEG_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_NEG(E,2,R,X)
end_define

begin_define
define|#
directive|define
name|FP_ADD_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_ADD(E,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SUB_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_SUB(E,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_MUL_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_MUL(E,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_DIV_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_DIV(E,2,R,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_SQRT_E
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
value|_FP_SQRT(E,2,R,X)
end_define

begin_comment
comment|/*  * Square root algorithms:  * We have just one right now, maybe Newton approximation  * should be added for those machines where division is fast.  * We optimize it by doing most of the calculations  * in one UWtype registers instead of two, although we don't  * have to.  */
end_comment

begin_define
define|#
directive|define
name|_FP_SQRT_MEAT_E
parameter_list|(
name|R
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|X
parameter_list|,
name|q
parameter_list|)
define|\
value|do {							\     q = (_FP_W_TYPE)1<< (_FP_W_TYPE_SIZE - 1);		\     _FP_FRAC_SRL_2(X, (_FP_WORKBITS));			\     while (q)						\       {							\         T##_f0 = S##_f0 + q;				\         if (T##_f0<= X##_f0)				\           {						\             S##_f0 = T##_f0 + q;			\             X##_f0 -= T##_f0;				\             R##_f0 += q;				\           }						\         _FP_FRAC_SLL_1(X, 1);				\         q>>= 1;					\       }							\     _FP_FRAC_SLL_2(R, (_FP_WORKBITS));			\     if (X##_f0)						\       {							\ 	if (S##_f0< X##_f0)				\ 	  R##_f0 |= _FP_WORK_ROUND;			\ 	R##_f0 |= _FP_WORK_STICKY;			\       }							\   } while (0)
end_define

begin_define
define|#
directive|define
name|FP_CMP_E
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|un
parameter_list|)
value|_FP_CMP(E,2,r,X,Y,un)
end_define

begin_define
define|#
directive|define
name|FP_CMP_EQ_E
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_EQ(E,2,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_CMP_UNORD_E
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|_FP_CMP_UNORD(E,2,r,X,Y)
end_define

begin_define
define|#
directive|define
name|FP_TO_INT_E
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|rsz
parameter_list|,
name|rsg
parameter_list|)
value|_FP_TO_INT(E,2,r,X,rsz,rsg)
end_define

begin_define
define|#
directive|define
name|FP_FROM_INT_E
parameter_list|(
name|X
parameter_list|,
name|r
parameter_list|,
name|rs
parameter_list|,
name|rt
parameter_list|)
value|_FP_FROM_INT(E,2,X,r,rs,rt)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_E
parameter_list|(
name|X
parameter_list|)
value|(X##_f1)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_RAW_E
parameter_list|(
name|X
parameter_list|)
value|(X##_f0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _FP_W_TYPE_SIZE< 64 */
end_comment

end_unit

