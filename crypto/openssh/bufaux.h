begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: bufaux.h,v 1.16 2002/03/04 17:27:39 stevesk Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFAUX_H
end_ifndef

begin_define
define|#
directive|define
name|BUFAUX_H
end_define

begin_include
include|#
directive|include
file|"buffer.h"
end_include

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_function_decl
name|void
name|buffer_put_bignum
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_bignum2
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_get_bignum
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_get_bignum2
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|buffer_get_int
parameter_list|(
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_int
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|buffer_get_int64
parameter_list|(
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_int64
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_char
parameter_list|(
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_char
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|buffer_get_string
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_string
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_cstring
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BUFAUX_H */
end_comment

end_unit

