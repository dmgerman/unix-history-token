begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Definition for Async HDLC  */
end_comment

begin_define
define|#
directive|define
name|HDLC_SYN
value|0x7e
end_define

begin_comment
comment|/* SYNC character */
end_comment

begin_define
define|#
directive|define
name|HDLC_ESC
value|0x7d
end_define

begin_comment
comment|/* Escape character */
end_comment

begin_define
define|#
directive|define
name|HDLC_XOR
value|0x20
end_define

begin_comment
comment|/* Modifier value */
end_comment

begin_define
define|#
directive|define
name|HDLC_ADDR
value|0xff
end_define

begin_define
define|#
directive|define
name|HDLC_UI
value|0x03
end_define

begin_comment
comment|/*  *  Definition for HDLC Frame Check Sequence  */
end_comment

begin_define
define|#
directive|define
name|INITFCS
value|0xffff
end_define

begin_comment
comment|/* Initial value for FCS computation */
end_comment

begin_define
define|#
directive|define
name|GOODFCS
value|0xf0b8
end_define

begin_comment
comment|/* Good FCS value */
end_comment

begin_define
define|#
directive|define
name|DEF_MRU
value|1500
end_define

begin_define
define|#
directive|define
name|MAX_MRU
value|2048
end_define

begin_define
define|#
directive|define
name|MIN_MRU
value|296
end_define

begin_define
define|#
directive|define
name|DEF_MTU
value|0
end_define

begin_comment
comment|/* whatever peer says */
end_comment

begin_define
define|#
directive|define
name|MAX_MTU
value|2048
end_define

begin_define
define|#
directive|define
name|MIN_MTU
value|296
end_define

begin_struct_decl
struct_decl|struct
name|physical
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|link
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lcp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|hdlc
block|{
name|struct
name|pppTimer
name|ReportTimer
decl_stmt|;
struct|struct
block|{
name|int
name|badfcs
decl_stmt|;
name|int
name|badaddr
decl_stmt|;
name|int
name|badcommand
decl_stmt|;
name|int
name|unknownproto
decl_stmt|;
block|}
name|laststats
struct|,
name|stats
struct|;
struct|struct
block|{
name|struct
name|lcp
modifier|*
name|owner
decl_stmt|;
comment|/* parent LCP */
name|struct
name|pppTimer
name|timer
decl_stmt|;
comment|/* When to send */
name|int
name|method
decl_stmt|;
comment|/* bit-mask for LQM_* from lqr.h */
name|u_int32_t
name|OutPackets
decl_stmt|;
comment|/* Packets sent by me */
name|u_int32_t
name|OutOctets
decl_stmt|;
comment|/* Octets sent by me */
name|u_int32_t
name|SaveInPackets
decl_stmt|;
comment|/* Packets received from peer */
name|u_int32_t
name|SaveInDiscards
decl_stmt|;
comment|/* Discards */
name|u_int32_t
name|SaveInErrors
decl_stmt|;
comment|/* Errors */
name|u_int32_t
name|SaveInOctets
decl_stmt|;
comment|/* Octets received from peer */
struct|struct
block|{
name|u_int32_t
name|OutLQRs
decl_stmt|;
comment|/* LQRs sent by me */
name|u_int32_t
name|SaveInLQRs
decl_stmt|;
comment|/* LQRs received from peer */
name|struct
name|lqrdata
name|peer
decl_stmt|;
comment|/* Last LQR from peer */
name|int
name|peer_timeout
decl_stmt|;
comment|/* peers max lqr timeout */
name|int
name|resent
decl_stmt|;
comment|/* Resent last packet `resent' times */
block|}
name|lqr
struct|;
struct|struct
block|{
name|u_int32_t
name|seq_sent
decl_stmt|;
comment|/* last echo sent */
name|u_int32_t
name|seq_recv
decl_stmt|;
comment|/* last echo received */
block|}
name|echo
struct|;
block|}
name|lqm
struct|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|hdlc_Init
parameter_list|(
name|struct
name|hdlc
modifier|*
parameter_list|,
name|struct
name|lcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hdlc_StartTimer
parameter_list|(
name|struct
name|hdlc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hdlc_StopTimer
parameter_list|(
name|struct
name|hdlc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hdlc_ReportStatus
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|hdlc_Protocol2Nam
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hdlc_DecodePacket
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|hdlc_Fcs
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hdlc_Detect
parameter_list|(
name|u_char
specifier|const
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hdlc_WrapperOctets
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|layer
name|hdlclayer
decl_stmt|;
end_decl_stmt

end_unit

