begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: libmdoc.h,v 1.96 2014/12/01 04:05:32 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008, 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2013, 2014 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_enum
enum|enum
name|mdoc_next
block|{
name|MDOC_NEXT_SIBLING
init|=
literal|0
block|,
name|MDOC_NEXT_CHILD
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mdoc
block|{
name|struct
name|mparse
modifier|*
name|parse
decl_stmt|;
comment|/* parse pointer */
specifier|const
name|char
modifier|*
name|defos
decl_stmt|;
comment|/* default argument for .Os */
name|int
name|quick
decl_stmt|;
comment|/* abort parse early */
name|int
name|flags
decl_stmt|;
comment|/* parse flags */
define|#
directive|define
name|MDOC_LITERAL
value|(1<< 1)
comment|/* in a literal scope */
define|#
directive|define
name|MDOC_PBODY
value|(1<< 2)
comment|/* in the document body */
define|#
directive|define
name|MDOC_NEWLINE
value|(1<< 3)
comment|/* first macro/text in a line */
define|#
directive|define
name|MDOC_PHRASELIT
value|(1<< 4)
comment|/* literal within a partila phrase */
define|#
directive|define
name|MDOC_PPHRASE
value|(1<< 5)
comment|/* within a partial phrase */
define|#
directive|define
name|MDOC_FREECOL
value|(1<< 6)
comment|/* `It' invocation should close */
define|#
directive|define
name|MDOC_SYNOPSIS
value|(1<< 7)
comment|/* SYNOPSIS-style formatting */
define|#
directive|define
name|MDOC_KEEP
value|(1<< 8)
comment|/* in a word keep */
define|#
directive|define
name|MDOC_SMOFF
value|(1<< 9)
comment|/* spacing is off */
define|#
directive|define
name|MDOC_NODELIMC
value|(1<< 10)
comment|/* disable closing delimiter handling */
name|enum
name|mdoc_next
name|next
decl_stmt|;
comment|/* where to put the next node */
name|struct
name|mdoc_node
modifier|*
name|last
decl_stmt|;
comment|/* the last node parsed */
name|struct
name|mdoc_node
modifier|*
name|first
decl_stmt|;
comment|/* the first node parsed */
name|struct
name|mdoc_node
modifier|*
name|last_es
decl_stmt|;
comment|/* the most recent Es node */
name|struct
name|mdoc_meta
name|meta
decl_stmt|;
comment|/* document meta-data */
name|enum
name|mdoc_sec
name|lastnamed
decl_stmt|;
name|enum
name|mdoc_sec
name|lastsec
decl_stmt|;
name|struct
name|roff
modifier|*
name|roff
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MACRO_PROT_ARGS
value|struct mdoc *mdoc, \ 			enum mdoct tok, \ 			int line, \ 			int ppos, \ 			int *pos, \ 			char *buf
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
name|ARGS_QWORD
block|,
comment|/* quoted word */
name|ARGS_PHRASE
block|,
comment|/* Ta'd phrase (-column) */
name|ARGS_PPHRASE
block|,
comment|/* tabbed phrase (-column) */
name|ARGS_PEND
comment|/* last phrase (-column) */
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
name|__BEGIN_DECLS
name|void
name|mdoc_macro
parameter_list|(
name|MACRO_PROT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_word_alloc
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_word_append
parameter_list|(
name|struct
name|mdoc
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
name|mdoc_elem_alloc
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mdoct
parameter_list|,
name|struct
name|mdoc_arg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mdoc_node
modifier|*
name|mdoc_block_alloc
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mdoct
parameter_list|,
name|struct
name|mdoc_arg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mdoc_node
modifier|*
name|mdoc_head_alloc
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mdoct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_tail_alloc
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mdoct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mdoc_node
modifier|*
name|mdoc_body_alloc
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mdoct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_endbody_alloc
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mdoct
parameter_list|,
name|struct
name|mdoc_node
modifier|*
parameter_list|,
name|enum
name|mdoc_endbody
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_node_delete
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|struct
name|mdoc_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_node_relink
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|struct
name|mdoc_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_hash_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|mdoct
name|mdoc_hash_find
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
name|void
name|mdoc_valid_pre
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|struct
name|mdoc_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_valid_post
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_argv
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|mdoct
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
name|void
name|mdoc_argv_free
parameter_list|(
name|struct
name|mdoc_arg
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
name|mdoc
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
name|mdoct
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_macroend
parameter_list|(
name|struct
name|mdoc
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

begin_macro
name|__END_DECLS
end_macro

end_unit

