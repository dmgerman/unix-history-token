begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"foo.h"
end_include

begin_decl_stmt
name|int
name|global_var
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar_func
parameter_list|(
name|void
parameter_list|)
block|{
name|global_var
operator|+=
literal|100
expr_stmt|;
name|foo_func
argument_list|(
name|global_var
argument_list|)
expr_stmt|;
name|struct
name|MyStruct
modifier|*
name|ms
decl_stmt|;
name|ms
operator|->
name|field_var
operator|=
literal|10
expr_stmt|;
block|}
end_function

begin_comment
comment|// Suppress 'no run line' failure.
end_comment

begin_comment
comment|// RUN: true
end_comment

end_unit

