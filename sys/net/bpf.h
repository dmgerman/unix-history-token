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
comment|/* Pull in data-link level type codes. */
end_comment

begin_include
include|#
directive|include
file|<net/dlt.h>
end_include

begin_comment
comment|/*  * The instruction encodings.  *  * Please inform tcpdump-workers@lists.tcpdump.org if you use any  * of the reserved values, so that we can note that they're used  * (and perhaps implement it in the reference BPF implementation  * and encourage its implementation elsewhere).  */
end_comment

begin_comment
comment|/*  * The upper 8 bits of the opcode aren't used. BSD/OS used 0x8000.  */
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

begin_comment
comment|/*				0x18	reserved; used by BSD/OS */
end_comment

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
comment|/*				0xc0	reserved; used by BSD/OS */
end_comment

begin_comment
comment|/*				0xe0	reserved; used by BSD/OS */
end_comment

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
name|BPF_MOD
value|0x90
end_define

begin_define
define|#
directive|define
name|BPF_XOR
value|0xa0
end_define

begin_comment
comment|/*				0xb0	reserved */
end_comment

begin_comment
comment|/*				0xc0	reserved */
end_comment

begin_comment
comment|/*				0xd0	reserved */
end_comment

begin_comment
comment|/*				0xe0	reserved */
end_comment

begin_comment
comment|/*				0xf0	reserved */
end_comment

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

begin_comment
comment|/*				0x50	reserved; used on BSD/OS */
end_comment

begin_comment
comment|/*				0x60	reserved */
end_comment

begin_comment
comment|/*				0x70	reserved */
end_comment

begin_comment
comment|/*				0x80	reserved */
end_comment

begin_comment
comment|/*				0x90	reserved */
end_comment

begin_comment
comment|/*				0xa0	reserved */
end_comment

begin_comment
comment|/*				0xb0	reserved */
end_comment

begin_comment
comment|/*				0xc0	reserved */
end_comment

begin_comment
comment|/*				0xd0	reserved */
end_comment

begin_comment
comment|/*				0xe0	reserved */
end_comment

begin_comment
comment|/*				0xf0	reserved */
end_comment

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
comment|/*				0x18	reserved */
end_comment

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

begin_comment
comment|/*				0x08	reserved */
end_comment

begin_comment
comment|/*				0x10	reserved */
end_comment

begin_comment
comment|/*				0x18	reserved */
end_comment

begin_comment
comment|/* #define	BPF_COP		0x20	NetBSD "coprocessor" extensions */
end_comment

begin_comment
comment|/*				0x28	reserved */
end_comment

begin_comment
comment|/*				0x30	reserved */
end_comment

begin_comment
comment|/*				0x38	reserved */
end_comment

begin_comment
comment|/* #define	BPF_COPX	0x40	NetBSD "coprocessor" extensions */
end_comment

begin_comment
comment|/*					also used on BSD/OS */
end_comment

begin_comment
comment|/*				0x48	reserved */
end_comment

begin_comment
comment|/*				0x50	reserved */
end_comment

begin_comment
comment|/*				0x58	reserved */
end_comment

begin_comment
comment|/*				0x60	reserved */
end_comment

begin_comment
comment|/*				0x68	reserved */
end_comment

begin_comment
comment|/*				0x70	reserved */
end_comment

begin_comment
comment|/*				0x78	reserved */
end_comment

begin_define
define|#
directive|define
name|BPF_TXA
value|0x80
end_define

begin_comment
comment|/*				0x88	reserved */
end_comment

begin_comment
comment|/*				0x90	reserved */
end_comment

begin_comment
comment|/*				0x98	reserved */
end_comment

begin_comment
comment|/*				0xa0	reserved */
end_comment

begin_comment
comment|/*				0xa8	reserved */
end_comment

begin_comment
comment|/*				0xb0	reserved */
end_comment

begin_comment
comment|/*				0xb8	reserved */
end_comment

begin_comment
comment|/*				0xc0	reserved; used on BSD/OS */
end_comment

begin_comment
comment|/*				0xc8	reserved */
end_comment

begin_comment
comment|/*				0xd0	reserved */
end_comment

begin_comment
comment|/*				0xd8	reserved */
end_comment

begin_comment
comment|/*				0xe0	reserved */
end_comment

begin_comment
comment|/*				0xe8	reserved */
end_comment

begin_comment
comment|/*				0xf0	reserved */
end_comment

begin_comment
comment|/*				0xf8	reserved */
end_comment

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
comment|/*  * Rotate the packet buffers in descriptor d.  Move the store buffer into the  * hold slot, and the free buffer into the store slot.  Zero the length of the  * new store buffer.  Descriptor lock should be held.  One must be careful to  * not rotate the buffers twice, i.e. if fbuf != NULL.  */
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
comment|/*  * Descriptor associated with each attached hardware interface.  * Part of this structure is exposed to external callers to speed up  * bpf_peers_present() calls.  */
end_comment

begin_struct_decl
struct_decl|struct
name|bpf_if
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bpf_if_ext
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

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_function_decl
name|int
name|bpf_get_bp_params
parameter_list|(
name|struct
name|bpf_if
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
name|struct
name|bpf_if_ext
modifier|*
name|ext
decl_stmt|;
name|ext
operator|=
operator|(
expr|struct
name|bpf_if_ext
operator|*
operator|)
name|bpf
expr_stmt|;
if|if
condition|(
operator|!
name|LIST_EMPTY
argument_list|(
operator|&
name|ext
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

