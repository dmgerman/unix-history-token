begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_AMTPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_AMTPHYREG_H_
end_define

begin_comment
comment|/*  * AMD Am79C873 registers.  */
end_comment

begin_define
define|#
directive|define
name|MII_AMPHY_DSCR
value|0x10
comment|/* Specified configuration register */
value|a
end_define

begin_define
define|#
directive|define
name|DSCR_BP4B5B
value|0x8000
end_define

begin_comment
comment|/* Bypass 4B5B encoding */
end_comment

begin_define
define|#
directive|define
name|DSCR_BPSCR
value|0x4000
end_define

begin_comment
comment|/* Bypass scrambler */
end_comment

begin_define
define|#
directive|define
name|DSCR_BPALIGN
value|0x2000
end_define

begin_comment
comment|/* Bypass symbol alignment */
end_comment

begin_define
define|#
directive|define
name|DSCR_REPEATER
value|0x0800
end_define

begin_comment
comment|/* Repeater mode */
end_comment

begin_define
define|#
directive|define
name|DSCR_TX
value|0x0400
end_define

begin_comment
comment|/* TX/FX mode control */
end_comment

begin_define
define|#
directive|define
name|DSCR_UTP
value|0x0200
end_define

begin_comment
comment|/* UTP/STP mode control */
end_comment

begin_define
define|#
directive|define
name|DSCR_CLK25MDIS
value|0x0100
end_define

begin_comment
comment|/* CLK25M disable */
end_comment

begin_define
define|#
directive|define
name|DSCR_FGLNKTX
value|0x0080
end_define

begin_comment
comment|/* Force good link at 100baseTX */
end_comment

begin_define
define|#
directive|define
name|DSCR_LINKLEDCTL
value|0x0020
end_define

begin_comment
comment|/* Link LED control */
end_comment

begin_define
define|#
directive|define
name|DSCR_FDXLEDCTL
value|0x0010
end_define

begin_comment
comment|/* FDX LED control */
end_comment

begin_define
define|#
directive|define
name|DSCR_SMRTS
value|0x0008
end_define

begin_comment
comment|/* Reset state machine */
end_comment

begin_define
define|#
directive|define
name|DSCR_MFPSC
value|0x0004
end_define

begin_comment
comment|/* Preamble surpression control */
end_comment

begin_define
define|#
directive|define
name|DSCR_SLEEP
value|0x0002
end_define

begin_comment
comment|/* Sleep mode */
end_comment

begin_define
define|#
directive|define
name|DSCR_RLOUT
value|0x0001
end_define

begin_comment
comment|/* Remote loopout control */
end_comment

begin_define
define|#
directive|define
name|MII_AMPHY_DSCSR
value|0x11
end_define

begin_comment
comment|/* Specified configuration and status */
end_comment

begin_define
define|#
directive|define
name|DSCSR_100FDX
value|0x8000
end_define

begin_comment
comment|/* 100MBps full duplex */
end_comment

begin_define
define|#
directive|define
name|DSCSR_100HDX
value|0x4000
end_define

begin_comment
comment|/* 100Mbps half duplex */
end_comment

begin_define
define|#
directive|define
name|DSCSR_10FDX
value|0x2000
end_define

begin_comment
comment|/* 10Mbps full duplex */
end_comment

begin_define
define|#
directive|define
name|DSCSR_10HDX
value|0x1000
end_define

begin_comment
comment|/* 10Mbps half duplex */
end_comment

begin_define
define|#
directive|define
name|DSCSR_PADDR
value|0x01F0
end_define

begin_comment
comment|/* PHY address */
end_comment

begin_define
define|#
directive|define
name|DSCSR_ASTAT
value|0x000F
end_define

begin_comment
comment|/* Autonegotiation status */
end_comment

begin_define
define|#
directive|define
name|ASTAT_COMPLETE
value|0x8
end_define

begin_define
define|#
directive|define
name|ASTAT_PDLINK_READY_FAIL
value|0x7
end_define

begin_define
define|#
directive|define
name|ASTAT_PDLINK_READY
value|0x6
end_define

begin_define
define|#
directive|define
name|ASTAT_CONSTMATCH_FAIL
value|0x5
end_define

begin_define
define|#
directive|define
name|ASTAT_CONSTMATCH
value|0x4
end_define

begin_define
define|#
directive|define
name|ASTAT_ACKMATCH_FAIL
value|0x3
end_define

begin_define
define|#
directive|define
name|ASTAT_ACKMATCH
value|0x2
end_define

begin_define
define|#
directive|define
name|ASTAT_ABILITYMATCH
value|0x1
end_define

begin_define
define|#
directive|define
name|ASTAT_IDLE
value|0x0
end_define

begin_define
define|#
directive|define
name|MII_AMPHY_T10CSRSCR
value|0x12
end_define

begin_comment
comment|/* 10baseT configuration/status */
end_comment

begin_define
define|#
directive|define
name|T10CSRSCR_LPEN
value|0x4000
end_define

begin_comment
comment|/* Link pulse enable */
end_comment

begin_define
define|#
directive|define
name|T10CSRSCR_HBE
value|0x2000
end_define

begin_comment
comment|/* Heartbeat enable */
end_comment

begin_define
define|#
directive|define
name|T10CSRSCR_JABEN
value|0x0800
end_define

begin_comment
comment|/* Jabber enable */
end_comment

begin_define
define|#
directive|define
name|T10CSRSCR_SER
value|0x0400
end_define

begin_comment
comment|/* Serial mode enable */
end_comment

begin_define
define|#
directive|define
name|T10CSRSCR_POLR
value|0x0001
end_define

begin_comment
comment|/* Polarity reversed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_AMTPHYREG_H_ */
end_comment

end_unit

