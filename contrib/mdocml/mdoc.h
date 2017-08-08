begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: mdoc.h,v 1.145 2017/04/24 23:06:18 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008, 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2014, 2015 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHORS DISCLAIM ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_enum
enum|enum
name|mdocargt
block|{
name|MDOC_Split
block|,
comment|/* -split */
name|MDOC_Nosplit
block|,
comment|/* -nospli */
name|MDOC_Ragged
block|,
comment|/* -ragged */
name|MDOC_Unfilled
block|,
comment|/* -unfilled */
name|MDOC_Literal
block|,
comment|/* -literal */
name|MDOC_File
block|,
comment|/* -file */
name|MDOC_Offset
block|,
comment|/* -offset */
name|MDOC_Bullet
block|,
comment|/* -bullet */
name|MDOC_Dash
block|,
comment|/* -dash */
name|MDOC_Hyphen
block|,
comment|/* -hyphen */
name|MDOC_Item
block|,
comment|/* -item */
name|MDOC_Enum
block|,
comment|/* -enum */
name|MDOC_Tag
block|,
comment|/* -tag */
name|MDOC_Diag
block|,
comment|/* -diag */
name|MDOC_Hang
block|,
comment|/* -hang */
name|MDOC_Ohang
block|,
comment|/* -ohang */
name|MDOC_Inset
block|,
comment|/* -inset */
name|MDOC_Column
block|,
comment|/* -column */
name|MDOC_Width
block|,
comment|/* -width */
name|MDOC_Compact
block|,
comment|/* -compact */
name|MDOC_Std
block|,
comment|/* -std */
name|MDOC_Filled
block|,
comment|/* -filled */
name|MDOC_Words
block|,
comment|/* -words */
name|MDOC_Emphasis
block|,
comment|/* -emphasis */
name|MDOC_Symbolic
block|,
comment|/* -symbolic */
name|MDOC_Nested
block|,
comment|/* -nested */
name|MDOC_Centred
block|,
comment|/* -centered */
name|MDOC_ARG_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * An argument to a macro (multiple values = `-column xxx yyy').  */
end_comment

begin_struct
struct|struct
name|mdoc_argv
block|{
name|enum
name|mdocargt
name|arg
decl_stmt|;
comment|/* type of argument */
name|int
name|line
decl_stmt|;
name|int
name|pos
decl_stmt|;
name|size_t
name|sz
decl_stmt|;
comment|/* elements in "value" */
name|char
modifier|*
modifier|*
name|value
decl_stmt|;
comment|/* argument strings */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reference-counted macro arguments.  These are refcounted because  * blocks have multiple instances of the same arguments spread across  * the HEAD, BODY, TAIL, and BLOCK node types.  */
end_comment

begin_struct
struct|struct
name|mdoc_arg
block|{
name|size_t
name|argc
decl_stmt|;
name|struct
name|mdoc_argv
modifier|*
name|argv
decl_stmt|;
name|unsigned
name|int
name|refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mdoc_list
block|{
name|LIST__NONE
init|=
literal|0
block|,
name|LIST_bullet
block|,
comment|/* -bullet */
name|LIST_column
block|,
comment|/* -column */
name|LIST_dash
block|,
comment|/* -dash */
name|LIST_diag
block|,
comment|/* -diag */
name|LIST_enum
block|,
comment|/* -enum */
name|LIST_hang
block|,
comment|/* -hang */
name|LIST_hyphen
block|,
comment|/* -hyphen */
name|LIST_inset
block|,
comment|/* -inset */
name|LIST_item
block|,
comment|/* -item */
name|LIST_ohang
block|,
comment|/* -ohang */
name|LIST_tag
block|,
comment|/* -tag */
name|LIST_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mdoc_disp
block|{
name|DISP__NONE
init|=
literal|0
block|,
name|DISP_centered
block|,
comment|/* -centered */
name|DISP_ragged
block|,
comment|/* -ragged */
name|DISP_unfilled
block|,
comment|/* -unfilled */
name|DISP_filled
block|,
comment|/* -filled */
name|DISP_literal
comment|/* -literal */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mdoc_auth
block|{
name|AUTH__NONE
init|=
literal|0
block|,
name|AUTH_split
block|,
comment|/* -split */
name|AUTH_nosplit
comment|/* -nosplit */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mdoc_font
block|{
name|FONT__NONE
init|=
literal|0
block|,
name|FONT_Em
block|,
comment|/* Em, -emphasis */
name|FONT_Li
block|,
comment|/* Li, -literal */
name|FONT_Sy
comment|/* Sy, -symbolic */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mdoc_bd
block|{
specifier|const
name|char
modifier|*
name|offs
decl_stmt|;
comment|/* -offset */
name|enum
name|mdoc_disp
name|type
decl_stmt|;
comment|/* -ragged, etc. */
name|int
name|comp
decl_stmt|;
comment|/* -compact */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdoc_bl
block|{
specifier|const
name|char
modifier|*
name|width
decl_stmt|;
comment|/* -width */
specifier|const
name|char
modifier|*
name|offs
decl_stmt|;
comment|/* -offset */
name|enum
name|mdoc_list
name|type
decl_stmt|;
comment|/* -tag, -enum, etc. */
name|int
name|comp
decl_stmt|;
comment|/* -compact */
name|size_t
name|ncols
decl_stmt|;
comment|/* -column arg count */
specifier|const
name|char
modifier|*
modifier|*
name|cols
decl_stmt|;
comment|/* -column val ptr */
name|int
name|count
decl_stmt|;
comment|/* -enum counter */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdoc_bf
block|{
name|enum
name|mdoc_font
name|font
decl_stmt|;
comment|/* font */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdoc_an
block|{
name|enum
name|mdoc_auth
name|auth
decl_stmt|;
comment|/* -split, etc. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdoc_rs
block|{
name|int
name|quote_T
decl_stmt|;
comment|/* whether to quote %T */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Consists of normalised node arguments.  These should be used instead  * of iterating through the mdoc_arg pointers of a node: defaults are  * provided, etc.  */
end_comment

begin_union
union|union
name|mdoc_data
block|{
name|struct
name|mdoc_an
name|An
decl_stmt|;
name|struct
name|mdoc_bd
name|Bd
decl_stmt|;
name|struct
name|mdoc_bf
name|Bf
decl_stmt|;
name|struct
name|mdoc_bl
name|Bl
decl_stmt|;
name|struct
name|roff_node
modifier|*
name|Es
decl_stmt|;
name|struct
name|mdoc_rs
name|Rs
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Names of macro args.  Index is enum mdocargt. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|mdoc_argnames
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mdoc_validate
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

