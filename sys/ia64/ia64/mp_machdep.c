begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
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
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<machine/globaldata.h>
end_include

begin_include
include|#
directive|include
file|<machine/pal.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_function_decl
specifier|static
name|void
name|ipi_send
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|u_int64_t
name|cpu_to_lid
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncpus
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|cpu_mp_probe
parameter_list|()
block|{
name|all_cpus
operator|=
literal|1
expr_stmt|;
comment|/* Needed for MB init code */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|cpu_mp_start
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|cpu_mp_announce
parameter_list|()
block|{ }
end_function

begin_comment
comment|/*  * send an IPI to a set of cpus.  */
end_comment

begin_function
name|void
name|ipi_selected
parameter_list|(
name|u_int
name|cpus
parameter_list|,
name|u_int64_t
name|ipi
parameter_list|)
block|{
name|u_int
name|mask
decl_stmt|;
name|int
name|cpu
decl_stmt|;
for|for
control|(
name|mask
operator|=
literal|1
operator|,
name|cpu
operator|=
literal|0
init|;
name|cpu
operator|<
name|ncpus
condition|;
name|mask
operator|<<=
literal|1
operator|,
name|cpu
operator|++
control|)
block|{
if|if
condition|(
name|cpus
operator|&
name|mask
condition|)
name|ipi_send
argument_list|(
name|cpu_to_lid
index|[
name|cpu
index|]
argument_list|,
name|ipi
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * send an IPI INTerrupt containing 'vector' to all CPUs, including myself  */
end_comment

begin_function
name|void
name|ipi_all
parameter_list|(
name|u_int64_t
name|ipi
parameter_list|)
block|{
name|int
name|cpu
decl_stmt|;
for|for
control|(
name|cpu
operator|=
literal|0
init|;
name|cpu
operator|<
name|ncpus
condition|;
name|cpu
operator|++
control|)
name|ipi_send
argument_list|(
name|cpu_to_lid
index|[
name|cpu
index|]
argument_list|,
name|ipi
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * send an IPI to all CPUs EXCEPT myself  */
end_comment

begin_function
name|void
name|ipi_all_but_self
parameter_list|(
name|u_int64_t
name|ipi
parameter_list|)
block|{
name|u_int64_t
name|lid
decl_stmt|;
name|int
name|cpu
decl_stmt|;
for|for
control|(
name|cpu
operator|=
literal|0
init|;
name|cpu
operator|<
name|ncpus
condition|;
name|cpu
operator|++
control|)
block|{
name|lid
operator|=
name|cpu_to_lid
index|[
name|cpu
index|]
expr_stmt|;
if|if
condition|(
name|lid
operator|!=
name|ia64_get_lid
argument_list|()
condition|)
name|ipi_send
argument_list|(
name|lid
argument_list|,
name|ipi
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * send an IPI to myself  */
end_comment

begin_function
name|void
name|ipi_self
parameter_list|(
name|u_int64_t
name|ipi
parameter_list|)
block|{
name|ipi_send
argument_list|(
name|ia64_get_lid
argument_list|()
argument_list|,
name|ipi
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Send an IPI to the specified processor. The lid parameter holds the  * cr.lid (CR64) contents of the target processor. Only the id and eid  * fields are used here.  */
end_comment

begin_function
specifier|static
name|void
name|ipi_send
parameter_list|(
name|u_int64_t
name|lid
parameter_list|,
name|u_int64_t
name|ipi
parameter_list|)
block|{
specifier|volatile
name|u_int64_t
modifier|*
name|pipi
decl_stmt|;
name|CTR2
argument_list|(
name|KTR_SMP
argument_list|,
name|__func__
literal|": lid=%lx, ipi=%lx"
argument_list|,
name|lid
argument_list|,
name|ipi
argument_list|)
expr_stmt|;
name|pipi
operator|=
name|ia64_memory_address
argument_list|(
name|PAL_PIB_DEFAULT_ADDR
operator||
operator|(
operator|(
name|lid
operator|>>
literal|12
operator|)
operator|&
literal|0xFFFF0L
operator|)
argument_list|)
expr_stmt|;
operator|*
name|pipi
operator|=
name|ipi
operator|&
literal|0xFF
expr_stmt|;
block|}
end_function

end_unit

