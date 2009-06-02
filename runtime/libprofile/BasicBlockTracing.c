begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- BasicBlockTracing.c - Support library for basic block tracing -----===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |*  |*===----------------------------------------------------------------------===*| |*  |* This file implements the call back routines for the basic block tracing |* instrumentation pass.  This should be used with the -trace-basic-blocks |* LLVM pass. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"Profiling.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|unsigned
modifier|*
name|ArrayStart
decl_stmt|,
modifier|*
name|ArrayEnd
decl_stmt|,
modifier|*
name|ArrayCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WriteAndFlushBBTraceData - write out the currently accumulated trace data  * and reset the cursor to point to the beginning of the buffer.  */
end_comment

begin_function
specifier|static
name|void
name|WriteAndFlushBBTraceData
parameter_list|()
block|{
name|write_profiling_data
argument_list|(
name|BBTraceInfo
argument_list|,
name|ArrayStart
argument_list|,
operator|(
name|ArrayCursor
operator|-
name|ArrayStart
operator|)
argument_list|)
expr_stmt|;
name|ArrayCursor
operator|=
name|ArrayStart
expr_stmt|;
block|}
end_function

begin_comment
comment|/* BBTraceAtExitHandler - When the program exits, just write out any remaining   * data and free the trace buffer.  */
end_comment

begin_function
specifier|static
name|void
name|BBTraceAtExitHandler
parameter_list|()
block|{
name|WriteAndFlushBBTraceData
argument_list|()
expr_stmt|;
name|free
argument_list|(
name|ArrayStart
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* llvm_trace_basic_block - called upon hitting a new basic block. */
end_comment

begin_function
name|void
name|llvm_trace_basic_block
parameter_list|(
name|unsigned
name|BBNum
parameter_list|)
block|{
operator|*
name|ArrayCursor
operator|++
operator|=
name|BBNum
expr_stmt|;
if|if
condition|(
name|ArrayCursor
operator|==
name|ArrayEnd
condition|)
name|WriteAndFlushBBTraceData
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* llvm_start_basic_block_tracing - This is the main entry point of the basic  * block tracing library.  It is responsible for setting up the atexit  * handler and allocating the trace buffer.  */
end_comment

begin_function
name|int
name|llvm_start_basic_block_tracing
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|unsigned
modifier|*
name|arrayStart
parameter_list|,
name|unsigned
name|numElements
parameter_list|)
block|{
name|int
name|Ret
decl_stmt|;
specifier|const
name|unsigned
name|BufferSize
init|=
literal|128
operator|*
literal|1024
decl_stmt|;
name|unsigned
name|ArraySize
decl_stmt|;
name|Ret
operator|=
name|save_arguments
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* Allocate a buffer to contain BB tracing data */
name|ArraySize
operator|=
name|BufferSize
operator|/
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
expr_stmt|;
name|ArrayStart
operator|=
name|malloc
argument_list|(
name|ArraySize
operator|*
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
argument_list|)
expr_stmt|;
name|ArrayEnd
operator|=
name|ArrayStart
operator|+
name|ArraySize
expr_stmt|;
name|ArrayCursor
operator|=
name|ArrayStart
expr_stmt|;
comment|/* Set up the atexit handler. */
name|atexit
argument_list|(
name|BBTraceAtExitHandler
argument_list|)
expr_stmt|;
return|return
name|Ret
return|;
block|}
end_function

end_unit

