begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: manpath.h,v 1.6 2012/06/08 10:32:40 kristaps Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 Ingo Schwarze<schwarze@openbsd.org>  * Copyright (c) 2011 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MANPATH_H
end_ifndef

begin_define
define|#
directive|define
name|MANPATH_H
end_define

begin_comment
comment|/*  * Unsorted list of unique, absolute paths to be searched for manual  * databases.  */
end_comment

begin_struct
struct|struct
name|manpaths
block|{
name|size_t
name|sz
decl_stmt|;
name|char
modifier|*
modifier|*
name|paths
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
name|void
name|manpath_manconf
parameter_list|(
name|struct
name|manpaths
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|manpath_parse
parameter_list|(
name|struct
name|manpaths
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
name|void
name|manpath_free
parameter_list|(
name|struct
name|manpaths
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!MANPATH_H*/
end_comment

end_unit

