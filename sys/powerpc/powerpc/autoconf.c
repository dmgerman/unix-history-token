begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_decl_stmt
specifier|static
name|device_t
name|nexusdev
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|configure
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|SYSINIT
argument_list|(
argument|configure
argument_list|,
argument|SI_SUB_CONFIGURE
argument_list|,
argument|SI_ORDER_THIRD
argument_list|,
argument|configure
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_comment
comment|/*  * Determine i/o configuration for a machine.  */
end_comment

begin_function
specifier|static
name|void
name|configure
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|nexusdev
operator|=
name|device_add_child
argument_list|(
name|root_bus
argument_list|,
literal|"nexus"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|root_bus_configure
argument_list|()
expr_stmt|;
comment|/* 	 * Enable device interrupts 	 */
name|mtmsr
argument_list|(
name|mfmsr
argument_list|()
operator||
name|PSL_EE
operator||
name|PSL_RI
argument_list|)
expr_stmt|;
name|cold
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

