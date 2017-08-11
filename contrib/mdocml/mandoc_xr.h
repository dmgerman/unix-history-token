begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: mandoc_xr.h,v 1.3 2017/07/02 21:18:29 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2017 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_struct
struct|struct
name|mandoc_xr
block|{
name|struct
name|mandoc_xr
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|sec
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|line
decl_stmt|;
comment|/* Or -1 for this page's own names. */
name|int
name|pos
decl_stmt|;
name|int
name|count
decl_stmt|;
name|char
name|hashkey
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|mandoc_xr_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mandoc_xr_add
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mandoc_xr
modifier|*
name|mandoc_xr_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mandoc_xr_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

