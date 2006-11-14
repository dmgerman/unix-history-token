begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sa11x0_gpioreg.h,v 1.2 2001/07/30 15:58:56 rjs Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Ichiro FUKUHARA (ichiro@ichiro.org).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * SA-11x0 GPIO Register   */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_NPORTS
value|8
end_define

begin_comment
comment|/* GPIO pin-level register */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_PLR
value|0x00
end_define

begin_comment
comment|/* GPIO pin direction register */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_PDR
value|0x04
end_define

begin_comment
comment|/* GPIO pin output set register */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_PSR
value|0x08
end_define

begin_comment
comment|/* GPIO pin output clear register */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_PCR
value|0x0C
end_define

begin_comment
comment|/* GPIO rising-edge detect register */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_RER
value|0x10
end_define

begin_comment
comment|/* GPIO falling-edge detect register */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_FER
value|0x14
end_define

begin_comment
comment|/* GPIO edge-detect status register */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_EDR
value|0x18
end_define

begin_comment
comment|/* GPIO alternate function register */
end_comment

begin_define
define|#
directive|define
name|SAGPIO_AFR
value|0x1C
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|GPIO
parameter_list|(
name|x
parameter_list|)
value|(0x00000001<< (x))
end_define

begin_comment
comment|/*  * SA-11x0 GPIOs parameter  */
end_comment

begin_comment
comment|/* port	name 		desc 0	Reserved 1	Reserved 2...9	LDD{8..15}	LCD DATA(8-15) 10	SSP_TXD		SSP transmit 11	SSP_RXD		SSP receive 12	SSP_SCLK	SSP serial clock 13	SSP_SFRM	SSP frameclock 14	UART_TXD	UART transmit 15	UART_RXD	UART receive 16	GPCLK_OUT	General-purpose clock out 17	Reserved 18	UART_SCLK	Sample clock input 19	SSP_CLK		Sample clock input 20	UART_SCLK3	Sample clock input 21	MCP_CLK		MCP dock in 22	TREQA		Either TIC request A 23	TREQB		Either TIC request B 24	Reserved 25	RTC		Real Time Clock 26	RCLK_OUT	internal clock /2 27	32KHZ_OUT	Raw 32.768kHz osc output  */
end_comment

end_unit

