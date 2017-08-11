begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: manconf.h,v 1.5 2017/07/01 09:47:30 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011, 2015, 2017 Ingo Schwarze<schwarze@openbsd.org>  * Copyright (c) 2011 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHORS DISCLAIM ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* List of unique, absolute paths to manual trees. */
end_comment

begin_struct
struct|struct
name|manpaths
block|{
name|char
modifier|*
modifier|*
name|paths
decl_stmt|;
name|size_t
name|sz
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Data from -O options and man.conf(5) output directives. */
end_comment

begin_struct
struct|struct
name|manoutput
block|{
name|char
modifier|*
name|includes
decl_stmt|;
name|char
modifier|*
name|man
decl_stmt|;
name|char
modifier|*
name|paper
decl_stmt|;
name|char
modifier|*
name|style
decl_stmt|;
name|size_t
name|indent
decl_stmt|;
name|size_t
name|width
decl_stmt|;
name|int
name|fragment
decl_stmt|;
name|int
name|mdoc
decl_stmt|;
name|int
name|synopsisonly
decl_stmt|;
name|int
name|noval
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|manconf
block|{
name|struct
name|manoutput
name|output
decl_stmt|;
name|struct
name|manpaths
name|manpath
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|manconf_parse
parameter_list|(
name|struct
name|manconf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|manconf_output
parameter_list|(
name|struct
name|manoutput
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|manconf_free
parameter_list|(
name|struct
name|manconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|manpath_base
parameter_list|(
name|struct
name|manpaths
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

