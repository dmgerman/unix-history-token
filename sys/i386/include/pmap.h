begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and William Jolitz of UUNET Technologies Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Derived from hp300 version by Mike Hibler, this version by William  * Jolitz uses a recursive map [a pde points to the page directory] to  * map the page tables using the pagetables themselves. This is done to  * reduce the impact on kernel virtual memory for lots of sparse address  * space, and to reduce the cost of memory to each process.  *  *	from: hp300: @(#)pmap.h	7.2 (Berkeley) 12/16/90  *	from: @(#)pmap.h	7.4 (Berkeley) 5/12/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PMAP_H_
end_define

begin_comment
comment|/*  * Page-directory and page-table entries follow this format, with a few  * of the fields not present here and there, depending on a lot of things.  */
end_comment

begin_comment
comment|/* ---- Intel Nomenclature ---- */
end_comment

begin_define
define|#
directive|define
name|PG_V
value|0x001
end_define

begin_comment
comment|/* P	Valid			*/
end_comment

begin_define
define|#
directive|define
name|PG_RW
value|0x002
end_define

begin_comment
comment|/* R/W	Read/Write		*/
end_comment

begin_define
define|#
directive|define
name|PG_U
value|0x004
end_define

begin_comment
comment|/* U/S  User/Supervisor		*/
end_comment

begin_define
define|#
directive|define
name|PG_NC_PWT
value|0x008
end_define

begin_comment
comment|/* PWT	Write through		*/
end_comment

begin_define
define|#
directive|define
name|PG_NC_PCD
value|0x010
end_define

begin_comment
comment|/* PCD	Cache disable		*/
end_comment

begin_define
define|#
directive|define
name|PG_A
value|0x020
end_define

begin_comment
comment|/* A	Accessed		*/
end_comment

begin_define
define|#
directive|define
name|PG_M
value|0x040
end_define

begin_comment
comment|/* D	Dirty			*/
end_comment

begin_define
define|#
directive|define
name|PG_PS
value|0x080
end_define

begin_comment
comment|/* PS	Page size (0=4k,1=4M)	*/
end_comment

begin_define
define|#
directive|define
name|PG_PTE_PAT
value|0x080
end_define

begin_comment
comment|/* PAT	PAT index		*/
end_comment

begin_define
define|#
directive|define
name|PG_G
value|0x100
end_define

begin_comment
comment|/* G	Global			*/
end_comment

begin_define
define|#
directive|define
name|PG_AVAIL1
value|0x200
end_define

begin_comment
comment|/*    /	Available for system	*/
end_comment

begin_define
define|#
directive|define
name|PG_AVAIL2
value|0x400
end_define

begin_comment
comment|/*<	programmers use		*/
end_comment

begin_define
define|#
directive|define
name|PG_AVAIL3
value|0x800
end_define

begin_comment
comment|/*    \				*/
end_comment

begin_define
define|#
directive|define
name|PG_PDE_PAT
value|0x1000
end_define

begin_comment
comment|/* PAT	PAT index		*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_define
define|#
directive|define
name|PG_NX
value|(1ull<<63)
end_define

begin_comment
comment|/* No-execute */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Our various interpretations of the above */
end_comment

begin_define
define|#
directive|define
name|PG_W
value|PG_AVAIL1
end_define

begin_comment
comment|/* "Wired" pseudoflag */
end_comment

begin_define
define|#
directive|define
name|PG_MANAGED
value|PG_AVAIL2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_define
define|#
directive|define
name|PG_FRAME
value|(0x000ffffffffff000ull)
end_define

begin_define
define|#
directive|define
name|PG_PS_FRAME
value|(0x000fffffffe00000ull)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PG_FRAME
value|(~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|PG_PS_FRAME
value|(0xffc00000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PG_PROT
value|(PG_RW|PG_U)
end_define

begin_comment
comment|/* all protection bits . */
end_comment

begin_define
define|#
directive|define
name|PG_N
value|(PG_NC_PWT|PG_NC_PCD)
end_define

begin_comment
comment|/* Non-cacheable */
end_comment

begin_comment
comment|/*  * Page Protection Exception bits  */
end_comment

begin_define
define|#
directive|define
name|PGEX_P
value|0x01
end_define

begin_comment
comment|/* Protection violation vs. not present */
end_comment

begin_define
define|#
directive|define
name|PGEX_W
value|0x02
end_define

begin_comment
comment|/* during a Write cycle */
end_comment

begin_define
define|#
directive|define
name|PGEX_U
value|0x04
end_define

begin_comment
comment|/* access from User mode (UPL) */
end_comment

begin_define
define|#
directive|define
name|PGEX_I
value|0x10
end_define

begin_comment
comment|/* during an instruction fetch */
end_comment

begin_comment
comment|/*  * Size of Kernel address space.  This is the number of page table pages  * (4MB each) to use for the kernel.  256 pages == 1 Gigabyte.  * This **MUST** be a multiple of 4 (eg: 252, 256, 260, etc).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KVA_PAGES
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_define
define|#
directive|define
name|KVA_PAGES
value|512
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KVA_PAGES
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Pte related macros  */
end_comment

begin_define
define|#
directive|define
name|VADDR
parameter_list|(
name|pdi
parameter_list|,
name|pti
parameter_list|)
value|((vm_offset_t)(((pdi)<<PDRSHIFT)|((pti)<<PAGE_SHIFT)))
end_define

begin_comment
comment|/* Initial number of kernel page tables. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NKPT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_comment
comment|/* 152 page tables needed to map 16G (76B "struct vm_page", 2M page tables). */
end_comment

begin_define
define|#
directive|define
name|NKPT
value|240
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 18 page tables needed to map 4G (72B "struct vm_page", 4M page tables). */
end_comment

begin_define
define|#
directive|define
name|NKPT
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NKPDE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|NKPDE
value|(KVA_PAGES - 1)
end_define

begin_comment
comment|/* number of page tables/pde's */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NKPDE
value|(KVA_PAGES)
end_define

begin_comment
comment|/* number of page tables/pde's */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The *PTDI values control the layout of virtual memory  *  * XXX This works for now, but I am not real happy with it, I'll fix it  * right after I fix locore.s and the magic 28K hole  *  * SMP_PRIVPAGES: The per-cpu address space is 0xff80000 -> 0xffbfffff  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|MPPTDI
value|(NPDEPTD-1)
end_define

begin_comment
comment|/* per cpu ptd entry */
end_comment

begin_define
define|#
directive|define
name|KPTDI
value|(MPPTDI-NKPDE)
end_define

begin_comment
comment|/* start of kernel virtual pde's */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KPTDI
value|(NPDEPTD-NKPDE)
end_define

begin_comment
comment|/* start of kernel virtual pde's */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|PTDPTDI
value|(KPTDI-NPGPTD)
end_define

begin_comment
comment|/* ptd entry that points to ptd! */
end_comment

begin_comment
comment|/*  * XXX doesn't really belong here I guess...  */
end_comment

begin_define
define|#
directive|define
name|ISA_HOLE_START
value|0xa0000
end_define

begin_define
define|#
directive|define
name|ISA_HOLE_LENGTH
value|(0x100000-ISA_HOLE_START)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_typedef
typedef|typedef
name|uint64_t
name|pdpt_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|pd_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|pt_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PTESHIFT
value|(3)
end_define

begin_define
define|#
directive|define
name|PDESHIFT
value|(3)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|uint32_t
name|pd_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|pt_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PTESHIFT
value|(2)
end_define

begin_define
define|#
directive|define
name|PDESHIFT
value|(2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Address of current and alternate address space page table maps  * and directories.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|pt_entry_t
name|PTmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pd_entry_t
name|PTD
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pd_entry_t
name|PTDpde
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_decl_stmt
specifier|extern
name|pdpt_entry_t
modifier|*
name|IdlePDPT
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|pd_entry_t
modifier|*
name|IdlePTD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical address of "Idle" state directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * virtual address to page table entry and  * to physical address.  * Note: these work recursively, thus vtopte of a pte will give  * the corresponding pde that in turn maps it.  */
end_comment

begin_define
define|#
directive|define
name|vtopte
parameter_list|(
name|va
parameter_list|)
value|(PTmap + i386_btop(va))
end_define

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|pmap_kextract((vm_offset_t)(va))
end_define

begin_comment
comment|/*  *	Routine:	pmap_kextract  *	Function:  *		Extract the physical page address associated  *		kernel virtual address.  */
end_comment

begin_function
specifier|static
name|__inline
name|vm_paddr_t
name|pmap_kextract
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
block|{
name|vm_paddr_t
name|pa
decl_stmt|;
if|if
condition|(
operator|(
name|pa
operator|=
name|PTD
index|[
name|va
operator|>>
name|PDRSHIFT
index|]
operator|)
operator|&
name|PG_PS
condition|)
block|{
name|pa
operator|=
operator|(
name|pa
operator|&
name|PG_PS_FRAME
operator|)
operator||
operator|(
name|va
operator|&
name|PDRMASK
operator|)
expr_stmt|;
block|}
else|else
block|{
name|pa
operator|=
operator|*
name|vtopte
argument_list|(
name|va
argument_list|)
expr_stmt|;
name|pa
operator|=
operator|(
name|pa
operator|&
name|PG_FRAME
operator|)
operator||
operator|(
name|va
operator|&
name|PAGE_MASK
operator|)
expr_stmt|;
block|}
return|return
name|pa
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_function
specifier|static
name|__inline
name|pt_entry_t
name|pte_load
parameter_list|(
name|pt_entry_t
modifier|*
name|ptep
parameter_list|)
block|{
name|pt_entry_t
name|r
decl_stmt|;
asm|__asm __volatile(
literal|"lock; cmpxchg8b %1"
operator|:
literal|"=A"
operator|(
name|r
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|ptep
operator|)
operator|,
literal|"a"
operator|(
literal|0
operator|)
operator|,
literal|"d"
operator|(
literal|0
operator|)
operator|,
literal|"b"
operator|(
literal|0
operator|)
operator|,
literal|"c"
operator|(
literal|0
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|r
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|pt_entry_t
name|pte_load_store
parameter_list|(
name|pt_entry_t
modifier|*
name|ptep
parameter_list|,
name|pt_entry_t
name|v
parameter_list|)
block|{
name|pt_entry_t
name|r
decl_stmt|;
name|r
operator|=
operator|*
name|ptep
expr_stmt|;
asm|__asm __volatile(
literal|"1:\n"
literal|"\tlock; cmpxchg8b %1\n"
literal|"\tjnz 1b"
operator|:
literal|"+A"
operator|(
name|r
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|ptep
operator|)
operator|,
literal|"b"
operator|(
operator|(
name|uint32_t
operator|)
name|v
operator|)
operator|,
literal|"c"
operator|(
call|(
name|uint32_t
call|)
argument_list|(
name|v
operator|>>
literal|32
argument_list|)
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|r
operator|)
return|;
end_return

begin_comment
unit|}
comment|/* XXXRU move to atomic.h? */
end_comment

begin_function
unit|static
name|__inline
name|int
name|atomic_cmpset_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|dst
parameter_list|,
name|uint64_t
name|exp
parameter_list|,
name|uint64_t
name|src
parameter_list|)
block|{
name|int64_t
name|res
init|=
name|exp
decl_stmt|;
asm|__asm __volatile (
literal|"	lock ;			"
literal|"	cmpxchg8b %2 ;		"
literal|"	setz	%%al ;		"
literal|"	movzbl	%%al,%0 ;	"
literal|"# atomic_cmpset_64"
operator|:
literal|"+A"
operator|(
name|res
operator|)
operator|,
comment|/* 0 (result) */
literal|"=m"
operator|(
operator|*
name|dst
operator|)
comment|/* 1 */
operator|:
literal|"m"
operator|(
operator|*
name|dst
operator|)
operator|,
comment|/* 2 */
literal|"b"
operator|(
operator|(
name|uint32_t
operator|)
name|src
operator|)
operator|,
literal|"c"
operator|(
call|(
name|uint32_t
call|)
argument_list|(
name|src
operator|>>
literal|32
argument_list|)
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|res
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|pte_load_clear
parameter_list|(
name|ptep
parameter_list|)
value|pte_load_store((ptep), (pt_entry_t)0ULL)
end_define

begin_define
define|#
directive|define
name|pte_store
parameter_list|(
name|ptep
parameter_list|,
name|pte
parameter_list|)
value|pte_load_store((ptep), (pt_entry_t)pte)
end_define

begin_decl_stmt
unit|extern
name|pt_entry_t
name|pg_nx
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PAE */
end_comment

begin_function
specifier|static
name|__inline
name|pt_entry_t
name|pte_load
parameter_list|(
name|pt_entry_t
modifier|*
name|ptep
parameter_list|)
block|{
name|pt_entry_t
name|r
decl_stmt|;
name|r
operator|=
operator|*
name|ptep
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|pt_entry_t
name|pte_load_store
parameter_list|(
name|pt_entry_t
modifier|*
name|ptep
parameter_list|,
name|pt_entry_t
name|pte
parameter_list|)
block|{
name|pt_entry_t
name|r
decl_stmt|;
asm|__asm __volatile(
literal|"xchgl %0,%1"
operator|:
literal|"=m"
operator|(
operator|*
name|ptep
operator|)
operator|,
literal|"=r"
operator|(
name|r
operator|)
operator|:
literal|"1"
operator|(
name|pte
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|ptep
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|r
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|pte_load_clear
parameter_list|(
name|pte
parameter_list|)
value|atomic_readandclear_int(pte)
end_define

begin_function
unit|static
name|__inline
name|void
name|pte_store
parameter_list|(
name|pt_entry_t
modifier|*
name|ptep
parameter_list|,
name|pt_entry_t
name|pte
parameter_list|)
block|{
operator|*
name|ptep
operator|=
name|pte
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAE */
end_comment

begin_define
define|#
directive|define
name|pte_clear
parameter_list|(
name|ptep
parameter_list|)
value|pte_store((ptep), (pt_entry_t)0ULL)
end_define

begin_define
define|#
directive|define
name|pde_store
parameter_list|(
name|pdep
parameter_list|,
name|pde
parameter_list|)
value|pte_store((pdep), (pde))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Pmap stuff  */
end_comment

begin_struct_decl
struct_decl|struct
name|pv_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pv_chunk
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|md_page
block|{
name|int
name|pv_list_count
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_entry
argument_list|)
name|pv_list
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmap
block|{
name|struct
name|mtx
name|pm_mtx
decl_stmt|;
name|pd_entry_t
modifier|*
name|pm_pdir
decl_stmt|;
comment|/* KVA of page directory */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pv_chunk
argument_list|)
name|pm_pvchunk
expr_stmt|;
comment|/* list of mappings in pmap */
name|u_int
name|pm_active
decl_stmt|;
comment|/* active on cpus */
name|struct
name|pmap_statistics
name|pm_stats
decl_stmt|;
comment|/* pmap statistics */
name|LIST_ENTRY
argument_list|(
argument|pmap
argument_list|)
name|pm_list
expr_stmt|;
comment|/* List of all pmaps */
ifdef|#
directive|ifdef
name|PAE
name|pdpt_entry_t
modifier|*
name|pm_pdpt
decl_stmt|;
comment|/* KVA of page director pointer 						   table */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pmap
modifier|*
name|pmap_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pmap
name|kernel_pmap_store
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|kernel_pmap
value|(&kernel_pmap_store)
end_define

begin_define
define|#
directive|define
name|PMAP_LOCK
parameter_list|(
name|pmap
parameter_list|)
value|mtx_lock(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_LOCK_ASSERT
parameter_list|(
name|pmap
parameter_list|,
name|type
parameter_list|)
define|\
value|mtx_assert(&(pmap)->pm_mtx, (type))
end_define

begin_define
define|#
directive|define
name|PMAP_LOCK_DESTROY
parameter_list|(
name|pmap
parameter_list|)
value|mtx_destroy(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_LOCK_INIT
parameter_list|(
name|pmap
parameter_list|)
value|mtx_init(&(pmap)->pm_mtx, "pmap", \ 				    NULL, MTX_DEF | MTX_DUPOK)
end_define

begin_define
define|#
directive|define
name|PMAP_LOCKED
parameter_list|(
name|pmap
parameter_list|)
value|mtx_owned(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_MTX
parameter_list|(
name|pmap
parameter_list|)
value|(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_TRYLOCK
parameter_list|(
name|pmap
parameter_list|)
value|mtx_trylock(&(pmap)->pm_mtx)
end_define

begin_define
define|#
directive|define
name|PMAP_UNLOCK
parameter_list|(
name|pmap
parameter_list|)
value|mtx_unlock(&(pmap)->pm_mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For each vm_page_t, there is a list of all currently valid virtual  * mappings of that page.  An entry is a pv_entry_t, the list is pv_list.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pv_entry
block|{
name|vm_offset_t
name|pv_va
decl_stmt|;
comment|/* virtual address for mapping */
name|TAILQ_ENTRY
argument_list|(
argument|pv_entry
argument_list|)
name|pv_list
expr_stmt|;
block|}
typedef|*
name|pv_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * pv_entries are allocated in chunks per-process.  This avoids the  * need to track per-pmap assignments.  */
end_comment

begin_define
define|#
directive|define
name|_NPCM
value|11
end_define

begin_define
define|#
directive|define
name|_NPCPV
value|336
end_define

begin_struct
struct|struct
name|pv_chunk
block|{
name|pmap_t
name|pc_pmap
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pv_chunk
argument_list|)
name|pc_list
expr_stmt|;
name|uint32_t
name|pc_map
index|[
name|_NPCM
index|]
decl_stmt|;
comment|/* bitmap; 1 = free */
name|uint32_t
name|pc_spare
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|pv_entry
name|pc_pventry
index|[
name|_NPCPV
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|NPPROVMTRR
value|8
end_define

begin_define
define|#
directive|define
name|PPRO_VMTRRphysBase0
value|0x200
end_define

begin_define
define|#
directive|define
name|PPRO_VMTRRphysMask0
value|0x201
end_define

begin_struct
struct|struct
name|ppro_vmtrr
block|{
name|u_int64_t
name|base
decl_stmt|,
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ppro_vmtrr
name|PPro_vmtrr
index|[
name|NPPROVMTRR
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|caddr_t
name|CADDR1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pt_entry_t
modifier|*
name|CMAP1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|phys_avail
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|dump_avail
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pseflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pgeflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ptvmmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* poor name! */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|virtual_avail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|virtual_end
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pmap_page_is_mapped
parameter_list|(
name|m
parameter_list|)
value|(!TAILQ_EMPTY(&(m)->md.pv_list))
end_define

begin_define
define|#
directive|define
name|pmap_unmapbios
parameter_list|(
name|va
parameter_list|,
name|sz
parameter_list|)
value|pmap_unmapdev((va), (sz))
end_define

begin_function_decl
name|void
name|pmap_bootstrap
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmap_change_attr
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_init_pat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kenter
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kenter_attr
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pmap_kenter_temporary
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_kremove
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pmap_mapbios
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pmap_mapdev
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pmap_mapdev_attr
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_unmapdev
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|pt_entry_t
modifier|*
name|pmap_pte
argument_list|(
name|pmap_t
argument_list|,
name|vm_offset_t
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pmap_set_pg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_invalidate_page
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_invalidate_range
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_invalidate_all
parameter_list|(
name|pmap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmap_invalidate_cache
parameter_list|(
name|void
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
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PMAP_H_ */
end_comment

end_unit

