begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002, Jeffrey Roberson<jroberson@chesapeake.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * uma_dbg.c	Debugging features for UMA users  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/types.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma_int.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma_dbg.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|u_int32_t
name|uma_junk
init|=
literal|0xdeadc0de
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Checks an item to make sure it hasn't been overwritten since freed.  *  * Complies with standard ctor arg/return  *  */
end_comment

begin_function
name|void
name|trash_ctor
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|cnt
decl_stmt|;
name|u_int32_t
modifier|*
name|p
decl_stmt|;
name|cnt
operator|=
name|size
operator|/
sizeof|sizeof
argument_list|(
name|uma_junk
argument_list|)
expr_stmt|;
for|for
control|(
name|p
operator|=
name|mem
init|;
name|cnt
operator|>
literal|0
condition|;
name|cnt
operator|--
operator|,
name|p
operator|++
control|)
if|if
condition|(
operator|*
name|p
operator|!=
name|uma_junk
condition|)
name|panic
argument_list|(
literal|"Memory modified after free %p(%d)\n"
argument_list|,
name|mem
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Fills an item with predictable garbage  *  * Complies with standard dtor arg/return  *  */
end_comment

begin_function
name|void
name|trash_dtor
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|cnt
decl_stmt|;
name|u_int32_t
modifier|*
name|p
decl_stmt|;
name|cnt
operator|=
name|size
operator|/
sizeof|sizeof
argument_list|(
name|uma_junk
argument_list|)
expr_stmt|;
for|for
control|(
name|p
operator|=
name|mem
init|;
name|cnt
operator|>
literal|0
condition|;
name|cnt
operator|--
operator|,
name|p
operator|++
control|)
operator|*
name|p
operator|=
name|uma_junk
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Fills an item with predictable garbage  *  * Complies with standard init arg/return  *  */
end_comment

begin_function
name|void
name|trash_init
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|trash_dtor
argument_list|(
name|mem
argument_list|,
name|size
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Checks an item to make sure it hasn't been overwritten since it was freed.  *  * Complies with standard fini arg/return  *  */
end_comment

begin_function
name|void
name|trash_fini
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|trash_ctor
argument_list|(
name|mem
argument_list|,
name|size
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

