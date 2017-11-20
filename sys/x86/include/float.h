begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)float.h	7.1 (Berkeley) 5/8/90  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FLOAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FLOAT_H_
value|1
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|__flt_rounds
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_define
define|#
directive|define
name|FLT_RADIX
value|2
end_define

begin_comment
comment|/* b */
end_comment

begin_define
define|#
directive|define
name|FLT_ROUNDS
value|__flt_rounds()
end_define

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|FLT_EVAL_METHOD
value|0
end_define

begin_comment
comment|/* no promotions */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FLT_EVAL_METHOD
value|(-1)
end_define

begin_comment
comment|/* i387 semantics are...interesting */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DECIMAL_DIG
value|21
end_define

begin_comment
comment|/* max precision in decimal digits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FLT_MANT_DIG
value|24
end_define

begin_comment
comment|/* p */
end_comment

begin_define
define|#
directive|define
name|FLT_EPSILON
value|1.19209290E-07F
end_define

begin_comment
comment|/* b**(1-p) */
end_comment

begin_define
define|#
directive|define
name|FLT_DIG
value|6
end_define

begin_comment
comment|/* floor((p-1)*log10(b))+(b == 10) */
end_comment

begin_define
define|#
directive|define
name|FLT_MIN_EXP
value|(-125)
end_define

begin_comment
comment|/* emin */
end_comment

begin_define
define|#
directive|define
name|FLT_MIN
value|1.17549435E-38F
end_define

begin_comment
comment|/* b**(emin-1) */
end_comment

begin_define
define|#
directive|define
name|FLT_MIN_10_EXP
value|(-37)
end_define

begin_comment
comment|/* ceil(log10(b**(emin-1))) */
end_comment

begin_define
define|#
directive|define
name|FLT_MAX_EXP
value|128
end_define

begin_comment
comment|/* emax */
end_comment

begin_define
define|#
directive|define
name|FLT_MAX
value|3.40282347E+38F
end_define

begin_comment
comment|/* (1-b**(-p))*b**emax */
end_comment

begin_define
define|#
directive|define
name|FLT_MAX_10_EXP
value|38
end_define

begin_comment
comment|/* floor(log10((1-b**(-p))*b**emax)) */
end_comment

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|2011
end_if

begin_define
define|#
directive|define
name|FLT_TRUE_MIN
value|1.40129846E-45F
end_define

begin_comment
comment|/* b**(emin-p) */
end_comment

begin_define
define|#
directive|define
name|FLT_DECIMAL_DIG
value|9
end_define

begin_comment
comment|/* ceil(1+p*log10(b)) */
end_comment

begin_define
define|#
directive|define
name|FLT_HAS_SUBNORM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ISO_C_VISIBLE>= 2011 */
end_comment

begin_define
define|#
directive|define
name|DBL_MANT_DIG
value|53
end_define

begin_define
define|#
directive|define
name|DBL_EPSILON
value|2.2204460492503131E-16
end_define

begin_define
define|#
directive|define
name|DBL_DIG
value|15
end_define

begin_define
define|#
directive|define
name|DBL_MIN_EXP
value|(-1021)
end_define

begin_define
define|#
directive|define
name|DBL_MIN
value|2.2250738585072014E-308
end_define

begin_define
define|#
directive|define
name|DBL_MIN_10_EXP
value|(-307)
end_define

begin_define
define|#
directive|define
name|DBL_MAX_EXP
value|1024
end_define

begin_define
define|#
directive|define
name|DBL_MAX
value|1.7976931348623157E+308
end_define

begin_define
define|#
directive|define
name|DBL_MAX_10_EXP
value|308
end_define

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|2011
end_if

begin_define
define|#
directive|define
name|DBL_TRUE_MIN
value|4.9406564584124654E-324
end_define

begin_define
define|#
directive|define
name|DBL_DECIMAL_DIG
value|17
end_define

begin_define
define|#
directive|define
name|DBL_HAS_SUBNORM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ISO_C_VISIBLE>= 2011 */
end_comment

begin_define
define|#
directive|define
name|LDBL_MANT_DIG
value|64
end_define

begin_define
define|#
directive|define
name|LDBL_EPSILON
value|1.0842021724855044340E-19L
end_define

begin_define
define|#
directive|define
name|LDBL_DIG
value|18
end_define

begin_define
define|#
directive|define
name|LDBL_MIN_EXP
value|(-16381)
end_define

begin_define
define|#
directive|define
name|LDBL_MIN
value|3.3621031431120935063E-4932L
end_define

begin_define
define|#
directive|define
name|LDBL_MIN_10_EXP
value|(-4931)
end_define

begin_define
define|#
directive|define
name|LDBL_MAX_EXP
value|16384
end_define

begin_define
define|#
directive|define
name|LDBL_MAX
value|1.1897314953572317650E+4932L
end_define

begin_define
define|#
directive|define
name|LDBL_MAX_10_EXP
value|4932
end_define

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|2011
end_if

begin_define
define|#
directive|define
name|LDBL_TRUE_MIN
value|3.6451995318824746025E-4951L
end_define

begin_define
define|#
directive|define
name|LDBL_DECIMAL_DIG
value|21
end_define

begin_define
define|#
directive|define
name|LDBL_HAS_SUBNORM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ISO_C_VISIBLE>= 2011 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FLOAT_H_ */
end_comment

end_unit

