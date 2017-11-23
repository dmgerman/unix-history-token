begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)udp.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_UDP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_UDP_H_
end_define

begin_comment
comment|/*  * UDP protocol header.  * Per RFC 768, September, 1981.  */
end_comment

begin_struct
struct|struct
name|udphdr
block|{
name|u_short
name|uh_sport
decl_stmt|;
comment|/* source port */
name|u_short
name|uh_dport
decl_stmt|;
comment|/* destination port */
name|u_short
name|uh_ulen
decl_stmt|;
comment|/* udp length */
name|u_short
name|uh_sum
decl_stmt|;
comment|/* udp checksum */
block|}
struct|;
end_struct

begin_comment
comment|/*   * User-settable options (used with setsockopt).  */
end_comment

begin_define
define|#
directive|define
name|UDP_ENCAP
value|1
end_define

begin_comment
comment|/* Start of reserved space for third-party user-settable options. */
end_comment

begin_define
define|#
directive|define
name|UDP_VENDOR
value|SO_VENDOR
end_define

begin_comment
comment|/*  * UDP Encapsulation of IPsec Packets options.  */
end_comment

begin_comment
comment|/* Encapsulation types. */
end_comment

begin_define
define|#
directive|define
name|UDP_ENCAP_ESPINUDP_NON_IKE
value|1
end_define

begin_comment
comment|/* draft-ietf-ipsec-nat-t-ike-00/01 */
end_comment

begin_define
define|#
directive|define
name|UDP_ENCAP_ESPINUDP
value|2
end_define

begin_comment
comment|/* RFC3948 */
end_comment

begin_comment
comment|/* Default ESP in UDP encapsulation port. */
end_comment

begin_define
define|#
directive|define
name|UDP_ENCAP_ESPINUDP_PORT
value|500
end_define

begin_comment
comment|/* Maximum UDP fragment size for ESP over UDP. */
end_comment

begin_define
define|#
directive|define
name|UDP_ENCAP_ESPINUDP_MAXFRAGLEN
value|552
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

