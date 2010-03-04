begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: roaming_dummy.c,v 1.3 2009/06/21 09:04:03 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004-2009 AppGate Network Security AB  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * This file is included in the client programs which should not  * support roaming.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"roaming.h"
end_include

begin_decl_stmt
name|int
name|resume_in_progress
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|u_int64_t
name|get_recv_bytes
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|ssize_t
name|roaming_write
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|count
parameter_list|,
name|int
modifier|*
name|cont
parameter_list|)
block|{
return|return
name|write
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
return|;
block|}
end_function

begin_function
name|ssize_t
name|roaming_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|count
parameter_list|,
name|int
modifier|*
name|cont
parameter_list|)
block|{
if|if
condition|(
name|cont
condition|)
operator|*
name|cont
operator|=
literal|0
expr_stmt|;
return|return
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|add_recv_bytes
parameter_list|(
name|u_int64_t
name|num
parameter_list|)
block|{ }
end_function

begin_function
name|int
name|resume_kex
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

end_unit

