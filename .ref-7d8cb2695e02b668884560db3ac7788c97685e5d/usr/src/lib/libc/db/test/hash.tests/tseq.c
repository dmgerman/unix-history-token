begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Margo Seltzer.  *  * %sccs.include.redist.c%  */
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
literal|"@(#) Copyright (c) 1991, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
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
literal|"@(#)tseq.c	8.1 (Berkeley) %G%"
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
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_define
define|#
directive|define
name|INITIAL
value|25000
end_define

begin_define
define|#
directive|define
name|MAXWORDS
value|25000
end_define

begin_comment
comment|/* # of elements in search table */
end_comment

begin_decl_stmt
name|char
name|wp
index|[
literal|8192
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cp
index|[
literal|8192
index|]
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
modifier|*
name|argv
decl_stmt|;
block|{
name|DBT
name|item
decl_stmt|,
name|key
decl_stmt|,
name|res
decl_stmt|;
name|DB
modifier|*
name|dbp
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
name|int
name|stat
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|dbp
operator|=
name|dbopen
argument_list|(
literal|"hashtest"
argument_list|,
name|O_RDONLY
argument_list|,
literal|0400
argument_list|,
name|DB_HASH
argument_list|,
name|NULL
argument_list|)
operator|)
condition|)
block|{
comment|/* create table */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"cannot open: hash table\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* * put info in structure, and structure in the item */
for|for
control|(
name|stat
operator|=
call|(
name|dbp
operator|->
name|seq
call|)
argument_list|(
name|dbp
argument_list|,
operator|&
name|res
argument_list|,
operator|&
name|item
argument_list|,
literal|1
argument_list|)
init|;
name|stat
operator|==
literal|0
condition|;
name|stat
operator|=
call|(
name|dbp
operator|->
name|seq
call|)
argument_list|(
name|dbp
argument_list|,
operator|&
name|res
argument_list|,
operator|&
name|item
argument_list|,
literal|0
argument_list|)
control|)
block|{
name|bcopy
argument_list|(
name|res
operator|.
name|data
argument_list|,
name|wp
argument_list|,
name|res
operator|.
name|size
argument_list|)
expr_stmt|;
name|wp
index|[
name|res
operator|.
name|size
index|]
operator|=
literal|0
expr_stmt|;
name|bcopy
argument_list|(
name|item
operator|.
name|data
argument_list|,
name|cp
argument_list|,
name|item
operator|.
name|size
argument_list|)
expr_stmt|;
name|cp
index|[
name|item
operator|.
name|size
index|]
operator|=
literal|0
expr_stmt|;
name|printf
argument_list|(
literal|"%s %s\n"
argument_list|,
name|wp
argument_list|,
name|cp
argument_list|)
expr_stmt|;
block|}
call|(
name|dbp
operator|->
name|close
call|)
argument_list|(
name|dbp
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

