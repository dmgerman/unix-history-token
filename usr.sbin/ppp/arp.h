begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *			User Process PPP  *  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan, Inc.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  */
end_comment

begin_struct_decl
struct_decl|struct
name|sockaddr_dl
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|arp_ClearProxy
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|arp_SetProxy
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_ether_addr
parameter_list|(
name|int
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|struct
name|sockaddr_dl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

