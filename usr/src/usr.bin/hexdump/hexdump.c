begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#) Copyright (c) 1989 The Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)hexdump.c	5.4 (Berkeley) %G%"
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"hexdump.h"
end_include

begin_decl_stmt
name|FS
modifier|*
name|fshead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of format strings */
end_comment

begin_decl_stmt
name|int
name|blocksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data block size */
end_comment

begin_decl_stmt
name|int
name|exitval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* final exit value */
end_comment

begin_decl_stmt
name|int
name|length
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max bytes to read */
end_comment

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
modifier|*
name|argv
decl_stmt|;
block|{
specifier|extern
name|int
name|errno
decl_stmt|;
specifier|register
name|FS
modifier|*
name|tfs
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|p
operator|=
name|rindex
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|'o'
argument_list|)
operator|)
operator|||
name|strcmp
argument_list|(
name|p
argument_list|,
literal|"od"
argument_list|)
condition|)
name|newsyntax
argument_list|(
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
expr_stmt|;
else|else
name|oldsyntax
argument_list|(
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
expr_stmt|;
comment|/* figure out the data block size */
for|for
control|(
name|blocksize
operator|=
literal|0
operator|,
name|tfs
operator|=
name|fshead
init|;
name|tfs
condition|;
name|tfs
operator|=
name|tfs
operator|->
name|nextfs
control|)
block|{
name|tfs
operator|->
name|bcnt
operator|=
name|size
argument_list|(
name|tfs
argument_list|)
expr_stmt|;
if|if
condition|(
name|blocksize
operator|<
name|tfs
operator|->
name|bcnt
condition|)
name|blocksize
operator|=
name|tfs
operator|->
name|bcnt
expr_stmt|;
block|}
comment|/* rewrite the rules, do syntax checking */
for|for
control|(
name|tfs
operator|=
name|fshead
init|;
name|tfs
condition|;
name|tfs
operator|=
name|tfs
operator|->
name|nextfs
control|)
name|rewrite
argument_list|(
name|tfs
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|next
argument_list|(
name|argv
argument_list|)
expr_stmt|;
name|display
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|exitval
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

