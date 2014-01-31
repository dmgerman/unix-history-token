begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: man.h,v 1.62 2013/10/17 20:54:58 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAN_H
end_ifndef

begin_define
define|#
directive|define
name|MAN_H
end_define

begin_enum
enum|enum
name|mant
block|{
name|MAN_br
init|=
literal|0
block|,
name|MAN_TH
block|,
name|MAN_SH
block|,
name|MAN_SS
block|,
name|MAN_TP
block|,
name|MAN_LP
block|,
name|MAN_PP
block|,
name|MAN_P
block|,
name|MAN_IP
block|,
name|MAN_HP
block|,
name|MAN_SM
block|,
name|MAN_SB
block|,
name|MAN_BI
block|,
name|MAN_IB
block|,
name|MAN_BR
block|,
name|MAN_RB
block|,
name|MAN_R
block|,
name|MAN_B
block|,
name|MAN_I
block|,
name|MAN_IR
block|,
name|MAN_RI
block|,
name|MAN_na
block|,
name|MAN_sp
block|,
name|MAN_nf
block|,
name|MAN_fi
block|,
name|MAN_RE
block|,
name|MAN_RS
block|,
name|MAN_DT
block|,
name|MAN_UC
block|,
name|MAN_PD
block|,
name|MAN_AT
block|,
name|MAN_in
block|,
name|MAN_ft
block|,
name|MAN_OP
block|,
name|MAN_EX
block|,
name|MAN_EE
block|,
name|MAN_UR
block|,
name|MAN_UE
block|,
name|MAN_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|man_type
block|{
name|MAN_TEXT
block|,
name|MAN_ELEM
block|,
name|MAN_ROOT
block|,
name|MAN_BLOCK
block|,
name|MAN_HEAD
block|,
name|MAN_BODY
block|,
name|MAN_TAIL
block|,
name|MAN_TBL
block|,
name|MAN_EQN
block|}
enum|;
end_enum

begin_struct
struct|struct
name|man_meta
block|{
name|char
modifier|*
name|msec
decl_stmt|;
comment|/* `TH' section (1, 3p, etc.) */
name|char
modifier|*
name|date
decl_stmt|;
comment|/* `TH' normalised date */
name|char
modifier|*
name|vol
decl_stmt|;
comment|/* `TH' volume */
name|char
modifier|*
name|title
decl_stmt|;
comment|/* `TH' title (e.g., FOO) */
name|char
modifier|*
name|source
decl_stmt|;
comment|/* `TH' source (e.g., GNU) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|man_node
block|{
name|struct
name|man_node
modifier|*
name|parent
decl_stmt|;
comment|/* parent AST node */
name|struct
name|man_node
modifier|*
name|child
decl_stmt|;
comment|/* first child AST node */
name|struct
name|man_node
modifier|*
name|next
decl_stmt|;
comment|/* sibling AST node */
name|struct
name|man_node
modifier|*
name|prev
decl_stmt|;
comment|/* prior sibling AST node */
name|int
name|nchild
decl_stmt|;
comment|/* number children */
name|int
name|line
decl_stmt|;
name|int
name|pos
decl_stmt|;
name|enum
name|mant
name|tok
decl_stmt|;
comment|/* tok or MAN__MAX if none */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|MAN_VALID
value|(1<< 0)
comment|/* has been validated */
define|#
directive|define
name|MAN_EOS
value|(1<< 2)
comment|/* at sentence boundary */
define|#
directive|define
name|MAN_LINE
value|(1<< 3)
comment|/* first macro/text on line */
name|enum
name|man_type
name|type
decl_stmt|;
comment|/* AST node type */
name|char
modifier|*
name|string
decl_stmt|;
comment|/* TEXT node argument */
name|struct
name|man_node
modifier|*
name|head
decl_stmt|;
comment|/* BLOCK node HEAD ptr */
name|struct
name|man_node
modifier|*
name|tail
decl_stmt|;
comment|/* BLOCK node TAIL ptr */
name|struct
name|man_node
modifier|*
name|body
decl_stmt|;
comment|/* BLOCK node BODY ptr */
specifier|const
name|struct
name|tbl_span
modifier|*
name|span
decl_stmt|;
comment|/* TBL */
specifier|const
name|struct
name|eqn
modifier|*
name|eqn
decl_stmt|;
comment|/* EQN */
block|}
struct|;
end_struct

begin_comment
comment|/* Names of macros.  Index is enum mant. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|man_macronames
decl_stmt|;
end_decl_stmt

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|man
struct_decl|;
end_struct_decl

begin_function_decl
specifier|const
name|struct
name|man_node
modifier|*
name|man_node
parameter_list|(
specifier|const
name|struct
name|man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|man_meta
modifier|*
name|man_meta
parameter_list|(
specifier|const
name|struct
name|man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|mparse
modifier|*
name|man_mparse
parameter_list|(
specifier|const
name|struct
name|man
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
comment|/*!MAN_H*/
end_comment

end_unit

