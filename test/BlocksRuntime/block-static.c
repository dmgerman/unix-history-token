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
comment|// testfilerunner CONFIG
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
modifier|*
name|argv
parameter_list|)
block|{
specifier|static
name|int
name|numberOfSquesals
init|=
literal|5
decl_stmt|;
lambda|^
block|{
name|numberOfSquesals
operator|=
literal|6
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
if|if
condition|(
name|numberOfSquesals
operator|==
literal|6
condition|)
block|{
name|printf
argument_list|(
literal|"%s: success\n"
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
block|}
name|printf
argument_list|(
literal|"**** did not update static local, rdar://6177162\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

