begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_empty
empty|#
end_empty

begin_comment
comment|/*  * pi - Pascal interpreter code translator  *  * Charles Haley, Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_define
define|#
directive|define
name|INTR
value|2
end_define

begin_function_decl
name|int
name|onintr
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_expr_stmt
expr|main
operator|(
name|argc
operator|)
name|int
name|argc
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|main
parameter_list|()
endif|#
directive|endif
block|{
name|int
name|intr
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|hp21mx
operator|=
name|argc
operator|>
literal|1
expr_stmt|;
endif|#
directive|endif
name|intr
operator|=
name|signal
argument_list|(
name|INTR
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|intr
operator|==
literal|0
condition|)
name|signal
argument_list|(
name|INTR
argument_list|,
name|onintr
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|dprintf
argument_list|(
literal|"PI1 initialized\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|yymain
argument_list|()
expr_stmt|;
comment|/* no return */
block|}
end_function

begin_comment
comment|/*  * Buffer for putchar  */
end_comment

begin_decl_stmt
name|char
name|pcbuf
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pcbp
name|pcbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Line buffered putchar for pi.  */
end_comment

begin_macro
name|putchar
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|pcbp
operator|++
operator|=
name|c
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'\n'
operator|||
name|pcbp
operator|==
operator|&
name|pcbuf
index|[
sizeof|sizeof
name|pcbuf
operator|-
literal|1
index|]
condition|)
block|{
name|write
argument_list|(
literal|1
argument_list|,
operator|&
name|pcbuf
argument_list|,
name|pcbp
operator|-
name|pcbuf
argument_list|)
expr_stmt|;
name|pcbp
operator|=
name|pcbuf
expr_stmt|;
block|}
block|}
end_block

begin_expr_stmt
name|char
name|ugh
index|[]
literal|"Fatal error in pi1\n"
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Exit from the Pascal system.  */
end_comment

begin_macro
name|pexit
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|c
operator|==
name|DIED
condition|)
name|write
argument_list|(
literal|2
argument_list|,
name|ugh
argument_list|,
sizeof|sizeof
name|ugh
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|onintr
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|pexit
argument_list|(
name|NOSTART
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Get an error message from the error message file  */
end_comment

begin_macro
name|geterr
argument_list|(
argument|seekpt
argument_list|,
argument|buf
argument_list|)
end_macro

begin_decl_stmt
name|int
name|seekpt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|seek
argument_list|(
name|efil
argument_list|,
name|seekpt
argument_list|,
literal|0
argument_list|)
operator|||
name|read
argument_list|(
name|efil
argument_list|,
name|buf
argument_list|,
literal|256
argument_list|)
operator|<=
literal|0
condition|)
name|perror
argument_list|(
name|errfile
argument_list|)
operator|,
name|pexit
argument_list|(
name|DIED
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

