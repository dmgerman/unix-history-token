begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Margo Seltzer.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)tseq.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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

