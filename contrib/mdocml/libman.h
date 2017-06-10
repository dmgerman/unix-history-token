begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: libman.h,v 1.81 2017/04/29 12:45:41 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2014, 2015 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHORS DISCLAIM ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|MACRO_PROT_ARGS
value|struct roff_man *man, \ 			  enum roff_tok tok, \ 			  int line, \ 			  int ppos, \ 			  int *pos, \ 			  char *buf
end_define

begin_struct
struct|struct
name|man_macro
block|{
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|MACRO_PROT_ARGS
parameter_list|)
function_decl|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|MAN_SCOPED
value|(1<< 0)
comment|/* Optional next-line scope. */
define|#
directive|define
name|MAN_NSCOPED
value|(1<< 1)
comment|/* Allowed in next-line element scope. */
define|#
directive|define
name|MAN_BSCOPE
value|(1<< 2)
comment|/* Break next-line block scope. */
define|#
directive|define
name|MAN_JOIN
value|(1<< 3)
comment|/* Join arguments together. */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|man_macro
modifier|*
specifier|const
name|man_macros
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|man_node_validate
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_state
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|,
name|struct
name|roff_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_unscope
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|,
specifier|const
name|struct
name|roff_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

