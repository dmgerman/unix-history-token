begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Warner Losh  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_ATOMIC_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function
specifier|static
specifier|inline
name|isc_int32_t
name|isc_atomic_xadd
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
return|return
name|atomic_fetchadd_int
argument_list|(
name|p
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|isc_atomic_store
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
name|atomic_store_rel_int
argument_list|(
name|p
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|isc_int32_t
name|isc_atomic_cmpxchg
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|cmpval
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
specifier|register
name|int
name|done
decl_stmt|,
name|ras_start
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"adr	%1, 1b\n"
literal|"mov	%0, #0xe0000004\n"
literal|"str	%1, [%0]\n"
literal|"mov	%0, #0xe0000008\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0]\n"
literal|"ldr	%1, [%2]\n"
literal|"cmp	%1, %3\n"
literal|"streq	%4, [%2]\n"
literal|"2:\n"
literal|"mov	%3, #0\n"
literal|"mov	%0, #0xe0000004\n"
literal|"str	%3, [%0]\n"
literal|"mov	%3, #0xffffffff\n"
literal|"mov	%0, #0xe0000008\n"
literal|"str	%3, [%0]\n"
operator|:
literal|"=r"
operator|(
name|ras_start
operator|)
operator|,
literal|"=r"
operator|(
name|done
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|cmpval
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|done
operator|)
return|;
end_return

begin_else
unit|}
else|#
directive|else
end_else

begin_comment
comment|/* !FreeBSD */
end_comment

begin_error
error|#
directive|error
literal|"unsupported compiler.  disable atomic ops by --disable-atomic"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_ATOMIC_H */
end_comment

end_unit

