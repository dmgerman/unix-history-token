begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    regcomp.h  */
end_comment

begin_typedef
typedef|typedef
name|OP
name|OP_4tree
typedef|;
end_typedef

begin_comment
comment|/* Will be redefined later. */
end_comment

begin_comment
comment|/*  * The "internal use only" fields in regexp.h are present to pass info from  * compile to execute that permits the execute phase to run lots faster on  * simple cases.  They are:  *  * regstart	sv that must begin a match; Nullch if none obvious  * reganch	is the match anchored (at beginning-of-line only)?  * regmust	string (pointer into program) that match must include, or NULL  *  [regmust changed to SV* for bminstr()--law]  * regmlen	length of regmust string  *  [regmlen not used currently]  *  * Regstart and reganch permit very fast decisions on suitable starting points  * for a match, cutting down the work a lot.  Regmust permits fast rejection  * of lines that cannot possibly match.  The regmust tests are costly enough  * that pregcomp() supplies a regmust only if the r.e. contains something  * potentially expensive (at present, the only such thing detected is * or +  * at the start of the r.e., which can involve a lot of backup).  Regmlen is  * supplied because the test in pregexec() needs it and pregcomp() is computing  * it anyway.  * [regmust is now supplied always.  The tests that use regmust have a  * heuristic that disables the test if it usually matches.]  *  * [In fact, we now use regmust in many cases to locate where the search  * starts in the string, so if regback is>= 0, the regmust search is never  * wasted effort.  The regback variable says how many characters back from  * where regmust matched is the earliest possible start of the match.  * For instance, /[a-z].foo/ has a regmust of 'foo' and a regback of 2.]  */
end_comment

begin_comment
comment|/*  * Structure for regexp "program".  This is essentially a linear encoding  * of a nondeterministic finite-state machine (aka syntax charts or  * "railroad normal form" in parsing technology).  Each node is an opcode  * plus a "next" pointer, possibly plus an operand.  "Next" pointers of  * all nodes except BRANCH implement concatenation; a "next" pointer with  * a BRANCH on both ends of it is connecting two alternatives.  (Here we  * have one of the subtle syntax dependencies:  an individual BRANCH (as  * opposed to a collection of them) is never concatenated with anything  * because of operator precedence.)  The operand of some types of node is  * a literal string; for others, it is a node leading into a sub-FSM.  In  * particular, the operand of a BRANCH node is the first node of the branch.  * (NB this is *not* a tree structure:  the tail of the branch connects  * to the thing following the set of BRANCHes.)  The opcodes are:  */
end_comment

begin_comment
comment|/*  * A node is one char of opcode followed by two chars of "next" pointer.  * "Next" pointers are stored as two 8-bit pieces, high order first.  The  * value is a positive offset from the opcode of the node containing it.  * An operand, if any, simply follows the node.  (Note that much of the  * code generation knows about this implicit relationship.)  *  * Using two bytes for the "next" pointer is vast overkill for most things,  * but allows patterns to get big without disasters.  *  * [The "next" pointer is always aligned on an even  * boundary, and reads the offset directly as a short.  Also, there is no  * special test to reverse the sign of BACK pointers since the offset is  * stored negative.]  */
end_comment

begin_struct
struct|struct
name|regnode_string
block|{
name|U8
name|flags
decl_stmt|;
name|U8
name|type
decl_stmt|;
name|U16
name|next_off
decl_stmt|;
name|U8
name|string
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regnode_1
block|{
name|U8
name|flags
decl_stmt|;
name|U8
name|type
decl_stmt|;
name|U16
name|next_off
decl_stmt|;
name|U32
name|arg1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regnode_2
block|{
name|U8
name|flags
decl_stmt|;
name|U8
name|type
decl_stmt|;
name|U16
name|next_off
decl_stmt|;
name|U16
name|arg1
decl_stmt|;
name|U16
name|arg2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* XXX fix this description.    Impose a limit of REG_INFTY on various pattern matching operations    to limit stack growth and to avoid "infinite" recursions. */
end_comment

begin_comment
comment|/* The default size for REG_INFTY is I16_MAX, which is the same as    SHORT_MAX (see perl.h).  Unfortunately I16 isn't necessarily 16 bits    (see handy.h).  On the Cray C90, sizeof(short)==4 and hence I16_MAX is    ((1<<31)-1), while on the Cray T90, sizeof(short)==8 and I16_MAX is    ((1<<63)-1).  To limit stack growth to reasonable sizes, supply a    smaller default. 	--Andy Dougherty  11 June 1998 */
end_comment

begin_if
if|#
directive|if
name|SHORTSIZE
operator|>
literal|2
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|REG_INFTY
end_ifndef

begin_define
define|#
directive|define
name|REG_INFTY
value|((1<<15)-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REG_INFTY
end_ifndef

begin_define
define|#
directive|define
name|REG_INFTY
value|I16_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARG_VALUE
parameter_list|(
name|arg
parameter_list|)
value|(arg)
end_define

begin_define
define|#
directive|define
name|ARG__SET
parameter_list|(
name|arg
parameter_list|,
name|val
parameter_list|)
value|((arg) = (val))
end_define

begin_define
define|#
directive|define
name|ARG
parameter_list|(
name|p
parameter_list|)
value|ARG_VALUE(ARG_LOC(p))
end_define

begin_define
define|#
directive|define
name|ARG1
parameter_list|(
name|p
parameter_list|)
value|ARG_VALUE(ARG1_LOC(p))
end_define

begin_define
define|#
directive|define
name|ARG2
parameter_list|(
name|p
parameter_list|)
value|ARG_VALUE(ARG2_LOC(p))
end_define

begin_define
define|#
directive|define
name|ARG_SET
parameter_list|(
name|p
parameter_list|,
name|val
parameter_list|)
value|ARG__SET(ARG_LOC(p), (val))
end_define

begin_define
define|#
directive|define
name|ARG1_SET
parameter_list|(
name|p
parameter_list|,
name|val
parameter_list|)
value|ARG__SET(ARG1_LOC(p), (val))
end_define

begin_define
define|#
directive|define
name|ARG2_SET
parameter_list|(
name|p
parameter_list|,
name|val
parameter_list|)
value|ARG__SET(ARG2_LOC(p), (val))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|NEXT_OFF
parameter_list|(
name|p
parameter_list|)
value|((p)->next_off)
end_define

begin_define
define|#
directive|define
name|NODE_ALIGN
parameter_list|(
name|node
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NODE_ALIGN_FILL
parameter_list|(
name|node
parameter_list|)
value|((node)->flags = 0xde)
end_define

begin_comment
comment|/* deadbeef */
end_comment

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
name|NEXT_OFF
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|NODE_ALIGN
parameter_list|(
name|node
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NODE_ALIGN_FILL
parameter_list|(
name|node
parameter_list|)
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
name|SIZE_ALIGN
value|NODE_ALIGN
end_define

begin_define
define|#
directive|define
name|OP
parameter_list|(
name|p
parameter_list|)
value|((p)->type)
end_define

begin_define
define|#
directive|define
name|OPERAND
parameter_list|(
name|p
parameter_list|)
value|(((struct regnode_string *)p)->string)
end_define

begin_define
define|#
directive|define
name|NODE_ALIGN
parameter_list|(
name|node
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ARG_LOC
parameter_list|(
name|p
parameter_list|)
value|(((struct regnode_1 *)p)->arg1)
end_define

begin_define
define|#
directive|define
name|ARG1_LOC
parameter_list|(
name|p
parameter_list|)
value|(((struct regnode_2 *)p)->arg1)
end_define

begin_define
define|#
directive|define
name|ARG2_LOC
parameter_list|(
name|p
parameter_list|)
value|(((struct regnode_2 *)p)->arg2)
end_define

begin_define
define|#
directive|define
name|NODE_STEP_REGNODE
value|1
end_define

begin_comment
comment|/* sizeof(regnode)/sizeof(regnode) */
end_comment

begin_define
define|#
directive|define
name|EXTRA_STEP_2ARGS
value|EXTRA_SIZE(struct regnode_2)
end_define

begin_define
define|#
directive|define
name|NODE_STEP_B
value|4
end_define

begin_define
define|#
directive|define
name|NEXTOPER
parameter_list|(
name|p
parameter_list|)
value|((p) + NODE_STEP_REGNODE)
end_define

begin_define
define|#
directive|define
name|PREVOPER
parameter_list|(
name|p
parameter_list|)
value|((p) - NODE_STEP_REGNODE)
end_define

begin_define
define|#
directive|define
name|FILL_ADVANCE_NODE
parameter_list|(
name|ptr
parameter_list|,
name|op
parameter_list|)
value|STMT_START { \     (ptr)->type = op;    (ptr)->next_off = 0;   (ptr)++; } STMT_END
end_define

begin_define
define|#
directive|define
name|FILL_ADVANCE_NODE_ARG
parameter_list|(
name|ptr
parameter_list|,
name|op
parameter_list|,
name|arg
parameter_list|)
value|STMT_START { \     ARG_SET(ptr, arg);  FILL_ADVANCE_NODE(ptr, op); (ptr) += 1; } STMT_END
end_define

begin_define
define|#
directive|define
name|MAGIC
value|0234
end_define

begin_define
define|#
directive|define
name|SIZE_ONLY
value|(PL_regcode ==&PL_regdummy)
end_define

begin_comment
comment|/* Flags for first parameter byte of ANYOF */
end_comment

begin_define
define|#
directive|define
name|ANYOF_INVERT
value|0x40
end_define

begin_define
define|#
directive|define
name|ANYOF_FOLD
value|0x20
end_define

begin_define
define|#
directive|define
name|ANYOF_LOCALE
value|0x10
end_define

begin_define
define|#
directive|define
name|ANYOF_ISA
value|0x0F
end_define

begin_define
define|#
directive|define
name|ANYOF_ALNUML
value|0x08
end_define

begin_define
define|#
directive|define
name|ANYOF_NALNUML
value|0x04
end_define

begin_define
define|#
directive|define
name|ANYOF_SPACEL
value|0x02
end_define

begin_define
define|#
directive|define
name|ANYOF_NSPACEL
value|0x01
end_define

begin_comment
comment|/* Utility macros for bitmap of ANYOF */
end_comment

begin_define
define|#
directive|define
name|ANYOF_BYTE
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(p)[1 + (((c)>> 3)& 31)]
end_define

begin_define
define|#
directive|define
name|ANYOF_BIT
parameter_list|(
name|c
parameter_list|)
value|(1<< ((c)& 7))
end_define

begin_define
define|#
directive|define
name|ANYOF_SET
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_BYTE(p,c) |=  ANYOF_BIT(c))
end_define

begin_define
define|#
directive|define
name|ANYOF_CLEAR
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_BYTE(p,c)&= ~ANYOF_BIT(c))
end_define

begin_define
define|#
directive|define
name|ANYOF_TEST
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_BYTE(p,c)&   ANYOF_BIT(c))
end_define

begin_define
define|#
directive|define
name|ANY_SKIP
value|((33 - 1)/sizeof(regnode) + 1)
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
name|CHARMASK
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
value|((int)*(p)&CHARMASK)
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
value|PL_regdummy
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
value|croak    ("/%.127s/: %s",  PL_regprecomp,m)
end_define

begin_define
define|#
directive|define
name|FAIL2
parameter_list|(
name|pat
parameter_list|,
name|m
parameter_list|)
value|re_croak2("/%.127s/: ",pat,PL_regprecomp,m)
end_define

begin_define
define|#
directive|define
name|EXTRA_SIZE
parameter_list|(
name|guy
parameter_list|)
value|((sizeof(guy)-1)/sizeof(struct regnode))
end_define

begin_define
define|#
directive|define
name|REG_SEEN_ZERO_LEN
value|1
end_define

begin_define
define|#
directive|define
name|REG_SEEN_LOOKBEHIND
value|2
end_define

begin_define
define|#
directive|define
name|REG_SEEN_GPOS
value|4
end_define

begin_define
define|#
directive|define
name|REG_SEEN_EVAL
value|8
end_define

begin_include
include|#
directive|include
file|"regnodes.h"
end_include

begin_comment
comment|/* The following have no fixed length. char* since we do strchr on it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
name|EXTCONST
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
name|EXTCONST
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
name|CURLYX
block|,
name|REF
block|,
name|REFF
block|,
name|REFFL
block|,
name|WHILEM
block|,
name|CURLYM
block|,
name|CURLYN
block|,
name|BRANCHJ
block|,
name|IFTHEN
block|,
name|SUSPEND
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
comment|/* The following always have a length of 1. char* since we do strchr on it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
name|EXTCONST
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
name|EXTCONST
name|char
name|simple
index|[]
init|=
block|{
name|ANY
block|,
name|SANY
block|,
name|ANYOF
block|,
name|ALNUM
block|,
name|ALNUML
block|,
name|NALNUM
block|,
name|NALNUML
block|,
name|SPACE
block|,
name|SPACEL
block|,
name|NSPACE
block|,
name|NSPACEL
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

end_unit

