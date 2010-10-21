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
comment|/*  *  byrefcopyint.c  *  testObjects  *  *  Created by Blaine Garst on 12/1/08.  *  */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  byrefcopyid.m
end_comment

begin_comment
comment|//  testObjects
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Blaine Garst on 5/13/08.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Tests copying of blocks with byref ints
end_comment

begin_comment
comment|// CONFIG rdar://6414583 -C99
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<Block.h>
end_include

begin_include
include|#
directive|include
file|<Block_private.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|voidVoid
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|voidVoid
name|dummy
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|callVoidVoid
parameter_list|(
name|voidVoid
name|closure
parameter_list|)
block|{
name|closure
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|voidVoid
name|testRoutine
parameter_list|(
specifier|const
name|char
modifier|*
name|whoami
parameter_list|)
block|{
specifier|__block
name|int
name|dumbo
init|=
name|strlen
argument_list|(
name|whoami
argument_list|)
decl_stmt|;
name|dummy
operator|=
lambda|^
block|{
comment|//printf("incring dumbo from %d\n", dumbo);
operator|++
name|dumbo
expr_stmt|;
block|}
expr_stmt|;
name|voidVoid
name|copy
init|=
name|Block_copy
argument_list|(
name|dummy
argument_list|)
decl_stmt|;
return|return
name|copy
return|;
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
name|voidVoid
name|array
index|[
literal|100
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
operator|++
name|i
control|)
block|{
name|array
index|[
name|i
index|]
operator|=
name|testRoutine
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|array
index|[
name|i
index|]
operator|(
operator|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
operator|++
name|i
control|)
block|{
name|Block_release
argument_list|(
name|array
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
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

