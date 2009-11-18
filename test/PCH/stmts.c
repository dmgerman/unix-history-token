begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: clang-cc -include %S/stmts.h -fsyntax-only -emit-llvm -o - %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: clang-cc -emit-pch -o %t %S/stmts.h
end_comment

begin_comment
comment|// RUN: clang-cc -include-pch %t -fsyntax-only -emit-llvm -o - %s
end_comment

begin_function
name|void
name|g0
parameter_list|(
name|void
parameter_list|)
block|{
name|f0
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|g1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|f1
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|query_name
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|what_is_my_name
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|use_computed_goto
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|computed_goto
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|get_weird_max
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|weird_max
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

end_unit

