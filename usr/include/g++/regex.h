begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for data structures callers pass the regex library.    Copyright (C) 1985 Free Software Foundation, Inc.  		       NO WARRANTY    BECAUSE THIS PROGRAM IS LICENSED FREE OF CHARGE, WE PROVIDE ABSOLUTELY NO WARRANTY, TO THE EXTENT PERMITTED BY APPLICABLE STATE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING, FREE SOFTWARE FOUNDATION, INC, RICHARD M. STALLMAN AND/OR OTHER PARTIES PROVIDE THIS PROGRAM "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.   IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW WILL RICHARD M. STALLMAN, THE FREE SOFTWARE FOUNDATION, INC., AND/OR ANY OTHER PARTY WHO MAY MODIFY AND REDISTRIBUTE THIS PROGRAM AS PERMITTED BELOW, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY LOST PROFITS, LOST MONIES, OR OTHER SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS) THIS PROGRAM, EVEN IF YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES, OR FOR ANY CLAIM BY ANY OTHER PARTY.  		GENERAL PUBLIC LICENSE TO COPY    1. You may copy and distribute verbatim copies of this source file as you receive it, in any medium, provided that you conspicuously and appropriately publish on each copy a valid copyright notice "Copyright (C) 1985 Free Software Foundation, Inc."; and include following the copyright notice a verbatim copy of the above disclaimer of warranty and of this License.  You may charge a distribution fee for the physical act of transferring a copy.    2. You may modify your copy or copies of this source file or any portion of it, and copy and distribute such modifications under the terms of Paragraph 1 above, provided that you also do the following:      a) cause the modified files to carry prominent notices stating     that you changed the files and the date of any change; and      b) cause the whole of any work that you distribute or publish,     that in whole or in part contains or is a derivative of this     program or any part thereof, to be licensed at no charge to all     third parties on terms identical to those contained in this     License Agreement (except that you may choose to grant more extensive     warranty protection to some or all third parties, at your option).      c) You may charge a distribution fee for the physical act of     transferring a copy, and you may at your option offer warranty     protection in exchange for a fee.  Mere aggregation of another unrelated program with this program (or its derivative) on a volume of a storage or distribution medium does not bring the other program under the scope of these terms.    3. You may copy and distribute this program (or a portion or derivative of it, under Paragraph 2) in object code or executable form under the terms of Paragraphs 1 and 2 above provided that you also do one of the following:      a) accompany it with the complete corresponding machine-readable     source code, which must be distributed under the terms of     Paragraphs 1 and 2 above; or,      b) accompany it with a written offer, valid for at least three     years, to give any third party free (except for a nominal     shipping charge) a complete machine-readable copy of the     corresponding source code, to be distributed under the terms of     Paragraphs 1 and 2 above; or,      c) accompany it with the information you received as to where the     corresponding source code may be obtained.  (This alternative is     allowed only for noncommercial distribution and only if you     received the program in object code or executable form alone.)  For an executable file, complete source code means all the source code for all modules it contains; but, as a special exception, it need not include source code for modules which are standard libraries that accompany the operating system on which the executable file runs.    4. You may not copy, sublicense, distribute or transfer this program except as expressly provided under this License Agreement.  Any attempt otherwise to copy, sublicense, distribute or transfer this program is void and your rights to use the program under this License agreement shall be automatically terminated.  However, parties who have received computer software programs from you with this License Agreement will not have their licenses terminated so long as such parties remain in full compliance.    5. If you wish to incorporate parts of this program into other free programs whose distribution conditions are different, write to the Free Software Foundation at 675 Mass Ave, Cambridge, MA 02139.  We have not yet worked out a simple rule that can be stated here, but we will often permit this.  We will be guided by the two goals of preserving the free status of all derivatives of our free software and of promoting the sharing and reuse of software.   In other words, you are welcome to use, share and improve this program. You are forbidden to forbid anyone else to use, share and improve what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SHORT_NAMES
argument_list|)
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|re_compile_pattern
value|recmppat
end_define

begin_define
define|#
directive|define
name|re_pattern_buffer
value|repatbuf
end_define

begin_define
define|#
directive|define
name|re_registers
value|reregs
end_define

begin_endif
endif|#
directive|endif
end_endif

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
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|re_pattern_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Is this really advertised? */
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
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
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

begin_comment
comment|/* 4.2 bsd compatibility (yuck) */
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

end_unit

