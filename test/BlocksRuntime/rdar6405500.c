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
comment|// CONFIG rdar://6405500
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_empty
empty|#import<dispatch/dispatch.h>
end_empty

begin_empty
empty|#import<objc/objc-auto.h>
end_empty

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
specifier|__block
name|void
function_decl|(
modifier|^
name|blockFu
function_decl|)
parameter_list|(
name|size_t
name|t
parameter_list|)
function_decl|;
name|blockFu
operator|=
lambda|^
parameter_list|(
name|size_t
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|==
literal|20
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
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
name|dispatch_async
argument_list|(
name|dispatch_get_main_queue
argument_list|()
argument_list|,
lambda|^
block|{
name|blockFu
argument_list|(
literal|20
argument_list|)
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
block|}
expr_stmt|;
name|dispatch_apply
argument_list|(
literal|10
argument_list|,
name|dispatch_get_concurrent_queue
argument_list|(
name|DISPATCH_QUEUE_PRIORITY_DEFAULT
argument_list|)
argument_list|,
name|blockFu
argument_list|)
expr_stmt|;
name|dispatch_main
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"shouldn't get here\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

