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
name|pcs_nhardclocks
decl_stmt|;
comment|/* IPI_HARDCLOCK counter. */
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcpu_md
block|{
name|struct
name|pcb
name|pcb
decl_stmt|;
comment|/* Used by IPI_STOP */
name|struct
name|pmap
modifier|*
name|current_pmap
decl_stmt|;
comment|/* active pmap */
name|vm_offset_t
name|vhpt
decl_stmt|;
comment|/* Address of VHPT */
name|uint64_t
name|lid
decl_stmt|;
comment|/* local CPU ID */
name|uint64_t
name|clock
decl_stmt|;
comment|/* Clock counter. */
name|uint64_t
name|clock_load
decl_stmt|;
comment|/* Clock reload value. */
name|uint32_t
name|clock_mode
decl_stmt|;
comment|/* Clock ET mode */
name|uint32_t
name|awake
range|:
literal|1
decl_stmt|;
comment|/* CPU is awake? */
name|struct
name|pcpu_stats
name|stats
decl_stmt|;
comment|/* Interrupt stats. */
name|void
modifier|*
name|xtrace_buffer
decl_stmt|;
name|uint64_t
name|xtrace_tail
decl_stmt|;
ifdef|#
directive|ifdef
name|_KERNEL
name|struct
name|sysctl_ctx_list
name|sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_tree
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
value|uint32_t	pc_acpi_id;
comment|/* ACPI CPU id. */
value|\ 	struct pcpu_md	pc_md;
comment|/* MD fields. */
value|\ 	char		__pad[10*128]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

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
specifier|volatile
name|pcpup
name|__asm__
argument_list|(
literal|"r13"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|__inline
name|__pure2
expr|struct
name|thread
operator|*
name|__curthread
argument_list|(
argument|void
argument_list|)
block|{ 	struct
name|thread
operator|*
name|td
block|;
asm|__asm("ld8.acq %0=[r13]" : "=r"(td));
return|return
operator|(
name|td
operator|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|curthread
value|(__curthread())
end_define

begin_define
define|#
directive|define
name|__pcpu_offset
parameter_list|(
name|name
parameter_list|)
value|__offsetof(struct pcpu, name)
end_define

begin_define
define|#
directive|define
name|__pcpu_type
parameter_list|(
name|name
parameter_list|)
value|__typeof(((struct pcpu *)0)->name)
end_define

begin_define
define|#
directive|define
name|PCPU_ADD
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|do {							\ 	__pcpu_type(pc_ ## name) *nmp;				\ 	critical_enter();					\ 	__asm __volatile("add %0=%1,r13;;" :			\ 	    "=r"(nmp) : "i"(__pcpu_offset(pc_ ## name)));	\ 	*nmp += val;						\ 	critical_exit();					\     } while (0)
end_define

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|name
parameter_list|)
define|\
value|({	__pcpu_type(pc_ ## name) *nmp;				\ 	__pcpu_type(pc_ ## name) res;				\ 	critical_enter();					\ 	__asm __volatile("add %0=%1,r13;;" :			\ 	    "=r"(nmp) : "i"(__pcpu_offset(pc_ ## name)));	\ 	res = *nmp;						\ 	critical_exit();					\ 	res;							\     })
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
name|name
parameter_list|)
define|\
value|({	__pcpu_type(pc_ ## name) *nmp;				\ 	__asm __volatile("add %0=%1,r13;;" :			\ 	    "=r"(nmp) : "i"(__pcpu_offset(pc_ ## name)));	\ 	nmp;							\     })
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|do {							\ 	__pcpu_type(pc_ ## name) *nmp;				\ 	critical_enter();					\ 	__asm __volatile("add %0=%1,r13;;" :			\ 	    "=r"(nmp) : "i"(__pcpu_offset(pc_ ## name)));	\ 	*nmp = val;						\ 	critical_exit();					\     } while (0)
end_define

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

