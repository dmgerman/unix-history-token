begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- BlockProfiling.c - Support library for block profiling ------------===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source       |* License. See LICENSE.TXT for details.                                       |*  |*===----------------------------------------------------------------------===*| |*  |* This file implements the call back routines for the block profiling |* instrumentation pass.  This should be used with the -insert-block-profiling |* LLVM pass. |* \*===----------------------------------------------------------------------===*/
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

begin_decl_stmt
specifier|static
name|unsigned
modifier|*
name|ArrayStart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|NumElements
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BlockProfAtExitHandler - When the program exits, just write out the profiling  * data.  */
end_comment

begin_function
specifier|static
name|void
name|BlockProfAtExitHandler
parameter_list|()
block|{
comment|/* Note that if this were doing something more intelligent with the    * instrumentation, we could do some computation here to expand what we    * collected into simple block profiles. (Or we could do it in llvm-prof.)    * Regardless, we directly count each block, so no expansion is necessary.    */
name|write_profiling_data
argument_list|(
name|BlockInfo
argument_list|,
name|ArrayStart
argument_list|,
name|NumElements
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* llvm_start_block_profiling - This is the main entry point of the block  * profiling library.  It is responsible for setting up the atexit handler.  */
end_comment

begin_function
name|int
name|llvm_start_block_profiling
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
init|=
name|save_arguments
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|ArrayStart
operator|=
name|arrayStart
expr_stmt|;
name|NumElements
operator|=
name|numElements
expr_stmt|;
name|atexit
argument_list|(
name|BlockProfAtExitHandler
argument_list|)
expr_stmt|;
return|return
name|Ret
return|;
block|}
end_function

end_unit

