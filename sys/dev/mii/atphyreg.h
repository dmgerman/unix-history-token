begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, Pyun YongHyeon  * All rights reserved.  *                * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:               * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.    * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_ATPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_ATPHYREG_H_
end_define

begin_comment
comment|/*  * Registers for the Attansic/Atheros Gigabit PHY.  */
end_comment

begin_comment
comment|/* Special Control Register */
end_comment

begin_define
define|#
directive|define
name|ATPHY_SCR
value|0x10
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_JABBER_DISABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_POLARITY_REVERSAL
value|0x0002
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_SQE_TEST
value|0x0004
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_MAC_PDOWN
value|0x0008
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_CLK125_DISABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_MDI_MANUAL_MODE
value|0x0000
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_MDIX_MANUAL_MODE
value|0x0020
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_AUTO_X_1000T
value|0x0040
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_AUTO_X_MODE
value|0x0060
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_10BT_EXT_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_MII_5BIT_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_SCRAMBLER_DISABLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_FORCE_LINK_GOOD
value|0x0400
end_define

begin_define
define|#
directive|define
name|ATPHY_SCR_ASSERT_CRS_ON_TX
value|0x0800
end_define

begin_comment
comment|/* Special Status Register. */
end_comment

begin_define
define|#
directive|define
name|ATPHY_SSR
value|0x11
end_define

begin_define
define|#
directive|define
name|ATPHY_SSR_SPD_DPLX_RESOLVED
value|0x0800
end_define

begin_define
define|#
directive|define
name|ATPHY_SSR_DUPLEX
value|0x2000
end_define

begin_define
define|#
directive|define
name|ATPHY_SSR_SPEED_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|ATPHY_SSR_10MBS
value|0x0000
end_define

begin_define
define|#
directive|define
name|ATPHY_SSR_100MBS
value|0x4000
end_define

begin_define
define|#
directive|define
name|ATPHY_SSR_1000MBS
value|0x8000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_ATPHYREG_H_ */
end_comment

end_unit

