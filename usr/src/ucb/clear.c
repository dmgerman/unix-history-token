begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#) Copyright (c) 1980 Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)clear.c	5.1 (Berkeley) 5/31/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* load me with -ltermlib */
end_comment

begin_comment
comment|/* #include<retrofit.h> on version 6 */
end_comment

begin_comment
comment|/*  * clear - clear the screen  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_function_decl
name|int
name|putchar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|()
block|{
name|char
modifier|*
name|cp
init|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
decl_stmt|;
name|char
name|clbuf
index|[
literal|20
index|]
decl_stmt|;
name|char
name|pcbuf
index|[
literal|20
index|]
decl_stmt|;
name|char
modifier|*
name|clbp
init|=
name|clbuf
decl_stmt|;
name|char
modifier|*
name|pcbp
init|=
name|pcbuf
decl_stmt|;
name|char
modifier|*
name|clear
decl_stmt|;
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
name|char
modifier|*
name|pc
decl_stmt|;
name|struct
name|sgttyb
name|tty
decl_stmt|;
name|gtty
argument_list|(
literal|1
argument_list|,
operator|&
name|tty
argument_list|)
expr_stmt|;
name|ospeed
operator|=
name|tty
operator|.
name|sg_ospeed
expr_stmt|;
if|if
condition|(
name|cp
operator|==
operator|(
name|char
operator|*
operator|)
literal|0
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|tgetent
argument_list|(
name|buf
argument_list|,
name|cp
argument_list|)
operator|!=
literal|1
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|pc
operator|=
name|tgetstr
argument_list|(
literal|"pc"
argument_list|,
operator|&
name|pcbp
argument_list|)
expr_stmt|;
if|if
condition|(
name|pc
condition|)
name|PC
operator|=
operator|*
name|pc
expr_stmt|;
name|clear
operator|=
name|tgetstr
argument_list|(
literal|"cl"
argument_list|,
operator|&
name|clbp
argument_list|)
expr_stmt|;
if|if
condition|(
name|clear
condition|)
name|tputs
argument_list|(
name|clear
argument_list|,
name|tgetnum
argument_list|(
literal|"li"
argument_list|)
argument_list|,
name|putchar
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|clear
operator|==
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

