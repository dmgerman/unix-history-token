begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)yy.h	5.2 (Berkeley) 6/21/85  */
end_comment

begin_include
include|#
directive|include
file|"y.tab.h"
end_include

begin_undef
undef|#
directive|undef
name|CBSIZE
end_undef

begin_comment
comment|/* from paramsys/param.h */
end_comment

begin_comment
comment|/*  * INPUT/OUTPUT   */
end_comment

begin_comment
comment|/*  * The buffer for the input file is normally "ibuf".  * When files are included, however, this may be  * pushed down in the stack of currently active  * files. For this reason, the pointer ibp always  * references the i/o buffer of the current input file.  */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|ibuf
decl_stmt|,
modifier|*
name|ibp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Line and token buffers.  Charbuf is the character buffer for  * input lines, token the buffer for tokens returned  * by the scanner.  CBSIZE defines the maximum line  * length allowed on input and is doubtless too small.  * The token buffer should be a local array in yylex.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR16
end_ifdef

begin_define
define|#
directive|define
name|CBSIZE
value|161
end_define

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_define
define|#
directive|define
name|CBSIZE
value|1024
end_define

begin_endif
endif|#
directive|endif
endif|ADDR32
end_endif

begin_decl_stmt
name|char
name|charbuf
index|[
name|CBSIZE
index|]
decl_stmt|,
modifier|*
name|bufp
decl_stmt|,
name|token
index|[
name|CBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|digit
parameter_list|(
name|c
parameter_list|)
value|(c>= '0'&& c<= '9')
end_define

begin_define
define|#
directive|define
name|alph
parameter_list|(
name|c
parameter_list|)
value|((c>= 'a'&& c<= 'z') || (c>= 'A'&& c<= 'Z'))
end_define

begin_comment
comment|/*  * Flag to prevent reprinting current line after  * an error.  */
end_comment

begin_decl_stmt
name|char
name|yyprtd
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * The following variables are maintained by  * the scanner in the file lex and used in scanning  * and in parsing.  *  * The variable yychar is the current scanner character.  * Currently, the scanner must be called as  *	yychar = yylex()  * even though it should set yychar itself.  * Yychar has value YEOF at end of file, and negative value if  * there is no yychar, e.g. after a shift in the parser.  *  * The variable yycol is the current column in the line whose number  * is given by yyline.  Yyecol and yyeline give the position for an  * error message to flag, usually the start of an input token.  * Yylval is the semantic return from the scanner.  *  * In fact all of these variables are "per token".  * In the usual case, only the copies in the scanner token structure  * 'Y' are used, and the #defines below serve to make them look  * like variables.  *  * For the purposes of the error recovery, however, they are copied  * and restored quite freely.  For the error recovery also, the  * file name which the input line this token is on and the seek  * pointer of this line in its source file are saved as yyefile  * and yyseekp.  The global variable yylinpt is the seek pointer  * of the current input line.  */
end_comment

begin_decl_stmt
name|int
name|yycol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yyseqid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yysavc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yylinpt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* *** NOTE ***  * It would be much better to not have the Yyeline and Yyefile  * in the scanner structure and to have a mechanism for mapping  * seqid's to these globally.  */
end_comment

begin_struct
struct|struct
name|yytok
block|{
name|int
name|Yychar
decl_stmt|;
name|int
name|Yylval
decl_stmt|;
name|int
name|Yyecol
decl_stmt|;
name|int
name|Yyeline
decl_stmt|;
name|int
name|Yyseekp
decl_stmt|;
name|char
modifier|*
name|Yyefile
decl_stmt|;
name|int
name|Yyeseqid
decl_stmt|;
block|}
name|Y
struct|,
name|OY
struct|;
end_struct

begin_define
define|#
directive|define
name|yychar
value|Y.Yychar
end_define

begin_define
define|#
directive|define
name|yylval
value|Y.Yylval
end_define

begin_define
define|#
directive|define
name|yyecol
value|Y.Yyecol
end_define

begin_define
define|#
directive|define
name|yyeline
value|Y.Yyeline
end_define

begin_define
define|#
directive|define
name|yyseekp
value|Y.Yyseekp
end_define

begin_define
define|#
directive|define
name|yyefile
value|Y.Yyefile
end_define

begin_define
define|#
directive|define
name|yyeseqid
value|Y.Yyeseqid
end_define

begin_comment
comment|/* Semantic Stack so that y.tab.c will lint */
end_comment

begin_union
union|union
name|semstack
block|{
name|int
name|i_entry
decl_stmt|;
name|struct
name|nl
modifier|*
name|nl_entry
decl_stmt|;
name|struct
name|tnode
modifier|*
name|tr_entry
decl_stmt|;
name|char
modifier|*
name|cptr
decl_stmt|;
block|}
name|yyval
union|;
end_union

begin_comment
comment|/*  * Yyval is the semantic value returned by a reduction.  * It is what "$$" is expanded to by yacc.  */
end_comment

begin_decl_stmt
name|int
modifier|*
name|Ps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * N is the length of a reduction.  * Used externally by "lineof" to get the left and  * right margins for a reduction.  */
end_comment

begin_decl_stmt
name|int
name|N
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Definitions for looking up keywords.  * The keyword array is called yykey, and  * lastkey points at the end of it.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|lastkey
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|kwtab
block|{
name|char
modifier|*
name|kw_str
decl_stmt|;
name|int
name|kw_val
decl_stmt|;
block|}
name|yykey
index|[]
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*  * ERROR RECOVERY EXTERNALS  */
end_comment

begin_define
define|#
directive|define
name|CLIMIT
value|40
end_define

begin_comment
comment|/* see yyrecover.c */
end_comment

begin_function_decl
name|char
modifier|*
name|tokname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|charname
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|classes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Tokens which yacc doesn't define  */
end_comment

begin_define
define|#
directive|define
name|YEOF
value|0
end_define

begin_define
define|#
directive|define
name|ERROR
value|256
end_define

begin_comment
comment|/*  * Limit on the number of syntax errors  */
end_comment

begin_define
define|#
directive|define
name|MAXSYNERR
value|100
end_define

begin_comment
comment|/*  * Big costs  */
end_comment

begin_define
define|#
directive|define
name|HUGE
value|50
end_define

begin_define
define|#
directive|define
name|INFINITY
value|100
end_define

begin_comment
comment|/*  * Kinds of panics  */
end_comment

begin_define
define|#
directive|define
name|PDECL
value|0
end_define

begin_define
define|#
directive|define
name|PSTAT
value|1
end_define

begin_define
define|#
directive|define
name|PEXPR
value|2
end_define

begin_define
define|#
directive|define
name|PPROG
value|3
end_define

begin_define
define|#
directive|define
name|yyresume
parameter_list|()
value|yyResume = 1;
end_define

begin_decl_stmt
name|char
name|yyResume
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|dquote
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|PC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ
end_ifndef

begin_decl_stmt
name|char
name|errout
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|OBJ
end_endif

begin_endif
endif|#
directive|endif
endif|PC
end_endif

begin_comment
comment|/*  * Yyidwant and yyidhave are the namelist classes  * of identifiers associated with a identifier reduce  * error, set before the recovery is called.  * Since they may be set again during the forward move  * they must be saved by yyrecover, which uses them in printing  * error messages.  */
end_comment

begin_decl_stmt
name|int
name|yyidhave
decl_stmt|,
name|yyidwant
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * The variables yy*shifts are used to prevent looping and the printing  * of spurious messages in the parser.  Yyshifts gives the number of  * true input shifts since the last corrective action.  YyOshifts  * is the value of yyshifts before it was last cleared, and is used  * by yyPerror in yypanic.c to suppress messages.  *  * Yytshifts counts true input shifts.  It is used to prevent looping  * inserting unique symbols.  If yytshifts == yyTshifts (local to  * yyrecover.c) then there has been no shift over true input since  * the last unique symbol insertion.  We refuse, in this case,  * to insert more unique symbols so as to prevent looping.  *  * The recovery cannot loop because it guarantees the progress of the  * parse, i.e.:  *  *	1) Any insertion guarantees to shift over 2 symbols, a replacement  *	   over one symbol.  *  *	2) Unique symbol insertions are limited to one for each true  *	   symbol of input, or "safe" insertion of the keywords "end"  *	   and "until" at zero cost (safe since these are know to match  *	   stack that cannot have been generated - e.g. "begin" or "repeat")  *  *	3) We never panic more than once from a given state without  *	   shifting over input, i.e. we force the parse stack to shrink  *	   after each unsuccessful panic.  */
end_comment

begin_decl_stmt
name|int
name|yyshifts
decl_stmt|,
name|yyOshifts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|yytshifts
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PXP
end_ifdef

begin_escape
end_escape

begin_comment
comment|/*  * Identifier class definitions  */
end_comment

begin_define
define|#
directive|define
name|UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|CONST
value|1
end_define

begin_define
define|#
directive|define
name|TYPE
value|2
end_define

begin_define
define|#
directive|define
name|VAR
value|3
end_define

begin_define
define|#
directive|define
name|ARRAY
value|4
end_define

begin_define
define|#
directive|define
name|PTRFILE
value|5
end_define

begin_define
define|#
directive|define
name|RECORD
value|6
end_define

begin_define
define|#
directive|define
name|FIELD
value|7
end_define

begin_define
define|#
directive|define
name|PROC
value|8
end_define

begin_define
define|#
directive|define
name|FUNC
value|9
end_define

begin_define
define|#
directive|define
name|FVAR
value|10
end_define

begin_define
define|#
directive|define
name|REF
value|11
end_define

begin_define
define|#
directive|define
name|PTR
value|12
end_define

begin_define
define|#
directive|define
name|FILET
value|13
end_define

begin_define
define|#
directive|define
name|SET
value|14
end_define

begin_define
define|#
directive|define
name|RANGE
value|15
end_define

begin_define
define|#
directive|define
name|LABEL
value|16
end_define

begin_define
define|#
directive|define
name|WITHPTR
value|17
end_define

begin_define
define|#
directive|define
name|SCAL
value|18
end_define

begin_define
define|#
directive|define
name|STR
value|19
end_define

begin_define
define|#
directive|define
name|PROG
value|20
end_define

begin_define
define|#
directive|define
name|IMPROPER
value|21
end_define

begin_escape
end_escape

begin_comment
comment|/*  * COMMENT FORMATTING DEFINITIONS  */
end_comment

begin_comment
comment|/*  * Count of tokens on this input line  * Note that this can be off if input is not syntactically correct.  */
end_comment

begin_decl_stmt
name|int
name|yytokcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yywhcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Types of comments  */
end_comment

begin_define
define|#
directive|define
name|CLMARG
value|0
end_define

begin_define
define|#
directive|define
name|CALIGN
value|1
end_define

begin_define
define|#
directive|define
name|CTRAIL
value|2
end_define

begin_define
define|#
directive|define
name|CRMARG
value|3
end_define

begin_define
define|#
directive|define
name|CSRMARG
value|4
end_define

begin_define
define|#
directive|define
name|CNL
value|5
end_define

begin_define
define|#
directive|define
name|CNLBL
value|6
end_define

begin_define
define|#
directive|define
name|CFORM
value|7
end_define

begin_define
define|#
directive|define
name|CINCLUD
value|8
end_define

begin_comment
comment|/*  * Comment structure  * Cmhp is the head of the current list of comments  */
end_comment

begin_struct
struct|struct
name|comment
block|{
name|struct
name|comment
modifier|*
name|cmnext
decl_stmt|;
name|int
name|cmdelim
decl_stmt|;
name|struct
name|commline
modifier|*
name|cml
decl_stmt|;
name|int
name|cmjust
decl_stmt|;
name|int
name|cmseqid
decl_stmt|;
block|}
modifier|*
name|cmhp
struct|;
end_struct

begin_comment
comment|/*  * Structure for holding a comment line  */
end_comment

begin_struct
struct|struct
name|commline
block|{
name|char
modifier|*
name|cmtext
decl_stmt|;
name|int
name|cmcol
decl_stmt|;
comment|/* Only used for first line of comment currently */
name|struct
name|commline
modifier|*
name|cml
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|W
block|{
name|int
name|Wseqid
decl_stmt|;
name|int
name|Wcol
decl_stmt|;
block|}
name|yyw
index|[
name|MAXDEPTH
operator|+
literal|1
index|]
struct|,
modifier|*
name|yypw
struct|;
end_struct

begin_define
define|#
directive|define
name|commform
parameter_list|()
value|quickcomm(CFORM)
end_define

begin_define
define|#
directive|define
name|commnl
parameter_list|()
value|quickcomm(CNL)
end_define

begin_define
define|#
directive|define
name|commnlbl
parameter_list|()
value|quickcomm(CNLBL)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

