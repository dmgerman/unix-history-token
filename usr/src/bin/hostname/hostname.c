begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#) Copyright (c) 1983 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
literal|"@(#)hostname.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * hostname -- get (or set hostname)  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|char
name|hostname
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|int
name|myerrno
decl_stmt|;
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
if|if
condition|(
name|argc
condition|)
block|{
if|if
condition|(
name|sethostname
argument_list|(
operator|*
name|argv
argument_list|,
name|strlen
argument_list|(
operator|*
name|argv
argument_list|)
argument_list|)
condition|)
name|perror
argument_list|(
literal|"sethostname"
argument_list|)
expr_stmt|;
name|myerrno
operator|=
name|errno
expr_stmt|;
block|}
else|else
block|{
name|gethostname
argument_list|(
name|hostname
argument_list|,
sizeof|sizeof
argument_list|(
name|hostname
argument_list|)
argument_list|)
expr_stmt|;
name|myerrno
operator|=
name|errno
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|hostname
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
name|myerrno
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

