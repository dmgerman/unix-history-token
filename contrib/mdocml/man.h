begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: man.h,v 1.78 2017/04/24 23:06:18 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2014, 2015 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHORS DISCLAIM ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_struct_decl
struct_decl|struct
name|roff_man
struct_decl|;
end_struct_decl

begin_function_decl
specifier|const
name|struct
name|mparse
modifier|*
name|man_mparse
parameter_list|(
specifier|const
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_validate
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

