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
file|<machine/endian.h>
end_include

begin_comment
comment|/* BEGIN: these are going away */
end_comment

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
name|soft_int_mask
parameter_list|(
name|softintr
parameter_list|)
value|(1<< ((softintr) + 8))
end_define

begin_define
define|#
directive|define
name|hard_int_mask
parameter_list|(
name|hardintr
parameter_list|)
value|(1<< ((hardintr) + 10))
end_define

begin_comment
comment|/* END: These are going away */
end_comment

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
comment|/*  * Exported definitions unique to mips cpu support.  */
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
file|<machine/cpufunc.h>
end_include

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
comment|/*  * A machine-independent interface to the CPU's counter.  */
end_comment

begin_define
define|#
directive|define
name|get_cyclecount
parameter_list|()
value|mips_rd_count()
end_define

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

begin_struct_decl
struct_decl|struct
name|user
struct_decl|;
end_struct_decl

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

