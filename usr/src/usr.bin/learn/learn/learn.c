begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#) Copyright (c) 1986 The Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)learn.c	4.7 (Berkeley) %G%"
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
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"lrnref.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|direct
init|=
name|_PATH_LEARN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|more
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|speed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|todo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|incopy
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|didok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sequence
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|comfile
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wrong
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pwline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|scrin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|logging
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 0 to turn off logging */
end_comment

begin_decl_stmt
name|int
name|ask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|again
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|skip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|teed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|total
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|hangup
argument_list|()
decl_stmt|,
name|intrpt
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|getlogin
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|;
name|speed
operator|=
literal|0
expr_stmt|;
name|more
operator|=
literal|1
expr_stmt|;
name|pwline
operator|=
name|getlogin
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|BSD4_2
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|malloc
argument_list|(
name|BUFSIZ
argument_list|)
argument_list|)
expr_stmt|;
name|setbuf
argument_list|(
name|stderr
argument_list|,
name|malloc
argument_list|(
name|BUFSIZ
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|selsub
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|chgenv
argument_list|()
expr_stmt|;
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|hangup
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|intrpt
argument_list|)
expr_stmt|;
while|while
condition|(
name|more
condition|)
block|{
name|selunit
argument_list|()
expr_stmt|;
name|dounit
argument_list|()
expr_stmt|;
name|whatnow
argument_list|()
expr_stmt|;
block|}
name|wrapup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|hangup
parameter_list|()
block|{
name|wrapup
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|intrpt
parameter_list|()
block|{
name|char
name|response
index|[
literal|20
index|]
decl_stmt|,
modifier|*
name|p
decl_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|hangup
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
literal|"\nInterrupt.\nWant to go on?  "
argument_list|,
literal|28
argument_list|)
expr_stmt|;
name|p
operator|=
name|response
expr_stmt|;
operator|*
name|p
operator|=
literal|'n'
expr_stmt|;
while|while
condition|(
name|read
argument_list|(
literal|0
argument_list|,
name|p
argument_list|,
literal|1
argument_list|)
operator|==
literal|1
operator|&&
operator|*
name|p
operator|!=
literal|'\n'
condition|)
name|p
operator|++
expr_stmt|;
if|if
condition|(
name|response
index|[
literal|0
index|]
operator|!=
literal|'y'
condition|)
name|wrapup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|ungetc
argument_list|(
literal|'\n'
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|intrpt
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

