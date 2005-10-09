begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Wind River Systems  * Copyright (c) 2001  *	Bill Paul<wpaul@bsdi.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_NSGPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_NSGPHYREG_H_
end_define

begin_comment
comment|/*  * NatSemi DP83891 registers  */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_STRAPOPT
value|0x10
end_define

begin_comment
comment|/* Strap options */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_PHYADDR
value|0xF800
end_define

begin_comment
comment|/* PHY address */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_COMPAT
value|0x0400
end_define

begin_comment
comment|/* Broadcom compat mode */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_MMSE
value|0x0200
end_define

begin_comment
comment|/* Manual master/slave enable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_ANEG
value|0x0100
end_define

begin_comment
comment|/* Autoneg enable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_MMSV
value|0x0080
end_define

begin_comment
comment|/* Manual master/slave setting */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_1000HDX
value|0x0010
end_define

begin_comment
comment|/* Advertise 1000 half-duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_1000FDX
value|0x0008
end_define

begin_comment
comment|/* Advertise 1000 full-duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_100_ADV
value|0x0004
end_define

begin_comment
comment|/* Advertise 100 full/half-duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_SPEED1
value|0x0002
end_define

begin_comment
comment|/* speed selection */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_SPEED0
value|0x0001
end_define

begin_comment
comment|/* speed selection */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_SPDSEL
value|(NSGPHY_STRAPOPT_SPEED1|NSGPHY_STRAPOPT_SPEED0)
end_define

begin_define
define|#
directive|define
name|NSGPHY_MII_PHYSUP
value|0x11
end_define

begin_comment
comment|/* PHY support/current status */
end_comment

begin_define
define|#
directive|define
name|PHY_SUP_SPEED1
value|0x0010
end_define

begin_comment
comment|/* speed bit 1 */
end_comment

begin_define
define|#
directive|define
name|PHY_SUP_SPEED0
value|0x0008
end_define

begin_comment
comment|/* speed bit 1 */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_SPEED1
value|0x0010
end_define

begin_comment
comment|/* speed status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_SPEED0
value|0x0008
end_define

begin_comment
comment|/* speed status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_SPDSTS
value|(NSGPHY_PHYSUP_SPEED1|NSGPHY_PHYSUP_SPEED0)
end_define

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_LNKSTS
value|0x0004
end_define

begin_comment
comment|/* link status */
end_comment

begin_define
define|#
directive|define
name|PHY_SUP_LINK
value|0x0004
end_define

begin_comment
comment|/* link status */
end_comment

begin_define
define|#
directive|define
name|PHY_SUP_DUPLEX
value|0x0002
end_define

begin_comment
comment|/* 1 == full-duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_DUPSTS
value|0x0002
end_define

begin_comment
comment|/* duplex status 1 == full */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_10BT
value|0x0001
end_define

begin_comment
comment|/* 10baseT resolved */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_SPDSTS_1000
value|0x0010
end_define

begin_define
define|#
directive|define
name|NSGPHY_SPDSTS_100
value|0x0008
end_define

begin_define
define|#
directive|define
name|NSGPHY_SPDSTS_10
value|0x0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_NSGPHY_MIIREG_H_ */
end_comment

end_unit

