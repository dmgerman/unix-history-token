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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* CONFIG rdar://6310599  */
end_comment

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
name|flags
decl_stmt|;
specifier|__block
name|void
modifier|*
name|isa
decl_stmt|;
lambda|^
block|{
name|flags
operator|=
literal|1
expr_stmt|;
name|isa
operator|=
operator|(
name|void
operator|*
operator|)
name|isa
expr_stmt|;
block|}
expr_stmt|;
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
end_function

end_unit

