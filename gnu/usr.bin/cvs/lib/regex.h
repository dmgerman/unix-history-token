begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for data structures and routines for the regular    expression library, version REPLACE-WITH-VERSION.     Copyright (C) 1985, 1989, 1990, 1991, 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__REGEXP_LIBRARY_H__
end_ifndef

begin_define
define|#
directive|define
name|__REGEXP_LIBRARY_H__
end_define

begin_comment
comment|/* POSIX says that<sys/types.h> must be included before<regex.h>.  */
end_comment

begin_comment
comment|/* The following bits are used to determine the regexp syntax we    recognize.  The set/not-set meanings are chosen so that Emacs syntax    remains the value 0.  The bits are given in alphabetical order, and    the definitions shifted by one from the previous bit; thus, when we    add or remove a bit, only one other definition need change.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|reg_syntax_t
typedef|;
end_typedef

begin_comment
comment|/* If this bit is not set, then \ inside a bracket expression is literal.    If set, then such a \ quotes the following character.  */
end_comment

begin_define
define|#
directive|define
name|RE_BACKSLASH_ESCAPE_IN_LISTS
value|(1)
end_define

begin_comment
comment|/* If this bit is not set, then + and ? are operators, and \+ and \? are      literals.     If set, then \+ and \? are operators and + and ? are literals.  */
end_comment

begin_define
define|#
directive|define
name|RE_BK_PLUS_QM
value|(RE_BACKSLASH_ESCAPE_IN_LISTS<< 1)
end_define

begin_comment
comment|/* If this bit is set, then character classes are supported.  They are:      [:alpha:], [:upper:], [:lower:],  [:digit:], [:alnum:], [:xdigit:],      [:space:], [:print:], [:punct:], [:graph:], and [:cntrl:].    If not set, then character classes are not supported.  */
end_comment

begin_define
define|#
directive|define
name|RE_CHAR_CLASSES
value|(RE_BK_PLUS_QM<< 1)
end_define

begin_comment
comment|/* If this bit is set, then ^ and $ are always anchors (outside bracket      expressions).    If this bit is not set, then it depends:         ^  is an anchor if it is at the beginning of a regular            expression or after an open-group or an alternation operator;         $  is an anchor if it is at the end of a regular expression, or            before a close-group or an alternation operator.      This bit could be (re)combined with RE_CONTEXT_INDEP_OPS, because    POSIX now says that the behavior of * etc. in leading positions is    undefined.  We have already implemented a previous draft which    made those constructs invalid, so we may as well not change the code    back.  */
end_comment

begin_define
define|#
directive|define
name|RE_CONTEXT_INDEP_ANCHORS
value|(RE_CHAR_CLASSES<< 1)
end_define

begin_comment
comment|/* If this bit is set, then special characters are always special      regardless of where they are in the pattern.    If this bit is not set, then special characters are special only in      some contexts; otherwise they are ordinary.  Specifically,       * + ? and intervals are only special when not after the beginning,      open-group, or alternation operator.  */
end_comment

begin_define
define|#
directive|define
name|RE_CONTEXT_INDEP_OPS
value|(RE_CONTEXT_INDEP_ANCHORS<< 1)
end_define

begin_comment
comment|/* If this bit is set, then *, +, ?, and { cannot be first in an re or    immediately after an alternation or begin-group operator.    Furthermore, alternation cannot be first or last in an re, or    immediately follow another alternation or begin-group.  */
end_comment

begin_define
define|#
directive|define
name|RE_CONTEXT_INVALID_OPS
value|(RE_CONTEXT_INDEP_OPS<< 1)
end_define

begin_comment
comment|/* If this bit is set, then . matches a newline.    If not set, then it doesn't.  */
end_comment

begin_define
define|#
directive|define
name|RE_DOT_NEWLINE
value|(RE_CONTEXT_INVALID_OPS<< 1)
end_define

begin_comment
comment|/* If this bit is set, then period doesn't match a null.    If not set, then it does.  */
end_comment

begin_define
define|#
directive|define
name|RE_DOT_NOT_NULL
value|(RE_DOT_NEWLINE<< 1)
end_define

begin_comment
comment|/* If this bit is set, nonmatching lists [^...] do not match newline.    If not set, they do.  */
end_comment

begin_define
define|#
directive|define
name|RE_HAT_LISTS_NOT_NEWLINE
value|(RE_DOT_NOT_NULL<< 1)
end_define

begin_comment
comment|/* If this bit is set, either \{...\} or {...} defines an      interval, depending on RE_NO_BK_BRACES.     If not set, \{, \}, {, and } are literals.  */
end_comment

begin_define
define|#
directive|define
name|RE_INTERVALS
value|(RE_HAT_LISTS_NOT_NEWLINE<< 1)
end_define

begin_comment
comment|/* If this bit is set,  +, ? and | aren't recognized as operators.    If not set, they are.  */
end_comment

begin_define
define|#
directive|define
name|RE_LIMITED_OPS
value|(RE_INTERVALS<< 1)
end_define

begin_comment
comment|/* If this bit is set, newline is an alternation operator.    If not set, newline is literal.  */
end_comment

begin_define
define|#
directive|define
name|RE_NEWLINE_ALT
value|(RE_LIMITED_OPS<< 1)
end_define

begin_comment
comment|/* If this bit is set, newline in the pattern is an ordinary character.    If not set, newline before ^ or after $ allows the ^ or $ to be an      anchor.  */
end_comment

begin_define
define|#
directive|define
name|RE_NEWLINE_ORDINARY
value|(RE_NEWLINE_ALT<< 1)
end_define

begin_comment
comment|/* If this bit is not set, then \{ and \} defines an interval,      and { and } are literals.    If set, then { and } defines an interval, and \{ and \} are literals.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_BRACES
value|(RE_NEWLINE_ORDINARY<< 1)
end_define

begin_comment
comment|/* If this bit is set, (...) defines a group, and \( and \) are literals.    If not set, \(...\) defines a group, and ( and ) are literals.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_PARENS
value|(RE_NO_BK_BRACES<< 1)
end_define

begin_comment
comment|/* If this bit is set, then back references (i.e., \<digit>) are not      recognized.    If not set, then they are.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_REFS
value|(RE_NO_BK_PARENS<< 1)
end_define

begin_comment
comment|/* If this bit is set, then | is an alternation operator, and \| is literal.     If not set, then \| is an alternation operator, and | is literal.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_VBAR
value|(RE_NO_BK_REFS<< 1)
end_define

begin_comment
comment|/* If this bit is set, then you can't have empty alternatives.    If not set, then you can.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_EMPTY_ALTS
value|(RE_NO_BK_VBAR<< 1)
end_define

begin_comment
comment|/* If this bit is set, then you can't have empty groups.    If not set, then you can.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_EMPTY_GROUPS
value|(RE_NO_EMPTY_ALTS<< 1)
end_define

begin_comment
comment|/* If this bit is set, then an ending range point has to collate higher      than or equal to the starting range point.    If not set, then when the ending range point collates higher than the      starting range point, we consider such a range to be empty.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_EMPTY_RANGES
value|(RE_NO_EMPTY_GROUPS<< 1)
end_define

begin_comment
comment|/* If this bit is set, then all back references must refer to a preceding      subexpression.    If not set, then a back reference to a nonexistent subexpression is      treated as literal characters.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_MISSING_BK_REF
value|(RE_NO_EMPTY_RANGES<< 1)
end_define

begin_comment
comment|/* If this bit is set, then Regex considers an unmatched close-group      operator to be the ordinary character parenthesis.    If not set, then an unmatched close-group operator is invalid.  */
end_comment

begin_define
define|#
directive|define
name|RE_UNMATCHED_RIGHT_PAREN_ORD
value|(RE_NO_MISSING_BK_REF<< 1)
end_define

begin_comment
comment|/* This global variable defines the particular regexp syntax to use (for    some interfaces).  When a regexp is compiled, the syntax used is    stored in the pattern buffer, so changing this does not affect    already-compiled regexps.  */
end_comment

begin_decl_stmt
specifier|extern
name|reg_syntax_t
name|obscure_syntax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define combinations of the above bits for the standard possibilities.    (The [[[ comments delimit what gets put into the Texinfo file.) */
end_comment

begin_comment
comment|/* [[[begin syntaxes]]] */
end_comment

begin_define
define|#
directive|define
name|RE_SYNTAX_EMACS
value|0
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_POSIX_AWK
define|\
value|(RE_CONTEXT_INDEP_ANCHORS | RE_CONTEXT_INDEP_OPS | RE_NO_BK_PARENS	\    | RE_NO_BK_VBAR)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_AWK
define|\
value|(RE_BACKSLASH_ESCAPE_IN_LISTS | RE_SYNTAX_POSIX_AWK)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_GREP
define|\
value|(RE_BK_PLUS_QM | RE_NEWLINE_ALT)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_EGREP
define|\
value|(RE_CONTEXT_INDEP_ANCHORS | RE_CONTEXT_INDEP_OPS			\    | RE_NEWLINE_ALT | RE_NO_BK_PARENS | RE_NO_BK_VBAR)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_POSIX_BASIC
define|\
value|(RE_CHAR_CLASSES | RE_DOT_NEWLINE					\    | RE_DOT_NOT_NULL | RE_INTERVALS | RE_LIMITED_OPS			\    | RE_NEWLINE_ORDINARY | RE_NO_EMPTY_RANGES | RE_NO_MISSING_BK_REF)
end_define

begin_define
define|#
directive|define
name|RE_SYNTAX_POSIX_EXTENDED
define|\
value|(RE_CHAR_CLASSES | RE_CONTEXT_INDEP_ANCHORS				\    | RE_CONTEXT_INVALID_OPS | RE_DOT_NEWLINE | RE_DOT_NOT_NULL		\    | RE_INTERVALS | RE_NEWLINE_ORDINARY | RE_NO_BK_BRACES		\    | RE_NO_BK_PARENS | RE_NO_BK_REFS | RE_NO_BK_VBAR			\    | RE_NO_EMPTY_ALTS | RE_NO_EMPTY_GROUPS | RE_NO_EMPTY_RANGES		\    | RE_UNMATCHED_RIGHT_PAREN_ORD)
end_define

begin_comment
comment|/* [[[end syntaxes]]] */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Maximum number of duplicates an interval can allow.  */
end_comment

begin_undef
undef|#
directive|undef
name|RE_DUP_MAX
end_undef

begin_define
define|#
directive|define
name|RE_DUP_MAX
value|((1<< 15) - 1)
end_define

begin_comment
comment|/* POSIX `cflags' bits (i.e., information for regcomp).  */
end_comment

begin_comment
comment|/* If this bit is set, then use extended regular expression syntax.    If not set, then use basic regular expression syntax.  */
end_comment

begin_define
define|#
directive|define
name|REG_EXTENDED
value|1
end_define

begin_comment
comment|/* If this bit is set, then ignore case when matching.    If not set, then case is significant.  */
end_comment

begin_define
define|#
directive|define
name|REG_ICASE
value|(REG_EXTENDED<< 1)
end_define

begin_comment
comment|/* If this bit is set, then anchors do not match at newline      characters in the string.    If not set, then anchors do match at newlines.  */
end_comment

begin_define
define|#
directive|define
name|REG_NEWLINE
value|(REG_ICASE<< 1)
end_define

begin_comment
comment|/* If this bit is set, then report only success or fail in regexec.    If not set, then returns differ between not matching and errors.  */
end_comment

begin_define
define|#
directive|define
name|REG_NOSUB
value|(REG_NEWLINE<< 1)
end_define

begin_comment
comment|/* POSIX `eflags' bits (i.e., information for regexec).  */
end_comment

begin_comment
comment|/* If this bit is set, then the beginning-of-line operator doesn't match      the beginning of the string (presumably because it's not the      beginning of a line).    If not set, then the beginning-of-line operator does match the      beginning of the string.  */
end_comment

begin_define
define|#
directive|define
name|REG_NOTBOL
value|1
end_define

begin_comment
comment|/* Like REG_NOTBOL, except for the end-of-line.  */
end_comment

begin_define
define|#
directive|define
name|REG_NOTEOL
value|(1<< 1)
end_define

begin_comment
comment|/* If any error codes are removed, changed, or added, update the    `re_error_msg' table in regex.c.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|REG_NOERROR
init|=
literal|0
block|,
comment|/* Success.  */
name|REG_NOMATCH
block|,
comment|/* Didn't find a match (for regexec).  */
comment|/* POSIX regcomp return error codes.  (In the order listed in the      standard.)  */
name|REG_BADPAT
block|,
comment|/* Invalid pattern.  */
name|REG_ECOLLATE
block|,
comment|/* Not implemented.  */
name|REG_ECTYPE
block|,
comment|/* Invalid character class name.  */
name|REG_EESCAPE
block|,
comment|/* Trailing backslash.  */
name|REG_ESUBREG
block|,
comment|/* Invalid back reference.  */
name|REG_EBRACK
block|,
comment|/* Unmatched left bracket.  */
name|REG_EPAREN
block|,
comment|/* Parenthesis imbalance.  */
name|REG_EBRACE
block|,
comment|/* Unmatched \{.  */
name|REG_BADBR
block|,
comment|/* Invalid contents of \{\}.  */
name|REG_ERANGE
block|,
comment|/* Invalid range end.  */
name|REG_ESPACE
block|,
comment|/* Ran out of memory.  */
name|REG_BADRPT
block|,
comment|/* No preceding re for repetition op.  */
comment|/* Error codes we've added.  */
name|REG_EEND
block|,
comment|/* Premature end.  */
name|REG_ESIZE
block|,
comment|/* Compiled pattern bigger than 2^16 bytes.  */
name|REG_ERPAREN
comment|/* Unmatched ) or \); not returned from regcomp.  */
block|}
name|reg_errcode_t
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* This data structure represents a compiled pattern.  Before calling    the pattern compiler, the fields `buffer', `allocated', `fastmap',    `translate', and `no_sub' can be set.  After the pattern has been    compiled, the `re_nsub' field is available.  All other fields are    private to the regex routines.  */
end_comment

begin_struct
struct|struct
name|re_pattern_buffer
block|{
comment|/* [[[begin pattern_buffer]]] */
comment|/* Space that holds the compiled pattern.  It is declared as           `unsigned char *' because its elements are            sometimes used as array indexes.  */
name|unsigned
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* Number of bytes to which `buffer' points.  */
name|unsigned
name|long
name|allocated
decl_stmt|;
comment|/* Number of bytes actually used in `buffer'.  */
name|unsigned
name|long
name|used
decl_stmt|;
comment|/* Syntax setting with which the pattern was compiled.  */
name|reg_syntax_t
name|syntax
decl_stmt|;
comment|/* Pointer to a fastmap, if any, otherwise zero.  re_search uses            the fastmap, if there is one, to skip over impossible            starting points for matches.  */
name|char
modifier|*
name|fastmap
decl_stmt|;
comment|/* Either a translate table to apply to all characters before            comparing them, or zero for no translation.  The translation            is applied to a pattern when it is compiled and to a string            when it is matched.  */
name|char
modifier|*
name|translate
decl_stmt|;
comment|/* Number of subexpressions found by the compiler.  */
name|size_t
name|re_nsub
decl_stmt|;
comment|/* Set to 1 by re_compile_fastmap if this pattern can match the            null string; 0 prevents the searcher from matching it with            the null string.  Set to 2 if it might match the null string            either at the end of a search range or just before a            character listed in the fastmap.  */
name|unsigned
name|can_be_null
range|:
literal|2
decl_stmt|;
comment|/* Set to zero when regex_compile compiles a pattern; set to one            by re_compile_fastmap when it updates the fastmap, if any.  */
name|unsigned
name|fastmap_accurate
range|:
literal|1
decl_stmt|;
comment|/* If set, regexec reports only success or failure and does not            return anything in pmatch.  */
name|unsigned
name|no_sub
range|:
literal|1
decl_stmt|;
comment|/* If set, a beginning-of-line anchor doesn't match at the            beginning of the string.  */
name|unsigned
name|not_bol
range|:
literal|1
decl_stmt|;
comment|/* Similarly for an end-of-line anchor.  */
name|unsigned
name|not_eol
range|:
literal|1
decl_stmt|;
comment|/* If true, an anchor at a newline matches.  */
name|unsigned
name|newline_anchor
range|:
literal|1
decl_stmt|;
comment|/* If set, re_match_2 assumes a non-null REGS argument is            initialized.  If not set, REGS is initialized to the max of            RE_NREGS and re_nsub + 1 registers.  */
name|unsigned
name|caller_allocated_regs
range|:
literal|1
decl_stmt|;
comment|/* [[[end pattern_buffer]]] */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|re_pattern_buffer
name|regex_t
typedef|;
end_typedef

begin_comment
comment|/* search.c (search_buffer) in Emacs needs this one opcode value.  It is    defined both in `regex.c' and here.  */
end_comment

begin_define
define|#
directive|define
name|RE_EXACTN_VALUE
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Type for byte offsets within the string.  POSIX mandates us defining    this.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|regoff_t
typedef|;
end_typedef

begin_comment
comment|/* This is the structure we store register match data in.  See    regex.texinfo for a full description of what registers match.  */
end_comment

begin_struct
struct|struct
name|re_registers
block|{
name|unsigned
name|num_regs
decl_stmt|;
name|regoff_t
modifier|*
name|start
decl_stmt|;
name|regoff_t
modifier|*
name|end
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* If `caller_allocated_regs' is zero in the pattern buffer, re_match_2    returns information about this many registers.  */
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
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX specification for registers.  Aside from the different names than    `re_registers', POSIX uses an array of structures, instead of a    structure of arrays.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|regoff_t
name|rm_so
decl_stmt|;
comment|/* Byte offset from string's start to substring's start.  */
name|regoff_t
name|rm_eo
decl_stmt|;
comment|/* Byte offset from string's start to substring's end.  */
block|}
name|regmatch_t
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Declarations for routines.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_comment
comment|/* Sets the current syntax to SYNTAX.  You can also simply assign to the    `obscure_syntax' variable.  */
end_comment

begin_function_decl
specifier|extern
name|reg_syntax_t
name|re_set_syntax
parameter_list|(
name|reg_syntax_t
name|syntax
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compile the regular expression PATTERN, with length LENGTH    and syntax given by the global `obscure_syntax', into the buffer    BUFFER.  Return NULL if successful, and an error string if not.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|re_compile_pattern
parameter_list|(
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
name|int
name|length
parameter_list|,
name|struct
name|re_pattern_buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compile a fastmap for the compiled pattern in BUFFER; used to    accelerate searches.  Return 0 if successful and -2 if was an    internal error.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|re_compile_fastmap
parameter_list|(
name|struct
name|re_pattern_buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Search in the string STRING (with length LENGTH) for the pattern    compiled into BUFFER.  Start searching at position START, for RANGE    characters.  Return the starting position of the match, -1 for no    match, or -2 for an internal error.  Also return register    information in REGS (if REGS and BUFFER->no_sub are nonzero).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|re_search
parameter_list|(
name|struct
name|re_pattern_buffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|range
parameter_list|,
name|struct
name|re_registers
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like `re_search', but search in the concatenation of STRING1 and    STRING2.  Also, stop searching at index START + STOP.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|re_search_2
parameter_list|(
name|struct
name|re_pattern_buffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|string1
parameter_list|,
name|int
name|length1
parameter_list|,
specifier|const
name|char
modifier|*
name|string2
parameter_list|,
name|int
name|length2
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|range
parameter_list|,
name|struct
name|re_registers
modifier|*
name|regs
parameter_list|,
name|int
name|stop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like `re_search', but return how many characters in STRING the regexp    in BUFFER matched, starting at position START.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|re_match
parameter_list|(
specifier|const
name|struct
name|re_pattern_buffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|start
parameter_list|,
name|struct
name|re_registers
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Relates to `re_match' as `re_search_2' relates to `re_search'.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|re_match_2
parameter_list|(
specifier|const
name|struct
name|re_pattern_buffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|string1
parameter_list|,
name|int
name|length1
parameter_list|,
specifier|const
name|char
modifier|*
name|string2
parameter_list|,
name|int
name|length2
parameter_list|,
name|int
name|start
parameter_list|,
name|struct
name|re_registers
modifier|*
name|regs
parameter_list|,
name|int
name|stop
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_comment
comment|/* 4.2 bsd compatibility.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|bsdi
end_ifndef

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|re_comp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|re_exec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX compatibility.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|regcomp
parameter_list|(
name|regex_t
modifier|*
name|preg
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
name|int
name|cflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|regexec
parameter_list|(
specifier|const
name|regex_t
modifier|*
name|preg
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|size_t
name|nmatch
parameter_list|,
name|regmatch_t
name|pmatch
index|[]
parameter_list|,
name|int
name|eflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|regerror
parameter_list|(
name|int
name|errcode
parameter_list|,
specifier|const
name|regex_t
modifier|*
name|preg
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|size_t
name|errbuf_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regfree
parameter_list|(
name|regex_t
modifier|*
name|preg
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_comment
comment|/* Support old C compilers.  */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_function_decl
specifier|extern
name|reg_syntax_t
name|re_set_syntax
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|re_compile_pattern
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
comment|/* 4.2 BSD compatibility.  */
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

begin_comment
comment|/* POSIX compatibility.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|regcomp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|regexec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|regerror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|regfree
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __REGEXP_LIBRARY_H__ */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Local variables: make-backup-files: t version-control: t trim-versions-without-asking: nil End: */
end_comment

end_unit

