begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ipsec.h,v 1.53 2001/11/20 08:32:38 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * IPsec controller part.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPSEC_IPSEC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPSEC_IPSEC_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LKM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_include
include|#
directive|include
file|"opt_ipsec.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/pfkeyv2.h>
end_include

begin_include
include|#
directive|include
file|<netipsec/keydb.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/_rwlock.h>
end_include

begin_define
define|#
directive|define
name|IPSEC_ASSERT
parameter_list|(
name|_c
parameter_list|,
name|_m
parameter_list|)
value|KASSERT(_c, _m)
end_define

begin_comment
comment|/*  * Security Policy Index  * Ensure that both address families in the "src" and "dst" are same.  * When the value of the ul_proto is ICMPv6, the port field in "src"  * specifies ICMPv6 type, and the port field in "dst" specifies ICMPv6 code.  */
end_comment

begin_struct
struct|struct
name|secpolicyindex
block|{
name|union
name|sockaddr_union
name|src
decl_stmt|;
comment|/* IP src address for SP */
name|union
name|sockaddr_union
name|dst
decl_stmt|;
comment|/* IP dst address for SP */
name|uint8_t
name|ul_proto
decl_stmt|;
comment|/* upper layer Protocol */
name|uint8_t
name|dir
decl_stmt|;
comment|/* direction of packet flow */
name|uint8_t
name|prefs
decl_stmt|;
comment|/* prefix length in bits for src */
name|uint8_t
name|prefd
decl_stmt|;
comment|/* prefix length in bits for dst */
block|}
struct|;
end_struct

begin_comment
comment|/* Request for IPsec */
end_comment

begin_struct
struct|struct
name|ipsecrequest
block|{
name|struct
name|secasindex
name|saidx
decl_stmt|;
comment|/* hint for search proper SA */
comment|/* if __ss_len == 0 then no address specified.*/
name|u_int
name|level
decl_stmt|;
comment|/* IPsec level defined below. */
block|}
struct|;
end_struct

begin_comment
comment|/* Security Policy Data Base */
end_comment

begin_struct
struct|struct
name|secpolicy
block|{
name|TAILQ_ENTRY
argument_list|(
argument|secpolicy
argument_list|)
name|chain
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|secpolicy
argument_list|)
name|idhash
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|secpolicy
argument_list|)
name|drainq
expr_stmt|;
name|struct
name|secpolicyindex
name|spidx
decl_stmt|;
comment|/* selector */
define|#
directive|define
name|IPSEC_MAXREQ
value|4
name|struct
name|ipsecrequest
modifier|*
name|req
index|[
name|IPSEC_MAXREQ
index|]
decl_stmt|;
name|u_int
name|tcount
decl_stmt|;
comment|/* IPsec transforms count */
specifier|volatile
name|u_int
name|refcnt
decl_stmt|;
comment|/* reference count */
name|u_int
name|policy
decl_stmt|;
comment|/* policy_type per pfkeyv2.h */
name|u_int
name|state
decl_stmt|;
define|#
directive|define
name|IPSEC_SPSTATE_DEAD
value|0
define|#
directive|define
name|IPSEC_SPSTATE_LARVAL
value|1
define|#
directive|define
name|IPSEC_SPSTATE_ALIVE
value|2
define|#
directive|define
name|IPSEC_SPSTATE_PCB
value|3
define|#
directive|define
name|IPSEC_SPSTATE_IFNET
value|4
name|uint32_t
name|priority
decl_stmt|;
comment|/* priority of this policy */
name|uint32_t
name|id
decl_stmt|;
comment|/* It's unique number on the system. */
comment|/* 	 * lifetime handler. 	 * the policy can be used without limitiation if both lifetime and 	 * validtime are zero. 	 * "lifetime" is passed by sadb_lifetime.sadb_lifetime_addtime. 	 * "validtime" is passed by sadb_lifetime.sadb_lifetime_usetime. 	 */
name|time_t
name|created
decl_stmt|;
comment|/* time created the policy */
name|time_t
name|lastused
decl_stmt|;
comment|/* updated every when kernel sends a packet */
name|long
name|lifetime
decl_stmt|;
comment|/* duration of the lifetime of this policy */
name|long
name|validtime
decl_stmt|;
comment|/* duration this policy is valid without use */
block|}
struct|;
end_struct

begin_comment
comment|/*  * PCB security policies.  * Application can setup private security policies for socket.  * Such policies can have IPSEC, BYPASS and ENTRUST type.  * By default, policies are set to NULL. This means that they have ENTRUST type.  * When application sets BYPASS or IPSEC type policy, the flags field  * is also updated. When flags is not set, the system could store  * used security policy into the sp_in/sp_out pointer to speed up further  * lookups.  */
end_comment

begin_struct
struct|struct
name|inpcbpolicy
block|{
name|struct
name|secpolicy
modifier|*
name|sp_in
decl_stmt|;
name|struct
name|secpolicy
modifier|*
name|sp_out
decl_stmt|;
name|uint32_t
name|genid
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|INP_INBOUND_POLICY
value|0x0001
define|#
directive|define
name|INP_OUTBOUND_POLICY
value|0x0002
name|uint16_t
name|hdrsz
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SP acquiring list table. */
end_comment

begin_struct
struct|struct
name|secspacq
block|{
name|LIST_ENTRY
argument_list|(
argument|secspacq
argument_list|)
name|chain
expr_stmt|;
name|struct
name|secpolicyindex
name|spidx
decl_stmt|;
name|time_t
name|created
decl_stmt|;
comment|/* for lifetime */
name|int
name|count
decl_stmt|;
comment|/* for lifetime */
comment|/* XXX: here is mbuf place holder to be sent ? */
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

begin_comment
comment|/* buffer size for formatted output of ipsec address */
end_comment

begin_define
define|#
directive|define
name|IPSEC_ADDRSTRLEN
value|(INET6_ADDRSTRLEN + 11)
end_define

begin_comment
comment|/* according to IANA assignment, port 0x0000 and proto 0xff are reserved. */
end_comment

begin_define
define|#
directive|define
name|IPSEC_PORT_ANY
value|0
end_define

begin_define
define|#
directive|define
name|IPSEC_ULPROTO_ANY
value|255
end_define

begin_define
define|#
directive|define
name|IPSEC_PROTO_ANY
value|255
end_define

begin_comment
comment|/* mode of security protocol */
end_comment

begin_comment
comment|/* NOTE: DON'T use IPSEC_MODE_ANY at SPD.  It's only use in SAD */
end_comment

begin_define
define|#
directive|define
name|IPSEC_MODE_ANY
value|0
end_define

begin_comment
comment|/* i.e. wildcard. */
end_comment

begin_define
define|#
directive|define
name|IPSEC_MODE_TRANSPORT
value|1
end_define

begin_define
define|#
directive|define
name|IPSEC_MODE_TUNNEL
value|2
end_define

begin_define
define|#
directive|define
name|IPSEC_MODE_TCPMD5
value|3
end_define

begin_comment
comment|/* TCP MD5 mode */
end_comment

begin_comment
comment|/*  * Direction of security policy.  * NOTE: Since INVALID is used just as flag.  * The other are used for loop counter too.  */
end_comment

begin_define
define|#
directive|define
name|IPSEC_DIR_ANY
value|0
end_define

begin_define
define|#
directive|define
name|IPSEC_DIR_INBOUND
value|1
end_define

begin_define
define|#
directive|define
name|IPSEC_DIR_OUTBOUND
value|2
end_define

begin_define
define|#
directive|define
name|IPSEC_DIR_MAX
value|3
end_define

begin_define
define|#
directive|define
name|IPSEC_DIR_INVALID
value|4
end_define

begin_comment
comment|/* Policy level */
end_comment

begin_comment
comment|/*  * IPSEC, ENTRUST and BYPASS are allowed for setsockopt() in PCB,  * DISCARD, IPSEC and NONE are allowed for setkey() in SPD.  * DISCARD and NONE are allowed for system default.  */
end_comment

begin_define
define|#
directive|define
name|IPSEC_POLICY_DISCARD
value|0
end_define

begin_comment
comment|/* discarding packet */
end_comment

begin_define
define|#
directive|define
name|IPSEC_POLICY_NONE
value|1
end_define

begin_comment
comment|/* through IPsec engine */
end_comment

begin_define
define|#
directive|define
name|IPSEC_POLICY_IPSEC
value|2
end_define

begin_comment
comment|/* do IPsec */
end_comment

begin_define
define|#
directive|define
name|IPSEC_POLICY_ENTRUST
value|3
end_define

begin_comment
comment|/* consulting SPD if present. */
end_comment

begin_define
define|#
directive|define
name|IPSEC_POLICY_BYPASS
value|4
end_define

begin_comment
comment|/* only for privileged socket. */
end_comment

begin_comment
comment|/* Policy scope */
end_comment

begin_define
define|#
directive|define
name|IPSEC_POLICYSCOPE_ANY
value|0x00
end_define

begin_comment
comment|/* unspecified */
end_comment

begin_define
define|#
directive|define
name|IPSEC_POLICYSCOPE_GLOBAL
value|0x01
end_define

begin_comment
comment|/* global scope */
end_comment

begin_define
define|#
directive|define
name|IPSEC_POLICYSCOPE_IFNET
value|0x02
end_define

begin_comment
comment|/* if_ipsec(4) scope */
end_comment

begin_define
define|#
directive|define
name|IPSEC_POLICYSCOPE_PCB
value|0x04
end_define

begin_comment
comment|/* PCB scope */
end_comment

begin_comment
comment|/* Security protocol level */
end_comment

begin_define
define|#
directive|define
name|IPSEC_LEVEL_DEFAULT
value|0
end_define

begin_comment
comment|/* reference to system default */
end_comment

begin_define
define|#
directive|define
name|IPSEC_LEVEL_USE
value|1
end_define

begin_comment
comment|/* use SA if present. */
end_comment

begin_define
define|#
directive|define
name|IPSEC_LEVEL_REQUIRE
value|2
end_define

begin_comment
comment|/* require SA. */
end_comment

begin_define
define|#
directive|define
name|IPSEC_LEVEL_UNIQUE
value|3
end_define

begin_comment
comment|/* unique SA. */
end_comment

begin_define
define|#
directive|define
name|IPSEC_MANUAL_REQID_MAX
value|0x3fff
end_define

begin_comment
comment|/* 				 * if security policy level == unique, this id 				 * indicate to a relative SA for use, else is 				 * zero. 				 * 1 - 0x3fff are reserved for manual keying. 				 * 0 are reserved for above reason.  Others is 				 * for kernel use. 				 * Note that this id doesn't identify SA 				 * by only itself. 				 */
end_comment

begin_define
define|#
directive|define
name|IPSEC_REPLAYWSIZE
value|32
end_define

begin_comment
comment|/* statistics for ipsec processing */
end_comment

begin_struct
struct|struct
name|ipsecstat
block|{
name|uint64_t
name|ips_in_polvio
decl_stmt|;
comment|/* input: sec policy violation */
name|uint64_t
name|ips_in_nomem
decl_stmt|;
comment|/* input: no memory available */
name|uint64_t
name|ips_in_inval
decl_stmt|;
comment|/* input: generic error */
name|uint64_t
name|ips_out_polvio
decl_stmt|;
comment|/* output: sec policy violation */
name|uint64_t
name|ips_out_nosa
decl_stmt|;
comment|/* output: SA unavailable  */
name|uint64_t
name|ips_out_nomem
decl_stmt|;
comment|/* output: no memory available */
name|uint64_t
name|ips_out_noroute
decl_stmt|;
comment|/* output: no route available */
name|uint64_t
name|ips_out_inval
decl_stmt|;
comment|/* output: generic error */
name|uint64_t
name|ips_out_bundlesa
decl_stmt|;
comment|/* output: bundled SA processed */
name|uint64_t
name|ips_mbcoalesced
decl_stmt|;
comment|/* mbufs coalesced during clone */
name|uint64_t
name|ips_clcoalesced
decl_stmt|;
comment|/* clusters coalesced during clone */
name|uint64_t
name|ips_clcopied
decl_stmt|;
comment|/* clusters copied during clone */
name|uint64_t
name|ips_mbinserted
decl_stmt|;
comment|/* mbufs inserted during makespace */
comment|/*  	 * Temporary statistics for performance analysis. 	 */
comment|/* See where ESP/AH/IPCOMP header land in mbuf on input */
name|uint64_t
name|ips_input_front
decl_stmt|;
name|uint64_t
name|ips_input_middle
decl_stmt|;
name|uint64_t
name|ips_input_end
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for IPsec& Key sysctl operations.  */
end_comment

begin_define
define|#
directive|define
name|IPSECCTL_STATS
value|1
end_define

begin_comment
comment|/* stats */
end_comment

begin_define
define|#
directive|define
name|IPSECCTL_DEF_POLICY
value|2
end_define

begin_define
define|#
directive|define
name|IPSECCTL_DEF_ESP_TRANSLEV
value|3
end_define

begin_comment
comment|/* int; ESP transport mode */
end_comment

begin_define
define|#
directive|define
name|IPSECCTL_DEF_ESP_NETLEV
value|4
end_define

begin_comment
comment|/* int; ESP tunnel mode */
end_comment

begin_define
define|#
directive|define
name|IPSECCTL_DEF_AH_TRANSLEV
value|5
end_define

begin_comment
comment|/* int; AH transport mode */
end_comment

begin_define
define|#
directive|define
name|IPSECCTL_DEF_AH_NETLEV
value|6
end_define

begin_comment
comment|/* int; AH tunnel mode */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* obsolete, do not reuse */
end_comment

begin_define
define|#
directive|define
name|IPSECCTL_INBOUND_CALL_IKE
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPSECCTL_AH_CLEARTOS
value|8
end_define

begin_define
define|#
directive|define
name|IPSECCTL_AH_OFFSETMASK
value|9
end_define

begin_define
define|#
directive|define
name|IPSECCTL_DFBIT
value|10
end_define

begin_define
define|#
directive|define
name|IPSECCTL_ECN
value|11
end_define

begin_define
define|#
directive|define
name|IPSECCTL_DEBUG
value|12
end_define

begin_define
define|#
directive|define
name|IPSECCTL_ESP_RANDPAD
value|13
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

begin_struct_decl
struct_decl|struct
name|ipsec_ctx_data
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|IPSEC_INIT_CTX
parameter_list|(
name|_ctx
parameter_list|,
name|_mp
parameter_list|,
name|_inp
parameter_list|,
name|_sav
parameter_list|,
name|_af
parameter_list|,
name|_enc
parameter_list|)
value|do {	\ 	(_ctx)->mp = (_mp);				\ 	(_ctx)->inp = (_inp);				\ 	(_ctx)->sav = (_sav);				\ 	(_ctx)->af = (_af);				\ 	(_ctx)->enc = (_enc);				\ } while(0)
end_define

begin_function_decl
name|int
name|ipsec_run_hhooks
parameter_list|(
name|struct
name|ipsec_ctx_data
modifier|*
name|ctx
parameter_list|,
name|int
name|direction
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipsec_debug
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ipsec_debug
value|VNET(ipsec_debug)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REGRESSION
end_ifdef

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipsec_replay
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipsec_integrity
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ipsec_replay
value|VNET(ipsec_replay)
end_define

begin_define
define|#
directive|define
name|V_ipsec_integrity
value|VNET(ipsec_integrity)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|VNET_PCPUSTAT_DECLARE
argument_list|(
expr|struct
name|ipsecstat
argument_list|,
name|ipsec4stat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip4_esp_trans_deflev
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip4_esp_net_deflev
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip4_ah_trans_deflev
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip4_ah_net_deflev
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip4_ah_offsetmask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip4_ipsec_dfbit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip4_ipsec_ecn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip4_esp_randpad
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|crypto_support
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|natt_cksum_policy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|IPSECSTAT_INC
parameter_list|(
name|name
parameter_list|)
define|\
value|VNET_PCPUSTAT_ADD(struct ipsecstat, ipsec4stat, name, 1)
end_define

begin_define
define|#
directive|define
name|V_ip4_esp_trans_deflev
value|VNET(ip4_esp_trans_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip4_esp_net_deflev
value|VNET(ip4_esp_net_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip4_ah_trans_deflev
value|VNET(ip4_ah_trans_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip4_ah_net_deflev
value|VNET(ip4_ah_net_deflev)
end_define

begin_define
define|#
directive|define
name|V_ip4_ah_offsetmask
value|VNET(ip4_ah_offsetmask)
end_define

begin_define
define|#
directive|define
name|V_ip4_ipsec_dfbit
value|VNET(ip4_ipsec_dfbit)
end_define

begin_define
define|#
directive|define
name|V_ip4_ipsec_ecn
value|VNET(ip4_ipsec_ecn)
end_define

begin_define
define|#
directive|define
name|V_ip4_esp_randpad
value|VNET(ip4_esp_randpad)
end_define

begin_define
define|#
directive|define
name|V_crypto_support
value|VNET(crypto_support)
end_define

begin_define
define|#
directive|define
name|V_natt_cksum_policy
value|VNET(natt_cksum_policy)
end_define

begin_define
define|#
directive|define
name|ipseclog
parameter_list|(
name|x
parameter_list|)
value|do { if (V_ipsec_debug) log x; } while (0)
end_define

begin_comment
comment|/* for openbsd compatibility */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|IPSEC_DEBUG_DECLARE
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|)
value|do { if (V_ipsec_debug) printf x; } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPSEC_DEBUG_DECLARE
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|m_tag
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|secasvar
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tcphdr
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|sockaddr_union
union_decl|;
end_union_decl

begin_function_decl
name|int
name|ipsec_if_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|secasvar
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ipsecrequest
modifier|*
name|ipsec_newisr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipsec_delisr
parameter_list|(
name|struct
name|ipsecrequest
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|secpolicy
modifier|*
name|ipsec4_checkpolicy
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|ipsec_get_reqlevel
parameter_list|(
name|struct
name|secpolicy
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udp_ipsec_adjust_cksum
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|secasvar
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|udp_ipsec_output
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|secasvar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|udp_ipsec_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|udp_ipsec_pcbctl
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_chkreplay
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|secasvar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_updatereplay
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|secasvar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_updateid
parameter_list|(
name|struct
name|secasvar
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_initialized
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipsec_setspidx_inpcb
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|secpolicyindex
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipsec4_setsockaddrs
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|,
name|union
name|sockaddr_union
modifier|*
parameter_list|,
name|union
name|sockaddr_union
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec4_in_reject
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec4_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec4_forward
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec4_pcbctl
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec4_output
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec4_capability
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec4_common_input_cb
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|secasvar
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec4_process_packet
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|secpolicy
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipsec_process_done
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|secpolicy
modifier|*
parameter_list|,
name|struct
name|secasvar
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|m_checkalignment
parameter_list|(
specifier|const
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|int
name|off
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|m_makespace
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|int
name|skip
parameter_list|,
name|int
name|hlen
parameter_list|,
name|int
modifier|*
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|caddr_t
name|m_pad
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|m_striphdr
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|skip
parameter_list|,
name|int
name|hlen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
specifier|extern
name|caddr_t
name|ipsec_set_policy
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipsec_get_policylen
parameter_list|(
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ipsec_dump_policy
parameter_list|(
name|caddr_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|ipsec_strerror
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
comment|/* ! KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETIPSEC_IPSEC_H_ */
end_comment

end_unit

