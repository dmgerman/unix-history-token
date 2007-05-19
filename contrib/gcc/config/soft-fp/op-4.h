begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Software floating-point emulation.    Basic four-word fraction declaration and manipulation.    Copyright (C) 1997,1998,1999,2006 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Richard Henderson (rth@cygnus.com), 		  Jakub Jelinek (jj@ultra.linux.cz), 		  David S. Miller (davem@redhat.com) and 		  Peter Maydell (pmaydell@chiark.greenend.org.uk).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     In addition to the permissions in the GNU Lesser General Public    License, the Free Software Foundation gives you unlimited    permission to link the compiled version of this file into    combinations with other programs, and to distribute those    combinations without any restriction coming from the use of this    file.  (The Lesser General Public License restrictions do apply in    other respects; for example, they cover modification of the file,    and distribution when not linked into a combine executable.)     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_DECL_4
parameter_list|(
name|X
parameter_list|)
value|_FP_W_TYPE X##_f[4]
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_COPY_4
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
define|\
value|(D##_f[0] = S##_f[0], D##_f[1] = S##_f[1],	\    D##_f[2] = S##_f[2], D##_f[3] = S##_f[3])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SET_4
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|)
value|__FP_FRAC_SET_4(X, I)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_4
parameter_list|(
name|X
parameter_list|)
value|(X##_f[3])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_LOW_4
parameter_list|(
name|X
parameter_list|)
value|(X##_f[0])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_WORD_4
parameter_list|(
name|X
parameter_list|,
name|w
parameter_list|)
value|(X##_f[w])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SLL_4
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
define|\
value|do {									\     _FP_I_TYPE _up, _down, _skip, _i;					\     _skip = (N) / _FP_W_TYPE_SIZE;					\     _up = (N) % _FP_W_TYPE_SIZE;					\     _down = _FP_W_TYPE_SIZE - _up;					\     if (!_up)								\       for (_i = 3; _i>= _skip; --_i)					\ 	X##_f[_i] = X##_f[_i-_skip];					\     else								\       {									\ 	for (_i = 3; _i> _skip; --_i)					\ 	  X##_f[_i] = X##_f[_i-_skip]<< _up				\ 		      | X##_f[_i-_skip-1]>> _down;			\ 	X##_f[_i--] = X##_f[0]<< _up; 					\       }									\     for (; _i>= 0; --_i)						\       X##_f[_i] = 0;							\   } while (0)
end_define

begin_comment
comment|/* This one was broken too */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_SRL_4
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
define|\
value|do {									\     _FP_I_TYPE _up, _down, _skip, _i;					\     _skip = (N) / _FP_W_TYPE_SIZE;					\     _down = (N) % _FP_W_TYPE_SIZE;					\     _up = _FP_W_TYPE_SIZE - _down;					\     if (!_down)								\       for (_i = 0; _i<= 3-_skip; ++_i)					\ 	X##_f[_i] = X##_f[_i+_skip];					\     else								\       {									\ 	for (_i = 0; _i< 3-_skip; ++_i)				\ 	  X##_f[_i] = X##_f[_i+_skip]>> _down				\ 		      | X##_f[_i+_skip+1]<< _up;			\ 	X##_f[_i++] = X##_f[3]>> _down;				\       }									\     for (; _i< 4; ++_i)						\       X##_f[_i] = 0;							\   } while (0)
end_define

begin_comment
comment|/* Right shift with sticky-lsb.   * What this actually means is that we do a standard right-shift,  * but that if any of the bits that fall off the right hand side  * were one then we always set the LSbit.  */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_SRST_4
parameter_list|(
name|X
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|,
name|size
parameter_list|)
define|\
value|do {							\     _FP_I_TYPE _up, _down, _skip, _i;			\     _FP_W_TYPE _s;					\     _skip = (N) / _FP_W_TYPE_SIZE;			\     _down = (N) % _FP_W_TYPE_SIZE;			\     _up = _FP_W_TYPE_SIZE - _down;			\     for (_s = _i = 0; _i< _skip; ++_i)			\       _s |= X##_f[_i];					\     if (!_down)						\       for (_i = 0; _i<= 3-_skip; ++_i)			\ 	X##_f[_i] = X##_f[_i+_skip];			\     else						\       {							\ 	_s |= X##_f[_i]<< _up;				\ 	for (_i = 0; _i< 3-_skip; ++_i)		\ 	  X##_f[_i] = X##_f[_i+_skip]>> _down		\ 		      | X##_f[_i+_skip+1]<< _up;	\ 	X##_f[_i++] = X##_f[3]>> _down;		\       }							\     for (; _i< 4; ++_i)				\       X##_f[_i] = 0;					\     S = (_s != 0);					\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SRS_4
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|,
name|size
parameter_list|)
define|\
value|do {						\     int _sticky;				\     _FP_FRAC_SRST_4(X, _sticky, N, size);	\     X##_f[0] |= _sticky;			\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_ADD_4
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|__FP_FRAC_ADD_4(R##_f[3], R##_f[2], R##_f[1], R##_f[0],		\ 		  X##_f[3], X##_f[2], X##_f[1], X##_f[0],		\ 		  Y##_f[3], Y##_f[2], Y##_f[1], Y##_f[0])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SUB_4
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|__FP_FRAC_SUB_4(R##_f[3], R##_f[2], R##_f[1], R##_f[0],		\ 		  X##_f[3], X##_f[2], X##_f[1], X##_f[0],		\ 		  Y##_f[3], Y##_f[2], Y##_f[1], Y##_f[0])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_DEC_4
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|__FP_FRAC_DEC_4(X##_f[3], X##_f[2], X##_f[1], X##_f[0],		\ 		  Y##_f[3], Y##_f[2], Y##_f[1], Y##_f[0])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_ADDI_4
parameter_list|(
name|X
parameter_list|,
name|I
parameter_list|)
define|\
value|__FP_FRAC_ADDI_4(X##_f[3], X##_f[2], X##_f[1], X##_f[0], I)
end_define

begin_define
define|#
directive|define
name|_FP_ZEROFRAC_4
value|0,0,0,0
end_define

begin_define
define|#
directive|define
name|_FP_MINFRAC_4
value|0,0,0,1
end_define

begin_define
define|#
directive|define
name|_FP_MAXFRAC_4
value|(~(_FP_WS_TYPE)0), (~(_FP_WS_TYPE)0), (~(_FP_WS_TYPE)0), (~(_FP_WS_TYPE)0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_ZEROP_4
parameter_list|(
name|X
parameter_list|)
value|((X##_f[0] | X##_f[1] | X##_f[2] | X##_f[3]) == 0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_NEGP_4
parameter_list|(
name|X
parameter_list|)
value|((_FP_WS_TYPE)X##_f[3]< 0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_OVERP_4
parameter_list|(
name|fs
parameter_list|,
name|X
parameter_list|)
value|(_FP_FRAC_HIGH_##fs(X)& _FP_OVERFLOW_##fs)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_CLEAR_OVERP_4
parameter_list|(
name|fs
parameter_list|,
name|X
parameter_list|)
value|(_FP_FRAC_HIGH_##fs(X)&= ~_FP_OVERFLOW_##fs)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_EQ_4
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|(X##_f[0] == Y##_f[0]&& X##_f[1] == Y##_f[1]		\&& X##_f[2] == Y##_f[2]&& X##_f[3] == Y##_f[3])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_GT_4
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|(X##_f[3]> Y##_f[3] ||				\   (X##_f[3] == Y##_f[3]&& (X##_f[2]> Y##_f[2] ||	\    (X##_f[2] == Y##_f[2]&& (X##_f[1]> Y##_f[1] ||	\     (X##_f[1] == Y##_f[1]&& X##_f[0]> Y##_f[0])	\    ))							\   ))							\  )
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_GE_4
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|(X##_f[3]> Y##_f[3] ||				\   (X##_f[3] == Y##_f[3]&& (X##_f[2]> Y##_f[2] ||	\    (X##_f[2] == Y##_f[2]&& (X##_f[1]> Y##_f[1] ||	\     (X##_f[1] == Y##_f[1]&& X##_f[0]>= Y##_f[0])	\    ))							\   ))							\  )
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_CLZ_4
parameter_list|(
name|R
parameter_list|,
name|X
parameter_list|)
define|\
value|do {					\     if (X##_f[3])			\     {					\ 	__FP_CLZ(R,X##_f[3]);		\     }					\     else if (X##_f[2])			\     {					\ 	__FP_CLZ(R,X##_f[2]);		\ 	R += _FP_W_TYPE_SIZE;		\     }					\     else if (X##_f[1])			\     {					\ 	__FP_CLZ(R,X##_f[1]);		\ 	R += _FP_W_TYPE_SIZE*2;		\     }					\     else				\     {					\ 	__FP_CLZ(R,X##_f[0]);		\ 	R += _FP_W_TYPE_SIZE*3;		\     }					\   } while(0)
end_define

begin_define
define|#
directive|define
name|_FP_UNPACK_RAW_4
parameter_list|(
name|fs
parameter_list|,
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\     union _FP_UNION_##fs _flo; _flo.flt = (val);		\     X##_f[0] = _flo.bits.frac0;					\     X##_f[1] = _flo.bits.frac1;					\     X##_f[2] = _flo.bits.frac2;					\     X##_f[3] = _flo.bits.frac3;					\     X##_e  = _flo.bits.exp;					\     X##_s  = _flo.bits.sign;					\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_UNPACK_RAW_4_P
parameter_list|(
name|fs
parameter_list|,
name|X
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\     union _FP_UNION_##fs *_flo =				\       (union _FP_UNION_##fs *)(val);				\ 								\     X##_f[0] = _flo->bits.frac0;				\     X##_f[1] = _flo->bits.frac1;				\     X##_f[2] = _flo->bits.frac2;				\     X##_f[3] = _flo->bits.frac3;				\     X##_e  = _flo->bits.exp;					\     X##_s  = _flo->bits.sign;					\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_PACK_RAW_4
parameter_list|(
name|fs
parameter_list|,
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {								\     union _FP_UNION_##fs _flo;					\     _flo.bits.frac0 = X##_f[0];					\     _flo.bits.frac1 = X##_f[1];					\     _flo.bits.frac2 = X##_f[2];					\     _flo.bits.frac3 = X##_f[3];					\     _flo.bits.exp   = X##_e;					\     _flo.bits.sign  = X##_s;					\     (val) = _flo.flt;				   		\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_PACK_RAW_4_P
parameter_list|(
name|fs
parameter_list|,
name|val
parameter_list|,
name|X
parameter_list|)
define|\
value|do {								\     union _FP_UNION_##fs *_flo =				\       (union _FP_UNION_##fs *)(val);				\ 								\     _flo->bits.frac0 = X##_f[0];				\     _flo->bits.frac1 = X##_f[1];				\     _flo->bits.frac2 = X##_f[2];				\     _flo->bits.frac3 = X##_f[3];				\     _flo->bits.exp   = X##_e;					\     _flo->bits.sign  = X##_s;					\   } while (0)
end_define

begin_comment
comment|/*  * Multiplication algorithms:  */
end_comment

begin_comment
comment|/* Given a 1W * 1W => 2W primitive, do the extended multiplication.  */
end_comment

begin_define
define|#
directive|define
name|_FP_MUL_MEAT_4_wide
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
value|do {									    \     _FP_FRAC_DECL_8(_z); _FP_FRAC_DECL_2(_b); _FP_FRAC_DECL_2(_c);	    \     _FP_FRAC_DECL_2(_d); _FP_FRAC_DECL_2(_e); _FP_FRAC_DECL_2(_f);	    \ 									    \     doit(_FP_FRAC_WORD_8(_z,1), _FP_FRAC_WORD_8(_z,0), X##_f[0], Y##_f[0]); \     doit(_b_f1, _b_f0, X##_f[0], Y##_f[1]);				    \     doit(_c_f1, _c_f0, X##_f[1], Y##_f[0]);				    \     doit(_d_f1, _d_f0, X##_f[1], Y##_f[1]);				    \     doit(_e_f1, _e_f0, X##_f[0], Y##_f[2]);				    \     doit(_f_f1, _f_f0, X##_f[2], Y##_f[0]);				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,3),_FP_FRAC_WORD_8(_z,2),	    \ 		    _FP_FRAC_WORD_8(_z,1), 0,_b_f1,_b_f0,		    \ 		    0,0,_FP_FRAC_WORD_8(_z,1));				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,3),_FP_FRAC_WORD_8(_z,2),	    \ 		    _FP_FRAC_WORD_8(_z,1), 0,_c_f1,_c_f0,		    \ 		    _FP_FRAC_WORD_8(_z,3),_FP_FRAC_WORD_8(_z,2),	    \ 		    _FP_FRAC_WORD_8(_z,1));				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,4),_FP_FRAC_WORD_8(_z,3),	    \ 		    _FP_FRAC_WORD_8(_z,2), 0,_d_f1,_d_f0,		    \ 		    0,_FP_FRAC_WORD_8(_z,3),_FP_FRAC_WORD_8(_z,2));	    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,4),_FP_FRAC_WORD_8(_z,3),	    \ 		    _FP_FRAC_WORD_8(_z,2), 0,_e_f1,_e_f0,		    \ 		    _FP_FRAC_WORD_8(_z,4),_FP_FRAC_WORD_8(_z,3),	    \ 		    _FP_FRAC_WORD_8(_z,2));				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,4),_FP_FRAC_WORD_8(_z,3),	    \ 		    _FP_FRAC_WORD_8(_z,2), 0,_f_f1,_f_f0,		    \ 		    _FP_FRAC_WORD_8(_z,4),_FP_FRAC_WORD_8(_z,3),	    \ 		    _FP_FRAC_WORD_8(_z,2));				    \     doit(_b_f1, _b_f0, X##_f[0], Y##_f[3]);				    \     doit(_c_f1, _c_f0, X##_f[3], Y##_f[0]);				    \     doit(_d_f1, _d_f0, X##_f[1], Y##_f[2]);				    \     doit(_e_f1, _e_f0, X##_f[2], Y##_f[1]);				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,5),_FP_FRAC_WORD_8(_z,4),	    \ 		    _FP_FRAC_WORD_8(_z,3), 0,_b_f1,_b_f0,		    \ 		    0,_FP_FRAC_WORD_8(_z,4),_FP_FRAC_WORD_8(_z,3));	    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,5),_FP_FRAC_WORD_8(_z,4),	    \ 		    _FP_FRAC_WORD_8(_z,3), 0,_c_f1,_c_f0,		    \ 		    _FP_FRAC_WORD_8(_z,5),_FP_FRAC_WORD_8(_z,4),	    \ 		    _FP_FRAC_WORD_8(_z,3));				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,5),_FP_FRAC_WORD_8(_z,4),	    \ 		    _FP_FRAC_WORD_8(_z,3), 0,_d_f1,_d_f0,		    \ 		    _FP_FRAC_WORD_8(_z,5),_FP_FRAC_WORD_8(_z,4),	    \ 		    _FP_FRAC_WORD_8(_z,3));				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,5),_FP_FRAC_WORD_8(_z,4),	    \ 		    _FP_FRAC_WORD_8(_z,3), 0,_e_f1,_e_f0,		    \ 		    _FP_FRAC_WORD_8(_z,5),_FP_FRAC_WORD_8(_z,4),	    \ 		    _FP_FRAC_WORD_8(_z,3));				    \     doit(_b_f1, _b_f0, X##_f[2], Y##_f[2]);				    \     doit(_c_f1, _c_f0, X##_f[1], Y##_f[3]);				    \     doit(_d_f1, _d_f0, X##_f[3], Y##_f[1]);				    \     doit(_e_f1, _e_f0, X##_f[2], Y##_f[3]);				    \     doit(_f_f1, _f_f0, X##_f[3], Y##_f[2]);				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,6),_FP_FRAC_WORD_8(_z,5),	    \ 		    _FP_FRAC_WORD_8(_z,4), 0,_b_f1,_b_f0,		    \ 		    0,_FP_FRAC_WORD_8(_z,5),_FP_FRAC_WORD_8(_z,4));	    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,6),_FP_FRAC_WORD_8(_z,5),	    \ 		    _FP_FRAC_WORD_8(_z,4), 0,_c_f1,_c_f0,		    \ 		    _FP_FRAC_WORD_8(_z,6),_FP_FRAC_WORD_8(_z,5),	    \ 		    _FP_FRAC_WORD_8(_z,4));				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,6),_FP_FRAC_WORD_8(_z,5),	    \ 		    _FP_FRAC_WORD_8(_z,4), 0,_d_f1,_d_f0,		    \ 		    _FP_FRAC_WORD_8(_z,6),_FP_FRAC_WORD_8(_z,5),	    \ 		    _FP_FRAC_WORD_8(_z,4));				    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,7),_FP_FRAC_WORD_8(_z,6),	    \ 		    _FP_FRAC_WORD_8(_z,5), 0,_e_f1,_e_f0,		    \ 		    0,_FP_FRAC_WORD_8(_z,6),_FP_FRAC_WORD_8(_z,5));	    \     __FP_FRAC_ADD_3(_FP_FRAC_WORD_8(_z,7),_FP_FRAC_WORD_8(_z,6),	    \ 		    _FP_FRAC_WORD_8(_z,5), 0,_f_f1,_f_f0,		    \ 		    _FP_FRAC_WORD_8(_z,7),_FP_FRAC_WORD_8(_z,6),	    \ 		    _FP_FRAC_WORD_8(_z,5));				    \     doit(_b_f1, _b_f0, X##_f[3], Y##_f[3]);				    \     __FP_FRAC_ADD_2(_FP_FRAC_WORD_8(_z,7),_FP_FRAC_WORD_8(_z,6),	    \ 		    _b_f1,_b_f0,					    \ 		    _FP_FRAC_WORD_8(_z,7),_FP_FRAC_WORD_8(_z,6));	    \ 									    \
comment|/* Normalize since we know where the msb of the multiplicands	    \        were (bit B), we know that the msb of the of the product is	    \        at either 2B or 2B-1.  */
value|\     _FP_FRAC_SRS_8(_z, wfracbits-1, 2*wfracbits);			    \     __FP_FRAC_SET_4(R, _FP_FRAC_WORD_8(_z,3), _FP_FRAC_WORD_8(_z,2),	    \ 		    _FP_FRAC_WORD_8(_z,1), _FP_FRAC_WORD_8(_z,0));	    \   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_MUL_MEAT_4_gmp
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
value|do {									    \     _FP_FRAC_DECL_8(_z);						    \ 									    \     mpn_mul_n(_z_f, _x_f, _y_f, 4);					    \ 									    \
comment|/* Normalize since we know where the msb of the multiplicands	    \        were (bit B), we know that the msb of the of the product is	    \        at either 2B or 2B-1.  */
value|\     _FP_FRAC_SRS_8(_z, wfracbits-1, 2*wfracbits);	 		    \     __FP_FRAC_SET_4(R, _FP_FRAC_WORD_8(_z,3), _FP_FRAC_WORD_8(_z,2),	    \ 		    _FP_FRAC_WORD_8(_z,1), _FP_FRAC_WORD_8(_z,0));	    \   } while (0)
end_define

begin_comment
comment|/*  * Helper utility for _FP_DIV_MEAT_4_udiv:  * pppp = m * nnn  */
end_comment

begin_define
define|#
directive|define
name|umul_ppppmnnn
parameter_list|(
name|p3
parameter_list|,
name|p2
parameter_list|,
name|p1
parameter_list|,
name|p0
parameter_list|,
name|m
parameter_list|,
name|n2
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|)
define|\
value|do {									    \     UWtype _t;								    \     umul_ppmm(p1,p0,m,n0);						    \     umul_ppmm(p2,_t,m,n1);						    \     __FP_FRAC_ADDI_2(p2,p1,_t);						    \     umul_ppmm(p3,_t,m,n2);						    \     __FP_FRAC_ADDI_2(p3,p2,_t);						    \   } while (0)
end_define

begin_comment
comment|/*  * Division algorithms:  */
end_comment

begin_define
define|#
directive|define
name|_FP_DIV_MEAT_4_udiv
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
value|do {									    \     int _i;								    \     _FP_FRAC_DECL_4(_n); _FP_FRAC_DECL_4(_m);				    \     _FP_FRAC_SET_4(_n, _FP_ZEROFRAC_4);					    \     if (_FP_FRAC_GT_4(X, Y))						    \       {									    \ 	_n_f[3] = X##_f[0]<< (_FP_W_TYPE_SIZE - 1);			    \ 	_FP_FRAC_SRL_4(X, 1);						    \       }									    \     else								    \       R##_e--;								    \ 									    \
comment|/* Normalize, i.e. make the most significant bit of the 		    \        denominator set. */
value|\     _FP_FRAC_SLL_4(Y, _FP_WFRACXBITS_##fs);				    \ 									    \     for (_i = 3; ; _i--)						    \       {									    \         if (X##_f[3] == Y##_f[3])					    \           {								    \
comment|/* This is a special case, not an optimization		    \                (X##_f[3]/Y##_f[3] would not fit into UWtype).		    \                As X## is guaranteed to be< Y,  R##_f[_i] can be either	    \                (UWtype)-1 or (UWtype)-2.  */
value|\             R##_f[_i] = -1;						    \             if (!_i)							    \ 	      break;							    \             __FP_FRAC_SUB_4(X##_f[3], X##_f[2], X##_f[1], X##_f[0],	    \ 			    Y##_f[2], Y##_f[1], Y##_f[0], 0,		    \ 			    X##_f[2], X##_f[1], X##_f[0], _n_f[_i]);	    \             _FP_FRAC_SUB_4(X, Y, X);					    \             if (X##_f[3]> Y##_f[3])					    \               {								    \                 R##_f[_i] = -2;						    \                 _FP_FRAC_ADD_4(X, Y, X);				    \               }								    \           }								    \         else								    \           {								    \             udiv_qrnnd(R##_f[_i], X##_f[3], X##_f[3], X##_f[2], Y##_f[3]);  \             umul_ppppmnnn(_m_f[3], _m_f[2], _m_f[1], _m_f[0],		    \ 			  R##_f[_i], Y##_f[2], Y##_f[1], Y##_f[0]);	    \             X##_f[2] = X##_f[1];					    \             X##_f[1] = X##_f[0];					    \             X##_f[0] = _n_f[_i];					    \             if (_FP_FRAC_GT_4(_m, X))					    \               {								    \                 R##_f[_i]--;						    \                 _FP_FRAC_ADD_4(X, Y, X);				    \                 if (_FP_FRAC_GE_4(X, Y)&& _FP_FRAC_GT_4(_m, X))	    \                   {							    \ 		    R##_f[_i]--;					    \ 		    _FP_FRAC_ADD_4(X, Y, X);				    \                   }							    \               }								    \             _FP_FRAC_DEC_4(X, _m);					    \             if (!_i)							    \ 	      {								    \ 		if (!_FP_FRAC_EQ_4(X, _m))				    \ 		  R##_f[0] |= _FP_WORK_STICKY;				    \ 		break;							    \ 	      }								    \           }								    \       }									    \   } while (0)
end_define

begin_comment
comment|/*  * Square root algorithms:  * We have just one right now, maybe Newton approximation  * should be added for those machines where division is fast.  */
end_comment

begin_define
define|#
directive|define
name|_FP_SQRT_MEAT_4
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
value|do {								\     while (q)							\       {								\ 	T##_f[3] = S##_f[3] + q;				\ 	if (T##_f[3]<= X##_f[3])				\ 	  {							\ 	    S##_f[3] = T##_f[3] + q;				\ 	    X##_f[3] -= T##_f[3];				\ 	    R##_f[3] += q;					\ 	  }							\ 	_FP_FRAC_SLL_4(X, 1);					\ 	q>>= 1;						\       }								\     q = (_FP_W_TYPE)1<< (_FP_W_TYPE_SIZE - 1);			\     while (q)							\       {								\ 	T##_f[2] = S##_f[2] + q;				\ 	T##_f[3] = S##_f[3];					\ 	if (T##_f[3]< X##_f[3] || 				\ 	    (T##_f[3] == X##_f[3]&& T##_f[2]<= X##_f[2]))	\ 	  {							\ 	    S##_f[2] = T##_f[2] + q;				\ 	    S##_f[3] += (T##_f[2]> S##_f[2]);			\ 	    __FP_FRAC_DEC_2(X##_f[3], X##_f[2],			\ 			    T##_f[3], T##_f[2]);		\ 	    R##_f[2] += q;					\ 	  }							\ 	_FP_FRAC_SLL_4(X, 1);					\ 	q>>= 1;						\       }								\     q = (_FP_W_TYPE)1<< (_FP_W_TYPE_SIZE - 1);			\     while (q)							\       {								\ 	T##_f[1] = S##_f[1] + q;				\ 	T##_f[2] = S##_f[2];					\ 	T##_f[3] = S##_f[3];					\ 	if (T##_f[3]< X##_f[3] || 				\ 	    (T##_f[3] == X##_f[3]&& (T##_f[2]< X##_f[2] ||	\ 	     (T##_f[2] == X##_f[2]&& T##_f[1]<= X##_f[1]))))	\ 	  {							\ 	    S##_f[1] = T##_f[1] + q;				\ 	    S##_f[2] += (T##_f[1]> S##_f[1]);			\ 	    S##_f[3] += (T##_f[2]> S##_f[2]);			\ 	    __FP_FRAC_DEC_3(X##_f[3], X##_f[2], X##_f[1],	\ 	    		    T##_f[3], T##_f[2], T##_f[1]);	\ 	    R##_f[1] += q;					\ 	  }							\ 	_FP_FRAC_SLL_4(X, 1);					\ 	q>>= 1;						\       }								\     q = (_FP_W_TYPE)1<< (_FP_W_TYPE_SIZE - 1);			\     while (q != _FP_WORK_ROUND)					\       {								\ 	T##_f[0] = S##_f[0] + q;				\ 	T##_f[1] = S##_f[1];					\ 	T##_f[2] = S##_f[2];					\ 	T##_f[3] = S##_f[3];					\ 	if (_FP_FRAC_GE_4(X,T))					\ 	  {							\ 	    S##_f[0] = T##_f[0] + q;				\ 	    S##_f[1] += (T##_f[0]> S##_f[0]);			\ 	    S##_f[2] += (T##_f[1]> S##_f[1]);			\ 	    S##_f[3] += (T##_f[2]> S##_f[2]);			\ 	    _FP_FRAC_DEC_4(X, T);				\ 	    R##_f[0] += q;					\ 	  }							\ 	_FP_FRAC_SLL_4(X, 1);					\ 	q>>= 1;						\       }								\     if (!_FP_FRAC_ZEROP_4(X))					\       {								\ 	if (_FP_FRAC_GT_4(X,S))					\ 	  R##_f[0] |= _FP_WORK_ROUND;				\ 	R##_f[0] |= _FP_WORK_STICKY;				\       }								\   } while (0)
end_define

begin_comment
comment|/*  * Internals   */
end_comment

begin_define
define|#
directive|define
name|__FP_FRAC_SET_4
parameter_list|(
name|X
parameter_list|,
name|I3
parameter_list|,
name|I2
parameter_list|,
name|I1
parameter_list|,
name|I0
parameter_list|)
define|\
value|(X##_f[3] = I3, X##_f[2] = I2, X##_f[1] = I1, X##_f[0] = I0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__FP_FRAC_ADD_3
end_ifndef

begin_define
define|#
directive|define
name|__FP_FRAC_ADD_3
parameter_list|(
name|r2
parameter_list|,
name|r1
parameter_list|,
name|r0
parameter_list|,
name|x2
parameter_list|,
name|x1
parameter_list|,
name|x0
parameter_list|,
name|y2
parameter_list|,
name|y1
parameter_list|,
name|y0
parameter_list|)
define|\
value|do {								\     _FP_W_TYPE _c1, _c2;					\     r0 = x0 + y0;						\     _c1 = r0< x0;						\     r1 = x1 + y1;						\     _c2 = r1< x1;						\     r1 += _c1;							\     _c2 |= r1< _c1;						\     r2 = x2 + y2 + _c2;						\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FP_FRAC_ADD_4
end_ifndef

begin_define
define|#
directive|define
name|__FP_FRAC_ADD_4
parameter_list|(
name|r3
parameter_list|,
name|r2
parameter_list|,
name|r1
parameter_list|,
name|r0
parameter_list|,
name|x3
parameter_list|,
name|x2
parameter_list|,
name|x1
parameter_list|,
name|x0
parameter_list|,
name|y3
parameter_list|,
name|y2
parameter_list|,
name|y1
parameter_list|,
name|y0
parameter_list|)
define|\
value|do {								\     _FP_W_TYPE _c1, _c2, _c3;					\     r0 = x0 + y0;						\     _c1 = r0< x0;						\     r1 = x1 + y1;						\     _c2 = r1< x1;						\     r1 += _c1;							\     _c2 |= r1< _c1;						\     r2 = x2 + y2;						\     _c3 = r2< x2;						\     r2 += _c2;							\     _c3 |= r2< _c2;						\     r3 = x3 + y3 + _c3;						\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FP_FRAC_SUB_3
end_ifndef

begin_define
define|#
directive|define
name|__FP_FRAC_SUB_3
parameter_list|(
name|r2
parameter_list|,
name|r1
parameter_list|,
name|r0
parameter_list|,
name|x2
parameter_list|,
name|x1
parameter_list|,
name|x0
parameter_list|,
name|y2
parameter_list|,
name|y1
parameter_list|,
name|y0
parameter_list|)
define|\
value|do {								\     _FP_W_TYPE _c1, _c2;					\     r0 = x0 - y0;						\     _c1 = r0> x0;						\     r1 = x1 - y1;						\     _c2 = r1> x1;						\     r1 -= _c1;							\     _c2 |= _c1&& (y1 == x1);					\     r2 = x2 - y2 - _c2;						\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FP_FRAC_SUB_4
end_ifndef

begin_define
define|#
directive|define
name|__FP_FRAC_SUB_4
parameter_list|(
name|r3
parameter_list|,
name|r2
parameter_list|,
name|r1
parameter_list|,
name|r0
parameter_list|,
name|x3
parameter_list|,
name|x2
parameter_list|,
name|x1
parameter_list|,
name|x0
parameter_list|,
name|y3
parameter_list|,
name|y2
parameter_list|,
name|y1
parameter_list|,
name|y0
parameter_list|)
define|\
value|do {								\     _FP_W_TYPE _c1, _c2, _c3;					\     r0 = x0 - y0;						\     _c1 = r0> x0;						\     r1 = x1 - y1;						\     _c2 = r1> x1;						\     r1 -= _c1;							\     _c2 |= _c1&& (y1 == x1);					\     r2 = x2 - y2;						\     _c3 = r2> x2;						\     r2 -= _c2;							\     _c3 |= _c2&& (y2 == x2);					\     r3 = x3 - y3 - _c3;						\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FP_FRAC_DEC_3
end_ifndef

begin_define
define|#
directive|define
name|__FP_FRAC_DEC_3
parameter_list|(
name|x2
parameter_list|,
name|x1
parameter_list|,
name|x0
parameter_list|,
name|y2
parameter_list|,
name|y1
parameter_list|,
name|y0
parameter_list|)
define|\
value|do {									\     UWtype _t0, _t1, _t2;						\     _t0 = x0, _t1 = x1, _t2 = x2;					\     __FP_FRAC_SUB_3 (x2, x1, x0, _t2, _t1, _t0, y2, y1, y0);		\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FP_FRAC_DEC_4
end_ifndef

begin_define
define|#
directive|define
name|__FP_FRAC_DEC_4
parameter_list|(
name|x3
parameter_list|,
name|x2
parameter_list|,
name|x1
parameter_list|,
name|x0
parameter_list|,
name|y3
parameter_list|,
name|y2
parameter_list|,
name|y1
parameter_list|,
name|y0
parameter_list|)
define|\
value|do {									\     UWtype _t0, _t1, _t2, _t3;						\     _t0 = x0, _t1 = x1, _t2 = x2, _t3 = x3;				\     __FP_FRAC_SUB_4 (x3,x2,x1,x0,_t3,_t2,_t1,_t0, y3,y2,y1,y0);		\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__FP_FRAC_ADDI_4
end_ifndef

begin_define
define|#
directive|define
name|__FP_FRAC_ADDI_4
parameter_list|(
name|x3
parameter_list|,
name|x2
parameter_list|,
name|x1
parameter_list|,
name|x0
parameter_list|,
name|i
parameter_list|)
define|\
value|do {									\     UWtype _t;								\     _t = ((x0 += i)< i);						\     x1 += _t; _t = (x1< _t);						\     x2 += _t; _t = (x2< _t);						\     x3 += _t;								\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Convert FP values between word sizes. This appears to be more  * complicated than I'd have expected it to be, so these might be  * wrong... These macros are in any case somewhat bogus because they  * use information about what various FRAC_n variables look like   * internally [eg, that 2 word vars are X_f0 and x_f1]. But so do  * the ones in op-2.h and op-1.h.   */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_COPY_1_4
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
value|(D##_f = S##_f[0])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_COPY_2_4
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
define|\
value|do {						\   D##_f0 = S##_f[0];				\   D##_f1 = S##_f[1];				\ } while (0)
end_define

begin_comment
comment|/* Assembly/disassembly for converting to/from integral types.    * No shifting or overflow handled here.  */
end_comment

begin_comment
comment|/* Put the FP value X into r, which is an integer of size rsize. */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_ASSEMBLE_4
parameter_list|(
name|r
parameter_list|,
name|X
parameter_list|,
name|rsize
parameter_list|)
define|\
value|do {									\     if (rsize<= _FP_W_TYPE_SIZE)					\       r = X##_f[0];							\     else if (rsize<= 2*_FP_W_TYPE_SIZE)				\     {									\       r = X##_f[1];							\       r<<= _FP_W_TYPE_SIZE;						\       r += X##_f[0];							\     }									\     else								\     {									\
comment|/* I'm feeling lazy so we deal with int == 3words (implausible)*/
value|\
comment|/* and int == 4words as a single case.			 */
value|\       r = X##_f[3];							\       r<<= _FP_W_TYPE_SIZE;						\       r += X##_f[2];							\       r<<= _FP_W_TYPE_SIZE;						\       r += X##_f[1];							\       r<<= _FP_W_TYPE_SIZE;						\       r += X##_f[0];							\     }									\   } while (0)
end_define

begin_comment
comment|/* "No disassemble Number Five!" */
end_comment

begin_comment
comment|/* move an integer of size rsize into X's fractional part. We rely on  * the _f[] array consisting of words of size _FP_W_TYPE_SIZE to avoid  * having to mask the values we store into it.  */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_DISASSEMBLE_4
parameter_list|(
name|X
parameter_list|,
name|r
parameter_list|,
name|rsize
parameter_list|)
define|\
value|do {									\     X##_f[0] = r;							\     X##_f[1] = (rsize<= _FP_W_TYPE_SIZE ? 0 : r>> _FP_W_TYPE_SIZE);	\     X##_f[2] = (rsize<= 2*_FP_W_TYPE_SIZE ? 0 : r>> 2*_FP_W_TYPE_SIZE); \     X##_f[3] = (rsize<= 3*_FP_W_TYPE_SIZE ? 0 : r>> 3*_FP_W_TYPE_SIZE); \   } while (0);
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_COPY_4_1
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
define|\
value|do {						\   D##_f[0] = S##_f;				\   D##_f[1] = D##_f[2] = D##_f[3] = 0;		\ } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_COPY_4_2
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|)
define|\
value|do {						\   D##_f[0] = S##_f0;				\   D##_f[1] = S##_f1;				\   D##_f[2] = D##_f[3] = 0;			\ } while (0)
end_define

end_unit

