begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2006, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HAVE_SHA2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__SCTP_AUTH_H__
end_ifndef

begin_define
define|#
directive|define
name|__SCTP_AUTH_H__
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SCTP_SHA1
end_ifdef

begin_include
include|#
directive|include
file|<netinet/sctp_sha1.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<crypto/sha1.h>
end_include

begin_comment
comment|/* map standard crypto API names */
end_comment

begin_define
define|#
directive|define
name|SHA1_Init
value|SHA1Init
end_define

begin_define
define|#
directive|define
name|SHA1_Update
value|SHA1Update
end_define

begin_define
define|#
directive|define
name|SHA1_Final
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|SHA1Final((caddr_t)x, y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SHA2
argument_list|)
end_if

begin_include
include|#
directive|include
file|<crypto/sha2/sha2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_comment
comment|/* map standard crypto API names */
end_comment

begin_define
define|#
directive|define
name|MD5_Init
value|MD5Init
end_define

begin_define
define|#
directive|define
name|MD5_Update
value|MD5Update
end_define

begin_define
define|#
directive|define
name|MD5_Final
value|MD5Final
end_define

begin_comment
comment|/* digest lengths */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTH_DIGEST_LEN_SHA1
value|20
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_DIGEST_LEN_MD5
value|16
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_DIGEST_LEN_SHA224
value|28
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_DIGEST_LEN_SHA256
value|32
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_DIGEST_LEN_SHA384
value|48
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_DIGEST_LEN_SHA512
value|64
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_DIGEST_LEN_MAX
value|64
end_define

begin_comment
comment|/* random sizes */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTH_RANDOM_SIZE_DEFAULT
value|32
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_RANDOM_SIZE_REQUIRED
value|32
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_RANDOM_SIZE_MAX
value|256
end_define

begin_comment
comment|/* union of all supported HMAC algorithm contexts */
end_comment

begin_typedef
typedef|typedef
union|union
name|sctp_hash_context
block|{
name|SHA1_CTX
name|sha1
decl_stmt|;
name|MD5_CTX
name|md5
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_SHA2
name|SHA256_CTX
name|sha256
decl_stmt|;
name|SHA384_CTX
name|sha384
decl_stmt|;
name|SHA512_CTX
name|sha512
decl_stmt|;
endif|#
directive|endif
block|}
name|sctp_hash_context_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|sctp_key
block|{
name|uint32_t
name|keylen
decl_stmt|;
name|uint8_t
name|key
index|[
literal|0
index|]
decl_stmt|;
block|}
name|sctp_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|sctp_shared_key
block|{
name|LIST_ENTRY
argument_list|(
argument|sctp_shared_key
argument_list|)
name|next
expr_stmt|;
name|sctp_key_t
modifier|*
name|key
decl_stmt|;
comment|/* key text */
name|uint16_t
name|keyid
decl_stmt|;
comment|/* shared key ID */
block|}
name|sctp_sharedkey_t
typedef|;
end_typedef

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|sctp_keyhead
argument_list|,
name|sctp_shared_key
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* authentication chunks list */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sctp_auth_chklist
block|{
name|uint8_t
name|chunks
index|[
literal|256
index|]
decl_stmt|;
name|uint8_t
name|num_chunks
decl_stmt|;
block|}
name|sctp_auth_chklist_t
typedef|;
end_typedef

begin_comment
comment|/* hmac algos supported list */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sctp_hmaclist
block|{
name|uint16_t
name|max_algo
decl_stmt|;
comment|/* max algorithms allocated */
name|uint16_t
name|num_algo
decl_stmt|;
comment|/* num algorithms used */
name|uint16_t
name|hmac
index|[
literal|0
index|]
decl_stmt|;
block|}
name|sctp_hmaclist_t
typedef|;
end_typedef

begin_comment
comment|/* authentication info */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sctp_authinfo
block|{
name|sctp_key_t
modifier|*
name|random
decl_stmt|;
comment|/* local random key (concatenated) */
name|uint32_t
name|random_len
decl_stmt|;
comment|/* local random number length for param */
name|sctp_key_t
modifier|*
name|peer_random
decl_stmt|;
comment|/* peer's random key (concatenated) */
name|uint16_t
name|assoc_keyid
decl_stmt|;
comment|/* current send keyid (cached) */
name|uint16_t
name|recv_keyid
decl_stmt|;
comment|/* last recv keyid (cached) */
name|sctp_key_t
modifier|*
name|assoc_key
decl_stmt|;
comment|/* cached send key */
name|sctp_key_t
modifier|*
name|recv_key
decl_stmt|;
comment|/* cached recv key */
block|}
name|sctp_authinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * global variables  */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_asconf_auth_nochk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sysctl to disable ASCONF auth chk */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_auth_disable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sysctl for temp feature interop */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_auth_random_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sysctl */
end_comment

begin_comment
comment|/*  * Macros  */
end_comment

begin_define
define|#
directive|define
name|sctp_auth_is_required_chunk
parameter_list|(
name|chunk
parameter_list|,
name|list
parameter_list|)
value|((list == NULL) ? (0) : (list->chunks[chunk] != 0))
end_define

begin_comment
comment|/*  * function prototypes  */
end_comment

begin_comment
comment|/* socket option api functions */
end_comment

begin_function_decl
specifier|extern
name|sctp_auth_chklist_t
modifier|*
name|sctp_alloc_chunklist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_free_chunklist
parameter_list|(
name|sctp_auth_chklist_t
modifier|*
name|chklist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_clear_chunklist
parameter_list|(
name|sctp_auth_chklist_t
modifier|*
name|chklist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sctp_auth_chklist_t
modifier|*
name|sctp_copy_chunklist
parameter_list|(
name|sctp_auth_chklist_t
modifier|*
name|chklist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_auth_add_chunk
parameter_list|(
name|uint8_t
name|chunk
parameter_list|,
name|sctp_auth_chklist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_auth_delete_chunk
parameter_list|(
name|uint8_t
name|chunk
parameter_list|,
name|sctp_auth_chklist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_auth_get_chklist_size
parameter_list|(
specifier|const
name|sctp_auth_chklist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_auth_set_default_chunks
parameter_list|(
name|sctp_auth_chklist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_serialize_auth_chunks
parameter_list|(
specifier|const
name|sctp_auth_chklist_t
modifier|*
name|list
parameter_list|,
name|uint8_t
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_pack_auth_chunks
parameter_list|(
specifier|const
name|sctp_auth_chklist_t
modifier|*
name|list
parameter_list|,
name|uint8_t
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_unpack_auth_chunks
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|ptr
parameter_list|,
name|uint8_t
name|num_chunks
parameter_list|,
name|sctp_auth_chklist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* key handling */
end_comment

begin_function_decl
specifier|extern
name|sctp_key_t
modifier|*
name|sctp_alloc_key
parameter_list|(
name|uint32_t
name|keylen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_free_key
parameter_list|(
name|sctp_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_print_key
parameter_list|(
name|sctp_key_t
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_show_key
parameter_list|(
name|sctp_key_t
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sctp_key_t
modifier|*
name|sctp_generate_random_key
parameter_list|(
name|uint32_t
name|keylen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sctp_key_t
modifier|*
name|sctp_set_key
parameter_list|(
name|uint8_t
modifier|*
name|key
parameter_list|,
name|uint32_t
name|keylen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sctp_key_t
modifier|*
name|sctp_compute_hashkey
parameter_list|(
name|sctp_key_t
modifier|*
name|key1
parameter_list|,
name|sctp_key_t
modifier|*
name|key2
parameter_list|,
name|sctp_key_t
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* shared key handling */
end_comment

begin_function_decl
specifier|extern
name|sctp_sharedkey_t
modifier|*
name|sctp_alloc_sharedkey
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_free_sharedkey
parameter_list|(
name|sctp_sharedkey_t
modifier|*
name|skey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sctp_sharedkey_t
modifier|*
name|sctp_find_sharedkey
parameter_list|(
name|struct
name|sctp_keyhead
modifier|*
name|shared_keys
parameter_list|,
name|uint16_t
name|key_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_insert_sharedkey
parameter_list|(
name|struct
name|sctp_keyhead
modifier|*
name|shared_keys
parameter_list|,
name|sctp_sharedkey_t
modifier|*
name|new_skey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_copy_skeylist
parameter_list|(
specifier|const
name|struct
name|sctp_keyhead
modifier|*
name|src
parameter_list|,
name|struct
name|sctp_keyhead
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* hmac list handling */
end_comment

begin_function_decl
specifier|extern
name|sctp_hmaclist_t
modifier|*
name|sctp_alloc_hmaclist
parameter_list|(
name|uint8_t
name|num_hmacs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_free_hmaclist
parameter_list|(
name|sctp_hmaclist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_auth_add_hmacid
parameter_list|(
name|sctp_hmaclist_t
modifier|*
name|list
parameter_list|,
name|uint16_t
name|hmac_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sctp_hmaclist_t
modifier|*
name|sctp_copy_hmaclist
parameter_list|(
name|sctp_hmaclist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sctp_hmaclist_t
modifier|*
name|sctp_default_supported_hmaclist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint16_t
name|sctp_negotiate_hmacid
parameter_list|(
name|sctp_hmaclist_t
modifier|*
name|peer
parameter_list|,
name|sctp_hmaclist_t
modifier|*
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_serialize_hmaclist
parameter_list|(
name|sctp_hmaclist_t
modifier|*
name|list
parameter_list|,
name|uint8_t
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_verify_hmac_param
parameter_list|(
name|struct
name|sctp_auth_hmac_algo
modifier|*
name|hmacs
parameter_list|,
name|uint32_t
name|num_hmacs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sctp_authinfo_t
modifier|*
name|sctp_alloc_authinfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_free_authinfo
parameter_list|(
name|sctp_authinfo_t
modifier|*
name|authinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* keyed-HMAC functions */
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|sctp_get_auth_chunk_len
parameter_list|(
name|uint16_t
name|hmac_algo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|sctp_get_hmac_digest_len
parameter_list|(
name|uint16_t
name|hmac_algo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|sctp_hmac
parameter_list|(
name|uint16_t
name|hmac_algo
parameter_list|,
name|uint8_t
modifier|*
name|key
parameter_list|,
name|uint32_t
name|keylen
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|text
parameter_list|,
name|uint32_t
name|textlen
parameter_list|,
name|uint8_t
modifier|*
name|digest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_verify_hmac
parameter_list|(
name|uint16_t
name|hmac_algo
parameter_list|,
name|uint8_t
modifier|*
name|key
parameter_list|,
name|uint32_t
name|keylen
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|text
parameter_list|,
name|uint32_t
name|textlen
parameter_list|,
name|uint8_t
modifier|*
name|digest
parameter_list|,
name|uint32_t
name|digestlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|sctp_compute_hmac
parameter_list|(
name|uint16_t
name|hmac_algo
parameter_list|,
name|sctp_key_t
modifier|*
name|key
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|text
parameter_list|,
name|uint32_t
name|textlen
parameter_list|,
name|uint8_t
modifier|*
name|digest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_auth_is_supported_hmac
parameter_list|(
name|sctp_hmaclist_t
modifier|*
name|list
parameter_list|,
name|uint16_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mbuf versions */
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|sctp_hmac_m
parameter_list|(
name|uint16_t
name|hmac_algo
parameter_list|,
name|uint8_t
modifier|*
name|key
parameter_list|,
name|uint32_t
name|keylen
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint32_t
name|m_offset
parameter_list|,
name|uint8_t
modifier|*
name|digest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|sctp_compute_hmac_m
parameter_list|(
name|uint16_t
name|hmac_algo
parameter_list|,
name|sctp_key_t
modifier|*
name|key
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint32_t
name|m_offset
parameter_list|,
name|uint8_t
modifier|*
name|digest
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * authentication routines  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sctp_clear_cachedkeys
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|uint16_t
name|keyid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_clear_cachedkeys_ep
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
name|inp
parameter_list|,
name|uint16_t
name|keyid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_delete_sharedkey
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|uint16_t
name|keyid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_delete_sharedkey_ep
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
name|inp
parameter_list|,
name|uint16_t
name|keyid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_auth_setactivekey
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|uint16_t
name|keyid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_auth_setactivekey_ep
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
name|inp
parameter_list|,
name|uint16_t
name|keyid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_auth_get_cookie_params
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_fill_hmac_digest_m
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint32_t
name|auth_offset
parameter_list|,
name|struct
name|sctp_auth_chunk
modifier|*
name|auth
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|sctp_add_auth_chunk
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|m_end
parameter_list|,
name|struct
name|sctp_auth_chunk
modifier|*
modifier|*
name|auth_ret
parameter_list|,
name|uint32_t
modifier|*
name|offset
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|uint8_t
name|chunk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_handle_auth
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_auth_chunk
modifier|*
name|ch
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint32_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_notify_authentication
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|uint32_t
name|indication
parameter_list|,
name|uint16_t
name|keyid
parameter_list|,
name|uint16_t
name|alt_keyid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sctp_validate_init_auth_params
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|limit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_initialize_auth_params
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
name|inp
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* test functions */
end_comment

begin_function_decl
specifier|extern
name|void
name|sctp_test_hmac_sha1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_test_hmac_md5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sctp_test_authkey
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SCTP_AUTH_H__ */
end_comment

end_unit

