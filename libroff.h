begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: libroff.h,v 1.42 2017/07/08 17:52:49 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2014, 2015, 2017 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_enum
enum|enum
name|tbl_part
block|{
name|TBL_PART_OPTS
block|,
comment|/* in options (first line) */
name|TBL_PART_LAYOUT
block|,
comment|/* describing layout */
name|TBL_PART_DATA
block|,
comment|/* creating data rows */
name|TBL_PART_CDATA
comment|/* continue previous row */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|tbl_node
block|{
name|struct
name|mparse
modifier|*
name|parse
decl_stmt|;
comment|/* parse point */
name|int
name|pos
decl_stmt|;
comment|/* invocation column */
name|int
name|line
decl_stmt|;
comment|/* invocation line */
name|enum
name|tbl_part
name|part
decl_stmt|;
name|struct
name|tbl_opts
name|opts
decl_stmt|;
name|struct
name|tbl_row
modifier|*
name|first_row
decl_stmt|;
name|struct
name|tbl_row
modifier|*
name|last_row
decl_stmt|;
name|struct
name|tbl_span
modifier|*
name|first_span
decl_stmt|;
name|struct
name|tbl_span
modifier|*
name|current_span
decl_stmt|;
name|struct
name|tbl_span
modifier|*
name|last_span
decl_stmt|;
name|struct
name|tbl_node
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eqn_node
block|{
name|struct
name|mparse
modifier|*
name|parse
decl_stmt|;
comment|/* main parser, for error reporting */
name|struct
name|roff_node
modifier|*
name|node
decl_stmt|;
comment|/* syntax tree of this equation */
name|struct
name|eqn_def
modifier|*
name|defs
decl_stmt|;
comment|/* array of definitions */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* source code of this equation */
name|char
modifier|*
name|start
decl_stmt|;
comment|/* first byte of the current token */
name|char
modifier|*
name|end
decl_stmt|;
comment|/* first byte of the next token */
name|size_t
name|defsz
decl_stmt|;
comment|/* number of definitions */
name|size_t
name|sz
decl_stmt|;
comment|/* length of the source code */
name|size_t
name|toksz
decl_stmt|;
comment|/* length of the current token */
name|int
name|gsize
decl_stmt|;
comment|/* default point size */
name|int
name|delim
decl_stmt|;
comment|/* in-line delimiters enabled */
name|char
name|odelim
decl_stmt|;
comment|/* in-line opening delimiter */
name|char
name|cdelim
decl_stmt|;
comment|/* in-line closing delimiter */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eqn_def
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|size_t
name|keysz
decl_stmt|;
name|char
modifier|*
name|val
decl_stmt|;
name|size_t
name|valsz
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|tbl_node
modifier|*
name|tbl_alloc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|mparse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tbl_restart
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|tbl_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tbl_free
parameter_list|(
name|struct
name|tbl_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tbl_reset
parameter_list|(
name|struct
name|tbl_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tbl_read
parameter_list|(
name|struct
name|tbl_node
modifier|*
parameter_list|,
name|int
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
name|tbl_option
parameter_list|(
name|struct
name|tbl_node
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tbl_layout
parameter_list|(
name|struct
name|tbl_node
modifier|*
parameter_list|,
name|int
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
name|tbl_data
parameter_list|(
name|struct
name|tbl_node
modifier|*
parameter_list|,
name|int
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
name|tbl_cdata
parameter_list|(
name|struct
name|tbl_node
modifier|*
parameter_list|,
name|int
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
specifier|const
name|struct
name|tbl_span
modifier|*
name|tbl_span
parameter_list|(
name|struct
name|tbl_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tbl_end
parameter_list|(
name|struct
name|tbl_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|eqn_node
modifier|*
name|eqn_alloc
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eqn_box_free
parameter_list|(
name|struct
name|eqn_box
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eqn_free
parameter_list|(
name|struct
name|eqn_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eqn_parse
parameter_list|(
name|struct
name|eqn_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eqn_read
parameter_list|(
name|struct
name|eqn_node
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
name|eqn_reset
parameter_list|(
name|struct
name|eqn_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

