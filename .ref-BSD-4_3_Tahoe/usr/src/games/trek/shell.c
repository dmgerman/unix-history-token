begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)shell.c	5.3 (Berkeley) 6/18/88"
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
comment|/* **  CALL THE SHELL */
end_comment

begin_macro
name|shell
argument_list|()
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|;
specifier|register
name|int
name|pid
decl_stmt|;
specifier|register
name|int
name|sav2
decl_stmt|,
name|sav3
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|pid
operator|=
name|fork
argument_list|()
operator|)
condition|)
block|{
name|setuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
name|nice
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|execl
argument_list|(
literal|"/bin/csh"
argument_list|,
literal|"-"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|syserr
argument_list|(
literal|"cannot execute /bin/csh"
argument_list|)
expr_stmt|;
block|}
name|sav2
operator|=
name|signal
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|sav3
operator|=
name|signal
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
while|while
condition|(
name|wait
argument_list|(
operator|&
name|i
argument_list|)
operator|!=
name|pid
condition|)
empty_stmt|;
name|signal
argument_list|(
literal|2
argument_list|,
name|sav2
argument_list|)
expr_stmt|;
name|signal
argument_list|(
literal|3
argument_list|,
name|sav3
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

