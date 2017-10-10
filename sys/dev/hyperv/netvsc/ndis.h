begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016-2017 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_NDIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_NDIS_H_
end_define

begin_define
define|#
directive|define
name|NDIS_MEDIA_STATE_CONNECTED
value|0
end_define

begin_define
define|#
directive|define
name|NDIS_MEDIA_STATE_DISCONNECTED
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_NETCHANGE_TYPE_POSSIBLE
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_NETCHANGE_TYPE_DEFINITE
value|2
end_define

begin_define
define|#
directive|define
name|NDIS_NETCHANGE_TYPE_FROMMEDIA
value|3
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_SET_NOCHG
value|0
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_SET_ON
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_SET_OFF
value|2
end_define

begin_comment
comment|/* a.k.a GRE MAC */
end_comment

begin_define
define|#
directive|define
name|NDIS_ENCAP_TYPE_NVGRE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_FUNCTION_MASK
value|0x000000FF
end_define

begin_comment
comment|/* see hash function */
end_comment

begin_define
define|#
directive|define
name|NDIS_HASH_TYPE_MASK
value|0x00FFFF00
end_define

begin_comment
comment|/* see hash type */
end_comment

begin_comment
comment|/* hash function */
end_comment

begin_define
define|#
directive|define
name|NDIS_HASH_FUNCTION_TOEPLITZ
value|0x00000001
end_define

begin_comment
comment|/* hash type */
end_comment

begin_define
define|#
directive|define
name|NDIS_HASH_IPV4
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_TCP_IPV4
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_IPV6
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_IPV6_EX
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_TCP_IPV6
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_TCP_IPV6_EX
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_ALL
value|(NDIS_HASH_IPV4 |	\ 					 NDIS_HASH_TCP_IPV4 |	\ 					 NDIS_HASH_IPV6 |	\ 					 NDIS_HASH_IPV6_EX |	\ 					 NDIS_HASH_TCP_IPV6 |	\ 					 NDIS_HASH_TCP_IPV6_EX)
end_define

begin_comment
comment|/* Hash description for use with printf(9) %b identifier. */
end_comment

begin_define
define|#
directive|define
name|NDIS_HASH_BITS
define|\
value|"\20\1TOEPLITZ\11IP4\12TCP4\13IP6\14IP6EX\15TCP6\16TCP6EX"
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_KEYSIZE_TOEPLITZ
value|40
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_INDCNT
value|128
end_define

begin_define
define|#
directive|define
name|NDIS_OBJTYPE_DEFAULT
value|0x80
end_define

begin_define
define|#
directive|define
name|NDIS_OBJTYPE_RSS_CAPS
value|0x88
end_define

begin_define
define|#
directive|define
name|NDIS_OBJTYPE_RSS_PARAMS
value|0x89
end_define

begin_define
define|#
directive|define
name|NDIS_OBJTYPE_OFFLOAD
value|0xa7
end_define

begin_struct
struct|struct
name|ndis_object_hdr
block|{
name|uint8_t
name|ndis_type
decl_stmt|;
comment|/* NDIS_OBJTYPE_ */
name|uint8_t
name|ndis_rev
decl_stmt|;
comment|/* type specific */
name|uint16_t
name|ndis_size
decl_stmt|;
comment|/* incl. this hdr */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OID_TCP_OFFLOAD_PARAMETERS  * ndis_type: NDIS_OBJTYPE_DEFAULT  */
end_comment

begin_struct
struct|struct
name|ndis_offload_params
block|{
name|struct
name|ndis_object_hdr
name|ndis_hdr
decl_stmt|;
name|uint8_t
name|ndis_ip4csum
decl_stmt|;
comment|/* NDIS_OFFLOAD_PARAM_ */
name|uint8_t
name|ndis_tcp4csum
decl_stmt|;
comment|/* NDIS_OFFLOAD_PARAM_ */
name|uint8_t
name|ndis_udp4csum
decl_stmt|;
comment|/* NDIS_OFFLOAD_PARAM_ */
name|uint8_t
name|ndis_tcp6csum
decl_stmt|;
comment|/* NDIS_OFFLOAD_PARAM_ */
name|uint8_t
name|ndis_udp6csum
decl_stmt|;
comment|/* NDIS_OFFLOAD_PARAM_ */
name|uint8_t
name|ndis_lsov1
decl_stmt|;
comment|/* NDIS_OFFLOAD_PARAM_ */
name|uint8_t
name|ndis_ipsecv1
decl_stmt|;
comment|/* NDIS_OFFLOAD_IPSECV1_ */
name|uint8_t
name|ndis_lsov2_ip4
decl_stmt|;
comment|/* NDIS_OFFLOAD_LSOV2_ */
name|uint8_t
name|ndis_lsov2_ip6
decl_stmt|;
comment|/* NDIS_OFFLOAD_LSOV2_ */
name|uint8_t
name|ndis_tcp4conn
decl_stmt|;
comment|/* 0 */
name|uint8_t
name|ndis_tcp6conn
decl_stmt|;
comment|/* 0 */
name|uint32_t
name|ndis_flags
decl_stmt|;
comment|/* 0 */
comment|/* NDIS>= 6.1 */
name|uint8_t
name|ndis_ipsecv2
decl_stmt|;
comment|/* NDIS_OFFLOAD_IPSECV2_ */
name|uint8_t
name|ndis_ipsecv2_ip4
decl_stmt|;
comment|/* NDIS_OFFLOAD_IPSECV2_ */
comment|/* NDIS>= 6.30 */
name|uint8_t
name|ndis_rsc_ip4
decl_stmt|;
comment|/* NDIS_OFFLOAD_RSC_ */
name|uint8_t
name|ndis_rsc_ip6
decl_stmt|;
comment|/* NDIS_OFFLOAD_RSC_ */
name|uint8_t
name|ndis_encap
decl_stmt|;
comment|/* NDIS_OFFLOAD_SET_ */
name|uint8_t
name|ndis_encap_types
decl_stmt|;
comment|/* NDIS_ENCAP_TYPE_ */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_PARAMS_SIZE
value|sizeof(struct ndis_offload_params)
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_PARAMS_SIZE_6_1
define|\
value|__offsetof(struct ndis_offload_params, ndis_rsc_ip4)
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_PARAMS_REV_2
value|2
end_define

begin_comment
comment|/* NDIS 6.1 */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_PARAMS_REV_3
value|3
end_define

begin_comment
comment|/* NDIS 6.30 */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_PARAM_NOCHG
value|0
end_define

begin_comment
comment|/* common */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_PARAM_OFF
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_PARAM_TX
value|2
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_PARAM_RX
value|3
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_PARAM_TXRX
value|4
end_define

begin_comment
comment|/* NDIS_OFFLOAD_PARAM_NOCHG */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_LSOV1_OFF
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_LSOV1_ON
value|2
end_define

begin_comment
comment|/* NDIS_OFFLOAD_PARAM_NOCHG */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_IPSECV1_OFF
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_IPSECV1_AH
value|2
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_IPSECV1_ESP
value|3
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_IPSECV1_AH_ESP
value|4
end_define

begin_comment
comment|/* NDIS_OFFLOAD_PARAM_NOCHG */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_LSOV2_OFF
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_LSOV2_ON
value|2
end_define

begin_comment
comment|/* NDIS_OFFLOAD_PARAM_NOCHG */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_IPSECV2_OFF
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_IPSECV2_AH
value|2
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_IPSECV2_ESP
value|3
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_IPSECV2_AH_ESP
value|4
end_define

begin_comment
comment|/* NDIS_OFFLOAD_PARAM_NOCHG */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_RSC_OFF
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_RSC_ON
value|2
end_define

begin_comment
comment|/*  * OID_GEN_RECEIVE_SCALE_CAPABILITIES  * ndis_type: NDIS_OBJTYPE_RSS_CAPS  */
end_comment

begin_struct
struct|struct
name|ndis_rss_caps
block|{
name|struct
name|ndis_object_hdr
name|ndis_hdr
decl_stmt|;
name|uint32_t
name|ndis_caps
decl_stmt|;
comment|/* NDIS_RSS_CAP_ */
name|uint32_t
name|ndis_nmsi
decl_stmt|;
comment|/* # of MSIs */
name|uint32_t
name|ndis_nrxr
decl_stmt|;
comment|/* # of RX rings */
comment|/* NDIS>= 6.30 */
name|uint16_t
name|ndis_nind
decl_stmt|;
comment|/* # of indtbl ent. */
name|uint16_t
name|ndis_pad
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NDIS_RSS_CAPS_SIZE
define|\
value|__offsetof(struct ndis_rss_caps, ndis_pad)
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAPS_SIZE_6_0
define|\
value|__offsetof(struct ndis_rss_caps, ndis_nind)
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAPS_REV_1
value|1
end_define

begin_comment
comment|/* NDIS 6.{0,1,20} */
end_comment

begin_define
define|#
directive|define
name|NDIS_RSS_CAPS_REV_2
value|2
end_define

begin_comment
comment|/* NDIS 6.30 */
end_comment

begin_define
define|#
directive|define
name|NDIS_RSS_CAP_MSI
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAP_CLASSIFY_ISR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAP_CLASSIFY_DPC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAP_MSIX
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAP_IPV4
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAP_IPV6
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAP_IPV6_EX
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAP_HASH_TOEPLITZ
value|NDIS_HASH_FUNCTION_TOEPLITZ
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_CAP_HASHFUNC_MASK
value|NDIS_HASH_FUNCTION_MASK
end_define

begin_comment
comment|/*  * OID_GEN_RECEIVE_SCALE_PARAMETERS  * ndis_type: NDIS_OBJTYPE_RSS_PARAMS  */
end_comment

begin_struct
struct|struct
name|ndis_rss_params
block|{
name|struct
name|ndis_object_hdr
name|ndis_hdr
decl_stmt|;
name|uint16_t
name|ndis_flags
decl_stmt|;
comment|/* NDIS_RSS_FLAG_ */
name|uint16_t
name|ndis_bcpu
decl_stmt|;
comment|/* base cpu 0 */
name|uint32_t
name|ndis_hash
decl_stmt|;
comment|/* NDIS_HASH_ */
name|uint16_t
name|ndis_indsize
decl_stmt|;
comment|/* indirect table */
name|uint32_t
name|ndis_indoffset
decl_stmt|;
name|uint16_t
name|ndis_keysize
decl_stmt|;
comment|/* hash key */
name|uint32_t
name|ndis_keyoffset
decl_stmt|;
comment|/* NDIS>= 6.20 */
name|uint32_t
name|ndis_cpumaskoffset
decl_stmt|;
name|uint32_t
name|ndis_cpumaskcnt
decl_stmt|;
name|uint32_t
name|ndis_cpumaskentsz
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NDIS_RSS_PARAMS_SIZE
value|sizeof(struct ndis_rss_params)
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_PARAMS_SIZE_6_0
define|\
value|__offsetof(struct ndis_rss_params, ndis_cpumaskoffset)
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_PARAMS_REV_1
value|1
end_define

begin_comment
comment|/* NDIS 6.0 */
end_comment

begin_define
define|#
directive|define
name|NDIS_RSS_PARAMS_REV_2
value|2
end_define

begin_comment
comment|/* NDIS 6.20 */
end_comment

begin_define
define|#
directive|define
name|NDIS_RSS_FLAG_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_FLAG_BCPU_UNCHG
value|0x0001
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_FLAG_HASH_UNCHG
value|0x0002
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_FLAG_IND_UNCHG
value|0x0004
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_FLAG_KEY_UNCHG
value|0x0008
end_define

begin_define
define|#
directive|define
name|NDIS_RSS_FLAG_DISABLE
value|0x0010
end_define

begin_comment
comment|/* non-standard convenient struct */
end_comment

begin_struct
struct|struct
name|ndis_rssprm_toeplitz
block|{
name|struct
name|ndis_rss_params
name|rss_params
decl_stmt|;
comment|/* Toeplitz hash key */
name|uint8_t
name|rss_key
index|[
name|NDIS_HASH_KEYSIZE_TOEPLITZ
index|]
decl_stmt|;
comment|/* Indirect table */
name|uint32_t
name|rss_ind
index|[
name|NDIS_HASH_INDCNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NDIS_RSSPRM_TOEPLITZ_SIZE
parameter_list|(
name|nind
parameter_list|)
define|\
value|__offsetof(struct ndis_rssprm_toeplitz, rss_ind[nind])
end_define

begin_comment
comment|/*  * OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES  * ndis_type: NDIS_OBJTYPE_OFFLOAD  */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_ENCAP_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_ENCAP_NULL
value|0x0001
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_ENCAP_8023
value|0x0002
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_ENCAP_8023PQ
value|0x0004
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_ENCAP_8023PQ_OOB
value|0x0008
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_ENCAP_RFC1483
value|0x0010
end_define

begin_struct
struct|struct
name|ndis_csum_offload
block|{
name|uint32_t
name|ndis_ip4_txenc
decl_stmt|;
comment|/*NDIS_OFFLOAD_ENCAP_*/
name|uint32_t
name|ndis_ip4_txcsum
decl_stmt|;
define|#
directive|define
name|NDIS_TXCSUM_CAP_IP4OPT
value|0x001
define|#
directive|define
name|NDIS_TXCSUM_CAP_TCP4OPT
value|0x004
define|#
directive|define
name|NDIS_TXCSUM_CAP_TCP4
value|0x010
define|#
directive|define
name|NDIS_TXCSUM_CAP_UDP4
value|0x040
define|#
directive|define
name|NDIS_TXCSUM_CAP_IP4
value|0x100
name|uint32_t
name|ndis_ip4_rxenc
decl_stmt|;
comment|/*NDIS_OFFLOAD_ENCAP_*/
name|uint32_t
name|ndis_ip4_rxcsum
decl_stmt|;
define|#
directive|define
name|NDIS_RXCSUM_CAP_IP4OPT
value|0x001
define|#
directive|define
name|NDIS_RXCSUM_CAP_TCP4OPT
value|0x004
define|#
directive|define
name|NDIS_RXCSUM_CAP_TCP4
value|0x010
define|#
directive|define
name|NDIS_RXCSUM_CAP_UDP4
value|0x040
define|#
directive|define
name|NDIS_RXCSUM_CAP_IP4
value|0x100
name|uint32_t
name|ndis_ip6_txenc
decl_stmt|;
comment|/*NDIS_OFFLOAD_ENCAP_*/
name|uint32_t
name|ndis_ip6_txcsum
decl_stmt|;
define|#
directive|define
name|NDIS_TXCSUM_CAP_IP6EXT
value|0x001
define|#
directive|define
name|NDIS_TXCSUM_CAP_TCP6OPT
value|0x004
define|#
directive|define
name|NDIS_TXCSUM_CAP_TCP6
value|0x010
define|#
directive|define
name|NDIS_TXCSUM_CAP_UDP6
value|0x040
name|uint32_t
name|ndis_ip6_rxenc
decl_stmt|;
comment|/*NDIS_OFFLOAD_ENCAP_*/
name|uint32_t
name|ndis_ip6_rxcsum
decl_stmt|;
define|#
directive|define
name|NDIS_RXCSUM_CAP_IP6EXT
value|0x001
define|#
directive|define
name|NDIS_RXCSUM_CAP_TCP6OPT
value|0x004
define|#
directive|define
name|NDIS_RXCSUM_CAP_TCP6
value|0x010
define|#
directive|define
name|NDIS_RXCSUM_CAP_UDP6
value|0x040
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_lsov1_offload
block|{
name|uint32_t
name|ndis_encap
decl_stmt|;
comment|/*NDIS_OFFLOAD_ENCAP_*/
name|uint32_t
name|ndis_maxsize
decl_stmt|;
name|uint32_t
name|ndis_minsegs
decl_stmt|;
name|uint32_t
name|ndis_opts
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_ipsecv1_offload
block|{
name|uint32_t
name|ndis_encap
decl_stmt|;
comment|/*NDIS_OFFLOAD_ENCAP_*/
name|uint32_t
name|ndis_ah_esp
decl_stmt|;
name|uint32_t
name|ndis_xport_tun
decl_stmt|;
name|uint32_t
name|ndis_ip4_opts
decl_stmt|;
name|uint32_t
name|ndis_flags
decl_stmt|;
name|uint32_t
name|ndis_ip4_ah
decl_stmt|;
name|uint32_t
name|ndis_ip4_esp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_lsov2_offload
block|{
name|uint32_t
name|ndis_ip4_encap
decl_stmt|;
comment|/*NDIS_OFFLOAD_ENCAP_*/
name|uint32_t
name|ndis_ip4_maxsz
decl_stmt|;
name|uint32_t
name|ndis_ip4_minsg
decl_stmt|;
name|uint32_t
name|ndis_ip6_encap
decl_stmt|;
comment|/*NDIS_OFFLOAD_ENCAP_*/
name|uint32_t
name|ndis_ip6_maxsz
decl_stmt|;
name|uint32_t
name|ndis_ip6_minsg
decl_stmt|;
name|uint32_t
name|ndis_ip6_opts
decl_stmt|;
define|#
directive|define
name|NDIS_LSOV2_CAP_IP6EXT
value|0x001
define|#
directive|define
name|NDIS_LSOV2_CAP_TCP6OPT
value|0x004
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_ipsecv2_offload
block|{
name|uint32_t
name|ndis_encap
decl_stmt|;
comment|/*NDIS_OFFLOAD_ENCAP_*/
name|uint16_t
name|ndis_ip6
decl_stmt|;
name|uint16_t
name|ndis_ip4opt
decl_stmt|;
name|uint16_t
name|ndis_ip6ext
decl_stmt|;
name|uint16_t
name|ndis_ah
decl_stmt|;
name|uint16_t
name|ndis_esp
decl_stmt|;
name|uint16_t
name|ndis_ah_esp
decl_stmt|;
name|uint16_t
name|ndis_xport
decl_stmt|;
name|uint16_t
name|ndis_tun
decl_stmt|;
name|uint16_t
name|ndis_xport_tun
decl_stmt|;
name|uint16_t
name|ndis_lso
decl_stmt|;
name|uint16_t
name|ndis_extseq
decl_stmt|;
name|uint32_t
name|ndis_udp_esp
decl_stmt|;
name|uint32_t
name|ndis_auth
decl_stmt|;
name|uint32_t
name|ndis_crypto
decl_stmt|;
name|uint32_t
name|ndis_sa_caps
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_rsc_offload
block|{
name|uint16_t
name|ndis_ip4
decl_stmt|;
name|uint16_t
name|ndis_ip6
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_encap_offload
block|{
name|uint32_t
name|ndis_flags
decl_stmt|;
name|uint32_t
name|ndis_maxhdr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_offload
block|{
name|struct
name|ndis_object_hdr
name|ndis_hdr
decl_stmt|;
name|struct
name|ndis_csum_offload
name|ndis_csum
decl_stmt|;
name|struct
name|ndis_lsov1_offload
name|ndis_lsov1
decl_stmt|;
name|struct
name|ndis_ipsecv1_offload
name|ndis_ipsecv1
decl_stmt|;
name|struct
name|ndis_lsov2_offload
name|ndis_lsov2
decl_stmt|;
name|uint32_t
name|ndis_flags
decl_stmt|;
comment|/* NDIS>= 6.1 */
name|struct
name|ndis_ipsecv2_offload
name|ndis_ipsecv2
decl_stmt|;
comment|/* NDIS>= 6.30 */
name|struct
name|ndis_rsc_offload
name|ndis_rsc
decl_stmt|;
name|struct
name|ndis_encap_offload
name|ndis_encap_gre
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_SIZE
value|sizeof(struct ndis_offload)
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_SIZE_6_0
define|\
value|__offsetof(struct ndis_offload, ndis_ipsecv2)
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_SIZE_6_1
define|\
value|__offsetof(struct ndis_offload, ndis_rsc)
end_define

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_REV_1
value|1
end_define

begin_comment
comment|/* NDIS 6.0 */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_REV_2
value|2
end_define

begin_comment
comment|/* NDIS 6.1 */
end_comment

begin_define
define|#
directive|define
name|NDIS_OFFLOAD_REV_3
value|3
end_define

begin_comment
comment|/* NDIS 6.30 */
end_comment

begin_comment
comment|/*  * Per-packet-info  */
end_comment

begin_comment
comment|/* VLAN */
end_comment

begin_define
define|#
directive|define
name|NDIS_VLAN_INFO_SIZE
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|NDIS_VLAN_INFO_PRI_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|NDIS_VLAN_INFO_CFI_MASK
value|0x0008
end_define

begin_define
define|#
directive|define
name|NDIS_VLAN_INFO_ID_MASK
value|0xfff0
end_define

begin_define
define|#
directive|define
name|NDIS_VLAN_INFO_MAKE
parameter_list|(
name|id
parameter_list|,
name|pri
parameter_list|,
name|cfi
parameter_list|)
define|\
value|(((pri)& NDIS_VLAN_INFO_PRI_MASK) |	\ 	 (((cfi)& 0x1)<< 3) | (((id)& 0xfff)<< 4))
end_define

begin_define
define|#
directive|define
name|NDIS_VLAN_INFO_ID
parameter_list|(
name|inf
parameter_list|)
value|(((inf)& NDIS_VLAN_INFO_ID_MASK)>> 4)
end_define

begin_define
define|#
directive|define
name|NDIS_VLAN_INFO_CFI
parameter_list|(
name|inf
parameter_list|)
value|(((inf)& NDIS_VLAN_INFO_CFI_MASK)>> 3)
end_define

begin_define
define|#
directive|define
name|NDIS_VLAN_INFO_PRI
parameter_list|(
name|inf
parameter_list|)
value|((inf)& NDIS_VLAN_INFO_PRI_MASK)
end_define

begin_comment
comment|/* Reception checksum */
end_comment

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_SIZE
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_TCPCS_FAILED
value|0x0001
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_UDPCS_FAILED
value|0x0002
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_IPCS_FAILED
value|0x0004
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_TCPCS_OK
value|0x0008
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_UDPCS_OK
value|0x0010
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_IPCS_OK
value|0x0020
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_LOOPBACK
value|0x0040
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_TCPCS_INVAL
value|0x0080
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_INFO_IPCS_INVAL
value|0x0100
end_define

begin_comment
comment|/* LSOv2 */
end_comment

begin_define
define|#
directive|define
name|NDIS_LSO2_INFO_SIZE
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|NDIS_LSO2_INFO_MSS_MASK
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|NDIS_LSO2_INFO_THOFF_MASK
value|0x3ff00000
end_define

begin_define
define|#
directive|define
name|NDIS_LSO2_INFO_ISLSO2
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NDIS_LSO2_INFO_ISIPV6
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NDIS_LSO2_INFO_MAKE
parameter_list|(
name|thoff
parameter_list|,
name|mss
parameter_list|)
define|\
value|((((uint32_t)(mss))& NDIS_LSO2_INFO_MSS_MASK) |	\ 	 ((((uint32_t)(thoff))& 0x3ff)<< 20) |		\ 	 NDIS_LSO2_INFO_ISLSO2)
end_define

begin_define
define|#
directive|define
name|NDIS_LSO2_INFO_MAKEIPV4
parameter_list|(
name|thoff
parameter_list|,
name|mss
parameter_list|)
define|\
value|NDIS_LSO2_INFO_MAKE((thoff), (mss))
end_define

begin_define
define|#
directive|define
name|NDIS_LSO2_INFO_MAKEIPV6
parameter_list|(
name|thoff
parameter_list|,
name|mss
parameter_list|)
define|\
value|(NDIS_LSO2_INFO_MAKE((thoff), (mss)) | NDIS_LSO2_INFO_ISIPV6)
end_define

begin_comment
comment|/* Transmission checksum */
end_comment

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_SIZE
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_IPV4
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_IPV6
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_TCPCS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_UDPCS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_IPCS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_THOFF
value|0x03ff0000
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_MKL4CS
parameter_list|(
name|thoff
parameter_list|,
name|flag
parameter_list|)
define|\
value|((((uint32_t)(thoff))<< 16) | (flag))
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_MKTCPCS
parameter_list|(
name|thoff
parameter_list|)
define|\
value|NDIS_TXCSUM_INFO_MKL4CS((thoff), NDIS_TXCSUM_INFO_TCPCS)
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_INFO_MKUDPCS
parameter_list|(
name|thoff
parameter_list|)
define|\
value|NDIS_TXCSUM_INFO_MKL4CS((thoff), NDIS_TXCSUM_INFO_UDPCS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_NDIS_H_ */
end_comment

end_unit

