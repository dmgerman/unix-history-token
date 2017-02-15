begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence  * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)bpf.h       7.1 (Berkeley) 5/7/91  */
end_comment

begin_comment
comment|/*  * This is libpcap's cut-down version of bpf.h; it includes only  * the stuff needed for the code generator and the userland BPF  * interpreter, and the libpcap APIs for setting filters, etc..  *  * "pcap-bpf.c" will include the native OS version, as it deals with  * the OS's BPF implementation.  *  * At least two programs found by Google Code Search explicitly includes  *<pcap/bpf.h> (even though<pcap.h>/<pcap/pcap.h> includes it for you),  * so moving that stuff to<pcap/pcap.h> would break the build for some  * programs.  */
end_comment

begin_comment
comment|/*  * If we've already included<net/bpf.h>, don't re-define this stuff.  * We assume BSD-style multiple-include protection in<net/bpf.h>,  * which is true of all but the oldest versions of FreeBSD and NetBSD,  * or Tru64 UNIX-style multiple-include protection (or, at least,  * Tru64 UNIX 5.x-style; I don't have earlier versions available to check),  * or AIX-style multiple-include protection (or, at least, AIX 5.x-style;  * I don't have earlier versions available to check), or QNX-style  * multiple-include protection (as per GitHub pull request #394).  *  * We do not check for BPF_MAJOR_VERSION, as that's defined by  *<linux/filter.h>, which is directly or indirectly included in some  * programs that also include pcap.h, and<linux/filter.h> doesn't  * define stuff we need.  *  * This also provides our own multiple-include protection.  */
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
name|_NET_BPF_H_INCLUDED
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

begin_include
include|#
directive|include
file|<pcap/export-defs.h>
end_include

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
comment|/*  * Alignment macros.  BPF_WORDALIGN rounds up to the next  * even multiple of BPF_ALIGNMENT.  *  * Tcpdump's print-pflog.c uses this, so we define it here.  */
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
include|#
directive|include
file|<pcap/dlt.h>
comment|/*  * The instruction encodings.  *  * Please inform tcpdump-workers@lists.tcpdump.org if you use any  * of the reserved values, so that we can note that they're used  * (and perhaps implement it in the reference BPF implementation  * and encourage its implementation elsewhere).  */
comment|/*  * The upper 8 bits of the opcode aren't used. BSD/OS used 0x8000.  */
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
comment|/*				0x18	reserved; used by BSD/OS */
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
comment|/*				0xc0	reserved; used by BSD/OS */
comment|/*				0xe0	reserved; used by BSD/OS */
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
name|BPF_MOD
value|0x90
define|#
directive|define
name|BPF_XOR
value|0xa0
comment|/*				0xb0	reserved */
comment|/*				0xc0	reserved */
comment|/*				0xd0	reserved */
comment|/*				0xe0	reserved */
comment|/*				0xf0	reserved */
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
comment|/*				0x50	reserved; used on BSD/OS */
comment|/*				0x60	reserved */
comment|/*				0x70	reserved */
comment|/*				0x80	reserved */
comment|/*				0x90	reserved */
comment|/*				0xa0	reserved */
comment|/*				0xb0	reserved */
comment|/*				0xc0	reserved */
comment|/*				0xd0	reserved */
comment|/*				0xe0	reserved */
comment|/*				0xf0	reserved */
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
comment|/*				0x18	reserved */
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
comment|/*				0x08	reserved */
comment|/*				0x10	reserved */
comment|/*				0x18	reserved */
comment|/* #define	BPF_COP		0x20	NetBSD "coprocessor" extensions */
comment|/*				0x28	reserved */
comment|/*				0x30	reserved */
comment|/*				0x38	reserved */
comment|/* #define	BPF_COPX	0x40	NetBSD "coprocessor" extensions */
comment|/*					also used on BSD/OS */
comment|/*				0x48	reserved */
comment|/*				0x50	reserved */
comment|/*				0x58	reserved */
comment|/*				0x60	reserved */
comment|/*				0x68	reserved */
comment|/*				0x70	reserved */
comment|/*				0x78	reserved */
define|#
directive|define
name|BPF_TXA
value|0x80
comment|/*				0x88	reserved */
comment|/*				0x90	reserved */
comment|/*				0x98	reserved */
comment|/*				0xa0	reserved */
comment|/*				0xa8	reserved */
comment|/*				0xb0	reserved */
comment|/*				0xb8	reserved */
comment|/*				0xc0	reserved; used on BSD/OS */
comment|/*				0xc8	reserved */
comment|/*				0xd0	reserved */
comment|/*				0xd8	reserved */
comment|/*				0xe0	reserved */
comment|/*				0xe8	reserved */
comment|/*				0xf0	reserved */
comment|/*				0xf8	reserved */
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
comment|/*  * Auxiliary data, for use when interpreting a filter intended for the  * Linux kernel when the kernel rejects the filter (requiring us to  * run it in userland).  It contains VLAN tag information.  */
struct|struct
name|bpf_aux_data
block|{
name|u_short
name|vlan_tag_present
decl_stmt|;
name|u_short
name|vlan_tag
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
name|PCAP_API
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
name|PCAP_API
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
specifier|extern
name|u_int
name|bpf_filter_with_aux_data
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
parameter_list|,
specifier|const
name|struct
name|bpf_aux_data
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
name|PCAP_API
name|int
name|bpf_validate
parameter_list|()
function_decl|;
name|PCAP_API
name|u_int
name|bpf_filter
parameter_list|()
function_decl|;
specifier|extern
name|u_int
name|bpf_filter_with_aux_data
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

