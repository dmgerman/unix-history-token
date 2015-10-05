begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence   * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)bpf.h       7.1 (Berkeley) 5/7/91  *  * @(#) $Header: /tcpdump/master/libpcap/pcap-bpf.h,v 1.37 2005/05/01 19:46:27 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * This is libpcap's cut-down version of bpf.h; it includes only  * the stuff needed for the code generator and the userland BPF  * interpreter, and the libpcap APIs for setting filters, etc..  *  * "pcap-bpf.c" will include the native OS version, as it deals with  * the OS's BPF implementation.  *  * XXX - should this all just be moved to "pcap.h"?  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BPF_MAJOR_VERSION
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* BSD style release date */
define|#
directive|define
name|BPF_RELEASE
value|199606
ifdef|#
directive|ifdef
name|MSDOS
comment|/* must be 32-bit */
typedef|typedef
name|long
name|bpf_int32
typedef|;
typedef|typedef
name|unsigned
name|long
name|bpf_u_int32
typedef|;
else|#
directive|else
typedef|typedef
name|int
name|bpf_int32
typedef|;
typedef|typedef
name|u_int
name|bpf_u_int32
typedef|;
endif|#
directive|endif
comment|/*  * Alignment macros.  BPF_WORDALIGN rounds up to the next   * even multiple of BPF_ALIGNMENT.   */
ifndef|#
directive|ifndef
name|__NetBSD__
define|#
directive|define
name|BPF_ALIGNMENT
value|sizeof(bpf_int32)
else|#
directive|else
define|#
directive|define
name|BPF_ALIGNMENT
value|sizeof(long)
endif|#
directive|endif
define|#
directive|define
name|BPF_WORDALIGN
parameter_list|(
name|x
parameter_list|)
value|(((x)+(BPF_ALIGNMENT-1))&~(BPF_ALIGNMENT-1))
define|#
directive|define
name|BPF_MAXINSNS
value|512
define|#
directive|define
name|BPF_MAXBUFSIZE
value|0x8000
define|#
directive|define
name|BPF_MINBUFSIZE
value|32
comment|/*  * Structure for "pcap_compile()", "pcap_setfilter()", etc..  */
struct|struct
name|bpf_program
block|{
name|u_int
name|bf_len
decl_stmt|;
name|struct
name|bpf_insn
modifier|*
name|bf_insns
decl_stmt|;
block|}
struct|;
comment|/*  * Struct return by BIOCVERSION.  This represents the version number of   * the filter language described by the instruction encodings below.  * bpf understands a program iff kernel_major == filter_major&&  * kernel_minor>= filter_minor, that is, if the value returned by the  * running kernel has the same major number and a minor number equal  * equal to or less than the filter being downloaded.  Otherwise, the  * results are undefined, meaning an error may be returned or packets  * may be accepted haphazardly.  * It has nothing to do with the source code version.  */
struct|struct
name|bpf_version
block|{
name|u_short
name|bv_major
decl_stmt|;
name|u_short
name|bv_minor
decl_stmt|;
block|}
struct|;
comment|/* Current version number of filter architecture. */
define|#
directive|define
name|BPF_MAJOR_VERSION
value|1
define|#
directive|define
name|BPF_MINOR_VERSION
value|1
comment|/*  * Data-link level type codes.  *  * Do *NOT* add new values to this list without asking  * "tcpdump-workers@tcpdump.org" for a value.  Otherwise, you run the  * risk of using a value that's already being used for some other purpose,  * and of having tools that read libpcap-format captures not being able  * to handle captures with your new DLT_ value, with no hope that they  * will ever be changed to do so (as that would destroy their ability  * to read captures using that value for that other purpose).  */
comment|/*  * These are the types that are the same on all platforms, and that  * have been defined by<net/bpf.h> for ages.  */
define|#
directive|define
name|DLT_NULL
value|0
comment|/* BSD loopback encapsulation */
define|#
directive|define
name|DLT_EN10MB
value|1
comment|/* Ethernet (10Mb) */
define|#
directive|define
name|DLT_EN3MB
value|2
comment|/* Experimental Ethernet (3Mb) */
define|#
directive|define
name|DLT_AX25
value|3
comment|/* Amateur Radio AX.25 */
define|#
directive|define
name|DLT_PRONET
value|4
comment|/* Proteon ProNET Token Ring */
define|#
directive|define
name|DLT_CHAOS
value|5
comment|/* Chaos */
define|#
directive|define
name|DLT_IEEE802
value|6
comment|/* IEEE 802 Networks */
define|#
directive|define
name|DLT_ARCNET
value|7
comment|/* ARCNET, with BSD-style header */
define|#
directive|define
name|DLT_SLIP
value|8
comment|/* Serial Line IP */
define|#
directive|define
name|DLT_PPP
value|9
comment|/* Point-to-point Protocol */
define|#
directive|define
name|DLT_FDDI
value|10
comment|/* FDDI */
comment|/*  * These are types that are different on some platforms, and that  * have been defined by<net/bpf.h> for ages.  We use #ifdefs to  * detect the BSDs that define them differently from the traditional  * libpcap<net/bpf.h>  *  * XXX - DLT_ATM_RFC1483 is 13 in BSD/OS, and DLT_RAW is 14 in BSD/OS,  * but I don't know what the right #define is for BSD/OS.  */
define|#
directive|define
name|DLT_ATM_RFC1483
value|11
comment|/* LLC/SNAP encapsulated atm */
ifdef|#
directive|ifdef
name|__OpenBSD__
define|#
directive|define
name|DLT_RAW
value|14
comment|/* raw IP */
else|#
directive|else
define|#
directive|define
name|DLT_RAW
value|12
comment|/* raw IP */
endif|#
directive|endif
comment|/*  * Given that the only OS that currently generates BSD/OS SLIP or PPP  * is, well, BSD/OS, arguably everybody should have chosen its values  * for DLT_SLIP_BSDOS and DLT_PPP_BSDOS, which are 15 and 16, but they  * didn't.  So it goes.  */
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
ifndef|#
directive|ifndef
name|DLT_SLIP_BSDOS
define|#
directive|define
name|DLT_SLIP_BSDOS
value|13
comment|/* BSD/OS Serial Line IP */
define|#
directive|define
name|DLT_PPP_BSDOS
value|14
comment|/* BSD/OS Point-to-point Protocol */
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|DLT_SLIP_BSDOS
value|15
comment|/* BSD/OS Serial Line IP */
define|#
directive|define
name|DLT_PPP_BSDOS
value|16
comment|/* BSD/OS Point-to-point Protocol */
endif|#
directive|endif
comment|/*  * 17 is used for DLT_OLD_PFLOG in OpenBSD;  *     OBSOLETE: DLT_PFLOG is 117 in OpenBSD now as well. See below.  * 18 is used for DLT_PFSYNC in OpenBSD; don't use it for anything else.  */
define|#
directive|define
name|DLT_ATM_CLIP
value|19
comment|/* Linux Classical-IP over ATM */
comment|/*  * Apparently Redback uses this for its SmartEdge 400/800.  I hope  * nobody else decided to use it, too.  */
define|#
directive|define
name|DLT_REDBACK_SMARTEDGE
value|32
comment|/*  * These values are defined by NetBSD; other platforms should refrain from  * using them for other purposes, so that NetBSD savefiles with link  * types of 50 or 51 can be read as this type on all platforms.  */
define|#
directive|define
name|DLT_PPP_SERIAL
value|50
comment|/* PPP over serial with HDLC encapsulation */
define|#
directive|define
name|DLT_PPP_ETHER
value|51
comment|/* PPP over Ethernet */
comment|/*  * The Axent Raptor firewall - now the Symantec Enterprise Firewall - uses  * a link-layer type of 99 for the tcpdump it supplies.  The link-layer  * header has 6 bytes of unknown data, something that appears to be an  * Ethernet type, and 36 bytes that appear to be 0 in at least one capture  * I've seen.  */
define|#
directive|define
name|DLT_SYMANTEC_FIREWALL
value|99
comment|/*  * Values between 100 and 103 are used in capture file headers as  * link-layer types corresponding to DLT_ types that differ  * between platforms; don't use those values for new DLT_ new types.  */
comment|/*  * This value was defined by libpcap 0.5; platforms that have defined  * it with a different value should define it here with that value -  * a link type of 104 in a save file will be mapped to DLT_C_HDLC,  * whatever value that happens to be, so programs will correctly  * handle files with that link type regardless of the value of  * DLT_C_HDLC.  *  * The name DLT_C_HDLC was used by BSD/OS; we use that name for source  * compatibility with programs written for BSD/OS.  *  * libpcap 0.5 defined it as DLT_CHDLC; we define DLT_CHDLC as well,  * for source compatibility with programs written for libpcap 0.5.  */
define|#
directive|define
name|DLT_C_HDLC
value|104
comment|/* Cisco HDLC */
define|#
directive|define
name|DLT_CHDLC
value|DLT_C_HDLC
define|#
directive|define
name|DLT_IEEE802_11
value|105
comment|/* IEEE 802.11 wireless */
comment|/*  * 106 is reserved for Linux Classical IP over ATM; it's like DLT_RAW,  * except when it isn't.  (I.e., sometimes it's just raw IP, and  * sometimes it isn't.)  We currently handle it as DLT_LINUX_SLL,  * so that we don't have to worry about the link-layer header.)  */
comment|/*  * Frame Relay; BSD/OS has a DLT_FR with a value of 11, but that collides  * with other values.  * DLT_FR and DLT_FRELAY packets start with the Q.922 Frame Relay header  * (DLCI, etc.).  */
define|#
directive|define
name|DLT_FRELAY
value|107
comment|/*  * OpenBSD DLT_LOOP, for loopback devices; it's like DLT_NULL, except  * that the AF_ type in the link-layer header is in network byte order.  *  * OpenBSD defines it as 12, but that collides with DLT_RAW, so we  * define it as 108 here.  If OpenBSD picks up this file, it should  * define DLT_LOOP as 12 in its version, as per the comment above -  * and should not use 108 as a DLT_ value.  */
define|#
directive|define
name|DLT_LOOP
value|108
comment|/*  * Encapsulated packets for IPsec; DLT_ENC is 13 in OpenBSD, but that's  * DLT_SLIP_BSDOS in NetBSD, so we don't use 13 for it in OSes other  * than OpenBSD.  */
ifdef|#
directive|ifdef
name|__OpenBSD__
define|#
directive|define
name|DLT_ENC
value|13
else|#
directive|else
define|#
directive|define
name|DLT_ENC
value|109
endif|#
directive|endif
comment|/*  * Values between 110 and 112 are reserved for use in capture file headers  * as link-layer types corresponding to DLT_ types that might differ  * between platforms; don't use those values for new DLT_ types  * other than the corresponding DLT_ types.  */
comment|/*  * This is for Linux cooked sockets.  */
define|#
directive|define
name|DLT_LINUX_SLL
value|113
comment|/*  * Apple LocalTalk hardware.  */
define|#
directive|define
name|DLT_LTALK
value|114
comment|/*  * Acorn Econet.  */
define|#
directive|define
name|DLT_ECONET
value|115
comment|/*  * Reserved for use with OpenBSD ipfilter.  */
define|#
directive|define
name|DLT_IPFILTER
value|116
comment|/*  * OpenBSD DLT_PFLOG; DLT_PFLOG is 17 in OpenBSD, but that's DLT_LANE8023  * in SuSE 6.3, so we can't use 17 for it in capture-file headers.  *  * XXX: is there a conflict with DLT_PFSYNC 18 as well?  */
ifdef|#
directive|ifdef
name|__OpenBSD__
define|#
directive|define
name|DLT_OLD_PFLOG
value|17
define|#
directive|define
name|DLT_PFSYNC
value|18
endif|#
directive|endif
define|#
directive|define
name|DLT_PFLOG
value|117
comment|/*  * Registered for Cisco-internal use.  */
define|#
directive|define
name|DLT_CISCO_IOS
value|118
comment|/*  * For 802.11 cards using the Prism II chips, with a link-layer  * header including Prism monitor mode information plus an 802.11  * header.  */
define|#
directive|define
name|DLT_PRISM_HEADER
value|119
comment|/*  * Reserved for Aironet 802.11 cards, with an Aironet link-layer header  * (see Doug Ambrisko's FreeBSD patches).  */
define|#
directive|define
name|DLT_AIRONET_HEADER
value|120
comment|/*  * Reserved for Siemens HiPath HDLC.  */
define|#
directive|define
name|DLT_HHDLC
value|121
comment|/*  * This is for RFC 2625 IP-over-Fibre Channel.  *  * This is not for use with raw Fibre Channel, where the link-layer  * header starts with a Fibre Channel frame header; it's for IP-over-FC,  * where the link-layer header starts with an RFC 2625 Network_Header  * field.  */
define|#
directive|define
name|DLT_IP_OVER_FC
value|122
comment|/*  * This is for Full Frontal ATM on Solaris with SunATM, with a  * pseudo-header followed by an AALn PDU.  *  * There may be other forms of Full Frontal ATM on other OSes,  * with different pseudo-headers.  *  * If ATM software returns a pseudo-header with VPI/VCI information  * (and, ideally, packet type information, e.g. signalling, ILMI,  * LANE, LLC-multiplexed traffic, etc.), it should not use  * DLT_ATM_RFC1483, but should get a new DLT_ value, so tcpdump  * and the like don't have to infer the presence or absence of a  * pseudo-header and the form of the pseudo-header.  */
define|#
directive|define
name|DLT_SUNATM
value|123
comment|/* Solaris+SunATM */
comment|/*   * Reserved as per request from Kent Dahlgren<kent@praesum.com>  * for private use.  */
define|#
directive|define
name|DLT_RIO
value|124
comment|/* RapidIO */
define|#
directive|define
name|DLT_PCI_EXP
value|125
comment|/* PCI Express */
define|#
directive|define
name|DLT_AURORA
value|126
comment|/* Xilinx Aurora link layer */
comment|/*  * Header for 802.11 plus a number of bits of link-layer information  * including radio information, used by some recent BSD drivers as  * well as the madwifi Atheros driver for Linux.  */
define|#
directive|define
name|DLT_IEEE802_11_RADIO
value|127
comment|/* 802.11 plus radiotap radio header */
comment|/*  * Reserved for the TZSP encapsulation, as per request from  * Chris Waters<chris.waters@networkchemistry.com>  * TZSP is a generic encapsulation for any other link type,  * which includes a means to include meta-information  * with the packet, e.g. signal strength and channel  * for 802.11 packets.  */
define|#
directive|define
name|DLT_TZSP
value|128
comment|/* Tazmen Sniffer Protocol */
comment|/*  * BSD's ARCNET headers have the source host, destination host,  * and type at the beginning of the packet; that's what's handed  * up to userland via BPF.  *  * Linux's ARCNET headers, however, have a 2-byte offset field  * between the host IDs and the type; that's what's handed up  * to userland via PF_PACKET sockets.  *  * We therefore have to have separate DLT_ values for them.  */
define|#
directive|define
name|DLT_ARCNET_LINUX
value|129
comment|/* ARCNET */
comment|/*  * Juniper-private data link types, as per request from  * Hannes Gredler<hannes@juniper.net>.  The DLT_s are used  * for passing on chassis-internal metainformation such as  * QOS profiles, etc..  */
define|#
directive|define
name|DLT_JUNIPER_MLPPP
value|130
define|#
directive|define
name|DLT_JUNIPER_MLFR
value|131
define|#
directive|define
name|DLT_JUNIPER_ES
value|132
define|#
directive|define
name|DLT_JUNIPER_GGSN
value|133
define|#
directive|define
name|DLT_JUNIPER_MFR
value|134
define|#
directive|define
name|DLT_JUNIPER_ATM2
value|135
define|#
directive|define
name|DLT_JUNIPER_SERVICES
value|136
define|#
directive|define
name|DLT_JUNIPER_ATM1
value|137
comment|/*  * Apple IP-over-IEEE 1394, as per a request from Dieter Siegmund  *<dieter@apple.com>.  The header that's presented is an Ethernet-like  * header:  *  *	#define FIREWIRE_EUI64_LEN	8  *	struct firewire_header {  *		u_char  firewire_dhost[FIREWIRE_EUI64_LEN];  *		u_char  firewire_shost[FIREWIRE_EUI64_LEN];  *		u_short firewire_type;  *	};  *  * with "firewire_type" being an Ethernet type value, rather than,  * for example, raw GASP frames being handed up.  */
define|#
directive|define
name|DLT_APPLE_IP_OVER_IEEE1394
value|138
comment|/*  * Various SS7 encapsulations, as per a request from Jeff Morriss  *<jeff.morriss[AT]ulticom.com> and subsequent discussions.  */
define|#
directive|define
name|DLT_MTP2_WITH_PHDR
value|139
comment|/* pseudo-header with various info, followed by MTP2 */
define|#
directive|define
name|DLT_MTP2
value|140
comment|/* MTP2, without pseudo-header */
define|#
directive|define
name|DLT_MTP3
value|141
comment|/* MTP3, without pseudo-header or MTP2 */
define|#
directive|define
name|DLT_SCCP
value|142
comment|/* SCCP, without pseudo-header or MTP2 or MTP3 */
comment|/*  * DOCSIS MAC frames.  */
define|#
directive|define
name|DLT_DOCSIS
value|143
comment|/*  * Linux-IrDA packets. Protocol defined at http://www.irda.org.  * Those packets include IrLAP headers and above (IrLMP...), but  * don't include Phy framing (SOF/EOF/CRC& byte stuffing), because Phy  * framing can be handled by the hardware and depend on the bitrate.  * This is exactly the format you would get capturing on a Linux-IrDA  * interface (irdaX), but not on a raw serial port.  * Note the capture is done in "Linux-cooked" mode, so each packet include  * a fake packet header (struct sll_header). This is because IrDA packet  * decoding is dependant on the direction of the packet (incomming or  * outgoing).  * When/if other platform implement IrDA capture, we may revisit the  * issue and define a real DLT_IRDA...  * Jean II  */
define|#
directive|define
name|DLT_LINUX_IRDA
value|144
comment|/*  * Reserved for IBM SP switch and IBM Next Federation switch.  */
define|#
directive|define
name|DLT_IBM_SP
value|145
define|#
directive|define
name|DLT_IBM_SN
value|146
comment|/*  * Reserved for private use.  If you have some link-layer header type  * that you want to use within your organization, with the capture files  * using that link-layer header type not ever be sent outside your  * organization, you can use these values.  *  * No libpcap release will use these for any purpose, nor will any  * tcpdump release use them, either.  *  * Do *NOT* use these in capture files that you expect anybody not using  * your private versions of capture-file-reading tools to read; in  * particular, do *NOT* use them in products, otherwise you may find that  * people won't be able to use tcpdump, or snort, or Ethereal, or... to  * read capture files from your firewall/intrusion detection/traffic  * monitoring/etc. appliance, or whatever product uses that DLT_ value,  * and you may also find that the developers of those applications will  * not accept patches to let them read those files.  *  * Also, do not use them if somebody might send you a capture using them  * for *their* private type and tools using them for *your* private type  * would have to read them.  *  * Instead, ask "tcpdump-workers@tcpdump.org" for a new DLT_ value,  * as per the comment above, and use the type you're given.  */
define|#
directive|define
name|DLT_USER0
value|147
define|#
directive|define
name|DLT_USER1
value|148
define|#
directive|define
name|DLT_USER2
value|149
define|#
directive|define
name|DLT_USER3
value|150
define|#
directive|define
name|DLT_USER4
value|151
define|#
directive|define
name|DLT_USER5
value|152
define|#
directive|define
name|DLT_USER6
value|153
define|#
directive|define
name|DLT_USER7
value|154
define|#
directive|define
name|DLT_USER8
value|155
define|#
directive|define
name|DLT_USER9
value|156
define|#
directive|define
name|DLT_USER10
value|157
define|#
directive|define
name|DLT_USER11
value|158
define|#
directive|define
name|DLT_USER12
value|159
define|#
directive|define
name|DLT_USER13
value|160
define|#
directive|define
name|DLT_USER14
value|161
define|#
directive|define
name|DLT_USER15
value|162
comment|/*  * For future use with 802.11 captures - defined by AbsoluteValue  * Systems to store a number of bits of link-layer information  * including radio information:  *  *	http://www.shaftnet.org/~pizza/software/capturefrm.txt  *  * but it might be used by some non-AVS drivers now or in the  * future.  */
define|#
directive|define
name|DLT_IEEE802_11_RADIO_AVS
value|163
comment|/* 802.11 plus AVS radio header */
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  The DLT_s are used  * for passing on chassis-internal metainformation such as  * QOS profiles, etc..  */
define|#
directive|define
name|DLT_JUNIPER_MONITOR
value|164
comment|/*  * Reserved for BACnet MS/TP.  */
define|#
directive|define
name|DLT_BACNET_MS_TP
value|165
comment|/*  * Another PPP variant as per request from Karsten Keil<kkeil@suse.de>.  *  * This is used in some OSes to allow a kernel socket filter to distinguish  * between incoming and outgoing packets, on a socket intended to  * supply pppd with outgoing packets so it can do dial-on-demand and  * hangup-on-lack-of-demand; incoming packets are filtered out so they  * don't cause pppd to hold the connection up (you don't want random  * input packets such as port scans, packets from old lost connections,  * etc. to force the connection to stay up).  *  * The first byte of the PPP header (0xff03) is modified to accomodate  * the direction - 0x00 = IN, 0x01 = OUT.  */
define|#
directive|define
name|DLT_PPP_PPPD
value|166
comment|/*  * Names for backwards compatibility with older versions of some PPP  * software; new software should use DLT_PPP_PPPD.  */
define|#
directive|define
name|DLT_PPP_WITH_DIRECTION
value|DLT_PPP_PPPD
define|#
directive|define
name|DLT_LINUX_PPP_WITHDIRECTION
value|DLT_PPP_PPPD
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  The DLT_s are used  * for passing on chassis-internal metainformation such as  * QOS profiles, cookies, etc..  */
define|#
directive|define
name|DLT_JUNIPER_PPPOE
value|167
define|#
directive|define
name|DLT_JUNIPER_PPPOE_ATM
value|168
define|#
directive|define
name|DLT_GPRS_LLC
value|169
comment|/* GPRS LLC */
define|#
directive|define
name|DLT_GPF_T
value|170
comment|/* GPF-T (ITU-T G.7041/Y.1303) */
define|#
directive|define
name|DLT_GPF_F
value|171
comment|/* GPF-F (ITU-T G.7041/Y.1303) */
comment|/*  * Requested by Oolan Zimmer<oz@gcom.com> for use in Gcom's T1/E1 line  * monitoring equipment.  */
define|#
directive|define
name|DLT_GCOM_T1E1
value|172
define|#
directive|define
name|DLT_GCOM_SERIAL
value|173
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  The DLT_ is used  * for internal communication to Physical Interface Cards (PIC)  */
define|#
directive|define
name|DLT_JUNIPER_PIC_PEER
value|174
comment|/*  * Link types requested by Gregor Maier<gregor@endace.com> of Endace  * Measurement Systems.  They add an ERF header (see  * http://www.endace.com/support/EndaceRecordFormat.pdf) in front of  * the link-layer header.  */
define|#
directive|define
name|DLT_ERF_ETH
value|175
comment|/* Ethernet */
define|#
directive|define
name|DLT_ERF_POS
value|176
comment|/* Packet-over-SONET */
comment|/*  * Requested by Daniele Orlandi<daniele@orlandi.com> for raw LAPD  * for vISDN (http://www.orlandi.com/visdn/).  Its link-layer header  * includes additional information before the LAPD header, so it's  * not necessarily a generic LAPD header.  */
define|#
directive|define
name|DLT_LINUX_LAPD
value|177
comment|/*  * The instruction encodings.  */
comment|/* instruction classes */
define|#
directive|define
name|BPF_CLASS
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x07)
define|#
directive|define
name|BPF_LD
value|0x00
define|#
directive|define
name|BPF_LDX
value|0x01
define|#
directive|define
name|BPF_ST
value|0x02
define|#
directive|define
name|BPF_STX
value|0x03
define|#
directive|define
name|BPF_ALU
value|0x04
define|#
directive|define
name|BPF_JMP
value|0x05
define|#
directive|define
name|BPF_RET
value|0x06
define|#
directive|define
name|BPF_MISC
value|0x07
comment|/* ld/ldx fields */
define|#
directive|define
name|BPF_SIZE
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x18)
define|#
directive|define
name|BPF_W
value|0x00
define|#
directive|define
name|BPF_H
value|0x08
define|#
directive|define
name|BPF_B
value|0x10
define|#
directive|define
name|BPF_MODE
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xe0)
define|#
directive|define
name|BPF_IMM
value|0x00
define|#
directive|define
name|BPF_ABS
value|0x20
define|#
directive|define
name|BPF_IND
value|0x40
define|#
directive|define
name|BPF_MEM
value|0x60
define|#
directive|define
name|BPF_LEN
value|0x80
define|#
directive|define
name|BPF_MSH
value|0xa0
comment|/* alu/jmp fields */
define|#
directive|define
name|BPF_OP
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xf0)
define|#
directive|define
name|BPF_ADD
value|0x00
define|#
directive|define
name|BPF_SUB
value|0x10
define|#
directive|define
name|BPF_MUL
value|0x20
define|#
directive|define
name|BPF_DIV
value|0x30
define|#
directive|define
name|BPF_OR
value|0x40
define|#
directive|define
name|BPF_AND
value|0x50
define|#
directive|define
name|BPF_LSH
value|0x60
define|#
directive|define
name|BPF_RSH
value|0x70
define|#
directive|define
name|BPF_NEG
value|0x80
define|#
directive|define
name|BPF_JA
value|0x00
define|#
directive|define
name|BPF_JEQ
value|0x10
define|#
directive|define
name|BPF_JGT
value|0x20
define|#
directive|define
name|BPF_JGE
value|0x30
define|#
directive|define
name|BPF_JSET
value|0x40
define|#
directive|define
name|BPF_SRC
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x08)
define|#
directive|define
name|BPF_K
value|0x00
define|#
directive|define
name|BPF_X
value|0x08
comment|/* ret - BPF_K and BPF_X also apply */
define|#
directive|define
name|BPF_RVAL
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x18)
define|#
directive|define
name|BPF_A
value|0x10
comment|/* misc */
define|#
directive|define
name|BPF_MISCOP
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xf8)
define|#
directive|define
name|BPF_TAX
value|0x00
define|#
directive|define
name|BPF_TXA
value|0x80
comment|/*  * The instruction data structure.  */
struct|struct
name|bpf_insn
block|{
name|u_short
name|code
decl_stmt|;
name|u_char
name|jt
decl_stmt|;
name|u_char
name|jf
decl_stmt|;
name|bpf_int32
name|k
decl_stmt|;
block|}
struct|;
comment|/*  * Macros for insn array initializers.  */
define|#
directive|define
name|BPF_STMT
parameter_list|(
name|code
parameter_list|,
name|k
parameter_list|)
value|{ (u_short)(code), 0, 0, k }
define|#
directive|define
name|BPF_JUMP
parameter_list|(
name|code
parameter_list|,
name|k
parameter_list|,
name|jt
parameter_list|,
name|jf
parameter_list|)
value|{ (u_short)(code), jt, jf, k }
if|#
directive|if
name|__STDC__
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
specifier|extern
name|int
name|bpf_validate
parameter_list|(
name|struct
name|bpf_insn
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|u_int
name|bpf_filter
parameter_list|(
name|struct
name|bpf_insn
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|int
name|bpf_validate
parameter_list|()
function_decl|;
specifier|extern
name|u_int
name|bpf_filter
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/*  * Number of scratch memory words (for BPF_LD|BPF_MEM and BPF_ST).  */
define|#
directive|define
name|BPF_MEMWORDS
value|16
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

