begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007 The DragonFly Project.  All rights reserved.  *   * This code is derived from software contributed to The DragonFly Project  * by Sepherosa Ziehau<sepherosa@gmail.com>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $DragonFly: src/sys/dev/netif/mii_layer/truephyreg.h,v 1.2 2007/10/23 14:28:42 sephe Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MII_TRUEPHYREG_H
end_ifndef

begin_define
define|#
directive|define
name|_MII_TRUEPHYREG_H
end_define

begin_define
define|#
directive|define
name|TRUEPHY_INDEX
value|0x10
end_define

begin_comment
comment|/* XXX reserved in DS */
end_comment

begin_define
define|#
directive|define
name|TRUEPHY_INDEX_MAGIC
value|0x402
end_define

begin_define
define|#
directive|define
name|TRUEPHY_DATA
value|0x11
end_define

begin_comment
comment|/* XXX reserved in DS */
end_comment

begin_define
define|#
directive|define
name|TRUEPHY_CTRL
value|0x12
end_define

begin_define
define|#
directive|define
name|TRUEPHY_CTRL_DIAG
value|0x0004
end_define

begin_define
define|#
directive|define
name|TRUEPHY_CTRL_RSV1
value|0x0002
end_define

begin_comment
comment|/* XXX reserved */
end_comment

begin_define
define|#
directive|define
name|TRUEPHY_CTRL_RSV0
value|0x0001
end_define

begin_comment
comment|/* XXX reserved */
end_comment

begin_define
define|#
directive|define
name|TRUEPHY_CONF
value|0x16
end_define

begin_define
define|#
directive|define
name|TRUEPHY_CONF_TXFIFO_MASK
value|0x3000
end_define

begin_define
define|#
directive|define
name|TRUEPHY_CONF_TXFIFO_8
value|0x0000
end_define

begin_define
define|#
directive|define
name|TRUEPHY_CONF_TXFIFO_16
value|0x1000
end_define

begin_define
define|#
directive|define
name|TRUEPHY_CONF_TXFIFO_24
value|0x2000
end_define

begin_define
define|#
directive|define
name|TRUEPHY_CONF_TXFIFO_32
value|0x3000
end_define

begin_define
define|#
directive|define
name|TRUEPHY_SR
value|0x1a
end_define

begin_define
define|#
directive|define
name|TRUEPHY_SR_SPD_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|TRUEPHY_SR_SPD_1000T
value|0x0200
end_define

begin_define
define|#
directive|define
name|TRUEPHY_SR_SPD_100TX
value|0x0100
end_define

begin_define
define|#
directive|define
name|TRUEPHY_SR_SPD_10T
value|0x0000
end_define

begin_define
define|#
directive|define
name|TRUEPHY_SR_FDX
value|0x0080
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MII_TRUEPHYREG_H */
end_comment

end_unit

