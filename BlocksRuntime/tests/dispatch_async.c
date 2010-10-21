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
file|<CoreFoundation/CoreFoundation.h>
end_include

begin_include
include|#
directive|include
file|<dispatch/dispatch.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|//#import<Foundation/Foundation.h>
end_comment

begin_include
include|#
directive|include
file|<Block.h>
end_include

begin_comment
comment|// CONFIG rdar://problem/6371811
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|whoami
init|=
literal|"nobody"
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|EnqueueStuff
parameter_list|(
name|dispatch_queue_t
name|q
parameter_list|)
block|{
specifier|__block
name|CFIndex
name|counter
decl_stmt|;
comment|// above call has a side effect: it works around:
comment|//<rdar://problem/6225809> __block variables not implicitly imported into intermediate scopes
name|dispatch_async
argument_list|(
name|q
argument_list|,
lambda|^
block|{
name|counter
operator|=
literal|0
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
name|dispatch_async
argument_list|(
name|q
argument_list|,
lambda|^
block|{
comment|//printf("outer block.\n");
name|counter
operator|++
expr_stmt|;
name|dispatch_async
argument_list|(
name|q
argument_list|,
lambda|^
block|{
comment|//printf("inner block.\n");
name|counter
operator|--
expr_stmt|;
if|if
condition|(
name|counter
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%s: success\n"
argument_list|,
name|whoami
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
if|if
condition|(
name|counter
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"already done? inconceivable!\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
block|}
end_function

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
name|dispatch_queue_t
name|q
init|=
name|dispatch_queue_create
argument_list|(
literal|"queue"
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|whoami
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|EnqueueStuff
argument_list|(
name|q
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

