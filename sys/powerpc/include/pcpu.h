begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * Copyright (c) Peter Wemm<peter@netplex.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_GLOBALDATA_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_GLOBALDATA_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * This structure maps out the global data that needs to be kept on a  * per-cpu basis.  genassym uses this to generate offsets for the assembler  * code, which also provides external symbols so that C can get at them as  * though they were really globals. This structure is pointed to by  * the per-cpu system value (see alpha_pal_rdval() and alpha_pal_wrval()).  * Inside the kernel, the globally reserved register t7 is used to  * point at the globaldata structure.  */
end_comment

begin_struct
struct|struct
name|globaldata
block|{
name|struct
name|thread
modifier|*
name|gd_curthread
decl_stmt|;
comment|/* current thread */
name|struct
name|thread
modifier|*
name|gd_idlethread
decl_stmt|;
comment|/* idle thread */
name|struct
name|thread
modifier|*
name|gd_fpcurthread
decl_stmt|;
comment|/* fp state owner */
name|struct
name|pcb
modifier|*
name|gd_curpcb
decl_stmt|;
comment|/* current pcb */
name|struct
name|timeval
name|gd_switchtime
decl_stmt|;
name|int
name|gd_switchticks
decl_stmt|;
name|u_int
name|gd_cpuid
decl_stmt|;
comment|/* this cpu number */
name|u_int
name|gd_other_cpus
decl_stmt|;
comment|/* all other cpus */
name|int
name|gd_inside_intr
decl_stmt|;
name|u_int32_t
name|gd_next_asn
decl_stmt|;
comment|/* next ASN to allocate */
name|u_int32_t
name|gd_current_asngen
decl_stmt|;
comment|/* ASN rollover check */
name|SLIST_ENTRY
argument_list|(
argument|globaldata
argument_list|)
name|gd_allcpu
expr_stmt|;
name|struct
name|lock_list_entry
modifier|*
name|gd_spinlocks
decl_stmt|;
ifdef|#
directive|ifdef
name|KTR_PERCPU
name|int
name|gd_ktr_idx
decl_stmt|;
comment|/* Index into trace table */
name|char
modifier|*
name|gd_ktr_buf
decl_stmt|;
name|char
name|gd_ktr_buf_data
index|[
name|KTR_SIZE
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
name|void
name|globaldata_init
parameter_list|(
name|struct
name|globaldata
modifier|*
name|pcpu
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|size_t
name|sz
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
comment|/* !_MACHINE_GLOBALDATA_H_ */
end_comment

end_unit

