begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: returns.h,v 1.1 2011/04/10 09:55:09 blymn Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright 2009 Brett Lymn<blymn@NetBSD.org>  *  * All rights reserved.  *  * This code has been donated to The NetBSD Foundation by the Author.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CTF_RETURNS_H
end_ifndef

begin_define
define|#
directive|define
name|CTF_RETURNS_H
value|1
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|ret_number
init|=
literal|1
block|,
name|ret_string
block|,
name|ret_byte
block|,
name|ret_err
block|,
name|ret_ok
block|,
name|ret_null
block|,
name|ret_nonnull
block|,
name|ret_var
block|,
name|ret_ref
block|,
name|ret_count
block|,
name|ret_slave_error
block|}
name|returns_enum_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|returns_enum_t
name|return_type
decl_stmt|;
name|void
modifier|*
name|return_value
decl_stmt|;
comment|/* used if return_type is ret_num or 					   or ret_byte or ret_string */
name|size_t
name|return_len
decl_stmt|;
comment|/* number of bytes in return_value iff 					   return_type is ret_byte */
name|int
name|return_index
decl_stmt|;
comment|/* index into var array for return 					   if return_type is ret_var */
block|}
name|returns_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|size_t
name|count
decl_stmt|;
name|size_t
name|allocated
decl_stmt|;
name|size_t
name|readp
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|saved_data_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTF_RETURNS_H */
end_comment

end_unit

