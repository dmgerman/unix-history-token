begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: compress.h,v 1.11 2002/03/04 17:27:39 stevesk Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Interface to packet compression for ssh.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPRESS_H
end_ifndef

begin_define
define|#
directive|define
name|COMPRESS_H
end_define

begin_function_decl
name|void
name|buffer_compress_init_send
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_compress_init_recv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_compress_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_compress
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_uncompress
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPRESS_H */
end_comment

end_unit

