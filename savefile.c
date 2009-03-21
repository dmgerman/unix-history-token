begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * savefile.c - supports offline use of tcpdump  *	Extraction/creation by Jeffrey Mogul, DECWRL  *	Modified by Steve McCanne, LBL.  *  * Used to save the received packet headers, after filtering, to  * a file, and then read them later.  * The first record in the file contains saved values for the machine  * dependent values so we can print the dump file on any architecture.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/libpcap/savefile.c,v 1.168.2.10 2008-10-06 15:38:39 gianluca Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"pcap-int.h"
end_include

begin_include
include|#
directive|include
file|"pcap/usb.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OS_PROTO_H
end_ifdef

begin_include
include|#
directive|include
file|"os-proto.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Standard libpcap format.  */
end_comment

begin_define
define|#
directive|define
name|TCPDUMP_MAGIC
value|0xa1b2c3d4
end_define

begin_comment
comment|/*  * Alexey Kuznetzov's modified libpcap format.  */
end_comment

begin_define
define|#
directive|define
name|KUZNETZOV_TCPDUMP_MAGIC
value|0xa1b2cd34
end_define

begin_comment
comment|/*  * Reserved for Francisco Mesquita<francisco.mesquita@radiomovel.pt>  * for another modified format.  */
end_comment

begin_define
define|#
directive|define
name|FMESQUITA_TCPDUMP_MAGIC
value|0xa1b234cd
end_define

begin_comment
comment|/*  * Navtel Communcations' format, with nanosecond timestamps,  * as per a request from Dumas Hwang<dumas.hwang@navtelcom.com>.  */
end_comment

begin_define
define|#
directive|define
name|NAVTEL_TCPDUMP_MAGIC
value|0xa12b3c4d
end_define

begin_comment
comment|/*  * Normal libpcap format, except for seconds/nanoseconds timestamps,  * as per a request by Ulf Lamping<ulf.lamping@web.de>  */
end_comment

begin_define
define|#
directive|define
name|NSEC_TCPDUMP_MAGIC
value|0xa1b23c4d
end_define

begin_comment
comment|/*  * We use the "receiver-makes-right" approach to byte order,  * because time is at a premium when we are writing the file.  * In other words, the pcap_file_header and pcap_pkthdr,  * records are written in host byte order.  * Note that the bytes of packet data are written out in the order in  * which they were received, so multi-byte fields in packets are not  * written in host byte order, they're written in whatever order the  * sending machine put them in.  *  * ntoh[ls] aren't sufficient because we might need to swap on a big-endian  * machine (if the file was written in little-end order).  */
end_comment

begin_define
define|#
directive|define
name|SWAPLONG
parameter_list|(
name|y
parameter_list|)
define|\
value|((((y)&0xff)<<24) | (((y)&0xff00)<<8) | (((y)&0xff0000)>>8) | (((y)>>24)&0xff))
end_define

begin_define
define|#
directive|define
name|SWAPSHORT
parameter_list|(
name|y
parameter_list|)
define|\
value|( (((y)&0xff)<<8) | ((u_short)((y)&0xff00)>>8) )
end_define

begin_define
define|#
directive|define
name|SFERR_TRUNC
value|1
end_define

begin_define
define|#
directive|define
name|SFERR_BADVERSION
value|2
end_define

begin_define
define|#
directive|define
name|SFERR_BADF
value|3
end_define

begin_define
define|#
directive|define
name|SFERR_EOF
value|4
end_define

begin_comment
comment|/* not really an error, just a status */
end_comment

begin_comment
comment|/*  * Setting O_BINARY on DOS/Windows is a bit tricky  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|SET_BINMODE
parameter_list|(
name|f
parameter_list|)
value|_setmode(_fileno(f), _O_BINARY)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__HIGHC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SET_BINMODE
parameter_list|(
name|f
parameter_list|)
value|setmode(f, O_BINARY)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET_BINMODE
parameter_list|(
name|f
parameter_list|)
value|setmode(fileno(f), O_BINARY)
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
comment|/*  * We don't write DLT_* values to the capture file header, because  * they're not the same on all platforms.  *  * Unfortunately, the various flavors of BSD have not always used the same  * numerical values for the same data types, and various patches to  * libpcap for non-BSD OSes have added their own DLT_* codes for link  * layer encapsulation types seen on those OSes, and those codes have had,  * in some cases, values that were also used, on other platforms, for other  * link layer encapsulation types.  *  * This means that capture files of a type whose numerical DLT_* code  * means different things on different BSDs, or with different versions  * of libpcap, can't always be read on systems other than those like  * the one running on the machine on which the capture was made.  *  * Instead, we define here a set of LINKTYPE_* codes, and map DLT_* codes  * to LINKTYPE_* codes when writing a savefile header, and map LINKTYPE_*  * codes to DLT_* codes when reading a savefile header.  *  * For those DLT_* codes that have, as far as we know, the same values on  * all platforms (DLT_NULL through DLT_FDDI), we define LINKTYPE_xxx as  * DLT_xxx; that way, captures of those types can still be read by  * versions of libpcap that map LINKTYPE_* values to DLT_* values, and  * captures of those types written by versions of libpcap that map DLT_  * values to LINKTYPE_ values can still be read by older versions  * of libpcap.  *  * The other LINKTYPE_* codes are given values starting at 100, in the  * hopes that no DLT_* code will be given one of those values.  *  * In order to ensure that a given LINKTYPE_* code's value will refer to  * the same encapsulation type on all platforms, you should not allocate  * a new LINKTYPE_* value without consulting  * "tcpdump-workers@lists.tcpdump.org".  The tcpdump developers will  * allocate a value for you, and will not subsequently allocate it to  * anybody else; that value will be added to the "pcap.h" in the  * tcpdump.org CVS repository, so that a future libpcap release will  * include it.  *  * You should, if possible, also contribute patches to libpcap and tcpdump  * to handle the new encapsulation type, so that they can also be checked  * into the tcpdump.org CVS repository and so that they will appear in  * future libpcap and tcpdump releases.  *  * Do *NOT* assume that any values after the largest value in this file  * are available; you might not have the most up-to-date version of this  * file, and new values after that one might have been assigned.  Also,  * do *NOT* use any values below 100 - those might already have been  * taken by one (or more!) organizations.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_NULL
value|DLT_NULL
end_define

begin_define
define|#
directive|define
name|LINKTYPE_ETHERNET
value|DLT_EN10MB
end_define

begin_comment
comment|/* also for 100Mb and up */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_EXP_ETHERNET
value|DLT_EN3MB
end_define

begin_comment
comment|/* 3Mb experimental Ethernet */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_AX25
value|DLT_AX25
end_define

begin_define
define|#
directive|define
name|LINKTYPE_PRONET
value|DLT_PRONET
end_define

begin_define
define|#
directive|define
name|LINKTYPE_CHAOS
value|DLT_CHAOS
end_define

begin_define
define|#
directive|define
name|LINKTYPE_TOKEN_RING
value|DLT_IEEE802
end_define

begin_comment
comment|/* DLT_IEEE802 is used for Token Ring */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ARCNET
value|DLT_ARCNET
end_define

begin_comment
comment|/* BSD-style headers */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_SLIP
value|DLT_SLIP
end_define

begin_define
define|#
directive|define
name|LINKTYPE_PPP
value|DLT_PPP
end_define

begin_define
define|#
directive|define
name|LINKTYPE_FDDI
value|DLT_FDDI
end_define

begin_comment
comment|/*  * LINKTYPE_PPP is for use when there might, or might not, be an RFC 1662  * PPP in HDLC-like framing header (with 0xff 0x03 before the PPP protocol  * field) at the beginning of the packet.  *  * This is for use when there is always such a header; the address field  * might be 0xff, for regular PPP, or it might be an address field for Cisco  * point-to-point with HDLC framing as per section 4.3.1 of RFC 1547 ("Cisco  * HDLC").  This is, for example, what you get with NetBSD's DLT_PPP_SERIAL.  *  * We give it the same value as NetBSD's DLT_PPP_SERIAL, in the hopes that  * nobody else will choose a DLT_ value of 50, and so that DLT_PPP_SERIAL  * captures will be written out with a link type that NetBSD's tcpdump  * can read.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PPP_HDLC
value|50
end_define

begin_comment
comment|/* PPP in HDLC-like framing */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PPP_ETHER
value|51
end_define

begin_comment
comment|/* NetBSD PPP-over-Ethernet */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_SYMANTEC_FIREWALL
value|99
end_define

begin_comment
comment|/* Symantec Enterprise Firewall */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ATM_RFC1483
value|100
end_define

begin_comment
comment|/* LLC/SNAP-encapsulated ATM */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_RAW
value|101
end_define

begin_comment
comment|/* raw IP */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_SLIP_BSDOS
value|102
end_define

begin_comment
comment|/* BSD/OS SLIP BPF header */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PPP_BSDOS
value|103
end_define

begin_comment
comment|/* BSD/OS PPP BPF header */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_C_HDLC
value|104
end_define

begin_comment
comment|/* Cisco HDLC */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_11
value|105
end_define

begin_comment
comment|/* IEEE 802.11 (wireless) */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ATM_CLIP
value|106
end_define

begin_comment
comment|/* Linux Classical IP over ATM */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_FRELAY
value|107
end_define

begin_comment
comment|/* Frame Relay */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LOOP
value|108
end_define

begin_comment
comment|/* OpenBSD loopback */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ENC
value|109
end_define

begin_comment
comment|/* OpenBSD IPSEC enc */
end_comment

begin_comment
comment|/*  * These three types are reserved for future use.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LANE8023
value|110
end_define

begin_comment
comment|/* ATM LANE + 802.3 */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_HIPPI
value|111
end_define

begin_comment
comment|/* NetBSD HIPPI */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_HDLC
value|112
end_define

begin_comment
comment|/* NetBSD HDLC framing */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LINUX_SLL
value|113
end_define

begin_comment
comment|/* Linux cooked socket capture */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LTALK
value|114
end_define

begin_comment
comment|/* Apple LocalTalk hardware */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ECONET
value|115
end_define

begin_comment
comment|/* Acorn Econet */
end_comment

begin_comment
comment|/*  * Reserved for use with OpenBSD ipfilter.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IPFILTER
value|116
end_define

begin_define
define|#
directive|define
name|LINKTYPE_PFLOG
value|117
end_define

begin_comment
comment|/* OpenBSD DLT_PFLOG */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_CISCO_IOS
value|118
end_define

begin_comment
comment|/* For Cisco-internal use */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PRISM_HEADER
value|119
end_define

begin_comment
comment|/* 802.11+Prism II monitor mode */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_AIRONET_HEADER
value|120
end_define

begin_comment
comment|/* FreeBSD Aironet driver stuff */
end_comment

begin_comment
comment|/*  * Reserved for Siemens HiPath HDLC.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_HHDLC
value|121
end_define

begin_define
define|#
directive|define
name|LINKTYPE_IP_OVER_FC
value|122
end_define

begin_comment
comment|/* RFC 2625 IP-over-Fibre Channel */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_SUNATM
value|123
end_define

begin_comment
comment|/* Solaris+SunATM */
end_comment

begin_comment
comment|/*  * Reserved as per request from Kent Dahlgren<kent@praesum.com>  * for private use.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_RIO
value|124
end_define

begin_comment
comment|/* RapidIO */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PCI_EXP
value|125
end_define

begin_comment
comment|/* PCI Express */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_AURORA
value|126
end_define

begin_comment
comment|/* Xilinx Aurora link layer */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_11_RADIO
value|127
end_define

begin_comment
comment|/* 802.11 plus BSD radio header */
end_comment

begin_comment
comment|/*  * Reserved for the TZSP encapsulation, as per request from  * Chris Waters<chris.waters@networkchemistry.com>  * TZSP is a generic encapsulation for any other link type,  * which includes a means to include meta-information  * with the packet, e.g. signal strength and channel  * for 802.11 packets.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_TZSP
value|128
end_define

begin_comment
comment|/* Tazmen Sniffer Protocol */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ARCNET_LINUX
value|129
end_define

begin_comment
comment|/* Linux-style headers */
end_comment

begin_comment
comment|/*  * Juniper-private data link types, as per request from  * Hannes Gredler<hannes@juniper.net>.  The corresponding  * DLT_s are used for passing on chassis-internal  * metainformation such as QOS profiles, etc..  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_MLPPP
value|130
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_MLFR
value|131
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_ES
value|132
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_GGSN
value|133
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_MFR
value|134
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_ATM2
value|135
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_SERVICES
value|136
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_ATM1
value|137
end_define

begin_define
define|#
directive|define
name|LINKTYPE_APPLE_IP_OVER_IEEE1394
value|138
end_define

begin_comment
comment|/* Apple IP-over-IEEE 1394 cooked header */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_MTP2_WITH_PHDR
value|139
end_define

begin_define
define|#
directive|define
name|LINKTYPE_MTP2
value|140
end_define

begin_define
define|#
directive|define
name|LINKTYPE_MTP3
value|141
end_define

begin_define
define|#
directive|define
name|LINKTYPE_SCCP
value|142
end_define

begin_define
define|#
directive|define
name|LINKTYPE_DOCSIS
value|143
end_define

begin_comment
comment|/* DOCSIS MAC frames */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LINUX_IRDA
value|144
end_define

begin_comment
comment|/* Linux-IrDA */
end_comment

begin_comment
comment|/*  * Reserved for IBM SP switch and IBM Next Federation switch.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IBM_SP
value|145
end_define

begin_define
define|#
directive|define
name|LINKTYPE_IBM_SN
value|146
end_define

begin_comment
comment|/*  * Reserved for private use.  If you have some link-layer header type  * that you want to use within your organization, with the capture files  * using that link-layer header type not ever be sent outside your  * organization, you can use these values.  *  * No libpcap release will use these for any purpose, nor will any  * tcpdump release use them, either.  *  * Do *NOT* use these in capture files that you expect anybody not using  * your private versions of capture-file-reading tools to read; in  * particular, do *NOT* use them in products, otherwise you may find that  * people won't be able to use tcpdump, or snort, or Ethereal, or... to  * read capture files from your firewall/intrusion detection/traffic  * monitoring/etc. appliance, or whatever product uses that LINKTYPE_ value,  * and you may also find that the developers of those applications will  * not accept patches to let them read those files.  *  * Also, do not use them if somebody might send you a capture using them  * for *their* private type and tools using them for *your* private type  * would have to read them.  *  * Instead, in those cases, ask "tcpdump-workers@lists.tcpdump.org" for a  * new DLT_ and LINKTYPE_ value, as per the comment in pcap/bpf.h, and use  * the type you're given.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_USER0
value|147
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER1
value|148
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER2
value|149
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER3
value|150
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER4
value|151
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER5
value|152
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER6
value|153
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER7
value|154
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER8
value|155
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER9
value|156
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER10
value|157
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER11
value|158
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER12
value|159
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER13
value|160
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER14
value|161
end_define

begin_define
define|#
directive|define
name|LINKTYPE_USER15
value|162
end_define

begin_comment
comment|/*  * For future use with 802.11 captures - defined by AbsoluteValue  * Systems to store a number of bits of link-layer information  * including radio information:  *  *	http://www.shaftnet.org/~pizza/software/capturefrm.txt  *  * but could and arguably should also be used by non-AVS Linux  * 802.11 drivers; that may happen in the future.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_11_RADIO_AVS
value|163
end_define

begin_comment
comment|/* 802.11 plus AVS radio header */
end_comment

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  The corresponding  * DLT_s are used for passing on chassis-internal  * metainformation such as QOS profiles, etc..  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_MONITOR
value|164
end_define

begin_comment
comment|/*  * Reserved for BACnet MS/TP.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_BACNET_MS_TP
value|165
end_define

begin_comment
comment|/*  * Another PPP variant as per request from Karsten Keil<kkeil@suse.de>.  *  * This is used in some OSes to allow a kernel socket filter to distinguish  * between incoming and outgoing packets, on a socket intended to  * supply pppd with outgoing packets so it can do dial-on-demand and  * hangup-on-lack-of-demand; incoming packets are filtered out so they  * don't cause pppd to hold the connection up (you don't want random  * input packets such as port scans, packets from old lost connections,  * etc. to force the connection to stay up).  *  * The first byte of the PPP header (0xff03) is modified to accomodate  * the direction - 0x00 = IN, 0x01 = OUT.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PPP_PPPD
value|166
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  The DLT_s are used  * for passing on chassis-internal metainformation such as  * QOS profiles, cookies, etc..  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_PPPOE
value|167
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_PPPOE_ATM
value|168
end_define

begin_define
define|#
directive|define
name|LINKTYPE_GPRS_LLC
value|169
end_define

begin_comment
comment|/* GPRS LLC */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_GPF_T
value|170
end_define

begin_comment
comment|/* GPF-T (ITU-T G.7041/Y.1303) */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_GPF_F
value|171
end_define

begin_comment
comment|/* GPF-T (ITU-T G.7041/Y.1303) */
end_comment

begin_comment
comment|/*  * Requested by Oolan Zimmer<oz@gcom.com> for use in Gcom's T1/E1 line  * monitoring equipment.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_GCOM_T1E1
value|172
end_define

begin_define
define|#
directive|define
name|LINKTYPE_GCOM_SERIAL
value|173
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  The DLT_ is used  * for internal communication to Physical Interface Cards (PIC)  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_PIC_PEER
value|174
end_define

begin_comment
comment|/*  * Link types requested by Gregor Maier<gregor@endace.com> of Endace  * Measurement Systems.  They add an ERF header (see  * http://www.endace.com/support/EndaceRecordFormat.pdf) in front of  * the link-layer header.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ERF_ETH
value|175
end_define

begin_comment
comment|/* Ethernet */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ERF_POS
value|176
end_define

begin_comment
comment|/* Packet-over-SONET */
end_comment

begin_comment
comment|/*  * Requested by Daniele Orlandi<daniele@orlandi.com> for raw LAPD  * for vISDN (http://www.orlandi.com/visdn/).  Its link-layer header  * includes additional information before the LAPD header, so it's  * not necessarily a generic LAPD header.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LINUX_LAPD
value|177
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.   * The Link Types are used for prepending meta-information  * like interface index, interface name  * before standard Ethernet, PPP, Frelay& C-HDLC Frames  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_ETHER
value|178
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_PPP
value|179
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_FRELAY
value|180
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_CHDLC
value|181
end_define

begin_comment
comment|/*  * Multi Link Frame Relay (FRF.16)  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_MFR
value|182
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.   * The DLT_ is used for internal communication with a  * voice Adapter Card (PIC)  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_VP
value|183
end_define

begin_comment
comment|/*  * Arinc 429 frames.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  * Every frame contains a 32bit A429 label.  * More documentation on Arinc 429 can be found at  * http://www.condoreng.com/support/downloads/tutorials/ARINCTutorial.pdf  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_A429
value|184
end_define

begin_comment
comment|/*  * Arinc 653 Interpartition Communication messages.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  * Please refer to the A653-1 standard for more information.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_A653_ICM
value|185
end_define

begin_comment
comment|/*  * USB packets, beginning with a USB setup header; requested by  * Paolo Abeni<paolo.abeni@email.it>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_USB
value|186
end_define

begin_comment
comment|/*  * Bluetooth HCI UART transport layer (part H:4); requested by  * Paolo Abeni.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_BLUETOOTH_HCI_H4
value|187
end_define

begin_comment
comment|/*  * IEEE 802.16 MAC Common Part Sublayer; requested by Maria Cruz  *<cruz_petagay@bah.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_16_MAC_CPS
value|188
end_define

begin_comment
comment|/*  * USB packets, beginning with a Linux USB header; requested by  * Paolo Abeni<paolo.abeni@email.it>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_USB_LINUX
value|189
end_define

begin_comment
comment|/*  * Controller Area Network (CAN) v. 2.0B packets.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  * Used to dump CAN packets coming from a CAN Vector board.  * More documentation on the CAN v2.0B frames can be found at  * http://www.can-cia.org/downloads/?269  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_CAN20B
value|190
end_define

begin_comment
comment|/*  * IEEE 802.15.4, with address fields padded, as is done by Linux  * drivers; requested by Juergen Schimmer.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_15_4_LINUX
value|191
end_define

begin_comment
comment|/*  * Per Packet Information encapsulated packets.  * LINKTYPE_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PPI
value|192
end_define

begin_comment
comment|/*  * Header for 802.16 MAC Common Part Sublayer plus a radiotap radio header;  * requested by Charles Clancy.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_16_MAC_CPS_RADIO
value|193
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.   * The DLT_ is used for internal communication with a  * integrated service module (ISM).  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_ISM
value|194
end_define

begin_comment
comment|/*  * IEEE 802.15.4, exactly as it appears in the spec (no padding, no  * nothing); requested by Mikko Saarnivala<mikko.saarnivala@sensinode.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_15_4
value|195
end_define

begin_comment
comment|/*  * Various link-layer types, with a pseudo-header, for SITA  * (http://www.sita.aero/); requested by Fulko Hew (fulko.hew@gmail.com).  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_SITA
value|196
end_define

begin_comment
comment|/*  * Various link-layer types, with a pseudo-header, for Endace DAG cards;  * encapsulates Endace ERF records.  Requested by Stephen Donnelly  *<stephen@endace.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ERF
value|197
end_define

begin_comment
comment|/*  * Special header prepended to Ethernet packets when capturing from a  * u10 Networks board.  Requested by Phil Mulholland  *<phil@u10networks.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_RAIF1
value|198
end_define

begin_comment
comment|/*  * IPMB packet for IPMI, beginning with the I2C slave address, followed  * by the netFn and LUN, etc..  Requested by Chanthy Toeung  *<chanthy.toeung@ca.kontron.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IPMB
value|199
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.   * The DLT_ is used for capturing data on a secure tunnel interface.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_ST
value|200
end_define

begin_comment
comment|/*  * Bluetooth HCI UART transport layer (part H:4), with pseudo-header  * that includes direction information; requested by Paolo Abeni.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_BLUETOOTH_HCI_H4_WITH_PHDR
value|201
end_define

begin_comment
comment|/*  * AX.25 packet with a 1-byte KISS header; see  *  *	http://www.ax25.net/kiss.htm  *  * as per Richard Stearn<richard@rns-stearn.demon.co.uk>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_AX25_KISS
value|202
end_define

begin_comment
comment|/*  * LAPD packets from an ISDN channel, starting with the address field,  * with no pseudo-header.  * Requested by Varuna De Silva<varunax@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LAPD
value|203
end_define

begin_comment
comment|/*  * Variants of various link-layer headers, with a one-byte direction  * pseudo-header prepended - zero means "received by this host",  * non-zero (any non-zero value) means "sent by this host" - as per  * Will Barker<w.barker@zen.co.uk>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PPP_WITH_DIR
value|204
end_define

begin_comment
comment|/* PPP */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_C_HDLC_WITH_DIR
value|205
end_define

begin_comment
comment|/* Cisco HDLC */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_FRELAY_WITH_DIR
value|206
end_define

begin_comment
comment|/* Frame Relay */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LAPB_WITH_DIR
value|207
end_define

begin_comment
comment|/* LAPB */
end_comment

begin_comment
comment|/*  * 208 is reserved for an as-yet-unspecified proprietary link-layer  * type, as requested by Will Barker.  */
end_comment

begin_comment
comment|/*  * IPMB with a Linux-specific pseudo-header; as requested by Alexey Neyman  *<avn@pigeonpoint.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IPMB_LINUX
value|209
end_define

begin_comment
comment|/*  * FlexRay automotive bus - http://www.flexray.com/ - as requested  * by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_FLEXRAY
value|210
end_define

begin_comment
comment|/*  * Media Oriented Systems Transport (MOST) bus for multimedia  * transport - http://www.mostcooperation.com/ - as requested  * by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_MOST
value|211
end_define

begin_comment
comment|/*  * Local Interconnect Network (LIN) bus for vehicle networks -  * http://www.lin-subbus.org/ - as requested by Hannes Kaelber  *<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LIN
value|212
end_define

begin_comment
comment|/*  * X2E-private data link type used for serial line capture,  * as requested by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_X2E_SERIAL
value|213
end_define

begin_comment
comment|/*  * X2E-private data link type used for the Xoraya data logger  * family, as requested by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_X2E_XORAYA
value|214
end_define

begin_comment
comment|/*  * IEEE 802.15.4, exactly as it appears in the spec (no padding, no  * nothing), but with the PHY-level data for non-ASK PHYs (4 octets  * of 0 as preamble, one octet of SFD, one octet of frame length+  * reserved bit, and then the MAC-layer data, starting with the  * frame control field).  *  * Requested by Max Filippov<jcmvbkbc@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_15_4_NONASK_PHY
value|215
end_define

begin_struct
specifier|static
struct|struct
name|linktype_map
block|{
name|int
name|dlt
decl_stmt|;
name|int
name|linktype
decl_stmt|;
block|}
name|map
index|[]
init|=
block|{
comment|/* 	 * These DLT_* codes have LINKTYPE_* codes with values identical 	 * to the values of the corresponding DLT_* code. 	 */
block|{
name|DLT_NULL
block|,
name|LINKTYPE_NULL
block|}
block|,
block|{
name|DLT_EN10MB
block|,
name|LINKTYPE_ETHERNET
block|}
block|,
block|{
name|DLT_EN3MB
block|,
name|LINKTYPE_EXP_ETHERNET
block|}
block|,
block|{
name|DLT_AX25
block|,
name|LINKTYPE_AX25
block|}
block|,
block|{
name|DLT_PRONET
block|,
name|LINKTYPE_PRONET
block|}
block|,
block|{
name|DLT_CHAOS
block|,
name|LINKTYPE_CHAOS
block|}
block|,
block|{
name|DLT_IEEE802
block|,
name|LINKTYPE_TOKEN_RING
block|}
block|,
block|{
name|DLT_ARCNET
block|,
name|LINKTYPE_ARCNET
block|}
block|,
block|{
name|DLT_SLIP
block|,
name|LINKTYPE_SLIP
block|}
block|,
block|{
name|DLT_PPP
block|,
name|LINKTYPE_PPP
block|}
block|,
block|{
name|DLT_FDDI
block|,
name|LINKTYPE_FDDI
block|}
block|,
comment|/* 	 * These DLT_* codes have different values on different 	 * platforms; we map them to LINKTYPE_* codes that 	 * have values that should never be equal to any DLT_* 	 * code. 	 */
ifdef|#
directive|ifdef
name|DLT_FR
comment|/* BSD/OS Frame Relay */
block|{
name|DLT_FR
block|,
name|LINKTYPE_FRELAY
block|}
block|,
endif|#
directive|endif
block|{
name|DLT_SYMANTEC_FIREWALL
block|,
name|LINKTYPE_SYMANTEC_FIREWALL
block|}
block|,
block|{
name|DLT_ATM_RFC1483
block|,
name|LINKTYPE_ATM_RFC1483
block|}
block|,
block|{
name|DLT_RAW
block|,
name|LINKTYPE_RAW
block|}
block|,
block|{
name|DLT_SLIP_BSDOS
block|,
name|LINKTYPE_SLIP_BSDOS
block|}
block|,
block|{
name|DLT_PPP_BSDOS
block|,
name|LINKTYPE_PPP_BSDOS
block|}
block|,
comment|/* BSD/OS Cisco HDLC */
block|{
name|DLT_C_HDLC
block|,
name|LINKTYPE_C_HDLC
block|}
block|,
comment|/* 	 * These DLT_* codes are not on all platforms, but, so far, 	 * there don't appear to be any platforms that define 	 * other codes with those values; we map them to 	 * different LINKTYPE_* values anyway, just in case. 	 */
comment|/* Linux ATM Classical IP */
block|{
name|DLT_ATM_CLIP
block|,
name|LINKTYPE_ATM_CLIP
block|}
block|,
comment|/* NetBSD sync/async serial PPP (or Cisco HDLC) */
block|{
name|DLT_PPP_SERIAL
block|,
name|LINKTYPE_PPP_HDLC
block|}
block|,
comment|/* NetBSD PPP over Ethernet */
block|{
name|DLT_PPP_ETHER
block|,
name|LINKTYPE_PPP_ETHER
block|}
block|,
comment|/* IEEE 802.11 wireless */
block|{
name|DLT_IEEE802_11
block|,
name|LINKTYPE_IEEE802_11
block|}
block|,
comment|/* Frame Relay */
block|{
name|DLT_FRELAY
block|,
name|LINKTYPE_FRELAY
block|}
block|,
comment|/* OpenBSD loopback */
block|{
name|DLT_LOOP
block|,
name|LINKTYPE_LOOP
block|}
block|,
comment|/* Linux cooked socket capture */
block|{
name|DLT_LINUX_SLL
block|,
name|LINKTYPE_LINUX_SLL
block|}
block|,
comment|/* Apple LocalTalk hardware */
block|{
name|DLT_LTALK
block|,
name|LINKTYPE_LTALK
block|}
block|,
comment|/* Acorn Econet */
block|{
name|DLT_ECONET
block|,
name|LINKTYPE_ECONET
block|}
block|,
comment|/* OpenBSD DLT_PFLOG */
block|{
name|DLT_PFLOG
block|,
name|LINKTYPE_PFLOG
block|}
block|,
comment|/* For Cisco-internal use */
block|{
name|DLT_CISCO_IOS
block|,
name|LINKTYPE_CISCO_IOS
block|}
block|,
comment|/* Prism II monitor-mode header plus 802.11 header */
block|{
name|DLT_PRISM_HEADER
block|,
name|LINKTYPE_PRISM_HEADER
block|}
block|,
comment|/* FreeBSD Aironet driver stuff */
block|{
name|DLT_AIRONET_HEADER
block|,
name|LINKTYPE_AIRONET_HEADER
block|}
block|,
comment|/* Siemens HiPath HDLC */
block|{
name|DLT_HHDLC
block|,
name|LINKTYPE_HHDLC
block|}
block|,
comment|/* RFC 2625 IP-over-Fibre Channel */
block|{
name|DLT_IP_OVER_FC
block|,
name|LINKTYPE_IP_OVER_FC
block|}
block|,
comment|/* Solaris+SunATM */
block|{
name|DLT_SUNATM
block|,
name|LINKTYPE_SUNATM
block|}
block|,
comment|/* RapidIO */
block|{
name|DLT_RIO
block|,
name|LINKTYPE_RIO
block|}
block|,
comment|/* PCI Express */
block|{
name|DLT_PCI_EXP
block|,
name|LINKTYPE_PCI_EXP
block|}
block|,
comment|/* Xilinx Aurora link layer */
block|{
name|DLT_AURORA
block|,
name|LINKTYPE_AURORA
block|}
block|,
comment|/* 802.11 plus BSD radio header */
block|{
name|DLT_IEEE802_11_RADIO
block|,
name|LINKTYPE_IEEE802_11_RADIO
block|}
block|,
comment|/* Tazmen Sniffer Protocol */
block|{
name|DLT_TZSP
block|,
name|LINKTYPE_TZSP
block|}
block|,
comment|/* Arcnet with Linux-style link-layer headers */
block|{
name|DLT_ARCNET_LINUX
block|,
name|LINKTYPE_ARCNET_LINUX
block|}
block|,
comment|/* Juniper-internal chassis encapsulation */
block|{
name|DLT_JUNIPER_MLPPP
block|,
name|LINKTYPE_JUNIPER_MLPPP
block|}
block|,
block|{
name|DLT_JUNIPER_MLFR
block|,
name|LINKTYPE_JUNIPER_MLFR
block|}
block|,
block|{
name|DLT_JUNIPER_ES
block|,
name|LINKTYPE_JUNIPER_ES
block|}
block|,
block|{
name|DLT_JUNIPER_GGSN
block|,
name|LINKTYPE_JUNIPER_GGSN
block|}
block|,
block|{
name|DLT_JUNIPER_MFR
block|,
name|LINKTYPE_JUNIPER_MFR
block|}
block|,
block|{
name|DLT_JUNIPER_ATM2
block|,
name|LINKTYPE_JUNIPER_ATM2
block|}
block|,
block|{
name|DLT_JUNIPER_SERVICES
block|,
name|LINKTYPE_JUNIPER_SERVICES
block|}
block|,
block|{
name|DLT_JUNIPER_ATM1
block|,
name|LINKTYPE_JUNIPER_ATM1
block|}
block|,
comment|/* Apple IP-over-IEEE 1394 cooked header */
block|{
name|DLT_APPLE_IP_OVER_IEEE1394
block|,
name|LINKTYPE_APPLE_IP_OVER_IEEE1394
block|}
block|,
comment|/* SS7 */
block|{
name|DLT_MTP2_WITH_PHDR
block|,
name|LINKTYPE_MTP2_WITH_PHDR
block|}
block|,
block|{
name|DLT_MTP2
block|,
name|LINKTYPE_MTP2
block|}
block|,
block|{
name|DLT_MTP3
block|,
name|LINKTYPE_MTP3
block|}
block|,
block|{
name|DLT_SCCP
block|,
name|LINKTYPE_SCCP
block|}
block|,
comment|/* DOCSIS MAC frames */
block|{
name|DLT_DOCSIS
block|,
name|LINKTYPE_DOCSIS
block|}
block|,
comment|/* IrDA IrLAP packets + Linux-cooked header */
block|{
name|DLT_LINUX_IRDA
block|,
name|LINKTYPE_LINUX_IRDA
block|}
block|,
comment|/* IBM SP and Next Federation switches */
block|{
name|DLT_IBM_SP
block|,
name|LINKTYPE_IBM_SP
block|}
block|,
block|{
name|DLT_IBM_SN
block|,
name|LINKTYPE_IBM_SN
block|}
block|,
comment|/* 802.11 plus AVS radio header */
block|{
name|DLT_IEEE802_11_RADIO_AVS
block|,
name|LINKTYPE_IEEE802_11_RADIO_AVS
block|}
block|,
comment|/* 	 * Any platform that defines additional DLT_* codes should: 	 * 	 *	request a LINKTYPE_* code and value from tcpdump.org, 	 *	as per the above; 	 * 	 *	add, in their version of libpcap, an entry to map 	 *	those DLT_* codes to the corresponding LINKTYPE_* 	 *	code; 	 * 	 *	redefine, in their "net/bpf.h", any DLT_* values 	 *	that collide with the values used by their additional 	 *	DLT_* codes, to remove those collisions (but without 	 *	making them collide with any of the LINKTYPE_* 	 *	values equal to 50 or above; they should also avoid 	 *	defining DLT_* values that collide with those 	 *	LINKTYPE_* values, either). 	 */
comment|/* Juniper-internal chassis encapsulation */
block|{
name|DLT_JUNIPER_MONITOR
block|,
name|LINKTYPE_JUNIPER_MONITOR
block|}
block|,
comment|/* BACnet MS/TP */
block|{
name|DLT_BACNET_MS_TP
block|,
name|LINKTYPE_BACNET_MS_TP
block|}
block|,
comment|/* PPP for pppd, with direction flag in the PPP header */
block|{
name|DLT_PPP_PPPD
block|,
name|LINKTYPE_PPP_PPPD
block|}
block|,
comment|/* Juniper-internal chassis encapsulation */
block|{
name|DLT_JUNIPER_PPPOE
block|,
name|LINKTYPE_JUNIPER_PPPOE
block|}
block|,
block|{
name|DLT_JUNIPER_PPPOE_ATM
block|,
name|LINKTYPE_JUNIPER_PPPOE_ATM
block|}
block|,
comment|/* GPRS LLC */
block|{
name|DLT_GPRS_LLC
block|,
name|LINKTYPE_GPRS_LLC
block|}
block|,
comment|/* Transparent Generic Framing Procedure (ITU-T G.7041/Y.1303) */
block|{
name|DLT_GPF_T
block|,
name|LINKTYPE_GPF_T
block|}
block|,
comment|/* Framed Generic Framing Procedure (ITU-T G.7041/Y.1303) */
block|{
name|DLT_GPF_F
block|,
name|LINKTYPE_GPF_F
block|}
block|,
block|{
name|DLT_GCOM_T1E1
block|,
name|LINKTYPE_GCOM_T1E1
block|}
block|,
block|{
name|DLT_GCOM_SERIAL
block|,
name|LINKTYPE_GCOM_SERIAL
block|}
block|,
comment|/* Juniper-internal chassis encapsulation */
block|{
name|DLT_JUNIPER_PIC_PEER
block|,
name|LINKTYPE_JUNIPER_PIC_PEER
block|}
block|,
comment|/* Endace types */
block|{
name|DLT_ERF_ETH
block|,
name|LINKTYPE_ERF_ETH
block|}
block|,
block|{
name|DLT_ERF_POS
block|,
name|LINKTYPE_ERF_POS
block|}
block|,
comment|/* viSDN LAPD */
block|{
name|DLT_LINUX_LAPD
block|,
name|LINKTYPE_LINUX_LAPD
block|}
block|,
comment|/* Juniper meta-information before Ether, PPP, Frame Relay, C-HDLC Frames */
block|{
name|DLT_JUNIPER_ETHER
block|,
name|LINKTYPE_JUNIPER_ETHER
block|}
block|,
block|{
name|DLT_JUNIPER_PPP
block|,
name|LINKTYPE_JUNIPER_PPP
block|}
block|,
block|{
name|DLT_JUNIPER_FRELAY
block|,
name|LINKTYPE_JUNIPER_FRELAY
block|}
block|,
block|{
name|DLT_JUNIPER_CHDLC
block|,
name|LINKTYPE_JUNIPER_CHDLC
block|}
block|,
comment|/* Multi Link Frame Relay (FRF.16) */
block|{
name|DLT_MFR
block|,
name|LINKTYPE_MFR
block|}
block|,
comment|/* Juniper Voice PIC */
block|{
name|DLT_JUNIPER_VP
block|,
name|LINKTYPE_JUNIPER_VP
block|}
block|,
comment|/* Controller Area Network (CAN) v2.0B */
block|{
name|DLT_A429
block|,
name|LINKTYPE_A429
block|}
block|,
comment|/* Arinc 653 Interpartition Communication messages */
block|{
name|DLT_A653_ICM
block|,
name|LINKTYPE_A653_ICM
block|}
block|,
comment|/* USB */
block|{
name|DLT_USB
block|,
name|LINKTYPE_USB
block|}
block|,
comment|/* Bluetooth HCI UART transport layer */
block|{
name|DLT_BLUETOOTH_HCI_H4
block|,
name|LINKTYPE_BLUETOOTH_HCI_H4
block|}
block|,
comment|/* IEEE 802.16 MAC Common Part Sublayer */
block|{
name|DLT_IEEE802_16_MAC_CPS
block|,
name|LINKTYPE_IEEE802_16_MAC_CPS
block|}
block|,
comment|/* USB with Linux header */
block|{
name|DLT_USB_LINUX
block|,
name|LINKTYPE_USB_LINUX
block|}
block|,
comment|/* Controller Area Network (CAN) v2.0B */
block|{
name|DLT_CAN20B
block|,
name|LINKTYPE_CAN20B
block|}
block|,
comment|/* IEEE 802.15.4 with address fields padded */
block|{
name|DLT_IEEE802_15_4_LINUX
block|,
name|LINKTYPE_IEEE802_15_4_LINUX
block|}
block|,
comment|/* Per Packet Information encapsulated packets */
block|{
name|DLT_PPI
block|,
name|LINKTYPE_PPI
block|}
block|,
comment|/* IEEE 802.16 MAC Common Part Sublayer plus radiotap header */
block|{
name|DLT_IEEE802_16_MAC_CPS_RADIO
block|,
name|LINKTYPE_IEEE802_16_MAC_CPS_RADIO
block|}
block|,
comment|/* Juniper Voice ISM */
block|{
name|DLT_JUNIPER_ISM
block|,
name|LINKTYPE_JUNIPER_ISM
block|}
block|,
comment|/* IEEE 802.15.4 exactly as it appears in the spec */
block|{
name|DLT_IEEE802_15_4
block|,
name|LINKTYPE_IEEE802_15_4
block|}
block|,
comment|/* Various link-layer types for SITA */
block|{
name|DLT_SITA
block|,
name|LINKTYPE_SITA
block|}
block|,
comment|/* Various link-layer types for Endace */
block|{
name|DLT_ERF
block|,
name|LINKTYPE_ERF
block|}
block|,
comment|/* Special header for u10 Networks boards */
block|{
name|DLT_RAIF1
block|,
name|LINKTYPE_RAIF1
block|}
block|,
comment|/* IPMB */
block|{
name|DLT_IPMB
block|,
name|LINKTYPE_IPMB
block|}
block|,
comment|/* Juniper Secure Tunnel */
block|{
name|DLT_JUNIPER_ST
block|,
name|LINKTYPE_JUNIPER_ST
block|}
block|,
comment|/* Bluetooth HCI UART transport layer, with pseudo-header */
block|{
name|DLT_BLUETOOTH_HCI_H4_WITH_PHDR
block|,
name|LINKTYPE_BLUETOOTH_HCI_H4_WITH_PHDR
block|}
block|,
comment|/* AX.25 with KISS header */
block|{
name|DLT_AX25_KISS
block|,
name|LINKTYPE_AX25_KISS
block|}
block|,
comment|/* Raw LAPD, with no pseudo-header */
block|{
name|DLT_LAPD
block|,
name|LINKTYPE_LAPD
block|}
block|,
comment|/* PPP with one-byte pseudo-header giving direction */
block|{
name|DLT_PPP_WITH_DIR
block|,
name|LINKTYPE_PPP_WITH_DIR
block|}
block|,
comment|/* Cisco HDLC with one-byte pseudo-header giving direction */
block|{
name|DLT_C_HDLC_WITH_DIR
block|,
name|LINKTYPE_C_HDLC_WITH_DIR
block|}
block|,
comment|/* Frame Relay with one-byte pseudo-header giving direction */
block|{
name|DLT_FRELAY_WITH_DIR
block|,
name|LINKTYPE_FRELAY_WITH_DIR
block|}
block|,
comment|/* LAPB with one-byte pseudo-header giving direction */
block|{
name|DLT_LAPB_WITH_DIR
block|,
name|LINKTYPE_LAPB_WITH_DIR
block|}
block|,
comment|/* IPMB with Linux pseudo-header */
block|{
name|DLT_IPMB_LINUX
block|,
name|LINKTYPE_IPMB_LINUX
block|}
block|,
comment|/* FlexRay */
block|{
name|DLT_FLEXRAY
block|,
name|LINKTYPE_FLEXRAY
block|}
block|,
comment|/* MOST */
block|{
name|DLT_MOST
block|,
name|LINKTYPE_MOST
block|}
block|,
comment|/* LIN */
block|{
name|DLT_LIN
block|,
name|LINKTYPE_LIN
block|}
block|,
comment|/* X2E-private serial line capture */
block|{
name|DLT_X2E_SERIAL
block|,
name|LINKTYPE_X2E_SERIAL
block|}
block|,
comment|/* X2E-private for Xoraya data logger family */
block|{
name|DLT_X2E_XORAYA
block|,
name|LINKTYPE_X2E_XORAYA
block|}
block|,
comment|/* IEEE 802.15.4 with PHY data for non-ASK PHYs */
block|{
name|DLT_IEEE802_15_4_NONASK_PHY
block|,
name|LINKTYPE_IEEE802_15_4_NONASK_PHY
block|}
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mechanism for storing information about a capture in the upper  * 6 bits of a linktype value in a capture file.  *  * LT_LINKTYPE_EXT(x) extracts the additional information.  *  * The rest of the bits are for a value describing the link-layer  * value.  LT_LINKTYPE(x) extracts that value.  */
end_comment

begin_define
define|#
directive|define
name|LT_LINKTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x03FFFFFF)
end_define

begin_define
define|#
directive|define
name|LT_LINKTYPE_EXT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFC000000)
end_define

begin_function
specifier|static
name|int
name|dlt_to_linktype
parameter_list|(
name|int
name|dlt
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|map
index|[
name|i
index|]
operator|.
name|dlt
operator|!=
operator|-
literal|1
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|map
index|[
name|i
index|]
operator|.
name|dlt
operator|==
name|dlt
condition|)
return|return
operator|(
name|map
index|[
name|i
index|]
operator|.
name|linktype
operator|)
return|;
block|}
comment|/* 	 * If we don't have a mapping for this DLT_ code, return an 	 * error; that means that the table above needs to have an 	 * entry added. 	 */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|linktype_to_dlt
parameter_list|(
name|int
name|linktype
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|map
index|[
name|i
index|]
operator|.
name|linktype
operator|!=
operator|-
literal|1
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|map
index|[
name|i
index|]
operator|.
name|linktype
operator|==
name|linktype
condition|)
return|return
operator|(
name|map
index|[
name|i
index|]
operator|.
name|dlt
operator|)
return|;
block|}
comment|/* 	 * If we don't have an entry for this link type, return 	 * the link type value; it may be a DLT_ value from an 	 * older version of libpcap. 	 */
return|return
name|linktype
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sf_write_header
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|int
name|linktype
parameter_list|,
name|int
name|thiszone
parameter_list|,
name|int
name|snaplen
parameter_list|)
block|{
name|struct
name|pcap_file_header
name|hdr
decl_stmt|;
name|hdr
operator|.
name|magic
operator|=
name|TCPDUMP_MAGIC
expr_stmt|;
name|hdr
operator|.
name|version_major
operator|=
name|PCAP_VERSION_MAJOR
expr_stmt|;
name|hdr
operator|.
name|version_minor
operator|=
name|PCAP_VERSION_MINOR
expr_stmt|;
name|hdr
operator|.
name|thiszone
operator|=
name|thiszone
expr_stmt|;
name|hdr
operator|.
name|snaplen
operator|=
name|snaplen
expr_stmt|;
name|hdr
operator|.
name|sigfigs
operator|=
literal|0
expr_stmt|;
name|hdr
operator|.
name|linktype
operator|=
name|linktype
expr_stmt|;
if|if
condition|(
name|fwrite
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|hdr
argument_list|,
sizeof|sizeof
argument_list|(
name|hdr
argument_list|)
argument_list|,
literal|1
argument_list|,
name|fp
argument_list|)
operator|!=
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|swap_hdr
parameter_list|(
name|struct
name|pcap_file_header
modifier|*
name|hp
parameter_list|)
block|{
name|hp
operator|->
name|version_major
operator|=
name|SWAPSHORT
argument_list|(
name|hp
operator|->
name|version_major
argument_list|)
expr_stmt|;
name|hp
operator|->
name|version_minor
operator|=
name|SWAPSHORT
argument_list|(
name|hp
operator|->
name|version_minor
argument_list|)
expr_stmt|;
name|hp
operator|->
name|thiszone
operator|=
name|SWAPLONG
argument_list|(
name|hp
operator|->
name|thiszone
argument_list|)
expr_stmt|;
name|hp
operator|->
name|sigfigs
operator|=
name|SWAPLONG
argument_list|(
name|hp
operator|->
name|sigfigs
argument_list|)
expr_stmt|;
name|hp
operator|->
name|snaplen
operator|=
name|SWAPLONG
argument_list|(
name|hp
operator|->
name|snaplen
argument_list|)
expr_stmt|;
name|hp
operator|->
name|linktype
operator|=
name|SWAPLONG
argument_list|(
name|hp
operator|->
name|linktype
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|sf_getnonblock
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
block|{
comment|/* 	 * This is a savefile, not a live capture file, so never say 	 * it's in non-blocking mode. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sf_setnonblock
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|int
name|nonblock
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
block|{
comment|/* 	 * This is a savefile, not a live capture file, so ignore 	 * requests to put it in non-blocking mode. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sf_stats
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|struct
name|pcap_stat
modifier|*
name|ps
parameter_list|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"Statistics aren't available from savefiles"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_function
specifier|static
name|int
name|sf_setbuff
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|int
name|dim
parameter_list|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"The kernel buffer size cannot be set while reading from a file"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sf_setmode
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|int
name|mode
parameter_list|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"impossible to set mode while reading from a file"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sf_setmintocopy
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"The mintocopy parameter cannot be set while reading from a file"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|int
name|sf_inject
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
name|_U_
parameter_list|,
name|size_t
name|size
name|_U_
parameter_list|)
block|{
name|strlcpy
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
literal|"Sending packets isn't supported on savefiles"
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Set direction flag: Which packets do we accept on a forwarding  * single device? IN, OUT or both?  */
end_comment

begin_function
specifier|static
name|int
name|sf_setdirection
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|pcap_direction_t
name|d
parameter_list|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|p
operator|->
name|errbuf
argument_list|)
argument_list|,
literal|"Setting direction is not supported on savefiles"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|sf_cleanup
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|p
operator|->
name|sf
operator|.
name|rfile
operator|!=
name|stdin
condition|)
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|p
operator|->
name|sf
operator|.
name|rfile
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|sf
operator|.
name|base
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|p
operator|->
name|sf
operator|.
name|base
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|pcap_t
modifier|*
name|pcap_open_offline
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|pcap_t
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|fname
index|[
literal|0
index|]
operator|==
literal|'-'
operator|&&
name|fname
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
block|{
name|fp
operator|=
name|stdin
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
comment|/* 		 * We're reading from the standard input, so put it in binary 		 * mode, as savefiles are binary files. 		 */
name|SET_BINMODE
argument_list|(
name|fp
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
name|fp
operator|=
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
else|#
directive|else
name|fp
operator|=
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"rb"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|fp
operator|==
name|NULL
condition|)
block|{
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"%s: %s"
argument_list|,
name|fname
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
block|}
name|p
operator|=
name|pcap_fopen_offline
argument_list|(
name|fp
argument_list|,
name|errbuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|fp
operator|!=
name|stdin
condition|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_function
name|pcap_t
modifier|*
name|pcap_hopen_offline
parameter_list|(
name|intptr_t
name|osfd
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
block|{
name|int
name|fd
decl_stmt|;
name|FILE
modifier|*
name|file
decl_stmt|;
name|fd
operator|=
name|_open_osfhandle
argument_list|(
name|osfd
argument_list|,
name|_O_RDONLY
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|file
operator|=
name|_fdopen
argument_list|(
name|fd
argument_list|,
literal|"rb"
argument_list|)
expr_stmt|;
if|if
condition|(
name|file
operator|==
name|NULL
condition|)
block|{
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|pcap_fopen_offline
argument_list|(
name|file
argument_list|,
name|errbuf
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_function
specifier|static
endif|#
directive|endif
name|pcap_t
modifier|*
name|pcap_fopen_offline
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
block|{
specifier|register
name|pcap_t
modifier|*
name|p
decl_stmt|;
name|struct
name|pcap_file_header
name|hdr
decl_stmt|;
name|size_t
name|amt_read
decl_stmt|;
name|bpf_u_int32
name|magic
decl_stmt|;
name|int
name|linklen
decl_stmt|;
name|p
operator|=
operator|(
name|pcap_t
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|p
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
block|{
name|strlcpy
argument_list|(
name|errbuf
argument_list|,
literal|"out of swap"
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|memset
argument_list|(
operator|(
name|char
operator|*
operator|)
name|p
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|p
argument_list|)
argument_list|)
expr_stmt|;
name|amt_read
operator|=
name|fread
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|hdr
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|hdr
argument_list|)
argument_list|,
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|amt_read
operator|!=
sizeof|sizeof
argument_list|(
name|hdr
argument_list|)
condition|)
block|{
if|if
condition|(
name|ferror
argument_list|(
name|fp
argument_list|)
condition|)
block|{
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"error reading dump file: %s"
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"truncated dump file; tried to read %lu file header bytes, only got %lu"
argument_list|,
operator|(
name|unsigned
name|long
operator|)
sizeof|sizeof
argument_list|(
name|hdr
argument_list|)
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|amt_read
argument_list|)
expr_stmt|;
block|}
goto|goto
name|bad
goto|;
block|}
name|magic
operator|=
name|hdr
operator|.
name|magic
expr_stmt|;
if|if
condition|(
name|magic
operator|!=
name|TCPDUMP_MAGIC
operator|&&
name|magic
operator|!=
name|KUZNETZOV_TCPDUMP_MAGIC
condition|)
block|{
name|magic
operator|=
name|SWAPLONG
argument_list|(
name|magic
argument_list|)
expr_stmt|;
if|if
condition|(
name|magic
operator|!=
name|TCPDUMP_MAGIC
operator|&&
name|magic
operator|!=
name|KUZNETZOV_TCPDUMP_MAGIC
condition|)
block|{
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"bad dump file format"
argument_list|)
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
name|p
operator|->
name|sf
operator|.
name|swapped
operator|=
literal|1
expr_stmt|;
name|swap_hdr
argument_list|(
operator|&
name|hdr
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|magic
operator|==
name|KUZNETZOV_TCPDUMP_MAGIC
condition|)
block|{
comment|/* 		 * XXX - the patch that's in some versions of libpcap 		 * changes the packet header but not the magic number, 		 * and some other versions with this magic number have 		 * some extra debugging information in the packet header; 		 * we'd have to use some hacks^H^H^H^H^Hheuristics to 		 * detect those variants. 		 * 		 * Ethereal does that, but it does so by trying to read 		 * the first two packets of the file with each of the 		 * record header formats.  That currently means it seeks 		 * backwards and retries the reads, which doesn't work 		 * on pipes.  We want to be able to read from a pipe, so 		 * that strategy won't work; we'd have to buffer some 		 * data ourselves and read from that buffer in order to 		 * make that work. 		 */
name|p
operator|->
name|sf
operator|.
name|hdrsize
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|pcap_sf_patched_pkthdr
argument_list|)
expr_stmt|;
block|}
else|else
name|p
operator|->
name|sf
operator|.
name|hdrsize
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|pcap_sf_pkthdr
argument_list|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|.
name|version_major
operator|<
name|PCAP_VERSION_MAJOR
condition|)
block|{
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"archaic file format"
argument_list|)
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
name|p
operator|->
name|tzoff
operator|=
name|hdr
operator|.
name|thiszone
expr_stmt|;
name|p
operator|->
name|snapshot
operator|=
name|hdr
operator|.
name|snaplen
expr_stmt|;
name|p
operator|->
name|linktype
operator|=
name|linktype_to_dlt
argument_list|(
name|LT_LINKTYPE
argument_list|(
name|hdr
operator|.
name|linktype
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|linktype_ext
operator|=
name|LT_LINKTYPE_EXT
argument_list|(
name|hdr
operator|.
name|linktype
argument_list|)
expr_stmt|;
if|if
condition|(
name|magic
operator|==
name|KUZNETZOV_TCPDUMP_MAGIC
operator|&&
name|p
operator|->
name|linktype
operator|==
name|DLT_EN10MB
condition|)
block|{
comment|/* 		 * This capture might have been done in raw mode or cooked 		 * mode. 		 * 		 * If it was done in cooked mode, p->snapshot was passed 		 * to recvfrom() as the buffer size, meaning that the 		 * most packet data that would be copied would be 		 * p->snapshot.  However, a faked Ethernet header would 		 * then have been added to it, so the most data that would 		 * be in a packet in the file would be p->snapshot + 14. 		 * 		 * We can't easily tell whether the capture was done in 		 * raw mode or cooked mode, so we'll assume it was 		 * cooked mode, and add 14 to the snapshot length.  That 		 * means that, for a raw capture, the snapshot length will 		 * be misleading if you use it to figure out why a capture 		 * doesn't have all the packet data, but there's not much 		 * we can do to avoid that. 		 */
name|p
operator|->
name|snapshot
operator|+=
literal|14
expr_stmt|;
block|}
name|p
operator|->
name|sf
operator|.
name|rfile
operator|=
name|fp
expr_stmt|;
ifndef|#
directive|ifndef
name|WIN32
name|p
operator|->
name|bufsize
operator|=
name|hdr
operator|.
name|snaplen
expr_stmt|;
else|#
directive|else
comment|/* Allocate the space for pcap_pkthdr as well. It will be used by pcap_read_ex */
name|p
operator|->
name|bufsize
operator|=
name|hdr
operator|.
name|snaplen
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|pcap_pkthdr
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Align link header as required for proper data alignment */
comment|/* XXX should handle all types */
switch|switch
condition|(
name|p
operator|->
name|linktype
condition|)
block|{
case|case
name|DLT_EN10MB
case|:
name|linklen
operator|=
literal|14
expr_stmt|;
break|break;
case|case
name|DLT_FDDI
case|:
name|linklen
operator|=
literal|13
operator|+
literal|8
expr_stmt|;
comment|/* fddi_header + llc */
break|break;
case|case
name|DLT_NULL
case|:
default|default:
name|linklen
operator|=
literal|0
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|p
operator|->
name|bufsize
operator|<
literal|0
condition|)
name|p
operator|->
name|bufsize
operator|=
name|BPF_MAXBUFSIZE
expr_stmt|;
name|p
operator|->
name|sf
operator|.
name|base
operator|=
operator|(
name|u_char
operator|*
operator|)
name|malloc
argument_list|(
name|p
operator|->
name|bufsize
operator|+
name|BPF_ALIGNMENT
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|sf
operator|.
name|base
operator|==
name|NULL
condition|)
block|{
name|strlcpy
argument_list|(
name|errbuf
argument_list|,
literal|"out of swap"
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|)
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
name|p
operator|->
name|buffer
operator|=
name|p
operator|->
name|sf
operator|.
name|base
operator|+
name|BPF_ALIGNMENT
operator|-
operator|(
name|linklen
operator|%
name|BPF_ALIGNMENT
operator|)
expr_stmt|;
name|p
operator|->
name|sf
operator|.
name|version_major
operator|=
name|hdr
operator|.
name|version_major
expr_stmt|;
name|p
operator|->
name|sf
operator|.
name|version_minor
operator|=
name|hdr
operator|.
name|version_minor
expr_stmt|;
ifdef|#
directive|ifdef
name|PCAP_FDDIPAD
comment|/* Padding only needed for live capture fcode */
name|p
operator|->
name|fddipad
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * We interchanged the caplen and len fields at version 2.3, 	 * in order to match the bpf header layout.  But unfortunately 	 * some files were written with version 2.3 in their headers 	 * but without the interchanged fields. 	 * 	 * In addition, DG/UX tcpdump writes out files with a version 	 * number of 543.0, and with the caplen and len fields in the 	 * pre-2.3 order. 	 */
switch|switch
condition|(
name|hdr
operator|.
name|version_major
condition|)
block|{
case|case
literal|2
case|:
if|if
condition|(
name|hdr
operator|.
name|version_minor
operator|<
literal|3
condition|)
name|p
operator|->
name|sf
operator|.
name|lengths_swapped
operator|=
name|SWAPPED
expr_stmt|;
elseif|else
if|if
condition|(
name|hdr
operator|.
name|version_minor
operator|==
literal|3
condition|)
name|p
operator|->
name|sf
operator|.
name|lengths_swapped
operator|=
name|MAYBE_SWAPPED
expr_stmt|;
else|else
name|p
operator|->
name|sf
operator|.
name|lengths_swapped
operator|=
name|NOT_SWAPPED
expr_stmt|;
break|break;
case|case
literal|543
case|:
name|p
operator|->
name|sf
operator|.
name|lengths_swapped
operator|=
name|SWAPPED
expr_stmt|;
break|break;
default|default:
name|p
operator|->
name|sf
operator|.
name|lengths_swapped
operator|=
name|NOT_SWAPPED
expr_stmt|;
break|break;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
comment|/* 	 * You can do "select()" and "poll()" on plain files on most 	 * platforms, and should be able to do so on pipes. 	 * 	 * You can't do "select()" on anything other than sockets in 	 * Windows, so, on Win32 systems, we don't have "selectable_fd". 	 */
name|p
operator|->
name|selectable_fd
operator|=
name|fileno
argument_list|(
name|fp
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|p
operator|->
name|read_op
operator|=
name|pcap_offline_read
expr_stmt|;
name|p
operator|->
name|inject_op
operator|=
name|sf_inject
expr_stmt|;
name|p
operator|->
name|setfilter_op
operator|=
name|install_bpf_program
expr_stmt|;
name|p
operator|->
name|setdirection_op
operator|=
name|sf_setdirection
expr_stmt|;
name|p
operator|->
name|set_datalink_op
operator|=
name|NULL
expr_stmt|;
comment|/* we don't support munging link-layer headers */
name|p
operator|->
name|getnonblock_op
operator|=
name|sf_getnonblock
expr_stmt|;
name|p
operator|->
name|setnonblock_op
operator|=
name|sf_setnonblock
expr_stmt|;
name|p
operator|->
name|stats_op
operator|=
name|sf_stats
expr_stmt|;
ifdef|#
directive|ifdef
name|WIN32
name|p
operator|->
name|setbuff_op
operator|=
name|sf_setbuff
expr_stmt|;
name|p
operator|->
name|setmode_op
operator|=
name|sf_setmode
expr_stmt|;
name|p
operator|->
name|setmintocopy_op
operator|=
name|sf_setmintocopy
expr_stmt|;
endif|#
directive|endif
name|p
operator|->
name|cleanup_op
operator|=
name|sf_cleanup
expr_stmt|;
name|p
operator|->
name|activated
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
name|bad
label|:
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Read sf_readfile and return the next packet.  Return the header in hdr  * and the contents in buf.  Return 0 on success, SFERR_EOF if there were  * no more packets, and SFERR_TRUNC if a partial packet was encountered.  */
end_comment

begin_function
specifier|static
name|int
name|sf_next_packet
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|struct
name|pcap_pkthdr
modifier|*
name|hdr
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|u_int
name|buflen
parameter_list|)
block|{
name|struct
name|pcap_sf_patched_pkthdr
name|sf_hdr
decl_stmt|;
name|FILE
modifier|*
name|fp
init|=
name|p
operator|->
name|sf
operator|.
name|rfile
decl_stmt|;
name|size_t
name|amt_read
decl_stmt|;
name|bpf_u_int32
name|t
decl_stmt|;
comment|/* 	 * Read the packet header; the structure we use as a buffer 	 * is the longer structure for files generated by the patched 	 * libpcap, but if the file has the magic number for an 	 * unpatched libpcap we only read as many bytes as the regular 	 * header has. 	 */
name|amt_read
operator|=
name|fread
argument_list|(
operator|&
name|sf_hdr
argument_list|,
literal|1
argument_list|,
name|p
operator|->
name|sf
operator|.
name|hdrsize
argument_list|,
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|amt_read
operator|!=
name|p
operator|->
name|sf
operator|.
name|hdrsize
condition|)
block|{
if|if
condition|(
name|ferror
argument_list|(
name|fp
argument_list|)
condition|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"error reading dump file: %s"
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|amt_read
operator|!=
literal|0
condition|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"truncated dump file; tried to read %lu header bytes, only got %lu"
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|p
operator|->
name|sf
operator|.
name|hdrsize
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|amt_read
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* EOF */
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
if|if
condition|(
name|p
operator|->
name|sf
operator|.
name|swapped
condition|)
block|{
comment|/* these were written in opposite byte order */
name|hdr
operator|->
name|caplen
operator|=
name|SWAPLONG
argument_list|(
name|sf_hdr
operator|.
name|caplen
argument_list|)
expr_stmt|;
name|hdr
operator|->
name|len
operator|=
name|SWAPLONG
argument_list|(
name|sf_hdr
operator|.
name|len
argument_list|)
expr_stmt|;
name|hdr
operator|->
name|ts
operator|.
name|tv_sec
operator|=
name|SWAPLONG
argument_list|(
name|sf_hdr
operator|.
name|ts
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
name|hdr
operator|->
name|ts
operator|.
name|tv_usec
operator|=
name|SWAPLONG
argument_list|(
name|sf_hdr
operator|.
name|ts
operator|.
name|tv_usec
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|hdr
operator|->
name|caplen
operator|=
name|sf_hdr
operator|.
name|caplen
expr_stmt|;
name|hdr
operator|->
name|len
operator|=
name|sf_hdr
operator|.
name|len
expr_stmt|;
name|hdr
operator|->
name|ts
operator|.
name|tv_sec
operator|=
name|sf_hdr
operator|.
name|ts
operator|.
name|tv_sec
expr_stmt|;
name|hdr
operator|->
name|ts
operator|.
name|tv_usec
operator|=
name|sf_hdr
operator|.
name|ts
operator|.
name|tv_usec
expr_stmt|;
block|}
comment|/* Swap the caplen and len fields, if necessary. */
switch|switch
condition|(
name|p
operator|->
name|sf
operator|.
name|lengths_swapped
condition|)
block|{
case|case
name|NOT_SWAPPED
case|:
break|break;
case|case
name|MAYBE_SWAPPED
case|:
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<=
name|hdr
operator|->
name|len
condition|)
block|{
comment|/* 			 * The captured length is<= the actual length, 			 * so presumably they weren't swapped. 			 */
break|break;
block|}
comment|/* FALLTHROUGH */
case|case
name|SWAPPED
case|:
name|t
operator|=
name|hdr
operator|->
name|caplen
expr_stmt|;
name|hdr
operator|->
name|caplen
operator|=
name|hdr
operator|->
name|len
expr_stmt|;
name|hdr
operator|->
name|len
operator|=
name|t
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|>
name|buflen
condition|)
block|{
comment|/* 		 * This can happen due to Solaris 2.3 systems tripping 		 * over the BUFMOD problem and not setting the snapshot 		 * correctly in the savefile header.  If the caplen isn't 		 * grossly wrong, try to salvage. 		 */
specifier|static
name|u_char
modifier|*
name|tp
init|=
name|NULL
decl_stmt|;
specifier|static
name|size_t
name|tsize
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|>
literal|65535
condition|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"bogus savefile header"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|tsize
operator|<
name|hdr
operator|->
name|caplen
condition|)
block|{
name|tsize
operator|=
operator|(
operator|(
name|hdr
operator|->
name|caplen
operator|+
literal|1023
operator|)
operator|/
literal|1024
operator|)
operator|*
literal|1024
expr_stmt|;
if|if
condition|(
name|tp
operator|!=
name|NULL
condition|)
name|free
argument_list|(
operator|(
name|u_char
operator|*
operator|)
name|tp
argument_list|)
expr_stmt|;
name|tp
operator|=
operator|(
name|u_char
operator|*
operator|)
name|malloc
argument_list|(
name|tsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|tp
operator|==
name|NULL
condition|)
block|{
name|tsize
operator|=
literal|0
expr_stmt|;
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"BUFMOD hack malloc"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
name|amt_read
operator|=
name|fread
argument_list|(
operator|(
name|char
operator|*
operator|)
name|tp
argument_list|,
literal|1
argument_list|,
name|hdr
operator|->
name|caplen
argument_list|,
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|amt_read
operator|!=
name|hdr
operator|->
name|caplen
condition|)
block|{
if|if
condition|(
name|ferror
argument_list|(
name|fp
argument_list|)
condition|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"error reading dump file: %s"
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"truncated dump file; tried to read %u captured bytes, only got %lu"
argument_list|,
name|hdr
operator|->
name|caplen
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|amt_read
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* 		 * We can only keep up to buflen bytes.  Since caplen> buflen 		 * is exactly how we got here, we know we can only keep the 		 * first buflen bytes and must drop the remainder.  Adjust 		 * caplen accordingly, so we don't get confused later as 		 * to how many bytes we have to play with. 		 */
name|hdr
operator|->
name|caplen
operator|=
name|buflen
expr_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|buf
argument_list|,
operator|(
name|char
operator|*
operator|)
name|tp
argument_list|,
name|buflen
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* read the packet itself */
name|amt_read
operator|=
name|fread
argument_list|(
operator|(
name|char
operator|*
operator|)
name|buf
argument_list|,
literal|1
argument_list|,
name|hdr
operator|->
name|caplen
argument_list|,
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|amt_read
operator|!=
name|hdr
operator|->
name|caplen
condition|)
block|{
if|if
condition|(
name|ferror
argument_list|(
name|fp
argument_list|)
condition|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"error reading dump file: %s"
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"truncated dump file; tried to read %u captured bytes, only got %lu"
argument_list|,
name|hdr
operator|->
name|caplen
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|amt_read
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
comment|/* 	 * The DLT_USB_LINUX header is in host byte order when capturing 	 * (it's supplied directly from a memory-mapped buffer shared 	 * by the kernel). 	 * 	 * When reading a DLT_USB_LINUX capture file, we need to convert 	 * it from the capturing host's byte order to the reading host's 	 * byte order. 	 */
if|if
condition|(
name|p
operator|->
name|sf
operator|.
name|swapped
operator|&&
name|p
operator|->
name|linktype
operator|==
name|DLT_USB_LINUX
condition|)
block|{
name|pcap_usb_header
modifier|*
name|uhdr
init|=
operator|(
name|pcap_usb_header
operator|*
operator|)
name|buf
decl_stmt|;
comment|/* 		 * The URB id is a totally opaque value; do we really need to  		 * converte it to the reading host's byte order??? 		 */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
literal|8
condition|)
return|return
literal|0
return|;
name|uhdr
operator|->
name|id
operator|=
name|SWAPLL
argument_list|(
name|uhdr
operator|->
name|id
argument_list|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
literal|14
condition|)
return|return
literal|0
return|;
name|uhdr
operator|->
name|bus_id
operator|=
name|SWAPSHORT
argument_list|(
name|uhdr
operator|->
name|bus_id
argument_list|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
literal|24
condition|)
return|return
literal|0
return|;
name|uhdr
operator|->
name|ts_sec
operator|=
name|SWAPLL
argument_list|(
name|uhdr
operator|->
name|ts_sec
argument_list|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
literal|28
condition|)
return|return
literal|0
return|;
name|uhdr
operator|->
name|ts_usec
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|ts_usec
argument_list|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
literal|32
condition|)
return|return
literal|0
return|;
name|uhdr
operator|->
name|status
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
literal|36
condition|)
return|return
literal|0
return|;
name|uhdr
operator|->
name|urb_len
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|urb_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
literal|40
condition|)
return|return
literal|0
return|;
name|uhdr
operator|->
name|data_len
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|data_len
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Print out packets stored in the file initialized by sf_read_init().  * If cnt> 0, return after 'cnt' packets, otherwise continue until eof.  */
end_comment

begin_function
name|int
name|pcap_offline_read
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|int
name|cnt
parameter_list|,
name|pcap_handler
name|callback
parameter_list|,
name|u_char
modifier|*
name|user
parameter_list|)
block|{
name|struct
name|bpf_insn
modifier|*
name|fcode
decl_stmt|;
name|int
name|status
init|=
literal|0
decl_stmt|;
name|int
name|n
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|status
operator|==
literal|0
condition|)
block|{
name|struct
name|pcap_pkthdr
name|h
decl_stmt|;
comment|/* 		 * Has "pcap_breakloop()" been called? 		 * If so, return immediately - if we haven't read any 		 * packets, clear the flag and return -2 to indicate 		 * that we were told to break out of the loop, otherwise 		 * leave the flag set, so that the *next* call will break 		 * out of the loop without having read any packets, and 		 * return the number of packets we've processed so far. 		 */
if|if
condition|(
name|p
operator|->
name|break_loop
condition|)
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
block|{
name|p
operator|->
name|break_loop
operator|=
literal|0
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
else|else
return|return
operator|(
name|n
operator|)
return|;
block|}
name|status
operator|=
name|sf_next_packet
argument_list|(
name|p
argument_list|,
operator|&
name|h
argument_list|,
name|p
operator|->
name|buffer
argument_list|,
name|p
operator|->
name|bufsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
block|{
if|if
condition|(
name|status
operator|==
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|status
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|fcode
operator|=
name|p
operator|->
name|fcode
operator|.
name|bf_insns
operator|)
operator|==
name|NULL
operator|||
name|bpf_filter
argument_list|(
name|fcode
argument_list|,
name|p
operator|->
name|buffer
argument_list|,
name|h
operator|.
name|len
argument_list|,
name|h
operator|.
name|caplen
argument_list|)
condition|)
block|{
call|(
modifier|*
name|callback
call|)
argument_list|(
name|user
argument_list|,
operator|&
name|h
argument_list|,
name|p
operator|->
name|buffer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|n
operator|>=
name|cnt
operator|&&
name|cnt
operator|>
literal|0
condition|)
break|break;
block|}
block|}
comment|/*XXX this breaks semantics tcpslice expects */
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Output a packet to the initialized dump file.  */
end_comment

begin_function
name|void
name|pcap_dump
parameter_list|(
name|u_char
modifier|*
name|user
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|sp
parameter_list|)
block|{
specifier|register
name|FILE
modifier|*
name|f
decl_stmt|;
name|struct
name|pcap_sf_pkthdr
name|sf_hdr
decl_stmt|;
name|f
operator|=
operator|(
name|FILE
operator|*
operator|)
name|user
expr_stmt|;
name|sf_hdr
operator|.
name|ts
operator|.
name|tv_sec
operator|=
name|h
operator|->
name|ts
operator|.
name|tv_sec
expr_stmt|;
name|sf_hdr
operator|.
name|ts
operator|.
name|tv_usec
operator|=
name|h
operator|->
name|ts
operator|.
name|tv_usec
expr_stmt|;
name|sf_hdr
operator|.
name|caplen
operator|=
name|h
operator|->
name|caplen
expr_stmt|;
name|sf_hdr
operator|.
name|len
operator|=
name|h
operator|->
name|len
expr_stmt|;
comment|/* XXX we should check the return status */
operator|(
name|void
operator|)
name|fwrite
argument_list|(
operator|&
name|sf_hdr
argument_list|,
sizeof|sizeof
argument_list|(
name|sf_hdr
argument_list|)
argument_list|,
literal|1
argument_list|,
name|f
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fwrite
argument_list|(
name|sp
argument_list|,
name|h
operator|->
name|caplen
argument_list|,
literal|1
argument_list|,
name|f
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|pcap_dumper_t
modifier|*
name|pcap_setup_dump
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|int
name|linktype
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
comment|/* 	 * If we're writing to the standard output, put it in binary 	 * mode, as savefiles are binary files. 	 * 	 * Otherwise, we turn off buffering. 	 * XXX - why?  And why not on the standard output? 	 */
if|if
condition|(
name|f
operator|==
name|stdout
condition|)
name|SET_BINMODE
argument_list|(
name|f
argument_list|)
expr_stmt|;
else|else
name|setbuf
argument_list|(
name|f
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|sf_write_header
argument_list|(
name|f
argument_list|,
name|linktype
argument_list|,
name|p
operator|->
name|tzoff
argument_list|,
name|p
operator|->
name|snapshot
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"Can't write to %s: %s"
argument_list|,
name|fname
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
operator|!=
name|stdout
condition|)
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
return|return
operator|(
operator|(
name|pcap_dumper_t
operator|*
operator|)
name|f
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Initialize so that sf_write() will output to the file named 'fname'.  */
end_comment

begin_function
name|pcap_dumper_t
modifier|*
name|pcap_dump_open
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
block|{
name|FILE
modifier|*
name|f
decl_stmt|;
name|int
name|linktype
decl_stmt|;
name|linktype
operator|=
name|dlt_to_linktype
argument_list|(
name|p
operator|->
name|linktype
argument_list|)
expr_stmt|;
if|if
condition|(
name|linktype
operator|==
operator|-
literal|1
condition|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"%s: link-layer type %d isn't supported in savefiles"
argument_list|,
name|fname
argument_list|,
name|linktype
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|linktype
operator||=
name|p
operator|->
name|linktype_ext
expr_stmt|;
if|if
condition|(
name|fname
index|[
literal|0
index|]
operator|==
literal|'-'
operator|&&
name|fname
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
block|{
name|f
operator|=
name|stdout
expr_stmt|;
name|fname
operator|=
literal|"standard output"
expr_stmt|;
block|}
else|else
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
name|f
operator|=
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
else|#
directive|else
name|f
operator|=
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"wb"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|f
operator|==
name|NULL
condition|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"%s: %s"
argument_list|,
name|fname
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
block|}
return|return
operator|(
name|pcap_setup_dump
argument_list|(
name|p
argument_list|,
name|linktype
argument_list|,
name|f
argument_list|,
name|fname
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Initialize so that sf_write() will output to the given stream.  */
end_comment

begin_function
name|pcap_dumper_t
modifier|*
name|pcap_dump_fopen
parameter_list|(
name|pcap_t
modifier|*
name|p
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
block|{
name|int
name|linktype
decl_stmt|;
name|linktype
operator|=
name|dlt_to_linktype
argument_list|(
name|p
operator|->
name|linktype
argument_list|)
expr_stmt|;
if|if
condition|(
name|linktype
operator|==
operator|-
literal|1
condition|)
block|{
name|snprintf
argument_list|(
name|p
operator|->
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"stream: link-layer type %d isn't supported in savefiles"
argument_list|,
name|linktype
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|linktype
operator||=
name|p
operator|->
name|linktype_ext
expr_stmt|;
return|return
operator|(
name|pcap_setup_dump
argument_list|(
name|p
argument_list|,
name|linktype
argument_list|,
name|f
argument_list|,
literal|"stream"
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|FILE
modifier|*
name|pcap_dump_file
parameter_list|(
name|pcap_dumper_t
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
operator|(
name|FILE
operator|*
operator|)
name|p
operator|)
return|;
block|}
end_function

begin_function
name|long
name|pcap_dump_ftell
parameter_list|(
name|pcap_dumper_t
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|ftell
argument_list|(
operator|(
name|FILE
operator|*
operator|)
name|p
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|pcap_dump_flush
parameter_list|(
name|pcap_dumper_t
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|fflush
argument_list|(
operator|(
name|FILE
operator|*
operator|)
name|p
argument_list|)
operator|==
name|EOF
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|pcap_dump_close
parameter_list|(
name|pcap_dumper_t
modifier|*
name|p
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|notyet
if|if
condition|(
name|ferror
argument_list|(
operator|(
name|FILE
operator|*
operator|)
name|p
argument_list|)
condition|)
return|return
operator|-
name|an
operator|-
name|error
return|;
comment|/* XXX should check return from fclose() too */
endif|#
directive|endif
operator|(
name|void
operator|)
name|fclose
argument_list|(
operator|(
name|FILE
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

