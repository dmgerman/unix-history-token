begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1990, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
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
literal|"@(#)mkfifo.c	8.2 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|int
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
name|int
name|optind
decl_stmt|;
name|int
name|ch
decl_stmt|,
name|exitval
decl_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|""
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'?'
case|:
default|default:
name|usage
argument_list|()
expr_stmt|;
block|}
name|argc
operator|-=
name|optind
expr_stmt|;
name|argv
operator|+=
name|optind
expr_stmt|;
if|if
condition|(
name|argv
index|[
literal|0
index|]
operator|==
name|NULL
condition|)
name|usage
argument_list|()
expr_stmt|;
for|for
control|(
name|exitval
operator|=
literal|0
init|;
operator|*
name|argv
operator|!=
name|NULL
condition|;
operator|++
name|argv
control|)
if|if
condition|(
name|mkfifo
argument_list|(
operator|*
name|argv
argument_list|,
name|S_IRWXU
operator||
name|S_IRWXG
operator||
name|S_IRWXO
argument_list|)
operator|<
literal|0
condition|)
block|{
name|warn
argument_list|(
literal|"%s"
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
name|exitval
operator|=
literal|1
expr_stmt|;
block|}
name|exit
argument_list|(
name|exitval
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|usage
argument_list|()
end_macro

begin_block
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: mkfifo fifoname ...\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

