begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: canohost.h,v 1.12 2016/03/07 19:02:43 djm Exp $ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CANOHOST_H
end_ifndef

begin_define
define|#
directive|define
name|_CANOHOST_H
end_define

begin_function_decl
name|char
modifier|*
name|get_peer_ipaddr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_peer_port
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_local_ipaddr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_local_name
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_local_port
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CANOHOST_H */
end_comment

begin_function_decl
name|void
name|ipv64_normalise_mapped
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
parameter_list|,
name|socklen_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

