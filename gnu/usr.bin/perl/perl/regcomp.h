begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: regcomp.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:15 $  *  * $Log: regcomp.h,v $  * Revision 1.2  1995/05/30 05:03:15  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:35  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:39  nate  * PERL!  *  * Revision 4.0.1.1  91/06/07  11:49:40  lwall  * patch4: no change  *  * Revision 4.0  91/03/20  01:39:09  lwall  * 4.0 baseline.  *  */
end_comment

begin_comment
comment|/*  * The "internal use only" fields in regexp.h are present to pass info from  * compile to execute that permits the execute phase to run lots faster on  * simple cases.  They are:  *  * regstart	str that must begin a match; Nullch if none obvious  * reganch	is the match anchored (at beginning-of-line only)?  * regmust	string (pointer into program) that match must include, or NULL  *  [regmust changed to STR* for bminstr()--law]  * regmlen	length of regmust string  *  [regmlen not used currently]  *  * Regstart and reganch permit very fast decisions on suitable starting points  * for a match, cutting down the work a lot.  Regmust permits fast rejection  * of lines that cannot possibly match.  The regmust tests are costly enough  * that regcomp() supplies a regmust only if the r.e. contains something  * potentially expensive (at present, the only such thing detected is * or +  * at the start of the r.e., which can involve a lot of backup).  Regmlen is  * supplied because the test in regexec() needs it and regcomp() is computing  * it anyway.  * [regmust is now supplied always.  The tests that use regmust have a  * heuristic that disables the test if it usually matches.]  *  * [In fact, we now use regmust in many cases to locate where the search  * starts in the string, so if regback is>= 0, the regmust search is never  * wasted effort.  The regback variable says how many characters back from  * where regmust matched is the earliest possible start of the match.  * For instance, /[a-z].foo/ has a regmust of 'foo' and a regback of 2.]  */
end_comment

begin_comment
comment|/*  * Structure for regexp "program".  This is essentially a linear encoding  * of a nondeterministic finite-state machine (aka syntax charts or  * "railroad normal form" in parsing technology).  Each node is an opcode  * plus a "next" pointer, possibly plus an operand.  "Next" pointers of  * all nodes except BRANCH implement concatenation; a "next" pointer with  * a BRANCH on both ends of it is connecting two alternatives.  (Here we  * have one of the subtle syntax dependencies:  an individual BRANCH (as  * opposed to a collection of them) is never concatenated with anything  * because of operator precedence.)  The operand of some types of node is  * a literal string; for others, it is a node leading into a sub-FSM.  In  * particular, the operand of a BRANCH node is the first node of the branch.  * (NB this is *not* a tree structure:  the tail of the branch connects  * to the thing following the set of BRANCHes.)  The opcodes are:  */
end_comment

begin_comment
comment|/* definition	number	opnd?	meaning */
end_comment

begin_define
define|#
directive|define
name|END
value|0
end_define

begin_comment
comment|/* no	End of program. */
end_comment

begin_define
define|#
directive|define
name|BOL
value|1
end_define

begin_comment
comment|/* no	Match "" at beginning of line. */
end_comment

begin_define
define|#
directive|define
name|EOL
value|2
end_define

begin_comment
comment|/* no	Match "" at end of line. */
end_comment

begin_define
define|#
directive|define
name|ANY
value|3
end_define

begin_comment
comment|/* no	Match any one character. */
end_comment

begin_define
define|#
directive|define
name|ANYOF
value|4
end_define

begin_comment
comment|/* str	Match character in (or not in) this class. */
end_comment

begin_define
define|#
directive|define
name|CURLY
value|5
end_define

begin_comment
comment|/* str	Match this simple thing {n,m} times. */
end_comment

begin_define
define|#
directive|define
name|BRANCH
value|6
end_define

begin_comment
comment|/* node	Match this alternative, or the next... */
end_comment

begin_define
define|#
directive|define
name|BACK
value|7
end_define

begin_comment
comment|/* no	Match "", "next" ptr points backward. */
end_comment

begin_define
define|#
directive|define
name|EXACTLY
value|8
end_define

begin_comment
comment|/* str	Match this string (preceded by length). */
end_comment

begin_define
define|#
directive|define
name|NOTHING
value|9
end_define

begin_comment
comment|/* no	Match empty string. */
end_comment

begin_define
define|#
directive|define
name|STAR
value|10
end_define

begin_comment
comment|/* node	Match this (simple) thing 0 or more times. */
end_comment

begin_define
define|#
directive|define
name|PLUS
value|11
end_define

begin_comment
comment|/* node	Match this (simple) thing 1 or more times. */
end_comment

begin_define
define|#
directive|define
name|ALNUM
value|12
end_define

begin_comment
comment|/* no	Match any alphanumeric character */
end_comment

begin_define
define|#
directive|define
name|NALNUM
value|13
end_define

begin_comment
comment|/* no	Match any non-alphanumeric character */
end_comment

begin_define
define|#
directive|define
name|BOUND
value|14
end_define

begin_comment
comment|/* no	Match "" at any word boundary */
end_comment

begin_define
define|#
directive|define
name|NBOUND
value|15
end_define

begin_comment
comment|/* no	Match "" at any word non-boundary */
end_comment

begin_define
define|#
directive|define
name|SPACE
value|16
end_define

begin_comment
comment|/* no	Match any whitespace character */
end_comment

begin_define
define|#
directive|define
name|NSPACE
value|17
end_define

begin_comment
comment|/* no	Match any non-whitespace character */
end_comment

begin_define
define|#
directive|define
name|DIGIT
value|18
end_define

begin_comment
comment|/* no	Match any numeric character */
end_comment

begin_define
define|#
directive|define
name|NDIGIT
value|19
end_define

begin_comment
comment|/* no	Match any non-numeric character */
end_comment

begin_define
define|#
directive|define
name|REF
value|20
end_define

begin_comment
comment|/* num	Match some already matched string */
end_comment

begin_define
define|#
directive|define
name|OPEN
value|21
end_define

begin_comment
comment|/* num	Mark this point in input as start of #n. */
end_comment

begin_define
define|#
directive|define
name|CLOSE
value|22
end_define

begin_comment
comment|/* num	Analogous to OPEN. */
end_comment

begin_comment
comment|/*  * Opcode notes:  *  * BRANCH	The set of branches constituting a single choice are hooked  *		together with their "next" pointers, since precedence prevents  *		anything being concatenated to any individual branch.  The  *		"next" pointer of the last BRANCH in a choice points to the  *		thing following the whole choice.  This is also where the  *		final "next" pointer of each individual branch points; each  *		branch starts with the operand node of a BRANCH node.  *  * BACK		Normal "next" pointers all implicitly point forward; BACK  *		exists to make loop structures possible.  *  * STAR,PLUS	'?', and complex '*' and '+', are implemented as circular  *		BRANCH structures using BACK.  Simple cases (one character  *		per match) are implemented with STAR and PLUS for speed  *		and to minimize recursive plunges.  *  * OPEN,CLOSE	...are numbered at compile time.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|regarglen
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|regarglen
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following have no fixed length. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|varies
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|varies
index|[]
init|=
block|{
name|BRANCH
block|,
name|BACK
block|,
name|STAR
block|,
name|PLUS
block|,
name|CURLY
block|,
name|REF
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following always have a length of 1. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|simple
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|simple
index|[]
init|=
block|{
name|ANY
block|,
name|ANYOF
block|,
name|ALNUM
block|,
name|NALNUM
block|,
name|SPACE
block|,
name|NSPACE
block|,
name|DIGIT
block|,
name|NDIGIT
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|char
name|regdummy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * A node is one char of opcode followed by two chars of "next" pointer.  * "Next" pointers are stored as two 8-bit pieces, high order first.  The  * value is a positive offset from the opcode of the node containing it.  * An operand, if any, simply follows the node.  (Note that much of the  * code generation knows about this implicit relationship.)  *  * Using two bytes for the "next" pointer is vast overkill for most things,  * but allows patterns to get big without disasters.  *  * [If REGALIGN is defined, the "next" pointer is always aligned on an even  * boundary, and reads the offset directly as a short.  Also, there is no  * special test to reverse the sign of BACK pointers since the offset is  * stored negative.]  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gould
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|cray
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|eta10
end_ifndef

begin_define
define|#
directive|define
name|REGALIGN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OP
parameter_list|(
name|p
parameter_list|)
value|(*(p))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|REGALIGN
end_ifdef

begin_define
define|#
directive|define
name|NEXT
parameter_list|(
name|p
parameter_list|)
value|(*(short*)(p+1))
end_define

begin_define
define|#
directive|define
name|ARG1
parameter_list|(
name|p
parameter_list|)
value|(*(unsigned short*)(p+3))
end_define

begin_define
define|#
directive|define
name|ARG2
parameter_list|(
name|p
parameter_list|)
value|(*(unsigned short*)(p+5))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NEXT
parameter_list|(
name|p
parameter_list|)
value|(((*((p)+1)&0377)<<8) + (*((p)+2)&0377))
end_define

begin_define
define|#
directive|define
name|ARG1
parameter_list|(
name|p
parameter_list|)
value|(((*((p)+3)&0377)<<8) + (*((p)+4)&0377))
end_define

begin_define
define|#
directive|define
name|ARG2
parameter_list|(
name|p
parameter_list|)
value|(((*((p)+5)&0377)<<8) + (*((p)+6)&0377))
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
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|NEXT
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|OPERAND
parameter_list|(
name|p
parameter_list|)
value|((p) + 3)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REGALIGN
end_ifdef

begin_define
define|#
directive|define
name|NEXTOPER
parameter_list|(
name|p
parameter_list|)
value|((p) + 4)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NEXTOPER
parameter_list|(
name|p
parameter_list|)
value|((p) + 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAGIC
value|0234
end_define

begin_comment
comment|/*  * Utility definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|CHARBITS
end_ifndef

begin_define
define|#
directive|define
name|UCHARAT
parameter_list|(
name|p
parameter_list|)
value|((int)*(unsigned char *)(p))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UCHARAT
parameter_list|(
name|p
parameter_list|)
value|((int)*(p)&CHARBITS)
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
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|UCHARAT
parameter_list|(
name|p
parameter_list|)
value|regdummy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|FAIL
parameter_list|(
name|m
parameter_list|)
value|fatal("/%s/: %s",regprecomp,m)
end_define

begin_function_decl
name|char
modifier|*
name|regnext
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_function_decl
name|void
name|regdump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|regprop
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

