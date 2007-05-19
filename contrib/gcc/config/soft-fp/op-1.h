begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Software floating-point emulation.    Basic one-word fraction declaration and manipulation.    Copyright (C) 1997,1998,1999,2006 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Richard Henderson (rth@cygnus.com), 		  Jakub Jelinek (jj@ultra.linux.cz), 		  David S. Miller (davem@redhat.com) and 		  Peter Maydell (pmaydell@chiark.greenend.org.uk).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     In addition to the permissions in the GNU Lesser General Public    License, the Free Software Foundation gives you unlimited    permission to link the compiled version of this file into    combinations with other programs, and to distribute those    combinations without any restriction coming from the use of this    file.  (The Lesser General Public License restrictions do apply in    other respects; for example, they cover modification of the file,    and distribution when not linked into a combine executable.)     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_DECL_1
parameter_list|(
name|X
parameter_list|)
value|_FP_W_TYPE X##_f
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_COPY_1
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
value|(D##_f = S##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SET_1
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|)
value|(X##_f = I)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_1
parameter_list|(
name|X
parameter_list|)
value|(X##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_LOW_1
parameter_list|(
name|X
parameter_list|)
value|(X##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_WORD_1
parameter_list|(
name|X
parameter_list|,
name|w
parameter_list|)
value|(X##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_ADDI_1
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|)
value|(X##_f += I)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SLL_1
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
define|\
value|do {						\     if (__builtin_constant_p(N)&& (N) == 1)	\       X##_f += X##_f;				\     else					\       X##_f<<= (N);				\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SRL_1
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(X##_f>>= N)
end_define

begin_comment
comment|/* Right shift with sticky-lsb.  */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_SRST_1
parameter_list|(
name|X
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|,
name|sz
parameter_list|)
value|__FP_FRAC_SRST_1(X##_f, S, N, sz)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SRS_1
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|,
name|sz
parameter_list|)
value|__FP_FRAC_SRS_1(X##_f, N, sz)
end_define

begin_define
define|#
directive|define
name|__FP_FRAC_SRST_1
parameter_list|(
name|X
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|,
name|sz
parameter_list|)
define|\
value|do {							\   S = (__builtin_constant_p(N)&& (N) == 1		\        ? X& 1 : (X<< (_FP_W_TYPE_SIZE - (N))) != 0);	\   X = X>> (N);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|__FP_FRAC_SRS_1
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|,
name|sz
parameter_list|)
define|\
value|(X = (X>> (N) | (__builtin_constant_p(N)&& (N) == 1		\ 		     ? X& 1 : (X<< (_FP_W_TYPE_SIZE - (N))) != 0)))
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_ADD_1
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|(R##_f = X##_f + Y##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SUB_1
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|(R##_f = X##_f - Y##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_DEC_1
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|(X##_f -= Y##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_CLZ_1
parameter_list|(
name|z
parameter_list|,
name|X
parameter_list|)
value|__FP_CLZ(z, X##_f)
end_define

begin_comment
comment|/* Predicates */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_NEGP_1
parameter_list|(
name|X
parameter_list|)
value|((_FP_WS_TYPE)X##_f< 0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_ZEROP_1
parameter_list|(
name|X
parameter_list|)
value|(X##_f == 0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_OVERP_1
parameter_list|(
name|fs
parameter_list|,
name|X
parameter_list|)
value|(X##_f& _FP_OVERFLOW_##fs)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_CLEAR_OVERP_1
parameter_list|(
name|fs
parameter_list|,
name|X
parameter_list|)
value|(X##_f&= ~_FP_OVERFLOW_##fs)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_EQ_1
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|(X##_f == Y##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_GE_1
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|(X##_f>= Y##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_GT_1
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|(X##_f> Y##_f)
end_define

begin_define
define|#
directive|define
name|_FP_ZEROFRAC_1
value|0
end_define

begin_define
define|#
directive|define
name|_FP_MINFRAC_1
value|1
end_define

begin_define
define|#
directive|define
name|_FP_MAXFRAC_1
value|(~(_FP_WS_TYPE)0)
end_define

begin_comment
comment|/*  * Unpack the raw bits of a native fp value.  Do not classify or  * normalize the data.  */
end_comment

begin_define
define|#
directive|define
name|_FP_UNPACK_RAW_1
parameter_list|(
name|fs
parameter_list|,
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\     union _FP_UNION_##fs _flo; _flo.flt = (val);		\ 								\     X##_f = _flo.bits.frac;					\     X##_e = _flo.bits.exp;					\     X##_s = _flo.bits.sign;					\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_UNPACK_RAW_1_P
parameter_list|(
name|fs
parameter_list|,
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\     union _FP_UNION_##fs *_flo =				\       (union _FP_UNION_##fs *)(val);				\ 								\     X##_f = _flo->bits.frac;					\     X##_e = _flo->bits.exp;					\     X##_s = _flo->bits.sign;					\   } while (0)
end_define

begin_comment
comment|/*  * Repack the raw bits of a native fp value.  */
end_comment

begin_define
define|#
directive|define
name|_FP_PACK_RAW_1
parameter_list|(
name|fs
parameter_list|,
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {								\     union _FP_UNION_##fs _flo;					\ 								\     _flo.bits.frac = X##_f;					\     _flo.bits.exp  = X##_e;					\     _flo.bits.sign = X##_s;					\ 								\     (val) = _flo.flt;						\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_PACK_RAW_1_P
parameter_list|(
name|fs
parameter_list|,
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {								\     union _FP_UNION_##fs *_flo =				\       (union _FP_UNION_##fs *)(val);				\ 								\     _flo->bits.frac = X##_f;					\     _flo->bits.exp  = X##_e;					\     _flo->bits.sign = X##_s;					\   } while (0)
end_define

begin_comment
comment|/*  * Multiplication algorithms:  */
end_comment

begin_comment
comment|/* Basic.  Assuming the host word size is>= 2*FRACBITS, we can do the    multiplication immediately.  */
end_comment

begin_define
define|#
directive|define
name|_FP_MUL_MEAT_1_imm
parameter_list|(
name|wfracbits
parameter_list|,
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|do {									\     R##_f = X##_f * Y##_f;						\
comment|/* Normalize since we know where the msb of the multiplicands	\        were (bit B), we know that the msb of the of the product is	\        at either 2B or 2B-1.  */
value|\     _FP_FRAC_SRS_1(R, wfracbits-1, 2*wfracbits);			\   } while (0)
end_define

begin_comment
comment|/* Given a 1W * 1W => 2W primitive, do the extended multiplication.  */
end_comment

begin_define
define|#
directive|define
name|_FP_MUL_MEAT_1_wide
parameter_list|(
name|wfracbits
parameter_list|,
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|doit
parameter_list|)
define|\
value|do {									\     _FP_W_TYPE _Z_f0, _Z_f1;						\     doit(_Z_f1, _Z_f0, X##_f, Y##_f);					\
comment|/* Normalize since we know where the msb of the multiplicands	\        were (bit B), we know that the msb of the of the product is	\        at either 2B or 2B-1.  */
value|\     _FP_FRAC_SRS_2(_Z, wfracbits-1, 2*wfracbits);			\     R##_f = _Z_f0;							\   } while (0)
end_define

begin_comment
comment|/* Finally, a simple widening multiply algorithm.  What fun!  */
end_comment

begin_define
define|#
directive|define
name|_FP_MUL_MEAT_1_hard
parameter_list|(
name|wfracbits
parameter_list|,
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|do {									\     _FP_W_TYPE _xh, _xl, _yh, _yl, _z_f0, _z_f1, _a_f0, _a_f1;		\ 									\
comment|/* split the words in half */
value|\     _xh = X##_f>> (_FP_W_TYPE_SIZE/2);					\     _xl = X##_f& (((_FP_W_TYPE)1<< (_FP_W_TYPE_SIZE/2)) - 1);		\     _yh = Y##_f>> (_FP_W_TYPE_SIZE/2);					\     _yl = Y##_f& (((_FP_W_TYPE)1<< (_FP_W_TYPE_SIZE/2)) - 1);		\ 									\
comment|/* multiply the pieces */
value|\     _z_f0 = _xl * _yl;							\     _a_f0 = _xh * _yl;							\     _a_f1 = _xl * _yh;							\     _z_f1 = _xh * _yh;							\ 									\
comment|/* reassemble into two full words */
value|\     if ((_a_f0 += _a_f1)< _a_f1)					\       _z_f1 += (_FP_W_TYPE)1<< (_FP_W_TYPE_SIZE/2);			\     _a_f1 = _a_f0>> (_FP_W_TYPE_SIZE/2);				\     _a_f0 = _a_f0<< (_FP_W_TYPE_SIZE/2);				\     _FP_FRAC_ADD_2(_z, _z, _a);						\ 									\
comment|/* normalize */
value|\     _FP_FRAC_SRS_2(_z, wfracbits - 1, 2*wfracbits);			\     R##_f = _z_f0;							\   } while (0)
end_define

begin_comment
comment|/*  * Division algorithms:  */
end_comment

begin_comment
comment|/* Basic.  Assuming the host word size is>= 2*FRACBITS, we can do the    division immediately.  Give this macro either _FP_DIV_HELP_imm for    C primitives or _FP_DIV_HELP_ldiv for the ISO function.  Which you    choose will depend on what the compiler does with divrem4.  */
end_comment

begin_define
define|#
directive|define
name|_FP_DIV_MEAT_1_imm
parameter_list|(
name|fs
parameter_list|,
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|,
name|doit
parameter_list|)
define|\
value|do {							\     _FP_W_TYPE _q, _r;					\     X##_f<<= (X##_f< Y##_f				\ 	       ? R##_e--, _FP_WFRACBITS_##fs		\ 	       : _FP_WFRACBITS_##fs - 1);		\     doit(_q, _r, X##_f, Y##_f);				\     R##_f = _q | (_r != 0);				\   } while (0)
end_define

begin_comment
comment|/* GCC's longlong.h defines a 2W / 1W => (1W,1W) primitive udiv_qrnnd    that may be useful in this situation.  This first is for a primitive    that requires normalization, the second for one that does not.  Look    for UDIV_NEEDS_NORMALIZATION to tell which your machine needs.  */
end_comment

begin_define
define|#
directive|define
name|_FP_DIV_MEAT_1_udiv_norm
parameter_list|(
name|fs
parameter_list|,
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|do {									\     _FP_W_TYPE _nh, _nl, _q, _r, _y;					\ 									\
comment|/* Normalize Y -- i.e. make the most significant bit set.  */
value|\     _y = Y##_f<< _FP_WFRACXBITS_##fs;					\ 									\
comment|/* Shift X op correspondingly high, that is, up one full word.  */
value|\     if (X##_f< Y##_f)							\       {									\ 	R##_e--;							\ 	_nl = 0;							\ 	_nh = X##_f;							\       }									\     else								\       {									\ 	_nl = X##_f<< (_FP_W_TYPE_SIZE - 1);				\ 	_nh = X##_f>> 1;						\       }									\     									\     udiv_qrnnd(_q, _r, _nh, _nl, _y);					\     R##_f = _q | (_r != 0);						\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_DIV_MEAT_1_udiv
parameter_list|(
name|fs
parameter_list|,
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|do {							\     _FP_W_TYPE _nh, _nl, _q, _r;			\     if (X##_f< Y##_f)					\       {							\ 	R##_e--;					\ 	_nl = X##_f<< _FP_WFRACBITS_##fs;		\ 	_nh = X##_f>> _FP_WFRACXBITS_##fs;		\       }							\     else						\       {							\ 	_nl = X##_f<< (_FP_WFRACBITS_##fs - 1);	\ 	_nh = X##_f>> (_FP_WFRACXBITS_##fs + 1);	\       }							\     udiv_qrnnd(_q, _r, _nh, _nl, Y##_f);		\     R##_f = _q | (_r != 0);				\   } while (0)
end_define

begin_comment
comment|/*  * Square root algorithms:  * We have just one right now, maybe Newton approximation  * should be added for those machines where division is fast.  */
end_comment

begin_define
define|#
directive|define
name|_FP_SQRT_MEAT_1
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
value|do {							\     while (q != _FP_WORK_ROUND)				\       {							\         T##_f = S##_f + q;				\         if (T##_f<= X##_f)				\           {						\             S##_f = T##_f + q;				\             X##_f -= T##_f;				\             R##_f += q;					\           }						\         _FP_FRAC_SLL_1(X, 1);				\         q>>= 1;					\       }							\     if (X##_f)						\       {							\ 	if (S##_f< X##_f)				\ 	  R##_f |= _FP_WORK_ROUND;			\ 	R##_f |= _FP_WORK_STICKY;			\       }							\   } while (0)
end_define

begin_comment
comment|/*  * Assembly/disassembly for converting to/from integral types.    * No shifting or overflow handled here.  */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_ASSEMBLE_1
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|rsize
parameter_list|)
value|(r = X##_f)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_DISASSEMBLE_1
parameter_list|(
name|X
parameter_list|,
name|r
parameter_list|,
name|rsize
parameter_list|)
value|(X##_f = r)
end_define

begin_comment
comment|/*  * Convert FP values between word sizes  */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_COPY_1_1
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
value|(D##_f = S##_f)
end_define

end_unit

