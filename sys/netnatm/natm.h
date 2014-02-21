begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 Charles D. Cranor and Washington University.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Charles D. Cranor and  *      Washington University.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $NetBSD: natm.h,v 1.1 1996/07/04 03:20:12 chuck Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * natm.h: native mode atm  */
end_comment

begin_comment
comment|/*  * supported protocols  */
end_comment

begin_define
define|#
directive|define
name|PROTO_NATMAAL0
value|1
end_define

begin_define
define|#
directive|define
name|PROTO_NATMAAL5
value|2
end_define

begin_comment
comment|/*  * sockaddr_natm  */
end_comment

begin_struct
struct|struct
name|sockaddr_natm
block|{
name|unsigned
name|char
name|snatm_len
decl_stmt|;
comment|/* length */
name|sa_family_t
name|snatm_family
decl_stmt|;
comment|/* AF_NATM */
name|char
name|snatm_if
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name */
name|u_int16_t
name|snatm_vci
decl_stmt|;
comment|/* vci */
name|u_int8_t
name|snatm_vpi
decl_stmt|;
comment|/* vpi */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * natm protocol control block  */
end_comment

begin_struct
struct|struct
name|natmpcb
block|{
name|LIST_ENTRY
argument_list|(
argument|natmpcb
argument_list|)
name|pcblist
expr_stmt|;
comment|/* list pointers */
name|u_int
name|npcb_inq
decl_stmt|;
comment|/* # of our pkts in proto q */
name|struct
name|socket
modifier|*
name|npcb_socket
decl_stmt|;
comment|/* backpointer to socket */
name|struct
name|ifnet
modifier|*
name|npcb_ifp
decl_stmt|;
comment|/* pointer to hardware */
name|struct
name|in_addr
name|ipaddr
decl_stmt|;
comment|/* remote IP address, if APCB_IP */
name|u_int16_t
name|npcb_vci
decl_stmt|;
comment|/* VCI */
name|u_int8_t
name|npcb_vpi
decl_stmt|;
comment|/* VPI */
name|u_int8_t
name|npcb_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|NPCB_FREE
value|0x01
end_define

begin_comment
comment|/* free (not on any list) */
end_comment

begin_define
define|#
directive|define
name|NPCB_CONNECTED
value|0x02
end_define

begin_comment
comment|/* connected */
end_comment

begin_define
define|#
directive|define
name|NPCB_IP
value|0x04
end_define

begin_comment
comment|/* used by IP */
end_comment

begin_define
define|#
directive|define
name|NPCB_DRAIN
value|0x08
end_define

begin_comment
comment|/* destroy as soon as inq == 0 */
end_comment

begin_comment
comment|/* flag arg to npcb_free */
end_comment

begin_define
define|#
directive|define
name|NPCB_REMOVE
value|0
end_define

begin_comment
comment|/* remove from global list */
end_comment

begin_define
define|#
directive|define
name|NPCB_DESTROY
value|1
end_define

begin_comment
comment|/* destroy and be free */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|npcblist
argument_list|,
name|natmpcb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* global data structures */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|natm_mtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global netnatm lock */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|npcblist
name|natm_pcbs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global list of pcbs */
end_comment

begin_define
define|#
directive|define
name|NATM_STAT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NATM_STAT
end_ifdef

begin_decl_stmt
specifier|extern
name|u_int
name|natm_sodropcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|natm_sodropbytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* account of droppage */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|natm_sookcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|natm_sookbytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* account of ok */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* locking macros */
end_comment

begin_define
define|#
directive|define
name|NATM_LOCK_INIT
parameter_list|()
value|mtx_init(&natm_mtx, "natm_mtx", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|NATM_LOCK
parameter_list|()
value|mtx_lock(&natm_mtx)
end_define

begin_define
define|#
directive|define
name|NATM_UNLOCK
parameter_list|()
value|mtx_unlock(&natm_mtx)
end_define

begin_define
define|#
directive|define
name|NATM_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&natm_mtx, MA_OWNED)
end_define

begin_comment
comment|/* external functions */
end_comment

begin_comment
comment|/* natm_pcb.c */
end_comment

begin_function_decl
name|struct
name|natmpcb
modifier|*
name|npcb_alloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|npcb_free
parameter_list|(
name|struct
name|natmpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|natmpcb
modifier|*
name|npcb_add
parameter_list|(
name|struct
name|natmpcb
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* natm.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|natm_usrreqs
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_HANDLER_ARGS
end_ifdef

begin_function_decl
name|int
name|natm0_sysctl
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|natm5_sysctl
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|natmintr
parameter_list|(
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

end_unit

