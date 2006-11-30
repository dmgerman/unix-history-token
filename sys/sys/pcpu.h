begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Wind River Systems, Inc.  * All rights reserved.  * Written by: John Baldwin<jhb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PCPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PCPU_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_error
error|#
directive|error
literal|"no assembler-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcpu.h>
end_include

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * This structure maps out the global data that needs to be kept on a  * per-cpu basis.  The members are accessed via the PCPU_GET/SET/PTR  * macros defined in<machine/pcpu.h>.  Machine dependent fields are  * defined in the PCPU_MD_FIELDS macro defined in<machine/pcpu.h>.  */
end_comment

begin_struct
struct|struct
name|pcpu
block|{
name|struct
name|thread
modifier|*
name|pc_curthread
decl_stmt|;
comment|/* Current thread */
name|struct
name|thread
modifier|*
name|pc_idlethread
decl_stmt|;
comment|/* Idle thread */
name|struct
name|thread
modifier|*
name|pc_fpcurthread
decl_stmt|;
comment|/* Fp state owner */
name|struct
name|thread
modifier|*
name|pc_deadthread
decl_stmt|;
comment|/* Zombie thread or NULL */
name|struct
name|pcb
modifier|*
name|pc_curpcb
decl_stmt|;
comment|/* Current pcb */
name|uint64_t
name|pc_switchtime
decl_stmt|;
name|int
name|pc_switchticks
decl_stmt|;
name|u_int
name|pc_cpuid
decl_stmt|;
comment|/* This cpu number */
name|cpumask_t
name|pc_cpumask
decl_stmt|;
comment|/* This cpu mask */
name|cpumask_t
name|pc_other_cpus
decl_stmt|;
comment|/* Mask of all other cpus */
name|SLIST_ENTRY
argument_list|(
argument|pcpu
argument_list|)
name|pc_allcpu
expr_stmt|;
name|struct
name|lock_list_entry
modifier|*
name|pc_spinlocks
decl_stmt|;
ifdef|#
directive|ifdef
name|KTR_PERCPU
name|int
name|pc_ktr_idx
decl_stmt|;
comment|/* Index into trace table */
name|char
modifier|*
name|pc_ktr_buf
decl_stmt|;
endif|#
directive|endif
name|PCPU_MD_FIELDS
expr_stmt|;
name|struct
name|vmmeter
name|pc_cnt
decl_stmt|;
comment|/* VM stats counters */
name|struct
name|device
modifier|*
name|pc_device
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|cpuhead
argument_list|,
name|pcpu
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cpuhead
name|cpuhead
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|curcpu
value|PCPU_GET(cpuid)
end_define

begin_define
define|#
directive|define
name|curproc
value|(curthread->td_proc)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|curthread
end_ifndef

begin_define
define|#
directive|define
name|curthread
value|PCPU_GET(curthread)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * MI PCPU support functions  *  * PCPU_LAZY_INC() -	Lazily increment a per-cpu stats counter, without  *			guarenteeing atomicity or even necessarily consistency.  *  *			XXX we need to create MD primitives to support  *			this to guarentee at least some level of consistency,  *			i.e., to prevent us from totally corrupting the   *			counters due to preemption in a multi-instruction  *			increment sequence for architectures that do not  *			support single-instruction memory increments.  */
end_comment

begin_define
define|#
directive|define
name|PCPU_LAZY_INC
parameter_list|(
name|var
parameter_list|)
value|(++*PCPU_PTR(var))
end_define

begin_comment
comment|/*  * Machine dependent callouts.  cpu_pcpu_init() is responsible for  * initializing machine dependent fields of struct pcpu, and  * db_show_mdpcpu() is responsible for handling machine dependent  * fields for the DDB 'show pcpu' command.  */
end_comment

begin_function_decl
name|void
name|cpu_pcpu_init
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_show_mdpcpu
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcpu_destroy
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcpu
modifier|*
name|pcpu_find
parameter_list|(
name|u_int
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcpu_init
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_PCPU_H_ */
end_comment

end_unit

