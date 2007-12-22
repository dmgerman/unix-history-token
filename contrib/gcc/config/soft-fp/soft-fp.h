begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Software floating-point emulation.    Copyright (C) 1997,1998,1999,2000,2002,2003,2005,2006 	Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Richard Henderson (rth@cygnus.com), 		  Jakub Jelinek (jj@ultra.linux.cz), 		  David S. Miller (davem@redhat.com) and 		  Peter Maydell (pmaydell@chiark.greenend.org.uk).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     In addition to the permissions in the GNU Lesser General Public    License, the Free Software Foundation gives you unlimited    permission to link the compiled version of this file into    combinations with other programs, and to distribute those    combinations without any restriction coming from the use of this    file.  (The Lesser General Public License restrictions do apply in    other respects; for example, they cover modification of the file,    and distribution when not linked into a combine executable.)     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOFT_FP_H
end_ifndef

begin_define
define|#
directive|define
name|SOFT_FP_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|<sfp-machine.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"sfp-machine.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allow sfp-machine to have its own byte order definitions. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BYTE_ORDER
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"endianness not defined by sfp-machine.h"
end_error

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
name|_FP_WORKBITS
value|3
end_define

begin_define
define|#
directive|define
name|_FP_WORK_LSB
value|((_FP_W_TYPE)1<< 3)
end_define

begin_define
define|#
directive|define
name|_FP_WORK_ROUND
value|((_FP_W_TYPE)1<< 2)
end_define

begin_define
define|#
directive|define
name|_FP_WORK_GUARD
value|((_FP_W_TYPE)1<< 1)
end_define

begin_define
define|#
directive|define
name|_FP_WORK_STICKY
value|((_FP_W_TYPE)1<< 0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FP_RND_NEAREST
end_ifndef

begin_define
define|#
directive|define
name|FP_RND_NEAREST
value|0
end_define

begin_define
define|#
directive|define
name|FP_RND_ZERO
value|1
end_define

begin_define
define|#
directive|define
name|FP_RND_PINF
value|2
end_define

begin_define
define|#
directive|define
name|FP_RND_MINF
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FP_ROUNDMODE
end_ifndef

begin_define
define|#
directive|define
name|FP_ROUNDMODE
value|FP_RND_NEAREST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default don't care about exceptions. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FP_EX_INVALID
end_ifndef

begin_define
define|#
directive|define
name|FP_EX_INVALID
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FP_EX_OVERFLOW
end_ifndef

begin_define
define|#
directive|define
name|FP_EX_OVERFLOW
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FP_EX_UNDERFLOW
end_ifndef

begin_define
define|#
directive|define
name|FP_EX_UNDERFLOW
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FP_EX_DIVZERO
end_ifndef

begin_define
define|#
directive|define
name|FP_EX_DIVZERO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FP_EX_INEXACT
end_ifndef

begin_define
define|#
directive|define
name|FP_EX_INEXACT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FP_EX_DENORM
end_ifndef

begin_define
define|#
directive|define
name|FP_EX_DENORM
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_FP_DECL_EX
end_ifdef

begin_define
define|#
directive|define
name|FP_DECL_EX
define|\
value|int _fex = 0;						\   _FP_DECL_EX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FP_DECL_EX
value|int _fex = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FP_INIT_ROUNDMODE
end_ifndef

begin_define
define|#
directive|define
name|FP_INIT_ROUNDMODE
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FP_HANDLE_EXCEPTIONS
end_ifndef

begin_define
define|#
directive|define
name|FP_HANDLE_EXCEPTIONS
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FP_INHIBIT_RESULTS
end_ifndef

begin_comment
comment|/* By default we write the results always.  * sfp-machine may override this and e.g.  * check if some exceptions are unmasked  * and inhibit it in such a case.  */
end_comment

begin_define
define|#
directive|define
name|FP_INHIBIT_RESULTS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FP_SET_EXCEPTION
parameter_list|(
name|ex
parameter_list|)
define|\
value|_fex |= (ex)
end_define

begin_define
define|#
directive|define
name|FP_UNSET_EXCEPTION
parameter_list|(
name|ex
parameter_list|)
define|\
value|_fex&= ~(ex)
end_define

begin_define
define|#
directive|define
name|FP_CLEAR_EXCEPTIONS
define|\
value|_fex = 0
end_define

begin_define
define|#
directive|define
name|_FP_ROUND_NEAREST
parameter_list|(
name|wc
parameter_list|,
name|X
parameter_list|)
define|\
value|do {							\     if ((_FP_FRAC_LOW_##wc(X)& 15) != _FP_WORK_ROUND)	\       _FP_FRAC_ADDI_##wc(X, _FP_WORK_ROUND);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_ROUND_ZERO
parameter_list|(
name|wc
parameter_list|,
name|X
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|_FP_ROUND_PINF
parameter_list|(
name|wc
parameter_list|,
name|X
parameter_list|)
define|\
value|do {							\     if (!X##_s&& (_FP_FRAC_LOW_##wc(X)& 7))		\       _FP_FRAC_ADDI_##wc(X, _FP_WORK_LSB);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_ROUND_MINF
parameter_list|(
name|wc
parameter_list|,
name|X
parameter_list|)
define|\
value|do {							\     if (X##_s&& (_FP_FRAC_LOW_##wc(X)& 7))		\       _FP_FRAC_ADDI_##wc(X, _FP_WORK_LSB);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|_FP_ROUND
parameter_list|(
name|wc
parameter_list|,
name|X
parameter_list|)
define|\
value|do {						\ 	if (_FP_FRAC_LOW_##wc(X)& 7)		\ 	  FP_SET_EXCEPTION(FP_EX_INEXACT);	\ 	switch (FP_ROUNDMODE)			\ 	{					\ 	  case FP_RND_NEAREST:			\ 	    _FP_ROUND_NEAREST(wc,X);		\ 	    break;				\ 	  case FP_RND_ZERO:			\ 	    _FP_ROUND_ZERO(wc,X);		\ 	    break;				\ 	  case FP_RND_PINF:			\ 	    _FP_ROUND_PINF(wc,X);		\ 	    break;				\ 	  case FP_RND_MINF:			\ 	    _FP_ROUND_MINF(wc,X);		\ 	    break;				\ 	}					\ } while (0)
end_define

begin_define
define|#
directive|define
name|FP_CLS_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|FP_CLS_ZERO
value|1
end_define

begin_define
define|#
directive|define
name|FP_CLS_INF
value|2
end_define

begin_define
define|#
directive|define
name|FP_CLS_NAN
value|3
end_define

begin_define
define|#
directive|define
name|_FP_CLS_COMBINE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<< 2) | (y))
end_define

begin_include
include|#
directive|include
file|"op-1.h"
end_include

begin_include
include|#
directive|include
file|"op-2.h"
end_include

begin_include
include|#
directive|include
file|"op-4.h"
end_include

begin_include
include|#
directive|include
file|"op-8.h"
end_include

begin_include
include|#
directive|include
file|"op-common.h"
end_include

begin_comment
comment|/* Sigh.  Silly things longlong.h needs.  */
end_comment

begin_define
define|#
directive|define
name|UWtype
value|_FP_W_TYPE
end_define

begin_define
define|#
directive|define
name|W_TYPE_SIZE
value|_FP_W_TYPE_SIZE
end_define

begin_typedef
typedef|typedef
name|int
name|QItype
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

begin_if
if|#
directive|if
name|_FP_W_TYPE_SIZE
operator|==
literal|32
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UHWtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|HI
typedef|)));
end_typedef

begin_elif
elif|#
directive|elif
name|_FP_W_TYPE_SIZE
operator|==
literal|64
end_elif

begin_typedef
typedef|typedef
name|USItype
name|UHWtype
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SI_BITS
value|(__CHAR_BIT__ * (int)sizeof(SItype))
end_define

begin_define
define|#
directive|define
name|DI_BITS
value|(__CHAR_BIT__ * (int)sizeof(DItype))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|umul_ppmm
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|<stdlib/longlong.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"longlong.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|(
name|void
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

end_unit

