begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    op.h  *  *    Copyright (c) 1991-1999, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_comment
comment|/*  * The fields of BASEOP are:  *	op_next		Pointer to next ppcode to execute after this one.  *			(Top level pre-grafted op points to first op,  *			but this is replaced when op is grafted in, when  *			this op will point to the real next op, and the new  *			parent takes over role of remembering starting op.)  *	op_ppaddr	Pointer to current ppcode's function.  *	op_type		The type of the operation.  *	op_flags	Flags common to all operations.  See OPf_* below.  *	op_private	Flags peculiar to a particular operation (BUT,  *			by default, set to the number of children until  *			the operation is privatized by a check routine,  *			which may or may not check number of children).  */
end_comment

begin_typedef
typedef|typedef
name|U32
name|PADOFFSET
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NOT_IN_PAD
value|((PADOFFSET) -1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING_OPS
end_ifdef

begin_define
define|#
directive|define
name|OPCODE
value|opcode
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPCODE
value|U16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BASEOP_DEFINITION
end_ifdef

begin_define
define|#
directive|define
name|BASEOP
value|BASEOP_DEFINITION
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BASEOP
define|\
value|OP*		op_next;		\     OP*		op_sibling;		\     OP*		(CPERLscope(*op_ppaddr))_((ARGSproto));		\     PADOFFSET	op_targ;		\     OPCODE	op_type;		\     U16		op_seq;			\     U8		op_flags;		\     U8		op_private;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OP_GIMME
parameter_list|(
name|op
parameter_list|,
name|dfl
parameter_list|)
define|\
value|(((op)->op_flags& OPf_WANT) == OPf_WANT_VOID   ? G_VOID   : \ 	 ((op)->op_flags& OPf_WANT) == OPf_WANT_SCALAR ? G_SCALAR : \ 	 ((op)->op_flags& OPf_WANT) == OPf_WANT_LIST   ? G_ARRAY   : \ 	 dfl)
end_define

begin_define
define|#
directive|define
name|GIMME_V
value|OP_GIMME(PL_op, block_gimme())
end_define

begin_comment
comment|/* Public flags */
end_comment

begin_define
define|#
directive|define
name|OPf_WANT
value|3
end_define

begin_comment
comment|/* Mask for "want" bits: */
end_comment

begin_define
define|#
directive|define
name|OPf_WANT_VOID
value|1
end_define

begin_comment
comment|/*   Want nothing */
end_comment

begin_define
define|#
directive|define
name|OPf_WANT_SCALAR
value|2
end_define

begin_comment
comment|/*   Want single value */
end_comment

begin_define
define|#
directive|define
name|OPf_WANT_LIST
value|3
end_define

begin_comment
comment|/*   Want list of any length */
end_comment

begin_define
define|#
directive|define
name|OPf_KIDS
value|4
end_define

begin_comment
comment|/* There is a firstborn child. */
end_comment

begin_define
define|#
directive|define
name|OPf_PARENS
value|8
end_define

begin_comment
comment|/* This operator was parenthesized. */
end_comment

begin_comment
comment|/*  (Or block needs explicit scope entry.) */
end_comment

begin_define
define|#
directive|define
name|OPf_REF
value|16
end_define

begin_comment
comment|/* Certified reference. */
end_comment

begin_comment
comment|/*  (Return container, not containee). */
end_comment

begin_define
define|#
directive|define
name|OPf_MOD
value|32
end_define

begin_comment
comment|/* Will modify (lvalue). */
end_comment

begin_define
define|#
directive|define
name|OPf_STACKED
value|64
end_define

begin_comment
comment|/* Some arg is arriving on the stack. */
end_comment

begin_define
define|#
directive|define
name|OPf_SPECIAL
value|128
end_define

begin_comment
comment|/* Do something weird for this op: */
end_comment

begin_comment
comment|/*  On local LVAL, don't init local value. */
end_comment

begin_comment
comment|/*  On OP_SORT, subroutine is inlined. */
end_comment

begin_comment
comment|/*  On OP_NOT, inversion was implicit. */
end_comment

begin_comment
comment|/*  On OP_LEAVE, don't restore curpm. */
end_comment

begin_comment
comment|/*  On truncate, we truncate filehandle */
end_comment

begin_comment
comment|/*  On control verbs, we saw no label */
end_comment

begin_comment
comment|/*  On flipflop, we saw ... instead of .. */
end_comment

begin_comment
comment|/*  On UNOPs, saw bare parens, e.g. eof(). */
end_comment

begin_comment
comment|/*  On OP_ENTERSUB || OP_NULL, saw a "do". */
end_comment

begin_comment
comment|/*  On OP_(ENTER|LEAVE)EVAL, don't clear $@ */
end_comment

begin_comment
comment|/*  On OP_ENTERITER, loop var is per-thread */
end_comment

begin_comment
comment|/* old names; don't use in new code, but don't break them, either */
end_comment

begin_define
define|#
directive|define
name|OPf_LIST
value|OPf_WANT_LIST
end_define

begin_define
define|#
directive|define
name|OPf_KNOW
value|OPf_WANT
end_define

begin_define
define|#
directive|define
name|GIMME
define|\
value|(PL_op->op_flags& OPf_WANT					\ 	   ? ((PL_op->op_flags& OPf_WANT) == OPf_WANT_LIST		\ 	      ? G_ARRAY							\ 	      : G_SCALAR)						\ 	   : dowantarray())
end_define

begin_comment
comment|/* Private for lvalues */
end_comment

begin_define
define|#
directive|define
name|OPpLVAL_INTRO
value|128
end_define

begin_comment
comment|/* Lvalue must be localized */
end_comment

begin_comment
comment|/* Private for OP_AASSIGN */
end_comment

begin_define
define|#
directive|define
name|OPpASSIGN_COMMON
value|64
end_define

begin_comment
comment|/* Left& right have syms in common. */
end_comment

begin_comment
comment|/* Private for OP_SASSIGN */
end_comment

begin_define
define|#
directive|define
name|OPpASSIGN_BACKWARDS
value|64
end_define

begin_comment
comment|/* Left& right switched. */
end_comment

begin_comment
comment|/* Private for OP_MATCH and OP_SUBST{,CONST} */
end_comment

begin_define
define|#
directive|define
name|OPpRUNTIME
value|64
end_define

begin_comment
comment|/* Pattern coming in on the stack */
end_comment

begin_comment
comment|/* Private for OP_TRANS */
end_comment

begin_define
define|#
directive|define
name|OPpTRANS_COUNTONLY
value|8
end_define

begin_define
define|#
directive|define
name|OPpTRANS_SQUASH
value|16
end_define

begin_define
define|#
directive|define
name|OPpTRANS_DELETE
value|32
end_define

begin_define
define|#
directive|define
name|OPpTRANS_COMPLEMENT
value|64
end_define

begin_comment
comment|/* Private for OP_REPEAT */
end_comment

begin_define
define|#
directive|define
name|OPpREPEAT_DOLIST
value|64
end_define

begin_comment
comment|/* List replication. */
end_comment

begin_comment
comment|/* Private for OP_ENTERSUB, OP_RV2?V, OP_?ELEM */
end_comment

begin_define
define|#
directive|define
name|OPpDEREF
value|(32|64)
end_define

begin_comment
comment|/* Want ref to something: */
end_comment

begin_define
define|#
directive|define
name|OPpDEREF_AV
value|32
end_define

begin_comment
comment|/*   Want ref to AV. */
end_comment

begin_define
define|#
directive|define
name|OPpDEREF_HV
value|64
end_define

begin_comment
comment|/*   Want ref to HV. */
end_comment

begin_define
define|#
directive|define
name|OPpDEREF_SV
value|(32|64)
end_define

begin_comment
comment|/*   Want ref to SV. */
end_comment

begin_comment
comment|/* OP_ENTERSUB only */
end_comment

begin_define
define|#
directive|define
name|OPpENTERSUB_DB
value|16
end_define

begin_comment
comment|/* Debug subroutine. */
end_comment

begin_define
define|#
directive|define
name|OPpENTERSUB_AMPER
value|8
end_define

begin_comment
comment|/* Used& form to call. */
end_comment

begin_comment
comment|/* OP_?ELEM only */
end_comment

begin_define
define|#
directive|define
name|OPpLVAL_DEFER
value|16
end_define

begin_comment
comment|/* Defer creation of array/hash elem */
end_comment

begin_comment
comment|/* for OP_RV2?V, lower bits carry hints */
end_comment

begin_comment
comment|/* Private for OP_CONST */
end_comment

begin_define
define|#
directive|define
name|OPpCONST_ENTERED
value|16
end_define

begin_comment
comment|/* Has been entered as symbol. */
end_comment

begin_define
define|#
directive|define
name|OPpCONST_ARYBASE
value|32
end_define

begin_comment
comment|/* Was a $[ translated to constant. */
end_comment

begin_define
define|#
directive|define
name|OPpCONST_BARE
value|64
end_define

begin_comment
comment|/* Was a bare word (filehandle?). */
end_comment

begin_comment
comment|/* Private for OP_FLIP/FLOP */
end_comment

begin_define
define|#
directive|define
name|OPpFLIP_LINENUM
value|64
end_define

begin_comment
comment|/* Range arg potentially a line num. */
end_comment

begin_comment
comment|/* Private for OP_LIST */
end_comment

begin_define
define|#
directive|define
name|OPpLIST_GUESSED
value|64
end_define

begin_comment
comment|/* Guessed that pushmark was needed. */
end_comment

begin_comment
comment|/* Private for OP_DELETE */
end_comment

begin_define
define|#
directive|define
name|OPpSLICE
value|64
end_define

begin_comment
comment|/* Operating on a list of keys */
end_comment

begin_comment
comment|/* Private for OP_SORT, OP_PRTF, OP_SPRINTF, string cmp'n, and case changers */
end_comment

begin_define
define|#
directive|define
name|OPpLOCALE
value|64
end_define

begin_comment
comment|/* Use locale */
end_comment

begin_comment
comment|/* Private for OP_THREADSV */
end_comment

begin_define
define|#
directive|define
name|OPpDONE_SVREF
value|64
end_define

begin_comment
comment|/* Been through newSVREF once */
end_comment

begin_struct
struct|struct
name|op
block|{
name|BASEOP
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unop
block|{
name|BASEOP
name|OP
modifier|*
name|op_first
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|binop
block|{
name|BASEOP
name|OP
modifier|*
name|op_first
decl_stmt|;
name|OP
modifier|*
name|op_last
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|logop
block|{
name|BASEOP
name|OP
modifier|*
name|op_first
decl_stmt|;
name|OP
modifier|*
name|op_other
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|condop
block|{
name|BASEOP
name|OP
modifier|*
name|op_first
decl_stmt|;
name|OP
modifier|*
name|op_true
decl_stmt|;
name|OP
modifier|*
name|op_false
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|listop
block|{
name|BASEOP
name|OP
modifier|*
name|op_first
decl_stmt|;
name|OP
modifier|*
name|op_last
decl_stmt|;
name|U32
name|op_children
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmop
block|{
name|BASEOP
name|OP
modifier|*
name|op_first
decl_stmt|;
name|OP
modifier|*
name|op_last
decl_stmt|;
name|U32
name|op_children
decl_stmt|;
name|OP
modifier|*
name|op_pmreplroot
decl_stmt|;
name|OP
modifier|*
name|op_pmreplstart
decl_stmt|;
name|PMOP
modifier|*
name|op_pmnext
decl_stmt|;
comment|/* list of all scanpats */
name|REGEXP
modifier|*
name|op_pmregexp
decl_stmt|;
comment|/* compiled expression */
name|U16
name|op_pmflags
decl_stmt|;
name|U16
name|op_pmpermflags
decl_stmt|;
name|U8
name|op_pmdynflags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMdf_USED
value|0x01
end_define

begin_comment
comment|/* pm has been used once already */
end_comment

begin_define
define|#
directive|define
name|PMdf_TAINTED
value|0x02
end_define

begin_comment
comment|/* pm compiled from tainted pattern */
end_comment

begin_define
define|#
directive|define
name|PMf_RETAINT
value|0x0001
end_define

begin_comment
comment|/* taint $1 etc. if target tainted */
end_comment

begin_define
define|#
directive|define
name|PMf_ONCE
value|0x0002
end_define

begin_comment
comment|/* use pattern only once per reset */
end_comment

begin_define
define|#
directive|define
name|PMf_REVERSED
value|0x0004
end_define

begin_comment
comment|/* Should be matched right->left */
end_comment

begin_define
define|#
directive|define
name|PMf_MAYBE_CONST
value|0x0008
end_define

begin_comment
comment|/* replacement contains variables */
end_comment

begin_define
define|#
directive|define
name|PMf_SKIPWHITE
value|0x0010
end_define

begin_comment
comment|/* skip leading whitespace for split */
end_comment

begin_define
define|#
directive|define
name|PMf_WHITE
value|0x0020
end_define

begin_comment
comment|/* pattern is \s+ */
end_comment

begin_define
define|#
directive|define
name|PMf_CONST
value|0x0040
end_define

begin_comment
comment|/* subst replacement is constant */
end_comment

begin_define
define|#
directive|define
name|PMf_KEEP
value|0x0080
end_define

begin_comment
comment|/* keep 1st runtime pattern forever */
end_comment

begin_define
define|#
directive|define
name|PMf_GLOBAL
value|0x0100
end_define

begin_comment
comment|/* pattern had a g modifier */
end_comment

begin_define
define|#
directive|define
name|PMf_CONTINUE
value|0x0200
end_define

begin_comment
comment|/* don't reset pos() if //g fails */
end_comment

begin_define
define|#
directive|define
name|PMf_EVAL
value|0x0400
end_define

begin_comment
comment|/* evaluating replacement as expr */
end_comment

begin_define
define|#
directive|define
name|PMf_LOCALE
value|0x0800
end_define

begin_comment
comment|/* use locale for character types */
end_comment

begin_define
define|#
directive|define
name|PMf_MULTILINE
value|0x1000
end_define

begin_comment
comment|/* assume multiple lines */
end_comment

begin_define
define|#
directive|define
name|PMf_SINGLELINE
value|0x2000
end_define

begin_comment
comment|/* assume single line */
end_comment

begin_define
define|#
directive|define
name|PMf_FOLD
value|0x4000
end_define

begin_comment
comment|/* case insensitivity */
end_comment

begin_define
define|#
directive|define
name|PMf_EXTENDED
value|0x8000
end_define

begin_comment
comment|/* chuck embedded whitespace */
end_comment

begin_comment
comment|/* mask of bits stored in regexp->reganch */
end_comment

begin_define
define|#
directive|define
name|PMf_COMPILETIME
value|(PMf_MULTILINE|PMf_SINGLELINE|PMf_LOCALE|PMf_FOLD|PMf_EXTENDED)
end_define

begin_struct
struct|struct
name|svop
block|{
name|BASEOP
name|SV
modifier|*
name|op_sv
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gvop
block|{
name|BASEOP
name|GV
modifier|*
name|op_gv
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pvop
block|{
name|BASEOP
name|char
modifier|*
name|op_pv
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|loop
block|{
name|BASEOP
name|OP
modifier|*
name|op_first
decl_stmt|;
name|OP
modifier|*
name|op_last
decl_stmt|;
name|U32
name|op_children
decl_stmt|;
name|OP
modifier|*
name|op_redoop
decl_stmt|;
name|OP
modifier|*
name|op_nextop
decl_stmt|;
name|OP
modifier|*
name|op_lastop
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cUNOP
value|((UNOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cBINOP
value|((BINOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cLISTOP
value|((LISTOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cLOGOP
value|((LOGOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cCONDOP
value|((CONDOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cPMOP
value|((PMOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cSVOP
value|((SVOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cGVOP
value|((GVOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cPVOP
value|((PVOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cCOP
value|((COP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cLOOP
value|((LOOP*)PL_op)
end_define

begin_define
define|#
directive|define
name|cUNOPo
value|((UNOP*)o)
end_define

begin_define
define|#
directive|define
name|cBINOPo
value|((BINOP*)o)
end_define

begin_define
define|#
directive|define
name|cLISTOPo
value|((LISTOP*)o)
end_define

begin_define
define|#
directive|define
name|cLOGOPo
value|((LOGOP*)o)
end_define

begin_define
define|#
directive|define
name|cCONDOPo
value|((CONDOP*)o)
end_define

begin_define
define|#
directive|define
name|cPMOPo
value|((PMOP*)o)
end_define

begin_define
define|#
directive|define
name|cSVOPo
value|((SVOP*)o)
end_define

begin_define
define|#
directive|define
name|cGVOPo
value|((GVOP*)o)
end_define

begin_define
define|#
directive|define
name|cPVOPo
value|((PVOP*)o)
end_define

begin_define
define|#
directive|define
name|cCVOPo
value|((CVOP*)o)
end_define

begin_define
define|#
directive|define
name|cCOPo
value|((COP*)o)
end_define

begin_define
define|#
directive|define
name|cLOOPo
value|((LOOP*)o)
end_define

begin_define
define|#
directive|define
name|kUNOP
value|((UNOP*)kid)
end_define

begin_define
define|#
directive|define
name|kBINOP
value|((BINOP*)kid)
end_define

begin_define
define|#
directive|define
name|kLISTOP
value|((LISTOP*)kid)
end_define

begin_define
define|#
directive|define
name|kLOGOP
value|((LOGOP*)kid)
end_define

begin_define
define|#
directive|define
name|kCONDOP
value|((CONDOP*)kid)
end_define

begin_define
define|#
directive|define
name|kPMOP
value|((PMOP*)kid)
end_define

begin_define
define|#
directive|define
name|kSVOP
value|((SVOP*)kid)
end_define

begin_define
define|#
directive|define
name|kGVOP
value|((GVOP*)kid)
end_define

begin_define
define|#
directive|define
name|kPVOP
value|((PVOP*)kid)
end_define

begin_define
define|#
directive|define
name|kCOP
value|((COP*)kid)
end_define

begin_define
define|#
directive|define
name|kLOOP
value|((LOOP*)kid)
end_define

begin_define
define|#
directive|define
name|Nullop
value|Null(OP*)
end_define

begin_comment
comment|/* Lowest byte of opargs */
end_comment

begin_define
define|#
directive|define
name|OA_MARK
value|1
end_define

begin_define
define|#
directive|define
name|OA_FOLDCONST
value|2
end_define

begin_define
define|#
directive|define
name|OA_RETSCALAR
value|4
end_define

begin_define
define|#
directive|define
name|OA_TARGET
value|8
end_define

begin_define
define|#
directive|define
name|OA_RETINTEGER
value|16
end_define

begin_define
define|#
directive|define
name|OA_OTHERINT
value|32
end_define

begin_define
define|#
directive|define
name|OA_DANGEROUS
value|64
end_define

begin_define
define|#
directive|define
name|OA_DEFGV
value|128
end_define

begin_comment
comment|/* The next 4 bits encode op class information */
end_comment

begin_define
define|#
directive|define
name|OA_CLASS_MASK
value|(15<< 8)
end_define

begin_define
define|#
directive|define
name|OA_BASEOP
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|OA_UNOP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|OA_BINOP
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|OA_LOGOP
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|OA_CONDOP
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|OA_LISTOP
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|OA_PMOP
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|OA_SVOP
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|OA_GVOP
value|(8<< 8)
end_define

begin_define
define|#
directive|define
name|OA_PVOP
value|(9<< 8)
end_define

begin_define
define|#
directive|define
name|OA_LOOP
value|(10<< 8)
end_define

begin_define
define|#
directive|define
name|OA_COP
value|(11<< 8)
end_define

begin_define
define|#
directive|define
name|OA_BASEOP_OR_UNOP
value|(12<< 8)
end_define

begin_define
define|#
directive|define
name|OA_FILESTATOP
value|(13<< 8)
end_define

begin_define
define|#
directive|define
name|OA_LOOPEXOP
value|(14<< 8)
end_define

begin_define
define|#
directive|define
name|OASHIFT
value|12
end_define

begin_comment
comment|/* Remaining nybbles of opargs */
end_comment

begin_define
define|#
directive|define
name|OA_SCALAR
value|1
end_define

begin_define
define|#
directive|define
name|OA_LIST
value|2
end_define

begin_define
define|#
directive|define
name|OA_AVREF
value|3
end_define

begin_define
define|#
directive|define
name|OA_HVREF
value|4
end_define

begin_define
define|#
directive|define
name|OA_CVREF
value|5
end_define

begin_define
define|#
directive|define
name|OA_FILEREF
value|6
end_define

begin_define
define|#
directive|define
name|OA_SCALARREF
value|7
end_define

begin_define
define|#
directive|define
name|OA_OPTIONAL
value|8
end_define

end_unit

