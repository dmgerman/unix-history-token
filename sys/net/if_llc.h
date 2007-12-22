begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_llc.h,v 1.12 1999/11/19 20:41:19 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_llc.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_LLC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_LLC_H_
end_define

begin_comment
comment|/*  * IEEE 802.2 Link Level Control headers, for use in conjunction with  * 802.{3,4,5} media access control methods.  *  * Headers here do not use bit fields due to shortcommings in many  * compilers.  */
end_comment

begin_struct
struct|struct
name|llc
block|{
name|u_int8_t
name|llc_dsap
decl_stmt|;
name|u_int8_t
name|llc_ssap
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|control
decl_stmt|;
name|u_int8_t
name|format_id
decl_stmt|;
name|u_int8_t
name|class
decl_stmt|;
name|u_int8_t
name|window_x2
decl_stmt|;
block|}
name|__packed
name|type_u
struct|;
struct|struct
block|{
name|u_int8_t
name|num_snd_x2
decl_stmt|;
name|u_int8_t
name|num_rcv_x2
decl_stmt|;
block|}
name|__packed
name|type_i
struct|;
struct|struct
block|{
name|u_int8_t
name|control
decl_stmt|;
name|u_int8_t
name|num_rcv_x2
decl_stmt|;
block|}
name|__packed
name|type_s
struct|;
struct|struct
block|{
name|u_int8_t
name|control
decl_stmt|;
comment|/* 		 * We cannot put the following fields in a structure because 		 * the structure rounding might cause padding. 		 */
name|u_int8_t
name|frmr_rej_pdu0
decl_stmt|;
name|u_int8_t
name|frmr_rej_pdu1
decl_stmt|;
name|u_int8_t
name|frmr_control
decl_stmt|;
name|u_int8_t
name|frmr_control_ext
decl_stmt|;
name|u_int8_t
name|frmr_cause
decl_stmt|;
block|}
name|__packed
name|type_frmr
struct|;
struct|struct
block|{
name|u_int8_t
name|control
decl_stmt|;
name|u_int8_t
name|org_code
index|[
literal|3
index|]
decl_stmt|;
name|u_int16_t
name|ether_type
decl_stmt|;
block|}
name|__packed
name|type_snap
struct|;
struct|struct
block|{
name|u_int8_t
name|control
decl_stmt|;
name|u_int8_t
name|control_ext
decl_stmt|;
block|}
name|__packed
name|type_raw
struct|;
block|}
name|__packed
name|llc_un
union|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|frmrinfo
block|{
name|u_int8_t
name|frmr_rej_pdu0
decl_stmt|;
name|u_int8_t
name|frmr_rej_pdu1
decl_stmt|;
name|u_int8_t
name|frmr_control
decl_stmt|;
name|u_int8_t
name|frmr_control_ext
decl_stmt|;
name|u_int8_t
name|frmr_cause
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|llc_control
value|llc_un.type_u.control
end_define

begin_define
define|#
directive|define
name|llc_control_ext
value|llc_un.type_raw.control_ext
end_define

begin_define
define|#
directive|define
name|llc_fid
value|llc_un.type_u.format_id
end_define

begin_define
define|#
directive|define
name|llc_class
value|llc_un.type_u.class
end_define

begin_define
define|#
directive|define
name|llc_window
value|llc_un.type_u.window_x2
end_define

begin_define
define|#
directive|define
name|llc_frmrinfo
value|llc_un.type_frmr.frmr_rej_pdu0
end_define

begin_define
define|#
directive|define
name|llc_frmr_pdu0
value|llc_un.type_frmr.frmr_rej_pdu0
end_define

begin_define
define|#
directive|define
name|llc_frmr_pdu1
value|llc_un.type_frmr.frmr_rej_pdu1
end_define

begin_define
define|#
directive|define
name|llc_frmr_control
value|llc_un.type_frmr.frmr_control
end_define

begin_define
define|#
directive|define
name|llc_frmr_control_ext
value|llc_un.type_frmr.frmr_control_ext
end_define

begin_define
define|#
directive|define
name|llc_frmr_cause
value|llc_un.type_frmr.frmr_cause
end_define

begin_define
define|#
directive|define
name|llc_snap
value|llc_un.type_snap
end_define

begin_comment
comment|/*  * Don't use sizeof(struct llc_un) for LLC header sizes  */
end_comment

begin_define
define|#
directive|define
name|LLC_ISFRAMELEN
value|4
end_define

begin_define
define|#
directive|define
name|LLC_UFRAMELEN
value|3
end_define

begin_define
define|#
directive|define
name|LLC_FRMRLEN
value|7
end_define

begin_define
define|#
directive|define
name|LLC_SNAPFRAMELEN
value|8
end_define

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
name|llc
argument_list|)
operator|==
name|LLC_SNAPFRAMELEN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Unnumbered LLC format commands  */
end_comment

begin_define
define|#
directive|define
name|LLC_UI
value|0x3
end_define

begin_define
define|#
directive|define
name|LLC_UI_P
value|0x13
end_define

begin_define
define|#
directive|define
name|LLC_DISC
value|0x43
end_define

begin_define
define|#
directive|define
name|LLC_DISC_P
value|0x53
end_define

begin_define
define|#
directive|define
name|LLC_UA
value|0x63
end_define

begin_define
define|#
directive|define
name|LLC_UA_P
value|0x73
end_define

begin_define
define|#
directive|define
name|LLC_TEST
value|0xe3
end_define

begin_define
define|#
directive|define
name|LLC_TEST_P
value|0xf3
end_define

begin_define
define|#
directive|define
name|LLC_FRMR
value|0x87
end_define

begin_define
define|#
directive|define
name|LLC_FRMR_P
value|0x97
end_define

begin_define
define|#
directive|define
name|LLC_DM
value|0x0f
end_define

begin_define
define|#
directive|define
name|LLC_DM_P
value|0x1f
end_define

begin_define
define|#
directive|define
name|LLC_XID
value|0xaf
end_define

begin_define
define|#
directive|define
name|LLC_XID_P
value|0xbf
end_define

begin_define
define|#
directive|define
name|LLC_SABME
value|0x6f
end_define

begin_define
define|#
directive|define
name|LLC_SABME_P
value|0x7f
end_define

begin_comment
comment|/*  * Supervisory LLC commands  */
end_comment

begin_define
define|#
directive|define
name|LLC_RR
value|0x01
end_define

begin_define
define|#
directive|define
name|LLC_RNR
value|0x05
end_define

begin_define
define|#
directive|define
name|LLC_REJ
value|0x09
end_define

begin_comment
comment|/*  * Info format - dummy only  */
end_comment

begin_define
define|#
directive|define
name|LLC_INFO
value|0x00
end_define

begin_comment
comment|/*  * ISO PDTR 10178 contains among others  */
end_comment

begin_define
define|#
directive|define
name|LLC_8021D_LSAP
value|0x42
end_define

begin_define
define|#
directive|define
name|LLC_X25_LSAP
value|0x7e
end_define

begin_define
define|#
directive|define
name|LLC_SNAP_LSAP
value|0xaa
end_define

begin_define
define|#
directive|define
name|LLC_ISO_LSAP
value|0xfe
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_LLC_H_ */
end_comment

end_unit

