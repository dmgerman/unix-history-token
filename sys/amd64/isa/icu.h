begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)icu.h	5.6 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * AT/386 Interrupt Control constants  * W. Jolitz 8/89  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_ICU_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_ICU_H_
end_define

begin_comment
comment|/*  * Interrupt enable bits - in normal order of priority (which we change)  */
end_comment

begin_define
define|#
directive|define
name|IRQ0
value|0x0001
end_define

begin_comment
comment|/* highest priority - timer */
end_comment

begin_define
define|#
directive|define
name|IRQ1
value|0x0002
end_define

begin_define
define|#
directive|define
name|IRQ_SLAVE
value|0x0004
end_define

begin_define
define|#
directive|define
name|IRQ8
value|0x0100
end_define

begin_define
define|#
directive|define
name|IRQ9
value|0x0200
end_define

begin_define
define|#
directive|define
name|IRQ2
value|IRQ9
end_define

begin_define
define|#
directive|define
name|IRQ10
value|0x0400
end_define

begin_define
define|#
directive|define
name|IRQ11
value|0x0800
end_define

begin_define
define|#
directive|define
name|IRQ12
value|0x1000
end_define

begin_define
define|#
directive|define
name|IRQ13
value|0x2000
end_define

begin_define
define|#
directive|define
name|IRQ14
value|0x4000
end_define

begin_define
define|#
directive|define
name|IRQ15
value|0x8000
end_define

begin_define
define|#
directive|define
name|IRQ3
value|0x0008
end_define

begin_comment
comment|/* this is highest after rotation */
end_comment

begin_define
define|#
directive|define
name|IRQ4
value|0x0010
end_define

begin_define
define|#
directive|define
name|IRQ5
value|0x0020
end_define

begin_define
define|#
directive|define
name|IRQ6
value|0x0040
end_define

begin_define
define|#
directive|define
name|IRQ7
value|0x0080
end_define

begin_comment
comment|/* lowest - parallel printer */
end_comment

begin_comment
comment|/* Initialization control word 1. Written to even address. */
end_comment

begin_define
define|#
directive|define
name|ICW1_IC4
value|0x01
end_define

begin_comment
comment|/* ICW4 present */
end_comment

begin_define
define|#
directive|define
name|ICW1_SNGL
value|0x02
end_define

begin_comment
comment|/* 1 = single, 0 = cascaded */
end_comment

begin_define
define|#
directive|define
name|ICW1_ADI
value|0x04
end_define

begin_comment
comment|/* 1 = 4, 0 = 8 byte vectors */
end_comment

begin_define
define|#
directive|define
name|ICW1_LTIM
value|0x08
end_define

begin_comment
comment|/* 1 = level trigger, 0 = edge */
end_comment

begin_define
define|#
directive|define
name|ICW1_RESET
value|0x10
end_define

begin_comment
comment|/* must be 1 */
end_comment

begin_comment
comment|/* 0x20 - 0x80 - in 8080/8085 mode only */
end_comment

begin_comment
comment|/* Initialization control word 2. Written to the odd address. */
end_comment

begin_comment
comment|/* No definitions, it is the base vector of the IDT for 8086 mode */
end_comment

begin_comment
comment|/* Initialization control word 3. Written to the odd address. */
end_comment

begin_comment
comment|/* For a master PIC, bitfield indicating a slave 8259 on given input */
end_comment

begin_comment
comment|/* For slave, lower 3 bits are the slave's ID binary id on master */
end_comment

begin_comment
comment|/* Initialization control word 4. Written to the odd address. */
end_comment

begin_define
define|#
directive|define
name|ICW4_8086
value|0x01
end_define

begin_comment
comment|/* 1 = 8086, 0 = 8080 */
end_comment

begin_define
define|#
directive|define
name|ICW4_AEOI
value|0x02
end_define

begin_comment
comment|/* 1 = Auto EOI */
end_comment

begin_define
define|#
directive|define
name|ICW4_MS
value|0x04
end_define

begin_comment
comment|/* 1 = buffered master, 0 = slave */
end_comment

begin_define
define|#
directive|define
name|ICW4_BUF
value|0x08
end_define

begin_comment
comment|/* 1 = enable buffer mode */
end_comment

begin_define
define|#
directive|define
name|ICW4_SFNM
value|0x10
end_define

begin_comment
comment|/* 1 = special fully nested mode */
end_comment

begin_comment
comment|/* Operation control words.  Written after initialization. */
end_comment

begin_comment
comment|/* Operation control word type 1 */
end_comment

begin_comment
comment|/*  * No definitions.  Written to the odd address.  Bitmask for interrupts.  * 1 = disabled.  */
end_comment

begin_comment
comment|/* Operation control word type 2.  Bit 3 (0x08) must be zero. Even address. */
end_comment

begin_define
define|#
directive|define
name|OCW2_L0
value|0x01
end_define

begin_comment
comment|/* Level */
end_comment

begin_define
define|#
directive|define
name|OCW2_L1
value|0x02
end_define

begin_define
define|#
directive|define
name|OCW2_L2
value|0x04
end_define

begin_comment
comment|/* 0x08 must be 0 to select OCW2 vs OCW3 */
end_comment

begin_comment
comment|/* 0x10 must be 0 to select OCW2 vs ICW1 */
end_comment

begin_define
define|#
directive|define
name|OCW2_EOI
value|0x20
end_define

begin_comment
comment|/* 1 = EOI */
end_comment

begin_define
define|#
directive|define
name|OCW2_SL
value|0x40
end_define

begin_comment
comment|/* EOI mode */
end_comment

begin_define
define|#
directive|define
name|OCW2_R
value|0x80
end_define

begin_comment
comment|/* EOI mode */
end_comment

begin_comment
comment|/* Operation control word type 3.  Bit 3 (0x08) must be set. Even address. */
end_comment

begin_define
define|#
directive|define
name|OCW3_RIS
value|0x01
end_define

begin_comment
comment|/* 1 = read IS, 0 = read IR */
end_comment

begin_define
define|#
directive|define
name|OCW3_RR
value|0x02
end_define

begin_comment
comment|/* register read */
end_comment

begin_define
define|#
directive|define
name|OCW3_P
value|0x04
end_define

begin_comment
comment|/* poll mode command */
end_comment

begin_comment
comment|/* 0x08 must be 1 to select OCW3 vs OCW2 */
end_comment

begin_define
define|#
directive|define
name|OCW3_SEL
value|0x08
end_define

begin_comment
comment|/* must be 1 */
end_comment

begin_comment
comment|/* 0x10 must be 0 to select OCW3 vs ICW1 */
end_comment

begin_define
define|#
directive|define
name|OCW3_SMM
value|0x20
end_define

begin_comment
comment|/* special mode mask */
end_comment

begin_define
define|#
directive|define
name|OCW3_ESMM
value|0x40
end_define

begin_comment
comment|/* enable SMM */
end_comment

begin_comment
comment|/*  * Interrupt Control offset into Interrupt descriptor table (IDT)  */
end_comment

begin_define
define|#
directive|define
name|ICU_OFFSET
value|32
end_define

begin_comment
comment|/* 0-31 are processor exceptions */
end_comment

begin_define
define|#
directive|define
name|ICU_LEN
value|16
end_define

begin_comment
comment|/* 32-47 are ISA interrupts */
end_comment

begin_define
define|#
directive|define
name|ICU_IMR_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|ICU_SLAVEID
value|2
end_define

begin_define
define|#
directive|define
name|ICU_EOI
value|(OCW2_EOI)
end_define

begin_comment
comment|/* non-specific EOI */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_function_decl
name|void
name|atpic_handle_intr
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|struct
name|intrframe
name|iframe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atpic_startup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_ICU_H_ */
end_comment

end_unit

