begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ipsec.h,v 1.44 2001/03/23 08:08:47 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * IPsec controller part.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IPSEC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IPSEC_H_
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
file|<netkey/keydb.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Security Policy Index  * NOTE: Ensure to be same address family and upper layer protocol.  * NOTE: ul_proto, port number, uid, gid:  *	ANY: reserved for waldcard.  *	0 to (~0 - 1): is one of the number of each value.  */
end_comment

begin_struct
struct|struct
name|secpolicyindex
block|{
name|u_int8_t
name|dir
decl_stmt|;
comment|/* direction of packet flow, see blow */
name|struct
name|sockaddr_storage
name|src
decl_stmt|;
comment|/* IP src address for SP */
name|struct
name|sockaddr_storage
name|dst
decl_stmt|;
comment|/* IP dst address for SP */
name|u_int8_t
name|prefs
decl_stmt|;
comment|/* prefix length in bits for src */
name|u_int8_t
name|prefd
decl_stmt|;
comment|/* prefix length in bits for dst */
name|u_int16_t
name|ul_proto
decl_stmt|;
comment|/* upper layer Protocol */
ifdef|#
directive|ifdef
name|notyet
name|uid_t
name|uids
decl_stmt|;
name|uid_t
name|uidd
decl_stmt|;
name|gid_t
name|gids
decl_stmt|;
name|gid_t
name|gidd
decl_stmt|;
endif|#
directive|endif
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
name|LIST_ENTRY
argument_list|(
argument|secpolicy
argument_list|)
name|chain
expr_stmt|;
name|int
name|refcnt
decl_stmt|;
comment|/* reference count */
name|struct
name|secpolicyindex
name|spidx
decl_stmt|;
comment|/* selector */
name|u_int32_t
name|id
decl_stmt|;
comment|/* It's unique number on the system. */
name|u_int
name|state
decl_stmt|;
comment|/* 0: dead, others: alive */
define|#
directive|define
name|IPSEC_SPSTATE_DEAD
value|0
define|#
directive|define
name|IPSEC_SPSTATE_ALIVE
value|1
name|u_int
name|policy
decl_stmt|;
comment|/* DISCARD, NONE or IPSEC, see keyv2.h */
name|struct
name|ipsecrequest
modifier|*
name|req
decl_stmt|;
comment|/* pointer to the ipsec request tree, */
comment|/* if policy == IPSEC else this value == NULL.*/
comment|/* 	 * lifetime handler. 	 * the policy can be used without limitiation if both lifetime and 	 * validtime are zero. 	 * "lifetime" is passed by sadb_lifetime.sadb_lifetime_addtime. 	 * "validtime" is passed by sadb_lifetime.sadb_lifetime_usetime. 	 */
name|long
name|created
decl_stmt|;
comment|/* time created the policy */
name|long
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
comment|/* Request for IPsec */
end_comment

begin_struct
struct|struct
name|ipsecrequest
block|{
name|struct
name|ipsecrequest
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next structure */
comment|/* If NULL, it means the end of chain. */
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
name|struct
name|secasvar
modifier|*
name|sav
decl_stmt|;
comment|/* place holder of SA for use */
name|struct
name|secpolicy
modifier|*
name|sp
decl_stmt|;
comment|/* back pointer to SP */
block|}
struct|;
end_struct

begin_comment
comment|/* security policy in PCB */
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
name|int
name|priv
decl_stmt|;
comment|/* privileged socket ? */
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
name|long
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
comment|/*_KERNEL*/
end_comment

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
name|u_quad_t
name|in_success
decl_stmt|;
comment|/* succeeded inbound process */
name|u_quad_t
name|in_polvio
decl_stmt|;
comment|/* security policy violation for inbound process */
name|u_quad_t
name|in_nosa
decl_stmt|;
comment|/* inbound SA is unavailable */
name|u_quad_t
name|in_inval
decl_stmt|;
comment|/* inbound processing failed due to EINVAL */
name|u_quad_t
name|in_nomem
decl_stmt|;
comment|/* inbound processing failed due to ENOBUFS */
name|u_quad_t
name|in_badspi
decl_stmt|;
comment|/* failed getting a SPI */
name|u_quad_t
name|in_ahreplay
decl_stmt|;
comment|/* AH replay check failed */
name|u_quad_t
name|in_espreplay
decl_stmt|;
comment|/* ESP replay check failed */
name|u_quad_t
name|in_ahauthsucc
decl_stmt|;
comment|/* AH authentication success */
name|u_quad_t
name|in_ahauthfail
decl_stmt|;
comment|/* AH authentication failure */
name|u_quad_t
name|in_espauthsucc
decl_stmt|;
comment|/* ESP authentication success */
name|u_quad_t
name|in_espauthfail
decl_stmt|;
comment|/* ESP authentication failure */
name|u_quad_t
name|in_esphist
index|[
literal|256
index|]
decl_stmt|;
name|u_quad_t
name|in_ahhist
index|[
literal|256
index|]
decl_stmt|;
name|u_quad_t
name|in_comphist
index|[
literal|256
index|]
decl_stmt|;
name|u_quad_t
name|out_success
decl_stmt|;
comment|/* succeeded outbound process */
name|u_quad_t
name|out_polvio
decl_stmt|;
comment|/* security policy violation for outbound process */
name|u_quad_t
name|out_nosa
decl_stmt|;
comment|/* outbound SA is unavailable */
name|u_quad_t
name|out_inval
decl_stmt|;
comment|/* outbound process failed due to EINVAL */
name|u_quad_t
name|out_nomem
decl_stmt|;
comment|/* inbound processing failed due to ENOBUFS */
name|u_quad_t
name|out_noroute
decl_stmt|;
comment|/* there is no route */
name|u_quad_t
name|out_esphist
index|[
literal|256
index|]
decl_stmt|;
name|u_quad_t
name|out_ahhist
index|[
literal|256
index|]
decl_stmt|;
name|u_quad_t
name|out_comphist
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for IPsec& Key sysctl operations.  */
end_comment

begin_comment
comment|/*  * Names for IPsec& Key sysctl objects  */
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
comment|/*obsolete, do not reuse*/
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

begin_define
define|#
directive|define
name|IPSECCTL_MAXID
value|14
end_define

begin_define
define|#
directive|define
name|IPSECCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "def_policy", CTLTYPE_INT }, \ 	{ "esp_trans_deflev", CTLTYPE_INT }, \ 	{ "esp_net_deflev", CTLTYPE_INT }, \ 	{ "ah_trans_deflev", CTLTYPE_INT }, \ 	{ "ah_net_deflev", CTLTYPE_INT }, \ 	{ 0, 0 }, \ 	{ "ah_cleartos", CTLTYPE_INT }, \ 	{ "ah_offsetmask", CTLTYPE_INT }, \ 	{ "dfbit", CTLTYPE_INT }, \ 	{ "ecn", CTLTYPE_INT }, \ 	{ "debug", CTLTYPE_INT }, \ 	{ "esp_randpad", CTLTYPE_INT }, \ }
end_define

begin_define
define|#
directive|define
name|IPSEC6CTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "def_policy", CTLTYPE_INT }, \ 	{ "esp_trans_deflev", CTLTYPE_INT }, \ 	{ "esp_net_deflev", CTLTYPE_INT }, \ 	{ "ah_trans_deflev", CTLTYPE_INT }, \ 	{ "ah_net_deflev", CTLTYPE_INT }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ 0, 0 }, \ 	{ "ecn", CTLTYPE_INT }, \ 	{ "debug", CTLTYPE_INT }, \ 	{ "esp_randpad", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|ipsec_output_state
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|route
modifier|*
name|ro
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|dst
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipsec_history
block|{
name|int
name|ih_proto
decl_stmt|;
name|u_int32_t
name|ih_spi
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|ipsec_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipsecstat
name|ipsecstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
name|ip4_def_policy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip4_esp_trans_deflev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip4_esp_net_deflev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip4_ah_trans_deflev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip4_ah_net_deflev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip4_ah_cleartos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip4_ah_offsetmask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip4_ipsec_dfbit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip4_ipsec_ecn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip4_esp_randpad
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ipseclog
parameter_list|(
name|x
parameter_list|)
value|do { if (ipsec_debug) log x; } while (0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
modifier|*
name|ipsec4_getpolicybysock
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|socket
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
modifier|*
name|ipsec4_getpolicybyaddr
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|u_int
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|ipsec_init_policy
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|inpcbpolicy
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec_copy_policy
name|__P
argument_list|(
operator|(
expr|struct
name|inpcbpolicy
operator|*
operator|,
expr|struct
name|inpcbpolicy
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|ipsec_get_reqlevel
name|__P
argument_list|(
operator|(
expr|struct
name|ipsecrequest
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec4_set_policy
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
name|inp
operator|,
name|int
name|optname
operator|,
name|caddr_t
name|request
operator|,
name|size_t
name|len
operator|,
name|int
name|priv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec4_get_policy
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
name|inpcb
operator|,
name|caddr_t
name|request
operator|,
name|size_t
name|len
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec4_delete_pcbpolicy
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec4_in_reject_so
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|socket
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec4_in_reject
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|secas
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tcpcb
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|ipsec_chkreplay
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|,
expr|struct
name|secasvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec_updatereplay
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|,
expr|struct
name|secasvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|ipsec4_hdrsiz
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|ipsec_hdrsiz_tcp
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|ip
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ipsec4_logpacketstr
name|__P
argument_list|(
operator|(
expr|struct
name|ip
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ipsec_logsastr
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
name|ipsec_dumpmbuf
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec4_output
name|__P
argument_list|(
operator|(
expr|struct
name|ipsec_output_state
operator|*
operator|,
expr|struct
name|secpolicy
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec4_tunnel_validate
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|u_int
operator|,
expr|struct
name|secasvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mbuf
modifier|*
name|ipsec_copypkt
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipsec_delaux
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec_setsocket
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|socket
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|socket
modifier|*
name|ipsec_getsocket
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec_addhist
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipsec_history
modifier|*
name|ipsec_gethist
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipsec_clearhist
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
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
comment|/*_KERNEL*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_decl_stmt
specifier|extern
name|caddr_t
name|ipsec_set_policy
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsec_get_policylen
name|__P
argument_list|(
operator|(
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ipsec_dump_policy
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ipsec_strerror
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_KERNEL*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_NETINET6_IPSEC_H_*/
end_comment

end_unit

