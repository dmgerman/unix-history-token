begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsrvcache.h	8.3 (Berkeley) 3/30/95  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Definitions for the server recent request cache  */
end_comment

begin_define
define|#
directive|define
name|NFSRVCACHESIZ
value|64
end_define

begin_struct
struct|struct
name|nfsrvcache
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfsrvcache
argument_list|)
name|rc_lru
expr_stmt|;
comment|/* LRU chain */
name|LIST_ENTRY
argument_list|(
argument|nfsrvcache
argument_list|)
name|rc_hash
expr_stmt|;
comment|/* Hash chain */
name|u_int32_t
name|rc_xid
decl_stmt|;
comment|/* rpc id number */
union|union
block|{
name|struct
name|mbuf
modifier|*
name|ru_repmb
decl_stmt|;
comment|/* Reply mbuf list OR */
name|int
name|ru_repstat
decl_stmt|;
comment|/* Reply status */
block|}
name|rc_un
union|;
name|union
name|nethostaddr
name|rc_haddr
decl_stmt|;
comment|/* Host address */
name|u_int32_t
name|rc_proc
decl_stmt|;
comment|/* rpc proc number */
name|u_char
name|rc_state
decl_stmt|;
comment|/* Current state of request */
name|u_char
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
value|rc_un.ru_repmb
end_define

begin_define
define|#
directive|define
name|rc_status
value|rc_un.ru_repstat
end_define

begin_define
define|#
directive|define
name|rc_inetaddr
value|rc_haddr.had_inetaddr
end_define

begin_define
define|#
directive|define
name|rc_nam
value|rc_haddr.had_nam
end_define

begin_comment
comment|/* Cache entry states */
end_comment

begin_define
define|#
directive|define
name|RC_UNUSED
value|0
end_define

begin_define
define|#
directive|define
name|RC_INPROG
value|1
end_define

begin_define
define|#
directive|define
name|RC_DONE
value|2
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

begin_define
define|#
directive|define
name|RC_CHECKIT
value|3
end_define

begin_comment
comment|/* Flag bits */
end_comment

begin_define
define|#
directive|define
name|RC_LOCKED
value|0x01
end_define

begin_define
define|#
directive|define
name|RC_WANTED
value|0x02
end_define

begin_define
define|#
directive|define
name|RC_REPSTATUS
value|0x04
end_define

begin_define
define|#
directive|define
name|RC_REPMBUF
value|0x08
end_define

begin_define
define|#
directive|define
name|RC_NQNFS
value|0x10
end_define

begin_define
define|#
directive|define
name|RC_INETADDR
value|0x20
end_define

begin_define
define|#
directive|define
name|RC_NAM
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

