begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1996,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: ns_netint.c,v 1.3 2005/04/27 04:56:40 sra Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Import. */
end_comment

begin_include
include|#
directive|include
file|"port_before.h"
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_comment
comment|/* Public. */
end_comment

begin_function
name|u_int
name|ns_get16
parameter_list|(
specifier|const
name|u_char
modifier|*
name|src
parameter_list|)
block|{
name|u_int
name|dst
decl_stmt|;
name|NS_GET16
argument_list|(
name|dst
argument_list|,
name|src
argument_list|)
expr_stmt|;
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

begin_function
name|u_long
name|ns_get32
parameter_list|(
specifier|const
name|u_char
modifier|*
name|src
parameter_list|)
block|{
name|u_long
name|dst
decl_stmt|;
name|NS_GET32
argument_list|(
name|dst
argument_list|,
name|src
argument_list|)
expr_stmt|;
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

begin_function
name|void
name|ns_put16
parameter_list|(
name|u_int
name|src
parameter_list|,
name|u_char
modifier|*
name|dst
parameter_list|)
block|{
name|NS_PUT16
argument_list|(
name|src
argument_list|,
name|dst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ns_put32
parameter_list|(
name|u_long
name|src
parameter_list|,
name|u_char
modifier|*
name|dst
parameter_list|)
block|{
name|NS_PUT32
argument_list|(
name|src
argument_list|,
name|dst
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*! \file */
end_comment

end_unit

