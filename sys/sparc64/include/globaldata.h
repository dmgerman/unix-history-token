begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_struct_decl
struct_decl|struct
name|lock_list_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|globaldata
block|{
name|SLIST_ENTRY
argument_list|(
argument|globaldata
argument_list|)
name|gd_allcpu
expr_stmt|;
name|struct
name|pcb
modifier|*
name|gd_curpcb
decl_stmt|;
name|struct
name|proc
modifier|*
name|gd_curproc
decl_stmt|;
name|struct
name|proc
modifier|*
name|gd_fpproc
decl_stmt|;
name|struct
name|proc
modifier|*
name|gd_idleproc
decl_stmt|;
name|u_int
name|gd_cpuid
decl_stmt|;
name|u_int
name|gd_other_cpus
decl_stmt|;
name|struct
name|lock_list_entry
modifier|*
name|gd_spinlocks
decl_stmt|;
name|struct
name|timeval
name|gd_switchtime
decl_stmt|;
name|int
name|gd_switchticks
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_GLOBALDATA_H_ */
end_comment

end_unit

