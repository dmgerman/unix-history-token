begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)clnp_stat.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_CLNP_STAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_CLNP_STAT_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/clnp_stat.h,v $ */
end_comment

begin_struct
struct|struct
name|clnp_stat
block|{
name|int
name|cns_total
decl_stmt|;
comment|/* total pkts received */
name|int
name|cns_toosmall
decl_stmt|;
comment|/* fixed part of header too small */
name|int
name|cns_badhlen
decl_stmt|;
comment|/* header length is not reasonable */
name|int
name|cns_badcsum
decl_stmt|;
comment|/* checksum on packet failed */
name|int
name|cns_badaddr
decl_stmt|;
comment|/* address fields were not reasonable */
name|int
name|cns_badvers
decl_stmt|;
comment|/* incorrect version */
name|int
name|cns_noseg
decl_stmt|;
comment|/* segment information forgotten */
name|int
name|cns_noproto
decl_stmt|;
comment|/* incorrect protocol id */
name|int
name|cns_delivered
decl_stmt|;
comment|/* packets consumed by protocol */
name|int
name|cns_ttlexpired
decl_stmt|;
comment|/* ttl has expired */
name|int
name|cns_forward
decl_stmt|;
comment|/* forwarded packets */
name|int
name|cns_sent
decl_stmt|;
comment|/* total packets sent */
name|int
name|cns_odropped
decl_stmt|;
comment|/* o.k. packets discarded, e.g. ENOBUFS */
name|int
name|cns_cantforward
decl_stmt|;
comment|/* non-forwarded packets */
name|int
name|cns_fragmented
decl_stmt|;
comment|/* packets fragmented */
name|int
name|cns_fragments
decl_stmt|;
comment|/* fragments received */
name|int
name|cns_fragdropped
decl_stmt|;
comment|/* fragments discarded */
name|int
name|cns_fragtimeout
decl_stmt|;
comment|/* fragments timed out */
name|int
name|cns_ofragments
decl_stmt|;
comment|/* fragments generated */
name|int
name|cns_cantfrag
decl_stmt|;
comment|/* fragmentation prohibited */
name|int
name|cns_reassembled
decl_stmt|;
comment|/* packets reconstructed */
name|int
name|cns_cachemiss
decl_stmt|;
comment|/* cache misses */
name|int
name|cns_congest_set
decl_stmt|;
comment|/* congestion experienced bit set */
name|int
name|cns_congest_rcvd
decl_stmt|;
comment|/* congestion experienced bit received */
name|int
name|cns_er_inhist
index|[
name|CLNP_ERRORS
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|cns_er_outhist
index|[
name|CLNP_ERRORS
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|clnp_stat
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|INCSTAT
end_ifdef

begin_undef
undef|#
directive|undef
name|INCSTAT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INCSTAT */
end_comment

begin_define
define|#
directive|define
name|INCSTAT
parameter_list|(
name|x
parameter_list|)
value|clnp_stat.
comment|/**/
value|x
comment|/**/
value|++
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

