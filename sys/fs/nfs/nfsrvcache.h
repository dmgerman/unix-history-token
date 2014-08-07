begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSRVCACHE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSRVCACHE_H_
end_define

begin_comment
comment|/*  * Definitions for the server recent request cache  */
end_comment

begin_define
define|#
directive|define
name|NFSRVCACHE_MAX_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|NFSRVCACHE_MIN_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|NFSRVCACHE_HASHSIZE
value|500
end_define

begin_comment
comment|/* Cache table entry. */
end_comment

begin_struct
struct|struct
name|nfsrvcache
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsrvcache
argument_list|)
name|rc_hash
expr_stmt|;
comment|/* Hash chain */
name|LIST_ENTRY
argument_list|(
argument|nfsrvcache
argument_list|)
name|rc_ahash
expr_stmt|;
comment|/* ACK hash chain */
name|TAILQ_ENTRY
argument_list|(
argument|nfsrvcache
argument_list|)
name|rc_lru
expr_stmt|;
comment|/* UDP lru chain */
name|u_int32_t
name|rc_xid
decl_stmt|;
comment|/* rpc id number */
name|time_t
name|rc_timestamp
decl_stmt|;
comment|/* Time done */
union|union
block|{
name|mbuf_t
name|repmb
decl_stmt|;
comment|/* Reply mbuf list OR */
name|int
name|repstat
decl_stmt|;
comment|/* Reply status */
block|}
name|rc_un
union|;
union|union
block|{
struct|struct
block|{
name|union
name|nethostaddr
name|haddr
decl_stmt|;
comment|/* Host address */
block|}
name|udp
struct|;
struct|struct
block|{
name|u_int64_t
name|sockref
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
name|u_int32_t
name|tcpseq
decl_stmt|;
name|int16_t
name|refcnt
decl_stmt|;
name|u_int16_t
name|cksum
decl_stmt|;
name|time_t
name|cachetime
decl_stmt|;
name|int
name|acked
decl_stmt|;
block|}
name|ot
struct|;
block|}
name|rc_un2
union|;
name|u_int16_t
name|rc_proc
decl_stmt|;
comment|/* rpc proc number */
name|u_int16_t
name|rc_flag
decl_stmt|;
comment|/* Flag bits */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rc_reply
value|rc_un.repmb
end_define

begin_define
define|#
directive|define
name|rc_status
value|rc_un.repstat
end_define

begin_define
define|#
directive|define
name|rc_inet
value|rc_un2.udp.haddr.had_inet.s_addr
end_define

begin_define
define|#
directive|define
name|rc_inet6
value|rc_un2.udp.haddr.had_inet6
end_define

begin_define
define|#
directive|define
name|rc_haddr
value|rc_un2.udp.haddr
end_define

begin_define
define|#
directive|define
name|rc_sockref
value|rc_un2.ot.sockref
end_define

begin_define
define|#
directive|define
name|rc_tcpseq
value|rc_un2.ot.tcpseq
end_define

begin_define
define|#
directive|define
name|rc_refcnt
value|rc_un2.ot.refcnt
end_define

begin_define
define|#
directive|define
name|rc_reqlen
value|rc_un2.ot.len
end_define

begin_define
define|#
directive|define
name|rc_cksum
value|rc_un2.ot.cksum
end_define

begin_define
define|#
directive|define
name|rc_cachetime
value|rc_un2.ot.cachetime
end_define

begin_define
define|#
directive|define
name|rc_acked
value|rc_un2.ot.acked
end_define

begin_comment
comment|/* TCP ACK values */
end_comment

begin_define
define|#
directive|define
name|RC_NO_SEQ
value|0
end_define

begin_define
define|#
directive|define
name|RC_NO_ACK
value|1
end_define

begin_define
define|#
directive|define
name|RC_ACK
value|2
end_define

begin_define
define|#
directive|define
name|RC_NACK
value|3
end_define

begin_comment
comment|/* Return values */
end_comment

begin_define
define|#
directive|define
name|RC_DROPIT
value|0
end_define

begin_define
define|#
directive|define
name|RC_REPLY
value|1
end_define

begin_define
define|#
directive|define
name|RC_DOIT
value|2
end_define

begin_comment
comment|/* Flag bits */
end_comment

begin_define
define|#
directive|define
name|RC_LOCKED
value|0x0001
end_define

begin_define
define|#
directive|define
name|RC_WANTED
value|0x0002
end_define

begin_define
define|#
directive|define
name|RC_REPSTATUS
value|0x0004
end_define

begin_define
define|#
directive|define
name|RC_REPMBUF
value|0x0008
end_define

begin_define
define|#
directive|define
name|RC_UDP
value|0x0010
end_define

begin_define
define|#
directive|define
name|RC_INETIPV6
value|0x0020
end_define

begin_define
define|#
directive|define
name|RC_INPROG
value|0x0040
end_define

begin_define
define|#
directive|define
name|RC_NFSV2
value|0x0100
end_define

begin_define
define|#
directive|define
name|RC_NFSV3
value|0x0200
end_define

begin_define
define|#
directive|define
name|RC_NFSV4
value|0x0400
end_define

begin_define
define|#
directive|define
name|RC_NFSVERS
value|(RC_NFSV2 | RC_NFSV3 | RC_NFSV4)
end_define

begin_define
define|#
directive|define
name|RC_REFCNT
value|0x0800
end_define

begin_define
define|#
directive|define
name|RC_SAMETCPCONN
value|0x1000
end_define

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfsrvhashhead
argument_list|,
name|nfsrvcache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The fine-grained locked cache hash table for TCP. */
end_comment

begin_struct
struct|struct
name|nfsrchash_bucket
block|{
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|nfsrvhashhead
name|tbl
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSRVCACHE_H_ */
end_comment

end_unit

