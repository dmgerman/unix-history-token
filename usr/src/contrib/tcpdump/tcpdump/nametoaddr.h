begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988-1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: nametoaddr.h,v 1.6 90/09/24 12:50:41 mccanne Exp $ (LBL)  *  * Address to name translation routines.  */
end_comment

begin_function_decl
specifier|extern
name|u_long
modifier|*
modifier|*
name|s_nametoaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|s_nametonetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|s_nametoport
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|s_nametoproto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|s_nametoeproto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_char
modifier|*
name|ETHER_hostton
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_char
modifier|*
name|ETHER_aton
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * If a protocol is unknown, PROTO_UNDEF is returned.  * Also, s_nametoport() returns the protocol along with the port number.  * If there are ambiguous entried in /etc/services (i.e. domain  * can be either tcp or udp) PROTO_UNDEF is returned.  */
end_comment

begin_define
define|#
directive|define
name|PROTO_UNDEF
value|-1
end_define

end_unit

