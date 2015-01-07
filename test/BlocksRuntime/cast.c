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
comment|/*  *  cast.c  *  testObjects  *  *  Created by Blaine Garst on 2/17/09.  *  */
end_comment

begin_comment
comment|// PURPOSE should allow casting of a Block reference to an arbitrary pointer and back
end_comment

begin_comment
comment|// CONFIG open
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
name|void
function_decl|(
modifier|^
name|aBlock
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
modifier|*
name|ip
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|double
modifier|*
name|dp
decl_stmt|;
name|ip
operator|=
operator|(
name|int
operator|*
operator|)
name|aBlock
expr_stmt|;
name|cp
operator|=
operator|(
name|char
operator|*
operator|)
name|aBlock
expr_stmt|;
name|dp
operator|=
operator|(
name|double
operator|*
operator|)
name|aBlock
expr_stmt|;
name|aBlock
operator|=
operator|(
name|void
argument_list|(
operator|^
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
name|ip
expr_stmt|;
name|aBlock
operator|=
operator|(
name|void
argument_list|(
operator|^
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
name|cp
expr_stmt|;
name|aBlock
operator|=
operator|(
name|void
argument_list|(
operator|^
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
name|dp
expr_stmt|;
name|printf
argument_list|(
literal|"%s: success"
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

