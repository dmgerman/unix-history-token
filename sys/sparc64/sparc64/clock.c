begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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
file|<machine/clock.h>
end_include

begin_decl_stmt
name|u_long
name|tick_increment
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|tick_freq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|tick_MHz
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|cpu_initclocks
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|DELAY
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|u_long
name|start
decl_stmt|,
name|end
decl_stmt|;
name|start
operator|=
name|rd
argument_list|(
name|tick
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|<
literal|0
condition|)
return|return;
name|end
operator|=
name|start
operator|+
operator|(
name|u_long
operator|)
name|n
operator|*
name|tick_MHz
expr_stmt|;
while|while
condition|(
name|rd
argument_list|(
name|tick
argument_list|)
operator|<
name|end
condition|)
empty_stmt|;
block|}
end_function

begin_function
name|void
name|setstatclockrate
parameter_list|(
name|int
name|newhz
parameter_list|)
block|{
name|TODO
expr_stmt|;
block|}
end_function

begin_function
name|int
name|sysbeep
parameter_list|(
name|int
name|pitch
parameter_list|,
name|int
name|period
parameter_list|)
block|{
comment|/* 	 * XXX: function exists to enable RAID drivers to compile at the moment. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

