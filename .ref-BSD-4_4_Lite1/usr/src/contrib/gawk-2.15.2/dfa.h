begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dfa.h - declarations for GNU deterministic regexp compiler    Copyright (C) 1988 Free Software Foundation, Inc.                       Written June, 1988 by Mike Haertel  		       NO WARRANTY    BECAUSE THIS PROGRAM IS LICENSED FREE OF CHARGE, WE PROVIDE ABSOLUTELY NO WARRANTY, TO THE EXTENT PERMITTED BY APPLICABLE STATE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING, FREE SOFTWARE FOUNDATION, INC, RICHARD M. STALLMAN AND/OR OTHER PARTIES PROVIDE THIS PROGRAM "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.   IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW WILL RICHARD M. STALLMAN, THE FREE SOFTWARE FOUNDATION, INC., AND/OR ANY OTHER PARTY WHO MAY MODIFY AND REDISTRIBUTE THIS PROGRAM AS PERMITTED BELOW, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY LOST PROFITS, LOST MONIES, OR OTHER SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS) THIS PROGRAM, EVEN IF YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES, OR FOR ANY CLAIM BY ANY OTHER PARTY.  		GENERAL PUBLIC LICENSE TO COPY    1. You may copy and distribute verbatim copies of this source file as you receive it, in any medium, provided that you conspicuously and appropriately publish on each copy a valid copyright notice "Copyright  (C) 1988 Free Software Foundation, Inc."; and include following the copyright notice a verbatim copy of the above disclaimer of warranty and of this License.  You may charge a distribution fee for the physical act of transferring a copy.    2. You may modify your copy or copies of this source file or any portion of it, and copy and distribute such modifications under the terms of Paragraph 1 above, provided that you also do the following:      a) cause the modified files to carry prominent notices stating     that you changed the files and the date of any change; and      b) cause the whole of any work that you distribute or publish,     that in whole or in part contains or is a derivative of this     program or any part thereof, to be licensed at no charge to all     third parties on terms identical to those contained in this     License Agreement (except that you may choose to grant more extensive     warranty protection to some or all third parties, at your option).      c) You may charge a distribution fee for the physical act of     transferring a copy, and you may at your option offer warranty     protection in exchange for a fee.  Mere aggregation of another unrelated program with this program (or its derivative) on a volume of a storage or distribution medium does not bring the other program under the scope of these terms.    3. You may copy and distribute this program or any portion of it in compiled, executable or object code form under the terms of Paragraphs 1 and 2 above provided that you do the following:      a) accompany it with the complete corresponding machine-readable     source code, which must be distributed under the terms of     Paragraphs 1 and 2 above; or,      b) accompany it with a written offer, valid for at least three     years, to give any third party free (except for a nominal     shipping charge) a complete machine-readable copy of the     corresponding source code, to be distributed under the terms of     Paragraphs 1 and 2 above; or,      c) accompany it with the information you received as to where the     corresponding source code may be obtained.  (This alternative is     allowed only for noncommercial distribution and only if you     received the program in object code or executable form alone.)  For an executable file, complete source code means all the source code for all modules it contains; but, as a special exception, it need not include source code for modules which are standard libraries that accompany the operating system on which the executable file runs.    4. You may not copy, sublicense, distribute or transfer this program except as expressly provided under this License Agreement.  Any attempt otherwise to copy, sublicense, distribute or transfer this program is void and your rights to use the program under this License agreement shall be automatically terminated.  However, parties who have received computer software programs from you with this License Agreement will not have their licenses terminated so long as such parties remain in full compliance.    5. If you wish to incorporate parts of this program into other free programs whose distribution conditions are different, write to the Free Software Foundation at 675 Mass Ave, Cambridge, MA 02139.  We have not yet worked out a simple rule that can be stated here, but we will often permit this.  We will be guided by the two goals of preserving the free status of all derivatives our free software and of promoting the sharing and reuse of software.   In other words, you are welcome to use, share and improve this program. You are forbidden to forbid anyone else to use, share and improve what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SOMEDAY
end_ifdef

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|isalnum(c)
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|isalpha(c)
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|isupper(c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isalnum(c))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isalpha(c))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isupper(c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __STDC__ */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isalnum(c))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isalpha(c))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isupper(c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __STDC__ */
end_comment

begin_comment
comment|/* 1 means plain parentheses serve as grouping, and backslash      parentheses are needed for literal searching.    0 means backslash-parentheses are grouping, and plain parentheses      are for literal searching.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_PARENS
value|1L
end_define

begin_comment
comment|/* 1 means plain | serves as the "or"-operator, and \| is a literal.    0 means \| serves as the "or"-operator, and | is a literal.  */
end_comment

begin_define
define|#
directive|define
name|RE_NO_BK_VBAR
value|(1L<< 1)
end_define

begin_comment
comment|/* 0 means plain + or ? serves as an operator, and \+, \? are literals.    1 means \+, \? are operators and plain +, ? are literals.  */
end_comment

begin_define
define|#
directive|define
name|RE_BK_PLUS_QM
value|(1L<< 2)
end_define

begin_comment
comment|/* 1 means | binds tighter than ^ or $.    0 means the contrary.  */
end_comment

begin_define
define|#
directive|define
name|RE_TIGHT_VBAR
value|(1L<< 3)
end_define

begin_comment
comment|/* 1 means treat \n as an _OR operator    0 means treat it as a normal character */
end_comment

begin_define
define|#
directive|define
name|RE_NEWLINE_OR
value|(1L<< 4)
end_define

begin_comment
comment|/* 0 means that a special characters (such as *, ^, and $) always have      their special meaning regardless of the surrounding context.    1 means that special characters may act as normal characters in some      contexts.  Specifically, this applies to: 	^ - only special at the beginning, or after ( or | 	$ - only special at the end, or before ) or | 	*, +, ? - only special when not after the beginning, (, or | */
end_comment

begin_define
define|#
directive|define
name|RE_CONTEXT_INDEP_OPS
value|(1L<< 5)
end_define

begin_comment
comment|/* 1 means that \ in a character class escapes the next character (typically    a hyphen.  It also is overloaded to mean that hyphen at the end of the range    is allowable and means that the hyphen is to be taken literally. */
end_comment

begin_define
define|#
directive|define
name|RE_AWK_CLASS_HACK
value|(1L<< 6)
end_define

begin_comment
comment|/* Now define combinations of bits for the standard possibilities.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The NULL pointer. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in an unsigned char. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHARBITS
end_ifndef

begin_define
define|#
directive|define
name|CHARBITS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* First integer value that is greater than any character code. */
end_comment

begin_define
define|#
directive|define
name|_NOTCHAR
value|(1<< CHARBITS)
end_define

begin_comment
comment|/* INTBITS need not be exact, just a lower bound. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INTBITS
end_ifndef

begin_define
define|#
directive|define
name|INTBITS
value|(CHARBITS * sizeof (int))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of ints required to hold a bit for every character. */
end_comment

begin_define
define|#
directive|define
name|_CHARSET_INTS
value|((_NOTCHAR + INTBITS - 1) / INTBITS)
end_define

begin_comment
comment|/* Sets of unsigned characters are stored as bit vectors in arrays of ints. */
end_comment

begin_typedef
typedef|typedef
name|int
name|_charset
index|[
name|_CHARSET_INTS
index|]
typedef|;
end_typedef

begin_comment
comment|/* The regexp is parsed into an array of tokens in postfix form.  Some tokens    are operators and others are terminal symbols.  Most (but not all) of these    codes are returned by the lexical analyzer. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
enum|enum
block|{
name|_END
init|=
operator|-
literal|1
block|,
comment|/* _END is a terminal symbol that matches the 				   end of input; any value of _END or less in 				   the parse tree is such a symbol.  Accepting 				   states of the DFA are those that would have 				   a transition on _END. */
comment|/* Ordinary character values are terminal symbols that match themselves. */
name|_EMPTY
init|=
name|_NOTCHAR
block|,
comment|/* _EMPTY is a terminal symbol that matches 				   the empty string. */
name|_BACKREF
block|,
comment|/* _BACKREF is generated by \<digit>; it 				   it not completely handled.  If the scanner 				   detects a transition on backref, it returns 				   a kind of "semi-success" indicating that 				   the match will have to be verified with 				   a backtracking matcher. */
name|_BEGLINE
block|,
comment|/* _BEGLINE is a terminal symbol that matches 				   the empty string if it is at the beginning 				   of a line. */
name|_ALLBEGLINE
block|,
comment|/* _ALLBEGLINE is a terminal symbol that 				   matches the empty string if it is at the 				   beginning of a line; _ALLBEGLINE applies 				   to the entire regexp and can only occur 				   as the first token thereof.  _ALLBEGLINE 				   never appears in the parse tree; a _BEGLINE 				   is prepended with _CAT to the entire 				   regexp instead. */
name|_ENDLINE
block|,
comment|/* _ENDLINE is a terminal symbol that matches 				   the empty string if it is at the end of 				   a line. */
name|_ALLENDLINE
block|,
comment|/* _ALLENDLINE is to _ENDLINE as _ALLBEGLINE 				   is to _BEGLINE. */
name|_BEGWORD
block|,
comment|/* _BEGWORD is a terminal symbol that matches 				   the empty string if it is at the beginning 				   of a word. */
name|_ENDWORD
block|,
comment|/* _ENDWORD is a terminal symbol that matches 				   the empty string if it is at the end of 				   a word. */
name|_LIMWORD
block|,
comment|/* _LIMWORD is a terminal symbol that matches 				   the empty string if it is at the beginning 				   or the end of a word. */
name|_NOTLIMWORD
block|,
comment|/* _NOTLIMWORD is a terminal symbol that 				   matches the empty string if it is not at 				   the beginning or end of a word. */
name|_QMARK
block|,
comment|/* _QMARK is an operator of one argument that 				   matches zero or one occurences of its 				   argument. */
name|_STAR
block|,
comment|/* _STAR is an operator of one argument that 				   matches the Kleene closure (zero or more 				   occurrences) of its argument. */
name|_PLUS
block|,
comment|/* _PLUS is an operator of one argument that 				   matches the positive closure (one or more 				   occurrences) of its argument. */
name|_CAT
block|,
comment|/* _CAT is an operator of two arguments that 				   matches the concatenation of its 				   arguments.  _CAT is never returned by the 				   lexical analyzer. */
name|_OR
block|,
comment|/* _OR is an operator of two arguments that 				   matches either of its arguments. */
name|_LPAREN
block|,
comment|/* _LPAREN never appears in the parse tree, 				   it is only a lexeme. */
name|_RPAREN
block|,
comment|/* _RPAREN never appears in the parse tree. */
name|_SET
comment|/* _SET and (and any value greater) is a 				   terminal symbol that matches any of a 				   class of characters. */
block|}
name|_token
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __STDC__ */
end_comment

begin_typedef
typedef|typedef
name|short
name|_token
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_END
value|-1
end_define

begin_define
define|#
directive|define
name|_EMPTY
value|_NOTCHAR
end_define

begin_define
define|#
directive|define
name|_BACKREF
value|(_EMPTY + 1)
end_define

begin_define
define|#
directive|define
name|_BEGLINE
value|(_EMPTY + 2)
end_define

begin_define
define|#
directive|define
name|_ALLBEGLINE
value|(_EMPTY + 3)
end_define

begin_define
define|#
directive|define
name|_ENDLINE
value|(_EMPTY + 4)
end_define

begin_define
define|#
directive|define
name|_ALLENDLINE
value|(_EMPTY + 5)
end_define

begin_define
define|#
directive|define
name|_BEGWORD
value|(_EMPTY + 6)
end_define

begin_define
define|#
directive|define
name|_ENDWORD
value|(_EMPTY + 7)
end_define

begin_define
define|#
directive|define
name|_LIMWORD
value|(_EMPTY + 8)
end_define

begin_define
define|#
directive|define
name|_NOTLIMWORD
value|(_EMPTY + 9)
end_define

begin_define
define|#
directive|define
name|_QMARK
value|(_EMPTY + 10)
end_define

begin_define
define|#
directive|define
name|_STAR
value|(_EMPTY + 11)
end_define

begin_define
define|#
directive|define
name|_PLUS
value|(_EMPTY + 12)
end_define

begin_define
define|#
directive|define
name|_CAT
value|(_EMPTY + 13)
end_define

begin_define
define|#
directive|define
name|_OR
value|(_EMPTY + 14)
end_define

begin_define
define|#
directive|define
name|_LPAREN
value|(_EMPTY + 15)
end_define

begin_define
define|#
directive|define
name|_RPAREN
value|(_EMPTY + 16)
end_define

begin_define
define|#
directive|define
name|_SET
value|(_EMPTY + 17)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __STDC__ */
end_comment

begin_comment
comment|/* Sets are stored in an array in the compiled regexp; the index of the    array corresponding to a given set token is given by _SET_INDEX(t). */
end_comment

begin_define
define|#
directive|define
name|_SET_INDEX
parameter_list|(
name|t
parameter_list|)
value|((t) - _SET)
end_define

begin_comment
comment|/* Sometimes characters can only be matched depending on the surrounding    context.  Such context decisions depend on what the previous character    was, and the value of the current (lookahead) character.  Context    dependent constraints are encoded as 8 bit integers.  Each bit that    is set indicates that the constraint succeeds in the corresponding    context.     bit 7 - previous and current are newlines    bit 6 - previous was newline, current isn't    bit 5 - previous wasn't newline, current is    bit 4 - neither previous nor current is a newline    bit 3 - previous and current are word-constituents    bit 2 - previous was word-constituent, current isn't    bit 1 - previous wasn't word-constituent, current is    bit 0 - neither previous nor current is word-constituent     Word-constituent characters are those that satisfy isalnum().     The macro _SUCCEEDS_IN_CONTEXT determines whether a a given constraint    succeeds in a particular context.  Prevn is true if the previous character    was a newline, currn is true if the lookahead character is a newline.    Prevl and currl similarly depend upon whether the previous and current    characters are word-constituent letters. */
end_comment

begin_define
define|#
directive|define
name|_MATCHES_NEWLINE_CONTEXT
parameter_list|(
name|constraint
parameter_list|,
name|prevn
parameter_list|,
name|currn
parameter_list|)
define|\
value|((constraint)& (1<< (((prevn) ? 2 : 0) + ((currn) ? 1 : 0) + 4)))
end_define

begin_define
define|#
directive|define
name|_MATCHES_LETTER_CONTEXT
parameter_list|(
name|constraint
parameter_list|,
name|prevl
parameter_list|,
name|currl
parameter_list|)
define|\
value|((constraint)& (1<< (((prevl) ? 2 : 0) + ((currl) ? 1 : 0))))
end_define

begin_define
define|#
directive|define
name|_SUCCEEDS_IN_CONTEXT
parameter_list|(
name|constraint
parameter_list|,
name|prevn
parameter_list|,
name|currn
parameter_list|,
name|prevl
parameter_list|,
name|currl
parameter_list|)
define|\
value|(_MATCHES_NEWLINE_CONTEXT(constraint, prevn, currn)		     \&& _MATCHES_LETTER_CONTEXT(constraint, prevl, currl))
end_define

begin_comment
comment|/* The following macros give information about what a constraint depends on. */
end_comment

begin_define
define|#
directive|define
name|_PREV_NEWLINE_DEPENDENT
parameter_list|(
name|constraint
parameter_list|)
define|\
value|(((constraint)& 0xc0)>> 2 != ((constraint)& 0x30))
end_define

begin_define
define|#
directive|define
name|_PREV_LETTER_DEPENDENT
parameter_list|(
name|constraint
parameter_list|)
define|\
value|(((constraint)& 0x0c)>> 2 != ((constraint)& 0x03))
end_define

begin_comment
comment|/* Tokens that match the empty string subject to some constraint actually    work by applying that constraint to determine what may follow them,    taking into account what has gone before.  The following values are    the constraints corresponding to the special tokens previously defined. */
end_comment

begin_define
define|#
directive|define
name|_NO_CONSTRAINT
value|0xff
end_define

begin_define
define|#
directive|define
name|_BEGLINE_CONSTRAINT
value|0xcf
end_define

begin_define
define|#
directive|define
name|_ENDLINE_CONSTRAINT
value|0xaf
end_define

begin_define
define|#
directive|define
name|_BEGWORD_CONSTRAINT
value|0xf2
end_define

begin_define
define|#
directive|define
name|_ENDWORD_CONSTRAINT
value|0xf4
end_define

begin_define
define|#
directive|define
name|_LIMWORD_CONSTRAINT
value|0xf6
end_define

begin_define
define|#
directive|define
name|_NOTLIMWORD_CONSTRAINT
value|0xf9
end_define

begin_comment
comment|/* States of the recognizer correspond to sets of positions in the parse    tree, together with the constraints under which they may be matched.    So a position is encoded as an index into the parse tree together with    a constraint. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|index
decl_stmt|;
comment|/* Index into the parse array. */
name|unsigned
name|constraint
decl_stmt|;
comment|/* Constraint for matching this position. */
block|}
name|_position
typedef|;
end_typedef

begin_comment
comment|/* Sets of positions are stored as arrays. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|_position
modifier|*
name|elems
decl_stmt|;
comment|/* Elements of this position set. */
name|int
name|nelem
decl_stmt|;
comment|/* Number of elements in this set. */
block|}
name|_position_set
typedef|;
end_typedef

begin_comment
comment|/* A state of the regexp consists of a set of positions, some flags,    and the token value of the lowest-numbered position of the state that    contains an _END token. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|hash
decl_stmt|;
comment|/* Hash of the positions of this state. */
name|_position_set
name|elems
decl_stmt|;
comment|/* Positions this state could match. */
name|char
name|newline
decl_stmt|;
comment|/* True if previous state matched newline. */
name|char
name|letter
decl_stmt|;
comment|/* True if previous state matched a letter. */
name|char
name|backref
decl_stmt|;
comment|/* True if this state matches a \<digit>. */
name|unsigned
name|char
name|constraint
decl_stmt|;
comment|/* Constraint for this state to accept. */
name|int
name|first_end
decl_stmt|;
comment|/* Token value of the first _END in elems. */
block|}
name|_dfa_state
typedef|;
end_typedef

begin_comment
comment|/* If an r.e. is at most MUST_MAX characters long, we look for a string which    must appear in it; whatever's found is dropped into the struct reg. */
end_comment

begin_define
define|#
directive|define
name|MUST_MAX
value|50
end_define

begin_comment
comment|/* A compiled regular expression. */
end_comment

begin_struct
struct|struct
name|regexp
block|{
comment|/* Stuff built by the scanner. */
name|_charset
modifier|*
name|charsets
decl_stmt|;
comment|/* Array of character sets for _SET tokens. */
name|int
name|cindex
decl_stmt|;
comment|/* Index for adding new charsets. */
name|int
name|calloc
decl_stmt|;
comment|/* Number of charsets currently allocated. */
comment|/* Stuff built by the parser. */
name|_token
modifier|*
name|tokens
decl_stmt|;
comment|/* Postfix parse array. */
name|int
name|tindex
decl_stmt|;
comment|/* Index for adding new tokens. */
name|int
name|talloc
decl_stmt|;
comment|/* Number of tokens currently allocated. */
name|int
name|depth
decl_stmt|;
comment|/* Depth required of an evaluation stack 				   used for depth-first traversal of the 				   parse tree. */
name|int
name|nleaves
decl_stmt|;
comment|/* Number of leaves on the parse tree. */
name|int
name|nregexps
decl_stmt|;
comment|/* Count of parallel regexps being built 				   with regparse(). */
comment|/* Stuff owned by the state builder. */
name|_dfa_state
modifier|*
name|states
decl_stmt|;
comment|/* States of the regexp. */
name|int
name|sindex
decl_stmt|;
comment|/* Index for adding new states. */
name|int
name|salloc
decl_stmt|;
comment|/* Number of states currently allocated. */
comment|/* Stuff built by the structure analyzer. */
name|_position_set
modifier|*
name|follows
decl_stmt|;
comment|/* Array of follow sets, indexed by position 				   index.  The follow of a position is the set 				   of positions containing characters that 				   could conceivably follow a character 				   matching the given position in a string 				   matching the regexp.  Allocated to the 				   maximum possible position index. */
name|int
name|searchflag
decl_stmt|;
comment|/* True if we are supposed to build a searching 				   as opposed to an exact matcher.  A searching 				   matcher finds the first and shortest string 				   matching a regexp anywhere in the buffer, 				   whereas an exact matcher finds the longest 				   string matching, but anchored to the 				   beginning of the buffer. */
comment|/* Stuff owned by the executor. */
name|int
name|tralloc
decl_stmt|;
comment|/* Number of transition tables that have 				   slots so far. */
name|int
name|trcount
decl_stmt|;
comment|/* Number of transition tables that have 				   actually been built. */
name|int
modifier|*
modifier|*
name|trans
decl_stmt|;
comment|/* Transition tables for states that can 				   never accept.  If the transitions for a 				   state have not yet been computed, or the 				   state could possibly accept, its entry in 				   this table is NULL. */
name|int
modifier|*
modifier|*
name|realtrans
decl_stmt|;
comment|/* Trans always points to realtrans + 1; this 				   is so trans[-1] can contain NULL. */
name|int
modifier|*
modifier|*
name|fails
decl_stmt|;
comment|/* Transition tables after failing to accept 				   on a state that potentially could do so. */
name|int
modifier|*
name|success
decl_stmt|;
comment|/* Table of acceptance conditions used in 				   regexecute and computed in build_state. */
name|int
modifier|*
name|newlines
decl_stmt|;
comment|/* Transitions on newlines.  The entry for a 				   newline in any transition table is always 				   -1 so we can count lines without wasting 				   too many cycles.  The transition for a 				   newline is stored separately and handled 				   as a special case.  Newline is also used 				   as a sentinel at the end of the buffer. */
name|char
name|must
index|[
name|MUST_MAX
index|]
decl_stmt|;
name|int
name|mustn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Some macros for user access to regexp internals. */
end_comment

begin_comment
comment|/* ACCEPTING returns true if s could possibly be an accepting state of r. */
end_comment

begin_define
define|#
directive|define
name|ACCEPTING
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
value|((r).states[s].constraint)
end_define

begin_comment
comment|/* ACCEPTS_IN_CONTEXT returns true if the given state accepts in the    specified context. */
end_comment

begin_define
define|#
directive|define
name|ACCEPTS_IN_CONTEXT
parameter_list|(
name|prevn
parameter_list|,
name|currn
parameter_list|,
name|prevl
parameter_list|,
name|currl
parameter_list|,
name|state
parameter_list|,
name|reg
parameter_list|)
define|\
value|_SUCCEEDS_IN_CONTEXT((reg).states[state].constraint,		   \ 		       prevn, currn, prevl, currl)
end_define

begin_comment
comment|/* FIRST_MATCHING_REGEXP returns the index number of the first of parallel    regexps that a given state could accept.  Parallel regexps are numbered    starting at 1. */
end_comment

begin_define
define|#
directive|define
name|FIRST_MATCHING_REGEXP
parameter_list|(
name|state
parameter_list|,
name|reg
parameter_list|)
value|(-(reg).states[state].first_end)
end_define

begin_comment
comment|/* Entry points. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Regsyntax() takes two arguments; the first sets the syntax bits described    earlier in this file, and the second sets the case-folding flag. */
end_comment

begin_function_decl
specifier|extern
name|void
name|regsyntax
parameter_list|(
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compile the given string of the given length into the given struct regexp.    Final argument is a flag specifying whether to build a searching or an    exact matcher. */
end_comment

begin_function_decl
specifier|extern
name|void
name|regcompile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|regexp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Execute the given struct regexp on the buffer of characters.  The    first char * points to the beginning, and the second points to the    first character after the end of the buffer, which must be a writable    place so a sentinel end-of-buffer marker can be stored there.  The    second-to-last argument is a flag telling whether to allow newlines to    be part of a string matching the regexp.  The next-to-last argument,    if non-NULL, points to a place to increment every time we see a    newline.  The final argument, if non-NULL, points to a flag that will    be set if further examination by a backtracking matcher is needed in    order to verify backreferencing; otherwise the flag will be cleared.    Returns NULL if no match is found, or a pointer to the first    character after the first& shortest matching string in the buffer. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|regexecute
parameter_list|(
name|struct
name|regexp
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free the storage held by the components of a struct regexp. */
end_comment

begin_function_decl
specifier|extern
name|void
name|reg_free
parameter_list|(
name|struct
name|regexp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Entry points for people who know what they're doing. */
end_comment

begin_comment
comment|/* Initialize the components of a struct regexp. */
end_comment

begin_function_decl
specifier|extern
name|void
name|reginit
parameter_list|(
name|struct
name|regexp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Incrementally parse a string of given length into a struct regexp. */
end_comment

begin_function_decl
specifier|extern
name|void
name|regparse
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|regexp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Analyze a parsed regexp; second argument tells whether to build a searching    or an exact matcher. */
end_comment

begin_function_decl
specifier|extern
name|void
name|reganalyze
parameter_list|(
name|struct
name|regexp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compute, for each possible character, the transitions out of a given    state, storing them in an array of integers. */
end_comment

begin_function_decl
specifier|extern
name|void
name|regstate
parameter_list|(
name|int
parameter_list|,
name|struct
name|regexp
modifier|*
parameter_list|,
name|int
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Error handling. */
end_comment

begin_comment
comment|/* Regerror() is called by the regexp routines whenever an error occurs.  It    takes a single argument, a NUL-terminated string describing the error.    The default reg_error() prints the error message to stderr and exits.    The user can provide a different reg_free() if so desired. */
end_comment

begin_function_decl
specifier|extern
name|void
name|reg_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __STDC__ */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|regsyntax
argument_list|()
decl_stmt|,
name|regcompile
argument_list|()
decl_stmt|,
name|reg_free
argument_list|()
decl_stmt|,
name|reginit
argument_list|()
decl_stmt|,
name|regparse
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reganalyze
argument_list|()
decl_stmt|,
name|regstate
argument_list|()
decl_stmt|,
name|reg_error
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|regexecute
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

