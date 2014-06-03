begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: libman.h,v 1.56 2012/11/17 00:26:33 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBMAN_H
end_ifndef

begin_define
define|#
directive|define
name|LIBMAN_H
end_define

begin_enum
enum|enum
name|man_next
block|{
name|MAN_NEXT_SIBLING
init|=
literal|0
block|,
name|MAN_NEXT_CHILD
block|}
enum|;
end_enum

begin_struct
struct|struct
name|man
block|{
name|struct
name|mparse
modifier|*
name|parse
decl_stmt|;
comment|/* parse pointer */
name|int
name|flags
decl_stmt|;
comment|/* parse flags */
define|#
directive|define
name|MAN_HALT
value|(1<< 0)
comment|/* badness happened: die */
define|#
directive|define
name|MAN_ELINE
value|(1<< 1)
comment|/* Next-line element scope. */
define|#
directive|define
name|MAN_BLINE
value|(1<< 2)
comment|/* Next-line block scope. */
define|#
directive|define
name|MAN_ILINE
value|(1<< 3)
comment|/* Ignored in next-line scope. */
define|#
directive|define
name|MAN_LITERAL
value|(1<< 4)
comment|/* Literal input. */
define|#
directive|define
name|MAN_BPLINE
value|(1<< 5)
define|#
directive|define
name|MAN_NEWLINE
value|(1<< 6)
comment|/* first macro/text in a line */
name|enum
name|man_next
name|next
decl_stmt|;
comment|/* where to put the next node */
name|struct
name|man_node
modifier|*
name|last
decl_stmt|;
comment|/* the last parsed node */
name|struct
name|man_node
modifier|*
name|first
decl_stmt|;
comment|/* the first parsed node */
name|struct
name|man_meta
name|meta
decl_stmt|;
comment|/* document meta-data */
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
value|struct man *man, \ 			  enum mant tok, \ 			  int line, \ 			  int ppos, \ 			  int *pos, \ 			  char *buf
end_define

begin_struct
struct|struct
name|man_macro
block|{
name|int
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
define|#
directive|define
name|MAN_EXPLICIT
value|(1<< 1)
comment|/* See blk_imp(). */
define|#
directive|define
name|MAN_FSCOPED
value|(1<< 2)
comment|/* See blk_imp(). */
define|#
directive|define
name|MAN_NSCOPED
value|(1<< 3)
comment|/* See in_line_eoln(). */
define|#
directive|define
name|MAN_NOCLOSE
value|(1<< 4)
comment|/* See blk_exp(). */
define|#
directive|define
name|MAN_BSCOPE
value|(1<< 5)
comment|/* Break BLINE scope. */
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
name|__BEGIN_DECLS
define|#
directive|define
name|man_pmsg
parameter_list|(
name|man
parameter_list|,
name|l
parameter_list|,
name|p
parameter_list|,
name|t
parameter_list|)
define|\
value|mandoc_msg((t), (man)->parse, (l), (p), NULL)
define|#
directive|define
name|man_nmsg
parameter_list|(
name|man
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|mandoc_msg((t), (man)->parse, (n)->line, (n)->pos, NULL)
name|int
name|man_word_alloc
parameter_list|(
name|struct
name|man
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
name|int
name|man_block_alloc
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mant
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_head_alloc
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mant
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_tail_alloc
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mant
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_body_alloc
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mant
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_elem_alloc
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|mant
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_node_delete
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
name|struct
name|man_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_hash_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|mant
name|man_hash_find
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_macroend
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_valid_post
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_valid_pre
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
name|struct
name|man_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_unscope
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
specifier|const
name|struct
name|man_node
modifier|*
parameter_list|,
name|enum
name|mandocerr
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
comment|/*!LIBMAN_H*/
end_comment

end_unit

