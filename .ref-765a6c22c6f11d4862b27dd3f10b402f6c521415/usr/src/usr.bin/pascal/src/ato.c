begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
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
literal|"@(#)ato.c 1.6 %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is an sccs experiment */
end_comment

begin_include
include|#
directive|include
file|"whoami.h"
end_include

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_function
name|long
name|a8tol
parameter_list|(
name|cp
parameter_list|)
name|char
modifier|*
name|cp
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
name|long
name|l
decl_stmt|;
specifier|register
name|CHAR
name|c
decl_stmt|;
name|l
operator|=
literal|0
expr_stmt|;
name|err
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|cp
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
name|c
operator|==
literal|'8'
operator|||
name|c
operator|==
literal|'9'
condition|)
if|if
condition|(
name|err
operator|==
literal|0
condition|)
block|{
name|error
argument_list|(
literal|"8 or 9 in octal number"
argument_list|)
expr_stmt|;
name|err
operator|++
expr_stmt|;
block|}
name|c
operator|-=
literal|'0'
expr_stmt|;
if|if
condition|(
operator|(
name|l
operator|&
literal|016000000000L
operator|)
operator|!=
literal|0
condition|)
if|if
condition|(
name|err
operator|==
literal|0
condition|)
block|{
name|error
argument_list|(
literal|"Number too large for this implementation"
argument_list|)
expr_stmt|;
name|err
operator|++
expr_stmt|;
block|}
name|l
operator|=
operator|(
name|l
operator|<<
literal|3
operator|)
operator||
name|c
expr_stmt|;
block|}
return|return
operator|(
name|l
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Note that the version of atof  * used in this compiler does not  * (sadly) complain when floating  * point numbers are too large.  */
end_comment

end_unit

