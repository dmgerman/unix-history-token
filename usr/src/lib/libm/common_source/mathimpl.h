begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * All recipients should regard themselves as participants in an ongoing  * research project and hence should feel obligated to report their  * experiences (good or bad) with these elementary function codes, using  * the sendbug(8) program, to the authors.  *  *	@(#)mathimpl.h	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|const
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_comment
comment|/* Deal with different ways to concatenate in cpp */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|cat3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a ## b ## c
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cat3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a
comment|/**/
value|b
comment|/**/
value|c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Deal with vax/tahoe byte order issues */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|cat3t
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|cat3(a,b,c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cat3t
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|cat3(a,c,b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|vccast
parameter_list|(
name|name
parameter_list|)
value|(*(const double *)(cat3(name,,x)))
end_define

begin_comment
comment|/*     * Define a constant to high precision on a Vax or Tahoe.     *     * Args are the name to define, the decimal floating point value,     * four 16-bit chunks of the float value in hex     * (because the vax and tahoe differ in float format!), the power     * of 2 of the hex-float exponent, and the hex-float mantissa.     * Most of these arguments are not used at compile time; they are     * used in a post-check to make sure the constants were compiled     * correctly.     *     * People who want to use the constant will have to do their own     *     #define foo vccast(foo)     * since CPP cannot do this for them from inside another macro (sigh).     * We define "vccast" if this needs doing.     */
end_comment

begin_define
define|#
directive|define
name|vc
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|,
name|x1
parameter_list|,
name|x2
parameter_list|,
name|x3
parameter_list|,
name|x4
parameter_list|,
name|bexp
parameter_list|,
name|xval
parameter_list|)
define|\
value|const static long cat3(name,,x)[] = {cat3t(0x,x1,x2), cat3t(0x,x3,x4)};
end_define

begin_define
define|#
directive|define
name|ic
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|,
name|bexp
parameter_list|,
name|xval
parameter_list|)
value|;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* vax or tahoe */
end_comment

begin_comment
comment|/* Hooray, we have an IEEE machine */
end_comment

begin_undef
undef|#
directive|undef
name|vccast
end_undef

begin_define
define|#
directive|define
name|vc
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|,
name|x1
parameter_list|,
name|x2
parameter_list|,
name|x3
parameter_list|,
name|x4
parameter_list|,
name|bexp
parameter_list|,
name|xval
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|ic
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|,
name|bexp
parameter_list|,
name|xval
parameter_list|)
define|\
value|const static double name = value;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_comment
comment|/*  * Functions internal to the math package, yet not static.  */
end_comment

begin_function_decl
specifier|extern
name|double
name|exp__E
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|log__L
parameter_list|()
function_decl|;
end_function_decl

end_unit

