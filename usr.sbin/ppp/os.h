begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id:$  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OS_H_
end_ifndef

begin_define
define|#
directive|define
name|_OS_H_
end_define

begin_function_decl
name|int
name|OsSetIpaddress
parameter_list|(
name|struct
name|in_addr
name|myaddr
parameter_list|,
name|struct
name|in_addr
name|hisaddr
parameter_list|,
name|struct
name|in_addr
name|netmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OsInterfaceDown
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OsSetInterfaceParams
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|mtu
parameter_list|,
name|int
name|speed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OpenTunnel
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OsCloseLink
parameter_list|(
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|OsLinkup
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|OsLinkdown
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|OsSetRoute
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DeleteIfRoutes
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

