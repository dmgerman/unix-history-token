begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From:	@(#)nfsrvcache.h	7.3 (Berkeley) 6/28/90  *	$Id: nfsrvcache.h,v 1.2 1993/09/09 22:06:26 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__h_nfsrvcache
end_ifndef

begin_define
define|#
directive|define
name|__h_nfsrvcache
value|1
end_define

begin_comment
comment|/*  * Definitions for the server recent request cache  */
end_comment

begin_define
define|#
directive|define
name|NFSRVCACHESIZ
value|128
end_define

begin_define
define|#
directive|define
name|NFSRCHSZ
value|32
end_define

begin_struct
struct|struct
name|nfsrvcache
block|{
name|struct
name|nfsrvcache
modifier|*
name|rc_chain
index|[
literal|2
index|]
decl_stmt|;
comment|/* Hash chain links */
name|struct
name|nfsrvcache
modifier|*
name|rc_next
decl_stmt|;
comment|/* Lru list */
name|struct
name|nfsrvcache
modifier|*
name|rc_prev
decl_stmt|;
name|int
name|rc_state
decl_stmt|;
comment|/* Current state of request */
name|int
name|rc_flag
decl_stmt|;
comment|/* Flag bits */
name|struct
name|mbuf
name|rc_nam
decl_stmt|;
comment|/* Sockaddr of requestor */
name|u_long
name|rc_xid
decl_stmt|;
comment|/* rpc id number */
name|int
name|rc_proc
decl_stmt|;
comment|/* rpc proc number */
name|long
name|rc_timestamp
decl_stmt|;
comment|/* Time stamp */
union|union
block|{
name|struct
name|mbuf
modifier|*
name|rc_repmb
decl_stmt|;
comment|/* Reply mbuf list OR */
name|int
name|rc_repstat
decl_stmt|;
comment|/* Reply status */
block|}
name|rc_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rc_forw
value|rc_chain[0]
end_define

begin_define
define|#
directive|define
name|rc_back
value|rc_chain[1]
end_define

begin_define
define|#
directive|define
name|rc_status
value|rc_un.rc_repstat
end_define

begin_define
define|#
directive|define
name|rc_reply
value|rc_un.rc_repmb
end_define

begin_define
define|#
directive|define
name|put_at_head
parameter_list|(
name|rp
parameter_list|)
define|\
value|(rp)->rc_prev->rc_next = (rp)->rc_next; \ 		(rp)->rc_next->rc_prev = (rp)->rc_prev; \ 		(rp)->rc_next = nfsrvcachehead.rc_next; \ 		(rp)->rc_next->rc_prev = (rp); \ 		nfsrvcachehead.rc_next = (rp); \ 		(rp)->rc_prev =&nfsrvcachehead
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

begin_comment
comment|/* Flag bits */
end_comment

begin_define
define|#
directive|define
name|RC_LOCKED
value|0x1
end_define

begin_define
define|#
directive|define
name|RC_WANTED
value|0x2
end_define

begin_define
define|#
directive|define
name|RC_REPSTATUS
value|0x4
end_define

begin_define
define|#
directive|define
name|RC_REPMBUF
value|0x8
end_define

begin_comment
comment|/* Delay time after completion that request is dropped */
end_comment

begin_define
define|#
directive|define
name|RC_DELAY
value|2
end_define

begin_comment
comment|/* seconds */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|void
name|nfsrv_initcache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nfsrv_getcache
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nfsrv_updatecache
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __h_nfsrvcache */
end_comment

end_unit

