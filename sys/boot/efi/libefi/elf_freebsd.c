begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: loadfile.c,v 1.10 1998/06/25 06:45:46 ross Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)boot.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<efi.h>
end_include

begin_include
include|#
directive|include
file|<efilib.h>
end_include

begin_include
include|#
directive|include
file|"bootstrap.h"
end_include

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_function_decl
specifier|static
name|int
name|elf_exec
parameter_list|(
name|struct
name|preloaded_file
modifier|*
name|amp
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|file_format
name|ia64_elf
init|=
block|{
name|elf_loadfile
block|,
name|elf_exec
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|u_int64_t
name|disable_ic
parameter_list|()
block|{
name|u_int64_t
name|psr
decl_stmt|;
asm|__asm __volatile("mov %0=psr;;" : "=r" (psr));
asm|__asm __volatile("rsm psr.ic|psr.i;; srlz.i;;");
return|return
name|psr
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|restore_ic
parameter_list|(
name|u_int64_t
name|psr
parameter_list|)
block|{
asm|__asm __volatile("mov psr.l=%0;; srlz.i" :: "r" (psr));
block|}
end_function

begin_comment
comment|/*  * Entered with psr.ic and psr.i both zero.  */
end_comment

begin_function
name|void
name|enter_kernel
parameter_list|(
name|u_int64_t
name|start
parameter_list|,
name|struct
name|bootinfo
modifier|*
name|bi
parameter_list|)
block|{
name|u_int64_t
name|psr
decl_stmt|;
asm|__asm __volatile("srlz.i;;");
asm|__asm __volatile("mov cr.ipsr=%0"
operator|::
literal|"r"
operator|(
name|IA64_PSR_IC
operator||
name|IA64_PSR_DT
operator||
name|IA64_PSR_RT
operator||
name|IA64_PSR_IT
operator||
name|IA64_PSR_BN
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("mov cr.iip=%0" :: "r"(start));
end_asm

begin_asm
asm|__asm __volatile("mov cr.ifs=r0;;");
end_asm

begin_asm
asm|__asm __volatile("mov ar.rsc=0;; flushrs;;");
end_asm

begin_asm
asm|__asm __volatile("mov r8=%0" :: "r" (bi));
end_asm

begin_asm
asm|__asm __volatile("rfi;;");
end_asm

begin_function
unit|}  static
name|int
name|elf_exec
parameter_list|(
name|struct
name|preloaded_file
modifier|*
name|fp
parameter_list|)
block|{
name|struct
name|file_metadata
modifier|*
name|md
decl_stmt|;
name|Elf_Ehdr
modifier|*
name|hdr
decl_stmt|;
name|struct
name|ia64_pte
name|pte
decl_stmt|;
name|struct
name|bootinfo
modifier|*
name|bi
decl_stmt|;
name|u_int64_t
name|psr
decl_stmt|;
name|UINTN
name|mapkey
decl_stmt|;
name|EFI_STATUS
name|status
decl_stmt|;
if|if
condition|(
operator|(
name|md
operator|=
name|file_findmetadata
argument_list|(
name|fp
argument_list|,
name|MODINFOMD_ELFHDR
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|EFTYPE
operator|)
return|;
comment|/* XXX actually EFUCKUP */
name|hdr
operator|=
operator|(
name|Elf_Ehdr
operator|*
operator|)
operator|&
operator|(
name|md
operator|->
name|md_data
operator|)
expr_stmt|;
name|printf
argument_list|(
literal|"Entering %s at 0x%lx...\n"
argument_list|,
name|fp
operator|->
name|f_name
argument_list|,
name|hdr
operator|->
name|e_entry
argument_list|)
expr_stmt|;
comment|/* 	 * Ugly hack, similar to linux. Dump the bootinfo into a 	 * special page reserved in the link map. 	 */
name|bi
operator|=
operator|(
expr|struct
name|bootinfo
operator|*
operator|)
literal|0x508000
expr_stmt|;
name|bzero
argument_list|(
name|bi
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|bootinfo
argument_list|)
argument_list|)
expr_stmt|;
name|bi_load
argument_list|(
name|bi
argument_list|,
name|fp
argument_list|,
operator|&
name|mapkey
argument_list|)
expr_stmt|;
name|status
operator|=
name|BS
operator|->
name|ExitBootServices
argument_list|(
name|IH
argument_list|,
name|mapkey
argument_list|)
expr_stmt|;
if|if
condition|(
name|EFI_ERROR
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"ExitBootServices returned 0x%lx\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return;
block|}
name|psr
operator|=
name|disable_ic
argument_list|()
expr_stmt|;
comment|/* 	 * Region 6 is direct mapped UC and region 7 is direct mapped 	 * WC. The details of this is controlled by the Alt {I,D}TLB 	 * handlers. Here we just make sure that they have the largest  	 * possible page size to minimise TLB usage. 	 */
name|ia64_set_rr
argument_list|(
name|IA64_RR_BASE
argument_list|(
literal|6
argument_list|)
argument_list|,
operator|(
literal|6
operator|<<
literal|8
operator|)
operator||
operator|(
literal|28
operator|<<
literal|2
operator|)
argument_list|)
expr_stmt|;
name|ia64_set_rr
argument_list|(
name|IA64_RR_BASE
argument_list|(
literal|7
argument_list|)
argument_list|,
operator|(
literal|7
operator|<<
literal|8
operator|)
operator||
operator|(
literal|28
operator|<<
literal|2
operator|)
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|pte
argument_list|,
sizeof|sizeof
argument_list|(
name|pte
argument_list|)
argument_list|)
expr_stmt|;
name|pte
operator|.
name|pte_p
operator|=
literal|1
expr_stmt|;
name|pte
operator|.
name|pte_ma
operator|=
name|PTE_MA_WB
expr_stmt|;
name|pte
operator|.
name|pte_a
operator|=
literal|1
expr_stmt|;
name|pte
operator|.
name|pte_d
operator|=
literal|1
expr_stmt|;
name|pte
operator|.
name|pte_pl
operator|=
name|PTE_PL_KERN
expr_stmt|;
name|pte
operator|.
name|pte_ar
operator|=
name|PTE_AR_RWX
expr_stmt|;
name|pte
operator|.
name|pte_ppn
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile("mov cr.ifa=%0" :: "r"(IA64_RR_BASE(7)));
asm|__asm __volatile("mov cr.itir=%0" :: "r"(28<< 2));
asm|__asm __volatile("ptr.i %0,%1" :: "r"(IA64_RR_BASE(7)), "r"(28<<2));
asm|__asm __volatile("ptr.d %0,%1" :: "r"(IA64_RR_BASE(7)), "r"(28<<2));
asm|__asm __volatile("srlz.i;;");
asm|__asm __volatile("itr.i itr[%0]=%1;;"
operator|::
literal|"r"
operator|(
literal|0
operator|)
operator|,
literal|"r"
operator|(
operator|*
operator|(
name|u_int64_t
operator|*
operator|)
operator|&
name|pte
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("srlz.i;;");
end_asm

begin_asm
asm|__asm __volatile("itr.d dtr[%0]=%1;;"
end_asm

begin_expr_stmt
operator|::
literal|"r"
operator|(
literal|0
operator|)
operator|,
literal|"r"
operator|(
operator|*
operator|(
name|u_int64_t
operator|*
operator|)
operator|&
name|pte
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm __volatile("srlz.i;;");
end_asm

begin_expr_stmt
name|bzero
argument_list|(
operator|&
name|pte
argument_list|,
sizeof|sizeof
argument_list|(
name|pte
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pte
operator|.
name|pte_p
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pte
operator|.
name|pte_ma
operator|=
name|PTE_MA_UC
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pte
operator|.
name|pte_a
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pte
operator|.
name|pte_d
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pte
operator|.
name|pte_pl
operator|=
name|PTE_PL_KERN
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pte
operator|.
name|pte_ar
operator|=
name|PTE_AR_RWX
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pte
operator|.
name|pte_ppn
operator|=
literal|0xffffc000000
operator|>>
literal|12
expr_stmt|;
end_expr_stmt

begin_asm
asm|__asm __volatile("mov cr.ifa=%0" :: "r"(IA64_PHYS_TO_RR6(0xffffc000000)));
end_asm

begin_asm
asm|__asm __volatile("mov cr.itir=%0" :: "r"(26<< 2));
end_asm

begin_comment
comment|//__asm __volatile("ptr.d %0,%1" :: "r"(IA64_PHYS_TO_RR6(0xffffc000000)), "r"(26<<2));
end_comment

begin_asm
asm|__asm __volatile("srlz.i;;");
end_asm

begin_asm
asm|__asm __volatile("itr.d dtr[%0]=%1;;"
end_asm

begin_expr_stmt
operator|::
literal|"r"
operator|(
literal|1
operator|)
operator|,
literal|"r"
operator|(
operator|*
operator|(
name|u_int64_t
operator|*
operator|)
operator|&
name|pte
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm __volatile("srlz.i;;");
end_asm

begin_expr_stmt
name|enter_kernel
argument_list|(
name|hdr
operator|->
name|e_entry
argument_list|,
name|bi
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|restore_ic
argument_list|(
name|psr
argument_list|)
expr_stmt|;
end_expr_stmt

unit|}
end_unit

