begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell, and Kazumasa Utashiro of Software Research  * Associates, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)machConst.h	7.2 (Berkeley) %G%  *  * machConst.h --  *  *	Machine dependent constants.  *  *	Copyright (C) 1989 Digital Equipment Corporation.  *	Permission to use, copy, modify, and distribute this software and  *	its documentation for any purpose and without fee is hereby granted,  *	provided that the above copyright notice appears in all copies.  *	Digital Equipment Corporation makes no representations about the  *	suitability of this software for any purpose.  It is provided "as is"  *	without express or implied warranty.  *  * from: $Header: /sprite/src/kernel/mach/ds3100.md/RCS/machConst.h,  *	v 9.2 89/10/21 15:55:22 jhh Exp $ SPRITE (DECWRL)  * from: $Header: /sprite/src/kernel/mach/ds3100.md/RCS/machAddrs.h,  *	v 1.2 89/08/15 18:28:21 rab Exp $ SPRITE (DECWRL)  * from: $Header: /sprite/src/kernel/vm/ds3100.md/RCS/vmPmaxConst.h,  *	v 9.1 89/09/18 17:33:00 shirriff Exp $ SPRITE (DECWRL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHCONST
end_ifndef

begin_define
define|#
directive|define
name|_MACHCONST
end_define

begin_define
define|#
directive|define
name|MACH_KUSEG_ADDR
value|0x0
end_define

begin_define
define|#
directive|define
name|MACH_CACHED_MEMORY_ADDR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MACH_UNCACHED_MEMORY_ADDR
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|MACH_KSEG2_ADDR
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|MACH_CACHED_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|MACH_UNMAPPED_TO_PHYS(x)
end_define

begin_define
define|#
directive|define
name|MACH_UNCACHED_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|MACH_UNMAPPED_TO_PHYS(x)
end_define

begin_define
define|#
directive|define
name|MACH_UNMAPPED_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)& 0x1fffffff)
end_define

begin_define
define|#
directive|define
name|MACH_PHYS_TO_CACHED
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x) | MACH_CACHED_MEMORY_ADDR)
end_define

begin_define
define|#
directive|define
name|MACH_PHYS_TO_UNCACHED
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x) | MACH_UNCACHED_MEMORY_ADDR)
end_define

begin_define
define|#
directive|define
name|MACH_CACHED_TO_UNCACHED
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x) | MACH_UNCACHED_MEMORY_ADDR)
end_define

begin_define
define|#
directive|define
name|MACH_UNCACHED_TO_CACHED
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)& 0x9fffffff)
end_define

begin_define
define|#
directive|define
name|BETWEEN
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((unsigned)(x)>= (a)&& (unsigned)(x)< (b))
end_define

begin_define
define|#
directive|define
name|MACH_IS_UNMAPPED
parameter_list|(
name|x
parameter_list|)
define|\
value|BETWEEN(x, MACH_CACHED_MEMORY_ADDR, MACH_KSEG2_ADDR)
end_define

begin_define
define|#
directive|define
name|MACH_IS_CACHED
parameter_list|(
name|x
parameter_list|)
define|\
value|BETWEEN(x, MACH_CACHED_MEMORY_ADDR, MACH_UNCACHED_MEMORY_ADDR)
end_define

begin_define
define|#
directive|define
name|MACH_IS_UNCACHED
parameter_list|(
name|x
parameter_list|)
define|\
value|BETWEEN(x, MACH_UNCACHED_MEMORY_ADDR, MACH_KSEG2_ADDR)
end_define

begin_define
define|#
directive|define
name|MACH_IS_MAPPED
parameter_list|(
name|x
parameter_list|)
define|\
value|BETWEEN(x, MACH_CACHED_MEMORY_ADDR, MACH_KSEG2_ADDR)
end_define

begin_define
define|#
directive|define
name|MACH_IS_USPACE
parameter_list|(
name|x
parameter_list|)
define|\
value|((unsigned)(x)< MACH_CACHED_MEMORY_ADDR)
end_define

begin_define
define|#
directive|define
name|MACH_CODE_START
value|0x80001000
end_define

begin_define
define|#
directive|define
name|MACH_RESERVED_ADDR
value|0xb3000000
end_define

begin_comment
comment|/* KU:XXX need this? */
end_comment

begin_define
define|#
directive|define
name|MACH_KERNWORK_ADDR
value|0x800001c0
end_define

begin_define
define|#
directive|define
name|MACH_MAXMEMSIZE_ADDR
value|(MACH_KERNWORK_ADDR + 0 * 4)
end_define

begin_define
define|#
directive|define
name|MACH_BOOTSW_ADDR
value|(MACH_KERNWORK_ADDR + 1 * 4)
end_define

begin_define
define|#
directive|define
name|MACH_BOOTDEV_ADDR
value|(MACH_KERNWORK_ADDR + 2 * 4)
end_define

begin_define
define|#
directive|define
name|MACH_HOWTO_ADDR
value|(MACH_KERNWORK_ADDR + 3 * 4)
end_define

begin_define
define|#
directive|define
name|MACH_BP_ADDR
value|(MACH_KERNWORK_ADDR + 4 * 4)
end_define

begin_define
define|#
directive|define
name|MACH_MONARG_ADDR
value|(MACH_KERNWORK_ADDR + 5 * 4)
end_define

begin_comment
comment|/*  * The bits in the cause register.  *  *	MACH_CR_BR_DELAY	Exception happened in branch delay slot.  *	MACH_CR_COP_ERR		Coprocessor error.  *				Interrupt pending bits defined below.  *	MACH_CR_EXC_CODE	The exception type (see exception codes below).  */
end_comment

begin_define
define|#
directive|define
name|MACH_CR_BR_DELAY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MACH_CR_COP_ERR
value|0x30000000
end_define

begin_define
define|#
directive|define
name|MACH_CR_EXC_CODE
value|0x0000003C
end_define

begin_define
define|#
directive|define
name|MACH_CR_EXC_CODE_SHIFT
value|2
end_define

begin_comment
comment|/*  * The bits in the status register.  All bits are active when set to 1.  *  *	MACH_SR_CO_USABILITY	Control the usability of the four coprocessors.  *	MACH_SR_BOOT_EXC_VEC	Use alternate exception vectors.  *	MACH_SR_TLB_SHUTDOWN	TLB disabled.  *	MACH_SR_PARITY_ERR	Parity error.  *	MACH_SR_CACHE_MISS	Most recent D-cache load resulted in a miss.  *	MACH_SR_PARITY_ZERO	Zero replaces outgoing parity bits.  *	MACH_SR_SWAP_CACHES	Swap I-cache and D-cache.  *	MACH_SR_ISOL_CACHES	Isolate D-cache from main memory.  *				Interrupt enable bits defined below.  *	MACH_SR_KU_OLD		Old kernel/user mode bit. 1 => user mode.  *	MACH_SR_INT_ENA_OLD	Old interrupt enable bit.  *	MACH_SR_KU_PREV		Previous kernel/user mode bit. 1 => user mode.  *	MACH_SR_INT_ENA_PREV	Previous interrupt enable bit.  *	MACH_SR_KU_CUR		Current kernel/user mode bit. 1 => user mode.  *	MACH_SR_INT_ENA_CUR	Current interrupt enable bit.  */
end_comment

begin_define
define|#
directive|define
name|MACH_SR_COP_USABILITY
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|MACH_SR_COP_0_BIT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MACH_SR_COP_1_BIT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|MACH_SR_BOOT_EXC_VEC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|MACH_SR_TLB_SHUTDOWN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|MACH_SR_PARITY_ERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|MACH_SR_CACHE_MISS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MACH_SR_PARITY_ZERO
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MACH_SR_SWAP_CACHES
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MACH_SR_ISOL_CACHES
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MACH_SR_KU_OLD
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MACH_SR_INT_ENA_OLD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MACH_SR_KU_PREV
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MACH_SR_INT_ENA_PREV
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MACH_SR_KU_CUR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MACH_SR_INT_ENA_CUR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MACH_SR_MBZ
value|0x0f8000c0
end_define

begin_comment
comment|/*  * The interrupt masks.  * If a bit in the mask is 1 then the interrupt is enabled (or pending).  */
end_comment

begin_define
define|#
directive|define
name|MACH_INT_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|MACH_INT_MASK_5
value|0x8000
end_define

begin_define
define|#
directive|define
name|MACH_INT_MASK_4
value|0x4000
end_define

begin_define
define|#
directive|define
name|MACH_INT_MASK_3
value|0x2000
end_define

begin_define
define|#
directive|define
name|MACH_INT_MASK_2
value|0x1000
end_define

begin_define
define|#
directive|define
name|MACH_INT_MASK_1
value|0x0800
end_define

begin_define
define|#
directive|define
name|MACH_INT_MASK_0
value|0x0400
end_define

begin_define
define|#
directive|define
name|MACH_HARD_INT_MASK
value|0xfc00
end_define

begin_define
define|#
directive|define
name|MACH_SOFT_INT_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|MACH_SOFT_INT_MASK_1
value|0x0200
end_define

begin_define
define|#
directive|define
name|MACH_SOFT_INT_MASK_0
value|0x0100
end_define

begin_define
define|#
directive|define
name|MACH_SPL_MASK_8
value|0x0000
end_define

begin_define
define|#
directive|define
name|MACH_SPL_MASK_7
value|MACH_SPL_MASK_8 | MACH_INT_MASK_5
end_define

begin_define
define|#
directive|define
name|MACH_SPL_MASK_6
value|MACH_SPL_MASK_7 | MACH_INT_MASK_4
end_define

begin_define
define|#
directive|define
name|MACH_SPL_MASK_5
value|MACH_SPL_MASK_6 | MACH_INT_MASK_3
end_define

begin_define
define|#
directive|define
name|MACH_SPL_MASK_4
value|MACH_SPL_MASK_5 | MACH_INT_MASK_2
end_define

begin_define
define|#
directive|define
name|MACH_SPL_MASK_3
value|MACH_SPL_MASK_4 | MACH_INT_MASK_1
end_define

begin_define
define|#
directive|define
name|MACH_SPL_MASK_2
value|MACH_SPL_MASK_3 | MACH_INT_MASK_0
end_define

begin_define
define|#
directive|define
name|MACH_SPL_MASK_1
value|MACH_SPL_MASK_2 | MACH_SOFT_INT_MASK_1
end_define

begin_define
define|#
directive|define
name|MACH_SPL_MASK_0
value|MACH_SPL_MASK_1 | MACH_SOFT_INT_MASK_0
end_define

begin_comment
comment|/*  * The system control status register.  */
end_comment

begin_comment
comment|/*  * The bits in the context register.  */
end_comment

begin_define
define|#
directive|define
name|MACH_CNTXT_PTE_BASE
value|0xFFE00000
end_define

begin_define
define|#
directive|define
name|MACH_CNTXT_BAD_VPN
value|0x001FFFFC
end_define

begin_comment
comment|/*  * Location of exception vectors.  */
end_comment

begin_define
define|#
directive|define
name|MACH_RESET_EXC_VEC
value|0xBFC00000
end_define

begin_define
define|#
directive|define
name|MACH_UTLB_MISS_EXC_VEC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MACH_GEN_EXC_VEC
value|0x80000080
end_define

begin_comment
comment|/*  * Coprocessor 0 registers:  *  *	MACH_COP_0_TLB_INDEX	TLB index.  *	MACH_COP_0_TLB_RANDOM	TLB random.  *	MACH_COP_0_TLB_LOW	TLB entry low.  *	MACH_COP_0_TLB_CONTEXT	TLB context.  *	MACH_COP_0_BAD_VADDR	Bad virtual address.  *	MACH_COP_0_TLB_HI	TLB entry high.  *	MACH_COP_0_STATUS_REG	Status register.  *	MACH_COP_0_CAUSE_REG	Exception cause register.  *	MACH_COP_0_EXC_PC	Exception PC.  *	MACH_COP_0_PRID		Processor revision identifier.  */
end_comment

begin_define
define|#
directive|define
name|MACH_COP_0_TLB_INDEX
value|$0
end_define

begin_define
define|#
directive|define
name|MACH_COP_0_TLB_RANDOM
value|$1
end_define

begin_define
define|#
directive|define
name|MACH_COP_0_TLB_LOW
value|$2
end_define

begin_define
define|#
directive|define
name|MACH_COP_0_TLB_CONTEXT
value|$4
end_define

begin_define
define|#
directive|define
name|MACH_COP_0_BAD_VADDR
value|$8
end_define

begin_define
define|#
directive|define
name|MACH_COP_0_TLB_HI
value|$10
end_define

begin_define
define|#
directive|define
name|MACH_COP_0_STATUS_REG
value|$12
end_define

begin_define
define|#
directive|define
name|MACH_COP_0_CAUSE_REG
value|$13
end_define

begin_define
define|#
directive|define
name|MACH_COP_0_EXC_PC
value|$14
end_define

begin_define
define|#
directive|define
name|MACH_COP_0_PRID
value|$15
end_define

begin_comment
comment|/*  * Values for the code field in a break instruction.  */
end_comment

begin_define
define|#
directive|define
name|MACH_BREAK_INSTR
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|MACH_BREAK_VAL_MASK
value|0x03ff0000
end_define

begin_define
define|#
directive|define
name|MACH_BREAK_VAL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MACH_BREAK_KDB_VAL
value|512
end_define

begin_define
define|#
directive|define
name|MACH_BREAK_SSTEP_VAL
value|513
end_define

begin_define
define|#
directive|define
name|MACH_BREAK_BRKPT_VAL
value|514
end_define

begin_define
define|#
directive|define
name|MACH_BREAK_KDB
value|(MACH_BREAK_INSTR | \ 				(MACH_BREAK_KDB_VAL<< MACH_BREAK_VAL_SHIFT))
end_define

begin_define
define|#
directive|define
name|MACH_BREAK_SSTEP
value|(MACH_BREAK_INSTR | \ 				(MACH_BREAK_SSTEP_VAL<< MACH_BREAK_VAL_SHIFT))
end_define

begin_define
define|#
directive|define
name|MACH_BREAK_BRKPT
value|(MACH_BREAK_INSTR | \ 				(MACH_BREAK_BRKPT_VAL<< MACH_BREAK_VAL_SHIFT))
end_define

begin_comment
comment|/*  * Mininum and maximum cache sizes.  */
end_comment

begin_define
define|#
directive|define
name|MACH_MIN_CACHE_SIZE
value|(16 * 1024)
end_define

begin_define
define|#
directive|define
name|MACH_MAX_CACHE_SIZE
value|(256 * 1024)
end_define

begin_comment
comment|/*  * The floating point version and status registers.  */
end_comment

begin_define
define|#
directive|define
name|MACH_FPC_ID
value|$0
end_define

begin_define
define|#
directive|define
name|MACH_FPC_CSR
value|$31
end_define

begin_comment
comment|/*  * The floating point coprocessor status register bits.  */
end_comment

begin_define
define|#
directive|define
name|MACH_FPC_ROUNDING_BITS
value|0x00000003
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ROUND_RN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ROUND_RZ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ROUND_RP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ROUND_RM
value|0x00000003
end_define

begin_define
define|#
directive|define
name|MACH_FPC_STICKY_BITS
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|MACH_FPC_STICKY_INEXACT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MACH_FPC_STICKY_UNDERFLOW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MACH_FPC_STICKY_OVERFLOW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MACH_FPC_STICKY_DIV0
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MACH_FPC_STICKY_INVALID
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ENABLE_BITS
value|0x00000f80
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ENABLE_INEXACT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ENABLE_UNDERFLOW
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ENABLE_OVERFLOW
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ENABLE_DIV0
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MACH_FPC_ENABLE_INVALID
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MACH_FPC_EXCEPTION_BITS
value|0x0003f000
end_define

begin_define
define|#
directive|define
name|MACH_FPC_EXCEPTION_INEXACT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MACH_FPC_EXCEPTION_UNDERFLOW
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MACH_FPC_EXCEPTION_OVERFLOW
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MACH_FPC_EXCEPTION_DIV0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MACH_FPC_EXCEPTION_INVALID
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MACH_FPC_EXCEPTION_UNIMPL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MACH_FPC_COND_BIT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|MACH_FPC_MBZ_BITS
value|0xff7c0000
end_define

begin_comment
comment|/*  * Constants to determine if have a floating point instruction.  */
end_comment

begin_define
define|#
directive|define
name|MACH_OPCODE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|MACH_OPCODE_C1
value|0x11
end_define

begin_comment
comment|/*  * The low part of the TLB entry.  */
end_comment

begin_define
define|#
directive|define
name|VMMACH_TLB_PF_NUM
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_NON_CACHEABLE_BIT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_MOD_BIT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_VALID_BIT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_GLOBAL_BIT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_PHYS_PAGE_SHIFT
value|12
end_define

begin_comment
comment|/*  * The high part of the TLB entry.  */
end_comment

begin_define
define|#
directive|define
name|VMMACH_TLB_VIRT_PAGE_NUM
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_PID
value|0x00000fc0
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_PID_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_VIRT_PAGE_SHIFT
value|12
end_define

begin_comment
comment|/*  * The shift to put the index in the right spot.  */
end_comment

begin_define
define|#
directive|define
name|VMMACH_TLB_INDEX_SHIFT
value|8
end_define

begin_comment
comment|/*  * The number of TLB entries and the first one that write random hits.  */
end_comment

begin_define
define|#
directive|define
name|VMMACH_NUM_TLB_ENTRIES
value|64
end_define

begin_define
define|#
directive|define
name|VMMACH_FIRST_RAND_ENTRY
value|8
end_define

begin_comment
comment|/*  * The number of process id entries.  */
end_comment

begin_define
define|#
directive|define
name|VMMACH_NUM_PIDS
value|64
end_define

begin_comment
comment|/*  * TLB probe return codes.  */
end_comment

begin_define
define|#
directive|define
name|VMMACH_TLB_NOT_FOUND
value|0
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_FOUND_WITH_PATCH
value|2
end_define

begin_define
define|#
directive|define
name|VMMACH_TLB_PROBE_ERROR
value|3
end_define

begin_comment
comment|/*  * Kernel virtual address for user page table entries  * (i.e., the address for the context register).  */
end_comment

begin_define
define|#
directive|define
name|VMMACH_PTE_BASE
value|0xFFC00000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHCONST */
end_comment

end_unit

