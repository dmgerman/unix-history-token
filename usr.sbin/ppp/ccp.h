begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CCP_H_
end_ifndef

begin_define
define|#
directive|define
name|_CCP_H_
end_define

begin_define
define|#
directive|define
name|CCP_MAXCODE
value|CODE_RESETACK
end_define

begin_define
define|#
directive|define
name|TY_OUI
value|0
end_define

begin_comment
comment|/* OUI */
end_comment

begin_define
define|#
directive|define
name|TY_PRED1
value|1
end_define

begin_comment
comment|/* Predictor type 1 */
end_comment

begin_define
define|#
directive|define
name|TY_PRED2
value|2
end_define

begin_comment
comment|/* Predictor type 2 */
end_comment

begin_define
define|#
directive|define
name|TY_PUDDLE
value|3
end_define

begin_comment
comment|/* Puddle Jumper */
end_comment

begin_define
define|#
directive|define
name|TY_HWPPC
value|16
end_define

begin_comment
comment|/* Hewlett-Packard PPC */
end_comment

begin_define
define|#
directive|define
name|TY_STAC
value|17
end_define

begin_comment
comment|/* Stac Electronics LZS */
end_comment

begin_define
define|#
directive|define
name|TY_MSPPC
value|18
end_define

begin_comment
comment|/* Microsoft PPC */
end_comment

begin_define
define|#
directive|define
name|TY_GAND
value|19
end_define

begin_comment
comment|/* Gandalf FZA */
end_comment

begin_define
define|#
directive|define
name|TY_V42BIS
value|20
end_define

begin_comment
comment|/* V.42bis compression */
end_comment

begin_define
define|#
directive|define
name|TY_BSD
value|21
end_define

begin_comment
comment|/* BSD LZW Compress */
end_comment

begin_struct
struct|struct
name|ccpstate
block|{
name|u_long
name|his_proto
decl_stmt|;
comment|/* peer's compression protocol */
name|u_long
name|want_proto
decl_stmt|;
comment|/* my compression protocol */
name|u_long
name|his_reject
decl_stmt|;
comment|/* Request codes rejected by peer */
name|u_long
name|my_reject
decl_stmt|;
comment|/* Request codes I have rejected */
name|u_long
name|orgout
decl_stmt|,
name|compout
decl_stmt|;
name|u_long
name|orgin
decl_stmt|,
name|compin
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ccpstate
name|CcpInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CcpRecvResetReq
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CcpSendResetReq
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CcpInput
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

begin_decl_stmt
name|void
name|CcpUp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CcpOpen
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CcpInit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

