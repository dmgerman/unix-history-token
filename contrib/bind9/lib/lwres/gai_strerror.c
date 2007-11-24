begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: gai_strerror.c,v 1.14.2.1.10.3 2006/08/25 05:25:50 marka Exp $ */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<lwres/netdb.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|gai_messages
index|[]
init|=
block|{
literal|"no error"
block|,
literal|"address family for hostname not supported"
block|,
literal|"temporary failure in name resolution"
block|,
literal|"invalid value for ai_flags"
block|,
literal|"non-recoverable failure in name resolution"
block|,
literal|"ai_family not supported"
block|,
literal|"memory allocation failure"
block|,
literal|"no address associated with hostname"
block|,
literal|"hostname nor servname provided, or not known"
block|,
literal|"servname not supported for ai_socktype"
block|,
literal|"ai_socktype not supported"
block|,
literal|"system error returned in errno"
block|,
literal|"bad hints"
block|,
literal|"bad protocol"
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|lwres_gai_strerror
parameter_list|(
name|int
name|ecode
parameter_list|)
block|{
union|union
block|{
specifier|const
name|char
modifier|*
name|const_ptr
decl_stmt|;
name|char
modifier|*
name|deconst_ptr
decl_stmt|;
block|}
name|ptr
union|;
if|if
condition|(
operator|(
name|ecode
operator|<
literal|0
operator|)
operator|||
operator|(
name|ecode
operator|>=
call|(
name|int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|gai_messages
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|gai_messages
argument_list|)
argument_list|)
operator|)
condition|)
name|ptr
operator|.
name|const_ptr
operator|=
literal|"invalid error code"
expr_stmt|;
else|else
name|ptr
operator|.
name|const_ptr
operator|=
name|gai_messages
index|[
name|ecode
index|]
expr_stmt|;
return|return
operator|(
name|ptr
operator|.
name|deconst_ptr
operator|)
return|;
block|}
end_function

end_unit

