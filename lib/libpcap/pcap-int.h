begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the Computer Systems  *	Engineering Group at Lawrence Berkeley Laboratory.  * 4. Neither the name of the University nor of the Laboratory may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * @(#) $FreeBSD$ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|pcap_int_h
end_ifndef

begin_define
define|#
directive|define
name|pcap_int_h
end_define

begin_include
include|#
directive|include
file|<pcap.h>
end_include

begin_comment
comment|/*  * Savefile  */
end_comment

begin_struct
struct|struct
name|pcap_sf
block|{
name|FILE
modifier|*
name|rfile
decl_stmt|;
name|int
name|swapped
decl_stmt|;
name|int
name|version_major
decl_stmt|;
name|int
name|version_minor
decl_stmt|;
name|u_char
modifier|*
name|base
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcap_md
block|{
name|struct
name|pcap_stat
name|stat
decl_stmt|;
ifdef|#
directive|ifdef
name|PCAP_PF
name|int
name|use_bpf
decl_stmt|;
name|u_long
name|TotPkts
decl_stmt|;
comment|/* can't oflow for 79 hrs on ether */
name|u_long
name|TotAccepted
decl_stmt|;
comment|/* count accepted by filter */
name|u_long
name|TotDrops
decl_stmt|;
comment|/* count of dropped packets */
name|long
name|TotMissed
decl_stmt|;
comment|/* missed by i/f during this run */
name|long
name|OrigMissed
decl_stmt|;
comment|/* missed by i/f before this run */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcap
block|{
name|int
name|fd
decl_stmt|;
name|int
name|snapshot
decl_stmt|;
name|int
name|linktype
decl_stmt|;
name|int
name|tzoff
decl_stmt|;
comment|/* timezone offset */
name|struct
name|pcap_sf
name|sf
decl_stmt|;
name|struct
name|pcap_md
name|md
decl_stmt|;
comment|/* 	 * Read buffer. 	 */
name|int
name|bufsize
decl_stmt|;
name|u_char
modifier|*
name|buffer
decl_stmt|;
name|u_char
modifier|*
name|bp
decl_stmt|;
name|int
name|cc
decl_stmt|;
comment|/* 	 * Place holder for pcap_next(). 	 */
name|u_char
modifier|*
name|pkt
decl_stmt|;
comment|/* 	 * Placeholder for filter code if bpf not in kernel. 	 */
name|struct
name|bpf_program
name|fcode
decl_stmt|;
name|char
name|errbuf
index|[
name|PCAP_ERRBUF_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* XXX should these be in pcap.h? */
end_comment

begin_function_decl
name|int
name|pcap_offline_read
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
name|pcap_read
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|int
name|cnt
parameter_list|,
name|pcap_handler
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

