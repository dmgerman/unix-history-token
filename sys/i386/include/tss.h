begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)tss.h	5.4 (Berkeley) 1/18/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TSS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TSS_H_
value|1
end_define

begin_include
include|#
directive|include
file|<machine/globals.h>
end_include

begin_comment
comment|/*  * Intel 386 Context Data Type  */
end_comment

begin_struct
struct|struct
name|i386tss
block|{
name|int
name|tss_link
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_esp0
decl_stmt|;
comment|/* kernel stack pointer privilege level 0 */
define|#
directive|define
name|tss_ksp
value|tss_esp0
name|int
name|tss_ss0
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_esp1
decl_stmt|;
comment|/* kernel stack pointer privilege level 1 */
name|int
name|tss_ss1
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_esp2
decl_stmt|;
comment|/* kernel stack pointer privilege level 2 */
name|int
name|tss_ss2
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_cr3
decl_stmt|;
comment|/* page table directory */
define|#
directive|define
name|tss_ptd
value|tss_cr3
name|int
name|tss_eip
decl_stmt|;
comment|/* program counter */
define|#
directive|define
name|tss_pc
value|tss_eip
name|int
name|tss_eflags
decl_stmt|;
comment|/* program status longword */
define|#
directive|define
name|tss_psl
value|tss_eflags
name|int
name|tss_eax
decl_stmt|;
name|int
name|tss_ecx
decl_stmt|;
name|int
name|tss_edx
decl_stmt|;
name|int
name|tss_ebx
decl_stmt|;
name|int
name|tss_esp
decl_stmt|;
comment|/* user stack pointer */
define|#
directive|define
name|tss_usp
value|tss_esp
name|int
name|tss_ebp
decl_stmt|;
comment|/* user frame pointer */
define|#
directive|define
name|tss_fp
value|tss_ebp
name|int
name|tss_esi
decl_stmt|;
name|int
name|tss_edi
decl_stmt|;
name|int
name|tss_es
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_cs
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_ss
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_ds
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_fs
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_gs
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_ldt
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_ioopt
decl_stmt|;
comment|/* options& io offset bitmap: currently zero */
comment|/* XXX unimplemented .. i/o permission bitmap */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|common_tss
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|i386tss
name|common_tss
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_TSS_H_ */
end_comment

end_unit

