begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/* From: NetBSD: pte.h,v 1.10 1997/09/02 19:07:22 thorpej Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Alpha page table entry.  * Things which are in the VMS PALcode but not in the OSF PALcode  * are marked with "(VMS)".  *  * This information derived from pp. (II) 3-3 - (II) 3-6 and  * (III) 3-3 - (III) 3-5 of the "Alpha Architecture Reference Manual" by  * Richard L. Sites.  */
end_comment

begin_comment
comment|/*  * Alpha Page Table Entry  */
end_comment

begin_include
include|#
directive|include
file|<machine/alpha_cpu.h>
end_include

begin_typedef
typedef|typedef
name|alpha_pt_entry_t
name|pt_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PT_ENTRY_NULL
value|((pt_entry_t *) 0)
end_define

begin_define
define|#
directive|define
name|PTESHIFT
value|3
end_define

begin_comment
comment|/* pte size == 1<< PTESHIFT */
end_comment

begin_define
define|#
directive|define
name|PG_V
value|ALPHA_PTE_VALID
end_define

begin_define
define|#
directive|define
name|PG_NV
value|0
end_define

begin_define
define|#
directive|define
name|PG_FOR
value|ALPHA_PTE_FAULT_ON_READ
end_define

begin_define
define|#
directive|define
name|PG_FOW
value|ALPHA_PTE_FAULT_ON_WRITE
end_define

begin_define
define|#
directive|define
name|PG_FOE
value|ALPHA_PTE_FAULT_ON_EXECUTE
end_define

begin_define
define|#
directive|define
name|PG_ASM
value|ALPHA_PTE_ASM
end_define

begin_define
define|#
directive|define
name|PG_GH
value|ALPHA_PTE_GRANULARITY
end_define

begin_define
define|#
directive|define
name|PG_KRE
value|ALPHA_PTE_KR
end_define

begin_define
define|#
directive|define
name|PG_URE
value|ALPHA_PTE_UR
end_define

begin_define
define|#
directive|define
name|PG_KWE
value|ALPHA_PTE_KW
end_define

begin_define
define|#
directive|define
name|PG_UWE
value|ALPHA_PTE_UW
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|ALPHA_PTE_PROT
end_define

begin_define
define|#
directive|define
name|PG_RSVD
value|0x000000000000cc80
end_define

begin_comment
comment|/* Reserved fpr hardware */
end_comment

begin_define
define|#
directive|define
name|PG_WIRED
value|0x0000000000010000
end_define

begin_comment
comment|/* Wired. [SOFTWARE] */
end_comment

begin_define
define|#
directive|define
name|PG_FRAME
value|ALPHA_PTE_RAME
end_define

begin_define
define|#
directive|define
name|PG_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|PG_PFNUM
parameter_list|(
name|x
parameter_list|)
value|ALPHA_PTE_TO_PFN(x)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX NOT HERE */
end_comment

begin_define
define|#
directive|define
name|K0SEG_BEGIN
value|0xfffffc0000000000
end_define

begin_comment
comment|/* unmapped, cached */
end_comment

begin_define
define|#
directive|define
name|K0SEG_END
value|0xfffffe0000000000
end_define

begin_define
define|#
directive|define
name|PHYS_UNCACHED
value|0x0000000040000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX NOT HERE */
end_comment

begin_define
define|#
directive|define
name|k0segtophys
parameter_list|(
name|x
parameter_list|)
value|((vm_offset_t)(x)& 0x00000003ffffffff)
end_define

begin_define
define|#
directive|define
name|phystok0seg
parameter_list|(
name|x
parameter_list|)
value|((vm_offset_t)(x) | K0SEG_BEGIN)
end_define

begin_define
define|#
directive|define
name|phystouncached
parameter_list|(
name|x
parameter_list|)
value|((vm_offset_t)(x) | PHYS_UNCACHED)
end_define

begin_define
define|#
directive|define
name|uncachedtophys
parameter_list|(
name|x
parameter_list|)
value|((vm_offset_t)(x)& ~PHYS_UNCACHED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PTEMASK
value|(NPTEPG - 1)
end_define

begin_define
define|#
directive|define
name|vatopte
parameter_list|(
name|va
parameter_list|)
value|(((va)>> PGSHIFT)& PTEMASK)
end_define

begin_define
define|#
directive|define
name|vatoste
parameter_list|(
name|va
parameter_list|)
value|(((va)>> SEGSHIFT)& PTEMASK)
end_define

begin_define
define|#
directive|define
name|kvtol1pte
parameter_list|(
name|va
parameter_list|)
define|\
value|(((vm_offset_t)(va)>> (PGSHIFT + 2*(PGSHIFT-PTESHIFT)))& PTEMASK)
end_define

begin_define
define|#
directive|define
name|vatopa
parameter_list|(
name|va
parameter_list|)
define|\
value|((PG_PFNUM(*kvtopte(va))<< PGSHIFT) | ((vm_offset_t)(va)& PGOFSET))
end_define

begin_define
define|#
directive|define
name|ALPHA_STSIZE
value|((u_long)NBPG)
end_define

begin_comment
comment|/* 8k */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MAX_PTSIZE
value|((u_long)(NPTEPG * NBPG))
end_define

begin_comment
comment|/* 8M */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Kernel virtual address to Sysmap entry and visa versa.  */
end_comment

begin_define
define|#
directive|define
name|kvtopte
parameter_list|(
name|va
parameter_list|)
define|\
value|(Sysmap + (((vm_offset_t)(va) - VM_MIN_KERNEL_ADDRESS)>> PGSHIFT))
end_define

begin_define
define|#
directive|define
name|ptetokv
parameter_list|(
name|pte
parameter_list|)
define|\
value|((((pt_entry_t *)(pte) - Sysmap)<< PGSHIFT) + VM_MIN_KERNEL_ADDRESS)
end_define

begin_decl_stmt
specifier|extern
name|pt_entry_t
modifier|*
name|Lev1map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Alpha Level One page table */
end_comment

begin_decl_stmt
specifier|extern
name|pt_entry_t
modifier|*
name|Sysmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel pte table */
end_comment

begin_decl_stmt
specifier|extern
name|vm_size_t
name|Sysmapsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of pte's in Sysmap */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

