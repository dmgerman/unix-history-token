begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#) Copyright (c) 1980, 1987 Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)users.c	5.6 (Berkeley) 6/29/88"
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
comment|/*  * users  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|NMAX
value|sizeof(utmp.ut_name)
end_define

begin_define
define|#
directive|define
name|MAXUSERS
value|200
end_define

begin_define
define|#
directive|define
name|UTMP_FILE
value|"/etc/utmp"
end_define

begin_decl_stmt
specifier|static
name|struct
name|utmp
name|utmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read structure */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ncnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of names */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|names
index|[
name|MAXUSERS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* names table */
end_comment

begin_function
name|main
parameter_list|()
block|{
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* file pointer */
if|if
condition|(
operator|!
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|UTMP_FILE
argument_list|,
literal|"r"
argument_list|)
operator|)
condition|)
block|{
name|perror
argument_list|(
name|UTMP_FILE
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|fread
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|utmp
argument_list|,
sizeof|sizeof
argument_list|(
name|utmp
argument_list|)
argument_list|,
literal|1
argument_list|,
name|fp
argument_list|)
operator|==
literal|1
condition|)
if|if
condition|(
operator|*
name|utmp
operator|.
name|ut_name
condition|)
block|{
if|if
condition|(
operator|++
name|ncnt
operator|>
name|MAXUSERS
condition|)
block|{
name|ncnt
operator|=
name|MAXUSERS
expr_stmt|;
name|fputs
argument_list|(
literal|"users: too many users.\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
break|break;
block|}
name|nsave
argument_list|()
expr_stmt|;
block|}
name|summary
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|nsave
argument_list|()
end_macro

begin_block
block|{
specifier|static
name|char
modifier|*
modifier|*
name|namp
init|=
name|names
decl_stmt|;
comment|/* pointer to names table */
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
if|if
condition|(
operator|!
operator|(
operator|*
name|namp
operator|=
name|calloc
argument_list|(
call|(
name|u_int
call|)
argument_list|(
name|NMAX
operator|+
literal|1
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
operator|)
condition|)
block|{
name|fputs
argument_list|(
literal|"users: malloc error.\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|bcopy
argument_list|(
name|utmp
operator|.
name|ut_name
argument_list|,
operator|*
name|namp
operator|++
argument_list|,
name|NMAX
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|summary
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|char
modifier|*
modifier|*
name|p
decl_stmt|;
name|int
name|scmp
parameter_list|()
function_decl|;
if|if
condition|(
operator|!
name|ncnt
condition|)
return|return;
name|qsort
argument_list|(
operator|(
name|char
operator|*
operator|)
name|names
argument_list|,
name|ncnt
argument_list|,
sizeof|sizeof
argument_list|(
name|names
index|[
literal|0
index|]
argument_list|)
argument_list|,
name|scmp
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|names
index|[
literal|0
index|]
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
for|for
control|(
name|p
operator|=
operator|&
name|names
index|[
literal|1
index|]
init|;
operator|--
name|ncnt
condition|;
operator|++
name|p
control|)
block|{
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
operator|*
name|p
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|scmp
argument_list|(
argument|p
argument_list|,
argument|q
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
modifier|*
name|p
decl_stmt|,
modifier|*
modifier|*
name|q
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|strcmp
argument_list|(
operator|*
name|p
argument_list|,
operator|*
name|q
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

