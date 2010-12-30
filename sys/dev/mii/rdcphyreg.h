begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010, Pyun YongHyeon<yongari@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_RDCPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_RDCPHYREG_H_
end_define

begin_define
define|#
directive|define
name|MII_RDCPHY_DEBUG
value|0x11
end_define

begin_define
define|#
directive|define
name|DEBUG_JABBER_DIS
value|0x0040
end_define

begin_define
define|#
directive|define
name|DEBUG_LOOP_BACK_10MBPS
value|0x0400
end_define

begin_define
define|#
directive|define
name|MII_RDCPHY_CTRL
value|0x14
end_define

begin_define
define|#
directive|define
name|CTRL_SQE_ENB
value|0x0100
end_define

begin_define
define|#
directive|define
name|CTRL_NEG_POLARITY
value|0x0400
end_define

begin_define
define|#
directive|define
name|CTRL_AUTO_POLARITY
value|0x0800
end_define

begin_define
define|#
directive|define
name|CTRL_MDIXSEL_RX
value|0x2000
end_define

begin_define
define|#
directive|define
name|CTRL_MDIXSEL_TX
value|0x4000
end_define

begin_define
define|#
directive|define
name|CTRL_AUTO_MDIX_DIS
value|0x8000
end_define

begin_define
define|#
directive|define
name|MII_RDCPHY_CTRL2
value|0x15
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_DUPLEX
value|0x0000
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_DUPLEX_COL
value|0x0008
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_ACT
value|0x0010
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_SPEED_ACT
value|0x0018
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_BLK_100MBPS_DIS
value|0x0020
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_BLK_10MBPS_DIS
value|0x0040
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_BLK_LINK_ACT_DIS
value|0x0080
end_define

begin_define
define|#
directive|define
name|CTRL2_SDT_THRESH_MASK
value|0x3E00
end_define

begin_define
define|#
directive|define
name|CTRL2_TIMING_ERR_SEL
value|0x4000
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_BLK_80MS
value|0x8000
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_BLK_160MS
value|0x0000
end_define

begin_define
define|#
directive|define
name|CTRL2_LED_MASK
value|0x0018
end_define

begin_define
define|#
directive|define
name|MII_RDCPHY_STATUS
value|0x16
end_define

begin_define
define|#
directive|define
name|STATUS_AUTO_MDIX_RX
value|0x0200
end_define

begin_define
define|#
directive|define
name|STATUS_AUTO_MDIX_TX
value|0x0400
end_define

begin_define
define|#
directive|define
name|STATUS_NEG_POLARITY
value|0x0800
end_define

begin_define
define|#
directive|define
name|STATUS_FULL_DUPLEX
value|0x1000
end_define

begin_define
define|#
directive|define
name|STATUS_SPEED_10
value|0x0000
end_define

begin_define
define|#
directive|define
name|STATUS_SPEED_100
value|0x2000
end_define

begin_define
define|#
directive|define
name|STATUS_SPEED_MASK
value|0x6000
end_define

begin_define
define|#
directive|define
name|STATUS_LINK_UP
value|0x8000
end_define

begin_comment
comment|/* Analog test register 2 */
end_comment

begin_define
define|#
directive|define
name|MII_RDCPHY_TEST2
value|0x1A
end_define

begin_define
define|#
directive|define
name|TEST2_PWR_DOWN
value|0x0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_RDCPHYREG_H_ */
end_comment

end_unit

