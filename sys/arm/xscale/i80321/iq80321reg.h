begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: iq80321reg.h,v 1.4 2003/05/14 19:46:39 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IQ80321REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IQ80321REG_H_
end_define

begin_comment
comment|/*  * Memory map and register definitions for the Intel IQ80321  * Evaluation Board.  */
end_comment

begin_comment
comment|/*  * The memory map of the IQ80321 looks like so:  *  *           ------------------------------  *		Intel 80321 IOP Reserved  * FFFF E900 ------------------------------  *		Peripheral Memory Mapped  *		    Registers  * FFFF E000 ------------------------------  *		On-board devices  * FE80 0000 ------------------------------  *		SDRAM  * A000 0000 ------------------------------  *		Reserved  * 9100 0000 ------------------------------  * 		Flash  * 9080 0000 ------------------------------  *		Reserved  * 9002 0000 ------------------------------  *		ATU Outbound Transaction  *		    Windows  * 8000 0000 ------------------------------  *		ATU Outbound Direct  *		    Addressing Windows  * 0000 1000 ------------------------------  *		Initialization Boot Code  *		    from Flash  * 0000 0000 ------------------------------  */
end_comment

begin_comment
comment|/*  * We allocate a page table for VA 0xfe400000 (4MB) and map the  * PCI I/O space (64K) and i80321 memory-mapped registers (4K) there.  */
end_comment

begin_define
define|#
directive|define
name|IQ80321_IOPXS_VBASE
value|0xfe400000UL
end_define

begin_define
define|#
directive|define
name|IQ80321_IOW_VBASE
value|IQ80321_IOPXS_VBASE
end_define

begin_define
define|#
directive|define
name|IQ80321_80321_VBASE
value|(IQ80321_IOW_VBASE +			\ 				 VERDE_OUT_XLATE_IO_WIN_SIZE)
end_define

begin_comment
comment|/*  * The IQ80321 on-board devices are mapped VA==PA during bootstrap.  * Conveniently, the size of the on-board register space is 1 section  * mapping.  */
end_comment

begin_define
define|#
directive|define
name|IQ80321_OBIO_BASE
value|0xfe800000UL
end_define

begin_define
define|#
directive|define
name|IQ80321_OBIO_SIZE
value|0x00100000UL
end_define

begin_comment
comment|/* 1MB */
end_comment

begin_define
define|#
directive|define
name|IQ80321_UART1
value|0xfe800000UL
end_define

begin_comment
comment|/* TI 16550 */
end_comment

begin_define
define|#
directive|define
name|IQ80321_7SEG_MSB
value|0xfe840000UL
end_define

begin_define
define|#
directive|define
name|IQ80321_7SEG_LSB
value|0xfe850000UL
end_define

begin_define
define|#
directive|define
name|IQ80321_ROT_SWITCH
value|0xfe8d0000UL
end_define

begin_define
define|#
directive|define
name|IQ80321_BATTERY_STAT
value|0xfe8f0000UL
end_define

begin_define
define|#
directive|define
name|BATTERY_STAT_PRES
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|BATTERY_STAT_CHRG
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|BATTERY_STAT_DISCHRG
value|(1U<< 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IQ80321REG_H_ */
end_comment

end_unit

