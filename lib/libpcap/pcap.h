begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the Computer Systems  *	Engineering Group at Lawrence Berkeley Laboratory.  * 4. Neither the name of the University nor of the Laboratory may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * @(#) $FreeBSD$ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lib_pcap_h
end_ifndef

begin_define
define|#
directive|define
name|lib_pcap_h
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|PCAP_VERSION_MAJOR
value|2
end_define

begin_define
define|#
directive|define
name|PCAP_VERSION_MINOR
value|4
end_define

begin_define
define|#
directive|define
name|PCAP_ERRBUF_SIZE
value|256
end_define

begin_comment
comment|/*  * Compatibility for systems that have a bpf.h that  * predates the bpf typedefs for 64-bit support.  */
end_comment

begin_if
if|#
directive|if
name|BPF_RELEASE
operator|-
literal|0
operator|<
literal|199406
end_if

begin_typedef
typedef|typedef
name|long
name|bpf_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|bpf_u_int32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|pcap
name|pcap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pcap_dumper
name|pcap_dumper_t
typedef|;
end_typedef

begin_comment
comment|/*  * The first record in the file contains saved values for some  * of the flags used in the printout phases of tcpdump.  * Many fields here are longs so compilers won't insert unwanted  * padding; these files need to be interchangeable across architectures.  */
end_comment

begin_struct
struct|struct
name|pcap_file_header
block|{
name|bpf_u_int32
name|magic
decl_stmt|;
name|u_short
name|version_major
decl_stmt|;
name|u_short
name|version_minor
decl_stmt|;
name|bpf_int32
name|thiszone
decl_stmt|;
comment|/* gmt to local correction */
name|bpf_u_int32
name|sigfigs
decl_stmt|;
comment|/* accuracy of timestamps */
name|bpf_u_int32
name|snaplen
decl_stmt|;
comment|/* max length saved portion of each pkt */
name|bpf_u_int32
name|linktype
decl_stmt|;
comment|/* data link type (DLT_*) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Each packet in the dump file is prepended with this generic header.  * This gets around the problem of different headers for different  * packet interfaces.  */
end_comment

begin_struct
struct|struct
name|pcap_pkthdr
block|{
name|struct
name|timeval
name|ts
decl_stmt|;
comment|/* time stamp */
name|bpf_u_int32
name|caplen
decl_stmt|;
comment|/* length of portion present */
name|bpf_u_int32
name|len
decl_stmt|;
comment|/* length this packet (off wire) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * As returned by the pcap_stats()  */
end_comment

begin_struct
struct|struct
name|pcap_stat
block|{
name|u_int
name|ps_recv
decl_stmt|;
comment|/* number of packets received */
name|u_int
name|ps_drop
decl_stmt|;
comment|/* number of packets dropped */
name|u_int
name|ps_ifdrop
decl_stmt|;
comment|/* drops by interface XXX not yet supported */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|pcap_handler
function_decl|)
parameter_list|(
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|char
modifier|*
name|pcap_lookupdev
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_lookupnet
parameter_list|(
name|char
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pcap_t
modifier|*
name|pcap_open_live
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pcap_t
modifier|*
name|pcap_open_offline
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcap_close
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_loop
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|pcap_handler
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_dispatch
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|pcap_handler
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u_char
modifier|*
name|pcap_next
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|struct
name|pcap_pkthdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_stats
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|struct
name|pcap_stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_setfilter
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|struct
name|bpf_program
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcap_perror
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pcap_strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pcap_geterr
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_compile
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|struct
name|bpf_program
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
name|int
name|pcap_freecode
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|struct
name|bpf_program
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_datalink
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_snapshot
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_is_swapped
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_major_version
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_minor_version
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
name|FILE
modifier|*
name|pcap_file
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcap_fileno
parameter_list|(
name|pcap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pcap_dumper_t
modifier|*
name|pcap_dump_open
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcap_dump_close
parameter_list|(
name|pcap_dumper_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcap_dump
parameter_list|(
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX this guy lives in the bpf tree */
end_comment

begin_function_decl
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
end_function_decl

begin_function_decl
name|char
modifier|*
name|bpf_image
parameter_list|(
name|struct
name|bpf_insn
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

