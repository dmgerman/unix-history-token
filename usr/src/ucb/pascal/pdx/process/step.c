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
literal|"@(#)step.c	5.2 (Berkeley) 4/7/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Continue execution up to the next source line.  *  * We call "nextaddr" from the machine module to figure out  * what the object address is that corresponds to the next source line.  * If nextaddr returns -1, then the end of the program has been reached.  *  * There are two ways to define the next source line depending on what  * is desired when a procedure or function call is encountered.  Step  * stops at the beginning of the procedure or call; next skips over it.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"source.h"
end_include

begin_include
include|#
directive|include
file|"mappings.h"
end_include

begin_include
include|#
directive|include
file|"process.rep"
end_include

begin_comment
comment|/*  * Stepc is what is called when the step command is given.  * It has to play with the "isstopped" information.  */
end_comment

begin_macro
name|stepc
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|isstopped
condition|)
block|{
name|error
argument_list|(
literal|"can't continue execution"
argument_list|)
expr_stmt|;
block|}
name|isstopped
operator|=
name|FALSE
expr_stmt|;
name|dostep
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|isstopped
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_macro
name|next
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|isstopped
condition|)
block|{
name|error
argument_list|(
literal|"can't continue execution"
argument_list|)
expr_stmt|;
block|}
name|isstopped
operator|=
name|FALSE
expr_stmt|;
name|dostep
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
name|isstopped
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_macro
name|step
argument_list|()
end_macro

begin_block
block|{
name|dostep
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Resume execution up to the given address.  It is assumed that  * no breakpoints exist between the current address and the one  * we're stepping to.  This saves us from setting all the breakpoints.  */
end_comment

begin_macro
name|stepto
argument_list|(
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|ADDRESS
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|setbp
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|resume
argument_list|()
expr_stmt|;
name|unsetbp
argument_list|(
name|addr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isbperr
argument_list|()
condition|)
block|{
name|printstatus
argument_list|()
expr_stmt|;
block|}
block|}
end_block

begin_function
name|LOCAL
name|dostep
parameter_list|(
name|isnext
parameter_list|)
name|BOOLEAN
name|isnext
decl_stmt|;
block|{
specifier|register
name|ADDRESS
name|addr
decl_stmt|;
specifier|register
name|LINENO
name|line
decl_stmt|;
name|addr
operator|=
name|pc
expr_stmt|;
do|do
block|{
name|addr
operator|=
name|nextaddr
argument_list|(
name|addr
argument_list|,
name|isnext
argument_list|)
expr_stmt|;
name|line
operator|=
name|linelookup
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|line
operator|==
literal|0
operator|&&
operator|!
name|ss_instructions
condition|)
do|;
name|stepto
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|curline
operator|=
name|line
expr_stmt|;
block|}
end_function

end_unit

