begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from tahoe:	in_cksum.c	1.2	86/01/05  *	from:		@(#)in_cksum.c	1.3 (Berkeley) 1/19/91  *	from: Id: in_cksum.c,v 1.8 1995/12/03 18:35:19 bde Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IN_CKSUM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IN_CKSUM_H_
value|1
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|u_short
name|in_cksum
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|in_addword
parameter_list|(
name|u_short
name|sum
parameter_list|,
name|u_short
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|in_cksum_skip
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|skip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|do_cksum
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|in_cksum_hdr
parameter_list|(
specifier|const
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|u_short
name|in_pseudo
parameter_list|(
name|u_int
name|sum
parameter_list|,
name|u_int
name|b
parameter_list|,
name|u_int
name|c
parameter_list|)
block|{
asm|__asm __volatile("adds %0, %0, %1\n"
literal|"adcs %0, %0, %2\n"
literal|"adc %0, %0, #0\n"
operator|:
literal|"+r"
operator|(
name|sum
operator|)
operator|:
literal|"r"
operator|(
name|b
operator|)
operator|,
literal|"r"
operator|(
name|c
operator|)
block|)
function|;
end_function

begin_expr_stmt
name|sum
operator|=
operator|(
name|sum
operator|&
literal|0xffff
operator|)
operator|+
operator|(
name|sum
operator|>>
literal|16
operator|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|sum
operator|>
literal|0xffff
condition|)
name|sum
operator|-=
literal|0xffff
expr_stmt|;
end_if

begin_return
return|return
operator|(
name|sum
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IN_CKSUM_H_ */
end_comment

end_unit

