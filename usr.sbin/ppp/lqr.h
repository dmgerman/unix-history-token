begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LQR_H_
end_ifndef

begin_define
define|#
directive|define
name|_LQR_H_
end_define

begin_comment
comment|/*  *  Structure of LQR packet defined in RFC1333  */
end_comment

begin_struct
struct|struct
name|lqrdata
block|{
name|u_long
name|MagicNumber
decl_stmt|;
name|u_long
name|LastOutLQRs
decl_stmt|;
name|u_long
name|LastOutPackets
decl_stmt|;
name|u_long
name|LastOutOctets
decl_stmt|;
name|u_long
name|PeerInLQRs
decl_stmt|;
name|u_long
name|PeerInPackets
decl_stmt|;
name|u_long
name|PeerInDiscards
decl_stmt|;
name|u_long
name|PeerInErrors
decl_stmt|;
name|u_long
name|PeerInOctets
decl_stmt|;
name|u_long
name|PeerOutLQRs
decl_stmt|;
name|u_long
name|PeerOutPackets
decl_stmt|;
name|u_long
name|PeerOutOctets
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lqrsave
block|{
name|u_long
name|SaveInLQRs
decl_stmt|;
name|u_long
name|SaveInPackets
decl_stmt|;
name|u_long
name|SaveInDiscards
decl_stmt|;
name|u_long
name|SaveInErrors
decl_stmt|;
name|u_long
name|SaveInOctets
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|lqrdata
name|MyLqrData
decl_stmt|,
name|HisLqrData
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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

begin_decl_stmt
specifier|extern
name|void
name|LqrDump
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|lqrdata
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|LqrChangeOrder
name|__P
argument_list|(
operator|(
expr|struct
name|lqrdata
operator|*
operator|,
expr|struct
name|lqrdata
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|StartLqm
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|StopLqr
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|StopLqrTimer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|RecvEchoLqr
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

