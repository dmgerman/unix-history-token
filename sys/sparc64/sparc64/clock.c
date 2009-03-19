begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sched.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_function_decl
name|void
function_decl|(
modifier|*
name|delay_func
function_decl|)
parameter_list|(
name|int
name|usec
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|u_long
name|clock_boot
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|DELAY
parameter_list|(
name|int
name|usec
parameter_list|)
block|{
call|(
modifier|*
name|delay_func
call|)
argument_list|(
name|usec
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|delay_boot
parameter_list|(
name|int
name|usec
parameter_list|)
block|{
name|u_long
name|end
decl_stmt|;
if|if
condition|(
name|usec
operator|<
literal|0
condition|)
return|return;
name|end
operator|=
name|rd
argument_list|(
name|tick
argument_list|)
operator|+
operator|(
name|u_long
operator|)
name|usec
operator|*
name|clock_boot
operator|/
literal|1000000
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
name|cpu_spinwait
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|delay_tick
parameter_list|(
name|int
name|usec
parameter_list|)
block|{
name|u_long
name|end
decl_stmt|;
if|if
condition|(
name|usec
operator|<
literal|0
condition|)
return|return;
comment|/* 	 * We avoid being migrated to another CPU with a possibly 	 * unsynchronized TICK timer while spinning. 	 */
name|sched_pin
argument_list|()
expr_stmt|;
name|end
operator|=
name|rd
argument_list|(
name|tick
argument_list|)
operator|+
operator|(
name|u_long
operator|)
name|usec
operator|*
name|PCPU_GET
argument_list|(
name|clock
argument_list|)
operator|/
literal|1000000
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
name|cpu_spinwait
argument_list|()
expr_stmt|;
name|sched_unpin
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_startprofclock
parameter_list|(
name|void
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|cpu_stopprofclock
parameter_list|(
name|void
parameter_list|)
block|{  }
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

