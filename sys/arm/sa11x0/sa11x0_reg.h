begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sa11x0_reg.h,v 1.4 2002/07/19 18:26:56 ichiro Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by IWAMOTO Toshihiro.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_SA11X0_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_SA11X0_REG_H_
end_define

begin_comment
comment|/* Physical register base addresses */
end_comment

begin_define
define|#
directive|define
name|SAOST_BASE
value|0x90000000
end_define

begin_comment
comment|/* OS Timer */
end_comment

begin_define
define|#
directive|define
name|SARTC_BASE
value|0x90010000
end_define

begin_comment
comment|/* Real-Time Clock */
end_comment

begin_define
define|#
directive|define
name|SAPMR_BASE
value|0x90020000
end_define

begin_comment
comment|/* Power Manager */
end_comment

begin_define
define|#
directive|define
name|SARCR_BASE
value|0x90030000
end_define

begin_comment
comment|/* Reset Controller */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_BASE
value|0x90040000
end_define

begin_comment
comment|/* GPIO */
end_comment

begin_define
define|#
directive|define
name|SAIPIC_BASE
value|0x90050000
end_define

begin_comment
comment|/* Interrupt Controller */
end_comment

begin_define
define|#
directive|define
name|SAPPC_BASE
value|0x90060000
end_define

begin_comment
comment|/* Peripheral Pin Controller */
end_comment

begin_define
define|#
directive|define
name|SAUDC_BASE
value|0x80000000
end_define

begin_comment
comment|/* USB Device Controller*/
end_comment

begin_define
define|#
directive|define
name|SACOM1_BASE
value|0x80010000
end_define

begin_comment
comment|/* GPCLK/UART 1 */
end_comment

begin_define
define|#
directive|define
name|SACOM3_HW_BASE
value|0x80050000
end_define

begin_comment
comment|/* UART 3  */
end_comment

begin_define
define|#
directive|define
name|SAMCP_BASE
value|0x80060000
end_define

begin_comment
comment|/* MCP Controller */
end_comment

begin_define
define|#
directive|define
name|SASSP_BASE
value|0x80070000
end_define

begin_comment
comment|/* Synchronous serial port */
end_comment

begin_define
define|#
directive|define
name|SADMAC_BASE
value|0xB0000000
end_define

begin_comment
comment|/* DMA Controller */
end_comment

begin_define
define|#
directive|define
name|SALCD_BASE
value|0xB0100000
end_define

begin_comment
comment|/* LCD */
end_comment

begin_comment
comment|/* Register base virtual addresses mapped by initarm() */
end_comment

begin_define
define|#
directive|define
name|SACOM3_BASE
value|0xd000d000
end_define

begin_comment
comment|/* Interrupt controller registers */
end_comment

begin_define
define|#
directive|define
name|SAIPIC_NPORTS
value|9
end_define

begin_define
define|#
directive|define
name|SAIPIC_IP
value|0x00
end_define

begin_comment
comment|/* IRQ pending register */
end_comment

begin_define
define|#
directive|define
name|SAIPIC_MR
value|0x04
end_define

begin_comment
comment|/* Mask register */
end_comment

begin_define
define|#
directive|define
name|SAIPIC_LR
value|0x08
end_define

begin_comment
comment|/* Level register */
end_comment

begin_define
define|#
directive|define
name|SAIPIC_FP
value|0x10
end_define

begin_comment
comment|/* FIQ pending register */
end_comment

begin_define
define|#
directive|define
name|SAIPIC_PR
value|0x20
end_define

begin_comment
comment|/* Pending register */
end_comment

begin_define
define|#
directive|define
name|SAIPIC_CR
value|0x0C
end_define

begin_comment
comment|/* Control register */
end_comment

begin_comment
comment|/* width of interrupt controller */
end_comment

begin_define
define|#
directive|define
name|ICU_LEN
value|32
end_define

begin_comment
comment|/* Reset controller registers */
end_comment

begin_define
define|#
directive|define
name|SARCR_RSRR
value|0x0
end_define

begin_comment
comment|/* Software reset register */
end_comment

begin_define
define|#
directive|define
name|SARCR_RCSR
value|0x4
end_define

begin_comment
comment|/* Reset status register */
end_comment

begin_define
define|#
directive|define
name|SARCR_TUCR
value|0x8
end_define

begin_comment
comment|/* Test Unit control reg */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_SA11X0_REG_H_ */
end_comment

end_unit

