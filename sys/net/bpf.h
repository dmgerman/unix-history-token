begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence  * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)bpf.h	8.1 (Berkeley) 6/10/93  *	@(#)bpf.h	1.34 (LBL)     6/16/96  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_BPF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_BPF_H_
end_define

begin_comment
comment|/* BSD style release date */
end_comment

begin_define
define|#
directive|define
name|BPF_RELEASE
value|199606
end_define

begin_typedef
typedef|typedef
name|int32_t
name|bpf_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|bpf_u_int32
typedef|;
end_typedef

begin_comment
comment|/*  * Alignment macros.  BPF_WORDALIGN rounds up to the next  * even multiple of BPF_ALIGNMENT.  */
end_comment

begin_define
define|#
directive|define
name|BPF_ALIGNMENT
value|sizeof(long)
end_define

begin_define
define|#
directive|define
name|BPF_WORDALIGN
parameter_list|(
name|x
parameter_list|)
value|(((x)+(BPF_ALIGNMENT-1))&~(BPF_ALIGNMENT-1))
end_define

begin_define
define|#
directive|define
name|BPF_MAXINSNS
value|512
end_define

begin_define
define|#
directive|define
name|BPF_MAXBUFSIZE
value|0x80000
end_define

begin_define
define|#
directive|define
name|BPF_MINBUFSIZE
value|32
end_define

begin_comment
comment|/*  *  Structure for BIOCSETF.  */
end_comment

begin_struct
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
end_struct

begin_comment
comment|/*  * Struct returned by BIOCGSTATS.  */
end_comment

begin_struct
struct|struct
name|bpf_stat
block|{
name|u_int
name|bs_recv
decl_stmt|;
comment|/* number of packets received */
name|u_int
name|bs_drop
decl_stmt|;
comment|/* number of packets dropped */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Struct return by BIOCVERSION.  This represents the version number of  * the filter language described by the instruction encodings below.  * bpf understands a program iff kernel_major == filter_major&&  * kernel_minor>= filter_minor, that is, if the value returned by the  * running kernel has the same major number and a minor number equal  * equal to or less than the filter being downloaded.  Otherwise, the  * results are undefined, meaning an error may be returned or packets  * may be accepted haphazardly.  * It has nothing to do with the source code version.  */
end_comment

begin_struct
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
end_struct

begin_comment
comment|/* Current version number of filter architecture. */
end_comment

begin_define
define|#
directive|define
name|BPF_MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|BPF_MINOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|BIOCGBLEN
value|_IOR('B',102, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSBLEN
value|_IOWR('B',102, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSETF
value|_IOW('B',103, struct bpf_program)
end_define

begin_define
define|#
directive|define
name|BIOCFLUSH
value|_IO('B',104)
end_define

begin_define
define|#
directive|define
name|BIOCPROMISC
value|_IO('B',105)
end_define

begin_define
define|#
directive|define
name|BIOCGDLT
value|_IOR('B',106, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGETIF
value|_IOR('B',107, struct ifreq)
end_define

begin_define
define|#
directive|define
name|BIOCSETIF
value|_IOW('B',108, struct ifreq)
end_define

begin_define
define|#
directive|define
name|BIOCSRTIMEOUT
value|_IOW('B',109, struct timeval)
end_define

begin_define
define|#
directive|define
name|BIOCGRTIMEOUT
value|_IOR('B',110, struct timeval)
end_define

begin_define
define|#
directive|define
name|BIOCGSTATS
value|_IOR('B',111, struct bpf_stat)
end_define

begin_define
define|#
directive|define
name|BIOCIMMEDIATE
value|_IOW('B',112, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCVERSION
value|_IOR('B',113, struct bpf_version)
end_define

begin_define
define|#
directive|define
name|BIOCGRSIG
value|_IOR('B',114, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSRSIG
value|_IOW('B',115, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGHDRCMPLT
value|_IOR('B',116, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSHDRCMPLT
value|_IOW('B',117, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGSEESENT
value|_IOR('B',118, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSSEESENT
value|_IOW('B',119, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSDLT
value|_IOW('B',120, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGDLTLIST
value|_IOWR('B',121, struct bpf_dltlist)
end_define

begin_comment
comment|/*  * Structure prepended to each packet.  */
end_comment

begin_struct
struct|struct
name|bpf_hdr
block|{
name|struct
name|timeval
name|bh_tstamp
decl_stmt|;
comment|/* time stamp */
name|bpf_u_int32
name|bh_caplen
decl_stmt|;
comment|/* length of captured portion */
name|bpf_u_int32
name|bh_datalen
decl_stmt|;
comment|/* original length of packet */
name|u_short
name|bh_hdrlen
decl_stmt|;
comment|/* length of bpf header (this struct 					   plus alignment padding) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Because the structure above is not a multiple of 4 bytes, some compilers  * will insist on inserting padding; hence, sizeof(struct bpf_hdr) won't work.  * Only the kernel needs to know about it; applications use bh_hdrlen.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_BPF_HDR
value|(sizeof(struct bpf_hdr)<= 20 ? 18 : \     sizeof(struct bpf_hdr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Data-link level type codes.  */
end_comment

begin_define
define|#
directive|define
name|DLT_NULL
value|0
end_define

begin_comment
comment|/* no link-layer encapsulation */
end_comment

begin_define
define|#
directive|define
name|DLT_EN10MB
value|1
end_define

begin_comment
comment|/* Ethernet (10Mb) */
end_comment

begin_define
define|#
directive|define
name|DLT_EN3MB
value|2
end_define

begin_comment
comment|/* Experimental Ethernet (3Mb) */
end_comment

begin_define
define|#
directive|define
name|DLT_AX25
value|3
end_define

begin_comment
comment|/* Amateur Radio AX.25 */
end_comment

begin_define
define|#
directive|define
name|DLT_PRONET
value|4
end_define

begin_comment
comment|/* Proteon ProNET Token Ring */
end_comment

begin_define
define|#
directive|define
name|DLT_CHAOS
value|5
end_define

begin_comment
comment|/* Chaos */
end_comment

begin_define
define|#
directive|define
name|DLT_IEEE802
value|6
end_define

begin_comment
comment|/* IEEE 802 Networks */
end_comment

begin_define
define|#
directive|define
name|DLT_ARCNET
value|7
end_define

begin_comment
comment|/* ARCNET */
end_comment

begin_define
define|#
directive|define
name|DLT_SLIP
value|8
end_define

begin_comment
comment|/* Serial Line IP */
end_comment

begin_define
define|#
directive|define
name|DLT_PPP
value|9
end_define

begin_comment
comment|/* Point-to-point Protocol */
end_comment

begin_define
define|#
directive|define
name|DLT_FDDI
value|10
end_define

begin_comment
comment|/* FDDI */
end_comment

begin_define
define|#
directive|define
name|DLT_ATM_RFC1483
value|11
end_define

begin_comment
comment|/* LLC/SNAP encapsulated atm */
end_comment

begin_define
define|#
directive|define
name|DLT_RAW
value|12
end_define

begin_comment
comment|/* raw IP */
end_comment

begin_comment
comment|/*  * These are values from BSD/OS's "bpf.h".  * These are not the same as the values from the traditional libpcap  * "bpf.h"; however, these values shouldn't be generated by any  * OS other than BSD/OS, so the correct values to use here are the  * BSD/OS values.  *  * Platforms that have already assigned these values to other  * DLT_ codes, however, should give these codes the values  * from that platform, so that programs that use these codes will  * continue to compile - even though they won't correctly read  * files of these types.  */
end_comment

begin_define
define|#
directive|define
name|DLT_SLIP_BSDOS
value|15
end_define

begin_comment
comment|/* BSD/OS Serial Line IP */
end_comment

begin_define
define|#
directive|define
name|DLT_PPP_BSDOS
value|16
end_define

begin_comment
comment|/* BSD/OS Point-to-point Protocol */
end_comment

begin_define
define|#
directive|define
name|DLT_ATM_CLIP
value|19
end_define

begin_comment
comment|/* Linux Classical-IP over ATM */
end_comment

begin_comment
comment|/*  * These values are defined by NetBSD; other platforms should refrain from  * using them for other purposes, so that NetBSD savefiles with link  * types of 50 or 51 can be read as this type on all platforms.  */
end_comment

begin_define
define|#
directive|define
name|DLT_PPP_SERIAL
value|50
end_define

begin_comment
comment|/* PPP over serial with HDLC encapsulation */
end_comment

begin_define
define|#
directive|define
name|DLT_PPP_ETHER
value|51
end_define

begin_comment
comment|/* PPP over Ethernet */
end_comment

begin_comment
comment|/*  * This value was defined by libpcap 0.5; platforms that have defined  * it with a different value should define it here with that value -  * a link type of 104 in a save file will be mapped to DLT_C_HDLC,  * whatever value that happens to be, so programs will correctly  * handle files with that link type regardless of the value of  * DLT_C_HDLC.  *  * The name DLT_C_HDLC was used by BSD/OS; we use that name for source  * compatibility with programs written for BSD/OS.  *  * libpcap 0.5 defined it as DLT_CHDLC; we define DLT_CHDLC as well,  * for source compatibility with programs written for libpcap 0.5.  */
end_comment

begin_define
define|#
directive|define
name|DLT_C_HDLC
value|104
end_define

begin_comment
comment|/* Cisco HDLC */
end_comment

begin_define
define|#
directive|define
name|DLT_CHDLC
value|DLT_C_HDLC
end_define

begin_define
define|#
directive|define
name|DLT_IEEE802_11
value|105
end_define

begin_comment
comment|/* IEEE 802.11 wireless */
end_comment

begin_comment
comment|/*  * Values between 106 and 107 are used in capture file headers as  * link-layer types corresponding to DLT_ types that might differ  * between platforms; don't use those values for new DLT_ new types.  */
end_comment

begin_comment
comment|/*  * Frame Relay; BSD/OS has a DLT_FR with a value of 11, but that collides  * with other values.  * DLT_FR and DLT_FRELAY packets start with the Q.922 Frame Relay header  * (DLCI, etc.).  */
end_comment

begin_define
define|#
directive|define
name|DLT_FRELAY
value|107
end_define

begin_comment
comment|/*  * OpenBSD DLT_LOOP, for loopback devices; it's like DLT_NULL, except  * that the AF_ type in the link-layer header is in network byte order.  *  * OpenBSD defines it as 12, but that collides with DLT_RAW, so we  * define it as 108 here.  If OpenBSD picks up this file, it should  * define DLT_LOOP as 12 in its version, as per the comment above -  * and should not use 108 as a DLT_ value.  */
end_comment

begin_define
define|#
directive|define
name|DLT_LOOP
value|108
end_define

begin_comment
comment|/*  * Values between 109 and 112 are used in capture file headers as  * link-layer types corresponding to DLT_ types that might differ  * between platforms; don't use those values for new DLT_ new types.  */
end_comment

begin_comment
comment|/*  * Encapsulated packets for IPsec; DLT_ENC is 13 in OpenBSD, but that's  * DLT_SLIP_BSDOS in NetBSD, so we don't use 13 for it in OSes other  * than OpenBSD.  */
end_comment

begin_define
define|#
directive|define
name|DLT_ENC
value|109
end_define

begin_comment
comment|/*  * This is for Linux cooked sockets.  */
end_comment

begin_define
define|#
directive|define
name|DLT_LINUX_SLL
value|113
end_define

begin_comment
comment|/*  * Apple LocalTalk hardware.  */
end_comment

begin_define
define|#
directive|define
name|DLT_LTALK
value|114
end_define

begin_comment
comment|/*  * Acorn Econet.  */
end_comment

begin_define
define|#
directive|define
name|DLT_ECONET
value|115
end_define

begin_comment
comment|/*  * Reserved for use with OpenBSD ipfilter.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IPFILTER
value|116
end_define

begin_comment
comment|/*  * Reserved for use in capture-file headers as a link-layer type  * corresponding to OpenBSD DLT_PFLOG; DLT_PFLOG is 17 in OpenBSD,  * but that's DLT_LANE8023 in SuSE 6.3, so we can't use 17 for it  * in capture-file headers.  */
end_comment

begin_define
define|#
directive|define
name|DLT_PFLOG
value|117
end_define

begin_comment
comment|/*  * Registered for Cisco-internal use.  */
end_comment

begin_define
define|#
directive|define
name|DLT_CISCO_IOS
value|118
end_define

begin_comment
comment|/*  * Reserved for 802.11 cards using the Prism II chips, with a link-layer  * header including Prism monitor mode information plus an 802.11  * header.  */
end_comment

begin_define
define|#
directive|define
name|DLT_PRISM_HEADER
value|119
end_define

begin_comment
comment|/*  * Reserved for Aironet 802.11 cards, with an Aironet link-layer header  * (see Doug Ambrisko's FreeBSD patches).  */
end_comment

begin_define
define|#
directive|define
name|DLT_AIRONET_HEADER
value|120
end_define

begin_comment
comment|/*  * Reserved for use by OpenBSD's pfsync device.  */
end_comment

begin_define
define|#
directive|define
name|DLT_PFSYNC
value|121
end_define

begin_comment
comment|/*  * Reserved for RFC 2625 IP-over-Fibre Channel.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IP_OVER_FC
value|122
end_define

begin_comment
comment|/*  * Reserved for Full Frontal ATM on Solaris.  */
end_comment

begin_define
define|#
directive|define
name|DLT_SUNATM
value|123
end_define

begin_comment
comment|/*  * BSD header for 802.11 plus a number of bits of link-layer information  * including radio information.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DLT_IEEE802_11_RADIO
end_ifndef

begin_define
define|#
directive|define
name|DLT_IEEE802_11_RADIO
value|127
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Reserved for Linux ARCNET.  */
end_comment

begin_define
define|#
directive|define
name|DLT_ARCNET_LINUX
value|129
end_define

begin_comment
comment|/*  * Reserved for Apple IP-over-IEEE-1394.  */
end_comment

begin_define
define|#
directive|define
name|DLT_APPLE_IP_OVER_IEEE1394
value|138
end_define

begin_comment
comment|/*  * Reserved for Linux IrDA.  */
end_comment

begin_define
define|#
directive|define
name|DLT_LINUX_IRDA
value|144
end_define

begin_comment
comment|/*  * Reserved for AbsoluteValue Systems 802.11 capture.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IEEE802_11_RADIO_AVS
value|163
end_define

begin_comment
comment|/*  * The instruction encodings.  */
end_comment

begin_comment
comment|/* instruction classes */
end_comment

begin_define
define|#
directive|define
name|BPF_CLASS
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x07)
end_define

begin_define
define|#
directive|define
name|BPF_LD
value|0x00
end_define

begin_define
define|#
directive|define
name|BPF_LDX
value|0x01
end_define

begin_define
define|#
directive|define
name|BPF_ST
value|0x02
end_define

begin_define
define|#
directive|define
name|BPF_STX
value|0x03
end_define

begin_define
define|#
directive|define
name|BPF_ALU
value|0x04
end_define

begin_define
define|#
directive|define
name|BPF_JMP
value|0x05
end_define

begin_define
define|#
directive|define
name|BPF_RET
value|0x06
end_define

begin_define
define|#
directive|define
name|BPF_MISC
value|0x07
end_define

begin_comment
comment|/* ld/ldx fields */
end_comment

begin_define
define|#
directive|define
name|BPF_SIZE
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x18)
end_define

begin_define
define|#
directive|define
name|BPF_W
value|0x00
end_define

begin_define
define|#
directive|define
name|BPF_H
value|0x08
end_define

begin_define
define|#
directive|define
name|BPF_B
value|0x10
end_define

begin_define
define|#
directive|define
name|BPF_MODE
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xe0)
end_define

begin_define
define|#
directive|define
name|BPF_IMM
value|0x00
end_define

begin_define
define|#
directive|define
name|BPF_ABS
value|0x20
end_define

begin_define
define|#
directive|define
name|BPF_IND
value|0x40
end_define

begin_define
define|#
directive|define
name|BPF_MEM
value|0x60
end_define

begin_define
define|#
directive|define
name|BPF_LEN
value|0x80
end_define

begin_define
define|#
directive|define
name|BPF_MSH
value|0xa0
end_define

begin_comment
comment|/* alu/jmp fields */
end_comment

begin_define
define|#
directive|define
name|BPF_OP
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xf0)
end_define

begin_define
define|#
directive|define
name|BPF_ADD
value|0x00
end_define

begin_define
define|#
directive|define
name|BPF_SUB
value|0x10
end_define

begin_define
define|#
directive|define
name|BPF_MUL
value|0x20
end_define

begin_define
define|#
directive|define
name|BPF_DIV
value|0x30
end_define

begin_define
define|#
directive|define
name|BPF_OR
value|0x40
end_define

begin_define
define|#
directive|define
name|BPF_AND
value|0x50
end_define

begin_define
define|#
directive|define
name|BPF_LSH
value|0x60
end_define

begin_define
define|#
directive|define
name|BPF_RSH
value|0x70
end_define

begin_define
define|#
directive|define
name|BPF_NEG
value|0x80
end_define

begin_define
define|#
directive|define
name|BPF_JA
value|0x00
end_define

begin_define
define|#
directive|define
name|BPF_JEQ
value|0x10
end_define

begin_define
define|#
directive|define
name|BPF_JGT
value|0x20
end_define

begin_define
define|#
directive|define
name|BPF_JGE
value|0x30
end_define

begin_define
define|#
directive|define
name|BPF_JSET
value|0x40
end_define

begin_define
define|#
directive|define
name|BPF_SRC
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x08)
end_define

begin_define
define|#
directive|define
name|BPF_K
value|0x00
end_define

begin_define
define|#
directive|define
name|BPF_X
value|0x08
end_define

begin_comment
comment|/* ret - BPF_K and BPF_X also apply */
end_comment

begin_define
define|#
directive|define
name|BPF_RVAL
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x18)
end_define

begin_define
define|#
directive|define
name|BPF_A
value|0x10
end_define

begin_comment
comment|/* misc */
end_comment

begin_define
define|#
directive|define
name|BPF_MISCOP
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xf8)
end_define

begin_define
define|#
directive|define
name|BPF_TAX
value|0x00
end_define

begin_define
define|#
directive|define
name|BPF_TXA
value|0x80
end_define

begin_comment
comment|/*  * The instruction data structure.  */
end_comment

begin_struct
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
end_struct

begin_comment
comment|/*  * Macros for insn array initializers.  */
end_comment

begin_define
define|#
directive|define
name|BPF_STMT
parameter_list|(
name|code
parameter_list|,
name|k
parameter_list|)
value|{ (u_short)(code), 0, 0, k }
end_define

begin_define
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
end_define

begin_comment
comment|/*  * Structure to retrieve available DLTs for the interface.  */
end_comment

begin_struct
struct|struct
name|bpf_dltlist
block|{
name|u_int
name|bfl_len
decl_stmt|;
comment|/* number of bfd_list array */
name|u_int
modifier|*
name|bfl_list
decl_stmt|;
comment|/* array of DLTs */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|bpf_if
struct_decl|;
end_struct_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|void
name|bpf_tap
parameter_list|(
name|struct
name|bpf_if
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpf_mtap
parameter_list|(
name|struct
name|bpf_if
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpf_mtap2
parameter_list|(
name|struct
name|bpf_if
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpfattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpfattach2
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|bpf_if
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpfdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpfilterattach
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|bpf_filter
parameter_list|(
specifier|const
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
end_function_decl

begin_define
define|#
directive|define
name|BPF_TAP
parameter_list|(
name|_ifp
parameter_list|,
name|_pkt
parameter_list|,
name|_pktlen
parameter_list|)
value|do {				\ 	if ((_ifp)->if_bpf)					\ 		bpf_tap((_ifp)->if_bpf, (_pkt), (_pktlen));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|BPF_MTAP
parameter_list|(
name|_ifp
parameter_list|,
name|_m
parameter_list|)
value|do {					\ 	if ((_ifp)->if_bpf) {					\ 		M_ASSERTVALID(_m);				\ 		bpf_mtap((_ifp)->if_bpf, (_m));			\ 	}							\ } while (0)
end_define

begin_define
define|#
directive|define
name|BPF_MTAP2
parameter_list|(
name|_ifp
parameter_list|,
name|_data
parameter_list|,
name|_dlen
parameter_list|,
name|_m
parameter_list|)
value|do {			\ 	if ((_ifp)->if_bpf) {					\ 		M_ASSERTVALID(_m);				\ 		bpf_mtap2((_ifp)->if_bpf,(_data),(_dlen),(_m));	\ 	}							\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Number of scratch memory words (for BPF_LD|BPF_MEM and BPF_ST).  */
end_comment

begin_define
define|#
directive|define
name|BPF_MEMWORDS
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_BPF_H_ */
end_comment

end_unit

