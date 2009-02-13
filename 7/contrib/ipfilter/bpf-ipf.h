begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence   * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)bpf.h       7.1 (Berkeley) 5/7/91  *  * @(#) $Header: /devel/CVS/IP-Filter/bpf-ipf.h,v 2.1 2002/10/26 12:14:26 darrenr Exp $ (LBL)  */
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
typedef|typedef
name|int
name|bpf_int32
typedef|;
typedef|typedef
name|u_int
name|bpf_u_int32
typedef|;
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
comment|/*  *  Structure for BIOCSETF.  */
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
comment|/*  * Struct returned by BIOCGSTATS.  */
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
comment|/*  * BPF ioctls  *  * The first set is for compatibility with Sun's pcc style  * header files.  If your using gcc, we assume that you  * have run fixincludes so the latter set should work.  */
if|#
directive|if
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|ibm032
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
define|#
directive|define
name|BIOCGBLEN
value|_IOR(B,102, u_int)
define|#
directive|define
name|BIOCSBLEN
value|_IOWR(B,102, u_int)
define|#
directive|define
name|BIOCSETF
value|_IOW(B,103, struct bpf_program)
define|#
directive|define
name|BIOCFLUSH
value|_IO(B,104)
define|#
directive|define
name|BIOCPROMISC
value|_IO(B,105)
define|#
directive|define
name|BIOCGDLT
value|_IOR(B,106, u_int)
define|#
directive|define
name|BIOCGETIF
value|_IOR(B,107, struct ifreq)
define|#
directive|define
name|BIOCSETIF
value|_IOW(B,108, struct ifreq)
define|#
directive|define
name|BIOCSRTIMEOUT
value|_IOW(B,109, struct timeval)
define|#
directive|define
name|BIOCGRTIMEOUT
value|_IOR(B,110, struct timeval)
define|#
directive|define
name|BIOCGSTATS
value|_IOR(B,111, struct bpf_stat)
define|#
directive|define
name|BIOCIMMEDIATE
value|_IOW(B,112, u_int)
define|#
directive|define
name|BIOCVERSION
value|_IOR(B,113, struct bpf_version)
define|#
directive|define
name|BIOCSTCPF
value|_IOW(B,114, struct bpf_program)
define|#
directive|define
name|BIOCSUDPF
value|_IOW(B,115, struct bpf_program)
else|#
directive|else
define|#
directive|define
name|BIOCGBLEN
value|_IOR('B',102, u_int)
define|#
directive|define
name|BIOCSBLEN
value|_IOWR('B',102, u_int)
define|#
directive|define
name|BIOCSETF
value|_IOW('B',103, struct bpf_program)
define|#
directive|define
name|BIOCFLUSH
value|_IO('B',104)
define|#
directive|define
name|BIOCPROMISC
value|_IO('B',105)
define|#
directive|define
name|BIOCGDLT
value|_IOR('B',106, u_int)
define|#
directive|define
name|BIOCGETIF
value|_IOR('B',107, struct ifreq)
define|#
directive|define
name|BIOCSETIF
value|_IOW('B',108, struct ifreq)
define|#
directive|define
name|BIOCSRTIMEOUT
value|_IOW('B',109, struct timeval)
define|#
directive|define
name|BIOCGRTIMEOUT
value|_IOR('B',110, struct timeval)
define|#
directive|define
name|BIOCGSTATS
value|_IOR('B',111, struct bpf_stat)
define|#
directive|define
name|BIOCIMMEDIATE
value|_IOW('B',112, u_int)
define|#
directive|define
name|BIOCVERSION
value|_IOR('B',113, struct bpf_version)
define|#
directive|define
name|BIOCSTCPF
value|_IOW('B',114, struct bpf_program)
define|#
directive|define
name|BIOCSUDPF
value|_IOW('B',115, struct bpf_program)
endif|#
directive|endif
comment|/*  * Structure prepended to each packet.  */
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
comment|/*  * Because the structure above is not a multiple of 4 bytes, some compilers  * will insist on inserting padding; hence, sizeof(struct bpf_hdr) won't work.  * Only the kernel needs to know about it; applications use bh_hdrlen.  */
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
define|#
directive|define
name|SIZEOF_BPF_HDR
value|18
endif|#
directive|endif
comment|/*  * Data-link level type codes.  */
comment|/*  * These are the types that are the same on all platforms; on other  * platforms, a<net/bpf.h> should be supplied that defines the additional  * DLT_* codes appropriately for that platform (the BSDs, for example,  * should not just pick up this version of "bpf.h"; they should also define  * the additional DLT_* codes used by their kernels, as well as the values  * defined here - and, if the values they use for particular DLT_ types  * differ from those here, they should use their values, not the ones  * here).  */
define|#
directive|define
name|DLT_NULL
value|0
comment|/* no link-layer encapsulation */
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
comment|/* ARCNET */
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
comment|/*  * These are values from the traditional libpcap "bpf.h".  * Ports of this to particular platforms should replace these definitions  * with the ones appropriate to that platform, if the values are  * different on that platform.  */
define|#
directive|define
name|DLT_ATM_RFC1483
value|11
comment|/* LLC/SNAP encapsulated atm */
define|#
directive|define
name|DLT_RAW
value|12
comment|/* raw IP */
comment|/*  * These are values from BSD/OS's "bpf.h".  * These are not the same as the values from the traditional libpcap  * "bpf.h"; however, these values shouldn't be generated by any  * OS other than BSD/OS, so the correct values to use here are the  * BSD/OS values.  *  * Platforms that have already assigned these values to other  * DLT_ codes, however, should give these codes the values  * from that platform, so that programs that use these codes will  * continue to compile - even though they won't correctly read  * files of these types.  */
ifdef|#
directive|ifdef
name|__NetBSD__
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
define|#
directive|define
name|DLT_ATM_CLIP
value|19
comment|/* Linux Classical-IP over ATM */
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
comment|/*  * Values between 106 and 107 are used in capture file headers as  * link-layer types corresponding to DLT_ types that might differ  * between platforms; don't use those values for new DLT_ new types.  */
comment|/*  * OpenBSD DLT_LOOP, for loopback devices; it's like DLT_NULL, except  * that the AF_ type in the link-layer header is in network byte order.  *  * OpenBSD defines it as 12, but that collides with DLT_RAW, so we  * define it as 108 here.  If OpenBSD picks up this file, it should  * define DLT_LOOP as 12 in its version, as per the comment above -  * and should not use 108 as a DLT_ value.  */
define|#
directive|define
name|DLT_LOOP
value|108
comment|/*  * Values between 109 and 112 are used in capture file headers as  * link-layer types corresponding to DLT_ types that might differ  * between platforms; don't use those values for new DLT_ types  * other than the corresponding DLT_ types.  */
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
comment|/*  * Reserved for use in capture-file headers as a link-layer type  * corresponding to OpenBSD DLT_PFLOG; DLT_PFLOG is 17 in OpenBSD,  * but that's DLT_LANE8023 in SuSE 6.3, so we can't use 17 for it  * in capture-file headers.  */
define|#
directive|define
name|DLT_PFLOG
value|117
comment|/*  * Registered for Cisco-internal use.  */
define|#
directive|define
name|DLT_CISCO_IOS
value|118
comment|/*  * Reserved for 802.11 cards using the Prism II chips, with a link-layer  * header including Prism monitor mode information plus an 802.11  * header.  */
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
comment|/*  * Reserved for RFC 2625 IP-over-Fibre Channel, as per a request from  * Don Lee<donlee@cray.com>.  *  * This is not for use with raw Fibre Channel, where the link-layer  * header starts with a Fibre Channel frame header; it's for IP-over-FC,  * where the link-layer header starts with an RFC 2625 Network_Header  * field.  */
define|#
directive|define
name|DLT_IP_OVER_FC
value|122
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
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
comment|/*  * Systems based on non-BSD kernels don't have ifnet's (or they don't mean  * anything if it is in<net/if.h>) and won't work like this.  */
if|#
directive|if
name|__STDC__
specifier|extern
name|void
name|bpf_tap
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|bpf_mtap
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
specifier|extern
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
specifier|extern
name|void
name|bpfilterattach
parameter_list|(
name|int
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|void
name|bpf_tap
parameter_list|()
function_decl|;
specifier|extern
name|void
name|bpf_mtap
parameter_list|()
function_decl|;
specifier|extern
name|void
name|bpfattach
parameter_list|()
function_decl|;
specifier|extern
name|void
name|bpfilterattach
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* __STDC__ */
endif|#
directive|endif
comment|/* BSD&& (_KERNEL || KERNEL) */
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

