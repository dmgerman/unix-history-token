begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)parse.c	4.1	(Berkeley)	%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  			  Copyright (C) 1976 				by the 			  Board of Trustees 				of the 			University of Illinois  			 All rights reserved   FILE NAME: 	parse.c  PURPOSE: 	Contains the routines which keep track of the parse stack.  GLOBALS: 	p_stack =	The parse stack, set by both routines 	il =		Stack of indentation levels, set by parse 	cstk =		Stack of case statement indentation levels, set by parse 	tos =		Pointer to top of stack, set by both routines.  FUNCTIONS: 	parse 	reduce */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  			  Copyright (C) 1976 				by the 			  Board of Trustees 				of the 			University of Illinois  			 All rights reserved   NAME: 	parse  FUNCTION: 	Parse is given one input which is a "maxi token" just scanned from 	input.  Maxi tokens are signifigant constructs such as else, {, do, 	if (...), etc.  Parse works with reduce to maintain a parse stack 	of these constructs.  Parse is responsible for the "shift" portion 	of the parse algorithm, and reduce handles the "reduce" portion.  ALGORITHM: 	1) If there is "ifstmt" on the stack and input is anything other than 	   an else, then change the top of stack (TOS) to<stmt>.  Do a reduce. 	2) Use a switch statement to implement the following shift operations:  	   TOS
comment|___		Input
comment|_____		Stack
comment|_____		Note
comment|____ 	decl		decl		nothing 	anything else	decl		decl 	"dostmt"	while (..)			Change TOS to<stmt> 	anything else	while (..)	while 	"ifstmt"	else				Change TOS to "ifelse" 	{<stmtl>	}				Change {<stmtl>  								to<stmtl> 			switch (..)	switch 			do		do 			for(..)		for 			;<stmt> 			{		{<stmt>  PARAMETERS: 	tk	An integer code for the maxi token scanned  RETURNS: 	Nothing  GLOBALS: 	break_comma =	Set to true when in a declaration but not initialization 	btype_2 	case_ind = 	cstk = 	i_l_follow = 	il =		Stack of indentation levels 	ind_level = 	p_stack =	Stack of token codes 	search_brace =	Set to true if we must look for possibility of moving a 			brace 	tos =		Pointer to top of p_stack, il, and cstk  CALLS: 	printf (lib) 	reduce  CALLED BY: 	main  HISTORY: 	initial coding 	November 1976	D A Willcox of CAC  */
end_comment

begin_escape
end_escape

begin_include
include|#
directive|include
file|"./indent_globs.h"
include|;
end_include

begin_include
include|#
directive|include
file|"./indent_codes.h"
include|;
end_include

begin_decl_stmt
name|int
name|p_stack
index|[
literal|50
index|]
init|=
name|stmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this is the parser's stack */
end_comment

begin_decl_stmt
name|int
name|il
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this stack stores indentation levels */
end_comment

begin_decl_stmt
name|int
name|cstk
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to store case stmt indentation levels */
end_comment

begin_decl_stmt
name|int
name|tos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to top of stack */
end_comment

begin_macro
name|parse
argument_list|(
argument|tk
argument_list|)
end_macro

begin_decl_stmt
name|int
name|tk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the code for the construct scanned */
end_comment

begin_block
block|{
name|int
name|i
decl_stmt|;
ifdef|#
directive|ifdef
name|debug
name|printf
argument_list|(
literal|"%2d - %s\n"
argument_list|,
name|tk
argument_list|,
name|token
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
name|p_stack
index|[
name|tos
index|]
operator|==
name|ifhead
operator|&&
name|tk
operator|!=
name|elselit
condition|)
block|{
comment|/* true if we have an if without an else */
name|p_stack
index|[
name|tos
index|]
operator|=
name|stmt
expr_stmt|;
comment|/* apply the if(..) stmt ::= stmt reduction */
name|reduce
argument_list|()
expr_stmt|;
comment|/* see if this allows any reduction */
block|}
switch|switch
condition|(
name|tk
condition|)
block|{
comment|/* go on and figure out what to do with the 			          input */
case|case
name|decl
case|:
comment|/* scanned a declaration word */
name|search_brace
operator|=
name|btype_2
expr_stmt|;
comment|/* indicate that following brace should be on same line */
if|if
condition|(
name|p_stack
index|[
name|tos
index|]
operator|!=
name|decl
condition|)
block|{
comment|/* only put one declaration onto stack */
name|break_comma
operator|=
name|true
expr_stmt|;
comment|/* while in declaration, newline should be forced after comma */
name|p_stack
index|[
operator|++
name|tos
index|]
operator|=
name|decl
expr_stmt|;
name|il
index|[
name|tos
index|]
operator|=
name|i_l_follow
expr_stmt|;
if|if
condition|(
name|ljust_decl
condition|)
block|{
comment|/* only do if we want left justified declarations */
name|ind_level
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
name|tos
operator|-
literal|1
init|;
name|i
operator|>
literal|0
condition|;
operator|--
name|i
control|)
if|if
condition|(
name|p_stack
index|[
name|i
index|]
operator|==
name|decl
condition|)
operator|++
name|ind_level
expr_stmt|;
comment|/* indentation is number of declaration levels deep we are */
name|i_l_follow
operator|=
name|ind_level
expr_stmt|;
block|}
block|}
break|break;
case|case
name|ifstmt
case|:
comment|/* scanned if (...) */
case|case
name|dolit
case|:
comment|/* 'do' */
case|case
name|forstmt
case|:
comment|/* for (...) */
name|p_stack
index|[
operator|++
name|tos
index|]
operator|=
name|tk
expr_stmt|;
name|il
index|[
name|tos
index|]
operator|=
name|ind_level
operator|=
name|i_l_follow
expr_stmt|;
operator|++
name|i_l_follow
expr_stmt|;
comment|/* subsequent statements should be indented 1 */
name|search_brace
operator|=
name|btype_2
expr_stmt|;
break|break;
case|case
name|lbrace
case|:
comment|/* scanned { */
name|break_comma
operator|=
name|false
expr_stmt|;
comment|/* don't break comma in an initial list */
if|if
condition|(
name|p_stack
index|[
name|tos
index|]
operator|==
name|stmt
operator|||
name|p_stack
index|[
name|tos
index|]
operator|==
name|decl
operator|||
name|p_stack
index|[
name|tos
index|]
operator|==
name|stmtl
condition|)
operator|++
name|i_l_follow
expr_stmt|;
comment|/* it is a random, isolated stmt group or a 			          declaration */
else|else
block|{
if|if
condition|(
name|s_code
operator|==
name|e_code
condition|)
block|{
comment|/* only do this if there is nothing on the line */
operator|--
name|ind_level
expr_stmt|;
comment|/* it is a group as part of a while, for, etc. */
if|if
condition|(
name|p_stack
index|[
name|tos
index|]
operator|==
name|swstmt
condition|)
operator|--
name|ind_level
expr_stmt|;
comment|/* for a switch, brace should be two levels out from the code  		*/
block|}
block|}
name|p_stack
index|[
operator|++
name|tos
index|]
operator|=
name|lbrace
expr_stmt|;
name|il
index|[
name|tos
index|]
operator|=
name|ind_level
expr_stmt|;
name|p_stack
index|[
operator|++
name|tos
index|]
operator|=
name|stmt
expr_stmt|;
comment|/* allow null stmt between braces */
name|il
index|[
name|tos
index|]
operator|=
name|i_l_follow
expr_stmt|;
break|break;
case|case
name|whilestmt
case|:
comment|/* scanned while (...) */
if|if
condition|(
name|p_stack
index|[
name|tos
index|]
operator|==
name|dohead
condition|)
block|{
comment|/* it is matched with do stmt */
name|ind_level
operator|=
name|i_l_follow
operator|=
name|il
index|[
name|tos
index|]
expr_stmt|;
name|p_stack
index|[
operator|++
name|tos
index|]
operator|=
name|whilestmt
expr_stmt|;
name|il
index|[
name|tos
index|]
operator|=
name|ind_level
operator|=
name|i_l_follow
expr_stmt|;
block|}
else|else
block|{
comment|/* it is a while loop */
name|p_stack
index|[
operator|++
name|tos
index|]
operator|=
name|whilestmt
expr_stmt|;
name|il
index|[
name|tos
index|]
operator|=
name|i_l_follow
expr_stmt|;
operator|++
name|i_l_follow
expr_stmt|;
name|search_brace
operator|=
name|btype_2
expr_stmt|;
block|}
break|break;
case|case
name|elselit
case|:
comment|/* scanned an else */
if|if
condition|(
name|p_stack
index|[
name|tos
index|]
operator|!=
name|ifhead
condition|)
block|{
name|printf
argument_list|(
literal|"%d: Unmatched else\n"
argument_list|,
name|line_no
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ind_level
operator|=
name|il
index|[
name|tos
index|]
expr_stmt|;
comment|/* indentation for else should be same as for if */
name|i_l_follow
operator|=
name|ind_level
operator|+
literal|1
expr_stmt|;
comment|/* everything following should be in 1 level */
name|p_stack
index|[
name|tos
index|]
operator|=
name|elsehead
expr_stmt|;
comment|/* remember if with else */
name|search_brace
operator|=
name|btype_2
expr_stmt|;
block|}
break|break;
case|case
name|rbrace
case|:
comment|/* scanned a } */
comment|/* stack should have<lbrace><stmt> or<lbrace><stmtl> */
if|if
condition|(
name|p_stack
index|[
name|tos
operator|-
literal|1
index|]
operator|==
name|lbrace
condition|)
block|{
name|ind_level
operator|=
name|i_l_follow
operator|=
name|il
index|[
operator|--
name|tos
index|]
expr_stmt|;
name|p_stack
index|[
name|tos
index|]
operator|=
name|stmt
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"%d: Stmt nesting error\n"
argument_list|,
name|line_no
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|swstmt
case|:
comment|/* had switch (...) */
name|p_stack
index|[
operator|++
name|tos
index|]
operator|=
name|swstmt
expr_stmt|;
name|cstk
index|[
name|tos
index|]
operator|=
name|case_ind
expr_stmt|;
comment|/* save current case indent level */
name|il
index|[
name|tos
index|]
operator|=
name|i_l_follow
expr_stmt|;
name|case_ind
operator|=
name|i_l_follow
operator|+
literal|1
expr_stmt|;
comment|/* cases should be one level down from switch */
name|i_l_follow
operator|+
operator|=
literal|2
expr_stmt|;
comment|/* statements should be two levels in */
name|search_brace
operator|=
name|btype_2
expr_stmt|;
break|break;
case|case
name|semicolon
case|:
comment|/* this indicates a simple stmt */
name|break_comma
operator|=
name|false
expr_stmt|;
comment|/* turn off flag to break after commas in a declaration */
name|p_stack
index|[
operator|++
name|tos
index|]
operator|=
name|stmt
expr_stmt|;
name|il
index|[
name|tos
index|]
operator|=
name|ind_level
expr_stmt|;
break|break;
default|default:
comment|/* this is an error */
name|printf
argument_list|(
literal|"%d: Unknown code to parser - %d\n"
argument_list|,
name|line_no
argument_list|,
name|tk
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* end of switch */
name|reduce
argument_list|()
expr_stmt|;
comment|/* see if any reduction can be done */
ifdef|#
directive|ifdef
name|debug
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<=
name|tos
condition|;
operator|++
name|i
control|)
name|printf
argument_list|(
literal|"(%d %d)"
argument_list|,
name|p_stack
index|[
name|i
index|]
argument_list|,
name|il
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  			  Copyright (C) 1976 				by the 			  Board of Trustees 				of the 			University of Illinois  			 All rights reserved   NAME: 	reduce  FUNCTION: 	Implements the reduce part of the parsing algorithm  ALGORITHM: 	The following reductions are done.  Reductions are repeated until no 	more are possible.  	Old
comment|___ TOS
comment|___		New
comment|___ TOS
comment|___<stmt><stmt><stmtl><stmtl><stmt><stmtl> 	do<stmt>	"dostmt" 	if<stmt>	"ifstmt" 	switch<stmt><stmt> 	decl<stmt><stmt> 	"ifelse"<stmt><stmt> 	for<stmt><stmt> 	while<stmt><stmt> 	"dostmt" while<stmt>  	On each reduction, i_l_follow (the indentation for the following line) 	is set to the indentation level associated with the old TOS.  PARAMETERS: 	None  RETURNS: 	Nothing  GLOBALS: 	cstk 	i_l_follow = 	il 	p_stack = 	tos =  CALLS: 	None  CALLED BY: 	parse
comment|HISTORY: 	initial coding 	November 1976	D A Willcox of CAC  */
end_comment

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------*\ |   REDUCTION PHASE \*----------------------------------------------*/
end_comment

begin_macro
name|reduce
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* local looping variable */
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* keep looping until there is nothing left to 			          reduce */
switch|switch
condition|(
name|p_stack
index|[
name|tos
index|]
condition|)
block|{
case|case
name|stmt
case|:
switch|switch
condition|(
name|p_stack
index|[
name|tos
operator|-
literal|1
index|]
condition|)
block|{
case|case
name|stmt
case|:
case|case
name|stmtl
case|:
comment|/* stmtl stmt or stmt stmt */
name|p_stack
index|[
operator|--
name|tos
index|]
operator|=
name|stmtl
expr_stmt|;
break|break;
case|case
name|dolit
case|:
comment|/*<do><stmt> */
name|p_stack
index|[
operator|--
name|tos
index|]
operator|=
name|dohead
expr_stmt|;
name|i_l_follow
operator|=
name|il
index|[
name|tos
index|]
expr_stmt|;
break|break;
case|case
name|ifstmt
case|:
comment|/*<if><stmt> */
name|p_stack
index|[
operator|--
name|tos
index|]
operator|=
name|ifhead
expr_stmt|;
for|for
control|(
name|i
operator|=
name|tos
operator|-
literal|1
init|;
operator|(
name|p_stack
index|[
name|i
index|]
operator|!=
name|stmt
operator|&&
name|p_stack
index|[
name|i
index|]
operator|!=
name|stmtl
operator|&&
name|p_stack
index|[
name|i
index|]
operator|!=
name|lbrace
operator|)
condition|;
operator|--
name|i
control|)
empty_stmt|;
name|i_l_follow
operator|=
name|il
index|[
name|i
index|]
expr_stmt|;
comment|/* for the time being, we will assume that there is no else 		       on this if, and set the indentation level accordingly. 		       If an else is scanned, it will be fixed up later */
break|break;
case|case
name|swstmt
case|:
comment|/*<switch><stmt> */
name|case_ind
operator|=
name|cstk
index|[
name|tos
operator|-
literal|1
index|]
expr_stmt|;
case|case
name|decl
case|:
comment|/* finish of a declaration */
case|case
name|elsehead
case|:
comment|/*<<if><stmt> else><stmt> */
case|case
name|forstmt
case|:
comment|/*<for><stmt> */
case|case
name|whilestmt
case|:
comment|/*<while><stmt> */
name|p_stack
index|[
operator|--
name|tos
index|]
operator|=
name|stmt
expr_stmt|;
name|i_l_follow
operator|=
name|il
index|[
name|tos
index|]
expr_stmt|;
break|break;
default|default:
comment|/*<anything else><stmt> */
return|return;
block|}
comment|/* end of section for<stmt> on top of stack */
break|break;
case|case
name|whilestmt
case|:
comment|/* while (...) on top */
if|if
condition|(
name|p_stack
index|[
name|tos
operator|-
literal|1
index|]
operator|==
name|dohead
condition|)
block|{
comment|/* it is termination of a do while */
name|p_stack
index|[
operator|--
name|tos
index|]
operator|=
name|stmt
expr_stmt|;
break|break;
block|}
else|else
return|return;
default|default:
comment|/* anything else on top */
return|return;
block|}
comment|/* end of big switch */
block|}
comment|/* end of reduction phase for (;;) */
block|}
end_block

end_unit

