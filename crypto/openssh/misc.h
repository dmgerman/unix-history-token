begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: misc.h,v 1.4 2001/04/12 20:09:36 stevesk Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* remove newline at end of string */
end_comment

begin_function_decl
name|char
modifier|*
name|chop
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return next token in configuration line */
end_comment

begin_function_decl
name|char
modifier|*
name|strdelim
parameter_list|(
name|char
modifier|*
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set filedescriptor to non-blocking */
end_comment

begin_function_decl
name|void
name|set_nonblock
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|pwcopy
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert ASCII string to TCP/IP port number.  * Port must be>0 and<=65535.  * Return 0 if invalid.  */
end_comment

begin_function_decl
name|int
name|a2port
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

end_unit

