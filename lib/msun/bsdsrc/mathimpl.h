begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mathimpl.h	8.1 (Berkeley) 6/4/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

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
name|__exp__E
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|__log__L
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|Double
block|{
name|double
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|double
name|__exp__D
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|Double
name|__log__D
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

end_unit

