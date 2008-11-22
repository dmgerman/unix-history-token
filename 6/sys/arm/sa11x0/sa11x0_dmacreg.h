begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $NetBSD: sa11x0_dmacreg.h,v 1.1 2001/07/08 23:37:53 rjs Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001, The NetBSD Foundation, Inc.  All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by IWAMOTO Toshihiro.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the NetBSD  *      Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/* SA11[01]0 integrated DMA controller */
end_comment

begin_define
define|#
directive|define
name|SADMAC_NPORTS
value|40
end_define

begin_define
define|#
directive|define
name|SADMAC_DAR0
value|0x00
end_define

begin_comment
comment|/* DMA device address register */
end_comment

begin_define
define|#
directive|define
name|SADMAC_DCR0_SET
value|0x04
end_define

begin_comment
comment|/* DMA control/status (set) */
end_comment

begin_define
define|#
directive|define
name|SADMAC_DCR0_CLR
value|0x08
end_define

begin_comment
comment|/* DMA control/status (clear) */
end_comment

begin_define
define|#
directive|define
name|SADMAC_DCR0
value|0x0C
end_define

begin_comment
comment|/* DMA control/status (read only) */
end_comment

begin_define
define|#
directive|define
name|SADMAC_DBSA0
value|0x10
end_define

begin_comment
comment|/* DMA Buffer A start address */
end_comment

begin_define
define|#
directive|define
name|SADMAC_DBTA0
value|0x14
end_define

begin_comment
comment|/* DMA Buffer A transfer count */
end_comment

begin_define
define|#
directive|define
name|SADMAC_DBSB0
value|0x18
end_define

begin_comment
comment|/* DMA Buffer B start address */
end_comment

begin_define
define|#
directive|define
name|SADMAC_DBTB0
value|0x1C
end_define

begin_comment
comment|/* DMA Buffer B transfer count */
end_comment

begin_define
define|#
directive|define
name|SADMAC_DAR1
value|0x20
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR1_SET
value|0x24
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR1_CLR
value|0x28
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR1
value|0x2C
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSA1
value|0x30
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTA1
value|0x34
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSB1
value|0x38
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTB1
value|0x3C
end_define

begin_define
define|#
directive|define
name|SADMAC_DAR2
value|0x40
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR2_SET
value|0x44
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR2_CLR
value|0x48
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR2
value|0x4C
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSA2
value|0x50
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTA2
value|0x54
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSB2
value|0x58
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTB2
value|0x5C
end_define

begin_define
define|#
directive|define
name|SADMAC_DAR3
value|0x60
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR3_SET
value|0x64
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR3_CLR
value|0x68
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR3
value|0x6C
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSA3
value|0x70
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTA3
value|0x74
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSB3
value|0x78
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTB3
value|0x7C
end_define

begin_define
define|#
directive|define
name|SADMAC_DAR4
value|0x80
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR4_SET
value|0x84
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR4_CLR
value|0x88
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR4
value|0x8C
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSA4
value|0x90
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTA4
value|0x94
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSB4
value|0x98
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTB4
value|0x9C
end_define

begin_define
define|#
directive|define
name|SADMAC_DAR5
value|0xA0
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR5_SET
value|0xA4
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR5_CLR
value|0xA8
end_define

begin_define
define|#
directive|define
name|SADMAC_DCR5
value|0xAC
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSA5
value|0xB0
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTA5
value|0xB4
end_define

begin_define
define|#
directive|define
name|SADMAC_DBSB5
value|0xB8
end_define

begin_define
define|#
directive|define
name|SADMAC_DBTB5
value|0xBC
end_define

end_unit

