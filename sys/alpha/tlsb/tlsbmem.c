begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: tlsbmem.c,v 1.6 1998/01/12 10:21:25 thorpej Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Dummy Node for TLSB Memory Modules found on  * AlphaServer 8200 and 8400 systems.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* RCS ID& Copyright macro defns */
end_comment

begin_expr_stmt
name|__KERNEL_RCSID
argument_list|(
literal|0
argument_list|,
literal|"$NetBSD: tlsbmem.c,v 1.6 1998/01/12 10:21:25 thorpej Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<machine/autoconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<alpha/tlsb/tlsbreg.h>
end_include

begin_include
include|#
directive|include
file|<alpha/tlsb/tlsbvar.h>
end_include

begin_struct
struct|struct
name|tlsbmem_softc
block|{
name|struct
name|device
name|sc_dv
decl_stmt|;
name|int
name|sc_node
decl_stmt|;
comment|/* TLSB node */
name|u_int16_t
name|sc_dtype
decl_stmt|;
comment|/* device type */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|int
name|tlsbmemmatch
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|cfdata
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|tlsbmemattach
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|device
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cfattach
name|tlsbmem_ca
init|=
block|{
sizeof|sizeof
argument_list|(
expr|struct
name|tlsbmem_softc
argument_list|)
block|,
name|tlsbmemmatch
block|,
name|tlsbmemattach
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|tlsbmemmatch
parameter_list|(
name|parent
parameter_list|,
name|cf
parameter_list|,
name|aux
parameter_list|)
name|struct
name|device
modifier|*
name|parent
decl_stmt|;
name|struct
name|cfdata
modifier|*
name|cf
decl_stmt|;
name|void
modifier|*
name|aux
decl_stmt|;
block|{
name|struct
name|tlsb_dev_attach_args
modifier|*
name|ta
init|=
name|aux
decl_stmt|;
if|if
condition|(
name|TLDEV_ISMEM
argument_list|(
name|ta
operator|->
name|ta_dtype
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|tlsbmemattach
parameter_list|(
name|parent
parameter_list|,
name|self
parameter_list|,
name|aux
parameter_list|)
name|struct
name|device
modifier|*
name|parent
decl_stmt|;
name|struct
name|device
modifier|*
name|self
decl_stmt|;
name|void
modifier|*
name|aux
decl_stmt|;
block|{
name|struct
name|tlsb_dev_attach_args
modifier|*
name|ta
init|=
name|aux
decl_stmt|;
name|struct
name|tlsbmem_softc
modifier|*
name|sc
init|=
operator|(
expr|struct
name|tlsbmem_softc
operator|*
operator|)
name|self
decl_stmt|;
name|sc
operator|->
name|sc_node
operator|=
name|ta
operator|->
name|ta_node
expr_stmt|;
name|sc
operator|->
name|sc_dtype
operator|=
name|ta
operator|->
name|ta_dtype
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

