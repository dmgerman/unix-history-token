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
file|<sys/smp.h>
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
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/dkstat.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
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

begin_decl_stmt
name|int
name|boot_cpu_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * XXX: needs to move to machdep.c  *  * Initialise a struct globaldata.  */
end_comment

begin_function
name|void
name|globaldata_init
parameter_list|(
name|struct
name|globaldata
modifier|*
name|globaldata
parameter_list|,
name|int
name|cpuno
parameter_list|,
name|size_t
name|sz
parameter_list|)
block|{
name|bzero
argument_list|(
name|globaldata
argument_list|,
name|sz
argument_list|)
expr_stmt|;
name|globaldata
operator|->
name|gd_idlepcbphys
operator|=
name|vtophys
argument_list|(
operator|(
name|vm_offset_t
operator|)
operator|&
name|globaldata
operator|->
name|gd_idlepcb
argument_list|)
expr_stmt|;
name|globaldata
operator|->
name|gd_idlepcb
operator|.
name|apcb_ksp
operator|=
call|(
name|u_int64_t
call|)
argument_list|(
operator|(
name|caddr_t
operator|)
name|globaldata
operator|+
name|sz
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|trapframe
argument_list|)
argument_list|)
expr_stmt|;
name|globaldata
operator|->
name|gd_idlepcb
operator|.
name|apcb_ptbr
operator|=
name|proc0
operator|.
name|p_addr
operator|->
name|u_pcb
operator|.
name|pcb_hw
operator|.
name|apcb_ptbr
expr_stmt|;
name|globaldata
operator|->
name|gd_cpuno
operator|=
name|cpuno
expr_stmt|;
name|globaldata
operator|->
name|gd_other_cpus
operator|=
name|all_cpus
operator|&
operator|~
operator|(
literal|1
operator|<<
name|cpuno
operator|)
expr_stmt|;
name|globaldata
operator|->
name|gd_next_asn
operator|=
literal|0
expr_stmt|;
name|globaldata
operator|->
name|gd_current_asngen
operator|=
literal|1
expr_stmt|;
name|globaldata
operator|->
name|gd_cpuid
operator|=
name|cpuno
expr_stmt|;
name|globaldata_register
argument_list|(
name|globaldata
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|cpu_mp_probe
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|cpu_mp_start
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|cpu_mp_announce
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

