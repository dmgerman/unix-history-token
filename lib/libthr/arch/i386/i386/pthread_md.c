begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2003 David Xu<davidxu@freebsd.org>  * Copyright (c) 2001,2003 Daniel Eischen<deischen@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<rtld_tls.h>
end_include

begin_include
include|#
directive|include
file|"pthread_md.h"
end_include

begin_function
name|struct
name|tcb
modifier|*
name|_tcb_ctor
parameter_list|(
name|struct
name|pthread
modifier|*
name|thread
parameter_list|,
name|int
name|initial
parameter_list|)
block|{
name|struct
name|tcb
modifier|*
name|tcb
decl_stmt|;
if|if
condition|(
name|initial
condition|)
asm|__asm __volatile("movl %%gs:0, %0" : "=r" (tcb));
else|else
name|tcb
operator|=
name|_rtld_allocate_tls
argument_list|(
name|NULL
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tcb
argument_list|)
argument_list|,
literal|16
argument_list|)
expr_stmt|;
if|if
condition|(
name|tcb
condition|)
name|tcb
operator|->
name|tcb_thread
operator|=
name|thread
expr_stmt|;
return|return
operator|(
name|tcb
operator|)
return|;
block|}
end_function

begin_function
name|void
name|_tcb_dtor
parameter_list|(
name|struct
name|tcb
modifier|*
name|tcb
parameter_list|)
block|{
name|_rtld_free_tls
argument_list|(
name|tcb
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tcb
argument_list|)
argument_list|,
literal|16
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

