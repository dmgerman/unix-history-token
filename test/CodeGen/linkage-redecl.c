begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - |grep internal
end_comment

begin_comment
comment|// C99 6.2.2p3
end_comment

begin_comment
comment|// PR3425
end_comment

begin_function_decl
specifier|static
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|g0
parameter_list|()
block|{
name|f
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|extern
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{ }
end_function

begin_comment
comment|// still has internal linkage
end_comment

end_unit

