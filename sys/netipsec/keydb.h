begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: keydb.h,v 1.14 2000/08/02 17:58:26 sakane Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/counter.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

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
comment|/* source address for SA */
name|union
name|sockaddr_union
name|dst
decl_stmt|;
comment|/* destination address for SA */
name|uint8_t
name|proto
decl_stmt|;
comment|/* IPPROTO_ESP or IPPROTO_AH */
name|uint8_t
name|mode
decl_stmt|;
comment|/* mode of protocol, see ipsec.h */
name|uint32_t
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

begin_struct
struct|struct
name|secnatt
block|{
name|union
name|sockaddr_union
name|oai
decl_stmt|;
comment|/* original addresses of initiator */
name|union
name|sockaddr_union
name|oar
decl_stmt|;
comment|/* original address of responder */
name|uint16_t
name|sport
decl_stmt|;
comment|/* source port */
name|uint16_t
name|dport
decl_stmt|;
comment|/* destination port */
name|uint16_t
name|cksum
decl_stmt|;
comment|/* checksum delta */
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|IPSEC_NATT_F_OAI
value|0x0001
define|#
directive|define
name|IPSEC_NATT_F_OAR
value|0x0002
block|}
struct|;
end_struct

begin_comment
comment|/* Security Association Data Base */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|secasvar_queue
argument_list|,
name|secasvar
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|secashead
block|{
name|TAILQ_ENTRY
argument_list|(
argument|secashead
argument_list|)
name|chain
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|secashead
argument_list|)
name|addrhash
expr_stmt|;
comment|/* hash by sproto+src+dst addresses */
name|LIST_ENTRY
argument_list|(
argument|secashead
argument_list|)
name|drainq
expr_stmt|;
comment|/* used ONLY by flush callout */
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
specifier|volatile
name|u_int
name|refcnt
decl_stmt|;
comment|/* reference count */
name|uint8_t
name|state
decl_stmt|;
comment|/* MATURE or DEAD. */
name|struct
name|secasvar_queue
name|savtree_alive
decl_stmt|;
comment|/* MATURE and DYING SA */
name|struct
name|secasvar_queue
name|savtree_larval
decl_stmt|;
comment|/* LARVAL SA */
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
comment|/*  * Security Association  *  * For INBOUND packets we do SA lookup using SPI, thus only SPIHASH is used.  * For OUTBOUND packets there may be several SA suitable for packet.  * We use key_preferred_oldsa variable to choose better SA. First of we do  * lookup for suitable SAH using packet's saidx. Then we use SAH's savtree  * to search better candidate. The newer SA (by created time) are placed  * in the beginning of the savtree list. There is no preference between  * DYING and MATURE.  *  * NB: Fields with a tdb_ prefix are part of the "glue" used  *     to interface to the OpenBSD crypto support.  This was done  *     to distinguish this code from the mainline KAME code.  * NB: Fields are sorted on the basis of the frequency of changes, i.e.  *     constants and unchangeable fields are going first.  * NB: if you want to change this structure, check that this will not break  *     key_updateaddresses().  */
end_comment

begin_struct
struct|struct
name|secasvar
block|{
name|uint32_t
name|spi
decl_stmt|;
comment|/* SPI Value, network byte order */
name|uint32_t
name|flags
decl_stmt|;
comment|/* holder for SADB_KEY_FLAGS */
name|uint32_t
name|seq
decl_stmt|;
comment|/* sequence number */
name|pid_t
name|pid
decl_stmt|;
comment|/* message's pid */
name|u_int
name|ivlen
decl_stmt|;
comment|/* length of IV */
name|struct
name|secashead
modifier|*
name|sah
decl_stmt|;
comment|/* back pointer to the secashead */
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
name|struct
name|secreplay
modifier|*
name|replay
decl_stmt|;
comment|/* replay prevention */
name|struct
name|secnatt
modifier|*
name|natt
decl_stmt|;
comment|/* NAT-T config */
name|struct
name|mtx
modifier|*
name|lock
decl_stmt|;
comment|/* update/access lock */
specifier|const
name|struct
name|xformsw
modifier|*
name|tdb_xform
decl_stmt|;
comment|/* transform */
specifier|const
name|struct
name|enc_xform
modifier|*
name|tdb_encalgxform
decl_stmt|;
comment|/* encoding algorithm */
specifier|const
name|struct
name|auth_hash
modifier|*
name|tdb_authalgxform
decl_stmt|;
comment|/* authentication algorithm */
specifier|const
name|struct
name|comp_algo
modifier|*
name|tdb_compalgxform
decl_stmt|;
comment|/* compression algorithm */
name|uint64_t
name|tdb_cryptoid
decl_stmt|;
comment|/* crypto session id */
name|uint8_t
name|alg_auth
decl_stmt|;
comment|/* Authentication Algorithm Identifier*/
name|uint8_t
name|alg_enc
decl_stmt|;
comment|/* Cipher Algorithm Identifier */
name|uint8_t
name|alg_comp
decl_stmt|;
comment|/* Compression Algorithm Identifier */
name|uint8_t
name|state
decl_stmt|;
comment|/* Status of this SA (pfkeyv2.h) */
name|counter_u64_t
name|lft_c
decl_stmt|;
comment|/* CURRENT lifetime */
define|#
directive|define
name|lft_c_allocations
value|lft_c
define|#
directive|define
name|lft_c_bytes
value|lft_c + 1
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
name|uint64_t
name|created
decl_stmt|;
comment|/* time when SA was created */
name|uint64_t
name|firstused
decl_stmt|;
comment|/* time when SA was first used */
name|TAILQ_ENTRY
argument_list|(
argument|secasvar
argument_list|)
name|chain
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|secasvar
argument_list|)
name|spihash
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|secasvar
argument_list|)
name|drainq
expr_stmt|;
comment|/* used ONLY by flush callout */
name|uint64_t
name|cntr
decl_stmt|;
comment|/* counter for GCM and CTR */
specifier|volatile
name|u_int
name|refcnt
decl_stmt|;
comment|/* reference count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SECASVAR_LOCK
parameter_list|(
name|_sav
parameter_list|)
value|mtx_lock((_sav)->lock)
end_define

begin_define
define|#
directive|define
name|SECASVAR_UNLOCK
parameter_list|(
name|_sav
parameter_list|)
value|mtx_unlock((_sav)->lock)
end_define

begin_define
define|#
directive|define
name|SECASVAR_LOCK_ASSERT
parameter_list|(
name|_sav
parameter_list|)
value|mtx_assert((_sav)->lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|SAV_ISGCM
parameter_list|(
name|_sav
parameter_list|)
define|\
value|((_sav)->alg_enc == SADB_X_EALG_AESGCM8 ||	\ 			(_sav)->alg_enc == SADB_X_EALG_AESGCM12 ||	\ 			(_sav)->alg_enc == SADB_X_EALG_AESGCM16)
end_define

begin_define
define|#
directive|define
name|SAV_ISCTR
parameter_list|(
name|_sav
parameter_list|)
value|((_sav)->alg_enc == SADB_X_EALG_AESCTR)
end_define

begin_define
define|#
directive|define
name|SAV_ISCTRORGCM
parameter_list|(
name|_sav
parameter_list|)
value|(SAV_ISCTR((_sav)) || SAV_ISGCM((_sav)))
end_define

begin_comment
comment|/* Replay prevention, protected by SECASVAR_LOCK:  *  (m) locked by mtx  *  (c) read only except during creation / free  */
end_comment

begin_struct
struct|struct
name|secreplay
block|{
name|u_int32_t
name|count
decl_stmt|;
comment|/* (m) */
name|u_int
name|wsize
decl_stmt|;
comment|/* (c) window size, i.g. 4 bytes */
name|u_int32_t
name|seq
decl_stmt|;
comment|/* (m) used by sender */
name|u_int32_t
name|lastseq
decl_stmt|;
comment|/* (m) used by receiver */
name|u_int32_t
modifier|*
name|bitmap
decl_stmt|;
comment|/* (m) used by receiver */
name|u_int
name|bitmap_size
decl_stmt|;
comment|/* (c) size of the bitmap array */
name|int
name|overflow
decl_stmt|;
comment|/* (m) overflow flag */
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
name|LIST_ENTRY
argument_list|(
argument|secacq
argument_list|)
name|addrhash
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|secacq
argument_list|)
name|seqhash
expr_stmt|;
name|struct
name|secasindex
name|saidx
decl_stmt|;
name|uint32_t
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

