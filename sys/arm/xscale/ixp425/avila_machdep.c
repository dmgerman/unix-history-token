begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: hpc_machdep.c,v 1.70 2003/09/16 08:18:22 agc Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994-1998 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * machdep.c  *  * Machine dependant functions for kernel setup  *  * This file needs a lot of work.   *  * Created      : 17/09/94  */
end_comment

begin_include
include|#
directive|include
file|"opt_msgbuf.h"
end_include

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

begin_define
define|#
directive|define
name|_ARM32_BUS_DMA_PRIVATE
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/imgact.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/msgbuf.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_pager.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<vm/vnode_pager.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/undefined.h>
end_include

begin_include
include|#
directive|include
file|<machine/machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/metadata.h>
end_include

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425var.h>
end_include

begin_comment
comment|/* kernel text starts where we were loaded at boot */
end_comment

begin_define
define|#
directive|define
name|KERNEL_TEXT_OFF
value|(KERNPHYSADDR  - PHYSADDR)
end_define

begin_define
define|#
directive|define
name|KERNEL_TEXT_BASE
value|(KERNBASE + KERNEL_TEXT_OFF)
end_define

begin_define
define|#
directive|define
name|KERNEL_TEXT_PHYS
value|(PHYSADDR + KERNEL_TEXT_OFF)
end_define

begin_define
define|#
directive|define
name|KERNEL_PT_SYS
value|0
end_define

begin_comment
comment|/* Page table for mapping proc0 zero page */
end_comment

begin_define
define|#
directive|define
name|KERNEL_PT_IO
value|1
end_define

begin_define
define|#
directive|define
name|KERNEL_PT_IO_NUM
value|3
end_define

begin_define
define|#
directive|define
name|KERNEL_PT_BEFOREKERN
value|KERNEL_PT_IO + KERNEL_PT_IO_NUM
end_define

begin_define
define|#
directive|define
name|KERNEL_PT_AFKERNEL
value|KERNEL_PT_BEFOREKERN + 1
end_define

begin_comment
comment|/* L2 table for mapping after kernel */
end_comment

begin_define
define|#
directive|define
name|KERNEL_PT_AFKERNEL_NUM
value|9
end_define

begin_comment
comment|/* this should be evenly divisable by PAGE_SIZE / L2_TABLE_SIZE_REAL (or 4) */
end_comment

begin_define
define|#
directive|define
name|NUM_KERNEL_PTS
value|(KERNEL_PT_AFKERNEL + KERNEL_PT_AFKERNEL_NUM)
end_define

begin_comment
comment|/* Define various stack sizes in pages */
end_comment

begin_define
define|#
directive|define
name|IRQ_STACK_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|ABT_STACK_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|UND_STACK_SIZE
value|1
end_define

begin_decl_stmt
specifier|extern
name|u_int
name|data_abort_handler_address
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|prefetch_abort_handler_address
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|undefined_handler_address
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pv_addr
name|kernel_pt_table
index|[
name|NUM_KERNEL_PTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pcpu
name|__pcpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pcpu
modifier|*
name|pcpup
init|=
operator|&
name|__pcpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Physical and virtual addresses for some global pages */
end_comment

begin_decl_stmt
name|vm_paddr_t
name|phys_avail
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_paddr_t
name|dump_avail
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|physical_pages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pv_addr
name|systempage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pv_addr
name|msgbufpv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pv_addr
name|irqstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pv_addr
name|undstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pv_addr
name|abtstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pv_addr
name|kernelstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pv_addr
name|minidataclean
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|trapframe
name|proc0_tf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Static device mappings. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|pmap_devmap
name|ixp425_devmap
index|[]
init|=
block|{
comment|/* Physical/Virtual address for I/O space */
block|{
name|IXP425_IO_VBASE
block|,
name|IXP425_IO_HWBASE
block|,
name|IXP425_IO_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* Expansion Bus */
block|{
name|IXP425_EXP_VBASE
block|,
name|IXP425_EXP_HWBASE
block|,
name|IXP425_EXP_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* IXP425 PCI Configuration */
block|{
name|IXP425_PCI_VBASE
block|,
name|IXP425_PCI_HWBASE
block|,
name|IXP425_PCI_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* SDRAM Controller */
block|{
name|IXP425_MCU_VBASE
block|,
name|IXP425_MCU_HWBASE
block|,
name|IXP425_MCU_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* PCI Memory Space */
block|{
name|IXP425_PCI_MEM_VBASE
block|,
name|IXP425_PCI_MEM_HWBASE
block|,
name|IXP425_PCI_MEM_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* Q-Mgr Memory Space */
block|{
name|IXP425_QMGR_VBASE
block|,
name|IXP425_QMGR_HWBASE
block|,
name|IXP425_QMGR_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* NPE-A Memory Space */
block|{
name|IXP425_NPE_A_VBASE
block|,
name|IXP425_NPE_A_HWBASE
block|,
name|IXP425_NPE_A_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* NPE-B Memory Space */
block|{
name|IXP425_NPE_B_VBASE
block|,
name|IXP425_NPE_B_HWBASE
block|,
name|IXP425_NPE_B_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* NPE-C Memory Space */
block|{
name|IXP425_NPE_C_VBASE
block|,
name|IXP425_NPE_C_HWBASE
block|,
name|IXP425_NPE_C_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* MAC-B Memory Space */
block|{
name|IXP425_MAC_B_VBASE
block|,
name|IXP425_MAC_B_HWBASE
block|,
name|IXP425_MAC_B_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* MAC-C Memory Space */
block|{
name|IXP425_MAC_C_VBASE
block|,
name|IXP425_MAC_C_HWBASE
block|,
name|IXP425_MAC_C_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
block|{
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Static device mappings. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|pmap_devmap
name|ixp435_devmap
index|[]
init|=
block|{
comment|/* Physical/Virtual address for I/O space */
block|{
name|IXP425_IO_VBASE
block|,
name|IXP425_IO_HWBASE
block|,
name|IXP425_IO_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* Expansion Bus */
block|{
name|IXP425_EXP_VBASE
block|,
name|IXP425_EXP_HWBASE
block|,
name|IXP425_EXP_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* IXP425 PCI Configuration */
block|{
name|IXP425_PCI_VBASE
block|,
name|IXP425_PCI_HWBASE
block|,
name|IXP425_PCI_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* DDRII Controller NB: mapped same place as IXP425 */
block|{
name|IXP425_MCU_VBASE
block|,
name|IXP435_MCU_HWBASE
block|,
name|IXP425_MCU_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* PCI Memory Space */
block|{
name|IXP425_PCI_MEM_VBASE
block|,
name|IXP425_PCI_MEM_HWBASE
block|,
name|IXP425_PCI_MEM_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* Q-Mgr Memory Space */
block|{
name|IXP425_QMGR_VBASE
block|,
name|IXP425_QMGR_HWBASE
block|,
name|IXP425_QMGR_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* NPE-A Memory Space */
block|{
name|IXP425_NPE_A_VBASE
block|,
name|IXP425_NPE_A_HWBASE
block|,
name|IXP425_NPE_A_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* NPE-C Memory Space */
block|{
name|IXP425_NPE_C_VBASE
block|,
name|IXP425_NPE_C_HWBASE
block|,
name|IXP425_NPE_C_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* MAC-C Memory Space */
block|{
name|IXP425_MAC_C_VBASE
block|,
name|IXP425_MAC_C_HWBASE
block|,
name|IXP425_MAC_C_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* MAC-B Memory Space */
block|{
name|IXP425_MAC_B_VBASE
block|,
name|IXP425_MAC_B_HWBASE
block|,
name|IXP425_MAC_B_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* MAC-A Memory Space */
block|{
name|IXP435_MAC_A_VBASE
block|,
name|IXP435_MAC_A_HWBASE
block|,
name|IXP435_MAC_A_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* USB1 Memory Space */
block|{
name|IXP435_USB1_VBASE
block|,
name|IXP435_USB1_HWBASE
block|,
name|IXP435_USB1_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
comment|/* USB2 Memory Space */
block|{
name|IXP435_USB2_VBASE
block|,
name|IXP435_USB2_HWBASE
block|,
name|IXP435_USB2_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, }
block|,
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|xscale_cache_clean_addr
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|initarm
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
name|arg2
parameter_list|)
block|{
define|#
directive|define
name|next_chunk2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a) + (b))&~ ((b)-1))
define|#
directive|define
name|next_page
parameter_list|(
name|a
parameter_list|)
value|next_chunk2(a,PAGE_SIZE)
name|struct
name|pv_addr
name|kernel_l1pt
decl_stmt|;
name|int
name|loop
decl_stmt|,
name|i
decl_stmt|;
name|u_int
name|l1pagetable
decl_stmt|;
name|vm_offset_t
name|freemempos
decl_stmt|;
name|vm_offset_t
name|freemem_pt
decl_stmt|;
name|vm_offset_t
name|afterkern
decl_stmt|;
name|vm_offset_t
name|freemem_after
decl_stmt|;
name|vm_offset_t
name|lastaddr
decl_stmt|;
name|uint32_t
name|memsize
decl_stmt|;
name|set_cpufuncs
argument_list|()
expr_stmt|;
comment|/* NB: sets cputype */
name|lastaddr
operator|=
name|fake_preload_metadata
argument_list|()
expr_stmt|;
name|pcpu_init
argument_list|(
name|pcpup
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
argument_list|)
expr_stmt|;
name|PCPU_SET
argument_list|(
name|curthread
argument_list|,
operator|&
name|thread0
argument_list|)
expr_stmt|;
comment|/* 	 * We allocate memory downwards from where we were loaded 	 * by RedBoot; first the L1 page table, then NUM_KERNEL_PTS 	 * entries in the L2 page table.  Past that we re-align the 	 * allocation boundary so later data structures (stacks, etc) 	 * can be mapped with different attributes (write-back vs 	 * write-through).  Note this leaves a gap for expansion 	 * (or might be repurposed). 	 */
name|freemempos
operator|=
name|KERNPHYSADDR
expr_stmt|;
comment|/* macros to simplify initial memory allocation */
define|#
directive|define
name|alloc_pages
parameter_list|(
name|var
parameter_list|,
name|np
parameter_list|)
value|do {					\ 	freemempos -= (np * PAGE_SIZE);					\ 	(var) = freemempos;						\
comment|/* NB: this works because locore maps PA=VA */
value|\ 	memset((char *)(var), 0, ((np) * PAGE_SIZE));			\ } while (0)
define|#
directive|define
name|valloc_pages
parameter_list|(
name|var
parameter_list|,
name|np
parameter_list|)
value|do {					\ 	alloc_pages((var).pv_pa, (np));					\ 	(var).pv_va = (var).pv_pa + (KERNVIRTADDR - KERNPHYSADDR);	\ } while (0)
comment|/* force L1 page table alignment */
while|while
condition|(
operator|(
operator|(
name|freemempos
operator|-
name|L1_TABLE_SIZE
operator|)
operator|&
operator|(
name|L1_TABLE_SIZE
operator|-
literal|1
operator|)
operator|)
operator|!=
literal|0
condition|)
name|freemempos
operator|-=
name|PAGE_SIZE
expr_stmt|;
comment|/* allocate contiguous L1 page table */
name|valloc_pages
argument_list|(
name|kernel_l1pt
argument_list|,
name|L1_TABLE_SIZE
operator|/
name|PAGE_SIZE
argument_list|)
expr_stmt|;
comment|/* now allocate L2 page tables; they are linked to L1 below */
for|for
control|(
name|loop
operator|=
literal|0
init|;
name|loop
operator|<
name|NUM_KERNEL_PTS
condition|;
operator|++
name|loop
control|)
block|{
if|if
condition|(
operator|!
operator|(
name|loop
operator|%
operator|(
name|PAGE_SIZE
operator|/
name|L2_TABLE_SIZE_REAL
operator|)
operator|)
condition|)
block|{
name|valloc_pages
argument_list|(
name|kernel_pt_table
index|[
name|loop
index|]
argument_list|,
name|L2_TABLE_SIZE
operator|/
name|PAGE_SIZE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|kernel_pt_table
index|[
name|loop
index|]
operator|.
name|pv_pa
operator|=
name|freemempos
operator|+
operator|(
name|loop
operator|%
operator|(
name|PAGE_SIZE
operator|/
name|L2_TABLE_SIZE_REAL
operator|)
operator|)
operator|*
name|L2_TABLE_SIZE_REAL
expr_stmt|;
name|kernel_pt_table
index|[
name|loop
index|]
operator|.
name|pv_va
operator|=
name|kernel_pt_table
index|[
name|loop
index|]
operator|.
name|pv_pa
operator|+
operator|(
name|KERNVIRTADDR
operator|-
name|KERNPHYSADDR
operator|)
expr_stmt|;
block|}
block|}
name|freemem_pt
operator|=
name|freemempos
expr_stmt|;
comment|/* base of allocated pt's */
comment|/* 	 * Re-align allocation boundary so we can map the area 	 * write-back instead of write-through for the stacks and 	 * related structures allocated below. 	 */
name|freemempos
operator|=
name|PHYSADDR
operator|+
literal|0x100000
expr_stmt|;
comment|/* 	 * Allocate a page for the system page mapped to V0x00000000 	 * This page will just contain the system vectors and can be 	 * shared by all processes. 	 */
name|valloc_pages
argument_list|(
name|systempage
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Allocate stacks for all modes */
name|valloc_pages
argument_list|(
name|irqstack
argument_list|,
name|IRQ_STACK_SIZE
argument_list|)
expr_stmt|;
name|valloc_pages
argument_list|(
name|abtstack
argument_list|,
name|ABT_STACK_SIZE
argument_list|)
expr_stmt|;
name|valloc_pages
argument_list|(
name|undstack
argument_list|,
name|UND_STACK_SIZE
argument_list|)
expr_stmt|;
name|valloc_pages
argument_list|(
name|kernelstack
argument_list|,
name|KSTACK_PAGES
argument_list|)
expr_stmt|;
name|alloc_pages
argument_list|(
name|minidataclean
operator|.
name|pv_pa
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|valloc_pages
argument_list|(
name|msgbufpv
argument_list|,
name|round_page
argument_list|(
name|MSGBUF_SIZE
argument_list|)
operator|/
name|PAGE_SIZE
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ARM_USE_SMALL_ALLOC
error|#
directive|error
literal|"I am broken"
comment|/* XXX save people grief */
name|freemempos
operator|-=
name|PAGE_SIZE
expr_stmt|;
name|freemem_pt
operator|=
name|trunc_page
argument_list|(
name|freemem_pt
argument_list|)
expr_stmt|;
name|freemem_after
operator|=
name|freemempos
operator|-
operator|(
operator|(
name|freemem_pt
operator|-
literal|0x10100000
operator|)
operator|/
name|PAGE_SIZE
operator|)
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|arm_small_page
argument_list|)
expr_stmt|;
name|arm_add_smallalloc_pages
argument_list|(
argument|(void *)(freemem_after + (KERNVIRTADDR - KERNPHYSADDR) 	    , (void *)
literal|0xc0100000
argument|, freemem_pt -
literal|0x10100000
argument|,
literal|1
argument|); 	freemem_after -= ((freemem_after -
literal|0x10001000
argument|) / PAGE_SIZE) * 	    sizeof(struct arm_small_page); 	arm_add_smallalloc_pages((void *)(freemem_after + (KEYVIRTADDR - KERNPHYSADDR)) 	, (void *)
literal|0xc0001000
argument|, trunc_page(freemem_after) -
literal|0x10001000
argument|,
literal|0
argument|); 	freemempos = trunc_page(freemem_after); 	freemempos -= PAGE_SIZE;
endif|#
directive|endif
comment|/* 	 * Now construct the L1 page table.  First map the L2 	 * page tables into the L1 so we can replace L1 mappings 	 * later on if necessary 	 */
argument|l1pagetable = kernel_l1pt.pv_va;
comment|/* Map the L2 pages tables in the L1 page table */
argument|pmap_link_l2pt(l1pagetable, ARM_VECTORS_HIGH& ~(
literal|0x00100000
argument|-
literal|1
argument|),&kernel_pt_table[KERNEL_PT_SYS]); 	pmap_link_l2pt(l1pagetable, IXP425_IO_VBASE,&kernel_pt_table[KERNEL_PT_IO]); 	pmap_link_l2pt(l1pagetable, IXP425_MCU_VBASE,&kernel_pt_table[KERNEL_PT_IO +
literal|1
argument|]); 	pmap_link_l2pt(l1pagetable, IXP425_PCI_MEM_VBASE,&kernel_pt_table[KERNEL_PT_IO +
literal|2
argument|]); 	pmap_link_l2pt(l1pagetable, KERNBASE,&kernel_pt_table[KERNEL_PT_BEFOREKERN]); 	pmap_map_chunk(l1pagetable, KERNBASE, PHYSADDR,
literal|0x100000
argument|, 	    VM_PROT_READ|VM_PROT_WRITE, PTE_CACHE); 	pmap_map_chunk(l1pagetable, KERNBASE +
literal|0x100000
argument|, PHYSADDR +
literal|0x100000
argument|,
literal|0x100000
argument|, VM_PROT_READ|VM_PROT_WRITE, PTE_PAGETABLE); 	pmap_map_chunk(l1pagetable, KERNEL_TEXT_BASE, KERNEL_TEXT_PHYS, 	    next_chunk2(((uint32_t)lastaddr) - KERNEL_TEXT_BASE, L1_S_SIZE), 	    VM_PROT_READ|VM_PROT_WRITE, PTE_CACHE); 	freemem_after = next_page((int)lastaddr); 	afterkern = round_page(next_chunk2((vm_offset_t)lastaddr, L1_S_SIZE)); 	for (i =
literal|0
argument|; i< KERNEL_PT_AFKERNEL_NUM; i++) { 		pmap_link_l2pt(l1pagetable, afterkern + i *
literal|0x00100000
argument|,&kernel_pt_table[KERNEL_PT_AFKERNEL + i]); 	} 	pmap_map_entry(l1pagetable, afterkern, minidataclean.pv_pa,  	    VM_PROT_READ|VM_PROT_WRITE, PTE_CACHE);
ifdef|#
directive|ifdef
name|ARM_USE_SMALL_ALLOC
argument|if ((freemem_after +
literal|2
argument|* PAGE_SIZE)<= afterkern) { 		arm_add_smallalloc_pages((void *)(freemem_after), 		    (void*)(freemem_after + PAGE_SIZE), 		    afterkern - (freemem_after + PAGE_SIZE),
literal|0
argument|); 		     	}
endif|#
directive|endif
comment|/* Map the Mini-Data cache clean area. */
argument|xscale_setup_minidata(l1pagetable, afterkern, 	    minidataclean.pv_pa);
comment|/* Map the vector page. */
argument|pmap_map_entry(l1pagetable, ARM_VECTORS_HIGH, systempage.pv_pa, 	    VM_PROT_READ|VM_PROT_WRITE, PTE_CACHE); 	if (cpu_is_ixp43x()) 		pmap_devmap_bootstrap(l1pagetable, ixp435_devmap); 	else 		pmap_devmap_bootstrap(l1pagetable, ixp425_devmap);
comment|/* 	 * Give the XScale global cache clean code an appropriately 	 * sized chunk of unmapped VA space starting at 0xff000000 	 * (our device mappings end before this address). 	 */
argument|xscale_cache_clean_addr =
literal|0xff000000U
argument|;  	cpu_domains((DOMAIN_CLIENT<< (PMAP_DOMAIN_KERNEL*
literal|2
argument|)) | DOMAIN_CLIENT); 	setttb(kernel_l1pt.pv_pa); 	cpu_tlb_flushID(); 	cpu_domains(DOMAIN_CLIENT<< (PMAP_DOMAIN_KERNEL*
literal|2
argument|));
comment|/* 	 * Pages were allocated during the secondary bootstrap for the 	 * stacks for different CPU modes. 	 * We must now set the r13 registers in the different CPU modes to 	 * point to these stacks. 	 * Since the ARM stacks use STMFD etc. we must set r13 to the top end 	 * of the stack memory. 	 */
argument|set_stackptr(PSR_IRQ32_MODE, irqstack.pv_va + IRQ_STACK_SIZE*PAGE_SIZE); 	set_stackptr(PSR_ABT32_MODE, abtstack.pv_va + ABT_STACK_SIZE*PAGE_SIZE); 	set_stackptr(PSR_UND32_MODE, undstack.pv_va + UND_STACK_SIZE*PAGE_SIZE);
comment|/* 	 * We must now clean the cache again.... 	 * Cleaning may be done by reading new data to displace any 	 * dirty data in the cache. This will have happened in setttb() 	 * but since we are boot strapping the addresses used for the read 	 * may have just been remapped and thus the cache could be out 	 * of sync. A re-clean after the switch will cure this. 	 * After booting there are no gross relocations of the kernel thus 	 * this problem will not occur after initarm(). 	 */
argument|cpu_idcache_wbinv_all();
comment|/* ready to setup the console (XXX move earlier if possible) */
argument|cninit();
comment|/* 	 * Fetch the RAM size from the MCU registers.  The 	 * expansion bus was mapped above so we can now read 'em. 	 */
argument|if (cpu_is_ixp43x()) 		memsize = ixp435_ddram_size(); 	else 		memsize = ixp425_sdram_size(); 	physmem = memsize / PAGE_SIZE;
comment|/* Set stack for exception handlers */
argument|data_abort_handler_address = (u_int)data_abort_handler; 	prefetch_abort_handler_address = (u_int)prefetch_abort_handler; 	undefined_handler_address = (u_int)undefinedinstruction_bounce; 	undefined_init();  	proc_linkup0(&proc0,&thread0); 	thread0.td_kstack = kernelstack.pv_va; 	thread0.td_pcb = (struct pcb *) 		(thread0.td_kstack + KSTACK_PAGES * PAGE_SIZE) -
literal|1
argument|; 	thread0.td_pcb->pcb_flags =
literal|0
argument|; 	thread0.td_frame =&proc0_tf; 	pcpup->pc_curpcb = thread0.td_pcb;  	arm_vector_init(ARM_VECTORS_HIGH, ARM_VEC_ALL);  	pmap_curmaxkvaddr = afterkern + PAGE_SIZE; 	dump_avail[
literal|0
argument|] = PHYSADDR; 	dump_avail[
literal|1
argument|] = PHYSADDR + memsize; 	dump_avail[
literal|2
argument|] =
literal|0
argument|; 	dump_avail[
literal|3
argument|] =
literal|0
argument|;  	pmap_bootstrap(pmap_curmaxkvaddr,
literal|0xd0000000
argument|,&kernel_l1pt); 	msgbufp = (void*)msgbufpv.pv_va; 	msgbufinit(msgbufp, MSGBUF_SIZE); 	mutex_init();  	i =
literal|0
argument|;
ifdef|#
directive|ifdef
name|ARM_USE_SMALL_ALLOC
argument|phys_avail[i++] = PHYSADDR; 	phys_avail[i++] = PHYSADDR + PAGE_SIZE;
comment|/* 					 *XXX: Gross hack to get our 					 * pages in the vm_page_array 					 . */
endif|#
directive|endif
argument|phys_avail[i++] = round_page(virtual_avail - KERNBASE + PHYSADDR); 	phys_avail[i++] = trunc_page(PHYSADDR + memsize -
literal|1
argument|); 	phys_avail[i++] =
literal|0
argument|; 	phys_avail[i] =
literal|0
argument|;
comment|/* Do basic tuning, hz etc */
argument|init_param1(); 	init_param2(physmem); 	kdb_init();
comment|/* use static kernel environment if so configured */
argument|if (envmode ==
literal|1
argument|) 		kern_envp = static_env;  	return ((void *)(kernelstack.pv_va + USPACE_SVC_STACK_TOP - 	    sizeof(struct pcb)));
undef|#
directive|undef
name|next_page
undef|#
directive|undef
name|next_chunk2
argument|}
end_function

end_unit

