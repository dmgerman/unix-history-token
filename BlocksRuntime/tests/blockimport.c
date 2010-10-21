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
comment|/*  *  blockimport.c  *  testObjects  *  *  Created by Blaine Garst on 10/13/08.  *  */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// pure C nothing more needed
end_comment

begin_comment
comment|// CONFIG  rdar://6289344
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
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
name|int
name|i
init|=
literal|1
decl_stmt|;
name|int
function_decl|(
modifier|^
name|intblock
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
return|return
name|i
operator|*
literal|10
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
function_decl|(
modifier|^
name|vv
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_if
if|if
condition|(
name|argc
operator|>
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"intblock returns %d\n"
argument_list|,
name|intblock
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
unit|};
if|#
directive|if
literal|0
end_if

begin_comment
comment|//printf("Block dump %s\n", _Block_dump(vv));
end_comment

begin_endif
unit|{         struct Block_layout *layout = (struct Block_layout *)(void *)vv;         printf("isa %p\n", layout->isa);         printf("flags %x\n", layout->flags);         printf("descriptor %p\n", layout->descriptor);         printf("descriptor->size %d\n", layout->descriptor->size);     }
endif|#
directive|endif
end_endif

begin_function_decl
name|void
function_decl|(
modifier|^
name|vvcopy
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|Block_copy
argument_list|(
name|vv
argument_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|Block_release
argument_list|(
name|vvcopy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

unit|}
end_unit

