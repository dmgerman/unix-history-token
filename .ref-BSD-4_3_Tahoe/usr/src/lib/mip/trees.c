begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)trees.c	4.36 (Berkeley) 5/11/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"pass1.h"
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|int
name|bdebug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|adebug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern ddebug;
end_extern

begin_extern
extern|extern eprint(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* corrections when in violation of lint */
end_comment

begin_comment
comment|/*	some special actions, used in finding the type of nodes */
end_comment

begin_define
define|#
directive|define
name|NCVT
value|01
end_define

begin_define
define|#
directive|define
name|PUN
value|02
end_define

begin_define
define|#
directive|define
name|TYPL
value|04
end_define

begin_define
define|#
directive|define
name|TYPR
value|010
end_define

begin_define
define|#
directive|define
name|TYMATCH
value|040
end_define

begin_define
define|#
directive|define
name|LVAL
value|0100
end_define

begin_define
define|#
directive|define
name|CVTO
value|0200
end_define

begin_define
define|#
directive|define
name|CVTL
value|0400
end_define

begin_define
define|#
directive|define
name|CVTR
value|01000
end_define

begin_define
define|#
directive|define
name|PTMATCH
value|02000
end_define

begin_define
define|#
directive|define
name|OTHER
value|04000
end_define

begin_define
define|#
directive|define
name|NCVTR
value|010000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BUG1
end_ifndef

begin_macro
name|printact
argument_list|(
argument|t
argument_list|,
argument|acts
argument_list|)
end_macro

begin_decl_stmt
name|NODE
modifier|*
name|t
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acts
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
struct|struct
name|actions
block|{
name|int
name|a_bit
decl_stmt|;
name|char
modifier|*
name|a_name
decl_stmt|;
block|}
name|actions
index|[]
init|=
block|{
block|{
name|PUN
block|,
literal|"PUN"
block|}
block|,
block|{
name|CVTL
block|,
literal|"CVTL"
block|}
block|,
block|{
name|CVTR
block|,
literal|"CVTR"
block|}
block|,
block|{
name|TYPL
block|,
literal|"TYPL"
block|}
block|,
block|{
name|TYPR
block|,
literal|"TYPR"
block|}
block|,
block|{
name|TYMATCH
block|,
literal|"TYMATCH"
block|}
block|,
block|{
name|PTMATCH
block|,
literal|"PTMATCH"
block|}
block|,
block|{
name|LVAL
block|,
literal|"LVAL"
block|}
block|,
block|{
name|CVTO
block|,
literal|"CVTO"
block|}
block|,
block|{
name|NCVT
block|,
literal|"NCVT"
block|}
block|,
block|{
name|OTHER
block|,
literal|"OTHER"
block|}
block|,
block|{
name|NCVTR
block|,
literal|"NCVTR"
block|}
block|,
block|{
literal|0
block|}
block|}
struct|;
specifier|register
name|struct
name|actions
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|sep
init|=
literal|" "
decl_stmt|;
name|printf
argument_list|(
literal|"actions"
argument_list|)
expr_stmt|;
for|for
control|(
name|p
operator|=
name|actions
init|;
name|p
operator|->
name|a_name
condition|;
name|p
operator|++
control|)
if|if
condition|(
name|p
operator|->
name|a_bit
operator|&
name|acts
condition|)
block|{
name|printf
argument_list|(
literal|"%s%s"
argument_list|,
name|sep
argument_list|,
name|p
operator|->
name|a_name
argument_list|)
expr_stmt|;
name|sep
operator|=
literal|"|"
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|bdebug
condition|)
block|{
name|printf
argument_list|(
literal|" for:\n"
argument_list|)
expr_stmt|;
name|fwalk
argument_list|(
name|t
argument_list|,
name|eprint
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* node conventions:  	NAME:	rval>0 is stab index for external 		rval<0 is -inlabel number 		lval is offset in bits 	ICON:	lval has the value 		rval has the STAB index, or - label number, 			if a name whose address is in the constant 		rval = NONAME means no name 	REG:	rval is reg. identification cookie  	*/
end_comment

begin_function
name|NODE
modifier|*
name|buildtree
parameter_list|(
name|o
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|)
specifier|register
name|NODE
modifier|*
name|l
decl_stmt|,
decl|*
name|r
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|NODE
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
specifier|register
name|actions
expr_stmt|;
specifier|register
name|opty
expr_stmt|;
specifier|register
name|struct
name|symtab
modifier|*
name|sp
decl_stmt|;
specifier|register
name|NODE
modifier|*
name|lr
decl_stmt|,
modifier|*
name|ll
decl_stmt|;
name|NODE
modifier|*
name|fixargs
parameter_list|()
function_decl|;
name|int
name|i
decl_stmt|;
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|bdebug
condition|)
name|printf
argument_list|(
literal|"buildtree( %s, %o, %o )\n"
argument_list|,
name|opst
index|[
name|o
index|]
argument_list|,
name|l
argument_list|,
name|r
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|opty
operator|=
name|optype
argument_list|(
name|o
argument_list|)
expr_stmt|;
comment|/* check for constants */
if|if
condition|(
name|opty
operator|==
name|UTYPE
operator|&&
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
condition|)
block|{
switch|switch
condition|(
name|o
condition|)
block|{
case|case
name|NOT
case|:
if|if
condition|(
name|hflag
condition|)
name|werror
argument_list|(
literal|"constant argument to NOT"
argument_list|)
expr_stmt|;
case|case
name|UNARY
name|MINUS
case|:
case|case
name|COMPL
case|:
if|if
condition|(
name|conval
argument_list|(
name|l
argument_list|,
name|o
argument_list|,
name|l
argument_list|)
condition|)
return|return
operator|(
name|l
operator|)
return|;
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|opty
operator|==
name|UTYPE
operator|&&
operator|(
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|FCON
operator|||
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|DCON
operator|)
condition|)
block|{
switch|switch
condition|(
name|o
condition|)
block|{
case|case
name|NOT
case|:
if|if
condition|(
name|hflag
condition|)
name|werror
argument_list|(
literal|"constant argument to NOT"
argument_list|)
expr_stmt|;
if|if
condition|(
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|FCON
condition|)
name|l
operator|->
name|tn
operator|.
name|lval
operator|=
name|l
operator|->
name|fpn
operator|.
name|fval
operator|==
literal|0.0
expr_stmt|;
else|else
name|l
operator|->
name|tn
operator|.
name|lval
operator|=
name|l
operator|->
name|dpn
operator|.
name|dval
operator|==
literal|0.0
expr_stmt|;
name|l
operator|->
name|tn
operator|.
name|rval
operator|=
name|NONAME
expr_stmt|;
name|l
operator|->
name|in
operator|.
name|op
operator|=
name|ICON
expr_stmt|;
name|l
operator|->
name|fn
operator|.
name|csiz
operator|=
name|l
operator|->
name|in
operator|.
name|type
operator|=
name|INT
expr_stmt|;
name|l
operator|->
name|fn
operator|.
name|cdim
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|l
operator|)
return|;
case|case
name|UNARY
name|MINUS
case|:
if|if
condition|(
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|FCON
condition|)
name|l
operator|->
name|fpn
operator|.
name|fval
operator|=
operator|-
name|l
operator|->
name|fpn
operator|.
name|fval
expr_stmt|;
else|else
name|l
operator|->
name|dpn
operator|.
name|dval
operator|=
operator|-
name|l
operator|->
name|dpn
operator|.
name|dval
expr_stmt|;
return|return
operator|(
name|l
operator|)
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|o
operator|==
name|QUEST
operator|&&
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
condition|)
block|{
name|l
operator|->
name|in
operator|.
name|op
operator|=
name|FREE
expr_stmt|;
name|r
operator|->
name|in
operator|.
name|op
operator|=
name|FREE
expr_stmt|;
if|if
condition|(
name|l
operator|->
name|tn
operator|.
name|lval
condition|)
block|{
name|tfree
argument_list|(
name|r
operator|->
name|in
operator|.
name|right
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|->
name|in
operator|.
name|left
operator|)
return|;
block|}
else|else
block|{
name|tfree
argument_list|(
name|r
operator|->
name|in
operator|.
name|left
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|->
name|in
operator|.
name|right
operator|)
return|;
block|}
block|}
elseif|else
if|if
condition|(
operator|(
name|o
operator|==
name|ANDAND
operator|||
name|o
operator|==
name|OROR
operator|)
operator|&&
operator|(
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
operator|||
name|r
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
operator|)
condition|)
goto|goto
name|ccwarn
goto|;
elseif|else
if|if
condition|(
name|opty
operator|==
name|BITYPE
operator|&&
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
operator|&&
name|r
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
condition|)
block|{
switch|switch
condition|(
name|o
condition|)
block|{
case|case
name|ULT
case|:
case|case
name|UGT
case|:
case|case
name|ULE
case|:
case|case
name|UGE
case|:
case|case
name|LT
case|:
case|case
name|GT
case|:
case|case
name|LE
case|:
case|case
name|GE
case|:
case|case
name|EQ
case|:
case|case
name|NE
case|:
if|if
condition|(
name|l
operator|->
name|in
operator|.
name|type
operator|==
name|ENUMTY
operator|&&
name|r
operator|->
name|in
operator|.
name|type
operator|==
name|ENUMTY
condition|)
block|{
name|p
operator|=
name|block
argument_list|(
name|o
argument_list|,
name|l
argument_list|,
name|r
argument_list|,
name|INT
argument_list|,
literal|0
argument_list|,
name|INT
argument_list|)
expr_stmt|;
name|chkpun
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|p
operator|->
name|in
operator|.
name|op
operator|=
name|FREE
expr_stmt|;
block|}
case|case
name|ANDAND
case|:
case|case
name|OROR
case|:
case|case
name|CBRANCH
case|:
name|ccwarn
label|:
if|if
condition|(
name|hflag
condition|)
name|werror
argument_list|(
literal|"constant in conditional context"
argument_list|)
expr_stmt|;
case|case
name|PLUS
case|:
case|case
name|MINUS
case|:
case|case
name|MUL
case|:
case|case
name|DIV
case|:
case|case
name|MOD
case|:
case|case
name|AND
case|:
case|case
name|OR
case|:
case|case
name|ER
case|:
case|case
name|LS
case|:
case|case
name|RS
case|:
if|if
condition|(
name|conval
argument_list|(
name|l
argument_list|,
name|o
argument_list|,
name|r
argument_list|)
condition|)
block|{
name|r
operator|->
name|in
operator|.
name|op
operator|=
name|FREE
expr_stmt|;
return|return
operator|(
name|l
operator|)
return|;
block|}
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|opty
operator|==
name|BITYPE
operator|&&
operator|(
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|FCON
operator|||
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|DCON
operator|||
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
operator|)
operator|&&
operator|(
name|r
operator|->
name|in
operator|.
name|op
operator|==
name|FCON
operator|||
name|r
operator|->
name|in
operator|.
name|op
operator|==
name|DCON
operator|||
name|r
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
operator|)
condition|)
block|{
if|if
condition|(
name|o
operator|==
name|PLUS
operator|||
name|o
operator|==
name|MINUS
operator|||
name|o
operator|==
name|MUL
operator|||
name|o
operator|==
name|DIV
condition|)
block|{
specifier|extern
name|int
name|fpe_count
decl_stmt|;
specifier|extern
name|jmp_buf
name|gotfpe
decl_stmt|;
name|fpe_count
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|gotfpe
argument_list|)
condition|)
goto|goto
name|treatfpe
goto|;
if|if
condition|(
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
condition|)
name|l
operator|->
name|dpn
operator|.
name|dval
operator|=
name|l
operator|->
name|tn
operator|.
name|lval
expr_stmt|;
elseif|else
if|if
condition|(
name|l
operator|->
name|in
operator|.
name|op
operator|==
name|FCON
condition|)
name|l
operator|->
name|dpn
operator|.
name|dval
operator|=
name|l
operator|->
name|fpn
operator|.
name|fval
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|in
operator|.
name|op
operator|==
name|ICON
condition|)
name|r
operator|->
name|dpn
operator|.
name|dval
operator|=
name|r
operator|->
name|tn
operator|.
name|lval
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|->
name|in
operator|.
name|op
operator|==
name|FCON
condition|)
name|r
operator|->
name|dpn
operator|.
name|dval
operator|=
name|r
operator|->
name|fpn
operator|.
name|fval
expr_stmt|;
switch|switch
condition|(
name|o
condition|)
block|{
case|case
name|PLUS
case|:
name|l
operator|->
name|dpn
operator|.
name|dval
operator|+=
name|r
operator|->
name|dpn
operator|.
name|dval
expr_stmt|;
break|break;
case|case
name|MINUS
case|:
name|l
operator|->
name|dpn
operator|.
name|dval
operator|-=
name|r
operator|->
name|dpn
operator|.
name|dval
expr_stmt|;
break|break;
case|case
name|MUL
case|:
name|l
operator|->
name|dpn
operator|.
name|dval
operator|*=
name|r
operator|->
name|dpn
operator|.
name|dval
expr_stmt|;
break|break;
case|case
name|DIV
case|:
if|if
condition|(
name|r
operator|->
name|dpn
operator|.
name|dval
operator|==
literal|0
condition|)
name|uerror
argument_list|(
literal|"division by 0."
argument_list|)
expr_stmt|;
else|else
name|l
operator|->
name|dpn
operator|.
name|dval
operator|/=
name|r
operator|->
name|dpn
operator|.
name|dval
expr_stmt|;
break|break;
block|}
name|treatfpe
label|:
if|if
condition|(
name|fpe_count
operator|>
literal|0
condition|)
block|{
name|uerror
argument_list|(
literal|"floating point exception in constant expression"
argument_list|)
expr_stmt|;
name|l
operator|->
name|dpn
operator|.
name|dval
operator|=
literal|1.0
expr_stmt|;
comment|/* Fairly harmless */
block|}
name|fpe_count
operator|=
operator|-
literal|1
expr_stmt|;
name|l
operator|->
name|in
operator|.
name|op
operator|=
name|DCON
expr_stmt|;
name|l
operator|->
name|in
operator|.
name|type
operator|=
name|l
operator|->
name|fn
operator|.
name|csiz
operator|=
name|DOUBLE
expr_stmt|;
name|r
operator|->
name|in
operator|.
name|op
operator|=
name|FREE
expr_stmt|;
return|return
operator|(
name|l
operator|)
return|;
block|}
block|}
comment|/* it's real; we must make a new node */
name|p
operator|=
name|block
argument_list|(
name|o
argument_list|,
name|l
argument_list|,
name|r
argument_list|,
name|INT
argument_list|,
literal|0
argument_list|,
name|INT
argument_list|)
expr_stmt|;
name|actions
operator|=
name|opact
argument_list|(
name|p
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|adebug
condition|)
name|printact
argument_list|(
name|p
argument_list|,
name|actions
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|actions
operator|&
name|LVAL
condition|)
block|{
comment|/* check left descendent */
if|if
condition|(
name|notlval
argument_list|(
name|p
operator|->
name|in
operator|.
name|left
argument_list|)
condition|)
block|{
name|uerror
argument_list|(
literal|"illegal lvalue operand of assignment operator"
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|actions
operator|&
name|NCVTR
condition|)
block|{
name|p
operator|->
name|in
operator|.
name|left
operator|=
name|pconvert
argument_list|(
name|p
operator|->
name|in
operator|.
name|left
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
operator|(
name|actions
operator|&
name|NCVT
operator|)
condition|)
block|{
switch|switch
condition|(
name|opty
condition|)
block|{
case|case
name|BITYPE
case|:
name|p
operator|->
name|in
operator|.
name|right
operator|=
name|pconvert
argument_list|(
name|p
operator|->
name|in
operator|.
name|right
argument_list|)
expr_stmt|;
case|case
name|UTYPE
case|:
name|p
operator|->
name|in
operator|.
name|left
operator|=
name|pconvert
argument_list|(
name|p
operator|->
name|in
operator|.
name|left
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
name|actions
operator|&
name|PUN
operator|)
operator|&&
operator|(
name|o
operator|!=
name|CAST
operator|||
name|cflag
operator|)
condition|)
block|{
name|chkpun
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|actions
operator|&
operator|(
name|TYPL
operator||
name|TYPR
operator|)
condition|)
block|{
name|q
operator|=
operator|(
name|actions
operator|&
name|TYPL
operator|)
condition|?
name|p
operator|->
name|in
operator|.
name|left
else|:
name|p
operator|->
name|in
operator|.
name|right
expr_stmt|;
name|p
operator|->
name|in
operator|.
name|type
operator|=
name|q
operator|->
name|in
operator|.
name|type
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|cdim
operator|=
name|q
operator|->
name|fn
operator|.
name|cdim
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|csiz
operator|=
name|q
operator|->
name|fn
operator|.
name|csiz
expr_stmt|;
block|}
if|if
condition|(
name|actions
operator|&
name|CVTL
condition|)
name|p
operator|=
name|convert
argument_list|(
name|p
argument_list|,
name|CVTL
argument_list|)
expr_stmt|;
if|if
condition|(
name|actions
operator|&
name|CVTR
condition|)
name|p
operator|=
name|convert
argument_list|(
name|p
argument_list|,
name|CVTR
argument_list|)
expr_stmt|;
if|if
condition|(
name|actions
operator|&
name|TYMATCH
condition|)
name|p
operator|=
name|tymatch
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|actions
operator|&
name|PTMATCH
condition|)
name|p
operator|=
name|ptmatch
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|actions
operator|&
name|OTHER
condition|)
block|{
name|l
operator|=
name|p
operator|->
name|in
operator|.
name|left
expr_stmt|;
name|r
operator|=
name|p
operator|->
name|in
operator|.
name|right
expr_stmt|;
switch|switch
condition|(
name|o
condition|)
block|{
case|case
name|NAME
case|:
name|sp
operator|=
operator|&
name|stab
index|[
name|idname
index|]
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|stype
operator|==
name|UNDEF
condition|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|uerror
argument_list|(
literal|"%.8s undefined"
argument_list|,
name|sp
operator|->
name|sname
argument_list|)
expr_stmt|;
else|#
directive|else
name|uerror
argument_list|(
literal|"%s undefined"
argument_list|,
name|sp
operator|->
name|sname
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* make p look reasonable */
name|p
operator|->
name|in
operator|.
name|type
operator|=
name|p
operator|->
name|fn
operator|.
name|csiz
operator|=
name|INT
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|cdim
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|tn
operator|.
name|rval
operator|=
name|idname
expr_stmt|;
name|p
operator|->
name|tn
operator|.
name|lval
operator|=
literal|0
expr_stmt|;
name|defid
argument_list|(
name|p
argument_list|,
name|SNULL
argument_list|)
expr_stmt|;
break|break;
block|}
name|p
operator|->
name|in
operator|.
name|type
operator|=
name|sp
operator|->
name|stype
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|cdim
operator|=
name|sp
operator|->
name|dimoff
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|csiz
operator|=
name|sp
operator|->
name|sizoff
expr_stmt|;
name|p
operator|->
name|tn
operator|.
name|lval
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|tn
operator|.
name|rval
operator|=
name|idname
expr_stmt|;
comment|/* special case: MOETY is really an ICON... */
if|if
condition|(
name|p
operator|->
name|in
operator|.
name|type
operator|==
name|MOETY
condition|)
block|{
name|p
operator|->
name|tn
operator|.
name|rval
operator|=
name|NONAME
expr_stmt|;
name|p
operator|->
name|tn
operator|.
name|lval
operator|=
name|sp
operator|->
name|offset
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|cdim
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|in
operator|.
name|type
operator|=
name|ENUMTY
expr_stmt|;
name|p
operator|->
name|in
operator|.
name|op
operator|=
name|ICON
expr_stmt|;
block|}
break|break;
case|case
name|ICON
case|:
name|p
operator|->
name|in
operator|.
name|type
operator|=
name|INT
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|cdim
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|csiz
operator|=
name|INT
expr_stmt|;
break|break;
case|case
name|STRING
case|:
name|p
operator|->
name|in
operator|.
name|op
operator|=
name|NAME
expr_stmt|;
name|p
operator|->
name|in
operator|.
name|type
operator|=
name|CHAR
operator|+
name|ARY
expr_stmt|;
name|p
operator|->
name|tn
operator|.
name|lval
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|tn
operator|.
name|rval
operator|=
name|NOLAB
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|cdim
operator|=
name|curdim
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|csiz
operator|=
name|CHAR
expr_stmt|;
break|break;
case|case
name|FCON
case|:
name|p
operator|->
name|tn
operator|.
name|lval
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|tn
operator|.
name|rval
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|in
operator|.
name|type
operator|=
name|FLOAT
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|cdim
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|csiz
operator|=
name|FLOAT
expr_stmt|;
break|break;
case|case
name|DCON
case|:
name|p
operator|->
name|tn
operator|.
name|lval
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|tn
operator|.
name|rval
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|in
operator|.
name|type
operator|=
name|DOUBLE
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|cdim
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|fn
operator|.
name|csiz
operator|=
name|DOUBLE
expr_stmt|;
break|break;
case|case
name|STREF
case|:
comment|/* p->x turned into *(p+offset) */
comment|/* rhs must be a name; check correctness */
name|i
operator|=
name|r
operator|->
name|tn
operator|.
name|rval
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
operator|||
operator|(
operator|(
name|sp
operator|=
operator|&
name|stab
index|[
name|i
index|]
operator|)
operator|->
name|sclass
operator|!=
name|MOS
operator|&&
name|sp
operator|->
name|sclass
operator|!=
name|MOU
operator|&&
operator|!
operator|(
name|sp
operator|->
name|sclass
operator|&
name|FIELD
operator|)
operator|)
condition|)
block|{
name|uerror
argument_list|(
literal|"member of structure or union required"
argument_list|)
expr_stmt|;
block|}
elseif|else
comment|/* if this name is non-unique, find right one */
if|if
condition|(
name|stab
index|[
name|i
index|]
operator|.
name|sflags
operator|&
name|SNONUNIQ
operator|&&
operator|(
name|l
operator|->
name|in
operator|.
name|type
operator|==
name|PTR
operator|+
name|STRTY
operator|||
name|l
operator|->
name|in
operator|.
name|type
operator|==
name|PTR
operator|+
name|UNIONTY
operator|)
operator|&&
operator|(
name|l
operator|->
name|fn
operator|.
name|csiz
operator|+
literal|1
operator|)
operator|>=
literal|0
condition|)
block|{
comment|/* nonunique name&& structure defined */
name|char
modifier|*
name|memnam
decl_stmt|,
modifier|*
name|tabnam
decl_stmt|;
name|int
name|j
decl_stmt|;
name|int
name|memi
decl_stmt|;
name|j
operator|=
name|dimtab
index|[
name|l
operator|->
name|fn
operator|.
name|csiz
operator|+
literal|1
index|]
expr_stmt|;
for|for
control|(
init|;
operator|(
name|memi
operator|=
name|dimtab
index|[
name|j
index|]
operator|)
operator|>=
literal|0
condition|;
operator|++
name|j
control|)
block|{
name|tabnam
operator|=
name|stab
index|[
name|memi
index|]
operator|.
name|sname
expr_stmt|;
name|memnam
operator|=
name|stab
index|[
name|i
index|]
operator|.
name|sname
expr_stmt|;
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
operator|>
literal|1
condition|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"member %.8s==%.8s?\n"
argument_list|,
else|#
directive|else
argument|printf(
literal|"member %s==%s?\n"
argument|,
endif|#
directive|endif
argument|memnam, tabnam); 						}
endif|#
directive|endif
argument|if( stab[memi].sflags& SNONUNIQ ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|register k; 						for( k=
literal|0
argument|; k<NCHNAM; ++k ){ 							if(*memnam++!=*tabnam) 								goto next; 							if(!*tabnam++) break; 							}
else|#
directive|else
argument|if (memnam != tabnam) 							goto next;
endif|#
directive|endif
argument|r->tn.rval = i = memi; 						break; 						} 					next: continue; 					} 				if( memi<
literal|0
argument|)
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|uerror(
literal|"illegal member use: %.8s"
argument|,
else|#
directive|else
argument|uerror(
literal|"illegal member use: %s"
argument|,
endif|#
directive|endif
argument|stab[i].sname); 				} 			else { 				register j; 				if( l->in.type != PTR+STRTY&& l->in.type != PTR+UNIONTY ){ 					if( stab[i].sflags& SNONUNIQ ){ 						uerror(
literal|"nonunique name demands struct/union or struct/union pointer"
argument|); 						} 					else werror(
literal|"struct/union or struct/union pointer required"
argument|); 					} 				else if( (j=l->fn.csiz+
literal|1
argument|)<
literal|0
argument|) cerror(
literal|"undefined structure or union"
argument|); 				else if( !chkstr( i, dimtab[j], DECREF(l->in.type) ) ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|werror(
literal|"illegal member use: %.8s"
argument|, stab[i].sname );
else|#
directive|else
argument|werror(
literal|"illegal member use: %s"
argument|, stab[i].sname );
endif|#
directive|endif
argument|} 				}  			p = stref( p ); 			break;  		case UNARY MUL: 			if( l->in.op == UNARY AND ){ 				p->in.op = l->in.op = FREE; 				p = l->in.left; 				} 			if( !ISPTR(l->in.type))uerror(
literal|"illegal indirection"
argument|); 			p->in.type = DECREF(l->in.type); 			p->fn.cdim = l->fn.cdim; 			p->fn.csiz = l->fn.csiz; 			break;  		case UNARY AND: 			switch( l->in.op ){  			case UNARY MUL: 				p->in.op = l->in.op = FREE; 				p = l->in.left; 			case NAME: 				p->in.type = INCREF( l->in.type ); 				p->fn.cdim = l->fn.cdim; 				p->fn.csiz = l->fn.csiz; 				break;  			case COMOP: 				lr = buildtree( UNARY AND, l->in.right, NIL ); 				p->in.op = l->in.op = FREE; 				p = buildtree( COMOP, l->in.left, lr ); 				break;  			case QUEST: 				lr = buildtree( UNARY AND, l->in.right->in.right, NIL ); 				ll = buildtree( UNARY AND, l->in.right->in.left, NIL ); 				p->in.op = l->in.op = l->in.right->in.op = FREE; 				p = buildtree( QUEST, l->in.left, buildtree( COLON, ll, lr ) ); 				break;
ifdef|#
directive|ifdef
name|ADDROREG
argument|case OREG:
comment|/* OREG was built in clocal() 				 * for an auto or formal parameter 				 * now its address is being taken 				 * local code must unwind it 				 * back to PLUS/MINUS REG ICON 				 * according to local conventions 				 */
argument|{ 				extern NODE * addroreg(); 				p->in.op = FREE; 				p = addroreg( l ); 				} 				break;
endif|#
directive|endif
argument|default: 				uerror(
literal|"unacceptable operand of&"
argument|); 				break; 				} 			break;  		case LS: 		case RS: 			if( l->in.type == CHAR || l->in.type == SHORT ) 				p->in.type = INT; 			else if( l->in.type == UCHAR || l->in.type == USHORT ) 				p->in.type = UNSIGNED; 			else 				p->in.type = l->in.type; 		case ASG LS: 		case ASG RS: 			if( r->in.type != INT ) 				p->in.right = r = makety(r, INT,
literal|0
argument|, INT ); 			break;  		case RETURN: 		case ASSIGN: 		case CAST:
comment|/* structure assignment */
comment|/* take the addresses of the two sides; then make an 			/* operator using STASG and 			/* the addresses of left and right */
argument|{ 				register TWORD t; 				register d, s;  				if( l->fn.csiz != r->fn.csiz ) uerror(
literal|"assignment of different structures"
argument|);  				r = buildtree( UNARY AND, r, NIL ); 				t = r->in.type; 				d = r->fn.cdim; 				s = r->fn.csiz;  				l = block( STASG, l, r, t, d, s );  				if( o == RETURN ){ 					p->in.op = FREE; 					p = l; 					break; 					}  				p->in.op = UNARY MUL; 				p->in.left = l; 				p->in.right = NIL; 				break; 				} 		case COLON:
comment|/* structure colon */
argument|if( l->fn.csiz != r->fn.csiz ) uerror(
literal|"type clash in conditional"
argument|); 			break;  		case CALL: 			p->in.right = r = fixargs( p->in.right ); 		case UNARY CALL: 			if( !ISPTR(l->in.type)) uerror(
literal|"illegal function"
argument|); 			p->in.type = DECREF(l->in.type); 			if( !ISFTN(p->in.type)) uerror(
literal|"illegal function"
argument|); 			p->in.type = DECREF( p->in.type ); 			p->fn.cdim = l->fn.cdim; 			p->fn.csiz = l->fn.csiz; 			if( l->in.op == UNARY AND&& l->in.left->in.op == NAME&& 				l->in.left->tn.rval>=
literal|0
argument|&& l->in.left->tn.rval != NONAME&& 				( (i=stab[l->in.left->tn.rval].sclass) == FORTRAN || i==UFORTRAN ) ){ 				p->in.op += (FORTCALL-CALL); 				} 			if( p->in.type == STRTY || p->in.type == UNIONTY ){
comment|/* function returning structure */
comment|/*  make function really return ptr to str., with * */
argument|p->in.op += STCALL-CALL; 				p->in.type = INCREF( p->in.type ); 				p = buildtree( UNARY MUL, p, NIL );  				} 			break;  		default: 			cerror(
literal|"other code %d"
argument|, o ); 			}  		}  	if( actions& CVTO ) p = oconvert(p); 	p = clocal(p);
ifndef|#
directive|ifndef
name|BUG1
argument|if( bdebug ) fwalk( p, eprint,
literal|0
argument|);
endif|#
directive|endif
argument|return(p);  	}  int fpe_count = -
literal|1
argument|; jmp_buf gotfpe;  fpe() { 	if (fpe_count<
literal|0
argument|) 		cerror(
literal|"floating point exception"
argument|); 	++fpe_count; 	longjmp(gotfpe,
literal|1
argument|); 	}
comment|/*  * Rewrite arguments in a function call.  * Structure arguments are massaged, single  * precision floating point constants are  * cast to double (to eliminate convert code).  */
argument|NODE * fixargs( p ) register NODE *p;  { 	int o = p->in.op;  	if( o == CM ){ 		p->in.left = fixargs( p->in.left ); 		p->in.right = fixargs( p->in.right ); 		return( p ); 		}  	if( p->in.type == STRTY || p->in.type == UNIONTY ){ 		p = block( STARG, p, NIL, p->in.type, p->fn.cdim, p->fn.csiz ); 		p->in.left = buildtree( UNARY AND, p->in.left, NIL ); 		p = clocal(p); 		} 	else if( o == FCON ) 		p = makety(p, DOUBLE,
literal|0
argument|,
literal|0
argument|); 	return( p ); 	}  chkstr( i, j, type ) TWORD type; {
comment|/* is the MOS or MOU at stab[i] OK for strict reference by a ptr */
comment|/* i has been checked to contain a MOS or MOU */
comment|/* j is the index in dimtab of the members... */
argument|int k, kk;  	extern int ddebug;
ifndef|#
directive|ifndef
name|BUG1
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if( ddebug>
literal|1
argument|) printf(
literal|"chkstr( %.8s(%d), %d )\n"
argument|, stab[i].sname, i, j );
else|#
directive|else
argument|if( ddebug>
literal|1
argument|) printf(
literal|"chkstr( %s(%d), %d )\n"
argument|, stab[i].sname, i, j );
endif|#
directive|endif
endif|#
directive|endif
argument|if( (k = j)<
literal|0
argument|) uerror(
literal|"undefined structure or union"
argument|); 	else { 		for( ; (kk = dimtab[k] )>=
literal|0
argument|; ++k ){ 			if( kk>= SYMTSZ ){ 				cerror(
literal|"gummy structure"
argument|); 				return(
literal|1
argument|); 				} 			if( kk == i ) return(
literal|1
argument|); 			switch( stab[kk].stype ){  			case STRTY: 			case UNIONTY: 				if( type == STRTY ) continue;
comment|/* no recursive looking for strs */
argument|if( hflag&& chkstr( i, dimtab[stab[kk].sizoff+
literal|1
argument|], stab[kk].stype ) ){ 					if( stab[kk].sname[
literal|0
argument|] ==
literal|'$'
argument|) return(
literal|0
argument|);
comment|/* $FAKE */
argument|werror(
ifndef|#
directive|ifndef
name|FLEXNAMES
literal|"illegal member use: perhaps %.8s.%.8s?"
argument|,
else|#
directive|else
literal|"illegal member use: perhaps %s.%s?"
argument|,
endif|#
directive|endif
argument|stab[kk].sname, stab[i].sname ); 					return(
literal|1
argument|); 					} 				} 			} 		} 	return(
literal|0
argument|); 	}  conval( p, o, q ) register NODE *p, *q; {
comment|/* apply the op o to the lval part of p; if binary, rhs is val */
comment|/* works only on integer constants */
argument|NODE *r; 	int i, u; 	CONSZ val; 	TWORD utype;  	val = q->tn.lval; 	u = ISUNSIGNED(p->in.type) || ISUNSIGNED(q->in.type); 	if( u&& (o==LE||o==LT||o==GE||o==GT)) o += (UGE-GE);  	if( p->tn.rval != NONAME&& q->tn.rval != NONAME ) return(
literal|0
argument|); 	if( q->tn.rval != NONAME&& o!=PLUS ) return(
literal|0
argument|); 	if( p->tn.rval != NONAME&& o!=PLUS&& o!=MINUS ) return(
literal|0
argument|);
comment|/* usual type conversions -- handle casts of constants */
define|#
directive|define
name|ISLONG
parameter_list|(
name|t
parameter_list|)
value|((t) == LONG || (t) == ULONG)
argument|if (ISLONG(p->in.type) || ISLONG(q->in.type)) 		utype = u ? ULONG : LONG; 	else 		utype = u ? UNSIGNED : INT; 	if( !ISPTR(p->in.type)&& p->in.type != utype ) 		p = makety(p, utype,
literal|0
argument|, (int)utype); 	if( q->in.type != utype ) 		q = makety(q, utype,
literal|0
argument|, (int)utype);  	switch( o ){  	case PLUS: 		p->tn.lval += val; 		if( p->tn.rval == NONAME ){ 			p->tn.rval = q->tn.rval; 			p->in.type = q->in.type; 			} 		break; 	case MINUS: 		p->tn.lval -= val; 		break; 	case MUL: 		p->tn.lval *= val; 		break; 	case DIV: 		if( val ==
literal|0
argument|) uerror(
literal|"division by 0"
argument|); 		else if ( u ) p->tn.lval = (unsigned) p->tn.lval / val; 		else p->tn.lval /= val; 		break; 	case MOD: 		if( val ==
literal|0
argument|) uerror(
literal|"division by 0"
argument|); 		else if ( u ) p->tn.lval = (unsigned) p->tn.lval % val; 		else p->tn.lval %= val; 		break; 	case AND: 		p->tn.lval&= val; 		break; 	case OR: 		p->tn.lval |= val; 		break; 	case ER: 		p->tn.lval ^= val; 		break; 	case LS: 		i = val; 		p->tn.lval = p->tn.lval<< i; 		break; 	case RS: 		i = val; 		if ( u ) p->tn.lval = (unsigned) p->tn.lval>> i; 		else p->tn.lval = p->tn.lval>> i; 		break;  	case UNARY MINUS: 		p->tn.lval = - p->tn.lval; 		break; 	case COMPL: 		p->tn.lval = ~p->tn.lval; 		break; 	case NOT: 		p->tn.lval = !p->tn.lval; 		break; 	case LT: 		p->tn.lval = p->tn.lval< val; 		break; 	case LE: 		p->tn.lval = p->tn.lval<= val; 		break; 	case GT: 		p->tn.lval = p->tn.lval> val; 		break; 	case GE: 		p->tn.lval = p->tn.lval>= val; 		break; 	case ULT: 		p->tn.lval = p->tn.lval< (unsigned) val; 		break; 	case ULE: 		p->tn.lval = p->tn.lval<= (unsigned) val; 		break; 	case UGT: 		p->tn.lval = p->tn.lval> (unsigned) val; 		break; 	case UGE: 		p->tn.lval = p->tn.lval>= (unsigned) val; 		break; 	case EQ: 		p->tn.lval = p->tn.lval == val; 		break; 	case NE: 		p->tn.lval = p->tn.lval != val; 		break; 	default: 		return(
literal|0
argument|); 		} 	return(
literal|1
argument|); 	}  chkpun(p) register NODE *p; {
comment|/* checks p for the existance of a pun */
comment|/* this is called when the op of p is ASSIGN, RETURN, CAST, COLON, or relational */
comment|/* one case is when enumerations are used: this applies only to lint */
comment|/* in the other case, one operand is a pointer, the other integer type */
comment|/* we check that this integer is in fact a constant zero... */
comment|/* in the case of ASSIGN, any assignment of pointer to integer is illegal */
comment|/* this falls out, because the LHS is never 0 */
argument|register NODE *q; 	register t1, t2; 	register d1, d2; 	int ref1, ref2;  	t1 = p->in.left->in.type; 	t2 = p->in.right->in.type;  	if( t1==ENUMTY || t2==ENUMTY ) {
comment|/* check for enumerations */
comment|/* rob pike says this is obnoxious... 		if( logop( p->in.op )&& p->in.op != EQ&& p->in.op != NE ) 			werror( "comparison of enums" ); */
argument|if( t1==ENUMTY&& t2==ENUMTY ) { 			if ( p->in.left->fn.csiz!=p->in.right->fn.csiz ) 				werror(
literal|"enumeration type clash, operator %s"
argument|, opst[p->in.op] ); 			return; 			} 		if ( t1 == ENUMTY ) t1 = INT; 		if ( t2 == ENUMTY ) t2 = INT; 		}  	ref1 = ISPTR(t1) || ISARY(t1); 	ref2 = ISPTR(t2) || ISARY(t2);  	if( ref1 ^ ref2 ){ 		if( ref1 ) q = p->in.right; 		else q = p->in.left; 		if( q->in.op != ICON || q->tn.lval !=
literal|0
argument|){ 			werror(
literal|"illegal combination of pointer and integer, op %s"
argument|, 				opst[p->in.op] ); 			} 		} 	else if( ref1 ){ 		if( t1 == t2 ) { 			if( p->in.left->fn.csiz != p->in.right->fn.csiz ) { 				werror(
literal|"illegal structure pointer combination"
argument|); 				return; 				} 			d1 = p->in.left->fn.cdim; 			d2 = p->in.right->fn.cdim; 			for( ;; ){ 				if( ISARY(t1) ){ 					if( dimtab[d1] != dimtab[d2] ){ 						werror(
literal|"illegal array size combination"
argument|); 						return; 						} 					++d1; 					++d2; 					} 				else if( !ISPTR(t1) ) break; 				t1 = DECREF(t1); 				} 			} 		else if( t1 != INCREF(UNDEF)&& t2 != INCREF(UNDEF) ) 			werror(
literal|"illegal pointer combination"
argument|); 		}  	}  NODE * stref( p ) register NODE *p; {  	TWORD t; 	int d, s, dsc, align; 	OFFSZ off; 	register struct symtab *q;
comment|/* make p->x */
comment|/* this is also used to reference automatic variables */
argument|q =&stab[p->in.right->tn.rval]; 	p->in.right->in.op = FREE; 	p->in.op = FREE; 	p = pconvert( p->in.left );
comment|/* make p look like ptr to x */
argument|if( !ISPTR(p->in.type)){ 		p->in.type = PTR+UNIONTY; 		}  	t = INCREF( q->stype ); 	d = q->dimoff; 	s = q->sizoff;  	p = makety( p, t, d, s );
comment|/* compute the offset to be added */
argument|off = q->offset; 	dsc = q->sclass;  	if( dsc& FIELD ) {
comment|/* normalize offset */
argument|align = ALINT; 		s = INT; 		off = (off/align)*align; 		} 	if( off !=
literal|0
argument|) p = clocal( block( PLUS, p, offcon( off, t, d, s ), t, d, s ) );  	p = buildtree( UNARY MUL, p, NIL );
comment|/* if field, build field info */
argument|if( dsc& FIELD ){ 		p = block( FLD, p, NIL, q->stype,
literal|0
argument|, q->sizoff ); 		p->tn.rval = PKFIELD( dsc&FLDSIZ, q->offset%align ); 		}  	return( clocal(p) ); 	}  notlval(p) register NODE *p; {
comment|/* return 0 if p an lvalue, 1 otherwise */
argument|again:  	switch( p->in.op ){  	case FLD: 		p = p->in.left; 		goto again;  	case UNARY MUL:
comment|/* fix the&(a=b) bug, given that a and b are structures */
argument|if( p->in.left->in.op == STASG ) return(
literal|1
argument|);
comment|/* and the f().a bug, given that f returns a structure */
argument|if( p->in.left->in.op == UNARY STCALL || 		    p->in.left->in.op == STCALL ) return(
literal|1
argument|); 	case NAME: 	case OREG: 		if( ISARY(p->in.type) || ISFTN(p->in.type) ) return(
literal|1
argument|); 	case REG: 		return(
literal|0
argument|);  	default: 		return(
literal|1
argument|);  		}  	}  NODE * bcon( i ){
comment|/* make a constant node with value i */
argument|register NODE *p;  	p = block( ICON, NIL, NIL, INT,
literal|0
argument|, INT ); 	p->tn.lval = i; 	p->tn.rval = NONAME; 	return( clocal(p) ); 	}  NODE * bpsize(p) register NODE *p; { 	return( offcon( psize(p), p->in.type, p->fn.cdim, p->fn.csiz ) ); 	}  OFFSZ psize( p ) NODE *p; {
comment|/* p is a node of type pointer; psize returns the 	   size of the thing pointed to */
argument|if( !ISPTR(p->in.type) ){ 		uerror(
literal|"pointer required"
argument|); 		return( SZINT ); 		}
comment|/* note: no pointers to fields */
argument|return( tsize( DECREF(p->in.type), p->fn.cdim, p->fn.csiz ) ); 	}  NODE * convert( p, f )  register NODE *p; {
comment|/*  convert an operand of p 	    f is either CVTL or CVTR 	    operand has type int, and is converted by the size of the other side 	    */
argument|register NODE *q, *r;  	q = (f==CVTL)?p->in.left:p->in.right;  	r = block( PMCONV, 		q, bpsize(f==CVTL?p->in.right:p->in.left), INT,
literal|0
argument|, INT ); 	r = clocal(r); 	if( f == CVTL ) 		p->in.left = r; 	else 		p->in.right = r; 	return(p);  	}
ifndef|#
directive|ifndef
name|econvert
argument|econvert( p ) register NODE *p; {
comment|/* change enums to ints, or appropriate types */
argument|register TWORD ty;  	if( (ty=BTYPE(p->in.type)) == ENUMTY || ty == MOETY ) { 		if( dimtab[ p->fn.csiz ] == SZCHAR ) ty = CHAR; 		else if( dimtab[ p->fn.csiz ] == SZINT ) ty = INT; 		else if( dimtab[ p->fn.csiz ] == SZSHORT ) ty = SHORT; 		else ty = LONG; 		ty = ctype( ty ); 		p->fn.csiz = ty; 		MODTYPE(p->in.type,ty); 		if( p->in.op == ICON&& ty != LONG ) p->in.type = p->fn.csiz = INT; 		} 	}
endif|#
directive|endif
argument|NODE * pconvert( p ) register NODE *p; {
comment|/* if p should be changed into a pointer, do so */
argument|if( ISARY( p->in.type) ){ 		p->in.type = DECREF( p->in.type ); 		++p->fn.cdim; 		return( buildtree( UNARY AND, p, NIL ) ); 		} 	if( ISFTN( p->in.type) ) 		return( buildtree( UNARY AND, p, NIL ) );  	return( p ); 	}  NODE * oconvert(p) register NODE *p; {
comment|/* convert the result itself: used for pointer and unsigned */
argument|switch(p->in.op) {  	case LE: 	case LT: 	case GE: 	case GT: 		if( ISUNSIGNED(p->in.left->in.type) || ISUNSIGNED(p->in.right->in.type) )  p->in.op += (ULE-LE); 	case EQ: 	case NE: 		return( p );  	case MINUS: 		return(  clocal( block( PVCONV, 			p, bpsize(p->in.left), INT,
literal|0
argument|, INT ) ) ); 		}  	cerror(
literal|"illegal oconvert: %d"
argument|, p->in.op );  	return(p); 	}  NODE * ptmatch(p)  register NODE *p; {
comment|/* makes the operands of p agree; they are 	   either pointers or integers, by this time */
comment|/* with MINUS, the sizes must be the same */
comment|/* with COLON, the types must be the same */
argument|TWORD t1, t2, t; 	int o, d2, d, s2, s;  	o = p->in.op; 	t = t1 = p->in.left->in.type; 	t2 = p->in.right->in.type; 	d = p->in.left->fn.cdim; 	d2 = p->in.right->fn.cdim; 	s = p->in.left->fn.csiz; 	s2 = p->in.right->fn.csiz;  	switch( o ){  	case ASSIGN: 	case RETURN: 	case CAST: 		{  break; }  	case MINUS: 		{  if( psize(p->in.left) != psize(p->in.right) ){ 			uerror(
literal|"illegal pointer subtraction"
argument|); 			} 		   break; 		   } 	case COLON: 		{  if( t1 != t2 ) uerror(
literal|"illegal types in :"
argument|); 		   break; 		   } 	default:
comment|/* must work harder: relationals or comparisons */
argument|if( !ISPTR(t1) ){ 			t = t2; 			d = d2; 			s = s2; 			break; 			} 		if( !ISPTR(t2) ){ 			break; 			}
comment|/* both are pointers */
argument|if( talign(t2,s2)< talign(t,s) ){ 			t = t2; 			s = s2; 			} 		break; 		}  	p->in.left = makety( p->in.left, t, d, s ); 	p->in.right = makety( p->in.right, t, d, s ); 	if( o!=MINUS&& !logop(o) ){  		p->in.type = t; 		p->fn.cdim = d; 		p->fn.csiz = s; 		}  	return(clocal(p)); 	}  int tdebug =
literal|0
argument|;  NODE * tymatch(p)  register NODE *p; {
comment|/* satisfy the types of various arithmetic binary ops */
comment|/* rules are: 		if assignment, type of LHS 		if any float or doubles, make double 		if any longs, make long 		otherwise, make int 		if either operand is unsigned, the result is... 	*/
argument|register TWORD t1, t2, t, tu; 	register o, u;  	o = p->in.op;  	t1 = p->in.left->in.type; 	t2 = p->in.right->in.type; 	if( (t1==UNDEF || t2==UNDEF)&& o!=CAST ) 		uerror(
literal|"void type illegal in expression"
argument|);  	u =
literal|0
argument|; 	if( ISUNSIGNED(t1) ){ 		u =
literal|1
argument|; 		t1 = DEUNSIGN(t1); 		} 	if( ISUNSIGNED(t2) ){ 		u =
literal|1
argument|; 		t2 = DEUNSIGN(t2); 		}  	if( ( t1 == CHAR || t1 == SHORT )&& o!= RETURN ) t1 = INT; 	if( t2 == CHAR || t2 == SHORT ) t2 = INT;
ifdef|#
directive|ifdef
name|SPRECC
argument|if( t1 == DOUBLE || t2 == DOUBLE ) 		t = DOUBLE; 	else if( t1 == FLOAT || t2 == FLOAT ) 		t = FLOAT;
else|#
directive|else
argument|if (t1 == DOUBLE || t1 == FLOAT || t2 == DOUBLE || t2 == FLOAT) 		t = DOUBLE;
endif|#
directive|endif
argument|else if( t1==LONG || t2==LONG ) t = LONG; 	else t = INT;  	if( o == ASSIGN || o == CAST || o == RETURN ) 	{ 		tu = p->in.left->in.type; 		t = t1; 		} 	else { 		tu = (u&& UNSIGNABLE(t))?ENUNSIGN(t):t; 		}
comment|/* because expressions have values that are at least as wide 	   as INT or UNSIGNED, the only conversions needed 	   are those involving FLOAT/DOUBLE, and those 	   from LONG to INT and ULONG to UNSIGNED */
argument|if( (t != t1 || (u&& !ISUNSIGNED(p->in.left->in.type)))&& ! asgop(o) ) 		p->in.left = makety( p->in.left, tu,
literal|0
argument|, (int)tu );  	if( t != t2 || (u&& !ISUNSIGNED(p->in.right->in.type)) || o==CAST) 		if ( tu == ENUMTY ) {
comment|/* always asgop */
argument|p->in.right = makety( p->in.right, INT,
literal|0
argument|, INT ); 			p->in.right->in.type = tu; 			p->in.right->fn.cdim = p->in.left->fn.cdim; 			p->in.right->fn.csiz = p->in.left->fn.csiz; 			} 		else 			p->in.right = makety( p->in.right, tu,
literal|0
argument|, (int)tu );  	if( asgop(o) ){ 		p->in.type = p->in.left->in.type; 		p->fn.cdim = p->in.left->fn.cdim; 		p->fn.csiz = p->in.left->fn.csiz; 		} 	else if( !logop(o) ){ 		p->in.type = tu; 		p->fn.cdim =
literal|0
argument|; 		p->fn.csiz = t; 		}
ifndef|#
directive|ifndef
name|BUG1
argument|if( tdebug ) printf(
literal|"tymatch(%o): %o %s %o => %o\n"
argument|,p,t1,opst[o],t2,tu );
endif|#
directive|endif
argument|return(p); 	}  NODE * makety( p, t, d, s ) register NODE *p; TWORD t; {
comment|/* make p into type t by inserting a conversion */
argument|if( p->in.type == ENUMTY&& p->in.op == ICON ) econvert(p); 	if( t == p->in.type ){ 		p->fn.cdim = d; 		p->fn.csiz = s; 		return( p ); 		}  	if( t& TMASK ){
comment|/* non-simple type */
argument|return( block( PCONV, p, NIL, t, d, s ) ); 		}  	if( p->in.op == ICON ){ 		if (t == DOUBLE) { 			p->in.op = DCON; 			if (ISUNSIGNED(p->in.type)) 				p->dpn.dval = (U_CONSZ) p->tn.lval; 			else 				p->dpn.dval = p->tn.lval; 			p->in.type = p->fn.csiz = t; 			return (clocal(p)); 		} 		if (t == FLOAT) { 			p->in.op = FCON; 			if( ISUNSIGNED(p->in.type) ){ 				p->fpn.fval = (U_CONSZ) p->tn.lval; 				} 			else { 				p->fpn.fval = p->tn.lval; 				}  			p->in.type = p->fn.csiz = t; 			return( clocal(p) ); 			} 		} 	else if (p->in.op == FCON&& t == DOUBLE) { 		double db;  		p->in.op = DCON; 		db = p->fpn.fval; 		p->dpn.dval = db; 		p->in.type = p->fn.csiz = t; 		return (clocal(p)); 	} else if (p->in.op == DCON&& t == FLOAT) { 		float fl;  		p->in.op = FCON; 		fl = p->dpn.dval;
ifdef|#
directive|ifdef
name|notdef
argument|if (fl != p->dpn.dval) 			werror(
literal|"float conversion loses precision"
argument|);
endif|#
directive|endif
argument|p->fpn.fval = fl; 		p->in.type = p->fn.csiz = t; 		return (clocal(p)); 	}  	return( clocal( block( SCONV, p, NIL, t, d, s ) ) );  	}  NODE * block( o, l, r, t, d, s ) register NODE *l, *r; TWORD t; {  	register NODE *p;  	p = talloc(); 	p->in.op = o; 	p->in.left = l; 	p->in.right = r; 	p->in.type = t; 	p->fn.cdim = d; 	p->fn.csiz = s; 	return(p); 	}  icons(p) register NODE *p; {
comment|/* if p is an integer constant, return its value */
argument|int val;  	if( p->in.op != ICON ){ 		uerror(
literal|"constant expected"
argument|); 		val =
literal|1
argument|; 		} 	else { 		val = p->tn.lval; 		if( val != p->tn.lval ) uerror(
literal|"constant too big for cross-compiler"
argument|); 		} 	tfree( p ); 	return(val); 	}
comment|/* 	the intent of this table is to examine the 	operators, and to check them for 	correctness.  	The table is searched for the op and the 	modified type (where this is one of the 	types INT (includes char and short), LONG, 	DOUBLE (includes FLOAT), and POINTER  	The default action is to make the node type integer  	The actions taken include: 		PUN	  check for puns 		CVTL	  convert the left operand 		CVTR	  convert the right operand 		TYPL	  the type is determined by the left operand 		TYPR	  the type is determined by the right operand 		TYMATCH	  force type of left and right to match, by inserting conversions 		PTMATCH	  like TYMATCH, but for pointers 		LVAL	  left operand must be lval 		CVTO	  convert the op 		NCVT	  do not convert the operands 		OTHER	  handled by code 		NCVTR	  convert the left operand, not the right...  	*/
define|#
directive|define
name|MINT
value|01
comment|/* integer */
define|#
directive|define
name|MDBI
value|02
comment|/* integer or double */
define|#
directive|define
name|MSTR
value|04
comment|/* structure */
define|#
directive|define
name|MPTR
value|010
comment|/* pointer */
define|#
directive|define
name|MPTI
value|020
comment|/* pointer or integer */
define|#
directive|define
name|MENU
value|040
comment|/* enumeration variable or member */
define|#
directive|define
name|MVOID
value|0100000
comment|/* void type */
argument|opact( p )  NODE *p; {  	register mt12, mt1, mt2, o;  	mt1 = mt2 = mt12 =
literal|0
argument|;  	switch( optype(o=p->in.op) ){  	case BITYPE: 		mt2 = moditype( p->in.right->in.type ); 	case UTYPE: 		mt1 = moditype( p->in.left->in.type ); 		break;  		}  	if( ((mt1 | mt2)& MVOID)&& 	    o != COMOP&& 	    o != COLON&& 	    !(o == QUEST&& (mt1& MVOID) ==
literal|0
argument|)&& 	    !(o == CAST&& (mt1& MVOID)) ){
comment|/* if lhs of RETURN is void, grammar will complain */
argument|if( o != RETURN ) 			uerror(
literal|"value of void expression used"
argument|); 		return( NCVT ); 		} 	mt12 = mt1& mt2;  	switch( o ){  	case NAME : 	case STRING : 	case ICON : 	case FCON : 	case DCON : 	case CALL : 	case UNARY CALL: 	case UNARY MUL: 		{  return( OTHER ); } 	case UNARY MINUS: 		if( mt1& MENU ) return(
literal|0
argument|); 		if( mt1& MDBI ) return( TYPL ); 		break;  	case COMPL: 		if( mt1& MENU ) return(
literal|0
argument|); 		if( mt1& MINT ) return( TYPL ); 		break;  	case UNARY AND: 		return( NCVT+OTHER ); 	case INIT: 	case CM: 		return(
literal|0
argument|);  	case NOT: 	case CBRANCH: 		if( mt1& MSTR ) break; 		return(
literal|0
argument|);  	case ANDAND: 	case OROR: 		if( (mt1& MSTR) || (mt2& MSTR) ) break; 		return(
literal|0
argument|);  	case MUL: 	case DIV: 		if( mt12& MDBI ) return( TYMATCH ); 		break;  	case MOD: 	case AND: 	case OR: 	case ER: 		if( mt12& MINT ) return( TYMATCH ); 		break;  	case LS: 	case RS: 		if( mt12& MINT ) return( OTHER ); 		break;  	case EQ: 	case NE: 	case LT: 	case LE: 	case GT: 	case GE: 		if( mt12& MENU ) return( TYMATCH+NCVT+PUN ); 		if( mt12& MDBI ) return( TYMATCH+NCVT+CVTO ); 		else if( mt12& MPTR ) return( PTMATCH+PUN ); 		else if( mt12& MPTI ) return( PTMATCH+PUN ); 		else break;  	case QUEST: 	case COMOP: 		if( mt2&MENU ) return( TYPR+NCVTR ); 		return( TYPR );  	case STREF: 		return( NCVTR+OTHER );  	case FORCE: 		return( TYPL );  	case COLON: 		if( mt12& MENU ) return( NCVT+PUN+TYMATCH ); 		else if( mt12& MDBI ) return( NCVT+TYMATCH ); 		else if( mt12& MPTR ) return( TYPL+PTMATCH+PUN ); 		else if( (mt1&MINT)&& (mt2&MPTR) ) return( TYPR+PUN ); 		else if( (mt1&MPTR)&& (mt2&MINT) ) return( TYPL+PUN ); 		else if( mt12& MSTR ) return( NCVT+TYPL+OTHER ); 		else if( mt12 == MVOID ) return( NCVT+TYPL ); 		break;  	case ASSIGN: 	case RETURN: 		if( mt12& MSTR ) return( LVAL+NCVT+TYPL+OTHER ); 		else if( mt12& MENU ) return( LVAL+NCVT+TYPL+TYMATCH+PUN ); 	case CAST: 		if(o==CAST&& mt1==MVOID)return(TYPL+TYMATCH); 		else if( mt12& MDBI ) return( TYPL+LVAL+NCVT+TYMATCH ); 		else if( mt2 == MVOID&& 		        ( p->in.right->in.op == CALL || 			  p->in.right->in.op == UNARY CALL)) break; 		else if( (mt1& MPTR)&& (mt2& MPTI) ) 			return( LVAL+PTMATCH+PUN ); 		else if( mt12& MPTI ) return( TYPL+LVAL+TYMATCH+PUN ); 		break;  	case ASG LS: 	case ASG RS: 		if( mt12& MINT ) return( TYPL+LVAL+OTHER ); 		break;  	case ASG MUL: 	case ASG DIV: 		if( mt12& MDBI ) return( LVAL+TYMATCH ); 		break;  	case ASG MOD: 	case ASG AND: 	case ASG OR: 	case ASG ER: 		if( mt12& MINT ) return( LVAL+TYMATCH ); 		break;  	case ASG PLUS: 	case ASG MINUS: 	case INCR: 	case DECR: 		if( mt12& MDBI ) return( TYMATCH+LVAL ); 		else if( (mt1&MPTR)&& (mt2&MINT) ) return( TYPL+LVAL+CVTR ); 		break;  	case MINUS: 		if( mt12& MPTR ) return( CVTO+PTMATCH+PUN ); 		if( mt2& MPTR ) break; 	case PLUS: 		if( mt12& MDBI ) return( TYMATCH ); 		else if( (mt1&MPTR)&& (mt2&MINT) ) return( TYPL+CVTR ); 		else if( (mt1&MINT)&& (mt2&MPTR) ) return( TYPR+CVTL );  		} 	if( mt12 == MSTR ) 		uerror(
literal|"%s is not a permitted struct/union operation"
argument|, opst[o] ); 	else 		uerror(
literal|"operands of %s have incompatible types"
argument|, opst[o] ); 	return( NCVT ); 	}  moditype( ty ) TWORD ty; {  	switch( ty ){  	case UNDEF: 		return( MVOID ); 	case ENUMTY: 	case MOETY: 		return( MENU|MINT|MDBI|MPTI );
comment|/* enums are ints */
argument|case STRTY: 	case UNIONTY: 		return( MSTR );  	case CHAR: 	case SHORT: 	case UCHAR: 	case USHORT: 		return( MINT|MPTI|MDBI ); 	case UNSIGNED: 	case ULONG: 	case INT: 	case LONG: 		return( MINT|MDBI|MPTI ); 	case FLOAT: 	case DOUBLE: 		return( MDBI ); 	default: 		return( MPTR|MPTI );  		} 	}  NODE * doszof( p )  register NODE *p; {
comment|/* do sizeof p */
argument|int i;
comment|/* whatever is the meaning of this if it is a bitfield? */
argument|i = tsize( p->in.type, p->fn.cdim, p->fn.csiz )/SZCHAR;  	tfree(p); 	if( i<=
literal|0
argument|) werror(
literal|"sizeof returns 0"
argument|); 	return( bcon( i ) ); 	}
ifndef|#
directive|ifndef
name|BUG2
argument|eprint( p, down, a, b ) register NODE *p; int *a, *b; { 	register ty;  	*a = *b = down+
literal|1
argument|; 	while( down>
literal|1
argument|){ 		printf(
literal|"\t"
argument|); 		down -=
literal|2
argument|; 		} 	if( down ) printf(
literal|"    "
argument|);  	ty = optype( p->in.op );  	printf(
literal|"%o) %s, "
argument|, p, opst[p->in.op] ); 	if( ty == LTYPE ){ 		printf( CONFMT, p->tn.lval ); 		printf(
literal|", %d, "
argument|, p->tn.rval ); 		} 	tprint( p->in.type ); 	printf(
literal|", %d, %d\n"
argument|, p->fn.cdim, p->fn.csiz ); 	}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PRTDCON
argument|prtdcon( p ) register NODE *p; { 	int o = p->in.op, i;  	if( o == DCON || o == FCON ){ 		(void) locctr( DATA ); 		defalign( o == DCON ? ALDOUBLE : ALFLOAT ); 		deflab( i = getlab() ); 		if( o == FCON ) 			fincode( p->fpn.fval, SZFLOAT ); 		else 			fincode( p->dpn.dval, SZDOUBLE ); 		p->tn.lval =
literal|0
argument|; 		p->tn.rval = -i; 		p->in.type = (o == DCON ? DOUBLE : FLOAT); 		p->in.op = NAME; 		} 	}
endif|#
directive|endif
endif|PRTDCON
argument|int edebug =
literal|0
argument|; ecomp( p ) register NODE *p; {
ifndef|#
directive|ifndef
name|BUG2
argument|if( edebug ) fwalk( p, eprint,
literal|0
argument|);
endif|#
directive|endif
argument|if( !reached ){ 		werror(
literal|"statement not reached"
argument|); 		reached =
literal|1
argument|; 		} 	p = optim(p); 	walkf( p, prtdcon ); 	(void) locctr( PROG ); 	ecode( p ); 	tfree(p); 	}
ifdef|#
directive|ifdef
name|STDPRTREE
ifndef|#
directive|ifndef
name|ONEPASS
argument|prtree(p) register NODE *p; {  	register struct symtab *q; 	register ty;
ifdef|#
directive|ifdef
name|MYPRTREE
argument|MYPRTREE(p);
comment|/* local action can be taken here; then return... */
endif|#
directive|endif
argument|ty = optype(p->in.op);  	printf(
literal|"%d\t"
argument|, p->in.op );  	if( ty == LTYPE ) { 		printf( CONFMT, p->tn.lval ); 		printf(
literal|"\t"
argument|); 		} 	if( ty != BITYPE ) { 		if( p->in.op == NAME || p->in.op == ICON ) printf(
literal|"0\t"
argument|); 		else printf(
literal|"%d\t"
argument|, p->tn.rval ); 		}  	printf(
literal|"%o\t"
argument|, p->in.type );
comment|/* handle special cases */
argument|switch( p->in.op ){  	case NAME: 	case ICON:
comment|/* print external name */
argument|if( p->tn.rval == NONAME ) printf(
literal|"\n"
argument|); 		else if( p->tn.rval>=
literal|0
argument|){ 			q =&stab[p->tn.rval]; 			printf(
literal|"%s\n"
argument|, exname(q->sname) ); 			} 		else {
comment|/* label */
argument|printf( LABFMT, -p->tn.rval ); 			} 		break;  	case STARG: 	case STASG: 	case STCALL: 	case UNARY STCALL:
comment|/* print out size */
comment|/* use lhs size, in order to avoid hassles with the structure `.' operator */
comment|/* note: p->in.left not a field... */
argument|printf( CONFMT, (CONSZ) tsize( STRTY, p->in.left->fn.cdim, p->in.left->fn.csiz ) ); 		printf(
literal|"\t%d\t\n"
argument|, talign( STRTY, p->in.left->fn.csiz ) ); 		break;  	default: 		printf(
literal|"\n"
argument|); 		}  	if( ty != LTYPE ) prtree( p->in.left ); 	if( ty == BITYPE ) prtree( p->in.right );  	}
else|#
directive|else
argument|p2tree(p) register NODE *p; { 	register ty;
ifdef|#
directive|ifdef
name|MYP2TREE
argument|MYP2TREE(p);
comment|/* local action can be taken here; then return... */
endif|#
directive|endif
argument|ty = optype(p->in.op);  	switch( p->in.op ){  	case NAME: 	case ICON:
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if( p->tn.rval == NONAME ) p->in.name[
literal|0
argument|] =
literal|'\0'
argument|;
else|#
directive|else
argument|if( p->tn.rval == NONAME ) p->in.name =
literal|""
argument|;
endif|#
directive|endif
argument|else if( p->tn.rval>=
literal|0
argument|){
comment|/* copy name from exname */
argument|register char *cp; 			cp = exname( stab[p->tn.rval].sname );
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|{ 				register i; 				for( i=
literal|0
argument|; i<NCHNAM; ++i ) 					p->in.name[i] = *cp++; 			}
else|#
directive|else
argument|p->in.name = tstr(cp);
endif|#
directive|endif
argument|}
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|else sprintf( p->in.name, LABFMT, -p->tn.rval );
else|#
directive|else
argument|else { 			char temp[
literal|32
argument|]; 			sprintf( temp, LABFMT, -p->tn.rval ); 			p->in.name = tstr(temp); 		}
endif|#
directive|endif
argument|break;  	case STARG: 	case STASG: 	case STCALL: 	case UNARY STCALL:
comment|/* set up size parameters */
argument|p->stn.stsize = (tsize(STRTY,p->in.left->fn.cdim,p->in.left->fn.csiz)+SZCHAR-
literal|1
argument|)/SZCHAR; 		p->stn.stalign = talign(STRTY,p->in.left->fn.csiz)/SZCHAR; 		break;  	case REG: 		rbusy( p->tn.rval, p->in.type ); 	default:
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|p->in.name[
literal|0
argument|] =
literal|'\0'
argument|;
else|#
directive|else
argument|p->in.name =
literal|""
argument|;
endif|#
directive|endif
argument|}  	p->in.rall = NOPREF;  	if( ty != LTYPE ) p2tree( p->in.left ); 	if( ty == BITYPE ) p2tree( p->in.right ); 	}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

