begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Just a replacement, if the original malloc is not    GNU-compliant. See autoconf documentation. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_undef
undef|#
directive|undef
name|malloc
end_undef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate an N-byte block of memory from the heap.    If N is zero, allocate a 1-byte block.  */
end_comment

begin_function
name|void
modifier|*
name|rpl_malloc_unbound
parameter_list|(
name|size_t
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
name|n
operator|=
literal|1
expr_stmt|;
return|return
name|malloc
argument_list|(
name|n
argument_list|)
return|;
block|}
end_function

end_unit

