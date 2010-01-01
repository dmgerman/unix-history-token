begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_function_decl
specifier|extern
name|void
name|go
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|float
name|v
index|[
literal|2
index|]
init|=
block|{
literal|0.0
block|,
literal|1.0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|go
argument_list|(
name|v
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

