begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $NetBSD: sa11x0_ppcreg.h,v 1.2 2001/07/30 12:19:04 rjs Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001, The NetBSD Foundation, Inc.  All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by IWAMOTO Toshihiro.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the NetBSD  *      Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/* SA11[01]0 PPC (peripheral pin controller) */
end_comment

begin_comment
comment|/* size of I/O space */
end_comment

begin_define
define|#
directive|define
name|SAPPC_NPORTS
value|13
end_define

begin_define
define|#
directive|define
name|SAPPC_PDR
value|0x00
end_define

begin_comment
comment|/* pin direction register */
end_comment

begin_define
define|#
directive|define
name|SAPPC_PSR
value|0x04
end_define

begin_comment
comment|/* pin state register */
end_comment

begin_define
define|#
directive|define
name|SAPPC_PAR
value|0x08
end_define

begin_comment
comment|/* pin assignment register */
end_comment

begin_define
define|#
directive|define
name|PAR_UPR
value|0x01000
end_define

begin_comment
comment|/* UART pin assignment */
end_comment

begin_define
define|#
directive|define
name|PAR_SPR
value|0x40000
end_define

begin_comment
comment|/* SSP pin assignment */
end_comment

begin_define
define|#
directive|define
name|SAPPC_SDR
value|0x0C
end_define

begin_comment
comment|/* sleep mode direction register */
end_comment

begin_define
define|#
directive|define
name|SAPPC_PFR
value|0x10
end_define

begin_comment
comment|/* pin flag register */
end_comment

begin_define
define|#
directive|define
name|PFR_LCD
value|0x00001
end_define

begin_comment
comment|/* LCD controller flag */
end_comment

begin_define
define|#
directive|define
name|PFR_SP1TX
value|0x01000
end_define

begin_comment
comment|/* serial port 1 Tx flag */
end_comment

begin_define
define|#
directive|define
name|PFR_SP1RX
value|0x02000
end_define

begin_comment
comment|/* serial port 1 Rx flag */
end_comment

begin_define
define|#
directive|define
name|PFR_SP2TX
value|0x04000
end_define

begin_comment
comment|/* serial port 2 Tx flag */
end_comment

begin_define
define|#
directive|define
name|PFR_SP2RX
value|0x08000
end_define

begin_comment
comment|/* serial port 2 Rx flag */
end_comment

begin_define
define|#
directive|define
name|PFR_SP3TX
value|0x10000
end_define

begin_comment
comment|/* serial port 3 Tx flag */
end_comment

begin_define
define|#
directive|define
name|PFR_SP3RX
value|0x20000
end_define

begin_comment
comment|/* serial port 3 Rx flag */
end_comment

begin_define
define|#
directive|define
name|PFR_SP4
value|0x40000
end_define

begin_comment
comment|/* serial port 4 flag */
end_comment

begin_comment
comment|/* MCP control register 1 */
end_comment

begin_define
define|#
directive|define
name|SAMCP_CR1
value|0x30
end_define

begin_comment
comment|/* MCP control register 1 */
end_comment

end_unit

