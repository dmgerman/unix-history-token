begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)if_types.h	7.3 (Berkeley) 6/28/90  *	$Id: if_types.h,v 1.3 1993/10/16 17:43:25 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_TYPES_H_
value|1
end_define

begin_comment
comment|/* interface types for benefit of parsing media address headers */
end_comment

begin_define
define|#
directive|define
name|IFT_OTHER
value|0x1
end_define

begin_comment
comment|/* none of the following */
end_comment

begin_define
define|#
directive|define
name|IFT_1822
value|0x2
end_define

begin_comment
comment|/* old-style arpanet imp */
end_comment

begin_define
define|#
directive|define
name|IFT_HDH1822
value|0x3
end_define

begin_comment
comment|/* HDH arpanet imp */
end_comment

begin_define
define|#
directive|define
name|IFT_X25DDN
value|0x4
end_define

begin_comment
comment|/* x25 to imp */
end_comment

begin_define
define|#
directive|define
name|IFT_X25
value|0x5
end_define

begin_comment
comment|/* PDN X25 interface */
end_comment

begin_define
define|#
directive|define
name|IFT_ETHER
value|0x6
end_define

begin_comment
comment|/* Ethernet I or II */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88023
value|0x7
end_define

begin_comment
comment|/* CMSA CD */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88024
value|0x8
end_define

begin_comment
comment|/* Token Bus */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88025
value|0x9
end_define

begin_comment
comment|/* Token Ring */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88026
value|0xa
end_define

begin_comment
comment|/* MAN */
end_comment

begin_define
define|#
directive|define
name|IFT_STARLAN
value|0xb
end_define

begin_define
define|#
directive|define
name|IFT_P10
value|0xc
end_define

begin_comment
comment|/* Proteon 10MBit ring */
end_comment

begin_define
define|#
directive|define
name|IFT_P80
value|0xd
end_define

begin_comment
comment|/* Proteon 10MBit ring */
end_comment

begin_define
define|#
directive|define
name|IFT_HY
value|0xe
end_define

begin_comment
comment|/* Hyperchannel */
end_comment

begin_define
define|#
directive|define
name|IFT_FDDI
value|0xf
end_define

begin_define
define|#
directive|define
name|IFT_LAPB
value|0x10
end_define

begin_define
define|#
directive|define
name|IFT_SDLC
value|0x11
end_define

begin_define
define|#
directive|define
name|IFT_T1
value|0x12
end_define

begin_define
define|#
directive|define
name|IFT_CEPT
value|0x13
end_define

begin_define
define|#
directive|define
name|IFT_ISDNBASIC
value|0x14
end_define

begin_define
define|#
directive|define
name|IFT_ISDNPRIMARY
value|0x15
end_define

begin_define
define|#
directive|define
name|IFT_PTPSERIAL
value|0x16
end_define

begin_define
define|#
directive|define
name|IFT_LOOP
value|0x18
end_define

begin_comment
comment|/* loopback */
end_comment

begin_define
define|#
directive|define
name|IFT_EON
value|0x19
end_define

begin_comment
comment|/* ISO over IP */
end_comment

begin_define
define|#
directive|define
name|IFT_XETHER
value|0x1a
end_define

begin_comment
comment|/* obsolete 3MB experimental ethernet */
end_comment

begin_define
define|#
directive|define
name|IFT_NSIP
value|0x1b
end_define

begin_comment
comment|/* XNS over IP */
end_comment

begin_define
define|#
directive|define
name|IFT_SLIP
value|0x1c
end_define

begin_comment
comment|/* IP over generic TTY */
end_comment

begin_define
define|#
directive|define
name|IFT_PPP
value|0x1d
end_define

begin_comment
comment|/* PPP over generic TTY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_TYPES_H_ */
end_comment

end_unit

