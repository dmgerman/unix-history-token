begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: serverloop.h,v 1.5 2001/06/27 02:12:53 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/*  * Performs the interactive session.  This handles data transmission between  * the client and the program.  Note that the notion of stdin, stdout, and  * stderr in this function is sort of reversed: this function writes to stdin  * (of the child program), and reads from stdout and stderr (of the child  * program).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVERLOOP_H
end_ifndef

begin_define
define|#
directive|define
name|SERVERLOOP_H
end_define

begin_function_decl
name|void
name|server_loop
parameter_list|(
name|pid_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|server_loop2
parameter_list|(
name|Authctxt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

