begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/globaldata.h>
end_include

begin_include
include|#
directive|include
file|<machine/globals.h>
end_include

begin_include
include|#
directive|include
file|<machine/mutex.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
end_include

begin_include
include|#
directive|include
file|"sio.h"
end_include

begin_decl_stmt
name|unsigned
name|int
name|bio_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|cam_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|net_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|tty_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
specifier|static
name|void
name|swi_net
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|void
argument_list|(
argument|*netisrs[
literal|32
argument|]
argument_list|)
end_macro

begin_expr_stmt
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|swihand_t
modifier|*
name|shandlers
index|[
name|NSWI
index|]
init|=
block|{
comment|/* software interrupts */
name|swi_null
block|,
name|swi_net
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|softclock
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|netisr
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|swi_null
parameter_list|()
block|{
comment|/* No interrupt registered, do nothing */
block|}
end_function

begin_function
name|void
name|swi_generic
parameter_list|()
block|{
comment|/* Just a placeholder, we call swi_dispatcher directly */
name|panic
argument_list|(
literal|"swi_generic() called"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|swi_net
parameter_list|()
block|{
name|u_int32_t
name|bits
init|=
name|atomic_readandclear_32
argument_list|(
operator|&
name|netisr
argument_list|)
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|bits
operator|&
literal|1
condition|)
name|netisrs
index|[
name|i
index|]
operator|(
operator|)
expr_stmt|;
name|bits
operator|>>=
literal|1
expr_stmt|;
block|}
block|}
end_function

end_unit

