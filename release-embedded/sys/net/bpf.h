begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence  * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)bpf.h	8.1 (Berkeley) 6/10/93  *	@(#)bpf.h	1.34 (LBL)     6/16/96  *  * $FreeBSD$  */
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

begin_typedef
typedef|typedef
name|int64_t
name|bpf_int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int64_t
name|bpf_u_int64
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

begin_comment
comment|/*  * Historically, BPF has supported a single buffering model, first using mbuf  * clusters in kernel, and later using malloc(9) buffers in kernel.  We now  * support multiple buffering modes, which may be queried and set using  * BIOCGETBUFMODE and BIOCSETBUFMODE.  So as to avoid handling the complexity  * of changing modes while sniffing packets, the mode becomes fixed once an  * interface has been attached to the BPF descriptor.  */
end_comment

begin_define
define|#
directive|define
name|BPF_BUFMODE_BUFFER
value|1
end_define

begin_comment
comment|/* Kernel buffers with read(). */
end_comment

begin_define
define|#
directive|define
name|BPF_BUFMODE_ZBUF
value|2
end_define

begin_comment
comment|/* Zero-copy buffers. */
end_comment

begin_comment
comment|/*-  * Struct used by BIOCSETZBUF, BIOCROTZBUF: describes up to two zero-copy  * buffer as used by BPF.  */
end_comment

begin_struct
struct|struct
name|bpf_zbuf
block|{
name|void
modifier|*
name|bz_bufa
decl_stmt|;
comment|/* Location of 'a' zero-copy buffer. */
name|void
modifier|*
name|bz_bufb
decl_stmt|;
comment|/* Location of 'b' zero-copy buffer. */
name|size_t
name|bz_buflen
decl_stmt|;
comment|/* Size of zero-copy buffers. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIOCGBLEN
value|_IOR('B', 102, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSBLEN
value|_IOWR('B', 102, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSETF
value|_IOW('B', 103, struct bpf_program)
end_define

begin_define
define|#
directive|define
name|BIOCFLUSH
value|_IO('B', 104)
end_define

begin_define
define|#
directive|define
name|BIOCPROMISC
value|_IO('B', 105)
end_define

begin_define
define|#
directive|define
name|BIOCGDLT
value|_IOR('B', 106, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGETIF
value|_IOR('B', 107, struct ifreq)
end_define

begin_define
define|#
directive|define
name|BIOCSETIF
value|_IOW('B', 108, struct ifreq)
end_define

begin_define
define|#
directive|define
name|BIOCSRTIMEOUT
value|_IOW('B', 109, struct timeval)
end_define

begin_define
define|#
directive|define
name|BIOCGRTIMEOUT
value|_IOR('B', 110, struct timeval)
end_define

begin_define
define|#
directive|define
name|BIOCGSTATS
value|_IOR('B', 111, struct bpf_stat)
end_define

begin_define
define|#
directive|define
name|BIOCIMMEDIATE
value|_IOW('B', 112, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCVERSION
value|_IOR('B', 113, struct bpf_version)
end_define

begin_define
define|#
directive|define
name|BIOCGRSIG
value|_IOR('B', 114, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSRSIG
value|_IOW('B', 115, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGHDRCMPLT
value|_IOR('B', 116, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSHDRCMPLT
value|_IOW('B', 117, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGDIRECTION
value|_IOR('B', 118, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSDIRECTION
value|_IOW('B', 119, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSDLT
value|_IOW('B', 120, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGDLTLIST
value|_IOWR('B', 121, struct bpf_dltlist)
end_define

begin_define
define|#
directive|define
name|BIOCLOCK
value|_IO('B', 122)
end_define

begin_define
define|#
directive|define
name|BIOCSETWF
value|_IOW('B', 123, struct bpf_program)
end_define

begin_define
define|#
directive|define
name|BIOCFEEDBACK
value|_IOW('B', 124, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGETBUFMODE
value|_IOR('B', 125, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSETBUFMODE
value|_IOW('B', 126, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGETZMAX
value|_IOR('B', 127, size_t)
end_define

begin_define
define|#
directive|define
name|BIOCROTZBUF
value|_IOR('B', 128, struct bpf_zbuf)
end_define

begin_define
define|#
directive|define
name|BIOCSETZBUF
value|_IOW('B', 129, struct bpf_zbuf)
end_define

begin_define
define|#
directive|define
name|BIOCSETFNR
value|_IOW('B', 130, struct bpf_program)
end_define

begin_define
define|#
directive|define
name|BIOCGTSTAMP
value|_IOR('B', 131, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSTSTAMP
value|_IOW('B', 132, u_int)
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|BIOCGSEESENT
value|BIOCGDIRECTION
end_define

begin_define
define|#
directive|define
name|BIOCSSEESENT
value|BIOCSDIRECTION
end_define

begin_comment
comment|/* Packet directions */
end_comment

begin_enum
enum|enum
name|bpf_direction
block|{
name|BPF_D_IN
block|,
comment|/* See incoming packets */
name|BPF_D_INOUT
block|,
comment|/* See incoming and outgoing packets */
name|BPF_D_OUT
comment|/* See outgoing packets */
block|}
enum|;
end_enum

begin_comment
comment|/* Time stamping functions */
end_comment

begin_define
define|#
directive|define
name|BPF_T_MICROTIME
value|0x0000
end_define

begin_define
define|#
directive|define
name|BPF_T_NANOTIME
value|0x0001
end_define

begin_define
define|#
directive|define
name|BPF_T_BINTIME
value|0x0002
end_define

begin_define
define|#
directive|define
name|BPF_T_NONE
value|0x0003
end_define

begin_define
define|#
directive|define
name|BPF_T_FORMAT_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|BPF_T_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|BPF_T_FAST
value|0x0100
end_define

begin_define
define|#
directive|define
name|BPF_T_MONOTONIC
value|0x0200
end_define

begin_define
define|#
directive|define
name|BPF_T_MONOTONIC_FAST
value|(BPF_T_FAST | BPF_T_MONOTONIC)
end_define

begin_define
define|#
directive|define
name|BPF_T_FLAG_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|BPF_T_FORMAT
parameter_list|(
name|t
parameter_list|)
value|((t)& BPF_T_FORMAT_MASK)
end_define

begin_define
define|#
directive|define
name|BPF_T_FLAG
parameter_list|(
name|t
parameter_list|)
value|((t)& BPF_T_FLAG_MASK)
end_define

begin_define
define|#
directive|define
name|BPF_T_VALID
parameter_list|(
name|t
parameter_list|)
define|\
value|((t) == BPF_T_NONE || (BPF_T_FORMAT(t) != BPF_T_NONE&&	\     ((t)& ~(BPF_T_FORMAT_MASK | BPF_T_FLAG_MASK)) == 0))
end_define

begin_define
define|#
directive|define
name|BPF_T_MICROTIME_FAST
value|(BPF_T_MICROTIME | BPF_T_FAST)
end_define

begin_define
define|#
directive|define
name|BPF_T_NANOTIME_FAST
value|(BPF_T_NANOTIME | BPF_T_FAST)
end_define

begin_define
define|#
directive|define
name|BPF_T_BINTIME_FAST
value|(BPF_T_BINTIME | BPF_T_FAST)
end_define

begin_define
define|#
directive|define
name|BPF_T_MICROTIME_MONOTONIC
value|(BPF_T_MICROTIME | BPF_T_MONOTONIC)
end_define

begin_define
define|#
directive|define
name|BPF_T_NANOTIME_MONOTONIC
value|(BPF_T_NANOTIME | BPF_T_MONOTONIC)
end_define

begin_define
define|#
directive|define
name|BPF_T_BINTIME_MONOTONIC
value|(BPF_T_BINTIME | BPF_T_MONOTONIC)
end_define

begin_define
define|#
directive|define
name|BPF_T_MICROTIME_MONOTONIC_FAST
value|(BPF_T_MICROTIME | BPF_T_MONOTONIC_FAST)
end_define

begin_define
define|#
directive|define
name|BPF_T_NANOTIME_MONOTONIC_FAST
value|(BPF_T_NANOTIME | BPF_T_MONOTONIC_FAST)
end_define

begin_define
define|#
directive|define
name|BPF_T_BINTIME_MONOTONIC_FAST
value|(BPF_T_BINTIME | BPF_T_MONOTONIC_FAST)
end_define

begin_comment
comment|/*  * Structure prepended to each packet.  */
end_comment

begin_struct
struct|struct
name|bpf_ts
block|{
name|bpf_int64
name|bt_sec
decl_stmt|;
comment|/* seconds */
name|bpf_u_int64
name|bt_frac
decl_stmt|;
comment|/* fraction */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bpf_xhdr
block|{
name|struct
name|bpf_ts
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
comment|/* Obsolete */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MTAG_BPF
value|0x627066
end_define

begin_define
define|#
directive|define
name|MTAG_BPF_TIMESTAMP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * When using zero-copy BPF buffers, a shared memory header is present  * allowing the kernel BPF implementation and user process to synchronize  * without using system calls.  This structure defines that header.  When  * accessing these fields, appropriate atomic operation and memory barriers  * are required in order not to see stale or out-of-order data; see bpf(4)  * for reference code to access these fields from userspace.  *  * The layout of this structure is critical, and must not be changed; if must  * fit in a single page on all architectures.  */
end_comment

begin_struct
struct|struct
name|bpf_zbuf_header
block|{
specifier|volatile
name|u_int
name|bzh_kernel_gen
decl_stmt|;
comment|/* Kernel generation number. */
specifier|volatile
name|u_int
name|bzh_kernel_len
decl_stmt|;
comment|/* Length of data in the buffer. */
specifier|volatile
name|u_int
name|bzh_user_gen
decl_stmt|;
comment|/* User generation number. */
name|u_int
name|_bzh_pad
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* BSD loopback encapsulation */
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
comment|/*  * Reserved for the Symantec Enterprise Firewall.  */
end_comment

begin_define
define|#
directive|define
name|DLT_SYMANTEC_FIREWALL
value|99
end_define

begin_comment
comment|/*  * Values between 100 and 103 are used in capture file headers as  * link-layer header type LINKTYPE_ values corresponding to DLT_ types  * that differ between platforms; don't use those values for new DLT_  * new types.  */
end_comment

begin_comment
comment|/*  * Values starting with 104 are used for newly-assigned link-layer  * header type values; for those link-layer header types, the DLT_  * value returned by pcap_datalink() and passed to pcap_open_dead(),  * and the LINKTYPE_ value that appears in capture files, are the  * same.  *  * DLT_MATCHING_MIN is the lowest such value; DLT_MATCHING_MAX is  * the highest such value.  */
end_comment

begin_define
define|#
directive|define
name|DLT_MATCHING_MIN
value|104
end_define

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
comment|/*  * Reserved for Siemens HiPath HDLC. XXX  */
end_comment

begin_define
define|#
directive|define
name|DLT_HHDLC
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
comment|/*  * Reserved as per request from Kent Dahlgren<kent@praesum.com>  * for private use.  */
end_comment

begin_define
define|#
directive|define
name|DLT_RIO
value|124
end_define

begin_comment
comment|/* RapidIO */
end_comment

begin_define
define|#
directive|define
name|DLT_PCI_EXP
value|125
end_define

begin_comment
comment|/* PCI Express */
end_comment

begin_define
define|#
directive|define
name|DLT_AURORA
value|126
end_define

begin_comment
comment|/* Xilinx Aurora link layer */
end_comment

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
comment|/*  * Reserved for TZSP encapsulation.  */
end_comment

begin_define
define|#
directive|define
name|DLT_TZSP
value|128
end_define

begin_comment
comment|/* Tazmen Sniffer Protocol */
end_comment

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
comment|/*  * Juniper-private data link types.  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_MLPPP
value|130
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_MLFR
value|131
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_ES
value|132
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_GGSN
value|133
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_MFR
value|134
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_ATM2
value|135
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_SERVICES
value|136
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_ATM1
value|137
end_define

begin_comment
comment|/*  * Apple IP-over-IEEE 1394, as per a request from Dieter Siegmund  *<dieter@apple.com>.  The header that's presented is an Ethernet-like  * header:  *  *	#define FIREWIRE_EUI64_LEN	8  *	struct firewire_header {  *		u_char  firewire_dhost[FIREWIRE_EUI64_LEN];  *		u_char  firewire_shost[FIREWIRE_EUI64_LEN];  *		u_short firewire_type;  *	};  *  * with "firewire_type" being an Ethernet type value, rather than,  * for example, raw GASP frames being handed up.  */
end_comment

begin_define
define|#
directive|define
name|DLT_APPLE_IP_OVER_IEEE1394
value|138
end_define

begin_comment
comment|/*  * Various SS7 encapsulations, as per a request from Jeff Morriss  *<jeff.morriss[AT]ulticom.com> and subsequent discussions.  */
end_comment

begin_define
define|#
directive|define
name|DLT_MTP2_WITH_PHDR
value|139
end_define

begin_comment
comment|/* pseudo-header with various info, followed by MTP2 */
end_comment

begin_define
define|#
directive|define
name|DLT_MTP2
value|140
end_define

begin_comment
comment|/* MTP2, without pseudo-header */
end_comment

begin_define
define|#
directive|define
name|DLT_MTP3
value|141
end_define

begin_comment
comment|/* MTP3, without pseudo-header or MTP2 */
end_comment

begin_define
define|#
directive|define
name|DLT_SCCP
value|142
end_define

begin_comment
comment|/* SCCP, without pseudo-header or MTP2 or MTP3 */
end_comment

begin_comment
comment|/*  * Reserved for DOCSIS.  */
end_comment

begin_define
define|#
directive|define
name|DLT_DOCSIS
value|143
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
comment|/*  * Reserved for IBM SP switch and IBM Next Federation switch.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IBM_SP
value|145
end_define

begin_define
define|#
directive|define
name|DLT_IBM_SN
value|146
end_define

begin_comment
comment|/*  * Reserved for private use.  If you have some link-layer header type  * that you want to use within your organization, with the capture files  * using that link-layer header type not ever be sent outside your  * organization, you can use these values.  *  * No libpcap release will use these for any purpose, nor will any  * tcpdump release use them, either.  *  * Do *NOT* use these in capture files that you expect anybody not using  * your private versions of capture-file-reading tools to read; in  * particular, do *NOT* use them in products, otherwise you may find that  * people won't be able to use tcpdump, or snort, or Ethereal, or... to  * read capture files from your firewall/intrusion detection/traffic  * monitoring/etc. appliance, or whatever product uses that DLT_ value,  * and you may also find that the developers of those applications will  * not accept patches to let them read those files.  *  * Also, do not use them if somebody might send you a capture using them  * for *their* private type and tools using them for *your* private type  * would have to read them.  *  * Instead, ask "tcpdump-workers@tcpdump.org" for a new DLT_ value,  * as per the comment above, and use the type you're given.  */
end_comment

begin_define
define|#
directive|define
name|DLT_USER0
value|147
end_define

begin_define
define|#
directive|define
name|DLT_USER1
value|148
end_define

begin_define
define|#
directive|define
name|DLT_USER2
value|149
end_define

begin_define
define|#
directive|define
name|DLT_USER3
value|150
end_define

begin_define
define|#
directive|define
name|DLT_USER4
value|151
end_define

begin_define
define|#
directive|define
name|DLT_USER5
value|152
end_define

begin_define
define|#
directive|define
name|DLT_USER6
value|153
end_define

begin_define
define|#
directive|define
name|DLT_USER7
value|154
end_define

begin_define
define|#
directive|define
name|DLT_USER8
value|155
end_define

begin_define
define|#
directive|define
name|DLT_USER9
value|156
end_define

begin_define
define|#
directive|define
name|DLT_USER10
value|157
end_define

begin_define
define|#
directive|define
name|DLT_USER11
value|158
end_define

begin_define
define|#
directive|define
name|DLT_USER12
value|159
end_define

begin_define
define|#
directive|define
name|DLT_USER13
value|160
end_define

begin_define
define|#
directive|define
name|DLT_USER14
value|161
end_define

begin_define
define|#
directive|define
name|DLT_USER15
value|162
end_define

begin_comment
comment|/*  * For future use with 802.11 captures - defined by AbsoluteValue  * Systems to store a number of bits of link-layer information  * including radio information:  *  *	http://www.shaftnet.org/~pizza/software/capturefrm.txt  *  * but it might be used by some non-AVS drivers now or in the  * future.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IEEE802_11_RADIO_AVS
value|163
end_define

begin_comment
comment|/* 802.11 plus AVS radio header */
end_comment

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  The DLT_s are used  * for passing on chassis-internal metainformation such as  * QOS profiles, etc..  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_MONITOR
value|164
end_define

begin_comment
comment|/*  * Reserved for BACnet MS/TP.  */
end_comment

begin_define
define|#
directive|define
name|DLT_BACNET_MS_TP
value|165
end_define

begin_comment
comment|/*  * Another PPP variant as per request from Karsten Keil<kkeil@suse.de>.  *  * This is used in some OSes to allow a kernel socket filter to distinguish  * between incoming and outgoing packets, on a socket intended to  * supply pppd with outgoing packets so it can do dial-on-demand and  * hangup-on-lack-of-demand; incoming packets are filtered out so they  * don't cause pppd to hold the connection up (you don't want random  * input packets such as port scans, packets from old lost connections,  * etc. to force the connection to stay up).  *  * The first byte of the PPP header (0xff03) is modified to accomodate  * the direction - 0x00 = IN, 0x01 = OUT.  */
end_comment

begin_define
define|#
directive|define
name|DLT_PPP_PPPD
value|166
end_define

begin_comment
comment|/*  * Names for backwards compatibility with older versions of some PPP  * software; new software should use DLT_PPP_PPPD.  */
end_comment

begin_define
define|#
directive|define
name|DLT_PPP_WITH_DIRECTION
value|DLT_PPP_PPPD
end_define

begin_define
define|#
directive|define
name|DLT_LINUX_PPP_WITHDIRECTION
value|DLT_PPP_PPPD
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  The DLT_s are used  * for passing on chassis-internal metainformation such as  * QOS profiles, cookies, etc..  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_PPPOE
value|167
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_PPPOE_ATM
value|168
end_define

begin_define
define|#
directive|define
name|DLT_GPRS_LLC
value|169
end_define

begin_comment
comment|/* GPRS LLC */
end_comment

begin_define
define|#
directive|define
name|DLT_GPF_T
value|170
end_define

begin_comment
comment|/* GPF-T (ITU-T G.7041/Y.1303) */
end_comment

begin_define
define|#
directive|define
name|DLT_GPF_F
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
name|DLT_GCOM_T1E1
value|172
end_define

begin_define
define|#
directive|define
name|DLT_GCOM_SERIAL
value|173
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  The DLT_ is used  * for internal communication to Physical Interface Cards (PIC)  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_PIC_PEER
value|174
end_define

begin_comment
comment|/*  * Link types requested by Gregor Maier<gregor@endace.com> of Endace  * Measurement Systems.  They add an ERF header (see  * http://www.endace.com/support/EndaceRecordFormat.pdf) in front of  * the link-layer header.  */
end_comment

begin_define
define|#
directive|define
name|DLT_ERF_ETH
value|175
end_define

begin_comment
comment|/* Ethernet */
end_comment

begin_define
define|#
directive|define
name|DLT_ERF_POS
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
name|DLT_LINUX_LAPD
value|177
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  * The DLT_ are used for prepending meta-information  * like interface index, interface name  * before standard Ethernet, PPP, Frelay& C-HDLC Frames  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_ETHER
value|178
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_PPP
value|179
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_FRELAY
value|180
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_CHDLC
value|181
end_define

begin_comment
comment|/*  * Multi Link Frame Relay (FRF.16)  */
end_comment

begin_define
define|#
directive|define
name|DLT_MFR
value|182
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  * The DLT_ is used for internal communication with a  * voice Adapter Card (PIC)  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_VP
value|183
end_define

begin_comment
comment|/*  * Arinc 429 frames.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  * Every frame contains a 32bit A429 label.  * More documentation on Arinc 429 can be found at  * http://www.condoreng.com/support/downloads/tutorials/ARINCTutorial.pdf  */
end_comment

begin_define
define|#
directive|define
name|DLT_A429
value|184
end_define

begin_comment
comment|/*  * Arinc 653 Interpartition Communication messages.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  * Please refer to the A653-1 standard for more information.  */
end_comment

begin_define
define|#
directive|define
name|DLT_A653_ICM
value|185
end_define

begin_comment
comment|/*  * USB packets, beginning with a USB setup header; requested by  * Paolo Abeni<paolo.abeni@email.it>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_USB
value|186
end_define

begin_comment
comment|/*  * Bluetooth HCI UART transport layer (part H:4); requested by  * Paolo Abeni.  */
end_comment

begin_define
define|#
directive|define
name|DLT_BLUETOOTH_HCI_H4
value|187
end_define

begin_comment
comment|/*  * IEEE 802.16 MAC Common Part Sublayer; requested by Maria Cruz  *<cruz_petagay@bah.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IEEE802_16_MAC_CPS
value|188
end_define

begin_comment
comment|/*  * USB packets, beginning with a Linux USB header; requested by  * Paolo Abeni<paolo.abeni@email.it>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_USB_LINUX
value|189
end_define

begin_comment
comment|/*  * Controller Area Network (CAN) v. 2.0B packets.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  * Used to dump CAN packets coming from a CAN Vector board.  * More documentation on the CAN v2.0B frames can be found at  * http://www.can-cia.org/downloads/?269  */
end_comment

begin_define
define|#
directive|define
name|DLT_CAN20B
value|190
end_define

begin_comment
comment|/*  * IEEE 802.15.4, with address fields padded, as is done by Linux  * drivers; requested by Juergen Schimmer.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IEEE802_15_4_LINUX
value|191
end_define

begin_comment
comment|/*  * Per Packet Information encapsulated packets.  * DLT_ requested by Gianluca Varenni<gianluca.varenni@cacetech.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_PPI
value|192
end_define

begin_comment
comment|/*  * Header for 802.16 MAC Common Part Sublayer plus a radiotap radio header;  * requested by Charles Clancy.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IEEE802_16_MAC_CPS_RADIO
value|193
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  * The DLT_ is used for internal communication with a  * integrated service module (ISM).  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_ISM
value|194
end_define

begin_comment
comment|/*  * IEEE 802.15.4, exactly as it appears in the spec (no padding, no  * nothing); requested by Mikko Saarnivala<mikko.saarnivala@sensinode.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IEEE802_15_4
value|195
end_define

begin_comment
comment|/*  * Various link-layer types, with a pseudo-header, for SITA  * (http://www.sita.aero/); requested by Fulko Hew (fulko.hew@gmail.com).  */
end_comment

begin_define
define|#
directive|define
name|DLT_SITA
value|196
end_define

begin_comment
comment|/*  * Various link-layer types, with a pseudo-header, for Endace DAG cards;  * encapsulates Endace ERF records.  Requested by Stephen Donnelly  *<stephen@endace.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_ERF
value|197
end_define

begin_comment
comment|/*  * Special header prepended to Ethernet packets when capturing from a  * u10 Networks board.  Requested by Phil Mulholland  *<phil@u10networks.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_RAIF1
value|198
end_define

begin_comment
comment|/*  * IPMB packet for IPMI, beginning with the I2C slave address, followed  * by the netFn and LUN, etc..  Requested by Chanthy Toeung  *<chanthy.toeung@ca.kontron.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IPMB
value|199
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  * The DLT_ is used for capturing data on a secure tunnel interface.  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_ST
value|200
end_define

begin_comment
comment|/*  * Bluetooth HCI UART transport layer (part H:4), with pseudo-header  * that includes direction information; requested by Paolo Abeni.  */
end_comment

begin_define
define|#
directive|define
name|DLT_BLUETOOTH_HCI_H4_WITH_PHDR
value|201
end_define

begin_comment
comment|/*  * AX.25 packet with a 1-byte KISS header; see  *  *      http://www.ax25.net/kiss.htm  *  * as per Richard Stearn<richard@rns-stearn.demon.co.uk>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_AX25_KISS
value|202
end_define

begin_comment
comment|/*  * LAPD packets from an ISDN channel, starting with the address field,  * with no pseudo-header.  * Requested by Varuna De Silva<varunax@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_LAPD
value|203
end_define

begin_comment
comment|/*  * Variants of various link-layer headers, with a one-byte direction  * pseudo-header prepended - zero means "received by this host",  * non-zero (any non-zero value) means "sent by this host" - as per  * Will Barker<w.barker@zen.co.uk>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_PPP_WITH_DIR
value|204
end_define

begin_comment
comment|/* PPP - don't confuse with DLT_PPP_WITH_DIRECTION */
end_comment

begin_define
define|#
directive|define
name|DLT_C_HDLC_WITH_DIR
value|205
end_define

begin_comment
comment|/* Cisco HDLC */
end_comment

begin_define
define|#
directive|define
name|DLT_FRELAY_WITH_DIR
value|206
end_define

begin_comment
comment|/* Frame Relay */
end_comment

begin_define
define|#
directive|define
name|DLT_LAPB_WITH_DIR
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
name|DLT_IPMB_LINUX
value|209
end_define

begin_comment
comment|/*  * FlexRay automotive bus - http://www.flexray.com/ - as requested  * by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_FLEXRAY
value|210
end_define

begin_comment
comment|/*  * Media Oriented Systems Transport (MOST) bus for multimedia  * transport - http://www.mostcooperation.com/ - as requested  * by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_MOST
value|211
end_define

begin_comment
comment|/*  * Local Interconnect Network (LIN) bus for vehicle networks -  * http://www.lin-subbus.org/ - as requested by Hannes Kaelber  *<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_LIN
value|212
end_define

begin_comment
comment|/*  * X2E-private data link type used for serial line capture,  * as requested by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_X2E_SERIAL
value|213
end_define

begin_comment
comment|/*  * X2E-private data link type used for the Xoraya data logger  * family, as requested by Hannes Kaelber<hannes.kaelber@x2e.de>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_X2E_XORAYA
value|214
end_define

begin_comment
comment|/*  * IEEE 802.15.4, exactly as it appears in the spec (no padding, no  * nothing), but with the PHY-level data for non-ASK PHYs (4 octets  * of 0 as preamble, one octet of SFD, one octet of frame length+  * reserved bit, and then the MAC-layer data, starting with the  * frame control field).  *  * Requested by Max Filippov<jcmvbkbc@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IEEE802_15_4_NONASK_PHY
value|215
end_define

begin_comment
comment|/*   * David Gibson<david@gibson.dropbear.id.au> requested this for  * captures from the Linux kernel /dev/input/eventN devices. This  * is used to communicate keystrokes and mouse movements from the  * Linux kernel to display systems, such as Xorg.   */
end_comment

begin_define
define|#
directive|define
name|DLT_LINUX_EVDEV
value|216
end_define

begin_comment
comment|/*  * GSM Um and Abis interfaces, preceded by a "gsmtap" header.  *  * Requested by Harald Welte<laforge@gnumonks.org>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_GSMTAP_UM
value|217
end_define

begin_define
define|#
directive|define
name|DLT_GSMTAP_ABIS
value|218
end_define

begin_comment
comment|/*  * MPLS, with an MPLS label as the link-layer header.  * Requested by Michele Marchetto<michele@openbsd.org> on behalf  * of OpenBSD.  */
end_comment

begin_define
define|#
directive|define
name|DLT_MPLS
value|219
end_define

begin_comment
comment|/*  * USB packets, beginning with a Linux USB header, with the USB header  * padded to 64 bytes; required for memory-mapped access.  */
end_comment

begin_define
define|#
directive|define
name|DLT_USB_LINUX_MMAPPED
value|220
end_define

begin_comment
comment|/*  * DECT packets, with a pseudo-header; requested by  * Matthias Wenzel<tcpdump@mazzoo.de>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_DECT
value|221
end_define

begin_comment
comment|/*  * From: "Lidwa, Eric (GSFC-582.0)[SGT INC]"<eric.lidwa-1@nasa.gov>  * Date: Mon, 11 May 2009 11:18:30 -0500  *  * DLT_AOS. We need it for AOS Space Data Link Protocol.  *   I have already written dissectors for but need an OK from  *   legal before I can submit a patch.  *  */
end_comment

begin_define
define|#
directive|define
name|DLT_AOS
value|222
end_define

begin_comment
comment|/*  * Wireless HART (Highway Addressable Remote Transducer)  * From the HART Communication Foundation  * IES/PAS 62591  *  * Requested by Sam Roberts<vieuxtech@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_WIHART
value|223
end_define

begin_comment
comment|/*  * Fibre Channel FC-2 frames, beginning with a Frame_Header.  * Requested by Kahou Lei<kahou82@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_FC_2
value|224
end_define

begin_comment
comment|/*  * Fibre Channel FC-2 frames, beginning with an encoding of the  * SOF, and ending with an encoding of the EOF.  *  * The encodings represent the frame delimiters as 4-byte sequences  * representing the corresponding ordered sets, with K28.5  * represented as 0xBC, and the D symbols as the corresponding  * byte values; for example, SOFi2, which is K28.5 - D21.5 - D1.2 - D21.2,  * is represented as 0xBC 0xB5 0x55 0x55.  *  * Requested by Kahou Lei<kahou82@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_FC_2_WITH_FRAME_DELIMS
value|225
end_define

begin_comment
comment|/*  * Solaris ipnet pseudo-header; requested by Darren Reed<Darren.Reed@Sun.COM>.  *  * The pseudo-header starts with a one-byte version number; for version 2,  * the pseudo-header is:  *  * struct dl_ipnetinfo {  *     u_int8_t   dli_version;  *     u_int8_t   dli_family;  *     u_int16_t  dli_htype;  *     u_int32_t  dli_pktlen;  *     u_int32_t  dli_ifindex;  *     u_int32_t  dli_grifindex;  *     u_int32_t  dli_zsrc;  *     u_int32_t  dli_zdst;  * };  *  * dli_version is 2 for the current version of the pseudo-header.  *  * dli_family is a Solaris address family value, so it's 2 for IPv4  * and 26 for IPv6.  *  * dli_htype is a "hook type" - 0 for incoming packets, 1 for outgoing  * packets, and 2 for packets arriving from another zone on the same  * machine.  *  * dli_pktlen is the length of the packet data following the pseudo-header  * (so the captured length minus dli_pktlen is the length of the  * pseudo-header, assuming the entire pseudo-header was captured).  *  * dli_ifindex is the interface index of the interface on which the  * packet arrived.  *  * dli_grifindex is the group interface index number (for IPMP interfaces).  *  * dli_zsrc is the zone identifier for the source of the packet.  *  * dli_zdst is the zone identifier for the destination of the packet.  *  * A zone number of 0 is the global zone; a zone number of 0xffffffff  * means that the packet arrived from another host on the network, not  * from another zone on the same machine.  *  * An IPv4 or IPv6 datagram follows the pseudo-header; dli_family indicates  * which of those it is.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IPNET
value|226
end_define

begin_comment
comment|/*  * CAN (Controller Area Network) frames, with a pseudo-header as supplied  * by Linux SocketCAN.  See Documentation/networking/can.txt in the Linux  * source.  *  * Requested by Felix Obenhuber<felix@obenhuber.de>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_CAN_SOCKETCAN
value|227
end_define

begin_comment
comment|/*  * Raw IPv4/IPv6; different from DLT_RAW in that the DLT_ value specifies  * whether it's v4 or v6.  Requested by Darren Reed<Darren.Reed@Sun.COM>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IPV4
value|228
end_define

begin_define
define|#
directive|define
name|DLT_IPV6
value|229
end_define

begin_comment
comment|/*  * IEEE 802.15.4, exactly as it appears in the spec (no padding, no  * nothing), and with no FCS at the end of the frame; requested by  * Jon Smirl<jonsmirl@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IEEE802_15_4_NOFCS
value|230
end_define

begin_comment
comment|/*  * Raw D-Bus:  *  *	http://www.freedesktop.org/wiki/Software/dbus  *  * messages:  *  *	http://dbus.freedesktop.org/doc/dbus-specification.html#message-protocol-messages  *  * starting with the endianness flag, followed by the message type, etc.,  * but without the authentication handshake before the message sequence:  *  *	http://dbus.freedesktop.org/doc/dbus-specification.html#auth-protocol  *  * Requested by Martin Vidner<martin@vidner.net>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_DBUS
value|231
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_VS
value|232
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_SRX_E2E
value|233
end_define

begin_define
define|#
directive|define
name|DLT_JUNIPER_FIBRECHANNEL
value|234
end_define

begin_comment
comment|/*  * DVB-CI (DVB Common Interface for communication between a PC Card  * module and a DVB receiver).  See  *  *	http://www.kaiser.cx/pcap-dvbci.html  *  * for the specification.  *  * Requested by Martin Kaiser<martin@kaiser.cx>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_DVB_CI
value|235
end_define

begin_comment
comment|/*  * Variant of 3GPP TS 27.010 multiplexing protocol (similar to, but  * *not* the same as, 27.010).  Requested by Hans-Christoph Schemmel  *<hans-christoph.schemmel@cinterion.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_MUX27010
value|236
end_define

begin_comment
comment|/*  * STANAG 5066 D_PDUs.  Requested by M. Baris Demiray  *<barisdemiray@gmail.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_STANAG_5066_D_PDU
value|237
end_define

begin_comment
comment|/*  * Juniper-private data link type, as per request from  * Hannes Gredler<hannes@juniper.net>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_JUNIPER_ATM_CEMIC
value|238
end_define

begin_comment
comment|/*  * NetFilter LOG messages   * (payload of netlink NFNL_SUBSYS_ULOG/NFULNL_MSG_PACKET packets)  *  * Requested by Jakub Zawadzki<darkjames-ws@darkjames.pl>  */
end_comment

begin_define
define|#
directive|define
name|DLT_NFLOG
value|239
end_define

begin_comment
comment|/*  * Hilscher Gesellschaft fuer Systemautomation mbH link-layer type  * for Ethernet packets with a 4-byte pseudo-header and always  * with the payload including the FCS, as supplied by their  * netANALYZER hardware and software.  *  * Requested by Holger P. Frommer<HPfrommer@hilscher.com>  */
end_comment

begin_define
define|#
directive|define
name|DLT_NETANALYZER
value|240
end_define

begin_comment
comment|/*  * Hilscher Gesellschaft fuer Systemautomation mbH link-layer type  * for Ethernet packets with a 4-byte pseudo-header and FCS and  * with the Ethernet header preceded by 7 bytes of preamble and  * 1 byte of SFD, as supplied by their netANALYZER hardware and  * software.  *  * Requested by Holger P. Frommer<HPfrommer@hilscher.com>  */
end_comment

begin_define
define|#
directive|define
name|DLT_NETANALYZER_TRANSPARENT
value|241
end_define

begin_comment
comment|/*  * IP-over-Infiniband, as specified by RFC 4391.  *  * Requested by Petr Sumbera<petr.sumbera@oracle.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_IPOIB
value|242
end_define

begin_comment
comment|/*  * MPEG-2 transport stream (ISO 13818-1/ITU-T H.222.0).  *  * Requested by Guy Martin<gmsoft@tuxicoman.be>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_MPEG_2_TS
value|243
end_define

begin_comment
comment|/*  * ng4T GmbH's UMTS Iub/Iur-over-ATM and Iub/Iur-over-IP format as  * used by their ng40 protocol tester.  *  * Requested by Jens Grimmer<jens.grimmer@ng4t.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_NG40
value|244
end_define

begin_comment
comment|/*  * Pseudo-header giving adapter number and flags, followed by an NFC  * (Near-Field Communications) Logical Link Control Protocol (LLCP) PDU,  * as specified by NFC Forum Logical Link Control Protocol Technical  * Specification LLCP 1.1.  *  * Requested by Mike Wakerly<mikey@google.com>.  */
end_comment

begin_define
define|#
directive|define
name|DLT_NFC_LLCP
value|245
end_define

begin_comment
comment|/*  * 245 is used as LINKTYPE_PFSYNC; do not use it for any other purpose.  *  * DLT_PFSYNC has different values on different platforms, and all of  * them collide with something used elsewhere.  On platforms that  * don't already define it, define it as 245.  */
end_comment

begin_if
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
end_if

begin_define
define|#
directive|define
name|DLT_PFSYNC
value|246
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DLT_MATCHING_MAX
value|246
end_define

begin_comment
comment|/* highest value in the "matching" range */
end_comment

begin_comment
comment|/*  * DLT and savefile link type values are split into a class and  * a member of that class.  A class value of 0 indicates a regular  * DLT_/LINKTYPE_ value.  */
end_comment

begin_define
define|#
directive|define
name|DLT_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x03ff0000)
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

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_BPF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_bpf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Rotate the packet buffers in descriptor d.  Move the store buffer into the  * hold slot, and the free buffer ino the store slot.  Zero the length of the  * new store buffer.  Descriptor lock should be held. Hold buffer must  * not be marked "in use".  */
end_comment

begin_define
define|#
directive|define
name|ROTATE_BUFFERS
parameter_list|(
name|d
parameter_list|)
value|do {					\ 	(d)->bd_hbuf = (d)->bd_sbuf;					\ 	(d)->bd_hlen = (d)->bd_slen;					\ 	(d)->bd_sbuf = (d)->bd_fbuf;					\ 	(d)->bd_slen = 0;						\ 	(d)->bd_fbuf = NULL;						\ 	bpf_bufheld(d);							\ } while (0)
end_define

begin_comment
comment|/*  * Descriptor associated with each attached hardware interface.  * FIXME: this structure is exposed to external callers to speed up  * bpf_peers_present() call. However we cover all fields not needed by  * this function via BPF_INTERNAL define  */
end_comment

begin_struct
struct|struct
name|bpf_if
block|{
name|LIST_ENTRY
argument_list|(
argument|bpf_if
argument_list|)
name|bif_next
expr_stmt|;
comment|/* list of all interfaces */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|bpf_d
argument_list|)
name|bif_dlist
expr_stmt|;
comment|/* descriptor list */
ifdef|#
directive|ifdef
name|BPF_INTERNAL
name|u_int
name|bif_dlt
decl_stmt|;
comment|/* link layer type */
name|u_int
name|bif_hdrlen
decl_stmt|;
comment|/* length of link header */
name|struct
name|ifnet
modifier|*
name|bif_ifp
decl_stmt|;
comment|/* corresponding interface */
name|struct
name|rwlock
name|bif_lock
decl_stmt|;
comment|/* interface lock */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|bpf_d
argument_list|)
name|bif_wlist
expr_stmt|;
comment|/* writer-only list */
name|int
name|flags
decl_stmt|;
comment|/* Interface flags */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
name|void
name|bpf_bufheld
parameter_list|(
name|struct
name|bpf_d
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

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

begin_function
specifier|static
name|__inline
name|int
name|bpf_peers_present
parameter_list|(
name|struct
name|bpf_if
modifier|*
name|bpf
parameter_list|)
block|{
if|if
condition|(
operator|!
name|LIST_EMPTY
argument_list|(
operator|&
name|bpf
operator|->
name|bif_dlist
argument_list|)
condition|)
return|return
operator|(
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
value|do {				\ 	if (bpf_peers_present((_ifp)->if_bpf))			\ 		bpf_tap((_ifp)->if_bpf, (_pkt), (_pktlen));	\ } while (0)
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
value|do {					\ 	if (bpf_peers_present((_ifp)->if_bpf)) {		\ 		M_ASSERTVALID(_m);				\ 		bpf_mtap((_ifp)->if_bpf, (_m));			\ 	}							\ } while (0)
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
value|do {			\ 	if (bpf_peers_present((_ifp)->if_bpf)) {		\ 		M_ASSERTVALID(_m);				\ 		bpf_mtap2((_ifp)->if_bpf,(_data),(_dlen),(_m));	\ 	}							\ } while (0)
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

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_EVENTHANDLER_H_
end_ifdef

begin_comment
comment|/* BPF attach/detach events */
end_comment

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bpf_track_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
comment|/* dlt */
parameter_list|,
name|int
comment|/* 1 =>'s attach */
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|bpf_track
argument_list|,
name|bpf_track_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_EVENTHANDLER_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_BPF_H_ */
end_comment

end_unit

