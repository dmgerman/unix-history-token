begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: ccp.h,v 1.13 1998/01/10 01:55:09 brian Exp $  *  *	TODO:  */
end_comment

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

begin_define
define|#
directive|define
name|TY_PPPD_DEFLATE
value|24
end_define

begin_comment
comment|/* Deflate (gzip) - (mis) numbered by pppd */
end_comment

begin_define
define|#
directive|define
name|TY_DEFLATE
value|26
end_define

begin_comment
comment|/* Deflate (gzip) - rfc 1979 */
end_comment

begin_struct
struct|struct
name|ccpstate
block|{
name|int
name|his_proto
decl_stmt|;
comment|/* peer's compression protocol */
name|int
name|my_proto
decl_stmt|;
comment|/* our compression protocol */
name|int
name|reset_sent
decl_stmt|;
comment|/* If != -1, ignore compressed 'till ack */
name|int
name|last_reset
decl_stmt|;
comment|/* We can receive more (dups) w/ this id */
name|u_int32_t
name|his_reject
decl_stmt|;
comment|/* Request codes rejected by peer */
name|u_int32_t
name|my_reject
decl_stmt|;
comment|/* Request codes I have rejected */
name|int
name|out_init
decl_stmt|;
comment|/* Init called for out algorithm */
name|int
name|in_init
decl_stmt|;
comment|/* Init called for in algorithm */
name|u_long
name|uncompout
decl_stmt|,
name|compout
decl_stmt|;
name|u_long
name|uncompin
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

begin_struct
struct|struct
name|ccp_algorithm
block|{
name|int
name|id
decl_stmt|;
name|int
name|Conf
decl_stmt|;
comment|/* A Conf value from vars.h */
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|Disp
function_decl|)
parameter_list|(
name|struct
name|lcp_opt
modifier|*
parameter_list|)
function_decl|;
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|Get
function_decl|)
parameter_list|(
name|struct
name|lcp_opt
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|Set
function_decl|)
parameter_list|(
name|struct
name|lcp_opt
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|Init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|Term
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|Reset
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|Read
function_decl|)
parameter_list|(
name|u_short
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|DictSetup
function_decl|)
parameter_list|(
name|u_short
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
block|}
name|i
struct|;
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|Get
function_decl|)
parameter_list|(
name|struct
name|lcp_opt
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|Set
function_decl|)
parameter_list|(
name|struct
name|lcp_opt
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|Init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|Term
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|Reset
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|Write
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|u_short
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
block|}
name|o
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|fsm
name|CcpFsm
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|CcpRecvResetReq
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CcpSendResetReq
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CcpInput
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
name|CcpUp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CcpOpen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CcpInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ReportCcpStatus
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
name|void
name|CcpResetInput
parameter_list|(
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|CcpOutput
parameter_list|(
name|int
parameter_list|,
name|u_short
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
name|CompdInput
parameter_list|(
name|u_short
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
name|CcpDictSetup
parameter_list|(
name|u_short
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

