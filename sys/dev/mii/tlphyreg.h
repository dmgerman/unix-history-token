begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: tlphyreg.h,v 1.1 1998/08/10 23:59:58 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Manuel Bouyer.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Manuel Bouyer.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_TLPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_TLPHYREG_H_
end_define

begin_comment
comment|/*  * Registers for the TI ThunderLAN internal PHY.  */
end_comment

begin_define
define|#
directive|define
name|MII_TLPHY_ID
value|0x10
end_define

begin_comment
comment|/* ThunderLAN PHY ID */
end_comment

begin_define
define|#
directive|define
name|ID_10BASETAUI
value|0x0001
end_define

begin_comment
comment|/* 10baseT/AUI PHY */
end_comment

begin_define
define|#
directive|define
name|MII_TLPHY_CTRL
value|0x11
end_define

begin_comment
comment|/* Control regiseter */
end_comment

begin_define
define|#
directive|define
name|CTRL_ILINK
value|0x8000
end_define

begin_comment
comment|/* Ignore link */
end_comment

begin_define
define|#
directive|define
name|CTRL_SWPOL
value|0x4000
end_define

begin_comment
comment|/* swap polarity */
end_comment

begin_define
define|#
directive|define
name|CTRL_AUISEL
value|0x2000
end_define

begin_comment
comment|/* Select AUI */
end_comment

begin_define
define|#
directive|define
name|CTRL_SQEEN
value|0x1000
end_define

begin_comment
comment|/* Enable SQE */
end_comment

begin_define
define|#
directive|define
name|CTRL_NFEW
value|0x0004
end_define

begin_comment
comment|/* Not far end wrap */
end_comment

begin_define
define|#
directive|define
name|CTRL_INTEN
value|0x0002
end_define

begin_comment
comment|/* Interrupts enable */
end_comment

begin_define
define|#
directive|define
name|CTRL_TINT
value|0x0001
end_define

begin_comment
comment|/* Test Interrupts */
end_comment

begin_define
define|#
directive|define
name|MII_TLPHY_ST
value|0x12
end_define

begin_comment
comment|/* Status register */
end_comment

begin_define
define|#
directive|define
name|ST_MII_INT
value|0x8000
end_define

begin_comment
comment|/* MII interrupt */
end_comment

begin_define
define|#
directive|define
name|ST_PHOK
value|0x4000
end_define

begin_comment
comment|/* Power high OK */
end_comment

begin_define
define|#
directive|define
name|ST_POLOK
value|0x2000
end_define

begin_comment
comment|/* Polarity OK */
end_comment

begin_define
define|#
directive|define
name|ST_TPE
value|0x1000
end_define

begin_comment
comment|/* Twisted pair energy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_TLPHYREG_H_ */
end_comment

end_unit

