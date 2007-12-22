begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/aodv.h,v 1.3 2003/09/13 01:34:42 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (c) 2003 Bruce M. Simpson<bms@spc.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by Bruce M. Simpson.  * 4. Neither the name of Bruce M. Simpson nor the names of co-  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bruce M. Simpson AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL Bruce M. Simpson OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AODV_H_
end_ifndef

begin_define
define|#
directive|define
name|_AODV_H_
end_define

begin_struct
struct|struct
name|aodv_rreq
block|{
name|u_int8_t
name|rreq_type
decl_stmt|;
comment|/* AODV message type (1) */
name|u_int8_t
name|rreq_flags
decl_stmt|;
comment|/* various flags */
name|u_int8_t
name|rreq_zero0
decl_stmt|;
comment|/* reserved, set to zero */
name|u_int8_t
name|rreq_hops
decl_stmt|;
comment|/* number of hops from originator */
name|u_int32_t
name|rreq_id
decl_stmt|;
comment|/* request ID */
name|u_int32_t
name|rreq_da
decl_stmt|;
comment|/* destination IPv4 address */
name|u_int32_t
name|rreq_ds
decl_stmt|;
comment|/* destination sequence number */
name|u_int32_t
name|rreq_oa
decl_stmt|;
comment|/* originator IPv4 address */
name|u_int32_t
name|rreq_os
decl_stmt|;
comment|/* originator sequence number */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_struct
struct|struct
name|aodv_rreq6
block|{
name|u_int8_t
name|rreq_type
decl_stmt|;
comment|/* AODV message type (1) */
name|u_int8_t
name|rreq_flags
decl_stmt|;
comment|/* various flags */
name|u_int8_t
name|rreq_zero0
decl_stmt|;
comment|/* reserved, set to zero */
name|u_int8_t
name|rreq_hops
decl_stmt|;
comment|/* number of hops from originator */
name|u_int32_t
name|rreq_id
decl_stmt|;
comment|/* request ID */
name|struct
name|in6_addr
name|rreq_da
decl_stmt|;
comment|/* destination IPv6 address */
name|u_int32_t
name|rreq_ds
decl_stmt|;
comment|/* destination sequence number */
name|struct
name|in6_addr
name|rreq_oa
decl_stmt|;
comment|/* originator IPv6 address */
name|u_int32_t
name|rreq_os
decl_stmt|;
comment|/* originator sequence number */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aodv_rreq6_draft_01
block|{
name|u_int8_t
name|rreq_type
decl_stmt|;
comment|/* AODV message type (16) */
name|u_int8_t
name|rreq_flags
decl_stmt|;
comment|/* various flags */
name|u_int8_t
name|rreq_zero0
decl_stmt|;
comment|/* reserved, set to zero */
name|u_int8_t
name|rreq_hops
decl_stmt|;
comment|/* number of hops from originator */
name|u_int32_t
name|rreq_id
decl_stmt|;
comment|/* request ID */
name|u_int32_t
name|rreq_ds
decl_stmt|;
comment|/* destination sequence number */
name|u_int32_t
name|rreq_os
decl_stmt|;
comment|/* originator sequence number */
name|struct
name|in6_addr
name|rreq_da
decl_stmt|;
comment|/* destination IPv6 address */
name|struct
name|in6_addr
name|rreq_oa
decl_stmt|;
comment|/* originator IPv6 address */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RREQ_JOIN
value|0x80
end_define

begin_comment
comment|/* join (reserved for multicast */
end_comment

begin_define
define|#
directive|define
name|RREQ_REPAIR
value|0x40
end_define

begin_comment
comment|/* repair (reserved for multicast */
end_comment

begin_define
define|#
directive|define
name|RREQ_GRAT
value|0x20
end_define

begin_comment
comment|/* gratuitous RREP */
end_comment

begin_define
define|#
directive|define
name|RREQ_DEST
value|0x10
end_define

begin_comment
comment|/* destination only */
end_comment

begin_define
define|#
directive|define
name|RREQ_UNKNOWN
value|0x08
end_define

begin_comment
comment|/* unknown destination sequence num */
end_comment

begin_define
define|#
directive|define
name|RREQ_FLAGS_MASK
value|0xF8
end_define

begin_comment
comment|/* mask for rreq_flags */
end_comment

begin_struct
struct|struct
name|aodv_rrep
block|{
name|u_int8_t
name|rrep_type
decl_stmt|;
comment|/* AODV message type (2) */
name|u_int8_t
name|rrep_flags
decl_stmt|;
comment|/* various flags */
name|u_int8_t
name|rrep_ps
decl_stmt|;
comment|/* prefix size */
name|u_int8_t
name|rrep_hops
decl_stmt|;
comment|/* number of hops from o to d */
name|u_int32_t
name|rrep_da
decl_stmt|;
comment|/* destination IPv4 address */
name|u_int32_t
name|rrep_ds
decl_stmt|;
comment|/* destination sequence number */
name|u_int32_t
name|rrep_oa
decl_stmt|;
comment|/* originator IPv4 address */
name|u_int32_t
name|rrep_life
decl_stmt|;
comment|/* lifetime of this route */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_struct
struct|struct
name|aodv_rrep6
block|{
name|u_int8_t
name|rrep_type
decl_stmt|;
comment|/* AODV message type (2) */
name|u_int8_t
name|rrep_flags
decl_stmt|;
comment|/* various flags */
name|u_int8_t
name|rrep_ps
decl_stmt|;
comment|/* prefix size */
name|u_int8_t
name|rrep_hops
decl_stmt|;
comment|/* number of hops from o to d */
name|struct
name|in6_addr
name|rrep_da
decl_stmt|;
comment|/* destination IPv6 address */
name|u_int32_t
name|rrep_ds
decl_stmt|;
comment|/* destination sequence number */
name|struct
name|in6_addr
name|rrep_oa
decl_stmt|;
comment|/* originator IPv6 address */
name|u_int32_t
name|rrep_life
decl_stmt|;
comment|/* lifetime of this route */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aodv_rrep6_draft_01
block|{
name|u_int8_t
name|rrep_type
decl_stmt|;
comment|/* AODV message type (17) */
name|u_int8_t
name|rrep_flags
decl_stmt|;
comment|/* various flags */
name|u_int8_t
name|rrep_ps
decl_stmt|;
comment|/* prefix size */
name|u_int8_t
name|rrep_hops
decl_stmt|;
comment|/* number of hops from o to d */
name|u_int32_t
name|rrep_ds
decl_stmt|;
comment|/* destination sequence number */
name|struct
name|in6_addr
name|rrep_da
decl_stmt|;
comment|/* destination IPv6 address */
name|struct
name|in6_addr
name|rrep_oa
decl_stmt|;
comment|/* originator IPv6 address */
name|u_int32_t
name|rrep_life
decl_stmt|;
comment|/* lifetime of this route */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RREP_REPAIR
value|0x80
end_define

begin_comment
comment|/* repair (reserved for multicast */
end_comment

begin_define
define|#
directive|define
name|RREP_ACK
value|0x40
end_define

begin_comment
comment|/* acknowledgement required */
end_comment

begin_define
define|#
directive|define
name|RREP_FLAGS_MASK
value|0xC0
end_define

begin_comment
comment|/* mask for rrep_flags */
end_comment

begin_define
define|#
directive|define
name|RREP_PREFIX_MASK
value|0x1F
end_define

begin_comment
comment|/* mask for prefix size */
end_comment

begin_struct
struct|struct
name|rerr_unreach
block|{
name|u_int32_t
name|u_da
decl_stmt|;
comment|/* IPv4 address */
name|u_int32_t
name|u_ds
decl_stmt|;
comment|/* sequence number */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_struct
struct|struct
name|rerr_unreach6
block|{
name|struct
name|in6_addr
name|u_da
decl_stmt|;
comment|/* IPv6 address */
name|u_int32_t
name|u_ds
decl_stmt|;
comment|/* sequence number */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rerr_unreach6_draft_01
block|{
name|struct
name|in6_addr
name|u_da
decl_stmt|;
comment|/* IPv6 address */
name|u_int32_t
name|u_ds
decl_stmt|;
comment|/* sequence number */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|aodv_rerr
block|{
name|u_int8_t
name|rerr_type
decl_stmt|;
comment|/* AODV message type (3 or 18) */
name|u_int8_t
name|rerr_flags
decl_stmt|;
comment|/* various flags */
name|u_int8_t
name|rerr_zero0
decl_stmt|;
comment|/* reserved, set to zero */
name|u_int8_t
name|rerr_dc
decl_stmt|;
comment|/* destination count */
union|union
block|{
name|struct
name|rerr_unreach
name|dest
index|[
literal|1
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|INET6
name|struct
name|rerr_unreach6
name|dest6
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|rerr_unreach6_draft_01
name|dest6_draft_01
index|[
literal|1
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|r
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RERR_NODELETE
value|0x80
end_define

begin_comment
comment|/* don't delete the link */
end_comment

begin_define
define|#
directive|define
name|RERR_FLAGS_MASK
value|0x80
end_define

begin_comment
comment|/* mask for rerr_flags */
end_comment

begin_struct
struct|struct
name|aodv_rrep_ack
block|{
name|u_int8_t
name|ra_type
decl_stmt|;
name|u_int8_t
name|ra_zero0
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|aodv
block|{
name|struct
name|aodv_rreq
name|rreq
decl_stmt|;
name|struct
name|aodv_rrep
name|rrep
decl_stmt|;
name|struct
name|aodv_rerr
name|rerr
decl_stmt|;
name|struct
name|aodv_rrep_ack
name|rrep_ack
decl_stmt|;
ifdef|#
directive|ifdef
name|INET6
name|struct
name|aodv_rreq6
name|rreq6
decl_stmt|;
name|struct
name|aodv_rreq6_draft_01
name|rreq6_draft_01
decl_stmt|;
name|struct
name|aodv_rrep6
name|rrep6
decl_stmt|;
name|struct
name|aodv_rrep6_draft_01
name|rrep6_draft_01
decl_stmt|;
endif|#
directive|endif
block|}
union|;
end_union

begin_define
define|#
directive|define
name|AODV_RREQ
value|1
end_define

begin_comment
comment|/* route request */
end_comment

begin_define
define|#
directive|define
name|AODV_RREP
value|2
end_define

begin_comment
comment|/* route response */
end_comment

begin_define
define|#
directive|define
name|AODV_RERR
value|3
end_define

begin_comment
comment|/* error report */
end_comment

begin_define
define|#
directive|define
name|AODV_RREP_ACK
value|4
end_define

begin_comment
comment|/* route response acknowledgement */
end_comment

begin_define
define|#
directive|define
name|AODV_V6_DRAFT_01_RREQ
value|16
end_define

begin_comment
comment|/* IPv6 route request */
end_comment

begin_define
define|#
directive|define
name|AODV_V6_DRAFT_01_RREP
value|17
end_define

begin_comment
comment|/* IPv6 route response */
end_comment

begin_define
define|#
directive|define
name|AODV_V6_DRAFT_01_RERR
value|18
end_define

begin_comment
comment|/* IPv6 error report */
end_comment

begin_define
define|#
directive|define
name|AODV_V6_DRAFT_01_RREP_ACK
value|19
end_define

begin_comment
comment|/* IPV6 route response acknowledgment */
end_comment

begin_struct
struct|struct
name|aodv_ext
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* extension type */
name|u_int8_t
name|length
decl_stmt|;
comment|/* extension length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aodv_hello
block|{
name|struct
name|aodv_ext
name|eh
decl_stmt|;
comment|/* extension header */
name|u_int32_t
name|interval
decl_stmt|;
comment|/* expect my next hello in 						 * (n) ms */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AODV_EXT_HELLO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AODV_H_ */
end_comment

end_unit

