begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: ipcp.h,v 1.10 1997/09/03 02:08:19 brian Exp $  *  *	TODO:  */
end_comment

begin_define
define|#
directive|define
name|IPCP_MAXCODE
value|CODE_CODEREJ
end_define

begin_define
define|#
directive|define
name|TY_IPADDRS
value|1
end_define

begin_define
define|#
directive|define
name|TY_COMPPROTO
value|2
end_define

begin_define
define|#
directive|define
name|TY_IPADDR
value|3
end_define

begin_comment
comment|/* MS PPP NameServer and NetBIOS NameServer stuff */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOMSEXT
end_ifndef

begin_define
define|#
directive|define
name|TY_PRIMARY_DNS
value|129
end_define

begin_define
define|#
directive|define
name|TY_PRIMARY_NBNS
value|130
end_define

begin_define
define|#
directive|define
name|TY_SECONDARY_DNS
value|131
end_define

begin_define
define|#
directive|define
name|TY_SECONDARY_NBNS
value|132
end_define

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|ns_entries
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|nbns_entries
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ipcpstate
block|{
name|struct
name|in_addr
name|his_ipaddr
decl_stmt|;
comment|/* IP address he is willing to use */
name|u_long
name|his_compproto
decl_stmt|;
name|struct
name|in_addr
name|want_ipaddr
decl_stmt|;
comment|/* IP address I'm willing to use */
name|u_long
name|want_compproto
decl_stmt|;
name|u_long
name|his_reject
decl_stmt|;
comment|/* Request codes rejected by peer */
name|u_long
name|my_reject
decl_stmt|;
comment|/* Request codes I have rejected */
name|int
name|heis1172
decl_stmt|;
comment|/* True if he is speaking rfc1172 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|compreq
block|{
name|u_short
name|proto
decl_stmt|;
name|u_char
name|slots
decl_stmt|;
name|u_char
name|compcid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in_range
block|{
name|struct
name|in_addr
name|ipaddr
decl_stmt|;
name|struct
name|in_addr
name|mask
decl_stmt|;
name|int
name|width
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ipcpstate
name|IpcpInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_range
name|DefMyAddress
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_range
name|DefHisAddress
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|TriggerAddress
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|HaveTriggerAddress
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fsm
name|IpcpFsm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pppTimer
name|IpcpReportTimer
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|IpcpInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IpcpDefAddress
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IpcpUp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IpcpOpen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ReportIpcpStatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

