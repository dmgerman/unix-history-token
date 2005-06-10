begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_types.h	8.3 (Berkeley) 4/28/95  * $FreeBSD$  * $NetBSD: if_types.h,v 1.16 2000/04/19 06:30:53 itojun Exp $  */
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
comment|/*  * Interface types for benefit of parsing media address headers.  * This list is derived from the SNMP list of ifTypes, originally  * documented in RFC1573, now maintained as:  *  * 	http://www.iana.org/assignments/smi-numbers  */
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
comment|/* Ethernet CSMA/CD */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88023
value|0x7
end_define

begin_comment
comment|/* CMSA/CD */
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
name|IFT_IEEE80212
value|0x37
end_define

begin_comment
comment|/* 100BaseVG */
end_comment

begin_define
define|#
directive|define
name|IFT_FIBRECHANNEL
value|0x38
end_define

begin_comment
comment|/* Fibre Channel */
end_comment

begin_define
define|#
directive|define
name|IFT_HIPPIINTERFACE
value|0x39
end_define

begin_comment
comment|/* HIPPI interfaces	 */
end_comment

begin_define
define|#
directive|define
name|IFT_FRAMERELAYINTERCONNECT
value|0x3a
end_define

begin_comment
comment|/* Obsolete, use either 0x20 or 0x2c */
end_comment

begin_define
define|#
directive|define
name|IFT_AFLANE8023
value|0x3b
end_define

begin_comment
comment|/* ATM Emulated LAN for 802.3 */
end_comment

begin_define
define|#
directive|define
name|IFT_AFLANE8025
value|0x3c
end_define

begin_comment
comment|/* ATM Emulated LAN for 802.5 */
end_comment

begin_define
define|#
directive|define
name|IFT_CCTEMUL
value|0x3d
end_define

begin_comment
comment|/* ATM Emulated circuit		  */
end_comment

begin_define
define|#
directive|define
name|IFT_FASTETHER
value|0x3e
end_define

begin_comment
comment|/* Fast Ethernet (100BaseT) */
end_comment

begin_define
define|#
directive|define
name|IFT_ISDN
value|0x3f
end_define

begin_comment
comment|/* ISDN and X.25	    */
end_comment

begin_define
define|#
directive|define
name|IFT_V11
value|0x40
end_define

begin_comment
comment|/* CCITT V.11/X.21		*/
end_comment

begin_define
define|#
directive|define
name|IFT_V36
value|0x41
end_define

begin_comment
comment|/* CCITT V.36			*/
end_comment

begin_define
define|#
directive|define
name|IFT_G703AT64K
value|0x42
end_define

begin_comment
comment|/* CCITT G703 at 64Kbps */
end_comment

begin_define
define|#
directive|define
name|IFT_G703AT2MB
value|0x43
end_define

begin_comment
comment|/* Obsolete see DS1-MIB */
end_comment

begin_define
define|#
directive|define
name|IFT_QLLC
value|0x44
end_define

begin_comment
comment|/* SNA QLLC			*/
end_comment

begin_define
define|#
directive|define
name|IFT_FASTETHERFX
value|0x45
end_define

begin_comment
comment|/* Fast Ethernet (100BaseFX)	*/
end_comment

begin_define
define|#
directive|define
name|IFT_CHANNEL
value|0x46
end_define

begin_comment
comment|/* channel			*/
end_comment

begin_define
define|#
directive|define
name|IFT_IEEE80211
value|0x47
end_define

begin_comment
comment|/* radio spread spectrum	*/
end_comment

begin_define
define|#
directive|define
name|IFT_IBM370PARCHAN
value|0x48
end_define

begin_comment
comment|/* IBM System 360/370 OEMI Channel */
end_comment

begin_define
define|#
directive|define
name|IFT_ESCON
value|0x49
end_define

begin_comment
comment|/* IBM Enterprise Systems Connection */
end_comment

begin_define
define|#
directive|define
name|IFT_DLSW
value|0x4a
end_define

begin_comment
comment|/* Data Link Switching */
end_comment

begin_define
define|#
directive|define
name|IFT_ISDNS
value|0x4b
end_define

begin_comment
comment|/* ISDN S/T interface */
end_comment

begin_define
define|#
directive|define
name|IFT_ISDNU
value|0x4c
end_define

begin_comment
comment|/* ISDN U interface */
end_comment

begin_define
define|#
directive|define
name|IFT_LAPD
value|0x4d
end_define

begin_comment
comment|/* Link Access Protocol D */
end_comment

begin_define
define|#
directive|define
name|IFT_IPSWITCH
value|0x4e
end_define

begin_comment
comment|/* IP Switching Objects */
end_comment

begin_define
define|#
directive|define
name|IFT_RSRB
value|0x4f
end_define

begin_comment
comment|/* Remote Source Route Bridging */
end_comment

begin_define
define|#
directive|define
name|IFT_ATMLOGICAL
value|0x50
end_define

begin_comment
comment|/* ATM Logical Port */
end_comment

begin_define
define|#
directive|define
name|IFT_DS0
value|0x51
end_define

begin_comment
comment|/* Digital Signal Level 0 */
end_comment

begin_define
define|#
directive|define
name|IFT_DS0BUNDLE
value|0x52
end_define

begin_comment
comment|/* group of ds0s on the same ds1 */
end_comment

begin_define
define|#
directive|define
name|IFT_BSC
value|0x53
end_define

begin_comment
comment|/* Bisynchronous Protocol */
end_comment

begin_define
define|#
directive|define
name|IFT_ASYNC
value|0x54
end_define

begin_comment
comment|/* Asynchronous Protocol */
end_comment

begin_define
define|#
directive|define
name|IFT_CNR
value|0x55
end_define

begin_comment
comment|/* Combat Net Radio */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88025DTR
value|0x56
end_define

begin_comment
comment|/* ISO 802.5r DTR */
end_comment

begin_define
define|#
directive|define
name|IFT_EPLRS
value|0x57
end_define

begin_comment
comment|/* Ext Pos Loc Report Sys */
end_comment

begin_define
define|#
directive|define
name|IFT_ARAP
value|0x58
end_define

begin_comment
comment|/* Appletalk Remote Access Protocol */
end_comment

begin_define
define|#
directive|define
name|IFT_PROPCNLS
value|0x59
end_define

begin_comment
comment|/* Proprietary Connectionless Protocol*/
end_comment

begin_define
define|#
directive|define
name|IFT_HOSTPAD
value|0x5a
end_define

begin_comment
comment|/* CCITT-ITU X.29 PAD Protocol */
end_comment

begin_define
define|#
directive|define
name|IFT_TERMPAD
value|0x5b
end_define

begin_comment
comment|/* CCITT-ITU X.3 PAD Facility */
end_comment

begin_define
define|#
directive|define
name|IFT_FRAMERELAYMPI
value|0x5c
end_define

begin_comment
comment|/* Multiproto Interconnect over FR */
end_comment

begin_define
define|#
directive|define
name|IFT_X213
value|0x5d
end_define

begin_comment
comment|/* CCITT-ITU X213 */
end_comment

begin_define
define|#
directive|define
name|IFT_ADSL
value|0x5e
end_define

begin_comment
comment|/* Asymmetric Digital Subscriber Loop */
end_comment

begin_define
define|#
directive|define
name|IFT_RADSL
value|0x5f
end_define

begin_comment
comment|/* Rate-Adapt. Digital Subscriber Loop*/
end_comment

begin_define
define|#
directive|define
name|IFT_SDSL
value|0x60
end_define

begin_comment
comment|/* Symmetric Digital Subscriber Loop */
end_comment

begin_define
define|#
directive|define
name|IFT_VDSL
value|0x61
end_define

begin_comment
comment|/* Very H-Speed Digital Subscrib. Loop*/
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88025CRFPINT
value|0x62
end_define

begin_comment
comment|/* ISO 802.5 CRFP */
end_comment

begin_define
define|#
directive|define
name|IFT_MYRINET
value|0x63
end_define

begin_comment
comment|/* Myricom Myrinet */
end_comment

begin_define
define|#
directive|define
name|IFT_VOICEEM
value|0x64
end_define

begin_comment
comment|/* voice recEive and transMit */
end_comment

begin_define
define|#
directive|define
name|IFT_VOICEFXO
value|0x65
end_define

begin_comment
comment|/* voice Foreign Exchange Office */
end_comment

begin_define
define|#
directive|define
name|IFT_VOICEFXS
value|0x66
end_define

begin_comment
comment|/* voice Foreign Exchange Station */
end_comment

begin_define
define|#
directive|define
name|IFT_VOICEENCAP
value|0x67
end_define

begin_comment
comment|/* voice encapsulation */
end_comment

begin_define
define|#
directive|define
name|IFT_VOICEOVERIP
value|0x68
end_define

begin_comment
comment|/* voice over IP encapsulation */
end_comment

begin_define
define|#
directive|define
name|IFT_ATMDXI
value|0x69
end_define

begin_comment
comment|/* ATM DXI */
end_comment

begin_define
define|#
directive|define
name|IFT_ATMFUNI
value|0x6a
end_define

begin_comment
comment|/* ATM FUNI */
end_comment

begin_define
define|#
directive|define
name|IFT_ATMIMA
value|0x6b
end_define

begin_comment
comment|/* ATM IMA		      */
end_comment

begin_define
define|#
directive|define
name|IFT_PPPMULTILINKBUNDLE
value|0x6c
end_define

begin_comment
comment|/* PPP Multilink Bundle */
end_comment

begin_define
define|#
directive|define
name|IFT_IPOVERCDLC
value|0x6d
end_define

begin_comment
comment|/* IBM ipOverCdlc */
end_comment

begin_define
define|#
directive|define
name|IFT_IPOVERCLAW
value|0x6e
end_define

begin_comment
comment|/* IBM Common Link Access to Workstn */
end_comment

begin_define
define|#
directive|define
name|IFT_STACKTOSTACK
value|0x6f
end_define

begin_comment
comment|/* IBM stackToStack */
end_comment

begin_define
define|#
directive|define
name|IFT_VIRTUALIPADDRESS
value|0x70
end_define

begin_comment
comment|/* IBM VIPA */
end_comment

begin_define
define|#
directive|define
name|IFT_MPC
value|0x71
end_define

begin_comment
comment|/* IBM multi-protocol channel support */
end_comment

begin_define
define|#
directive|define
name|IFT_IPOVERATM
value|0x72
end_define

begin_comment
comment|/* IBM ipOverAtm */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88025FIBER
value|0x73
end_define

begin_comment
comment|/* ISO 802.5j Fiber Token Ring */
end_comment

begin_define
define|#
directive|define
name|IFT_TDLC
value|0x74
end_define

begin_comment
comment|/* IBM twinaxial data link control */
end_comment

begin_define
define|#
directive|define
name|IFT_GIGABITETHERNET
value|0x75
end_define

begin_comment
comment|/* Gigabit Ethernet */
end_comment

begin_define
define|#
directive|define
name|IFT_HDLC
value|0x76
end_define

begin_comment
comment|/* HDLC */
end_comment

begin_define
define|#
directive|define
name|IFT_LAPF
value|0x77
end_define

begin_comment
comment|/* LAP F */
end_comment

begin_define
define|#
directive|define
name|IFT_V37
value|0x78
end_define

begin_comment
comment|/* V.37 */
end_comment

begin_define
define|#
directive|define
name|IFT_X25MLP
value|0x79
end_define

begin_comment
comment|/* Multi-Link Protocol */
end_comment

begin_define
define|#
directive|define
name|IFT_X25HUNTGROUP
value|0x7a
end_define

begin_comment
comment|/* X25 Hunt Group */
end_comment

begin_define
define|#
directive|define
name|IFT_TRANSPHDLC
value|0x7b
end_define

begin_comment
comment|/* Transp HDLC */
end_comment

begin_define
define|#
directive|define
name|IFT_INTERLEAVE
value|0x7c
end_define

begin_comment
comment|/* Interleave channel */
end_comment

begin_define
define|#
directive|define
name|IFT_FAST
value|0x7d
end_define

begin_comment
comment|/* Fast channel */
end_comment

begin_define
define|#
directive|define
name|IFT_IP
value|0x7e
end_define

begin_comment
comment|/* IP (for APPN HPR in IP networks) */
end_comment

begin_define
define|#
directive|define
name|IFT_DOCSCABLEMACLAYER
value|0x7f
end_define

begin_comment
comment|/* CATV Mac Layer */
end_comment

begin_define
define|#
directive|define
name|IFT_DOCSCABLEDOWNSTREAM
value|0x80
end_define

begin_comment
comment|/* CATV Downstream interface */
end_comment

begin_define
define|#
directive|define
name|IFT_DOCSCABLEUPSTREAM
value|0x81
end_define

begin_comment
comment|/* CATV Upstream interface */
end_comment

begin_define
define|#
directive|define
name|IFT_A12MPPSWITCH
value|0x82
end_define

begin_comment
comment|/* Avalon Parallel Processor */
end_comment

begin_define
define|#
directive|define
name|IFT_TUNNEL
value|0x83
end_define

begin_comment
comment|/* Encapsulation interface */
end_comment

begin_define
define|#
directive|define
name|IFT_COFFEE
value|0x84
end_define

begin_comment
comment|/* coffee pot */
end_comment

begin_define
define|#
directive|define
name|IFT_CES
value|0x85
end_define

begin_comment
comment|/* Circiut Emulation Service */
end_comment

begin_define
define|#
directive|define
name|IFT_ATMSUBINTERFACE
value|0x86
end_define

begin_comment
comment|/* (x)  ATM Sub Interface */
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
name|IFT_L3IPVLAN
value|0x88
end_define

begin_comment
comment|/* Layer 3 Virtual LAN - IP Protocol */
end_comment

begin_define
define|#
directive|define
name|IFT_L3IPXVLAN
value|0x89
end_define

begin_comment
comment|/* Layer 3 Virtual LAN - IPX Prot. */
end_comment

begin_define
define|#
directive|define
name|IFT_DIGITALPOWERLINE
value|0x8a
end_define

begin_comment
comment|/* IP over Power Lines */
end_comment

begin_define
define|#
directive|define
name|IFT_MEDIAMAILOVERIP
value|0x8b
end_define

begin_comment
comment|/* (xxx)  Multimedia Mail over IP */
end_comment

begin_define
define|#
directive|define
name|IFT_DTM
value|0x8c
end_define

begin_comment
comment|/* Dynamic synchronous Transfer Mode */
end_comment

begin_define
define|#
directive|define
name|IFT_DCN
value|0x8d
end_define

begin_comment
comment|/* Data Communications Network */
end_comment

begin_define
define|#
directive|define
name|IFT_IPFORWARD
value|0x8e
end_define

begin_comment
comment|/* IP Forwarding Interface */
end_comment

begin_define
define|#
directive|define
name|IFT_MSDSL
value|0x8f
end_define

begin_comment
comment|/* Multi-rate Symmetric DSL */
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

begin_define
define|#
directive|define
name|IFT_IFGSN
value|0x91
end_define

begin_comment
comment|/* HIPPI-6400 */
end_comment

begin_define
define|#
directive|define
name|IFT_DVBRCCMACLAYER
value|0x92
end_define

begin_comment
comment|/* DVB-RCC MAC Layer */
end_comment

begin_define
define|#
directive|define
name|IFT_DVBRCCDOWNSTREAM
value|0x93
end_define

begin_comment
comment|/* DVB-RCC Downstream Channel */
end_comment

begin_define
define|#
directive|define
name|IFT_DVBRCCUPSTREAM
value|0x94
end_define

begin_comment
comment|/* DVB-RCC Upstream Channel */
end_comment

begin_define
define|#
directive|define
name|IFT_ATMVIRTUAL
value|0x95
end_define

begin_comment
comment|/* ATM Virtual Interface */
end_comment

begin_define
define|#
directive|define
name|IFT_MPLSTUNNEL
value|0x96
end_define

begin_comment
comment|/* MPLS Tunnel Virtual Interface */
end_comment

begin_define
define|#
directive|define
name|IFT_SRP
value|0x97
end_define

begin_comment
comment|/* Spatial Reuse Protocol */
end_comment

begin_define
define|#
directive|define
name|IFT_VOICEOVERATM
value|0x98
end_define

begin_comment
comment|/* Voice over ATM */
end_comment

begin_define
define|#
directive|define
name|IFT_VOICEOVERFRAMERELAY
value|0x99
end_define

begin_comment
comment|/* Voice Over Frame Relay */
end_comment

begin_define
define|#
directive|define
name|IFT_IDSL
value|0x9a
end_define

begin_comment
comment|/* Digital Subscriber Loop over ISDN */
end_comment

begin_define
define|#
directive|define
name|IFT_COMPOSITELINK
value|0x9b
end_define

begin_comment
comment|/* Avici Composite Link Interface */
end_comment

begin_define
define|#
directive|define
name|IFT_SS7SIGLINK
value|0x9c
end_define

begin_comment
comment|/* SS7 Signaling Link */
end_comment

begin_define
define|#
directive|define
name|IFT_PROPWIRELESSP2P
value|0x9d
end_define

begin_comment
comment|/* Prop. P2P wireless interface */
end_comment

begin_define
define|#
directive|define
name|IFT_FRFORWARD
value|0x9e
end_define

begin_comment
comment|/* Frame forward Interface */
end_comment

begin_define
define|#
directive|define
name|IFT_RFC1483
value|0x9f
end_define

begin_comment
comment|/* Multiprotocol over ATM AAL5 */
end_comment

begin_define
define|#
directive|define
name|IFT_USB
value|0xa0
end_define

begin_comment
comment|/* USB Interface */
end_comment

begin_define
define|#
directive|define
name|IFT_IEEE8023ADLAG
value|0xa1
end_define

begin_comment
comment|/* IEEE 802.3ad Link Aggregate*/
end_comment

begin_define
define|#
directive|define
name|IFT_BGPPOLICYACCOUNTING
value|0xa2
end_define

begin_comment
comment|/* BGP Policy Accounting */
end_comment

begin_define
define|#
directive|define
name|IFT_FRF16MFRBUNDLE
value|0xa3
end_define

begin_comment
comment|/* FRF.16 Multilik Frame Relay*/
end_comment

begin_define
define|#
directive|define
name|IFT_H323GATEKEEPER
value|0xa4
end_define

begin_comment
comment|/* H323 Gatekeeper */
end_comment

begin_define
define|#
directive|define
name|IFT_H323PROXY
value|0xa5
end_define

begin_comment
comment|/* H323 Voice and Video Proxy */
end_comment

begin_define
define|#
directive|define
name|IFT_MPLS
value|0xa6
end_define

begin_comment
comment|/* MPLS */
end_comment

begin_define
define|#
directive|define
name|IFT_MFSIGLINK
value|0xa7
end_define

begin_comment
comment|/* Multi-frequency signaling link */
end_comment

begin_define
define|#
directive|define
name|IFT_HDSL2
value|0xa8
end_define

begin_comment
comment|/* High Bit-Rate DSL, 2nd gen. */
end_comment

begin_define
define|#
directive|define
name|IFT_SHDSL
value|0xa9
end_define

begin_comment
comment|/* Multirate HDSL2 */
end_comment

begin_define
define|#
directive|define
name|IFT_DS1FDL
value|0xaa
end_define

begin_comment
comment|/* Facility Data Link (4Kbps) on a DS1*/
end_comment

begin_define
define|#
directive|define
name|IFT_POS
value|0xab
end_define

begin_comment
comment|/* Packet over SONET/SDH Interface */
end_comment

begin_define
define|#
directive|define
name|IFT_DVBASILN
value|0xac
end_define

begin_comment
comment|/* DVB-ASI Input */
end_comment

begin_define
define|#
directive|define
name|IFT_DVBASIOUT
value|0xad
end_define

begin_comment
comment|/* DVB-ASI Output */
end_comment

begin_define
define|#
directive|define
name|IFT_PLC
value|0xae
end_define

begin_comment
comment|/* Power Line Communications */
end_comment

begin_define
define|#
directive|define
name|IFT_NFAS
value|0xaf
end_define

begin_comment
comment|/* Non-Facility Associated Signaling */
end_comment

begin_define
define|#
directive|define
name|IFT_TR008
value|0xb0
end_define

begin_comment
comment|/* TROO8 */
end_comment

begin_define
define|#
directive|define
name|IFT_GR303RDT
value|0xb1
end_define

begin_comment
comment|/* Remote Digital Terminal */
end_comment

begin_define
define|#
directive|define
name|IFT_GR303IDT
value|0xb2
end_define

begin_comment
comment|/* Integrated Digital Terminal */
end_comment

begin_define
define|#
directive|define
name|IFT_ISUP
value|0xb3
end_define

begin_comment
comment|/* ISUP */
end_comment

begin_define
define|#
directive|define
name|IFT_PROPDOCSWIRELESSMACLAYER
value|0xb4
end_define

begin_comment
comment|/* prop/Wireless MAC Layer */
end_comment

begin_define
define|#
directive|define
name|IFT_PROPDOCSWIRELESSDOWNSTREAM
value|0xb5
end_define

begin_comment
comment|/* prop/Wireless Downstream */
end_comment

begin_define
define|#
directive|define
name|IFT_PROPDOCSWIRELESSUPSTREAM
value|0xb6
end_define

begin_comment
comment|/* prop/Wireless Upstream */
end_comment

begin_define
define|#
directive|define
name|IFT_HIPERLAN2
value|0xb7
end_define

begin_comment
comment|/* HIPERLAN Type 2 Radio Interface */
end_comment

begin_define
define|#
directive|define
name|IFT_PROPBWAP2MP
value|0xb8
end_define

begin_comment
comment|/* PropBroadbandWirelessAccess P2MP*/
end_comment

begin_define
define|#
directive|define
name|IFT_SONETOVERHEADCHANNEL
value|0xb9
end_define

begin_comment
comment|/* SONET Overhead Channel */
end_comment

begin_define
define|#
directive|define
name|IFT_DIGITALWRAPPEROVERHEADCHANNEL
value|0xba
end_define

begin_comment
comment|/* Digital Wrapper Overhead */
end_comment

begin_define
define|#
directive|define
name|IFT_AAL2
value|0xbb
end_define

begin_comment
comment|/* ATM adaptation layer 2 */
end_comment

begin_define
define|#
directive|define
name|IFT_RADIOMAC
value|0xbc
end_define

begin_comment
comment|/* MAC layer over radio links */
end_comment

begin_define
define|#
directive|define
name|IFT_ATMRADIO
value|0xbd
end_define

begin_comment
comment|/* ATM over radio links */
end_comment

begin_define
define|#
directive|define
name|IFT_IMT
value|0xbe
end_define

begin_comment
comment|/* Inter-Machine Trunks */
end_comment

begin_define
define|#
directive|define
name|IFT_MVL
value|0xbf
end_define

begin_comment
comment|/* Multiple Virtual Lines DSL */
end_comment

begin_define
define|#
directive|define
name|IFT_REACHDSL
value|0xc0
end_define

begin_comment
comment|/* Long Reach DSL */
end_comment

begin_define
define|#
directive|define
name|IFT_FRDLCIENDPT
value|0xc1
end_define

begin_comment
comment|/* Frame Relay DLCI End Point */
end_comment

begin_define
define|#
directive|define
name|IFT_ATMVCIENDPT
value|0xc2
end_define

begin_comment
comment|/* ATM VCI End Point */
end_comment

begin_define
define|#
directive|define
name|IFT_OPTICALCHANNEL
value|0xc3
end_define

begin_comment
comment|/* Optical Channel */
end_comment

begin_define
define|#
directive|define
name|IFT_OPTICALTRANSPORT
value|0xc4
end_define

begin_comment
comment|/* Optical Transport */
end_comment

begin_define
define|#
directive|define
name|IFT_BRIDGE
value|0xd1
end_define

begin_comment
comment|/* Transparent bridge interface */
end_comment

begin_define
define|#
directive|define
name|IFT_STF
value|0xd7
end_define

begin_comment
comment|/* 6to4 interface */
end_comment

begin_comment
comment|/* not based on IANA assignments */
end_comment

begin_define
define|#
directive|define
name|IFT_GIF
value|0xf0
end_define

begin_define
define|#
directive|define
name|IFT_PVC
value|0xf1
end_define

begin_define
define|#
directive|define
name|IFT_FAITH
value|0xf2
end_define

begin_define
define|#
directive|define
name|IFT_PFLOG
value|0xf6
end_define

begin_define
define|#
directive|define
name|IFT_PFSYNC
value|0xf7
end_define

begin_define
define|#
directive|define
name|IFT_CARP
value|0xf8
end_define

begin_comment
comment|/* Common Address Redundancy Protocol */
end_comment

begin_define
define|#
directive|define
name|IFT_IPXIP
value|0xf9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_TYPES_H_ */
end_comment

end_unit

