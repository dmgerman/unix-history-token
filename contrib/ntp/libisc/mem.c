begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1997-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: mem.c,v 1.113 2002/05/23 04:32:30 marka Exp $ */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<isc/mem.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_function
name|void
modifier|*
name|isc_mem_get
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|UNUSED
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
if|if
condition|(
name|size
operator|==
literal|0
condition|)
name|size
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|malloc
argument_list|(
name|size
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|void
name|isc_mem_put
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|UNUSED
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

