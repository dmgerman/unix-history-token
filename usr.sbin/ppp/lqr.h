begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: lqr.h,v 1.11 1998/01/11 17:50:42 brian Exp $  *  *	TODO:  */
end_comment

begin_comment
comment|/*  *  Structure of LQR packet defined in RFC1333  */
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
name|u_int32_t
name|LastOutPackets
decl_stmt|;
name|u_int32_t
name|LastOutOctets
decl_stmt|;
name|u_int32_t
name|PeerInLQRs
decl_stmt|;
name|u_int32_t
name|PeerInPackets
decl_stmt|;
name|u_int32_t
name|PeerInDiscards
decl_stmt|;
name|u_int32_t
name|PeerInErrors
decl_stmt|;
name|u_int32_t
name|PeerInOctets
decl_stmt|;
name|u_int32_t
name|PeerOutLQRs
decl_stmt|;
name|u_int32_t
name|PeerOutPackets
decl_stmt|;
name|u_int32_t
name|PeerOutOctets
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lqrsave
block|{
name|u_int32_t
name|SaveInLQRs
decl_stmt|;
name|u_int32_t
name|SaveInPackets
decl_stmt|;
name|u_int32_t
name|SaveInDiscards
decl_stmt|;
name|u_int32_t
name|SaveInErrors
decl_stmt|;
name|u_int32_t
name|SaveInOctets
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|lqrdata
name|MyLqrData
decl_stmt|,
name|HisLqrData
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|lqrsave
name|HisLqrSave
decl_stmt|;
end_decl_stmt

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

begin_function_decl
specifier|extern
name|void
name|LqrDump
parameter_list|(
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
name|LqrChangeOrder
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
name|StartLqm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|StopLqr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|StopLqrTimer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RecvEchoLqr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LqrInput
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

