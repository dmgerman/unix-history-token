begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)print.c	5.2 (Berkeley) 4/7/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Routines to print out symbols.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"sym.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"runtime.h"
end_include

begin_include
include|#
directive|include
file|"classes.h"
end_include

begin_include
include|#
directive|include
file|"sym.rep"
end_include

begin_include
include|#
directive|include
file|"process/process.rep"
end_include

begin_comment
comment|/*  * Note the entry of the given block, unless it's the main program.  */
end_comment

begin_macro
name|printentry
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|SYM
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|s
operator|!=
name|program
condition|)
block|{
name|printf
argument_list|(
literal|"\nentering %s %s\n"
argument_list|,
name|classname
argument_list|(
name|s
argument_list|)
argument_list|,
name|s
operator|->
name|symbol
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * Note the exit of the given block  */
end_comment

begin_macro
name|printexit
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|SYM
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|s
operator|!=
name|program
condition|)
block|{
name|printf
argument_list|(
literal|"leaving %s %s\n\n"
argument_list|,
name|classname
argument_list|(
name|s
argument_list|)
argument_list|,
name|s
operator|->
name|symbol
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * Note the call of s from t.  */
end_comment

begin_macro
name|printcall
argument_list|(
argument|s
argument_list|,
argument|t
argument_list|)
end_macro

begin_decl_stmt
name|SYM
modifier|*
name|s
decl_stmt|,
modifier|*
name|t
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"calling %s"
argument_list|,
name|s
operator|->
name|symbol
argument_list|)
expr_stmt|;
name|printparams
argument_list|(
name|s
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" from %s %s\n"
argument_list|,
name|classname
argument_list|(
name|t
argument_list|)
argument_list|,
name|t
operator|->
name|symbol
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Note the return from s.  If s is a function, print the value  * it is returning.  This is somewhat painful, since the function  * has actually just returned.  */
end_comment

begin_macro
name|printrtn
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|SYM
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|len
decl_stmt|;
name|printf
argument_list|(
literal|"returning "
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|->
name|class
operator|==
name|FUNC
condition|)
block|{
name|len
operator|=
name|size
argument_list|(
name|s
operator|->
name|type
argument_list|)
expr_stmt|;
name|dread
argument_list|(
name|sp
argument_list|,
name|process
operator|->
name|sp
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|sp
operator|+=
name|len
expr_stmt|;
ifdef|#
directive|ifdef
name|tahoe
name|alignstack
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|printval
argument_list|(
name|s
operator|->
name|type
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"from %s\n"
argument_list|,
name|s
operator|->
name|symbol
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Print the values of the parameters of the given procedure or function.  * The frame distinguishes recursive instances of a procedure.  */
end_comment

begin_macro
name|printparams
argument_list|(
argument|f
argument_list|,
argument|frame
argument_list|)
end_macro

begin_decl_stmt
name|SYM
modifier|*
name|f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FRAME
modifier|*
name|frame
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|SYM
modifier|*
name|param
decl_stmt|;
for|for
control|(
name|param
operator|=
name|f
operator|->
name|chain
init|;
name|param
operator|!=
name|NIL
condition|;
name|param
operator|=
name|param
operator|->
name|chain
control|)
block|{
if|if
condition|(
name|param
operator|==
name|f
operator|->
name|chain
condition|)
block|{
name|printf
argument_list|(
literal|"("
argument_list|)
expr_stmt|;
block|}
name|printv
argument_list|(
name|param
argument_list|,
name|frame
argument_list|)
expr_stmt|;
if|if
condition|(
name|param
operator|->
name|chain
operator|!=
name|NIL
condition|)
block|{
name|printf
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|")"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_block

begin_comment
comment|/*  * Print the name and value of a variable.  */
end_comment

begin_macro
name|printv
argument_list|(
argument|s
argument_list|,
argument|frame
argument_list|)
end_macro

begin_decl_stmt
name|SYM
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FRAME
modifier|*
name|frame
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|ADDRESS
name|addr
decl_stmt|;
name|int
name|len
decl_stmt|;
if|if
condition|(
name|s
operator|->
name|class
operator|==
name|REF
condition|)
block|{
name|dread
argument_list|(
operator|&
name|addr
argument_list|,
name|address
argument_list|(
name|s
argument_list|,
name|frame
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|ADDRESS
argument_list|)
argument_list|)
expr_stmt|;
name|len
operator|=
name|size
argument_list|(
name|s
operator|->
name|type
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|addr
operator|=
name|address
argument_list|(
name|s
argument_list|,
name|frame
argument_list|)
expr_stmt|;
name|len
operator|=
name|size
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"%s = "
argument_list|,
name|s
operator|->
name|symbol
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|rpush
argument_list|(
name|addr
argument_list|,
name|len
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"*** expression too large ***"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|s
operator|->
name|class
operator|==
name|REF
operator|||
name|s
operator|->
name|class
operator|==
name|VAR
condition|)
block|{
name|printval
argument_list|(
name|s
operator|->
name|type
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printval
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_block

begin_comment
comment|/*  * Print the fully specified variable that is described by the given identifer.  */
end_comment

begin_macro
name|printwhich
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|SYM
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printouter
argument_list|(
name|s
operator|->
name|func
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|s
operator|->
name|symbol
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|LOCAL
name|printouter
parameter_list|(
name|s
parameter_list|)
name|SYM
modifier|*
name|s
decl_stmt|;
block|{
if|if
condition|(
name|s
operator|->
name|func
operator|!=
name|NIL
condition|)
block|{
name|printouter
argument_list|(
name|s
operator|->
name|func
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"%s."
argument_list|,
name|s
operator|->
name|symbol
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

