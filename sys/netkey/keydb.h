begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETKEY_KEYDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETKEY_KEYDB_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Security Assocciation Index */
end_comment

begin_comment
comment|/* NOTE: Encure to be same address family */
end_comment

begin_struct
struct|struct
name|secasindex
block|{
name|struct
name|sockaddr_storage
name|src
decl_stmt|;
comment|/* srouce address for SA */
name|struct
name|sockaddr_storage
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
argument|struct secashead
argument_list|)
name|chain
expr_stmt|;
name|struct
name|secasindex
name|saidx
decl_stmt|;
name|struct
name|secpolicyindex
modifier|*
name|owner
decl_stmt|;
comment|/* Indicate it who owned its SA. */
comment|/* If NULL then it's shared SA */
name|u_int8_t
name|state
decl_stmt|;
comment|/* MATURE or DEAD. */
name|LIST_HEAD
argument_list|(
argument|_satree
argument_list|,
argument|struct secasvar
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
comment|/* XXX */
block|}
struct|;
end_struct

begin_comment
comment|/* Security Association */
end_comment

begin_struct
struct|struct
name|secasvar
block|{
name|LIST_ENTRY
argument_list|(
argument|struct secasvar
argument_list|)
name|chain
expr_stmt|;
name|int
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
name|u_int32_t
name|spi
decl_stmt|;
comment|/* SPI Value, network byte order */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* holder for SADB_KEY_FLAGS */
name|struct
name|sadb_key
modifier|*
name|key_auth
decl_stmt|;
comment|/* Key for Authentication */
comment|/* length has been shifted up to 3. */
name|struct
name|sadb_key
modifier|*
name|key_enc
decl_stmt|;
comment|/* Key for Encryption */
comment|/* length has been shifted up to 3. */
name|caddr_t
name|iv
decl_stmt|;
comment|/* Initilization Vector */
name|u_int
name|ivlen
decl_stmt|;
comment|/* length of IV */
name|struct
name|secreplay
modifier|*
name|replay
decl_stmt|;
comment|/* replay prevention */
name|u_int32_t
name|tick
decl_stmt|;
comment|/* for lifetime */
name|struct
name|sadb_lifetime
modifier|*
name|lft_c
decl_stmt|;
comment|/* CURRENT lifetime, it's constant. */
name|struct
name|sadb_lifetime
modifier|*
name|lft_h
decl_stmt|;
comment|/* HARD lifetime */
name|struct
name|sadb_lifetime
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
block|}
struct|;
end_struct

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
argument|struct secreg
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

begin_ifndef
ifndef|#
directive|ifndef
name|IPSEC_NONBLOCK_ACQUIRE
end_ifndef

begin_comment
comment|/* acquiring list table. */
end_comment

begin_struct
struct|struct
name|secacq
block|{
name|LIST_ENTRY
argument_list|(
argument|struct secacq
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
name|u_int32_t
name|tick
decl_stmt|;
comment|/* for lifetime */
name|int
name|count
decl_stmt|;
comment|/* for lifetime */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

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

begin_struct
struct|struct
name|key_cb
block|{
name|int
name|key_count
decl_stmt|;
name|int
name|any_count
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* _NETKEY_KEYDB_H_ */
end_comment

end_unit

