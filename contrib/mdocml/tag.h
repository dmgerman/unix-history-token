begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $Id: tag.h,v 1.7 2015/11/20 21:59:54 schwarze Exp $    */
end_comment

begin_comment
comment|/*  * Copyright (c) 2015 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_struct
struct|struct
name|tag_files
block|{
name|char
name|ofn
index|[
literal|20
index|]
decl_stmt|;
name|char
name|tfn
index|[
literal|20
index|]
decl_stmt|;
name|int
name|ofd
decl_stmt|;
name|int
name|tfd
decl_stmt|;
name|pid_t
name|tcpgid
decl_stmt|;
name|pid_t
name|pager_pid
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|tag_files
modifier|*
name|tag_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tag_put
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tag_write
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tag_unlink
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

