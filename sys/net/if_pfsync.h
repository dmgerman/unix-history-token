begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Michael Shalayeff  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 David Gwynne<dlg@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  *	$OpenBSD: if_pfsync.h,v 1.35 2008/06/29 08:42:15 mcbride Exp $  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_PFSYNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_PFSYNC_H_
end_define

begin_define
define|#
directive|define
name|PFSYNC_VERSION
value|5
end_define

begin_define
define|#
directive|define
name|PFSYNC_DFLTTL
value|255
end_define

begin_define
define|#
directive|define
name|PFSYNC_ACT_CLR
value|0
end_define

begin_comment
comment|/* clear all states */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_INS
value|1
end_define

begin_comment
comment|/* insert state */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_INS_ACK
value|2
end_define

begin_comment
comment|/* ack of insterted state */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_UPD
value|3
end_define

begin_comment
comment|/* update state */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_UPD_C
value|4
end_define

begin_comment
comment|/* "compressed" update state */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_UPD_REQ
value|5
end_define

begin_comment
comment|/* request "uncompressed" state */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_DEL
value|6
end_define

begin_comment
comment|/* delete state */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_DEL_C
value|7
end_define

begin_comment
comment|/* "compressed" delete state */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_INS_F
value|8
end_define

begin_comment
comment|/* insert fragment */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_DEL_F
value|9
end_define

begin_comment
comment|/* delete fragments */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_BUS
value|10
end_define

begin_comment
comment|/* bulk update status */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_TDB
value|11
end_define

begin_comment
comment|/* TDB replay counter update */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_EOF
value|12
end_define

begin_comment
comment|/* end of frame */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_ACT_MAX
value|13
end_define

begin_comment
comment|/*  * A pfsync frame is built from a header followed by several sections which  * are all prefixed with their own subheaders. Frames must be terminated with  * an EOF subheader.  *  * | ...			|  * | IP header			|  * +============================+  * | pfsync_header		|  * +----------------------------+  * | pfsync_subheader		|  * +----------------------------+  * | first action fields	|  * | ...			|  * +----------------------------+  * | pfsync_subheader		|  * +----------------------------+  * | second action fields	|  * | ...			|  * +----------------------------+  * | EOF pfsync_subheader	|  * +----------------------------+  * | HMAC			|  * +============================+  */
end_comment

begin_comment
comment|/*  * Frame header  */
end_comment

begin_struct
struct|struct
name|pfsync_header
block|{
name|u_int8_t
name|version
decl_stmt|;
name|u_int8_t
name|_pad
decl_stmt|;
name|u_int16_t
name|len
decl_stmt|;
name|u_int8_t
name|pfcksum
index|[
name|PF_MD5_DIGEST_LENGTH
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Frame region subheader  */
end_comment

begin_struct
struct|struct
name|pfsync_subheader
block|{
name|u_int8_t
name|action
decl_stmt|;
name|u_int8_t
name|_pad
decl_stmt|;
name|u_int16_t
name|count
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CLR  */
end_comment

begin_struct
struct|struct
name|pfsync_clr
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * INS, UPD, DEL  */
end_comment

begin_comment
comment|/* these use struct pfsync_state in pfvar.h */
end_comment

begin_comment
comment|/*  * INS_ACK  */
end_comment

begin_struct
struct|struct
name|pfsync_ins_ack
block|{
name|u_int64_t
name|id
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * UPD_C  */
end_comment

begin_struct
struct|struct
name|pfsync_upd_c
block|{
name|u_int64_t
name|id
decl_stmt|;
name|struct
name|pfsync_state_peer
name|src
decl_stmt|;
name|struct
name|pfsync_state_peer
name|dst
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
name|u_int32_t
name|expire
decl_stmt|;
name|u_int8_t
name|timeout
decl_stmt|;
name|u_int8_t
name|_pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * UPD_REQ  */
end_comment

begin_struct
struct|struct
name|pfsync_upd_req
block|{
name|u_int64_t
name|id
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * DEL_C  */
end_comment

begin_struct
struct|struct
name|pfsync_del_c
block|{
name|u_int64_t
name|id
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * INS_F, DEL_F  */
end_comment

begin_comment
comment|/* not implemented (yet) */
end_comment

begin_comment
comment|/*  * BUS  */
end_comment

begin_struct
struct|struct
name|pfsync_bus
block|{
name|u_int32_t
name|creatorid
decl_stmt|;
name|u_int32_t
name|endtime
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
define|#
directive|define
name|PFSYNC_BUS_START
value|1
define|#
directive|define
name|PFSYNC_BUS_END
value|2
name|u_int8_t
name|_pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * TDB  */
end_comment

begin_struct
struct|struct
name|pfsync_tdb
block|{
name|u_int32_t
name|spi
decl_stmt|;
name|union
name|sockaddr_union
name|dst
decl_stmt|;
name|u_int32_t
name|rpl
decl_stmt|;
name|u_int64_t
name|cur_bytes
decl_stmt|;
name|u_int8_t
name|sproto
decl_stmt|;
name|u_int8_t
name|updates
decl_stmt|;
name|u_int8_t
name|_pad
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|PFSYNC_HDRLEN
value|sizeof(struct pfsync_header)
end_define

begin_struct
struct|struct
name|pfsyncstats
block|{
name|u_int64_t
name|pfsyncs_ipackets
decl_stmt|;
comment|/* total input packets, IPv4 */
name|u_int64_t
name|pfsyncs_ipackets6
decl_stmt|;
comment|/* total input packets, IPv6 */
name|u_int64_t
name|pfsyncs_badif
decl_stmt|;
comment|/* not the right interface */
name|u_int64_t
name|pfsyncs_badttl
decl_stmt|;
comment|/* TTL is not PFSYNC_DFLTTL */
name|u_int64_t
name|pfsyncs_hdrops
decl_stmt|;
comment|/* packets shorter than hdr */
name|u_int64_t
name|pfsyncs_badver
decl_stmt|;
comment|/* bad (incl unsupp) version */
name|u_int64_t
name|pfsyncs_badact
decl_stmt|;
comment|/* bad action */
name|u_int64_t
name|pfsyncs_badlen
decl_stmt|;
comment|/* data length does not match */
name|u_int64_t
name|pfsyncs_badauth
decl_stmt|;
comment|/* bad authentication */
name|u_int64_t
name|pfsyncs_stale
decl_stmt|;
comment|/* stale state */
name|u_int64_t
name|pfsyncs_badval
decl_stmt|;
comment|/* bad values */
name|u_int64_t
name|pfsyncs_badstate
decl_stmt|;
comment|/* insert/lookup failed */
name|u_int64_t
name|pfsyncs_opackets
decl_stmt|;
comment|/* total output packets, IPv4 */
name|u_int64_t
name|pfsyncs_opackets6
decl_stmt|;
comment|/* total output packets, IPv6 */
name|u_int64_t
name|pfsyncs_onomem
decl_stmt|;
comment|/* no memory for an mbuf */
name|u_int64_t
name|pfsyncs_oerrors
decl_stmt|;
comment|/* ip output error */
name|u_int64_t
name|pfsyncs_iacts
index|[
name|PFSYNC_ACT_MAX
index|]
decl_stmt|;
name|u_int64_t
name|pfsyncs_oacts
index|[
name|PFSYNC_ACT_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Configuration structure for SIOCSETPFSYNC SIOCGETPFSYNC  */
end_comment

begin_struct
struct|struct
name|pfsyncreq
block|{
name|char
name|pfsyncr_syncdev
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|in_addr
name|pfsyncr_syncpeer
decl_stmt|;
name|int
name|pfsyncr_maxupdates
decl_stmt|;
name|int
name|pfsyncr_defer
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCSETPFSYNC
value|_IOW('i', 247, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGETPFSYNC
value|_IOWR('i', 248, struct ifreq)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * this shows where a pf state is with respect to the syncing.  */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_S_INS
value|0x00
end_define

begin_define
define|#
directive|define
name|PFSYNC_S_IACK
value|0x01
end_define

begin_define
define|#
directive|define
name|PFSYNC_S_UPD
value|0x02
end_define

begin_define
define|#
directive|define
name|PFSYNC_S_UPD_C
value|0x03
end_define

begin_define
define|#
directive|define
name|PFSYNC_S_DEL
value|0x04
end_define

begin_define
define|#
directive|define
name|PFSYNC_S_COUNT
value|0x05
end_define

begin_define
define|#
directive|define
name|PFSYNC_S_DEFER
value|0xfe
end_define

begin_define
define|#
directive|define
name|PFSYNC_S_NONE
value|0xff
end_define

begin_define
define|#
directive|define
name|PFSYNC_SI_IOCTL
value|0x01
end_define

begin_define
define|#
directive|define
name|PFSYNC_SI_CKSUM
value|0x02
end_define

begin_define
define|#
directive|define
name|PFSYNC_SI_ACK
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_PFSYNC_H_ */
end_comment

end_unit

