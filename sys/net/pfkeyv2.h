begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* $Id: keyv2.h,v 1.1.6.1.6.4 1999/06/08 05:33:39 itojun Exp $ */
end_comment

begin_comment
comment|/*  * This file has been derived rfc 2367,  * And added some flags of SADB_KEY_FLAGS_ as SADB_X_EXT_.  *	sakane@ydc.co.jp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_PFKEYV2_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_PFKEYV2_H_
end_define

begin_comment
comment|/* This file defines structures and symbols for the PF_KEY Version 2 key management interface. It was written at the U.S. Naval Research Laboratory. This file is in the public domain. The authors ask that you leave this credit intact on any copies of this file. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PFKEY_V2_H
end_ifndef

begin_define
define|#
directive|define
name|__PFKEY_V2_H
value|1
end_define

begin_define
define|#
directive|define
name|PF_KEY_V2
value|2
end_define

begin_define
define|#
directive|define
name|PFKEYV2_REVISION
value|199806L
end_define

begin_define
define|#
directive|define
name|SADB_RESERVED
value|0
end_define

begin_define
define|#
directive|define
name|SADB_GETSPI
value|1
end_define

begin_define
define|#
directive|define
name|SADB_UPDATE
value|2
end_define

begin_define
define|#
directive|define
name|SADB_ADD
value|3
end_define

begin_define
define|#
directive|define
name|SADB_DELETE
value|4
end_define

begin_define
define|#
directive|define
name|SADB_GET
value|5
end_define

begin_define
define|#
directive|define
name|SADB_ACQUIRE
value|6
end_define

begin_define
define|#
directive|define
name|SADB_REGISTER
value|7
end_define

begin_define
define|#
directive|define
name|SADB_EXPIRE
value|8
end_define

begin_define
define|#
directive|define
name|SADB_FLUSH
value|9
end_define

begin_define
define|#
directive|define
name|SADB_DUMP
value|10
end_define

begin_define
define|#
directive|define
name|SADB_X_PROMISC
value|11
end_define

begin_define
define|#
directive|define
name|SADB_X_PCHANGE
value|12
end_define

begin_define
define|#
directive|define
name|SADB_X_SPDUPDATE
value|13
end_define

begin_comment
comment|/* not yet */
end_comment

begin_define
define|#
directive|define
name|SADB_X_SPDADD
value|14
end_define

begin_define
define|#
directive|define
name|SADB_X_SPDDELETE
value|15
end_define

begin_define
define|#
directive|define
name|SADB_X_SPDGET
value|16
end_define

begin_comment
comment|/* not yet */
end_comment

begin_define
define|#
directive|define
name|SADB_X_SPDACQUIRE
value|17
end_define

begin_comment
comment|/* not yet */
end_comment

begin_define
define|#
directive|define
name|SADB_X_SPDDUMP
value|18
end_define

begin_define
define|#
directive|define
name|SADB_X_SPDFLUSH
value|19
end_define

begin_define
define|#
directive|define
name|SADB_MAX
value|19
end_define

begin_struct
struct|struct
name|sadb_msg
block|{
name|u_int8_t
name|sadb_msg_version
decl_stmt|;
name|u_int8_t
name|sadb_msg_type
decl_stmt|;
name|u_int8_t
name|sadb_msg_errno
decl_stmt|;
name|u_int8_t
name|sadb_msg_satype
decl_stmt|;
name|u_int16_t
name|sadb_msg_len
decl_stmt|;
name|u_int8_t
name|sadb_msg_mode
decl_stmt|;
comment|/* XXX */
name|u_int8_t
name|sadb_msg_reserved
decl_stmt|;
name|u_int32_t
name|sadb_msg_seq
decl_stmt|;
name|u_int32_t
name|sadb_msg_pid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_ext
block|{
name|u_int16_t
name|sadb_ext_len
decl_stmt|;
name|u_int16_t
name|sadb_ext_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_sa
block|{
name|u_int16_t
name|sadb_sa_len
decl_stmt|;
name|u_int16_t
name|sadb_sa_exttype
decl_stmt|;
name|u_int32_t
name|sadb_sa_spi
decl_stmt|;
name|u_int8_t
name|sadb_sa_replay
decl_stmt|;
name|u_int8_t
name|sadb_sa_state
decl_stmt|;
name|u_int8_t
name|sadb_sa_auth
decl_stmt|;
name|u_int8_t
name|sadb_sa_encrypt
decl_stmt|;
name|u_int32_t
name|sadb_sa_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_lifetime
block|{
name|u_int16_t
name|sadb_lifetime_len
decl_stmt|;
name|u_int16_t
name|sadb_lifetime_exttype
decl_stmt|;
name|u_int32_t
name|sadb_lifetime_allocations
decl_stmt|;
name|u_int64_t
name|sadb_lifetime_bytes
decl_stmt|;
name|u_int64_t
name|sadb_lifetime_addtime
decl_stmt|;
name|u_int64_t
name|sadb_lifetime_usetime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_address
block|{
name|u_int16_t
name|sadb_address_len
decl_stmt|;
name|u_int16_t
name|sadb_address_exttype
decl_stmt|;
name|u_int8_t
name|sadb_address_proto
decl_stmt|;
name|u_int8_t
name|sadb_address_prefixlen
decl_stmt|;
name|u_int16_t
name|sadb_address_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_key
block|{
name|u_int16_t
name|sadb_key_len
decl_stmt|;
name|u_int16_t
name|sadb_key_exttype
decl_stmt|;
name|u_int16_t
name|sadb_key_bits
decl_stmt|;
name|u_int16_t
name|sadb_key_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_ident
block|{
name|u_int16_t
name|sadb_ident_len
decl_stmt|;
name|u_int16_t
name|sadb_ident_exttype
decl_stmt|;
name|u_int16_t
name|sadb_ident_type
decl_stmt|;
name|u_int16_t
name|sadb_ident_reserved
decl_stmt|;
name|u_int64_t
name|sadb_ident_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* in order to use to divide sadb_ident.sadb_ident_id */
end_comment

begin_union
union|union
name|sadb_x_ident_id
block|{
name|u_int64_t
name|sadb_x_ident_id
decl_stmt|;
struct|struct
name|_sadb_x_ident_id_addr
block|{
name|u_int16_t
name|prefix
decl_stmt|;
name|u_int16_t
name|ul_proto
decl_stmt|;
name|u_int32_t
name|reserved
decl_stmt|;
block|}
name|sadb_x_ident_id_addr
struct|;
block|}
union|;
end_union

begin_struct
struct|struct
name|sadb_sens
block|{
name|u_int16_t
name|sadb_sens_len
decl_stmt|;
name|u_int16_t
name|sadb_sens_exttype
decl_stmt|;
name|u_int32_t
name|sadb_sens_dpd
decl_stmt|;
name|u_int8_t
name|sadb_sens_sens_level
decl_stmt|;
name|u_int8_t
name|sadb_sens_sens_len
decl_stmt|;
name|u_int8_t
name|sadb_sens_integ_level
decl_stmt|;
name|u_int8_t
name|sadb_sens_integ_len
decl_stmt|;
name|u_int32_t
name|sadb_sens_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_prop
block|{
name|u_int16_t
name|sadb_prop_len
decl_stmt|;
name|u_int16_t
name|sadb_prop_exttype
decl_stmt|;
name|u_int8_t
name|sadb_prop_replay
decl_stmt|;
name|u_int8_t
name|sadb_prop_reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_comb
block|{
name|u_int8_t
name|sadb_comb_auth
decl_stmt|;
name|u_int8_t
name|sadb_comb_encrypt
decl_stmt|;
name|u_int16_t
name|sadb_comb_flags
decl_stmt|;
name|u_int16_t
name|sadb_comb_auth_minbits
decl_stmt|;
name|u_int16_t
name|sadb_comb_auth_maxbits
decl_stmt|;
name|u_int16_t
name|sadb_comb_encrypt_minbits
decl_stmt|;
name|u_int16_t
name|sadb_comb_encrypt_maxbits
decl_stmt|;
name|u_int32_t
name|sadb_comb_reserved
decl_stmt|;
name|u_int32_t
name|sadb_comb_soft_allocations
decl_stmt|;
name|u_int32_t
name|sadb_comb_hard_allocations
decl_stmt|;
name|u_int64_t
name|sadb_comb_soft_bytes
decl_stmt|;
name|u_int64_t
name|sadb_comb_hard_bytes
decl_stmt|;
name|u_int64_t
name|sadb_comb_soft_addtime
decl_stmt|;
name|u_int64_t
name|sadb_comb_hard_addtime
decl_stmt|;
name|u_int64_t
name|sadb_comb_soft_usetime
decl_stmt|;
name|u_int64_t
name|sadb_comb_hard_usetime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_supported
block|{
name|u_int16_t
name|sadb_supported_len
decl_stmt|;
name|u_int16_t
name|sadb_supported_exttype
decl_stmt|;
name|u_int32_t
name|sadb_supported_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_alg
block|{
name|u_int8_t
name|sadb_alg_id
decl_stmt|;
name|u_int8_t
name|sadb_alg_ivlen
decl_stmt|;
name|u_int16_t
name|sadb_alg_minbits
decl_stmt|;
name|u_int16_t
name|sadb_alg_maxbits
decl_stmt|;
name|u_int16_t
name|sadb_alg_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_spirange
block|{
name|u_int16_t
name|sadb_spirange_len
decl_stmt|;
name|u_int16_t
name|sadb_spirange_exttype
decl_stmt|;
name|u_int32_t
name|sadb_spirange_min
decl_stmt|;
name|u_int32_t
name|sadb_spirange_max
decl_stmt|;
name|u_int32_t
name|sadb_spirange_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sadb_x_kmprivate
block|{
name|u_int16_t
name|sadb_x_kmprivate_len
decl_stmt|;
name|u_int16_t
name|sadb_x_kmprivate_exttype
decl_stmt|;
name|u_int32_t
name|sadb_x_kmprivate_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* XXX Policy Extension */
end_comment

begin_comment
comment|/* sizeof(struct sadb_x_policy) == 8 */
end_comment

begin_struct
struct|struct
name|sadb_x_policy
block|{
name|u_int16_t
name|sadb_x_policy_len
decl_stmt|;
name|u_int16_t
name|sadb_x_policy_exttype
decl_stmt|;
comment|/* See policy type of ipsec.h */
name|u_int16_t
name|sadb_x_policy_type
decl_stmt|;
name|u_int8_t
name|sadb_x_policy_dir
decl_stmt|;
comment|/* direction, see ipsec.h */
name|u_int8_t
name|sadb_x_policy_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * When policy_type == IPSEC, it is followed by some of  * the ipsec policy request.  * [total length of ipsec policy requests]  *	= (sadb_x_policy_len * sizeof(uint64_t) - sizeof(struct sadb_x_policy))  */
end_comment

begin_comment
comment|/* XXX IPsec Policy Request Extension */
end_comment

begin_comment
comment|/*  * This structure is aligned 8 bytes.  */
end_comment

begin_struct
struct|struct
name|sadb_x_ipsecrequest
block|{
name|u_int16_t
name|sadb_x_ipsecrequest_len
decl_stmt|;
comment|/* structure length aligned to 8 bytes. 				 * This value is true length of bytes. 				 * Not in units of 64 bits. */
name|u_int16_t
name|sadb_x_ipsecrequest_proto
decl_stmt|;
comment|/* See ipsec.h */
comment|/* See ipsec.h. Not SADB_SATYPE_XX */
name|u_int16_t
name|sadb_x_ipsecrequest_mode
decl_stmt|;
name|u_int16_t
name|sadb_x_ipsecrequest_level
decl_stmt|;
comment|/* See ipsec.h */
comment|/* 	 * followed by source IP address of SA, and immediately followed by 	 * destination IP address of SA.  These encoded into two of sockaddr 	 * structure without any padding.  Must set each sa_len exactly. 	 * Each of length of the sockaddr structure are not aligned to 64bits, 	 * but sum of x_request and addresses is aligned to 64bits. 	 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SADB_EXT_RESERVED
value|0
end_define

begin_define
define|#
directive|define
name|SADB_EXT_SA
value|1
end_define

begin_define
define|#
directive|define
name|SADB_EXT_LIFETIME_CURRENT
value|2
end_define

begin_define
define|#
directive|define
name|SADB_EXT_LIFETIME_HARD
value|3
end_define

begin_define
define|#
directive|define
name|SADB_EXT_LIFETIME_SOFT
value|4
end_define

begin_define
define|#
directive|define
name|SADB_EXT_ADDRESS_SRC
value|5
end_define

begin_define
define|#
directive|define
name|SADB_EXT_ADDRESS_DST
value|6
end_define

begin_define
define|#
directive|define
name|SADB_EXT_ADDRESS_PROXY
value|7
end_define

begin_define
define|#
directive|define
name|SADB_EXT_KEY_AUTH
value|8
end_define

begin_define
define|#
directive|define
name|SADB_EXT_KEY_ENCRYPT
value|9
end_define

begin_define
define|#
directive|define
name|SADB_EXT_IDENTITY_SRC
value|10
end_define

begin_define
define|#
directive|define
name|SADB_EXT_IDENTITY_DST
value|11
end_define

begin_define
define|#
directive|define
name|SADB_EXT_SENSITIVITY
value|12
end_define

begin_define
define|#
directive|define
name|SADB_EXT_PROPOSAL
value|13
end_define

begin_define
define|#
directive|define
name|SADB_EXT_SUPPORTED_AUTH
value|14
end_define

begin_define
define|#
directive|define
name|SADB_EXT_SUPPORTED_ENCRYPT
value|15
end_define

begin_define
define|#
directive|define
name|SADB_EXT_SPIRANGE
value|16
end_define

begin_define
define|#
directive|define
name|SADB_X_EXT_KMPRIVATE
value|17
end_define

begin_define
define|#
directive|define
name|SADB_X_EXT_POLICY
value|18
end_define

begin_define
define|#
directive|define
name|SADB_EXT_MAX
value|18
end_define

begin_define
define|#
directive|define
name|SADB_SATYPE_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|SADB_SATYPE_AH
value|2
end_define

begin_define
define|#
directive|define
name|SADB_SATYPE_ESP
value|3
end_define

begin_define
define|#
directive|define
name|SADB_SATYPE_RSVP
value|5
end_define

begin_define
define|#
directive|define
name|SADB_SATYPE_OSPFV2
value|6
end_define

begin_define
define|#
directive|define
name|SADB_SATYPE_RIPV2
value|7
end_define

begin_define
define|#
directive|define
name|SADB_SATYPE_MIP
value|8
end_define

begin_define
define|#
directive|define
name|SADB_X_SATYPE_IPCOMP
value|9
end_define

begin_define
define|#
directive|define
name|SADB_SATYPE_MAX
value|9
end_define

begin_define
define|#
directive|define
name|SADB_SASTATE_LARVAL
value|0
end_define

begin_define
define|#
directive|define
name|SADB_SASTATE_MATURE
value|1
end_define

begin_define
define|#
directive|define
name|SADB_SASTATE_DYING
value|2
end_define

begin_define
define|#
directive|define
name|SADB_SASTATE_DEAD
value|3
end_define

begin_define
define|#
directive|define
name|SADB_SASTATE_MAX
value|3
end_define

begin_define
define|#
directive|define
name|SADB_SAFLAGS_PFS
value|1
end_define

begin_define
define|#
directive|define
name|SADB_AALG_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SADB_AALG_MD5HMAC
value|1
end_define

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|SADB_AALG_SHA1HMAC
value|2
end_define

begin_comment
comment|/* 3 */
end_comment

begin_define
define|#
directive|define
name|SADB_AALG_MD5
value|3
end_define

begin_comment
comment|/* Keyed MD5 */
end_comment

begin_define
define|#
directive|define
name|SADB_AALG_SHA
value|4
end_define

begin_comment
comment|/* Keyed SHA */
end_comment

begin_define
define|#
directive|define
name|SADB_AALG_NULL
value|5
end_define

begin_comment
comment|/* null authentication */
end_comment

begin_define
define|#
directive|define
name|SADB_AALG_MAX
value|6
end_define

begin_define
define|#
directive|define
name|SADB_EALG_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SADB_EALG_DESCBC
value|1
end_define

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|SADB_EALG_3DESCBC
value|2
end_define

begin_comment
comment|/* 3 */
end_comment

begin_define
define|#
directive|define
name|SADB_EALG_NULL
value|3
end_define

begin_comment
comment|/* 11 */
end_comment

begin_define
define|#
directive|define
name|SADB_EALG_BLOWFISHCBC
value|4
end_define

begin_define
define|#
directive|define
name|SADB_EALG_CAST128CBC
value|5
end_define

begin_define
define|#
directive|define
name|SADB_EALG_RC5CBC
value|6
end_define

begin_define
define|#
directive|define
name|SADB_EALG_MAX
value|7
end_define

begin_comment
comment|/*nonstandard */
end_comment

begin_define
define|#
directive|define
name|SADB_X_CALG_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SADB_X_CALG_OUI
value|1
end_define

begin_define
define|#
directive|define
name|SADB_X_CALG_DEFLATE
value|2
end_define

begin_define
define|#
directive|define
name|SADB_X_CALG_LZS
value|3
end_define

begin_define
define|#
directive|define
name|SADB_IDENTTYPE_RESERVED
value|0
end_define

begin_define
define|#
directive|define
name|SADB_IDENTTYPE_PREFIX
value|1
end_define

begin_define
define|#
directive|define
name|SADB_IDENTTYPE_FQDN
value|2
end_define

begin_define
define|#
directive|define
name|SADB_IDENTTYPE_USERFQDN
value|3
end_define

begin_define
define|#
directive|define
name|SADB_X_IDENTTYPE_ADDR
value|4
end_define

begin_define
define|#
directive|define
name|SADB_IDENTTYPE_MAX
value|4
end_define

begin_comment
comment|/* `flags' in sadb_sa structure holds followings */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_NONE
value|0x0000
end_define

begin_comment
comment|/* i.e. new format. */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_OLD
value|0x0001
end_define

begin_comment
comment|/* old format. */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_IV4B
value|0x0010
end_define

begin_comment
comment|/* IV length of 4 bytes in use */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_DERIV
value|0x0020
end_define

begin_comment
comment|/* DES derived */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_CYCSEQ
value|0x0040
end_define

begin_comment
comment|/* allowing to cyclic sequence. */
end_comment

begin_comment
comment|/* three of followings are exclusive flags each them */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_PSEQ
value|0x0000
end_define

begin_comment
comment|/* sequencial padding for ESP */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_PRAND
value|0x0100
end_define

begin_comment
comment|/* random padding for ESP */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_PZERO
value|0x0200
end_define

begin_comment
comment|/* zero padding for ESP */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_PMASK
value|0x0300
end_define

begin_comment
comment|/* mask for padding flag */
end_comment

begin_define
define|#
directive|define
name|SADB_X_EXT_RAWCPI
value|0x0080
end_define

begin_comment
comment|/* use well known CPI (IPComp) */
end_comment

begin_define
define|#
directive|define
name|SADB_KEY_FLAGS_MAX
value|0x0fff
end_define

begin_comment
comment|/* SPI size for PF_KEYv2 */
end_comment

begin_define
define|#
directive|define
name|PFKEY_SPI_SIZE
value|sizeof(u_int32_t)
end_define

begin_comment
comment|/* Identifier for menber of lifetime structure */
end_comment

begin_define
define|#
directive|define
name|SADB_X_LIFETIME_ALLOCATIONS
value|0
end_define

begin_define
define|#
directive|define
name|SADB_X_LIFETIME_BYTES
value|1
end_define

begin_define
define|#
directive|define
name|SADB_X_LIFETIME_ADDTIME
value|2
end_define

begin_define
define|#
directive|define
name|SADB_X_LIFETIME_USETIME
value|3
end_define

begin_comment
comment|/* The rate for SOFT lifetime against HARD one. */
end_comment

begin_define
define|#
directive|define
name|PFKEY_SOFT_LIFETIME_RATE
value|80
end_define

begin_comment
comment|/* Utilities */
end_comment

begin_define
define|#
directive|define
name|PFKEY_ALIGN8
parameter_list|(
name|a
parameter_list|)
value|(1 + (((a) - 1) | (8 - 1)))
end_define

begin_define
define|#
directive|define
name|PFKEY_EXTLEN
parameter_list|(
name|msg
parameter_list|)
define|\
value|PFKEY_UNUNIT64(((struct sadb_ext *)(msg))->sadb_ext_len)
end_define

begin_define
define|#
directive|define
name|PFKEY_ADDR_PREFIX
parameter_list|(
name|ext
parameter_list|)
define|\
value|(((struct sadb_address *)(ext))->sadb_address_prefixlen)
end_define

begin_define
define|#
directive|define
name|PFKEY_ADDR_PROTO
parameter_list|(
name|ext
parameter_list|)
define|\
value|(((struct sadb_address *)(ext))->sadb_address_proto)
end_define

begin_define
define|#
directive|define
name|PFKEY_ADDR_SADDR
parameter_list|(
name|ext
parameter_list|)
define|\
value|((struct sockaddr *)((caddr_t)(ext) + sizeof(struct sadb_address)))
end_define

begin_comment
comment|/* in 64bits */
end_comment

begin_define
define|#
directive|define
name|PFKEY_UNUNIT64
parameter_list|(
name|a
parameter_list|)
value|((a)<< 3)
end_define

begin_define
define|#
directive|define
name|PFKEY_UNIT64
parameter_list|(
name|a
parameter_list|)
value|((a)>> 3)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_function_decl
specifier|extern
name|void
name|pfkey_sadump
parameter_list|(
name|struct
name|sadb_msg
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pfkey_spdump
parameter_list|(
name|struct
name|sadb_msg
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|ipsec_check_keylen
name|__P
argument_list|(
operator|(
name|u_int
name|supported
operator|,
name|u_int
name|alg_id
operator|,
name|u_int
name|keylen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|pfkey_set_softrate
name|__P
argument_list|(
operator|(
name|u_int
name|type
operator|,
name|u_int
name|rate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|pfkey_get_softrate
name|__P
argument_list|(
operator|(
name|u_int
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_getspi
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
name|u_int
name|satype
operator|,
name|u_int
name|mode
operator|,
expr|struct
name|sockaddr
operator|*
name|src
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
name|u_int32_t
name|min
operator|,
name|u_int32_t
name|max
operator|,
name|u_int32_t
name|seq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_update
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
name|u_int
name|satype
operator|,
name|u_int
name|mode
operator|,
expr|struct
name|sockaddr
operator|*
name|src
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
name|u_int32_t
name|spi
operator|,
name|u_int
name|wsize
operator|,
name|caddr_t
name|keymat
operator|,
name|u_int
name|e_type
operator|,
name|u_int
name|e_keylen
operator|,
name|u_int
name|a_type
operator|,
name|u_int
name|a_keylen
operator|,
name|u_int
name|flags
operator|,
name|u_int32_t
name|l_alloc
operator|,
name|u_int64_t
name|l_bytes
operator|,
name|u_int64_t
name|l_addtime
operator|,
name|u_int64_t
name|l_usetime
operator|,
name|u_int32_t
name|seq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_add
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
name|u_int
name|satype
operator|,
name|u_int
name|mode
operator|,
expr|struct
name|sockaddr
operator|*
name|src
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
name|u_int32_t
name|spi
operator|,
name|u_int
name|wsize
operator|,
name|caddr_t
name|keymat
operator|,
name|u_int
name|e_type
operator|,
name|u_int
name|e_keylen
operator|,
name|u_int
name|a_type
operator|,
name|u_int
name|a_keylen
operator|,
name|u_int
name|flags
operator|,
name|u_int32_t
name|l_alloc
operator|,
name|u_int64_t
name|l_bytes
operator|,
name|u_int64_t
name|l_addtime
operator|,
name|u_int64_t
name|l_usetime
operator|,
name|u_int32_t
name|seq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_delete
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
name|u_int
name|satype
operator|,
name|u_int
name|mode
operator|,
expr|struct
name|sockaddr
operator|*
name|src
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
name|u_int32_t
name|spi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_get
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
name|u_int
name|satype
operator|,
name|u_int
name|mode
operator|,
expr|struct
name|sockaddr
operator|*
name|src
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
name|u_int32_t
name|spi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_register
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
name|u_int
name|satype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_recv_register
name|__P
argument_list|(
operator|(
name|int
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_flush
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
name|u_int
name|satype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_dump
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
name|u_int
name|satype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_promisc_toggle
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_spdadd
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
expr|struct
name|sockaddr
operator|*
name|src
operator|,
name|u_int
name|prefs
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
name|u_int
name|prefd
operator|,
name|u_int
name|proto
operator|,
name|caddr_t
name|policy
operator|,
name|int
name|policylen
operator|,
name|u_int32_t
name|seq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_spddelete
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
expr|struct
name|sockaddr
operator|*
name|src
operator|,
name|u_int
name|prefs
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
name|u_int
name|prefd
operator|,
name|u_int
name|proto
operator|,
name|u_int32_t
name|seq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_spdflush
name|__P
argument_list|(
operator|(
name|int
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send_spddump
name|__P
argument_list|(
operator|(
name|int
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_open
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pfkey_close
name|__P
argument_list|(
operator|(
name|int
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sadb_msg
modifier|*
name|pfkey_recv
name|__P
argument_list|(
operator|(
name|int
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_send
name|__P
argument_list|(
operator|(
name|int
name|so
operator|,
expr|struct
name|sadb_msg
operator|*
name|msg
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_align
name|__P
argument_list|(
operator|(
expr|struct
name|sadb_msg
operator|*
name|msg
operator|,
name|caddr_t
operator|*
name|mhp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfkey_check
name|__P
argument_list|(
operator|(
name|caddr_t
operator|*
name|mhp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!KERNEL*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PFKEY_V2_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_PFKEYV2_H_ */
end_comment

end_unit

