begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_include
include|#
directive|include
file|<machine/octeon_cop2.h>
end_include

begin_decl_stmt
specifier|static
name|uma_zone_t
name|ctxzone
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|octeon_cop2_init
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Create COP2 context zone\n"
argument_list|)
expr_stmt|;
name|ctxzone
operator|=
name|uma_zcreate
argument_list|(
literal|"COP2 context"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|octeon_cop2_state
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|8
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|struct
name|octeon_cop2_state
modifier|*
name|octeon_cop2_alloc_ctx
parameter_list|()
block|{
return|return
name|uma_zalloc
argument_list|(
name|ctxzone
argument_list|,
name|M_NOWAIT
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|octeon_cop2_free_ctx
parameter_list|(
name|struct
name|octeon_cop2_state
modifier|*
name|ctx
parameter_list|)
block|{
name|uma_zfree
argument_list|(
name|ctxzone
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|octeon_cop2
argument_list|,
name|SI_SUB_CPU
argument_list|,
name|SI_ORDER_FIRST
argument_list|,
name|octeon_cop2_init
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

