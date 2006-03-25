begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: keydb.h,v 1.14 2000/08/02 17:58:26 sakane Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPSEC_KEYDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPSEC_KEYDB_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<netipsec/key_var.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SOCKADDR_UNION_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_SOCKADDR_UNION_DEFINED
end_define

begin_comment
comment|/*  * The union of all possible address formats we handle.  */
end_comment

begin_union
union|union
name|sockaddr_union
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
name|struct
name|sockaddr_in6
name|sin6
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SOCKADDR_UNION_DEFINED */
end_comment

begin_comment
comment|/* Security Assocciation Index */
end_comment

begin_comment
comment|/* NOTE: Ensure to be same address family */
end_comment

begin_struct
struct|struct
name|secasindex
block|{
name|union
name|sockaddr_union
name|src
decl_stmt|;
comment|/* srouce address for SA */
name|union
name|sockaddr_union
name|dst
decl_stmt|;
comment|/* destination address for SA */
name|u_int16_t
name|proto
decl_stmt|;
comment|/* IPPROTO_ESP or IPPROTO_AH */
name|u_int8_t
name|mode
decl_stmt|;
comment|/* mode of protocol, see ipsec.h */
name|u_int32_t
name|reqid
decl_stmt|;
comment|/* reqid id who owned this SA */
comment|/* see IPSEC_MANUAL_REQID_MAX. */
block|}
struct|;
end_struct

begin_comment
comment|/*   * In order to split out the keydb implementation from that of the  * PF_KEY sockets we need to define a few structures that while they  * may seem common are likely to diverge over time.   */
end_comment

begin_comment
comment|/* sadb_identity */
end_comment

begin_struct
struct|struct
name|secident
block|{
name|u_int16_t
name|type
decl_stmt|;
name|u_int64_t
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sadb_key */
end_comment

begin_struct
struct|struct
name|seckey
block|{
name|u_int16_t
name|bits
decl_stmt|;
name|char
modifier|*
name|key_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|seclifetime
block|{
name|u_int32_t
name|allocations
decl_stmt|;
name|u_int64_t
name|bytes
decl_stmt|;
name|u_int64_t
name|addtime
decl_stmt|;
name|u_int64_t
name|usetime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Security Association Data Base */
end_comment

begin_struct
struct|struct
name|secashead
block|{
name|LIST_ENTRY
argument_list|(
argument|secashead
argument_list|)
name|chain
expr_stmt|;
name|struct
name|secasindex
name|saidx
decl_stmt|;
name|struct
name|secident
modifier|*
name|idents
decl_stmt|;
comment|/* source identity */
name|struct
name|secident
modifier|*
name|identd
decl_stmt|;
comment|/* destination identity */
comment|/* XXX I don't know how to use them. */
name|u_int8_t
name|state
decl_stmt|;
comment|/* MATURE or DEAD. */
name|LIST_HEAD
argument_list|(
argument|_satree
argument_list|,
argument|secasvar
argument_list|)
name|savtree
index|[
name|SADB_SASTATE_MAX
operator|+
literal|1
index|]
expr_stmt|;
comment|/* SA chain */
comment|/* The first of this list is newer SA */
name|struct
name|route
name|sa_route
decl_stmt|;
comment|/* route cache */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|xformsw
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|enc_xform
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|auth_hash
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comp_algo
struct_decl|;
end_struct_decl

begin_comment
comment|/* Security Association */
end_comment

begin_struct
struct|struct
name|secasvar
block|{
name|LIST_ENTRY
argument_list|(
argument|secasvar
argument_list|)
name|chain
expr_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
comment|/* update/access lock */
name|u_int
name|refcnt
decl_stmt|;
comment|/* reference count */
name|u_int8_t
name|state
decl_stmt|;
comment|/* Status of this Association */
name|u_int8_t
name|alg_auth
decl_stmt|;
comment|/* Authentication Algorithm Identifier*/
name|u_int8_t
name|alg_enc
decl_stmt|;
comment|/* Cipher Algorithm Identifier */
name|u_int8_t
name|alg_comp
decl_stmt|;
comment|/* Compression Algorithm Identifier */
name|u_int32_t
name|spi
decl_stmt|;
comment|/* SPI Value, network byte order */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* holder for SADB_KEY_FLAGS */
name|struct
name|seckey
modifier|*
name|key_auth
decl_stmt|;
comment|/* Key for Authentication */
name|struct
name|seckey
modifier|*
name|key_enc
decl_stmt|;
comment|/* Key for Encryption */
name|caddr_t
name|iv
decl_stmt|;
comment|/* Initilization Vector */
name|u_int
name|ivlen
decl_stmt|;
comment|/* length of IV */
name|void
modifier|*
name|sched
decl_stmt|;
comment|/* intermediate encryption key */
name|size_t
name|schedlen
decl_stmt|;
name|struct
name|secreplay
modifier|*
name|replay
decl_stmt|;
comment|/* replay prevention */
name|time_t
name|created
decl_stmt|;
comment|/* for lifetime */
name|struct
name|seclifetime
modifier|*
name|lft_c
decl_stmt|;
comment|/* CURRENT lifetime, it's constant. */
name|struct
name|seclifetime
modifier|*
name|lft_h
decl_stmt|;
comment|/* HARD lifetime */
name|struct
name|seclifetime
modifier|*
name|lft_s
decl_stmt|;
comment|/* SOFT lifetime */
name|u_int32_t
name|seq
decl_stmt|;
comment|/* sequence number */
name|pid_t
name|pid
decl_stmt|;
comment|/* message's pid */
name|struct
name|secashead
modifier|*
name|sah
decl_stmt|;
comment|/* back pointer to the secashead */
comment|/* 	 * NB: Fields with a tdb_ prefix are part of the "glue" used 	 *     to interface to the OpenBSD crypto support.  This was done 	 *     to distinguish this code from the mainline KAME code. 	 */
name|struct
name|xformsw
modifier|*
name|tdb_xform
decl_stmt|;
comment|/* transform */
name|struct
name|enc_xform
modifier|*
name|tdb_encalgxform
decl_stmt|;
comment|/* encoding algorithm */
name|struct
name|auth_hash
modifier|*
name|tdb_authalgxform
decl_stmt|;
comment|/* authentication algorithm */
name|struct
name|comp_algo
modifier|*
name|tdb_compalgxform
decl_stmt|;
comment|/* compression algorithm */
name|u_int64_t
name|tdb_cryptoid
decl_stmt|;
comment|/* crypto session id */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SECASVAR_LOCK_INIT
parameter_list|(
name|_sav
parameter_list|)
define|\
value|mtx_init(&(_sav)->lock, "ipsec association", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|SECASVAR_LOCK
parameter_list|(
name|_sav
parameter_list|)
value|mtx_lock(&(_sav)->lock)
end_define

begin_define
define|#
directive|define
name|SECASVAR_UNLOCK
parameter_list|(
name|_sav
parameter_list|)
value|mtx_unlock(&(_sav)->lock)
end_define

begin_define
define|#
directive|define
name|SECASVAR_LOCK_DESTROY
parameter_list|(
name|_sav
parameter_list|)
value|mtx_destroy(&(_sav)->lock)
end_define

begin_define
define|#
directive|define
name|SECASVAR_LOCK_ASSERT
parameter_list|(
name|_sav
parameter_list|)
value|mtx_assert(&(_sav)->lock, MA_OWNED)
end_define

begin_comment
comment|/* replay prevention */
end_comment

begin_struct
struct|struct
name|secreplay
block|{
name|u_int32_t
name|count
decl_stmt|;
name|u_int
name|wsize
decl_stmt|;
comment|/* window size, i.g. 4 bytes */
name|u_int32_t
name|seq
decl_stmt|;
comment|/* used by sender */
name|u_int32_t
name|lastseq
decl_stmt|;
comment|/* used by receiver */
name|caddr_t
name|bitmap
decl_stmt|;
comment|/* used by receiver */
name|int
name|overflow
decl_stmt|;
comment|/* overflow flag */
block|}
struct|;
end_struct

begin_comment
comment|/* socket table due to send PF_KEY messages. */
end_comment

begin_struct
struct|struct
name|secreg
block|{
name|LIST_ENTRY
argument_list|(
argument|secreg
argument_list|)
name|chain
expr_stmt|;
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* acquiring list table. */
end_comment

begin_struct
struct|struct
name|secacq
block|{
name|LIST_ENTRY
argument_list|(
argument|secacq
argument_list|)
name|chain
expr_stmt|;
name|struct
name|secasindex
name|saidx
decl_stmt|;
name|u_int32_t
name|seq
decl_stmt|;
comment|/* sequence number */
name|time_t
name|created
decl_stmt|;
comment|/* for lifetime */
name|int
name|count
decl_stmt|;
comment|/* for lifetime */
block|}
struct|;
end_struct

begin_comment
comment|/* Sensitivity Level Specification */
end_comment

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|SADB_KILL_INTERVAL
value|600
end_define

begin_comment
comment|/* six seconds */
end_comment

begin_comment
comment|/* secpolicy */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
modifier|*
name|keydb_newsecpolicy
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keydb_delsecpolicy
name|__P
argument_list|(
operator|(
expr|struct
name|secpolicy
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* secashead */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|secashead
modifier|*
name|keydb_newsecashead
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keydb_delsecashead
name|__P
argument_list|(
operator|(
expr|struct
name|secashead
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* secasvar */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|secasvar
modifier|*
name|keydb_newsecasvar
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keydb_refsecasvar
name|__P
argument_list|(
operator|(
expr|struct
name|secasvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keydb_freesecasvar
name|__P
argument_list|(
operator|(
expr|struct
name|secasvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* secreplay */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|secreplay
modifier|*
name|keydb_newsecreplay
name|__P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keydb_delsecreplay
name|__P
argument_list|(
operator|(
expr|struct
name|secreplay
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* secreg */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|secreg
modifier|*
name|keydb_newsecreg
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keydb_delsecreg
name|__P
argument_list|(
operator|(
expr|struct
name|secreg
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETIPSEC_KEYDB_H_ */
end_comment

end_unit

