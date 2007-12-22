begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 Bruce D. Evans.  * Copyright (c) 2002 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: src/sys/i386/isa/prof_machdep.c,v 1.16 2000/07/04 11:25:19  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GUPROF
end_ifdef

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
file|<sys/gmon.h>
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
file|<machine/profile.h>
end_include

begin_decl_stmt
name|int
name|cputime_bias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return the time elapsed since the last call.  The units are machine-  * dependent.  * XXX: this is not SMP-safe. It should use per-CPU variables; %tick can be  * used though.  */
end_comment

begin_function
name|int
name|cputime
parameter_list|(
name|void
parameter_list|)
block|{
name|u_long
name|count
decl_stmt|;
name|int
name|delta
decl_stmt|;
specifier|static
name|u_long
name|prev_count
decl_stmt|;
name|count
operator|=
name|rd
argument_list|(
name|tick
argument_list|)
expr_stmt|;
name|delta
operator|=
call|(
name|int
call|)
argument_list|(
name|count
operator|-
name|prev_count
argument_list|)
expr_stmt|;
name|prev_count
operator|=
name|count
expr_stmt|;
return|return
operator|(
name|delta
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * The start and stop routines need not be here since we turn off profiling  * before calling them.  They are here for convenience.  */
end_comment

begin_function
name|void
name|startguprof
parameter_list|(
name|struct
name|gmonparam
modifier|*
name|gp
parameter_list|)
block|{
name|gp
operator|->
name|profrate
operator|=
name|tick_freq
expr_stmt|;
name|cputime_bias
operator|=
literal|0
expr_stmt|;
name|cputime
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|stopguprof
parameter_list|(
name|struct
name|gmonparam
modifier|*
name|gp
parameter_list|)
block|{
comment|/* Nothing to do. */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GUPROF */
end_comment

end_unit

