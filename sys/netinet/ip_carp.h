begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: ip_carp.h,v 1.8 2004/07/29 22:12:15 mcbride Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2002 Michael Shalayeff. All rights reserved.  * Copyright (c) 2003 Ryan McBride. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_CARP_H
end_ifndef

begin_define
define|#
directive|define
name|_IP_CARP_H
end_define

begin_comment
comment|/*  * The CARP header layout is as follows:  *  *     0                   1                   2                   3  *     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |Version| Type  | VirtualHostID |    AdvSkew    |    Auth Len   |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |   Reserved    |     AdvBase   |          Checksum             |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |                         Counter (1)                           |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |                         Counter (2)                           |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |                        SHA-1 HMAC (1)                         |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |                        SHA-1 HMAC (2)                         |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |                        SHA-1 HMAC (3)                         |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |                        SHA-1 HMAC (4)                         |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |                        SHA-1 HMAC (5)                         |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *  */
end_comment

begin_struct
struct|struct
name|carp_header
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_int8_t
name|carp_type
range|:
literal|4
decl_stmt|,
name|carp_version
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int8_t
name|carp_version
range|:
literal|4
decl_stmt|,
name|carp_type
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|u_int8_t
name|carp_vhid
decl_stmt|;
comment|/* virtual host id */
name|u_int8_t
name|carp_advskew
decl_stmt|;
comment|/* advertisement skew */
name|u_int8_t
name|carp_authlen
decl_stmt|;
comment|/* size of counter+md, 32bit chunks */
name|u_int8_t
name|carp_pad1
decl_stmt|;
comment|/* reserved */
name|u_int8_t
name|carp_advbase
decl_stmt|;
comment|/* advertisement interval */
name|u_int16_t
name|carp_cksum
decl_stmt|;
name|u_int32_t
name|carp_counter
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|carp_md
index|[
literal|20
index|]
decl_stmt|;
comment|/* SHA1 HMAC */
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|carp_header
argument_list|)
operator|==
literal|36
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CARP_DFLTTL
value|255
end_define

begin_comment
comment|/* carp_version */
end_comment

begin_define
define|#
directive|define
name|CARP_VERSION
value|2
end_define

begin_comment
comment|/* carp_type */
end_comment

begin_define
define|#
directive|define
name|CARP_ADVERTISEMENT
value|0x01
end_define

begin_define
define|#
directive|define
name|CARP_KEY_LEN
value|20
end_define

begin_comment
comment|/* a sha1 hash of a passphrase */
end_comment

begin_comment
comment|/* carp_advbase */
end_comment

begin_define
define|#
directive|define
name|CARP_DFLTINTV
value|1
end_define

begin_comment
comment|/*  * Statistics.  */
end_comment

begin_struct
struct|struct
name|carpstats
block|{
name|uint64_t
name|carps_ipackets
decl_stmt|;
comment|/* total input packets, IPv4 */
name|uint64_t
name|carps_ipackets6
decl_stmt|;
comment|/* total input packets, IPv6 */
name|uint64_t
name|carps_badif
decl_stmt|;
comment|/* wrong interface */
name|uint64_t
name|carps_badttl
decl_stmt|;
comment|/* TTL is not CARP_DFLTTL */
name|uint64_t
name|carps_hdrops
decl_stmt|;
comment|/* packets shorter than hdr */
name|uint64_t
name|carps_badsum
decl_stmt|;
comment|/* bad checksum */
name|uint64_t
name|carps_badver
decl_stmt|;
comment|/* bad (incl unsupp) version */
name|uint64_t
name|carps_badlen
decl_stmt|;
comment|/* data length does not match */
name|uint64_t
name|carps_badauth
decl_stmt|;
comment|/* bad authentication */
name|uint64_t
name|carps_badvhid
decl_stmt|;
comment|/* bad VHID */
name|uint64_t
name|carps_badaddrs
decl_stmt|;
comment|/* bad address list */
name|uint64_t
name|carps_opackets
decl_stmt|;
comment|/* total output packets, IPv4 */
name|uint64_t
name|carps_opackets6
decl_stmt|;
comment|/* total output packets, IPv6 */
name|uint64_t
name|carps_onomem
decl_stmt|;
comment|/* no memory for an mbuf */
name|uint64_t
name|carps_ostates
decl_stmt|;
comment|/* total state updates sent */
name|uint64_t
name|carps_preempt
decl_stmt|;
comment|/* if enabled, preemptions */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Configuration structure for SIOCSVH SIOCGVH  */
end_comment

begin_struct
struct|struct
name|carpreq
block|{
name|int
name|carpr_state
decl_stmt|;
define|#
directive|define
name|CARP_STATES
value|"INIT", "BACKUP", "MASTER"
define|#
directive|define
name|CARP_MAXSTATE
value|2
name|int
name|carpr_vhid
decl_stmt|;
name|int
name|carpr_advskew
decl_stmt|;
name|int
name|carpr_advbase
decl_stmt|;
name|unsigned
name|char
name|carpr_key
index|[
name|CARP_KEY_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCSVH
value|_IOWR('i', 245, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGVH
value|_IOWR('i', 246, struct ifreq)
end_define

begin_comment
comment|/*  * Names for CARP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|CARPCTL_ALLOW
value|1
end_define

begin_comment
comment|/* accept incoming CARP packets */
end_comment

begin_define
define|#
directive|define
name|CARPCTL_PREEMPT
value|2
end_define

begin_comment
comment|/* high-pri backup preemption mode */
end_comment

begin_define
define|#
directive|define
name|CARPCTL_LOG
value|3
end_define

begin_comment
comment|/* log bad packets */
end_comment

begin_define
define|#
directive|define
name|CARPCTL_STATS
value|4
end_define

begin_comment
comment|/* statistics (read-only) */
end_comment

begin_define
define|#
directive|define
name|CARPCTL_ARPBALANCE
value|5
end_define

begin_comment
comment|/* balance arp responses */
end_comment

begin_define
define|#
directive|define
name|CARPCTL_MAXID
value|6
end_define

begin_define
define|#
directive|define
name|CARPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "allow", CTLTYPE_INT }, \ 	{ "preempt", CTLTYPE_INT }, \ 	{ "log", CTLTYPE_INT }, \ 	{ "stats", CTLTYPE_STRUCT }, \ 	{ "arpbalance", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|carp_carpdev_state
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|carp_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|carp6_input
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|carp_output
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|carp_iamatch
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|in_ifaddr
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|carp_iamatch6
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|carp_macmatch6
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifnet
modifier|*
name|carp_forus
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IP_CARP_H */
end_comment

end_unit

