begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -std=c11 -O0 %s -o %t&& %run %t
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function_decl
specifier|extern
name|void
modifier|*
name|aligned_alloc
parameter_list|(
name|size_t
name|alignment
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|volatile
name|void
modifier|*
name|p
init|=
name|aligned_alloc
argument_list|(
literal|128
argument_list|,
literal|1024
argument_list|)
decl_stmt|;
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

