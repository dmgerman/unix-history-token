begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IPL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IPL_H_
end_define

begin_include
include|#
directive|include
file|<machine/alpha_cpu.h>
end_include

begin_comment
comment|/* IPL-lowering/restoring macros */
end_comment

begin_define
define|#
directive|define
name|splx
parameter_list|(
name|s
parameter_list|)
define|\
value|((s) == ALPHA_PSL_IPL_0 ? spl0() : alpha_pal_swpipl(s))
end_define

begin_define
define|#
directive|define
name|splsoft
parameter_list|()
value|alpha_pal_swpipl(ALPHA_PSL_IPL_SOFT)
end_define

begin_define
define|#
directive|define
name|splsoftclock
parameter_list|()
value|splsoft()
end_define

begin_define
define|#
directive|define
name|splsoftnet
parameter_list|()
value|splsoft()
end_define

begin_comment
comment|/* IPL-raising functions/macros */
end_comment

begin_decl_stmt
specifier|static
name|__inline
name|int
name|_splraise
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|int
name|_splraise
parameter_list|(
name|s
parameter_list|)
name|int
name|s
decl_stmt|;
block|{
name|int
name|cur
init|=
name|alpha_pal_rdps
argument_list|()
operator|&
name|ALPHA_PSL_IPL_MASK
decl_stmt|;
return|return
operator|(
name|s
operator|>
name|cur
condition|?
name|alpha_pal_swpipl
argument_list|(
name|s
argument_list|)
else|:
name|cur
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|splnet
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_IO)
end_define

begin_define
define|#
directive|define
name|splbio
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_IO)
end_define

begin_define
define|#
directive|define
name|splimp
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_IO)
end_define

begin_define
define|#
directive|define
name|spltty
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_IO)
end_define

begin_define
define|#
directive|define
name|splvm
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_IO)
end_define

begin_define
define|#
directive|define
name|splclock
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_CLOCK)
end_define

begin_define
define|#
directive|define
name|splstatclock
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_CLOCK)
end_define

begin_define
define|#
directive|define
name|splhigh
parameter_list|()
value|_splraise(ALPHA_PSL_IPL_HIGH)
end_define

begin_comment
comment|/*  * simulated software interrupt register  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int64_t
name|ssir
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIR_NET
value|0x1
end_define

begin_define
define|#
directive|define
name|SIR_CLOCK
value|0x2
end_define

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|ssir |= SIR_NET
end_define

begin_define
define|#
directive|define
name|setsoftclock
parameter_list|()
value|ssir |= SIR_CLOCK
end_define

begin_function_decl
specifier|extern
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX bogus */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|cpl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current priority level mask */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MD_VAR_H_ */
end_comment

end_unit

