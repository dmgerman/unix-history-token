begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Software floating-point emulation.    Basic eight-word fraction declaration and manipulation.    Copyright (C) 1997,1998,1999,2006 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Richard Henderson (rth@cygnus.com), 		  Jakub Jelinek (jj@ultra.linux.cz) and 		  Peter Maydell (pmaydell@chiark.greenend.org.uk).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     In addition to the permissions in the GNU Lesser General Public    License, the Free Software Foundation gives you unlimited    permission to link the compiled version of this file into    combinations with other programs, and to distribute those    combinations without any restriction coming from the use of this    file.  (The Lesser General Public License restrictions do apply in    other respects; for example, they cover modification of the file,    and distribution when not linked into a combine executable.)     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* We need just a few things from here for op-4, if we ever need some    other macros, they can be added. */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_DECL_8
parameter_list|(
name|X
parameter_list|)
value|_FP_W_TYPE X##_f[8]
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_HIGH_8
parameter_list|(
name|X
parameter_list|)
value|(X##_f[7])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_LOW_8
parameter_list|(
name|X
parameter_list|)
value|(X##_f[0])
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_WORD_8
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
name|_FP_FRAC_SLL_8
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
define|\
value|do {									\     _FP_I_TYPE _up, _down, _skip, _i;					\     _skip = (N) / _FP_W_TYPE_SIZE;					\     _up = (N) % _FP_W_TYPE_SIZE;					\     _down = _FP_W_TYPE_SIZE - _up;					\     if (!_up)								\       for (_i = 7; _i>= _skip; --_i)					\ 	X##_f[_i] = X##_f[_i-_skip];					\     else								\       {									\ 	for (_i = 7; _i> _skip; --_i)					\ 	  X##_f[_i] = X##_f[_i-_skip]<< _up				\ 		      | X##_f[_i-_skip-1]>> _down;			\ 	X##_f[_i--] = X##_f[0]<< _up; 					\       }									\     for (; _i>= 0; --_i)						\       X##_f[_i] = 0;							\   } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_FRAC_SRL_8
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
define|\
value|do {									\     _FP_I_TYPE _up, _down, _skip, _i;					\     _skip = (N) / _FP_W_TYPE_SIZE;					\     _down = (N) % _FP_W_TYPE_SIZE;					\     _up = _FP_W_TYPE_SIZE - _down;					\     if (!_down)								\       for (_i = 0; _i<= 7-_skip; ++_i)					\ 	X##_f[_i] = X##_f[_i+_skip];					\     else								\       {									\ 	for (_i = 0; _i< 7-_skip; ++_i)				\ 	  X##_f[_i] = X##_f[_i+_skip]>> _down				\ 		      | X##_f[_i+_skip+1]<< _up;			\ 	X##_f[_i++] = X##_f[7]>> _down;				\       }									\     for (; _i< 8; ++_i)						\       X##_f[_i] = 0;							\   } while (0)
end_define

begin_comment
comment|/* Right shift with sticky-lsb.   * What this actually means is that we do a standard right-shift,  * but that if any of the bits that fall off the right hand side  * were one then we always set the LSbit.  */
end_comment

begin_define
define|#
directive|define
name|_FP_FRAC_SRS_8
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|,
name|size
parameter_list|)
define|\
value|do {									\     _FP_I_TYPE _up, _down, _skip, _i;					\     _FP_W_TYPE _s;							\     _skip = (N) / _FP_W_TYPE_SIZE;					\     _down = (N) % _FP_W_TYPE_SIZE;					\     _up = _FP_W_TYPE_SIZE - _down;					\     for (_s = _i = 0; _i< _skip; ++_i)					\       _s |= X##_f[_i];							\     if (!_down)								\       for (_i = 0; _i<= 7-_skip; ++_i)					\ 	X##_f[_i] = X##_f[_i+_skip];					\     else								\       {									\ 	_s |= X##_f[_i]<< _up;						\ 	for (_i = 0; _i< 7-_skip; ++_i)				\ 	  X##_f[_i] = X##_f[_i+_skip]>> _down				\ 		      | X##_f[_i+_skip+1]<< _up;			\ 	X##_f[_i++] = X##_f[7]>> _down;				\       }									\     for (; _i< 8; ++_i)						\       X##_f[_i] = 0;							\
comment|/* don't fix the LSB until the very end when we're sure f[0] is stable */
value|\     X##_f[0] |= (_s != 0);						\   } while (0)
end_define

end_unit

