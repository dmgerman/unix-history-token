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
file|<machine/tss.h>
end_include

begin_include
include|#
directive|include
file|<machine/npx.h>
end_include

begin_struct
struct|struct
name|pcb
block|{
name|struct
name|i386tss
name|pcb_tss
decl_stmt|;
define|#
directive|define
name|pcb_ksp
value|pcb_tss.tss_esp0
define|#
directive|define
name|pcb_ptd
value|pcb_tss.tss_cr3
define|#
directive|define
name|pcb_cr3
value|pcb_ptd
define|#
directive|define
name|pcb_pc
value|pcb_tss.tss_eip
define|#
directive|define
name|pcb_psl
value|pcb_tss.tss_eflags
define|#
directive|define
name|pcb_usp
value|pcb_tss.tss_esp
define|#
directive|define
name|pcb_fp
value|pcb_tss.tss_ebp
ifdef|#
directive|ifdef
name|notyet
name|u_char
name|pcb_iomap
index|[
name|NPORT
operator|/
sizeof|sizeof
argument_list|(
name|u_char
argument_list|)
index|]
decl_stmt|;
comment|/* i/o port bitmap */
endif|#
directive|endif
name|caddr_t
name|pcb_ldt
decl_stmt|;
comment|/* per process (user) LDT */
name|int
name|pcb_ldt_len
decl_stmt|;
comment|/* number of LDT entries */
name|struct
name|save87
name|pcb_savefpu
decl_stmt|;
comment|/* floating point state for 287/387 */
comment|/*  * Software pcb (extension)  */
name|u_char
name|pcb_flags
decl_stmt|;
define|#
directive|define
name|FP_SOFTFP
value|0x01
comment|/* process using software fltng pnt emulator */
name|caddr_t
name|pcb_onfault
decl_stmt|;
comment|/* copyin/out fault recovery */
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
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pcb
modifier|*
name|curpcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our current running pcb */
end_comment

begin_decl_stmt
name|void
name|savectx
name|__P
argument_list|(
operator|(
expr|struct
name|pcb
operator|*
operator|)
argument_list|)
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
comment|/* _I386_PCB_H_ */
end_comment

end_unit

