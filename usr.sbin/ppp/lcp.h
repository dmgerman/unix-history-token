begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: lcp.h,v 1.15 1997/12/04 18:49:28 brian Exp $  *  *	TODO:  */
end_comment

begin_define
define|#
directive|define
name|REJECTED
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|((p)->his_reject& (1<<(x)))
end_define

begin_struct
struct|struct
name|lcpstate
block|{
name|u_int16_t
name|his_mru
decl_stmt|;
name|u_int32_t
name|his_accmap
decl_stmt|;
name|u_int32_t
name|his_magic
decl_stmt|;
name|u_int32_t
name|his_lqrperiod
decl_stmt|;
name|u_char
name|his_protocomp
decl_stmt|;
name|u_char
name|his_acfcomp
decl_stmt|;
name|u_short
name|his_auth
decl_stmt|;
name|u_short
name|want_mru
decl_stmt|;
name|u_int32_t
name|want_accmap
decl_stmt|;
name|u_int32_t
name|want_magic
decl_stmt|;
name|u_int32_t
name|want_lqrperiod
decl_stmt|;
name|u_char
name|want_protocomp
decl_stmt|;
name|u_char
name|want_acfcomp
decl_stmt|;
name|u_short
name|want_auth
decl_stmt|;
name|u_int32_t
name|his_reject
decl_stmt|;
comment|/* Request codes rejected by peer */
name|u_int32_t
name|my_reject
decl_stmt|;
comment|/* Request codes I have rejected */
name|u_short
name|auth_iwait
decl_stmt|;
name|u_short
name|auth_ineed
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LCP_MAXCODE
value|CODE_DISCREQ
end_define

begin_define
define|#
directive|define
name|TY_MRU
value|1
end_define

begin_comment
comment|/* Maximum-Receive-Unit */
end_comment

begin_define
define|#
directive|define
name|TY_ACCMAP
value|2
end_define

begin_comment
comment|/* Async-Control-Character-Map */
end_comment

begin_define
define|#
directive|define
name|TY_AUTHPROTO
value|3
end_define

begin_comment
comment|/* Authentication-Protocol */
end_comment

begin_define
define|#
directive|define
name|TY_QUALPROTO
value|4
end_define

begin_comment
comment|/* Quality-Protocol */
end_comment

begin_define
define|#
directive|define
name|TY_MAGICNUM
value|5
end_define

begin_comment
comment|/* Magic-Number */
end_comment

begin_define
define|#
directive|define
name|TY_RESERVED
value|6
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|TY_PROTOCOMP
value|7
end_define

begin_comment
comment|/* Protocol-Field-Compression */
end_comment

begin_define
define|#
directive|define
name|TY_ACFCOMP
value|8
end_define

begin_comment
comment|/* Address-and-Control-Field-Compression */
end_comment

begin_define
define|#
directive|define
name|TY_FCSALT
value|9
end_define

begin_comment
comment|/* FCS-Alternatives */
end_comment

begin_define
define|#
directive|define
name|TY_SDP
value|10
end_define

begin_comment
comment|/* Self-Describing-Padding */
end_comment

begin_define
define|#
directive|define
name|MAX_LCP_OPT_LEN
value|10
end_define

begin_struct
struct|struct
name|lcp_opt
block|{
name|u_char
name|id
decl_stmt|;
name|u_char
name|len
decl_stmt|;
name|u_char
name|data
index|[
name|MAX_LCP_OPT_LEN
operator|-
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|lcpstate
name|LcpInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fsm
name|LcpFsm
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|LcpInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LcpUp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LcpSendProtoRej
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LcpOpen
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LcpClose
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LcpDown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|LcpPutConf
parameter_list|(
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|lcp_opt
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ReportLcpStatus
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
name|LcpInput
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

