begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|__GNUC__
end_if

begin_warning
warning|#
directive|warning
literal|"this file includes<values.h> which is obsoleted, use<limits.h> or<float.h> instead"
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Copyright (C) 1988 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VALUES_H_
end_ifndef

begin_define
define|#
directive|define
name|_VALUES_H_
end_define

begin_define
define|#
directive|define
name|BITSPERBYTE
value|8
end_define

begin_define
define|#
directive|define
name|BITS
parameter_list|(
name|type
parameter_list|)
value|(BITSPERBYTE * (int)sizeof(type))
end_define

begin_define
define|#
directive|define
name|CHARBITS
value|BITS(char)
end_define

begin_define
define|#
directive|define
name|SHORTBITS
value|BITS(short)
end_define

begin_define
define|#
directive|define
name|INTBITS
value|BITS(int)
end_define

begin_define
define|#
directive|define
name|LONGBITS
value|BITS(long)
end_define

begin_define
define|#
directive|define
name|PTRBITS
value|BITS(char*)
end_define

begin_define
define|#
directive|define
name|DOUBLEBITS
value|BITS(double)
end_define

begin_define
define|#
directive|define
name|FLOATBITS
value|BITS(float)
end_define

begin_define
define|#
directive|define
name|MINSHORT
value|((short)(1<< (SHORTBITS - 1)))
end_define

begin_define
define|#
directive|define
name|MININT
value|(1<< (INTBITS - 1))
end_define

begin_define
define|#
directive|define
name|MINLONG
value|(1L<< (LONGBITS - 1))
end_define

begin_define
define|#
directive|define
name|MAXSHORT
value|((short)~MINSHORT)
end_define

begin_define
define|#
directive|define
name|MAXINT
value|(~MININT)
end_define

begin_define
define|#
directive|define
name|MAXLONG
value|(~MINLONG)
end_define

begin_define
define|#
directive|define
name|HIBITS
value|MINSHORT
end_define

begin_define
define|#
directive|define
name|HIBITL
value|MINLONG
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|hp300
argument_list|)
operator|||
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|masscomp
argument_list|)
operator|||
name|defined
argument_list|(
name|sgi
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|masscomp
end_ifdef

begin_define
define|#
directive|define
name|MAXDOUBLE
define|\
value|({									\   double maxdouble_val;							\ 									\   __asm ("fmove%.d #0x7fefffffffffffff,%0"
comment|/* Max double */
value|\ 	 : "=f" (maxdouble_val)						\ 	 :
comment|/* no inputs */
value|);						\   maxdouble_val;							\ })
end_define

begin_define
define|#
directive|define
name|MAXFLOAT
value|((float) 3.40e+38)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXDOUBLE
value|1.79769313486231470e+308
end_define

begin_define
define|#
directive|define
name|MAXFLOAT
value|((float)3.40282346638528860e+38)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MINDOUBLE
value|4.94065645841246544e-324
end_define

begin_define
define|#
directive|define
name|MINFLOAT
value|((float)1.40129846432481707e-45)
end_define

begin_define
define|#
directive|define
name|_IEEE
value|1
end_define

begin_define
define|#
directive|define
name|_DEXPLEN
value|11
end_define

begin_define
define|#
directive|define
name|_FEXPLEN
value|8
end_define

begin_define
define|#
directive|define
name|_HIDDENBIT
value|1
end_define

begin_define
define|#
directive|define
name|DMINEXP
value|(-(DMAXEXP + DSIGNIF - _HIDDENBIT - 3))
end_define

begin_define
define|#
directive|define
name|FMINEXP
value|(-(FMAXEXP + FSIGNIF - _HIDDENBIT - 3))
end_define

begin_define
define|#
directive|define
name|DMAXEXP
value|((1<< _DEXPLEN - 1) - 1 + _IEEE)
end_define

begin_define
define|#
directive|define
name|FMAXEXP
value|((1<< _FEXPLEN - 1) - 1 + _IEEE)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sony
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MAXDOUBLE
value|1.79769313486231470e+308
end_define

begin_define
define|#
directive|define
name|MAXFLOAT
value|((float)3.40282346638528860e+38)
end_define

begin_define
define|#
directive|define
name|MINDOUBLE
value|2.2250738585072010e-308
end_define

begin_define
define|#
directive|define
name|MINFLOAT
value|((float)1.17549435e-38)
end_define

begin_define
define|#
directive|define
name|_IEEE
value|1
end_define

begin_define
define|#
directive|define
name|_DEXPLEN
value|11
end_define

begin_define
define|#
directive|define
name|_FEXPLEN
value|8
end_define

begin_define
define|#
directive|define
name|_HIDDENBIT
value|1
end_define

begin_define
define|#
directive|define
name|DMINEXP
value|(-(DMAXEXP + DSIGNIF - _HIDDENBIT - 3))
end_define

begin_define
define|#
directive|define
name|FMINEXP
value|(-(FMAXEXP + FSIGNIF - _HIDDENBIT - 3))
end_define

begin_define
define|#
directive|define
name|DMAXEXP
value|((1<< _DEXPLEN - 1) - 1 + _IEEE)
end_define

begin_define
define|#
directive|define
name|FMAXEXP
value|((1<< _FEXPLEN - 1) - 1 + _IEEE)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sequent
argument_list|)
end_elif

begin_decl_stmt
specifier|extern
name|double
name|_maxdouble
decl_stmt|,
name|_mindouble
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|_maxfloat
decl_stmt|,
name|_minfloat
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAXDOUBLE
value|_maxdouble
end_define

begin_define
define|#
directive|define
name|MAXFLOAT
value|_maxfloat
end_define

begin_define
define|#
directive|define
name|MINDOUBLE
value|_mindouble
end_define

begin_define
define|#
directive|define
name|MINFLOAT
value|_minfloat
end_define

begin_define
define|#
directive|define
name|_IEEE
value|1
end_define

begin_define
define|#
directive|define
name|_DEXPLEN
value|11
end_define

begin_define
define|#
directive|define
name|_FEXPLEN
value|8
end_define

begin_define
define|#
directive|define
name|_HIDDENBIT
value|1
end_define

begin_define
define|#
directive|define
name|DMINEXP
value|(-(DMAXEXP - 3))
end_define

begin_define
define|#
directive|define
name|FMINEXP
value|(-(FMAXEXP - 3))
end_define

begin_define
define|#
directive|define
name|DMAXEXP
value|((1<< _DEXPLEN - 1) - 1 + _IEEE)
end_define

begin_define
define|#
directive|define
name|FMAXEXP
value|((1<< _FEXPLEN - 1) - 1 + _IEEE)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|i386
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MAXDOUBLE
value|1.79769313486231570e+308
end_define

begin_define
define|#
directive|define
name|MAXFLOAT
value|((float)3.40282346638528860e+38)
end_define

begin_define
define|#
directive|define
name|MINDOUBLE
value|2.22507385850720140e-308
end_define

begin_define
define|#
directive|define
name|MINFLOAT
value|((float)1.17549435082228750e-38)
end_define

begin_define
define|#
directive|define
name|_IEEE
value|0
end_define

begin_define
define|#
directive|define
name|_DEXPLEN
value|11
end_define

begin_define
define|#
directive|define
name|_FEXPLEN
value|8
end_define

begin_define
define|#
directive|define
name|_HIDDENBIT
value|1
end_define

begin_define
define|#
directive|define
name|DMINEXP
value|(-DMAXEXP)
end_define

begin_define
define|#
directive|define
name|FMINEXP
value|(-FMAXEXP)
end_define

begin_define
define|#
directive|define
name|DMAXEXP
value|((1<< _DEXPLEN - 1) - 1 + _IEEE)
end_define

begin_define
define|#
directive|define
name|FMAXEXP
value|((1<< _FEXPLEN - 1) - 1 + _IEEE)
end_define

begin_comment
comment|/* from Andrew Klossner<andrew%frip.wv.tek.com@relay.cs.net> */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|m88k
argument_list|)
end_elif

begin_comment
comment|/* These are "good" guesses ... 	   I'll figure out the true mins and maxes later, at the time I find 	   out the mins and maxes that the compiler can tokenize. */
end_comment

begin_define
define|#
directive|define
name|MAXDOUBLE
value|1.79769313486231e+308
end_define

begin_define
define|#
directive|define
name|MAXFLOAT
value|((float)3.40282346638528e+38)
end_define

begin_define
define|#
directive|define
name|MINDOUBLE
value|2.22507385850720e-308
end_define

begin_define
define|#
directive|define
name|MINFLOAT
value|((float)1.17549435082228e-38)
end_define

begin_define
define|#
directive|define
name|_IEEE
value|1
end_define

begin_define
define|#
directive|define
name|_DEXPLEN
value|11
end_define

begin_define
define|#
directive|define
name|_FEXPLEN
value|8
end_define

begin_define
define|#
directive|define
name|_HIDDENBIT
value|1
end_define

begin_define
define|#
directive|define
name|DMINEXP
value|(1-DMAXEXP)
end_define

begin_define
define|#
directive|define
name|FMINEXP
value|(1-FMAXEXP)
end_define

begin_define
define|#
directive|define
name|DMAXEXP
value|((1<< _DEXPLEN - 1) - 1 + _IEEE)
end_define

begin_define
define|#
directive|define
name|FMAXEXP
value|((1<< _FEXPLEN - 1) - 1 + _IEEE)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|convex
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MAXDOUBLE
value|8.9884656743115785e+306
end_define

begin_define
define|#
directive|define
name|MAXFLOAT
value|((float) 1.70141173e+38)
end_define

begin_define
define|#
directive|define
name|MINDOUBLE
value|5.5626846462680035e-308
end_define

begin_define
define|#
directive|define
name|MINFLOAT
value|((float) 2.93873588e-39)
end_define

begin_define
define|#
directive|define
name|_IEEE
value|0
end_define

begin_define
define|#
directive|define
name|_DEXPLEN
value|11
end_define

begin_define
define|#
directive|define
name|_FEXPLEN
value|8
end_define

begin_define
define|#
directive|define
name|_HIDDENBIT
value|1
end_define

begin_define
define|#
directive|define
name|DMINEXP
value|(-DMAXEXP)
end_define

begin_define
define|#
directive|define
name|FMINEXP
value|(-FMAXEXP)
end_define

begin_define
define|#
directive|define
name|DMAXEXP
value|((1<< _DEXPLEN - 1) - 1 + _IEEE)
end_define

begin_define
define|#
directive|define
name|FMAXEXP
value|((1<< _FEXPLEN - 1) - 1 + _IEEE)
end_define

begin_comment
comment|/* #elif defined(vax) */
end_comment

begin_comment
comment|/* use vax versions by default -- they seem to be the most conservative */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXDOUBLE
value|1.701411834604692293e+38
end_define

begin_define
define|#
directive|define
name|MINDOUBLE
value|(2.938735877055718770e-39)
end_define

begin_define
define|#
directive|define
name|MAXFLOAT
value|1.7014117331926443e+38
end_define

begin_define
define|#
directive|define
name|MINFLOAT
value|2.9387358770557188e-39
end_define

begin_define
define|#
directive|define
name|_IEEE
value|0
end_define

begin_define
define|#
directive|define
name|_DEXPLEN
value|8
end_define

begin_define
define|#
directive|define
name|_FEXPLEN
value|8
end_define

begin_define
define|#
directive|define
name|_HIDDENBIT
value|1
end_define

begin_define
define|#
directive|define
name|DMINEXP
value|(-DMAXEXP)
end_define

begin_define
define|#
directive|define
name|FMINEXP
value|(-FMAXEXP)
end_define

begin_define
define|#
directive|define
name|DMAXEXP
value|((1<< _DEXPLEN - 1) - 1 + _IEEE)
end_define

begin_define
define|#
directive|define
name|FMAXEXP
value|((1<< _FEXPLEN - 1) - 1 + _IEEE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DSIGNIF
value|(DOUBLEBITS - _DEXPLEN + _HIDDENBIT - 1)
end_define

begin_define
define|#
directive|define
name|FSIGNIF
value|(FLOATBITS  - _FEXPLEN + _HIDDENBIT - 1)
end_define

begin_define
define|#
directive|define
name|DMAXPOWTWO
value|((double)(1L<< LONGBITS -2)*(1L<< DSIGNIF - LONGBITS +1))
end_define

begin_define
define|#
directive|define
name|FMAXPOWTWO
value|((float)(1L<< FSIGNIF - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VALUES_H_ */
end_comment

end_unit

