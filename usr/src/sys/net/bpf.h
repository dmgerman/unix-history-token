begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: bpf.h,v 1.20 91/04/24 22:06:24 mccanne Locked $ (LBL)  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.h) distributed with 4.3BSD Unix.  */
end_comment

begin_comment
comment|/*  * Alignment macros.  BPF_WORDALIGN rounds up to the next   * even multiple of BPF_ALIGNMENT.   */
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
value|0x8000
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
comment|/*  * BPF ioctls  *  * The first set is for compatibility with Sun's pcc style  * header files.  If your using gcc, we assume that you  * have run fixincludes so the latter set should work.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BIOCGFLEN
value|_IOR(B,101, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCGBLEN
value|_IOR(B,102, u_int)
end_define

begin_define
define|#
directive|define
name|BIOCSETF
value|_IOW(B,103, struct bpf_program)
end_define

begin_define
define|#
directive|define
name|BIOCFLUSH
value|_IO(B,104)
end_define

begin_define
define|#
directive|define
name|BIOCPROMISC
value|_IO(B,105)
end_define

begin_define
define|#
directive|define
name|BIOCDEVP
value|_IOR(B,106, struct bpf_devp)
end_define

begin_define
define|#
directive|define
name|BIOCGETIF
value|_IOR(B,107, struct ifreq)
end_define

begin_define
define|#
directive|define
name|BIOCSETIF
value|_IOW(B,108, struct ifreq)
end_define

begin_define
define|#
directive|define
name|BIOCSRTIMEOUT
value|_IOW(B,109, struct timeval)
end_define

begin_define
define|#
directive|define
name|BIOCGRTIMEOUT
value|_IOR(B,110, struct timeval)
end_define

begin_define
define|#
directive|define
name|BIOCGSTATS
value|_IOR(B,111, struct bpf_stat)
end_define

begin_define
define|#
directive|define
name|BIOCIMMEDIATE
value|_IOW(B,112, u_int)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BIOCGFLEN
value|_IOR('B',101, u_int)
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
name|BIOCDEVP
value|_IOR('B',106, struct bpf_devp)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The device parameters of a network interface.  */
end_comment

begin_struct
struct|struct
name|bpf_devp
block|{
name|u_short
name|bdev_type
decl_stmt|;
comment|/* data link layer type, codes below */
name|u_short
name|bdev_hdrlen
decl_stmt|;
comment|/* length of a hardware packet header */
block|}
struct|;
end_struct

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
name|u_long
name|bh_caplen
decl_stmt|;
comment|/* length of captured portion */
name|u_long
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
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_BPF_HDR
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Data-link level type codes.  * Currently, only ENDT_10MB and DLT_SLIP are supported.  */
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

begin_comment
comment|/*  * The instruction encondings.  */
end_comment

begin_comment
comment|/* classes<2:0> */
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
name|long
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|u_int
name|bpf_filter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bpfattach
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bpf_tap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bpf_mtap
parameter_list|()
function_decl|;
end_function_decl

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

end_unit

