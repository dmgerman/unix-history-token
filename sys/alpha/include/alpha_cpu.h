begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: alpha_cpu.h,v 1.15 1997/09/20 19:02:34 mjacob Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ALPHA_ALPHA_CPU_H__
end_ifndef

begin_define
define|#
directive|define
name|__ALPHA_ALPHA_CPU_H__
end_define

begin_comment
comment|/*  * Alpha CPU + OSF/1 PALcode definitions for use by the kernel.  *  * Definitions for:  *  *	Process Control Block  *	Interrupt/Exception/Syscall Stack Frame  *	Processor Status Register  *	Machine Check Error Summary Register  *	Machine Check Logout Area  *	Virtual Memory Management  *	Kernel Entry Vectors  *	MMCSR Fault Type Codes  *	Translation Buffer Invalidation  *  * and miscellaneous PALcode operations.  */
end_comment

begin_comment
comment|/*  * Process Control Block definitions [OSF/1 PALcode Specific]  */
end_comment

begin_struct
struct|struct
name|alpha_pcb
block|{
name|unsigned
name|long
name|apcb_ksp
decl_stmt|;
comment|/* kernel stack ptr */
name|unsigned
name|long
name|apcb_usp
decl_stmt|;
comment|/* user stack ptr */
name|unsigned
name|long
name|apcb_ptbr
decl_stmt|;
comment|/* page table base reg */
name|unsigned
name|int
name|apcb_cpc
decl_stmt|;
comment|/* charged process cycles */
name|unsigned
name|int
name|apcb_asn
decl_stmt|;
comment|/* address space number */
name|unsigned
name|long
name|apcb_unique
decl_stmt|;
comment|/* process unique value */
name|unsigned
name|long
name|apcb_flags
decl_stmt|;
comment|/* flags; see below */
name|unsigned
name|long
name|apcb_decrsv0
decl_stmt|;
comment|/* DEC reserved */
name|unsigned
name|long
name|apcb_decrsv1
decl_stmt|;
comment|/* DEC reserved */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ALPHA_PCB_FLAGS_FEN
value|0x0000000000000001
end_define

begin_define
define|#
directive|define
name|ALPHA_PCB_FLAGS_PME
value|0x4000000000000000
end_define

begin_comment
comment|/*  * Interrupt/Exception/Syscall "Hardware" (really PALcode)  * Stack Frame definitions  *  * These are quadword offsets from the sp on kernel entry, i.e.  * to get to the value in question you access (sp + (offset * 8)).  *  * On syscall entry, A0-A2 aren't written to memory but space  * _is_ reserved for them.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_HWFRAME_PS
value|0
end_define

begin_comment
comment|/* processor status register */
end_comment

begin_define
define|#
directive|define
name|ALPHA_HWFRAME_PC
value|1
end_define

begin_comment
comment|/* program counter */
end_comment

begin_define
define|#
directive|define
name|ALPHA_HWFRAME_GP
value|2
end_define

begin_comment
comment|/* global pointer */
end_comment

begin_define
define|#
directive|define
name|ALPHA_HWFRAME_A0
value|3
end_define

begin_comment
comment|/* a0 */
end_comment

begin_define
define|#
directive|define
name|ALPHA_HWFRAME_A1
value|4
end_define

begin_comment
comment|/* a1 */
end_comment

begin_define
define|#
directive|define
name|ALPHA_HWFRAME_A2
value|5
end_define

begin_comment
comment|/* a2 */
end_comment

begin_define
define|#
directive|define
name|ALPHA_HWFRAME_SIZE
value|6
end_define

begin_comment
comment|/* 6 8-byte words */
end_comment

begin_comment
comment|/*  * Processor Status Register [OSF/1 PALcode Specific]  *  * Includes user/kernel mode bit, interrupt priority levels, etc.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PSL_USERMODE
value|0x0008
end_define

begin_comment
comment|/* set -> user mode */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PSL_IPL_MASK
value|0x0007
end_define

begin_comment
comment|/* interrupt level mask */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PSL_IPL_0
value|0x0000
end_define

begin_comment
comment|/* all interrupts enabled */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PSL_IPL_SOFT
value|0x0001
end_define

begin_comment
comment|/* software ints disabled */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PSL_IPL_IO
value|0x0004
end_define

begin_comment
comment|/* I/O dev ints disabled */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PSL_IPL_CLOCK
value|0x0005
end_define

begin_comment
comment|/* clock ints disabled */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PSL_IPL_HIGH
value|0x0006
end_define

begin_comment
comment|/* all but mchecks disabled */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PSL_MUST_BE_ZERO
value|0xfffffffffffffff0
end_define

begin_comment
comment|/* Convenience constants: what must be set/clear in user mode */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PSL_USERSET
value|ALPHA_PSL_USERMODE
end_define

begin_define
define|#
directive|define
name|ALPHA_PSL_USERCLR
value|(ALPHA_PSL_MUST_BE_ZERO | ALPHA_PSL_IPL_MASK)
end_define

begin_comment
comment|/*  * Interrupt Type Code Definitions [OSF/1 PALcode Specific]  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_INTR_XPROC
value|0
end_define

begin_comment
comment|/* interprocessor interrupt */
end_comment

begin_define
define|#
directive|define
name|ALPHA_INTR_CLOCK
value|1
end_define

begin_comment
comment|/* clock interrupt */
end_comment

begin_define
define|#
directive|define
name|ALPHA_INTR_ERROR
value|2
end_define

begin_comment
comment|/* correctable error or mcheck */
end_comment

begin_define
define|#
directive|define
name|ALPHA_INTR_DEVICE
value|3
end_define

begin_comment
comment|/* device interrupt */
end_comment

begin_define
define|#
directive|define
name|ALPHA_INTR_PERF
value|4
end_define

begin_comment
comment|/* performance counter */
end_comment

begin_define
define|#
directive|define
name|ALPHA_INTR_PASSIVE
value|5
end_define

begin_comment
comment|/* passive release */
end_comment

begin_comment
comment|/*  * Machine Check Error Summary Register definitions [OSF/1 PALcode Specific]  *  * The following bits are values as read.  On write, _PCE, _SCE, and  * _MIP are "write 1 to clear."  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MCES_IMP
define|\
value|0xffffffff00000000
end_define

begin_comment
comment|/* impl. dependent */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MCES_RSVD
define|\
value|0x00000000ffffffe0
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MCES_DSC
define|\
value|0x0000000000000010
end_define

begin_comment
comment|/* disable system correctable error reporting */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MCES_DPC
define|\
value|0x0000000000000008
end_define

begin_comment
comment|/* disable processor correctable error reporting */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MCES_PCE
define|\
value|0x0000000000000004
end_define

begin_comment
comment|/* processor correctable error in progress */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MCES_SCE
define|\
value|0x0000000000000002
end_define

begin_comment
comment|/* system correctable error in progress */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MCES_MIP
define|\
value|0x0000000000000001
end_define

begin_comment
comment|/* machine check in progress */
end_comment

begin_comment
comment|/*  * Machine Check Error Summary Register definitions [OSF/1 PALcode Specific]  */
end_comment

begin_struct
struct|struct
name|alpha_logout_area
block|{
name|unsigned
name|int
name|la_frame_size
decl_stmt|;
comment|/* frame size */
name|unsigned
name|int
name|la_flags
decl_stmt|;
comment|/* flags; see below */
name|unsigned
name|int
name|la_cpu_offset
decl_stmt|;
comment|/* offset to cpu area */
name|unsigned
name|int
name|la_system_offset
decl_stmt|;
comment|/* offset to system area */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_FLAGS_RETRY
value|0x80000000
end_define

begin_comment
comment|/* OK to continue */
end_comment

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_FLAGS_SE
value|0x40000000
end_define

begin_comment
comment|/* second error */
end_comment

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_FLAGS_SBZ
value|0x3fffffff
end_define

begin_comment
comment|/* should be zero */
end_comment

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_NOT_BUILT
define|\
value|(struct alpha_logout_area *)0xffffffffffffffff)
end_define

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_PAL_AREA
parameter_list|(
name|lap
parameter_list|)
define|\
value|(unsigned long *)((unsigned char *)(lap) + 16)
end_define

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_PAL_SIZE
parameter_list|(
name|lap
parameter_list|)
define|\
value|((lap)->la_cpu_offset - 16)
end_define

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_CPU_AREA
parameter_list|(
name|lap
parameter_list|)
define|\
value|(unsigned long *)((unsigned char *)(lap) + (lap)->la_cpu_offset)
end_define

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_CPU_SIZE
parameter_list|(
name|lap
parameter_list|)
define|\
value|((lap)->la_system_offset - (lap)->la_cpu_offset)
end_define

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_SYSTEM_AREA
parameter_list|(
name|lap
parameter_list|)
define|\
value|(unsigned long *)((unsigned char *)(lap) + (lap)->la_system_offset)
end_define

begin_define
define|#
directive|define
name|ALPHA_LOGOUT_SYSTEM_SIZE
parameter_list|(
name|lap
parameter_list|)
define|\
value|((lap)->la_frame_size - (lap)->la_system_offset)
end_define

begin_comment
comment|/*  * Virtual Memory Management definitions [OSF/1 PALcode Specific]  *  * Includes user and kernel space addresses and information,  * page table entry definitions, etc.  *  * NOTE THAT THESE DEFINITIONS MAY CHANGE IN FUTURE ALPHA CPUS!  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PGSHIFT
value|13
end_define

begin_comment
comment|/* bits that index within page */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PTSHIFT
value|10
end_define

begin_comment
comment|/* bits that index within page tables */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PGBYTES
value|(1<< ALPHA_PGSHIFT)
end_define

begin_define
define|#
directive|define
name|ALPHA_L3SHIFT
value|ALPHA_PGSHIFT
end_define

begin_define
define|#
directive|define
name|ALPHA_L2SHIFT
value|(ALPHA_L3SHIFT+ALPHA_PTSHIFT)
end_define

begin_define
define|#
directive|define
name|ALPHA_L1SHIFT
value|(ALPHA_L2SHIFT+ALPHA_PTSHIFT)
end_define

begin_define
define|#
directive|define
name|ALPHA_USEG_BASE
value|0
end_define

begin_comment
comment|/* virtual */
end_comment

begin_define
define|#
directive|define
name|ALPHA_USEG_END
value|0x000003ffffffffffLL
end_define

begin_define
define|#
directive|define
name|ALPHA_K0SEG_BASE
value|0xfffffc0000000000LL
end_define

begin_comment
comment|/* direct-mapped */
end_comment

begin_define
define|#
directive|define
name|ALPHA_K0SEG_END
value|0xfffffdffffffffffLL
end_define

begin_define
define|#
directive|define
name|ALPHA_K1SEG_BASE
value|0xfffffe0000000000LL
end_define

begin_comment
comment|/* virtual */
end_comment

begin_define
define|#
directive|define
name|ALPHA_K1SEG_END
value|0xffffffffffffffffLL
end_define

begin_define
define|#
directive|define
name|ALPHA_K0SEG_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((x)& ~ALPHA_K0SEG_BASE)
end_define

begin_define
define|#
directive|define
name|ALPHA_PHYS_TO_K0SEG
parameter_list|(
name|x
parameter_list|)
value|((x) | ALPHA_K0SEG_BASE)
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_VALID
value|0x0001
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_FAULT_ON_READ
value|0x0002
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_FAULT_ON_WRITE
value|0x0004
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_FAULT_ON_EXECUTE
value|0x0008
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_ASM
value|0x0010
end_define

begin_comment
comment|/* addr. space match */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PTE_GRANULARITY
value|0x0060
end_define

begin_comment
comment|/* granularity hint */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PTE_PROT
value|0xff00
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_KR
value|0x0100
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_UR
value|0x0200
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_KW
value|0x1000
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_UW
value|0x2000
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_WRITE
value|(ALPHA_PTE_KW | ALPHA_PTE_UW)
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_SOFTWARE
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_PFN
value|0xffffffff00000000
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_TO_PFN
parameter_list|(
name|pte
parameter_list|)
value|((u_long)(pte)>> 32)
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_FROM_PFN
parameter_list|(
name|pfn
parameter_list|)
value|((u_long)(pfn)<< 32)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|alpha_pt_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Kernel Entry Vectors.  [OSF/1 PALcode Specific]  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_KENTRY_INT
value|0
end_define

begin_define
define|#
directive|define
name|ALPHA_KENTRY_ARITH
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_KENTRY_MM
value|2
end_define

begin_define
define|#
directive|define
name|ALPHA_KENTRY_IF
value|3
end_define

begin_define
define|#
directive|define
name|ALPHA_KENTRY_UNA
value|4
end_define

begin_define
define|#
directive|define
name|ALPHA_KENTRY_SYS
value|5
end_define

begin_comment
comment|/*  * MMCSR Fault Type Codes.  [OSF/1 PALcode Specific]  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MMCSR_INVALTRANS
value|0
end_define

begin_define
define|#
directive|define
name|ALPHA_MMCSR_ACCESS
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_MMCSR_FOR
value|2
end_define

begin_define
define|#
directive|define
name|ALPHA_MMCSR_FOE
value|3
end_define

begin_define
define|#
directive|define
name|ALPHA_MMCSR_FOW
value|4
end_define

begin_comment
comment|/*  * Instruction Fault Type Codes.  [OSF/1 PALcode Specific]  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_IF_CODE_BPT
value|0
end_define

begin_define
define|#
directive|define
name|ALPHA_IF_CODE_BUGCHK
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_IF_CODE_GENTRAP
value|2
end_define

begin_define
define|#
directive|define
name|ALPHA_IF_CODE_FEN
value|3
end_define

begin_define
define|#
directive|define
name|ALPHA_IF_CODE_OPDEC
value|4
end_define

begin_comment
comment|/*  * Translation Buffer Invalidation definitions [OSF/1 PALcode Specific]  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_TBIA
parameter_list|()
value|alpha_pal_tbi(-2, 0)
end_define

begin_comment
comment|/* all TB entries */
end_comment

begin_define
define|#
directive|define
name|ALPHA_TBIAP
parameter_list|()
value|alpha_pal_tbi(-1, 0)
end_define

begin_comment
comment|/* all per-process */
end_comment

begin_define
define|#
directive|define
name|ALPHA_TBISI
parameter_list|(
name|va
parameter_list|)
value|alpha_pal_tbi(1, (va))
end_define

begin_comment
comment|/* ITB entry for va */
end_comment

begin_define
define|#
directive|define
name|ALPHA_TBISD
parameter_list|(
name|va
parameter_list|)
value|alpha_pal_tbi(2, (va))
end_define

begin_comment
comment|/* DTB entry for va */
end_comment

begin_define
define|#
directive|define
name|ALPHA_TBIS
parameter_list|(
name|va
parameter_list|)
value|alpha_pal_tbi(3, (va))
end_define

begin_comment
comment|/* all for va */
end_comment

begin_comment
comment|/*  * Bits used in the amask instruction [EV56 and later]  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_AMASK_BWX
value|0x0001
end_define

begin_comment
comment|/* byte/word extension */
end_comment

begin_define
define|#
directive|define
name|ALPHA_AMASK_FIX
value|0x0002
end_define

begin_comment
comment|/* sqrt and f<-> i conversion extension */
end_comment

begin_define
define|#
directive|define
name|ALPHA_AMASK_CIX
value|0x0004
end_define

begin_comment
comment|/* count extension */
end_comment

begin_define
define|#
directive|define
name|ALPHA_AMASK_MVI
value|0x0100
end_define

begin_comment
comment|/* multimedia extension */
end_comment

begin_define
define|#
directive|define
name|ALPHA_AMASK_PRECISE
value|0x0200
end_define

begin_comment
comment|/* Precise arithmetic traps */
end_comment

begin_comment
comment|/*  * Chip family IDs returned by implver instruction  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_IMPLVER_EV4
value|0
end_define

begin_comment
comment|/* LCA/EV4/EV45 */
end_comment

begin_define
define|#
directive|define
name|ALPHA_IMPLVER_EV5
value|1
end_define

begin_comment
comment|/* EV5/EV56/PCA56 */
end_comment

begin_define
define|#
directive|define
name|ALPHA_IMPLVER_EV6
value|2
end_define

begin_comment
comment|/* EV6 */
end_comment

begin_comment
comment|/*  * Inlines for Alpha instructions normally inaccessible from C.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int64_t
name|alpha_amask
parameter_list|(
name|u_int64_t
name|mask
parameter_list|)
block|{
name|u_int64_t
name|result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"amask %1,%0" 		: "=r" (result) 		: "r" (mask));
return|return
name|result
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|alpha_implver
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int64_t
name|result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"implver %0" 		: "=r" (result));
return|return
name|result
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|alpha_rpcc
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int64_t
name|result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"rpcc %0" 		: "=r" (result));
return|return
name|result
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_mb
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("mb");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_wmb
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * XXX dfr: NetBSD originally had mb instead of wmb for 	 * alpha_wmb(). I'm not sure why so I'm leaving it alone. I 	 * think it should be safe to use wmb though. 	 */
asm|__asm__
specifier|__volatile__
asm|("mb");
block|}
end_function

begin_comment
comment|/*  * Inlines for OSF/1 PALcode operations.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_halt
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("call_pal 0x0 #PAL_halt");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_cflush
parameter_list|(
name|u_int64_t
name|pfn
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|pfn
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x1 #PAL_cflush" 		: 		: "r" (a0));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_draina
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("call_pal 0x2 #PAL_draina" : : : "memory");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_wripir
parameter_list|(
name|u_int64_t
name|ipir
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|ipir
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0xd #PAL_ipir" 		: "=r" (a0) 		: "0" (a0) 		: "$1", "$22", "$23", "$24", "$25");
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|alpha_pal_rdmces
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|v0
name|__asm__
argument_list|(
literal|"$0"
argument_list|)
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x10 #PAL_OSF1_rdmces" 		: "=r" (v0) 		: 		: "$1", "$22", "$23", "$24", "$25");
return|return
name|v0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_wrmces
parameter_list|(
name|u_int64_t
name|mces
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|mces
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x11 #PAL_wrmces" 		: "=r" (a0) 		: "0" (a0) 		: "$1", "$22", "$23", "$24", "$25");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_wrfen
parameter_list|(
name|u_int64_t
name|fen
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|fen
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x2b #PAL_wrfen" 		: "=r" (a0) 		: "0" (a0) 		: "$1", "$22", "$23", "$24", "$25");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_wrvptptr
parameter_list|(
name|u_int64_t
name|vptptr
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|vptptr
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x2d #PAL_wrvptptr" 		: "=r" (a0) 		: "0" (a0) 		: "$1", "$22", "$23", "$24", "$25");
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|alpha_pal_swpctx
parameter_list|(
name|u_int64_t
name|pcb
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|pcb
decl_stmt|;
specifier|register
name|u_int64_t
name|v0
name|__asm__
argument_list|(
literal|"$0"
argument_list|)
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x30 #PAL_OSF1_swpctx" 		: "=r" (v0), "=r" (a0) 		: "1" (a0) 		: "$1", "$22", "$23", "$24", "$25", "memory");
return|return
name|v0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_wrval
parameter_list|(
name|u_int64_t
name|sysvalue
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|sysvalue
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x31 #PAL_wrval" 		: "=r" (a0) 		: "0" (a0) 		: "$1", "$22", "$23", "$24", "$25");
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|alpha_pal_rdval
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|v0
name|__asm__
argument_list|(
literal|"$0"
argument_list|)
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x32 #PAL_OSF1_rdval" 		: "=r" (v0) 		: 		: "$1", "$22", "$23", "$24", "$25");
return|return
name|v0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_tbi
parameter_list|(
name|u_int64_t
name|op
parameter_list|,
name|u_int64_t
name|va
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|op
decl_stmt|;
specifier|register
name|u_int64_t
name|a1
name|__asm__
argument_list|(
literal|"$17"
argument_list|)
init|=
name|va
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x33 #PAL_OSF1_tbi" 		: "=r" (a0), "=r" (a1) 		: "0" (a0), "1" (a1) 		: "$1", "$22", "$23", "$24", "$25");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_wrent
parameter_list|(
name|void
modifier|*
name|ent
parameter_list|,
name|u_int64_t
name|which
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
operator|(
name|u_int64_t
operator|)
name|ent
decl_stmt|;
specifier|register
name|u_int64_t
name|a1
name|__asm__
argument_list|(
literal|"$17"
argument_list|)
init|=
name|which
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x34 #PAL_OSF1_wrent" 		: "=r" (a0), "=r" (a1) 		: "0" (a0), "1" (a1) 		: "$1", "$22", "$23", "$24", "$25");
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|alpha_pal_swpipl
parameter_list|(
name|u_int64_t
name|newipl
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|newipl
decl_stmt|;
specifier|register
name|u_int64_t
name|v0
name|__asm__
argument_list|(
literal|"$0"
argument_list|)
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x35 #PAL_OSF1_swpipl" 		: "=r" (v0), "=r" (a0) 		: "1" (a0) 		: "$1", "$22", "$23", "$24", "$25");
return|return
name|v0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|alpha_pal_rdps
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|v0
name|__asm__
argument_list|(
literal|"$0"
argument_list|)
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x36 #PAL_OSF1_rdps" 		: "=r" (v0) 		: 		: "$1", "$22", "$23", "$24", "$25");
return|return
name|v0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_wrusp
parameter_list|(
name|u_int64_t
name|usp
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|usp
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x38 #PAL_wrusp" 		: "=r" (a0) 		: "0" (a0) 		: "$1", "$22", "$23", "$24", "$25");
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|alpha_pal_wrperfmon
parameter_list|(
name|u_int64_t
name|arg0
parameter_list|,
name|u_int64_t
name|arg1
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|v0
name|__asm__
argument_list|(
literal|"$0"
argument_list|)
decl_stmt|;
specifier|register
name|u_int64_t
name|a0
name|__asm__
argument_list|(
literal|"$16"
argument_list|)
init|=
name|arg0
decl_stmt|;
specifier|register
name|u_int64_t
name|a1
name|__asm__
argument_list|(
literal|"$17"
argument_list|)
init|=
name|arg1
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x39 #PAL_OSF1_wrperfmon" 		: "=r" (a0), "=r" (a1), "=r" (v0) 		: "0" (a0), "1" (a1) 		: "$1", "$22", "$23", "$24", "$25");
return|return
name|v0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|alpha_pal_rdusp
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|v0
name|__asm__
argument_list|(
literal|"$0"
argument_list|)
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x3a #PAL_OSF1_rdusp" 		: "=r" (v0) 		: 		: "$1", "$22", "$23", "$24", "$25");
return|return
name|v0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|alpha_pal_whami
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|v0
name|__asm__
argument_list|(
literal|"$0"
argument_list|)
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		"call_pal 0x3c #PAL_OSF1_whami" 		: "=r" (v0) 		: 		: "$1", "$22", "$23", "$24", "$25");
return|return
name|v0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|alpha_pal_imb
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("call_pal 0x86 #PAL_imb");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ALPHA_ALPHA_CPU_H__ */
end_comment

end_unit

