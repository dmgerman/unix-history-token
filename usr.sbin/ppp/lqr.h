begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
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
name|void
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
name|void
name|lqr_Input
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

