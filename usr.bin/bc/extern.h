begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$						*/
end_comment

begin_comment
comment|/*      $OpenBSD: extern.h,v 1.10 2013/09/19 16:12:01 otto Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2003, Otto Moerbeek<otto@drijf.net>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_struct
struct|struct
name|lvalue
block|{
name|ssize_t
name|load
decl_stmt|;
name|ssize_t
name|store
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|abort_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|termios
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|gettty
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tstpcont
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|bc_eof
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fileindex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
modifier|*
name|sargv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|interactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EditLine
modifier|*
name|el
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|History
modifier|*
name|hist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HistEvent
name|he
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cmdexpr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|termios
name|ttysaved
decl_stmt|;
end_decl_stmt

end_unit

