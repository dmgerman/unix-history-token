begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: tildexpand.h,v 1.2 2001/01/29 01:58:19 niklas Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/*  * Expands tildes in the file name.  Returns data allocated by xmalloc.  * Warning: this calls getpw*.  */
end_comment

begin_function_decl
name|char
modifier|*
name|tilde_expand_filename
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|uid_t
name|my_uid
parameter_list|)
function_decl|;
end_function_decl

end_unit

