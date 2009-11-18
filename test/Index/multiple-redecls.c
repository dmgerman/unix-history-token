begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-pch %s -o %t.ast
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:8:4 -print-decls | count 2
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:8:4 -print-defs | count 1
end_comment

begin_function_decl
specifier|static
name|void
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
block|{
name|foo
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{  }
end_function

end_unit

