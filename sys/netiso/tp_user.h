begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tp_user.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_TP_USER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_TP_USER_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * ARGO TP  *  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/tp_user.h,v $  *  * These are the values a real-live user ;-) needs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|tp_conn_param
block|{
comment|/* PER CONNECTION parameters */
name|short
name|p_Nretrans
decl_stmt|;
name|short
name|p_dr_ticks
decl_stmt|;
name|short
name|p_cc_ticks
decl_stmt|;
name|short
name|p_dt_ticks
decl_stmt|;
name|short
name|p_x_ticks
decl_stmt|;
name|short
name|p_cr_ticks
decl_stmt|;
name|short
name|p_keepalive_ticks
decl_stmt|;
name|short
name|p_sendack_ticks
decl_stmt|;
name|short
name|p_ref_ticks
decl_stmt|;
name|short
name|p_inact_ticks
decl_stmt|;
name|short
name|p_ptpdusize
decl_stmt|;
comment|/* preferred tpdusize/128 */
name|short
name|p_winsize
decl_stmt|;
name|u_char
name|p_tpdusize
decl_stmt|;
comment|/* log 2 of size */
name|u_char
name|p_ack_strat
decl_stmt|;
comment|/* see comments in tp_pcb.h */
name|u_char
name|p_rx_strat
decl_stmt|;
comment|/* see comments in tp_pcb.h */
name|u_char
name|p_class
decl_stmt|;
comment|/* class bitmask */
name|u_char
name|p_xtd_format
decl_stmt|;
name|u_char
name|p_xpd_service
decl_stmt|;
name|u_char
name|p_use_checksum
decl_stmt|;
name|u_char
name|p_use_nxpd
decl_stmt|;
comment|/* netwk expedited data: not implemented */
name|u_char
name|p_use_rcc
decl_stmt|;
comment|/* receipt confirmation: not implemented */
name|u_char
name|p_use_efc
decl_stmt|;
comment|/* explicit flow control: not implemented */
name|u_char
name|p_no_disc_indications
decl_stmt|;
comment|/* don't deliver indic on disc */
name|u_char
name|p_dont_change_params
decl_stmt|;
comment|/* use these params as they are */
name|u_char
name|p_netservice
decl_stmt|;
name|u_char
name|p_version
decl_stmt|;
comment|/* only here for checking */
block|}
struct|;
end_struct

begin_comment
comment|/*  * These sockopt level definitions should be considered for socket.h  */
end_comment

begin_define
define|#
directive|define
name|SOL_TRANSPORT
value|0xfffe
end_define

begin_define
define|#
directive|define
name|SOL_NETWORK
value|0xfffd
end_define

begin_comment
comment|/* get/set socket opt commands */
end_comment

begin_define
define|#
directive|define
name|TPACK_WINDOW
value|0x0
end_define

begin_comment
comment|/* ack only on full window */
end_comment

begin_define
define|#
directive|define
name|TPACK_EACH
value|0x1
end_define

begin_comment
comment|/* ack every packet */
end_comment

begin_define
define|#
directive|define
name|TPRX_USE_CW
value|0x8
end_define

begin_comment
comment|/* use congestion window transmit */
end_comment

begin_define
define|#
directive|define
name|TPRX_EACH
value|0x4
end_define

begin_comment
comment|/* retrans each packet of a set */
end_comment

begin_define
define|#
directive|define
name|TPRX_FASTSTART
value|0x1
end_define

begin_comment
comment|/* don't use slow start */
end_comment

begin_define
define|#
directive|define
name|TPOPT_INTERCEPT
value|0x200
end_define

begin_define
define|#
directive|define
name|TPOPT_FLAGS
value|0x300
end_define

begin_define
define|#
directive|define
name|TPOPT_CONN_DATA
value|0x400
end_define

begin_define
define|#
directive|define
name|TPOPT_DISC_DATA
value|0x500
end_define

begin_define
define|#
directive|define
name|TPOPT_CFRM_DATA
value|0x600
end_define

begin_define
define|#
directive|define
name|TPOPT_CDDATA_CLEAR
value|0x700
end_define

begin_define
define|#
directive|define
name|TPOPT_MY_TSEL
value|0x800
end_define

begin_define
define|#
directive|define
name|TPOPT_PEER_TSEL
value|0x900
end_define

begin_define
define|#
directive|define
name|TPOPT_PERF_MEAS
value|0xa00
end_define

begin_define
define|#
directive|define
name|TPOPT_PSTATISTICS
value|0xb00
end_define

begin_define
define|#
directive|define
name|TPOPT_PARAMS
value|0xc00
end_define

begin_comment
comment|/* to replace a bunch of the others */
end_comment

begin_define
define|#
directive|define
name|TPOPT_DISC_REASON
value|0xe00
end_define

begin_struct
struct|struct
name|tp_disc_reason
block|{
name|struct
name|cmsghdr
name|dr_hdr
decl_stmt|;
name|u_int
name|dr_reason
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  ***********************flags**********************************  */
end_comment

begin_comment
comment|/* read only flags */
end_comment

begin_define
define|#
directive|define
name|TPFLAG_NLQOS_PDN
value|(u_char)0x01
end_define

begin_define
define|#
directive|define
name|TPFLAG_PEER_ON_SAMENET
value|(u_char)0x02
end_define

begin_define
define|#
directive|define
name|TPFLAG_GENERAL_ADDR
value|(u_char)0x04
end_define

begin_comment
comment|/* bound to wildcard addr */
end_comment

begin_comment
comment|/*  ***********************end flags******************************  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

