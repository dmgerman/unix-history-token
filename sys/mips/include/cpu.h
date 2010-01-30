begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: cpu.h,v 1.4 1998/09/15 10:50:12 pefo Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	Copyright (C) 1989 Digital Equipment Corporation.  *	Permission to use, copy, modify, and distribute this software and  *	its documentation for any purpose and without fee is hereby granted,  *	provided that the above copyright notice appears in all copies.  *	Digital Equipment Corporation makes no representations about the  *	suitability of this software for any purpose.  It is provided "as is"  *	without express or implied warranty.  *  *	from: @(#)cpu.h	8.4 (Berkeley) 1/4/94  *	JNPR: cpu.h,v 1.9.2.2 2007/09/10 08:23:46 girish  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPU_H_
end_define

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_define
define|#
directive|define
name|MIPS_CACHED_MEMORY_ADDR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MIPS_UNCACHED_MEMORY_ADDR
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|MIPS_MAX_MEM_ADDR
value|0xbe000000
end_define

begin_define
define|#
directive|define
name|MIPS_RESERVED_ADDR
value|0xbfc80000
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG0_LARGEST_PHYS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|MIPS_CACHED_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x)& 0x1fffffff)
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_CACHED
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x) | MIPS_CACHED_MEMORY_ADDR)
end_define

begin_define
define|#
directive|define
name|MIPS_UNCACHED_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x)& 0x1fffffff)
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_UNCACHED
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x) | MIPS_UNCACHED_MEMORY_ADDR)
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_MASK
value|(0x1fffffff)
end_define

begin_define
define|#
directive|define
name|MIPS_PA_2_K1VA
parameter_list|(
name|x
parameter_list|)
value|(MIPS_KSEG1_START | ((x)& MIPS_PHYS_MASK))
end_define

begin_define
define|#
directive|define
name|MIPS_VA_TO_CINDEX
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x)& 0xffffff | MIPS_CACHED_MEMORY_ADDR)
end_define

begin_define
define|#
directive|define
name|MIPS_CACHED_TO_UNCACHED
parameter_list|(
name|x
parameter_list|)
value|(MIPS_PHYS_TO_UNCACHED(MIPS_CACHED_TO_PHYS(x)))
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_KSEG0
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x) | MIPS_KSEG0_START)
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_KSEG1
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x) | MIPS_KSEG1_START)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG0_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x)& MIPS_PHYS_MASK)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG1_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x)& MIPS_PHYS_MASK)
end_define

begin_define
define|#
directive|define
name|MIPS_IS_KSEG0_ADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((vm_offset_t)(x)>= MIPS_KSEG0_START)&&		\ 	    ((vm_offset_t)(x)<= MIPS_KSEG0_END))
end_define

begin_define
define|#
directive|define
name|MIPS_IS_KSEG1_ADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((vm_offset_t)(x)>= MIPS_KSEG1_START)&&		\ 	    ((vm_offset_t)(x)<= MIPS_KSEG1_END))
end_define

begin_define
define|#
directive|define
name|MIPS_IS_VALID_PTR
parameter_list|(
name|x
parameter_list|)
value|(MIPS_IS_KSEG0_ADDR(x) || \ 						MIPS_IS_KSEG1_ADDR(x))
end_define

begin_comment
comment|/*  *  Status register.  */
end_comment

begin_define
define|#
directive|define
name|SR_COP_USABILITY
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|SR_COP_0_BIT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SR_COP_1_BIT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SR_COP_2_BIT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SR_RP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SR_FR_32
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SR_RE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SR_PX
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SR_BOOT_EXC_VEC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SR_TLB_SHUTDOWN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SR_SOFT_RESET
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SR_DIAG_CH
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SR_DIAG_CE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SR_DIAG_DE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SR_KX
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SR_SX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SR_UX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SR_KSU_MASK
value|0x00000018
end_define

begin_define
define|#
directive|define
name|SR_KSU_USER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SR_KSU_SUPER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SR_KSU_KERNEL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SR_ERL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SR_EXL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SR_INT_ENAB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SR_INT_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|SOFT_INT_MASK_0
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SOFT_INT_MASK_1
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SR_INT_MASK_0
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SR_INT_MASK_1
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SR_INT_MASK_2
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SR_INT_MASK_3
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SR_INT_MASK_4
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SR_INT_MASK_5
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ALL_INT_MASK
value|SR_INT_MASK
end_define

begin_define
define|#
directive|define
name|SOFT_INT_MASK
value|(SOFT_INT_MASK_0 | SOFT_INT_MASK_1)
end_define

begin_define
define|#
directive|define
name|HW_INT_MASK
value|(ALL_INT_MASK& ~SOFT_INT_MASK)
end_define

begin_comment
comment|/*  * The bits in the cause register.  *  *	CR_BR_DELAY	Exception happened in branch delay slot.  *	CR_COP_ERR	Coprocessor error.  *	CR_IP		Interrupt pending bits defined below.  *	CR_EXC_CODE	The exception type (see exception codes below).  */
end_comment

begin_define
define|#
directive|define
name|CR_BR_DELAY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CR_COP_ERR
value|0x30000000
end_define

begin_define
define|#
directive|define
name|CR_EXC_CODE
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|CR_EXC_CODE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|CR_IPEND
value|0x0000ff00
end_define

begin_comment
comment|/*  * Cause Register Format:  *  *   31  30  29 28 27  26  25  24 23                   8  7 6       2  1  0  *  ----------------------------------------------------------------------  * | BD | 0| CE   | 0| W2| W1| IV|	IP15 - IP0	| 0| Exc Code | 0|  * |______________________________________________________________________  */
end_comment

begin_define
define|#
directive|define
name|CR_INT_SOFT0
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CR_INT_SOFT1
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CR_INT_0
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CR_INT_1
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CR_INT_2
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CR_INT_3
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CR_INT_4
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CR_INT_5
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CR_INT_UART
value|CR_INT_1
end_define

begin_define
define|#
directive|define
name|CR_INT_IPI
value|CR_INT_2
end_define

begin_define
define|#
directive|define
name|CR_INT_CLOCK
value|CR_INT_5
end_define

begin_comment
comment|/*  * The bits in the CONFIG register  */
end_comment

begin_define
define|#
directive|define
name|CFG_K0_UNCACHED
value|2
end_define

begin_define
define|#
directive|define
name|CFG_K0_CACHED
value|3
end_define

begin_define
define|#
directive|define
name|CFG_K0_MASK
value|0x7
end_define

begin_comment
comment|/*  * The bits in the context register.  */
end_comment

begin_define
define|#
directive|define
name|CNTXT_PTE_BASE
value|0xff800000
end_define

begin_define
define|#
directive|define
name|CNTXT_BAD_VPN2
value|0x007ffff0
end_define

begin_comment
comment|/*  * Location of exception vectors.  */
end_comment

begin_define
define|#
directive|define
name|RESET_EXC_VEC
value|0xbfc00000
end_define

begin_define
define|#
directive|define
name|TLB_MISS_EXC_VEC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|XTLB_MISS_EXC_VEC
value|0x80000080
end_define

begin_define
define|#
directive|define
name|CACHE_ERR_EXC_VEC
value|0x80000100
end_define

begin_define
define|#
directive|define
name|GEN_EXC_VEC
value|0x80000180
end_define

begin_comment
comment|/*  * Coprocessor 0 registers:  */
end_comment

begin_define
define|#
directive|define
name|COP_0_TLB_INDEX
value|$0
end_define

begin_define
define|#
directive|define
name|COP_0_TLB_RANDOM
value|$1
end_define

begin_define
define|#
directive|define
name|COP_0_TLB_LO0
value|$2
end_define

begin_define
define|#
directive|define
name|COP_0_TLB_LO1
value|$3
end_define

begin_define
define|#
directive|define
name|COP_0_TLB_CONTEXT
value|$4
end_define

begin_define
define|#
directive|define
name|COP_0_TLB_PG_MASK
value|$5
end_define

begin_define
define|#
directive|define
name|COP_0_TLB_WIRED
value|$6
end_define

begin_define
define|#
directive|define
name|COP_0_INFO
value|$7
end_define

begin_define
define|#
directive|define
name|COP_0_BAD_VADDR
value|$8
end_define

begin_define
define|#
directive|define
name|COP_0_COUNT
value|$9
end_define

begin_define
define|#
directive|define
name|COP_0_TLB_HI
value|$10
end_define

begin_define
define|#
directive|define
name|COP_0_COMPARE
value|$11
end_define

begin_define
define|#
directive|define
name|COP_0_STATUS_REG
value|$12
end_define

begin_define
define|#
directive|define
name|COP_0_CAUSE_REG
value|$13
end_define

begin_define
define|#
directive|define
name|COP_0_EXC_PC
value|$14
end_define

begin_define
define|#
directive|define
name|COP_0_PRID
value|$15
end_define

begin_define
define|#
directive|define
name|COP_0_CONFIG
value|$16
end_define

begin_define
define|#
directive|define
name|COP_0_LLADDR
value|$17
end_define

begin_define
define|#
directive|define
name|COP_0_WATCH_LO
value|$18
end_define

begin_define
define|#
directive|define
name|COP_0_WATCH_HI
value|$19
end_define

begin_define
define|#
directive|define
name|COP_0_TLB_XCONTEXT
value|$20
end_define

begin_define
define|#
directive|define
name|COP_0_ECC
value|$26
end_define

begin_define
define|#
directive|define
name|COP_0_CACHE_ERR
value|$27
end_define

begin_define
define|#
directive|define
name|COP_0_TAG_LO
value|$28
end_define

begin_define
define|#
directive|define
name|COP_0_TAG_HI
value|$29
end_define

begin_define
define|#
directive|define
name|COP_0_ERROR_PC
value|$30
end_define

begin_comment
comment|/*  *  Coprocessor 0 Set 1  */
end_comment

begin_define
define|#
directive|define
name|C0P_1_IPLLO
value|$18
end_define

begin_define
define|#
directive|define
name|C0P_1_IPLHI
value|$19
end_define

begin_define
define|#
directive|define
name|C0P_1_INTCTL
value|$20
end_define

begin_define
define|#
directive|define
name|C0P_1_DERRADDR0
value|$26
end_define

begin_define
define|#
directive|define
name|C0P_1_DERRADDR1
value|$27
end_define

begin_comment
comment|/*  * Values for the code field in a break instruction.  */
end_comment

begin_define
define|#
directive|define
name|BREAK_INSTR
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|BREAK_VAL_MASK
value|0x03ffffc0
end_define

begin_define
define|#
directive|define
name|BREAK_VAL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BREAK_KDB_VAL
value|512
end_define

begin_define
define|#
directive|define
name|BREAK_SSTEP_VAL
value|513
end_define

begin_define
define|#
directive|define
name|BREAK_BRKPT_VAL
value|514
end_define

begin_define
define|#
directive|define
name|BREAK_SOVER_VAL
value|515
end_define

begin_define
define|#
directive|define
name|BREAK_DDB_VAL
value|516
end_define

begin_define
define|#
directive|define
name|BREAK_KDB
value|(BREAK_INSTR | (BREAK_KDB_VAL<< BREAK_VAL_SHIFT))
end_define

begin_define
define|#
directive|define
name|BREAK_SSTEP
value|(BREAK_INSTR | (BREAK_SSTEP_VAL<< BREAK_VAL_SHIFT))
end_define

begin_define
define|#
directive|define
name|BREAK_BRKPT
value|(BREAK_INSTR | (BREAK_BRKPT_VAL<< BREAK_VAL_SHIFT))
end_define

begin_define
define|#
directive|define
name|BREAK_SOVER
value|(BREAK_INSTR | (BREAK_SOVER_VAL<< BREAK_VAL_SHIFT))
end_define

begin_define
define|#
directive|define
name|BREAK_DDB
value|(BREAK_INSTR | (BREAK_DDB_VAL<< BREAK_VAL_SHIFT))
end_define

begin_comment
comment|/*  * Mininum and maximum cache sizes.  */
end_comment

begin_define
define|#
directive|define
name|MIN_CACHE_SIZE
value|(16 * 1024)
end_define

begin_define
define|#
directive|define
name|MAX_CACHE_SIZE
value|(256 * 1024)
end_define

begin_comment
comment|/*  * The floating point version and status registers.  */
end_comment

begin_define
define|#
directive|define
name|FPC_ID
value|$0
end_define

begin_define
define|#
directive|define
name|FPC_CSR
value|$31
end_define

begin_comment
comment|/*  * The floating point coprocessor status register bits.  */
end_comment

begin_define
define|#
directive|define
name|FPC_ROUNDING_BITS
value|0x00000003
end_define

begin_define
define|#
directive|define
name|FPC_ROUND_RN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FPC_ROUND_RZ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FPC_ROUND_RP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FPC_ROUND_RM
value|0x00000003
end_define

begin_define
define|#
directive|define
name|FPC_STICKY_BITS
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|FPC_STICKY_INEXACT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FPC_STICKY_UNDERFLOW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FPC_STICKY_OVERFLOW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|FPC_STICKY_DIV0
value|0x00000020
end_define

begin_define
define|#
directive|define
name|FPC_STICKY_INVALID
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FPC_ENABLE_BITS
value|0x00000f80
end_define

begin_define
define|#
directive|define
name|FPC_ENABLE_INEXACT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|FPC_ENABLE_UNDERFLOW
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FPC_ENABLE_OVERFLOW
value|0x00000200
end_define

begin_define
define|#
directive|define
name|FPC_ENABLE_DIV0
value|0x00000400
end_define

begin_define
define|#
directive|define
name|FPC_ENABLE_INVALID
value|0x00000800
end_define

begin_define
define|#
directive|define
name|FPC_EXCEPTION_BITS
value|0x0003f000
end_define

begin_define
define|#
directive|define
name|FPC_EXCEPTION_INEXACT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|FPC_EXCEPTION_UNDERFLOW
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FPC_EXCEPTION_OVERFLOW
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FPC_EXCEPTION_DIV0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FPC_EXCEPTION_INVALID
value|0x00010000
end_define

begin_define
define|#
directive|define
name|FPC_EXCEPTION_UNIMPL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FPC_COND_BIT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FPC_FLUSH_BIT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FPC_MBZ_BITS
value|0xfe7c0000
end_define

begin_comment
comment|/*  * Constants to determine if have a floating point instruction.  */
end_comment

begin_define
define|#
directive|define
name|OPCODE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|OPCODE_C1
value|0x11
end_define

begin_comment
comment|/*  * The low part of the TLB entry.  */
end_comment

begin_define
define|#
directive|define
name|VMTLB_PF_NUM
value|0x3fffffc0
end_define

begin_define
define|#
directive|define
name|VMTLB_ATTR_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|VMTLB_MOD_BIT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|VMTLB_VALID_BIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|VMTLB_GLOBAL_BIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|VMTLB_PHYS_PAGE_SHIFT
value|6
end_define

begin_comment
comment|/*  * The high part of the TLB entry.  */
end_comment

begin_define
define|#
directive|define
name|VMTLB_VIRT_PAGE_NUM
value|0xffffe000
end_define

begin_define
define|#
directive|define
name|VMTLB_PID
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|VMTLB_PID_R9K
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|VMTLB_PID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|VMTLB_VIRT_PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|VMTLB_VIRT_PAGE_SHIFT_R9K
value|13
end_define

begin_comment
comment|/*  * The first TLB entry that write random hits.  * TLB entry 0 maps the kernel stack of the currently running thread  * TLB entry 1 maps the pcpu area of processor (only for SMP builds)  */
end_comment

begin_define
define|#
directive|define
name|KSTACK_TLB_ENTRY
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|PCPU_TLB_ENTRY
value|1
end_define

begin_define
define|#
directive|define
name|VMWIRED_ENTRIES
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VMWIRED_ENTRIES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_comment
comment|/*  * The number of process id entries.  */
end_comment

begin_define
define|#
directive|define
name|VMNUM_PIDS
value|256
end_define

begin_comment
comment|/*  * TLB probe return codes.  */
end_comment

begin_define
define|#
directive|define
name|VMTLB_NOT_FOUND
value|0
end_define

begin_define
define|#
directive|define
name|VMTLB_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|VMTLB_FOUND_WITH_PATCH
value|2
end_define

begin_define
define|#
directive|define
name|VMTLB_PROBE_ERROR
value|3
end_define

begin_comment
comment|/*  * Exported definitions unique to mips cpu support.  */
end_comment

begin_comment
comment|/*  * definitions of cpu-dependent requirements  * referenced in generic code  */
end_comment

begin_define
define|#
directive|define
name|COPY_SIGCODE
end_define

begin_comment
comment|/* copy sigcode above user stack in exec */
end_comment

begin_define
define|#
directive|define
name|cpu_swapout
parameter_list|(
name|p
parameter_list|)
value|panic("cpu_swapout: can't get here");
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_comment
comment|/*  * Arguments to hardclock and gatherstats encapsulate the previous  * machine state in an opaque clockframe.  */
end_comment

begin_define
define|#
directive|define
name|clockframe
value|trapframe
end_define

begin_comment
comment|/* Use normal trap frame */
end_comment

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|((framep)->sr& SR_KSU_USER)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
value|((framep)->cpl == 0)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->pc)
end_define

begin_define
define|#
directive|define
name|CLKF_INTR
parameter_list|(
name|framep
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|MIPS_CLKF_INTR
parameter_list|()
value|(intr_nesting_level>= 1)
end_define

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|(((framep)->sr& SR_KSU_USER) != 0)
end_define

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->pc)
end_define

begin_define
define|#
directive|define
name|cpu_getstack
parameter_list|(
name|td
parameter_list|)
value|((td)->td_frame->sp)
end_define

begin_comment
comment|/*  * CPU identification, from PRID register.  */
end_comment

begin_union
union|union
name|cpuprid
block|{
name|int
name|cpuprid
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int
name|pad1
range|:
literal|8
decl_stmt|;
comment|/* reserved */
name|u_int
name|cp_vendor
range|:
literal|8
decl_stmt|;
comment|/* company identifier */
name|u_int
name|cp_imp
range|:
literal|8
decl_stmt|;
comment|/* implementation identifier */
name|u_int
name|cp_majrev
range|:
literal|4
decl_stmt|;
comment|/* major revision identifier */
name|u_int
name|cp_minrev
range|:
literal|4
decl_stmt|;
comment|/* minor revision identifier */
else|#
directive|else
name|u_int
name|cp_minrev
range|:
literal|4
decl_stmt|;
comment|/* minor revision identifier */
name|u_int
name|cp_majrev
range|:
literal|4
decl_stmt|;
comment|/* major revision identifier */
name|u_int
name|cp_imp
range|:
literal|8
decl_stmt|;
comment|/* implementation identifier */
name|u_int
name|cp_vendor
range|:
literal|8
decl_stmt|;
comment|/* company identifier */
name|u_int
name|pad1
range|:
literal|8
decl_stmt|;
comment|/* reserved */
endif|#
directive|endif
block|}
name|cpu
struct|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LOCORE */
end_comment

begin_comment
comment|/*  * CTL_MACHDEP definitions.  */
end_comment

begin_define
define|#
directive|define
name|CPU_CONSDEV
value|1
end_define

begin_comment
comment|/* dev_t: console terminal device */
end_comment

begin_define
define|#
directive|define
name|CPU_ADJKERNTZ
value|2
end_define

begin_comment
comment|/* int: timezone offset (seconds) */
end_comment

begin_define
define|#
directive|define
name|CPU_DISRTCSET
value|3
end_define

begin_comment
comment|/* int: disable resettodr() call */
end_comment

begin_define
define|#
directive|define
name|CPU_BOOTINFO
value|4
end_define

begin_comment
comment|/* struct: bootinfo */
end_comment

begin_define
define|#
directive|define
name|CPU_WALLCLOCK
value|5
end_define

begin_comment
comment|/* int: indicates wall CMOS clock */
end_comment

begin_define
define|#
directive|define
name|CPU_MAXID
value|6
end_define

begin_comment
comment|/* number of valid machdep ids */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{			\ 	{ 0, 0 },				\ 	{ "console_device", CTLTYPE_STRUCT },	\ 	{ "adjkerntz", CTLTYPE_INT },		\ 	{ "disable_rtc_set", CTLTYPE_INT },	\ 	{ "bootinfo", CTLTYPE_STRUCT },		\ 	{ "wall_cmos_clock", CTLTYPE_INT },	\ }
end_define

begin_comment
comment|/*  * MIPS CPU types (cp_imp).  */
end_comment

begin_define
define|#
directive|define
name|MIPS_R2000
value|0x01
end_define

begin_comment
comment|/* MIPS R2000 CPU		ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R3000
value|0x02
end_define

begin_comment
comment|/* MIPS R3000 CPU		ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R6000
value|0x03
end_define

begin_comment
comment|/* MIPS R6000 CPU		ISA II	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4000
value|0x04
end_define

begin_comment
comment|/* MIPS R4000/4400 CPU		ISA III	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R3LSI
value|0x05
end_define

begin_comment
comment|/* LSI Logic R3000 derivate	ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R6000A
value|0x06
end_define

begin_comment
comment|/* MIPS R6000A CPU		ISA II	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R3IDT
value|0x07
end_define

begin_comment
comment|/* IDT R3000 derivate		ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R10000
value|0x09
end_define

begin_comment
comment|/* MIPS R10000/T5 CPU		ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4200
value|0x0a
end_define

begin_comment
comment|/* MIPS R4200 CPU (ICE)		ISA III	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4300
value|0x0b
end_define

begin_comment
comment|/* NEC VR4300 CPU		ISA III	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4100
value|0x0c
end_define

begin_comment
comment|/* NEC VR41xx CPU MIPS-16	ISA III	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R8000
value|0x10
end_define

begin_comment
comment|/* MIPS R8000 Blackbird/TFP	ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4600
value|0x20
end_define

begin_comment
comment|/* QED R4600 Orion		ISA III	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4700
value|0x21
end_define

begin_comment
comment|/* QED R4700 Orion		ISA III	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R3TOSH
value|0x22
end_define

begin_comment
comment|/* Toshiba R3000 based CPU	ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R5000
value|0x23
end_define

begin_comment
comment|/* MIPS R5000 CPU		ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_RM7000
value|0x27
end_define

begin_comment
comment|/* QED RM7000 CPU		ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_RM52X0
value|0x28
end_define

begin_comment
comment|/* QED RM52X0 CPU		ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_VR5400
value|0x54
end_define

begin_comment
comment|/* NEC Vr5400 CPU		ISA IV+	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_RM9000
value|0x34
end_define

begin_comment
comment|/* E9000 CPU				 */
end_comment

begin_comment
comment|/*  * MIPS FPU types  */
end_comment

begin_define
define|#
directive|define
name|MIPS_SOFT
value|0x00
end_define

begin_comment
comment|/* Software emulation		ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R2360
value|0x01
end_define

begin_comment
comment|/* MIPS R2360 FPC		ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R2010
value|0x02
end_define

begin_comment
comment|/* MIPS R2010 FPC		ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R3010
value|0x03
end_define

begin_comment
comment|/* MIPS R3010 FPC		ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R6010
value|0x04
end_define

begin_comment
comment|/* MIPS R6010 FPC		ISA II	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4010
value|0x05
end_define

begin_comment
comment|/* MIPS R4000/R4400 FPC		ISA II	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R31LSI
value|0x06
end_define

begin_comment
comment|/* LSI Logic derivate		ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R10010
value|0x09
end_define

begin_comment
comment|/* MIPS R10000/T5 FPU		ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4210
value|0x0a
end_define

begin_comment
comment|/* MIPS R4200 FPC (ICE)		ISA III	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_UNKF1
value|0x0b
end_define

begin_comment
comment|/* unnanounced product cpu	ISA III	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R8000
value|0x10
end_define

begin_comment
comment|/* MIPS R8000 Blackbird/TFP	ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4600
value|0x20
end_define

begin_comment
comment|/* QED R4600 Orion		ISA III	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R3SONY
value|0x21
end_define

begin_comment
comment|/* Sony R3000 based FPU		ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R3TOSH
value|0x22
end_define

begin_comment
comment|/* Toshiba R3000 based FPU	ISA I	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_R5010
value|0x23
end_define

begin_comment
comment|/* MIPS R5000 based FPU		ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_RM7000
value|0x27
end_define

begin_comment
comment|/* QED RM7000 FPU		ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_RM5230
value|0x28
end_define

begin_comment
comment|/* QED RM52X0 based FPU		ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_RM52XX
value|0x28
end_define

begin_comment
comment|/* QED RM52X0 based FPU		ISA IV	 */
end_comment

begin_define
define|#
directive|define
name|MIPS_VR5400
value|0x54
end_define

begin_comment
comment|/* NEC Vr5400 FPU		ISA IV+	 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
name|union
name|cpuprid
name|cpu_id
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mips_proc_type
parameter_list|()
value|((cpu_id.cpu.cp_vendor<< 8) | cpu_id.cpu.cp_imp)
end_define

begin_define
define|#
directive|define
name|mips_set_proc_type
parameter_list|(
name|type
parameter_list|)
value|(cpu_id.cpu.cp_vendor = (type)>> 8, \ 					 cpu_id.cpu.cp_imp = ((type)& 0x00ff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LOCORE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LOCORE
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|union
name|cpuprid
name|fpu_id
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|tlb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|user
struct_decl|;
end_struct_decl

begin_function_decl
name|u_int32_t
name|mips_cp0_config1_read
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Mips_ConfigCache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_SetWIRED
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_SetPID
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|Mips_GetCOUNT
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_SetCOMPARE
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|Mips_GetCOMPARE
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_SyncCache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_SyncDCache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_HitSyncDCache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_HitSyncSCache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_IOSyncDCache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_HitInvalidateDCache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_SyncICache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_InvalidateICache
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_TLBFlush
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_TLBFlushAddr
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_TLBWriteIndexed
parameter_list|(
name|int
parameter_list|,
name|struct
name|tlb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_TLBUpdate
parameter_list|(
name|vm_offset_t
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Mips_TLBRead
parameter_list|(
name|int
parameter_list|,
name|struct
name|tlb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mips_TBIAP
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wbflush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_int32_t
name|cpu_counter_interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of counter ticks/tick */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|cpu_counter_last
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last compare value loaded    */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|num_tlbentries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|btext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|etext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|intr_nesting_level
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|func_0args_asmmacro
parameter_list|(
name|func
parameter_list|,
name|in
parameter_list|)
define|\
value|__asm __volatile ( "jalr %0"					\ 			: "=r" (in)
comment|/* outputs */
value|\ 			: "r" (func)
comment|/* inputs */
value|\ 			: "$31", "$4");
end_define

begin_define
define|#
directive|define
name|func_1args_asmmacro
parameter_list|(
name|func
parameter_list|,
name|arg0
parameter_list|)
define|\
value|__asm __volatile ("move $4, %1;"				\ 			"jalr %0"					\ 			:
comment|/* outputs */
value|\ 			: "r" (func), "r" (arg0)
comment|/* inputs */
value|\ 			: "$31", "$4");
end_define

begin_define
define|#
directive|define
name|func_2args_asmmacro
parameter_list|(
name|func
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|__asm __volatile ("move $4, %1;"				\ 			"move $5, %2;"					\ 			"jalr %0"					\ 			:
comment|/* outputs */
value|\ 			: "r" (func), "r" (arg0), "r" (arg1)
comment|/* inputs */
value|\ 			: "$31", "$4", "$5");
end_define

begin_define
define|#
directive|define
name|func_3args_asmmacro
parameter_list|(
name|func
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|__asm __volatile ( "move $4, %1;"				\ 			"move $5, %2;"					\ 			"move $6, %3;"					\ 			"jalr %0"					\ 			:
comment|/* outputs */
value|\ 			: "r" (func), "r" (arg0), "r" (arg1), "r" (arg2)
comment|/* inputs */
value|\ 			: "$31", "$4", "$5", "$6");
end_define

begin_define
define|#
directive|define
name|MachSetPID
value|Mips_SetPID
end_define

begin_define
define|#
directive|define
name|MachTLBUpdate
value|Mips_TLBUpdate
end_define

begin_define
define|#
directive|define
name|mips_TBIS
value|Mips_TLBFlushAddr
end_define

begin_define
define|#
directive|define
name|MIPS_TBIAP
parameter_list|()
value|mips_TBIAP(num_tlbentries)
end_define

begin_define
define|#
directive|define
name|MachSetWIRED
parameter_list|(
name|index
parameter_list|)
value|Mips_SetWIRED(index)
end_define

begin_define
define|#
directive|define
name|MachTLBFlush
parameter_list|(
name|count
parameter_list|)
value|Mips_TLBFlush(count)
end_define

begin_define
define|#
directive|define
name|MachTLBGetPID
parameter_list|(
name|pid
parameter_list|)
value|(pid = Mips_TLBGetPID())
end_define

begin_define
define|#
directive|define
name|MachTLBRead
parameter_list|(
name|tlbno
parameter_list|,
name|tlbp
parameter_list|)
value|Mips_TLBRead(tlbno, tlbp)
end_define

begin_define
define|#
directive|define
name|MachFPTrap
parameter_list|(
name|sr
parameter_list|,
name|cause
parameter_list|,
name|pc
parameter_list|)
value|MipsFPTrap(sr, cause, pc)
end_define

begin_comment
comment|/*  * Enable realtime clock (always enabled).  */
end_comment

begin_define
define|#
directive|define
name|enablertclock
parameter_list|()
end_define

begin_comment
comment|/*  * Are we in an interrupt handler? required by JunOS  */
end_comment

begin_define
define|#
directive|define
name|IN_INT_HANDLER
parameter_list|()
define|\
value|(curthread->td_intr_nesting_level != 0 ||	\ 	(curthread->td_pflags& TDP_ITHREAD))
end_define

begin_comment
comment|/*  *  Low level access routines to CPU registers  */
end_comment

begin_function_decl
name|void
name|setsoftintr0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clearsoftintr0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setsoftintr1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clearsoftintr1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|mips_cp0_status_read
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mips_cp0_status_write
parameter_list|(
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|disableintr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|restoreintr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|enableintr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Mips_TLBGetPID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swi_vm
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_halt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|set_intr_mask
parameter_list|(
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|get_intr_mask
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cpu_spinwait
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

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
comment|/* !_MACHINE_CPU_H_ */
end_comment

end_unit

