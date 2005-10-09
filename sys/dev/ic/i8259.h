begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Peter Wemm  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register defintions for the i8259A programmable interrupt cnotroller.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_IC_I8259_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_IC_I8259_H_
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_IC_I8259_H_ */
end_comment

end_unit

