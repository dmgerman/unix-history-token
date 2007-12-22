begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: net.h,v 1.10 1995/10/20 00:46:30 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1993 Adam Glass   * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* XXX - see<netinet/in.h> */
end_comment

begin_undef
undef|#
directive|undef
name|__IPADDR
end_undef

begin_define
define|#
directive|define
name|__IPADDR
parameter_list|(
name|x
parameter_list|)
value|htonl((u_int32_t)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"iodesc.h"
end_include

begin_define
define|#
directive|define
name|BA
value|{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }
end_define

begin_comment
comment|/* Returns true if n_long's on the same net */
end_comment

begin_define
define|#
directive|define
name|SAMENET
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|m
parameter_list|)
value|((a1.s_addr& m) == (a2.s_addr& m))
end_define

begin_define
define|#
directive|define
name|MACPY
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|bcopy((char *)s, (char *)d, 6)
end_define

begin_define
define|#
directive|define
name|MAXTMO
value|20
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|MINTMO
value|2
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|FNAME_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|IFNAME_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|RECV_SIZE
value|1536
end_define

begin_comment
comment|/* XXX delete this */
end_comment

begin_comment
comment|/*  * How much room to leave for headers:  *  14: struct ether_header  *  20: struct ip  *   8: struct udphdr  * That's 42 but let's pad it out to 48 bytes.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_SIZE
value|14
end_define

begin_define
define|#
directive|define
name|HEADER_SIZE
value|48
end_define

begin_decl_stmt
specifier|extern
name|u_char
name|bcea
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|rootpath
index|[
name|FNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|bootfile
index|[
name|FNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[
name|FNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hostnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|domainname
index|[
name|FNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|domainnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ifname
index|[
name|IFNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All of these are in network order. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|myip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|rootip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|swapip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|gateip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|nameip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|n_long
name|netmask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in the machdep sources */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|iodesc
name|sockets
index|[
name|SOPEN_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARP/RevARP functions: */
end_comment

begin_function_decl
name|u_char
modifier|*
name|arpwhohas
parameter_list|(
name|struct
name|iodesc
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arp_reply
parameter_list|(
name|struct
name|iodesc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rarp_getipaddress
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Link functions: */
end_comment

begin_function_decl
name|ssize_t
name|sendether
parameter_list|(
name|struct
name|iodesc
modifier|*
name|d
parameter_list|,
name|void
modifier|*
name|pkt
parameter_list|,
name|size_t
name|len
parameter_list|,
name|u_char
modifier|*
name|dea
parameter_list|,
name|int
name|etype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|readether
parameter_list|(
name|struct
name|iodesc
modifier|*
name|d
parameter_list|,
name|void
modifier|*
name|pkt
parameter_list|,
name|size_t
name|len
parameter_list|,
name|time_t
name|tleft
parameter_list|,
name|u_int16_t
modifier|*
name|etype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|sendudp
parameter_list|(
name|struct
name|iodesc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|readudp
parameter_list|(
name|struct
name|iodesc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|sendrecv
parameter_list|(
name|struct
name|iodesc
modifier|*
parameter_list|,
name|ssize_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|iodesc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|ssize_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|iodesc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|time_t
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bootp/DHCP */
end_comment

begin_function_decl
name|void
name|bootp
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Utilities: */
end_comment

begin_function_decl
name|char
modifier|*
name|ether_sprintf
parameter_list|(
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_cksum
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_ntoa
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|intoa
parameter_list|(
name|n_long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* similar to inet_ntoa */
end_comment

begin_function_decl
name|n_long
name|inet_addr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Machine-dependent functions: */
end_comment

begin_function_decl
name|time_t
name|getsecs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

