begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: libmdoc.h,v 1.112 2017/05/30 16:22:03 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008, 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2013, 2014, 2015, 2017 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHORS DISCLAIM ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|MACRO_PROT_ARGS
value|struct roff_man *mdoc, \ 			enum roff_tok tok, \ 			int line, \ 			int ppos, \ 			int *pos, \ 			char *buf
end_define

begin_struct
struct|struct
name|mdoc_macro
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
name|MDOC_CALLABLE
value|(1<< 0)
define|#
directive|define
name|MDOC_PARSED
value|(1<< 1)
define|#
directive|define
name|MDOC_EXPLICIT
value|(1<< 2)
define|#
directive|define
name|MDOC_PROLOGUE
value|(1<< 3)
define|#
directive|define
name|MDOC_IGNDELIM
value|(1<< 4)
define|#
directive|define
name|MDOC_JOIN
value|(1<< 5)
block|}
struct|;
end_struct

begin_enum
enum|enum
name|margserr
block|{
name|ARGS_ERROR
block|,
name|ARGS_EOLN
block|,
comment|/* end-of-line */
name|ARGS_WORD
block|,
comment|/* normal word */
name|ARGS_PUNCT
block|,
comment|/* series of punctuation */
name|ARGS_PHRASE
comment|/* Bl -column phrase */
block|}
enum|;
end_enum

begin_comment
comment|/*  * A punctuation delimiter is opening, closing, or "middle mark"  * punctuation.  These govern spacing.  * Opening punctuation (e.g., the opening parenthesis) suppresses the  * following space; closing punctuation (e.g., the closing parenthesis)  * suppresses the leading space; middle punctuation (e.g., the vertical  * bar) can do either.  The middle punctuation delimiter bends the rules  * depending on usage.  */
end_comment

begin_enum
enum|enum
name|mdelim
block|{
name|DELIM_NONE
init|=
literal|0
block|,
name|DELIM_OPEN
block|,
name|DELIM_MIDDLE
block|,
name|DELIM_CLOSE
block|,
name|DELIM_MAX
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mdoc_macro
modifier|*
specifier|const
name|mdoc_macros
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mdoc_macro
parameter_list|(
name|MACRO_PROT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_elem_alloc
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|roff_tok
parameter_list|,
name|struct
name|mdoc_arg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|roff_node
modifier|*
name|mdoc_block_alloc
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|roff_tok
parameter_list|,
name|struct
name|mdoc_arg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_tail_alloc
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|roff_tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|roff_node
modifier|*
name|mdoc_endbody_alloc
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|roff_tok
parameter_list|,
name|struct
name|roff_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_node_relink
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
name|mdoc_node_validate
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_state
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
name|mdoc_state_reset
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mdoc_a2arch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mdoc_a2att
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mdoc_a2lib
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|roff_sec
name|mdoc_a2sec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mdoc_a2st
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_argv
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|roff_tok
parameter_list|,
name|struct
name|mdoc_arg
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|margserr
name|mdoc_args
parameter_list|(
name|struct
name|roff_man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|enum
name|roff_tok
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|mdelim
name|mdoc_isdelim
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

