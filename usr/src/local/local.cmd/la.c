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
literal|"@(#)la.c	6.1 (Berkeley) %G%"
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
comment|/*  * la - print load averages  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_comment
comment|/* VAX page table entry */
end_comment

begin_include
include|#
directive|include
file|<sys/vm.h>
end_include

begin_decl_stmt
name|struct
name|nlist
name|nl
index|[]
init|=
block|{
block|{
literal|"_avenrun"
block|}
block|,
define|#
directive|define
name|X_AVENRUN
value|0
block|{
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|avenrun
index|[
literal|3
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
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|int
name|kmem
decl_stmt|,
name|mem
decl_stmt|;
name|char
name|obuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|obuf
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|kmem
operator|=
name|open
argument_list|(
literal|"/dev/kmem"
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"No kmem\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|nlist
argument_list|(
literal|"/vmunix"
argument_list|,
name|nl
argument_list|)
expr_stmt|;
if|if
condition|(
name|nl
index|[
literal|0
index|]
operator|.
name|n_type
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"No namelist\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|lseek
argument_list|(
name|kmem
argument_list|,
operator|(
name|long
operator|)
name|nl
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|read
argument_list|(
name|kmem
argument_list|,
name|avenrun
argument_list|,
sizeof|sizeof
argument_list|(
name|avenrun
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|argc
operator|>
literal|1
operator|)
operator|&&
operator|(
operator|!
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"-g"
argument_list|)
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"1    5    15\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Min  Min  Min\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-------------\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"%.2f %.2f %.2f\n"
argument_list|,
name|avenrun
index|[
literal|0
index|]
argument_list|,
name|avenrun
index|[
literal|1
index|]
argument_list|,
name|avenrun
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

