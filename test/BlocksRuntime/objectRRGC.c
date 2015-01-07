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
comment|/*  *  objectRRGC.c  *  testObjects  *  *  Created by Blaine Garst on 10/31/08.  *  * Test that the runtime honors the new callouts properly for retain/release and GC  * CON FIG C  rdar://6175959  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<Block_private.h>
end_include

begin_decl_stmt
name|int
name|AssignCalled
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|DisposeCalled
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// local copy instead of libSystem.B.dylib copy
end_comment

begin_function
name|void
name|_Block_object_assign
parameter_list|(
name|void
modifier|*
name|destAddr
parameter_list|,
specifier|const
name|void
modifier|*
name|object
parameter_list|,
specifier|const
name|int
name|isWeak
parameter_list|)
block|{
comment|//printf("_Block_object_assign(%p, %p, %d) called\n", destAddr, object, isWeak);
name|AssignCalled
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_Block_object_dispose
parameter_list|(
specifier|const
name|void
modifier|*
name|object
parameter_list|,
specifier|const
name|int
name|isWeak
parameter_list|)
block|{
comment|//printf("_Block_object_dispose(%p, %d) called\n", object, isWeak);
name|DisposeCalled
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|MyStruct
block|{
name|long
name|isa
decl_stmt|;
name|long
name|field
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|MyStruct
modifier|*
name|__attribute__
argument_list|(
operator|(
name|NSObject
operator|)
argument_list|)
name|MyStruct_t
typedef|;
end_typedef

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
comment|// create a block
name|struct
name|MyStruct
name|X
decl_stmt|;
name|MyStruct_t
name|xp
init|=
operator|(
name|MyStruct_t
operator|)
operator|&
name|X
decl_stmt|;
name|xp
operator|->
name|field
operator|=
literal|10
expr_stmt|;
name|void
function_decl|(
modifier|^
name|myBlock
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|printf
argument_list|(
literal|"field is %ld\n"
argument_list|,
name|xp
operator|->
name|field
argument_list|)
function_decl|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// should be a copy helper generated with a calls to above routines
end_comment

begin_comment
comment|// Lets find out!
end_comment

begin_decl_stmt
name|struct
name|Block_layout
modifier|*
name|bl
init|=
operator|(
expr|struct
name|Block_layout
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
name|myBlock
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
operator|(
name|bl
operator|->
name|flags
operator|&
name|BLOCK_HAS_DESCRIPTOR
operator|)
operator|!=
name|BLOCK_HAS_DESCRIPTOR
condition|)
block|{
name|printf
argument_list|(
literal|"using old runtime layout!\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_if

begin_if
if|if
condition|(
operator|(
name|bl
operator|->
name|flags
operator|&
name|BLOCK_HAS_COPY_DISPOSE
operator|)
operator|!=
name|BLOCK_HAS_COPY_DISPOSE
condition|)
block|{
name|printf
argument_list|(
literal|"no copy dispose!!!!\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_if

begin_comment
comment|// call helper routines directly.  These will, in turn, we hope, call the stubs above
end_comment

begin_decl_stmt
name|long
name|destBuffer
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|//printf("destbuffer is at %p, block at %p\n", destBuffer, (void *)bl);
end_comment

begin_comment
comment|//printf("dump is %s\n", _Block_dump(myBlock));
end_comment

begin_expr_stmt
name|bl
operator|->
name|descriptor
operator|->
name|copy
argument_list|(
name|destBuffer
argument_list|,
name|bl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bl
operator|->
name|descriptor
operator|->
name|dispose
argument_list|(
name|bl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|AssignCalled
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"did not call assign helper!\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_if

begin_if
if|if
condition|(
name|DisposeCalled
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"did not call dispose helper\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_if

begin_expr_stmt
name|printf
argument_list|(
literal|"%s: Success!\n"
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

