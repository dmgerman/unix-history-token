begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Structure of LQR packet defined in RFC1989  */
end_comment

begin_struct
struct|struct
name|lqrdata
block|{
name|u_int32_t
name|MagicNumber
decl_stmt|;
name|u_int32_t
name|LastOutLQRs
decl_stmt|;
comment|/* most recently received PeerOutLQRs */
name|u_int32_t
name|LastOutPackets
decl_stmt|;
comment|/* most recently received PeerOutPackets */
name|u_int32_t
name|LastOutOctets
decl_stmt|;
comment|/* most recently received PeerOutOctets */
name|u_int32_t
name|PeerInLQRs
decl_stmt|;
comment|/* Peers SaveInLQRs */
name|u_int32_t
name|PeerInPackets
decl_stmt|;
comment|/* Peers SaveInPackets */
name|u_int32_t
name|PeerInDiscards
decl_stmt|;
comment|/* Peers SaveInDiscards */
name|u_int32_t
name|PeerInErrors
decl_stmt|;
comment|/* Peers SaveInErrors */
name|u_int32_t
name|PeerInOctets
decl_stmt|;
comment|/* Peers SaveInOctets */
name|u_int32_t
name|PeerOutLQRs
decl_stmt|;
comment|/* Peers OutLQRs (hdlc.h) */
name|u_int32_t
name|PeerOutPackets
decl_stmt|;
comment|/* Peers OutPackets (hdlc.h) */
name|u_int32_t
name|PeerOutOctets
decl_stmt|;
comment|/* Peers OutOctets (hdlc.h) */
block|}
struct|;
end_struct

begin_comment
comment|/*  *  We support LQR and ECHO as LQM method  */
end_comment

begin_define
define|#
directive|define
name|LQM_LQR
value|1
end_define

begin_define
define|#
directive|define
name|LQM_ECHO
value|2
end_define

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|physical
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lcp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fsm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|link
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|lqr_Dump
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|lqrdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lqr_ChangeOrder
parameter_list|(
name|struct
name|lqrdata
modifier|*
parameter_list|,
name|struct
name|lqrdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lqr_Start
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lqr_reStart
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lqr_Stop
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lqr_StopTimer
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|lqr_RecvEcho
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|lqr_Input
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|layer
name|lqrlayer
decl_stmt|;
end_decl_stmt

end_unit

