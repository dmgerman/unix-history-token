begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#) Copyright (c) 1980, 1988 Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)tput.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|clbp
decl_stmt|,
name|clbuf
index|[
literal|100
index|]
decl_stmt|,
name|tbuf
index|[
literal|1024
index|]
decl_stmt|,
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|tgetstr
argument_list|()
decl_stmt|;
name|int
name|putchar
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|cp
operator|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
operator|)
operator|&&
name|tgetent
argument_list|(
name|tbuf
argument_list|,
name|cp
argument_list|)
operator|==
literal|1
condition|)
block|{
name|clbp
operator|=
name|clbuf
expr_stmt|;
if|if
condition|(
name|cp
operator|=
name|tgetstr
argument_list|(
literal|"cl"
argument_list|,
operator|&
name|clbp
argument_list|)
condition|)
block|{
name|tputs
argument_list|(
name|cp
argument_list|,
literal|1
argument_list|,
name|putchar
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

