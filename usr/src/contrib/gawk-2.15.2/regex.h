begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for data structures callers pass the regex library.     Copyright (C) 1985, 1989-90 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__REGEXP_LIBRARY
end_ifndef

begin_define
define|#
directive|define
name|__REGEXP_LIBRARY
end_define

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

begin_define
define|#
directive|define
name|BYTEWIDTH
value|8
end_define

begin_comment
comment|/* Maximum number of duplicates an interval can allow.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RE_DUP_MAX
end_ifndef

begin_define
define|#
directive|define
name|RE_DUP_MAX
value|((1<< 15) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This defines the various regexp syntaxes.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|obscure_syntax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following bits are used in the obscure_syntax variable to choose among    alternative regexp syntaxes.  */
end_comment

begin_comment
comment|/* If this bit is set, plain parentheses serve as grouping, and backslash      parentheses are needed for literal searching.    If not set, backslash-parentheses are grouping, and plain parentheses      are for literal searching.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_PARENS
value|1L
end_define

begin_comment
comment|/* If this bit is set, plain | serves as the `or'-operator, and \| is a       literal.    If not set, \| serves as the `or'-operator, and | is a literal.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_VBAR
value|(1L<< 1)
end_define

begin_comment
comment|/* If this bit is not set, plain + or ? serves as an operator, and \+, \? are       literals.    If set, \+, \? are operators and plain +, ? are literals.  */
end_comment

begin_define
define|#
directive|define
name|RE_BK_PLUS_QM
value|(1L<< 2)
end_define

begin_comment
comment|/* If this bit is set, | binds tighter than ^ or $.    If not set, the contrary.  */
end_comment

begin_define
define|#
directive|define
name|RE_TIGHT_VBAR
value|(1L<< 3)
end_define

begin_comment
comment|/* If this bit is set, then treat newline as an OR operator.    If not set, treat it as a normal character.  */
end_comment

begin_define
define|#
directive|define
name|RE_NEWLINE_OR
value|(1L<< 4)
end_define

begin_comment
comment|/* If this bit is set, then special characters may act as normal    characters in some contexts. Specifically, this applies to: 	^ -- only special at the beginning, or after ( or |; 	$ -- only special at the end, or before ) or |; 	*, +, ? -- only special when not after the beginning, (, or |.    If this bit is not set, special characters (such as *, ^, and $)    always have their special meaning regardless of the surrounding    context.  */
end_comment

begin_define
define|#
directive|define
name|RE_CONTEXT_INDEP_OPS
value|(1L<< 5)
end_define

begin_comment
comment|/* If this bit is not set, then \ before anything inside [ and ] is taken as       a real \.    If set, then such a \ escapes the following character.  This is a      special case for awk.  */
end_comment

begin_define
define|#
directive|define
name|RE_AWK_CLASS_HACK
value|(1L<< 6)
end_define

begin_comment
comment|/* If this bit is set, then \{ and \} or { and } serve as interval operators.    If not set, then \{ and \} and { and } are treated as literals.  */
end_comment

begin_define
define|#
directive|define
name|RE_INTERVALS
value|(1L<< 7)
end_define

begin_comment
comment|/* If this bit is not set, then \{ and \} serve as interval operators and       { and } are literals.    If set, then { and } serve as interval operators and \{ and \} are       literals.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_CURLY_BRACES
value|(1L<< 8)
end_define

begin_comment
comment|/* If this bit is set, then character classes are supported; they are:      [:alpha:],	[:upper:], [:lower:],  [:digit:], [:alnum:], [:xdigit:],      [:space:], [:print:], [:punct:], [:graph:], and [:cntrl:].    If not set, then character classes are not supported.  */
end_comment

begin_define
define|#
directive|define
name|RE_CHAR_CLASSES
value|(1L<< 9)
end_define

begin_comment
comment|/* If this bit is set, then the dot re doesn't match a null byte.    If not set, it does.  */
end_comment

begin_define
define|#
directive|define
name|RE_DOT_NOT_NULL
value|(1L<< 10)
end_define

begin_comment
comment|/* If this bit is set, then [^...] doesn't match a newline.    If not set, it does.  */
end_comment

begin_define
define|#
directive|define
name|RE_HAT_NOT_NEWLINE
value|(1L<< 11)
end_define

begin_comment
comment|/* If this bit is set, back references are recognized.    If not set, they aren't.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_REFS
value|(1L<< 12)
end_define

begin_comment
comment|/* If this bit is set, back references must refer to a preceding    subexpression.  If not set, a back reference to a nonexistent    subexpression is treated as literal characters.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_EMPTY_BK_REF
value|(1L<< 13)
end_define

begin_comment
comment|/* If this bit is set, bracket expressions can't be empty.      If it is set, they can be empty.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_EMPTY_BRACKETS
value|(1L<< 14)
end_define

begin_comment
comment|/* If this bit is set, then *, +, ? and { cannot be first in an re or    immediately after a |, or a (.  Furthermore, a | cannot be first or    last in an re, or immediately follow another | or a (.  Also, a ^    cannot appear in a nonleading position and a $ cannot appear in a    nontrailing position (outside of bracket expressions, that is).  */
end_comment

begin_define
define|#
directive|define
name|RE_CONTEXTUAL_INVALID_OPS
value|(1L<< 15)
end_define

begin_comment
comment|/* If this bit is set, then +, ? and | aren't recognized as operators.    If it's not, they are.  */
end_comment

begin_define
define|#
directive|define
name|RE_LIMITED_OPS
value|(1L<< 16)
end_define

begin_comment
comment|/* If this bit is set, then an ending range point has to collate higher      or equal to the starting range point.    If it's not set, then when the ending range point collates higher      than the starting range point, the range is just considered empty.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_EMPTY_RANGES
value|(1L<< 17)
end_define

begin_comment
comment|/* If this bit is set, then a hyphen (-) can't be an ending range point.    If it isn't, then it can.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_HYPHEN_RANGE_END
value|(1L<< 18)
end_define

begin_comment
comment|/* Define combinations of bits for the standard possibilities.  */
end_comment

begin_define
define|#
directive|define
name|RE_SYNTAX_POSIX_AWK
value|(RE_NO_BK_PARENS | RE_NO_BK_VBAR \ 			| RE_CONTEXT_INDEP_OPS)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_AWK
value|(RE_NO_BK_PARENS | RE_NO_BK_VBAR | RE_AWK_CLASS_HACK)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_EGREP
value|(RE_NO_BK_PARENS | RE_NO_BK_VBAR \ 			| RE_CONTEXT_INDEP_OPS | RE_NEWLINE_OR)
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

begin_define
define|#
directive|define
name|RE_SYNTAX_POSIX_BASIC
value|(RE_INTERVALS | RE_BK_PLUS_QM 		\ 			| RE_CHAR_CLASSES | RE_DOT_NOT_NULL 		\                         | RE_HAT_NOT_NEWLINE | RE_NO_EMPTY_BK_REF 	\                         | RE_NO_EMPTY_BRACKETS | RE_LIMITED_OPS		\                         | RE_NO_EMPTY_RANGES | RE_NO_HYPHEN_RANGE_END)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_POSIX_EXTENDED
value|(RE_INTERVALS | RE_NO_BK_CURLY_BRACES	   \ 			| RE_NO_BK_VBAR | RE_NO_BK_PARENS 		   \                         | RE_HAT_NOT_NEWLINE | RE_CHAR_CLASSES 		   \                         | RE_NO_EMPTY_BRACKETS | RE_CONTEXTUAL_INVALID_OPS \                         | RE_NO_BK_REFS | RE_NO_EMPTY_RANGES 		   \                         | RE_NO_HYPHEN_RANGE_END)
end_define

begin_comment
comment|/* This data structure is used to represent a compiled pattern.  */
end_comment

begin_struct
struct|struct
name|re_pattern_buffer
block|{
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* Space holding the compiled pattern commands.  */
name|long
name|allocated
decl_stmt|;
comment|/* Size of space that `buffer' points to. */
name|long
name|used
decl_stmt|;
comment|/* Length of portion of buffer actually occupied  */
name|char
modifier|*
name|fastmap
decl_stmt|;
comment|/* Pointer to fastmap, if any, or zero if none.  */
comment|/* re_search uses the fastmap, if there is one, 			   to skip over totally implausible characters.  */
name|char
modifier|*
name|translate
decl_stmt|;
comment|/* Translate table to apply to all characters before  		           comparing, or zero for no translation. 			   The translation is applied to a pattern when it is                             compiled and to data when it is matched.  */
name|char
name|fastmap_accurate
decl_stmt|;
comment|/* Set to zero when a new pattern is stored, 			   set to one when the fastmap is updated from it.  */
name|char
name|can_be_null
decl_stmt|;
comment|/* Set to one by compiling fastmap 			   if this pattern might match the null string. 			   It does not necessarily match the null string 			   in that case, but if this is zero, it cannot. 			   2 as value means can match null string 			   but at end of range or before a character 			   listed in the fastmap.  */
block|}
struct|;
end_struct

begin_comment
comment|/* search.c (search_buffer) needs this one value.  It is defined both in    regex.c and here.  */
end_comment

begin_define
define|#
directive|define
name|RE_EXACTN_VALUE
value|1
end_define

begin_comment
comment|/* Structure to store register contents data in.     Pass the address of such a structure as an argument to re_match, etc.,    if you want this information back.     For i from 1 to RE_NREGS - 1, start[i] records the starting index in    the string of where the ith subexpression matched, and end[i] records    one after the ending index.  start[0] and end[0] are analogous, for    the entire pattern.  */
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

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|re_compile_pattern
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|re_pattern_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Is this really advertised?  */
end_comment

begin_function_decl
specifier|extern
name|void
name|re_compile_fastmap
parameter_list|(
name|struct
name|re_pattern_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|re_search
parameter_list|(
name|struct
name|re_pattern_buffer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|re_registers
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|re_search_2
parameter_list|(
name|struct
name|re_pattern_buffer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|re_registers
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|re_match
parameter_list|(
name|struct
name|re_pattern_buffer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|re_registers
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|re_match_2
parameter_list|(
name|struct
name|re_pattern_buffer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|re_registers
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|re_set_syntax
parameter_list|(
name|long
name|syntax
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|GAWK
end_ifndef

begin_comment
comment|/* 4.2 bsd compatibility.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|re_comp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|re_exec
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__STDC__ */
end_comment

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

begin_function_decl
specifier|extern
name|long
name|re_set_syntax
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|GAWK
end_ifndef

begin_comment
comment|/* 4.2 bsd compatibility.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__REGEXP_LIBRARY */
end_comment

end_unit

