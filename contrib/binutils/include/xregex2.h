begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for data structures and routines for the regular    expression library, version 0.12.    Copyright (C) 1985,1989-1993,1995-1998, 2000 Free Software Foundation, Inc.    This file is part of the GNU C Library.  Its master source is NOT part of    the C library, however.  The master source lives in /gd/gnu/lib.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA    02111-1307 USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REGEX_H
end_ifndef

begin_define
define|#
directive|define
name|_REGEX_H
value|1
end_define

begin_comment
comment|/* Allow the use in C++ code.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* POSIX says that<sys/types.h> must be included (by the caller) before<regex.h>.  */
if|#
directive|if
operator|!
name|defined
name|_POSIX_C_SOURCE
operator|&&
operator|!
name|defined
name|_POSIX_SOURCE
operator|&&
name|defined
name|VMS
comment|/* VMS doesn't have `size_t' in<sys/types.h>, even though POSIX says it    should be there.  */
include|#
directive|include
file|<stddef.h>
endif|#
directive|endif
comment|/* The following two types have to be signed and unsigned integer type    wide enough to hold a value of a pointer.  For most ANSI compilers    ptrdiff_t and size_t should be likely OK.  Still size of these two    types is 2 for Microsoft C.  Ugh... */
typedef|typedef
name|long
name|int
name|s_reg_t
typedef|;
typedef|typedef
name|unsigned
name|long
name|int
name|active_reg_t
typedef|;
comment|/* The following bits are used to determine the regexp syntax we    recognize.  The set/not-set meanings are chosen so that Emacs syntax    remains the value 0.  The bits are given in alphabetical order, and    the definitions shifted by one from the previous bit; thus, when we    add or remove a bit, only one other definition need change.  */
typedef|typedef
name|unsigned
name|long
name|int
name|reg_syntax_t
typedef|;
comment|/* If this bit is not set, then \ inside a bracket expression is literal.    If set, then such a \ quotes the following character.  */
define|#
directive|define
name|RE_BACKSLASH_ESCAPE_IN_LISTS
value|((unsigned long int) 1)
comment|/* If this bit is not set, then + and ? are operators, and \+ and \? are      literals.    If set, then \+ and \? are operators and + and ? are literals.  */
define|#
directive|define
name|RE_BK_PLUS_QM
value|(RE_BACKSLASH_ESCAPE_IN_LISTS<< 1)
comment|/* If this bit is set, then character classes are supported.  They are:      [:alpha:], [:upper:], [:lower:],  [:digit:], [:alnum:], [:xdigit:],      [:space:], [:print:], [:punct:], [:graph:], and [:cntrl:].    If not set, then character classes are not supported.  */
define|#
directive|define
name|RE_CHAR_CLASSES
value|(RE_BK_PLUS_QM<< 1)
comment|/* If this bit is set, then ^ and $ are always anchors (outside bracket      expressions, of course).    If this bit is not set, then it depends:         ^  is an anchor if it is at the beginning of a regular            expression or after an open-group or an alternation operator;         $  is an anchor if it is at the end of a regular expression, or            before a close-group or an alternation operator.     This bit could be (re)combined with RE_CONTEXT_INDEP_OPS, because    POSIX draft 11.2 says that * etc. in leading positions is undefined.    We already implemented a previous draft which made those constructs    invalid, though, so we haven't changed the code back.  */
define|#
directive|define
name|RE_CONTEXT_INDEP_ANCHORS
value|(RE_CHAR_CLASSES<< 1)
comment|/* If this bit is set, then special characters are always special      regardless of where they are in the pattern.    If this bit is not set, then special characters are special only in      some contexts; otherwise they are ordinary.  Specifically,      * + ? and intervals are only special when not after the beginning,      open-group, or alternation operator.  */
define|#
directive|define
name|RE_CONTEXT_INDEP_OPS
value|(RE_CONTEXT_INDEP_ANCHORS<< 1)
comment|/* If this bit is set, then *, +, ?, and { cannot be first in an re or      immediately after an alternation or begin-group operator.  */
define|#
directive|define
name|RE_CONTEXT_INVALID_OPS
value|(RE_CONTEXT_INDEP_OPS<< 1)
comment|/* If this bit is set, then . matches newline.    If not set, then it doesn't.  */
define|#
directive|define
name|RE_DOT_NEWLINE
value|(RE_CONTEXT_INVALID_OPS<< 1)
comment|/* If this bit is set, then . doesn't match NUL.    If not set, then it does.  */
define|#
directive|define
name|RE_DOT_NOT_NULL
value|(RE_DOT_NEWLINE<< 1)
comment|/* If this bit is set, nonmatching lists [^...] do not match newline.    If not set, they do.  */
define|#
directive|define
name|RE_HAT_LISTS_NOT_NEWLINE
value|(RE_DOT_NOT_NULL<< 1)
comment|/* If this bit is set, either \{...\} or {...} defines an      interval, depending on RE_NO_BK_BRACES.    If not set, \{, \}, {, and } are literals.  */
define|#
directive|define
name|RE_INTERVALS
value|(RE_HAT_LISTS_NOT_NEWLINE<< 1)
comment|/* If this bit is set, +, ? and | aren't recognized as operators.    If not set, they are.  */
define|#
directive|define
name|RE_LIMITED_OPS
value|(RE_INTERVALS<< 1)
comment|/* If this bit is set, newline is an alternation operator.    If not set, newline is literal.  */
define|#
directive|define
name|RE_NEWLINE_ALT
value|(RE_LIMITED_OPS<< 1)
comment|/* If this bit is set, then `{...}' defines an interval, and \{ and \}      are literals.   If not set, then `\{...\}' defines an interval.  */
define|#
directive|define
name|RE_NO_BK_BRACES
value|(RE_NEWLINE_ALT<< 1)
comment|/* If this bit is set, (...) defines a group, and \( and \) are literals.    If not set, \(...\) defines a group, and ( and ) are literals.  */
define|#
directive|define
name|RE_NO_BK_PARENS
value|(RE_NO_BK_BRACES<< 1)
comment|/* If this bit is set, then \<digit> matches<digit>.    If not set, then \<digit> is a back-reference.  */
define|#
directive|define
name|RE_NO_BK_REFS
value|(RE_NO_BK_PARENS<< 1)
comment|/* If this bit is set, then | is an alternation operator, and \| is literal.    If not set, then \| is an alternation operator, and | is literal.  */
define|#
directive|define
name|RE_NO_BK_VBAR
value|(RE_NO_BK_REFS<< 1)
comment|/* If this bit is set, then an ending range point collating higher      than the starting range point, as in [z-a], is invalid.    If not set, then when ending range point collates higher than the      starting range point, the range is ignored.  */
define|#
directive|define
name|RE_NO_EMPTY_RANGES
value|(RE_NO_BK_VBAR<< 1)
comment|/* If this bit is set, then an unmatched ) is ordinary.    If not set, then an unmatched ) is invalid.  */
define|#
directive|define
name|RE_UNMATCHED_RIGHT_PAREN_ORD
value|(RE_NO_EMPTY_RANGES<< 1)
comment|/* If this bit is set, succeed as soon as we match the whole pattern,    without further backtracking.  */
define|#
directive|define
name|RE_NO_POSIX_BACKTRACKING
value|(RE_UNMATCHED_RIGHT_PAREN_ORD<< 1)
comment|/* If this bit is set, do not process the GNU regex operators.    If not set, then the GNU regex operators are recognized. */
define|#
directive|define
name|RE_NO_GNU_OPS
value|(RE_NO_POSIX_BACKTRACKING<< 1)
comment|/* If this bit is set, turn on internal regex debugging.    If not set, and debugging was on, turn it off.    This only works if regex.c is compiled -DDEBUG.    We define this bit always, so that all that's needed to turn on    debugging is to recompile regex.c; the calling code can always have    this bit set, and it won't affect anything in the normal case. */
define|#
directive|define
name|RE_DEBUG
value|(RE_NO_GNU_OPS<< 1)
comment|/* If this bit is set, a syntactically invalid interval is treated as    a string of ordinary characters.  For example, the ERE 'a{1' is    treated as 'a\{1'.  */
define|#
directive|define
name|RE_INVALID_INTERVAL_ORD
value|(RE_DEBUG<< 1)
comment|/* This global variable defines the particular regexp syntax to use (for    some interfaces).  When a regexp is compiled, the syntax used is    stored in the pattern buffer, so changing this does not affect    already-compiled regexps.  */
specifier|extern
name|reg_syntax_t
name|re_syntax_options
decl_stmt|;
comment|/* Define combinations of the above bits for the standard possibilities.    (The [[[ comments delimit what gets put into the Texinfo file, so    don't delete them!)  */
comment|/* [[[begin syntaxes]]] */
define|#
directive|define
name|RE_SYNTAX_EMACS
value|0
define|#
directive|define
name|RE_SYNTAX_AWK
define|\
value|(RE_BACKSLASH_ESCAPE_IN_LISTS   | RE_DOT_NOT_NULL			\    | RE_NO_BK_PARENS              | RE_NO_BK_REFS			\    | RE_NO_BK_VBAR                | RE_NO_EMPTY_RANGES			\    | RE_DOT_NEWLINE		  | RE_CONTEXT_INDEP_ANCHORS		\    | RE_UNMATCHED_RIGHT_PAREN_ORD | RE_NO_GNU_OPS)
define|#
directive|define
name|RE_SYNTAX_GNU_AWK
define|\
value|((RE_SYNTAX_POSIX_EXTENDED | RE_BACKSLASH_ESCAPE_IN_LISTS | RE_DEBUG)	\& ~(RE_DOT_NOT_NULL | RE_INTERVALS | RE_CONTEXT_INDEP_OPS))
define|#
directive|define
name|RE_SYNTAX_POSIX_AWK
define|\
value|(RE_SYNTAX_POSIX_EXTENDED | RE_BACKSLASH_ESCAPE_IN_LISTS		\    | RE_INTERVALS	    | RE_NO_GNU_OPS)
define|#
directive|define
name|RE_SYNTAX_GREP
define|\
value|(RE_BK_PLUS_QM              | RE_CHAR_CLASSES				\    | RE_HAT_LISTS_NOT_NEWLINE | RE_INTERVALS				\    | RE_NEWLINE_ALT)
define|#
directive|define
name|RE_SYNTAX_EGREP
define|\
value|(RE_CHAR_CLASSES        | RE_CONTEXT_INDEP_ANCHORS			\    | RE_CONTEXT_INDEP_OPS | RE_HAT_LISTS_NOT_NEWLINE			\    | RE_NEWLINE_ALT       | RE_NO_BK_PARENS				\    | RE_NO_BK_VBAR)
define|#
directive|define
name|RE_SYNTAX_POSIX_EGREP
define|\
value|(RE_SYNTAX_EGREP | RE_INTERVALS | RE_NO_BK_BRACES			\    | RE_INVALID_INTERVAL_ORD)
comment|/* P1003.2/D11.2, section 4.20.7.1, lines 5078ff.  */
define|#
directive|define
name|RE_SYNTAX_ED
value|RE_SYNTAX_POSIX_BASIC
define|#
directive|define
name|RE_SYNTAX_SED
value|RE_SYNTAX_POSIX_BASIC
comment|/* Syntax bits common to both basic and extended POSIX regex syntax.  */
define|#
directive|define
name|_RE_SYNTAX_POSIX_COMMON
define|\
value|(RE_CHAR_CLASSES | RE_DOT_NEWLINE      | RE_DOT_NOT_NULL		\    | RE_INTERVALS  | RE_NO_EMPTY_RANGES)
define|#
directive|define
name|RE_SYNTAX_POSIX_BASIC
define|\
value|(_RE_SYNTAX_POSIX_COMMON | RE_BK_PLUS_QM)
comment|/* Differs from ..._POSIX_BASIC only in that RE_BK_PLUS_QM becomes    RE_LIMITED_OPS, i.e., \? \+ \| are not recognized.  Actually, this    isn't minimal, since other operators, such as \`, aren't disabled.  */
define|#
directive|define
name|RE_SYNTAX_POSIX_MINIMAL_BASIC
define|\
value|(_RE_SYNTAX_POSIX_COMMON | RE_LIMITED_OPS)
define|#
directive|define
name|RE_SYNTAX_POSIX_EXTENDED
define|\
value|(_RE_SYNTAX_POSIX_COMMON  | RE_CONTEXT_INDEP_ANCHORS			\    | RE_CONTEXT_INDEP_OPS   | RE_NO_BK_BRACES				\    | RE_NO_BK_PARENS        | RE_NO_BK_VBAR				\    | RE_CONTEXT_INVALID_OPS | RE_UNMATCHED_RIGHT_PAREN_ORD)
comment|/* Differs from ..._POSIX_EXTENDED in that RE_CONTEXT_INDEP_OPS is    removed and RE_NO_BK_REFS is added.  */
define|#
directive|define
name|RE_SYNTAX_POSIX_MINIMAL_EXTENDED
define|\
value|(_RE_SYNTAX_POSIX_COMMON  | RE_CONTEXT_INDEP_ANCHORS			\    | RE_CONTEXT_INVALID_OPS | RE_NO_BK_BRACES				\    | RE_NO_BK_PARENS        | RE_NO_BK_REFS				\    | RE_NO_BK_VBAR	    | RE_UNMATCHED_RIGHT_PAREN_ORD)
comment|/* [[[end syntaxes]]] */
comment|/* Maximum number of duplicates an interval can allow.  Some systems    (erroneously) define this in other header files, but we want our    value, so remove any previous define.  */
ifdef|#
directive|ifdef
name|RE_DUP_MAX
undef|#
directive|undef
name|RE_DUP_MAX
endif|#
directive|endif
comment|/* If sizeof(int) == 2, then ((1<< 15) - 1) overflows.  */
define|#
directive|define
name|RE_DUP_MAX
value|(0x7fff)
comment|/* POSIX `cflags' bits (i.e., information for `regcomp').  */
comment|/* If this bit is set, then use extended regular expression syntax.    If not set, then use basic regular expression syntax.  */
define|#
directive|define
name|REG_EXTENDED
value|1
comment|/* If this bit is set, then ignore case when matching.    If not set, then case is significant.  */
define|#
directive|define
name|REG_ICASE
value|(REG_EXTENDED<< 1)
comment|/* If this bit is set, then anchors do not match at newline      characters in the string.    If not set, then anchors do match at newlines.  */
define|#
directive|define
name|REG_NEWLINE
value|(REG_ICASE<< 1)
comment|/* If this bit is set, then report only success or fail in regexec.    If not set, then returns differ between not matching and errors.  */
define|#
directive|define
name|REG_NOSUB
value|(REG_NEWLINE<< 1)
comment|/* POSIX `eflags' bits (i.e., information for regexec).  */
comment|/* If this bit is set, then the beginning-of-line operator doesn't match      the beginning of the string (presumably because it's not the      beginning of a line).    If not set, then the beginning-of-line operator does match the      beginning of the string.  */
define|#
directive|define
name|REG_NOTBOL
value|1
comment|/* Like REG_NOTBOL, except for the end-of-line.  */
define|#
directive|define
name|REG_NOTEOL
value|(1<< 1)
comment|/* If any error codes are removed, changed, or added, update the    `re_error_msg' table in regex.c.  */
typedef|typedef
enum|enum
block|{
ifdef|#
directive|ifdef
name|_XOPEN_SOURCE
name|REG_ENOSYS
init|=
operator|-
literal|1
block|,
comment|/* This will never happen for this implementation.  */
endif|#
directive|endif
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
comment|/* This data structure represents a compiled pattern.  Before calling    the pattern compiler, the fields `buffer', `allocated', `fastmap',    `translate', and `no_sub' can be set.  After the pattern has been    compiled, the `re_nsub' field is available.  All other fields are    private to the regex routines.  */
ifndef|#
directive|ifndef
name|RE_TRANSLATE_TYPE
define|#
directive|define
name|RE_TRANSLATE_TYPE
value|char *
endif|#
directive|endif
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
name|int
name|allocated
decl_stmt|;
comment|/* Number of bytes actually used in `buffer'.  */
name|unsigned
name|long
name|int
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
name|RE_TRANSLATE_TYPE
name|translate
decl_stmt|;
comment|/* Number of subexpressions found by the compiler.  */
name|size_t
name|re_nsub
decl_stmt|;
comment|/* Zero if this pattern cannot match the empty string, one else.            Well, in truth it's used only in `re_search_2', to see            whether or not we should use the fastmap, so we don't set            this absolutely perfectly; see `re_compile_fastmap' (the            `duplicate' case).  */
name|unsigned
name|can_be_null
range|:
literal|1
decl_stmt|;
comment|/* If REGS_UNALLOCATED, allocate space in the `regs' structure              for `max (RE_NREGS, re_nsub + 1)' groups.            If REGS_REALLOCATE, reallocate space if necessary.            If REGS_FIXED, use what's there.  */
define|#
directive|define
name|REGS_UNALLOCATED
value|0
define|#
directive|define
name|REGS_REALLOCATE
value|1
define|#
directive|define
name|REGS_FIXED
value|2
name|unsigned
name|regs_allocated
range|:
literal|2
decl_stmt|;
comment|/* Set to zero when `regex_compile' compiles a pattern; set to one            by `re_compile_fastmap' if it updates the fastmap.  */
name|unsigned
name|fastmap_accurate
range|:
literal|1
decl_stmt|;
comment|/* If set, `re_match_2' does not return information about            subexpressions.  */
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
comment|/* [[[end pattern_buffer]]] */
block|}
struct|;
typedef|typedef
name|struct
name|re_pattern_buffer
name|regex_t
typedef|;
comment|/* Type for byte offsets within the string.  POSIX mandates this.  */
typedef|typedef
name|int
name|regoff_t
typedef|;
comment|/* This is the structure we store register match data in.  See    regex.texinfo for a full description of what registers match.  */
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
comment|/* If `regs_allocated' is REGS_UNALLOCATED in the pattern buffer,    `re_match_2' returns information about at least this many registers    the first time a `regs' structure is passed.  */
ifndef|#
directive|ifndef
name|RE_NREGS
define|#
directive|define
name|RE_NREGS
value|30
endif|#
directive|endif
comment|/* POSIX specification for registers.  Aside from the different names than    `re_registers', POSIX uses an array of structures, instead of a    structure of arrays.  */
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
comment|/* Declarations for routines.  */
comment|/* To avoid duplicating every routine declaration -- once with a    prototype (if we are ANSI), and once without (if we aren't) -- we    use the following macro to declare argument types.  This    unfortunately clutters up the declarations a bit, but I think it's    worth it.  */
if|#
directive|if
name|__STDC__
define|#
directive|define
name|_RE_ARGS
parameter_list|(
name|args
parameter_list|)
value|args
else|#
directive|else
comment|/* not __STDC__ */
define|#
directive|define
name|_RE_ARGS
parameter_list|(
name|args
parameter_list|)
value|()
endif|#
directive|endif
comment|/* not __STDC__ */
comment|/* Sets the current default syntax to SYNTAX, and return the old syntax.    You can also simply assign to the `re_syntax_options' variable.  */
specifier|extern
name|reg_syntax_t
name|re_set_syntax
name|_RE_ARGS
argument_list|(
operator|(
name|reg_syntax_t
name|syntax
operator|)
argument_list|)
decl_stmt|;
comment|/* Compile the regular expression PATTERN, with length LENGTH    and syntax given by the global `re_syntax_options', into the buffer    BUFFER.  Return NULL if successful, and an error string if not.  */
specifier|extern
specifier|const
name|char
modifier|*
name|re_compile_pattern
name|_RE_ARGS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|pattern
operator|,
name|size_t
name|length
operator|,
expr|struct
name|re_pattern_buffer
operator|*
name|buffer
operator|)
argument_list|)
decl_stmt|;
comment|/* Compile a fastmap for the compiled pattern in BUFFER; used to    accelerate searches.  Return 0 if successful and -2 if was an    internal error.  */
specifier|extern
name|int
name|re_compile_fastmap
name|_RE_ARGS
argument_list|(
operator|(
expr|struct
name|re_pattern_buffer
operator|*
name|buffer
operator|)
argument_list|)
decl_stmt|;
comment|/* Search in the string STRING (with length LENGTH) for the pattern    compiled into BUFFER.  Start searching at position START, for RANGE    characters.  Return the starting position of the match, -1 for no    match, or -2 for an internal error.  Also return register    information in REGS (if REGS and BUFFER->no_sub are nonzero).  */
specifier|extern
name|int
name|re_search
name|_RE_ARGS
argument_list|(
operator|(
expr|struct
name|re_pattern_buffer
operator|*
name|buffer
operator|,
specifier|const
name|char
operator|*
name|string
operator|,
name|int
name|length
operator|,
name|int
name|start
operator|,
name|int
name|range
operator|,
expr|struct
name|re_registers
operator|*
name|regs
operator|)
argument_list|)
decl_stmt|;
comment|/* Like `re_search', but search in the concatenation of STRING1 and    STRING2.  Also, stop searching at index START + STOP.  */
specifier|extern
name|int
name|re_search_2
name|_RE_ARGS
argument_list|(
operator|(
expr|struct
name|re_pattern_buffer
operator|*
name|buffer
operator|,
specifier|const
name|char
operator|*
name|string1
operator|,
name|int
name|length1
operator|,
specifier|const
name|char
operator|*
name|string2
operator|,
name|int
name|length2
operator|,
name|int
name|start
operator|,
name|int
name|range
operator|,
expr|struct
name|re_registers
operator|*
name|regs
operator|,
name|int
name|stop
operator|)
argument_list|)
decl_stmt|;
comment|/* Like `re_search', but return how many characters in STRING the regexp    in BUFFER matched, starting at position START.  */
specifier|extern
name|int
name|re_match
name|_RE_ARGS
argument_list|(
operator|(
expr|struct
name|re_pattern_buffer
operator|*
name|buffer
operator|,
specifier|const
name|char
operator|*
name|string
operator|,
name|int
name|length
operator|,
name|int
name|start
operator|,
expr|struct
name|re_registers
operator|*
name|regs
operator|)
argument_list|)
decl_stmt|;
comment|/* Relates to `re_match' as `re_search_2' relates to `re_search'.  */
specifier|extern
name|int
name|re_match_2
name|_RE_ARGS
argument_list|(
operator|(
expr|struct
name|re_pattern_buffer
operator|*
name|buffer
operator|,
specifier|const
name|char
operator|*
name|string1
operator|,
name|int
name|length1
operator|,
specifier|const
name|char
operator|*
name|string2
operator|,
name|int
name|length2
operator|,
name|int
name|start
operator|,
expr|struct
name|re_registers
operator|*
name|regs
operator|,
name|int
name|stop
operator|)
argument_list|)
decl_stmt|;
comment|/* Set REGS to hold NUM_REGS registers, storing them in STARTS and    ENDS.  Subsequent matches using BUFFER and REGS will use this memory    for recording register information.  STARTS and ENDS must be    allocated with malloc, and must each be at least `NUM_REGS * sizeof    (regoff_t)' bytes long.     If NUM_REGS == 0, then subsequent matches should allocate their own    register data.     Unless this function is called, the first search or match using    PATTERN_BUFFER will allocate its own register data, without    freeing the old data.  */
specifier|extern
name|void
name|re_set_registers
name|_RE_ARGS
argument_list|(
operator|(
expr|struct
name|re_pattern_buffer
operator|*
name|buffer
operator|,
expr|struct
name|re_registers
operator|*
name|regs
operator|,
name|unsigned
name|num_regs
operator|,
name|regoff_t
operator|*
name|starts
operator|,
name|regoff_t
operator|*
name|ends
operator|)
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
name|_REGEX_RE_COMP
operator|||
name|defined
name|_LIBC
ifndef|#
directive|ifndef
name|_CRAY
comment|/* 4.2 bsd compatibility.  */
specifier|extern
name|char
modifier|*
name|re_comp
name|_RE_ARGS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|re_exec
name|_RE_ARGS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* GCC 2.95 and later have "__restrict"; C99 compilers have    "restrict", and "configure" may have defined "restrict".  */
ifndef|#
directive|ifndef
name|__restrict
if|#
directive|if
operator|!
operator|(
literal|2
operator|<
name|__GNUC__
operator|||
operator|(
literal|2
operator|==
name|__GNUC__
operator|&&
literal|95
operator|<=
name|__GNUC_MINOR__
operator|)
operator|)
if|#
directive|if
name|defined
specifier|restrict
operator|||
literal|199901L
operator|<=
name|__STDC_VERSION__
define|#
directive|define
name|__restrict
value|restrict
else|#
directive|else
define|#
directive|define
name|__restrict
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
comment|/* GCC 3.1 and later support declaring arrays as non-overlapping    using the syntax array_name[restrict]  */
ifndef|#
directive|ifndef
name|__restrict_arr
if|#
directive|if
operator|!
operator|(
literal|3
operator|<
name|__GNUC__
operator|||
operator|(
literal|3
operator|==
name|__GNUC__
operator|&&
literal|1
operator|<=
name|__GNUC_MINOR__
operator|)
operator|)
operator|||
name|defined
argument_list|(
name|__GNUG__
argument_list|)
define|#
directive|define
name|__restrict_arr
else|#
directive|else
define|#
directive|define
name|__restrict_arr
value|__restrict
endif|#
directive|endif
endif|#
directive|endif
comment|/* POSIX compatibility.  */
specifier|extern
name|int
name|regcomp
name|_RE_ARGS
argument_list|(
operator|(
name|regex_t
operator|*
name|__restrict
name|__preg
operator|,
specifier|const
name|char
operator|*
name|__restrict
name|__pattern
operator|,
name|int
name|__cflags
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|regexec
name|_RE_ARGS
argument_list|(
operator|(
specifier|const
name|regex_t
operator|*
name|__restrict
name|__preg
operator|,
specifier|const
name|char
operator|*
name|__restrict
name|__string
operator|,
name|size_t
name|__nmatch
operator|,
name|regmatch_t
name|__pmatch
index|[
name|__restrict_arr
index|]
operator|,
name|int
name|__eflags
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|size_t
name|regerror
name|_RE_ARGS
argument_list|(
operator|(
name|int
name|__errcode
operator|,
specifier|const
name|regex_t
operator|*
name|__preg
operator|,
name|char
operator|*
name|__errbuf
operator|,
name|size_t
name|__errbuf_size
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|regfree
name|_RE_ARGS
argument_list|(
operator|(
name|regex_t
operator|*
name|__preg
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C++ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* regex.h */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Local variables: make-backup-files: t version-control: t trim-versions-without-asking: nil End: */
end_comment

end_unit

