begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007-2008 University of Zagreb  * Copyright (c) 2007-2008 FreeBSD Foundation  *  * This software was developed by the University of Zagreb and the  * FreeBSD Foundation under sponsorship by the Stichting NLnet and the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPSEC_VIPSEC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPSEC_VIPSEC_H_
end_define

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ipsec.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/esp_var.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ah_var.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ipcomp_var.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/ipip_var.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<net/raw_cb.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/keysock.h>
end_include

begin_struct
struct|struct
name|vnet_ipsec
block|{
name|int
name|_ipsec_debug
decl_stmt|;
name|struct
name|ipsecstat
name|_ipsec4stat
decl_stmt|;
name|struct
name|secpolicy
name|_ip4_def_policy
decl_stmt|;
name|int
name|_ip4_esp_trans_deflev
decl_stmt|;
name|int
name|_ip4_esp_net_deflev
decl_stmt|;
name|int
name|_ip4_ah_trans_deflev
decl_stmt|;
name|int
name|_ip4_ah_net_deflev
decl_stmt|;
name|int
name|_ip4_ah_offsetmask
decl_stmt|;
name|int
name|_ip4_ipsec_dfbit
decl_stmt|;
name|int
name|_ip4_ipsec_ecn
decl_stmt|;
name|int
name|_ip4_esp_randpad
decl_stmt|;
name|int
name|_ipsec_replay
decl_stmt|;
name|int
name|_ipsec_integrity
decl_stmt|;
name|int
name|_crypto_support
decl_stmt|;
name|u_int32_t
name|_key_debug_level
decl_stmt|;
name|u_int
name|_key_spi_trycnt
decl_stmt|;
name|u_int32_t
name|_key_spi_minval
decl_stmt|;
name|u_int32_t
name|_key_spi_maxval
decl_stmt|;
name|u_int32_t
name|_policy_id
decl_stmt|;
name|u_int
name|_key_int_random
decl_stmt|;
name|u_int
name|_key_larval_lifetime
decl_stmt|;
name|int
name|_key_blockacq_count
decl_stmt|;
name|int
name|_key_blockacq_lifetime
decl_stmt|;
name|int
name|_key_preferred_oldsa
decl_stmt|;
name|u_int32_t
name|_acq_seq
decl_stmt|;
name|int
name|_esp_enable
decl_stmt|;
name|struct
name|espstat
name|_espstat
decl_stmt|;
name|int
name|_esp_max_ivlen
decl_stmt|;
name|int
name|_ipsec_esp_keymin
decl_stmt|;
name|int
name|_ipsec_esp_auth
decl_stmt|;
name|int
name|_ipsec_ah_keymin
decl_stmt|;
name|int
name|_ipip_allow
decl_stmt|;
name|struct
name|ipipstat
name|_ipipstat
decl_stmt|;
name|struct
name|ipsecstat
name|_ipsec6stat
decl_stmt|;
name|int
name|_ip6_esp_trans_deflev
decl_stmt|;
name|int
name|_ip6_esp_net_deflev
decl_stmt|;
name|int
name|_ip6_ah_trans_deflev
decl_stmt|;
name|int
name|_ip6_ah_net_deflev
decl_stmt|;
name|int
name|_ip6_ipsec_ecn
decl_stmt|;
name|int
name|_ah_enable
decl_stmt|;
name|int
name|_ah_cleartos
decl_stmt|;
name|struct
name|ahstat
name|_ahstat
decl_stmt|;
name|int
name|_ipcomp_enable
decl_stmt|;
name|struct
name|ipcompstat
name|_ipcompstat
decl_stmt|;
name|struct
name|pfkeystat
name|_pfkeystat
decl_stmt|;
name|struct
name|key_cb
name|_key_cb
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|secpolicy
argument_list|)
name|_sptree
index|[
name|IPSEC_DIR_MAX
index|]
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|secashead
argument_list|)
name|_sahtree
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|secreg
argument_list|)
name|_regtree
index|[
name|SADB_SATYPE_MAX
operator|+
literal|1
index|]
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|secacq
argument_list|)
name|_acqtree
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|secspacq
argument_list|)
name|_spacqtree
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Symbol translation macros  */
end_comment

begin_define
define|#
directive|define
name|INIT_VNET_IPSEC
parameter_list|(
name|vnet
parameter_list|)
define|\
value|INIT_FROM_VNET(vnet, VNET_MOD_IPSEC, struct vnet_ipsec, vnet_ipsec)
end_define

begin_define
define|#
directive|define
name|VNET_IPSEC
parameter_list|(
name|sym
parameter_list|)
value|VSYM(vnet_ipsec, sym)
end_define

begin_define
define|#
directive|define
name|V_acq_seq
value|VNET_IPSEC(acq_seq)
end_define

begin_define
define|#
directive|define
name|V_acqtree
value|VNET_IPSEC(acqtree)
end_define

begin_define
define|#
directive|define
name|V_ah_cleartos
value|VNET_IPSEC(ah_cleartos)
end_define

begin_define
define|#
directive|define
name|V_ah_enable
value|VNET_IPSEC(ah_enable)
end_define

begin_define
define|#
directive|define
name|V_ahstat
value|VNET_IPSEC(ahstat)
end_define

begin_define
define|#
directive|define
name|V_crypto_support
value|VNET_IPSEC(crypto_support)
end_define

begin_define
define|#
directive|define
name|V_esp_enable
value|VNET_IPSEC(esp_enable)
end_define

begin_define
define|#
directive|define
name|V_esp_max_ivlen
value|VNET_IPSEC(esp_max_ivlen)
end_define

begin_define
define|#
directive|define
name|V_espstat
value|VNET_IPSEC(espstat)
end_define

begin_define
define|#
directive|define
name|V_ip4_ah_net_deflev
value|VNET_IPSEC(ip4_ah_net_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip4_ah_offsetmask
value|VNET_IPSEC(ip4_ah_offsetmask)
end_define

begin_define
define|#
directive|define
name|V_ip4_ah_trans_deflev
value|VNET_IPSEC(ip4_ah_trans_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip4_def_policy
value|VNET_IPSEC(ip4_def_policy)
end_define

begin_define
define|#
directive|define
name|V_ip4_esp_net_deflev
value|VNET_IPSEC(ip4_esp_net_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip4_esp_randpad
value|VNET_IPSEC(ip4_esp_randpad)
end_define

begin_define
define|#
directive|define
name|V_ip4_esp_trans_deflev
value|VNET_IPSEC(ip4_esp_trans_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip4_ipsec_dfbit
value|VNET_IPSEC(ip4_ipsec_dfbit)
end_define

begin_define
define|#
directive|define
name|V_ip4_ipsec_ecn
value|VNET_IPSEC(ip4_ipsec_ecn)
end_define

begin_define
define|#
directive|define
name|V_ip6_ah_net_deflev
value|VNET_IPSEC(ip6_ah_net_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip6_ah_trans_deflev
value|VNET_IPSEC(ip6_ah_trans_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip6_esp_net_deflev
value|VNET_IPSEC(ip6_esp_net_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip6_esp_randpad
value|VNET_IPSEC(ip6_esp_randpad)
end_define

begin_define
define|#
directive|define
name|V_ip6_esp_trans_deflev
value|VNET_IPSEC(ip6_esp_trans_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip6_ipsec_ecn
value|VNET_IPSEC(ip6_ipsec_ecn)
end_define

begin_define
define|#
directive|define
name|V_ipcomp_enable
value|VNET_IPSEC(ipcomp_enable)
end_define

begin_define
define|#
directive|define
name|V_ipcompstat
value|VNET_IPSEC(ipcompstat)
end_define

begin_define
define|#
directive|define
name|V_ipip_allow
value|VNET_IPSEC(ipip_allow)
end_define

begin_define
define|#
directive|define
name|V_ipipstat
value|VNET_IPSEC(ipipstat)
end_define

begin_define
define|#
directive|define
name|V_ipsec4stat
value|VNET_IPSEC(ipsec4stat)
end_define

begin_define
define|#
directive|define
name|V_ipsec6stat
value|VNET_IPSEC(ipsec6stat)
end_define

begin_define
define|#
directive|define
name|V_ipsec_ah_keymin
value|VNET_IPSEC(ipsec_ah_keymin)
end_define

begin_define
define|#
directive|define
name|V_ipsec_debug
value|VNET_IPSEC(ipsec_debug)
end_define

begin_define
define|#
directive|define
name|V_ipsec_esp_auth
value|VNET_IPSEC(ipsec_esp_auth)
end_define

begin_define
define|#
directive|define
name|V_ipsec_esp_keymin
value|VNET_IPSEC(ipsec_esp_keymin)
end_define

begin_define
define|#
directive|define
name|V_ipsec_integrity
value|VNET_IPSEC(ipsec_integrity)
end_define

begin_define
define|#
directive|define
name|V_ipsec_replay
value|VNET_IPSEC(ipsec_replay)
end_define

begin_define
define|#
directive|define
name|V_key_blockacq_count
value|VNET_IPSEC(key_blockacq_count)
end_define

begin_define
define|#
directive|define
name|V_key_blockacq_lifetime
value|VNET_IPSEC(key_blockacq_lifetime)
end_define

begin_define
define|#
directive|define
name|V_key_cb
value|VNET_IPSEC(key_cb)
end_define

begin_define
define|#
directive|define
name|V_key_debug_level
value|VNET_IPSEC(key_debug_level)
end_define

begin_define
define|#
directive|define
name|V_key_int_random
value|VNET_IPSEC(key_int_random)
end_define

begin_define
define|#
directive|define
name|V_key_larval_lifetime
value|VNET_IPSEC(key_larval_lifetime)
end_define

begin_define
define|#
directive|define
name|V_key_preferred_oldsa
value|VNET_IPSEC(key_preferred_oldsa)
end_define

begin_define
define|#
directive|define
name|V_key_spi_maxval
value|VNET_IPSEC(key_spi_maxval)
end_define

begin_define
define|#
directive|define
name|V_key_spi_minval
value|VNET_IPSEC(key_spi_minval)
end_define

begin_define
define|#
directive|define
name|V_key_spi_trycnt
value|VNET_IPSEC(key_spi_trycnt)
end_define

begin_define
define|#
directive|define
name|V_pfkeystat
value|VNET_IPSEC(pfkeystat)
end_define

begin_define
define|#
directive|define
name|V_policy_id
value|VNET_IPSEC(policy_id)
end_define

begin_define
define|#
directive|define
name|V_regtree
value|VNET_IPSEC(regtree)
end_define

begin_define
define|#
directive|define
name|V_sahtree
value|VNET_IPSEC(sahtree)
end_define

begin_define
define|#
directive|define
name|V_spacqtree
value|VNET_IPSEC(spacqtree)
end_define

begin_define
define|#
directive|define
name|V_sptree
value|VNET_IPSEC(sptree)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETIPSEC_VIPSEC_H_ */
end_comment

end_unit

