begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/dhcp6.h,v 1.4 2000/12/17 23:07:48 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (C) 1998 and 1999 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * draft-ietf-dhc-dhcpv6-15  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DHCP6_H_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|__DHCP6_H_DEFINED
end_define

begin_comment
comment|/* Error Values */
end_comment

begin_define
define|#
directive|define
name|DH6ERR_FAILURE
value|16
end_define

begin_define
define|#
directive|define
name|DH6ERR_AUTHFAIL
value|17
end_define

begin_define
define|#
directive|define
name|DH6ERR_POORLYFORMED
value|18
end_define

begin_define
define|#
directive|define
name|DH6ERR_UNAVAIL
value|19
end_define

begin_define
define|#
directive|define
name|DH6ERR_NOBINDING
value|20
end_define

begin_define
define|#
directive|define
name|DH6ERR_INVALIDSOURCE
value|21
end_define

begin_define
define|#
directive|define
name|DH6ERR_NOSERVER
value|23
end_define

begin_define
define|#
directive|define
name|DH6ERR_ICMPERROR
value|64
end_define

begin_comment
comment|/* Message type */
end_comment

begin_define
define|#
directive|define
name|DH6_SOLICIT
value|1
end_define

begin_define
define|#
directive|define
name|DH6_ADVERT
value|2
end_define

begin_define
define|#
directive|define
name|DH6_REQUEST
value|3
end_define

begin_define
define|#
directive|define
name|DH6_REPLY
value|4
end_define

begin_define
define|#
directive|define
name|DH6_RELEASE
value|5
end_define

begin_define
define|#
directive|define
name|DH6_RECONFIG
value|6
end_define

begin_comment
comment|/* Predefined addresses */
end_comment

begin_define
define|#
directive|define
name|DH6ADDR_ALLAGENT
value|"ff02::1:2"
end_define

begin_define
define|#
directive|define
name|DH6ADDR_ALLSERVER
value|"ff05::1:3"
end_define

begin_define
define|#
directive|define
name|DH6ADDR_ALLRELAY
value|"ff05::1:4"
end_define

begin_define
define|#
directive|define
name|DH6PORT_DOWNSTREAM
value|"546"
end_define

begin_define
define|#
directive|define
name|DH6PORT_UPSTREAM
value|"547"
end_define

begin_comment
comment|/* Protocol constants */
end_comment

begin_define
define|#
directive|define
name|ADV_CLIENT_WAIT
value|2
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SOLICIT_HOPCOUNT
value|4
end_define

begin_define
define|#
directive|define
name|SERVER_MIN_ADV_DELAY
value|100
end_define

begin_comment
comment|/* msec */
end_comment

begin_define
define|#
directive|define
name|SERVER_MAX_ADV_DELAY
value|1000
end_define

begin_comment
comment|/* msec */
end_comment

begin_define
define|#
directive|define
name|REPLY_MSG_TIMEOUT
value|2
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|REQUEST_MSG_MIN_RETRANS
value|10
end_define

begin_comment
comment|/* retransmissions */
end_comment

begin_define
define|#
directive|define
name|RECONF_MSG_MIN_RETRANS
value|10
end_define

begin_comment
comment|/* retransmissions */
end_comment

begin_define
define|#
directive|define
name|RECONF_MSG_RETRANS_INTERVAL
value|12
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|RECONF_MMSG_MIN_RESP
value|2
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|RECONF_MMSG_MAX_RESP
value|10
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|RECONF_MULTICAST_REQUEST_WAIT
value|120
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|MIN_SOLICIT_DELAY
value|1
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|MAX_SOLICIT_DELAY
value|5
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|XID_TIMEOUT
value|600
end_define

begin_comment
comment|/* sec */
end_comment

begin_comment
comment|/* DHCP6 base packet format */
end_comment

begin_struct
struct|struct
name|dhcp6_solicit
block|{
name|u_int8_t
name|dh6sol_msgtype
decl_stmt|;
comment|/* DH6_SOLICIT */
name|u_int8_t
name|dh6sol_flags
decl_stmt|;
define|#
directive|define
name|DH6SOL_CLOSE
value|0x80
define|#
directive|define
name|DH6SOL_PREFIX
value|0x40
comment|/* XXX: solicit-ID is a 9-bit field...ugly! */
define|#
directive|define
name|DH6SOL_SOLICIT_ID_MASK
value|0x01ff
define|#
directive|define
name|DH6SOL_SOLICIT_ID_SHIFT
value|0
define|#
directive|define
name|DH6SOL_SOLICIT_ID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& DH6SOL_SOLICIT_ID_MASK)>> DH6SOL_SOLICIT_ID_SHIFT)
define|#
directive|define
name|DH6SOL_SOLICIT_PLEN_MASK
value|0xfe00
define|#
directive|define
name|DH6SOL_SOLICIT_PLEN_SHIFT
value|9
define|#
directive|define
name|DH6SOL_SOLICIT_PLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& DH6SOL_SOLICIT_PLEN_MASK)>> DH6SOL_SOLICIT_PLEN_SHIFT)
name|u_int16_t
name|dh6sol_plen_id
decl_stmt|;
comment|/* prefix-len and solict-ID */
name|struct
name|in6_addr
name|dh6sol_cliaddr
decl_stmt|;
comment|/* client's lladdr */
name|struct
name|in6_addr
name|dh6sol_relayaddr
decl_stmt|;
comment|/* relay agent's lladdr */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dhcp6_advert
block|{
name|u_int8_t
name|dh6adv_msgtype
decl_stmt|;
comment|/* DH6_ADVERT */
name|u_int8_t
name|dh6adv_rsv_id
decl_stmt|;
comment|/* reserved and uppermost bit of ID */
name|u_int8_t
name|dh6adv_solcit_id
decl_stmt|;
comment|/* lower 8 bits of solicit-ID */
name|u_int8_t
name|dh6adv_pref
decl_stmt|;
name|struct
name|in6_addr
name|dh6adv_cliaddr
decl_stmt|;
comment|/* client's link-local addr */
name|struct
name|in6_addr
name|dh6adv_relayaddr
decl_stmt|;
comment|/* relay agent's (non-ll) addr */
name|struct
name|in6_addr
name|dh6adv_serveraddr
decl_stmt|;
comment|/* server's addr */
comment|/* extensions */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dhcp6_request
block|{
name|u_int8_t
name|dh6req_msgtype
decl_stmt|;
comment|/* DH6_REQUEST */
name|u_int8_t
name|dh6req_flags
decl_stmt|;
define|#
directive|define
name|DH6REQ_CLOSE
value|0x80
define|#
directive|define
name|DH6REQ_REBOOT
value|0x40
name|u_int16_t
name|dh6req_xid
decl_stmt|;
comment|/* transaction-ID */
name|struct
name|in6_addr
name|dh6req_cliaddr
decl_stmt|;
comment|/* client's lladdr */
name|struct
name|in6_addr
name|dh6req_relayaddr
decl_stmt|;
comment|/* relay agent's (non-ll) addr */
name|struct
name|in6_addr
name|dh6req_serveraddr
decl_stmt|;
comment|/* server's addr */
comment|/* extensions */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dhcp6_reply
block|{
name|u_int8_t
name|dh6rep_msgtype
decl_stmt|;
comment|/* DH6_REPLY */
name|u_int8_t
name|dh6rep_flagandstat
decl_stmt|;
define|#
directive|define
name|DH6REP_RELAYPRESENT
value|0x80
define|#
directive|define
name|DH6REP_STATMASK
value|0x7f
name|u_int16_t
name|dh6rep_xid
decl_stmt|;
comment|/* transaction-ID */
name|struct
name|in6_addr
name|dh6rep_cliaddr
decl_stmt|;
comment|/* client's lladdr */
comment|/* struct in6_addr dh6rep_relayaddr; optional: relay address */
comment|/* extensions */
block|}
struct|;
end_struct

begin_comment
comment|/* XXX: followings are based on older drafts */
end_comment

begin_struct
struct|struct
name|dhcp6_release
block|{
name|u_int8_t
name|dh6rel_msgtype
decl_stmt|;
comment|/* DH6_RELEASE */
name|u_int8_t
name|dh6rel_flags
decl_stmt|;
define|#
directive|define
name|DH6REL_DIRECT
value|0x80
name|u_int16_t
name|dh6rel_xid
decl_stmt|;
comment|/* transaction-ID */
name|struct
name|in6_addr
name|dh6rel_cliaddr
decl_stmt|;
comment|/* client's lladdr */
name|struct
name|in6_addr
name|dh6rel_relayaddr
decl_stmt|;
comment|/* relay agent's (non-ll) addr */
name|struct
name|in6_addr
name|dh6rel_reladdr
decl_stmt|;
comment|/* server's addr to be released */
comment|/* extensions */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dhcp6_reconfig
block|{
name|u_int8_t
name|dh6cfg_msgtype
decl_stmt|;
comment|/* DH6_RECONFIG */
name|u_int8_t
name|dh6cfg_flags
decl_stmt|;
define|#
directive|define
name|DH6REP_NOREPLY
value|0x80
name|u_int16_t
name|dh6cfg_xid
decl_stmt|;
comment|/* transaction-ID */
name|struct
name|in6_addr
name|dh6cfg_servaddr
decl_stmt|;
comment|/* server's addr */
comment|/* extensions */
block|}
struct|;
end_struct

begin_union
union|union
name|dhcp6
block|{
name|u_int8_t
name|dh6_msgtype
decl_stmt|;
name|struct
name|dhcp6_solicit
name|dh6_sol
decl_stmt|;
name|struct
name|dhcp6_advert
name|dh6_adv
decl_stmt|;
name|struct
name|dhcp6_request
name|dh6_req
decl_stmt|;
name|struct
name|dhcp6_reply
name|dh6_rep
decl_stmt|;
name|struct
name|dhcp6_release
name|dh6_rel
decl_stmt|;
name|struct
name|dhcp6_reconfig
name|dh6_cfg
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* DHCP6 extension */
end_comment

begin_struct
struct|struct
name|dhcp6e_ipaddr
block|{
name|u_int16_t
name|dh6eip_type
decl_stmt|;
name|u_int16_t
name|dh6eip_len
decl_stmt|;
name|u_int8_t
name|dh6eip_status
decl_stmt|;
define|#
directive|define
name|DH6EX_IP_SUCCESS
value|0
comment|/* request granted, no errors */
define|#
directive|define
name|DH6EX_IP_SECFAIL
value|18
comment|/* Security parameters failed */
define|#
directive|define
name|DH6EX_IP_AAAAFAIL
value|20
comment|/* AAAA Record Parameter Problem */
define|#
directive|define
name|DH6EX_IP_PTRFAIL
value|21
comment|/* PTR Record Parameter Problem */
define|#
directive|define
name|DH6EX_IP_PARAMFAIL
value|22
comment|/* Unable to honor required params */
define|#
directive|define
name|DH6EX_IP_DNSNAMEFAIL
value|23
comment|/* DNS name string error */
define|#
directive|define
name|DH6EX_IP_NODYNDNS
value|24
comment|/* dynDNS Not Implemented */
define|#
directive|define
name|DH6EX_IP_NOAUTHDNS
value|25
comment|/* Authoritative DNS Server not found */
define|#
directive|define
name|DH6EX_IP_DNSFORMFAIL
value|33
comment|/* DNS format error */
define|#
directive|define
name|DH6EX_IP_SERVFAIL
value|34
comment|/* dynDNS unavailable at this time */
define|#
directive|define
name|DH6EX_IP_NXDOMAIN
value|35
comment|/* name does not exist */
define|#
directive|define
name|DH6EX_IP_NOTIMP
value|36
comment|/* DNS does not support the Opcode */
define|#
directive|define
name|DH6EX_IP_REFUSED
value|37
comment|/* DNS refuses specified operation */
define|#
directive|define
name|DH6EX_IP_YXDOMAIN
value|38
comment|/* name does not exist */
define|#
directive|define
name|DH6EX_IP_YXRRSET
value|39
comment|/* RRset does not exist */
define|#
directive|define
name|DH6EX_IP_NXRRSET
value|40
comment|/* RRset does not exist */
define|#
directive|define
name|DH6EX_IP_NOTAUTH
value|41
comment|/* non authoritative name server */
define|#
directive|define
name|DH6EX_IP_NOTZONE
value|42
comment|/* prerequisite out of zone */
name|u_int8_t
name|dh6eip_flags
decl_stmt|;
define|#
directive|define
name|DH6EX_IP_CLIANTADDR
value|0x80
comment|/* C: cliant's addr */
define|#
directive|define
name|DH6EX_IP_LIFETIME
value|0x40
comment|/* L: preferred/valid lifetime */
define|#
directive|define
name|DH6EX_IP_FORCEOPTS
value|0x20
comment|/* Q: options are mandatory */
define|#
directive|define
name|DH6EX_IP_AAAA
value|0x10
comment|/* A: DNS dynamic update for AAAA */
define|#
directive|define
name|DH6EX_IP_PTR
value|0x08
comment|/* P: DNS dynamic update for PTR*/
name|u_int8_t
name|dh6eip_pad
decl_stmt|;
name|u_int8_t
name|dh6eip_prefixlen
decl_stmt|;
comment|/* struct in6_addr: client's address (if C bit = 1) */
comment|/* u_int: preferred lifetime (if L bit = 1) */
comment|/* u_int: valid lifetime (if L bit = 1) */
comment|/* string: DNS name */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__DHCP6_H_DEFINED*/
end_comment

end_unit

