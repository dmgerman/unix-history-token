begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: bufaux.h,v 1.8 2000/09/07 20:27:50 deraadt Exp $"); */
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

begin_comment
comment|/*  * Stores an BIGNUM in the buffer with a 2-byte msb first bit count, followed  * by (bits+7)/8 bytes of binary data, msb first.  */
end_comment

begin_function_decl
name|void
name|buffer_put_bignum
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_bignum2
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Retrieves an BIGNUM from the buffer. */
end_comment

begin_function_decl
name|int
name|buffer_get_bignum
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_bignum2
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns an integer from the buffer (4 bytes, msb first). */
end_comment

begin_function_decl
name|unsigned
name|int
name|buffer_get_int
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Stores an integer in the buffer in 4 bytes, msb first. */
end_comment

begin_function_decl
name|void
name|buffer_put_int
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns a character from the buffer (0 - 255). */
end_comment

begin_function_decl
name|int
name|buffer_get_char
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Stores a character in the buffer. */
end_comment

begin_function_decl
name|void
name|buffer_put_char
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns an arbitrary binary string from the buffer.  The string cannot be  * longer than 256k.  The returned value points to memory allocated with  * xmalloc; it is the responsibility of the calling function to free the  * data.  If length_ptr is non-NULL, the length of the returned data will be  * stored there.  A null character will be automatically appended to the  * returned string, and is not counted in length.  */
end_comment

begin_function_decl
name|char
modifier|*
name|buffer_get_string
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
modifier|*
name|length_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Stores and arbitrary binary string in the buffer. */
end_comment

begin_function_decl
name|void
name|buffer_put_string
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_cstring
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|s
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

