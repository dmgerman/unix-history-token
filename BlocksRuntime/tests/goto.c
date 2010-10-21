begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|/*  *  goto.c  *  testObjects  *  *  Created by Blaine Garst on 10/17/08.  *  */
end_comment

begin_comment
comment|// CONFIG rdar://6289031
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
specifier|__block
name|int
name|val
init|=
literal|0
decl_stmt|;
lambda|^
block|{
name|val
operator|=
literal|1
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
if|if
condition|(
name|val
operator|==
literal|0
condition|)
block|{
goto|goto
name|out_bad
goto|;
comment|// error: local byref variable val is in the scope of this goto
block|}
name|printf
argument_list|(
literal|"%s: Success!\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
name|out_bad
label|:
name|printf
argument_list|(
literal|"%s: val not updated!\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

