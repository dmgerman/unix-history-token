begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)REMOVE.c	1.5 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_macro
name|REMOVE
argument_list|(
argument|name
argument_list|,
argument|namlim
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|namlim
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|cnt
decl_stmt|;
specifier|register
name|int
name|maxnamlen
init|=
name|namlim
decl_stmt|;
name|char
name|namebuf
index|[
name|NAMSIZ
index|]
decl_stmt|;
comment|/* 	 * trim trailing blanks, and insure that the name  	 * will fit into the file structure 	 */
for|for
control|(
name|cnt
operator|=
literal|0
init|;
name|cnt
operator|<
name|maxnamlen
condition|;
name|cnt
operator|++
control|)
if|if
condition|(
name|name
index|[
name|cnt
index|]
operator|==
literal|'\0'
operator|||
name|name
index|[
name|cnt
index|]
operator|==
literal|' '
condition|)
break|break;
if|if
condition|(
name|cnt
operator|>=
name|NAMSIZ
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: File name too long\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return;
block|}
name|maxnamlen
operator|=
name|cnt
expr_stmt|;
comment|/* 	 * put the name into the buffer with null termination 	 */
for|for
control|(
name|cnt
operator|=
literal|0
init|;
name|cnt
operator|<
name|maxnamlen
condition|;
name|cnt
operator|++
control|)
name|namebuf
index|[
name|cnt
index|]
operator|=
name|name
index|[
name|cnt
index|]
expr_stmt|;
name|namebuf
index|[
name|cnt
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* 	 * unlink the file 	 */
if|if
condition|(
name|unlink
argument_list|(
name|namebuf
argument_list|)
condition|)
block|{
name|PERROR
argument_list|(
literal|"Could not remove "
argument_list|,
name|namebuf
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_block

end_unit

