begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Functions to interface with the SSH_AUTHENTICATION_FD socket.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* $OpenBSD: auth-options.h,v 1.8 2001/01/21 19:05:42 markus Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTH_OPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|AUTH_OPTIONS_H
end_define

begin_comment
comment|/* Linked list of custom environment strings */
end_comment

begin_struct
struct|struct
name|envstring
block|{
name|struct
name|envstring
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags that may be set in authorized_keys options. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|no_port_forwarding_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_agent_forwarding_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_x11_forwarding_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_pty_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|forced_command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|envstring
modifier|*
name|custom_environment
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * return 1 if access is granted, 0 if not.  * side effect: sets key option flags  */
end_comment

begin_function_decl
name|int
name|auth_parse_options
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
name|char
modifier|*
name|options
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|u_long
name|linenum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reset options flags */
end_comment

begin_function_decl
name|void
name|auth_clear_options
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

