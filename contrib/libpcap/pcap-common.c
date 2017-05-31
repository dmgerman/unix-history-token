begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * pcap-common.c - common code for pcap and pcap-ng files  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<pcap-stdinc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _WIN32 */
end_comment

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_elif
elif|#
directive|elif
name|HAVE_STDINT_H
end_elif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_BITYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/bitypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WIN32 */
end_comment

begin_include
include|#
directive|include
file|"pcap-int.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"pcap/sll.h"
end_include

begin_include
include|#
directive|include
file|"pcap/usb.h"
end_include

begin_include
include|#
directive|include
file|"pcap/nflog.h"
end_include

begin_include
include|#
directive|include
file|"pcap/can_socketcan.h"
end_include

begin_include
include|#
directive|include
file|"pcap-common.h"
end_include

begin_comment
comment|/*  * We don't write DLT_* values to capture files, because they're not the  * same on all platforms.  *  * Unfortunately, the various flavors of BSD have not always used the same  * numerical values for the same data types, and various patches to  * libpcap for non-BSD OSes have added their own DLT_* codes for link  * layer encapsulation types seen on those OSes, and those codes have had,  * in some cases, values that were also used, on other platforms, for other  * link layer encapsulation types.  *  * This means that capture files of a type whose numerical DLT_* code  * means different things on different BSDs, or with different versions  * of libpcap, can't always be read on systems other than those like  * the one running on the machine on which the capture was made.  *  * Instead, we define here a set of LINKTYPE_* codes, and map DLT_* codes  * to LINKTYPE_* codes when writing a savefile header, and map LINKTYPE_*  * codes to DLT_* codes when reading a savefile header.  *  * For those DLT_* codes that have, as far as we know, the same values on  * all platforms (DLT_NULL through DLT_FDDI), we define LINKTYPE_xxx as  * DLT_xxx; that way, captures of those types can still be read by  * versions of libpcap that map LINKTYPE_* values to DLT_* values, and  * captures of those types written by versions of libpcap that map DLT_  * values to LINKTYPE_ values can still be read by older versions  * of libpcap.  *  * The other LINKTYPE_* codes are given values starting at 100, in the  * hopes that no DLT_* code will be given one of those values.  *  * In order to ensure that a given LINKTYPE_* code's value will refer to  * the same encapsulation type on all platforms, you should not allocate  * a new LINKTYPE_* value without consulting  * "tcpdump-workers@lists.tcpdump.org".  The tcpdump developers will  * allocate a value for you, and will not subsequently allocate it to  * anybody else; that value will be added to the "pcap.h" in the  * tcpdump.org Git repository, so that a future libpcap release will  * include it.  *  * You should, if possible, also contribute patches to libpcap and tcpdump  * to handle the new encapsulation type, so that they can also be checked  * into the tcpdump.org Git repository and so that they will appear in  * future libpcap and tcpdump releases.  *  * Do *NOT* assume that any values after the largest value in this file  * are available; you might not have the most up-to-date version of this  * file, and new values after that one might have been assigned.  Also,  * do *NOT* use any values below 100 - those might already have been  * taken by one (or more!) organizations.  *  * Any platform that defines additional DLT_* codes should:  *  *	request a LINKTYPE_* code and value from tcpdump.org,  *	as per the above;  *  *	add, in their version of libpcap, an entry to map  *	those DLT_* codes to the corresponding LINKTYPE_*  *	code;  *  *	redefine, in their "net/bpf.h", any DLT_* values  *	that collide with the values used by their additional  *	DLT_* codes, to remove those collisions (but without  *	making them collide with any of the LINKTYPE_*  *	values equal to 50 or above; they should also avoid  *	defining DLT_* values that collide with those  *	LINKTYPE_* values, either).  */
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
name|LINKTYPE_IEEE802_5
value|DLT_IEEE802
end_define

begin_comment
comment|/* DLT_IEEE802 is used for 802.5 Token Ring */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ARCNET_BSD
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

begin_comment
comment|/*  * These correspond to DLT_s that have different values on different  * platforms; we map between these values in capture files and  * the DLT_ values as returned by pcap_datalink() and passed to  * pcap_open_dead().  */
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

begin_comment
comment|/*  * Values starting with 104 are used for newly-assigned link-layer  * header type values; for those link-layer header types, the DLT_  * value returned by pcap_datalink() and passed to pcap_open_dead(),  * and the LINKTYPE_ value that appears in capture files, are the  * same.  *  * LINKTYPE_MATCHING_MIN is the lowest such value; LINKTYPE_MATCHING_MAX  * is the highest such value.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_MATCHING_MIN
value|104
end_define

begin_comment
comment|/* lowest value in the "matching" range */
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
name|LINKTYPE_IEEE802_11_PRISM
value|119
end_define

begin_comment
comment|/* 802.11 plus Prism II monitor mode radio metadata header */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_11_AIRONET
value|120
end_define

begin_comment
comment|/* 802.11 plus FreeBSD Aironet driver radio metadata header */
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
name|LINKTYPE_IEEE802_11_RADIOTAP
value|127
end_define

begin_comment
comment|/* 802.11 plus radiotap radio metadata header */
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
comment|/*  * For future use with 802.11 captures - defined by AbsoluteValue  * Systems to store a number of bits of link-layer information  * including radio information:  *  *	http://www.shaftnet.org/~pizza/software/capturefrm.txt  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_11_AVS
value|163
end_define

begin_comment
comment|/* 802.11 plus AVS radio metadata header */
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
comment|/*  * BACnet MS/TP frames.  */
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
comment|/* GPF-F (ITU-T G.7041/Y.1303) */
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
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  * The Link Types are used for prepending meta-information  * like interface index, interface name  * before standard Ethernet, PPP, Frelay& C-HDLC Frames  */
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
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  * The DLT_ is used for internal communication with a  * voice Adapter Card (PIC)  */
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
comment|/*  * This used to be "USB packets, beginning with a USB setup header;  * requested by Paolo Abeni<paolo.abeni@email.it>."  *  * However, that header didn't work all that well - it left out some  * useful information - and was abandoned in favor of the DLT_USB_LINUX  * header.  *  * This is now used by FreeBSD for its BPF taps for USB; that has its  * own headers.  So it is written, so it is done.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_USB_FREEBSD
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
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  * The DLT_ is used for internal communication with a  * integrated service module (ISM).  */
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
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  * The DLT_ is used for capturing data on a secure tunnel interface.  */
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

begin_comment
comment|/*  * David Gibson<david@gibson.dropbear.id.au> requested this for  * captures from the Linux kernel /dev/input/eventN devices. This  * is used to communicate keystrokes and mouse movements from the  * Linux kernel to display systems, such as Xorg.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_LINUX_EVDEV
value|216
end_define

begin_comment
comment|/*  * GSM Um and Abis interfaces, preceded by a "gsmtap" header.  *  * Requested by Harald Welte<laforge@gnumonks.org>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_GSMTAP_UM
value|217
end_define

begin_define
define|#
directive|define
name|LINKTYPE_GSMTAP_ABIS
value|218
end_define

begin_comment
comment|/*  * MPLS, with an MPLS label as the link-layer header.  * Requested by Michele Marchetto<michele@openbsd.org> on behalf  * of OpenBSD.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_MPLS
value|219
end_define

begin_comment
comment|/*  * USB packets, beginning with a Linux USB header, with the USB header  * padded to 64 bytes; required for memory-mapped access.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_USB_LINUX_MMAPPED
value|220
end_define

begin_comment
comment|/*  * DECT packets, with a pseudo-header; requested by  * Matthias Wenzel<tcpdump@mazzoo.de>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_DECT
value|221
end_define

begin_comment
comment|/*  * From: "Lidwa, Eric (GSFC-582.0)[SGT INC]"<eric.lidwa-1@nasa.gov>  * Date: Mon, 11 May 2009 11:18:30 -0500  *  * DLT_AOS. We need it for AOS Space Data Link Protocol.  *   I have already written dissectors for but need an OK from  *   legal before I can submit a patch.  *  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_AOS
value|222
end_define

begin_comment
comment|/*  * Wireless HART (Highway Addressable Remote Transducer)  * From the HART Communication Foundation  * IES/PAS 62591  *  * Requested by Sam Roberts<vieuxtech@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_WIHART
value|223
end_define

begin_comment
comment|/*  * Fibre Channel FC-2 frames, beginning with a Frame_Header.  * Requested by Kahou Lei<kahou82@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_FC_2
value|224
end_define

begin_comment
comment|/*  * Fibre Channel FC-2 frames, beginning with an encoding of the  * SOF, and ending with an encoding of the EOF.  *  * The encodings represent the frame delimiters as 4-byte sequences  * representing the corresponding ordered sets, with K28.5  * represented as 0xBC, and the D symbols as the corresponding  * byte values; for example, SOFi2, which is K28.5 - D21.5 - D1.2 - D21.2,  * is represented as 0xBC 0xB5 0x55 0x55.  *  * Requested by Kahou Lei<kahou82@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_FC_2_WITH_FRAME_DELIMS
value|225
end_define

begin_comment
comment|/*  * Solaris ipnet pseudo-header; requested by Darren Reed<Darren.Reed@Sun.COM>.  *  * The pseudo-header starts with a one-byte version number; for version 2,  * the pseudo-header is:  *  * struct dl_ipnetinfo {  *     u_int8_t   dli_version;  *     u_int8_t   dli_family;  *     u_int16_t  dli_htype;  *     u_int32_t  dli_pktlen;  *     u_int32_t  dli_ifindex;  *     u_int32_t  dli_grifindex;  *     u_int32_t  dli_zsrc;  *     u_int32_t  dli_zdst;  * };  *  * dli_version is 2 for the current version of the pseudo-header.  *  * dli_family is a Solaris address family value, so it's 2 for IPv4  * and 26 for IPv6.  *  * dli_htype is a "hook type" - 0 for incoming packets, 1 for outgoing  * packets, and 2 for packets arriving from another zone on the same  * machine.  *  * dli_pktlen is the length of the packet data following the pseudo-header  * (so the captured length minus dli_pktlen is the length of the  * pseudo-header, assuming the entire pseudo-header was captured).  *  * dli_ifindex is the interface index of the interface on which the  * packet arrived.  *  * dli_grifindex is the group interface index number (for IPMP interfaces).  *  * dli_zsrc is the zone identifier for the source of the packet.  *  * dli_zdst is the zone identifier for the destination of the packet.  *  * A zone number of 0 is the global zone; a zone number of 0xffffffff  * means that the packet arrived from another host on the network, not  * from another zone on the same machine.  *  * An IPv4 or IPv6 datagram follows the pseudo-header; dli_family indicates  * which of those it is.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IPNET
value|226
end_define

begin_comment
comment|/*  * CAN (Controller Area Network) frames, with a pseudo-header as supplied  * by Linux SocketCAN, and with multi-byte numerical fields in that header  * in big-endian byte order.  *  * See Documentation/networking/can.txt in the Linux source.  *  * Requested by Felix Obenhuber<felix@obenhuber.de>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_CAN_SOCKETCAN
value|227
end_define

begin_comment
comment|/*  * Raw IPv4/IPv6; different from DLT_RAW in that the DLT_ value specifies  * whether it's v4 or v6.  Requested by Darren Reed<Darren.Reed@Sun.COM>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IPV4
value|228
end_define

begin_define
define|#
directive|define
name|LINKTYPE_IPV6
value|229
end_define

begin_comment
comment|/*  * IEEE 802.15.4, exactly as it appears in the spec (no padding, no  * nothing), and with no FCS at the end of the frame; requested by  * Jon Smirl<jonsmirl@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IEEE802_15_4_NOFCS
value|230
end_define

begin_comment
comment|/*  * Raw D-Bus:  *  *	http://www.freedesktop.org/wiki/Software/dbus  *  * messages:  *  *	http://dbus.freedesktop.org/doc/dbus-specification.html#message-protocol-messages  *  * starting with the endianness flag, followed by the message type, etc.,  * but without the authentication handshake before the message sequence:  *  *	http://dbus.freedesktop.org/doc/dbus-specification.html#auth-protocol  *  * Requested by Martin Vidner<martin@vidner.net>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_DBUS
value|231
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_VS
value|232
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_SRX_E2E
value|233
end_define

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_FIBRECHANNEL
value|234
end_define

begin_comment
comment|/*  * DVB-CI (DVB Common Interface for communication between a PC Card  * module and a DVB receiver).  See  *  *	http://www.kaiser.cx/pcap-dvbci.html  *  * for the specification.  *  * Requested by Martin Kaiser<martin@kaiser.cx>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_DVB_CI
value|235
end_define

begin_comment
comment|/*  * Variant of 3GPP TS 27.010 multiplexing protocol.  Requested  * by Hans-Christoph Schemmel<hans-christoph.schemmel@cinterion.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_MUX27010
value|236
end_define

begin_comment
comment|/*  * STANAG 5066 D_PDUs.  Requested by M. Baris Demiray  *<barisdemiray@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_STANAG_5066_D_PDU
value|237
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_JUNIPER_ATM_CEMIC
value|238
end_define

begin_comment
comment|/*  * NetFilter LOG messages  * (payload of netlink NFNL_SUBSYS_ULOG/NFULNL_MSG_PACKET packets)  *  * Requested by Jakub Zawadzki<darkjames-ws@darkjames.pl>  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_NFLOG
value|239
end_define

begin_comment
comment|/*  * Hilscher Gesellschaft fuer Systemautomation mbH link-layer type  * for Ethernet packets with a 4-byte pseudo-header and always  * with the payload including the FCS, as supplied by their  * netANALYZER hardware and software.  *  * Requested by Holger P. Frommer<HPfrommer@hilscher.com>  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_NETANALYZER
value|240
end_define

begin_comment
comment|/*  * Hilscher Gesellschaft fuer Systemautomation mbH link-layer type  * for Ethernet packets with a 4-byte pseudo-header and FCS and  * 1 byte of SFD, as supplied by their netANALYZER hardware and  * software.  *  * Requested by Holger P. Frommer<HPfrommer@hilscher.com>  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_NETANALYZER_TRANSPARENT
value|241
end_define

begin_comment
comment|/*  * IP-over-InfiniBand, as specified by RFC 4391.  *  * Requested by Petr Sumbera<petr.sumbera@oracle.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IPOIB
value|242
end_define

begin_comment
comment|/*  * MPEG-2 transport stream (ISO 13818-1/ITU-T H.222.0).  *  * Requested by Guy Martin<gmsoft@tuxicoman.be>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_MPEG_2_TS
value|243
end_define

begin_comment
comment|/*  * ng4T GmbH's UMTS Iub/Iur-over-ATM and Iub/Iur-over-IP format as  * used by their ng40 protocol tester.  *  * Requested by Jens Grimmer<jens.grimmer@ng4t.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_NG40
value|244
end_define

begin_comment
comment|/*  * Pseudo-header giving adapter number and flags, followed by an NFC  * (Near-Field Communications) Logical Link Control Protocol (LLCP) PDU,  * as specified by NFC Forum Logical Link Control Protocol Technical  * Specification LLCP 1.1.  *  * Requested by Mike Wakerly<mikey@google.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_NFC_LLCP
value|245
end_define

begin_comment
comment|/*  * pfsync output; DLT_PFSYNC is 18, which collides with DLT_CIP in  * SuSE 6.3, on OpenBSD, NetBSD, DragonFly BSD, and Mac OS X, and  * is 121, which collides with DLT_HHDLC, in FreeBSD.  We pick a  * shiny new link-layer header type value that doesn't collide with  * anything, in the hopes that future pfsync savefiles, if any,  * won't require special hacks to distinguish from other savefiles.  *  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PFSYNC
value|246
end_define

begin_comment
comment|/*  * Raw InfiniBand packets, starting with the Local Routing Header.  *  * Requested by Oren Kladnitsky<orenk@mellanox.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_INFINIBAND
value|247
end_define

begin_comment
comment|/*  * SCTP, with no lower-level protocols (i.e., no IPv4 or IPv6).  *  * Requested by Michael Tuexen<Michael.Tuexen@lurchi.franken.de>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_SCTP
value|248
end_define

begin_comment
comment|/*  * USB packets, beginning with a USBPcap header.  *  * Requested by Tomasz Mon<desowin@gmail.com>  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_USBPCAP
value|249
end_define

begin_comment
comment|/*  * Schweitzer Engineering Laboratories "RTAC" product serial-line  * packets.  *  * Requested by Chris Bontje<chris_bontje@selinc.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_RTAC_SERIAL
value|250
end_define

begin_comment
comment|/*  * Bluetooth Low Energy air interface link-layer packets.  *  * Requested by Mike Kershaw<dragorn@kismetwireless.net>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_BLUETOOTH_LE_LL
value|251
end_define

begin_comment
comment|/*  * Link-layer header type for upper-protocol layer PDU saves from wireshark.  *  * the actual contents are determined by two TAGs stored with each  * packet:  *   EXP_PDU_TAG_LINKTYPE          the link type (LINKTYPE_ value) of the  *				   original packet.  *  *   EXP_PDU_TAG_PROTO_NAME        the name of the wireshark dissector  * 				   that can make sense of the data stored.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_WIRESHARK_UPPER_PDU
value|252
end_define

begin_comment
comment|/*  * Link-layer header type for the netlink protocol (nlmon devices).  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_NETLINK
value|253
end_define

begin_comment
comment|/*  * Bluetooth Linux Monitor headers for the BlueZ stack.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_BLUETOOTH_LINUX_MONITOR
value|254
end_define

begin_comment
comment|/*  * Bluetooth Basic Rate/Enhanced Data Rate baseband packets, as  * captured by Ubertooth.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_BLUETOOTH_BREDR_BB
value|255
end_define

begin_comment
comment|/*  * Bluetooth Low Energy link layer packets, as captured by Ubertooth.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_BLUETOOTH_LE_LL_WITH_PHDR
value|256
end_define

begin_comment
comment|/*  * PROFIBUS data link layer.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PROFIBUS_DL
value|257
end_define

begin_comment
comment|/*  * Apple's DLT_PKTAP headers.  *  * Sadly, the folks at Apple either had no clue that the DLT_USERn values  * are for internal use within an organization and partners only, and  * didn't know that the right way to get a link-layer header type is to  * ask tcpdump.org for one, or knew and didn't care, so they just  * used DLT_USER2, which causes problems for everything except for  * their version of tcpdump.  *  * So I'll just give them one; hopefully this will show up in a  * libpcap release in time for them to get this into 10.10 Big Sur  * or whatever Mavericks' successor is called.  LINKTYPE_PKTAP  * will be 258 *even on OS X*; that is *intentional*, so that  * PKTAP files look the same on *all* OSes (different OSes can have  * different numerical values for a given DLT_, but *MUST NOT* have  * different values for what goes in a file, as files can be moved  * between OSes!).  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_PKTAP
value|258
end_define

begin_comment
comment|/*  * Ethernet packets preceded by a header giving the last 6 octets  * of the preamble specified by 802.3-2012 Clause 65, section  * 65.1.3.2 "Transmit".  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_EPON
value|259
end_define

begin_comment
comment|/*  * IPMI trace packets, as specified by Table 3-20 "Trace Data Block Format"  * in the PICMG HPM.2 specification.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_IPMI_HPM_2
value|260
end_define

begin_comment
comment|/*  * per  Joshua Wright<jwright@hasborg.com>, formats for Zwave captures.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ZWAVE_R1_R2
value|261
end_define

begin_define
define|#
directive|define
name|LINKTYPE_ZWAVE_R3
value|262
end_define

begin_comment
comment|/*  * per Steve Karg<skarg@users.sourceforge.net>, formats for Wattstopper  * Digital Lighting Management room bus serial protocol captures.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_WATTSTOPPER_DLM
value|263
end_define

begin_comment
comment|/*  * ISO 14443 contactless smart card messages.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_ISO_14443
value|264
end_define

begin_comment
comment|/*  * Radio data system (RDS) groups.  IEC 62106.  * Per Jonathan Brucker<jonathan.brucke@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|LINKTYPE_RDS
value|265
end_define

begin_define
define|#
directive|define
name|LINKTYPE_MATCHING_MAX
value|265
end_define

begin_comment
comment|/* highest value in the "matching" range */
end_comment

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
name|LINKTYPE_IEEE802_5
block|}
block|,
block|{
name|DLT_ARCNET
block|,
name|LINKTYPE_ARCNET_BSD
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
block|{
name|DLT_SYMANTEC_FIREWALL
block|,
name|LINKTYPE_SYMANTEC_FIREWALL
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
comment|/* 	 * All LINKTYPE_ values between LINKTYPE_MATCHING_MIN 	 * and LINKTYPE_MATCHING_MAX are mapped to identical 	 * DLT_ values. 	 */
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

begin_function
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
comment|/* 	 * DLTs that, on some platforms, have values in the matching range 	 * but that *don't* have the same value as the corresponding 	 * LINKTYPE because, for some reason, not all OSes have the 	 * same value for that DLT (note that the DLT's value might be 	 * outside the matching range on some of those OSes). 	 */
if|if
condition|(
name|dlt
operator|==
name|DLT_PFSYNC
condition|)
return|return
operator|(
name|LINKTYPE_PFSYNC
operator|)
return|;
if|if
condition|(
name|dlt
operator|==
name|DLT_PKTAP
condition|)
return|return
operator|(
name|LINKTYPE_PKTAP
operator|)
return|;
comment|/* 	 * For all other values in the matching range, the DLT 	 * value is the same as the LINKTYPE value. 	 */
if|if
condition|(
name|dlt
operator|>=
name|DLT_MATCHING_MIN
operator|&&
name|dlt
operator|<=
name|DLT_MATCHING_MAX
condition|)
return|return
operator|(
name|dlt
operator|)
return|;
comment|/* 	 * Map the values outside that range. 	 */
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
comment|/* 	 * If we don't have a mapping for this DLT, return an 	 * error; that means that this is a value with no corresponding 	 * LINKTYPE, and we need to assign one. 	 */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
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
comment|/* 	 * LINKTYPEs in the matching range that *don't* 	 * have the same value as the corresponding DLTs 	 * because, for some reason, not all OSes have the 	 * same value for that DLT. 	 */
if|if
condition|(
name|linktype
operator|==
name|LINKTYPE_PFSYNC
condition|)
return|return
operator|(
name|DLT_PFSYNC
operator|)
return|;
if|if
condition|(
name|linktype
operator|==
name|LINKTYPE_PKTAP
condition|)
return|return
operator|(
name|DLT_PKTAP
operator|)
return|;
comment|/* 	 * For all other values in the matching range, the LINKTYPE 	 * value is the same as the DLT value. 	 */
if|if
condition|(
name|linktype
operator|>=
name|LINKTYPE_MATCHING_MIN
operator|&&
name|linktype
operator|<=
name|LINKTYPE_MATCHING_MAX
condition|)
return|return
operator|(
name|linktype
operator|)
return|;
comment|/* 	 * Map the values outside that range. 	 */
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
comment|/* 	 * If we don't have an entry for this LINKTYPE, return 	 * the link type value; it may be a DLT from an older 	 * version of libpcap. 	 */
return|return
name|linktype
return|;
block|}
end_function

begin_define
define|#
directive|define
name|EXTRACT_
end_define

begin_comment
comment|/*  * DLT_LINUX_SLL packets with a protocol type of LINUX_SLL_P_CAN or  * LINUX_SLL_P_CANFD have SocketCAN headers in front of the payload,  * with the CAN ID being in host byte order.  *  * When reading a DLT_LINUX_SLL capture file, we need to check for those  * packets and convert the CAN ID from the byte order of the host that  * wrote the file to this host's byte order.  */
end_comment

begin_function
specifier|static
name|void
name|swap_linux_sll_header
parameter_list|(
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|hdr
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|)
block|{
name|u_int
name|caplen
init|=
name|hdr
operator|->
name|caplen
decl_stmt|;
name|u_int
name|length
init|=
name|hdr
operator|->
name|len
decl_stmt|;
name|struct
name|sll_header
modifier|*
name|shdr
init|=
operator|(
expr|struct
name|sll_header
operator|*
operator|)
name|buf
decl_stmt|;
name|u_int16_t
name|protocol
decl_stmt|;
name|pcap_can_socketcan_hdr
modifier|*
name|chdr
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
operator|(
name|u_int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|sll_header
argument_list|)
operator|||
name|length
operator|<
operator|(
name|u_int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|sll_header
argument_list|)
condition|)
block|{
comment|/* Not enough data to have the protocol field */
return|return;
block|}
name|protocol
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|shdr
operator|->
name|sll_protocol
argument_list|)
expr_stmt|;
if|if
condition|(
name|protocol
operator|!=
name|LINUX_SLL_P_CAN
operator|&&
name|protocol
operator|!=
name|LINUX_SLL_P_CANFD
condition|)
return|return;
comment|/* 	 * SocketCAN packet; fix up the packet's header. 	 */
name|chdr
operator|=
operator|(
name|pcap_can_socketcan_hdr
operator|*
operator|)
operator|(
name|buf
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|sll_header
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|caplen
operator|<
operator|(
name|u_int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|sll_header
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|chdr
operator|->
name|can_id
argument_list|)
operator|||
name|length
operator|<
operator|(
name|u_int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|sll_header
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|chdr
operator|->
name|can_id
argument_list|)
condition|)
block|{
comment|/* Not enough data to have the CAN ID */
return|return;
block|}
name|chdr
operator|->
name|can_id
operator|=
name|SWAPLONG
argument_list|(
name|chdr
operator|->
name|can_id
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * The DLT_USB_LINUX and DLT_USB_LINUX_MMAPPED headers are in host  * byte order when capturing (it's supplied directly from a  * memory-mapped buffer shared by the kernel).  *  * When reading a DLT_USB_LINUX or DLT_USB_LINUX_MMAPPED capture file,  * we need to convert it from the byte order of the host that wrote  * the file to this host's byte order.  */
end_comment

begin_function
specifier|static
name|void
name|swap_linux_usb_header
parameter_list|(
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|hdr
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
name|header_len_64_bytes
parameter_list|)
block|{
name|pcap_usb_header_mmapped
modifier|*
name|uhdr
init|=
operator|(
name|pcap_usb_header_mmapped
operator|*
operator|)
name|buf
decl_stmt|;
name|bpf_u_int32
name|offset
init|=
literal|0
decl_stmt|;
comment|/* 	 * "offset" is the offset *past* the field we're swapping; 	 * we skip the field *before* checking to make sure 	 * the captured data length includes the entire field. 	 */
comment|/* 	 * The URB id is a totally opaque value; do we really need to 	 * convert it to the reading host's byte order??? 	 */
name|offset
operator|+=
literal|8
expr_stmt|;
comment|/* skip past id */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
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
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past various 1-byte fields */
name|offset
operator|+=
literal|2
expr_stmt|;
comment|/* skip past bus_id */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
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
name|offset
operator|+=
literal|2
expr_stmt|;
comment|/* skip past various 1-byte fields */
name|offset
operator|+=
literal|8
expr_stmt|;
comment|/* skip past ts_sec */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
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
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past ts_usec */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
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
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past status */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
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
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past urb_len */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
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
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past data_len */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
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
if|if
condition|(
name|uhdr
operator|->
name|transfer_type
operator|==
name|URB_ISOCHRONOUS
condition|)
block|{
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past s.iso.error_count */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
name|uhdr
operator|->
name|s
operator|.
name|iso
operator|.
name|error_count
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|s
operator|.
name|iso
operator|.
name|error_count
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past s.iso.numdesc */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
name|uhdr
operator|->
name|s
operator|.
name|iso
operator|.
name|numdesc
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|s
operator|.
name|iso
operator|.
name|numdesc
argument_list|)
expr_stmt|;
block|}
else|else
name|offset
operator|+=
literal|8
expr_stmt|;
comment|/* skip USB setup header */
comment|/* 	 * With the old header, there are no isochronous descriptors 	 * after the header. 	 * 	 * With the new header, the actual number of descriptors in 	 * the header is not s.iso.numdesc, it's ndesc - only the 	 * first N descriptors, for some value of N, are put into 	 * the header, and ndesc is set to the actual number copied. 	 * In addition, if s.iso.numdesc is negative, no descriptors 	 * are captured, and ndesc is set to 0. 	 */
if|if
condition|(
name|header_len_64_bytes
condition|)
block|{
comment|/* 		 * This is either the "version 1" header, with 		 * 16 bytes of additional fields at the end, or 		 * a "version 0" header from a memory-mapped 		 * capture, with 16 bytes of zeroed-out padding 		 * at the end.  Byte swap them as if this were 		 * a "version 1" header. 		 */
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past interval */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
name|uhdr
operator|->
name|interval
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|interval
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past start_frame */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
name|uhdr
operator|->
name|start_frame
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|start_frame
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past xfer_flags */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
name|uhdr
operator|->
name|xfer_flags
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|xfer_flags
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past ndesc */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
name|uhdr
operator|->
name|ndesc
operator|=
name|SWAPLONG
argument_list|(
name|uhdr
operator|->
name|ndesc
argument_list|)
expr_stmt|;
if|if
condition|(
name|uhdr
operator|->
name|transfer_type
operator|==
name|URB_ISOCHRONOUS
condition|)
block|{
comment|/* swap the values in struct linux_usb_isodesc */
name|usb_isodesc
modifier|*
name|pisodesc
decl_stmt|;
name|u_int32_t
name|i
decl_stmt|;
name|pisodesc
operator|=
operator|(
name|usb_isodesc
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
operator|(
name|buf
operator|+
name|offset
operator|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|uhdr
operator|->
name|ndesc
condition|;
name|i
operator|++
control|)
block|{
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past status */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
name|pisodesc
operator|->
name|status
operator|=
name|SWAPLONG
argument_list|(
name|pisodesc
operator|->
name|status
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past offset */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
name|pisodesc
operator|->
name|offset
operator|=
name|SWAPLONG
argument_list|(
name|pisodesc
operator|->
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past len */
if|if
condition|(
name|hdr
operator|->
name|caplen
operator|<
name|offset
condition|)
return|return;
name|pisodesc
operator|->
name|len
operator|=
name|SWAPLONG
argument_list|(
name|pisodesc
operator|->
name|len
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|4
expr_stmt|;
comment|/* skip past padding */
name|pisodesc
operator|++
expr_stmt|;
block|}
block|}
block|}
block|}
end_function

begin_comment
comment|/*  * The DLT_NFLOG "packets" have a mixture of big-endian and host-byte-order  * data.  They begin with a fixed-length header with big-endian fields,  * followed by a set of TLVs, where the type and length are in host  * byte order but the values are either big-endian or are a raw byte  * sequence that's the same regardless of the host's byte order.  *  * When reading a DLT_NFLOG capture file, we need to convert the type  * and length values from the byte order of the host that wrote the  * file to the byte order of this host.  */
end_comment

begin_function
specifier|static
name|void
name|swap_nflog_header
parameter_list|(
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|hdr
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|)
block|{
name|u_char
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|nflog_hdr_t
modifier|*
name|nfhdr
init|=
operator|(
name|nflog_hdr_t
operator|*
operator|)
name|buf
decl_stmt|;
name|nflog_tlv_t
modifier|*
name|tlv
decl_stmt|;
name|u_int
name|caplen
init|=
name|hdr
operator|->
name|caplen
decl_stmt|;
name|u_int
name|length
init|=
name|hdr
operator|->
name|len
decl_stmt|;
name|u_int16_t
name|size
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
operator|(
name|u_int
operator|)
sizeof|sizeof
argument_list|(
name|nflog_hdr_t
argument_list|)
operator|||
name|length
operator|<
operator|(
name|u_int
operator|)
sizeof|sizeof
argument_list|(
name|nflog_hdr_t
argument_list|)
condition|)
block|{
comment|/* Not enough data to have any TLVs. */
return|return;
block|}
if|if
condition|(
name|nfhdr
operator|->
name|nflog_version
operator|!=
literal|0
condition|)
block|{
comment|/* Unknown NFLOG version */
return|return;
block|}
name|length
operator|-=
sizeof|sizeof
argument_list|(
name|nflog_hdr_t
argument_list|)
expr_stmt|;
name|caplen
operator|-=
sizeof|sizeof
argument_list|(
name|nflog_hdr_t
argument_list|)
expr_stmt|;
name|p
operator|+=
sizeof|sizeof
argument_list|(
name|nflog_hdr_t
argument_list|)
expr_stmt|;
while|while
condition|(
name|caplen
operator|>=
sizeof|sizeof
argument_list|(
name|nflog_tlv_t
argument_list|)
condition|)
block|{
name|tlv
operator|=
operator|(
name|nflog_tlv_t
operator|*
operator|)
name|p
expr_stmt|;
comment|/* Swap the type and length. */
name|tlv
operator|->
name|tlv_type
operator|=
name|SWAPSHORT
argument_list|(
name|tlv
operator|->
name|tlv_type
argument_list|)
expr_stmt|;
name|tlv
operator|->
name|tlv_length
operator|=
name|SWAPSHORT
argument_list|(
name|tlv
operator|->
name|tlv_length
argument_list|)
expr_stmt|;
comment|/* Get the length of the TLV. */
name|size
operator|=
name|tlv
operator|->
name|tlv_length
expr_stmt|;
if|if
condition|(
name|size
operator|%
literal|4
operator|!=
literal|0
condition|)
name|size
operator|+=
literal|4
operator|-
name|size
operator|%
literal|4
expr_stmt|;
comment|/* Is the TLV's length less than the minimum? */
if|if
condition|(
name|size
operator|<
sizeof|sizeof
argument_list|(
name|nflog_tlv_t
argument_list|)
condition|)
block|{
comment|/* Yes. Give up now. */
return|return;
block|}
comment|/* Do we have enough data for the full TLV? */
if|if
condition|(
name|caplen
operator|<
name|size
operator|||
name|length
operator|<
name|size
condition|)
block|{
comment|/* No. */
return|return;
block|}
comment|/* Skip over the TLV. */
name|length
operator|-=
name|size
expr_stmt|;
name|caplen
operator|-=
name|size
expr_stmt|;
name|p
operator|+=
name|size
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|swap_pseudo_headers
parameter_list|(
name|int
name|linktype
parameter_list|,
name|struct
name|pcap_pkthdr
modifier|*
name|hdr
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|)
block|{
comment|/* 	 * Convert pseudo-headers from the byte order of 	 * the host on which the file was saved to our 	 * byte order, as necessary. 	 */
switch|switch
condition|(
name|linktype
condition|)
block|{
case|case
name|DLT_LINUX_SLL
case|:
name|swap_linux_sll_header
argument_list|(
name|hdr
argument_list|,
name|data
argument_list|)
expr_stmt|;
break|break;
case|case
name|DLT_USB_LINUX
case|:
name|swap_linux_usb_header
argument_list|(
name|hdr
argument_list|,
name|data
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|DLT_USB_LINUX_MMAPPED
case|:
name|swap_linux_usb_header
argument_list|(
name|hdr
argument_list|,
name|data
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|DLT_NFLOG
case|:
name|swap_nflog_header
argument_list|(
name|hdr
argument_list|,
name|data
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

end_unit

