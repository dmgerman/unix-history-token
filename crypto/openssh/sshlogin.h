begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: sshlogin.h,v 1.1 2001/03/04 01:46:30 djm Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSHLOGIN_H
end_ifndef

begin_define
define|#
directive|define
name|SSHLOGIN_H
end_define

begin_comment
comment|/*  * Returns the time when the user last logged in.  Returns 0 if the  * information is not available.  This must be called before record_login.  * The host from which the user logged in is stored in buf.  */
end_comment

begin_function_decl
name|u_long
name|get_last_login_time
parameter_list|(
name|uid_t
name|uid
parameter_list|,
specifier|const
name|char
modifier|*
name|logname
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|u_int
name|bufsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Records that the user has logged in.  This does many things normally done  * by login(1).  */
end_comment

begin_function_decl
name|void
name|record_login
parameter_list|(
name|pid_t
name|pid
parameter_list|,
specifier|const
name|char
modifier|*
name|ttyname
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
name|uid_t
name|uid
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Records that the user has logged out.  This does many thigs normally done  * by login(1) or init.  */
end_comment

begin_function_decl
name|void
name|record_logout
parameter_list|(
name|pid_t
name|pid
parameter_list|,
specifier|const
name|char
modifier|*
name|ttyname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

