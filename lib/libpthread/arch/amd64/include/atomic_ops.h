begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Daniel Eischen<deischen@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATOMIC_OPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATOMIC_OPS_H_
end_define

begin_comment
comment|/*  * Atomic swap:  *   Atomic (tmp = *dst, *dst = val), then *res = tmp  *  * void atomic_swap_long(long *dst, long val, long *res);  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|atomic_swap_long
parameter_list|(
name|long
modifier|*
name|dst
parameter_list|,
name|long
name|val
parameter_list|,
name|long
modifier|*
name|res
parameter_list|)
block|{
asm|__asm __volatile(
literal|"xchgq %2, %1; movq %2, %0"
operator|:
literal|"=m"
operator|(
operator|*
name|res
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|dst
operator|)
operator|,
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|atomic_swap_ptr
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|r
parameter_list|)
define|\
value|atomic_swap_long((long *)(d), (long)(v), (long *)(r))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

