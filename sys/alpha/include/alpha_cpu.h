begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
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

begin_define
define|#
directive|define
name|ALPHA_PGBYTES
value|(1<< ALPHA_PGSHIFT)
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
value|0x000003ffffffffff
end_define

begin_define
define|#
directive|define
name|ALPHA_K0SEG_BASE
value|0xfffffc0000000000
end_define

begin_comment
comment|/* direct-mapped */
end_comment

begin_define
define|#
directive|define
name|ALPHA_K0SEG_END
value|0xfffffdffffffffff
end_define

begin_define
define|#
directive|define
name|ALPHA_K1SEG_BASE
value|0xfffffe0000000000
end_define

begin_comment
comment|/* virtual */
end_comment

begin_define
define|#
directive|define
name|ALPHA_K1SEG_END
value|0xffffffffffffffff
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
value|((pte)>> 32)
end_define

begin_define
define|#
directive|define
name|ALPHA_PTE_FROM_PFN
parameter_list|(
name|pfn
parameter_list|)
value|((pfn)<< 32)
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
name|ALPHA_AMASK_CIX
value|0x0002
end_define

begin_comment
comment|/* count extension */
end_comment

begin_define
define|#
directive|define
name|ALPHA_AMASK_MAX
value|0x0100
end_define

begin_comment
comment|/* multimedia extension */
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
comment|/*  * Stubs for Alpha instructions normally inaccessible from C.  */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|alpha_amask
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|alpha_implver
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|alpha_rpcc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_mb
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_wmb
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|alpha_ldbu
name|__P
argument_list|(
operator|(
specifier|volatile
name|u_int8_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int16_t
name|alpha_ldwu
name|__P
argument_list|(
operator|(
specifier|volatile
name|u_int16_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_stb
name|__P
argument_list|(
operator|(
specifier|volatile
name|u_int8_t
operator|*
operator|,
name|u_int8_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_stw
name|__P
argument_list|(
operator|(
specifier|volatile
name|u_int16_t
operator|*
operator|,
name|u_int16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|alpha_sextb
name|__P
argument_list|(
operator|(
name|u_int8_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int16_t
name|alpha_sextw
name|__P
argument_list|(
operator|(
name|u_int16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Stubs for OSF/1 PALcode operations.  */
end_comment

begin_decl_stmt
name|void
name|alpha_pal_imb
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_cflush
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_draina
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_halt
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|__noreturn__
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|alpha_pal_rdmces
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|alpha_pal_rdps
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|alpha_pal_rdusp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|alpha_pal_rdval
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|alpha_pal_swpipl
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|_alpha_pal_swpipl
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for profiling */
end_comment

begin_decl_stmt
name|void
name|alpha_pal_tbi
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|alpha_pal_whami
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_wrent
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_wrfen
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_wripir
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_wrusp
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_wrvptptr
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_wrmces
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alpha_pal_wrval
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ALPHA_ALPHA_CPU_H__ */
end_comment

end_unit

