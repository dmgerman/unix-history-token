begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)pcb.h	5.10 (Berkeley) 5/12/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_PCB_H_
end_define

begin_comment
comment|/*  * Intel 386 process control block  */
end_comment

begin_include
include|#
directive|include
file|<machine/npx.h>
end_include

begin_struct
struct|struct
name|pcb
block|{
name|int
name|pcb_cr3
decl_stmt|;
name|int
name|pcb_edi
decl_stmt|;
name|int
name|pcb_esi
decl_stmt|;
name|int
name|pcb_ebp
decl_stmt|;
name|int
name|pcb_esp
decl_stmt|;
name|int
name|pcb_ebx
decl_stmt|;
name|int
name|pcb_eip
decl_stmt|;
name|int
name|pcb_dr0
decl_stmt|;
name|int
name|pcb_dr1
decl_stmt|;
name|int
name|pcb_dr2
decl_stmt|;
name|int
name|pcb_dr3
decl_stmt|;
name|int
name|pcb_dr6
decl_stmt|;
name|int
name|pcb_dr7
decl_stmt|;
name|union
name|savefpu
name|pcb_save
decl_stmt|;
name|u_int
name|pcb_flags
decl_stmt|;
define|#
directive|define
name|FP_SOFTFP
value|0x01
comment|/* process using software fltng pnt emulator */
define|#
directive|define
name|PCB_DBREGS
value|0x02
comment|/* process using debug registers */
define|#
directive|define
name|PCB_NPXTRAP
value|0x04
comment|/* npx trap pending */
name|caddr_t
name|pcb_onfault
decl_stmt|;
comment|/* copyin/out fault recovery */
name|int
name|pcb_gs
decl_stmt|;
name|struct
name|pcb_ext
modifier|*
name|pcb_ext
decl_stmt|;
comment|/* optional pcb extension */
name|int
name|pcb_psl
decl_stmt|;
comment|/* process status long */
name|u_long
name|__pcb_spare
index|[
literal|2
index|]
decl_stmt|;
comment|/* adjust to avoid core dump size changes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The pcb is augmented with machine-dependent additional data for  * core dumps. For the i386: ???  */
end_comment

begin_struct
struct|struct
name|md_coredump
block|{ }
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|savectx
parameter_list|(
name|struct
name|pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_PCB_H_ */
end_comment

end_unit

