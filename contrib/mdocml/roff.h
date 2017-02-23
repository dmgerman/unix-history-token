begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: roff.h,v 1.40 2017/02/16 03:00:23 schwarze Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2008, 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2013, 2014, 2015, 2017 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHORS DISCLAIM ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_struct_decl
struct_decl|struct
name|mdoc_arg
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|mdoc_data
union_decl|;
end_union_decl

begin_enum
enum|enum
name|roff_macroset
block|{
name|MACROSET_NONE
init|=
literal|0
block|,
name|MACROSET_MDOC
block|,
name|MACROSET_MAN
block|}
enum|;
end_enum

begin_enum
enum|enum
name|roff_sec
block|{
name|SEC_NONE
init|=
literal|0
block|,
name|SEC_NAME
block|,
name|SEC_LIBRARY
block|,
name|SEC_SYNOPSIS
block|,
name|SEC_DESCRIPTION
block|,
name|SEC_CONTEXT
block|,
name|SEC_IMPLEMENTATION
block|,
comment|/* IMPLEMENTATION NOTES */
name|SEC_RETURN_VALUES
block|,
name|SEC_ENVIRONMENT
block|,
name|SEC_FILES
block|,
name|SEC_EXIT_STATUS
block|,
name|SEC_EXAMPLES
block|,
name|SEC_DIAGNOSTICS
block|,
name|SEC_COMPATIBILITY
block|,
name|SEC_ERRORS
block|,
name|SEC_SEE_ALSO
block|,
name|SEC_STANDARDS
block|,
name|SEC_HISTORY
block|,
name|SEC_AUTHORS
block|,
name|SEC_CAVEATS
block|,
name|SEC_BUGS
block|,
name|SEC_SECURITY
block|,
name|SEC_CUSTOM
block|,
name|SEC__MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|roff_type
block|{
name|ROFFT_ROOT
block|,
name|ROFFT_BLOCK
block|,
name|ROFFT_HEAD
block|,
name|ROFFT_BODY
block|,
name|ROFFT_TAIL
block|,
name|ROFFT_ELEM
block|,
name|ROFFT_TEXT
block|,
name|ROFFT_TBL
block|,
name|ROFFT_EQN
block|}
enum|;
end_enum

begin_enum
enum|enum
name|roff_next
block|{
name|ROFF_NEXT_SIBLING
init|=
literal|0
block|,
name|ROFF_NEXT_CHILD
block|}
enum|;
end_enum

begin_comment
comment|/*  * Indicates that a BODY's formatting has ended, but  * the scope is still open.  Used for badly nested blocks.  */
end_comment

begin_enum
enum|enum
name|mdoc_endbody
block|{
name|ENDBODY_NOT
init|=
literal|0
block|,
name|ENDBODY_SPACE
comment|/* Is broken: append a space. */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|roff_node
block|{
name|struct
name|roff_node
modifier|*
name|parent
decl_stmt|;
comment|/* Parent AST node. */
name|struct
name|roff_node
modifier|*
name|child
decl_stmt|;
comment|/* First child AST node. */
name|struct
name|roff_node
modifier|*
name|last
decl_stmt|;
comment|/* Last child AST node. */
name|struct
name|roff_node
modifier|*
name|next
decl_stmt|;
comment|/* Sibling AST node. */
name|struct
name|roff_node
modifier|*
name|prev
decl_stmt|;
comment|/* Prior sibling AST node. */
name|struct
name|roff_node
modifier|*
name|head
decl_stmt|;
comment|/* BLOCK */
name|struct
name|roff_node
modifier|*
name|body
decl_stmt|;
comment|/* BLOCK/ENDBODY */
name|struct
name|roff_node
modifier|*
name|tail
decl_stmt|;
comment|/* BLOCK */
name|struct
name|mdoc_arg
modifier|*
name|args
decl_stmt|;
comment|/* BLOCK/ELEM */
name|union
name|mdoc_data
modifier|*
name|norm
decl_stmt|;
comment|/* Normalized arguments. */
name|char
modifier|*
name|string
decl_stmt|;
comment|/* TEXT */
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
name|int
name|line
decl_stmt|;
comment|/* Input file line number. */
name|int
name|pos
decl_stmt|;
comment|/* Input file column number. */
name|int
name|tok
decl_stmt|;
comment|/* Request or macro ID. */
define|#
directive|define
name|TOKEN_NONE
value|(-1)
comment|/* No request or macro. */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|NODE_VALID
value|(1<< 0)
comment|/* Has been validated. */
define|#
directive|define
name|NODE_ENDED
value|(1<< 1)
comment|/* Gone past body end mark. */
define|#
directive|define
name|NODE_EOS
value|(1<< 2)
comment|/* At sentence boundary. */
define|#
directive|define
name|NODE_LINE
value|(1<< 3)
comment|/* First macro/text on line. */
define|#
directive|define
name|NODE_SYNPRETTY
value|(1<< 4)
comment|/* SYNOPSIS-style formatting. */
define|#
directive|define
name|NODE_BROKEN
value|(1<< 5)
comment|/* Must validate parent when ending. */
define|#
directive|define
name|NODE_DELIMO
value|(1<< 6)
define|#
directive|define
name|NODE_DELIMC
value|(1<< 7)
define|#
directive|define
name|NODE_NOSRC
value|(1<< 8)
comment|/* Generated node, not in input file. */
define|#
directive|define
name|NODE_NOPRT
value|(1<< 9)
comment|/* Shall not print anything. */
name|int
name|prev_font
decl_stmt|;
comment|/* Before entering this node. */
name|int
name|aux
decl_stmt|;
comment|/* Decoded node data, type-dependent. */
name|enum
name|roff_type
name|type
decl_stmt|;
comment|/* AST node type. */
name|enum
name|roff_sec
name|sec
decl_stmt|;
comment|/* Current named section. */
name|enum
name|mdoc_endbody
name|end
decl_stmt|;
comment|/* BODY */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|roff_meta
block|{
name|char
modifier|*
name|msec
decl_stmt|;
comment|/* Manual section, usually a digit. */
name|char
modifier|*
name|vol
decl_stmt|;
comment|/* Manual volume title. */
name|char
modifier|*
name|os
decl_stmt|;
comment|/* Operating system. */
name|char
modifier|*
name|arch
decl_stmt|;
comment|/* Machine architecture. */
name|char
modifier|*
name|title
decl_stmt|;
comment|/* Manual title, usually CAPS. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Leading manual name. */
name|char
modifier|*
name|date
decl_stmt|;
comment|/* Normalized date. */
name|int
name|hasbody
decl_stmt|;
comment|/* Document is not empty. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|roff_man
block|{
name|struct
name|roff_meta
name|meta
decl_stmt|;
comment|/* Document meta-data. */
name|struct
name|mparse
modifier|*
name|parse
decl_stmt|;
comment|/* Parse pointer. */
name|struct
name|roff
modifier|*
name|roff
decl_stmt|;
comment|/* Roff parser state data. */
specifier|const
name|char
modifier|*
name|defos
decl_stmt|;
comment|/* Default operating system. */
name|struct
name|roff_node
modifier|*
name|first
decl_stmt|;
comment|/* The first node parsed. */
name|struct
name|roff_node
modifier|*
name|last
decl_stmt|;
comment|/* The last node parsed. */
name|struct
name|roff_node
modifier|*
name|last_es
decl_stmt|;
comment|/* The most recent Es node. */
name|int
name|quick
decl_stmt|;
comment|/* Abort parse early. */
name|int
name|flags
decl_stmt|;
comment|/* Parse flags. */
define|#
directive|define
name|MDOC_LITERAL
value|(1<< 1)
comment|/* In a literal scope. */
define|#
directive|define
name|MDOC_PBODY
value|(1<< 2)
comment|/* In the document body. */
define|#
directive|define
name|MDOC_NEWLINE
value|(1<< 3)
comment|/* First macro/text in a line. */
define|#
directive|define
name|MDOC_PHRASE
value|(1<< 4)
comment|/* In a Bl -column phrase. */
define|#
directive|define
name|MDOC_PHRASELIT
value|(1<< 5)
comment|/* Literal within a phrase. */
define|#
directive|define
name|MDOC_FREECOL
value|(1<< 6)
comment|/* `It' invocation should close. */
define|#
directive|define
name|MDOC_SYNOPSIS
value|(1<< 7)
comment|/* SYNOPSIS-style formatting. */
define|#
directive|define
name|MDOC_KEEP
value|(1<< 8)
comment|/* In a word keep. */
define|#
directive|define
name|MDOC_SMOFF
value|(1<< 9)
comment|/* Spacing is off. */
define|#
directive|define
name|MDOC_NODELIMC
value|(1<< 10)
comment|/* Disable closing delimiter handling. */
define|#
directive|define
name|MAN_ELINE
value|(1<< 11)
comment|/* Next-line element scope. */
define|#
directive|define
name|MAN_BLINE
value|(1<< 12)
comment|/* Next-line block scope. */
define|#
directive|define
name|MDOC_PHRASEQF
value|(1<< 13)
comment|/* Quote first word encountered. */
define|#
directive|define
name|MDOC_PHRASEQL
value|(1<< 14)
comment|/* Quote last word of this phrase. */
define|#
directive|define
name|MDOC_PHRASEQN
value|(1<< 15)
comment|/* Quote first word of the next phrase. */
define|#
directive|define
name|MAN_LITERAL
value|MDOC_LITERAL
define|#
directive|define
name|MAN_NEWLINE
value|MDOC_NEWLINE
name|enum
name|roff_macroset
name|macroset
decl_stmt|;
comment|/* Kind of high-level macros used. */
name|enum
name|roff_sec
name|lastsec
decl_stmt|;
comment|/* Last section seen. */
name|enum
name|roff_sec
name|lastnamed
decl_stmt|;
comment|/* Last standard section seen. */
name|enum
name|roff_next
name|next
decl_stmt|;
comment|/* Where to put the next node. */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|deroff
parameter_list|(
name|char
modifier|*
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

