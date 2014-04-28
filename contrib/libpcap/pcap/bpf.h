begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence   * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)bpf.h       7.1 (Berkeley) 5/7/91  *  * @(#) $Header: /tcpdump/master/libpcap/pcap/bpf.h,v 1.32 2008-12-23 20:13:29 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * This is libpcap's cut-down version of bpf.h; it includes only  * the stuff needed for the code generator and the userland BPF  * interpreter, and the libpcap APIs for setting filters, etc..  *  * "pcap-bpf.c" will include the native OS version, as it deals with  * the OS's BPF implementation.  *  * At least two programs found by Google Code Search explicitly includes  *<pcap/bpf.h> (even though<pcap.h>/<pcap/pcap.h> includes it for you),  * so moving that stuff to<pcap/pcap.h> would break the build for some  * programs.  */
end_comment

begin_comment
comment|/*  * If we've already included<net/bpf.h>, don't re-define this stuff.  * We assume BSD-style multiple-include protection in<net/bpf.h>,  * which is true of all but the oldest versions of FreeBSD and NetBSD,  * or Tru64 UNIX-style multiple-include protection (or, at least,  * Tru64 UNIX 5.x-style; I don't have earlier versions available to check),  * or AIX-style multiple-include protection (or, at least, AIX 5.x-style;  * I don't have earlier versions available to check).  *  * We do not check for BPF_MAJOR_VERSION, as that's defined by  *<linux/filter.h>, which is directly or indirectly included in some  * programs that also include pcap.h, and<linux/filter.h> doesn't  * define stuff we need.  *  * This also provides our own multiple-include protection.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_NET_BPF_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_BPF_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_H_BPF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lib_pcap_bpf_h
argument_list|)
end_if

begin_define
define|#
directive|define
name|lib_pcap_bpf_h
end_define

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
comment|/*  * Alignment macros.  BPF_WORDALIGN rounds up to the next   * even multiple of BPF_ALIGNMENT.  *  * Tcpdump's print-pflog.c uses this, so we define it here.  */
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
comment|/*  * Link-layer header type codes.  *  * Do *NOT* add new values to this list without asking  * "tcpdump-workers@lists.tcpdump.org" for a value.  Otherwise, you run  * the risk of using a value that's already being used for some other  * purpose, and of having tools that read libpcap-format captures not  * being able to handle captures with your new DLT_ value, with no hope  * that they will ever be changed to do so (as that would destroy their  * ability to read captures using that value for that other purpose).  *  * See  *  *	http://www.tcpdump.org/linktypes.html  *  * for detailed descriptions of some of these link-layer header types.  */
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
comment|/* 802.5 Token Ring */
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
comment|/* LLC-encapsulated ATM */
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
comment|/*  * 17 was used for DLT_PFLOG in OpenBSD; it no longer is.  *  * It was DLT_LANE8023 in SuSE 6.3, so we defined LINKTYPE_PFLOG  * as 117 so that pflog captures would use a link-layer header type  * value that didn't collide with any other values.  On all  * platforms other than OpenBSD, we defined DLT_PFLOG as 117,  * and we mapped between LINKTYPE_PFLOG and DLT_PFLOG.  *  * OpenBSD eventually switched to using 117 for DLT_PFLOG as well.  *  * Don't use 17 for anything else.  */
comment|/*  * 18 is used for DLT_PFSYNC in OpenBSD, NetBSD, DragonFly BSD and  * Mac OS X; don't use it for anything else.  (FreeBSD uses 121,  * which collides with DLT_HHDLC, even though it doesn't use 18  * for anything and doesn't appear to have ever used it for anything.)  *  * We define it as 18 on those platforms; it is, unfortunately, used  * for DLT_CIP in Suse 6.3, so we don't define it as DLT_PFSYNC  * in general.  As the packet format for it, like that for  * DLT_PFLOG, is not only OS-dependent but OS-version-dependent,  * we don't support printing it in tcpdump except on OSes that  * have the relevant header files, so it's not that useful on  * other platforms.  */
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
operator|||
name|defined
argument_list|(
name|__APPLE__
argument_list|)
define|#
directive|define
name|DLT_PFSYNC
value|18
endif|#
directive|endif
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
comment|/*  * Values between 100 and 103 are used in capture file headers as  * link-layer header type LINKTYPE_ values corresponding to DLT_ types  * that differ between platforms; don't use those values for new DLT_  * new types.  */
comment|/*  * Values starting with 104 are used for newly-assigned link-layer  * header type values; for those link-layer header types, the DLT_  * value returned by pcap_datalink() and passed to pcap_open_dead(),  * and the LINKTYPE_ value that appears in capture files, are the  * same.  *  * DLT_MATCHING_MIN is the lowest such value; DLT_MATCHING_MAX is  * the highest such value.  */
define|#
directive|define
name|DLT_MATCHING_MIN
value|104
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
comment|/*  * OpenBSD DLT_LOOP, for loopback devices; it's like DLT_NULL, except  * that the AF_ type in the link-layer header is in network byte order.  *  * DLT_LOOP is 12 in OpenBSD, but that's DLT_RAW in other OSes, so  * we don't use 12 for it in OSes other than OpenBSD.  */
ifdef|#
directive|ifdef
name|__OpenBSD__
define|#
directive|define
name|DLT_LOOP
value|12
else|#
directive|else
define|#
directive|define
name|DLT_LOOP
value|108
endif|#
directive|endif
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
comment|/*  * OpenBSD DLT_PFLOG.  */
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
comment|/*  * Sigh.  *  * This was reserved for Siemens HiPath HDLC on 2002-01-25, as  * requested by Tomas Kukosa.  *  * On 2004-02-25, a FreeBSD checkin to sys/net/bpf.h was made that  * assigned 121 as DLT_PFSYNC.  Its libpcap does DLT_<-> LINKTYPE_  * mapping, so it probably supports capturing on the pfsync device  * but not saving the captured data to a pcap file.  *  * OpenBSD, from which pf came, however, uses 18 for DLT_PFSYNC;  * their libpcap does no DLT_<-> LINKTYPE_ mapping, so it would  * use 18 in pcap files as well.  *  * NetBSD and DragonFly BSD also use 18 for DLT_PFSYNC; their  * libpcaps do DLT_<-> LINKTYPE_ mapping, and neither has an entry  * for DLT_PFSYNC, so it might not be able to write out dump files  * with 18 as the link-layer header type.  (Earlier versions might  * not have done mapping, in which case they'd work the same way  * OpenBSD does.)  *  * Mac OS X defines it as 18, but doesn't appear to use it as of  * Mac OS X 10.7.3.  Its libpcap does DLT_<-> LINKTYPE_ mapping.  *  * We'll define DLT_PFSYNC as 121 on FreeBSD and define it as 18 on  * all other platforms.  We'll define DLT_HHDLC as 121 on everything  * except for FreeBSD; anybody who wants to compile, on FreeBSD, code  * that uses DLT_HHDLC is out of luck.  *  * We'll define LINKTYPE_PFSYNC as 18, *even on FreeBSD*, and map  * it, so that savefiles won't use 121 for PFSYNC - they'll all  * use 18.  Code that uses pcap_datalink() to determine the link-layer  * header type of a savefile won't, when built and run on FreeBSD,  * be able to distinguish between LINKTYPE_PFSYNC and LINKTYPE_HHDLC  * capture files; code that doesn't, such as the code in Wireshark,  * will be able to distinguish between them.  */
ifdef|#
directive|ifdef
name|__FreeBSD__
define|#
directive|define
name|DLT_PFSYNC
value|121
else|#
directive|else
define|#
directive|define
name|DLT_HHDLC
value|121
endif|#
directive|endif
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
comment|/*  * Reserved for private use.  If you have some link-layer header type  * that you want to use within your organization, with the capture files  * using that link-layer header type not ever be sent outside your  * organization, you can use these values.  *  * No libpcap release will use these for any purpose, nor will any  * tcpdump release use them, either.  *  * Do *NOT* use these in capture files that you expect anybody not using  * your private versions of capture-file-reading tools to read; in  * particular, do *NOT* use them in products, otherwise you may find that  * people won't be able to use tcpdump, or snort, or Ethereal, or... to  * read capture files from your firewall/intrusion detection/traffic  * monitoring/etc. appliance, or whatever product uses that DLT_ value,  * and you may also find that the developers of those applications will  * not accept patches to let them read those files.  *  * Also, do not use them if somebody might send you a capture using them  * for *their* private type and tools using them for *your* private type  * would have to read them.  *  * Instead, ask "tcpdump-workers@lists.tcpdump.org" for a new DLT_ value,  * as per the comment above, and use the type you're given.  */
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
comment|/*  * BACnet MS/TP frames.  */
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
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.   * The DLT_ are used for prepending meta-information  * like interface index, interface name  * before standard Ethernet, PPP, Frelay& C-HDLC Frames  */
define|#
directive|define
name|DLT_JUNIPER_ETHER
value|178
define|#
directive|define
name|DLT_JUNIPER_PPP
value|179
define|#
directive|define
name|DLT_JUNIPER_FRELAY
value|180
define|#
directive|define
name|DLT_JUNIPER_CHDLC
value|181
comment|/*  * Multi Link Frame Relay (FRF.16)  */
define|#
directive|define
name|DLT_MFR
value|182
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.   * The DLT_ is used for internal communication with a  * voice Adapter Card (PIC)  */
define|#
directive|define
name|DLT_JUNIPER_VP
value|183
comment|/*  * Arinc 429 frames.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  * Every frame contains a 32bit A429 label.  * More documentation on Arinc 429 can be found at  * http://www.condoreng.com/support/downloads/tutorials/ARINCTutorial.pdf  */
define|#
directive|define
name|DLT_A429
value|184
comment|/*  * Arinc 653 Interpartition Communication messages.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  * Please refer to the A653-1 standard for more information.  */
define|#
directive|define
name|DLT_A653_ICM
value|185
comment|/*  * USB packets, beginning with a USB setup header; requested by  * Paolo Abeni<paolo.abeni@email.it>.  */
define|#
directive|define
name|DLT_USB
value|186
comment|/*  * Bluetooth HCI UART transport layer (part H:4); requested by  * Paolo Abeni.  */
define|#
directive|define
name|DLT_BLUETOOTH_HCI_H4
value|187
comment|/*  * IEEE 802.16 MAC Common Part Sublayer; requested by Maria Cruz  *<cruz_petagay@bah.com>.  */
define|#
directive|define
name|DLT_IEEE802_16_MAC_CPS
value|188
comment|/*  * USB packets, beginning with a Linux USB header; requested by  * Paolo Abeni<paolo.abeni@email.it>.  */
define|#
directive|define
name|DLT_USB_LINUX
value|189
comment|/*  * Controller Area Network (CAN) v. 2.0B packets.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  * Used to dump CAN packets coming from a CAN Vector board.  * More documentation on the CAN v2.0B frames can be found at  * http://www.can-cia.org/downloads/?269  */
define|#
directive|define
name|DLT_CAN20B
value|190
comment|/*  * IEEE 802.15.4, with address fields padded, as is done by Linux  * drivers; requested by Juergen Schimmer.  */
define|#
directive|define
name|DLT_IEEE802_15_4_LINUX
value|191
comment|/*  * Per Packet Information encapsulated packets.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  */
define|#
directive|define
name|DLT_PPI
value|192
comment|/*  * Header for 802.16 MAC Common Part Sublayer plus a radiotap radio header;  * requested by Charles Clancy.  */
define|#
directive|define
name|DLT_IEEE802_16_MAC_CPS_RADIO
value|193
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.   * The DLT_ is used for internal communication with a  * integrated service module (ISM).  */
define|#
directive|define
name|DLT_JUNIPER_ISM
value|194
comment|/*  * IEEE 802.15.4, exactly as it appears in the spec (no padding, no  * nothing); requested by Mikko Saarnivala<mikko.saarnivala@sensinode.com>.  * For this one, we expect the FCS to be present at the end of the frame;  * if the frame has no FCS, DLT_IEEE802_15_4_NOFCS should be used.  */
define|#
directive|define
name|DLT_IEEE802_15_4
value|195
comment|/*  * Various link-layer types, with a pseudo-header, for SITA  * (http://www.sita.aero/); requested by Fulko Hew (fulko.hew@gmail.com).  */
define|#
directive|define
name|DLT_SITA
value|196
comment|/*  * Various link-layer types, with a pseudo-header, for Endace DAG cards;  * encapsulates Endace ERF records.  Requested by Stephen Donnelly  *<stephen@endace.com>.  */
define|#
directive|define
name|DLT_ERF
value|197
comment|/*  * Special header prepended to Ethernet packets when capturing from a  * u10 Networks board.  Requested by Phil Mulholland  *<phil@u10networks.com>.  */
define|#
directive|define
name|DLT_RAIF1
value|198
comment|/*  * IPMB packet for IPMI, beginning with the I2C slave address, followed  * by the netFn and LUN, etc..  Requested by Chanthy Toeung  *<chanthy.toeung@ca.kontron.com>.  */
define|#
directive|define
name|DLT_IPMB
value|199
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.   * The DLT_ is used for capturing data on a secure tunnel interface.  */
define|#
directive|define
name|DLT_JUNIPER_ST
value|200
comment|/*  * Bluetooth HCI UART transport layer (part H:4), with pseudo-header  * that includes direction information; requested by Paolo Abeni.  */
define|#
directive|define
name|DLT_BLUETOOTH_HCI_H4_WITH_PHDR
value|201
comment|/*  * AX.25 packet with a 1-byte KISS header; see  *  *	http://www.ax25.net/kiss.htm  *  * as per Richard Stearn<richard@rns-stearn.demon.co.uk>.  */
define|#
directive|define
name|DLT_AX25_KISS
value|202
comment|/*  * LAPD packets from an ISDN channel, starting with the address field,  * with no pseudo-header.  * Requested by Varuna De Silva<varunax@gmail.com>.  */
define|#
directive|define
name|DLT_LAPD
value|203
comment|/*  * Variants of various link-layer headers, with a one-byte direction  * pseudo-header prepended - zero means "received by this host",  * non-zero (any non-zero value) means "sent by this host" - as per  * Will Barker<w.barker@zen.co.uk>.  */
define|#
directive|define
name|DLT_PPP_WITH_DIR
value|204
comment|/* PPP - don't confuse with DLT_PPP_WITH_DIRECTION */
define|#
directive|define
name|DLT_C_HDLC_WITH_DIR
value|205
comment|/* Cisco HDLC */
define|#
directive|define
name|DLT_FRELAY_WITH_DIR
value|206
comment|/* Frame Relay */
define|#
directive|define
name|DLT_LAPB_WITH_DIR
value|207
comment|/* LAPB */
comment|/*  * 208 is reserved for an as-yet-unspecified proprietary link-layer  * type, as requested by Will Barker.  */
comment|/*  * IPMB with a Linux-specific pseudo-header; as requested by Alexey Neyman  *<avn@pigeonpoint.com>.  */
define|#
directive|define
name|DLT_IPMB_LINUX
value|209
comment|/*  * FlexRay automotive bus - http://www.flexray.com/ - as requested  * by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
define|#
directive|define
name|DLT_FLEXRAY
value|210
comment|/*  * Media Oriented Systems Transport (MOST) bus for multimedia  * transport - http://www.mostcooperation.com/ - as requested  * by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
define|#
directive|define
name|DLT_MOST
value|211
comment|/*  * Local Interconnect Network (LIN) bus for vehicle networks -  * http://www.lin-subbus.org/ - as requested by Hannes Kaelber  *<hannes.kaelber@x2e.de>.  */
define|#
directive|define
name|DLT_LIN
value|212
comment|/*  * X2E-private data link type used for serial line capture,  * as requested by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
define|#
directive|define
name|DLT_X2E_SERIAL
value|213
comment|/*  * X2E-private data link type used for the Xoraya data logger  * family, as requested by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
define|#
directive|define
name|DLT_X2E_XORAYA
value|214
comment|/*  * IEEE 802.15.4, exactly as it appears in the spec (no padding, no  * nothing), but with the PHY-level data for non-ASK PHYs (4 octets  * of 0 as preamble, one octet of SFD, one octet of frame length+  * reserved bit, and then the MAC-layer data, starting with the  * frame control field).  *  * Requested by Max Filippov<jcmvbkbc@gmail.com>.  */
define|#
directive|define
name|DLT_IEEE802_15_4_NONASK_PHY
value|215
comment|/*   * David Gibson<david@gibson.dropbear.id.au> requested this for  * captures from the Linux kernel /dev/input/eventN devices. This  * is used to communicate keystrokes and mouse movements from the  * Linux kernel to display systems, such as Xorg.   */
define|#
directive|define
name|DLT_LINUX_EVDEV
value|216
comment|/*  * GSM Um and Abis interfaces, preceded by a "gsmtap" header.  *  * Requested by Harald Welte<laforge@gnumonks.org>.  */
define|#
directive|define
name|DLT_GSMTAP_UM
value|217
define|#
directive|define
name|DLT_GSMTAP_ABIS
value|218
comment|/*  * MPLS, with an MPLS label as the link-layer header.  * Requested by Michele Marchetto<michele@openbsd.org> on behalf  * of OpenBSD.  */
define|#
directive|define
name|DLT_MPLS
value|219
comment|/*  * USB packets, beginning with a Linux USB header, with the USB header  * padded to 64 bytes; required for memory-mapped access.  */
define|#
directive|define
name|DLT_USB_LINUX_MMAPPED
value|220
comment|/*  * DECT packets, with a pseudo-header; requested by  * Matthias Wenzel<tcpdump@mazzoo.de>.  */
define|#
directive|define
name|DLT_DECT
value|221
comment|/*  * From: "Lidwa, Eric (GSFC-582.0)[SGT INC]"<eric.lidwa-1@nasa.gov>  * Date: Mon, 11 May 2009 11:18:30 -0500  *  * DLT_AOS. We need it for AOS Space Data Link Protocol.  *   I have already written dissectors for but need an OK from  *   legal before I can submit a patch.  *  */
define|#
directive|define
name|DLT_AOS
value|222
comment|/*  * Wireless HART (Highway Addressable Remote Transducer)  * From the HART Communication Foundation  * IES/PAS 62591  *  * Requested by Sam Roberts<vieuxtech@gmail.com>.  */
define|#
directive|define
name|DLT_WIHART
value|223
comment|/*  * Fibre Channel FC-2 frames, beginning with a Frame_Header.  * Requested by Kahou Lei<kahou82@gmail.com>.  */
define|#
directive|define
name|DLT_FC_2
value|224
comment|/*  * Fibre Channel FC-2 frames, beginning with an encoding of the  * SOF, and ending with an encoding of the EOF.  *  * The encodings represent the frame delimiters as 4-byte sequences  * representing the corresponding ordered sets, with K28.5  * represented as 0xBC, and the D symbols as the corresponding  * byte values; for example, SOFi2, which is K28.5 - D21.5 - D1.2 - D21.2,  * is represented as 0xBC 0xB5 0x55 0x55.  *  * Requested by Kahou Lei<kahou82@gmail.com>.  */
define|#
directive|define
name|DLT_FC_2_WITH_FRAME_DELIMS
value|225
comment|/*  * Solaris ipnet pseudo-header; requested by Darren Reed<Darren.Reed@Sun.COM>.  *  * The pseudo-header starts with a one-byte version number; for version 2,  * the pseudo-header is:  *  * struct dl_ipnetinfo {  *     u_int8_t   dli_version;  *     u_int8_t   dli_family;  *     u_int16_t  dli_htype;  *     u_int32_t  dli_pktlen;  *     u_int32_t  dli_ifindex;  *     u_int32_t  dli_grifindex;  *     u_int32_t  dli_zsrc;  *     u_int32_t  dli_zdst;  * };  *  * dli_version is 2 for the current version of the pseudo-header.  *  * dli_family is a Solaris address family value, so it's 2 for IPv4  * and 26 for IPv6.  *  * dli_htype is a "hook type" - 0 for incoming packets, 1 for outgoing  * packets, and 2 for packets arriving from another zone on the same  * machine.  *  * dli_pktlen is the length of the packet data following the pseudo-header  * (so the captured length minus dli_pktlen is the length of the  * pseudo-header, assuming the entire pseudo-header was captured).  *  * dli_ifindex is the interface index of the interface on which the  * packet arrived.  *  * dli_grifindex is the group interface index number (for IPMP interfaces).  *  * dli_zsrc is the zone identifier for the source of the packet.  *  * dli_zdst is the zone identifier for the destination of the packet.  *  * A zone number of 0 is the global zone; a zone number of 0xffffffff  * means that the packet arrived from another host on the network, not  * from another zone on the same machine.  *  * An IPv4 or IPv6 datagram follows the pseudo-header; dli_family indicates  * which of those it is.  */
define|#
directive|define
name|DLT_IPNET
value|226
comment|/*  * CAN (Controller Area Network) frames, with a pseudo-header as supplied  * by Linux SocketCAN.  See Documentation/networking/can.txt in the Linux  * source.  *  * Requested by Felix Obenhuber<felix@obenhuber.de>.  */
define|#
directive|define
name|DLT_CAN_SOCKETCAN
value|227
comment|/*  * Raw IPv4/IPv6; different from DLT_RAW in that the DLT_ value specifies  * whether it's v4 or v6.  Requested by Darren Reed<Darren.Reed@Sun.COM>.  */
define|#
directive|define
name|DLT_IPV4
value|228
define|#
directive|define
name|DLT_IPV6
value|229
comment|/*  * IEEE 802.15.4, exactly as it appears in the spec (no padding, no  * nothing), and with no FCS at the end of the frame; requested by  * Jon Smirl<jonsmirl@gmail.com>.  */
define|#
directive|define
name|DLT_IEEE802_15_4_NOFCS
value|230
comment|/*  * Raw D-Bus:  *  *	http://www.freedesktop.org/wiki/Software/dbus  *  * messages:  *  *	http://dbus.freedesktop.org/doc/dbus-specification.html#message-protocol-messages  *  * starting with the endianness flag, followed by the message type, etc.,  * but without the authentication handshake before the message sequence:  *  *	http://dbus.freedesktop.org/doc/dbus-specification.html#auth-protocol  *  * Requested by Martin Vidner<martin@vidner.net>.  */
define|#
directive|define
name|DLT_DBUS
value|231
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  */
define|#
directive|define
name|DLT_JUNIPER_VS
value|232
define|#
directive|define
name|DLT_JUNIPER_SRX_E2E
value|233
define|#
directive|define
name|DLT_JUNIPER_FIBRECHANNEL
value|234
comment|/*  * DVB-CI (DVB Common Interface for communication between a PC Card  * module and a DVB receiver).  See  *  *	http://www.kaiser.cx/pcap-dvbci.html  *  * for the specification.  *  * Requested by Martin Kaiser<martin@kaiser.cx>.  */
define|#
directive|define
name|DLT_DVB_CI
value|235
comment|/*  * Variant of 3GPP TS 27.010 multiplexing protocol (similar to, but  * *not* the same as, 27.010).  Requested by Hans-Christoph Schemmel  *<hans-christoph.schemmel@cinterion.com>.  */
define|#
directive|define
name|DLT_MUX27010
value|236
comment|/*  * STANAG 5066 D_PDUs.  Requested by M. Baris Demiray  *<barisdemiray@gmail.com>.  */
define|#
directive|define
name|DLT_STANAG_5066_D_PDU
value|237
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  */
define|#
directive|define
name|DLT_JUNIPER_ATM_CEMIC
value|238
comment|/*  * NetFilter LOG messages   * (payload of netlink NFNL_SUBSYS_ULOG/NFULNL_MSG_PACKET packets)  *  * Requested by Jakub Zawadzki<darkjames-ws@darkjames.pl>  */
define|#
directive|define
name|DLT_NFLOG
value|239
comment|/*  * Hilscher Gesellschaft fuer Systemautomation mbH link-layer type  * for Ethernet packets with a 4-byte pseudo-header and always  * with the payload including the FCS, as supplied by their  * netANALYZER hardware and software.  *  * Requested by Holger P. Frommer<HPfrommer@hilscher.com>  */
define|#
directive|define
name|DLT_NETANALYZER
value|240
comment|/*  * Hilscher Gesellschaft fuer Systemautomation mbH link-layer type  * for Ethernet packets with a 4-byte pseudo-header and FCS and  * with the Ethernet header preceded by 7 bytes of preamble and  * 1 byte of SFD, as supplied by their netANALYZER hardware and  * software.  *  * Requested by Holger P. Frommer<HPfrommer@hilscher.com>  */
define|#
directive|define
name|DLT_NETANALYZER_TRANSPARENT
value|241
comment|/*  * IP-over-InfiniBand, as specified by RFC 4391.  *  * Requested by Petr Sumbera<petr.sumbera@oracle.com>.  */
define|#
directive|define
name|DLT_IPOIB
value|242
comment|/*  * MPEG-2 transport stream (ISO 13818-1/ITU-T H.222.0).  *  * Requested by Guy Martin<gmsoft@tuxicoman.be>.  */
define|#
directive|define
name|DLT_MPEG_2_TS
value|243
comment|/*  * ng4T GmbH's UMTS Iub/Iur-over-ATM and Iub/Iur-over-IP format as  * used by their ng40 protocol tester.  *  * Requested by Jens Grimmer<jens.grimmer@ng4t.com>.  */
define|#
directive|define
name|DLT_NG40
value|244
comment|/*  * Pseudo-header giving adapter number and flags, followed by an NFC  * (Near-Field Communications) Logical Link Control Protocol (LLCP) PDU,  * as specified by NFC Forum Logical Link Control Protocol Technical  * Specification LLCP 1.1.  *  * Requested by Mike Wakerly<mikey@google.com>.  */
define|#
directive|define
name|DLT_NFC_LLCP
value|245
comment|/*  * 245 is used as LINKTYPE_PFSYNC; do not use it for any other purpose.  *  * DLT_PFSYNC has different values on different platforms, and all of  * them collide with something used elsewhere.  On platforms that  * don't already define it, define it as 245.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
define|#
directive|define
name|DLT_PFSYNC
value|246
endif|#
directive|endif
comment|/*  * Raw InfiniBand packets, starting with the Local Routing Header.  *  * Requested by Oren Kladnitsky<orenk@mellanox.com>.  */
define|#
directive|define
name|DLT_INFINIBAND
value|247
comment|/*  * SCTP, with no lower-level protocols (i.e., no IPv4 or IPv6).  *  * Requested by Michael Tuexen<Michael.Tuexen@lurchi.franken.de>.  */
define|#
directive|define
name|DLT_SCTP
value|248
define|#
directive|define
name|DLT_MATCHING_MAX
value|248
comment|/* highest value in the "matching" range */
comment|/*  * DLT and savefile link type values are split into a class and  * a member of that class.  A class value of 0 indicates a regular  * DLT_/LINKTYPE_ value.  */
define|#
directive|define
name|DLT_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x03ff0000)
comment|/*  * NetBSD-specific generic "raw" link type.  The class value indicates  * that this is the generic raw type, and the lower 16 bits are the  * address family we're dealing with.  Those values are NetBSD-specific;  * do not assume that they correspond to AF_ values for your operating  * system.  */
define|#
directive|define
name|DLT_CLASS_NETBSD_RAWAF
value|0x02240000
define|#
directive|define
name|DLT_NETBSD_RAWAF
parameter_list|(
name|af
parameter_list|)
value|(DLT_CLASS_NETBSD_RAWAF | (af))
define|#
directive|define
name|DLT_NETBSD_RAWAF_AF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0000ffff)
define|#
directive|define
name|DLT_IS_NETBSD_RAWAF
parameter_list|(
name|x
parameter_list|)
value|(DLT_CLASS(x) == DLT_CLASS_NETBSD_RAWAF)
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
name|bpf_u_int32
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
specifier|const
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
specifier|const
name|struct
name|bpf_insn
modifier|*
parameter_list|,
specifier|const
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

begin_comment
comment|/* !defined(_NET_BPF_H_)&& !defined(_BPF_H_)&& !defined(_H_BPF)&& !defined(lib_pcap_bpf_h) */
end_comment

end_unit

