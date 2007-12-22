begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<machine/ia64_cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<ia64/include/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<ia64/include/vmparam.h>
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
name|elf64_exec
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
name|elf64_loadfile
block|,
name|elf64_exec
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Entered with psr.ic and psr.i both zero.  */
end_comment

begin_function
name|void
name|enter_kernel
parameter_list|(
name|uint64_t
name|start
parameter_list|,
name|uint64_t
name|bi
parameter_list|)
block|{
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

begin_comment
comment|/* NOTREACHED */
end_comment

begin_function
unit|}  static
name|int
name|elf64_exec
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
name|pt_entry_t
name|pte
decl_stmt|;
name|uint64_t
name|bi_addr
decl_stmt|;
name|md
operator|=
name|file_findmetadata
argument_list|(
name|fp
argument_list|,
name|MODINFOMD_ELFHDR
argument_list|)
expr_stmt|;
if|if
condition|(
name|md
operator|==
name|NULL
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
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
name|bi_load
argument_list|(
name|fp
argument_list|,
operator|&
name|bi_addr
argument_list|)
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
name|ldr_enter
argument_list|(
name|fp
operator|->
name|f_name
argument_list|)
expr_stmt|;
asm|__asm __volatile("rsm psr.ic|psr.i;;");
asm|__asm __volatile("srlz.i;;");
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
name|pte
operator|=
name|PTE_PRESENT
operator||
name|PTE_MA_WB
operator||
name|PTE_ACCESSED
operator||
name|PTE_DIRTY
operator||
name|PTE_PL_KERN
operator||
name|PTE_AR_RWX
operator||
name|PTE_ED
expr_stmt|;
asm|__asm __volatile("mov cr.ifa=%0" :: "r"(IA64_RR_BASE(7)));
asm|__asm __volatile("mov cr.itir=%0" :: "r"(28<< 2));
asm|__asm __volatile("ptr.i %0,%1" :: "r"(IA64_RR_BASE(7)), "r"(28<<2));
asm|__asm __volatile("ptr.d %0,%1" :: "r"(IA64_RR_BASE(7)), "r"(28<<2));
asm|__asm __volatile("srlz.i;;");
asm|__asm __volatile("itr.i itr[%0]=%1;;" :: "r"(0), "r"(pte));
asm|__asm __volatile("srlz.i;;");
asm|__asm __volatile("itr.d dtr[%0]=%1;;" :: "r"(0), "r"(pte));
asm|__asm __volatile("srlz.i;;");
name|enter_kernel
argument_list|(
name|hdr
operator|->
name|e_entry
argument_list|,
name|bi_addr
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

