begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- clear_cache.c - Implement __clear_cache ---------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_if
if|#
directive|if
name|__APPLE__
end_if

begin_include
include|#
directive|include
file|<libkern/OSCacheControl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The compiler generates calls to __clear_cache() when creating   * trampoline functions on the stack for use with nested functions.  * It is expected to invalidate the instruction cache for the   * specified range.  */
end_comment

begin_function
name|void
name|__clear_cache
parameter_list|(
name|void
modifier|*
name|start
parameter_list|,
name|void
modifier|*
name|end
parameter_list|)
block|{
if|#
directive|if
name|__i386__
operator|||
name|__x86_64__
comment|/*  * Intel processors have a unified instruction and data cache  * so there is nothing to do  */
else|#
directive|else
if|#
directive|if
name|__APPLE__
comment|/* On Darwin, sys_icache_invalidate() provides this functionality */
name|sys_icache_invalidate
argument_list|(
name|start
argument_list|,
name|end
operator|-
name|start
argument_list|)
expr_stmt|;
else|#
directive|else
name|compilerrt_abort
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

end_unit

