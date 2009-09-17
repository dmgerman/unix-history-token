begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_CRYPTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_CRYPTO_H_
end_define

begin_comment
comment|/*  * 802.11 protocol crypto-related definitions.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_KEYBUF_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|IEEE80211_MICBUF_SIZE
value|(8+8)
end_define

begin_comment
comment|/* space for both tx+rx keys */
end_comment

begin_comment
comment|/*  * Old WEP-style key.  Deprecated.  */
end_comment

begin_struct
struct|struct
name|ieee80211_wepkey
block|{
name|u_int
name|wk_len
decl_stmt|;
comment|/* key length in bytes */
name|uint8_t
name|wk_key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_rsnparms
block|{
name|uint8_t
name|rsn_mcastcipher
decl_stmt|;
comment|/* mcast/group cipher */
name|uint8_t
name|rsn_mcastkeylen
decl_stmt|;
comment|/* mcast key length */
name|uint8_t
name|rsn_ucastcipher
decl_stmt|;
comment|/* selected unicast cipher */
name|uint8_t
name|rsn_ucastkeylen
decl_stmt|;
comment|/* unicast key length */
name|uint8_t
name|rsn_keymgmt
decl_stmt|;
comment|/* selected key mgmt algo */
name|uint16_t
name|rsn_caps
decl_stmt|;
comment|/* capabilities */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ieee80211_cipher
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Crypto key state.  There is sufficient room for all supported  * ciphers (see below).  The underlying ciphers are handled  * separately through loadable cipher modules that register with  * the generic crypto support.  A key has a reference to an instance  * of the cipher; any per-key state is hung off wk_private by the  * cipher when it is attached.  Ciphers are automatically called  * to detach and cleanup any such state when the key is deleted.  *  * The generic crypto support handles encap/decap of cipher-related  * frame contents for both hardware- and software-based implementations.  * A key requiring software crypto support is automatically flagged and  * the cipher is expected to honor this and do the necessary work.  * Ciphers such as TKIP may also support mixed hardware/software  * encrypt/decrypt and MIC processing.  */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|ieee80211_keyix
typedef|;
end_typedef

begin_comment
comment|/* h/w key index */
end_comment

begin_struct
struct|struct
name|ieee80211_key
block|{
name|uint8_t
name|wk_keylen
decl_stmt|;
comment|/* key length in bytes */
name|uint8_t
name|wk_pad
decl_stmt|;
name|uint16_t
name|wk_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_KEY_XMIT
value|0x0001
comment|/* key used for xmit */
define|#
directive|define
name|IEEE80211_KEY_RECV
value|0x0002
comment|/* key used for recv */
define|#
directive|define
name|IEEE80211_KEY_GROUP
value|0x0004
comment|/* key used for WPA group operation */
define|#
directive|define
name|IEEE80211_KEY_SWENCRYPT
value|0x0010
comment|/* host-based encrypt */
define|#
directive|define
name|IEEE80211_KEY_SWDECRYPT
value|0x0020
comment|/* host-based decrypt */
define|#
directive|define
name|IEEE80211_KEY_SWENMIC
value|0x0040
comment|/* host-based enmic */
define|#
directive|define
name|IEEE80211_KEY_SWDEMIC
value|0x0080
comment|/* host-based demic */
define|#
directive|define
name|IEEE80211_KEY_DEVKEY
value|0x0100
comment|/* device key request completed */
define|#
directive|define
name|IEEE80211_KEY_CIPHER0
value|0x1000
comment|/* cipher-specific action 0 */
define|#
directive|define
name|IEEE80211_KEY_CIPHER1
value|0x2000
comment|/* cipher-specific action 1 */
name|ieee80211_keyix
name|wk_keyix
decl_stmt|;
comment|/* h/w key index */
name|ieee80211_keyix
name|wk_rxkeyix
decl_stmt|;
comment|/* optional h/w rx key index */
name|uint8_t
name|wk_key
index|[
name|IEEE80211_KEYBUF_SIZE
operator|+
name|IEEE80211_MICBUF_SIZE
index|]
decl_stmt|;
define|#
directive|define
name|wk_txmic
value|wk_key+IEEE80211_KEYBUF_SIZE+0
comment|/* XXX can't () right */
define|#
directive|define
name|wk_rxmic
value|wk_key+IEEE80211_KEYBUF_SIZE+8
comment|/* XXX can't () right */
comment|/* key receive sequence counter */
name|uint64_t
name|wk_keyrsc
index|[
name|IEEE80211_TID_SIZE
index|]
decl_stmt|;
name|uint64_t
name|wk_keytsc
decl_stmt|;
comment|/* key transmit sequence counter */
specifier|const
name|struct
name|ieee80211_cipher
modifier|*
name|wk_cipher
decl_stmt|;
name|void
modifier|*
name|wk_private
decl_stmt|;
comment|/* private cipher state */
name|uint8_t
name|wk_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_KEY_COMMON
comment|/* common flags passed in by apps */
define|\
value|(IEEE80211_KEY_XMIT | IEEE80211_KEY_RECV | IEEE80211_KEY_GROUP)
end_define

begin_define
define|#
directive|define
name|IEEE80211_KEY_SWCRYPT
define|\
value|(IEEE80211_KEY_SWENCRYPT | IEEE80211_KEY_SWDECRYPT)
end_define

begin_define
define|#
directive|define
name|IEEE80211_KEY_SWMIC
value|(IEEE80211_KEY_SWENMIC | IEEE80211_KEY_SWDEMIC)
end_define

begin_define
define|#
directive|define
name|IEEE80211_KEY_BITS
define|\
value|"\20\1XMIT\2RECV\3GROUP\4SWENCRYPT\5SWDECRYPT\6SWENMIC\7SWDEMIC" \ 	"\10DEVKEY\11CIPHER0\12CIPHER1"
end_define

begin_define
define|#
directive|define
name|IEEE80211_KEYIX_NONE
value|((ieee80211_keyix) -1)
end_define

begin_comment
comment|/*  * NB: these values are ordered carefully; there are lots of  * of implications in any reordering.  Beware that 4 is used  * only to indicate h/w TKIP MIC support in driver capabilities;  * there is no separate cipher support (it's rolled into the  * TKIP cipher support).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CIPHER_WEP
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_CIPHER_TKIP
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_CIPHER_AES_OCB
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_CIPHER_AES_CCM
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_CIPHER_TKIPMIC
value|4
end_define

begin_comment
comment|/* TKIP MIC capability */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CIPHER_CKIP
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_CIPHER_NONE
value|6
end_define

begin_comment
comment|/* pseudo value */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CIPHER_MAX
value|(IEEE80211_CIPHER_NONE+1)
end_define

begin_comment
comment|/* capability bits in ic_cryptocaps/iv_cryptocaps */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CRYPTO_WEP
value|(1<<IEEE80211_CIPHER_WEP)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CRYPTO_TKIP
value|(1<<IEEE80211_CIPHER_TKIP)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CRYPTO_AES_OCB
value|(1<<IEEE80211_CIPHER_AES_OCB)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CRYPTO_AES_CCM
value|(1<<IEEE80211_CIPHER_AES_CCM)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CRYPTO_TKIPMIC
value|(1<<IEEE80211_CIPHER_TKIPMIC)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CRYPTO_CKIP
value|(1<<IEEE80211_CIPHER_CKIP)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CRYPTO_BITS
define|\
value|"\20\1WEP\2TKIP\3AES\4AES_CCM\5TKIPMIC\6CKIP"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_struct_decl
struct_decl|struct
name|ieee80211com
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211vap
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_node
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_CRYPTO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|ieee80211_crypto_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_crypto_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_crypto_vattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_crypto_vdetach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_crypto_newkey
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
name|cipher
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|ieee80211_key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_crypto_delkey
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_crypto_setkey
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_crypto_delglobalkeys
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_crypto_reload_keys
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Template for a supported cipher.  Ciphers register with the  * crypto code and are typically loaded as separate modules  * (the null cipher is always present).  * XXX may need refcnts  */
end_comment

begin_struct
struct|struct
name|ieee80211_cipher
block|{
specifier|const
name|char
modifier|*
name|ic_name
decl_stmt|;
comment|/* printable name */
name|u_int
name|ic_cipher
decl_stmt|;
comment|/* IEEE80211_CIPHER_* */
name|u_int
name|ic_header
decl_stmt|;
comment|/* size of privacy header (bytes) */
name|u_int
name|ic_trailer
decl_stmt|;
comment|/* size of privacy trailer (bytes) */
name|u_int
name|ic_miclen
decl_stmt|;
comment|/* size of mic trailer (bytes) */
name|void
modifier|*
function_decl|(
modifier|*
name|ic_attach
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_key
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_detach
function_decl|)
parameter_list|(
name|struct
name|ieee80211_key
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_setkey
function_decl|)
parameter_list|(
name|struct
name|ieee80211_key
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_encap
function_decl|)
parameter_list|(
name|struct
name|ieee80211_key
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|uint8_t
name|keyid
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_decap
function_decl|)
parameter_list|(
name|struct
name|ieee80211_key
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_enmic
function_decl|)
parameter_list|(
name|struct
name|ieee80211_key
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_demic
function_decl|)
parameter_list|(
name|struct
name|ieee80211_key
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ieee80211_cipher
name|ieee80211_cipher_none
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IEEE80211_KEY_UNDEFINED
parameter_list|(
name|k
parameter_list|)
define|\
value|((k)->wk_cipher ==&ieee80211_cipher_none)
end_define

begin_function_decl
name|void
name|ieee80211_crypto_register
parameter_list|(
specifier|const
name|struct
name|ieee80211_cipher
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_crypto_unregister
parameter_list|(
specifier|const
name|struct
name|ieee80211_cipher
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_crypto_available
parameter_list|(
name|u_int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_key
modifier|*
name|ieee80211_crypto_encap
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_key
modifier|*
name|ieee80211_crypto_decap
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check and remove any MIC.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_crypto_demic
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|struct
name|ieee80211_key
modifier|*
name|k
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|force
parameter_list|)
block|{
specifier|const
name|struct
name|ieee80211_cipher
modifier|*
name|cip
init|=
name|k
operator|->
name|wk_cipher
decl_stmt|;
return|return
operator|(
name|cip
operator|->
name|ic_miclen
operator|>
literal|0
condition|?
name|cip
operator|->
name|ic_demic
argument_list|(
name|k
argument_list|,
name|m
argument_list|,
name|force
argument_list|)
else|:
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Add any MIC.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_crypto_enmic
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|struct
name|ieee80211_key
modifier|*
name|k
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|force
parameter_list|)
block|{
specifier|const
name|struct
name|ieee80211_cipher
modifier|*
name|cip
init|=
name|k
operator|->
name|wk_cipher
decl_stmt|;
return|return
operator|(
name|cip
operator|->
name|ic_miclen
operator|>
literal|0
condition|?
name|cip
operator|->
name|ic_enmic
argument_list|(
name|k
argument_list|,
name|m
argument_list|,
name|force
argument_list|)
else|:
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*   * Reset key state to an unused state.  The crypto  * key allocation mechanism insures other state (e.g.  * key data) is properly setup before a key is used.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_crypto_resetkey
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|struct
name|ieee80211_key
modifier|*
name|k
parameter_list|,
name|ieee80211_keyix
name|ix
parameter_list|)
block|{
name|k
operator|->
name|wk_cipher
operator|=
operator|&
name|ieee80211_cipher_none
expr_stmt|;
name|k
operator|->
name|wk_private
operator|=
name|k
operator|->
name|wk_cipher
operator|->
name|ic_attach
argument_list|(
name|vap
argument_list|,
name|k
argument_list|)
expr_stmt|;
name|k
operator|->
name|wk_keyix
operator|=
name|k
operator|->
name|wk_rxkeyix
operator|=
name|ix
expr_stmt|;
name|k
operator|->
name|wk_flags
operator|=
name|IEEE80211_KEY_XMIT
operator||
name|IEEE80211_KEY_RECV
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Crypt-related notification methods.  */
end_comment

begin_function_decl
name|void
name|ieee80211_notify_replay_failure
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_key
modifier|*
parameter_list|,
name|uint64_t
name|rsc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_michael_failure
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame
modifier|*
parameter_list|,
name|u_int
name|keyix
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__KERNEL__) || defined(_KERNEL) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_CRYPTO_H_ */
end_comment

end_unit

