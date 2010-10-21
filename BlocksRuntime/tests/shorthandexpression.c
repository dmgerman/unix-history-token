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
comment|/*  *  shorthandexpression.c  *  testObjects  *  *  Created by Blaine Garst on 9/16/08.  *  *  CONFIG error:  */
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|void
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
operator|^
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"hello world\n"
argument_list|)
function_decl|;
block|}
end_function

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
name|printf
argument_list|(
literal|"%s: this shouldn't compile\n"
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

