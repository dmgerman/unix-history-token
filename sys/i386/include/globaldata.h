begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) Peter Wemm<peter@netplex.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_include
include|#
directive|include
file|<machine/tss.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KTR_PERCPU
end_ifdef

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This structure maps out the global data that needs to be kept on a  * per-cpu basis.  genassym uses this to generate offsets for the assembler  * code, which also provides external symbols so that C can get at them as  * though they were really globals.  *  * The SMP parts are setup in pmap.c and locore.s for the BSP, and  * mp_machdep.c sets up the data for the AP's to "see" when they awake.  * The reason for doing it via a struct is so that an array of pointers  * to each CPU's data can be set up for things like "check curproc on all  * other processors"  */
end_comment

begin_struct
struct|struct
name|globaldata
block|{
name|struct
name|globaldata
modifier|*
name|gd_prvspace
decl_stmt|;
comment|/* self-reference */
name|struct
name|proc
modifier|*
name|gd_curproc
decl_stmt|;
name|struct
name|proc
modifier|*
name|gd_npxproc
decl_stmt|;
name|struct
name|pcb
modifier|*
name|gd_curpcb
decl_stmt|;
name|struct
name|proc
modifier|*
name|gd_idleproc
decl_stmt|;
name|struct
name|timeval
name|gd_switchtime
decl_stmt|;
name|struct
name|i386tss
name|gd_common_tss
decl_stmt|;
name|int
name|gd_switchticks
decl_stmt|;
name|struct
name|segment_descriptor
name|gd_common_tssd
decl_stmt|;
name|struct
name|segment_descriptor
modifier|*
name|gd_tss_gdt
decl_stmt|;
name|int
name|gd_currentldt
decl_stmt|;
name|u_int
name|gd_cpuid
decl_stmt|;
name|u_int
name|gd_other_cpus
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|globaldata
argument_list|)
name|gd_allcpu
expr_stmt|;
name|int
name|gd_witness_spin_check
decl_stmt|;
ifdef|#
directive|ifdef
name|KTR_PERCPU
ifdef|#
directive|ifdef
name|KTR
specifier|volatile
name|int
name|gd_ktr_idx
decl_stmt|;
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
endif|#
directive|endif
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|cpuhead
argument_list|,
name|globaldata
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

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_comment
comment|/*  * This is the upper (0xff800000) address space layout that is per-cpu.  * It is setup in locore.s and pmap.c for the BSP and in mp_machdep.c for  * each AP.  genassym helps export this to the assembler code.  */
end_comment

begin_struct
struct|struct
name|privatespace
block|{
comment|/* page 0 - data page */
name|struct
name|globaldata
name|globaldata
decl_stmt|;
name|char
name|__filler0
index|[
name|PAGE_SIZE
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|globaldata
argument_list|)
index|]
decl_stmt|;
comment|/* page 1 - idle stack (UPAGES pages) */
name|char
name|idlestack
index|[
name|UPAGES
operator|*
name|PAGE_SIZE
index|]
decl_stmt|;
comment|/* page 1+UPAGES... */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|privatespace
name|SMP_prvspace
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_GLOBALDATA_H_ */
end_comment

end_unit

