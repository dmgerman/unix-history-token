begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1990 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)makekey.c	5.2 (Berkeley) %G%"
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
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|r
decl_stmt|,
name|key
index|[
literal|9
index|]
decl_stmt|,
name|salt
index|[
literal|3
index|]
decl_stmt|,
modifier|*
name|crypt
argument_list|()
decl_stmt|;
name|get
argument_list|(
name|key
argument_list|,
sizeof|sizeof
argument_list|(
name|key
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|get
argument_list|(
name|salt
argument_list|,
sizeof|sizeof
argument_list|(
name|salt
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|r
operator|=
name|crypt
argument_list|(
name|key
argument_list|,
name|salt
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|write
argument_list|(
name|STDOUT_FILENO
argument_list|,
name|r
argument_list|,
name|len
argument_list|)
operator|!=
name|len
condition|)
name|error
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|get
argument_list|(
argument|bp
argument_list|,
argument|len
argument_list|)
name|char
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|nr
decl_stmt|;
name|bp
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|(
name|nr
operator|=
name|read
argument_list|(
name|STDIN_FILENO
argument_list|,
name|bp
argument_list|,
name|len
argument_list|)
operator|)
operator|==
name|len
condition|)
return|return;
if|if
condition|(
name|nr
operator|>=
literal|0
condition|)
name|errno
operator|=
name|EFTYPE
expr_stmt|;
name|error
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|error
argument_list|()
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"makekey: %s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
block|;
name|exit
argument_list|(
literal|1
argument_list|)
block|; }
end_expr_stmt

end_unit

