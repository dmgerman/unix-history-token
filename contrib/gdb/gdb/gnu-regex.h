begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for data structures callers pass the regex library.    Copyright (C) 1985, 1989 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Define number of parens for which we record the beginnings and ends.    This affects how much space the `struct re_registers' type takes up.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RE_NREGS
end_ifndef

begin_define
define|#
directive|define
name|RE_NREGS
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These bits are used in the obscure_syntax variable to choose among    alternative regexp syntaxes.  */
end_comment

begin_comment
comment|/* 1 means plain parentheses serve as grouping, and backslash      parentheses are needed for literal searching.    0 means backslash-parentheses are grouping, and plain parentheses      are for literal searching.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_PARENS
value|1
end_define

begin_comment
comment|/* 1 means plain | serves as the "or"-operator, and \| is a literal.    0 means \| serves as the "or"-operator, and | is a literal.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_VBAR
value|2
end_define

begin_comment
comment|/* 0 means plain + or ? serves as an operator, and \+, \? are literals.    1 means \+, \? are operators and plain +, ? are literals.  */
end_comment

begin_define
define|#
directive|define
name|RE_BK_PLUS_QM
value|4
end_define

begin_comment
comment|/* 1 means | binds tighter than ^ or $.    0 means the contrary.  */
end_comment

begin_define
define|#
directive|define
name|RE_TIGHT_VBAR
value|8
end_define

begin_comment
comment|/* 1 means treat \n as an _OR operator    0 means treat it as a normal character */
end_comment

begin_define
define|#
directive|define
name|RE_NEWLINE_OR
value|16
end_define

begin_comment
comment|/* 0 means that a special characters (such as *, ^, and $) always have      their special meaning regardless of the surrounding context.    1 means that special characters may act as normal characters in some      contexts.  Specifically, this applies to: 	^ - only special at the beginning, or after ( or | 	$ - only special at the end, or before ) or | 	*, +, ? - only special when not after the beginning, (, or | */
end_comment

begin_define
define|#
directive|define
name|RE_CONTEXT_INDEP_OPS
value|32
end_define

begin_comment
comment|/* Now define combinations of bits for the standard possibilities.  */
end_comment

begin_define
define|#
directive|define
name|RE_SYNTAX_AWK
value|(RE_NO_BK_PARENS | RE_NO_BK_VBAR | RE_CONTEXT_INDEP_OPS)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_EGREP
value|(RE_SYNTAX_AWK | RE_NEWLINE_OR)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_GREP
value|(RE_BK_PLUS_QM | RE_NEWLINE_OR)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_EMACS
value|0
end_define

begin_comment
comment|/* This data structure is used to represent a compiled pattern. */
end_comment

begin_struct
struct|struct
name|re_pattern_buffer
block|{
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* Space holding the compiled pattern commands. */
name|int
name|allocated
decl_stmt|;
comment|/* Size of space that  buffer  points to */
name|int
name|used
decl_stmt|;
comment|/* Length of portion of buffer actually occupied */
name|char
modifier|*
name|fastmap
decl_stmt|;
comment|/* Pointer to fastmap, if any, or zero if none. */
comment|/* re_search uses the fastmap, if there is one, 			   to skip quickly over totally implausible characters */
name|char
modifier|*
name|translate
decl_stmt|;
comment|/* Translate table to apply to all characters before comparing. 			   Or zero for no translation. 			   The translation is applied to a pattern when it is compiled 			   and to data when it is matched. */
name|char
name|fastmap_accurate
decl_stmt|;
comment|/* Set to zero when a new pattern is stored, 			   set to one when the fastmap is updated from it. */
name|char
name|can_be_null
decl_stmt|;
comment|/* Set to one by compiling fastmap 			   if this pattern might match the null string. 			   It does not necessarily match the null string 			   in that case, but if this is zero, it cannot. 			   2 as value means can match null string 			   but at end of range or before a character 			   listed in the fastmap.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure to store "register" contents data in.     Pass the address of such a structure as an argument to re_match, etc.,    if you want this information back.     start[i] and end[i] record the string matched by \( ... \) grouping i,    for i from 1 to RE_NREGS - 1.    start[0] and end[0] record the entire string matched. */
end_comment

begin_struct
struct|struct
name|re_registers
block|{
name|int
name|start
index|[
name|RE_NREGS
index|]
decl_stmt|;
name|int
name|end
index|[
name|RE_NREGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* These are the command codes that appear in compiled regular expressions, one per byte.   Some command codes are followed by argument bytes.   A command code can specify any interpretation whatever for its arguments.   Zero-bytes may appear in the compiled regular expression. */
end_comment

begin_enum
enum|enum
name|regexpcode
block|{
name|unused
block|,
name|exactn
block|,
comment|/* followed by one byte giving n, and then by n literal bytes */
name|begline
block|,
comment|/* fails unless at beginning of line */
name|endline
block|,
comment|/* fails unless at end of line */
name|jump
block|,
comment|/* followed by two bytes giving relative address to jump to */
name|on_failure_jump
block|,
comment|/* followed by two bytes giving relative address of place 		            to resume at in case of failure. */
name|finalize_jump
block|,
comment|/* Throw away latest failure point and then jump to address. */
name|maybe_finalize_jump
block|,
comment|/* Like jump but finalize if safe to do so. 			    This is used to jump back to the beginning 			    of a repeat.  If the command that follows 			    this jump is clearly incompatible with the 			    one at the beginning of the repeat, such that 			    we can be sure that there is no use backtracking 			    out of repetitions already completed, 			    then we finalize. */
name|dummy_failure_jump
block|,
comment|/* jump, and push a dummy failure point. 			    This failure point will be thrown away 			    if an attempt is made to use it for a failure. 			    A + construct makes this before the first repeat.  */
name|anychar
block|,
comment|/* matches any one character */
name|charset
block|,
comment|/* matches any one char belonging to specified set. 		    First following byte is # bitmap bytes. 		    Then come bytes for a bit-map saying which chars are in. 		    Bits in each byte are ordered low-bit-first. 		    A character is in the set if its bit is 1. 		    A character too large to have a bit in the map 		    is automatically not in the set */
name|charset_not
block|,
comment|/* similar but match any character that is NOT one of those specified */
name|start_memory
block|,
comment|/* starts remembering the text that is matched 		    and stores it in a memory register. 		    followed by one byte containing the register number. 		    Register numbers must be in the range 0 through NREGS. */
name|stop_memory
block|,
comment|/* stops remembering the text that is matched 		    and stores it in a memory register. 		    followed by one byte containing the register number. 		    Register numbers must be in the range 0 through NREGS. */
name|duplicate
block|,
comment|/* match a duplicate of something remembered. 		    Followed by one byte containing the index of the memory register. */
name|before_dot
block|,
comment|/* Succeeds if before dot */
name|at_dot
block|,
comment|/* Succeeds if at dot */
name|after_dot
block|,
comment|/* Succeeds if after dot */
name|begbuf
block|,
comment|/* Succeeds if at beginning of buffer */
name|endbuf
block|,
comment|/* Succeeds if at end of buffer */
name|wordchar
block|,
comment|/* Matches any word-constituent character */
name|notwordchar
block|,
comment|/* Matches any char that is not a word-constituent */
name|wordbeg
block|,
comment|/* Succeeds if at word beginning */
name|wordend
block|,
comment|/* Succeeds if at word end */
name|wordbound
block|,
comment|/* Succeeds if at a word boundary */
name|notwordbound
block|,
comment|/* Succeeds if not at a word boundary */
name|syntaxspec
block|,
comment|/* Matches any character whose syntax is specified. 		    followed by a byte which contains a syntax code, Sword or such like */
name|notsyntaxspec
comment|/* Matches any character whose syntax differs from the specified. */
block|}
enum|;
end_enum

begin_escape
end_escape

begin_function_decl
specifier|extern
name|char
modifier|*
name|re_compile_pattern
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Is this really advertised? */
end_comment

begin_function_decl
specifier|extern
name|void
name|re_compile_fastmap
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|re_search
argument_list|()
decl_stmt|,
name|re_search_2
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|re_match
argument_list|()
decl_stmt|,
name|re_match_2
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4.2 bsd compatibility (yuck) */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|re_comp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|re_exec
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SYNTAX_TABLE
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|re_syntax_table
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|re_set_syntax
parameter_list|()
function_decl|;
end_function_decl

end_unit

