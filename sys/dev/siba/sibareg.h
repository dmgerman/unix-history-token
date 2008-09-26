begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * TODO: sprom  * TODO: implement dma translation bits (if needed for system bus)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIBA_SIBAREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIBA_SIBAREG_H_
end_define

begin_define
define|#
directive|define
name|SIBA_CORE_LEN
value|0x00001000
end_define

begin_comment
comment|/* Size of cfg per core */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG_END
value|0x00010000
end_define

begin_comment
comment|/* Upper bound of cfg space */
end_comment

begin_define
define|#
directive|define
name|SIBA_MAX_CORES
value|(SIBA_CFG_END/SIBA_CORE_LEN)
end_define

begin_comment
comment|/* #max cores */
end_comment

begin_comment
comment|/* offset of high ID register */
end_comment

begin_define
define|#
directive|define
name|SIBA_CORE_IDLO
value|0x00000ff8
end_define

begin_define
define|#
directive|define
name|SIBA_CORE_IDHI
value|0x00000ffc
end_define

begin_comment
comment|/*  * Offsets of ChipCommon core registers.  * XXX: move to siba_cc  */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_UART0
value|0x00000300
end_define

begin_comment
comment|/* offset of UART0 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_UART1
value|0x00000400
end_define

begin_comment
comment|/* offset of UART1 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_CCID
value|0x0000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_IDMASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|SIBA_CC_REVMASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_REVSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PACKMASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PACKSHIFT
value|20
end_define

begin_define
define|#
directive|define
name|SIBA_CC_NRCORESMASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_NRCORESSHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH_RCLO
value|0x0000000F
end_define

begin_comment
comment|/* Revision Code (low part) */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDHIGH_CC
value|0x00008FF0
end_define

begin_comment
comment|/* Core Code */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDHIGH_CC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH_RCHI
value|0x00007000
end_define

begin_comment
comment|/* Revision Code (high part) */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDHIGH_RCHI_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH_VC
value|0xFFFF0000
end_define

begin_comment
comment|/* Vendor Code */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDHIGH_VC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_CCID_BCM4710
value|0x4710
end_define

begin_define
define|#
directive|define
name|SIBA_CCID_BCM4704
value|0x4704
end_define

begin_define
define|#
directive|define
name|SIBA_CCID_SENTRY5
value|0x5365
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIBA_SIBAREG_H_ */
end_comment

end_unit

