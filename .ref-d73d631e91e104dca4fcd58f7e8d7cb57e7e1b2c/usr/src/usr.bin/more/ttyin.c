begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)ttyin.c	5.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Routines dealing with getting input from the keyboard (i.e. from the user).  */
end_comment

begin_include
include|#
directive|include
file|<less.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Open keyboard for input.  * (Just use file descriptor 2.)  */
end_comment

begin_macro
name|open_getchr
argument_list|()
end_macro

begin_block
block|{
name|tty
operator|=
literal|2
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Get a character from the keyboard.  */
end_comment

begin_macro
name|getchr
argument_list|()
end_macro

begin_block
block|{
name|char
name|c
decl_stmt|;
name|int
name|result
decl_stmt|;
do|do
block|{
name|result
operator|=
name|iread
argument_list|(
name|tty
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|READ_INTR
condition|)
return|return
operator|(
name|READ_INTR
operator|)
return|;
if|if
condition|(
name|result
operator|<
literal|0
condition|)
block|{
comment|/* 			 * Don't call error() here, 			 * because error calls getchr! 			 */
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
do|while
condition|(
name|result
operator|!=
literal|1
condition|)
do|;
return|return
operator|(
name|c
operator|&
literal|0177
operator|)
return|;
block|}
end_block

end_unit

