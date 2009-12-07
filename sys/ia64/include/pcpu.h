begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * Copyright (c) Peter Wemm<peter@netplex.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCPU_H_
end_define

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_struct
struct|struct
name|pcpu_stats
block|{
name|u_long
name|pcs_nasts
decl_stmt|;
comment|/* IPI_AST counter. */
name|u_long
name|pcs_nclks
decl_stmt|;
comment|/* Clock interrupt counter. */
name|u_long
name|pcs_nextints
decl_stmt|;
comment|/* ExtINT counter. */
name|u_long
name|pcs_nhighfps
decl_stmt|;
comment|/* IPI_HIGH_FP counter. */
name|u_long
name|pcs_nhwints
decl_stmt|;
comment|/* Hardware int. counter. */
name|u_long
name|pcs_npreempts
decl_stmt|;
comment|/* IPI_PREEMPT counter. */
name|u_long
name|pcs_nrdvs
decl_stmt|;
comment|/* IPI_RENDEZVOUS counter. */
name|u_long
name|pcs_nstops
decl_stmt|;
comment|/* IPI_STOP counter. */
name|u_long
name|pcs_nstrays
decl_stmt|;
comment|/* Stray interrupt counter. */
ifdef|#
directive|ifdef
name|_KERNEL
name|struct
name|sysctl_ctx_list
name|pcs_sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|pcs_sysctl_tree
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|struct pcb	pc_pcb;
comment|/* Used by IPI_STOP */
value|\ 	struct pmap	*pc_current_pmap;
comment|/* active pmap */
value|\ 	vm_offset_t	pc_vhpt;
comment|/* Address of VHPT */
value|\ 	uint64_t	pc_lid;
comment|/* local CPU ID */
value|\ 	uint64_t	pc_clock;
comment|/* Clock counter. */
value|\ 	uint64_t	pc_clockadj;
comment|/* Clock adjust. */
value|\ 	uint32_t	pc_awake:1;
comment|/* CPU is awake? */
value|\ 	uint32_t	pc_acpi_id;
comment|/* ACPI CPU id. */
value|\ 	struct pcpu_stats pc_stats
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|pcpu
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|register
name|struct
name|pcpu
modifier|*
name|pcpup
name|__asm__
argument_list|(
literal|"r13"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|member
parameter_list|)
value|(pcpup->pc_ ## member)
end_define

begin_comment
comment|/*  * XXX The implementation of this operation should be made atomic  * with respect to preemption.  */
end_comment

begin_define
define|#
directive|define
name|PCPU_ADD
parameter_list|(
name|member
parameter_list|,
name|value
parameter_list|)
value|(pcpup->pc_ ## member += (value))
end_define

begin_define
define|#
directive|define
name|PCPU_INC
parameter_list|(
name|member
parameter_list|)
value|PCPU_ADD(member, 1)
end_define

begin_define
define|#
directive|define
name|PCPU_PTR
parameter_list|(
name|member
parameter_list|)
value|(&pcpup->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|member
parameter_list|,
name|value
parameter_list|)
value|(pcpup->pc_ ## member = (value))
end_define

begin_function_decl
name|void
name|pcpu_initclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PCPU_H_ */
end_comment

end_unit

