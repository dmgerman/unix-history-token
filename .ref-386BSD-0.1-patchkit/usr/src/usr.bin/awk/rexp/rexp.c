begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** rexp.c copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log:	rexp.c,v $  * Revision 3.4  91/08/13  09:09:59  brennan  * VERSION .9994  *   * Revision 3.3  91/08/04  15:45:03  brennan  * no longer attempt to recover mem on failed REcompile  * Its not worth the effort  *   * Revision 3.2  91/08/03  07:24:06  brennan  * check for empty machine stack (missing operand) wasn't quite right  *   * Revision 3.1  91/06/07  10:33:16  brennan  * VERSION 0.995  *   * Revision 1.7  91/06/05  08:58:47  brennan  * change RE_free to free  *   * Revision 1.6  91/06/03  07:07:17  brennan  * moved parser stacks inside REcompile  * removed unnecessary copying  *  */
end_comment

begin_comment
comment|/*  op precedence  parser for regular expressions  */
end_comment

begin_include
include|#
directive|include
file|"rexp.h"
end_include

begin_comment
comment|/*  DATA   */
end_comment

begin_decl_stmt
name|int
name|REerrno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|REerrlist
index|[]
init|=
block|{
operator|(
name|char
operator|*
operator|)
literal|0
block|,
comment|/* 1  */
literal|"missing '('"
block|,
comment|/* 2  */
literal|"missing ')'"
block|,
comment|/* 3  */
literal|"bad class -- [], [^] or ["
block|,
comment|/* 4  */
literal|"missing operand"
block|,
comment|/* 5  */
literal|"resource exhaustion -- regular expression too large"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* E5 is very unlikely to occur */
end_comment

begin_comment
comment|/* This table drives the operator precedence parser */
end_comment

begin_decl_stmt
specifier|static
name|short
name|table
index|[
literal|8
index|]
index|[
literal|8
index|]
init|=
block|{
comment|/*        0   |   CAT   *   +   ?   (   )   */
comment|/* 0 */
literal|0
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|E1
block|,
comment|/* | */
name|G
block|,
name|G
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|G
block|,
comment|/* CAT*/
name|G
block|,
name|G
block|,
name|G
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|G
block|,
comment|/* * */
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|E7
block|,
name|G
block|,
comment|/* + */
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|E7
block|,
name|G
block|,
comment|/* ? */
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|E7
block|,
name|G
block|,
comment|/* ( */
name|E2
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|L
block|,
name|EQ
block|,
comment|/* ) */
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|G
block|,
name|E7
block|,
name|G
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STACKSZ
value|64
end_define

begin_decl_stmt
specifier|static
name|jmp_buf
name|err_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  used to trap on error */
end_comment

begin_function
name|void
name|RE_error_trap
parameter_list|(
name|x
parameter_list|)
comment|/* return is dummy to make macro OK */
name|int
name|x
decl_stmt|;
block|{
name|REerrno
operator|=
name|x
expr_stmt|;
name|longjmp
argument_list|(
name|err_buf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|VOID
modifier|*
name|REcompile
parameter_list|(
name|re
parameter_list|)
name|char
modifier|*
name|re
decl_stmt|;
block|{
name|MACHINE
name|m_stack
index|[
name|STACKSZ
index|]
decl_stmt|;
struct|struct
name|op
block|{
name|int
name|token
decl_stmt|;
name|int
name|prec
decl_stmt|;
block|}
name|op_stack
index|[
name|STACKSZ
index|]
struct|;
specifier|register
name|MACHINE
modifier|*
name|m_ptr
decl_stmt|;
specifier|register
name|struct
name|op
modifier|*
name|op_ptr
decl_stmt|;
specifier|register
name|int
name|t
decl_stmt|;
comment|/* do this first because it also checks if we have a      run time stack */
name|RE_lex_init
argument_list|(
name|re
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|re
operator|==
literal|0
condition|)
block|{
name|STATE
modifier|*
name|p
init|=
operator|(
name|STATE
operator|*
operator|)
name|RE_malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|STATE
argument_list|)
argument_list|)
decl_stmt|;
name|p
operator|->
name|type
operator|=
name|M_ACCEPT
expr_stmt|;
return|return
operator|(
name|VOID
operator|*
operator|)
name|p
return|;
block|}
if|if
condition|(
name|setjmp
argument_list|(
name|err_buf
argument_list|)
condition|)
return|return
operator|(
name|VOID
operator|*
operator|)
literal|0
return|;
comment|/* we used to try to recover memory left on machine stack ;      but now m_ptr is in a register so it won't be right unless      we force it out of a register which isn't worth the trouble */
comment|/* initialize the stacks  */
name|m_ptr
operator|=
name|m_stack
operator|-
literal|1
expr_stmt|;
name|op_ptr
operator|=
name|op_stack
expr_stmt|;
name|op_ptr
operator|->
name|token
operator|=
literal|0
expr_stmt|;
name|t
operator|=
name|RE_lex
argument_list|(
name|m_stack
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|T_STR
case|:
case|case
name|T_ANY
case|:
case|case
name|T_U
case|:
case|case
name|T_START
case|:
case|case
name|T_END
case|:
case|case
name|T_CLASS
case|:
name|m_ptr
operator|++
expr_stmt|;
break|break ;
case|case
literal|0
case|:
comment|/*  end of reg expr   */
if|if
condition|(
name|op_ptr
operator|->
name|token
operator|==
literal|0
condition|)
comment|/*  done   */
if|if
condition|(
name|m_ptr
operator|==
name|m_stack
condition|)
return|return
operator|(
name|VOID
operator|*
operator|)
name|m_ptr
operator|->
name|start
return|;
else|else
comment|/*  machines still on the stack  */
name|RE_panic
argument_list|(
literal|"values still on machine stack"
argument_list|)
expr_stmt|;
comment|/*  otherwise  fall  thru to default              which is operator case  */
default|default:
if|if
condition|(
operator|(
name|op_ptr
operator|->
name|prec
operator|=
name|table
index|[
name|op_ptr
operator|->
name|token
index|]
index|[
name|t
index|]
operator|)
operator|==
name|G
condition|)
block|{
do|do
block|{
comment|/* op_pop   */
if|if
condition|(
name|op_ptr
operator|->
name|token
operator|<=
name|T_CAT
condition|)
comment|/*binary op*/
name|m_ptr
operator|--
expr_stmt|;
comment|/* if not enough values on machine stack 		   then we have a missing operand */
if|if
condition|(
name|m_ptr
operator|<
name|m_stack
condition|)
name|RE_error_trap
argument_list|(
operator|-
name|E4
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|op_ptr
operator|->
name|token
condition|)
block|{
case|case
name|T_CAT
case|:
name|RE_cat
argument_list|(
name|m_ptr
argument_list|,
name|m_ptr
operator|+
literal|1
argument_list|)
expr_stmt|;
break|break ;
case|case
name|T_OR
case|:
name|RE_or
argument_list|(
name|m_ptr
argument_list|,
name|m_ptr
operator|+
literal|1
argument_list|)
expr_stmt|;
break|break ;
case|case
name|T_STAR
case|:
name|RE_close
argument_list|(
name|m_ptr
argument_list|)
expr_stmt|;
break|break ;
case|case
name|T_PLUS
case|:
name|RE_poscl
argument_list|(
name|m_ptr
argument_list|)
expr_stmt|;
break|break ;
case|case
name|T_Q
case|:
name|RE_01
argument_list|(
name|m_ptr
argument_list|)
expr_stmt|;
break|break ;
default|default       :
break|break ;
comment|/*nothing on ( or ) */
block|}
name|op_ptr
operator|--
expr_stmt|;
block|}
do|while
condition|(
name|op_ptr
operator|->
name|prec
operator|!=
name|L
condition|)
do|;
continue|continue ;
comment|/* back thru switch at top */
block|}
if|if
condition|(
name|op_ptr
operator|->
name|prec
operator|<
literal|0
condition|)
if|if
condition|(
name|op_ptr
operator|->
name|prec
operator|==
name|E7
condition|)
name|RE_panic
argument_list|(
literal|"parser returns E7"
argument_list|)
expr_stmt|;
else|else
name|RE_error_trap
argument_list|(
operator|-
name|op_ptr
operator|->
name|prec
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|op_ptr
operator|==
name|op_stack
operator|+
name|STACKSZ
condition|)
comment|/* stack overflow */
name|RE_error_trap
argument_list|(
operator|-
name|E5
argument_list|)
expr_stmt|;
name|op_ptr
operator|->
name|token
operator|=
name|t
expr_stmt|;
block|}
comment|/* end of switch */
if|if
condition|(
name|m_ptr
operator|==
name|m_stack
operator|+
operator|(
name|STACKSZ
operator|-
literal|1
operator|)
condition|)
comment|/*overflow*/
name|RE_error_trap
argument_list|(
operator|-
name|E5
argument_list|)
expr_stmt|;
name|t
operator|=
name|RE_lex
argument_list|(
name|m_ptr
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* getting here means a logic flaw or unforeseen case */
end_comment

begin_function
name|void
name|RE_panic
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"REcompile() - panic:  %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|100
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

