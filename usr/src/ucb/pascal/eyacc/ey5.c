begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1979 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)ey5.c	5.1 (Berkeley) 4/29/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* fake portable I/O routines, for those     sites so backward as to not have the      port. library */
end_comment

begin_comment
comment|/* munged for standard i/o library: peter and louise 5 may 80 */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|FILE
modifier|*
name|cin
decl_stmt|,
modifier|*
name|cout
decl_stmt|;
end_decl_stmt

begin_function
name|FILE
modifier|*
name|copen
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|char
name|c
decl_stmt|;
block|{
name|FILE
modifier|*
name|f
decl_stmt|;
if|if
condition|(
name|c
operator|==
literal|'r'
condition|)
block|{
name|f
operator|=
name|fopen
argument_list|(
name|s
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|'a'
condition|)
block|{
name|f
operator|=
name|fopen
argument_list|(
name|s
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
name|fseek
argument_list|(
name|f
argument_list|,
literal|0L
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* c == w */
name|f
operator|=
name|fopen
argument_list|(
name|s
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|f
operator|)
return|;
block|}
end_function

begin_macro
name|cflush
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* fake! sets file to x */
name|fflush
argument_list|(
name|cout
argument_list|)
expr_stmt|;
name|cout
operator|=
name|x
expr_stmt|;
block|}
end_block

begin_macro
name|system
argument_list|()
end_macro

begin_block
block|{
name|error
argument_list|(
literal|"The function \"system\" is called"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cclose
argument_list|(
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|i
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fclose
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cexit
argument_list|(
argument|i
argument_list|)
end_macro

begin_block
block|{
name|fflush
argument_list|(
name|cout
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|!=
literal|0
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
name|exit
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

