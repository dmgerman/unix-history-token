begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_INTR_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_INTR_MACHDEP_H_
end_define

begin_comment
comment|/*  * Low level interrupt code.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|||
name|defined
argument_list|(
name|APIC_IO
argument_list|)
end_if

begin_comment
comment|/*  * XXX FIXME: rethink location for all IPI vectors.  */
end_comment

begin_comment
comment|/*     APIC TPR priority vector levels:  	0xff (255) +-------------+ 		   |             | 15 (IPIs: Xspuriousint) 	0xf0 (240) +-------------+ 		   |             | 14 	0xe0 (224) +-------------+ 		   |             | 13 	0xd0 (208) +-------------+ 		   |             | 12 	0xc0 (192) +-------------+ 		   |             | 11 	0xb0 (176) +-------------+ 		   |             | 10 (IPIs: Xcpustop) 	0xa0 (160) +-------------+ 		   |             |  9 (IPIs: Xinvltlb) 	0x90 (144) +-------------+ 		   |             |  8 (linux/BSD syscall, IGNORE FAST HW INTS) 	0x80 (128) +-------------+ 		   |             |  7 (FAST_INTR 16-23) 	0x70 (112) +-------------+ 		   |             |  6 (FAST_INTR 0-15) 	0x60 (96)  +-------------+ 		   |             |  5 (IGNORE HW INTS) 	0x50 (80)  +-------------+ 		   |             |  4 (2nd IO APIC) 	0x40 (64)  +------+------+ 		   |      |      |  3 (upper APIC hardware INTs: PCI) 	0x30 (48)  +------+------+ 		   |             |  2 (start of hardware INTs: ISA) 	0x20 (32)  +-------------+ 		   |             |  1 (exceptions, traps, etc.) 	0x10 (16)  +-------------+ 		   |             |  0 (exceptions, traps, etc.) 	0x00 (0)   +-------------+  */
end_comment

begin_comment
comment|/* IDT vector base for regular (aka. slow) and fast interrupts */
end_comment

begin_define
define|#
directive|define
name|TPR_SLOW_INTS
value|0x20
end_define

begin_define
define|#
directive|define
name|TPR_FAST_INTS
value|0x60
end_define

begin_comment
comment|/* blocking values for local APIC Task Priority Register */
end_comment

begin_define
define|#
directive|define
name|TPR_BLOCK_HWI
value|0x4f
end_define

begin_comment
comment|/* hardware INTs */
end_comment

begin_define
define|#
directive|define
name|TPR_IGNORE_HWI
value|0x5f
end_define

begin_comment
comment|/* ignore INTs */
end_comment

begin_define
define|#
directive|define
name|TPR_BLOCK_FHWI
value|0x7f
end_define

begin_comment
comment|/* hardware FAST INTs */
end_comment

begin_define
define|#
directive|define
name|TPR_IGNORE_FHWI
value|0x8f
end_define

begin_comment
comment|/* ignore FAST INTs */
end_comment

begin_define
define|#
directive|define
name|TPR_BLOCK_XINVLTLB
value|0x9f
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|TPR_BLOCK_XCPUSTOP
value|0xaf
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|TPR_BLOCK_ALL
value|0xff
end_define

begin_comment
comment|/* all INTs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST_TEST1
end_ifdef

begin_comment
comment|/* put a 'fake' HWI in top of APIC prio 0x3x, 32 + 31 = 63 = 0x3f */
end_comment

begin_define
define|#
directive|define
name|XTEST1_OFFSET
value|(ICU_OFFSET + 31)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** TEST_TEST1 */
end_comment

begin_comment
comment|/* TLB shootdowns */
end_comment

begin_define
define|#
directive|define
name|XINVLTLB_OFFSET
value|(ICU_OFFSET + 112)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BETTER_CLOCK
end_ifdef

begin_comment
comment|/* inter-cpu clock handling */
end_comment

begin_define
define|#
directive|define
name|XCPUCHECKSTATE_OFFSET
value|(ICU_OFFSET + 113)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* inter-CPU rendezvous */
end_comment

begin_define
define|#
directive|define
name|XRENDEZVOUS_OFFSET
value|(ICU_OFFSET + 114)
end_define

begin_comment
comment|/* IPI to generate an additional software trap at the target CPU */
end_comment

begin_define
define|#
directive|define
name|XCPUAST_OFFSET
value|(ICU_OFFSET +  48)
end_define

begin_comment
comment|/* IPI to signal the CPU holding the ISR lock that another IRQ has appeared */
end_comment

begin_define
define|#
directive|define
name|XFORWARD_IRQ_OFFSET
value|(ICU_OFFSET +  49)
end_define

begin_comment
comment|/* IPI to signal CPUs to stop and wait for another CPU to restart them */
end_comment

begin_define
define|#
directive|define
name|XCPUSTOP_OFFSET
value|(ICU_OFFSET + 128)
end_define

begin_comment
comment|/*  * Note: this vector MUST be xxxx1111, 32 + 223 = 255 = 0xff:  */
end_comment

begin_define
define|#
directive|define
name|XSPURIOUSINT_OFFSET
value|(ICU_OFFSET + 223)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP || APIC_IO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Type of the first (asm) part of an interrupt handler.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|inthand_t
name|__P
typedef|((
name|u_int
name|cs
typedef|,
name|u_int
name|ef
typedef|,
name|u_int
name|esp
typedef|,
name|u_int
name|ss
typedef|));
end_typedef

begin_define
define|#
directive|define
name|IDTVEC
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(X,name)
end_define

begin_decl_stmt
specifier|extern
name|char
name|eintrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of intrnames[] */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|intrcnt
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counts for for each device and stray */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|intrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string table containing device names */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
modifier|*
name|intr_countp
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers into intrcnt[] */
end_comment

begin_decl_stmt
specifier|extern
name|inthand2_t
modifier|*
name|intr_handler
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C entry points of intr handlers */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|intr_mask
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sets of intrs masked during handling of 1 */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|intr_unit
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cookies to pass to intr handlers */
end_comment

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|fastintr0
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr1
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr2
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr3
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr4
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr5
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr6
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr7
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr8
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr9
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr10
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr11
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr12
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr13
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr14
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr15
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|intr0
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr1
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr2
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr3
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr4
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr5
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr6
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr7
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr8
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr9
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr10
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr11
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr12
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr13
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr14
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr15
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|||
name|defined
argument_list|(
name|APIC_IO
argument_list|)
end_if

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|fastintr16
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr17
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr18
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr19
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr20
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr21
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr22
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|fastintr23
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|intr16
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr17
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr18
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr19
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr20
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr21
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr22
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|intr23
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|inthand_t
name|Xinvltlb
decl_stmt|,
comment|/* TLB shootdowns */
ifdef|#
directive|ifdef
name|BETTER_CLOCK
name|Xcpucheckstate
decl_stmt|,
comment|/* Check cpu state */
endif|#
directive|endif
name|Xcpuast
decl_stmt|,
comment|/* Additional software trap on other cpu */
name|Xforward_irq
decl_stmt|,
comment|/* Forward irq to cpu holding ISR lock */
name|Xcpustop
decl_stmt|,
comment|/* CPU stops& waits for another CPU to restart it */
name|Xspuriousint
decl_stmt|,
comment|/* handle APIC "spurious INTs" */
name|Xrendezvous
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* handle CPU rendezvous */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST_TEST1
end_ifdef

begin_decl_stmt
name|inthand_t
name|Xtest1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'fake' HWI at top of APIC prio 0x3x, 32+31 = 0x3f */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** TEST_TEST1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP || APIC_IO */
end_comment

begin_decl_stmt
name|void
name|isa_defaultirq
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isa_nmi
name|__P
argument_list|(
operator|(
name|int
name|cd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|icu_setup
name|__P
argument_list|(
operator|(
name|int
name|intr
operator|,
name|inthand2_t
operator|*
name|func
operator|,
name|void
operator|*
name|arg
operator|,
name|u_int
operator|*
name|maskptr
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|icu_unset
name|__P
argument_list|(
operator|(
name|int
name|intr
operator|,
name|inthand2_t
operator|*
name|handler
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|update_intr_masks
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|intrmask_t
name|splq
name|__P
argument_list|(
operator|(
name|intrmask_t
name|mask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INTR_FAST
value|0x00000001
end_define

begin_comment
comment|/* fast interrupt handler */
end_comment

begin_define
define|#
directive|define
name|INTR_EXCL
value|0x00010000
end_define

begin_comment
comment|/* excl. intr, default is shared */
end_comment

begin_comment
comment|/*  * WARNING: These are internal functions and not to be used by device drivers!  * They are subject to change without notice.   */
end_comment

begin_function_decl
name|struct
name|intrec
modifier|*
name|inthand_add
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|irq
parameter_list|,
name|inthand2_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|intrmask_t
modifier|*
name|maskptr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inthand_remove
parameter_list|(
name|struct
name|intrec
modifier|*
name|idesc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
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
comment|/* !_I386_ISA_INTR_MACHDEP_H_ */
end_comment

end_unit

