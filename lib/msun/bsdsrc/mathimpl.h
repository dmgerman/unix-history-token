begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mathimpl.h	8.1 (Berkeley) 6/4/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MATHIMPL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MATHIMPL_H_
end_define

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

begin_include
include|#
directive|include
file|"../src/math_private.h"
end_include

begin_comment
comment|/*  * TRUNC() is a macro that sets the trailing 27 bits in the mantissa of an  * IEEE double variable to zero.  It must be expression-like for syntactic  * reasons, and we implement this expression using an inline function  * instead of a pure macro to avoid depending on the gcc feature of  * statement-expressions.  */
end_comment

begin_define
define|#
directive|define
name|TRUNC
parameter_list|(
name|d
parameter_list|)
value|(_b_trunc(&(d)))
end_define

begin_function
specifier|static
name|__inline
name|void
name|_b_trunc
parameter_list|(
specifier|volatile
name|double
modifier|*
name|_dp
parameter_list|)
block|{
name|uint32_t
name|_lw
decl_stmt|;
name|GET_LOW_WORD
argument_list|(
name|_lw
argument_list|,
operator|*
name|_dp
argument_list|)
expr_stmt|;
name|SET_LOW_WORD
argument_list|(
operator|*
name|_dp
argument_list|,
name|_lw
operator|&
literal|0xf8000000
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|Double
block|{
name|double
name|a
decl_stmt|;
name|double
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Functions internal to the math package, yet not static.  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MATHIMPL_H_ */
end_comment

end_unit

