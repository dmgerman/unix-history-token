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
name|str_len
decl_stmt|;
name|U8
name|type
decl_stmt|;
name|U16
name|next_off
decl_stmt|;
name|char
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

begin_define
define|#
directive|define
name|ANYOF_BITMAP_SIZE
value|32
end_define

begin_comment
comment|/* 256 b/(8 b/B) */
end_comment

begin_define
define|#
directive|define
name|ANYOF_CLASSBITMAP_SIZE
value|4
end_define

begin_struct
struct|struct
name|regnode_charclass
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
name|char
name|bitmap
index|[
name|ANYOF_BITMAP_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regnode_charclass_class
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
name|char
name|bitmap
index|[
name|ANYOF_BITMAP_SIZE
index|]
decl_stmt|;
name|char
name|classflags
index|[
name|ANYOF_CLASSBITMAP_SIZE
index|]
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
name|MASK
parameter_list|(
name|p
parameter_list|)
value|((char*)OPERAND(p))
end_define

begin_define
define|#
directive|define
name|STR_LEN
parameter_list|(
name|p
parameter_list|)
value|(((struct regnode_string *)p)->str_len)
end_define

begin_define
define|#
directive|define
name|STRING
parameter_list|(
name|p
parameter_list|)
value|(((struct regnode_string *)p)->string)
end_define

begin_define
define|#
directive|define
name|STR_SZ
parameter_list|(
name|l
parameter_list|)
value|((l + sizeof(regnode) - 1) / sizeof(regnode))
end_define

begin_define
define|#
directive|define
name|NODE_SZ_STR
parameter_list|(
name|p
parameter_list|)
value|(STR_SZ(STR_LEN(p))+1)
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
name|REG_MAGIC
value|0234
end_define

begin_define
define|#
directive|define
name|SIZE_ONLY
value|(PL_regcode ==&PL_regdummy)
end_define

begin_comment
comment|/* Flags for node->flags of ANYOF */
end_comment

begin_define
define|#
directive|define
name|ANYOF_CLASS
value|0x08
end_define

begin_define
define|#
directive|define
name|ANYOF_INVERT
value|0x04
end_define

begin_define
define|#
directive|define
name|ANYOF_FOLD
value|0x02
end_define

begin_define
define|#
directive|define
name|ANYOF_LOCALE
value|0x01
end_define

begin_comment
comment|/* Used for regstclass only */
end_comment

begin_define
define|#
directive|define
name|ANYOF_EOS
value|0x10
end_define

begin_comment
comment|/* Can match an empty string too */
end_comment

begin_comment
comment|/* Character classes for node->classflags of ANYOF */
end_comment

begin_comment
comment|/* Should be synchronized with a table in regprop() */
end_comment

begin_comment
comment|/* 2n should pair with 2n+1 */
end_comment

begin_define
define|#
directive|define
name|ANYOF_ALNUM
value|0
end_define

begin_comment
comment|/* \w, PL_utf8_alnum, utf8::IsWord, ALNUM */
end_comment

begin_define
define|#
directive|define
name|ANYOF_NALNUM
value|1
end_define

begin_define
define|#
directive|define
name|ANYOF_SPACE
value|2
end_define

begin_comment
comment|/* \s */
end_comment

begin_define
define|#
directive|define
name|ANYOF_NSPACE
value|3
end_define

begin_define
define|#
directive|define
name|ANYOF_DIGIT
value|4
end_define

begin_define
define|#
directive|define
name|ANYOF_NDIGIT
value|5
end_define

begin_define
define|#
directive|define
name|ANYOF_ALNUMC
value|6
end_define

begin_comment
comment|/* isalnum(3), utf8::IsAlnum, ALNUMC */
end_comment

begin_define
define|#
directive|define
name|ANYOF_NALNUMC
value|7
end_define

begin_define
define|#
directive|define
name|ANYOF_ALPHA
value|8
end_define

begin_define
define|#
directive|define
name|ANYOF_NALPHA
value|9
end_define

begin_define
define|#
directive|define
name|ANYOF_ASCII
value|10
end_define

begin_define
define|#
directive|define
name|ANYOF_NASCII
value|11
end_define

begin_define
define|#
directive|define
name|ANYOF_CNTRL
value|12
end_define

begin_define
define|#
directive|define
name|ANYOF_NCNTRL
value|13
end_define

begin_define
define|#
directive|define
name|ANYOF_GRAPH
value|14
end_define

begin_define
define|#
directive|define
name|ANYOF_NGRAPH
value|15
end_define

begin_define
define|#
directive|define
name|ANYOF_LOWER
value|16
end_define

begin_define
define|#
directive|define
name|ANYOF_NLOWER
value|17
end_define

begin_define
define|#
directive|define
name|ANYOF_PRINT
value|18
end_define

begin_define
define|#
directive|define
name|ANYOF_NPRINT
value|19
end_define

begin_define
define|#
directive|define
name|ANYOF_PUNCT
value|20
end_define

begin_define
define|#
directive|define
name|ANYOF_NPUNCT
value|21
end_define

begin_define
define|#
directive|define
name|ANYOF_UPPER
value|22
end_define

begin_define
define|#
directive|define
name|ANYOF_NUPPER
value|23
end_define

begin_define
define|#
directive|define
name|ANYOF_XDIGIT
value|24
end_define

begin_define
define|#
directive|define
name|ANYOF_NXDIGIT
value|25
end_define

begin_define
define|#
directive|define
name|ANYOF_PSXSPC
value|26
end_define

begin_comment
comment|/* POSIX space: \s plus the vertical tab */
end_comment

begin_define
define|#
directive|define
name|ANYOF_NPSXSPC
value|27
end_define

begin_define
define|#
directive|define
name|ANYOF_BLANK
value|28
end_define

begin_comment
comment|/* GNU extension: space and tab */
end_comment

begin_define
define|#
directive|define
name|ANYOF_NBLANK
value|29
end_define

begin_define
define|#
directive|define
name|ANYOF_MAX
value|32
end_define

begin_comment
comment|/* Backward source code compatibility. */
end_comment

begin_define
define|#
directive|define
name|ANYOF_ALNUML
value|ANYOF_ALNUM
end_define

begin_define
define|#
directive|define
name|ANYOF_NALNUML
value|ANYOF_NALNUM
end_define

begin_define
define|#
directive|define
name|ANYOF_SPACEL
value|ANYOF_SPACE
end_define

begin_define
define|#
directive|define
name|ANYOF_NSPACEL
value|ANYOF_NSPACE
end_define

begin_comment
comment|/* Utility macros for the bitmap and classes of ANYOF */
end_comment

begin_define
define|#
directive|define
name|ANYOF_SIZE
value|(sizeof(struct regnode_charclass))
end_define

begin_define
define|#
directive|define
name|ANYOF_CLASS_SIZE
value|(sizeof(struct regnode_charclass_class))
end_define

begin_define
define|#
directive|define
name|ANYOF_FLAGS
parameter_list|(
name|p
parameter_list|)
value|((p)->flags)
end_define

begin_define
define|#
directive|define
name|ANYOF_FLAGS_ALL
value|0xff
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
name|ANYOF_CLASS_BYTE
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(((struct regnode_charclass_class*)(p))->classflags[((c)>> 3)& 3])
end_define

begin_define
define|#
directive|define
name|ANYOF_CLASS_SET
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_CLASS_BYTE(p, c) |=  ANYOF_BIT(c))
end_define

begin_define
define|#
directive|define
name|ANYOF_CLASS_CLEAR
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_CLASS_BYTE(p, c)&= ~ANYOF_BIT(c))
end_define

begin_define
define|#
directive|define
name|ANYOF_CLASS_TEST
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_CLASS_BYTE(p, c)&   ANYOF_BIT(c))
end_define

begin_define
define|#
directive|define
name|ANYOF_CLASS_ZERO
parameter_list|(
name|ret
parameter_list|)
value|Zero(((struct regnode_charclass_class*)(ret))->classflags, ANYOF_CLASSBITMAP_SIZE, char)
end_define

begin_define
define|#
directive|define
name|ANYOF_BITMAP_ZERO
parameter_list|(
name|ret
parameter_list|)
value|Zero(((struct regnode_charclass*)(ret))->bitmap, ANYOF_BITMAP_SIZE, char)
end_define

begin_define
define|#
directive|define
name|ANYOF_BITMAP
parameter_list|(
name|p
parameter_list|)
value|(((struct regnode_charclass*)(p))->bitmap)
end_define

begin_define
define|#
directive|define
name|ANYOF_BITMAP_BYTE
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_BITMAP(p)[((c)>> 3)& 31])
end_define

begin_define
define|#
directive|define
name|ANYOF_BITMAP_SET
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_BITMAP_BYTE(p, c) |=  ANYOF_BIT(c))
end_define

begin_define
define|#
directive|define
name|ANYOF_BITMAP_CLEAR
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_BITMAP_BYTE(p, c)&= ~ANYOF_BIT(c))
end_define

begin_define
define|#
directive|define
name|ANYOF_BITMAP_TEST
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|(ANYOF_BITMAP_BYTE(p, c)&   ANYOF_BIT(c))
end_define

begin_define
define|#
directive|define
name|ANYOF_SKIP
value|((ANYOF_SIZE - 1)/sizeof(regnode))
end_define

begin_define
define|#
directive|define
name|ANYOF_CLASS_SKIP
value|((ANYOF_CLASS_SIZE - 1)/sizeof(regnode))
end_define

begin_define
define|#
directive|define
name|ANYOF_CLASS_ADD_SKIP
value|(ANYOF_CLASS_SKIP - ANYOF_SKIP)
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
value|((int)*(U8*)(p))
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

begin_decl_stmt
name|START_EXTERN_C
include|#
directive|include
file|"regnodes.h"
comment|/* The following have no fixed length. U8 so we can do strchr() on it. */
ifndef|#
directive|ifndef
name|DOINIT
name|EXTCONST
name|U8
name|PL_varies
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXTCONST
name|U8
name|PL_varies
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
name|CLUMP
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
comment|/* The following always have a length of 1. U8 we can do strchr() on it. */
end_comment

begin_comment
comment|/* (Note that length 1 means "one character" under UTF8, not "one octet".) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
name|EXTCONST
name|U8
name|PL_simple
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXTCONST
name|U8
name|PL_simple
index|[]
init|=
block|{
name|REG_ANY
block|,
name|ANYUTF8
block|,
name|SANY
block|,
name|SANYUTF8
block|,
name|ANYOF
block|,
name|ANYOFUTF8
block|,
name|ALNUM
block|,
name|ALNUMUTF8
block|,
name|ALNUML
block|,
name|ALNUMLUTF8
block|,
name|NALNUM
block|,
name|NALNUMUTF8
block|,
name|NALNUML
block|,
name|NALNUMLUTF8
block|,
name|SPACE
block|,
name|SPACEUTF8
block|,
name|SPACEL
block|,
name|SPACELUTF8
block|,
name|NSPACE
block|,
name|NSPACEUTF8
block|,
name|NSPACEL
block|,
name|NSPACELUTF8
block|,
name|DIGIT
block|,
name|DIGITUTF8
block|,
name|NDIGIT
block|,
name|NDIGITUTF8
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|END_EXTERN_C
end_macro

begin_typedef
typedef|typedef
struct|struct
name|re_scream_pos_data_s
block|{
name|char
modifier|*
modifier|*
name|scream_olds
decl_stmt|;
comment|/* match pos */
name|I32
modifier|*
name|scream_pos
decl_stmt|;
comment|/* Internal iterator of scream. */
block|}
name|re_scream_pos_data
typedef|;
end_typedef

begin_struct
struct|struct
name|reg_data
block|{
name|U32
name|count
decl_stmt|;
name|U8
modifier|*
name|what
decl_stmt|;
name|void
modifier|*
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reg_substr_datum
block|{
name|I32
name|min_offset
decl_stmt|;
name|I32
name|max_offset
decl_stmt|;
name|SV
modifier|*
name|substr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reg_substr_data
block|{
name|struct
name|reg_substr_datum
name|data
index|[
literal|3
index|]
decl_stmt|;
comment|/* Actual array */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|anchored_substr
value|substrs->data[0].substr
end_define

begin_define
define|#
directive|define
name|anchored_offset
value|substrs->data[0].min_offset
end_define

begin_define
define|#
directive|define
name|float_substr
value|substrs->data[1].substr
end_define

begin_define
define|#
directive|define
name|float_min_offset
value|substrs->data[1].min_offset
end_define

begin_define
define|#
directive|define
name|float_max_offset
value|substrs->data[1].max_offset
end_define

begin_define
define|#
directive|define
name|check_substr
value|substrs->data[2].substr
end_define

begin_define
define|#
directive|define
name|check_offset_min
value|substrs->data[2].min_offset
end_define

begin_define
define|#
directive|define
name|check_offset_max
value|substrs->data[2].max_offset
end_define

end_unit

