begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: privsep.h,v 1.2 2004/05/04 18:51:18 henning Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004 Henning Brauer<henning@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER IN  * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE, ABUSE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<poll.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_struct
struct|struct
name|buf
block|{
name|u_char
modifier|*
name|buf
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|size_t
name|wpos
decl_stmt|;
name|size_t
name|rpos
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|imsg_code
block|{
name|IMSG_NONE
block|,
name|IMSG_SCRIPT_INIT
block|,
name|IMSG_SCRIPT_WRITE_PARAMS
block|,
name|IMSG_SCRIPT_GO
block|,
name|IMSG_SCRIPT_GO_RET
block|}
enum|;
end_enum

begin_struct
struct|struct
name|imsg_hdr
block|{
name|enum
name|imsg_code
name|code
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|buf
modifier|*
name|buf_open
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buf_add
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buf_close
parameter_list|(
name|int
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|buf_read
parameter_list|(
name|int
name|sock
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

