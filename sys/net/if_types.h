begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_types.h	8.3 (Berkeley) 4/28/95  * $FreeBSD$  * $NetBSD: if_types.h,v 1.16 2000/04/19 06:30:53 itojun Exp $  */
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

begin_typedef
typedef|typedef
enum|enum
block|{
name|IFT_OTHER
init|=
literal|0x1
block|,
comment|/* none of the following */
name|IFT_1822
init|=
literal|0x2
block|,
comment|/* old-style arpanet imp */
name|IFT_HDH1822
init|=
literal|0x3
block|,
comment|/* HDH arpanet imp */
name|IFT_X25DDN
init|=
literal|0x4
block|,
comment|/* x25 to imp */
name|IFT_X25
init|=
literal|0x5
block|,
comment|/* PDN X25 interface (RFC877) */
name|IFT_ETHER
init|=
literal|0x6
block|,
comment|/* Ethernet CSMA/CD */
name|IFT_ISO88023
init|=
literal|0x7
block|,
comment|/* CMSA/CD */
name|IFT_ISO88024
init|=
literal|0x8
block|,
comment|/* Token Bus */
name|IFT_ISO88025
init|=
literal|0x9
block|,
comment|/* Token Ring */
name|IFT_ISO88026
init|=
literal|0xa
block|,
comment|/* MAN */
name|IFT_STARLAN
init|=
literal|0xb
block|,
name|IFT_P10
init|=
literal|0xc
block|,
comment|/* Proteon 10MBit ring */
name|IFT_P80
init|=
literal|0xd
block|,
comment|/* Proteon 80MBit ring */
name|IFT_HY
init|=
literal|0xe
block|,
comment|/* Hyperchannel */
name|IFT_FDDI
init|=
literal|0xf
block|,
name|IFT_LAPB
init|=
literal|0x10
block|,
name|IFT_SDLC
init|=
literal|0x11
block|,
name|IFT_T1
init|=
literal|0x12
block|,
name|IFT_CEPT
init|=
literal|0x13
block|,
comment|/* E1 - european T1 */
name|IFT_ISDNBASIC
init|=
literal|0x14
block|,
name|IFT_ISDNPRIMARY
init|=
literal|0x15
block|,
name|IFT_PTPSERIAL
init|=
literal|0x16
block|,
comment|/* Proprietary PTP serial */
name|IFT_PPP
init|=
literal|0x17
block|,
comment|/* RFC 1331 */
name|IFT_LOOP
init|=
literal|0x18
block|,
comment|/* loopback */
name|IFT_EON
init|=
literal|0x19
block|,
comment|/* ISO over IP */
name|IFT_XETHER
init|=
literal|0x1a
block|,
comment|/* obsolete 3MB experimental ethernet */
name|IFT_NSIP
init|=
literal|0x1b
block|,
comment|/* XNS over IP */
name|IFT_SLIP
init|=
literal|0x1c
block|,
comment|/* IP over generic TTY */
name|IFT_ULTRA
init|=
literal|0x1d
block|,
comment|/* Ultra Technologies */
name|IFT_DS3
init|=
literal|0x1e
block|,
comment|/* Generic T3 */
name|IFT_SIP
init|=
literal|0x1f
block|,
comment|/* SMDS */
name|IFT_FRELAY
init|=
literal|0x20
block|,
comment|/* Frame Relay DTE only */
name|IFT_RS232
init|=
literal|0x21
block|,
name|IFT_PARA
init|=
literal|0x22
block|,
comment|/* parallel-port */
name|IFT_ARCNET
init|=
literal|0x23
block|,
name|IFT_ARCNETPLUS
init|=
literal|0x24
block|,
name|IFT_ATM
init|=
literal|0x25
block|,
comment|/* ATM cells */
name|IFT_MIOX25
init|=
literal|0x26
block|,
name|IFT_SONET
init|=
literal|0x27
block|,
comment|/* SONET or SDH */
name|IFT_X25PLE
init|=
literal|0x28
block|,
name|IFT_ISO88022LLC
init|=
literal|0x29
block|,
name|IFT_LOCALTALK
init|=
literal|0x2a
block|,
name|IFT_SMDSDXI
init|=
literal|0x2b
block|,
name|IFT_FRELAYDCE
init|=
literal|0x2c
block|,
comment|/* Frame Relay DCE */
name|IFT_V35
init|=
literal|0x2d
block|,
name|IFT_HSSI
init|=
literal|0x2e
block|,
name|IFT_HIPPI
init|=
literal|0x2f
block|,
name|IFT_MODEM
init|=
literal|0x30
block|,
comment|/* Generic Modem */
name|IFT_AAL5
init|=
literal|0x31
block|,
comment|/* AAL5 over ATM */
name|IFT_SONETPATH
init|=
literal|0x32
block|,
name|IFT_SONETVT
init|=
literal|0x33
block|,
name|IFT_SMDSICIP
init|=
literal|0x34
block|,
comment|/* SMDS InterCarrier Interface */
name|IFT_PROPVIRTUAL
init|=
literal|0x35
block|,
comment|/* Proprietary Virtual/internal */
name|IFT_PROPMUX
init|=
literal|0x36
block|,
comment|/* Proprietary Multiplexing */
name|IFT_IEEE80212
init|=
literal|0x37
block|,
comment|/* 100BaseVG */
name|IFT_FIBRECHANNEL
init|=
literal|0x38
block|,
comment|/* Fibre Channel */
name|IFT_HIPPIINTERFACE
init|=
literal|0x39
block|,
comment|/* HIPPI interfaces	 */
name|IFT_FRAMERELAYINTERCONNECT
init|=
literal|0x3a
block|,
comment|/* Obsolete, use 0x20 either 0x2c */
name|IFT_AFLANE8023
init|=
literal|0x3b
block|,
comment|/* ATM Emulated LAN for 802.3 */
name|IFT_AFLANE8025
init|=
literal|0x3c
block|,
comment|/* ATM Emulated LAN for 802.5 */
name|IFT_CCTEMUL
init|=
literal|0x3d
block|,
comment|/* ATM Emulated circuit		  */
name|IFT_FASTETHER
init|=
literal|0x3e
block|,
comment|/* Fast Ethernet (100BaseT) */
name|IFT_ISDN
init|=
literal|0x3f
block|,
comment|/* ISDN and X.25	    */
name|IFT_V11
init|=
literal|0x40
block|,
comment|/* CCITT V.11/X.21		*/
name|IFT_V36
init|=
literal|0x41
block|,
comment|/* CCITT V.36			*/
name|IFT_G703AT64K
init|=
literal|0x42
block|,
comment|/* CCITT G703 at 64Kbps */
name|IFT_G703AT2MB
init|=
literal|0x43
block|,
comment|/* Obsolete see DS1-MIB */
name|IFT_QLLC
init|=
literal|0x44
block|,
comment|/* SNA QLLC			*/
name|IFT_FASTETHERFX
init|=
literal|0x45
block|,
comment|/* Fast Ethernet (100BaseFX)	*/
name|IFT_CHANNEL
init|=
literal|0x46
block|,
comment|/* channel			*/
name|IFT_IEEE80211
init|=
literal|0x47
block|,
comment|/* radio spread spectrum (unused) */
name|IFT_IBM370PARCHAN
init|=
literal|0x48
block|,
comment|/* IBM System 360/370 OEMI Channel */
name|IFT_ESCON
init|=
literal|0x49
block|,
comment|/* IBM Enterprise Systems Connection */
name|IFT_DLSW
init|=
literal|0x4a
block|,
comment|/* Data Link Switching */
name|IFT_ISDNS
init|=
literal|0x4b
block|,
comment|/* ISDN S/T interface */
name|IFT_ISDNU
init|=
literal|0x4c
block|,
comment|/* ISDN U interface */
name|IFT_LAPD
init|=
literal|0x4d
block|,
comment|/* Link Access Protocol D */
name|IFT_IPSWITCH
init|=
literal|0x4e
block|,
comment|/* IP Switching Objects */
name|IFT_RSRB
init|=
literal|0x4f
block|,
comment|/* Remote Source Route Bridging */
name|IFT_ATMLOGICAL
init|=
literal|0x50
block|,
comment|/* ATM Logical Port */
name|IFT_DS0
init|=
literal|0x51
block|,
comment|/* Digital Signal Level 0 */
name|IFT_DS0BUNDLE
init|=
literal|0x52
block|,
comment|/* group of ds0s on the same ds1 */
name|IFT_BSC
init|=
literal|0x53
block|,
comment|/* Bisynchronous Protocol */
name|IFT_ASYNC
init|=
literal|0x54
block|,
comment|/* Asynchronous Protocol */
name|IFT_CNR
init|=
literal|0x55
block|,
comment|/* Combat Net Radio */
name|IFT_ISO88025DTR
init|=
literal|0x56
block|,
comment|/* ISO 802.5r DTR */
name|IFT_EPLRS
init|=
literal|0x57
block|,
comment|/* Ext Pos Loc Report Sys */
name|IFT_ARAP
init|=
literal|0x58
block|,
comment|/* Appletalk Remote Access Protocol */
name|IFT_PROPCNLS
init|=
literal|0x59
block|,
comment|/* Proprietary Connectionless Protocol*/
name|IFT_HOSTPAD
init|=
literal|0x5a
block|,
comment|/* CCITT-ITU X.29 PAD Protocol */
name|IFT_TERMPAD
init|=
literal|0x5b
block|,
comment|/* CCITT-ITU X.3 PAD Facility */
name|IFT_FRAMERELAYMPI
init|=
literal|0x5c
block|,
comment|/* Multiproto Interconnect over FR */
name|IFT_X213
init|=
literal|0x5d
block|,
comment|/* CCITT-ITU X213 */
name|IFT_ADSL
init|=
literal|0x5e
block|,
comment|/* Asymmetric Digital Subscriber Loop */
name|IFT_RADSL
init|=
literal|0x5f
block|,
comment|/* Rate-Adapt. Digital Subscriber Loop*/
name|IFT_SDSL
init|=
literal|0x60
block|,
comment|/* Symmetric Digital Subscriber Loop */
name|IFT_VDSL
init|=
literal|0x61
block|,
comment|/* Very H-Speed Digital Subscrib. Loop*/
name|IFT_ISO88025CRFPINT
init|=
literal|0x62
block|,
comment|/* ISO 802.5 CRFP */
name|IFT_MYRINET
init|=
literal|0x63
block|,
comment|/* Myricom Myrinet */
name|IFT_VOICEEM
init|=
literal|0x64
block|,
comment|/* voice recEive and transMit */
name|IFT_VOICEFXO
init|=
literal|0x65
block|,
comment|/* voice Foreign Exchange Office */
name|IFT_VOICEFXS
init|=
literal|0x66
block|,
comment|/* voice Foreign Exchange Station */
name|IFT_VOICEENCAP
init|=
literal|0x67
block|,
comment|/* voice encapsulation */
name|IFT_VOICEOVERIP
init|=
literal|0x68
block|,
comment|/* voice over IP encapsulation */
name|IFT_ATMDXI
init|=
literal|0x69
block|,
comment|/* ATM DXI */
name|IFT_ATMFUNI
init|=
literal|0x6a
block|,
comment|/* ATM FUNI */
name|IFT_ATMIMA
init|=
literal|0x6b
block|,
comment|/* ATM IMA		      */
name|IFT_PPPMULTILINKBUNDLE
init|=
literal|0x6c
block|,
comment|/* PPP Multilink Bundle */
name|IFT_IPOVERCDLC
init|=
literal|0x6d
block|,
comment|/* IBM ipOverCdlc */
name|IFT_IPOVERCLAW
init|=
literal|0x6e
block|,
comment|/* IBM Common Link Access to Workstn */
name|IFT_STACKTOSTACK
init|=
literal|0x6f
block|,
comment|/* IBM stackToStack */
name|IFT_VIRTUALIPADDRESS
init|=
literal|0x70
block|,
comment|/* IBM VIPA */
name|IFT_MPC
init|=
literal|0x71
block|,
comment|/* IBM multi-protocol channel support */
name|IFT_IPOVERATM
init|=
literal|0x72
block|,
comment|/* IBM ipOverAtm */
name|IFT_ISO88025FIBER
init|=
literal|0x73
block|,
comment|/* ISO 802.5j Fiber Token Ring */
name|IFT_TDLC
init|=
literal|0x74
block|,
comment|/* IBM twinaxial data link control */
name|IFT_GIGABITETHERNET
init|=
literal|0x75
block|,
comment|/* Gigabit Ethernet */
name|IFT_HDLC
init|=
literal|0x76
block|,
comment|/* HDLC */
name|IFT_LAPF
init|=
literal|0x77
block|,
comment|/* LAP F */
name|IFT_V37
init|=
literal|0x78
block|,
comment|/* V.37 */
name|IFT_X25MLP
init|=
literal|0x79
block|,
comment|/* Multi-Link Protocol */
name|IFT_X25HUNTGROUP
init|=
literal|0x7a
block|,
comment|/* X25 Hunt Group */
name|IFT_TRANSPHDLC
init|=
literal|0x7b
block|,
comment|/* Transp HDLC */
name|IFT_INTERLEAVE
init|=
literal|0x7c
block|,
comment|/* Interleave channel */
name|IFT_FAST
init|=
literal|0x7d
block|,
comment|/* Fast channel */
name|IFT_IP
init|=
literal|0x7e
block|,
comment|/* IP (for APPN HPR in IP networks) */
name|IFT_DOCSCABLEMACLAYER
init|=
literal|0x7f
block|,
comment|/* CATV Mac Layer */
name|IFT_DOCSCABLEDOWNSTREAM
init|=
literal|0x80
block|,
comment|/* CATV Downstream interface */
name|IFT_DOCSCABLEUPSTREAM
init|=
literal|0x81
block|,
comment|/* CATV Upstream interface */
name|IFT_A12MPPSWITCH
init|=
literal|0x82
block|,
comment|/* Avalon Parallel Processor */
name|IFT_TUNNEL
init|=
literal|0x83
block|,
comment|/* Encapsulation interface */
name|IFT_COFFEE
init|=
literal|0x84
block|,
comment|/* coffee pot */
name|IFT_CES
init|=
literal|0x85
block|,
comment|/* Circiut Emulation Service */
name|IFT_ATMSUBINTERFACE
init|=
literal|0x86
block|,
comment|/* (x)  ATM Sub Interface */
name|IFT_L2VLAN
init|=
literal|0x87
block|,
comment|/* Layer 2 Virtual LAN using 802.1Q */
name|IFT_L3IPVLAN
init|=
literal|0x88
block|,
comment|/* Layer 3 Virtual LAN - IP Protocol */
name|IFT_L3IPXVLAN
init|=
literal|0x89
block|,
comment|/* Layer 3 Virtual LAN - IPX Prot. */
name|IFT_DIGITALPOWERLINE
init|=
literal|0x8a
block|,
comment|/* IP over Power Lines */
name|IFT_MEDIAMAILOVERIP
init|=
literal|0x8b
block|,
comment|/* (xxx)  Multimedia Mail over IP */
name|IFT_DTM
init|=
literal|0x8c
block|,
comment|/* Dynamic synchronous Transfer Mode */
name|IFT_DCN
init|=
literal|0x8d
block|,
comment|/* Data Communications Network */
name|IFT_IPFORWARD
init|=
literal|0x8e
block|,
comment|/* IP Forwarding Interface */
name|IFT_MSDSL
init|=
literal|0x8f
block|,
comment|/* Multi-rate Symmetric DSL */
name|IFT_IEEE1394
init|=
literal|0x90
block|,
comment|/* IEEE1394 High Performance SerialBus*/
name|IFT_IFGSN
init|=
literal|0x91
block|,
comment|/* HIPPI-6400 */
name|IFT_DVBRCCMACLAYER
init|=
literal|0x92
block|,
comment|/* DVB-RCC MAC Layer */
name|IFT_DVBRCCDOWNSTREAM
init|=
literal|0x93
block|,
comment|/* DVB-RCC Downstream Channel */
name|IFT_DVBRCCUPSTREAM
init|=
literal|0x94
block|,
comment|/* DVB-RCC Upstream Channel */
name|IFT_ATMVIRTUAL
init|=
literal|0x95
block|,
comment|/* ATM Virtual Interface */
name|IFT_MPLSTUNNEL
init|=
literal|0x96
block|,
comment|/* MPLS Tunnel Virtual Interface */
name|IFT_SRP
init|=
literal|0x97
block|,
comment|/* Spatial Reuse Protocol */
name|IFT_VOICEOVERATM
init|=
literal|0x98
block|,
comment|/* Voice over ATM */
name|IFT_VOICEOVERFRAMERELAY
init|=
literal|0x99
block|,
comment|/* Voice Over Frame Relay */
name|IFT_IDSL
init|=
literal|0x9a
block|,
comment|/* Digital Subscriber Loop over ISDN */
name|IFT_COMPOSITELINK
init|=
literal|0x9b
block|,
comment|/* Avici Composite Link Interface */
name|IFT_SS7SIGLINK
init|=
literal|0x9c
block|,
comment|/* SS7 Signaling Link */
name|IFT_PROPWIRELESSP2P
init|=
literal|0x9d
block|,
comment|/* Prop. P2P wireless interface */
name|IFT_FRFORWARD
init|=
literal|0x9e
block|,
comment|/* Frame forward Interface */
name|IFT_RFC1483
init|=
literal|0x9f
block|,
comment|/* Multiprotocol over ATM AAL5 */
name|IFT_USB
init|=
literal|0xa0
block|,
comment|/* USB Interface */
name|IFT_IEEE8023ADLAG
init|=
literal|0xa1
block|,
comment|/* IEEE 802.3ad Link Aggregate*/
name|IFT_BGPPOLICYACCOUNTING
init|=
literal|0xa2
block|,
comment|/* BGP Policy Accounting */
name|IFT_FRF16MFRBUNDLE
init|=
literal|0xa3
block|,
comment|/* FRF.16 Multilik Frame Relay*/
name|IFT_H323GATEKEEPER
init|=
literal|0xa4
block|,
comment|/* H323 Gatekeeper */
name|IFT_H323PROXY
init|=
literal|0xa5
block|,
comment|/* H323 Voice and Video Proxy */
name|IFT_MPLS
init|=
literal|0xa6
block|,
comment|/* MPLS */
name|IFT_MFSIGLINK
init|=
literal|0xa7
block|,
comment|/* Multi-frequency signaling link */
name|IFT_HDSL2
init|=
literal|0xa8
block|,
comment|/* High Bit-Rate DSL, 2nd gen. */
name|IFT_SHDSL
init|=
literal|0xa9
block|,
comment|/* Multirate HDSL2 */
name|IFT_DS1FDL
init|=
literal|0xaa
block|,
comment|/* Facility Data Link (4Kbps) on a DS1*/
name|IFT_POS
init|=
literal|0xab
block|,
comment|/* Packet over SONET/SDH Interface */
name|IFT_DVBASILN
init|=
literal|0xac
block|,
comment|/* DVB-ASI Input */
name|IFT_DVBASIOUT
init|=
literal|0xad
block|,
comment|/* DVB-ASI Output */
name|IFT_PLC
init|=
literal|0xae
block|,
comment|/* Power Line Communications */
name|IFT_NFAS
init|=
literal|0xaf
block|,
comment|/* Non-Facility Associated Signaling */
name|IFT_TR008
init|=
literal|0xb0
block|,
comment|/* TROO8 */
name|IFT_GR303RDT
init|=
literal|0xb1
block|,
comment|/* Remote Digital Terminal */
name|IFT_GR303IDT
init|=
literal|0xb2
block|,
comment|/* Integrated Digital Terminal */
name|IFT_ISUP
init|=
literal|0xb3
block|,
comment|/* ISUP */
name|IFT_PROPDOCSWIRELESSMACLAYER
init|=
literal|0xb4
block|,
comment|/* prop/Wireless MAC Layer */
name|IFT_PROPDOCSWIRELESSDOWNSTREAM
init|=
literal|0xb5
block|,
comment|/* prop/Wireless Downstream */
name|IFT_PROPDOCSWIRELESSUPSTREAM
init|=
literal|0xb6
block|,
comment|/* prop/Wireless Upstream */
name|IFT_HIPERLAN2
init|=
literal|0xb7
block|,
comment|/* HIPERLAN Type 2 Radio Interface */
name|IFT_PROPBWAP2MP
init|=
literal|0xb8
block|,
comment|/* PropBroadbandWirelessAccess P2MP*/
name|IFT_SONETOVERHEADCHANNEL
init|=
literal|0xb9
block|,
comment|/* SONET Overhead Channel */
name|IFT_DIGITALWRAPPEROVERHEADCHANNEL
init|=
literal|0xba
block|,
comment|/* Digital Wrapper Overhead */
name|IFT_AAL2
init|=
literal|0xbb
block|,
comment|/* ATM adaptation layer 2 */
name|IFT_RADIOMAC
init|=
literal|0xbc
block|,
comment|/* MAC layer over radio links */
name|IFT_ATMRADIO
init|=
literal|0xbd
block|,
comment|/* ATM over radio links */
name|IFT_IMT
init|=
literal|0xbe
block|,
comment|/* Inter-Machine Trunks */
name|IFT_MVL
init|=
literal|0xbf
block|,
comment|/* Multiple Virtual Lines DSL */
name|IFT_REACHDSL
init|=
literal|0xc0
block|,
comment|/* Long Reach DSL */
name|IFT_FRDLCIENDPT
init|=
literal|0xc1
block|,
comment|/* Frame Relay DLCI End Point */
name|IFT_ATMVCIENDPT
init|=
literal|0xc2
block|,
comment|/* ATM VCI End Point */
name|IFT_OPTICALCHANNEL
init|=
literal|0xc3
block|,
comment|/* Optical Channel */
name|IFT_OPTICALTRANSPORT
init|=
literal|0xc4
block|,
comment|/* Optical Transport */
name|IFT_INFINIBAND
init|=
literal|0xc7
block|,
comment|/* Infiniband */
name|IFT_BRIDGE
init|=
literal|0xd1
block|,
comment|/* Transparent bridge interface */
name|IFT_STF
init|=
literal|0xd7
block|,
comment|/* 6to4 interface */
comment|/* 	 * Not based on IANA assignments.  Conflicting with IANA assignments. 	 * We should make them negative probably. 	 * This requires changes to struct if_data. 	 */
name|IFT_GIF
init|=
literal|0xf0
block|,
comment|/* Generic tunnel interface */
name|IFT_PVC
init|=
literal|0xf1
block|,
comment|/* Unused */
name|IFT_ENC
init|=
literal|0xf4
block|,
comment|/* Encapsulating interface */
name|IFT_PFLOG
init|=
literal|0xf6
block|,
comment|/* PF packet filter logging */
name|IFT_PFSYNC
init|=
literal|0xf7
block|,
comment|/* PF packet filter synchronization */
block|}
name|ifType
typedef|;
end_typedef

begin_comment
comment|/*  * Some (broken) software uses #ifdef IFT_TYPE to check whether  * an operating systems supports certain interface type.  Lack of  * ifdef leads to a piece of functionality compiled out.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BURN_BRIDGES
end_ifndef

begin_define
define|#
directive|define
name|IFT_BRIDGE
value|IFT_BRIDGE
end_define

begin_define
define|#
directive|define
name|IFT_PPP
value|IFT_PPP
end_define

begin_define
define|#
directive|define
name|IFT_PROPVIRTUAL
value|IFT_PROPVIRTUAL
end_define

begin_define
define|#
directive|define
name|IFT_L2VLAN
value|IFT_L2VLAN
end_define

begin_define
define|#
directive|define
name|IFT_L3IPVLAN
value|IFT_L3IPVLAN
end_define

begin_define
define|#
directive|define
name|IFT_IEEE1394
value|IFT_IEEE1394
end_define

begin_define
define|#
directive|define
name|IFT_INFINIBAND
value|IFT_INFINIBAND
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_TYPES_H_ */
end_comment

end_unit

