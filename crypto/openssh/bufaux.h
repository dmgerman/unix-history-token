begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: bufaux.h,v 1.21 2005/03/10 22:01:05 deraadt Exp $	*/
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
specifier|const
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
specifier|const
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
name|u_short
name|buffer_get_short
parameter_list|(
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_short
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_short
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

begin_define
define|#
directive|define
name|buffer_skip_string
parameter_list|(
name|b
parameter_list|)
define|\
value|do { u_int l = buffer_get_int(b); buffer_consume(b, l); } while (0)
end_define

begin_function_decl
name|int
name|buffer_put_bignum_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_bignum_ret
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
name|int
name|buffer_put_bignum2_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_bignum2_ret
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
name|int
name|buffer_get_short_ret
parameter_list|(
name|u_short
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_int_ret
parameter_list|(
name|u_int
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_int64_ret
parameter_list|(
name|u_int64_t
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|buffer_get_string_ret
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
name|int
name|buffer_get_char_ret
parameter_list|(
name|char
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
comment|/* BUFAUX_H */
end_comment

end_unit

