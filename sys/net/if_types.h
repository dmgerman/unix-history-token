begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_types.h	8.2 (Berkeley) 4/20/94  * $FreeBSD$  */
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
end_define

begin_comment
comment|/*  * Interface types for benefit of parsing media address headers.  * This list is derived from the SNMP list of ifTypes, currently  * documented in RFC1573.  */
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
comment|/* PDN X25 interface (RFC877) */
end_comment

begin_define
define|#
directive|define
name|IFT_ETHER
value|0x6
end_define

begin_comment
comment|/* Ethernet CSMACD */
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
comment|/* Proteon 80MBit ring */
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

begin_comment
comment|/* E1 - european T1 */
end_comment

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

begin_comment
comment|/* Proprietary PTP serial */
end_comment

begin_define
define|#
directive|define
name|IFT_PPP
value|0x17
end_define

begin_comment
comment|/* RFC 1331 */
end_comment

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
name|IFT_ULTRA
value|0x1d
end_define

begin_comment
comment|/* Ultra Technologies */
end_comment

begin_define
define|#
directive|define
name|IFT_DS3
value|0x1e
end_define

begin_comment
comment|/* Generic T3 */
end_comment

begin_define
define|#
directive|define
name|IFT_SIP
value|0x1f
end_define

begin_comment
comment|/* SMDS */
end_comment

begin_define
define|#
directive|define
name|IFT_FRELAY
value|0x20
end_define

begin_comment
comment|/* Frame Relay DTE only */
end_comment

begin_define
define|#
directive|define
name|IFT_RS232
value|0x21
end_define

begin_define
define|#
directive|define
name|IFT_PARA
value|0x22
end_define

begin_comment
comment|/* parallel-port */
end_comment

begin_define
define|#
directive|define
name|IFT_ARCNET
value|0x23
end_define

begin_define
define|#
directive|define
name|IFT_ARCNETPLUS
value|0x24
end_define

begin_define
define|#
directive|define
name|IFT_ATM
value|0x25
end_define

begin_comment
comment|/* ATM cells */
end_comment

begin_define
define|#
directive|define
name|IFT_MIOX25
value|0x26
end_define

begin_define
define|#
directive|define
name|IFT_SONET
value|0x27
end_define

begin_comment
comment|/* SONET or SDH */
end_comment

begin_define
define|#
directive|define
name|IFT_X25PLE
value|0x28
end_define

begin_define
define|#
directive|define
name|IFT_ISO88022LLC
value|0x29
end_define

begin_define
define|#
directive|define
name|IFT_LOCALTALK
value|0x2a
end_define

begin_define
define|#
directive|define
name|IFT_SMDSDXI
value|0x2b
end_define

begin_define
define|#
directive|define
name|IFT_FRELAYDCE
value|0x2c
end_define

begin_comment
comment|/* Frame Relay DCE */
end_comment

begin_define
define|#
directive|define
name|IFT_V35
value|0x2d
end_define

begin_define
define|#
directive|define
name|IFT_HSSI
value|0x2e
end_define

begin_define
define|#
directive|define
name|IFT_HIPPI
value|0x2f
end_define

begin_define
define|#
directive|define
name|IFT_MODEM
value|0x30
end_define

begin_comment
comment|/* Generic Modem */
end_comment

begin_define
define|#
directive|define
name|IFT_AAL5
value|0x31
end_define

begin_comment
comment|/* AAL5 over ATM */
end_comment

begin_define
define|#
directive|define
name|IFT_SONETPATH
value|0x32
end_define

begin_define
define|#
directive|define
name|IFT_SONETVT
value|0x33
end_define

begin_define
define|#
directive|define
name|IFT_SMDSICIP
value|0x34
end_define

begin_comment
comment|/* SMDS InterCarrier Interface */
end_comment

begin_define
define|#
directive|define
name|IFT_PROPVIRTUAL
value|0x35
end_define

begin_comment
comment|/* Proprietary Virtual/internal */
end_comment

begin_define
define|#
directive|define
name|IFT_PROPMUX
value|0x36
end_define

begin_comment
comment|/* Proprietary Multiplexing */
end_comment

begin_define
define|#
directive|define
name|IFT_GIF
value|0x37
end_define

begin_comment
comment|/*0xf0*/
end_comment

begin_define
define|#
directive|define
name|IFT_FAITH
value|0x38
end_define

begin_comment
comment|/*0xf2*/
end_comment

begin_define
define|#
directive|define
name|IFT_STF
value|0x39
end_define

begin_comment
comment|/*0xf3*/
end_comment

begin_define
define|#
directive|define
name|IFT_L2VLAN
value|0x87
end_define

begin_comment
comment|/* Layer 2 Virtual LAN using 802.1Q */
end_comment

begin_define
define|#
directive|define
name|IFT_IEEE1394
value|0x90
end_define

begin_comment
comment|/* IEEE1394 High Performance SerialBus*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

