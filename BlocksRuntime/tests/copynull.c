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
comment|/*  *  copynull.c  *  testObjects  *  *  Created by Blaine Garst on 10/15/08.  *  */
end_comment

begin_empty
empty|#import<stdio.h>
end_empty

begin_empty
empty|#import<Block.h>
end_empty

begin_empty
empty|#import<Block_private.h>
end_empty

begin_comment
comment|// CONFIG rdar://6295848
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
name|void
function_decl|(
modifier|^
name|block
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
operator|(
name|void
argument_list|(
operator|^
argument_list|)
operator|(
name|void
operator|)
operator|)
literal|0
function_decl|;
name|void
function_decl|(
modifier|^
name|blockcopy
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|Block_copy
argument_list|(
name|block
argument_list|)
function_decl|;
if|if
condition|(
name|blockcopy
operator|!=
operator|(
name|void
argument_list|(
operator|^
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"whoops, somehow we copied NULL!\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
comment|// make sure we can also
name|Block_release
argument_list|(
name|blockcopy
argument_list|)
expr_stmt|;
comment|// and more secretly
comment|//_Block_destroy(blockcopy);
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

