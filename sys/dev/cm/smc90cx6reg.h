begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: smc90cx6reg.h,v 1.7 1999/02/16 23:34:13 is Exp $ */
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994, 1995, 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Ignatios Souvatzis.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * chip offsets and bits for the SMC Arcnet chipset.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMC90CXVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMC90CXVAR_H_
end_define

begin_define
define|#
directive|define
name|CM_IO_PORTS
value|16
end_define

begin_define
define|#
directive|define
name|CM_MEM_SIZE
value|0x800
end_define

begin_comment
comment|/* register offsets */
end_comment

begin_define
define|#
directive|define
name|CMSTAT
value|0
end_define

begin_define
define|#
directive|define
name|CMCMD
value|1
end_define

begin_define
define|#
directive|define
name|CMRESET
value|8
end_define

begin_comment
comment|/* memory offsets */
end_comment

begin_define
define|#
directive|define
name|CMCHECKBYTE
value|0
end_define

begin_define
define|#
directive|define
name|CMMACOFF
value|1
end_define

begin_define
define|#
directive|define
name|CM_TXDIS
value|0x01
end_define

begin_define
define|#
directive|define
name|CM_RXDIS
value|0x02
end_define

begin_define
define|#
directive|define
name|CM_TX
parameter_list|(
name|x
parameter_list|)
value|(0x03 | ((x)<<3))
end_define

begin_define
define|#
directive|define
name|CM_RX
parameter_list|(
name|x
parameter_list|)
value|(0x04 | ((x)<<3))
end_define

begin_define
define|#
directive|define
name|CM_RXBC
parameter_list|(
name|x
parameter_list|)
value|(0x84 | ((x)<<3))
end_define

begin_define
define|#
directive|define
name|CM_CONF
parameter_list|(
name|x
parameter_list|)
value|(0x05 | (x))
end_define

begin_define
define|#
directive|define
name|CLR_POR
value|0x08
end_define

begin_define
define|#
directive|define
name|CLR_RECONFIG
value|0x10
end_define

begin_define
define|#
directive|define
name|CM_CLR
parameter_list|(
name|x
parameter_list|)
value|(0x06 | (x))
end_define

begin_define
define|#
directive|define
name|CONF_LONG
value|0x08
end_define

begin_define
define|#
directive|define
name|CONF_SHORT
value|0x00
end_define

begin_comment
comment|/*  * These are not in the COM90C65 docs. Derived from the arcnet.asm  * packet driver by Philippe Prindeville and Russel Nelson.  */
end_comment

begin_define
define|#
directive|define
name|CM_LDTST
parameter_list|(
name|x
parameter_list|)
value|(0x07 | (x))
end_define

begin_define
define|#
directive|define
name|TEST_ON
value|0x08
end_define

begin_define
define|#
directive|define
name|TEST_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|CM_TA
value|1
end_define

begin_comment
comment|/* int mask also */
end_comment

begin_define
define|#
directive|define
name|CM_TMA
value|2
end_define

begin_define
define|#
directive|define
name|CM_RECON
value|4
end_define

begin_comment
comment|/* int mask also */
end_comment

begin_define
define|#
directive|define
name|CM_TEST
value|8
end_define

begin_comment
comment|/* not in the COM90C65 docs (see above) */
end_comment

begin_define
define|#
directive|define
name|CM_POR
value|0x10
end_define

begin_comment
comment|/* non maskable interrupt */
end_comment

begin_define
define|#
directive|define
name|CM_ET1
value|0x20
end_define

begin_comment
comment|/* timeout value bits, normally 1 */
end_comment

begin_define
define|#
directive|define
name|CM_ET2
value|0x40
end_define

begin_comment
comment|/* timeout value bits, normally 1 */
end_comment

begin_define
define|#
directive|define
name|CM_RI
value|0x80
end_define

begin_comment
comment|/* int mask also */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

