begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCB_H_
end_define

begin_comment
comment|/*  * PCB: process control block  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|u_int64_t
name|pcb_r4
decl_stmt|;
name|u_int64_t
name|pcb_r5
decl_stmt|;
name|u_int64_t
name|pcb_r6
decl_stmt|;
name|u_int64_t
name|pcb_r7
decl_stmt|;
name|struct
name|ia64_fpreg
name|pcb_f2
decl_stmt|;
name|struct
name|ia64_fpreg
name|pcb_f3
decl_stmt|;
name|struct
name|ia64_fpreg
name|pcb_f4
decl_stmt|;
name|struct
name|ia64_fpreg
name|pcb_f5
decl_stmt|;
name|u_int64_t
name|pcb_b0
decl_stmt|;
comment|/* really restart address */
name|u_int64_t
name|pcb_b1
decl_stmt|;
name|u_int64_t
name|pcb_b2
decl_stmt|;
name|u_int64_t
name|pcb_b3
decl_stmt|;
name|u_int64_t
name|pcb_b4
decl_stmt|;
name|u_int64_t
name|pcb_b5
decl_stmt|;
name|u_int64_t
name|pcb_old_unat
decl_stmt|;
comment|/* caller's ar.unat */
name|u_int64_t
name|pcb_sp
decl_stmt|;
name|u_int64_t
name|pcb_pfs
decl_stmt|;
name|u_int64_t
name|pcb_bspstore
decl_stmt|;
name|u_int64_t
name|pcb_unat
decl_stmt|;
comment|/* ar.unat for r4..r7 */
name|u_int64_t
name|pcb_rnat
decl_stmt|;
name|u_int64_t
name|pcb_pr
decl_stmt|;
comment|/* predicates */
name|u_int64_t
name|pcb_pmap
decl_stmt|;
comment|/* current pmap */
name|u_int64_t
name|pcb_fsr
decl_stmt|;
name|u_int64_t
name|pcb_fcr
decl_stmt|;
name|u_int64_t
name|pcb_fir
decl_stmt|;
name|u_int64_t
name|pcb_fdr
decl_stmt|;
name|u_int64_t
name|pcb_eflag
decl_stmt|;
name|u_int64_t
name|pcb_csd
decl_stmt|;
name|u_int64_t
name|pcb_ssd
decl_stmt|;
name|u_int64_t
name|pcb_onfault
decl_stmt|;
comment|/* for copy faults */
name|u_int64_t
name|pcb_accessaddr
decl_stmt|;
comment|/* for [fs]uswintr */
name|struct
name|ia64_fpreg
name|pcb_highfp
index|[
literal|96
index|]
decl_stmt|;
comment|/* f32-f127 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The pcb is augmented with machine-dependent additional data for  * core dumps. For the Alpha, that's a trap frame.  */
end_comment

begin_struct
struct|struct
name|md_coredump
block|{
name|struct
name|trapframe
name|md_tf
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PCB_H_ */
end_comment

end_unit

