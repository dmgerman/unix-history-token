begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ipcomp.h,v 1.8 2000/09/26 07:55:14 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * RFC2393 IP payload compression protocol (IPComp).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IPCOMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IPCOMP_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LKM
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ipcomp
block|{
name|u_int8_t
name|comp_nxt
decl_stmt|;
comment|/* Next Header */
name|u_int8_t
name|comp_flags
decl_stmt|;
comment|/* reserved, must be zero */
name|u_int16_t
name|comp_cpi
decl_stmt|;
comment|/* Compression parameter index */
block|}
struct|;
end_struct

begin_comment
comment|/* well-known algorithm number (in CPI), from RFC2409 */
end_comment

begin_define
define|#
directive|define
name|IPCOMP_OUI
value|1
end_define

begin_comment
comment|/* vendor specific */
end_comment

begin_define
define|#
directive|define
name|IPCOMP_DEFLATE
value|2
end_define

begin_comment
comment|/* RFC2394 */
end_comment

begin_define
define|#
directive|define
name|IPCOMP_LZS
value|3
end_define

begin_comment
comment|/* RFC2395 */
end_comment

begin_define
define|#
directive|define
name|IPCOMP_MAX
value|4
end_define

begin_define
define|#
directive|define
name|IPCOMP_CPI_NEGOTIATE_MIN
value|256
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|ipcomp_algorithm
block|{
name|int
argument_list|(
argument|*compress
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*decompress
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
expr_stmt|;
name|size_t
name|minplen
decl_stmt|;
comment|/* minimum required length for compression */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ipsecrequest
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ipcomp_algorithm
modifier|*
name|ipcomp_algorithm_lookup
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipcomp4_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipcomp4_output
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|ipsecrequest
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*KERNEL*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_NETINET6_IPCOMP_H_*/
end_comment

end_unit

